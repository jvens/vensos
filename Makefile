.SECONDARY:

BIN = main

CWD := $(shell pwd)

LZZ := ./lzz

#CROSS_COMPILER ?= arm-linux-gnueabihf-
CROSS_COMPILER ?= arm-none-eabi-

CXX := $(CROSS_COMPILER)g++
CC  := $(CROSS_COMPILER)g++
AS  := $(CROSS_COMPILER)g++
LD	:= $(CROSS_COMPILER)g++
OBJDUMP := $(CROSS_COMPILER)objdump
OBJCOPY := $(CROSS_COMPILER)objcopy
POSTCOMPILE = mv $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d


SRC_DIR = src
OBJ_DIR = obj
LZZ_DIR = lzz-out
DEP_DIR = dep

$(shell mkdir -p $(OBJ_DIR) > /dev/null)
$(shell mkdir -p $(LZZ_DIR) > /dev/null)
$(shell mkdir -p $(DEP_DIR) > /dev/null)


MODULES = $(sort $(dir $(wildcard $(SRC_DIR)/*/)))

SRC_CXX := $(foreach dir,$(MODULES),$(wildcard $(dir)*.cpp))
SRC_C   := $(foreach dir,$(MODULES),$(wildcard $(dir)*.c))
SRC_S	:= $(foreach dir,$(MODULES),$(wildcard $(dir)*.S))
SRC_LZZ	:= $(foreach dir,$(MODULES),$(wildcard $(dir)*.lzz))

SRC_LZZ_H  := $(patsubst %.lzz,$(LZZ_DIR)/%.h,$(SRC_LZZ))


OBJ_CXX := $(patsubst %.cpp,$(OBJ_DIR)/%.cpp.o,$(SRC_CXX))
OBJ_C   := $(patsubst %.c,$(OBJ_DIR)/%.c.o,$(SRC_C))
OBJ_S 	:= $(patsubst %.S,$(OBJ_DIR)/%.S.o,$(SRC_S))
OBJ_LZZ := $(patsubst %.lzz,$(OBJ_DIR)/%.lzz.o,$(SRC_LZZ))

OBJS := $(OBJ_LZZ) $(OBJ_CXX) $(OBJ_C) $(OBJ_S)

# -nostartfiles 

INCLUDE := -I $(SRC_DIR)/include -I $(SRC_DIR) -I $(LZZ_DIR)/$(SRC_DIR)
DEP_FLAGS	= -MMD -MP -MF $(DEP_DIR)/$*.Td
#should be -mfloat-abi=hard
ARCH_FLAGS	= -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp
CC_FLAGS	= -g -Wall -O0 -nostartfiles -ffreestanding  $(INCLUDE) $(DEP_FLAGS)
CXX_FLAGS	= -std=c++11 $(CC_FLAGS)
AS_FLAGS	= $(CC_FLAGS)
LZZ_FLAGS	= -sx cpp -hx h $(INCLUDE)
LD_FLAGS	= -T linker.x $(CXX_FLAGS)

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERR]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARN]$(NO_COLOR)

SIZE_CMD = `stat -c%s $@ | numfmt --to=iec-i --suffix=B --format='%.1f'`
AWK_CMD = awk '{ printf "%-18s %-50s\n",$$2, $$1 }'
AWK_CMD_OK = awk '{ printf "%-18s %-50s%-10s\n",$$2, $$1, $$3 }'
PRINT_ERROR = printf "$@ $(ERROR_STRING)\n" | $(AWK_CMD) && printf "$(CMD)\n$$LOG\n" && false
PRINT_WARNING = printf "$@ $(WARN_STRING)\n" | $(AWK_CMD) && printf "$(CMD)\n$$LOG\n"
PRINT_OK = printf "$@ $(OK_STRING) $(SIZE_CMD)\n" | $(AWK_CMD_OK)

BUILD_CMD = LOG=$$($(CMD) 2>&1) ; if [ $$? -eq 1 ]; then $(PRINT_ERROR); elif [ "$$LOG" != "" ] ; then $(PRINT_WARNING); else $(PRINT_OK); fi;
LZZ_BUILD_CMD = if [ -e $(input) ]; then tmplog=$$(mktemp); $(CMD) 2> $$tmplog; if [ $$? -eq 1 ]; then printf "$@ $(WARN_STRING)\n" | $(AWK_CMD) && printf "$(CMD)\n" && cat $$tmplog; elif [ -s $$tmplog ] ; then printf "$@ $(WARN_STRING)\n" | $(AWK_CMD) && printf "$(CMD)\n" cat $$tmplog; else $(PRINT_OK); fi; rm $$tmplog; else echo "" | $(CMD2); $(PRINT_OK); fi;

#DEBUG_CMD = @echo $@: $^
DEBUG_CMD = 

all: preprocess_lzz
all: bin/main.bin bin/main.srec bin/main.list bin/main.elf

preprocess_lzz: $(SRC_LZZ_H)
	$(DEBUG_CMD)

bin/$(BIN).bin: CMD = $(OBJCOPY) $< -O binary $@
bin/$(BIN).bin: bin/main.elf
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@$(BUILD_CMD)
#	@echo "File size: `stat -c%s $@ | numfmt --to=iec-i --suffix=B --format='%.1f'`" 
	
	
bin/$(BIN).srec: CMD = $(OBJCOPY) --srec-forceS3 $< -O srec $@
bin/$(BIN).srec: bin/main.elf
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@$(BUILD_CMD)
	
	
bin/$(BIN).list: CMD = $(OBJDUMP) -d $< > $@
bin/$(BIN).list: bin/main.elf
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@$(BUILD_CMD)
	
	
bin/$(BIN).elf: CMD = $(LD) $^ $(LD_FLAGS) -o $@
bin/$(BIN).elf: $(OBJS)
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@$(BUILD_CMD)


$(LZZ_DIR)/%.h: CMD = $(LZZ) $(LZZ_FLAGS) -o $(dir $@) $<
$(LZZ_DIR)/%.h: %.lzz
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@$(BUILD_CMD)
	
$(OBJ_DIR)/%.lzz.o: CMD = $(CXX) $(CXX_FLAGS) $(ARCH_FLAGS) -c $(input) -o $@
$(OBJ_DIR)/%.lzz.o: CMD2 = $(CC) $(CC_FLAGS) $(ARCH_FLAGS) -x c -c -o $@ -
$(OBJ_DIR)/%.lzz.o: $(LZZ_DIR)/%.h
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)/$(subst $(LZZ_DIR)/,,$(dir $<))
	@$(eval input := $(patsubst %.h,%.cpp,$<))
	@$(LZZ_BUILD_CMD)
	@$(POSTCOMPILE)
	

$(OBJ_DIR)/%.cpp.o: CMD = $(CXX) $(CXX_FLAGS) $(ARCH_FLAGS) -c $< -o $@
$(OBJ_DIR)/%.cpp.o: %.cpp
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)/$(dir $<)
	@$(BUILD_CMD)
	@$(POSTCOMPILE)

$(OBJ_DIR)/%.c.o: CMD = $(CC) $(CC_FLAGS) $(ARCH_FLAGS) -c $< -o $@
$(OBJ_DIR)/%.c.o: %.c
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)/$(dir $<)
	@$(BUILD_CMD)
	@$(POSTCOMPILE)
	
$(OBJ_DIR)/%.S.o: CMD = $(AS) $(AS_FLAGS) $(ARCH_FLAGS) -c $< -o $@
$(OBJ_DIR)/%.S.o: %.S $(DEP_DIR)/%.d
	$(DEBUG_CMD)
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)/$(dir $<)
	@$(BUILD_CMD)
	@$(POSTCOMPILE)
	

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d




.PHONY: clean doc
clean: CMD = rm -rf bin/* obj/* lzz-out/* deps/*
clean:
	$(DEBUG_CMD)
#	@$(BUILD_CMD)
	@rm -rf bin/* obj/* lzz-out/* deps/*
	@printf "$(OK_STRING)\n"
doc: CMD = doxygen Doxyfile
doc: 
	@$(BUILD_CMD)

.PHONY: $(LZZ_DIR)/%.cpp
$(LZZ_DIR)/%.cpp: $(LZZ_DIR)/%.h
	
include $(wildcard $(patsubst %,$(DEP_DIR)/%.d,$(basename $(SRC_CXX))))
include $(wildcard $(patsubst %,$(DEP_DIR)/%.d,$(basename $(SRC_C))))
include $(wildcard $(patsubst %,$(DEP_DIR)/%.d,$(basename $(SRC_S))))
include $(wildcard $(patsubst %,$(DEP_DIR)/%.d,$(basename $(SRC_LZZ))))





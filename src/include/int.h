#pragma once


#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef volatile u32 __attribute__ ((aligned (4))) reg_t;

typedef /*const*/ reg_t reg_ro;
typedef reg_t reg_wo;
typedef reg_t reg_rw;

typedef /*const*/ unsigned bit_ro;
typedef unsigned bit_wo;
typedef unsigned bit_rw;
typedef unsigned bit_fil;

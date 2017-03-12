#pragma once

typedef volatile unsigned int reg_t;

typedef struct PMU_STRUCT {
	reg_t dvfs_ctrl_0;
	reg_t dvfs_ctrl_1;
	reg_t dummy1;
	reg_t dvfs_ctrl_2;
	reg_t dummy2;
	reg_t dummy3;
	reg_t dvfs_ctrl_3;
	reg_t dvfs_timeout_ctrl;
	reg_t axi_auto_swt_0;
	reg_t axi_auto_swt_1;
	reg_t irq_en;
	reg_t irq_status;
	reg_t cpuvdd_ctrl_addr;
	reg_t twi_addr;
	reg_t cpuvdd_value;
	reg_t cpuvdd_ramp_ctrl;
	reg_t khz32_cpuvdd_min;
	reg_t vf_table[19];
	reg_t vf_table_valid;
	reg_t vf_table_index;
	reg_t vf_table_range;
	reg_t speed_factor_0;
	reg_t speed_factor_1;
	reg_t speed_factor_2;
	reg_t cpu_idle_cnt_low;
	reg_t cpu_idle_cnt_high;
	reg_t cpu_idle_cnt_ctrl;
	reg_t cpu_idle_status;
} pmu_t;

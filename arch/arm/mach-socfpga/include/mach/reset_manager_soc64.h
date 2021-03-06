/* SPDX-License-Identifier: GPL-2.0 */
/*
 *  Copyright (C) 2016-2018 Intel Corporation <www.intel.com>
 */

#ifndef _RESET_MANAGER_SOC64_H_
#define _RESET_MANAGER_SOC64_H_

void reset_cpu(ulong addr);
void __secure l2_reset_cpu_psci(void);
void l2_reset_cpu(void);
void reset_deassert_peripherals_handoff(void);
int cpu_has_been_warmreset(void);

void socfpga_bridges_reset(int enable);
void socfpga_bridges_reset_psci(int enable);

void socfpga_per_reset(u32 reset, int set);
void socfpga_per_reset_all(void);

#define RSTMGR_MPUMODRST_CORE0		0
#define RSTMGR_PER0MODRST_OCP_MASK	0x0020bf00
#define RSTMGR_BRGMODRST_DDRSCH_MASK	0X00000040
#define RSTMGR_BRGMODRST_FPGA2SOC_MASK	0x00000004

/* Watchdogs and MPU warm reset mask */
#define RSTMGR_L4WD_MPU_WARMRESET_MASK	0x000F0F00

/*
 * SocFPGA Stratix10 reset IDs, bank mapping is as follows:
 * 0 ... mpumodrst
 * 1 ... per0modrst
 * 2 ... per1modrst
 * 3 ... brgmodrst
 */
#define RSTMGR_L4WD0		RSTMGR_DEFINE(2, 0)
#define RSTMGR_OSC1TIMER0	RSTMGR_DEFINE(2, 4)
#define RSTMGR_UART0		RSTMGR_DEFINE(2, 16)

#endif /* _RESET_MANAGER_SOC64_H_ */

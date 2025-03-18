//
// Created by fchabcho on 30/08/2024.
//

#ifndef MAIN_H
#define MAIN_H

// Includes
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "check_motor_fault.h"
#include "display_motor_info.h"
#include "motor_init.h"
#include "manage_faults.h"
#include "ETH_public.h"

// Constants
#define MAX_VOLTAGE ((uint32_t)100UL)
#define MAX_CURRENT ((uint32_t)100UL)
#define MAX_TEMP ((uint32_t)100UL)
#define MIN_VOLTAGE ((uint32_t)0UL)
#define MIN_CURRENT ((uint32_t)0UL)
#define MIN_TEMP ((uint32_t)0UL)
#define MAX_SPEED ((uint32_t)1000UL)
#define MIN_SPEED ((uint32_t)0UL)
#define MAX_TORQUE ((uint32_t)100UL)
#define MIN_TORQUE ((uint32_t)0UL)
#define MAX_POWER ((uint32_t)10000UL)
#define MIN_POWER ((uint32_t)0UL)
#define INIT_FAULT_WORD ((uint32_t)0x0000UL)
#define TRUE ((uint32_t)1==1)
#define FALSE ((uint32_t)1==0)

// Type definitions
typedef struct {
	uint32_t s_speed;
	uint32_t s_torque;
	uint32_t s_power;
	uint32_t s_voltage;
	uint32_t s_current;
	uint32_t s_temp;
} ts_Motor_u_bit;

typedef union {
	uint32_t R;
	ts_Motor_u_bit u_bit;
	ethernet_package u_package;
} tu_Motor;

typedef struct {
	uint32_t s_meas1_oc_fault: 1;
	uint32_t s_spare_30: 1;
	uint32_t s_meas1_short_gnd: 1;
	uint32_t s_meas1_out_of_range: 1;
	uint32_t s_meas2_oc_fault: 1;
	uint32_t s_spare_260: 1;
	uint32_t s_meas2_short_gnd: 1;
	uint32_t s_meas2_out_of_range: 1;
	uint32_t s_spare_23_to_08: 16;
	uint32_t s_out_of_range: 1;
	uint32_t s_spare_06_to_05: 2;
	uint32_t s_int_failure: 1;
	uint32_t s_spare_03_to_02: 2;
	uint32_t s_unavailable: 1;
	uint32_t s_invalid: 1;
} ts_fault_word_u_bit;

typedef union {
	uint32_t u_word;
	ts_fault_word_u_bit u_bit;
} tu_fault_word;

typedef struct {
	unsigned int bit31: 1;
	unsigned int bit30: 1;
	unsigned int bit29: 1;
	unsigned int bit28: 1;
	unsigned int bit27: 1;
	unsigned int bit26: 1;
	unsigned int bit25: 1;
	unsigned int bit24: 1;
	unsigned int bit23: 1;
	unsigned int bit22: 1;
	unsigned int bit21: 1;
	unsigned int bit20: 1;
	unsigned int bit19: 1;
	unsigned int bit18: 1;
	unsigned int bit17: 1;
	unsigned int bit16: 1;
	unsigned int bit15: 1;
	unsigned int bit14: 1;
	unsigned int bit13: 1;
	unsigned int bit12: 1;
	unsigned int bit11: 1;
	unsigned int bit10: 1;
	unsigned int bit09: 1;
	unsigned int bit08: 1;
	unsigned int bit07: 1;
	unsigned int bit06: 1;
	unsigned int bit05: 1;
	unsigned int bit04: 1;
	unsigned int bit03: 1;
	unsigned int bit02: 1;
	unsigned int bit01: 1;
	unsigned int transmission_busy: 1; // Example bit
	unsigned int FIFO_parity_error: 1; // Example bit
	unsigned int invalid: 1; // Bit 0 renamed to invalid
} FPGAStatusBits;

// Define a union to hold the full word and the structure of bits for FPGA status register
typedef union {
	unsigned int fullWord;
	FPGAStatusBits bits;
} FPGAStatusRegister;

// Define a structure to hold individual bits in big endian order for fault word register
typedef struct {
	unsigned int bit31: 1;
	unsigned int bit30: 1;
	unsigned int bit29: 1;
	unsigned int bit28: 1;
	unsigned int bit27: 1;
	unsigned int bit26: 1;
	unsigned int bit25: 1;
	unsigned int bit24: 1;
	unsigned int bit23: 1;
	unsigned int bit22: 1;
	unsigned int bit21: 1;
	unsigned int bit20: 1;
	unsigned int bit19: 1;
	unsigned int bit18: 1;
	unsigned int bit17: 1;
	unsigned int bit16: 1;
	unsigned int bit15: 1;
	unsigned int bit14: 1;
	unsigned int bit13: 1;
	unsigned int bit12: 1;
	unsigned int bit11: 1;
	unsigned int bit10: 1;
	unsigned int bit09: 1;
	unsigned int bit08: 1;
	unsigned int bit07: 1;
	unsigned int bit06: 1;
	unsigned int bit05: 1;
	unsigned int bit04: 1;
	unsigned int bit03: 1;
	unsigned int bit02: 1;
	unsigned int bit01: 1;
	unsigned int invalid: 1; // Bit 0 renamed to invalid
} FaultBits;

// Define a union to hold the full word and the structure of bits for fault word register
typedef union {
	unsigned int fullWord;
	FaultBits bits;
} FaultRegister;

// Function prototypes
extern void display_motor_info(tu_Motor motor);

extern void check_motor_faults(tu_Motor motor, tu_fault_word *fault_word);

extern void motor_init(tu_Motor *motor);

extern void manage_faults(tu_Motor *motor, tu_fault_word *fault_word);

extern tu_IP_address *ETH_prepare_package(tu_IP_address *dest_IP);

extern tu_IP_address get_IP_address(void);

extern void ETH_connection_info(void);

extern int ETH_establish_connection(tu_Motor *motor);

extern void readFPGAStatus(FPGAStatusRegister *fpga_Status, FaultRegister *faults);

extern void checkFaults(FaultRegister faults);

extern tu_IP_address IP_address;
extern tu_Motor motor;

extern FPGAStatusRegister fpgaStatus;

extern FaultRegister componentFaults;


#endif //MAIN_H

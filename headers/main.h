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

// Constants
#define MAX_VOLTAGE 100
#define MAX_CURRENT 100
#define MAX_TEMP 100
#define MIN_VOLTAGE 0
#define MIN_CURRENT 0
#define MIN_TEMP 0

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

// Function prototypes
void display_motor_info(tu_Motor motor);

void check_motor_faults(tu_Motor motor, tu_fault_word *fault_word);

void motor_init(tu_Motor *motor);

#endif //MAIN_H

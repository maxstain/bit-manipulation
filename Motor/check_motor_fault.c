//
// Created by fchabcho on 30/08/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/check_motor_fault.h"

/* ======= Type definitions and global variables and constants ======= */


/* ======= Function implementations ======= */
void check_motor_faults(tu_Motor motor, tu_fault_word *fault_word) {
	
	fault_word->u_word = 0x0000;
	
	if (motor.u_bit.s_torque > 100UL) {
		fault_word->u_bit.s_meas1_oc_fault = 1;
	}
	
	if (motor.u_bit.s_power > 100UL) {
		fault_word->u_bit.s_meas1_short_gnd = 1;
	}
	
	if ((motor.u_bit.s_voltage > MAX_VOLTAGE) || (motor.u_bit.s_voltage < MIN_VOLTAGE)) {
		fault_word->u_bit.s_meas1_out_of_range = 1;
	}
	
	if ((motor.u_bit.s_current > MAX_CURRENT) || (motor.u_bit.s_current < MIN_CURRENT)) {
		fault_word->u_bit.s_meas2_oc_fault = 1;
	}
	
	if ((motor.u_bit.s_temp > MAX_TEMP) || (motor.u_bit.s_temp < MIN_TEMP)) {
		fault_word->u_bit.s_meas2_short_gnd = 1;
	}
	
	if ((motor.u_bit.s_speed > MAX_SPEED) || (motor.u_bit.s_speed < MIN_SPEED)) {
		fault_word->u_bit.s_meas2_out_of_range = 1;
	}
}

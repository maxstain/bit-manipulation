//
// Created by fchabcho on 02/09/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/manage_faults.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */
void manage_faults(tu_Motor *motor, tu_fault_word *fault_word) {
	
	if (fault_word->u_bit.s_meas1_oc_fault) {
		printf_s("Overcurrent fault detected\n");
	}
	
	if (fault_word->u_bit.s_meas1_short_gnd) {
		printf_s("Short to ground fault detected\n");
	}
	
	if (fault_word->u_bit.s_meas1_out_of_range) {
		printf_s("Voltage out of range fault detected\n");
	}
	
	if (fault_word->u_bit.s_meas2_oc_fault) {
		printf_s("Overcurrent fault detected\n");
	}
	
	if (fault_word->u_bit.s_meas2_short_gnd) {
		printf_s("Short to ground fault detected\n");
	}
	
	if (fault_word->u_bit.s_meas2_out_of_range) {
		printf_s("Speed out of range fault detected\n");
	}
	
	// A reset is needed to clear the fault and allow the motor to operate again
	motor_init(motor);
	
}

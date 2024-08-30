//
// Created by fchabcho on 30/08/2024.
//

/* ======= Includes and definitions ======= */
#include "../headers/motor_init.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */
void motor_init(tu_Motor *motor) {
	motor->R = 0;
	motor->u_bit.s_torque = 0;
	motor->u_bit.s_power = 0;
	motor->u_bit.s_voltage = 0;
	motor->u_bit.s_current = 0;
	motor->u_bit.s_temp = 0;
}
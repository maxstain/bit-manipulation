//
// Created by fchabcho on 30/08/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/display_motor_info.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */
void display_motor_info(tu_Motor motor) {
	printf_s("Torque:           %d%%\n", motor.u_bit.s_torque);
	printf_s("Power:            %d%%\n", motor.u_bit.s_power);
	printf_s("Voltage:          %d%%\n", motor.u_bit.s_voltage);
	printf_s("Current:          %d%%\n", motor.u_bit.s_current);
	printf_s("Temperature:      %d%%\n", motor.u_bit.s_temp);
	printf_s("Speed:            %d%%\n", motor.u_bit.s_speed);
}

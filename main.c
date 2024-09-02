#include "headers/main.h"

int main(void) {
	tu_fault_word fault_word;
	
	tu_Motor motor;
	
	motor_init(&motor);
	while (TRUE) {
		system("cls");
		printf_s("Enter torque: ");
		if (scanf_s("%u", &motor.u_bit.s_torque) != 1) {
			printf_s("Invalid input. Please enter a valid integer.\n");
			continue;
		}
		motor.u_bit.s_speed = motor.u_bit.s_torque * 10UL;
		motor.u_bit.s_temp = motor.u_bit.s_torque;
		display_motor_info(motor);
		check_motor_faults(motor, &fault_word);
		if (fault_word.u_word != 0) {
			printf_s("Fault detected: %u\n", fault_word.u_word);
			manage_faults(&motor, &fault_word);
			printf_s("Motor reset\n");
			display_motor_info(motor);
		} else {
			printf_s("No fault detected\n");
		}
		
		if (motor.u_bit.s_torque == 0) {
			break;
		}
	}
	
	return 0;
}
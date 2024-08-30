#include "headers/main.h"

int main(void) {
	tu_fault_word fault_word = {0};
	tu_Motor motor = {0};
	
	motor_init(&motor);
	while (1) {
		system("cls");
		printf_s("Enter torque: ");
		if (scanf_s("%u", &motor.u_bit.s_torque) != 1) {
			printf_s("Invalid input. Please enter a valid integer.\n");
			continue;
		}
		display_motor_info(motor);
		check_motor_faults(motor, &fault_word);
		if (fault_word.u_word != 0) {
			printf_s("Fault detected: %u\n", fault_word.u_word);
			break;
		} else {
			printf_s("No fault detected\n");
		}
	}
	
	return 0;
}
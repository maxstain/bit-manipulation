//
// Created by fchabcho on 09/09/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/main.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */

int ETH_establish_connection(tu_Motor *motor) {
	motor->u_package.u_dest_MAC.u_addr = ETH_DFT_MAC_ADDR;
	motor->u_package.u_type = ETH_TYPE_IP;
	printf_s("\n");
	printf_s("Connect to the destination IP address? (y/n): ");
	char choice;
	do {
		choice = getchar();
		if (choice == 'y') {
			printf_s("Connected to the destination IP address\n");
			ETH_connection_info();
		} else if (choice == 'n') {
			printf_s("Connection refused\n");
		} else {
			printf_s("Invalid input. Please enter 'y' or 'n'.\n");
		}
	} while (choice == '\n');
}

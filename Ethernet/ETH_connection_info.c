//
// Created by fchabcho on 09/09/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/main.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */
void ETH_connection_info(void) {
	printf_s("Ethernet information.\n");
	printf_s("IP address: %u.%u.%u.%u\n", IP_address.u_IP_byte[0], IP_address.u_IP_byte[1],
	         IP_address.u_IP_byte[2], IP_address.u_IP_byte[3]);
	printf_s("MAC address: %u:%u:%u:%u:%u:%u\n", motor.u_package.u_dest_MAC.u_MAC[0],
	         motor.u_package.u_dest_MAC.u_MAC[1], motor.u_package.u_dest_MAC.u_MAC[2],
	         motor.u_package.u_dest_MAC.u_MAC[3],
	         motor.u_package.u_dest_MAC.u_MAC[4], motor.u_package.u_dest_MAC.u_MAC[5]);
}

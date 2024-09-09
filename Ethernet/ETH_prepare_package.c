//
// Created by fchabcho on 09/09/2024.
//

/* ======= Includes and definitions ======= */

#include "../headers/ETH_public.h"

/* ======= Type definitions and global variables and constants ======= */



/* ======= Methods and functions ======= */
void ETH_prepare_package(tu_IP_address *dest_IP) {
	dest_IP->u_IP_byte[0] = 192;
	dest_IP->u_IP_byte[1] = 168;
	dest_IP->u_IP_byte[2] = 1;
	dest_IP->u_IP_byte[3] = 1;
	
}

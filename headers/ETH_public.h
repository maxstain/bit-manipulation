//
// Created by fchabcho on 09/09/2024.
//

#ifndef ETH_PUBLIC_H
#define ETH_PUBLIC_H

// This is the header file for the Ethernet module. It contains the type definitions and the function prototypes.

#include <stdint.h>

// Defines
#define ETH_TYPE_IP ((uint16_t)0x0800)
#define ETH_TYPE_ARP ((uint16_t)0x0806)
#define ETH_TYPE_RARP ((uint16_t)0x8035)
#define ETH_TYPE_VLAN ((uint16_t)0x8100)
#define ETH_TYPE_IPV6 ((uint16_t)0x86DD)
#define ETH_TYPE_PPPoE_DISC ((uint16_t)0x8863)
#define ETH_TYPE_PPPoE_SESS ((uint16_t)0x8864)
#define ETH_MAC_ADDR_LEN 6
#define ETH_DFT_MAC_ADDR ((uint32_t)0xFFFFFFFFFFFF)

// Type definitions
typedef union {
	uint32_t u_IP;
	uint8_t u_IP_byte[4];
} tu_IP_address;

typedef union {
	uint32_t u_addr;
	uint8_t u_MAC[6];
} tu_MAC_address;

typedef struct {
	tu_MAC_address u_dest_MAC;
	uint8_t u_src_MAC[6];
	uint16_t u_type;
	uint8_t u_data[1500];
	uint32_t u_CRC;
} ethernet_package;

#endif //ETH_PUBLIC_H

//
// Created by fchabcho on 19/03/2025.
//

/* ======= Includes and definitions ======= */
#include "../headers/a429_transmission.h"

// Function to calculate the Bitwise OR of bits 01 to 31 and store in invalid (bit 0)
void updateInvalid(FaultRegister *faults) {
	unsigned int result = 0;
	for (int i = 1; i <= 31; i++) {
		result |= ((unsigned int *) faults)[i];
	}
	faults->bits.invalid = result ? 1 : 0;
}

// Function to check faults
void checkFaults(FaultRegister faults) {
	if (faults.bits.invalid) {
		printf("Invalid bit (OR of bits 01-31) is set\n");
	}
	// Add checks for other faults as needed
}

// Function to read FPGA status and update fault register
void readFPGAStatus(FPGAStatusRegister *fpga_Status, FaultRegister *faults) {
	faults->fullWord = fpga_Status->fullWord;
	faults->bits.invalid = fpga_Status->bits.transmission_busy | fpga_Status->bits.FIFO_parity_error;
	updateInvalid(faults);
}
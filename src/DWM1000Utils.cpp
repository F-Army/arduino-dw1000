#include <Arduino.h>
#include "DWM1000Utils.h"

namespace DWM1000Utils {
	/*
	* Set the value of a bit in an array of bytes that are considered
	* consecutive and stored from MSB to LSB.
	* @param data
	* 		The number as byte array.
	* @param n
	* 		The number of bytes in the array.
	* @param bit
	* 		The position of the bit to be set.
	* @param val
	*		The boolean value to be set to the given bit position.
	*/
	void setBit(byte data[], uint16_t n, uint16_t bit, boolean val) {
		uint16_t idx;
		uint8_t shift;
		
		idx = bit/8;
		if(idx >= n) {
			return; // TODO proper error handling: out of bounds
		}
		byte* targetByte = &data[idx];
		shift = bit%8;
		if(val) {
			bitSet(*targetByte, shift);
		} else {
			bitClear(*targetByte, shift);
		}
	}

	/*
	* Check the value of a bit in an array of bytes that are considered
	* consecutive and stored from MSB to LSB.
	* @param data
	* 		The number as byte array.
	* @param n
	* 		The number of bytes in the array.
	* @param bit
	* 		The position of the bit to be checked.
	*/
	boolean getBit(byte data[], uint16_t n, uint16_t bit) {
		uint16_t idx;
		uint8_t  shift;
		
		idx = bit/8;
		if(idx >= n) {
			return false; // TODO proper error handling: out of bounds
		}
		byte targetByte = data[idx];
		shift = bit%8;
		
		return bitRead(targetByte, shift); // TODO wrong type returned byte instead of boolean
	}

	void writeValueToBytes(byte data[], int32_t val, uint16_t n) {
		uint16_t i;
		for(i = 0; i < n; i++) {
			data[i] = ((val >> (i*8)) & 0xFF); // TODO bad types - signed unsigned problem
		}
	}
}


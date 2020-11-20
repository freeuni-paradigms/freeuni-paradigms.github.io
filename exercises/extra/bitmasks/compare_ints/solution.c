#include "compare_ints.h"

//Compares bits of the elements one after another from the most significant bit to the least significant bit. 
int compareIntsWithoutSignBit(int a, int b){
	unsigned int mask = 1;
	mask = mask << 30;
	//Does not take sign bit into account.
	for(int i = 0 ; i < 31; i++){
		if((a & mask)){
			if((b & mask) == 0){
				return a;
			}
		}else{
			if((b & mask)){
				return b;
			}
		}
		mask = mask >> 1;
	}
	return a;
}


//At first compares sign bits, if they are equal, then compares other bits.
int compareInts(int a, int b){
	unsigned int mask = 1;
	mask = mask << 31;
	if((a & mask)){
		if((b & mask) == 0){
			return b;
		} else {
			if(compareIntsWithoutSignBit(-a, -b) == -a){
				return b;
			}
			return a;
		}
	}else{
		if((b & mask)){
			return a;
		} else {
			return compareIntsWithoutSignBit(a, b);
		}
	}
}

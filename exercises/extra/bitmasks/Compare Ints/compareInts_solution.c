#include "compareInts.h"

int compare(int a, int b){
	unsigned int mask = 1;
	mask = mask << 31;
	for(int i = 0 ; i < 32; i++){
		if((mask & a)){
			if((mask & b) == 0) return a;
		}else{
			if((mask & b)) return b;
		}
		mask = mask/2;
	}
	return a;
}

int compareInts(int a, int b){
	unsigned int mask = 1;
	mask = mask << 31;
	if((mask & a)){
		if((b & mask) == 0){
			return b;
		} else {
			if(compare(-a, -b) == -a) return b;
			return a;
		}
	}else{
		if((b & mask)){
			return a;
		} else {
			return compare(a, b);
		}
	}
}

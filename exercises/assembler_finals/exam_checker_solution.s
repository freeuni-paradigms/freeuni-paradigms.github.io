// we recommend writing basic offsets here
// variables, struct members, struct sizes



// CheckPassed
// line 1
// return ((Student*)student)->score > 40;
R1 = M[SP + 4]
R2 = R1 + 12
R2 = M[R2]
BGT R2 40 PC + 12
RV = 0
RET
RV = 1
RET

// NumPassedThreshold
SP = SP - 8

// line 1
// int count = 0;
M[SP + 4] = 0


// line 2
// for (int i = 0; i < list.n; ++i) {
M[SP] = 0
R1 = M[SP]
R2 = M[SP + 12]
BGE R1 R2 PC + 17 * 4

	
// line 3
// if (CheckPassed((Student*)list.students + i)) {
R1 = M[SP + 16]
R2 = M[SP]
R3 = R2 * 16
R4 = R1 + R3
SP = SP - 4
M[SP] = R4
CALL <CheckPassed>
SP = SP + 4
BEQ RV 0 PC + 16


	
// line 4
// ++count;
R1 = M[SP + 4]
R2 = R1 + 1
M[SP + 4] = R2


	
// line 5
// } end of if statement, skip if necessary



	
// line 6 
// } end of for loop, skip if necessary
R1 = M[SP]
R2 = R1 + 1
M[SP] = R2

JMP PC - 18 * 4


	
// line 7
// return count;
RV = M[SP + 4]
SP = SP + 8
RET
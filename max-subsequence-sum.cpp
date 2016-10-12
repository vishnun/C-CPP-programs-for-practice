/*
	maximum subsequence sum.
	say you have a sequence
	S = -2, -3, 4, -1, -2, 1, 5, -3
	What is the maximum sum for a contiguous sub sequence.	
	Ans: 7 (4, -1, -2, 1, 5)
	
*/

#include <stdio.h>
#include<conio.h>

int maxSum(int S[], int n) {
	int max_so_far = 0;
	int max_ending_here = 0;
	for(int i=0;i<n;i++) {
		max_ending_here += S[i];
		if(max_ending_here < 0) {
			max_ending_here =0;
		}
		if(max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
		}
	}
	return max_so_far;
}


int main() {
	int s[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	printf("Sum: %d\n", maxSum(s,8));
	return 0;
}

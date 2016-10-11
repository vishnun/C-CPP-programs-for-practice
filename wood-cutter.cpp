// Wood cutter problem. Dynamic programming.
/*
	Vishnu Narang:
	
	Question: 
	Suppose you have a wood block of length n inches.
	You also have costs of wood of length l inches (where l goes from 1 to n)
	i.e. <c1,c2,c3...cl> is known.
	
	What is the optimal way to cut the wood of length n such that you get maximum profit.
	i.e. sum of all (C)s should be maximum.
	
	Eg:
	
	input n=4, C=[1,7,10,13]
	output:
	Max cost of wood: 14 (from 2 blocks of 2 inches each)
	
*/

#include <stdio.h>
#include <conio.h>

int max(int one, int two) {
	if(one >= two) {
		return one;
	}
	return two;
}

int optimalCostOfWood(int n, int c[]) {
	if(n == 0) {
		return 0;
	}
	int maxCost = 0;
	for(int i=1; i<=n; i++){
		maxCost = max(maxCost, c[i-1] + optimalCostOfWood(n-i,c));
	} 
	return maxCost;
}


int main() {
	
	int result = 0;
	int costs[] = {1,7,10,13};
	result = optimalCostOfWood(4, costs);
	printf("%d\n", result);
	
	return 0;
}

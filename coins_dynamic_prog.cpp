#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// Dynamic programming technique.
// Count the sum with each weight and having chosen a weight, get the remaining sum from the remaining weights.

long int count(long weights[], long numberOfWeights, long sum) {
    //  When we find the weights which satisfy the sum.
	if(sum == 0) {
        return 1;
    }
    //	If sum has gone below 0, the last weight wasn't good for the count
    if(sum < 0) {
        return 0;
    }
	//    If no more weights are remaining and the final sum is still not satisfied
    if(numberOfWeights<=0 && sum>0) {
        return 0;
    }
    return count(weights, numberOfWeights-1, sum) + count(weights, numberOfWeights, sum-weights[numberOfWeights-1]);
}

long count2( long S[], long m, long n ){
  long table[n+1][m+1];
  for(long i=0; i<=n; i++){
    for (long j=0; j<=m; j++) {
        table[i][j]=0;
    }
  }
  for(long i=0; i<=n; i++){
    for (long j=0; j<=m; j++) {
      if(i == 0){
         table[i][j] = 1;
      }          
      else if (j == 0){
         if( i%S[j] == 0){
             table[i][j] = 1;
         }
         else{ 
             table[i][j] = 0;
         }
      }
      else if (S[j] > i){
         table[i][j] = table[i][j - 1];
      }
      else{
         table[i][j] = table[i - S[j]][j] + table[i][j-1];
      }
    }
  }
  return table[n][m];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int start, end, numberOfWeights;
    long int numberOfCombinations=0;
    printf("Enter number of weights: ");
    scanf("%ld", &numberOfWeights);
    long int weights[numberOfWeights];
    printf("Enter the weights: ");
    for(long i=0;i<numberOfWeights;i++){
        scanf("%ld", &weights[i]);    
    }
    printf("Enter the start and end (for which you want to find change): ");
    scanf("%ld %ld",&start,&end);
    while(start<=end){
        numberOfCombinations+=count2(weights,numberOfWeights,start++);
    }
    printf("%ld", numberOfCombinations);
    return 0;
}


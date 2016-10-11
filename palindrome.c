#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s) {
 
    int len = strlen(s);
    int left = 0, right = len-1;
    while(left <= right) {
        if(s[left++] != s[right--]) {
            return 0;
        }
    }
    return 1;
}
int main() {
	char s[] = "le";
	printf("Is palindrome: %d", isPalindrome(s));
	return 0;
}

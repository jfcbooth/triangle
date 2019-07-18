#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void draw(int n){
	int l = n-1;
	for(int i = 1; i <= n; i++){ // Iterates through until n
		int spaces = 0; // Next 2 lines find left whitespace
		for(int j = l--; j > 0; j--){ // n-1 stops spaces from counting for center num
			spaces += floor(log10(j)) + 2; // Find left-side whitespace (+1 accounts for whitespace)
		}
		for(int j = spaces; j > 0; j--){ // Prints correct # of whitespace on left
			printf(" ");
		}
		for(int j = 1; j < i*2; j++){ // Prints numbers going up
			printf("%d", i - abs(j - i));
			for(int k = (floor(log10(n - (i - (i - abs(j-i))))) + 2) - (floor(log10((i- abs(j-i)))) + 1); k > 0; k--){
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void){
	draw(11);	
}

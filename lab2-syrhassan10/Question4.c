#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i =0;
	int index = 0;
	int count =0;
	int asci = 65;

		//scan the whole array alphabetically and add to count;
		count =0;
	for (int j =0;j<26;j++){
		count=0;
		i =0;
		while(word[i]!='\0'){


			if ((word[i]==asci)||(word[i]==(asci+32))){
				count+=1;
			}
			i++;

		}
		asci+=1;

		freq[index++] = count;



	}




   
}

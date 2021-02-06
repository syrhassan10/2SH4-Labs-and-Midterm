#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){


	int indexPos =0;

	for (int i =0;i<k1;i++){
		for (int j =0;j<k2;j++){

			if (pos1[i]==pos2[j]){
				val3[indexPos] = val1[i]+ val2[j];
				pos3[indexPos] = pos1[i];
				indexPos+=1;
				break;

			}
			else if (pos1[i]<pos2[j]){
				val3[indexPos] = val1[i];
				pos3[indexPos] = pos1[i];
				indexPos+=1;
				break;
			}
			else{
				if (pos2[j]>pos3[indexPos-1]){

					val3[indexPos] = val2[j];
					pos3[indexPos] = pos2[j];
					indexPos+=1;
				}
				if (j == (k1-1)){
					val3[indexPos] = val1[i];
					pos3[indexPos] = pos1[i];
				}
			}
		}
	}
}

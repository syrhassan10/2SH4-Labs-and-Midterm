#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	int temp =0;
	int sum =0;
	int counter=0;
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	for (int i=0;i<N2;i++){
		sum=0;
		for (int j=0;j<N2;j++){
			if(i==j){
				temp = mat[i][j];
			}
			else{
				sum+=fabs(mat[i][j]);
			}
		}
		if(fabs(temp)>=sum){
			counter+=1;

		}
	}
	if(counter==N2){
		isDiag=1;
	}


    return isDiag;
}

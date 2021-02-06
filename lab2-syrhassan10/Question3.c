#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


void diag_scan(int mat [][N3], int arr []){
	int limit = N3*N3;
	int *p = (int *) malloc(limit * sizeof(int));
	int inc =0;
	int tempi =0;
	int tempj =0;
	// You can improve this code by removing the first for loop;
	for(int i =0;i<N3;i++){
		if(i==0){
			//append to array and move on to next row

			*(p + inc) = mat[0][0];
			inc+=1;

		}
		else if (i<=(N3-1)){

			tempi =i;
			tempj =0;
				while(1){

					if(tempi==0){

						*(p + inc) = mat[tempi][tempj];
						inc+=1;
						break;
					}else{
						*(p + inc) = mat[tempi][tempj];
						inc+=1;
						tempj+=1;
						tempi-=1;
					}
				}
		}

	}
		tempi = N3-1;
		tempj = 1;
		int low  =1;
		while(1) {

			if ((tempj)>(N3-1)){
				*(p + inc) = mat[tempi][tempj];
				inc+=1;
				tempi=N3-1;
				tempj+=1;
				low+=1;
			}else{
				*(p + inc) = mat[tempi][tempj];
				inc+=1;
				tempj+=1;
				tempi-=1;

			}
			if (low==N3){
				break;
			}
		}
	int loop =0;
			for(loop = 0; loop < limit; loop++)
				arr[loop]=p[loop];
}

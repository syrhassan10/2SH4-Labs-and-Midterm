


#include <stdio.h>

void firstAppear(int a[], int b[], int size_a, int size_b, int c[]);
void numberPattern(int n);

void bugDetection();

int main (){

 // test your questions here as required.
	//Q1

	int x[] =  {8,23,41,100,-9};
	int y[] = {100, -9,41,87,41,-9,-9};
	int z[5];
	firstAppear(x, y,5, 7, z);
	int loop =0;
	for(loop = 0; loop < 5; loop++){
		printf("%d ",z[loop]);
	}
	printf("\n Q2: ");



	//Q2**************************************
	numberPattern(5);
	printf("\n");

	//Q3**************************************
	bugDetection();

   return 0;
}



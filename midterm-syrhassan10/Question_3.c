


/*
The program below is supposed to take a number entered by the user and calculate its factorial. 
Factorial of a positive integer n is product of all values from n to 1. 
For example, the factorial of 3 is (3 * 2 * 1 = 6).

The program has few bugs... you are required to correct them such that the program works as intended
Please note that these bugs will not necessarily trigger compiler syntax error. So, the program might build successfully. 
They are rather logical bugs.
*/


#include <stdio.h>

void bugDetection() {
   int i =0;
   int factorial=1;
   int number;
   
   printf("please Enter a number : ");
   scanf("%d",&number);
   i =number;
	 while(i>0){

	 
	 	factorial*=i;
	 	i--;
	 
	 }


   printf("Factorial of %d = %d \n", number, factorial);

   
}

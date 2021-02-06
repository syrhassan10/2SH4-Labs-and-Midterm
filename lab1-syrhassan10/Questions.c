
#include "Questions.h"



int Q1_for(){
	int sum=0;
	int i = 0;
	// calculate your sum below..this has to use for loop
	for (i=30;i<=1000;i++){
		if (i%4==0){
			sum+=i;			
		}
	}
	


	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum=0;
	int i = 30;
	while (i<=1000){
		if(i%4==0){
			sum+=i;
		}
		i+=1;
	}



	// calculate your sum below..this has to use while loop
	
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum=0;
	
	// calculate your sum below..this has to use do-while loop
	int i =30;
	do {

	if(i%4==0){
			sum+=i;
		}
		i+=1;
	}while(i<=1000);
	  

	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
	
	if((Q2_input>=10000 && Q2_input<=99999) ||(Q2_input<=-10000 && Q2_input>=-99999)  ){
		IsFiveDigit = 1;
	}
	else{
		IsFiveDigit = 0;
	}

	            
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and prints:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should print a message to signal an invalid input.
*/	
	// this is the varaible that holds the out value to return
	int GPA;
	

	if (Q3_input>=90 && Q3_input<=100){
		GPA = 4;
	}
	else if(Q3_input>=80 && Q3_input<=89){
		GPA = 3;

	}
	else if(Q3_input>=70 && Q3_input<=79){
		GPA = 2;
	}
	else if(Q3_input>=60 && Q3_input<=69){
		GPA = 1;
	}
	else if(Q3_input>=0 && Q3_input<=59){
		GPA = 0;
	}
	else {

		GPA = -1;
	}
	
	// Do your coding below to calculate the GPA variable value
	
	 
	
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi;
	double f =1;
	double sum = 0;
	double count  = 1;
	for (int i = 1;i<=Q4_input;i++){
		sum +=(4/count)*f;
		count+=2;
		f= -1*f;
	}
	
	pi = sum;
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		print each triple on a separate line, 
		and update the total number of triples if needed
	*/
	int temp1=0;
	int temp2=0;
	int counter=0;

	int i, j, k=0;
	for (i =1;i<400;i++){

		for(j=1;j<400;j++){

			for (k =1;k<=400;k++){
					if (i<=j){
						temp1 = i*i;
						temp2 = j*j;
						if (temp1+temp2==(k*k)){
							counter+=1;

						}

					}

			}

		}
	}
	totNumTribles = counter;

	//this is the format that you MUST print the found tribles..uncomment this line and fill in the missings to get it working correctly
	//printf("A trible found: side1=%d, side2=%d, side3=%d\n", ...)
	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
		// CHECK Unit tests ------wrongh
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
	    int temp=0;

	    int temp2=0;

	    for (int i =1;i<=Q6_input;i++){
	    	temp = 0;
	    	for (int j = 1;j<i;j++){

	    		if(i%j==0){
	    			temp+=j;
	    		}
	    	}

	    	if (temp==i){
	    		counts+=1;
	    		perfect[temp2++]=i;
	    	}


	    }




		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    
		
		
		
		

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	int temp = 0;
	for (int i =0;i<7;i++){
		temp = (Q7_input%10);
		reversedInt = (reversedInt*10)+temp;
		Q7_input = Q7_input/10;
	}




	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	
	
		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	int temp = 0;

	while(1){
		temp = (Q7b_input%10);
		reversedInt = (reversedInt*10)+temp;
		Q7b_input = Q7b_input/10;
		if (!(Q7b_input>0)){
			break;
		}
	}



	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	
	
	return reversedInt;

	
	
	
}

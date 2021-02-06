


/*********************
 **PART A**
**********************

Write a function that takes an integer n as input and prints the following pattern on the screen:
n (n times)
n-1 (n-1 times)
.
.
1 (1 time)
For example, if n was 5, the function should print

5 5 5 5 5
4 4 4 4
3 3 3
2 2
1

You are given the prototype below
*/

void numberPattern(int n){

	for(int i =n;i>=1;i--){

		for (int j=0;j<i;j++){
			printf("%d ",i);
		}
		printf("\n");

	}




}


/*********************
 **PART B**
**********************
/*test your function in the main in the Midterm_main.c*/

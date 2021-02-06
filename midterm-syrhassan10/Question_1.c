

/*********************
 **PART A**
**********************
Write a function that takes two arrays as input a and b as well as their sizes: size_a and size_b, respectively. 
Then for each element in a: it finds the index of the first appearance of this element in b and places this index in a third array c.
If the element does not exist in b, it places -1 in c.
You are given the prototype below
 Assume that array a does not contain repetitions. 
 
Example: If array a contains [8,23,41,100,-9], and array b contains [100, -9,41,87,41,-9,-9], 
then the function should update c to be: [-1,-1,2,0,1]
*/

void firstAppear(int a[], int b[], int size_a, int size_b, int c[]){

	int *p = c;
	int temp;
	int index =0;
	for (int i =0;i<size_a;i++){
		temp= 0;
		for (int j =0;j<size_b;j++){
			if (a[i]==b[j]){
				temp = j;
				break;
			}
			else{
				temp =-1;
			}
		}

		*p++ = temp;
	}



}


/*********************
 **PART B**
**********************
/*test your function in the main in the Midterm_main.c*/

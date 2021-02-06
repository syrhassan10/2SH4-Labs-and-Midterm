#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;
    char *temp;
    /*write your implementation here*/
	FILE *input_file=fopen(input_filename, "r");
	fscanf(input_file,"%d",nPtr);
	word_list = malloc(*nPtr*sizeof(word_list));
	for (int i =0;i<*nPtr;i++){
		fscanf(input_file,"%s",*temp);
		int k = strlen(*temp);

		word_list[i] = malloc(k*sizeof(char));
		word_list[i] =temp;

	}



    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	if (*str2<*str1){
		return 1;
	}else if (*str2>*str1){
		return 0;
	}else{
		return -1;
	}

    
}

void sort_words(char **words, int size){
   
	/*write your implementation here*/
}

void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/
}

void sort2_words(char **words, int size){

   
	/*write your implementation here*/
    
}


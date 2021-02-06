#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){


	/* this is the pointer holding the string to return */
	char *z = NULL;

	/*write your implementation here*/
	// getting the size of each string to allocate for new string
	int len1,len2 =0;
	len1 = strlen(str1);
	len2 = strlen(str2);

	z = malloc ((len1+len2+1)*sizeof(char));

	for (int i =0;i<len1;i++){
		z[i] = str1[i];
	}
	for (int i =0;i<len2;i++){
			z[i+len1] = str2[i];
	}
	z[len1+len2] = '\0';

	/* finally, return the string*/

	return z;
	
}

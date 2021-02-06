#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;

	FILE *input_file=fopen(filename, "r");

	fscanf(input_file,"%d",sizePtr);


	class_list = malloc(*sizePtr*sizeof(class_list));


	/*write your implementation here*/
	for (int i  =0;i<*sizePtr;i++){
		class_list[i]=calloc(1,sizeof(student));
		fscanf(input_file,"%d %s %s\n",&(class_list[i]->student_id),class_list[i]->first_name,class_list[i]->last_name);
	}

	fclose(input_file);




	/* finally return the created class list*/
	return class_list;
}


int find(int idNo, student **list, int size)
{
	for (int i =0;i<size;i++){
		if ((list[i]->student_id)==idNo){
			return i;
		}
	}
	/*write your implementation here and update the return accordingly*/
	return -1;
}

void input_grades(char *filename, student **list, int size)
{
	int temp1 =0;
	int temp2=0;
	int id=0;
	FILE *input_file=fopen(filename, "r");
	for(int i=0;i<size;i++){
		fscanf(input_file,"%d %d %d\n",&id,&temp1,&temp2);
		(list[find(id,list,size)]->project1_grade)=temp1;
		(list[find(id,list,size)]->project2_grade)=temp2;
	}
	fclose(input_file);
	/*write your implementation here*/

}

void compute_final_course_grades(student **list, int size)
{
	
	for (int i =0;i<size;i++){
		(list[i]->final_grade)=(double)((list[i]->project1_grade)+(list[i]->project2_grade))/2;
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	FILE *output_file=fopen(filename, "w");
	fprintf(output_file,"%d\n",size);

	for (int i =0;i<size;i++){
		fprintf(output_file,"%d %lf\n",(list[i]->student_id),(list[i]->final_grade));
	}

	fclose(output_file);

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int index= 0;
	index = find(idNo,list,*sizePtr);
	if (index ==-1){
		printf("Student not found");
		return;
	}
	student *temp = calloc(1,sizeof(student));
	for (int i=index;i<(*sizePtr)-1;i++){
		temp = list[i];
		list[i] = list[i+1];
		list[i+1] = temp;
		if (i == *sizePtr-2){
			free(list[i]);
		}


	}
	*sizePtr-=1;
}




void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for (int i =0;i<*sizePtr;i++){
		free(list[i]);
	}
	free(list);
	*sizePtr =0;
}

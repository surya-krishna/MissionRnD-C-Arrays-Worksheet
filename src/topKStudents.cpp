/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	int student_num,check,count=-1,count_k=K,index=0;
	
	if (K <= 0 || len <= 0)
	{

		return NULL;
	}

	student **top_k=(student**)malloc(sizeof(student)*K);
	
	

	for (student_num = 0; student_num < len; student_num++)
	{
		count = -1;
		for (check = 0; check < len; check++)
		{
			if (students[student_num].score<=students[check].score)
				count++;
		}
		if (count < K && count!=-1)
		{
			count_k--;
			top_k[index]=&students[student_num];
			index++;
		}
		if (count_k == 0)
			break;
	}

	return top_k;
}
#include "Student.h"
#include "Global.h"

#include <stdio.h>

int main() {
	Student S1;

	S1.SetName(new char[33] {"asfjagkdfafjasldfjadkjfaldjfkald"});
	printf("Numele este: %s\n", S1.GetName());

	S1.SetName(new char[7] {"Andrei"});
	printf("Numele este: %s\n", S1.GetName());

	S1.SetMathGrade(9.7);
	printf("Nota la mate este: %f\n", S1.GetMathGrade());

	S1.SetHistoryGrade(5.7);
	printf("Nota la istorie este: %f\n", S1.GetHistoryGrade());

	S1.SetEnglishGrade(8.5);
	printf("Nota la engleza este: %f\n", S1.GetEnglishGrade());

	printf("Media notelor este: %f\n", S1.GetAverageGrade());

	Student S2;
	S2.SetName(new char[8] {"Andreea"});
	S2.SetMathGrade(10);
	S2.SetHistoryGrade(4.3);
	S2.SetEnglishGrade(7.2);

	printf("Comparam numele: %d\n", CompareByName(&S1, &S2));
	printf("Comparam nota la mate: %d\n", CompareByMathGrade(&S1, &S2));
	printf("Comparam nota la istorie: %d\n", CompareByHistoryGrade(&S1, &S2));
	printf("Comparam nota la engleza: %d\n", CompareByEnglishGrade(&S1, &S2));
	printf("Comparam media notelor: %d\n", CompareByAverageGrade(&S1, &S2));

	return 0;
}
#include "Student.h"

void Student::SetName(char* str) {
	char i;
	for (i = 0; i < 31 && str[i]; i++)
		name[i] = str[i];
	name[i] = '\0';
}

char* Student::GetName() {
	return name;
}

void Student::SetMathGrade(float newMathGrade) {
	if(newMathGrade < 0 || newMathGrade > 10) return;
	this->MathGrade = newMathGrade;
}

float Student::GetMathGrade() {
	return this->MathGrade;
}

void Student::SetEnglishGrade(float newEnglishGrade) {
	if(newEnglishGrade < 0 || newEnglishGrade > 10) return;
	this->EnglishGrade = newEnglishGrade;
}

float Student::GetEnglishGrade() {
	return this->EnglishGrade;
}

void Student::SetHistoryGrade(float newHistoryGrade) {
	if(newHistoryGrade < 0 || newHistoryGrade > 10) return;
	this->HistoryGrade = newHistoryGrade;
}

float Student::GetHistoryGrade() {
	return this->HistoryGrade;
}

float Student::GetAverageGrade() {
	return (MathGrade + HistoryGrade + EnglishGrade) / 3.;
}

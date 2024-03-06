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
	this->MathGrade = newMathGrade;
}

float Student::GetMathGrade() {
	return this->MathGrade;
}

void Student::SetEnglishGrade(float newEnglishGrade) {
	this->EnglishGrade = newEnglishGrade;
}

float Student::GetEnglishGrade() {
	return this->EnglishGrade;
}

void Student::SetHistoryGrade(float newHistoryGrade) {
	this->HistoryGrade = newHistoryGrade;
}

float Student::GetHistoryGrade() {
	return this->HistoryGrade;
}

float Student::GetAverageGrade() {
	return (MathGrade + HistoryGrade + EnglishGrade) / 3.;
}

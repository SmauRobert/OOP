#pragma once
class Student {
	char name[32];
	float MathGrade;
	float EnglishGrade;
	float HistoryGrade;

public:
	void SetName(char* str);
	char* GetName();

	void SetMathGrade(float newMathGrade);
	float GetMathGrade();

	void SetEnglishGrade(float newEnglishGrade);
	float GetEnglishGrade();

	void SetHistoryGrade(float newHistoryGrade);
	float GetHistoryGrade();

	float GetAverageGrade();
};


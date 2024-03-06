#pragma once
class Movie {
	char name[256];
	int releaseYear;
	double score;
	int length;

public:
	void set_name(const char* str);
	char* get_name();

	void set_score(double newScore);
	double get_score();

	void set_year(int newYear);
	int get_year();

	void set_length(int newLength);
	int get_length();

	int get_passed_years();
};


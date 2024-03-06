#include "Movie.h"

void Movie::set_name(const char* str) {
	int i;
	for (i = 0; i < 255 && str[i]; i++)
		name[i] = str[i];
	name[i] = '\0';
}

char* Movie::get_name() {
	return name;
}

void Movie::set_score(double newScore) {
	if (newScore < 1 || newScore > 10) return;
	score = newScore;
}

double Movie::get_score() {
	return score;
}

void Movie::set_year(int newYear) {
	releaseYear = newYear;
}

int Movie::get_year() {
	return releaseYear;
}

void Movie::set_length(int newLength) {
	length = newLength;
}

int Movie::get_length() {
	return length;
}

int Movie::get_passed_years() {
	return 2024 - releaseYear;
}

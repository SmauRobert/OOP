#include "MovieSeries.h"

void MovieSeries::init() {
	count = 0;
}

void MovieSeries::add(Movie* m) {
	if (count >= 16) return;

	series[count++] = m;
}

void MovieSeries::sort() {
	for(int i = 0; i < count; i ++)
		for(int j = i + 1; j < count; j ++)
			if (movie_compare_passed_years(*series[i], *series[j]) == 1) {
				Movie* aux = series[i];
				series[i] = series[j];
				series[j] = aux;
			}
}

void MovieSeries::print() {
	for (int i = 0; i < count; i++)
		printf("%d. %s\n", i, series[i]->get_name());
}

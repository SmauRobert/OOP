#pragma once

#include "Movie.h"

#include <stdio.h>
#include "Global.h"

class MovieSeries {
	Movie* series[16];
	int count;
public:
	void init();
	void add(Movie* m);
	void sort();
	void print();
};


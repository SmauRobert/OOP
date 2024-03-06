#include "Global.h"

int movie_compare_name(Movie& m1, Movie& m2) {
    char* n1 = m1.get_name();
    char* n2 = m2.get_name();
    for (int i = 0; i < 255; i++)
        if (n1[i] < n2[i]) return -1;
        else if (n1[i] > n2[i]) return 1;
    return 0;
}

int movie_compare_year(Movie& m1, Movie& m2) {
    int y1 = m1.get_year();
    int y2 = m2.get_year();
    if (y1 < y2)
        return -1;
    if (y1 > y2)
        return 1;
    return 0;
}

int movie_compare_score(Movie& m1, Movie& m2) {
    int s1 = m1.get_score();
    int s2 = m2.get_score();
    if (s1 < s2)
        return -1;
    if (s1 > s2)
        return 1;
    return 0;
}

int movie_compare_length(Movie& m1, Movie& m2) {
    int l1 = m1.get_length();
    int l2 = m2.get_length();
    if (l1 < l2)
        return -1;
    if (l1 > l2)
        return 1;
    return 0;
}

int movie_compare_passed_years(Movie& m1, Movie& m2) {
    int p1 = m1.get_passed_years();
    int p2 = m2.get_passed_years();
    if (p1 < p2)
        return -1;
    if (p1 > p2)
        return 1;
    return 0;
}

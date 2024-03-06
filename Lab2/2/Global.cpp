#include "Global.h"

int CompareByName(Student* s1, Student* s2) {
    char* str1 = s1->GetName();
    char* str2 = s2->GetName();

    for (int i = 0; i < 32; i++)
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
    return 0;
}

int CompareByMathGrade(Student* s1, Student* s2) {
    int g1 = s1->GetMathGrade();
    int g2 = s2->GetMathGrade();

    if (g1 < g2) 
        return -1;

    if (g1 > g2) 
        return 1;
    return 0;
}

int CompareByHistoryGrade(Student* s1, Student* s2) {
    int g1 = s1->GetHistoryGrade();
    int g2 = s2->GetHistoryGrade();

    if (g1 < g2)
        return -1;

    if (g1 > g2)
        return 1;
    return 0;
}

int CompareByEnglishGrade(Student* s1, Student* s2) {
    int g1 = s1->GetEnglishGrade();
    int g2 = s2->GetEnglishGrade();

    if (g1 < g2)
        return -1;

    if (g1 > g2)
        return 1;
    return 0;
}

int CompareByAverageGrade(Student* s1, Student* s2) {
    int g1 = s1->GetAverageGrade();
    int g2 = s2->GetAverageGrade();

    if (g1 < g2)
        return -1;

    if (g1 > g2)
        return 1;
    return 0;
}

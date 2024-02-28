#include <stdio.h>

int main() {
    char sorted[100][100];
    int wordCount = 0;
    scanf("%c");
    while(scanf("%s ", sorted[wordCount])) {
        if(sorted[wordCount][0] == '\"') break;

        printf("%s\n", sorted[wordCount]);
        wordCount ++;
    }

    for(int i = 0; i < wordCount; i ++)
        printf("%s\n", sorted[i]);

    return 0;
}
#include <stdio.h>

int main(int argc, char **argv) {
    FILE *file = fopen("in.txt", "r");
    
    if(file == NULL) {
        printf("File could not open\n");
        return -1;
    }

    char text[100];
    int sum = 0;
    int lineIndex = 1;
    while(fgets(text, 100, file)) {
        int curr = 0, sign = 1;
        for(int i = 0; text[i] != '\0'; i ++)
            if(text[i] >= '0' && text[i] <= '9') curr = curr * 10 + text[i] -'0';
            else if(text[i] == '-') {
                if(curr != 0) {
                    printf("Number index %d is invalid\n", lineIndex);
                    return -1;
                }
                sign = -1;
            } else {
                sum += curr * sign;
                curr = 0;
                sign = 1;
            }
        lineIndex ++;
    }

    printf("%d\n", sum);

    return 0;
}
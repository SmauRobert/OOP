#include <stdio.h>

int main(int argc, char **argv) {
    FILE *file = fopen("in.txt", "r");
    
    if(file == NULL) {
        printf("File could not open\n");
        return -1;
    }

    char text[100];
    int sum = 0;
    while(fgets(text, 100, file)) {
        int curr = 0;
        for(int i = 0; text[i] != '\0'; i ++)
            if(text[i] >= '0' && text[i] <= '9') curr = curr * 10 + text[i] -'0';
            else {
                sum += curr;
                curr = 0;
            }
    }

    printf("%d\n", sum);

    return 0;
}
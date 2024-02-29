#include <stdio.h>

#define MAXWORDCOUNT 128
#define MAXWORDSIZE 32

struct String {
    char text[MAXWORDSIZE];
    short length;
};

// Functia verifica daca cele doua cuvinte a si b sunt deja ordonate
short Ordered(struct String a, struct String b) {
    if(a.length > b.length) return 1;
    if(a.length < b.length) return 0;
    char cha, chb;
    for(int i = 0; i < a.length; i ++) {
        cha = a.text[i];
        chb = b.text[i];

        // consideram caracterele ca fiind lowercase cand facem comparatia intre cuvinte
        if(cha >= 'A' && cha <= 'Z') cha -= 'A' - 'a';
        if(chb >= 'A' && chb <= 'Z') chb -= 'A' - 'a';

        if(cha < chb) return 1;
        else if(cha > chb) return 0;
    }
    return 1;
}

int main() {
    struct String words[MAXWORDSIZE];

    // Textul trebuie sa se afle intre ghilimele duble
    char ch;
    scanf("%c", &ch);
    if(ch != 34) {
        printf("Textul trebuie sa se afle intre ghilimele duble\n");
        return -1;
    }

    // Citim pana gasim al doilea "
    short found = 0, count = 0;
    for( ; found == 0 && scanf("%s", words[count].text); count ++) {
        // Calculam dimensiunea cuvantului si verificam pentru caracterul " ce incheie citirea
        words[count].length = 0;
        for( ; !found && words[count].text[words[count].length]; words[count].length ++) {
            if(words[count].text[words[count].length] == '\"') {
                words[count].text[words[count].length] = '\0';
                found = 1;
            }
        }

        // Sortare prin insertie
        for(short index = count; index > 0 && Ordered(words[index - 1], words[index]) == 0; index --) {
            // Gasim lungimea maxima a celor doua cuvinte
            short maxlength = words[index].length;
            if(maxlength < words[index - 1].length) 
                maxlength = words[index - 1].length;

            // Interschimbam caracter cu caracter
            for(short i = 0; i < maxlength; i ++) {
                ch = words[index - 1].text[i];
                words[index - 1].text[i] = words[index].text[i];
                words[index].text[i] = ch;
            }

            // Interschimbam lungimile
            short temp = words[index - 1].length;
            words[index - 1].length = words[index].length;
            words[index].length = temp;

            // Marcam finalul fiecarui sir de caractere 
            words[index - 1].text[words[index - 1].length] = '\0';
            words[index].text[words[index].length] = '\0';
        }
    }

    // Afisare
    for(short i = 0; i < count; i ++)
        printf("%s\n", words[i].text);

    return 0;
}
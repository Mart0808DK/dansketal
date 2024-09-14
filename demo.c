#include <stdio.h>
#include "dansketal.h"

int main() {
    char res[256];
    int tal = 0;
    printf("Enter a number: ");
    scanf("%d", &tal);
    dansketal(tal, res);
    printf("%s\n", res);
    return 0;
}
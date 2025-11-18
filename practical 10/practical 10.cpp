#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *src, *dest;
    char ch;
    src = fopen("input.txt", "r");
    dest = fopen("output.txt", "w");
    if (src == NULL || dest == NULL) {
        printf("File cannot be opened!\n");
        exit(0);
    }
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);
    printf("File copied successfully.\n");
    fclose(src);
    fclose(dest);
    return 0;
}


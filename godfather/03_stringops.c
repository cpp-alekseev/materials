#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n", strlen(str));
    printf("%s", str);
    printf("\n");

    char str2[100];
    strcpy(str2, str); // strcpy(char*, char*)

    str[99] = 'x'; // *(str + 99) = 'x'
    str2[99] = 'y';

    // str:  abc\0 ... x
    // str2: abc\0 ... y

    if (strcmp(str, str2) == 0) {
        printf("equal\n");
    } else {
        printf("not equal\n");
    }

    return 0;
}

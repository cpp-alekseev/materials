#include <stdio.h>
#include <string.h>

int main() {
    const char* first_string = "hello";
    const char* second_string = "hello";

    char third_string[] = "hello";

    printf("first_string address: %x\n", first_string);
    printf("second_string address: %x\n", second_string);
    printf("third_string address: %x\n\n", third_string);

    printf("first_string content: %s\n", first_string);
    printf("second_string content: %s\n", second_string);
    printf("third_string content: %s\n\n", third_string);

    printf("third_string length %ld\n", strlen(third_string));
    printf("third_string sizeof %ld\n\n", sizeof(third_string));

    third_string[0] = 'x';
    for (int i = 0; i < sizeof(third_string); ++i) {
        printf("%s\n", third_string + i); // Prints all suffixes. Why?
    }
    printf("\n");
}

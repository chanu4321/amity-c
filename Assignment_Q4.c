#include <stdio.h>
#include <string.h>
int main() {
    // strlen for finding length of string
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%d\n", strlen(alphabet));

    // strcat for joining(concatinate) two strings
    char str1[20] = "Hello ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("%s\n", str1);

    // strcpy to copy value of one string to other
    char str3[20] = "Hello World!";
    char str4[20];
    strcpy(str4, str3);
    printf("%s\n", str4);

    // strcmp
    char str5[] = "Hello";
    char str6[] = "Hello";
    char str7[] = "Hi";
    printf("%d\n", strcmp(str5, str6));  // Returns 0 (the strings are equal)
    printf("%d\n", strcmp(str5, str7));  // Returns -1 (the strings are not equal)

    return 0;
}
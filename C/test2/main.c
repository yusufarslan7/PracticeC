#include <stdio.h>

int main() {
    char str[] = "Hello@World";
    char str1[10], str2[10];

    sscanf(str, "%[^@]%s", str1, str2);

    printf("%s\n",str);
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);

    return 0;
}

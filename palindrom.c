#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int i, len, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Reverse the string
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';

    // Compare original and reversed string
    for (i = 0; i < len; i++) {
        if (str[i] != rev[i]) {
            isPalindrome = 0;
            break;
        }
    }

    // Output result
    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}

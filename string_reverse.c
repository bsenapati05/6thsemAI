#include <stdio.h>
#include <string.h>
int main() {
    char str[100], temp;
    int i = 0, j;
    printf("Enter a string: ");
    // Read string including spaces (replaces the dangerous gets)
    scanf("%[^\n]", str); 
    j = strlen(str) - 1; // Last character index
    while (i < j) {
        // Swap the characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        // Move pointers toward the middle
        i++;
        j--;
    }
    printf("Reversed string: %s\n", str);
    return 0;
}

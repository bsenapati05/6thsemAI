#include <stdio.h>

int main() {
    int x, y;

    printf("Enter two numbers:\n");
    scanf("%d %d", &x, &y);

    if (x > y) {
        printf("Greater number is: %d\n", x);
    } else if (y > x) {
        printf("Greater number is: %d\n", y);
    } else {
        printf("Both numbers are equal.\n");
    }

    return 0;
}

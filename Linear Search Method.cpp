#include <stdio.h>

int main() {
    int n, i, num, flag = 0, arr[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d", &num);
    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("%d found at index %d\n", num, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("%d not found\n", num);
    }
    return 0;
}


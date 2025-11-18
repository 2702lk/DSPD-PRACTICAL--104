#include <stdio.h>
#include <stdlib.h>

int* binary_search(int arr[], int size, int target) {
    if (arr == NULL || size <= 0) {
        return NULL;
    }

    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Middle value: %d\n", arr[mid]);

        if (arr[mid] == target) {
            return (arr + mid);
        } else if (arr[mid] < target) {
            start = mid + 1;
            printf("Adjusting start to index %d\n", start);
        } else {
            end = mid - 1;
            printf("Adjusting end to index %d\n", end);
        }
    }
    return (arr + 0);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int* result = binary_search(arr, size, target);

    if (result == NULL) {
        printf("Invalid input or empty array.\n");
    } else if (result == (arr + 0) && *result != target) {
        printf("Value not found.\n");
    } else {
        printf("Value found!\n");
    }

    return 0;
}


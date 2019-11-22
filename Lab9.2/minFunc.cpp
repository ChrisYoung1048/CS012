#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0;
    } else if (arrSize == 1) {
        return arr;
    } else if (arr[arrSize - 1] < *arr) {
        return min(arr + 1, arrSize - 1);
    } else {
        return min(arr, arrSize - 1);
    }
}
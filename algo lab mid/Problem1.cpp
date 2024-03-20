#include <iostream>
using namespace std;

// Merge function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // Create temporary arrays for both halves
    int leftHalf[subArrayOne];
    int rightHalf[subArrayTwo];

    // Copy data to temporary arrays
    for (int i = 0; i < subArrayOne; i++)
        leftHalf[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightHalf[j] = arr[mid + 1 + j];

    // Merge the two halves back into the original array
    int i = 0, j = 0, k = left;
    while (i < subArrayOne && j < subArrayTwo) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from leftHalf (if any)
    while (i < subArrayOne) {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy remaining elements from rightHalf (if any)
    while (j < subArrayTwo) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int unsortedNumbers[10];

    cout << "Enter 10 unsorted numbers:\n";
    for (int i = 0; i < 10; i++)
        cin >> unsortedNumbers[i];

    mergeSort(unsortedNumbers, 0, 9);

    cout << "Sorted numbers: ";
    for (int i = 0; i < 10; i++)
        cout << unsortedNumbers[i] << " ";
    cout << endl;

    cout << "Time complexity: O(n log n)\n";

    return 0;
}

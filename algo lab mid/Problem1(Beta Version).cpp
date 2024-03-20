#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int leftHalf[mid - left + 1], rightHalf[right - mid];
    for (int i = 0; i <= mid - left; i++) leftHalf[i] = arr[left + i];
    for (int j = 0; j < right - mid; j++) rightHalf[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i <= mid - left && j < right - mid) {
        if (leftHalf[i] <= rightHalf[j]) arr[k++] = leftHalf[i++];
        else arr[k++] = rightHalf[j++];
    }
    while (i <= mid - left) arr[k++] = leftHalf[i++];
    while (j < right - mid) arr[k++] = rightHalf[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int nums[10];
    cout << "Enter 10 unsorted numbers:\n";
    for (int i = 0; i < 10; i++) cin >> nums[i];
    mergeSort(nums, 0, 9);
    cout << "Sorted numbers: ";
    for (int i = 0; i < 10; i++) cout << nums[i] << " ";
    cout << "\nTime complexity: O(n log n)\n";
    return 0;
}

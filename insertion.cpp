Insertion Sort#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // Store the current element to be inserted
        int j = i - 1; // Index of the last element in the sorted part of the array

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place the current element in its correct position in the sorted array
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}Insertion Sort

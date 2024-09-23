/*#include<iostream>//number of passes=(n-1)
using namespace std; 
Space complexity O(1)
Time complexity O(n^2)
Best Case Complexity----O(n^2)
Worst Case Complexity----O(n^2)*/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // Assume the current element is the minimum
        for (int j = i + 1; j < n; ++j) {
            // Find the minimum element in the unsorted part of the array
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        //int temp = arr[minIndex];
        //arr[minIndex] = arr[i];
       // arr[i] = temp;
       swap(arr[minIndex],arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}Selection sort

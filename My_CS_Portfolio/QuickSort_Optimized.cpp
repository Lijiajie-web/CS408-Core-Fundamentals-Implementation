/**
 * @file QuickSort_Optimized.cpp
 * @brief Optimized QuickSort Algorithm implementation
 * @note Core Data Structures practice. Time Complexity: O(N log N)
 */

#include <iostream>
#include <vector>

using namespace std;

// Partition function using Lomuto partition scheme
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data = {87, 24, 65, 12, 45, 9, 53, 31};
    cout << "Unsorted array: \n";
    for(int n : data) cout << n << " ";
    
    quickSort(data, 0, data.size() - 1);
    
    cout << "\nSorted array: \n";
    for(int n : data) cout << n << " ";
    cout << endl;
    
    return 0;
}
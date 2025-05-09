#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SortingAlgorithms {
private:
    // Utility function for merge sort
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        // TODO: Implement merge function
        // 1. Create temporary arrays L[] and R[]
        // 2. Copy data to temporary arrays
        // 3. Merge the temporary arrays back into arr[left..right]
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1),R(n2);

        for(int i =0;i<n1;i++){
            L[i] = arr[left + i];
        }
        for(int j =0;j<n2;j++){
            R[j] = arr[mid + 1 +j];
        }
        int i = 0 , j = 0 , k = left;
        while(i<n1 && j<n2){
            if(L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }

    // Utility function for quick sort
    static int partition(std::vector<int>& arr, int low, int high) {
        // TODO: Implement partition function
        // 1. Select pivot (typically last element)
        // 2. Place pivot at its correct position
        // 3. Place smaller elements to left of pivot and greater to right
        int pivot = arr[high];
        int i = low - 1;
        for(int j =low;j<high;j++){
            if(arr[j] < pivot) swap(arr[++i],arr[j]);
        }
        swap(arr[i+1],arr[high]);
        return i+1; // Placeholder return
    }

    // Recursive function for merge sort
    static void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
        // TODO: Implement recursive merge sort
        // 1. Check if left < right
        // 2. Find middle point
        // 3. Sort first and second halves
        // 4. Merge the sorted halves
        if(left<right){
            int mid = left + (right - left)/2;
            mergeSortRecursive(arr,left,mid);
            mergeSortRecursive(arr,mid + 1,right);
            merge(arr,left,mid,right);
        }
    }

    // Recursive function for quick sort
    static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
        // TODO: Implement recursive quick sort
        // 1. Check if low < high
        // 2. Get partition index
        // 3. Sort elements before and after partition
        if(low<high){
            int pi = partition(arr,low,high);
            quickSortRecursive(arr,low,pi-1);
            quickSortRecursive(arr,pi+1,high);
        }
    }
    static void heapify(vector<int> &arr,int n,int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        if(largest != i){
            swap(arr[i] , arr[largest]);
            heapify(arr,n,largest);
        }
    }
    static void countingSort(vector<int> &arr , int exp){
        int n = arr.size();
        vector<int> output(n);
        int count[10] = {0};
        for(int i = 0;i<n;i++) count[(arr[i]/exp)%10]++;
        for(int i=1;i<10;i++) count[i] += count[i-1];
        for(int i =n-1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++) arr[i] = output[i];
    }

public:
    // Bubble Sort
    static void bubbleSort(std::vector<int>& arr){
        // TODO: Implement bubble sort
        // 1. Use nested loops
        // 2. Compare adjacent elements
        // 3. Swap if they are in wrong order
        int n = arr.size();
        for(int i= 0;i<n-1;i++){
            for(int j = 0;j<n-i-1;j++){
                if(arr[j] > arr[j+1])swap(arr[j],arr[j+1]);
            }
        }
    }

    // Selection Sort
    static void selectionSort(std::vector<int>& arr) {
        // TODO: Implement selection sort
        // 1. Find minimum element in unsorted array
        // 2. Swap it with first element of unsorted part
        // 3. Move boundary of unsorted array4
        int n = arr.size();
        for(int i = 0 ; i < n ; i++) {
            int minIndex = i;
            for(int j = 0 ; j < n ; j++){
                if(arr[i] < arr[minIndex]) minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Insertion Sort
    static void insertionSort(std::vector<int>& arr) {
        // TODO: Implement insertion sort
        // 1. Iterate through array
        // 2. For each element, insert it into its correct position in sorted part
        int n = arr.size();
        for(int i =0;i<n;i++){
            int key = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            } 
            arr[j+1] = key;
        }
    }

    // Merge Sort (public interface)
    static void mergeSort(std::vector<int>& arr) {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

    // Quick Sort (public interface)
    static void quickSort(std::vector<int>& arr) {
        quickSortRecursive(arr, 0, arr.size() - 1);
    }
    static void heapSort(vector<int> &arr){
        int n = arr.size();
        for(int i = n/2 -1;i>=0;i--) heapify(arr,n,i);
        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
    static void radixSort(vector<int> &arr){
        int maxVal = *max_element(arr.begin(),arr.end());
        for(int exp = 1;maxVal/exp >0;exp *=10){
            countingSort(arr,exp);
        }
    }
};

// Utility function to print array
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Testing function - DO NOT MODIFY
void testSortingAlgorithms() {
    std::vector<std::vector<int>> testArrays = {
        {64, 34, 25, 12, 22, 11, 90},
        {38, 27, 43, 3, 9, 82, 10},
        {8, 4, 23, 42, 16, 15},
        {122, 45, 75, 90, 32, 11},
        {122, 45, 75, 90, 32, 11},
        {122, 45, 75, 90, 32, 11},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    std::cout << "Testing Bubble Sort:\n";
    std::vector<int> arr1 = testArrays[0];
    std::cout << "Original array: ";
    printArray(arr1);
    SortingAlgorithms::bubbleSort(arr1);
    std::cout << "Sorted array: ";
    printArray(arr1);
    std::cout << std::endl;

    std::cout << "Testing Selection Sort:\n";
    std::vector<int> arr2 = testArrays[1];
    std::cout << "Original array: ";
    printArray(arr2);
    SortingAlgorithms::selectionSort(arr2);
    std::cout << "Sorted array: ";
    printArray(arr2);
    std::cout << std::endl;

    std::cout << "Testing Insertion Sort:\n";
    std::vector<int> arr3 = testArrays[2];
    std::cout << "Original array: ";
    printArray(arr3);
    SortingAlgorithms::insertionSort(arr3);
    std::cout << "Sorted array: ";
    printArray(arr3);
    std::cout << std::endl;

    std::cout << "Testing Merge Sort:\n";
    std::vector<int> arr4 = testArrays[3];
    std::cout << "Original array: ";
    printArray(arr4);
    SortingAlgorithms::mergeSort(arr4);
    std::cout << "Sorted array: ";
    printArray(arr4);
    std::cout << std::endl;

    std::cout << "Testing Quick Sort:\n";
    std::vector<int> arr5 = testArrays[4];
    std::cout << "Original array: ";
    printArray(arr5);
    SortingAlgorithms::quickSort(arr5);
    std::cout << "Sorted array: ";
    printArray(arr5);
    std::cout << std::endl;

    std::cout << "Testing Heap Sort:\n";
    std::vector<int> arr6 = testArrays[5];
    std::cout << "Original array: ";
    printArray(arr6);
    SortingAlgorithms::heapSort(arr6);
    std::cout << "Sorted array: ";
    printArray(arr6);
    std::cout << std::endl;

    std::cout << "Testing Radix Sort:\n";
    std::vector<int> arr7 = testArrays[6];
    std::cout << "Original array: ";
    printArray(arr7);
    SortingAlgorithms::radixSort(arr7);
    std::cout << "Sorted array: ";
    printArray(arr7);
}

int main() {
    testSortingAlgorithms();
    return 0;
}
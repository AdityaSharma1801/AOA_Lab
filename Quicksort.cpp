#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

// Function to take the last element as pivot, 
// places it at its correct position in sorted array,
// and places all smaller elements to the left of pivot
// and all greater elements to the right of pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Generates a random pivot, swaps pivot with
// end element, and calls the partition function
int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition_r(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; 
    cout << endl;
}

// Function to generate a random array
void generateRandomArray(int arr[], int size, int lower_bound, int upper_bound)
{
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < size; i++)
    {
        arr[i] = lower_bound + rand() % (upper_bound - lower_bound + 1);
    }
}

// Driver Code
int main()
{
    int n = 400000; // Size of the array
    int arr[n];

    // Generate an array with random numbers between 1 and 100
    generateRandomArray(arr, n, 1, 100);

//    cout << "Randomly generated array: \n";
//    printArray(arr, n);

    // Start measuring time
    clock_t start = clock();
    
    quickSort(arr, 0, n - 1);

    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    
    double time_taken = double(end - start) / CLOCKS_PER_SEC; // in seconds

//    cout << "Sorted array: \n";
//    printArray(arr, n);

    cout << "Time taken by QuickSort: " << time_taken << " seconds" << endl;
    
    return 0;
}


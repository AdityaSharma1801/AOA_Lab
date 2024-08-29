#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is the right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to generate a vector with random numbers
void generateRandomVector(vector<int> &arr, int size, int lower_bound, int upper_bound)
{
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < size; i++)
    {
        arr[i] = lower_bound + rand() % (upper_bound - lower_bound + 1);
    }
}

// Driver code
int main()
{
    int n = 100000; // Size of the vector
    vector<int> arr(n);

    // Generate a vector with random numbers between 1 and 100
    generateRandomVector(arr, n, 1, 100);

    //    cout << "Randomly generated vector is \n";
    //    printVector(arr);

    // Start measuring time
    clock_t start = clock();

    mergeSort(arr, 0, n - 1);

    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC; // in seconds

    //    cout << "\nSorted vector is \n";
    //    printVector(arr);

    cout << "Time taken by merge sort: " << time_taken << " seconds" << endl;

    return 0;
}

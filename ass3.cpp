#include <iostream>
#include <omp.h>
#include <climits>
using namespace std;

void min_reduction(int arr[], int n) {
    int min_value = INT_MAX;
    #pragma omp parallel for reduction(min: min_value)
    for (int i = 0; i < n; i++) {
        min_value = arr[i];  // No need for an "if" condition, OpenMP handles reduction automatically
    }
    cout << "Minimum value: " << min_value << endl;
}

void max_reduction(int arr[], int n) {
    int max_value = INT_MIN;
    #pragma omp parallel for reduction(max: max_value)
    for (int i = 0; i < n; i++) {
        max_value = arr[i];  // OpenMP handles reduction, no "if" needed
    }
    cout << "Maximum value: " << max_value << endl;
}

void sum_reduction(int arr[], int n) {
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
}

void average_reduction(int arr[], int n) {
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Average: " << (double)sum / n << endl;
}

int main() {
    int *arr, n;
    cout << "\nEnter total number of elements: ";
    cin >> n;
    arr = new int[n];
    cout << "\nEnter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    min_reduction(arr, n);
    max_reduction(arr, n);
    sum_reduction(arr, n);
    average_reduction(arr, n);
    
    delete[] arr;  // Free dynamically allocated memory
    return 0;
}


// #include <bits/stdc++.h>
// #include <omp.h>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int min_val = INT_MAX, max_val = INT_MIN, sum = 0;
//     double avg;

//     // Parallel Reduction
//     #pragma omp parallel for reduction(min: min_val) reduction(max: max_val) reduction(+: sum)
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < min_val) min_val = arr[i];  // Find min
//         if (arr[i] > max_val) max_val = arr[i];  // Find max
//         sum += arr[i];  // Compute sum
//     }

//     avg = (double)sum / n; // Compute average

//     cout << "\nMinimum Value: " << min_val;
//     cout << "\nMaximum Value: " << max_val;
//     cout << "\nSum: " << sum;
//     cout << "\nAverage: " << avg << endl;

//     return 0;
// }

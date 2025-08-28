#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void countSort(Student arr[], int n, int exp) {
    Student* output = new Student[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(int(arr[i].sgpa * 100) / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (int(arr[i].sgpa * 100) / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(Student arr[], int n) {
    int maxVal = int(arr[0].sgpa * 100);
    for (int i = 1; i < n; i++)
        if (int(arr[i].sgpa * 100) > maxVal)
            maxVal = int(arr[i].sgpa * 100);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

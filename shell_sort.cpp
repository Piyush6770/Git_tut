#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void shellSort(Student arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].name > temp.name; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

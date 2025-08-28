#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void shellSort(Student arr[], int n);  // function from shell_sort.cpp
void radixSort(Student arr[], int n);  // function from radix_sort.cpp

void display(const Student arr[], int n) {
    cout << "\nRoll No\tName\t\tSGPA\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].rollNo << "\t" << setw(10) << left << arr[i].name
             << "\t" << fixed << setprecision(2) << arr[i].sgpa << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <student_file> <sort_type>\n";
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin) {
        cout << argv[1] << "\n";
        return -1;
    }

    int n;
    fin >> n;
    Student* students = new Student[n];
    for (int i = 0; i < n; i++)
        fin >> students[i].rollNo >> students[i].name >> students[i].sgpa;
    fin.close();

    string sortType = argv[2];

    if (sortType == "radix") {
        radixSort(students, n);
        cout << "\nTop 10 SGPA Students:\n";
        for (int i = n - 1; i >= max(n - 10, 0); i--)
            cout << students[i].rollNo << "\t" << setw(10) << left << students[i].name
                 << "\t" << fixed << setprecision(2) << students[i].sgpa << endl;
    }
    else if (sortType == "shell") {
        shellSort(students, n);
        cout << "\nStudents Sorted Alphabetically (Shell Sort):\n";
        display(students, n);
    }
    else {
        cout << "Invalid sort type. Use 'radix' or 'shell'.\n";
    }

    delete[] students;
    return 0;
}

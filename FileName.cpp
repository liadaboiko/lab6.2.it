#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Генерує масив випадкових чисел від -50 до 50
void generateArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 101 - 50;
    }
}

// Виводить масив на екран
void printArray(const int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}
// Знаходить перший непарний елемент для порівнняня
int findFirstOddElement(const int a[], int size) {
    int minIndex = -1;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Знаходить індекс найменшого непарного елемента
int findMinOddIndex(const int a[], int size, int minIndex) {
    for (int i = 0; i < size; i++) {
        if (a[i] < a[minIndex] && a[i] % 2 != 0) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Замінює елемент за вказаним індексом на нуль
void replaceElement(int a[], int index) {
    if (index > -1) {
        a[index] = 0;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    const int n = 20;
    int a[n];

    generateArray(a, n);

    printArray(a, n);

    int i = findFirstOddElement(a, n);

    if (i > -1) {
        i = findMinOddIndex(a, n, i);
        cout << "Index of lowest odd element: " << i << endl;
        cout << "Lowest odd element: " << a[i] << endl;

        replaceElement(a, i);

        printArray(a, n);
    }
    else {
        cout << "Odd elements not founded." << endl;
    }

    return 0;
}

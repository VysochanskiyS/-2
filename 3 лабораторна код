#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
void func(int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1;
        }
        for (int j = i + 1; j < n - i - 1; j++) {
            arr[i][j] = 0;
        }

        for (int j = n - i; j < i; j++) {
            arr[i][j] = 0;
        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << arr[i][j];
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Ukr");
    int** arr, n;
    cout << "Ведiть розмiр матрицi: ";
    cin >> n;
    cout << "-----------------------------------------------------" << endl;
    arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    func(arr, n);
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}


#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void swap(int* a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool NextSet(int* a, int n) {
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l < r)
        swap(a, l++, r--);
    return true;
}

bool ifTrue(int* a, int n) {
    int x, lastx;
    int y, lasty;

    for (int i = 0; i < 5; i++)
        for (int j = 1; j < 5; j++)
        {
            lasty = j + 5 * i;
            y = j + 1 + 5 * i;
            lastx = i + 5 * (j - 1);
            x = i + 5 * j;
            if (a[lastx-1] > a[x-1] || a[lasty-1] > a[y-1])
                return false;
        }

    return true;
}

void Print(int* a, int n,string path) {  // вывод перестановки
    ofstream out(path + "\\output.txt");
    char ch;
    for (int i = 0; i < n; i++) {
        ch = 64 + a[i];
        out << ch << " ";
    }
    cout << endl;
    out.close();
}

int main() {
    string path;
    int k, kcheck = 0;
    int n = 25;
    int* a = new int[25];

    cout << "Enter the path: ";
    cin >> path;
    ifstream in(path + "\\input.txt");
    in >> k;
    in.close();

    for (int i = 0; i < 25; i++)
        a[i] = i + 1;

    while (NextSet(a, n))
        if (ifTrue(a, n)) {
            kcheck++;
            if (k == kcheck) {
                Print(a, n, path);
                break;
            }
        }

    return 0;
}
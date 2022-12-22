#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string str1;
    string titul = "";
    int n, m;
    ifstream in("C:\\Users\\79002\\source\\repos\\IS_Repo\\lb_7\\prgrm.txt");
    in >> n >> m; getline(in, str1);

    string** A = new string * [n];
    for (int i = 0; i < n; i++)
        A[i] = new string[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = "";

    while (getline(in, str1)) {
        titul = "";
        char c1, c2, c3;
        c1 = str1[0]; c2 = str1[1]; c3 = str1[2];
        titul = titul + c1 + c2 + c3;
        char ch1;
        int ini = 0, jm = 0;
        string digit;
        int ok;

        if (titul == "cco") {
            continue;
        }
        if (titul == "ccs") {
            continue;
        }
        if (titul == "cdo") {
            continue;
        }
        if (titul == "cds") {
            continue;
        }
        if (titul == "cer") {
            ch1 = str1[7];
            digit = "";
            ok = 0;

            for (int i = 0; i < str1.length(); i++) {
                if (str1[i] == '_' && ok == 0) {
                    ok = 1;
                    i++;
                }

                if (str1[i] == ' ' && ok == 1) {
                    ini = stoi(digit);
                    digit = "";
                    ok = 2;
                    i++;
                }

                if (ok == 1)
                    digit += str1[i];

                if (str1[i] == '_' && ok == 2) {
                    ok = 3;
                    i++;
                }

                if (ok == 3)
                    digit += str1[i];
            }
            jm = stoi(digit);

            A[ini][jm] += ch1;
            continue;
        }
        if (titul == "cdr") {
            continue;
        }
    }

    ofstream out("C:\\Users\\79002\\source\\repos\\IS_Repo\\lb_7\\rzlt.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << A[i][j]<<"\t";
        }
        out << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    in.close();
}
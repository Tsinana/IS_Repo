#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

bool IsSimple(int a);

int main()
{
    int choice;

    cout << "Coder(1) or decoder(2)?\n";
    cin >> choice;

    switch (choice) {

    case 1: {
        string path;
        string code;
        string strSimple;
        string strNotSimple;
        int shift = 0;

        cout << "Enter the path: ";
        cin >> path;
        ifstream in(path + "\\input_cod.txt");

        if (in.is_open()) {
            in >> shift;
            getline(in, code);
            getline(in, code);
        }

        in.close();

        for (int i = 0; i < shift; i++) {
            strSimple = "";
            strNotSimple = "";

            for (int i1 = 1; i1 <= code.length(); i1++) {
                if (IsSimple(i1))
                    strSimple.push_back(code[i1 - 1]);
                else
                    strNotSimple.push_back(code[i1 - 1]);
            }

            code = strSimple + strNotSimple;
        }

        ofstream out(path + "\\output_cod.txt");
        out << code;
        out.close();
    }

    case 2: {
        string path;
        string code;
        string strSimple = "";
        string strNotSimple = "";
        int shift = 0;
        int quantitySimple = 0;
        int strLength;
        int iS, iNS;

        cout << "Enter the path: ";
        cin >> path;
        ifstream in(path + "\\input.txt");

        if (in.is_open()) {
            in >> shift;
            getline(in, code);
            getline(in, code);
        }

        in.close();
        strLength = code.length();

        for (int i = 1; i <= code.length(); i++)
            if (IsSimple(i))
                quantitySimple++;

        for (int ish = 0; ish < shift; ish++) {

            strSimple = "";
            strNotSimple = "";

            for (int i = 0; i < quantitySimple; i++)
                strSimple.push_back(code[i]);

            for (int i = quantitySimple; i < code.length(); i++)
                strNotSimple.push_back(code[i]);

            iS = 0;
            iNS = 0;
            code = "";

            for (int i1 = 1; i1 <= strLength; i1++) {
                if (IsSimple(i1)) { 
                    code.push_back(strSimple[iS]);
                    iS++;
                } else {
                    code.push_back(strNotSimple[iNS]);
                    iNS++;
                }
            }
        }

        ofstream out(path + "\\output.txt");
        out << code;
        out.close();
        break;
    }

    default:
        break;
    }
}

bool IsSimple(int a) {
    int k = 1;

    if (a == 1)
        return false;

    for (int i = 1; i <= sqrt(a); i++)
        if (a % i == 0)
            k++;

    if (k == 2)
        return true;
    else
        return false;
}
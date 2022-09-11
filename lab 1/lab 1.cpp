#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int choice;

    cout << "Coder(1) or decoder(2)?\n";
    cin >> choice;

    switch (choice) {

        case 1: {
            string path;
            string code;
            int shift = 0;
            int nchar;

            cout << "Enter the path: ";
            cin >> path;
            ifstream in(path + "\\input_cod.txt");

            if (in.is_open()) {
                in >> shift; 
                shift = shift % 27;
                getline(in, code);
                getline(in, code);
            }

            transform(code.begin(), code.end(), code.begin(), toupper);
            in.close();

            for (int i = 0; i < code.length(); i++) {

                if (code[i] == 32)
                    code[i] = 64;

                nchar = code[i] + shift;

                if (nchar > 90)
                    nchar = nchar - 27;

                if (nchar == 64)
                    nchar = 32;

                code[i] = nchar;
            }

            ofstream out(path + "\\output_cod.txt");
            out << code;
            out.close();
            break;
        }

        case 2: {
            list<string> listStr;
            string word;
            string path;
            string line;
            string code;
            int maxCount = 0;
            int maxK = 0;
            int k;
            int nchar = 0;

            cout << "Enter the path: ";
            cin >> path;
            ifstream in(path + "\\input.txt");

            if (in.is_open()) {
                in >> k;
                k = k % 17;
                getline(in,code);

                for (int i = 0; i < k; i++) {
                    getline(in, line);
                    listStr.push_back(line);
                }

                getline(in, code);
            }

            in.close();
            
            for (int i = 0; i < 27; i++) {
                word = "";
                int counterK = 0;
                int counter = 0;
                code = code + ' ';

                for (int j = 0; j < code.length(); j++) {

                    if (code[j] == 32) {

                        if (word.length() != 0) {
                            counter = 0;

                            for (list<string>::iterator str = listStr.begin(); str != listStr.end(); ++str) {

                                if (*str == word)
                                    counter++;
                            }

                            counterK = counterK + counter;
                        }

                        word = "";
                    } else
                        word = word + code[j];
                }
               
                if (counterK > maxCount) {
                    maxCount = counterK;
                    maxK = i;
                }

                code.pop_back();

                for (int i2 = 0; i2 < code.length(); i2++) {

                    if (code[i2] == 32)
                        code[i2] = 64;

                    nchar = code[i2] + 1;

                    if (nchar > 90)
                        nchar = nchar - 27;

                    if (nchar == 64)
                        nchar = 32;

                    code[i2] = nchar;
                }
            }

            for (int i = 0; i < code.length(); i++) {

                if (code[i] == 32)
                    code[i] = 64;

                nchar = code[i] + maxK;

                if (nchar > 90)
                    nchar = nchar - 27;

                if (nchar == 64)
                    nchar = 32;

                code[i] = nchar;
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
#include <iostream>
#include "SHA1.h"

using namespace std;

int main()
{
    string ans = sha1("Black Egg");
    cout << "sha1('grape'):" << ans << endl;
    return 0;
}
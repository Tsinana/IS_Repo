#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct mirror {
    int x;
    int y;
    char side;//Right Left
};

int main()
{
    list<mirror> listMR;
    list<mirror> listML;
    list<mirror> listM;
    mirror start, archive;
    string path;
    string answer = "";
    int phase = 1;
    int r, c, m, n;
    int a, b;
    char direction;//Up Down Right Left

    cout << "Enter the path: ";
    cin >> path;
    ifstream in(path + "\\save.in");//C:\Users\79002\Desktop
    in >> r >> c >> m >> n;

    for (int i = 0; i < m; i++) {
        in >> a >> b;
        mirror mr;
        mr.x = a;
        mr.y = b;
        mr.side = 'R';
        listM.push_back(mr);
    }

    for (int i = 0; i < n; i++) {
        in >> a >> b;
        mirror mr;
        mr.x = a;
        mr.y = b;
        mr.side = 'L';
        listM.push_back(mr);
    }

    in.close();

    start.x = 1;
    start.y = -1;
    start.side = ' ';
    direction = 'R';
    a = 0;

    do {

        if (start.y == -1 && direction == 'R') {

            start.y = c + 1;
            for (list<mirror>::iterator mir = listM.begin(); mir != listM.end(); ++mir) {
                mirror mirror = *mir;

                if (mirror.x == start.x &&
                    mirror.y < start.y &&
                    mirror.y > a) {

                    start.x = mirror.x;
                    start.y = mirror.y;
                    start.side = mirror.side;
                }
            }
        }
        else {

            if (start.y == -1 && direction == 'L') {

                for (list<mirror>::iterator mir = listM.begin(); mir != listM.end(); ++mir) {
                    mirror mirror = *mir;

                    if (mirror.x == start.x &&
                        mirror.y > start.y &&
                        mirror.y < a) {

                        start.x = mirror.x;
                        start.y = mirror.y;
                        start.side = mirror.side;
                    }
                }
            }
        }

        if ((start.y == -1 || start.y == c + 1) && phase == 2) {
            start.side = direction;
            break;
        }

        if ((start.y == -1 || start.y == c + 1) && phase == 1) {
            phase = 2;
            archive = start;
            archive.side = direction;
            start.x = r;
            start.y = -1;
            start.side = ' ';
            direction = 'L';
            a = c + 1;
            continue;
        }

        if (start.x == -1 && direction == 'D') {

            start.x = r + 1;
            for (list<mirror>::iterator mir = listM.begin(); mir != listM.end(); ++mir) {
                mirror mirror = *mir;

                if (mirror.y == start.y &&
                    mirror.x < start.x &&
                    mirror.x > a) {

                    start.x = mirror.x;
                    start.y = mirror.y;
                    start.side = mirror.side;
                }
            }
        }
        else {

            if (start.x == -1 && direction == 'U') {

                for (list<mirror>::iterator mir = listM.begin(); mir != listM.end(); ++mir) {
                    mirror mirror = *mir;

                    if (mirror.y == start.y &&
                        mirror.x > start.x &&
                        mirror.x < a) {

                        start.x = mirror.x;
                        start.y = mirror.y;
                        start.side = mirror.side;
                    }
                }
            }
        }

        if ((start.x == -1 || start.x == r + 1) && phase == 2) {
            start.side = direction;
            break;
        }

        if ((start.x == -1 || start.x == r + 1) && phase == 1) {
            phase = 2;
            archive = start;
            archive.side = direction;
            start.x = r;
            start.y = -1;
            start.side = ' ';
            direction = 'L';
            a = c + 1;;
            continue;
        }

        switch (direction) {
        case('R'): {

            if (start.side == 'R')
                direction = 'U';
            else
                direction = 'D';

            break;
        }
        case('L'): {

            if (start.side == 'L')
                direction = 'U';
            else
                direction = 'D';

            break;
        }
        case('U'): {

            if (start.side == 'R')
                direction = 'R';
            else
                direction = 'L';

            break;
        }
        case('D'): {

            if (start.side == 'R')
                direction = 'L';
            else
                direction = 'R';

            break;
        }
        default:
            break;
        }

        switch (direction) {
        case('R'): {
            a = start.y;
            start.y = -1;
            break;
        }
        case('L'): {
            a = start.y;
            start.y = -1;
            break;
        }
        case('U'): {
            a = start.x;
            start.x = -1;
            break;
        }
        case('D'): {
            a = start.x;
            start.x = -1;
            break;
        }
        default:
            break;
        }

    } while (true);

    ofstream out(path + "\\save.out");

    if (start.x == r + 1)
        start.x = -1;

    if (start.y == c + 1)
        start.y = -1;

    if (archive.x == r + 1)
        archive.x = -1;

    if (archive.y == c + 1)
        archive.y = -1;

    if (archive.x && archive.side == 'R')
        answer = "0";
    else
        if (start.x == -1)
            if (archive.y == -1)
                if (start.side == 'L' && archive.side == 'D' ||
                    start.side == 'D' && archive.side == 'L' ||
                    start.side == 'R' && archive.side == 'U' ||
                    start.side == 'U' && archive.side == 'R') {
                      answer = start.y + " " + archive.x;
                      answer = answer + " L";
                } else {
                    answer = start.y + " " + archive.x;
                    answer = answer + " R";
                }
            else
                answer = "=(";
        else
            if (archive.x == -1)
                if (start.side == 'L' && archive.side == 'D' ||
                    start.side == 'D' && archive.side == 'L' ||
                    start.side == 'R' && archive.side == 'U' ||
                    start.side == 'U' && archive.side == 'R') {
                    answer = start.x + " " + archive.y;
                    answer = answer + " L";
                } else {
                    answer = start.x + " " + archive.y;
                    answer = answer + " R";
                }
            else
                answer = "=(";

    out << answer;
    out.close();
}

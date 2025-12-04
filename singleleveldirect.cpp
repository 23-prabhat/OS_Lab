#include <bits/stdc++.h>
using namespace std;

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir;

int main() {
    int i, ch;
    char f[30];
    dir.fcnt = 0;

    cout << "Enter name of directory -- ";
    cin >> dir.dname;

    while (1) {
        cout << "\n\n1. Create File\t2. Delete File\t3. Search File\n"
             << "4. Display Files\t5. Exit\nEnter your choice -- ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the name of the file -- ";
            cin >> dir.fname[dir.fcnt];
            dir.fcnt++;
            break;

        case 2:
            cout << "Enter the name of the file -- ";
            cin >> f;
            for (i = 0; i < dir.fcnt; i++) {
                if (strcmp(f, dir.fname[i]) == 0) {
                    cout << "File " << f << " is deleted ";
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    break;
                }
            }
            if (i == dir.fcnt)
                cout << "File " << f << " not found";
            else
                dir.fcnt--;
            break;

        case 3:
            cout << "Enter the name of the file -- ";
            cin >> f;
            for (i = 0; i < dir.fcnt; i++) {
                if (strcmp(f, dir.fname[i]) == 0) {
                    cout << "File " << f << " is found ";
                    break;
                }
            }
            if (i == dir.fcnt)
                cout << "File " << f << " not found";
            break;

        case 4:
            if (dir.fcnt == 0)
                cout << "Directory Empty";
            else {
                cout << "The Files are -- ";
                for (i = 0; i < dir.fcnt; i++)
                    cout << "\t" << dir.fname[i];
            }
            break;

        default:
            return 0;
        }
    }

    return 0;
}

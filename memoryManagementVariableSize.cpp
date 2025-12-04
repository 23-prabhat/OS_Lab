#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    int process[n];
    cout << "Enter sizes of processes:\n";
    for(int i = 0; i < n; i++) cin >> process[i];

    cout << "Enter total memory size: ";
    cin >> m;

    int mem = m;

    cout << "\nAllocation Result:\n";
    for(int i = 0; i < n; i++) {
        if(process[i] <= mem) {
            cout << "Process " << i+1 << " allocated (" 
                 << process[i] << " KB)\n";
            mem -= process[i];
        } else {
            cout << "Process " << i+1 << " NOT allocated\n";
        }
    }

    cout << "\nRemaining Free Memory: " << mem << " KB\n";

    return 0;
}

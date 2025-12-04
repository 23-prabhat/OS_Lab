#include <iostream>
using namespace std;

int main() {
    int p, n;

    cout << "Enter number of partitions: ";
    cin >> p;

    int part[p], allocated[p];
    cout << "Enter sizes of partitions:\n";
    for(int i = 0; i < p; i++) {
        cin >> part[i];
        allocated[i] = -1; 
    }

    cout << "Enter number of processes: ";
    cin >> n;

    int process[n];
    cout << "Enter sizes of processes:\n";
    for(int i = 0; i < n; i++) cin >> process[i];

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            if(allocated[j] == -1 && process[i] <= part[j]) {
                allocated[j] = i; 
                break;
            }
        }
    }

    cout << "\nAllocation Result:\n";
    for(int i = 0; i < p; i++) {
        cout << "Partition " << i+1 << " (size " << part[i] << "): ";
        if(allocated[i] != -1)
            cout << "Process " << allocated[i]+1;
        else
            cout << "Free";
        cout << endl;
    }

    return 0;
}

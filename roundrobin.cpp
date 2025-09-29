#include <bits/stdc++.h>
using namespace std;

int main() {
    int no_of_processes;
    cout << "Enter number of processes: ";
    cin >> no_of_processes;

    int Burst_time[no_of_processes], original_bt[no_of_processes];
    int arrival_time[no_of_processes];

    // Arrival times in consecutive manner 
    for (int i = 0; i < no_of_processes; i++) {
        arrival_time[i] = i;
    }

    for (int i = 0; i < no_of_processes; i++) {
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> Burst_time[i];
        original_bt[i] = Burst_time[i];
    }

    int total_time = 0;
    int tat[no_of_processes], waiting_time[no_of_processes];
    int completion_time[no_of_processes];
    int time_quantum;

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    int remaining_time[no_of_processes];
    for (int i = 0; i < no_of_processes; i++) {
        remaining_time[i] = Burst_time[i];
    }

    int done_count = 0;
    while (done_count < no_of_processes) {
        for (int i = 0; i < no_of_processes; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > time_quantum) {
                    total_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                    cout << "Process " << i + 1 << " executed for " << time_quantum << " units.\n";
                } else {
                    total_time += remaining_time[i];
                    cout << "Process " << i + 1 << " executed for " << remaining_time[i] << " units and completed.\n";
                    remaining_time[i] = 0;

                    completion_time[i] = total_time;
                    tat[i] = completion_time[i] - arrival_time[i];  // TAT formula
                    waiting_time[i] = tat[i] - original_bt[i];      // WT formula
                    done_count++;
                }
            }
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT";
    for (int i = 0; i < no_of_processes; i++) {
        cout << "\nP" << i + 1 << "\t" 
             << arrival_time[i] << "\t"
             << original_bt[i] << "\t"
             << completion_time[i] << "\t"
             << tat[i] << "\t"
             << waiting_time[i];
    }

    return 0;
}

#include <stdio.h>

int main() {
    int n, tq, bt[20], rem_bt[20], wt[20], tat[20], i, time = 0, done;
    float avg_wt = 0, avg_tat = 0;


    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; 
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    
    do {
        done = 1; 

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; 

                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];  
                    rem_bt[i] = 0;
                }
            }
        }
    } while (!done);


    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

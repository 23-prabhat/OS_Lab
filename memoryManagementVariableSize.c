#include<stdio.h>

int main(){
    int ms , n, mp[20] , allocated[20]  ;
    int ms_remaining , i , j ;
    int tif = 0;


    printf("total memory availabe in (Kb) : ");
    scanf("%d",&ms);
    ms_remaining = ms ;

    printf("Enter no of process : ");
    scanf("%d",&n);
   
    printf("Enter memory required for each process(kb) : ");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &mp[i]);
        allocated[i] = 0;
    }
    
    printf("\nProcess\tMemory Req\tAllocated\tRemaining Memory\n");

    for (i = 0; i < n; i++) {
        if (mp[i] <= ms_remaining) {
            allocated[i] = 1;
            ms_remaining -= mp[i];
            printf("%d\t%d\t\tYes\t\t%d\n", i + 1, mp[i], ms_remaining);
        } else {
            printf("%d\t%d\t\tNo\t\t%d\n", i + 1, mp[i], ms_remaining);
        }
    }

    printf("\nTotal Memory: %d KB", ms);
    printf("\nTotal Memory Used: %d KB", ms - ms_remaining);
    printf("\nExternal Fragmentation: %d KB\n", ms_remaining);

    return 0;
}
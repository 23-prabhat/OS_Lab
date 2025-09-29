#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[20], tif = 0;
    
  
    printf("Enter the total memory available (in KB) : ");
    scanf("%d", &ms);
    printf("Enter the block size (in KB) : ");
    scanf("%d", &bs);


    nob = ms / bs;
    ef = ms - nob * bs;

    printf("\nTotal memory: %d KB", ms);
    printf("\nBlock size: %d KB", bs);
    printf("\nNumber of blocks available: %d", nob);
    printf("\nExternal Fragmentation: %d KB\n", ef);


    printf("\nEnter the number of processes: ");
    scanf("%d", &n);


    printf("\nEnter memory required for each process (in KB):\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nProcess\tMemory Req\tAllocated Block\tInternal Frag\n");

   
    for (int i = 0; i < n && i < nob; i++) {
        if (mp[i] <= bs) {
            printf("%d\t%d\t\t%d\t\t%d\n", i + 1, mp[i], i + 1, bs - mp[i]);
            tif += bs - mp[i];
        } else {
            printf("%d\t%d\t\t---\t\tProcess too large!\n", i + 1, mp[i]);
        }
    }

    if (n > nob) {
        printf("\nMemory is full, remaining processes cannot be allocated.\n");
    }

    printf("\nTotal Internal Fragmentation: %d KB\n", tif);

    return 0;
}

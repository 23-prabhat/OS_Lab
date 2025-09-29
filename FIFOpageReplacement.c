#include <stdio.h>

int main() {
    int i, j, n, f, pages[50], frame[10], pageFaults = 0, nextToReplace = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string (page numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
  
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frame[i] = -1;
    }

    printf("\nPage Reference String with Frame Status:\n");

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < f; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }
  
        if (!found) {
            frame[nextToReplace] = page;   
            nextToReplace = (nextToReplace + 1) % f; 
            pageFaults++;
        }
 
        printf("Page %d -> ", page);
        for (j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (!found)
            printf(" (Page Fault)");
        printf("\n");
    }
 
    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

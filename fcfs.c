#include<stdio.h>

int main()
{
    int n, i;
    int bt[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // First process waiting time
    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }

    // Display output
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t\t%d\t\t%d",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nS_Average Waiting Time = %.2f",
           (float)total_wt / n);

    printf("\nS_Average Turnaround Time = %.2f",
           (float)total_tat / n);

    return 0;
}

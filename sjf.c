#include<stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], p[20];
    int n, i, j, temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        p[i] = i + 1;
    }

    // Sorting burst time
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];

    }
     // Calculate turnaround time
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

        for(i = 0; i < n; i++)
    {
         printf("\nP%d\t%d\t\t%d\t\t%d",
               p[i], bt[i], wt[i], tat[i]);
    }

   

    printf("\n\nA_Average Waiting Time = %.2f",(float) avg_wt/n);
    printf("\nA_Average Turnaround Time = %.2f", (float)avg_tat/n);

    return 0;
}

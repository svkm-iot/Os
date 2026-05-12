#include<stdio.h>

int main()
{
    int bt[20], rem_bt[20];
    int wt[20], tat[20];
    int n, tq;
    int i, time = 0, remain;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Round Robin Scheduling
    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                if(rem_bt[i] > tq)
                {
                    time = time + tq;
                    rem_bt[i] = rem_bt[i] - tq;
                }
                else
                {
                    time = time + rem_bt[i];

                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;

                    tat[i] = wt[i] + bt[i];

                    remain--;
                }
            }
        }
    }

 

    for(i = 0; i < n; i++)
    {
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];

    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t\t%d\t\t%d",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nP_Average Waiting Time = %.2f", avg_wt/n);
    printf("\nP_Average Turnaround Time = %.2f", avg_tat/n);

    return 0;
}

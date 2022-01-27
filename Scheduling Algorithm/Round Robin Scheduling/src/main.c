#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
    {
		rem_bt[i] = bt[i];
    }

	int t = 0; // Current time

	while (1)
	{
		bool done = true;

		// Traverse all processes one by one repeatedly
		for (int i = 0 ; i < n; i++)
		{
			// If burst time of a process is greater than 0 then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum)
				{
					// Increase the value of t
					t += quantum;

					// Decrease the burst_time of current process by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to quantum. Last cycle for this process
				else
				{
					// Increase the value of t
					t = t + rem_bt[i];

					// Waiting time is current time minus time used by this process
					wt[i] = t - bt[i];

					// As the process gets fully executed make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}

		if (done == true)
		break;
	}
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt, quantum);
	findTurnAroundTime(processes, n, bt, wt, tat);

    fprintf(stdout, "Processes    Burst Time    Waiting Time    Turnaround Time\n");

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];

        fprintf(stdout, " %8d %13d %15d %18d\n", i+1, bt[i], wt[i], tat[i]);
	}

    fprintf(stdout, "\nAverage waiting time = %3.5f\n", (float)total_wt / (float)n);
    fprintf(stdout, "Average turn around time = %3.5f\n", (float)total_tat / (float)n);
}


int main()
{
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	int burst_time[] = {10, 5, 8};

	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}

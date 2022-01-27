#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX 0x7FFFFFFF

typedef struct Process
{
	int processID; // Process ID
	int burstTime; // Burst Time
	int arrivalTime; // Arrival Time
} Process;


void findWaitingTime(Process proc[], int n, int wt[])
{
	int rt[n];

	for (int i = 0; i < n; i++)
		rt[i] = proc[i].burstTime;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	while (complete != n)
    {
		// Find process with minimum remaining time among the
		// processes that arrives till the current time
		for (int j = 0; j < n; j++)
        {
			if ((proc[j].arrivalTime <= t) && (rt[j] < minm) && rt[j] > 0)
            {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false)
        {
			t++;
			continue;
		}

		rt[shortest]--;

		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		// If a process gets completely executed
		if (rt[shortest] == 0)
        {
			complete++;
			check = false;

			finish_time = t + 1;

			wt[shortest] = finish_time - proc[shortest].burstTime - proc[shortest].arrivalTime;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}

		t++;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
    {
		tat[i] = proc[i].burstTime + wt[i];
    }
}

// Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(proc, n, wt);
	findTurnAroundTime(proc, n, wt, tat);

    fprintf(stdout, "Processes   Burst Time   Waiting Time   Turn-Around Time\n");

	// Calculate total waiting time and total turnaround time
	for (int i = 0; i < n; i++)
    {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
        fprintf(stdout, " %8d %12d %14d %18d\n", proc[i].processID, proc[i].burstTime, wt[i], tat[i]);
	}

    fprintf(stdout, "\nAverage Waiting time    = %3.5f\n", (float)total_wt / (float)n);
    fprintf(stdout, "Average Turnaround time = %3.5f\n", (float)total_tat / (float)n);
}

int main()
{
	Process proc[] = {
                        { 1, 6, 1 },
                        { 2, 8, 1 },
                        { 3, 7, 2 },
                        { 4, 3, 3 }
                    };

	int n = sizeof(proc) / sizeof(proc[0]);

	findavgTime(proc, n);
	return 0;
}

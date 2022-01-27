#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process
{
	int processID; // Process ID
	int burstTime; // CPU Burst time required
	int priority;  // Priority of this process
} Process;


int comparison(const void* a, const void* b)
{
	return (((Process*)a)->priority - ((Process*)b)->priority);
}

void sort(Process* processes, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(processes[j].priority < processes[j + 1].priority)
            {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void findWaitingTime(Process proc[], int n, int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < n ; i++ )
    {
		wt[i] = proc[i-1].burstTime + wt[i-1] ;
    }
}

void findTurnAroundTime( Process proc[], int n, int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
    {
		tat[i] = proc[i].burstTime + wt[i];
    }
}

//Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(proc, n, wt);
	findTurnAroundTime(proc, n, wt, tat);

    fprintf(stdout, "\nProcesses    Burst Time    Waiting Time    Turnaround Time\n");

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
        fprintf(stdout, "%9d %13d %15d %18d\n", proc[i].processID, proc[i].burstTime, wt[i], tat[i]);
	}

    fprintf(stdout,"\nAverage waiting time     = %3.5f\n", (float)total_wt / (float)n);
	fprintf(stdout, "Average turn around time = %3.5f\n", (float)total_tat / (float)n);
}

void priorityScheduling(Process proc[], int n)
{
	sort(proc, n);

    fprintf(stdout, "Order in which processes get executed is: \n");

	for (int i = 0 ; i < n; i++)
    {
        fprintf(stdout, "%d ", proc[i].processID);
    }

	findavgTime(proc, n);
}


int main()
{
	Process proc[] = {
                        {1, 10, 2},
                        {2,  5, 0},
                        {3,  8, 1}
                    };

	int n = sizeof proc / sizeof proc[0];
	priorityScheduling(proc, n);

    return EXIT_SUCCESS;
}

#include <stdio.h>

// Function to find the waiting time for all processes
void waitingtime(int n, int burst_time[], int wait_time[])
{
    // waiting time for first process is 0
    wait_time[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}

// Function to calculate turn around time
void turnaroundtime(int n, int burst_time[], int wait_time[], int tat[])
{
    // calculating turnaround time by adding
    // burst_time[i] + wait_time[i]
    for (int i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + wait_time[i];
    }

}
// Function to calculate average time
void avgtime(int proc[], const int n, int burst_time[])
{
    int wait_time[n];
    int tat[n];
    int total_wt = 0;
    int total_tat = 0;

    // Function to find waiting time of all processes
    waitingtime(n, burst_time, wait_time);

    // Function to find turn around time for all processes
    turnaroundtime(n, burst_time, wait_time, tat);

    // Display processes along with all details
    printf("Processes    Burst   Waiting   Turn around \n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("\t%d\t%2d\t%4d \t\t%2d\n", proc[i], burst_time[i], wait_time[i], tat[i]);
    }

    printf("\nAverage waiting time     = %3.3f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %3.3f\n", (float)total_tat / (float)n);
}

int main()
{
    // process id's
    int proc[] = {1, 2, 3};

    int n = sizeof proc / sizeof proc[0];

    // Burst time of all processes
    int burst_time[] = {5, 8, 12};

    avgtime(proc, n, burst_time);
    return 0;
}
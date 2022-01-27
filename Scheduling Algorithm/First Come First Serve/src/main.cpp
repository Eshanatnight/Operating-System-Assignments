/*
    Question: Implement the First Come First Serve (FCFS) scheduling algorithm.
*/

#include <iostream>
#include <array>

template<std::size_t SIZE>
void waitingTime(const std::array<int,SIZE>& proc, const std::array<int, SIZE>& burst_time, std::array<int,SIZE>& wait_time)
{
    // waiting time for first process is 0
    wait_time[0] = 0;
    // calculating waiting time
    for (uint32_t i = 1; i < proc.size(); i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}

template<std::size_t SIZE>
void turnAroundTime( const std::array<int,SIZE>& proc, const std::array<int,SIZE>& burst_time, const std::array<int,SIZE>& wait_time, std::array<int,SIZE>& tat)
{
    for (uint32_t i = 0; i < proc.size() ; i++)
    {
        tat[i] = burst_time[i] + wait_time[i];
    }
}

template<std::size_t SIZE>
void averageTime(const std::array<int, SIZE>& proc, const std::array<int, SIZE>& burst)
{
    std::array<int, SIZE> waitTime;
    std::array<int, SIZE> tat;
    int total_wt = 0;
    int total_tat = 0;

    waitingTime(proc, burst, waitTime);

    turnAroundTime(proc, burst, waitTime, tat);

    printf("Processes    Burst   Waiting   Turn around \n");

    for (uint32_t i = 0; i < proc.size(); i++)
    {
        total_wt = total_wt + waitTime[i];
        total_tat = total_tat + tat[i];
        printf("\t%d\t%2d\t%4d \t\t%2d\n", i + 1, burst[i], waitTime[i], tat[i]);
    }

    printf("\nAverage waiting time     = %3.3f\n", (float)total_wt / (float)proc.size());
    printf("Average turn around time = %3.3f\n", (float)total_tat / (float)proc.size());
}

int main()
{
    // Proc holdes the process ids
    std::array<int, 3> proc = {0, 1, 2};

    // Burst Time For All Processes
    std::array<int, 3> burstTime = {5, 8, 12};

    averageTime(proc, burstTime);

    return EXIT_SUCCESS;
}
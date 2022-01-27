/*
    Question[1]: Write a program to implement the SJF Scheduling algorithm
    Possible Solutions: Now the SJF Scheduling Algorithm we cam implement in Two Ways
    One is using the Pre-Emptive Method and the other is using the Non-Pre-Emptive Method.
*/

#include <stdio.h>
#include <stdlib.h>

int mat[10][6];

// A Sudo implementaion of the std:swap() function
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
	for (int i = 0; i < num; i++)
    {
		for (int j = 0; j < num - i - 1; j++)
        {
			if (mat[j][1] > mat[j + 1][1])
            {
				for (int k = 0; k < 5; k++)
                {
					swap(&mat[j][k], &mat[j + 1][k]);
				}
			}
		}
	}
}

void completionTime(int num, int mat[][6])
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2];
	mat[0][5] = mat[0][3] - mat[0][1];
	mat[0][4] = mat[0][5] - mat[0][2];

	for (int i = 1; i < num; i++)
    {
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++)
        {
			if (temp >= mat[j][1] && low >= mat[j][2])
            {
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];

        for (int k = 0; k < 6; k++)
        {
			swap(&mat[val][k], &mat[i][k]);
		}
	}
}

int main()
{
	int num;

    fprintf(stdout, "Enter the number of processes: ");
    scanf("%d", &num);

    fprintf(stdout, "Enter the Process IDs\n");

	for (int i = 0; i < num; i++)
    {
        fprintf(stdout, "...Process %d... \n", i + 1);
        fprintf(stdout, "Enter Process ID: ");
        scanf("%d", &mat[i][0]);
        fprintf(stdout, "Enter Arrival Time: ");
        scanf("%d", &mat[i][1]);
        fprintf(stdout, "Enter Burst Time: ");
        scanf("%d", &mat[i][2]);
	}

    fprintf(stdout, "Before Sorting...\n");
    fprintf(stdout, "Process ID\tArrival Time\tBurst Time\n");

	for (int i = 0; i < num; i++)
    {
        fprintf(stdout, "%d\t\t%d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2]);
	}

	arrangeArrival(num, mat);
	completionTime(num, mat);

    fprintf(stdout, "Final Result...\n");
    fprintf(stdout, "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < num; i++)
    {
        fprintf(stdout, "%d\t\t%d\t\t%d\t\t%d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2], mat[i][4], mat[i][5]);
    }

    return EXIT_SUCCESS;
}

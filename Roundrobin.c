#include <stdio.h>

void roundRobin(int n, int arrivalTime[], int burstTime[], int timeQuantum) {
    int completionTime[n];
    int turnaroundTime[n];
    int waitingTime[n];
    int remainingTime[n];

    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
        completionTime[i] = 0;
        turnaroundTime[i] = 0;
        waitingTime[i] = 0;
    }

    int currentTime = 0;
    int completedProcesses = 0;

    // Round Robin Scheduling
    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                // Execute the process for the time quantum or remaining burst time, whichever is smaller
                int executeTime = (remainingTime[i] < timeQuantum) ? remainingTime[i] : timeQuantum;

                remainingTime[i] -= executeTime;
                currentTime += executeTime;

                // Update completion time
                completionTime[i] = currentTime;

                // If the process is completed
                if (remainingTime[i] == 0) {
                    turnaroundTime[i] = completionTime[i] - arrivalTime[i];
                    waitingTime[i] = turnaroundTime[i] - burstTime[i];
                    completedProcesses++;
                }
            }
        }
    }

    // Display process details and scheduling results for Round Robin
    printf("\nRound Robin Scheduling:\n");
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, arrivalTime[i], burstTime[i],
               completionTime[i], turnaroundTime[i], waitingTime[i]);
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitingTime += waitingTime[i];
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
}

int main() {
    int n;
    int timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    int arrivalTime[n];
    int burstTime[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Perform Round Robin scheduling
    roundRobin(n, arrivalTime, burstTime, timeQuantum);

    return 0;
}

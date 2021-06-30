#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    if(a<b)
        return b;
    return a;
}
struct Process {
    int arrival;
    int burst;
    int prioity;
};

int main(){
    
    printf("Simulating First-come First-serve Process Scheduling Algorithm");
    printf("\n Enter number of process: ");
    int n;
    scanf("%d",&n);
    struct Process *arr = (struct Process *)malloc(sizeof(struct Process)*n);
    for(int i=0; i<n; i++)
    {
        printf("Enter Arrival time for process #%d: ",i+1);
        scanf("%d",&arr[i].arrival);
    }
    for(int i=0; i<n; i++)
    {
        printf("Enter Burst time for process #%d: ",i+1);
        scanf("%d",&arr[i].burst);
    }
    for(int i=0; i<n; i++)
    {
        printf("Enter Priority time for process #%d: ",i+1);
        scanf("%d",&arr[i].prioity);
    }
    /* Waiting Time Caluclation */
    int *wt = (int *)malloc(sizeof(int)*n);
    wt[0] = 0;
    double tot_wt=0;
    for(int i=1; i<n; i++)
    {
        wt[i] = arr[i-1].burst+wt[i-1]-(arr[i].arrival-arr[i-1].arrival);
        tot_wt += wt[i];
    }   
    
    int *tat = (int *)malloc(sizeof(int)*n);
    double tot_tat = 0;
    for(int i=0; i<n; i++)
    {
        tat[i] = wt[i]+arr[i].burst;
        tot_tat += tat[i];
    }   
    double count = n;
    double avg_wt, avg_tat;
    avg_wt = tot_wt/count;
    avg_tat = tot_tat/count;

    printf("\n");
    printf("Process\t\tArrival\t\tBurst\t\tPriority\tWait\t\tTat\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arr[i].arrival,arr[i].burst,arr[i].prioity,wt[i],tat[i]);
    }
    printf("\n_______________________________________________________________________________________\n");
    printf("\t\t\t\t\t\t\t\t%f\t\t%f\t\n",tot_wt,tot_tat);
    printf("Average Waiting Time : %f\n",avg_wt);
    printf("Average Turnaround Time : %f\n",avg_tat);    
    

    return 0;
}
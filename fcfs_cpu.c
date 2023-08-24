#include<stdio.h>
int main(){
    int n,bt[20],wt[20],tat[20],avgwt=0,avgtat=0;
    int i,j;
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the burst time\n");
    for(i=0;i<n;i++){
        printf("P[%d]=",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }
    printf("Gantt chart\n");
    for(i=0;i<n;i++){
        printf("| P[%d] |",i);
    }
    printf("\n0");
    for(i=0;i<n;i++){
        printf("    %d",tat[i]);
    }

    printf("\nProcess\tBurst time\tTurn around time\tWaiting time\n");
    for(i=0;i<n;i++){
    avgwt=avgwt+wt[i];
    avgtat=avgtat+tat[i];
    printf("\nP[%d]\t%d\t%d\t%d",i+1,bt[i],tat[i],wt[i]);
    }

    avgtat=avgtat/n;
    avgwt=avgwt/n;
    printf("\nAverage Turn around time:%d",avgtat);
    printf("\nAverage waiting time:%d",avgwt);
}

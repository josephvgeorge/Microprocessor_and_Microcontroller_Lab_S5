#include<stdio.h>
int main(){
    int n,bt[20],wt[20],tat[20],avgtat=0,avgwt=0,indexp[20];
    int i,j;
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the burst time\n");
    for(i=0;i<n;i++){
        printf("P[%d]=",i+1);
        scanf("%d",&bt[i]);
        indexp[i]=i+1;
    }
    //sorting
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                int temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp=indexp[j];
                indexp[j]=indexp[j+1];
                indexp[j+1]=temp;

            }
        }
    }
    //calculate waiting time
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    //calculate turnaroundtime
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }

    //printing gantchart
    printf("\nGantt chart");
    for(i=0;i<n;i++){
        printf("| P[%d] |",i);
    }
    printf("\n0");
    for(i=0;i<n;i++){
        printf("    %d",tat[i]);

    }
    printf("\nProcess\tBurst time\tTAT\tWaiting time");
    for(i=0;i<n;i++){
        avgtat=avgtat+tat[i];
        avgwt=avgwt+wt[i];
        printf("\nP[%d]\t%d\t%d\t%d",indexp[i],bt[i],tat[i],wt[i]);
    }
    avgtat=avgtat/n;
    avgwt=avgwt/n;
    printf("\nAverage waiting time=%d",avgwt);
    printf("\nAverage turn around time=%d",avgtat);


}

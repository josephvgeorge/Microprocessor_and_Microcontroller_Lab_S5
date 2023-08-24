#include<stdio.h>
int main(){
    int n,bt[20],wt[20],tat[20],index[20],avgtat=0,avgwt=0;
    int i,j,prio[20];
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the burst time and priority\n");
    for(i=0;i<n;i++){
        printf("P[%d]=",i+1);
        scanf("%d %d",&bt[i],&prio[i]);
        index[i]=i+1;
    }
    //sorting
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(prio[j]<prio[min]){
                min=j;
            }

        }
        int temp=prio[i];
        prio[i]=prio[min];
        prio[min]=temp;

        temp=bt[i];
        bt[i]=bt[min];
        bt[min]=temp;

        temp=index[i];
        index[i]=index[min];
        index[min]=temp;



    }
    //waiting time
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    //turn around time
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }

    //ganttchart
    printf("\nGantt chart\n");
    for(i=0;i<n;i++){
        printf("| P[%d] |",index[i]);
    }
    printf("\n0");
    for(i=0;i<n;i++){
        printf(" %d",tat[i]);
    }

    printf("\nProcess\tbt\ttat\twt");
    for(i=0;i<n;i++){
        avgwt=avgwt+wt[i];
        avgtat=avgtat+tat[i];
        printf("\nP[%d]\t%d\t%d\t%d",index[i],bt[i],tat[i],wt[i]);
    }

    avgtat=avgtat/n;
    avgwt=avgwt/n;
    printf("\naverage waiting time:%d",avgwt);
    printf("\naverage turn around time:%d",avgtat);

}

#include<stdio.h>
void main()
{
   int N;
   printf("Enter the no of process:");
   scanf("%d",&N);
   int Process[N],Burst[N],Gantch[N],priority[N],i,j;
   Gantch[0]= 0;
   float a_wt=0,a_tt=0;
   printf("Enter the Burst Time:\n");
   for(i=0;i<N;i++)
   {
       Process[i]=i+1;
       printf("Enter the burst time and priority for P%d Process:",Process[i]);
       scanf("%d %d",&Burst[i],&priority[i]);
   }
   for (i = 0; i < N - 1; i++) {
        for (j = i+1; j < N; j++) {
            if (priority[j] < priority[i] ){
                int temp= priority[i];
                priority[i]=priority[j];
                priority[j]=temp;    
				int temp2=Burst[i];
				Burst[i]=Burst[j];
				Burst[j]=temp2;            
            }
        }
    }
for(i=0;i<N;i++)
   { 
     if(i==0){
        Gantch[i]=Gantch[i]+Burst[i];
        a_wt=0;
        a_tt=Gantch[i];
     }
    else {
        Gantch[i]=Gantch[i-1]+Burst[i];
        a_wt=a_wt+Gantch[i-1];
        a_tt=a_tt+Gantch[i];
    }
   }
   a_wt=(float)a_wt/N;
   a_tt=(float)a_tt/N;
   printf("Average Waiting time:%.2f\n",a_wt);
   printf("Average Turnaroung time %.2f",a_tt);
  getch();
}

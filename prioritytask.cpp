#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of processes: ";
    cin>>n;
    int Burst_time[n];
    int Waiting[n];
    int TurnAround[n];
    int p[n];
    int priority[n];

    for(int i = 0 ; i <n ; i++){
        p[i] = i+1;
    }
    

    for(int i = 0; i<n ; i++){
        cout<<"Enter Burst Time for "<< i+1 <<"th process ";
        cin>>Burst_time[i];
    }

    for(int i = 0; i<n ; i++){
        cout<<"Enter priority of process"<< i+1 <<"th process ";
        cin>>priority[i];
    }
    
    cout<<"P  "<<"Pri   "<<"B  " << "W  " <<"T "<<endl ;
    Waiting[0] = 0;
    
    //sort of waiting time
    int cnt = 0;
    for(int i = 0 ; i<n ; i++){

        for(int j = i+1 ;j<n ; j++){
            if(priority[i]>priority[j]){
                cnt++;
                int temp = Burst_time[i];
                Burst_time[i] = Burst_time[j];
                Burst_time[j] = temp; 

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                
            }
        }
    }

    TurnAround[0] = Burst_time[0];
    cout<<p[0]<<"  "<< priority[0]<<" "<<Burst_time[0] <<"  "<< Waiting[0] << "  "<<TurnAround[0]  <<endl;

     for(int i = 1 ; i<n ; i++){
        Waiting[i] = Waiting[i-1] + Burst_time[i-1];
        TurnAround[i] = Waiting[i] + Burst_time[i];
        cout<<p[i]<<"  "<<priority[i]<<" "<< Burst_time[i] <<"  "<< Waiting[i] << "  "<<TurnAround[i]  <<endl;
    }

    // cout<<cnt;

}
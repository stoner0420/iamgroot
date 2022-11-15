#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;


void findavg(int ta[], int wt[],int n)
{
    float totalwt=0, totalta=0;
    for(int i=0; i<n; i++)
    {
        totalta+=ta[i];
        totalwt+=wt[i];
    }

    cout<<"Average Turn around time is  "<<totalta/n<<endl<<"Average Waiting time is  "<<totalwt/n<<endl;
}

void findTA(int p[], int at[], int bt[], int n )
{
    int et[n];
    et[0]=bt[0];
    int ta[n], wt[n];
    for(int i=1; i<n; i++)
    {
        et[i]=et[i-1]+bt[i];
    }

    for(int i=0; i<n; i++)
    {
        ta[i]=et[i]-at[i];
        wt[i]=ta[i]-bt[i];
    }

    

    
    cout<<"PROCESSES"<<"   "<<"ARRIVAL TIME "<<"   "<<"BURST TIME"<<"   "<<"TURN AROUND TIME"<<"   "<<"WAITING TIME"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< p[i] <<"             " << at[i] << "                " << bt[i]<<"           " <<ta[i]<<"                "<<wt[i]<< endl;
    }

    findavg(ta, wt, n);
    
}


void toSort(int P[], int BT[], int AT[], int n)
{
    int p[n], at[n], bt[n];
    vector<int> vec;



    for (int i = 0; i < n; i++)
    {
        if (AT[i] == 0)
        {
            at[0] = AT[i];
            bt[0] = BT[i];
            p[0] = P[i];
        }
        else
        {
            vec.push_back(BT[i]);
        }
    }

    sort(vec.begin(), vec.end());

    for (int i = 1; i < n; i++)
    {
        bt[i] = vec[i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (bt[i] == BT[j])
            {
                p[i] = P[j];
                at[i] = AT[j];
                break;
            }
        }
    }

    
    findTA(p, at, bt, n);
}

int main()
{

    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    int Process[n];

    for(int i=0; i<n;i++)
    {
        Process[i]=i+1;
    }

    int BT[n];
    int AT[n];
    cout << "Enter burst time  and arrival time for each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For process " << i + 1 << endl;
        cin >> BT[i] >> AT[i];
    }

     toSort(Process,BT,AT,n);

    return 0;
}
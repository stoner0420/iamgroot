#include <iostream>
#include <conio.h>

using namespace std;

void findTat(int p[], int n, int bt[], int tat[], int at[])
{
    int exitTime[n];
    exitTime[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        exitTime[i] = exitTime[i - 1] + bt[i];
         tat[i] = exitTime[i] - at[i];
    }

    // for(int i=0; i<n ; i++)
    // {
    //     tat[i] = exitTime[i] - at[i];
    // }
}

void findWt(int p[], int n, int bt[], int tat[], int wt[])
{

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
}

void findAvgTime(int p[], int n, int bt[], int at[])
{
    int wt[n], tat[n], Totwt = 0, Tottat = 0;

    findTat(p, n, bt, tat, at);
    findWt(p, n, bt, tat, wt);

    cout << "Process"
         << "  Burst Time"
         << "  Turn around Time"
         << "  Waiting Time" << endl;

    for (int i = 0; i < n; i++)
    {
        Tottat = Tottat + tat[i];
        Totwt = Totwt + wt[i];
        cout << "    " << i + 1 << "          " << bt[i] << "         " << tat[i] << "              " << wt[i] << endl;
    }

    // cout<<Tottat<<"\t"<<Totwt<<endl;

    float Avgta = (float)Tottat / (float)n;
    float Avgwt = (float)Totwt / (float)n;

    cout << "Average Turn around time is " << Avgta << endl
         << "Average waiting time is " << Avgwt;
}

int main()
{
    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    int process[n];

    int burst_time[n];
    int arrivalTime[n];
    cout << "Enter burst time  and arrival time for each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For process " << i + 1 << endl;
        cin >> burst_time[i]>>arrivalTime[i];
    }

    findAvgTime(process, n, burst_time, arrivalTime);

    return 0;
}
#include<iostream>
#include<algorithm>
#include<conio.h>
#include<vector>

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

void findTAWT(int bt[], int n, int p[], int pt[])
{
    int ta[n], wt[n];
    ta[0]=bt[0];
    for(int i=1; i<n; i++)
    {
        ta[i]=ta[i-1]+bt[i];

        
    }
    for(int i=0; i<n; i++)
    {
        wt[i]=ta[i]-bt[i];
    } 
    cout<<"Process"<<"   "<<"Burst time"<<"  "<<"Priority"<<"  "<<"turn around"<<"  "<<"Waiting time"<<endl;
   for(int i=0; i<n; i++)
    {
        cout<<p[i]<<"           "<<bt[i]<<"            "<<pt[i]<<"           "<<ta[i]<<"           "<<wt[i]<<endl;
    }




    findavg(ta, wt, n);
}

void toSort(int PT[], int n, int BT[], int Process[])
{
    vector<int> vec;
    int pt[n], bt[n],p[n];
    for(int i=0; i<n; i++)
    {
        vec.push_back(PT[i]);
    }

    sort(vec.begin(), vec.end());
    
    for(int i=0; i<n; i++)
    {
        pt[i]=vec[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(pt[i]==PT[j])
            {
                p[i]=Process[j];
                bt[i]=BT[j];
                break;
            }
        }
    }

    

    findTAWT(bt, n, p, pt);

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
    int PT[n];
    cout << "Enter burst time  and Priority for each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "For process " << i + 1 << endl;
        cin >> BT[i] >> PT[i];
    }

    toSort(PT, n, BT, Process);
    return 0;
}
#include<iostream>
#include<conio.h>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

void display(int pageFault, int pageHit)
{
    cout<<"The Page Fault is  "<<pageFault<<endl;
    cout<<"The Page Hit is  "<<pageHit<<endl;
    
    
}



void check(int PR[], int n, int pf)
{
    int pageFault=0, pageHit=0;
    vector <int> vec;
    vector<int>::iterator it;

    int i=0;
    while(i<n)
    {
        if(vec.empty())
        {
            pageFault++;
            vec.push_back(PR[i]);
            i++;
        }
        else
        {
            if(count(vec.begin(), vec.end(), PR[i]))
            {
                pageHit++;
                i++;
            }
            else
            {
                pageFault++;
                if(vec.size()==pf)
                {
                    it = vec.begin();
                    vec.erase(it);
                    vec.push_back(PR[i]);

                }
                else
                {
                    vec.push_back(PR[i]);

                }
                i++;
            }
        }
    }

    display(pageFault, pageHit);


}

int main()
{
    int n, pf;
    cout<<"Enter the number of page reference and size of Page frame"<<endl;
    cin>>n>>pf;

    int PR[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter reference key"<<endl;
        cin>>PR[i];
    }

    check(PR, n, pf);



    return 0;
}
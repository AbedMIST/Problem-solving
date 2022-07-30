
#include<bits/stdc++.h>
using namespace std;

class process{
       public:
       string name;
       int ar_time;
       int b_time;
       process(string n="",int a=0,int b=0)
       {
           name=n;
           ar_time=a;
           b_time=b;
       }
};
bool cmp(process obj1,process obj2)
{
    if(obj1.ar_time < obj2.ar_time){
        return true;
    }
    else
        return false;
}


int main()
{
    int it=1,i=0,n,q_tum,AT,BT;
    string PN;
    vector<process>lst;

    while(1)
    {
        cout<<" Input n and time_quantum: ";
        cin>>n>>q_tum;

        for(int i=0; i<n; i++)
        {
            cin>>PN>>AT>>BT;
            process t(PN,AT,BT);
            lst.push_back(t);
        }

        sort(lst.begin(),lst.end(),cmp);
        queue<process> ready,ex;
        process x;

        ready.push(lst[0]);

        int time=lst[0].ar_time;
        int it=1,rem,sum=0;
        cout<<"Seq.No. ProcessName  Timeline  TurnaroundTime(TAT)  "<<endl;
        while(!ready.empty()){

            x=ready.front();
            //cout<<x.name<<" "<<x.ar_time<<" "<<x.b_time<<endl;
            int prev_t=time;
            if(x.b_time<q_tum){
                    time+=x.b_time;
                    rem= 0;
                    x.b_time =0;
            }
            else{
                    time+=q_tum;
                    rem= x.b_time -q_tum;
                    x.b_time = rem;         ///update burst time
            }


            while(lst[it].ar_time <=time && it<n){  ///push all in the time.
                ready.push(lst[it]);
                it++;
            }
            if(rem>0)   ready.push(x);

            cout<<"  "<<i+1<<"         "<<x.name<<"         "<<prev_t<<"-"<<time<<"      ";
            if(x.b_time==0){
                cout<<time-x.ar_time<<endl;

                sum+= (time-x.ar_time);
            }
            else    cout<<"Pending"<<endl;

            i++;
            ready.pop();

        }
        double avg= 1.0*sum/n;
        cout<<"Average TAT:" <<setprecision(2)<<fixed<<avg<<endl;

    }
}

/*
5 3
P1 0  8
P2 5  2
P3 1  7
P4 6  3
P5 8  5
*/

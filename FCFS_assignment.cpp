#include<bits/stdc++.h>
using namespace std;

class process{
       public:
       int id;
       string name;
       int dur;
       int ar_time;
       int order;
       process(int s,string n,int d,int a,int o)
       {
           id=s;
           name=n;
           dur=d;
           ar_time=a;
           order=o;
       }
};
bool cmp(process obj1,process obj2)
{
    if(obj1.ar_time==obj2.ar_time){
        if(obj1.dur==obj2.dur){
            if(obj1.order<obj2.order)
                return true;
            else
                return false;
        }
        else if(obj1.dur<obj2.dur)
            return true;
        else
            return false;
    }

    else if(obj1.ar_time<obj2.ar_time)
        return true;
    else
        return false;
}

bool cmp2(process obj1,process obj2)
{
    if(obj1.dur==obj2.dur){
        if(obj1.order<obj2.order)
                return true;
            else
                return false;
    }
    else if(obj1.dur<obj2.dur)
        return true;
    else
        return false;
}

int main()
{
    int it=1,n,PI,DU,AT,OR,prev_proc=0;
    vector<process>lst,lst2;
    string PN;

    while(1)
    {
        cout<<"Iteration "<<it<<" Input: n = ";
        cin>>n;

        prev_proc+=n;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>PI>>PN>>DU>>AT>>OR;
            process t(PI,PN,DU,AT,OR);
            lst.push_back(t);

        }

        sort(lst.begin(),lst.end(),cmp);


        cout<<"Seq.No. ProcessName Timeline Turnaround   Order"<<endl;
        int prev_du=0;
        for(int i=0; i<prev_proc; i++)
        {
            cout<<"   "<<i+1<<"         "<<lst[i].name<<"       "<<prev_du<<"-"<< prev_du+lst[i].dur<<"        ";
            prev_du+=lst[i].dur;
            cout<<prev_du - lst[i].ar_time<<"           "<<lst[i].order<<endl;
            sum+=prev_du - lst[i].ar_time;

//            for(j=i+1;j<prev_proc;j++){
//                process l(lst[j].id,lst[j].name,lst[j].dur,lst[j].ar_time,lst[j].order);
//                lst2.push_back(l);
//            }
//            sort(lst2.begin(),lst2.end(),cmp2);
        }

        printf("A.T.T=%d\n",sum/lst.size());

    it++;
    }
}


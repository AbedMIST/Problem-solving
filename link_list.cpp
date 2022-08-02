                    /// Fuck rating, enjoy the experience.
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define rep(i,n) for(int i=0;i++<n;)
#define sci(a)   scanf("%d",&a)
#define scl(a)   scanf("%lld",&a)
#define b_s(a,b) binary_search(a.begin(),a.end(),b)
#define l_b(a,b) lower_bound(a.begin(),a.end(),b)
#define u_b(a,b) upper_bound(a.begin(),a.end(),b)
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int>   pii;
typedef pair<long long, long long>   pll;
typedef vector<int>     vi;
typedef vector<pair<int,int>>    vii;
const int MAXN   = 1e6+7;
const int INF    = (int)1e7;
const double EPS = 1e-9;



struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *head=NULL;

node* creat(int val){
    node *n=new node;///allocate memory for new node
    n->data=val;
    n->next=NULL;
    return n;
}
void insert_first(int num)
{
    node* newnode=creat(num);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void insert_tail(int num)
{
    node* newnode=creat(num);
    if(head==NULL)
    {
        head=newnode;
        return;
    }

    node* tail=head;
   while(tail->next!=NULL)
   {
       tail=tail->next;
   }
   tail->next=newnode;
}
void insert_middle(int pos,int num)  
{

   node* newnode=creat(num);
   int i=0;
   node *tail=head;
   while(i<pos-1)
   {
       tail=tail->next;
       ///printf("%d ",tail->data);
       i++;
   }
   node *next1=tail->next;
   tail->next=newnode;
   newnode->next=next1;

}
void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

//  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
//         ListNode* temp1 = list1;
//         ListNode* temp2 = list2;
//         ListNode* head = new ListNode();      //ans list
         
//         while(temp1 && temp2){
            
//             if(temp1->val <= temp2->val){        //list1 inserted
//                 head = insert_tail(head,temp1->val);
//                 temp1 = temp1->next;
//             }
//             else{                                   //list2 inserted
//                 head = insert_tail(head,temp2->val);
//                 temp2 = temp2->next;
//             }
//         }
        
//         while(temp1){
//             head = insert_tail(head,temp1->val);
//             temp1 = temp1->next;
//         }
//         while(temp2){
//             head = insert_tail(head,temp2->val);
//             temp2 = temp2->next;
//         }
        
//         head = head->next;
//         return head;    
// }

int main()
{

    int a=6,b=8,c=7,d=10,e=11,f=12;
   
    insert_first(a);
    insert_first(b);
    insert_tail(c);
    insert_tail(d);

    insert_middle(2,e);
    insert_middle(1,f);
    print();

}

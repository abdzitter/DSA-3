#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
class Linked_list
{
public:
node *head=NULL;

void insertfront(int value)
{
    node *temp=new node();
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insertback(int value)
{
    node *temp=new node();
    temp->data=value;
    node *p=new node();
    p=head;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
      while(p->next!=NULL)
      {
          p=p->next;
      }
      p->next=temp;
      temp->next=NULL;
    }
}
void Traverse()
{
    node *temp=new node();
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp=temp->next;
    }
}
void insertafter(int value,int data1)
{
    node *temp=new node();
    temp->data=data1;
    node* p=new node();
    p=head;
    while(p->next!=NULL)
    {
        if(p->data==value)
        {
            temp->next=p->next;
            p->next=temp;
            break;
        }
        else{
            p=p->next;
        }
    }
}
void insertbefore(int value,int data2)
{
    node *temp=new node();
    temp->data=data2;
    node* p=new node();
    p=head;
    node* q=new node();
    q=head;
    
     while(p->next!=NULL)
    {
        if(head->data==value)
        {
            temp->next=head;
            head=temp;
            break;
        }
        else
        {
        if(p->data==value)
        {
            temp->next=p;
            q->next=temp;
            break;
        }
        else
        {
            q=p;
            p=p->next;
        }
        }
    }
}
void deletef(int value)
{
    node *p= new node();
     node *temp= new node();
    p=head;
    node *q=new node();
    q=head;
    while(p!=NULL)
    {
        if(head->data==value)
        {
            temp=head;
            head=head->next;
            delete temp;
            break;
        }
        else
        {
            if(p->data==value)
            {
                q->next=p->next;
                delete p;
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
    } 
   
}
 void displayrecursively(node *head)
    {
       
            cout << head->data << " " ;
            displayrecursively(head->next);
      
    }
  void deleteduplicate(node *head)
  {
      node *p=head->next;
      node *q=head;
      while(p)
      {
          if(q->data==p->data)
          {
              q->next=p->next;
              delete p;
              p=q->next;
          }
          else
          {
                q=p;
                p=p->next;
          }
      }
  }
  void reverselinked()
  {
      node *p=head;
      node *q=NULL;
      node *r=NULL;
      while(p!=NULL)
      {
          r=q;
          q=p;
          p=p->next;
          q->next=r;
      }
      head->next=NULL;
      head=q;
  }
 void rottateleft(int p)
{
    int n=0;
    node * s=head;
    node* q=head;
    int t=p,d=p;
   while(t!=0)
   {
       q=s;
       s=s->next;
       t--;
   }
   
   q->next=NULL;
   node * w=s;
   while(w->next!=NULL)
   {
       w=w->next;
   }
  w->next=head;
  
  head=s;
     
}
void partition(int x)
{
    node*q=head;
    int node_no=0;
    while(q->data!=x)
    {
        q=q->next;
        node_no++;
    }
    node *t=q->next;
    node *p=head;
    node *r=head;
    int k=0,s=0;
    while(p!=NULL)
    {
        if(p->data>q->data && node_no>k)
        {
            if(p==head)
            {
                if(s==0)
                {
                    node *z=p;
                    head=z->next;
                    z->next=q->next;
                    q->next=z;
                    s++;
                    t=z;
                }
                if(s!=0)
                {
                    node *z=p;
                    head=z->next;
                    z->next=t->next;
                    t->next=z;
                    t=z;
                }
            }
            else
            {
                node *z=p;
                r->next=z->next;
                z->next=t->next;
                t->next=z;
                t=z;
            }
        }
        else if(p->data<q->data && node_no<k)
        {
            if(q!=head)
            {
                node *w=head;
                node *x=head;
                while(w->data!=q->data)
                {
                    x=w;
                    w=w->next;
                }
                node *z=p;
                r->next=z->next;
                x->next=z;
                z->next=w->next;
            }
            else
            {
                node *z=p;
                r->next=z->next;
                head=z;
                head->next=q;
            }
        }
        else if(p->data==q->data&&node_no<k)
        {
            node *z=p;
            r->next=z->next;
            z->next=q->next;
            q->next=z;
        }
        k++;
        r=p;
        p=p->next;
    }
    
}
};
int main()
{
    Linked_list l1;
    l1.insertfront(10);
    l1.insertfront(10);   
    l1.insertfront(9);  
    l1.insertfront(22); 
    l1.insertfront(66);
    l1.insertfront(43);  
    l1.insertfront(9);  
    l1.insertfront(224); 
    l1.Traverse();
     l1.partition(9);
     cout <<endl;
     l1.Traverse();
    return 0;
}
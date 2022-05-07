#include<iostream>
#include<vector>
#include"person.h"
using namespace std;
struct Node{

    int d;
    Person *p;
    struct Node *l;

    struct Node *r;

};

class avl_tree
{

    public:

        int c;

        int height(Node*);

        int diff(Node*);

        int Creating_Id(Node*,int,int,int);

        vector<int> date;

        Node* rr_rot(Node*);           //right-right rotation

        Node* rl_rot(Node*);           //right-left rotation 

        Node* lr_rot(Node*);           //left-right rotation

        Node* ll_rot(Node*);           //left-left rotation

        Node* balance(Node*);

        Node* insert(Node*,int,Person*);

        Node* Creating_Id(Node* ,int ,int ,int ,Person*);

        int difference(Node*);

        string showDate(Node*,int);

        void showDetails(Node*,int);

        int binary_search(int);

        void inorder(Node*);

        avl_tree()
        {
           c=999;
        }
};
int avl_tree::height(Node* tem)
{
    int h=0;

    if(tem!=NULL)
    {

        int lh = height(tem->l);

        int rh = height(tem->r);

        int max = (lh>rh)?lh:rh;

        h = max + 1;

    }
    return h;
}
Node* avl_tree::ll_rot(Node* parent)
{
    Node* t;

    t= parent->l;

    parent->l=t->r;

    t->r=parent;

    return t;    
}
Node* avl_tree::rr_rot(Node* parent)
{
    Node* t;

    t= parent->r;

    parent->r=t->l;

    t->l=parent;

    return t;    
}
Node* avl_tree::lr_rot(Node* parent) 
{
   Node* t;

   t = parent->l;

   parent->l = rr_rot(t);

   return ll_rot(parent);

}
Node* avl_tree::rl_rot(Node *parent) 
{
   Node *t;

   t = parent->r;

   parent->r = ll_rot(t);

   return rr_rot(parent);
}
int avl_tree::difference(Node *t) 
{

   int l_height = height(t->l);

   int r_height = height(t->r);

   int b_factor = r_height - l_height;

   return b_factor;
}
Node* avl_tree::balance(Node *t)
 {
   int bal_factor = difference(t);

   if (bal_factor < -1) 
   {
      if (difference(t->l) < 0)
         t = ll_rot(t);
      else
         t = lr_rot(t);
   }

    else if (bal_factor > 1)
     {
      if (difference(t->r) > 0)
         t = rr_rot(t);
      else
         t = rl_rot(t);
   }

   return t;
}
Node* avl_tree::insert(Node *r, int UID,Person* p)
{
   if (r == NULL) 
   {
      r = new Node;

      r->d = UID;

      r->p = p;

      r->l = NULL;

      r->r = NULL;

      return r;
   } 

   else if (UID > (r->d)) 
   {
      r->l = insert(r->l, UID,p);

      r = balance(r);
   } 

   else if (UID < (r->d)) 
   {
      r->r = insert(r->r, UID,p);

      r = balance(r);
   } 

   return r;
}
Node* avl_tree::Creating_Id(Node* r,int Number_Of_Doses,int Covid,int Age,Person *p)
{
    // Starting Unique_id from the No. of registration done till now
    int Unique_id=0;
    // Priority given to the non-vaccinated citizens
    if(Number_Of_Doses==0)Unique_id=Unique_id*10+3;

    else Unique_id=Unique_id*10+Number_Of_Doses;
    // Priority given to the non-immuned citizens
    if(Covid==0)Unique_id=Unique_id*10+3;

    else Unique_id=Unique_id*10+Covid;
    // Priority given to the senior citizens
    Unique_id=(Unique_id*10)+(Age/10);
    Unique_id=Unique_id*1000+c;
    c--;
    // Unique_id generated and returned to insert in AVL tree
    cout<<"Your Unique Identification Number is: "<<Unique_id<<endl;
    r = insert(r,Unique_id,p);
    return r;
}
string avl_tree::showDate(Node* r,int UID)
{
   inorder(r);

   int dt = binary_search(UID);

   if(dt==-1) return "Not Registered Yet";

   string dd = to_string(dt%31+1);

   string mm = to_string(dt/31+8);

   cout<< dd+"/"+mm+"/2021";

   return "";
}

void avl_tree::showDetails(Node* r, int UID)
{
   if(r->d == UID)
   {
      cout<<"Your name is : "<<r->p->getname()<<endl;
      cout<<"Your age is : "<<r->p->getage()<<endl;
      cout<<"Your gender is : "<<r->p->getgender()<<endl;
      cout<<"Your phone no. is : "<<r->p->getphone()<<endl;
      return;
   }
   if(r->d<UID)
   {
      showDetails(r->l,UID);
   }
   if(r->d>UID)
   {
      showDetails(r->r,UID);
   }
}

int avl_tree::binary_search(int UID)
{
   int l = 0;

   int h = date.size()-1;

   while(l<=h)
   {
      int mid = (l+h)/2;

      if(date[mid]==UID)
      {
         return mid;
      }

      else if(date[mid]<UID)
      {
         h=mid-1;
      }
      
      else
      {
         l=mid+1;
      }
   }

   return -1;
}
void avl_tree::inorder(Node *t) 
{
   if (t == NULL)
      return;

      inorder(t->l);

      date.push_back(t->d);

      inorder(t->r);
}
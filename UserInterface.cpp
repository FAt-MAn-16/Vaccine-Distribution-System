#include<iostream>
#include"avl_tree.h"
using namespace std;
avl_tree *tree = new avl_tree();
Node* r;
void registration()
{
    char gender;
    int UID, N_O_D, m, month, age;
    string name,phone;
    cout<<"Enter data:"<<endl<<endl;
    cout<<"Enter Name:  ";
    cin>>name;
    cout<<"Enter Age:  ";
    cin>>age;
    cout<<"Enter Gender:  ";
    cin>>gender;
    cout<<"No. of doses completed:    ";
    cin>>N_O_D;
    
    if(N_O_D == 0 || N_O_D == 1)
    {
        if(N_O_D == 0)
            N_O_D =3;
        else
        {
            cout<<"When was the last dose taken:    ";
            cin>>m;
            if(m==1)
                N_O_D = 1;
            else
                N_O_D = 2;
        }
    }
    else
        cout<<"Your vaccination is complete. You are covid immune. Congrats!";
        
    cout<<"Have you contracted COVID19 in the last two months?"<<endl;
    cout<<"If YES"<<endl;
    cout<<"If you got infected 2 months ago, Enter 2\n";
    cout<<"If you got infected 1 month ago, Enter 1\n";
    cout<<"If NO"<<endl<<"Enter 0"<<endl;
    cin>>month;
    cout<<"Enter Phone No.:    ";
    cin>>phone;

    Person *p = new Person(name,age,gender,phone);
    
    r = tree->Creating_Id(r,N_O_D, month, age,p);
    
    cout<<"Registration Complete"<<endl;
    return;
}

void login()
{
    int uid;
    cout<<"Enter your Unique ID:    ";
    cin>>uid;
    cout<<"Your Details: ";
    tree->showDetails(r,uid);
    cout<<"Your Vaccination Date is: ";
    tree->showDate(r,uid);
    cout<<endl<<endl<<endl<<"==========================================================================="<<endl;
}

int main()
{
    
    char status='a';
    int flag=0;
    string name,phone;
    while(status!='e')
    {
        cout<<endl<<endl<<endl<<"=========Your Session starts here==========="<<endl<<endl<<endl;
        cout<<"Welcome to Vaccine Registration Booth"<<endl;
        cout<<"1. Registration (r)"<<endl<<"2. Login In (l)"<<endl<<"3. Exit (e)"<<endl;
        cout<<"Enter choice:    ";
        cin>>status;
        switch(status)
        {
            case 'r':
                    registration();
                    break;
            
            case 'l': 
                    login();
                    break;
            case 'e':
                    flag=1;
                    break;
            default:
                    cout<<"Invalid choice"<<endl;
                    break;
        }
        if(flag)
            break;
    }
}
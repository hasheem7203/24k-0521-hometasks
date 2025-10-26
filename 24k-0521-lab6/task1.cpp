#include<iostream>
#include<string>
using namespace std;

struct Call {
    string name ;
    string number ;
    int duration ;
};

class CallHistory {
private:
    Call stack[100];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1 ;
    }

    bool empty() {
        return topIndex==-1 ;
    }

    void push (Call c) {
        if (topIndex>=99){
            cout<<"Call history full.\n";
            return ;
        }
        stack[++topIndex]=c ;
        cout<<"Added call from "<<c.name<<endl ;
    }

    void pop (){
        if ( empty() ){
            cout<<"No calls to remove.\n";
            return ;
        }
        cout<<"Removed last call: "<<stack[topIndex].name <<endl ;
        topIndex-- ;
    }

    void top (){
        if ( empty() ){
            cout<<"No recent call.\n";
            return ;
        }
        cout<< "\n--- Last Call ---\n"; 
        cout <<"Name: " <<stack[topIndex].name <<endl ; 
        cout<< "Number: " << stack[topIndex].number << endl ;
        cout<< "Duration: "<< stack[topIndex].duration<< " sec\n" ;
    }
};

int main (){
    CallHistory history ;
    int choice ;

    do {
        cout<<"\n1. Add Call";
        cout<<"\n2. Remove Last Call";
        cout<<"\n3. View Last Call";
        cout<<"\n4. Check if Empty";
        cout<<"\n5. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice ;
        cin.ignore();

        if (choice==1){
            Call c;
            cout<<"Enter Name: ";
            getline(cin ,c.name);
            cout<<"Enter Number: ";
            getline(cin ,c.number);
            cout<<"Enter Duration (sec): ";
            cin>>c.duration;
            history.push(c);
        }
        else if (choice==2){
            history.pop();
        }
        else if (choice==3){
            history.top();
        }
        else if (choice==4){
            if (history.empty())
                cout<<"Call history empty.\n";
            else
                cout<<"Calls exist in history.\n";
        }
        else if (choice==5){
            cout<<"Exiting...\n";
        }
        else{
            cout<<"Invalid choice.\n";
        }

    } while (choice !=5);

    return 0 ;
}

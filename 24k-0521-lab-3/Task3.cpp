#include <iostream>
using namespace std;

class node {
    public:
    int id;
    string name;
    int price;
    node* next;
    node* prev;

    node(int i,string n,int p){
        id=i;
        name=n;
        price=p;
        next=prev=nullptr;
    }
};

class list {
    node* head;
    node* tail;

    public:
    list(){
        head=tail=NULL;
    }

    void insertEnd(int id,string name,int price){
        node* newnode=new node(id,name,price);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    void insertFront(int id,string name,int price){
        node* newnode=new node(id,name,price);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void removeFront(){
        if(head==NULL){
            cout<<"Cart is empty!"<<endl;
            return;
        }
        node* temp=head;
        head=head->next;
        if(head!=NULL) head->prev=NULL;
        else tail=NULL;
        delete temp;
    }

    void removeEnd(){
        if(tail==NULL){
            cout<<"Cart is empty!"<<endl;
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL) tail->next=NULL;
        else head=NULL;
        delete temp;
    }

    void searchByID(int id){
        node* temp=head;
        while(temp!=NULL){
            if(temp->id==id){
                cout<<"Found: ID="<<temp->id<<", "<<temp->name<<", $"<<temp->price<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Item with ID "<<id<<" not found!"<<endl;
    }

    void updatePrice(int id,int newPrice){
        node* temp=head;
        while(temp!=NULL){
            if(temp->id==id){
                temp->price=newPrice;
                cout<<"Price updated for "<<temp->name<<" to $"<<newPrice<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Item with ID "<<id<<" not found!"<<endl;
    }

    void displayForward(){
        cout<<"Cart (Forward):"<<endl;
        node* temp=head;
        while(temp!=NULL){
            cout<<"ID="<<temp->id<<", "<<temp->name<<", $"<<temp->price<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    void displayBackward(){
        cout<<"Cart (Backward):"<<endl;
        node* temp=tail;
        while(temp!=NULL){
            cout<<"ID="<<temp->id<<", "<<temp->name<<", $"<<temp->price<<endl;
            temp=temp->prev;
        }
        cout<<endl;
    }

    int countItems(){
        int cnt=0;
        node* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    void mostExpensive(){
        if(head==NULL){
            cout<<"Cart is empty!"<<endl;
            return;
        }
        node* temp=head;
        node* maxNode=head;
        while(temp!=NULL){
            if(temp->price > maxNode->price){
                maxNode=temp;
            }
            temp=temp->next;
        }
        cout<<"Most Expensive: ID="<<maxNode->id<<", "<<maxNode->name<<", $"<<maxNode->price<<endl;
    }
};

int main(){
    list cart;

    cart.insertEnd(1,"Laptop",1000);
    cart.insertEnd(2,"Phone",700);
    cart.insertEnd(3,"Tablet",400);
    cart.insertEnd(4,"Headphones",150);

    cart.displayForward();
    cart.insertFront(5,"Smartwatch",200);
    cart.displayForward();
    cart.removeFront();
    cart.displayForward();
    cart.removeEnd();
    cart.displayForward();
    cart.searchByID(2);
    cart.updatePrice(2,750);
    cart.displayBackward();
    cout<<"Total items: "<<cart.countItems()<<endl;
    cart.mostExpensive();
}

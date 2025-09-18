#include <iostream>
using namespace std;

class node {
public:
    string item;
    int price;
    node* next;
    node(string name,int cost) {
        item=name;
        price=cost;
        next=nullptr;
    }
};

class list {
    node* head;
    node* tail;

public:
    list() {
        head =tail=NULL;
    }

    void pushfront(string name,int price) {
        node* newnode=new node(name,price);
        if (head==NULL) {
            head=tail=newnode;
        } else {
            newnode->next=head;
            head=newnode;
        }
    }

    void pushback(string name, int price) {
        node* newnode=new node(name, price);
        if (head==NULL) {
            head=tail =newnode;
        } else {
            tail->next= newnode;
            tail =newnode;
        }
    }

    void insertAfter(string prevItem, string name, int price) {
        node* temp=head;
        while (temp!=NULL &&temp->item!=prevItem) {
            temp=temp->next;
        }

        if (temp==NULL){
            cout<< "Item "<<prevItem<<" not found!"<< endl;
            return;
        }

        node* newnode=new node(name, price);
        newnode->next=temp->next;
        temp->next =newnode;
        if (temp ==tail) tail= newnode;
    }

    void search(string name) {
        node* temp=head;
        while(temp!=NULL) {
            if(temp->item==name) {
                cout<<name<<" fund! Price: $"<<temp->price<<endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in cart!" << endl;
    }

    void display() {
        node* temp=head;
        cout<<"Shopping Cart:"<<endl;
        while(temp!=NULL) {
            cout<<temp->item<<" -- $"<<temp->price<<endl;
            temp=temp->next;
        }
        cout << endl;
    }
};

int main() {
    list shoppingCart;
    shoppingCart.pushback("Laptop",1000);
    shoppingCart.pushback("Phone",700);
    shoppingCart.pushback("Tablet",400);
    shoppingCart.pushback("Headphones",150);

    shoppingCart.pushfront("Smartwatch",200);
    shoppingCart.pushback("Keyboard",80);
    shoppingCart.insertAfter("Phone","Monitor",300);
    shoppingCart.search("Tablet");
    shoppingCart.display();
}

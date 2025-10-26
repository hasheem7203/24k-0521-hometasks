#include <iostream>
#include <string>
using namespace std ;

class Node {
public:
    string link ;
    Node* nextPage ;

    Node (string site) {
        link = site ;
        nextPage = NULL ;
    }
} ;

class Stack {
    string stackArr[100] ;
    int topPos ;
public:
    Stack() {
        topPos = -1 ;
    }

    void push (string site) {
        if (topPos < 99)
            stackArr[++topPos] = site ;
    }

    string pop () {
        if (topPos >= 0)
            return stackArr[topPos--] ;
        return "" ;
    }

    bool isEmpty () {
        return (topPos < 0) ;
    }

    string peek () {
        if (isEmpty())  return "" ;
        return stackArr[topPos] ;
    }
} ;

class BrowserHistory {
public:
    Node* head ;
    BrowserHistory() {
        head = NULL ;
    }

    void visitSite (string site) {
        Node* n = new Node(site) ;
        n->nextPage = head ;
        head = n ;
    }

    void removeRecent () {
        if (!head) return ;
        Node* temp = head ;
        head = head->nextPage ;
        delete temp ;
    }

    void showHistory () {
        cout<<"History (most recent → oldest): " ;
        Node* cur = head ;
        while (cur) {
            cout<<cur->link<<" " ;
            cur = cur->nextPage ;
        }
        cout<<endl ;
    }
} ;

int main () {
    BrowserHistory bh ;
    Stack backTrack ;

    string websites[] = {"Google","Facebook","Twitter","LinkedIn","Instagram"} ;

    for (int i=0 ; i<5 ; i++) {
        bh.visitSite(websites[i]) ;
        backTrack.push(websites[i]) ;
    }

    cout<<"After visiting sites:\n" ;
    bh.showHistory() ;

    cout<<"\nUser BACK twice\n" ;
    for (int i=0 ; i<2 ; i++) {
        string gone = backTrack.pop() ;
        bh.removeRecent() ;
        cout<<"Leaving: "<<gone<<endl ;
    }

    cout<<"\nCurrently on: "<<backTrack.peek()<<endl ;
    bh.showHistory() ;

    return 0 ;
}

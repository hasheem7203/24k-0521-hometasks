#include <iostream>
#include <string>
using namespace std ;

class Stack {
    char st[100] ;
    int top ;
public:
    Stack() { top = -1 ; }

    void push (char ch) {
        if (top < 99)
            st[++top] = ch ;
    }

    char pop () {
        if (top >= 0)
            return st[top--] ;
        return '\0' ;
    }

    char peek () {
        if (top >= 0)
            return st[top] ;
        return '\0' ;
    }

    bool empty () {
        return (top == -1) ;
    }
} ;

int prec (char op) {
    if (op == '^') return 3 ;
    if (op == '*' || op == '/') return 2 ;
    if (op == '+' || op == '-') return 1 ;
    return -1 ;
}

string infixToPostfix (string exp) {
    Stack stk ;
    string out = "" ;

    for (int i=0 ; i<exp.size() ; i++) {
        char c = exp[i] ;

        if ( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ) {
            out += c ;
        }
        else if (c == '(') {
            stk.push(c) ;
        }
        else if (c == ')') {
            while (!stk.empty() && stk.peek() != '(') {
                out += stk.pop() ;
            }
            if (!stk.empty() && stk.peek() == '(') stk.pop() ;
        }
        else {
            while (!stk.empty() && prec(c) <= prec(stk.peek())) {
                out += stk.pop() ;
            }
            stk.push(c) ;
        }
    }

    while (!stk.empty()) {
        out += stk.pop() ;
    }

    return out ;
}

int main () {
    string infix ;
    cout<<"Type an infix expression: " ;
    cin>>infix ;

    string result = infixToPostfix(infix) ;
    cout<<"Converted postfix: "<<result<<endl ;

    return 0 ;
}

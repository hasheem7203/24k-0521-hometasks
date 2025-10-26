#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Stack {
    double arr[100];
    int topIndex ;
public:
    Stack (){
        topIndex = -1 ;
    }
    bool empty (){
        return topIndex == -1 ;
    }
    void push (double x){
        arr[++topIndex] = x ;
    }
    double pop (){
        if ( empty() ){
            cout<<"Stack underflow.\n";
            return 0 ;
        }
        return arr[topIndex--] ;
    }
    double top (){
        if ( empty() ){
            cout<<"Stack empty.\n";
            return 0 ;
        }
        return arr[topIndex] ;
    }
};

int main (){
    Stack s ;
    string exp ;

    cout<<"Enter postfix expression: " ;
    cin>>exp ;

    for (int i = 0 ; i < exp.length() ; i++ ){
        char ch = exp[i] ;

        if ( isdigit(ch) ){
            s.push(ch - '0') ;
        }
        else {
            double op2 = s.pop() ;
            double op1 = s.pop() ;
            double res ;

            if ( ch == '+' ) res=op1+op2 ;
            else if(ch == '-' )res=op1-op2 ;
            else if(ch == '*' )res= op1 * op2 ;
            else if(ch== '/' ) res = op1 / op2 ;
            else if ( ch=='^' ) res= pow(op1 , op2) ;
            else {
                cout<<"Invalid operator "<<ch<<endl ;
                return 0 ;
            }

            s.push(res) ;
        }
    }

    if ( !s.empty() )
        cout<<"Result: "<<s.top() <<endl ;
    else
        cout<<"Invalid Expression\n" ;

    return 0 ;
}

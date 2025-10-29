#include <iostream>
using namespace std;

const int SIZE = 100;

class Stack {
    char data[SIZE];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        data[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        return data[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return data[top];
    }
};

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string exp) {
    Stack s;
    string post = "";

    for (int i=0;exp[i]!='\0'; i++) {
        char c=exp[i];

        if ((c>='a'&&c<='z')||(c >='A' &&c <='Z')||(c>= '0'&&c<='9')) {
            post +=c;
        }
        else if (c== '(') {
            s.push(c);
        }
        else if (c== ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                post+= s.pop();
            }
            if(!s.isEmpty()) s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek())>= precedence(c)) {
                if (c=='^' && s.peek()=='^') break;
                post+= s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        post +=s.pop();
    }

    return post;
}

int main() {
    string exp;
    cout <<"Enter infix expression: ";
    cin>>exp;

    string result=infixToPostfix(exp);
    cout<<"Postfix expression: "<<result<<endl;

    return 0;
}

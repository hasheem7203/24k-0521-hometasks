#include <iostream>
using namespace std;

class exam{
    private:
        int* marks;
        int count;
    
    public:
        exam(int n){
            count =n;
            marks=new int[count];
            for(int i=0;i<n;i++){
                marks[i]=0;
            }
        }

        void setMarks(int i ,int val){
            marks[i]=val;
        }

        void display(){
            cout<<"makrs: \n";
            for(int i=0;i<count;i++){
                cout<<marks[i]<<endl;
            }
            cout<<endl;
        }

        ~exam(){
            delete[] marks;
        }
};

int main(){
    exam e1(2);
    e1.setMarks(0,90);
    e1.setMarks(1,95);

    cout << "exam 1: "<<endl ;
    e1.display();

    exam e2=e1;
    cout<< "exam 2: "<<endl;
    e2.display();

    e1.setMarks(0,50);
    cout<<"exam 1: ";
    e1.display();
    cout<< "exam 2: "<<endl;
    e2.display();

}


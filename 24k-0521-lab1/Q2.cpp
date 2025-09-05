#include <iostream>
#include <string>
using namespace std;

class box{
    private:
        int* volume;

    public:
        box(){
            volume =new int(0);
        }

        box (int v){
            volume =new int(v);
        }

        box(const box& o){
            volume =new int(*o.volume);
        }

        ~box(){
            delete volume;
        }

        void setVolume(int v){
            *volume=v;
        }
        void display(){
            cout <<"volume : "<<*volume<<endl;
        }

};



int main(){
    box b1(50);
    cout<<"Box 1 :"<<endl;
    b1.display();

    box b2=b1;
    cout<<"Box 2 :"<<endl;
    b2.display();
    
    b1.setVolume(34);
    cout<<"Box 1 :"<<endl;
    b1.display();

    cout<<"Box 2 :"<<endl;
    b2.display();


    return 0;
}

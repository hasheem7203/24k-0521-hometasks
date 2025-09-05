#include <iostream>
#include <cstring>
using namespace std;



class researchPaper{
    private:
        string* name;
        int authorcount;


    public:
        researchPaper(int count){
            authorcount=count;
            name=new string[authorcount];
        }

        researchPaper(const researchPaper& o){
            authorcount=o.authorcount;
            name=new string[authorcount];
            for(int i=0;i<authorcount;i++){
                name[i]=o.name[i];
            }
        }

        researchPaper& operator=(const researchPaper& o){
            authorcount=o.authorcount;
            name = new string[authorcount];
                    for (int i = 0; i < authorcount; i++) {
                        name[i] = o.name[i];
                    }
            return *this;
        }

    void setAuthor(int i, const string& n) {
        if (i >= 0 && i < authorcount) {
            name[i] = n;
        }
    }

    void display() const {
        for (int i=0;i< authorcount; i++) {
            cout << name[i]<<" ,";
        }
        cout << endl;
    }


        researchPaper(){
            delete[] name;
        }

};



int main() {
    researchPaper rp1(2);
    rp1.setAuthor(0, "Ali");
    rp1.setAuthor(1, "mustafa");

    cout << "Authors1:" << endl;
    rp1.display();

    researchPaper rp2 = rp1;
    rp2.setAuthor(0, "muzzamil");

    cout << "\nAuthors2:" << endl;
    rp2.display();

    cout << "Authors1:" << endl;
    rp1.display();

    return 0;
}
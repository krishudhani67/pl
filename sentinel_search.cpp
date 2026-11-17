#include <iostream>
using namespace std;

class phone{
    string name[51];
    string mobile[51];
    int n;
public:
    phone(){
        n =0;
    }

    void add(string nm,string mob){
        if(n==50){
            cout<<"phone is full"<<endl;
            return;
        }
        int i=n-1;
        while(i>=0 && name[i]>nm){
            name[i+1] = name[i];
            mobile[i+1] = mobile[i];
            i--;
        }
        name[i+1] = nm;
        mobile[i+1] = mob;
        n++;
    }

    int search (string key){
        name[n] = key;
        int i = 0;

        while(name[i]!=key){
            i++;
        }
        if(i==n){
            return -1;
        }
        return i;

    }
    void display(){
        for(int i=0;i<n;i++){
            cout<<name[i]<<" - "<<mobile[i]<<endl;
        }
    }
};

int main(){
    phone p;
    int choice;
    string name, mobile;
    do{
        cout<<"==== Menu ====\n";
        cout<<"1. Add\n";
        cout<<"2. Search\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter your name and mobile number : \n";
                cin>>name>>mobile;
                if(p.search(name)==-1){
                    p.add(name,mobile);
                }
                else{
                    cout<<"Friend already exist"<<endl;
                }
                break;

            case 2:
                cout<<"enter name to search : \n";
                cin>>name;
                if(p.search(name)==-1){
                    cout<<"Not found lets add enter number : ";
                    cin>>mobile;
                    p.add(name,mobile);
                }
                else{
                    cout<<"Friend Found";
                    
                }
                break;

            case 3:
                p.display();
                break;

            case 4:
                break;
 
        }
    }while(choice!=4);
}
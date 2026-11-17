#include <iostream>
using namespace std;

class patient{
    public:
        string name;
        int age;
        int priority;
};

class priorityqueue{
    int n;
    patient p[50];

    public:
        priorityqueue(){
            n=0;
        }
        void add();
        void serve();
        void display();

};

void priorityqueue::add(){
    if(n==50){
        cout<<"Queue is Full"<<endl;
        return;
    }
    patient x;
    cout<<"Enter name of patient : ";
    cin.ignore();              
    getline(cin, x.name);
    cout<<endl;
    cout<<"Enter Age of Patient : ";
    cin>>x.age;
    cout<<endl;
    cout<<"Enter Priority : ";
    cin>>x.priority;

    int i = n-1;
    while(i>=0 && p[i].priority > x.priority){
        p[i+1] = p[i];
        i--;
    }
    p[i+1] = x;
    n++;
}

void priorityqueue::serve(){
    if(n==0){
        cout<<"No one is in the queue"<<endl;
        return;
    }
    cout<<"serving"<<p[0].name<<endl<<"age : "<<p[0].age<<endl;

    for(int i=0;i<n-1;i++){
        p[i]=p[i+1];
        
    }
    n--;

}

void priorityqueue::display(){
    if(n==0){
        cout<<"No patient is waiting "<<endl;
    }
    else{
        cout<<"name\tage\tpriority"<<endl;
        for(int i=0;i<n;i++){
            cout<<p[i].name<<"\t"<<p[i].age<<"\t"<<p[i].priority<<endl;
        }

    }
}

int main(){
    priorityqueue pq;
    int choice;
    do{
        cout<<"====  Menu  ====\n";
        cout<<"1. add new patient\n";
        cout<<"2. serve patient\n";
        cout<<"3. Display patients\n";
        cout<<"4. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                pq.add();
                break;

            case 2:
                pq.serve();
                break;

            case 3:
                pq.display();
                break;
            
            case 4:
                cout<<"Exiting\n";
                break;

            default:
                cout<<"Invaild choice\n";
                break;
        }
    }while(choice!=4);

}
#include <iostream>
using namespace std;

class Rotation{
    int arr[50];
    int n;

    public:
        void read();
        void display();
        void leftRotation(int k);
        void rightRotation(int k);
};

void Rotation::read(){
    cout<<"enter total number of elements : ";
    cin>>n;
    cout<<"Enter all the n elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void Rotation::display(){
    cout<<"Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Rotation::leftRotation(int k){
    for(int step=1;step<=k;step++){
        int first = arr[0];
            for(int i=0;i<n-1;i++){
                arr[i] = arr[i+1];
            }
            arr[n-1] = first;
    }
}
void Rotation::rightRotation(int k){
    for(int step=1;step<=k;step++){
        int last = arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
}


int main(){
    Rotation r;
    int choice,k;

    do{
        cout<<"===== Menu =======\n";
        cout<<"1. Input array "<<endl;
        cout<<"2. Left Rotate array "<<endl;
        cout<<"3. Right Rotate "<<endl;
        cout<<"4. Display "<<endl;
        cout<<"5. Exit"<<endl;

        cin>>choice;

        switch(choice){
            case 1:
                r.read();
                break;
                
            case 2:
                cout<<"Enter K : ";
                cin>>k;
                r.leftRotation(k);
                r.display();
                break;

            case 3:
                cout<<"Enter K : ";
                cin>>k;
                r.rightRotation(k);
                r.display();
                break;

            case 4: 
                r.display();
                break;
            
            case 5:
                cout<<"Exiting -- "<<endl;
                break;
            
            default:
                cout<<"Incorrect Choice"<<endl;
                break;

        }
    }while(choice!=5);
}
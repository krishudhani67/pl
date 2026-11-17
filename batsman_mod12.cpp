#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class hashtable{
    node* table[12];
    public:
        hashtable(){
            for(int i=0;i<12;i++){
                table[i]=NULL;
            }
        }

        int hashfunc(int key){
            return key%12;
        }

        void insertkey(int key){
            int index = hashfunc(key);

            node* n = new node;
            n->data=key;
            n->next = NULL;

            if(table[index]==NULL){
                table[index] = n;
            }
            else{
                node* temp = table[index];
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = n;
            }
            cout<<key<<" inserted at index "<<index<<endl;
        }

        void search(int key){
            int index = hashfunc(key);
            node* temp = table[index];
            while(temp!=NULL){
                if(temp->data == key){
                    cout<<key<<" found at index "<<index<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"Key not found"<<endl;
        }

        void display(){
            cout<<"\n Hash Table \n";
            for(int i=0;i<12;i++){
                cout<<i<<"->";
                node* temp = table[i];
                while(temp!=NULL){
                    cout<<temp->data<<"->";
                    temp = temp->next;
                }
                cout<<" NULL "<<endl;
            }
        }
};


int main(){
    hashtable h;
    int choice,key;

    int data[12] = {10, 5, 4, 14, 15, 20,
                    1, 11, 6, 16, 36, 28};

    do{
        cout<<"Menu\n";
        cout<<"1. insert given data\n";
        cout<<"2. insert new key\n";
        cout<<"3. Search\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cin>>choice;

        switch (choice){
            case 1:
                for(int i=0;i<12;i++){
                    h.insertkey(data[i]);
                    
                }
                break;
            
            case 2:
                cout<<"Enter key : ";
                cin>>key;
                h.insertkey(key);
                break;

            case 3:
                cout<<"Enter key to search : ";
                cin>>key;
                h.search(key);
                break;

            case 4:
                h.display();
                break;

            case 5:
                cout<<"Exiting"<<endl;
                break;
        }
    }
    while(choice!=5);
}
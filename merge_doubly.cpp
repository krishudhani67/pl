#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* prev;
    node* next;

    
};

class doubly{
    public:
    node* head;
    doubly(){
        head = NULL;
    }
    
        void insertAtEnd(int d);

        void display();
        void mergeAlternate(doubly& list2);
        void sort();
};

void doubly::insertAtEnd(int d){
    node* n = new node;
    n->data =d;
    n->prev = NULL;
    n->next = NULL;
    if(head==NULL){
        head = n;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void doubly::display(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }

        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"<->";
            temp = temp->next;
        }
        
    
}

void doubly::mergeAlternate(doubly& list2){
    if(head == NULL){
        head = list2.head;
        list2.head = NULL;
        return;
    }

    node* p = head;
    node* q = list2.head;
    while(p!=NULL && q!=NULL){
        node* pnext = p->next;
        node* qnext = q->next;

        p->next = q;
        q->next = pnext;
        q->prev = p;
        if(pnext!=NULL){
            pnext->prev = q;
        }

        p = pnext;
        q = qnext;

    }
    if(q!=NULL){
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = q;
        q->prev = temp;
    }
    list2.head = NULL;
}

void doubly::sort(){
    for(node* i=head; i!=NULL; i=i->next){
        for(node* j=head; j->next!=NULL; j=j->next){
            if(j->data > j->next->data){
                swap(j->data, j->next->data);
            }
        }
    }
}

int main(){
    doubly list1, list2;
    int choice,val;

    do{
        cout<<"=== MENU ===\n";
        cout<<"1. Insert in List 1\n";
        cout<<"2. Insert in List 2\n";
        cout<<"3. Display both lists\n";
        cout<<"4. Merge List 2 in 1\n";
        cout<<"5. Sort List\n";
        cout<<"6. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value : ";
                cin>>val;
                list1.insertAtEnd(val);
                break;
            case 2:
                cout<<"Enter value : ";
                cin>>val;
                list2.insertAtEnd(val);
                break;

            case 3:
                cout<<"List 1 : \n";
                list1.display();
                cout<<endl;
                cout<<"List 2 : \n";
                list2.display();
                cout<<endl;
                break;

            case 4:
                list1.mergeAlternate(list2);
                cout<<"Merged List : ";
                list1.display();
                break;

            case 5: 
                list1.sort();
                cout<<"Sorted List : ";
                list1.display();
                break;


            case 6:
                cout<<"exiting ";
                break;

            default:
                cout<<"Invalid choice";
                break;


        }
    }while(choice!=6);
}

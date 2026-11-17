#include <iostream>
using namespace std;

class node{
public:
    int coef, expo;
    node *next;
};

class polynomial{
    node* head;

    public:
        polynomial(){
            head=NULL;
        }

        void insertAtEnd(int c, int e);
        void read();
        void display();
        void addPolynomial(polynomial p1, polynomial p2);
};

void polynomial::insertAtEnd(int c, int e){
    node* n = new node;
    n->coef = c;  
    n->expo = e;
    n->next = NULL;
    if(head == NULL){
        head = n;
    } 
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}

void polynomial::read(){
    int terms, c,e;
    cout<<"Enter number of terms : "<<endl;
    cin>>terms;
    for(int i=1;i<=terms;i++){
        cout<<"Enter coef and expo of term "<<i<<" : "<<endl;
        cin>>c>>e;
        insertAtEnd(c,e);
    }
}

void polynomial:: display(){
    for(node* temp=head;temp!=NULL;temp=temp->next){
        cout<<temp->coef<<"x^"<<temp->expo;
        if(temp->next != NULL){
            cout<<" + ";
        }
        
    }
    cout<<endl;
}

void polynomial::addPolynomial(polynomial p1, polynomial p2){
    node* a = p1.head;
    node* b = p2.head;

    while(a!=NULL && b!= NULL){
        if(a->expo == b->expo){
            insertAtEnd(a->coef+b->coef, a->expo);
            a = a->next;
            b = b->next;
        }
        else if(a->expo > b->expo){
            insertAtEnd(a->coef,a->expo);
            a=a->next;
        }
        else{
            insertAtEnd(b->coef,b->expo);
            b=b->next;
        }
    }
    while(a != NULL){
        insertAtEnd(a->coef,a->expo);
            a=a->next;
    }
    while(b != NULL){
        insertAtEnd(b->coef,b->expo);
            b=b->next;
    }
}

int main(){
    polynomial p1, p2, sum;

    cout<<"First Polynomial : "<<endl;
    p1.read();
    cout<<"Second Polynomial : "<<endl;
    p2.read();

    cout<<"P1 : \n";
    p1.display();
    cout<<"P2 : \n";
    p2.display();

    sum.addPolynomial(p1,p2);
    cout<<"Sum : ";
    sum.display();
}
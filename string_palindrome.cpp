#include <iostream>
using namespace std;

class deque{
    char arr[100];
    int front,rear;
public:
    deque(){
        front = 0;
        rear = -1;
    }
    int size(){
        return rear-front+1;
    }

    void insertrear(char ch){
        rear++;
        arr[rear] = ch;
        
    }
    char deletefront(){

        return arr[front++];
        
    }

    char deleterear(){
        return arr[rear--];
    }

    bool palindrome(){
        while(front<rear){
            if(deletefront()!=deleterear()){
                return false;
            }
            
        }
        return true;
    }
};

int main(){
    deque d;
    string s;

    cout<<"Enter string : ";
    cin>>s;
    cout<<endl;
    for(int i=0;i<s.size();i++){
        d.insertrear(s[i]);
    }
    if(d.palindrome()){
        cout<<"palindrone :)"<<endl;
    }
    else{
        cout<<"Not Palindrome :(";
    }
}

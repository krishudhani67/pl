#include <iostream>
using namespace std;

class hanoi{
    int moves;

    public:
        hanoi(){
            moves=0;
        }
        void solve(int n, char from, char to, char aux){
            if(n==0){
                return;
            }
            solve(n-1,from,aux,to);
            cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
            moves++;
            solve(n-1,aux,to,from);
        }

        void showTotal(){
            cout<<"Total moves : "<<moves<<endl;
        }
};

int main(){
    int n;
    cout<<"enter number of disks : ";
    cin>>n;
    hanoi h;
    h.solve(n,'A','C','B');
    h.showTotal();
    return 0;
}
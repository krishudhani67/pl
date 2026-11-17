#include <iostream>
using namespace std;

// addition and multiplication of two matrices

class matrix{
    int arr[10][10];
    int row, col;
public:
    void read();
    void display();
    void add(matrix B);
    void multiply(matrix B);

};

void matrix:: read(){
    cout<<"Enter Rows and Cols : ";
    cin>>row>>col;

    cout<<"Enter Elements of Matrix : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
}

void matrix:: display(){
    cout<<"=====  Matrix  ====\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrix:: add(matrix B){
    if(row != B.row || col != B.col){
        cout<<"Addition not possible "<<endl;
        return;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<< arr[i][j] + B.arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrix:: multiply(matrix B){
    if(col != B.row){
        cout<<"Multiplication not possible "<<endl;
        return;
    }
    for(int i=0;i<row;i++){
        for( int j=0;j<B.col;j++){
            int sum = 0;
            for(int k=0;k<col;k++){
                sum = sum + arr[i][k] * B.arr[k][j];
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }
}

int main(){
    matrix A,B;
    int choice;

    do{
        cout<<"==========  Menu  ================\n";
        cout<<"1. input matrices\n";
        cout<<"2. add matrices\n";
        cout<<"3. multiply matrices\n";
        cout<<"4. Display matrices\n";
        cout<<"5. exit menu\n";

        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Input Matrix A\n";
                A.read();
                cout<<"Input Matrix B\n";
                B.read();
                break;

            case 2:
                A.add(B);
                break;
            
            case 3:
                A.multiply(B);
                break;

            case 4:
                cout<<" Matrix A\n";
                A.display();
                cout<<" Matrix B\n";
                B.display();
                break;

            case 5:
                cout<<"exit cya "<<endl;
                break;
            
            default:
                cout<<"Invalid Choice nga"<<endl;
                break;
        }
    }while(choice!=5);
}

// Problem 6 (simplest): 8 Queens using a stack
// stack[r] = column of the queen placed in row r
#include <iostream>
using namespace std;
 
class Queens {
    int stack[8];
    int top;
 
    void push(int col) {
        top++;
        stack[top] = col;
    }
 
    int pop() {
        int col = stack[top];
        top--;
        return col;
    }
 
    // can we place a queen at (row, col)?
    bool isSafe(int row, int col) {
        for (int r = 0; r < row; r++) {
            int c = stack[r];
            if (c == col || row - r == c - col || row - r == col - c)
                return false;                     // same column or same diagonal
        }
        return true;
    }
 
public:
    Queens() {
        top = -1;
    }
 
    bool solve() {
        int row = 0, col = 0;
        while (row < 8) {
            while (col < 8 && !isSafe(row, col))  // look for a safe column
                col++;
 
            if (col < 8) {                        // found: place queen, go to next row
                push(col);
                row++;
                col = 0;
            }
            else {                                // not found: backtrack
                if (row == 0)
                    return false;
                col = pop() + 1;
                row--;
            }
        }
        return true;
    }
 
    void display() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (stack[r] == c) cout << " Q ";
                else cout << " . ";
            }
            cout << endl;
        }
    }
};
 
int main() {
    Queens q;
    if (q.solve())
        q.display();
    else
        cout << "No solution\n";
    return 0;
}
 
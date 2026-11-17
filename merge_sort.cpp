
// Problem 12 (simple): Sort percentages of students using Merge Sort
#include <iostream>
using namespace std;
 
class Students {
    float per[50];
    int n;
 
    // merge two sorted halves: [low..mid] and [mid+1..high]
    void merge(int low, int mid, int high) {
        float temp[50];
        int i = low;           // pointer in left half
        int j = mid + 1;       // pointer in right half
        int k = low;           // pointer in temp
 
        while (i <= mid && j <= high) {
            if (per[i] <= per[j]) {
                temp[k] = per[i];
                i++;
            }
            else {
                temp[k] = per[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {                 // left half leftovers
            temp[k] = per[i];
            i++;
            k++;
        }
        while (j <= high) {                // right half leftovers
            temp[k] = per[j];
            j++;
            k++;
        }
        for (int x = low; x <= high; x++)  // copy back
            per[x] = temp[x];
    }
 
    void mergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(low, mid);           // sort left half
            mergeSort(mid + 1, high);      // sort right half
            merge(low, mid, high);         // merge them
        }
    }
 
public:
    void read() {
        cout << "Enter number of students: ";
        cin >> n;
        cout << "Enter percentages:\n";
        for (int i = 0; i < n; i++)
            cin >> per[i];
    }
 
    void sort() {
        mergeSort(0, n - 1);
    }
 
    void display() {
        for (int i = 0; i < n; i++)
            cout << per[i] << "  ";
        cout << endl;
    }
};
 
int main() {
    Students s;
 
    s.read();
    cout << "Before sorting: ";
    s.display();
 
    s.sort();
    cout << "After sorting : ";
    s.display();
 
    return 0;
}
 
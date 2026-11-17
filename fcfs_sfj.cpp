
// Problem 9 (simplest): FCFS and SJF (non-preemptive) scheduling
#include <iostream>
using namespace std;
 
class Scheduler {
    int n;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    bool done[20];
 
public:
    void input() {
        cout << "Enter number of processes: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "P" << i + 1 << " arrival time and burst time: ";
            cin >> at[i] >> bt[i];
        }
    }
 
    // type 1 = FCFS, type 2 = SJF
    void schedule(int type) {
        for (int i = 0; i < n; i++)
            done[i] = false;
 
        int time = 0, completed = 0;
        cout << "Order: ";
 
        while (completed < n) {
            int pick = -1;
            for (int i = 0; i < n; i++) {
                if (done[i])
                    continue;
                if (type == 1) {                              // FCFS: earliest arrival
                    if (pick == -1 || at[i] < at[pick])
                        pick = i;
                }
                else {                                        // SJF: shortest burst among arrived
                    if (at[i] <= time && (pick == -1 || bt[i] < bt[pick]))
                        pick = i;
                }
            }
 
            if (pick == -1) {                                 // nobody has arrived yet
                time++;
                continue;
            }
 
            if (time < at[pick])                              // CPU waits for arrival
                time = at[pick];
            time = time + bt[pick];
            ct[pick] = time;
            tat[pick] = ct[pick] - at[pick];
            wt[pick] = tat[pick] - bt[pick];
            done[pick] = true;
            completed++;
            cout << "P" << pick + 1 << " ";
        }
 
        float totalTat = 0, totalWt = 0;
        cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
        for (int i = 0; i < n; i++) {
            cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t"
                 << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
            totalTat += tat[i];
            totalWt += wt[i];
        }
        cout << "Average TAT = " << totalTat / n << endl;
        cout << "Average WT  = " << totalWt / n << endl;
    }
};
 
int main() {
    Scheduler s;
    int choice;
 
    do {
        cout << "\n1. Enter processes\n2. FCFS\n3. SJF\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
 
        if (choice == 1) s.input();
        else if (choice == 2) s.schedule(1);
        else if (choice == 3) s.schedule(2);
    } while (choice != 0);
 
    return 0;
}
 
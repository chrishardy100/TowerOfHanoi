/*
 * This program provides a recursive solution to the
 * "Tower of Hanoi" puzzle with 3 rings and n disks.
 * 
 * @author Christopher Hardy
 * 
*/


#include <iostream>
#include <vector>

using namespace std;
int moves = 0;

struct Solution {
public:
    // Create an array of vectors
    vector<int> t[3];
    int maxHeight;

    Solution(int numOfDisks) {
        maxHeight = numOfDisks;
        for (int i = numOfDisks; i > 0; i--)
            t[0].push_back(i);
        print2();
        solve(numOfDisks, 0, 1, 2);

    }


    // Note [1]
    void print() {
        for (int i = 0; i < 3; i++) {
            //cout << "|"; // to represent a tower beginning
            for (int j = 0; j < t[i].size(); j++) {
                cout << t[i][j] << "  ";
            }
            // new line is the next tower
            cout << endl;
        }
        // new line for seperating towers
        cout << endl;
    }

    void print2() {
        for (int i = maxHeight; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                if (i < t[j].size())
                    cout << t[j][i] << " ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
        cout << "-----" << "\n" << endl;
    }

    void solve(int n, int from, int to, int aux) {
        bool even = false;
        if (maxHeight % 2 == 0)
            even = true;

        int x = 0;
        while (t[2].size() < maxHeight) {
            if (even == true) {

                if (x == 0) {
                    makeLegalMove(0, 1);
                    x++;
                }
                else if (x == 1) {
                    makeLegalMove(0, 2);
                    x++;
                }
                else if (x == 2) {
                    makeLegalMove(1, 2);
                    x = 0;
                }

            }
            else if (even == false) {

                if (x == 0) {
                    makeLegalMove(0, 2);
                    x++;
                }
                else if (x == 1) {
                    makeLegalMove(0, 1);
                    x++;
                }
                else if (x == 2) {
                    makeLegalMove(1, 2);
                    x = 0;
                }
            }

        }
    }



    void makeLegalMove(int x, int y) {
        if (t[x].size() == 0)
            move(y, x);
        else if (t[y].size() == 0)
            move(x, y);
        else if (t[y].back() < t[x].back())
            move(y, x);
        else if (t[x].back() < t[y].back())
            move(x, y);

        //return t[2].size() == maxHeight;
    }

    void move(int from, int to) {
        int curr = t[from].back();
        t[to].push_back(curr);
        t[from].pop_back();
        print2();
        moves++;
        cout << "move: " << moves;
    }

};


int main() {
    int size;
    cout << "ENTER SIZE" << endl;
    cin >> size;
    Solution s(size);
    cout << endl <<  "TOTAL MOVES = " << moves << endl;
}
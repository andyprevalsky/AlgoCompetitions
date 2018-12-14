#include <fstream>
using namespace std;

class Solution {
    private:
        int c1, c2, c3, b1, b2, b3; //c is capacicty and b is current amount of bucket
    public:
        void prepData() {
            ifstream fin ("mixmilk.in");
            fin >> c1 >> b1 >> c2 >> b2 >> c3 >> b3;
        }

        void rec(int pour, int start) {
            if (pour == 101) return;
            if (start == 0) { //pour b1 into b2
                if (b1 + b2 > c2) { b1 -= (c2 - b2); b2 = c2; }
                else { b2 = b1 + b2; b1 = 0; }
                rec(pour+1, 1);
            } else if (start == 1) { // 
                if (b2 + b3 > c3) { b2 -= (c3 - b3); b3 = c3; }
                else { b3 = b2 + b3; b2 = 0; }
                rec(pour+1, 2);
            } else if (start == 2) {
                if (b3 + b1 > c1) { b3 -= (c1 - b1); b1 = c1; }
                else { b1 = b3 + b1; b3 = 0; }
                rec(pour+1, 0);
            }
        }

        void main() {
            prepData();
            ofstream fout ("mixmilk.out");
            rec(1, 0);
            fout << b1 << endl << b2 << endl << b3 << endl;
        }
};

int main() {
    Solution s;
    s.main();
}
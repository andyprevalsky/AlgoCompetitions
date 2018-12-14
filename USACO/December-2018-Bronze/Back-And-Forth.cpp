#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
        int memo[2001]= {};
        int res = 0;
        vector<int> b1; vector<int> b2;
        
    public:
        void prepData() {
            ifstream fin ("backforth.in"); int a;
            for (int i = 0; i < 10; i++) { fin >> a; b1.push_back(a); }
            for (int i = 0; i < 10; i++) { fin >> a; b2.push_back(a); }
        }

        void dfs(int side, int t1, int t2, vector<int> c1, vector<int> c2) {
            if (side == 4) {
                if (memo[t1] != 1) { res++; }
                memo[t1] = 1;
                return;
            }
            if (side % 2 == 0) {
                for (int i = 0; i < c1.size(); i++) {
                    vector<int> n1 = c1; n1.erase(n1.begin()+i); vector<int> n2 = c2; n2.push_back(c1[i]);
                    dfs(side+1, t1-c1[i], t2+c1[i], n1, n2);
                }
            } else {
                for (int i = 0; i < c2.size(); i++) {
                    vector<int> n1 = c1; n1.push_back(c2[i]); vector<int> n2 = c2; n2.erase(n2.begin()+i);
                    dfs(side+1, t1+c2[i], t2-c2[i], n1, n2);
                }
            }
        }

        void main() {
            prepData();
            ofstream fout ("backforth.out");
            dfs(0, 1000, 1000, b1, b2);
            fout << res << endl;
        }
};

int main() {
    Solution s;
    s.main();
}
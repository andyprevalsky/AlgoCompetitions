#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    private:
        int N, M, C;
        int extra = 0;
        int res = 0;
        vector<int> cows;
    public:
        void prepData() {
            ifstream fin ("convention.in");
            fin >> N >> M >> C;
            int a; 
            for (int i = 0; i < N; i++) {
                fin >> a;
                cows.push_back(a);
            }
            sort(cows.begin(), cows.end());
        }

        bool isValid(int mSize) {
            int busesLeft = M-1;
            int start = cows[0];
            int numBus = 0;
            for (auto i: cows) {
                if (i-start > mSize || numBus >= C) {
                    if (busesLeft == 0) return false;
                    busesLeft--;
                    start = i;
                    numBus = 0;
                }
                numBus++;
            }

            return true;
        }

        void main() {
            prepData();
            ofstream fout ("convention.out");
            int l = 1;
            int r = cows.back();
            int  m = 0;
            while (l < r) {
                int mid = l + (r-l)/2;
                if (isValid(mid)) r = mid;
                else l = mid+1;
            }
            fout << r << endl;
        }
};

int main() {
    Solution s;
    s.main();
}
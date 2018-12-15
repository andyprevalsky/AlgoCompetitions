#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
    private:
        int N;
        vector<vector<int>> cows;
        priority_queue<vector<int>> q;
        int res = 0;
    public:
        void prepData() {
            ifstream fin ("convention2.in");
            fin >> N;
            int a, b;
            for (int i = 0; i < N; i++) {
                fin >> a >> b;
                cows.push_back({a, i, b});
            }
            sort(cows.begin(), cows.end());
        }

        void main() {
            prepData();
            ofstream fout ("convention2.out");
            int time = -1;
            for (int j = 0; j < cows.size(); j++) {
                vector<int> i = cows[j]; 
                if (i[0] <= time) q.push({N-i[1], i[0], i[2]});
                else { 
                    while (!q.empty() && time < i[0]) {
                        res = max(res, time - q.top()[1]);
                        cout << time << " " << q.top()[1] << " " << endl;
                        time += q.top()[2]; q.pop();
                    }
                    if (q.empty()) time = i[0] + i[2];
                    else q.push({N-i[1], i[0], i[2]});
                }
            }
            while (!q.empty()) { 
                res = max(res, time - q.top()[1]); 
                time += q.top()[2]; 
                q.pop(); 
            }
            fout << res << endl;
        }
};

int main() {
    Solution s;
    s.main();
}
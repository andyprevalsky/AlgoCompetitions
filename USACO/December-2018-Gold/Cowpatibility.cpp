#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
    private:
        int N; long long total = 0;
        vector<vector<int>> cows;
        unordered_map<int, set<int>> bu;
    public:
        void prepData() {
            ifstream fin ("cowpatibility.in");
            fin >> N; int a, b, c, d, e;
            for (int i = 0; i < N; i++) {
                fin >> a >> b >> c >> d >> e;
                cows.push_back({a, b, c, d, e});
            }

            for (int i = 0; i < cows.size(); i++) {
                for (auto j: cows[i]) {
                    bu[j].insert(i);
                }
            }



        }

        void main() {
            prepData();
            ofstream fout ("cowpatibility.out");
            for (int i = 0; i < cows.size(); i++) {
                set<int> s; int count = 0;
                for (auto j: cows[i]) {
                    bu[j].erase(i);
                    for (auto k: bu[j]) {
                        if (s.find(k) == s.end()) { s.insert(k); count++; }
                    }
                }
                total += count;
            }
            fout << (cows.size()*(cows.size()-1))/2 - total << endl;
            
        }
};

int main() {
    Solution s;
    s.main();
}
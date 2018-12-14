#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:
        int N; int res = 0;
        vector<vector<int>> cows;
    public:
        void prepData() {
            ifstream fin ("blist.in");
            fin >> N;
            int id = 1; int a, b, c;
            for (int i = 0; i < N; i++) {
                fin >> a >> b >> c;
                cows.push_back({a, id, c});
                cows.push_back({b, -id, c}); id++;
            }
            sort(cows.begin(), cows.end());
        }

        void main() {
            prepData();
            ofstream fout ("blist.out");
            int currB = 0;
            for (auto i: cows) {
                if (i[1] < 0) currB -= i[2];
                else currB += i[2];
                res = max(res, currB);
            }

            fout << res << endl;
        }
};

int main() {
    Solution s;
    s.main();
}

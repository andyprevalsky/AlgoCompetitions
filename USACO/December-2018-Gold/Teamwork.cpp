#include <fstream>
#include <vector>
using namespace std;

class Solution {
    private:
        int N, K;
        vector<int> cows;
    public:
        void prepData() {
            ifstream fin ("teamwork.in");
            fin >> N >> K; int a;
            for (int i = 0; i < N; i++) {
                fin >> a;
                cows.push_back(a);
            }
        }

        void main() {
            prepData();
            ofstream fout ("teamwork.out");
        }
};

int main() {
    Solution s;
    s.main();
}
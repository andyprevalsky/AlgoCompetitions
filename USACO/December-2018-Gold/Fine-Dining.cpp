#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

# define INF 2000000000;

class Solution {
    private:
        int N, M, K;
        int haybales[50001] = {};
        vector<vector<int>> edges[50001];
        int dp[50001] = {};
        int memo[5001] = {};
        int memoS[5001] = {};
    public:
        void prepData() {
            ifstream fin ("dining.in");
            fin >> N >> M >> K;
            int a, b, c;
            for (int i = 0; i < M; i++) {
                fin >> a >> b >> c;
                edges[a].push_back({b, c});
                edges[b].push_back({a, c});
            }

            for (int i = 0; i < K; i++) {
                fin >> a >> b;
                haybales[a] = max(haybales[a], b);
            }
            memset(dp, -1, sizeof(dp));
        }


        vector<int> dfsN(int root) {
            if (root == N) return {0, 0};
            if (memo[root] == 1) return {2000000000, 2000000000};
            memo[root] = 1;
            //if(dp[root] != -1) return dp[root];
            int sPath = INF; int h = 0;
            for (auto i: edges[root]) {
                vector<int> res = dfsN(i[0]); h = max(haybales[root], res[1]);
                sPath = min(sPath, res[0] - h + i[1]);
            }
            dp[root] = sPath;
            return sPath;
        }
        
        void dfsNN(int root) {
            if (memoS[root] == 1) return;
            memoS[root] = 1;
            int sPath = INF;
            for (auto i: edges[root]) {
                sPath = min(sPath, i[1]+dp[i[0]]);
            }
            dp[root] = sPath;
            for (auto i: edges[root]) {
                dfsNN(i[0]);
            }
        }

        // vector<int> dfsH() { // [0] is val of shortest path, //[1] is largest haybales ssen
        //     return {};
        // }

        void main() {
            prepData();
            ofstream fout ("dining.out");
            dp[N] = 0; memoS[N] = 1;
            dfsN(1);
            for (int i = 1; i < N; i++) cout << dp[i] << endl;
            dfsNN(1);
            cout << " ---- " << endl;
            for (int i = 1; i < N; i++) cout << dp[i] << endl;
        }
};

int main() {
    Solution s;
    s.main();
}
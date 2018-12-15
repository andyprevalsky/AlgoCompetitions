#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
    private:
        int N, K;
        vector<vector<int>> grid;
        int memo[100][10];
    public:
        void prepData() {
            ifstream fin ("mooyomooyo.in");
            fin >> N >> K;
            string a;
            for (int i = 0; i < N; i++) {
                vector<int> row;
                fin >> a;
                for (auto j: a) {
                    row.push_back(int(j)-'0');
                }
                grid.push_back(row);
            }
        }

        void settle() {
            vector<vector<int>> nGrid;
            for (int j = 0; j < 10; j++) {
                vector<int> col;
                for (int i = grid.size()-1; i >= 0; i--) {
                    if (grid[i][j] != -1) col.push_back(grid[i][j]);
                }
                while (col.size() < grid.size()) col.push_back(0);
                nGrid.push_back(col);
            }

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < 10; j++) {
                    grid[i][j] = nGrid[j][N-i-1];
                }
            }
        }

        void outGrid() {
            return;
            for (auto i: grid) {
                for (auto j: i) {
                    cout << j;
                }
                cout << endl;
            }
            cout << endl << endl;
        }
 
        int dfsCount(int p1, int p2, int s) {
            if (p1 < 0 || p2 < 0 || p1 >= N || p2 >= 10) return 0;
            if (grid[p1][p2] != s) return 0;
            if (memo[p1][p2] == 1) return 0;
            memo[p1][p2] = 1;
            vector<vector<int>> changes = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            int count = 1;
            for (auto i: changes) {
                count += dfsCount(p1+i[0], p2+i[1], grid[p1][p2]);
            }
            return count;
        }

        void markDead(int p1, int p2, int s) {
            if (p1 < 0 || p2 < 0 || p1 >= N || p2 >= 10) return;
            int orig = grid[p1][p2];
            if (grid[p1][p2] == s) grid[p1][p2] = -1;
            else return;
            vector<vector<int>> changes = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto i: changes) {
                markDead(p1+i[0], p2+i[1], orig);
            }
        }
 
        void main() {
            prepData();
            ofstream fout ("mooyomooyo.out");
            bool set = false;
            while (1) {
                set = false;
                outGrid();
                memset(memo, 0, sizeof(memo));
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (grid[i][j] != 0 && grid[i][j] != -1 && dfsCount(i, j, grid[i][j]) >= K) { markDead(i, j, grid[i][j]); set = true; }
                    }
                }
                cout << " --- *  ---- " << endl;
                outGrid();
                if (set == false) break;
                else settle();
                cout << " --- |  -- " << endl;
                outGrid();
                cout << " ---- E --- " << endl;
            }

            for (auto i: grid) {
                for (auto j: i) {
                    fout << j;
                }
                fout << endl;
            }
        }
};

int main() {
    Solution s;
    s.main();
}
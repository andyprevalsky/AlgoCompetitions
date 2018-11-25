#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
private:
    int total = 0;

    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
    };
    unordered_set<vector<int>, VectorHash> memo;
    unordered_map<int, vector<vector<int>>> rows;
    unordered_map<int, vector<vector<int>>> cols;
public:
    int dfs(vector<int>& stone) {
        if (memo.find(stone) != memo.end()) return 0;
        memo.insert(stone);
        int count = 1;
        for (auto i: rows[stone[0]]) {
            count += dfs(i);
        }
        for (auto j: cols[stone[1]]) {
            count += dfs(j);
        }
        return count;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for (auto i: stones) {
            rows[i[0]].push_back(i);
            cols[i[1]].push_back(i);
        }
        for (auto i: stones) {
            int ret = dfs(i)-1;
            if (ret > 0) total += ret;
        }
        return total;
    }
};
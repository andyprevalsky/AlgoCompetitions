#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> prefixes;
    int total = 0;
public:
    int binSearch(int power, int i) {
        int l = 0;
        int r = i;
        int mid = (l+r)/2;
        if (r == 0) return 0;
        while (l < r-1) {
            if (r == 0) return 0;
            if (l == r) break;
            mid = (l+r)/2;
            if (prefixes[mid][0] > power) r = mid;
            if (prefixes[mid][0] < power) l = mid;
            else return prefixes[mid][1];
        }
        if (l < 0 || r < 0 || mid < 0) return 0;
        if (prefixes[r][0] < power) return prefixes[r][1];
        if (prefixes[mid][0] < power) return prefixes[mid][1];
        if (prefixes[l][0] < power) prefixes[l][1];
        return 0;
    }


    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int points = 0;
        int reqPow = 0;
        for (auto i: tokens) {
            points += 1;
            reqPow += i;
            prefixes.push_back({reqPow, points});
        }
        int power = 0;
        for (int i = tokens.size()-1; i >= 0; i--) {
            power += tokens[i];
            int res = binSearch(power, i);
            if (res > total) total = res;
        }
        return total;
    }
};

int main() {
    Solution s;
    vector<int> token = {100,200};
    cout << s.bagOfTokensScore(token, 150);
}

#include <map>
#include <vector>
using namespace std;
class Solution {
    private:
        map<int, int> nums;
        int total = 0;
        vector<int> b;
    public:
        int minIncrementForUnique(vector<int>& A) {
            for (int i = 0; i < A.size(); i++) {
                nums[A[i]]++;
            }
            while (!nums.empty()) {
                auto i = nums.begin();
                total += (i->second-1)*(i->second)/2;
                for (int j = 1; j < i->second; j++) {
                    nums[i->first+j]++;
                }
                nums.erase(i->first);
            }
            return total;
        }
};
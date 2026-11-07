class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> first, cnt;
        int degree = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (!first.count(x)) first[x] = i;
            cnt[x]++;

            int len = i - first[x] + 1;
            if (cnt[x] > degree) {
                degree = cnt[x];
                ans = len;
            } else if (cnt[x] == degree) {
                ans = min(ans, len);
            }
        }
        return ans;
    }
};
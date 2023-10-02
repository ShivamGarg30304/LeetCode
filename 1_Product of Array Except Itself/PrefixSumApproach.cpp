// Using the extra space for the prefix and suffix array
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        vector<int> ans(n);
        ans[0] = suffix[1];
        ans[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        return ans;
    }
};



// Without using the extra space for the prefix and suffix instead using the ans vector

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int num = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = num;
            num *= nums[i];
        }
        for (auto x : ans) {
            cout << x << " " << endl;
        }
        num = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = num * ans[i];
            num = num * nums[i];
        }
        return ans;
    }
};

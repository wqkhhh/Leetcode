class Solution {
public:
    vector<int> budget;
    bool backtrack(vector<int>& nums,int index,int target)
    {
        if (index == nums.size())return true;
        for (int i = 0; i < budget.size(); i++)
        {
            if (nums[index] + budget[i] > target)continue;
            if (i<budget.size()-1&&budget[i] == budget[i + 1]) continue;
            budget[i] += nums[index];
            if (backtrack(nums, index + 1, target))
                return true;
            budget[i] -= nums[index];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        sort(nums.begin(), nums.end(), [&](int x, int y) {return x > y; });
        if (sum % k || nums[0] > sum / k) return false;
        budget.resize(k);
        return backtrack(nums, 0, sum / k);
    }
};

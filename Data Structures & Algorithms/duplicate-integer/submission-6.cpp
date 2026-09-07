class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set numsSet(nums.begin(), nums.end());
        return nums.size() != numsSet.size();
    }
};
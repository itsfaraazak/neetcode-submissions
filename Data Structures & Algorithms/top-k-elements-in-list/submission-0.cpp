class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for (std::pair<int, int> pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }

        std::vector<int> result;
        result.reserve(k);

        for (int i = buckets.size() - 1; result.size() < k; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, freq] : map) {
            bucket[freq].push_back(num);
        }
        vector<int> res;
        for (int i = bucket.size() - 1;; --i) {
            for (int num : bucket[i]) {
                res.push_back(num);
                --k;
                if (!k) {
                    return res;
                }
            }
        }
        return res;
    }
};

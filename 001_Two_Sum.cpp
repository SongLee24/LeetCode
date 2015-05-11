class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> m;  // 缓冲区
        unordered_multimap<int, int>::iterator it;
        vector<int> result;
        for(int i=0; i<nums.size(); ++i)
        {
            int another = target - nums[i];
            it = m.find(another);
            if(it == m.end())   // 没找到，加入缓冲区
            {
                m.insert(make_pair(nums[i], i+1));
            }
            else
            {
                result.push_back(it->second);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};
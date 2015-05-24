class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int count = 1;
        int pre = nums[0];
        vector<int>::iterator beg = nums.begin();
        for(++beg; beg!=nums.end(); ) {   // 从第二个开始
            if(*beg == pre)               // 重复，移除
                beg = nums.erase(beg);
            else                          // 不重复，更新pre
            {
                pre = *beg;
                ++beg;
            }
        }
        return nums.size();
    }
};
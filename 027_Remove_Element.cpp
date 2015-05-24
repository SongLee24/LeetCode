class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator beg = nums.begin();
        for( ; beg!=nums.end(); ) {
            if(*beg == val)
                beg = nums.erase(beg);
            else
                ++beg;
        }
        return nums.size();
    }
};
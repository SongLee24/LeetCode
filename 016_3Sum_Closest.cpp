class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());      // 排序

        int distance = INT_MAX;              // 记录距离
        int sum = nums[0]+nums[1]+nums[2];   // 记录和

        for(int i=0; i<nums.size()-2; ++i) { // 固定一个数字
            int l = i+1;                     // 头指针
            int r = nums.size()-1;           // 尾指针
            while(l < r) {
                // 如果距离更近，则更新
                if(abs(nums[l]+nums[r]+nums[i]-target) < distance) {
                    sum = nums[l]+nums[r]+nums[i];
                    distance = abs(nums[l]+nums[r]+nums[i]-target);
                }

                if(nums[l]+nums[r]+nums[i] == target)
                    return sum;
                else if(nums[l]+nums[r]+nums[i] < target)
                    ++l;
                else
                    --r;
            }
        }
        return sum;
    }
};
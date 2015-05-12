class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0) return 0; // 数组为空
    	int minlen = INT_MAX;
    	int sum = 0;
    	
    	int left = 0;          // 滑动窗口的左右边沿
    	int right = -1;
    	while(right < len)
    	{
    		while(sum < s && right < len)
    			sum += nums[++right];  // 向右延伸
    		if(sum >= s)
    		{
    			minlen = minlen < right-left+1 ? minlen : right-left+1;
    			sum -= nums[left++];
    		}
    	}
    	return minlen > len ? 0 : minlen;
    }
};
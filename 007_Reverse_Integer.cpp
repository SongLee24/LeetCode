class Solution {
public:
    int reverse(int x) {
    	uint64_t n = x>0 ? x:-x;
    	stack<int> s; // 存储每一位
    	while(n) {
    		s.push(n%10);
    		n = n/10;
    	}
    
    	uint64_t m10 = 1;
    	while(!s.empty()) {
    		n += m10 * s.top();
    		s.pop();
    		m10 *= 10;
    	}
    	
    	if(n > INT_MAX)  // 如果超出范围
    		return 0;
    	else
    		return x>0? n:-n;
    }
};
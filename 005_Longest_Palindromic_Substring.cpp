class Solution {
public:
    // 分别向左右扩展，返回扩展后的字符串
    string expand(string s, int left, int right) {
    	int len = s.size();
    	while (left>=0 && right<len && s[left] == s[right]) 
    	{
    		left--;
    		right++;
    	}
    	return s.substr(left+1, right-left-1);
    }
    
    string longestPalindrome(string s) {
    	int len = s.size();
    	if(len<=1) return s;
    
    	string longest;
    	for (int i=0; i<len-1; i++) 
    	{
    		string p1 = expand(s, i, i);  // 奇数
    		if (p1.size() > longest.size())
    			longest = p1;
    
    		string p2 = expand(s, i, i+1);  // 偶数
    		if (p2.size() > longest.size())
    			longest = p2;
    	}
    	return longest;
    }
};
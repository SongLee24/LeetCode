class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int maxlen = 0;
    	string buffer;
    	for(int i=0; i<s.size(); ++i)
    	{
    		int pos = buffer.find(s[i]);
    		if(pos >= 0)   // 重复
    		{
    		    // 更新最长长度
    			maxlen = maxlen > buffer.size()? maxlen : buffer.size();
    			// 删除从0到pos的所有字符
    			buffer.erase(buffer.begin(), buffer.begin()+pos+1);
    		}
    		buffer += s[i];
    	}
    	return maxlen > buffer.size() ? maxlen : buffer.size();
    }
};
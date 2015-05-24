/**
 *  朴素的字符串匹配算法
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        int index = -1;
        for(int i=0; i<=n-m; ++i) {
            if(needle.compare(haystack.substr(i, m)) == 0) {
                index = i;
                break;
            }
        }
        return index;
    }
};


/**
 *  KMP算法
 */
class Solution {
public:
    int* prefixFunction(string pattern)
    {
    	int len = pattern.size();
    	int k = 0;
    
    	int *pi = new int[len];
    	for(int i=0; i<len; i++)     // 初始化为0
    		pi[i] = 0;
    
    	for(int i=1; i<len; i++)
    	{
    		while (k>0 && pattern[k]!=pattern[i])
    			k = pi[k-1];
    
    		if (pattern[k]==pattern[i])
    			k = k+1;
    
    		pi[i] = k;
    	}
    
    	return pi;
    }
    
    int strStr(string haystack, string needle)
    {
    	if(needle == "")
    		return 0;
    
    	int n = haystack.size();
    	int m = needle.size();
    	int *pi = prefixFunction(needle);
    
    	int q=0;
    	for(int i=0; i<n; i++)
    	{
    		while (q>0 && needle[q]!=haystack[i])
    			q = pi[q-1];
    
    		if (needle[q]==haystack[i])
    			q = q+1;
    
    		if ( q == m )
    			return i - m + 1;
    	}
    	return -1;
    }
};
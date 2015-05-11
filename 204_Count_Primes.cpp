class Solution {
public:
    int countPrimes(int n) {
    	bool *Del = new bool[n]; // 标记是否被划去
    	Del[2] = false;
    
    	for(int i=3; i<n; ++i)
    		if(i%2 == 0)
    			Del[i] = true;  // 2的倍数全部划去
    		else
    			Del[i] = false;
    
    	for(int i=3; i<n; i+=2)
    		if(!Del[i])  // 之后第一个未被划去
    		{
    			if(i*i>n)  break;
    			for(int j=2; i*j<n; ++j)
    				Del[i*j] = true;
    		}
    
    	int count = 0;
    	for(int i=2; i<n; ++i)
    		if(!Del[i])
    			++count;
    
    	delete [] Del;
    	return count;
    }
};
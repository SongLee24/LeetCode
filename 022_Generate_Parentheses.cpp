class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string str;
    	generate(n, 0, 0, str);
    	return res;
    }
    
    void generate(int n, int i, int j, string str) {
    	if(i==n && j==n) // 递归终止条件
    		res.push_back(str);
    
    	if(i<n)          // 左括号没n个就可以添加
    		generate(n, i+1, j, str+'(');
    
    	if(j<n && i>j)   // 右括号，比左括号少的时候才可以添加
    		generate(n, i, j+1, str+')');
    }
};
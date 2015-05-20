class Solution {
    static string letter[10];
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
    	string str;
    	combine(digits, 0, str);
    	return res;
    }
    
    void combine(string &digits, int i, string str) {
    	if(i>=digits.size()) {   // 递归终止条件
    		res.push_back(str);
    		return;
    	}
    	string s = letter[digits[i]-'0'];
    	for(int j=0; j<s.size(); ++j)
    		combine(digits, i+1, str+s[j]);		
    }
};

string Solution::letter[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
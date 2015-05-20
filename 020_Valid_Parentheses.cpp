class Solution {
public:
    bool isValid(string s) {
    	stack<char> Stack;
    	for(int i=0; i<s.size(); ++i) {
    		if(Stack.empty())
    			Stack.push(s[i]);
    		else if((Stack.top()=='(' && s[i]==')') || (Stack.top()=='{' && s[i]=='}') || (Stack.top()=='[' && s[i]==']'))
    			Stack.pop();
    		else
    			Stack.push(s[i]);
    	}
    
    	if(Stack.empty())
    		return true;
    	else
    		return false;
    }
};
// 只能一对一进行映射

class Solution {
public:
    // s 和 t 具有相同的长度
    bool isIsomorphic(string s, string t) {
        map<char, char> m1;
        map<char, char> m2;
        bool flag = true;
        for(int i=0; i<s.size(); ++i)
        {
        	if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())
        	{
        		m1[s[i]] = t[i];
        		m2[t[i]] = s[i];
        	}
        	else if(m1.find(s[i]) != m1.end() && m2.find(t[i]) != m2.end())
        	{
        		if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i])
        		{
        			flag = false;
        			break;
        		}
        	}
        	else
        	{
        		flag = false;
        		break;
        	}
        }
        return flag;
    }
};
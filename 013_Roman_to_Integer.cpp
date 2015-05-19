class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m.insert(make_pair('I',1));
        m.insert(make_pair('V',5));
        m.insert(make_pair('X',10));
        m.insert(make_pair('L',50));
        m.insert(make_pair('C',100));
        m.insert(make_pair('D',500));
        m.insert(make_pair('M',1000));

        int res = 0;
        for(int i=0; i<s.size(); )
        {
            if(m[s[i]] < m[s[i+1]])  // 左减
            {
                res += m[s[i+1]]-m[s[i]];
                i+=2;
            }
            else
            {
                res += m[s[i]];
                ++i;
            }
        }
        return res;
    }
};
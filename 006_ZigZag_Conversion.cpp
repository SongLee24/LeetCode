class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        vector<string> v(numRows,"");  // 创建numRows个字符串
        int idx = 0;
        bool flag = true;
        for(int i=0; i<s.size(); ++i)
        {
            v[idx] += s[i];

            if(flag)
                ++idx;
            else
                --idx;

            if(idx == numRows-1)
                flag = false;
            if(idx == 0)
                flag = true;
        }

        // 输出
        string output = "";
        for(int i=0; i<numRows; ++i)
            output += v[i];
        return output;
    }
};
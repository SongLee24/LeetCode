bool cmp(string &s1, string &s2) {
    return s1.size() < s2.size();
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];

        // 按字符串长度从小到大排序
        sort(strs.begin(), strs.end(), cmp); 

        // 其他字符串都和第一个字符串比较
        for(int i=1; i<strs.size(); ++i) {   
            for(int j=0; j<strs[i].size(); ++j) {
                if(strs[i][j] != strs[0][j]) {
                    strs[0][j] = '\0';   // 标记公共前缀截止位置
                    break;
                }
            }
        }

        int pos = strs[0].find('\0');
        if(pos < 0)
            return strs[0];
        else
            return strs[0].substr(0,pos);
    }
};
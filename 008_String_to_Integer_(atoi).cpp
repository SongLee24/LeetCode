class Solution {
public:
    int myAtoi(string str) {
        int i=-1;
        bool positive = true;    // 标记正负
        while(str[++i]==' ') ;   // 跳过空字符
        if(str[i]=='-' || str[i]=='+') {
            positive = str[i]=='-'?false:true;
            ++i;
        }

        if(!isdigit(str[i]))     // 若第一个字符是非数字字符
            return 0;

        uint64_t sum = 0;
        uint64_t m10 = 1;
        for(int j=str.size()-1; j>=i; --j)
        {
            if(!isdigit(str[j]))  // 若中间出现非数字字符
            {
                sum = 0;
                m10 = 1;
                continue;
            }
            sum += (str[j]-'0') * m10;
            m10 *= 10;
            if(sum > INT_MAX)
                break;
        }

        if(sum > INT_MAX && positive)
            return INT_MAX;
        else if(sum > INT_MAX && !positive)
            return INT_MIN;
        else
            return positive?sum:-sum;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = true;                // 表示结果的正负
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            positive = false;

        int64_t absDividend = abs((int64_t)dividend);
        int64_t absDivisor = abs((int64_t)divisor);
        int64_t result = 0;

        while(absDivisor <= absDividend) {
            int64_t tmp = absDivisor;
            int64_t count = 1;
            while((tmp<<1) <= absDividend) {
                tmp = tmp<<1;                // divisor*2^n
                count = count<<1;            // count = 2^n
            }
            result += count;                 // 系数累加
            absDividend -= tmp;
        }

        if(positive && result >= INT_MAX)
            return INT_MAX;

        return positive ? result:-result;
    }
};
class Solution {
    static const string THOUS[4];
    static const string HUNDS[10];
    static const string TENS[10];
    static const string ONES[10];
public:
    string intToRoman(int num) {
    	string res;
    	res += THOUS[num/1000];
    	res += HUNDS[num/100%10];
    	res += TENS[num/10%10];
    	res += ONES[num%10];
    	return res;
    }
};

const string Solution::THOUS[]  = {"","M","MM","MMM"};
const string Solution::HUNDS[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::TENS[]   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::ONES[]   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
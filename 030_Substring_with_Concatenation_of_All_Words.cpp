class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size();
        int len = words.size()*word_len;
        int n = s.size();
        unordered_map<string, int> m;              // <单词,出现的次数>
        for(int i=0; i<words.size(); ++i)
        {
            if(m.count(words[i]) == 0)             // 注意count方法的使用
                m.insert(make_pair(words[i], 1));
            else
                ++m[words[i]];
        }

        vector<int> index;
        for(int i=0; i<word_len; ++i)
        {
            unordered_map<string, int> win;
            int left = i;                           // 窗口左边沿
            int count = 0;                          // 窗口中的单词数目
            for(int right=i; right<=n-word_len; right+=word_len)
            {
                string word = s.substr(right, word_len);
                if(m.find(word) != m.end())         // 在集合中
                {
                    if(win.find(word) == win.end()) // 不在窗口中，即添加
                        win[word] = 1;
                    else
                        ++win[word];                // 在窗口中

                    if(win[word] <= m[word])        // 还没出现相应的次数
                        ++count;
                    else  
                    {
                        // 单词在集合中，但是它已经在窗口中出现了相应的次数，不应该加入窗口
                        // 此时把窗口起始位置想左移动到，该单词第一次出现的位置的下一个单词位置
                        for(int k=left;  ; k+=word_len)
                        {
                            string temp = s.substr(k, word_len);
                            --win[temp];
                            if(temp == word)
                            {
                                left = k + word_len;
                                break;
                            }
                            --count;
                        }
                    }

                    if(count == words.size())
                        index.push_back(left);
                }
                else                                // 不在集合中，从窗口右侧重新开始
                {
                    left = right + word_len;
                    win.clear();
                    count = 0;
                }
            }
        }

        return index;
    }
};
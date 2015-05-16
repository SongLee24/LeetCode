/*********Trie树的节点结构*********/
class TrieNode {
public:
    bool iskey;   // 标记该节点是否代表关键字
    TrieNode *children[26]; // 各个子节点
    TrieNode() {
        iskey = false;
        for(int i=0; i<26; ++i)
            children[i] = NULL;
    }
};

/***************词典***************/
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // 插入一个单词
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); ++i)
        {
            if(node->children[word[i]-'a'] == NULL)
            {
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->iskey = true;
    }

    // 检索单词，可以包含'.'
    bool search(string word) {
        return searchWord(word, root, 0);
    }

private:
    TrieNode* root;
    
    bool searchWord(string &word, TrieNode* node, int p) {
        if(p == word.size())
            return node->iskey;
        
        if(word[p] == '.') {    // 匹配任何字符
            for(int i=0; i<26; ++i)
                if(node->children[i] && searchWord(word, node->children[i], p+1))
                    return true;
            return false;
        }
        else
            return node->children[word[p]-'a'] && searchWord(word, node->children[word[p]-'a'], p+1);
    }
};
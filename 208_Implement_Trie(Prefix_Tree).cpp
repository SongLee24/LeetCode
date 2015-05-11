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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // 插入一个单词到trie树中
    void insert(string s) {
        TrieNode* node = root;
        for(int i=0; i<s.size(); ++i)
        {
            if(node->children[s[i]-'a'] == NULL)
            {
                node->children[s[i]-'a'] = new TrieNode();
            }
            node = node->children[s[i]-'a'];
        }
        node->iskey = true;
    }

    // 搜索关键字key是否在trie树中
    bool search(string key) {
        TrieNode* node = root;
        for(int i=0; i<key.size(); ++i)
            if(node!=NULL)
                node = node->children[key[i]-'a'];
            else
                break;

        if(node == NULL)
            return false;
        else
            return node->iskey;
    }

    // 判断trie树中是否有以prefix为前缀的单词
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i<prefix.size(); ++i)
            if(node!=NULL)
                node = node->children[prefix[i]-'a'];
            else
                break;

        if(node == NULL)
            return false;
        else
            return true;
    }

private:
    TrieNode* root;
};
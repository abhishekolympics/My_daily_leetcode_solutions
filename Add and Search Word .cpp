class TrieNode {
    public:
    TrieNode * children[26];
    bool isWord;
    TrieNode()
    {
        isWord=false;
        for(auto &a: children) a=nullptr;
    }
};
class WordDictionary {
    TrieNode* root;      
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *p =root;
        for(auto &a:word)
        {
            int i=a-'a';
            if(!p->children[i]) p->children[i] = new TrieNode();
            p=p->children[i];
        }
        p->isWord=true;
    }
    bool searchUtil(TrieNode* root, string word)
    {
        TrieNode *crawler =root;

        for(int i=0;i< word.length();i++)
        {
            char ch = word[i];

            if(ch == '.')
            {
                for(int j=0; j<26; j++)
                {
                    if (crawler ->children[j] !=NULL)
                    {
                        if(searchUtil(crawler->children[j], word.substr(i+1)))
                            return true;
                    }
                }
                return false;
            }
            else if(crawler->children[ch-'a']==NULL)
                return false;
            crawler=crawler->children[ch-'a'];
        }
        return (crawler != NULL && crawler->isWord);
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//Go to Rough Copy Index
class TrieNode{
    public:
    bool isEndOfWord;
    TrieNode* children[26];
    TrieNode()
    {
        isEndOfWord=false;
        memset(children,NULL,sizeof(children));
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    void insert(string word) {
        TrieNode* p=root;
        for(char &a:word)
        {
            int i=a-'a';
            if(p->children[i]==NULL)
            {
                p->children[i]= new TrieNode;
            }
            p=p->children[i];
        }   
        p->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* q=root;
        for(int i=0;i<word.size();i++)
        {
            if(q->children[word[i]-'a']!=NULL)
            {
                q=q->children[word[i]-'a'];
            }
            else
            {
                return false;
            }
        }
        if(q->isEndOfWord)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* q=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(q->children[prefix[i]-'a']!=NULL)
            {
                q=q->children[prefix[i]-'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];
        bool isEndOfWord;
    Trie() {
       isEndOfWord = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr; 
        
    }
    
    /** Inserts a word into the trie. */
    //O(m) O(m)
    void insert(string word) {
       Trie* curr = this;
        for(auto c : word)
        {
            if((curr->children[c-'a']) == nullptr)
                curr->children[c-'a'] = new Trie;
            
            curr = curr->children[c-'a'];
        }
        curr->isEndOfWord = true; 
        
    }
    
    /** Returns if the word is in the trie. */
    //O(m)
    bool search(string word) {
        
        Trie* curr = this;
        for(auto c : word)
        {
            curr = curr->children[c-'a'];
            if(curr == nullptr)
                return false;
        }
        if(curr->isEndOfWord)
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    //O(m)
    bool startsWith(string prefix) {
        Trie*curr = this;
        for(auto c : prefix)
        {
            curr = curr->children[c-'a'];
            if(curr == nullptr)
                return false;
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

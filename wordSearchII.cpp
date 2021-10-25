//O(M(4⋅3 L−1))
    class Trie{
    public:
    Trie* children[26];
    bool endOfWord;
    
    Trie():endOfWord(false){
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
     }
        ~Trie()
        {
            for(int i = 0; i < 26; i++)
                if(children[i])
                    delete children[i];
        }
        void insert(string word)
        {
            Trie* curr = this;
            for(char c : word)
            {
                if(curr->children[c - 'a'] == nullptr)
                    curr->children[c-'a'] = new Trie;
                curr = curr->children[c-'a'];
            }
            curr->endOfWord = true;
        }
    };
    
class Solution {

    void dfs(vector<vector<char>>& board, int i, int j, unordered_set<string>& result, Trie *trie, string s){
        
        char c = board[i][j];
        
        if(c == '$')
            return;
        
        board[i][j] = '$';
        
        Trie* t = trie->children[c-'a'];
        if(t)
        {
            string ss = s + c;
            if(t->endOfWord)
                result.insert(ss);
            if(i < board.size() - 1)
                dfs(board, i + 1, j, result, t, ss);
            if(j < board[0].size() - 1)
                dfs(board, i, j + 1, result, t, ss);
            if(i > 0)
                dfs(board, i - 1, j, result, t, ss);
            if(j > 0)
                dfs(board, i, j - 1, result, t, ss);
        }
        board[i][j] = c;
    }
    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if(words.size() == 0)
            return {};
        
        Trie trie;
        
        for(string w: words)
            trie.insert(w);
        
        unordered_set<string> result;
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, result, &trie, "");
            }
        }
        vector<string> result_v(result.begin(), result.end());
        return result_v;
    }
};

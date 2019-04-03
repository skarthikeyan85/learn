// boggle
/*
Boggle (Find all possible words in a board of characters) | Set 1

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ
Boggle

We strongly recommend that you click here and practice it, before moving on to the solution.

The idea is to consider every character as a starting character and find all words starting with it. All words starting from a character can be found using Depth First Traversal. We do depth first traversal starting from every cell. We keep track of visited cells to make sure that a cell is considered only once in a word.
*/

class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)
               cur->children[index]=new TrieNode();
            cur=cur->children[index];
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root=trie->getRoot();
        set<string> result_set;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                findWords(board, x, y, root, "", result_set);

        vector<string> result;
        for(auto it:result_set)    result.push_back(it);
        return result;
    }
private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;

        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a'];
            if(root->is_end) result.insert(word);
            char c=board[x][y];
            board[x][y]=' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);
            board[x][y]=c;
        }
    }
};


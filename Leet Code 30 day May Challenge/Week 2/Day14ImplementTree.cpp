Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

/* Approach 1: 724ms   */
class Trie {
public:
    /** Initialize your data structure here. */
    
    vector<string> sen;
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        sen.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto pos=find(sen.begin(),sen.end(),word);
        return pos !=sen.end() ;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //return sen.find_first_of(prefix)==0;
        if(sen.size()==0) return false;
        // else if(sen[0].length() <prefix.length()) return false;
        // return sen[0].find_first_of(prefix)==0;
        for(int i=0;i<sen.size();i++)
        {
            if(sen[i].length() >= prefix.length() && sen[i].find(prefix)==0)return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/* Approach 2 : runtime 92ms*/
class Trie {
public:
    Trie* next[26];
    bool isWord=false;
    /** Initialize your data structure here. */
    Trie() {
        memset(next, 0, sizeof next);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* t=this;
        for(char c: word){
            int i=c-'a';
            if(t->next[i]==0) t->next[i]=new Trie();
            t=t->next[i];
        }
        t->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* t=this;
        for(char c: word){
            int i=c-'a';
            if(t->next[i]==0) return false;
            t=t->next[i];
        }
        return t->isWord;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* t=this;
        for(char c: prefix){
            int i=c-'a';
            if(t->next[i]==0) return false;
            t=t->next[i];
        }
        return true;        
    }
};

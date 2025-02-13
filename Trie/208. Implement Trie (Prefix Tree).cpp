struct node {
    char ch;
    bool isEnd;
    vector<node*> child;

    node() {
        this->ch = '$';
        this->isEnd = false;
        child.resize(26, NULL);
    }
};

class Trie {
public:
    node* root;

    Trie() {
        root = new node();    
    }
    
    void insert(string word) {
        node* parser = root;
        for(auto& it: word) {
            int index = it - 'a';
            if(!parser->child[index]) {
                parser->child[index] = new node();
            }
            parser = parser->child[index];
        }
        parser->isEnd = true;
    }
    
    bool search(string word) {
        node* parser = root;
        for(auto& it: word) {
            int index = it - 'a';
            if(!parser->child[index]) {
                return false;
            }
            parser = parser->child[index];
        }
        return parser->isEnd;
    }
    
    bool startsWith(string prefix) {
        node* parser = root;
        string curPrefix = "";
        for(auto& it: prefix) {
            int index = it - 'a';
            if(!parser->child[index]) {
                return false;
            }
            curPrefix += it;
            parser = parser->child[index];
        }
        return curPrefix == prefix;
		// or
	// return true
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
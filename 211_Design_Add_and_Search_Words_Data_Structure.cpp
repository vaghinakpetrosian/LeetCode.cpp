class Node {
    Node* childs[26];
    bool end{false};
public:
    Node()
    {
        for (int i = 0; i < 26; ++i)
            childs[i] = nullptr;
    }
    Node* get(char c) const 
    {
        return childs[c - 'a'];
    }
    void put(char c) 
    {
        childs[c - 'a'] = new Node();
    }
    bool isEnd()
    {
        return end;
    }
    void set()
    {
        end = true;
    }
};


class WordDictionary {
    Node* root;
    bool searchHelper(Node* node, const string& word, int index) 
    {
        if (!node) 
            return false;
        if (index == word.size()) 
            return node->isEnd();
        char c = word[index];
        if (c == '.') 
        {
            for (int i = 0; i < 26; ++i) 
            {
                if (searchHelper(node->get('a' + i), word, index + 1))
                    return true;
            }
            return false;
        } 
        else 
        {
            return searchHelper(node->get(c), word, index + 1);
        }
    }
public:
    WordDictionary() 
    {
        root = new Node();
    }
    void addWord(const string& word) 
    {
        Node* tmp = root;
        for (char c : word) {
            if (!tmp->get(c)) tmp->put(c);
            tmp = tmp->get(c);
        }
        tmp->set();
    }
    bool search(const string& word)
    {
        return searchHelper(root, word, 0);
    }
};
    

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

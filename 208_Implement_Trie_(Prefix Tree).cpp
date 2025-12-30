class Node
{
        bool end = false;
        Node* childs[26];
    public:
        Node(bool b = false)
        {
            end = b;
            for(int i = 0; i < 26; ++i)
            {
                childs[i] = nullptr;
            }
        }
        Node* get(char c) const
        {
            return childs[c - 'a'];
        }
        void put(char c)
        {
            childs[c - 'a'] = new Node();
        }
        void set()
        {
            end = true;
        }
        bool isEnd() const
        {
            return end;
        }
};
class Trie
{
    Node* root;
public:
    Trie() 
    {
        root = new Node();
    }
    
    void insert(const string& word) 
    {
        Node* tmp = root;
        int n = word.size();
        for(int i = 0; i < n; ++i)
        {
            if(!tmp->get(word[i]))
            {
                tmp->put(word[i]);
            }
            tmp = tmp->get(word[i]);
        }
        tmp->set();
    }
    
    bool search(const string& word) 
    {
        int n = word.size();
        Node* tmp = root;
        for(int i = 0; i < n; ++i)
        {
            if(!(tmp = tmp->get(word[i])))
            {
                return false;
            }
        }    
        if(tmp->isEnd())
            return true;
        return false;
    }
    
    bool startsWith(const string& prefix) 
    {
        int n = prefix.size();
        Node* tmp = root;
        for(int i = 0; i < n; ++i)
        {
            if(!(tmp = tmp->get(prefix[i])))
            {
                return false;
            }
        }    
        return true;
    }
};

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */

// class Trie {
//     std::unique_ptr<Node> root;
// public:
//     Trie() : root(std::make_unique<Node>()) {}

//     void insert(const std::string& word) {
//         Node* tmp = root.get();
//         for (char c : word) {
//             if (!tmp->get(c))
//                 tmp->put(c);
//             tmp = tmp->get(c);
//         }
//         tmp->set();
//     }

//     bool search(const std::string& word) const {
//         const Node* tmp = root.get();
//         for (char c : word)
//             if (!(tmp = tmp->get(c))) return false;
//         return tmp->isEnd();
//     }

//     bool startsWith(const std::string& prefix) const {
//         const Node* tmp = root.get();
//         for (char c : prefix)
//             if (!(tmp = tmp->get(c))) return false;
//         return true;
//     }
// };

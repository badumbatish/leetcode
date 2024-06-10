#include <array>
#include <memory>
#include <string>

class Node {
public:
    std::array<std::unique_ptr<Node>, 26> children;
    bool flag = false;

    Node() = default; // Default constructor
};

class Trie {
public:
    std::unique_ptr<Node> root;

    Trie() : root(std::make_unique<Node>()) {}

    void insert(const std::string& word) {
        Node* stem = get_stem(word, true);
        stem->flag = true;
    }

    bool search(const std::string& word)  {
        Node* stem = get_stem(word);
        return stem != nullptr && stem->flag;
    }

    bool startsWith(const std::string& prefix)  {
        Node* stem = get_stem(prefix);
        return stem != nullptr;
    }

    Node* get_stem(const std::string& word, bool auto_create = false) {
        Node* current = root.get();
        for (char c : word) {
            auto& child = current->children[c - 'a'];
            if (!child && auto_create == false) return nullptr;
            if (!child && auto_create == true) 
                child = std::make_unique<Node>();
            
            current = child.get();
        }
        return current;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
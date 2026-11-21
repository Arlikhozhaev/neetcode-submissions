class PrefixTree {
private:
    struct TrieNode {
        array<unique_ptr<TrieNode>, 26> children{};
        bool isEndOfWord = false;
    };

    unique_ptr<TrieNode> root;

    const TrieNode* findNode(string_view prefix) const noexcept {
        const TrieNode* curr = root.get();
        for (char c : prefix) {
            const int idx = c - 'a';
            if (!curr->children[idx]) {
                return nullptr;
            }
            curr = curr->children[idx].get();
        }
        return curr;
    }

public:
    PrefixTree() : root(make_unique<TrieNode>()) {}

    void insert(string word) {
        TrieNode* curr = root.get();
        for (char c : word) {
            const int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = make_unique<TrieNode>();
            }
            curr = curr->children[idx].get();
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) const noexcept {
        const TrieNode* node = findNode(word);
        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(string prefix) const noexcept {
        return findNode(prefix) != nullptr;
    }
};

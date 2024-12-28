#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct TrieNode {
    bool terminal;
    map<char, TrieNode*> child;
    TrieNode(){
        terminal = false;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* head = root;
        for(int i = 0; i < word.size(); i++){
            if(head->child[word[i]] == 0) {
                head->child[word[i]] = new TrieNode();
            }
            head = head->child[word[i]];
        }
        head->terminal = true;
    }

    bool search(string word, bool prefix=false){
        TrieNode* head = root;
        for(int i = 0; i < word.size(); i++){
            head = head->child[word[i]];
            if(head == 0) return false;
        }
        if(prefix) return true;
        return head->terminal;
    }

    bool startsWith(string prefix){
        return search(prefix, true);
    }
};

int main() {
    Trie* trie = new Trie();
    auto start = high_resolution_clock::now();

    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}
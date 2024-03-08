#include <bits/stdc++.h>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    os << "[";
    size_t last = vector.size() - 1;
    for (size_t i = 0; i < vector.size(); i++) {
        os << vector[i];
        if (i != last) os << ", ";
    }
    os << "]";
    return os;
}

// Brute force solution for basic style
// class Solution {
// public:
//     string reverseWords(string word) {
//         string reverse = "";
//         int length = 0;
//         for(int i = word.size() - 1; i > -1; i--) {
//             if(word[i] == ' ') continue;
//             length++;
//             if(i == 0 || word[i-1] == ' '){
//                 reverse.append(word.substr(i, length) + " ");
//                 length = 0;
//             }
//         }
//         reverse.erase(reverse.size() - 1);
//         return reverse;
//     }
// };

class Solution {
public:
    // Solution using stringstream class to handle the process
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string read;
        while(ss >> read) {
            words.push_back(read);
        }

        string reverse = "";
        for(int i = words.size() - 1; i >= 0; --i){
            if(i != words.size() - 1) reverse += ' ';
            reverse += words[i];
        }
        
        return reverse;
    }
};

int main() {    
    Solution* sol = new Solution();
    cout << sol->reverseWords("the sky is blue") << endl;
    cout << sol->reverseWords("  hello world  ") << endl;
    cout << sol->reverseWords("a good   example") << endl;
    return 0;
}
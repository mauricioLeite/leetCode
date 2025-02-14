#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define pii pair<int,int>
#define ll long long

// Overload ostream out operator to print vector n-dimensional
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    os << "[";
    size_t last = vector.size() - 1;
    for(size_t i = 0; i < vector.size(); i++) {
        os << vector[i];
        if(i != last) os << ", ";
    }
    cout << "]";
    return os;
}

static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}(); 

class ProductOfNumbers {
public:
    int pos;
    vector<int> prefix;
    ProductOfNumbers() {
        pos = 1;
        prefix = {1};
    }
    
    void add(int num) {
        if(num == 0) {
            pos = 1;
            prefix = {1};
        }
        else {
            prefix.push_back(prefix[pos-1]*num);
            pos++;
        }
    }
    
    int getProduct(int k) {
        if(pos <= k) return 0;
        cout << prefix << endl;
        return prefix[pos-1] / prefix[pos-1-k];
    }
};

int main() {
    ProductOfNumbers* sol = new ProductOfNumbers();
    auto start = high_resolution_clock::now();

    sol->add(3);
    cout << sol->getProduct(1) << endl;
    sol->add(0);
    sol->add(2);
    sol->add(5);
    sol->add(4);
    cout << sol->getProduct(2) << endl;
    cout << sol->getProduct(3) << endl;
    cout << sol->getProduct(4) << endl;
    sol->add(8);
    cout << sol->getProduct(2) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Overload ostream out operator to print vector n-dimensional
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

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class NumberContainers {
public:
    unordered_map<int, int> cont;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> idxs;
    NumberContainers() {
        cont.reserve(100000);
    }
    
    void change(int index, int number) {
        cont[index] = number;
        idxs[number].push(index);
    }
    
    int find(int number) {
        if(idxs.count(number) != 0) {
            while(!idxs[number].empty()){
                int pos = idxs[number].top();
                if(cont[pos] == number) return pos;
                idxs[number].pop();
            }
        }

        return -1;
    }
};

int main() {
    NumberContainers* sol = new NumberContainers();
    auto start = high_resolution_clock::now();

    sol->change(1, 10);
    cout << sol->find(10) << endl;
    sol->change(1, 20);
    cout << sol->find(10) << endl;
    cout << sol->find(20) << endl;
    cout << sol->find(30) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}
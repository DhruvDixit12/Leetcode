#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
private:
    vector<long long> prefix; 
public:
    ProductOfNumbers() {
        prefix.push_back(1); 
    }
    
    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            long long last = prefix.back();
            prefix.push_back(last * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefix.size()) return 0;
        int n = prefix.size();
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

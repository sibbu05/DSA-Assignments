#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &a, int index, int element) {
    if (index < 0 || index > a.size()) return;
    a.insert(a.begin() + index, element);
}

void remove(vector<int> &a, int index) {
    if (index < 0 || index >= a.size()) return;
    a.erase(a.begin() + index);
}

int findSize(vector<int> &a) {
    return a.size();
}

bool isEmpty(const vector<int> &a) {
    return a.empty();
}

void rotate(vector<int> &a, int k) {
    k = k % a.size();
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}

void reverse(vector<int> &a) {
    reverse(a.begin(), a.end());
}

void append(vector<int> &a, int element) {
    a.push_back(element);
}

void prepend(vector<int> &a, int element) {
    a.insert(a.begin(), element);
}

void merge(vector<int> &a, vector<int> &b) {
    a.insert(a.end(), b.begin(), b.end());
}

int findMiddle(const vector<int> &a) {
    return a[a.size() / 2];
}

int indexOf(vector<int> &a, int element) {
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == element) return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    return 0;
}

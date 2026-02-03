#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<iomanip>
using namespace std;

struct treenode {
    double num;
    int original_index;
    treenode* left;
    treenode* right;
    treenode(double p, int idx = -1):num(p),original_index(idx),left(nullptr),right(nullptr){}
};

struct compare {
    bool operator()(treenode* a, treenode* b){
        return a->num > b->num;
    }
};

unordered_map<int,long long> ans;

void find(treenode* cur,long long num=1) {
    if (!cur->left && !cur->right) {
        ans[cur->original_index]=num;
        return;
    }
    if (cur->left) find(cur->left,10*num+1);
    if (cur->right) find(cur->right,10*num);
}

int findnum(long long cur) {
    int ans=0;
    while (cur) {
        ans++;
        cur/=10;
    }
    return ans-1;
}

int main() {
    int number;
    cin >> number;
    vector<double>key(number);
    priority_queue<treenode*, vector<treenode*>, compare> minHeap;

    for (int i = 0; i < number; i++) {
        cin>>key[i];
        treenode* cur = new treenode(key[i], i);
        minHeap.push(cur);
    }

    while (minHeap.size() > 1) {
        treenode* first = minHeap.top(); minHeap.pop();
        treenode* second = minHeap.top(); minHeap.pop();
        treenode* newNode = new treenode(first->num + second->num);
        newNode->left = first;
        newNode->right = second;
        minHeap.push(newNode);
    }

    find(minHeap.top());

    double n=0;
    double H=0;

    for (int i = 0; i < number; i++) {
        if (key[i] > 0) {
            H -= key[i] * log2(key[i]);
        }
    }

    for (int i = 0; i < number; i++) {
        if (ans.find(i) != ans.end()) {
            int now=findnum(ans[i]);
            n += key[i] * now;

            string code_str = to_string(ans[i]);
            if (code_str.length() > 1) {
                code_str = code_str.substr(1);
            } else {
                code_str = "0";
            }
            cout << key[i] << "'s code is: " << code_str << endl;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << "n(g*)=" << n << endl;
    cout << "H(x)=" << H << endl;

    return 0;
}

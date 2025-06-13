#include <bits/stdc++.h>
using namespace std;

void generateBinary(int ones, int zeros, int n, string op, vector<string>& v) {
    if (n == 0) {
        v.push_back(op);
        return;
    }
    generateBinary(ones + 1, zeros, n - 1, op + "1", v);
    if (zeros < ones) {
        generateBinary(ones, zeros + 1, n - 1, op + "0", v);
    }
}

vector<string> NBitBinary(int n) {
    vector<string> ans;
    generateBinary(0, 0, n, "", ans);
    sort(ans.rbegin(), ans.rend());
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> result = NBitBinary(n);
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}

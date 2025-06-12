#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op, vector<string>& ans) {
    if (ip.length() == 0) {
        ans.push_back(op);
        return;
    }

    string op1 = op;
    string op2 = op;

    if (isalpha(ip[0])) {
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin());
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    } else {
        op.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(ip, op, ans);
    }
}

int main() {
    string s;
    cout << "Enter a string (letters and/or digits): ";
    cin >> s;

    vector<string> ans;
    string op = "";
    solve(s, op, ans);

    cout << "Letter case permutations:\n";
    for (const string& perm : ans) {
        cout << perm << "\n";
    }

    return 0;
}

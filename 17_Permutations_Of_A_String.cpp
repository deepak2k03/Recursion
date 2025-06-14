class Solution
{
    void solve(string ip, string op, vector<string> &v) {
        if (ip.size() == 0) {
            v.push_back(op);
            return;
        }

        unordered_set<char> mp;
        for (int i = 0; i < ip.size(); ++i) {
            if (mp.find(ip[i]) == mp.end()) {
                mp.insert(ip[i]);
                string newIp = ip.substr(0, i) + ip.substr(i + 1);
                string newOp = op + ip[i];
                solve(newIp, newOp, v);
            }
        }
    }

public:
    vector<string> find_permutation(string ip) {
        vector<string> result;
        solve(ip, "", result);
        return result;
    }
};

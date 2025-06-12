# include<bits/stdc++.h>
using namespace std;
void solve(vector<int>ip , vector<int>op, vector<vector<int>>&ans){
    if(ip.size()==0){
        ans.push_back(op);
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    op2.push_back(ip[0]);
    vector<int> new_ip(ip.begin() + 1, ip.end());
    solve(new_ip,op1,ans);
    solve(new_ip,op2,ans);
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i:v) cin>>i;
    vector<vector<int>>ans;
    vector<int>op;
    solve(v,op,ans);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
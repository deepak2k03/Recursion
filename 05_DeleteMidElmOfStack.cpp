# include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int val=s.top();
    s.pop();
    solve(s,k-1);
    s.push(val);
    return;
}
stack<int> DelMid(stack<int>&s,int size){
    if(s.size()==0) return s;
    int k=size/2+1;
    solve(s,k);
    return s;
}
int main() {
    stack<int>s;
    s.push(4);
    s.push(5);
    s.push(2);
    s.push(1);
    DelMid(s,4);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

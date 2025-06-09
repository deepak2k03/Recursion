# include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&St,int elm){
    if(St.size()==0){
        St.push(elm);
        return;
    }
        int temp=St.top();
    St.pop();
    insert(St,elm);
    St.push(temp);
    return;
}
void Reverse(stack<int> &St) {
    if(St.size()==1) return;
    int temp=St.top();
    St.pop();
    Reverse(St);
    insert(St,temp);
    return;
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    Reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
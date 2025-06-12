# include<bits/stdc++.h>
using namespace std;
void insertVal(vector<int>&v,int temp){
    if(v.size()==0||v[v.size()-1]<=temp){
        v.push_back(temp); 
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insertVal(v,temp);
    v.push_back(val);
    return;
}
void sortArray(vector<int>&v){
    if(v.size()==1) return;
    int temp=v[v.size()-1];
    v.pop_back();
    sortArray(v);
    insertVal(v,temp);
}
int main() {
    vector<int>v={4,3,5,6,2};
    sortArray(v);
    for(auto i:v) cout<<i<<" ";
    return 0;
}

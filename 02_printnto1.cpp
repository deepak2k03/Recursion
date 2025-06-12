/*
                            ██████╗ ███████╗███████╗██████╗  █████╗ ██╗  ██╗██████╗ ██╗  ██╗ ██████╗ ██████╗ 
                            ██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗██║ ██╔╝╚════██╗██║ ██╔╝██╔═══██╗╚════██╗
                            ██║  ██║█████╗  █████╗  ██████╔╝███████║█████╔╝  █████╔╝█████╔╝ ██║   ██║ █████╔╝
                            ██║  ██║██╔══╝  ██╔══╝  ██╔═══╝ ██╔══██║██╔═██╗ ██╔═══╝ ██╔═██╗ ██║   ██║ ╚═══██╗
                            ██████╝ ███████╗███████╗██║     ██║  ██║██║  ██╗███████╗██║  ██╗╚██████╔╝██████╔╝
                            ╚════╝  ╚═════╝╚══════╝╚══╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝ 
*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
using namespace std;
using namespace __gnu_pbds;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
#define int long long int
#define F first
#define YES "YES"
#define NO "NO"
#define S second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout << x << '\n'
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define ull unsigned long long
#define all(a) (a).begin(), (a).end()
#define arrinp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> sti;
typedef set<long> stl;
typedef set<char> stc;
typedef set<string> str;
typedef map<int, int> mpii;
typedef map<int, char> mpic;
typedef map<char, int> mpci;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
ll mod = 1000000007;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// binary exponentiation
int exp(int base, int n) {
    int res = 1;
    while (n) {
        if (n % 2) {
            res = res * base;
            n--;
        } else {
            base *= base;
            n /= 2;
        }
    }
    return res;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// prefix sum range query
int rsq(const vector<int>& v, int L, int R) {
    int n = v.size();
    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pfs[i] = pfs[i - 1] + v[i - 1];
    }
    return pfs[R] - pfs[L - 1];
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// gcd and lcm
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// sieve of erastothenes
vector<int> primes;
int is_prime[1000001];
void sieve() {
    int maxN = 1000000;
    fill(is_prime, is_prime + maxN + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxN; j += i) is_prime[j] = 0;
        }
    }
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// primality check
bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// finding divisors
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    return divisors;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// prime factorisation
vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// cumulative XOR from a to b
int cumulativeXOR(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
int xorFromAtoB(int a, int b) {
    return cumulativeXOR(b) ^ cumulativeXOR(a - 1);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
// DSU implementation
class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};
void solve(int n){
    if(n==1){
        cout<<"1 ";
        return;
    }
    cout<<n<<" ";
    solve(n-1);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
int32_t main() {
    solve(5);
}

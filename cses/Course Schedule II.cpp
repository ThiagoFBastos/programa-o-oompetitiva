#include "bits/stdc++.h"
 
using namespace std;
 
#define INF 1000000000
#define INFLL 1000000000000000000ll
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define fi first
#define sc second
 
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;
using ii = pair<int, int>;
 
const int N = 1e5 + 100;
 
vector<int> adj[N];
int in[N], n, m;
 
void solve() {
	priority_queue<int> pq;
 
	cin >> n >> m;
 
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[b].pb(a);
		++in[a];
	}
 
	for(int i = 0; i < n; ++i) if(!in[i]) pq.push(i);
 
	vector<int> p;
 
	while(!pq.empty()) {
		int u = pq.top(); pq.pop();
		p.pb(u + 1);
		for(int v : adj[u]) {
			if(--in[v]) continue;
			pq.push(v);
		}
	}
 
	reverse(all(p));
	for(int v : p) cout << v << ' ';
	cout << '\n';	
}
 
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  	//cin >> t;
	while(t--) solve();
	return 0;
}

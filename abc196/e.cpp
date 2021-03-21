#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

const ll INF = numeric_limits<ll>::max() / 4;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main() {
	ll N;
	cin >> N;
	ll low = -INF, high = INF, add = 0;

	for (ll i = 0; i < N; ++i) {
		ll a, t;
		cin >> a >> t;
		switch(t) {
			case 1:
				low += a;
				add += a;
				high += a;
				break;
			case 2:
				chmax(low, a);
				chmax(high, a);
				break;
			case 3:
				chmin(low, a);
				chmin(high, a);
				break;
		}
	}

	ll Q;
	cin >> Q;
	for (ll i = 0; i < Q; ++i) {
		ll x;
		cin >> x;
		x += add;

		if (x < low) x = low;
		else if (x > high) x = high;
		
		cout << x << endl;
	}

	return 0;
}
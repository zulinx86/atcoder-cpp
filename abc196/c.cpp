#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

int main() {
	ll N;
	cin >> N;

	for (ll i = 1; ; i++) {
		if (stoll(to_string(i) + to_string(i)) > N) {
			cout << i - 1 << endl;
			return 0;
		}
	}
}
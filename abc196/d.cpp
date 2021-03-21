#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

int H, W;
bool used[16][16];

ll dfs(int i, int j, int a, int b) {
	if (a < 0 || b < 0) return 0;
	if (j == W) j = 0, ++i;
	if (i == H) return 1;

	if (used[i][j]) return dfs(i, j + 1, a, b);

	ll res = 0;

	used[i][j] = true;
	res += dfs(i, j + 1, a, b - 1);

	if (j + 1 < W && !used[i][j + 1]) {
		used[i][j + 1] = true;
		res += dfs(i, j + 1, a - 1, b);
		used[i][j + 1] = false;
	}

	if (i + 1 < H && !used[i + 1][j]) {
		used[i + 1][j] = true;
		res += dfs(i, j + 1, a - 1, b);
		used[i + 1][j] = false;
	}

	used[i][j] = false;
	return res;
}

int main() {
	int A, B;
	cin >> H >> W;
	cin >> A >> B;

	cout << dfs(0, 0, A, B) << endl;
	return 0;
}
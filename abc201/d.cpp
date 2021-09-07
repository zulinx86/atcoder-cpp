#include<bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }

#define DEBUG

#ifdef DEBUG
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << " in " << __FILE__ << ")" << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;

	vvi a(h, vi(w));
	rep(i, h) {
		string s;
		cin >> s;
		rep(j, w) {
			if (s[j] == '+') a[i][j] = 1;
			else a[i][j] = -1;
		}
	}

	vvi d(h, vi(w)); // Takahashi - Aoki
	for (int i = h - 2; i >= 0; --i) {
		int x = ((i + w - 1) % 2 == 0) ? 1 : -1;
		d[i][w - 1] = d[i + 1][w - 1] + x * a[i + 1][w - 1];
	}
	for (int j = w - 2; j >= 0; --j) {
		int x = ((h - 1 + j) % 2 == 0) ? 1 : -1;
		d[h - 1][j] = d[h - 1][j + 1] + x * a[h - 1][j + 1];
	}


	for (int i = h - 2; i >= 0; --i) {
		for (int j = w - 2; j >= 0; --j) {
			if ((i + j) % 2 == 0) {
				d[i][j] = max(d[i + 1][j] + a[i + 1][j], d[i][j + 1] + a[i][j + 1]);
			} else {
				d[i][j] = min(d[i + 1][j] - a[i + 1][j], d[i][j + 1] - a[i][j + 1]);
			}
		}
	}

	if (d[0][0] == 0) cout << "Draw" << endl;
	else if (d[0][0] > 0) cout << "Takahashi" << endl;
	else if (d[0][0] < 0) cout << "Aoki" << endl;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vvvd = vector<vector<vector<double>>>;

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

	int a, b, c;
	cin >> a >> b >> c;

	vvvd dp(101, vvd(101, vd(101, 0.0)));
	dp[a][b][c] = 1.0;

	for (int p = a; p < 100; ++p) {
		for (int q = b; q < 100; ++q) {
			for (int r = c; r < 100; ++r) {
				dp[p + 1][q][r] += dp[p][q][r] * p / (p + q + r);
				dp[p][q + 1][r] += dp[p][q][r] * q / (p + q + r);
				dp[p][q][r + 1] += dp[p][q][r] * r / (p + q + r);
			}
		}
	}

	double ans = 0.0;
	for (int q = b; q < 100; ++q) {
		for (int r = c; r < 100; ++r) {
			ans += ((100 - a) + (q - b) + (r - c)) * dp[100][q][r];
		}
	}

	for (int p = a; p < 100; ++p) {
		for (int r = c; r < 100; ++r) {
			ans += ((p - a) + (100 - b) + (r - c)) * dp[p][100][r];
		}
	}

	for (int p = a; p < 100; ++p) {
		for (int q = b; q < 100; ++q) {
			ans += ((p - a) + (q - b) + (100 - c)) * dp[p][q][100];
		}
	}

	printf("%.9f\n", ans);
	return 0;
}

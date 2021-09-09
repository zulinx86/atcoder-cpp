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

ll power(ll a, ll b) {
	ll ans = 1;
	while (b--) ans *= a;
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int k;
	cin >> k;

	string s, t;
	cin >> s >> t;

	map<int, int> rem;
	rep(i, 9) rem[i + 1] = k;

	map<int, int> takahashi, aoki;
	rep(i, 4) {
		takahashi[s[i] - '0']++;
		rem[s[i] - '0']--;
	}
	rep(i, 4) {
		aoki[t[i] - '0']++;
		rem[t[i] - '0']--;
	}

	ll cnt = 0;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i == j && rem[i] < 2) continue;
			if (i != j && (rem[i] < 1 || rem[j] < 1)) continue;
			
			map<int, int> t_buf = takahashi, a_buf = aoki;
			t_buf[i]++;
			a_buf[j]++;

			ll t_score = 0, a_score = 0;
			for (int i = 1; i <= 9; ++i) t_score += i * power(10, t_buf[i]);
			for (int i = 1; i <= 9; ++i) a_score += i * power(10, a_buf[i]);

			if (t_score > a_score) {
				ll buf = rem[i];
				if (i == j) buf *= (rem[i] - 1);
				else buf *= rem[j];
				cnt += buf;
			}
		}
	}

	ll all = 9 * k - 8;
	printf("%.7f\n", (double)cnt / (double)all / (double)(all - 1));
	return 0;
}

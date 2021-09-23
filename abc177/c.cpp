#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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

template <ll mod>
class modint {
	using M = modint;

public:
	modint(ll x = 0) {
		while (x < 0) x += mod;
		_v = x % mod;
	}
	modint(const M &x) { _v = x._v; }

	M operator+() const { return *this; }
	M operator-() const { return M(-_v); }

	M &operator++() {
		_v = (_v + 1) % mod;
		return *this;
	}
	M &operator--() {
		_v = (_v - 1) % mod;
		return *this;
	}
	M operator++(int) {
		M res(*this);
		++*this;
		return res;
	}
	M operator--(int) {
		M res(*this);
		--*this;
		return res;
	}

	M &operator+=(const M &x) {
		_v = (_v + x._v) % mod;
		return *this;
	}
	M &operator-=(const M &x) {
		_v = (_v + mod - x._v) % mod;
		return *this;
	}
	M &operator*=(const M &x) {
		_v = (_v * x._v) % mod;
		return *this;
	}
	M &operator/=(const M &x) { return *this *= x.inv(); }

	M operator+(const M &x) const { return M(*this) += x; }
	M operator-(const M &x) const { return M(*this) -= x; }
	M operator*(const M &x) const { return M(*this) *= x; }
	M operator/(const M &x) const { return M(*this) /= x; }

	M pow(ll n) const {
		M x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	M inv() const { return pow(mod - 2); }

	friend ostream &operator<<(ostream &os, const M &x) {
		os << x._v;
		return os;
	}

private:
	ll _v = 0;
};

using mint = modint<1000000007>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	mint sum = 0;
	vector<mint> a(n);
	rep(i, n) {
		int x;
		cin >> x;
		a[i] = mint(x);
		sum += a[i];
	}

	mint ans = 0;
	rep(i, n) {
		sum -= a[i];
		ans += a[i] * sum;
	}

	cout << ans << endl;
	return 0;
}

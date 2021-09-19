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

class dsu {
public:
	dsu() : _n(0) {}
	dsu(int n) : _n(n), _grp_n(n), _per(n, -1) {}

	bool same(int v1, int v2) {
		return root(v1) == root(v2);
	}

	int root(int v) {
		if (_per[v] < 0) return v;
		return _per[v] = root(_per[v]);
	}

	int size(int v) {
		return -1 * _per[root(v)];
	}

	int merge(int v1, int v2) {
		int r1 = root(v1), r2 = root(v2);
		if (r1 == r2) return r1;
		_grp_n -= 1;
		if (-1 * _per[r1] < -1 * _per[r2]) swap(r1, r2);
		_per[r1] += _per[r2];
		_per[r2] = r1;
		return r1;
	}

	int group_count() {
		return _grp_n;
	}

private:
	int _n, _grp_n;
	vector<int> _per;
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<pi> ab(m);
	rep(i, m) {
		cin >> ab[i].fi >> ab[i].se;
		--ab[i].fi;
		--ab[i].se;
	}

	ll ans = 0;
	rep(i, 1 << n) {
		dsu uf(2 * n);

		bool bad = false;
		rep(j, m) {
			int a = ab[j].fi, b = ab[j].se;
			int bit_a = (1 << a), bit_b = (1 << b);
			if ((bit_a & i) == 0 && (bit_b & i) == 0) {
				bad = true;
				break;
			} else if ((bit_a & i) != 0 && (bit_b & i) != 0) {
				uf.merge(a, b + n);
				uf.merge(b, a + n);
			}
		}
		if (bad) continue;

		bad = false;
		rep(j, n) {
			if (uf.same(j, j + n)) {
				bad = true;
				break;
			}
		}
		if (bad) continue;

		ll r, gb = 0;
		rep(j, n) if (i & (1 << j)) ++gb;
		r = n - gb;

		ll p = 1;
		rep(j, uf.group_count() / 2 - r) p *= 2;
		ans += p;
	}

	cout << ans << endl;
	return 0;
}

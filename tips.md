# Tips
## Conversion between number and string
- number to `std::string`: [`std::to_string`](http://www.cplusplus.com/reference/string/to_string/)
- `std::string` to `int`: [`std::stoi`](http://www.cplusplus.com/reference/string/stoi/)
- `std::string` to `long`: [`std::stol`](http://www.cplusplus.com/reference/string/stol/)
- `std::string` to `long long`: [`std::stoll`](https://www.cplusplus.com/reference/string/stoll/)


## Computational Complexity
From [W - 2.06.計算量](https://atcoder.jp/contests/apg4b/tasks/APG4b_w)

![](https://img.atcoder.jp/APG4b-hidden/2.06.complexity_graph.png)

| N     | O(1)     | O(log N) | O(N)     | O(N log N) | O(N^2)    | O(2^N)    |
| ----- | -------- | -------- | -------- | ---------- | --------- | --------- |
| 1     | a moment | a moment | a moment | a moment   | a moment  | a moment  |
| 10    | a moment | a moment | a moment | a moment   | a moment  | a moment  |
| 1000  | a moment | a moment | a moment | a moment   | ~ 0.01 s  | explosion |
| 10^6  | a moment | a moment | ~ 0.01 s | ~ 0.2 s    | ~ 3 h     | explosion |
| 10^8  | a moment | a moment | ~ 1 s    | ~ 30 s     | ~ 3y      | explosion |
| 10^16 | a moment | a moment | ~ 3 y    | ~ 170 y    | explosion | explosion |
|       |          |          |          |            |           |           |


## Data Type Ranges
| type                 | byte | range                                      | order    |
| -------------------- | ---- | ------------------------------------------ | -------- |
| `char`               | 1    | -128 ~ 127                                 | O(10^2)  |
| `unsigned char`      | 1    | 0 ~ 255                                    | O(10^2)  |
| `short`              | 2    | -32768 ~ 32767                             | O(10^4)  |
| `unsigned short`     | 2    | 0 ~ 65535                                  | O(10^4)  |
| `int`                | 4    | -2147483648 ~ 2147483647                   | O(10^9)  |
| `unsigned int`       | 4    | 0 ~ 4294967295                             | O(10^9)  |
| `long long`          | 8    | -9223372036854775808 ~ 9223372036854775807 | O(10^18) |
| `unsigned long long` | 8    | 0 ~ 18446744073709551615                   | O(10^19) |
| `float`              | 4    | 1.17549e-38 ~ 3.40282e+38                  |          |
| `double`             | 8    | 2.27507e-308 ~ 1.79769e+308                |          |
| `long double`        | 16   | 3.3621e-4932 ~ 1.18973e+4932               |          |


## Brute-Force Search
### Brute-Force Search For Combination
How to search all combination of N items.
```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < (1 << n); ++i) {
		cout << bitset<10>(i) << endl;
	}
}
```
```
$ g++ test.cpp
$ ./a.out
4
0000000000
0000000001
0000000010
0000000011
0000000100
0000000101
0000000110
0000000111
0000001000
0000001001
0000001010
0000001011
0000001100
0000001101
0000001110
0000001111
```


## Distances
### Hamming Distance
https://en.wikipedia.org/wiki/Hamming_distance
> In information theory, the Hamming distance between two strings of equal length is the number of positions at which the corresponding symbols are different. In other words, it measures the minimum number of substitutions required to change one string into the other, or the minimum number of errors that could have transformed one string into the other.


## Integer Problem
### Number of Digits
```cpp
using ull = unsigned long long;

int calc_num_digits(ull n) {
	int res = 0;
	while (n) {
		++res;
		n /= 10;
	}
	return res;
}
```

### Primality Test
When we test the primality of N, we only need to check the number from 2 to the square root of N.
```cpp
using ull = unsigned long long;

bool is_prime(ull n) {
	if (n == 1) return false;
	for (ull i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
```

### Number of Divisors
```cpp
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

vector<ull> get_divisors(ull n) {
	vector<ull> res;
	for (ull i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (n / i != i) res.push_back(n / i);
		}
	}

	sort(res.begin(), res.end());
	return res;
}
```

### Prime Factorization
```cpp
#include<vector>

using namespace std;
using ull = unsigned long long;

vector<pair<ull, ull>> prime_factorization(ull n) {
	vector<pair<ull, ull>> res;
	for (ull a = 2; a * a <= n; ++a) {
		if (n % a != 0) continue;

		ull ex = 0;
		while (n % a == 0) {
			++ex;
			n /= a;
		}

		res.push_back({a, ex});
	}

	if (n != 1) res.push_back({n, 1});
	return res;
}
```

### Links
- [AtCoder 版！マスター・オブ・整数 (素因数分解編) - Qiita](https://qiita.com/drken/items/a14e9af0ca2d857dad23)
- [AtCoder 版！マスター・オブ・整数 (最大公約数編) - Qiita](https://qiita.com/drken/items/0c88a37eec520f82b788)


## Recursion
### Fibonacci Numbers
Dynamic Programming (DP) using memo.
```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;

	if (memo[n] != -1) return memo[n];

	return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void) {
	int n;
	cin >> n;

	memo = vector<long long>(n, -1);
	cout << fibo(n) << endl;

	return 0;
}
```

### Euclidean Algorithm
Recall that the greatest common divisor (GCD) of two integers a and b, written gcd(a, b), is the largest integer that divides a and b.
Define gcd(a, 0) = a.

Theorem:
```
Suppose two integers a and b (a >= b > 0) and a devided by b equals q with a remainder of r.
  a = q * b + r
Then,
  gcd(a, b) = gcd(b, r)
```

Proof:
```
Let m = gcd(a, b) and n = gcd(b, r).

a and b can be written as follows:
  a = m * a'
  b = m * b'
where a' and b' are coprime.

From the above,
  m * a' = q * (m * b') + r
       r = m * (a' - q * b') .
This means that m is one of common divisors of b and r.
As n is the GCD of b and r, m <= n ... (1)

In addition, 
  a = q * b + r
    = q * n * b'' + n * r''
    = n * (q * b'' + r'')
This means that n is one of common divisors of a and b.
As m is the GCD of a and b, n <= m ... (2)

From (1) and (2), n = m which means gcd(a, b) = gcd(b, r).
``` 

```cpp
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
```


## Graphs & Trees
### Disjoint Set Union (DSU) / Union-Find
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class dsu {
	dsu() : _n(0) {}
	dsu(int n) : _n(n), _per(n, -1) {}

	bool same(int v1, int v2) {
		return root(v1) == root(v2);
	}

	int root(int v) {
		if (per[v] < 0) return v;
		return per[v] = root(per[v]);
	}

	int size(int v) {
		return -1 * _per[root(v)];
	}

	int merge(int v1, int v2) {
		int r1 = root(v1), r2 = root(v2);
		if (r1 == r2) return r1;
		if (-1 * _per[r1] < -1 * _per[r2]) swap(r1, r2);
		_per[r1] += _per[r2];
		_per[r2] = r1;
		return r1;
	}

private:
	int _n;

	// root node : -1 * component size
	// otherwise : parent node
	vector<int> _per;
};
```

### Directed Acyclic Graph (DAG)
- [Directed acyclic graph - Wikipedia](https://en.wikipedia.org/wiki/Directed_acyclic_graph)
- Directed acyclic graph (DAG) is a directed graph with no directed cycles.

### Topological Sort
- [Topological sorting - Wikipedia](https://en.wikipedia.org/wiki/Topological_sorting)
- Topological sort of a directed acyclic graph is a linear ordering of its vertices such that for every directed edge from a vertex `u` to another vertex `v`, `u` comes before `v` in the ordering.
- Time complexity: O(|V| + |E|)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using graph = vector<vector<int>>;

void dfs(const graph &g, vector<bool> &seen, vector<int> &order, int v) {
	seen[v] = true;
	for (auto next_v : g[v]) {
		if (seen[next_v]) continue;
		dfs(g, seen, order, v);
	}
	order.push_back(v);
}

int main() {
	int n, m;
	cin >> n >> m;

	graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	vector<bool> seen(n, false);
	vector<int> order;
	for (int v = 0; v < n; ++v) {
		if (seen[v]) continue;
		dfs(g, seen, order, v);
	}
	reverse(order.begin(), order.end());

	for (auto v : order) cout << v << " -> ";
	cout << endl;
}
```

### Dijkstra's Algorithm
- [Dijkstra's algorithm - Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- Dijkstra's algorithm is an algorithm for finding the shortest paths between vertices in a graph without negative edges.

#### Simple Version
- Time complexity: O(|V|^2)
```cpp
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

struct edge {
	int to;
	long long w;
	edge(int to, long long w) : to(to), w(w) {}
};

using graph = vector<vector<edge>>;

template <class T>
bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	} else {
		return false;
	}
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back(edge(b, w));
	}

	vector<bool> used(n, false);
	vector<long long> dist(n, INF);
	dist[s] = 0;
	for (int it = 0; it < n; ++it) {
		long long min_dist = INF;
		int min_v = -1;

		for (int v = 0; v < n; ++v) {
			if (!used[v] && dist[v] < min_dist) {
				min_dist = dist[v];
				min_v = v;
			}
		}

		if (min_v == -1) break;

		for (auto e : g[min_v]) {
			chmin(dist[e.to], dist[min_v] + e.w);
		}
		used[min_v] = true;
	}

	for (int v = 0; v < n; ++v) {
		if (dist[v] < INF) cout << dist[v] << endl;
		else ouct << "INF" << endl;
	}

	return 0;
}
```

#### Heap Version
- Time complexity: O(|E| log |V|)
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int to;
	long long w;
	edge(int to, long long w) : to(to), w(w) {}
};

using graph = vector<vector<edge>>;

template <class T>
bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	} else {
		return false;
	}
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back(edge(b, w));
	}

	vector<long long> dist(n, INF);
	dist[s] = 0;

	priority_queue<pair<long long, int>,
		vector<pair<long long, int>>,
		greater<pair<long long, int>>> q;
	q.push(make_pair(dist[s], s));

	while (!q.empty()) {
		int v = q.top().second;
		long long d = q.top().first;
		q.pop();

		if (d > dist[v]) continue;

		for (auto e : g[v]) {
			if (chmin(dist[e.to], dist[v] + e.w)) {
				q.push(make_pair(dist[e.to], e.to));
			}
		}
	}

	for (int v = 0; v < n; ++v) {
		if (dist[v] < INF) cout << dist[v] << endl;
		else cout << "INF" << endl;
	}

	return 0;
}
```

### Bellman-Ford Algorithm
- [Bellman–Ford algorithm - Wikipedia](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
- Bellman-Ford algorithm is an algorithm that computes shortest paths from a single vertex to all of the other vertices in a weighted graph.
- It is slower than Dijkstra's algorithm for the same problem, but it is capable of handling graphs in which some of the edge weights are negative numbers.
- Proof of correctness
	- Suppose that there are no negative cycles.
		- The shortest paths have no cycles.
		- This means that the shortest paths have at most |V|-1 edges.
		- Thus, relaxing for all the edges |V|-1 times provides the shortest paths.
		- This means that there are no updates for |V|-th relaxation.
	- In the situation where there are some negative cycles, updates always occur/ for |V|-th relaxation.
- Time complexity: O(|V||E|)
```cpp
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

struct edge {
	int to;
	long long w;
	edge(int to, long long w) : to(to), w(w) {}
};

using graph = vector<vector<edge>>;

template <class T>
bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	} else {
		return false;
	}
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back(edge(b, w));
	}

	bool exist_negative_cycle = false;
	vector<long long> dist(n, INF);
	dist[s] = 0;
	for (int it = 0; it < n; ++it) {
		bool update = false;
		for (int v = 0; v < n; ++v) {
			if (dist[v] == INF) continue;
			for (auto e : g[v]) {
				if (chmin(dist[e.to], dist[v] + e.w)) {
					update = true;
				}
			}
		}

		if (!update) break;
		if (it == n - 1 && update) exist_negative_cycle = true;
	}

	if (exist_negative_cycle) cout << "negative cycle" << endl;
	else {
		for (int v = 0; v < n; ++v) {
			if (dist[v] < INF) cout << dist[v] << endl;
			else cout << "INF" << endl;
		}
	}

	return 0;
}
```

### Floyd-Warshall Algorithm
- [Floyd–Warshall algorithm - Wikipedia](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)
- Floyd-Warshall algorithm is an algorithm for finding shortest paths in a directed weighted graph with positive or negative edge weights (but with no negatice cycles).
```cpp
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<long long>> dp(n, vector<long long>(n, INF));
	for (int e = 0; e < m; ++e) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		dp[a][b] = w;
	}
	for (int v = 0; v < n; ++v) dp[v][v] = 0;

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	bool exist_negative_cycle = false;
	for (int v = 0; v < n; ++v) {
		if (dp[v][v] < 0) exist_negative_cycle = true;
	}

	if (exist_negative_cycle) {
		cout << "NEGATIVE CYCLE" << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j) cout << " ";
				if (dp[i][j] < INF/2) cout << dp[i][j];
				else cout << "INF";
			}
			cout << endl;
		}
	}

	return 0;
}
```

### Minimum Spanning Tree (MST)
- [Minimum spanning tree - Wikipedia](https://en.wikipedia.org/wiki/Minimum_spanning_tree)
- Minimum spanning tree (MST) is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

#### Kruskal's Algorithm
- [Kruskal's algorithm - Wikipedia](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using edge = pair<int, pair<int, int>>

class dsu {
	dsu() : _n(0) {}
	dsu(int n) : _n(n), _per(n, -1) {}

	bool same(int v1, int v2) {
		return root(v1) == root(v2);
	}

	int root(int v) {
		if (per[v] < 0) return v;
		return per[v] = root(per[v]);
	}

	int size(int v) {
		return -1 * _per[root(v)];
	}

	int merge(int v1, int v2) {
		int r1 = root(v1), r2 = root(v2);
		if (r1 == r2) return r1;
		if (-1 * _per[r1] < -1 * _per[r2]) swap(r1, r2);
		_per[r1] += _per[r2];
		_per[r2] = r1;
		return r1;
	}

private:
	int _n;

	// root node : -1 * component size
	// otherwise : parent node
	vector<int> _per;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<edge> edges(m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = edge(w, make_pair(u, v));
	}

	sort(edges.begin(), edges.end());

	long long ans = 0;
	dsu uf(n);
	for (int i = 0; i < m; ++i) {
		int w = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		if (uf.same(u, v)) continue;

		ans += w;
		uf.merge(u, v);
	}

	cout << ans << endl;
}
```


## Sort
- Stable sort means that it maintains the relative order of items with equal values.
- In-place means that it doesn't require any additional space.

### Bubble Sort
- Time complexity: O(N^2)
- Space complexity: O(1)

```cpp
#include <vector>

using namespace std;

void bubble_sort(vector<int> &a) {
	int n = a.size();
	
	bool sorted = false;
	while (!sorted) {
		sorted = true;

		for (int i = 0; i < n - 1; ++i) {
			if (a[i] > a[i + 1]) {
				sorted = false;
				swap(a[i], a[i + 1]);
			}
		}

		--n;
	}
}
```

### Insertion Sort
- Time complexity: O(N^2)
- Space complexity: O(1)

```cpp
#include <vector>

using namespace std;

void insertion_sort(vector<int> &a) {
	int n = a.size();
	for (int i = 1; i < n; ++i) {
		int v = a[i];

		int j = i;
		for (; j > 0; --j) {
			if (a[j - 1] > v) {
				a[j] = a[j - 1];
			}
			else break;
		}
		a[j] = v;
	}
}
```

### Merge Sort
- Time complexity: O(N log N)
- Space complexity: O(N)

```cpp
#include <vector>

using namespace std;

void merge_sort(vector<int> &a, int left, int right) {
	if (right - left <= 1) return;
	int mid = (left + right) / 2;

	merge_sort(a, left, mid);
	merge_sort(a, mid, right);

	vector<int> buf;
	for (int i = left; i < mid; ++i) buf.push_back(a[i]);
	for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

	int idx_left = 0, idx_right = buf.size() - 1;
	for (int i = left; i < right; ++i) {
		if (buf[idx_left] <= buf[idx_right]) {
			a[i] = buf[idx_left++];
		} else {
			a[i] = buf[idx_right--];
		}
	}
}
```

### Quick Sort
- Average time complexity: O(N log N)
- Worst time complexity: O(N^2)
- Space complexity: O(1)

```cpp
#include <vector>

using namespace std;

void quick_sort(vector<int> &a, int left, int right) {
	if (left + 1 >= right) return;

	int mid = (left + right) / 2;
	int pivot = a[mid];
	swap(a[mid], a[right - 1]);

	int i = left;
	for (int j = left, j < right - 1; ++j) {
		if (a[j] < pivot) {
			swap(a[i++], a[j]);
		}
	}

	quick_sort(a, left, i);
	quick_sort(a, i + 1, right);
}
```

### Heap Sort
- Time complexity: O(N log N)
- Space complexity: O(1)

```cpp
#include <vector>

using namespace std;

void heapify(vector<int> &a, int i, int n) {
	int child = i * 2 + 1;
	if (child >= n) return;

	if (child + 1 < n && a[child + 1] > a[child]) ++child;

	if (a[child] <= a[i]) return;
	swap(a[i], a[child]);

	heapify(a, child, n);
}

void heap_sort(vector<int> &a) {
	int n = a.size();

	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(a, i, n);
	}

	for (int i = n - 1; i > 0; --i) {
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}
```

### Bucket Sort
- Time complexity: O(N + A)
- Space complexity: O(N + A)

```cpp
#include <vector>

using namespace std;

const int MAX = 100000;

void bucket_sort(vector<int> &a) {
	int n = a.size();

	vector<int> num(MAX, 0);
	for (int i = 0; i < n; ++i) {
		++num[a[i]];
	}

	vector<int> sum(MAX, 0);
	for (int v = 1; v < MAX; ++v) {
		sum[v] = sum[v - 1] + num[v];
	}

	vector<int> sorted(n);
	for (int i = n - 1; i >= 0; --i) {
		sorted[--sum[a[i]]] = a[i];
	}

	a = sorted;
}
```


## Coding Interview
1. Clarify the problem.
	- Input (Data Type, Size)
	- Output
2. Take some examples.
3. Start with the brute-force algorithm.
	- Check its computational complexity.
		- Time complexity
		- Space complexity
4. Improve the algorithm.


## To-Do
- Divide-and-Conquer method
- Dynamic Programming


## Time Complexity of C++ STL (Standard Template Library)
| Method \ Class | `vector`       | `priority_queue` |
| -------------- | -------------- | ---------------- |
| `size()`       | O(1)           | \*\*             |
| `push()`       | n/a            | todo             |
| `pop()`        | n/a            | todo             |
| `push_back()`  | O(1) / O(N) \* | n/a              |
| `top()`        | n/a            | todo             |
| `operator[]`   | O(1)           | n/a              |

- n/a : The method is not available.
- \* : The time complexity can change depending on the situation.
- \*\* : The time complexity depends on other data structures.

### References
- [`vector`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html#std::vector)
	- [`size()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html#_ZNKSt6vector4sizeEv)
	- [`push_back()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html#_ZNSt6vector9push_backERKT_)
	- [`struct _Vector_base`](https://code.woboq.org/gcc/include/c++/7.2.1/bits/stl_vector.h.html#std::_Vector_base)
		- [`struct _Vector_impl`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html#std::_Vector_base::_Vector_impl)
- [`list`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_list.h.html#std::list)
- [`forward_list`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/forward_list.h.html#410)
- [`priority_queue`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_queue.h.html#423)
- [`size()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_queue.h.html#572)
	- [`push()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_queue.h.html#595)
	- [`pop()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_queue.h.html#630)
	- [`top()`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_queue.h.html#580)

### Allocator
- [`__allocator_traits_base`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/alloc_traits.h.html#std::__allocator_traits_base)
- [`allocator_traits`](https://code.woboq.org/gcc/libstdc++-v3/include/bits/alloc_traits.h.html#std::allocator_traits)


# Tips
## Conversion between number and string
- number to `std::string`: [`std::to_string`](http://www.cplusplus.com/reference/string/to_string/)
- `std::string` to `int`: [`std::stoi`](http://www.cplusplus.com/reference/string/stoi/)
- `std::string` to `long`: [`std::stol`](http://www.cplusplus.com/reference/string/stol/)
- `std::string` to `long long`: [std::stoll](https://www.cplusplus.com/reference/string/stoll/)


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


## Distances
### Hamming Distance
https://en.wikipedia.org/wiki/Hamming_distance
> In information theory, the Hamming distance between two strings of equal length is the number of positions at which the corresponding symbols are different. In other words, it measures the minimum number of substitutions required to change one string into the other, or the minimum number of errors that could have transformed one string into the other.


## Integer Problem
### Number of Digits
```cpp
using ull = unsigned long long;

int CalcNumDigits(ull N) {
	int res = 0;
	while (N) {
		++res;
		N /= 10;
	}
	return res;
}
```

### Primality Test
When we test the primality of N, we only need to check the number from 2 to the square root of N.
```cpp
using ull = unsigned long long;

bool IsPrime(ull N) {
	if (N == 1) return false;
	for (ull i = 2; i * i <= N; ++i) {
		if (N % i == 0) return false;
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

vector<ull> GetDivisors(ull N) {
	vector<ull> res;
	for (ull i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			if (N / i != i) res.push_back(N/ i);
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

vector<pair<ull, ull>> PrimeFactorization(ull N) {
	vector<pair<ull, ull>> res;
	for (ull a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;

		ull ex = 0;
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		res.push_back({a, ex});
	}

	if (N != 1) res.push_back({N, 1});
	return res;
}
```

### Links
- [AtCoder 版！マスター・オブ・整数 (素因数分解編) - Qiita](https://qiita.com/drken/items/a14e9af0ca2d857dad23)
- [AtCoder 版！マスター・オブ・整数 (最大公約数編) - Qiita](https://qiita.com/drken/items/0c88a37eec520f82b788)


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
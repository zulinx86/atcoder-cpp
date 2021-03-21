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
# Search Algorithms Comparison

<details>
<summary><h2>📊 Linear Search</h2></summary>

> ### Complexity Analysis
> | Metric | Value |
> |--------|--------|
> | Time Complexity | `O(n)` |
> | Space Complexity | `O(1)` |

#### ✅ Advantages
- Simple and easy to implement
- Works on unsorted arrays
- Good for small datasets
- No preprocessing required

#### ❌ Disadvantages
- Slow for large datasets
- Not efficient compared to other search algorithms
- Requires traversing entire array in worst case
</details>

<details>
<summary><h2>🔍 Binary Search</h2></summary>

> ### Complexity Analysis
> | Metric | Value |
> |--------|--------|
> | Time Complexity | `O(log n)` |
> | Space Complexity | `O(1)` iterative, `O(log n)` recursive |

#### ✅ Advantages
- Very efficient for large datasets
- Fast search process
- Reliable and predictable performance

#### ❌ Disadvantages
- Array must be sorted
- Only works on ordered collections
- Requires random access to elements
</details>

<details>
<summary><h2>📈 Interpolation Search</h2></summary>

> ### Complexity Analysis
> | Metric | Value |
> |--------|--------|
> | Time Complexity (Average) | `O(log log n)` |
> | Time Complexity (Worst) | `O(n)` |
> | Space Complexity | `O(1)` |

#### ✅ Advantages
- Better than binary search for uniformly distributed data
- Very efficient for sorted arrays
- Works well when elements are distributed uniformly

#### ❌ Disadvantages
- Poor performance for non-uniform distributions
- Array must be sorted
- More complex implementation than binary search
</details>
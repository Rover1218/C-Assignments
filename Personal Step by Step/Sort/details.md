# 🎯 Sorting Algorithms Comparison

<div align="center">
  <img src="https://img.shields.io/badge/Complexity-Analysis-blue"/>
  <img src="https://img.shields.io-badge/Algorithms-Sorting-green"/>
</div>

---

## 🔄 Bubble Sort
<details>
<summary>View Details</summary>

### ✅ Advantages
- 📌 Simple to understand and implement
- 📌 Efficient for small datasets or nearly sorted data

### ❌ Disadvantages
- 📌 Inefficient for large datasets
- 📌 High number of comparisons and swaps

### ⏱️ Time & Space Complexity
| Case    | Time      | Space |
|---------|-----------|--------|
| Best    | O(n)      | O(1)   |
| Average | O(n²)     | O(1)   |
| Worst   | O(n²)     | O(1)   |

</details>

## 🔄 Insertion Sort
### ✅ Advantages:
- Simple to implement
- Efficient for small datasets or nearly sorted data
- Stable sort

### ❌ Disadvantages:
- Inefficient for large datasets

### ⏱️ Complexity:
- Best: O(n)
- Average: O(n^2)
- Worst: O(n^2)
- Space Complexity: O(1)

## 🔄 Merge Sort
### ✅ Advantages:
- Efficient for large datasets
- Stable sort

### ❌ Disadvantages:
- Requires additional memory
- More complex to implement

### ⏱️ Complexity:
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)
- Space Complexity: O(n)

## 🔄 Quick Sort
### ✅ Advantages:
- Efficient for large datasets
- In-place sorting algorithm

### ❌ Disadvantages:
- Not stable
- Worst-case performance can be poor

### ⏱️ Complexity:
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n^2)
- Space Complexity: O(log n)

## 🔄 Selection Sort
### ✅ Advantages:
- Simple to implement
- Performs well on small datasets

### ❌ Disadvantages:
- Inefficient for large datasets
- Not stable

### ⏱️ Complexity:
- Best: O(n^2)
- Average: O(n^2)
- Worst: O(n^2)
- Space Complexity: O(1)

## 📊 Visual Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Stability |
|-----------|-----------|--------------|------------|-------|-----------|
| Bubble    | O(n)      | O(n²)        | O(n²)      | O(1)  | ✅        |
| Insertion | O(n)      | O(n²)        | O(n²)      | O(1)  | ✅        |
| Merge     | O(n log n)| O(n log n)   | O(n log n) | O(n)  | ✅        |
| Quick     | O(n log n)| O(n log n)   | O(n²)      | O(log n)| ❌     |
| Selection | O(n²)     | O(n²)        | O(n²)      | O(1)  | ❌        |

---
<div align="center">
  <i>💡 Choose the right algorithm based on your specific use case!</i>
</div>
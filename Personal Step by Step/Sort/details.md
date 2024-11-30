# 🎯 Sorting Algorithms Comparison

<div align="center">
  <img src="https://img.shields.io/badge/Complexity-Analysis-blue"/>
  <img src="https://img.shields.io-badge/Algorithms-Sorting-green"/>
</div>

---

<details>
<summary><h2>🔄 Bubble Sort</h2></summary>

### ✅ Advantages
- 📌 Simple to understand and implement
- 📌 Efficient for small datasets or nearly sorted data

### ❌ Disadvantages
- 📌 Inefficient for large datasets
- 📌 High number of comparisons and swaps

<details>
<summary>⏱️ View Time & Space Complexity</summary>

| Case    | Time      | Space |
|---------|-----------|--------|
| Best    | O(n)      | O(1)   |
| Average | O(n²)     | O(1)   |
| Worst   | O(n²)     | O(1)   |
</details>
</details>

<details>
<summary><h2>🔄 Insertion Sort</h2></summary>

### ✅ Advantages
- 📌 Simple to implement
- 📌 Efficient for small datasets or nearly sorted data
- 📌 Stable sort

### ❌ Disadvantages
- 📌 Inefficient for large datasets

<details>
<summary>⏱️ View Complexity</summary>

| Case    | Time      | Space |
|---------|-----------|--------|
| Best    | O(n)      | O(1)   |
| Average | O(n²)     | O(1)   |
| Worst   | O(n²)     | O(1)   |
</details>
</details>

<details>
<summary><h2>🔄 Merge Sort</h2></summary>

### ✅ Advantages
- 📌 Efficient for large datasets
- 📌 Stable sort

### ❌ Disadvantages
- 📌 Requires additional memory
- 📌 More complex to implement

<details>
<summary>⏱️ View Complexity</summary>

| Case    | Time        | Space |
|---------|-------------|--------|
| Best    | O(n log n)  | O(n)   |
| Average | O(n log n)  | O(n)   |
| Worst   | O(n log n)  | O(n)   |
</details>
</details>

<details>
<summary><h2>🔄 Quick Sort</h2></summary>

### ✅ Advantages
- 📌 Efficient for large datasets
- 📌 In-place sorting algorithm

### ❌ Disadvantages
- 📌 Not stable
- 📌 Worst-case performance can be poor

<details>
<summary>⏱️ View Complexity</summary>

| Case    | Time        | Space    |
|---------|-------------|----------|
| Best    | O(n log n)  | O(log n) |
| Average | O(n log n)  | O(log n) |
| Worst   | O(n²)       | O(log n) |
</details>
</details>

<details>
<summary><h2>🔄 Selection Sort</h2></summary>

### ✅ Advantages
- 📌 Simple to implement
- 📌 Performs well on small datasets

### ❌ Disadvantages
- 📌 Inefficient for large datasets
- 📌 Not stable

<details>
<summary>⏱️ View Complexity</summary>

| Case    | Time      | Space |
|---------|-----------|--------|
| Best    | O(n²)     | O(1)   |
| Average | O(n²)     | O(1)   |
| Worst   | O(n²)     | O(1)   |
</details>
</details>

<details>
<summary><h2>📊 Visual Comparison Chart</h2></summary>

| Algorithm | Best Case | Average Case | Worst Case | Space | Stability |
|-----------|-----------|--------------|------------|-------|-----------|
| Bubble    | O(n)      | O(n²)        | O(n²)      | O(1)  | ✅        |
| Insertion | O(n)      | O(n²)        | O(n²)      | O(1)  | ✅        |
| Merge     | O(n log n)| O(n log n)   | O(n log n) | O(n)  | ✅        |
| Quick     | O(n log n)| O(n log n)   | O(n²)      | O(log n)| ❌     |
| Selection | O(n²)     | O(n²)        | O(n²)      | O(1)  | ❌        |
</details>

---
<div align="center">
  <i>💡 Choose the right algorithm based on your specific use case!</i>
</div>
<style>
.algorithm {
    background-color: #f8f9fa;
    padding: 20px;
    margin: 15px 0;
    border-radius: 8px;
    border-left: 4px solid #007bff;
}

.complexity {
    color: #28a745;
    font-weight: bold;
}

.advantages {
    color: #28a745;
}

.disadvantages {
    color: #dc3545;
}

.separator {
    border-top: 2px dashed #dee2e6;
    margin: 30px 0;
}
</style>

# Search Algorithms Comparison

<div class="algorithm">

## Linear Search
- <span class="complexity">**Time Complexity**: O(n)</span>
- <span class="complexity">**Space Complexity**: O(1)</span>

<div class="advantages">

### Advantages:
- Simple and easy to implement
- Works on unsorted arrays
- Good for small datasets
- No preprocessing required
</div>

<div class="disadvantages">

### Disadvantages:
- Slow for large datasets
- Not efficient compared to other search algorithms
- Requires traversing entire array in worst case
</div>
</div>

<div class="separator"></div>

<div class="algorithm">

## Binary Search
- <span class="complexity">**Time Complexity**: O(log n)</span>
- <span class="complexity">**Space Complexity**: O(1) iterative, O(log n) recursive</span>

<div class="advantages">

### Advantages:
- Very efficient for large datasets
- Fast search process
- Reliable and predictable performance
</div>

<div class="disadvantages">

### Disadvantages:
- Array must be sorted
- Only works on ordered collections
- Requires random access to elements
</div>
</div>

<div class="separator"></div>

<div class="algorithm">

## Interpolation Search
- <span class="complexity">**Time Complexity**: 
  - Average case: O(log log n)
  - Worst case: O(n)</span>
- <span class="complexity">**Space Complexity**: O(1)</span>

<div class="advantages">

### Advantages:
- Better than binary search for uniformly distributed data
- Very efficient for sorted arrays
- Works well when elements are distributed uniformly
</div>

<div class="disadvantages">

### Disadvantages:
- Poor performance for non-uniform distributions
- Array must be sorted
- More complex implementation than binary search
</div>
</div>

<div class="separator"></div>

<div class="algorithm">

## Exponential Search
- <span class="complexity">**Time Complexity**: O(log n)</span>
- <span class="complexity">**Space Complexity**: O(1)</span>

<div class="advantages">

### Advantages:
- Works well for unbounded/infinite arrays
- Useful for searching in bounded arrays
- More efficient than binary search for values closer to first element
</div>

<div class="disadvantages">

### Disadvantages:
- Array must be sorted
- Additional overhead compared to binary search
- Not suitable for small datasets
</div>
</div>

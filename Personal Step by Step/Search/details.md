<style>
.algorithm {
    background-color: #ffffff;
    box-shadow: 0 2px 4px rgba(0,0,0,0.1);
    margin: 20px 0;
    border-radius: 10px;
    overflow: hidden;
    transition: transform 0.2s ease;
}

.algorithm:hover {
    transform: translateY(-2px);
    box-shadow: 0 4px 8px rgba(0,0,0,0.15);
}

.algorithm-header {
    background-color: #f8f9fa;
    padding: 15px 20px;
    cursor: pointer;
    border-bottom: 1px solid #eee;
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.algorithm-content {
    padding: 20px;
}

.complexity {
    color: #2c3e50;
    font-weight: 500;
    background-color: #e9ecef;
    padding: 4px 8px;
    border-radius: 4px;
    font-size: 0.9em;
}

.advantages, .disadvantages {
    margin: 15px 0;
    padding: 15px;
    border-radius: 6px;
}

.advantages {
    background-color: #f1f8f1;
    border-left: 4px solid #28a745;
}

.disadvantages {
    background-color: #fdf7f7;
    border-left: 4px solid #dc3545;
}

summary {
    list-style: none;
}

summary::-webkit-details-marker {
    display: none;
}

details {
    margin-bottom: 10px;
}

.arrow {
    transition: transform 0.3s ease;
}

details[open] .arrow {
    transform: rotate(180deg);
}
</style>

# Search Algorithms Comparison

<div class="algorithm">
    <details>
        <summary class="algorithm-header">
            Linear Search
            <span class="arrow">▼</span>
        </summary>
        <div class="algorithm-content">
            <div class="complexity-section">
                <span class="complexity">Time Complexity: O(n)</span>
                <span class="complexity">Space Complexity: O(1)</span>
            </div>
            
            <div class="advantages">
                <h3>Advantages:</h3>
                <ul>
                    <li>Simple and easy to implement</li>
                    <li>Works on unsorted arrays</li>
                    <li>Good for small datasets</li>
                    <li>No preprocessing required</li>
                </ul>
            </div>

            <div class="disadvantages">
                <h3>Disadvantages:</h3>
                <ul>
                    <li>Slow for large datasets</li>
                    <li>Not efficient compared to other search algorithms</li>
                    <li>Requires traversing entire array in worst case</li>
                </ul>
            </div>
        </div>
    </details>
</div>

<div class="algorithm">
    <details>
        <summary class="algorithm-header">
            Binary Search
            <span class="arrow">▼</span>
        </summary>
        <div class="algorithm-content">
            <div class="complexity-section">
                <span class="complexity">Time Complexity: O(log n)</span>
                <span class="complexity">Space Complexity: O(1) iterative, O(log n) recursive</span>
            </div>
            
            <div class="advantages">
                <h3>Advantages:</h3>
                <ul>
                    <li>Very efficient for large datasets</li>
                    <li>Fast search process</li>
                    <li>Reliable and predictable performance</li>
                </ul>
            </div>

            <div class="disadvantages">
                <h3>Disadvantages:</h3>
                <ul>
                    <li>Array must be sorted</li>
                    <li>Only works on ordered collections</li>
                    <li>Requires random access to elements</li>
                </ul>
            </div>
        </div>
    </details>
</div>

<div class="algorithm">
    <details>
        <summary class="algorithm-header">
            Interpolation Search
            <span class="arrow">▼</span>
        </summary>
        <div class="algorithm-content">
            <div class="complexity-section">
                <span class="complexity">Time Complexity: 
                    - Average case: O(log log n)
                    - Worst case: O(n)</span>
                <span class="complexity">Space Complexity: O(1)</span>
            </div>
            
            <div class="advantages">
                <h3>Advantages:</h3>
                <ul>
                    <li>Better than binary search for uniformly distributed data</li>
                    <li>Very efficient for sorted arrays</li>
                    <li>Works well when elements are distributed uniformly</li>
                </ul>
            </div>

            <div class="disadvantages">
                <h3>Disadvantages:</h3>
                <ul>
                    <li>Poor performance for non-uniform distributions</li>
                    <li>Array must be sorted</li>
                    <li>More complex implementation than binary search</li>
                </ul>
            </div>
        </div>
    </details>
</div>

<div class="algorithm">
    <details>
        <summary class="algorithm-header">
            Exponential Search
            <span class="arrow">▼</span>
        </summary>
        <div class="algorithm-content">
            <div class="complexity-section">
                <span class="complexity">Time Complexity: O(log n)</span>
                <span class="complexity">Space Complexity: O(1)</span>
            </div>
            
            <div class="advantages">
                <h3>Advantages:</h3>
                <ul>
                    <li>Works well for unbounded/infinite arrays</li>
                    <li>Useful for searching in bounded arrays</li>
                    <li>More efficient than binary search for values closer to first element</li>
                </ul>
            </div>

            <div class="disadvantages">
                <h3>Disadvantages:</h3>
                <ul>
                    <li>Array must be sorted</li>
                    <li>Additional overhead compared to binary search</li>
                    <li>Not suitable for small datasets</li>
                </ul>
            </div>
        </div>
    </details>
</div>

<script>
document.querySelectorAll('details').forEach(detail => {
    detail.addEventListener('toggle', e => {
        if (detail.open) {
            detail.scrollIntoView({ behavior: 'smooth', block: 'start' });
        }
    });
});
</script>

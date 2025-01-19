# 🔗 Linked List Data Structures Guide

## 📑 Table of Contents
- [Singly Linked List](#-singly-linked-list)
- [Circular Linked List](#-circular-linked-list)
- [Doubly Linked List](#-doubly-linked-list)

---

## 📝 Singly Linked List
### ⚡ Time Complexity
| Operation | Average Case | Worst Case | Space |
|-----------|-------------|------------|-------|
| Insert (front) | O(1) | O(1) | O(1) |
| Insert (end) | O(n) | O(n) | O(1) |
| Insert (middle) | O(n) | O(n) | O(1) |
| Delete (front) | O(1) | O(1) | O(1) |
| Delete (end) | O(n) | O(n) | O(1) |
| Search | O(n) | O(n) | O(1) |
| Access | O(n) | O(n) | O(1) |

### ✅ Advantages
```plaintext
1. Dynamic size
2. Easy insertion at front
3. Efficient memory utilization
4. No pre-allocation needed
5. Easy implementation
```

### ❌ Disadvantages
```plaintext
1. No random access
2. Extra memory for pointers
3. Not cache friendly
4. Reverse traversing not possible
5. No direct access to previous nodes
```

### 🎯 Best Use Cases
- Implementation of stacks and queues
- Dynamic memory allocation
- Music playlist management
- Undo functionality in software
- Symbol table management in compilers

---

## 🔄 Circular Linked List
### ⚡ Time Complexity
| Operation | Average Case | Worst Case | Space |
|-----------|-------------|------------|-------|
| Insert (front) | O(1) | O(1) | O(1) |
| Insert (end) | O(1)* | O(1)* | O(1) |
| Insert (middle) | O(n) | O(n) | O(1) |
| Delete (front) | O(1) | O(1) | O(1) |
| Delete (end) | O(n) | O(n) | O(1) |
| Search | O(n) | O(n) | O(1) |
| Access | O(n) | O(n) | O(1) |
*With tail pointer

### ✅ Advantages
```plaintext
1. Constant time insertion at both ends (with tail)
2. No null checking required
3. Circular nature useful for round-robin
4. Better memory utilization
5. Continuous loop operations possible
```

### ❌ Disadvantages
```plaintext
1. Complex implementation
2. Harder to detect end of list
3. Risk of infinite loops
4. More complex deletion
5. Extra care needed in traversal
```

### 🎯 Best Use Cases
- Round-robin scheduling
- Circular buffers
- Game turn management
- Multiplayer systems
- CPU scheduling

---

## 🔀 Doubly Linked List
### ⚡ Time Complexity
| Operation | Average Case | Worst Case | Space |
|-----------|-------------|------------|-------|
| Insert (front) | O(1) | O(1) | O(1) |
| Insert (end) | O(1)* | O(1)* | O(1) |
| Insert (middle) | O(n) | O(n) | O(1) |
| Delete (front) | O(1) | O(1) | O(1) |
| Delete (end) | O(1)* | O(1)* | O(1) |
| Search | O(n) | O(n) | O(1) |
| Access | O(n) | O(n) | O(1) |
*With tail pointer

### ✅ Advantages
```plaintext
1. Bidirectional traversal
2. Easy deletion of nodes
3. Quick insertion/deletion at both ends
4. Reverse traversal possible
5. Easy implementation of LRU cache
```

### ❌ Disadvantages
```plaintext
1. Extra memory for prev pointer
2. Complex implementation
3. More memory per node
4. Complex pointer management
5. Risk of pointer corruption
```

### 🎯 Best Use Cases
- Browser history
- MRU/LRU cache implementation
- Undo/Redo operations
- Text editors
- Music players (prev/next)

---

## 💡 Implementation Tips

### 🛠️ Memory Management
```plaintext
1. Always free deleted nodes
2. Handle NULL pointers carefully
3. Check for memory leaks
4. Maintain head/tail properly
5. Handle edge cases
```

### 🔍 Common Pitfalls
```plaintext
1. Memory leaks
2. Dangling pointers
3. Lost node references
4. Infinite loops
5. Incorrect pointer updates
```

### 📊 Performance Comparison
| Aspect | Singly | Circular | Doubly |
|--------|---------|-----------|---------|
| Memory | Low | Medium | High |
| Complexity | Simple | Medium | Complex |
| Flexibility | Limited | Medium | High |
| Traversal | Forward | Circular | Both |
| Implementation | Easy | Medium | Hard |

## 📱 Visual Representation
```plaintext
Singly:    A → B → C → NULL
Circular:  A → B → C ↩
Doubly:    NULL ← A ⟷ B ⟷ C → NULL
```

## 📚 Additional Resources
- [Linked List Visualization](https://visualgo.net/en/list)
- [GeeksforGeeks Linked Lists](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Practice Problems](https://leetcode.com/tag/linked-list/)

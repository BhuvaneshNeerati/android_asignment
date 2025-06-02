# Android Assignment Set 1 Solutions

This repository contains solutions to selected problems from Android Assignment Set 1.

---

## Q1: Least Recently Used (LRU) Cache

### Problem Statement  
Design and implement an LRU Cache with fixed capacity. When the cache exceeds this capacity, it must evict the least recently used item to make space.

### Operations  
- get(key): Return the value of the key if it exists, otherwise return -1.  
- put(key, value): Insert or update the value. If cache is full, remove the least recently used item before inserting.

### Constraints  
- Capacity: 1 <= capacity <= 3000  
- Keys and values: 0 <= key, value <= 10^4  
- Maximum operations: 10^5  
- Time complexity: O(1) per operation

### Approach  
- Use a doubly linked list to maintain order of usage with most recently used items at the front.  
- Use an unordered_map for O(1) key to node lookup.  
- On get, move the accessed node to the front.  
- On put, update existing node or add a new node at the front, evicting the tail node if capacity is exceeded.

### Code File  
LRUCache.cpp

### Example  
cpp
LRUCache lru(2);
lru.put(1, 1);
lru.put(2, 2);
cout << lru.get(1) << endl;  // Outputs 1
lru.put(3, 3);               // Evicts key 2
cout << lru.get(2) << endl;  // Outputs -1
lru.put(4, 4);
cout << lru.get(1) << endl;  // Outputs -1
cout << lru.get(3) << endl;  // Outputs 3
cout << lru.get(4) << endl;  // Outputs 4

---

# Q2: Custom HashMap (Without Using Built-in Hash Libraries)

## Problem Statement  
Implement a simplified HashMap without using built-in hash table libraries.

## Operations  
- `put(key, value)`: Insert or update the value by key.  
- `get(key)`: Return value by key; return -1 if not found.  
- `remove(key)`: Remove the key from the map.

## Constraints  
- Keys and values: 0 <= key, value <= 10^6  
- Keys are unique  
- Maximum operations: 10^5  
- Average time complexity: O(1)

## Approach  
- Use separate chaining for collision resolution with linked lists.  
- Hash function: `key % SIZE` where SIZE is a prime number (10007).  
- Each bucket stores a linked list of nodes.  
- On `put`, update existing node or insert new node at the head of the bucket list.  
- On `get` and `remove`, traverse the linked list in the corresponding bucket.

## Code File  
`HashMap.cpp`

## Example
cpp
MyHashMap obj;
obj.put(1, 10);
obj.put(2, 20);
cout << obj.get(1) << endl;  // Outputs 10
cout << obj.get(3) << endl;  // Outputs -1
obj.put(2, 30);
cout << obj.get(2) << endl;  // Outputs 30
obj.remove(2);
cout << obj.get(2) << endl;  // Outputs -1


## Compilation and Running Instructions

Use g++ to compile and run the programs:

bash
g++ LRUCache.cpp -o lru_cache
./lru_cache

g++ HashMap.cpp -o hashmap
./hashmap
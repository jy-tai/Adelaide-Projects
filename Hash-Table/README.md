# Hash Table Implementation with Specific Hash Function

## Problem Description
This program implements a specific hash table that stores lowercase English words as keys. The hash function is based on the last character of the word. The hash table has exactly 26 slots corresponding to each letter of the English alphabet from 'a' to 'z'.

### Hash Table Characteristics
- **Keys**: Lowercase English words (e.g., "apple", "pear"). The length of a key is at most 10 characters.
- **Hash Function**: The hash value of a key is determined by its last character. For example, the hash value of "apple" is 'e', and the hash value of "pear" is 'r'.
- **Slot statuses**:
  - **Never Used**: The slot has never been used. The table starts with 26 of these slots
  - **Tombstone**: The slot previously held a key but it has been deleted.
  - **Occupied**: The slot currently holds a key.

### Operations

1. **Insertion**: Adds a key to the hash table if it does not already exist.
2. **Deletion**: Removes a key from the hash table if it exists.
3. **Search**: Finds a key in the hash table or determines that it is not present.

### Examples

1. **Input**: `Aaaa Accc Abbb`
   **Output**: `aaa ccc bbb`
2. **Input**: `Abba Aaaa Acca`
   **Output**: `bba aaa cca`

3. **Input**: `Abba Aaaa Acca Daaa`
   **Output**: `bba cca`
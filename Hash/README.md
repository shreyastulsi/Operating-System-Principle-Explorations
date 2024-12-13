# Hash Hash Hash
Shreyas Tulsi - 706157430
This coding assignment focuses on different hash table implementations: specifically, one serial hash table implementation and two concurrent implementations, each using different locking strategies implemented with Mutexes.
## Building
```shell
make
```

## Running
```shell
Format: ./hash-table-tester - t [number of threads] -s [number of hashes to add per thread]

Example
./hash-table-tester -t 8 -s 50000
Generation: 364,324 usec
Hash Table base: 2,694,524 usec 
Hash Table v1: 3,425,965 usec
Hash Table v2: 3,393,935 usec

```

## First Implementation

Here's a grammatically corrected version of the text:

There is a lock placed at the start of the hash_table_v1_add_entry function. In specific, the the mutex here is being added every time there is an entry within the hash_table entry, which is similar to the first implementation as well. Then, at the end of the function, after the list entry is updated, the lock is released. To prevent race conditions, the add entry function is blocked off to ensure that the operations are accessible for single-thread usage. It is also important to note that the hash_table_v1_destroy function was used to ensure proper removal of memory.


### Performance
```shell
./hash-table-tester -t 8 -s 50000
Generation: 364,324 usec
Hash Table base: 2,694,524 usec 
Hash Table v1: 3,425,965 usec
```
Version 1 is a little slower than the base version, the reason for this is the overhead that is caused by the threads having to consistently wait on the other threads, as the inheriten structure of the locking mechanism prevents for more than execution of one thread at a time.

## Second Implementation
The hash_table_v2_add_entry function secures the corresponding bucket with a mutex lock, verifies whether a key already exists, updates its value if it does, or adds a new list entry if it does not, before unlocking the mutex. The hash_table_v2_get_value function retrieves the value associated with a given key, ensuring the key is present. The hash_table_v2_contains function checks and returns whether a key exists in the table. Finally, the hash_table_v2_destroy function cleans the hash table by freeing all list entries in each bucket, destroying the mutexes, and then freeing the hash table structure itself. The use of multiple mutexes to block off the sections, helps handle race conditions in a better manner.

### Performance
```shell
./hash-table-tester -t 8 -s 50000
Generation: 364,324 usec
Hash Table base: 2,694,524 usec 
Hash Table v1: 3,425,965 usec
Hash Table v2: 3,393,935 usec
```

Version two is faster than version one due to its efficiency in handling entries. Specifically, the first strategy required locking each entry in the table, adding it, and then engaging in the process of unlocking and deleting them. However, in this solution, if two resources need to use different buckets, we don't need to lock resources. There is no additional traffic, resulting in a more efficient solution.


## Cleaning up
```shell
make clean
```

# sigil — Daily TODO

## How to use this file
Every morning: write today's tasks.
Every evening: check what you finished. Commit everything.
Never delete old entries — they become your progress log.

---

## Day 1 — April 23, 2026

### Learn (6 hours)
- [x] Install GCC, make, valgrind, gdb, git on Arch
- [x] Read "Learn C the Hard Way" Exercise 1-3
- [x] Understand: variables, types, printf, compilation
- [x] Read: what is a pointer (just read, don't code yet)

### Build (4 hours)
- [x] Verify all tools installed: gcc --version, git --version
- [x] Create folder structure: core/, src/, contracts/, tests/, docs/
- [x] Write core/pqc_rand.c skeleton (just the function signature and a comment)
- [x] Commit: git add . && git commit -m "day 1: tools installed, hello world"

### Theory (2 hours — PDF 03)
- [x] Day 1 theory: integers, primes, why they matter for crypto
- [x] Exercise: Sieve of Eratosthenes in Python
-  Resource: Khan Academy Number Theory

### LeetCode (1 hour)
- [x] LC #1929 — Concatenation of Array
- [x] Read about Big O notation

---

## Day 2 — April 24, 2026

*Morning — uint8_t, Pointers, Stack vs Heap (3 hours)
[x]Read first:

 Learn C the Hard Way Exercise 6, 7, 8
 cppreference.com/w/c/types/integer — stdint.h section only

[x]Type and compile:

 Type the uint8_t + pointer exercise by hand
 Compile: gcc -Wall -Wextra -o day2 day2.c
 Run it and read every output line

[x]Break it deliberately:

 Try buf[32] out of bounds — read the output
 Print sizeof uint8_t, int, uint32_t — compare
 Try uint8_t x = 255; x = x + 1 — see it wrap to 0

Stack vs Heap:

 Read craftinginterpreters.com first section on memory
 Type the malloc/free example by hand
 Compile with valgrind — verify zero leaks


[x]Mid Morning — Write Real sigil Code (3 hours)
core/pqc_rand.h:

 Create the file
 Write the header guard #ifndef SIGIL_PQC_RAND_H
 Write the function declaration with comment
 Add spec reference comment — man 4 urandom

core/pqc_rand.c:

[x]Create the file
 Write copyright and spec reference comment at top
 Write null pointer check
 Write fopen /dev/urandom
 Write fread
 Write fclose
 Write bytes_read verification
 Return 0 on success

tests/test_pqc_rand.c:

[x]Create tests/ folder
 Write TEST macro
 Write Test 1 — returns 0 on success
 Write Test 2 — output not all zeros
 Write Test 3 — two calls differ
 Write Test 4 — null returns -1
 Write Test 5 — zero length returns -1
 Compile: gcc -Wall -Wextra -o test_rand tests/test_pqc_rand.c core/pqc_rand.c
 Run valgrind — zero leaks required
 All 5 tests pass


Afternoon — LeetCode + DSA (2 hours)

[N]LC #136 Single Number — solve it
 Read: how arrays are laid out in memory as contiguous bytes
 Connect: uint8_t buf[32] = 32 bytes side by side in memory


[x]Evening — Crypto Theory PDF Day 2 (2 hours)

 Read: modular arithmetic and clock arithmetic
 Understand: 17 mod 5 = 2
 Exercise: compute 2^100 mod 997 by hand first
 Verify with Python:

bashpython3 -c "print(pow(2, 100, 997))"

 Read: Mathematical Cryptography Ch 1.1-1.2


Night — Commit (1 hour)

 git add .
 git commit -m "day 2: uint8_t pointers stack heap pqc_rand.c 5 tests passing"
 git push

## DAY 3
LEARN (4 hours):

Bitwise operators: &, |, ^, ~, <<, >>
Understand each at bit level with paper examples first

BUILD (3 hours):

Implement core/xor_cipher.c — encrypts any file using XOR with a key
Command: sigil xor --in file --key key.bin --out file.enc

LEETCODE:

LC #191 Number of 1 Bits
DSA: Stack vs Heap

Crypto Theory — 

GCD and Extended Euclidean Algorithm
How modular inverses are computed in RSA and ECDSA
Exercise: Implement Extended Euclidean from scratch in Python
Find modular inverse of 17 mod 3120
Resource: Wikipedia Extended Euclidean — trace through the example



---

## WEEK 1 GOAL
By Day 7: v0.0.1 tagged. Repo skeleton complete. pqc_rand.c working.
XOR cipher working. First benchmark in BENCHMARKS.md. CI passing.

---

## RULES
1. Write tasks BEFORE starting the day — not during
2. Be specific — "implement sha256_pad()" not "work on SHA-256"
3. If a task takes more than 2 hours — break it into smaller tasks
4. End of day: commit everything, even broken code
5. Broken code committed is better than perfect code not committed.

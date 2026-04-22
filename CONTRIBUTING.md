# Contributing to sigil

Thank you for your interest in contributing to sigil.

sigil is a security-critical cryptographic library. Contributions are
welcome but held to a high standard — every line of crypto code must
be traceable to its primary specification.

---

## Before You Contribute

1. Read the [README](README.md) to understand what sigil does
2. Read the [SECURITY](SECURITY.md) policy
3. Open an issue before starting work on anything significant
4. For bug fixes: reference the specification that defines correct behavior

---

## Contributor License Agreement

By submitting a pull request to sigil, you agree that:

1. You wrote the code yourself or have the right to contribute it
2. You grant [Gaurish Bamrari] the right to include your contribution
   under both GPL v3 and the sigil Commercial License
3. You retain copyright of your contribution
4. You understand this is standard practice for dual-licensed projects

This is required to maintain the dual-license model that funds
sigil's long-term maintenance.

---

## How to Contribute

### Small fixes (typos, docs, test vectors)
1. Fork the repo
2. Make your change
3. Open a PR with a clear description

### New features or significant changes
1. Open an issue first — describe what you want to build
2. Wait for feedback before writing code
3. Fork and implement
4. Open a PR referencing the issue

---

## Code Standards

### C code
- Every function must have a comment referencing its specification
- Example: `/* SHA-256 padding — FIPS 180-4 Section 5.1.1 */`
- Zero heap allocations in crypto hot paths — stack only
- Must pass valgrind with zero errors: `valgrind --leak-check=full`
- Must compile with: `gcc -Wall -Wextra -Werror -O2`

### Rust code
- Run `cargo clippy` — zero warnings
- Run `cargo fmt` before submitting
- Every public function must have a doc comment with an example

### Solidity code
- Run Slither before submitting: `slither contracts/`
- All state-changing functions must emit events
- Follow checks-effects-interactions pattern strictly

---

## Test Requirements

Every contribution must include tests:

- C: test vectors from the primary specification
- Rust: unit tests + at least one integration test
- Solidity: Hardhat tests covering the happy path and edge cases

---

## What We Will NOT Accept

- Code that uses external crypto libraries in the C core
- Heap allocations in crypto hot paths
- Code without specification references
- Code that fails valgrind
- Untested code

---

## Questions

Open a GitHub Discussion or [gaurishb.dev@gmail.com] 

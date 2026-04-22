# sigil Benchmarks

All benchmarks 
Run on:Hardware: Lenovo IdeaPad, AMD Ryzen 7 5700U with Radeon Graphics

RAM:  16 GB  (13.2 GB usable)

OS: Arch Linux 6.19.11-arch1-1

Compiler: gcc [gcc (GCC) 15.2.1 20260209]
- Date: April 22, 2026

Benchmarks updated every week as new primitives are implemented.

---

## Week 1 — XOR Cipher

| Operation | sigil C | Python | Ratio |
|-----------|---------|--------|-------|
| XOR 1MB   | TBD     | TBD    | TBD   |

---

## Week 2 — SHA-256 (coming)

| Operation     | sigil C | Wasm  | Python hashlib | OpenSSL |
|---------------|---------|-------|----------------|---------|
| 1k hashes     | TBD     | TBD   | TBD            | TBD     |
| 100k hashes   | TBD     | TBD   | TBD            | TBD     |
| Throughput MB/s | TBD   | TBD   | TBD            | TBD     |

---

## Week 5 — WOTS+ (coming)

| Operation       | sigil | SPHINCS+ ref | Ratio |
|-----------------|-------|--------------|-------|
| keygen          | TBD   | TBD          | TBD   |
| sign            | TBD   | TBD          | TBD   |
| verify          | TBD   | TBD          | TBD   |
| sigs/second     | TBD   | TBD          | TBD   |

---

## Week 6 — XMSS-lite vs ECDSA (coming)

| Operation | sigil XMSS | OpenSSL ECDSA | Ratio |
|-----------|------------|---------------|-------|
| keygen    | TBD        | TBD           | TBD   |
| sign      | TBD        | TBD           | TBD   |
| verify    | TBD        | TBD           | TBD   |

---

## Week 8 — sigil migrate (coming)

| Operation        | Time  | Notes |
|------------------|-------|-------|
| proof generation | TBD   | ECDSA key → ML-DSA keypair + proof |
| on-chain verify  | TBD   | Gas cost in ETH |

---

## Methodology

- All C benchmarks: average of 1000 runs using `clock_gettime(CLOCK_MONOTONIC)`
- Rust benchmarks: criterion crate with statistical analysis
- No warm-up runs excluded — cold start included
- Machine under normal load — not isolated

Results are honest. If sigil is slower than OpenSSL in some operations,
that is noted. The goal is correctness and auditability, not raw speed.

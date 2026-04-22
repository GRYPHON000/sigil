# sigil

> Quantum-safe signing and key migration for blockchain developers.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![License: Commercial](https://img.shields.io/badge/License-Commercial-orange.svg)](LICENSE-COMMERCIAL)
[![Build Status](https://img.shields.io/github/actions/workflow/status/GRYPHON000/sigil/ci.yml)](https://github.com/GRYPHON000/sigil/actions)
[![Crates.io](https://img.shields.io/crates/v/sigil.svg)](https://crates.io/crates/sigil)

---

## The Problem

Every blockchain wallet uses ECDSA signatures. Shor's algorithm running on a sufficiently
large quantum computer breaks ECDSA in polynomial time. Google's March 2026 paper showed
Bitcoin keys are breakable with under 500,000 physical qubits — 20x fewer than previous
estimates.

NIST finalized post-quantum cryptographic standards in 2024 (FIPS 203, 204, 205).

**The migration problem nobody has solved cleanly:**
How does an existing blockchain user migrate from ECDSA to a quantum-safe key without
losing assets, without a hard fork, and with an on-chain verifiable proof?

sigil solves this.

---

## What sigil Does

```bash
# Generate a quantum-safe keypair
sigil keygen --algo ml-dsa --out keypair/

# Sign a transaction
sigil sign --key keypair/priv.key --in tx.json --out tx.sig

# Verify a signature
sigil verify --key keypair/pub.key --in tx.json --sig tx.sig

# Migrate from ECDSA to ML-DSA — the command that didn't exist
sigil migrate --from ecdsa.key --chain ethereum --out migration_proof.json

# Benchmark all algorithms
sigil bench
```

The `migrate` command is the core differentiator:
1. Reads your existing ECDSA private key
2. Generates a corresponding ML-DSA keypair deterministically
3. Outputs a migration proof — the new PQC public key signed with the old ECDSA key
4. `SigilMigration.sol` verifies this proof on-chain and records the key mapping permanently
5. Future transactions use the PQC key. The old key can be retired.

---

## Architecture

```
sigil/
├── core/                  # Pure C — zero dependency crypto engine
│   ├── sha256.c/h         # SHA-256 from FIPS 180-4
│   ├── hmac.c/h           # HMAC-SHA256 from RFC 2104
│   ├── merkle.c/h         # Merkle tree with proof generation
│   ├── wots.c/h           # WOTS+ from Hülsing 2017
│   ├── xmss.c/h           # XMSS-lite from RFC 8391
│   ├── sigil_sign.c/h     # Unified signing API (crypto agility)
│   ├── sigil_migrate.c/h  # Migration proof generation
│   └── pqc_rand.c/h       # Cryptographic random from /dev/urandom
├── src/                   # Rust CLI layer
│   ├── main.rs
│   └── commands/          # keygen · sign · verify · migrate · bench
├── contracts/             # Solidity on-chain verifier
│   ├── SigilVerifier.sol  # Verifies PQC signatures on-chain
│   ├── SigilMigration.sol # Records ECDSA → PQC key migrations
│   └── SigilWallet.sol    # ERC-4337 quantum-safe wallet
├── ffi/                   # Rust bindings to C core
├── scripts/               # ethers.js deployment scripts
├── tests/                 # Test vectors and integration tests
├── benchmarks/            # criterion benchmarks
└── docs/                  # Architecture diagrams, API reference
```

---

## Why Zero Dependencies

The C core has zero external dependencies. Every cryptographic primitive is implemented
from its primary specification:

| Primitive | Specification |
|-----------|---------------|
| SHA-256   | NIST FIPS 180-4 |
| HMAC      | RFC 2104 |
| WOTS+     | Hülsing 2017 (eprint.iacr.org/2017/965) |
| XMSS-lite | RFC 8391 |
| ML-DSA    | NIST FIPS 204 |

Zero dependencies means zero supply chain attack surface. You can audit every line.

---

## Crypto Agility

sigil builds algorithm agility in from day one — one function, any NIST PQC algorithm:

```c
sigil_sign(key, msg, SIGIL_ML_DSA);   // FIPS 204
sigil_sign(key, msg, SIGIL_SLH_DSA);  // FIPS 205
sigil_sign(key, msg, SIGIL_XMSS);     // RFC 8391
```

When NIST adds new algorithms, sigil supports them without breaking existing users.

---

## Benchmarks

*Updated weekly.

| Operation | sigil | OpenSSL ECDSA | Ratio |
|-----------|-------|---------------|-------|
| keygen    | TBD   | TBD           | TBD   |
| sign      | TBD   | TBD           | TBD   |
| verify    | TBD   | TBD           | TBD   |
| migrate   | TBD   | N/A           | N/A   |

---

## Security

sigil is under active development. Do not use in production until v1.0.0.

Security issues: see [SECURITY.md](SECURITY.md)
To report a vulnerability: 
email:gaurishb.dev@gmail.com or open a GitHub Security Advisory.

---


## License

sigil is dual licensed:

- **Open source use**: [GPL v3](LICENSE) — free for open source projects
- **Commercial use**: [Commercial License](LICENSE-COMMERCIAL) — required for proprietary products

For commercial licensing: gaurishb.dev@gmail.com

---

## Status

| Week | Milestone | Status |
|------|-----------|--------|
| 1    | v0.0.1 — Repo skeleton, XOR cipher, random | 🔄 In Progress |
| 2    | v0.0.2 — SHA-256, all NIST vectors | ⏳ Planned |
| 3    | v0.0.3 — Merkle tree, proofs | ⏳ Planned |
| 4    | v0.0.4 — Wasm bridge, CLI hash | ⏳ Planned |
| 5    | v0.1.0 — WOTS+ complete | ⏳ Planned |
| 6    | v0.2.0 — XMSS-lite complete | ⏳ Planned |
| 7    | v0.3.0 — Solidity verifier on Sepolia | ⏳ Planned |
| 8    | v0.4.0 — sigil migrate + demo video | ⏳ Planned |
| 9    | v0.5.0 — Rust CLI complete | ⏳ Planned |
| 10   | v1.0.0 — Published on crates.io | ⏳ Planned |

---

*Started: April 22, 2026. Building in public.*

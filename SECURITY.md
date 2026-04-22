# Security Policy

## Supported Versions

| Version | Supported |
|---------|-----------|
| 1.x.x   | ✅ Yes |
| 0.x.x   | ⚠️ Development only — not for production use |

---

## Reporting a Vulnerability

**Do not open a public GitHub issue for security vulnerabilities.**

### Option 1 — GitHub Security Advisory (Preferred)
1. Go to the [Security tab](https://github.com/GRYPHON000/sigil/security)
2. Click "Report a vulnerability"
3. Fill in the details

### Option 2 — MAIL
Send to: gaurishb.dev@gmail.com
Subject: `[SECURITY] sigil — brief description`

Include:
- Description of the vulnerability
- Steps to reproduce
- Potential impact
- Suggested fix if you have one

---

## Response Timeline

| Action | Timeline |
|--------|----------|
| Initial acknowledgment | Within 48 hours |
| Severity assessment | Within 5 days |
| Fix development | Depends on severity |
| Public disclosure | After fix is released |

---

## Threat Model

sigil is a cryptographic library. The threat model covers:

**In scope:**
- Incorrect cryptographic implementations
- Side-channel vulnerabilities in C core
- Memory safety issues (buffer overflows, use-after-free)
- Smart contract vulnerabilities in SigilVerifier.sol and SigilMigration.sol
- Key material exposure or leakage
- Migration proof forgery

**Out of scope:**
- Vulnerabilities in dependencies (report to them directly)
- Issues requiring physical access to the machine
- Social engineering attacks

---

## Security Design Principles

1. **Zero dependencies in crypto core** — no supply chain attack surface
2. **Stack-only allocation in hot paths** — no heap corruption in crypto operations
3. **Constant-time operations** — resistance to timing side channels
4. **Spec-first implementation** — every function traced to its primary specification
5. **Valgrind clean** — zero memory leaks in all code paths

---

## Known Limitations

- sigil is under active development. Do not use v0.x.x in production.
- The XMSS-lite implementation is stateful — state file corruption can cause
  security failures. Back up your state file.
- Migration proofs are permanent and on-chain. Verify carefully before submitting.

---

## Acknowledgments

Security researchers who responsibly disclose vulnerabilities will be
credited here (with their permission).

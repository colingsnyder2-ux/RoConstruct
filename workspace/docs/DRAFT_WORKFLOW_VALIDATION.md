# Native draft workflow validation

Validated 2026-11-04 using a fresh public Worker download.

- Public ZIP SHA-256 and every workspace-manifest file hash verified.
- Packaged CLI initializes without a fork, branch or Git commit.
- Automatic watcher uploads this newly created documentation file over HTTPS.
- Durable upload receipts and idempotent retry are checked before owner review.
- Owner integration uses explicit paths, isolated index and exact-tree preservation checks.
- Focused workflow regressions: 40 passing tests across transport, drafts and findings publication.
- Native source, active executable selection and server credit are unchanged by this validation.

Findings main/workspace is authoritative. Native updates commit directly there; packaging never reads an origin feature branch. Sparse advisory notes use leases as authority, with enforced cooldowns and two-hour expiry.

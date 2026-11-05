# Auto worker reliability, 2026-10-10

Client: August 19, 2007 (`2007-08`), registered VS2005 build 50727,
`/O2 /GS /EHsc /MD`. Model: `deepseek:deepseek-flash`, direct generation,
thinking disabled, two rounds, seed 42, four concurrent calls. Source hidden;
normal source hints allowed by each arm. No live submissions.

Frozen manifest: `benchmarks/worker-auto-reliable-2007-08.json`: 24 functions,
eight each in 1–64, 65–128 and 129–512 byte buckets. Half discovery, half
holdout; distinct units within each bucket. Targets had catalog exact sources
but these were not provided as starting drafts. This tests regeneration, not new
discoveries. Two draws per arm, arm order reversed across repeats and splits.

## Rejected combined policy

Start every function at 2048 tokens, enable full hints on large functions,
and double Auto output after a token-limit finish up to 4096.

| Arm | Exact / 48 jobs | At least one compilation | Mean best score |
| --- | --- | --- | --- |
| Previous Auto | 18 | 45 | 68.90 |
| Combined candidate | 14 | 45 | 63.56 |

Discovery exact was 6/24 for both; holdout fell 12/24 -> 8/24.
Both arms had eight truncated generations, none flagged incomplete.
Rejected larger starting caps and full hints. This experiment cannot isolate
which change caused the regression. Cost estimate: $0.2280111, shared cap $1.50.
Report: `work/worker-auto-reliable-results-20261010/report.json`.

## Accepted narrower policy

Keep starting output cap 1024 for call-free functions <=64 bytes, otherwise
2048, and DeepSeek Auto's source-hint cutoff at 128 bytes. Double the cap only
after an actual token-limit finish, up to 4096 on an existing later round.
Do not add rounds. Explicit manual caps stay fixed. Shared provider budget
reservation covers enlarged output and conversation history.

| Split | Arm | Exact | At least one compilation | Mean best score |
| --- | --- | --- | --- | --- |
| Discovery, 24 jobs | Previous Auto | 6 | 21 | 65.46 |
| Discovery, 24 jobs | Adaptive | 6 | 24 | 67.17 |
| Holdout, 24 jobs | Previous Auto | 10 | 24 | 68.42 |
| Holdout, 24 jobs | Adaptive | 12 | 23 | 74.00 |
| Combined, 48 jobs | Previous Auto | 16 | 45 | 66.94 |
| Combined, 48 jobs | Adaptive | 18 | 47 | 70.58 |

Control had three token-limit finishes, adaptive five; none were flagged
incomplete. More output is not itself a guarantee of completion or exactness.
All 34 exact result files were independently recompiled and passed normal
code-plus-referenced-data `match.check_text` checks. Small sample and provider
sampling variation prevent strong causal or universal-best claims. The
holdout is address-held-out within this experiment, not unseen by all historical
research. Reusing this manifest after inspecting combined-policy results also
limits the independence of the narrower-policy confirmation.

Cost estimate: $0.1945299, shared cap $0.50. Report:
`work/worker-auto-adaptive-results-20261010/report.json`. Reproduce with
`benchmarks/worker_auto_reliable.py --adaptive-only`; the original control
modules are preserved under `work/worker-auto-reliable-20261010/`.
The initial combined-policy candidate was reverted, so reproducing its exact
arm requires restoring the described starting-cap/full-hint changes.

## Entry-point consistency

- CLI and terminal `auto` now mean the same preset as `automatic`; previously
  the alias kept different concurrency, token and cloud-routing defaults.
- Auto generation strategy chooses direct instead of structured for tiny
  DeepSeek functions. Earlier paired direct/structured pilot favored direct
  3/12 vs 2/12; current automatic presets already explicitly used direct.
- GUI Auto clears near-repair and extra diversity candidates, preserving
  explicit worker count, cloud consent, targets and spend limits.
- Regression tests cover token-limit growth, the 4096 ceiling, manual caps,
  alias consistency, live worker propagation and GUI preset isolation.

Validation: `python -m pytest tests -q`: 264 passed, one existing msilib
deprecation warning. `node tests/test_gui_frontend.js` passed. Unscoped pytest
collection hits a pre-existing standalone script that exits during import;
the supported `tests/` suite passes. No paid service calls from unit tests.

Total estimated DeepSeek spending across this improvement series: $0.659862
of the user's $3 total authorization. Estimates are telemetry-based, not invoices.

# Background matching search, October 9, 2026

Two detached Python jobs run from the repository. Both share a thread-safe
request/token/cost budget within their own process and save compiler-scored
best sources with client, address, flags, score, session and source hash.

| Run | Targets | Workers | Arms | Rounds | Cost ceiling | Token ceiling | Initial PID |
|---|---:|---:|---:|---:|---:|---:|---:|
| mass-300-20261009 | 300 fresh source-hidden solved holdouts | 32 | direct/structured, 3 repeats | 4 | $30 | 30 million | 31384 |
| mass-unsolved-600-20261009 | 600 never-attempted unsolved functions, 8–512 bytes | 16 | direct/structured, 2 repeats | 4 | $20 | 20 million | 5376 |

Each arm requests three independent candidates for hard functions, then a
compiler-feedback repair round. Easy functions use normal feedback rounds.
An exact match stops generation early. Thinking is disabled. Arm order
alternates by repeat. Sampling seeds are recorded and best-effort by provider.

Manifests are frozen in `work/mass-unseen-300-20261009.json` and
`work/mass-unsolved-600-20261009.json`; copies and fingerprints are recorded
under `work/mass-search/<run>/`. Per-arm summaries checkpoint after each arm;
candidate files checkpoint after each target. Stdout/stderr are in
`work/<run>.out.log` and `work/<run>.err.log`.

Maximum combined configuration is 4,200 target trials, 16,800 generation
rounds, $50 and 50 million tokens. Actual usage can be lower through exact
stops, budget limits or provider failure. Existing GUI worker runs separately
and is not included in these ceilings. These jobs save candidates locally;
they do not submit to the server or alter recovered sources.

Compare per-client/size exact and compile rates before changing worker defaults.
Holdout exacts measure recovery of already solved functions, not new matches.
Unsolved exacts require independent normal compiler/data verification before
promotion; partial scores are not matches.

The existing shared-MFC replay is still running separately. Its checkpoint
shows both improvements and regressions, so recipe adoption must be per-target,
not a blanket client configuration replacement.

Validation: candidate archival, generation-failure, duplicate-cache, refine
selection, worker-auto/runtime tests: 26 passed. Existing top-k benchmark
smoke: passed.

Goal remains active: jobs must finish, candidates must be verified, and worker
changes must be supported by the paired results.

First independent recompile checkpoint: six unsolved candidates returned 100
through `match.check_text`, including its normal data-reference check:
2007-03 `00646230`, `006cb460`; 2007-08 `0072d180`; 2010-06 `009cb4d0`;
2011-06 `00a18c00`; 2012-06 `008f9140`. Sources and diagnostics are recorded
in `work/mass-search/mass-unsolved-600-20261009/verified-exacts.json`.
They remain local candidates, not server submissions. Relocation-masked
100 is the repository's normal exact-match criterion, not a semantic proof.

Live aggregation checkpoint: completed 300-target arms contain 887 archived
trials across 299 targets; best-per-target selection yields 83 exact targets.
The unsolved run has 415 archived trials so far, with 34 exact best targets.
These counts will increase while both processes remain active. Aggregation is
performed by `benchmarks/aggregate_search.py`; it preserves arm winner and
source paths for later independent `match.check_text` verification.

Independent exact revalidation jobs wrote reports under
`work/mass-verified-300-20261009/` and `work/mass-verified-unsolved-20261009/`.
They rerun normal compiler/data checks and do not alter source or score
databases. A new verification pass (PID 30268) covers the newly completed
unsolved direct arm.

Verification completed: 82/82 archived 300-run winners and 39/39 archived
unsolved-run winners remained exact under independent compiler/data checks.
The later unsolved direct-arm revalidation completed 54/54 exact winners.
Latest 300-target aggregation has 1,221 trials and 85 best-target exacts;
independent revalidation completed 85/85 exact.

Direct repeat 3 and unsolved structured repeat hit their own cloud budgets,
so their partial rows are marked failures and excluded from quality comparison.
A fresh 300-target unseen manifest (`mass-unseen-300b-20261009.json`) now runs
as session `mass-300b-20261009` with a separate $10 / 10M-token cap (PID
26348), preventing budget exhaustion from contaminating new measurements.
That run hit HTTP 402 before generation, so its 300 failures are retained as
provider-state evidence only. Local fallback now runs 100 unseen targets with
`ollama:qwen2.5-coder:14b`, eight workers, two rounds (PID 13352).
Runner now skips cloud preflight for local models, removing unnecessary
provider calls before Ollama generation. Local providers now force one slot to
avoid overloading one Ollama model; `mass_search --limit N` supports bounded
smoke runs. Regression suite remains green.

Verified exact distribution by client (300-run / unsolved-run): 2007-03
12/11, 2007-08 9/1, 2008-06 10/5, 2009-06 14/7, 2009-12 11/7, 2010-06
10/6, 2011-06 9/6, 2012-06 10/11.

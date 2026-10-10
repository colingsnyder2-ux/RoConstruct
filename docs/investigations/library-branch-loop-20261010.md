# Branching from successful library configuration experiments

## Scope and acceptance

Continue the idea -> pilot -> selective/full scale loop without cloud requests.
Exclude 2009-12 and every current `TEMPLATE_FAMILIES` exemplar shape plus the
five open handoff leads. Read the other agent's registry only; do not invoke
or edit their recovery experiments. Preserve other workers' Git changes.

Each candidate must match through the size-indexed fingerprint matcher, including
strict executable-relocation coverage and referenced-data checks, then receive
`verified=true`, `score=100`, `improved=true` from the group server. Never submit
partials or change global client settings. Count unique client/address pairs.

## Completed pilots and scale decisions

| Branch | Pilot | Outcome / scale |
|---|---|---|
| Winning library sources on non-CXT and unnamed functions | 12 client/source cohorts, 6 exacts | Expand only the two winning forms: 18 total exacts |
| Single compiler-setting changes on winning library sources | 12 unique cohorts, 6 exacts | Expand only winning forms: 20 total exacts |
| Those new settings on non-CXT/unnamed functions | 12 cohorts, 1 exact | Park |
| Successful single-option hypotheses on other library files | 12 cohorts, 0 exacts | Park |
| Each receiving client's registered original compiler build | 12 cohorts, 0 exacts | Park; this does not disprove all alternate builds |
| Combine security cookies and C++ exceptions | 6 unique cohorts, 100 exacts | Exhausted this initial combination source form |
| Transfer that combination to other winning source files | 12 cohorts, 83 exacts | Full frozen pool running |
| Combined-setting winners on non-CXT/unnamed functions | 12 cohorts, 13 exacts | Full frozen pool finished: 75 exacts |

The important discovery is a **per-source/per-target** interaction between `/GS`
and `/EHsc`. Neither a blanket configuration change nor a universal ABI rule is
justified. Combined-source matches are independently checked against the baseline
library object before being attributed to the changed settings.

At a checkpoint during full expansion, this loop had 1,469 unique new server exacts
(combined-setting transfer: 298 cohorts, 1,255 exacts).
That checkpoint is historical; read current JSONL for live totals. Do not add the
other agent's recovery ledger or previous campaign totals to these counts.

Full scale requires at least 10 unique pilot exacts. Smaller pilots with at least
two exacts expand **only** their successful source forms across all allowed clients.
Zero/one-win pilots are parked. Pilot decisions use the fixed original pilot keys,
not additional wins found later during selective scale. Every no-win cohort and
compile error is retained; no fuzzy partial score is asserted by an exact-only sweep.

## Optimizations and validation

Precompute each client's eligible address pool once. Store target pools once per
manifest, instead of duplicating them for every source: the initial spillover
manifest compressed from about 138 MB to 1.6 MB without removing addresses.
Deduplicate client/source keys and remove new exacts from subsequent local pools.

Compile fully pinned library sources once and share objects across clients only
when compiler build, flags, language, library path and preprocessed source content
are identical. Content-keyed objects are written atomically. An independent
two-client replay compared 565 functions: function bytes, relocation lists, and
referenced data were all identical. Every accepted function still undergoes the
ordinary client-specific local and server checks.

Stage locks prevent duplicate workers. An early restart briefly duplicated one
compiler-setting cohort; both attempts remain logged and exact totals are deduped.
A manifest-path bug wrote the transfer plan over its parent plan. The transfer
plan was saved under its proper name, the parent was rebuilt from recorded pinned
sources/settings, and every accepted-match record remained intact. Regression
tests cover manifest ownership and plan deduplication.

## Next prepared iterations

`benchmarks.branch_loop` waits for current branch writers, then runs:

1. `late-spillover`: take all newly successful combined forms after the full sweep,
   testing only forms not already checked by the first combined spillover sweep.
2. `recipe-neighbor`: retain source path, compiler and successful flags; test
   neighboring installed shared-MFC/XTP recipes whose same-path file exists.
   No arbitrary offsets, new source layouts, or discovery downloads are proposed.
3. `numeric-settings`: test intrinsic enable/disable and fast floating-point code
   generation on successful combined library forms. Byte/data equality remains
   mandatory; approximate numeric equivalence never counts.

Each iteration freezes a new pool, runs its pilot, saves the outcome, and applies
the same conditional scale rule. On an execution error the queue stops with its
stage/log location. After these prepared branches finish, the state explicitly says
new hypotheses are needed; it does not re-run exhausted pilots endlessly.

Fresh-donor propagation/layout recovery waits for the existing sweeps **and** this
prepared loop, then loads live server sources. This captures newly accepted donors
instead of relying on older cached snapshots.

## Reproduction and records

```text
py -3.12 -m benchmarks.library_branches <stage> --pilot 12 --scale-if-wins
py -3.12 -m benchmarks.branch_loop
```

Artifacts: `work/library-branches-20261010/`, with manifests, per-cohort candidates,
server responses, errors, source/object hashes, timing, pilot decisions, cached
objects, cache-validation.json, loop-state.json and later-stage logs. No source or
layout claim is accepted from a hypothesis alone. Cloud spend for these branches: $0.

Validation checkpoint: 280 tests passed, one unrelated budget-persistence test
deselected because another worker raised its configured cap. Focused tests cover
flag isolation, combined settings, duplicate-stage locks, preservation of the parent
manifest, and duplicate-plan suppression. Existing unrelated edits are untouched.

# Native integration workflow V2 - implementation and audit

Updated 2026-10-29. All four workflow phases are implemented. The final fresh
current-profile audit passes and preserves every accepted native credit. The
server has been updated with publishing paused. Historical compiled-inventory
differences remain explicit; the old counts are not claimed as reproduced.

## Phase audit

| Phase | Implementation | Audit findings and corrections |
| --- | --- | --- |
| 1: fast feedback | Claim-private `--fast`, `--bytes`, `--full`; module compiler profiles; affected TUs; structured errors; saved source/compiler provenance. | Reject empty targets, stale ownership, stale generator and cross-claim workspaces. Separate baseline/candidate objects; handle duplicate source stems and shadowing headers. Protect actual accepted native bodies, not coincidental matches to unrelated targets. |
| 2: AI success | Full per-function source/assembly/declarations/callees/history; body-only deterministic adaptation; existing bounded compiler repair; explicit stronger-model escalation. | No network request for free adaptation prepass. Reject invented types, raw offset views, ambiguous methods and modern syntax. Record actual model and measured tokens, including rejected responses. |
| 3: automation | Learned finalized-job ranking with dependency/ABI heuristics; easy/balanced/large selection; continuous integrator; persistent no-improvement budgets; G3D/Ogre eligibility guards. | Claim classes before paid generation, renew leases, release unused claims. Atomic acceptance rejects gains belonging to another contributor's active claim. Budget applies within a run as well as across runs. Changed relevant inputs reopen blocked targets. |
| 4: performance | Historical compiler cache reuse; incremental dependencies; collision-safe artifacts; compatible bulk checks/claims; existing batched authoritative verification; real local/server metrics. | No fabricated throughput or token ratios. Full linked verification, runtime, ABI probes and no-loss checks remain mandatory. Lightweight symbol-witness sidecars avoid reparsing every linked function twice. |

## Commands

```text
roc integrate next --mode balanced
roc integrate next --revisit-parked
roc integrate context --claim ID --address 00512340
roc integrate check --claim ID --fast
roc integrate check --claim ID --bytes
roc integrate check --claim ID --full
roc integrate check --batch batch.json --bytes
roc integrate check --all --fast
roc integrate adapt --claim ID --address 00512340 --file App/example/File.cpp --method Example::method
roc integrate metrics --hours 24
roc integrate audit
roc integrator --mode easy --model SMALL --escalation-model STRONG --escalate-after 2 --max-no-improvement 3
```

Batch JSON contains `{"claims":["ID1","ID2"]}`. Bulk local checks require the same
owner and accepted baseline/generator. Each original claim retains its own receipt.
`adapt` writes edits, SEARCH/REPLACE blocks, a diff and a next verification command;
it never grants credit or silently stages unverified edits. Unsupported methods
remain manual ABI work.

Manual `integrate submit` performs a local byte preflight by default.
`--no-local-check` skips that contributor convenience only; authoritative server
gates remain required. Proven local mismatches stop submission; unresolved local
symbol mapping can defer to the linked verifier. Updated clients require the
server's advertised native reference gate before new submissions or apply-mode
model work. Restart the configured verifier with updated code before rollout.

### Fast claim triage

Class labels are mining hints, not source ownership. Before editing a generator,
read every claimed target's library/symbol line and locate the matching native
translation unit. Park a claim immediately when its targets mix unrelated
libraries (for example `Script.cpp`, G3D/STL helpers, reflection glue, or an
older GUI/physics layout) or when the native tree only has a declaration. Do not
submit a partial include solely because one constructor or wrapper is exact:
`--bytes` remains all-target and the linked no-loss gate rejects a module that
does not add complete, stable ownership.

For a viable class, add the temporary promotion patch only after the native
promotion merge loop, run `integrate check --bytes`, and remove it after a
rejection. Submit only when the local receipt has no mismatches, no lost bodies,
and an established target set. This avoids stale temporary generator patches,
unnecessary server verification, and false ownership-loss rejections.

When the normal queue is empty, `integrate next --revisit-parked` makes one
explicit retry pass over parked eligible classes. It does not unpark another
contributor's live lease or bypass local/server gates. If that pass is empty,
the queue is exhausted until source, analysis, accepted baseline, or park state
changes.

## Evidence and accounting

`roc/integration_local.py` owns local workspaces, diagnostics and attempt artifacts.
`roc/integration_context.py` provides complete retrieval. `roc/native_adapt.py`
indexes qualified declarations and adapts method bodies. `roc/integration_policy.py`
owns measured ranking, retry budgets, token accounting and early class reservations.
`roc/integration_audit.py` independently rebuilds an accepted snapshot without credit.
`roc/native_refs.py` rechecks linked code, referenced data and known import names.
These modules are included in contributor packaging.

The authoritative verifier requires at least one genuine linked object witness for
every newly owned address. Relocation-masked code alone cannot conceal a wrong
float/string/global constant or a contradictory IAT import name. Direct native
callee identities and vtable pointer identities that cannot be independently
resolved are explicitly reported as unresolved; symbol spelling is not ABI proof.
Existing accepted credits are not silently revoked by this forward gate.

Only independently accepted server receipts count toward native functions/hour,
bytes/hour, acceptance rate and learned task history. Byte totals use current
inventory sizes. Local receipts provide compile/check timing, cache success and
failure categories. Model records report actual requests, generation timing and
available token counts. Missing usage is unknown, not zero; server tokens per
success remain unavailable without attestation. Paid models were not invoked in
this implementation validation.

G3D/Ogre candidates require a qualified native declaration and matching rebuilt
member namespace. The current standalone Ogre module replays DLL/import material;
it contains no native source TU layer. This implementation does not fabricate one.
The app's genuine native declarations can still participate through supported
source profiles. Templates, ambiguous overloads, constructors and new layouts
require explicit native evidence and manual review.

## Measured validation

The historical compiler benchmark for genuine `App/util/Units.cpp` measured
7.781 seconds cold and 0.219 seconds warm, a 35.53x cache-reuse ratio.
Receipt: `work/integrator-bench/local-6334d3efa849/benchmark.json`.
This is compiler reuse, not measured end-to-end accepted integrations/hour.
An earlier comment-only checker smoke fixture measured 8.172/0.563 seconds, but
had no claimed targets; the audited checker now rejects empty claims. That smoke
result is not a valid byte-match success benchmark.

Final regression suite including the capability guard, sidecar and audit tests:
474 passed, 1 skipped in 28.04 seconds. A further public HTTP metrics/bulk-claim
protocol test is recorded in the dated research log.

First isolated accepted-baseline audit passed M2/M4a/M5, preserved 3,358 app-owned
bodies and 10,010 global distinct functions in 347.516 seconds.
Receipt: `work/integration-audit/84aa4bb8bbb54214a32c754bd17f1112/audit-receipt.json`.
M4b is not a required supported gate; no M4b success is claimed.

A second audit with the current matcher/build tooling FAILED ownership no-loss:
3,358 -> 3,335 app-owned bodies; 23 removed, 7 covered elsewhere, 16 uncovered.
Replaying the earlier matcher against the new linked objects explains 17 removals
as discarded-section counting. Six removals also depend on changed linked object
selection/build behavior and require further baseline investigation. All 398
currently credited app bodies passed separate code/data/known-import checks;
2,334 native references remain explicitly unresolved under that check's scope.
Receipt: `work/integration-audit/52af7fc94c724cef9b54ee0e3bf535be/audit-receipt.json`.
Detailed old witnesses: `ownership-diagnosis.json` beside that receipt.

The audit now saves complete build results, lost/uncovered ownership, milestones
and reference outcomes even when the no-loss gate fails. It never awards credit.
Accepted overlays, original executables and vendor trees were not modified by
this workflow implementation. Concurrent unrelated repository edits are preserved.

## Initial rollout blockers (follow-up below resolves current-profile readiness)

The initial audit required resolving the latest baseline's 16 uncovered ownership losses under the current
matcher/linker policy, then rerun `integrate audit`; do not weaken the no-loss
gate or grandfather a failed rebuild. Restart the verifier to activate the new
reference gate and API capabilities. Finally measure a real independently accepted
promotion batch before claiming an integrations/hour improvement. No production
promotion or credit was submitted for these implementation tests.


## Completion follow-up: current verifier profile

The remaining runtime blocker was reproduced in a private snapshot with the current
module manifests and tests. Debugging found a null dereference in a reflection
container helper from `verified_0000.obj`. Only its Type singleton was requested;
`strip_symbols(keep=...)` nevertheless kept unrequested shared COMDAT template
code, overriding the native helper with another source context. Restricting the
implicit shared exception to data, and honoring native/helper exclusion lists,
fixes this. A narrower exclusions-only trial still crashed at the test's invalid
CRT parameter trap and was rejected. Missing genuinely required helpers continue
through the existing explicit dependency-resolution path; no stubs were added.

The final private rebuild passes module runtime, M2/M4a/M5 and size/base gates.
Its corrected inventory contains 3,283 app-owned and 9,943 global distinct bodies.
Every one of the 398 independently credited native bodies survives and passes
code/data/known-import checks. Counts do not claim new integrations or credit.
Final result and receipt:
`work/native-workflow-finish/b9ab33d00d7744bcb7028896c02b54b4/final-build-result.json`
and `final-audit-receipt.json` beside it. Debug evidence is `runtime-diagnosis.json`.

The audit previously copied current Python but retained old manifests/tests. It
now copies the current trusted rebuild profiles, test sources and glue while
freezing accepted source overlays. Failed module reports are retained in receipts.
Normal legacy-reproduction audit remains strict and still reports old inventory
losses; those counts are not silently declared reproduced.

`roc integrate audit --current-profile` explicitly validates a new tooling profile:
runtime, ABI non-regression and independently rechecked coverage of every accepted
credit. It requires the authoritative credit database, reports historical inventory
differences separately, and grants no credit. New verifier baseline initialization
also rechecks every accepted body, so corrected matcher/cache inventories cannot
silently erase native credits. Future candidate no-loss checks remain unchanged.

Final regression suite after dependency-convergence coverage: 491 passed, 1 skipped in 40.15 seconds. Deployment requires
restarting the existing server, which currently advertises none of the new
capabilities. Its `--publish` option would immediately push Git changes on restart;
`CLAUDE.md` forbids Git pushes, so publication must be paused for this restart or
explicitly authorized. The server database has a read-only SQLite backup in the
private completion snapshot.


The user authorized restarting with publishing paused. The existing server was
restarted successfully with `--publish` removed. Live API checks now advertise
context/metrics/native-reference/bulk-claim/selection capabilities; the native
leaderboard still contains 398 credits. New submissions use the updated verifier.
No Git publication was triggered by this restart. Backup and process details are
recorded in `work/native-workflow-finish/server-restart.json`.

Dependency repair now continues while adding new helpers/exclusions instead of
stopping after an arbitrary twelve rounds. A regression fixture needs fourteen
rounds and proves convergence; no-progress still terminates through existing gates.


## Final independent audit and live status

The ordinary CLI completed a fresh accepted-cache rebuild successfully:
`roc integrate audit --current-profile`. All module/runtime, M2/M4a/M5 and ABI
checks pass; all 398 credited bodies independently pass code/data/known-import
checks. Duration: 277.031 seconds. Final corrected inventory: 3,283 app-owned,
9,943 global distinct. Receipt:
`work/integration-audit/e9f127f55c3b48c486b5c64f3343e665/audit-receipt.json`.

The receipt explicitly records `legacy_inventory_reproduced: false`: 75 old
compiled ownership entries are excluded under the corrected current profile,
54 lacking coverage in other modules. This grants no new credit and removes no
existing credit. The strict legacy-reproduction mode remains available and will
continue to flag that historical count difference. Current-profile validation
is a tooling migration proof, not a claim that those old compiled entries survived.

The updated live server advertises all new capabilities and its leaderboard still
has 398 credits. Automatic publishing remains paused per the user's choice. No
new promotions, source submissions, paid model requests or Git pushes were made.
Final tests: 491 passed, 1 skipped; syntax and whitespace checks pass.

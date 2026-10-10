# Match-maximization audit

2026-10-10. Objective: maximize **unique newly code/data-exact functions**, then
matched bytes, per unit of compiler time and generation spend. Priority below is
an inference from repository evidence, not a guaranteed yield estimate.

Audit inputs: all archived report/plan topics, the detailed findings log, existing
runner/prototype code, selected local JSON reports and a read-only local catalog
snapshot. No new model calls, compilations or submissions were made for this audit.
Not every scratch output was independently reproduced. Archived PIDs and running
notes are historical. The local catalog is not necessarily the current server.

## First: harvest results already paid for

`work/mass-search/refine-unsolved-final/report.json` contains **55/55 exact**
independent rechecks, with zero repair mutations. It supersedes the earlier
54-winner checkpoint. Local catalog lookup: 46 still non-exact, 2 already exact,
7 absent. Absent rows may be clients not present in this catalog; they are not
failed matches. Recheck source hashes, client binary/compiler/flags, normal code
and data verification, and current server scores. Then retain/submit only actual
improvements and run propagation from those newly verified donors. This is the
highest-confidence immediate lead, not a claim of 46 guaranteed new submissions.

The solved-holdout final report contains 85/85 exact: 66 already exact locally,
8 locally non-exact, 11 absent. Investigate the eight discrepancies; these were
solved holdouts, so do not label them new discoveries without provenance.

Completed unsolved direct arm: 600 jobs, 53 exact, 581 compilable, no recorded
failures. Structured arm: 598 jobs, 444 failures; budget exhaustion invalidates a
simple strategy comparison. Holdout complete direct/structured repeats yielded
70/64 and 65/67 exact out of 300; no consistent strategy winner. Final repeat
had 249 failures. Do not combine failed arms into a quality-rate estimate.

Sources: local `work/mass-search/*/report.json`, final refine reports;
[historical mass search](archive/mass-search-20261009.md).

## Expansion queue

| Order | Experiment | Why now | Next bounded test |
| --- | --- | --- | --- |
| 1 | Whole-client family discovery + propagation | Repeated-family exemplar gains across four clients; deterministic conversions already verified | Index remaining clients/sections; measure unmatched eligible members and exact donors. Replay every safe candidate with code/data verification, deduplicate client/address, then solve representatives ranked by remaining sibling count |
| 2 | Shared-MFC and evidence-based build configuration | Independent 81-target replay contains ten new exacts vs freshly compiled baselines, all 2009-06 XMLNode; five train/five held-out | Expand to untested classes/clients: initially 6 class/config cohorts, 10 discovery + 20 unseen methods each and 10 exact guards. Separate candidate recipes; preserve existing best per target |
| 3 | Correct client-specific template instantiation | Local catalog has 1579 partials labeled `RBX::VInstance::?$NonFactoryProduct`; template RTTI inventory has 197 names but only three generated source files | Validate demangling and supported types/policies; select 20 distinct unresolved families, <=8 evidence-supported instantiations each. Score all emitted methods plus withheld siblings |
| 4 | Source/donor coverage audit | Existing libraries and exact source donors can multiply one recovery across classes/clients | Inventory unsolved functions by proven source family/version; use same-unit/cross-client/deep fingerprint only on untried, provenance-supported pairs. Pilot 24 scoped batches, expand families yielding new exacts |
| 5 | Real compilation neighborhoods | Synthetic opaque/visible differences prove context matters, but no real-target conversion rate established | Ten real callers with recovered exact callees; compare opaque objects, same-TU visible definitions, linked /GL+/LTCG. Add ten withheld callers if any actual conversion appears |
| 6 | Cross-client graph-assisted source transfer | Current xcopy/exact-callee hints are not a global correspondence solver | Fifty unmatched methods across two adjacent clients; multiple independent anchors, mapped ABI/globals; compare current xcopy/retrieval on identical targets |
| 7 | Type-safe joint ABI/layout repair | Regex permutations had 138 failed compiles in 199 attempts; narrow receiver idioms did yield exacts | Twenty close candidates across >=4 classes, <=100 compiles each; paired AST joint edits vs existing mutator; withhold target families, refresh diagnosis after each attempt |
| 8 | Genuine referenced-data repair | No qualifying cases in small XTP samples; broader inventory untested | Scan for `code_exact=true` + data failure. Recover at most 20 genuine cases, grouping consumers by shared object; stop if none qualify. Never classify 99 by score alone |
| 9 | Independent boundaries/alias audit | Initial contiguous-chain observations do not validate the catalog | Thirty persistent size/extra-instruction cases; independent CFG/call/return evidence and shadow ranges. Keep catalog correction separate from new recovery counts |
| 10 | Behavior-guided synthesis | Emulation probes exist; grammar/CEGIS absent, coverage narrow | Ten call-free integer functions, bounded memory/loops, 1000 defined inputs, <=100 source candidates each. Only start after grammar + memory model are valid; historical MSVC code/data exactness remains acceptance gate |

Prioritize actual address-level eligibility over impressive class counts. The
template label above is a triage lead, not proof all 1579 rows share one fix.
One representative that unlocks many unmatched siblings is more useful than
another isolated register-only 98% survivor.

## Evidence quality and unfinished work

| Topic | What evidence establishes | What it does not establish |
| --- | --- | --- |
| Family exemplars | 49/68 -> 68/68, 22/28 -> 28/28 on selected sibling holdouts; local models 0/4 -> 3/4 smoke | Whole-client recovery rate; four-model samples are tiny; sibling functions share family structure and are correlated |
| Family propagation | Later replays: 45/547, 35/1136, 8/948 exact conversions | Coverage outside sampled sections, remaining reachable gains or independent additive totals across snapshots |
| MFC/layout | Real configuration explains shared-release extra virtual slots; independent replay has ten new exacts | Blanket recipe correctness: three known-exact guards regressed to 72; apparent +8 is not automatically a member-field shift |
| Automatic scheduling | Provider request overlap works; operational defaults tested | Quality benefit: 24 repeated jobs from 12 targets yielded 5 exact vs control 6, with greater tokens/time |
| Prompt/history changes | Model/workload-specific exploratory results exist | Global default wins; temperature-zero/push hints lost, CFG/semantic samples of 12/24 were mixed, repeated draws are not independent targets |
| Output budgets/thinking | Disabling thinking addresses missing-code failure; six 40-target arms each had one exact | Larger caps increase exact rate; 40 medium/large rows across repeated arms are not 240 independent discoveries |
| Guided/instruction/permutation repair | Early narrow exact wins; 29-target instruction arm improved ten partials, combined arm eleven | General exact conversion: all residual arms converted zero; same 29 candidates reused across studies |
| Templates | Existing generic recipes had zero new matches; local extractor/generated C++ exists | Valid reconstruction of decorated type arguments, complete compile results or held-out matches. `template_args_test.json` is empty; three generated files are not completed recovery |
| Compilation context | DLL/map/export/opaque helpers and synthetic caller probe work | Real ten-caller/three-context trial, target-compatible linked scoring and data provenance; forced unresolved links/stubs are diagnostic only |
| AST/graph/CEGIS | Parsing, exact-callee hints, emulator and tiny window verifier prototypes | Production joint transformations, global graph alignment or full-function synthesis. Clang AST template APIs do not by themselves decode arbitrary binary RTTI names |
| Data-only | Shared-MFC recheck examined symbol ties and found zero qualifying plateaus | No genuine cases elsewhere in the catalog; broader scan is still justified |
| Boundary audit | Prologues/relocations/contiguous chains support inspected spans | Independent whole-section correctness or justified alternative boundaries |
| Debug metadata | Inspected local paths lack matching original client metadata | A broad artifact search is profitable. Keep opportunistic and bounded; matching build identity required |
| Runtime/cache work | Concrete reliability and telemetry-reader improvements | New exact conversions or universal throughput gains; measure total work separately |

## Park until evidence changes

- Repeating the same high-partial/compiler/model profile: 279-target guided run,
  DeepSeek 20, local Qwen 20, ABI-only 20 and instruction/constant 20 shards had
  zero gains. The 30-target mixed shard also had zero gains. Better selection alone
  has not solved structural deficits.
- Larger generic compiler flag/version grids already tried without a new source
  or config lead; deepen only a family with fresh evidence.
- More work on `00675890` alone without new data-flow/context evidence. Types,
  lifetimes, receivers and flags changed surrounding allocation or stayed at 98.
- Uniform +8 layout patching, blindly applying shared-MFC everywhere, bigger
  token budgets or all-model structured prompting.
- Whole-PE symbolic analysis, binary-only rewrites and speculative debug-file
  hunts. Optional tools must answer one bounded hypothesis before broader use.

## Sample and promotion rules

Freeze a prospective manifest before choosing winners. Separate source-hidden
solved holdouts from genuinely unsolved targets. Stratify by client, family,
source availability, score band and size; include 2007-03 and later 2011/2012,
which are underrepresented in the family evidence. For family trials split by
family/class as well as address; report donor coverage and within-family results.

Suggested next broad comparison: 300 unique unsolved targets across available
clients, with >=100 over 128 bytes and >=50 over 256 bytes, if eligible. Run
compiler-only baseline and the donor/config/template pipeline first. Cloud arm
only within explicit remaining budget; reduce sample instead of overspending.
Three hundred is a useful next batch, not a power guarantee. Report uncertainty
and correlated clusters; bootstrap by family/class for grouped methods.

Primary metric: newly independently verified exact addresses not already exact
in the frozen/current baseline. Also report exacts per 1000 compiles, wall-hour,
priced dollar and matched bytes; partial-score lift and compiling rate are secondary.
Compare best-of-k to best-of-k with equal request/compile/time bounds. Exclude
infrastructure/cooldown/budget failures from paired quality comparisons and report
them separately; do not silently drop them from operational yield.

Advance cheap pilots after a real held-out conversion; require broader family/
client validation before claiming generalization. Preserve known-exact anchors.
Stop after two fresh zero-gain shards for that profile. For orientation only,
zero successes in 29 independent representative cases would still allow roughly
a 10% success rate at the 95% upper bound (rule of three); current reused/selected
samples are less informative. Zero gains are a stopping signal, not impossibility.

## Immediate next batch

1. Refresh and reconcile the 46 locally non-exact archived winners and missing
   clients, plus ten shared-MFC replay gains. Save per-address fresh provenance.
2. Propagate those donors to eligible unmatched siblings across all clients.
3. Expand shared-MFC only to new cohorts, with exact guards and per-target acceptance.
4. Complete one client-specific template family end to end before generating more.
5. Spend model budget on high-fanout representatives still lacking source; follow
   every accepted exact with propagation. Run the real compilation-context pilot
   for structurally close survivors, not another generic repair sweep.

Read-only catalog snapshot: 7433 high partials (90–99), 43083 mid partials
(50–89), 30493 low partials (1–49). Counts can be stale and exclude unavailable
clients; they are workload hints, not reverified potential yields.

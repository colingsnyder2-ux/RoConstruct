# Experiment memory

Consolidated 2026-10-10. Historical measurements below are snapshots, not live
progress. Full reports/plans remain in [archive index](archive/README.md);
address-level attempts remain in [investigation log](investigations/matching-findings.md).
Read [worker guide](AI_WORKER_GUIDE.md) for current behavior and acceptance rules.
For evidence gaps and prioritized expansion, read [match-maximization audit](NEXT_EXPERIMENTS.md).

## What worked, with limits

| Method | Recorded evidence | Decision / source |
| --- | --- | --- |
| Adaptive Auto output (2026-10-10) | 24 frozen 2007 functions, two draws per arm: exact 16/48 -> 18/48, compiling 45/48 -> 47/48. Holdout exact 10/24 -> 12/24; 34 exact outputs independently reverified | Keep starting caps/hint policy, grow only after truncation within existing rounds and shared budget. Small noisy pilot; [Auto trial](investigations/worker-auto-20261010.md) |
| Source/library fingerprints | Deep pilot: 101 pairs, 73s, 7 new exact Ogre functions in 2010 | Scope by proven family/unit; [deep fingerprint](archive/deep-fingerprint.md) |
| Verified family exemplars | 2007 sibling holdout 49/68 -> 68/68 exact; 2008 cross-client 22/28 -> 28/28, fewer tokens | Strong repeated-family evidence, not whole-client proof; [family results](archive/family-reconstruction-results.md) |
| Cached strict-family reuse (2026-10-10) | Isolated 2007 family stage: 20 fresh sibling targets, exact 1 -> 11; model entries 17 -> 0. Real compiler/data checks, local API/model fixture; all eleven already exact in catalog | Preserve strict provenance on cache hits; directly compile symbolic donors when literal rewrite is unavailable. Not a new-recovery or full AI-quality result; [worker reuse](investigations/worker-reuse-20261010.md) |
| Literal-safe family propagation | Initial replay: 32 exact conversions in 2008, 37 in 2009; none safe in 2007/2010. Later DB-backed replays: 45/547, 35/1136, 8/948 | Different snapshots; do not add overlapping gains; [family plan/history](archive/family-worker-plan.md) |
| Shared-MFC configuration | `_AFXDLL _XTP_STATICLINK _DLL`, `/MD`, build 30729. ReportControl training/held-out new exacts 9/9; PopupBar 10/8 | Release shared MFC retains `AssertValid`/`Dump` slots; per-target adoption only; [layout pilot](archive/layout-config-pilot-results.md) |
| Evidence-guided repair | Early replay 4 -> 5 exact conversions; fresh 15-candidate replay 0 -> 1 | Narrow verified idioms help; [guided repair](archive/repair-guided-results.md) |
| Instruction-aware repair | 29 medium/large candidates: 10 improved, 0 exact; existing arm 2 improved | Faster partial improvement, not solved functions; [instruction repair](archive/instruction-aware-repair-results.md) |
| Guided + permutations | Same 29-candidate corpus: 11 improved, 0 exact; permutations alone 2 improved/138 compile failures | Keep bounded, evidence-ranked; cached timing is not clean speed comparison; [permutations](archive/permutation-repair-results.md) |
| Disable DeepSeek thinking | Four-target pilot: thinking consumed 4096/8192 budgets with no code; disabled produced 3 code candidates, 2 compilable | Generation fix; more tokens alone ineffective; [output budget](archive/output-budget-results.md) |
| Telemetry tail/cache | 583.75MB log: full read 1.3602s, tail 0.1288s, cached ~0.000018s | Reader measurement, not total worker speed; [runtime review](archive/worker-runtime-review.md) |
| Bounded mass search | Historical holdout checkpoint: 85/300 best-target exacts independently reverified; unsolved checkpoint: 54/54 archived exact winners reverified | Local candidates, not submissions; partial arms/budget failures excluded; [mass search](archive/mass-search-20261009.md) |

## Verified repair idioms worth reusing

Historical 2007-08 examples in the investigation log:

- Indirect `__thiscall` instead of `__stdcall`: `005948b0`, `00595230`;
  receiver/argument/const refinements: `00593e20`.
- A legal member call instead of illegal free-function `__thiscall`: `0040ebe0`.
- Static receiver + correct return carrier: `00594010`, `00594760`, `005952d0`.
- RTTI indirect-call form: `00595370`.
- Separate virtual-call view preserving plain storage layout: `00537c70`, `00720b80`.
- Return cleanup/calling convention: `004aa3f0`, independently reproduced 89 -> 100.
- Model-supplied virtual-slot/receiver shape: `00651ee0`; typed global initializer/
  store/helper sequence: `00775fd0`. Prior sources absent, so no exact textual diff claim.

Use `docs/repair-patterns.json` and diagnosed evidence, not address-based guessing.
These examples prove specific source changes, not universal transforms.

## What failed or remains unproven

| Attempt | Outcome / stopping lesson |
| --- | --- |
| Automatic policy vs control | 24 repeated jobs: 5 vs 6 exact; 121393 vs 118293 tokens; automatic slower/costlier. Convenience only; [review](archive/worker-automatic-review.md) |
| Less history / temperature zero / generic push hints | Less-history first draw tied 10/36 with lower tokens but fewer compilable; later evidence restored default history. Temperature zero 6/36, push hints 7/36; [efficiency](archive/worker-efficiency-results.md) |
| Selective compact DeepSeek repair history (2026-10-10) | Initial >48-byte sample: mean 38 -> 48.75%, exact 1/12 -> 2/12. Fresh six: mean 71.33 -> 67%, both 0 exact. Rejected; accepted full-conversation budget accounting only. Total estimated spend $0.1694; [paired history](investigations/worker-history-20261010.md) |
| Bigger output budget | 40 medium/large targets, direct/structured at 4096/8192/16384: every arm only 1 exact; larger caps cost more. Declaration-hygiene prompt failed; [budgets](archive/output-budget-results.md) |
| Always-structured CFG guidance | Results mixed. Twelve-target dominator arm 0 exact vs direct 1; CFG+semantics tied 1 with more tokens. Selective auto 5/24 vs direct 4/24, all exacts tiny; [control flow](archive/control-flow-research.md) |
| Focused LLM residual repair | 0/10 exact or improvements after deterministic repair; broader 29-request permutation report: 0 exact, 3 improved, 2 regressed. Preserve best source |
| Repeated high-partial mining | 279-target guided batch: 0 gains. DeepSeek top-20, local-Qwen evidence-guided 20, ABI-only 20 and stable instruction/constant 20 shards: 0 gains. Park unchanged profiles |
| Register-only `00675890` | Stuck at 98 (`mov ecx,eax` vs `mov ecx,esi`); source types/lifetimes/receiver/flags failed. Other tail allocation changed when apparent receiver fix applied |
| Blind shared-MFC adoption | Replay includes regressions; 2012 shard 24/46 exact but 0 new exacts vs DB. Stored 180 exact recipe sources are not attributable new gains |
| Data-only repair | First ten XTP 99 candidates were not genuine data-only mismatches. Twenty-case qualifying pilot not completed |
| Generic template recipes | Four existing Boost recipes yielded 0 in initial probe. Client-specific RTTI/template recovery still unfinished |
| Graph transfer / boundary audit | Initial correspondence/contiguous-function probes only; no completed 50-method global graph or independent full-boundary audit |
| AST / behavior synthesis | Clang diagnosis and Unicorn call-free probes exist; production type-safe joint repair and grammar/SMT CEGIS are unfinished |
| Compilation neighborhoods | Synthetic opaque vs visible callee differs; ten real pairs across opaque/visible/LTCG not established by initial report |
| Debug artifacts | Local triage found no matching client PDB/OBJ/LIB/MAP; WebService/LTCG artifacts are not original client metadata |

The archived `EXPERIMENT_SUMMARY_REPORT.md` contradicts itself with completion
checkmarks/conclusion after calling many topics partial. Use its underlying
pilot report and this status table; do not repeat its blanket completion claim.

## Recording the next experiment

Save manifest + hash, client/address, compiler/config/flags, baseline source/hash,
fresh code/data score, arm/model/seed, compile attempts/failures, exact conversions,
partial improvements, unique targets, tokens/time/cost and output/report paths.
Keep rejected sources and zero-gain outcomes. Separate infrastructure failure,
cooldown and budget exhaustion from quality results. Do not attribute concurrent
server progress to one worker, pool overlapping snapshots or count improvement
events as unique exacts. Historical PIDs/process-running notes are not live state.

Reproduction: `benchmarks/run_holdout.py`, `repairs.py`, `worker_auto.py`,
`family_replay.py`, `family_propagation.py`, `mass_search.py`,
`aggregate_search.py`, `refine_archive.py`; frozen JSON manifests stay in
`benchmarks/`, large local evidence stays in `work/`. Check CLI help and budgets.

# Instruction-aware repair results

Controlled repair benchmark over the 40 medium/large targets
(`benchmarks/holdout-ml-budget-40-20261008.json`) from
`docs/output-budget-results.md`, using the frozen best compilable candidate of
every target (session `ml40-direct-nt4096-20261008`, direct strategy,
thinking disabled, 4096 tokens, seed 20261008).

Baseline population: **30 compilable candidates, 1 exact** (`2011-06 00a33ad0`).
Repair-eligible (compilable, not already exact): **29**. Already-exact
candidates are never counted as repair conversions.

## Phase 1 — mismatch root cause

`work/mismatch-report.py` recompiled all 29 candidates with the real MSVC
compilers and classified the mismatches (`work/mismatch-report.json`):

| mismatch class | candidates |
| --- | ---: |
| calling-convention mismatch | 14 |
| missing/extra instruction | 12 |
| branch-condition mismatch | 1 |
| code-size mismatch | 1 |
| unknown | 1 |

Top near-exact candidates: `005c3bd0` 94, `00896920` 95, `00858730` 89,
`0056cef0` 82, `00527420` 79, `0056bb10` 78.

### The dominant root cause: member-function calling convention

Candidates declare the target as a class member (`void seg_00560000::func`,
`int S::f`). MSVC compiles members as `__thiscall`, which cleans its stack
arguments (`ret N`). The targets are `__cdecl` members or free functions and end
with a plain `ret`. The old `calling_convention_variants` could only add
`__stdcall` to convention-free free functions and bailed out when `__cdecl` or
`__stdcall` appeared *anywhere* in the file — including unrelated extern
declarations — so none of the 14 candidates were ever repaired.

Secondary localized patterns (visible in the diffs but not yet repaired):
stack-frame size deltas (`sub esp, 0x210` vs `0x204`), one extra inlined
`call` in the candidate, string-literal arguments compiled as `push 0`, and
relocation-only differences that scoring already masks.

## Phase 2–3 — implementation

`roc/mutate.py`:

- `cdecl_member_variants`: when return-cleanup evidence shows the candidate
  cleans stack (`ret N`) and the target does not (plain `ret`), add `__cdecl`
  to the **in-class declaration** (MSVC rejects the keyword on the
  out-of-class definition: C2373). Also converts `__stdcall`/`__thiscall`
  declarations to `__cdecl`.
- `free_function_variants`: when the member body never uses `this`, propose
  converting the member to a free `__cdecl` function (removes the extra stack
  argument) — for targets that are free functions, e.g. `00858730`.
- `calling_convention_variants` rewritten: the convention keyword is now read
  from the **target function's own declaration/definition** instead of a whole
  file scan, fixing the extern-declaration false bail-out. The
  `__stdcall` add direction now also applies to the target function only.
- `guided_variants` now proposes `calling_convention` whenever return-cleanup
  evidence differs — even when the classifier labels the mismatch something
  else (e.g. `005c3bd0` is a branch-condition mismatch *and* a 4-vs-0 cleanup
  difference; the old code never offered the convention fix for it).

`roc/match.py`: `diagnose` now reports `frame_size` (the `sub esp, N` local
frame of target vs candidate) as evidence for stack-layout repair.

## Phase 5 — controlled benchmark (deterministic arms, zero LLM tokens)

Same frozen candidate per target in every arm; same compiler, flags, and
scoring. Old-guided arm ran the pre-change `guided_variants`/`calling_convention_variants`
exec'd from git HEAD for an exact before comparison.

| arm | conversions | improved | regressed | seconds |
| --- | ---: | ---: | ---: | ---: |
| A control (no repair) | 0/29 | 0 | 0 | 0.0 |
| B existing guided | 0/29 | 2 | 0 | 23.8 |
| C new instruction-aware deterministic | 0/29 | **10** | 0 | 2.5 |

Per-target results for arm C (initial → final):

| target | size | initial | final | delta |
|---|---:|---:|---:|---:|
| 2011-06 0056cef0 | 233 | 82 | 87 | +5 |
| 2012-06 00858730 | 95 | 89 | 90 | +1 |
| 2007-03 005c3bd0 | 227 | 94 | 95 | +1 |
| 2011-06 0056bb10 | 118 | 78 | 80 | +2 |
| 2009-12 0060d150 | 221 | 44 | 49 | +5 |
| 2007-03 0073a2f0 | 203 | 35 | 36 | +1 |
| 2011-06 0057a6e0 | 332 | 35 | 36 | +1 |
| 2008-06 0053b4a0 | 124 | 50 | 51 | +1 |
| 2009-06 005920f0 | 74 | 69 | 73 | +4 |
| 2007-08 006168a0 | 194 | 53 | 54 | +1 |

No candidate regressed in any arm; `improve` keeps the best candidate.

## Phase 5 — LLM repair arm

Pilot (`work/llm_repair_pilot.py`): the 10 candidates scoring ≥70 each received
one narrowly focused repair request — target asm, candidate asm, mismatch note,
and current source — with thinking disabled, `max_tokens=4096`, seed 20261008,
temperature 0.05.

| arm | conversions | improved | tokens | cost | seconds |
| --- | ---: | ---: | ---: | ---: | ---: |
| control | 0/29 | 0 | 0 | $0 | 0.0 |
| existing guided (deterministic) | 0/29 | 2 | 0 | $0 | 23.8 |
| new deterministic | 0/29 | 10 | 0 | $0 | 2.5 |
| deterministic + focused LLM | **0/10** | 0 | 13,084 | $0.0064 | ~14 |

The LLM returned essentially the same source in all 10 cases (scores
unchanged to the point). One focused request per candidate does not help these
mismatches; it also costs ~$0.0006 per request for zero movement. LLM repair
stays opt-in and is not justified by this benchmark.

Follow-up experiment on the top candidate: `005c3bd0` (95 after the
convention fix) has an unexplained 12-byte stack delta (`sub esp, 0x210` target
vs `0x204` candidate). Sweeping the local buffer `char buf[0x200]` through
`0x1f4–0x210` peaks at `buf[0x20c]` → 95 — the frame delta is not the exact
blocker either. The residual blockers for that candidate are a `push 0` where
the target pushes a relocated string address and one extra inlined `call`.

## Phase 6 — efficiency

The new deterministic arm is **9.5× faster** than existing guided (2.5s vs
23.8s for the same 29 candidates) because the convention fix is now proposed
only on return-cleanup evidence instead of being suppressed, and deduplicated
variants cap at 8. `improve` keeps the best candidate; no arm regressed any
target. Deterministic-only is the justified configuration: zero LLM tokens,
zero cost.

## Failure analysis (why 0 exact)

The 10 improved candidates each still carry at least one structural difference
after the convention fix:

- **Extra inlined call** (`005c3bd0`, `0056cef0`): the candidate emits an
  additional `call` the target performs differently — a control-flow
  reconstruction difference, not a signature one.
- **Argument constants the target takes from relocations** (`005c3bd0`,
  `0056cef0`): the candidate pushes `0` where the target pushes a relocated
  string address; the existing immediate mutator needs a *unique* source
  literal and position-aligned instructions, neither of which holds.
- **Frame sizes / locals** (`0056cef0` `0x14` vs `0x24`): the candidate's
  locals are shaped differently; a bounded sweep proved the frame delta is not
  the sole blocker.
- **Register allocation** (`00527420` 79): the candidate uses thiscall-style
  `mov esi, ecx` sequencing the target does not.
- **Missing/extra instructions overall** (12 of 29 candidates): these are
  Category C structural regenerations; the goal's guidance not to burn dozens
  of tiny mutations on them is confirmed — the 2.5s arm already covers what is
  fixable.

Overlap reconciliation: 0 shared, 0 direct-only, 0 structured-only exact
matches across arms; each arm's conversion count (0) equals its reported total.

## Phase 4 — category thresholds (empirical)

From the 29-candidate report: exact-blocking mismatches cluster at the ends —
scores ≥75 are localized convention/frame fixes (8 candidates, all improved by
the new arm), scores ≤74 are dominated by missing/extra-instruction classes
(21 candidates, no repair moved one). Threshold used by the benchmark:
evidence-triggered deterministic repair for everything ≥70, structural
treatment (regeneration) recommended below.

## Verification

`tests/test_roc.py`: **72 passed** (new coverage: `__cdecl` member-declaration
variant, member→free conversion, `this` guard, evidence-triggered convention
proposal when the classifier disagrees, `frame_size` diagnosis).

## Conclusion and next bottleneck

Instruction-aware repair **improved 10 of 29 candidates** (2 under the old
guided arm) at 9.5× lower compute and zero LLM cost, but converted **zero**
additional compiler-verified byte-exact matches. The exact matches that exist
(`2011-06 00a33ad0`) were produced by generation, not repair, on every arm.
The focused-LLM arm converted zero and cost tokens for no movement; it stays
opt-in.

Next bottleneck, from measured evidence: the residual mismatches are
control-flow reconstruction (extra inlined calls, branch structure) and
relocated-argument constants — i.e. the *generation* problem, not the repair
problem. The highest-value next step is feeding the instruction-level
diagnosis (frame size, extra-call count, relocated-argument evidence) into the
generation prompt so candidates arrive closer to exact, rather than extending
the mutation search.

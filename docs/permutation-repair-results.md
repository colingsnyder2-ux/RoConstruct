# Open-source permutation techniques: research and benchmark

What four matching-decompilation projects actually contain (verified from
source, not README claims), what RoConstruct already had, what was integrated,
and what the controlled benchmark measured.

## Phase 1 — Research findings (verified from source)

### cpp_permuter (CriminalRETeam) — MIT
Read `src/scorer.cpp`, `src/passes.hpp`, `docs/passes.md`, `tests/integration/`.
- **Instruction-level Needleman-Wunsch scoring**, not byte scoring.
  `align()` fills a DP table; `subCost()` returns 0 for identical operands,
  `penaltyRegalloc` when operands differ only in register squashing, and
  `penaltyArgs` otherwise. Insert/delete penalties are far larger than
  substitution ones, and `scoreInsns()` re-scores a matched del+ins pair as a
  cheap "reorder" instead of a missing+extra instruction.
- **Relocation handling in the scorer**: relocated operands are replaced by
  the symbol name (`<sym>`) and absolute addresses outside the object are
  masked, so address-only differences do not count.
- **~40 source passes** in `passes*.cpp`, selected by name; test suite includes
  `vc6.sh` — it is actively built against MSVC 6, so **the MSVC-2005 build
  50727 we use is well inside its supported range**.
- It shells out to `objdump` for disassembly, which we do not need (capstone
  is already in-process).

### decomp-permuter (simonlindholm) — MIT
Read `src/randomizer.py` (93 KB, 37 `perm_*` transforms), `src/scorer.py`,
`src/permuter.py`, `src/perm/perm.py`.
- **`PERM` marker system**: manual hints in source are parsed and searched
  seeded by random seed enumeration (`perm_gen_all_seeds`).
- **Scorer** (`src/scorer.py`): `difflib.SequenceMatcher` over mnemonics with
  named penalties — `PENALTY_REGALLOC = 5`, `PENALTY_REORDERING = 60`,
  `PENALTY_INSERTION = PENALTY_DELETION = 100`, `PENALTY_STACKDIFF` and
  `PENALTY_BRANCHDIFF = 1`. Same tier structure as cpp_permuter.
- **`Permuter`** keeps the best score seen so far and never discards a winning
  candidate; perms are applied on top of the original source each round.
- **Vendors pycparser** for syntax-aware transforms. We deliberately did **not**
  vendor a parser (no new dependency); the transforms below are text-level
  and strictly semantics-preserving.

### objdiff (encounter) — MIT / Apache-2.0 (dual)
Read `objdiff-core/src/diff/mod.rs`, `code.rs`, `arch/x86.rs`.
- Instruction-level diff with **byte-masked relocation entries**, alignment
  awareness for x86, and a function-diff view that pairs target/candidate
  instructions with addresses.
- Exposes a CLI + C API (`objdiff-cli`, bindings). The equivalent capability
  is already in `roc/match.py` (`asm_lines` masks relocation operands,
  `diagnose` classifies mismatches), so **nothing was ported**; the concept
  confirms our masking approach.

### reccmp (isledecomp) — **AGPL-3.0**
Read `reccmp/compare/diff.py`, `reccmp/compare/core.py`.
- `SequenceMatcher` over instruction text with an **address-aware unified
  diff** (`@@ -addr,range +addr,range @@` slugs) and `is_effective_match`
  logic.
- **License blocks integration**: AGPL-3.0 does not permit copying its code
  into this project. Only the address-slug diff idea was noted; RoConstruct's
  `match.diff` already produces grouped unified diffs with context.
- Its signature-matches (`// FUNCTION: GAME 0xADDR`) have no analogue here —
  targets are nameless stripped client functions.

## Phase 2 — RoConstruct audit

Already present and working (not reimplemented):
- Exact byte comparison with relocation masking (`exact_match`).
- Capstone in-process disassembly with relocated operands shown as `sym`
  (`asm_lines`) — the objdiff-style masking.
- Mismatch classification with 14 categories (`match.diagnose`).
- Unified diff with grouping (`match.diff`, used as `diff_preview`).
- Deterministic compile-and-test mutation search (`mutate.improve`),
  evidence-guided variants, bounded variant list, best-candidate retention.
- Benchmark infrastructure with session isolation (metrics jsonl per session).

Genuinely missing before this change:
1. **Instruction-alignment scoring with tiered penalties.** Scoring was raw
   byte similarity, so a pure register renaming cost the same as a structural
   rewrite and could not rank hypotheses.
2. **A taxonomy of semantics-preserving source permutations** beyond four
   single-site mutators.
3. **Reorder detection** (a del+ins pair of the identical instruction).
4. **Alignment evidence feeding mutation choice.**

## Phase 3–4 — What was integrated

`roc/match.py`:
- `ALIGN_PENALTY_*` tiers (regalloc 1, args 5, delete/insert 100, reorder 60).
- `align_insns()` — Needleman-Wunsch alignment over `asm_lines`, with
  register-squashed substitution, delete/insert, and post-pass reorder pairing
  that converts a matched del+ins pair into the cheaper reorder cost.
  **Ranking only; it never verifies a match** — `exact_match` remains the sole
  verification signal.
- `alignment_evidence()` — compiles a candidate and returns its alignment.
- `frame_size` added to `diagnose` (target vs candidate `sub esp, N`).

`roc/mutate.py` (opt-in `permute=True`):
- `commutative_swap_variants` — swaps operands of `+ * & | ^ == !=` at every
  site; operands may be calls or member/pointer accesses (what generated code
  actually contains).
- `inequality_swap_variant` — `a < b` → `b > a` and friends, including
  numeric literals.
- `reorder_decls_variants` — swaps adjacent same-type scalar locals without
  initializers, preserving the surrounding whitespace exactly. Declaration
  order drives MSVC stack-slot and register allocation.
- `permute_variants()` — orders transforms by alignment evidence:
  regalloc-dominated → `reorder_decls` first, args-dominated → operand swaps
  first; canonical order without evidence.
- `improve(..., permute=True, alignment=None)` — opt-in, bounded to 8
  variants, keeps the best candidate, counts compile failures. Default
  behavior (legacy mutators) is unchanged.

Rejected:
- Vendoring pycparser / a C parser (dependency cost, and text transforms
  cover the measured differences).
- Porting objdiff's Rust diff engine (capability already present).
- Any reccmp code (AGPL-3.0).
- Beam search / random restarts / mutation scheduling (Phase 7): the
  single-level bounded search already exhausts the transform space, and
  adding search depth cannot repair structural differences.

## Phase 6 — Controlled benchmark

Frozen candidates: session `ml40-direct-nt4096-20261008` (40 medium/large
targets, direct, thinking disabled, `max_tokens=4096`, seed 20261008). Best
compilable round per target: **30 compilable, 1 exact**
(`2011-06 00a33ad0`), so **29 repair-eligible candidates**. Already-exact
candidates are never counted as conversions. Every arm starts from the
identical frozen source per target; same compiler, flags, and scoring. The
existing-guided arm ran the *committed* `guided_variants` (git `d5e1ba0a8`,
which contains the calling-convention repair) loaded from HEAD for an exact
before-comparison.

| arm | exact conversions | improved | regressed | attempts | compile fails | seconds | LLM tokens | cost |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| A control (no repair) | 0/29 | 0 | 0 | 0 | 0 | 0.0 | 0 | $0 |
| B existing guided (committed) | 0/29 | **10** | 0 | 96 | 11 | 22.0 | 0 | $0 |
| C permutations (canonical) | 0/29 | 2 | 0 | 199 | 138 | 3.7 | 0 | $0 |
| D permutations (alignment-ranked) | 0/29 | 2 | 0 | 199 | 138 | 0.9* | 0 | $0 |
| E guided + permutations (combined) | 0/29 | **11** | 0 | 270 | 132 | 1.1* | 0 | $0 |
| F bounded LLM repair (29 requests) | 0/29 | 3 | 2 | 29 | 0 | 51.6 | 54,877 | $0.0262 |

\* arms D/E reused the warm compile cache from earlier arms on the same
variant sets; cold cost equals arm C. Compilation caching across arms is the
single biggest efficiency lever measured (≈4× on the identical variant set).

**Variant-budget finding.** Combining the engines in one bounded list is
order-sensitive. Permutations-first crowds the guided variants out of the
8-variant cap and *loses* improvements (10 → 8). With the higher-yield guided
variants first and the cap raised to 16, the combined arm recovers the full
union — **11 improved (10 guided + 1 unique permutation gain)** — so
`improve()` now orders guided variants before permutations and
`MAX_VARIANTS = 16`. Guided-only behavior is unchanged (guided never needs
more than 8).

### Per-target results (before → after)

| target | size | B guided | C/D perms | E guided+perms | F LLM |
|---|---:|---:|---:|---:|---:|
| 2011-06 0056cef0 | 233 | 82→87 | 82 | 82→87 | 82 |
| 2012-06 00858730 | 95 | 89→90 | 89 | 89→90 | 89 |
| 2007-03 005c3bd0 | 227 | 94→95 | 94 | 94→95 | 94 |
| 2011-06 0056bb10 | 118 | 78→80 | 78 | 78→80 | 78 |
| 2009-12 0060d150 | 221 | 44→49 | 44 | 44→49 | 44 |
| 2007-03 0073a2f0 | 203 | 35→36 | **35→38** | 35→38 | 35 |
| 2011-06 0057a6e0 | 332 | 35→36 | 35 | 35→36 | 35 |
| 2008-06 0053b4a0 | 124 | 50→51 | 50 | 50→51 | 50 |
| 2009-06 005920f0 | 74 | 69→73 | 69 | 69→73 | **69→85** |
| 2007-08 006168a0 | 194 | 53→54 | 53 | 53→54 | 53 |
| 2011-06 00574ac0 | 320 | 22 | **22→41** | **22→41** | 22→27 |
| 2007-03 004824c0 | 83 | 16 | 16 | 16 | **16→33** |
| 2009-06 006c87b0 | 135 | 67 | 67 | 67 | 67→62 (regressed) |
| 2009-06 0059f310 | 115 | 31 | 31 | 31 | 31→26 (regressed) |
| remaining 15 | — | unchanged | unchanged | unchanged | unchanged |

### Results by function size and mutation category

29 eligible candidates: 16 medium (49–128 bytes) + 13 large (>128). The
manifest's tiny bucket has no eligible candidates (all tiny targets already
matched at generation).

| arm | medium improved | large improved |
| --- | ---: | ---: |
| existing guided | 4/16 | 6/13 |
| permutations | 0/16 | 2/13 |
| guided + permutations | 4/16 | 7/13 |

**Both permutation gains are on large functions** (`00574ac0` 22→41,
`0073a2f0` 35→38); no medium target improved from permutations that guided
repair had not already improved. Mutation categories attempted:
guided `calling_convention` (14), `negate_comparison` (22),
`toggle_int_signedness` (21), `toggle_char_signedness` (16),
`swap_add_operands` (6), `signedness` (4), `branch_condition` (1);
permutations `commutative` (22), `inequality` (13), `reorder_decls` (9).
The only mutation category that produced a *new* improvement was the
permutation set, via declaration reorder and operand swap on large functions.

## Results

- **Newly achieved compiler-verified exact matches: 0**, by every arm,
  against the 29 repair-eligible candidates. The one exact match on the
  frozen manifest (`2011-06 00a33ad0`) existed before any repair and is not
  counted.
- The permutation engine contributes **one unique gain** the committed
  repair does not reach: `00574ac0` 22 → 41 (adjacent-declaration reorder and
  commutative operand swap), at zero LLM cost. Combined, the engines reach
  **11 improved vs 10** for guided alone.
- Best overall single-target gain: `005920f0` 69 → 85 by the LLM arm — which
  also produced the only two regressions, because the pilot kept the LLM
  output unconditionally; keep-best would have discarded those.
- **The permutation gain is real but small (+1 improved, 0 exact), and its
  search is mostly failed compiles** (138 of 199 attempts). LLM repair costs
  $0.0009/request and ≈1,892 tokens/candidate for zero exact matches plus
  regression risk, so it stays out of the default path.

## Phase 7 — Search optimization

- **Compile-result caching** is already effective and is the highest-leverage
  optimization measured (arm D ran in 1.1 s reusing arm C's cache).
- Beam search, hill climbing, random restarts, and mutation scheduling were
  **not adopted**: the bounded 8-variant search already enumerates the
  transform space, and no arm produced an exact conversion for deeper search
  to improve on. Adding search machinery would cost complexity for no measured
  gain.

## Phase 8 — Verification

`tests/test_roc.py`: **77 passed**, including new coverage for alignment
scoring (identical / regalloc / args / delete / relocation-masked /
mnemonic-mismatch), permutation transform semantics (call-suffix operands,
inequality with numeric literals, adjacent-declaration reorder with whitespace
preservation, no-op avoidance), evidence-driven transform ordering, and
`permute` opt-in bounding. `git diff --check` clean. All scores in the tables
above come from real MSVC compilation against the target bytes — no score
improvement is claimed as a match.

## Remaining limitations

1. **Zero exact conversions from any repair arm.** The residual mismatches are
   control-flow reconstruction (extra/missing calls), relocated argument
   constants, and stack-frame shape — the same generation-side causes
   identified in `docs/instruction-aware-repair-results.md`. Repair reaches
   ≈95% and stops; it cannot invent missing structure.
2. 138/199 permutation attempts failed to compile — the transforms are
   text-level and occasionally produce invalid C++ (mostly swapping operands
   in pointer/signedness-sensitive contexts). Failures are cheap (skipped),
   but ~69% of the permutation search budget is spent on them.
3. `align_insns` is O(target × candidate) instructions. Target functions here
   top out near 300 instructions, so a 90k-cell DP is fine; it was not
   bench-marked against the whole client.
4. The alignment evidence is computed once from the initial candidate, not
   re-derived between attempts.
5. The LLM arm was a single request per candidate with no keep-best; the
   reported regressions are an artifact of that.

## Single highest-value next improvement

**Feed the mismatch evidence into generation, not repair.** Every arm fails
the same way: the candidate is structurally short (one extra inlined call
missing, string arguments compiled as `0`, wrong frame size) — exactly the
signals `match.diagnose` and `align_insns` now expose. Attaching the top-3
diagnosis lines and the alignment opcode histogram to the generation prompt
is a one-place change that lets the model produce the missing structure
directly, which is where the remaining exact matches are.

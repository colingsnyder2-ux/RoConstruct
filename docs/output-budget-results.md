# Output-token budget experiment

Root cause and controlled benchmark of the generation-budget bottleneck that
scored every medium/large target 0 in the 100-target holdout.

## Deliverables

1. **Root cause**: `max_tokens=1024` default caps reasoning+output together;
   DeepSeek reasoning expands to fill any budget (measured at 4096/8192/
   16384), so medium/large targets emitted zero code. Fix = disable thinking
   for cloud generation (the mechanism the tiny path already used).
2. **Code changes**: `roc/providers.py` (two-way budget settle),
   `roc/draft.py` (thinking-off default for cloud, `truncated`/`empty_reply`
   flags), `roc/benchmark.py` (`reasoning_tokens` job aggregate),
   `benchmarks/run_holdout.py` (`--max-tokens`/`--seed`/`--thinking`,
   `benchmark_start` config row), 4 new regression tests.
3. **Before/after** (same 40 medium/large targets, direct): before 0 exact /
   0 compilable / 0 code; after (4096, thinking off) 1 exact / 30 compilable /
   101,306 tokens / $0.047449 / 117s.
4. **Direct vs structured**: at 4096 direct wins efficiency (30 vs 29
   compilable, 101k vs 127k tokens); at 8192 structured ties direct-4096 on
   compilable (30) for +37% tokens. Structured never wins on
   tokens-per-compilable.
5. **Medium/large performance**: 30/40 compilable at 4096 (17 medium +
   13 large); 1 exact (medium, size 49). Large functions compile at 11–13/20
   per arm; remaining failures are byte-level diffs in compiled partials.
6. **Historical source recovery**: already proven useful before this
   experiment — `roc/libs.py` recipes for Lua 5.0–5.1.4, RakNet, G3D, SDL,
   Ogre (see `SOURCES.md`): RBXGS ~10k matches, g3d-6.09 +130, raknet-4.081
   +95, rbx2016-g3d +113, lua-5.0 +0. No new framework needed.
7. **Tests**: 70 passed (`tests/test_roc.py`), including budget refund,
   thinking-default, truncation-flag, and fail-fast-no-retry coverage.
8. **Remaining bottlenecks**: 25–29/40 compiled-but-partial per arm (byte
   diffs in control flow / struct layout); 6–10 compile errors per arm
   (`__thiscall` misuse, C2664 conversions, undeclared identifiers); output
   verbosity scales with budget (truncation at 8192/16384); guided repair
   still converts 0 of 29 new candidates — stays opt-in.
9. **Most valuable next improvement**: attack the compiled-but-partial
   majority with a second repair round keyed to the byte-diff diagnosis
   (the harness already produces per-round mismatch notes), rather than more
   prompt text — the hygiene-prompt experiment showed system-prompt edits do
   not move compilability.

## Root cause

The holdout harness used the provider default `max_tokens=1024`. For reasoning
models (DeepSeek flash), `max_tokens` caps reasoning + visible output together,
and the draft loop only disables thinking for targets ≤32 instructions. With a
1024-token cap, reasoning consumed the whole allowance: every medium/large
round ended `finish_reason=length` with `reasoning_tokens=1024` and
`output_chars=0` — no code was ever emitted, so all medium/large scores were 0
regardless of model skill. Budget increase alone does **not** fix this: at
4096 and 8192 with thinking left on, reasoning still expanded to fill the
budget (16,384/4 and 8,192/1 reasoning tokens, 0 output chars). Disabling
thinking (`thinking: {"type": "disabled"}` in the OpenAI-chat body, the same
mechanism the tiny-target path already used) is what unlocks output.

## Phase 1 changes

- `roc/providers.py`: `CloudBudget.settle` now replaces reservations with
  measured usage two-way, so large `max_tokens` over-estimates are refunded
  instead of permanently shrinking the shared cloud cap.
- `roc/draft.py`: empty/truncated rounds now record explicit `truncated` and
  `empty_reply` flags (truncation vs parse failure vs compile failure are
  distinguishable).
- `roc/benchmark.py`: job rows aggregate `reasoning_tokens` separately.
- `benchmarks/run_holdout.py`: `--max-tokens`, `--seed`, `--thinking`
  passthrough; every run records a `benchmark_start` config row (manifest,
  model, strategy, rounds, max_tokens, seed, caps) so experiments are
  reproducible and arms cannot silently mix.
- Fail-fast: provider 400/context-overflow errors are non-retryable and never
  re-requested (`_post` maps them to `provider_error`; only 408/429/5xx
  retry). Regression-tested.

## Pilot (4 targets: 2 medium, 2 large, direct, rounds=1, seed 20261008)

Manifest `benchmarks/holdout-ml-pilot-4-20261008.json`.

| session | max_tokens | thinking | done | code | compilable | truncated | reasoning tok |
| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| ml-pilot-b4096 | 4096 | auto | 4/4 | 0 | 0 | 4 | 16,384 |
| ml-pilot-b8192 | 8192 | auto | 4/4 | 0 | 0 | 4 | 32,768 |
| ml-pilot-b16384 | 16384 | auto | 4/4 | 1 (85%) | 1 | 3 | 16,384 |
| ml-pilot-nt4096 | 4096 | disabled | 4/4 | 3 | 2 | 0 | 0 |
| ml-pilot-nt8192 | 8192 | disabled | 4/4 | 3 | 2 | 0 | 0 |

With thinking on, reasoning expanded to fill 4096/8192 entirely and only
sometimes completed within 16384 (1/4, an 85% partial). With thinking off,
every job emitted code immediately (0 reasoning tokens, 0 truncation) at
roughly 5× lower cost.

## Controlled benchmark (40 medium/large targets)

Manifest `benchmarks/holdout-ml-budget-40-20261008.json`: 20 medium + 20 large,
all previously attempted in `holdout-fresh-100-20261008.json` (36/40 completed in
each old arm, all score 0, zero code). Arms: direct/structured ×
4096/8192/16384, thinking disabled, rounds=1, seed 20261008, model
`deepseek:deepseek-flash`, same compiler flags per client.

Command template:

```text
python benchmarks/run_holdout.py benchmarks/holdout-ml-budget-40-20261008.json --model deepseek:deepseek-flash --rounds 1 --strategy {direct|structured} --max-tokens {4096|8192|16384} --thinking disabled --seed 20261008 --allow-cloud --max-cloud-cost 1.00 --max-cloud-tokens 900000 --max-cloud-requests 60 --session ml40-{strategy}-nt{budget}-20261009
```

### Direct arm results

| budget | jobs | exact | compilable | avg score | median | truncated | tokens | cost | seconds |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 4096 | 40 | 1 | 30 | 43.52 | 47.0 | 1 | 101,306 | $0.047449 | 117.4 |
| 8192 | 40 | 1 | 26 | 40.48 | 45.5 | 4 | 128,592 | $0.080193 | 177.4 |
| 16384 | 40 | 1 | 28 | 43.67 | 44.0 | 4 | 160,630 | $0.118638 | 249.4 |

### Structured arm results

| budget | jobs | exact | compilable | avg score | median | truncated | tokens | cost | seconds |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 4096 | 40 | 1 | 29 | 40.80 | 43.5 | 1 | 127,078 | $0.054742 | 112.3 |
| 8192 | 40 | 1 | 30 | 43.45 | 47.5 | 1 | 138,576 | $0.068540 | 144.4 |
| 16384 | 40 | 1 | 30 | 44.12 | 50.0 | 4 | 187,324 | $0.127037 | 251.5 |

### What the budget actually does

Before (1024, thinking auto): 0 exact, 0 compilable, 0 code on all 40.
After (thinking disabled): every arm emits code on 36–40/40 targets.

- **4096 is the efficiency winner**: direct-4096 has the most compilable (30),
  fewest tokens (−21% vs 8192, −36% vs 16384), lowest cost, and fewest
  truncations. Bigger budgets make the model write longer, more verbose
  sources: 8192/16384 arms show *more* output truncation (verbosity scales
  with the budget) and no compilable gain at 16384.
- **Direct vs structured**: at 4096, direct edges structured on efficiency
  (30 vs 29 compilable, 101k vs 127k tokens, $0.047 vs $0.055). At 8192
  structured ties direct-4096 on compilable (30) for +37% tokens. Structured
  never beats direct on tokens-per-compilable; its avg/median scores are
  within noise of direct at matched budgets.
- **Exact matches**: all six arms produced exactly one exact match and it is
  the same target, `2011-06 00a33ad0` (size 49, medium), compiler-validated
  (`compile_ok=1`, `compile_error=None`, `finish=stop`), 103–107 output
  tokens, $0.00044. Exact-set overlap across all six arms: shared=1,
  direct-only=0, structured-only=0 — reconciles with each arm's total of 1.

### Failure modes after the budget fix (Phase 3)

Per arm, non-exact completed jobs split into: 25–29 compiled-but-partial
(bytes differ — the bulk), 6–10 compile errors, 1–4 no-code (output
truncation, concentrated at 8192/16384 where verbosity peaks). Top compile
errors: `__thiscall` applied to free functions (C3865), invented numbered-field
layout rejections, C2664 parameter conversions (e.g. `Node**`→`int`),
undeclared identifiers, receiver/object-pointer misuse. Prompt context is
not the bottleneck: input tokens stayed ~1–3k per job at every size.

### Failed experiment: declaration-hygiene system prompt

Adding "never apply `__thiscall` to free functions" and "declare unknown
layout as char padding arrays, never numbered fields" to the system prompt
(session `ml40-direct-nt4096-hygiene-20261009`, same 40 targets, direct, 4096):
27 compilable vs 30 for the unchanged prompt — no improvement, slight
regression within noise. The prompt change was reverted; the `__thiscall` /
numbered-field errors (2–3 occurrences each per arm) remain better addressed
by the existing per-round rejection feedback than by system-prompt text.

### Repair replay on the new candidates

`benchmarks/repairs.py --from-session ml40-direct-nt4096-20261009` (29
non-exact compilable candidates, zero model calls): 0 conversions in both
existing and guided arms, 0 in the 90–99% band (2 candidates). Guided repair
has now produced 0 conversions across 51 holdout candidates in total; it
stays opt-in with no default-on evidence.

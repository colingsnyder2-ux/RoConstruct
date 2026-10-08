# Worker efficiency measurements — 2026-10-08

DeepSeek Flash, direct generation, thinking disabled, two rounds, 18 source-hidden
solved 2007-08 targets (six each: tiny, medium, large), two repeats per arm.
Four benchmark threads; no submissions to the mining server.

| History | Jobs | Exact | Jobs with compiling candidate | Total tokens |
| --- | ---: | ---: | ---: | ---: |
| Original target + recent exchanges | 36 | 10 | 34 | 170,410 |
| Original target only; selected source/diff in repair prompt | 36 | 10 | 31 | 157,243 |

Removing redundant history saved 7.7% tokens, but compilation regressed in this
sample. Exact matches did not improve. Runtime is confounded by compiler-cache
warmup and provider variation; these runs do not prove a speed improvement.
Telemetry sessions: `history-ablation-20261008-k{2,0}-r{1,2}`.

Failure inspection found atomic reference-count functions generating inline asm
or undeclared Interlocked calls. Target-specific generation guidance now explains
MSVC `_InterlockedExchangeAdd`, its declaration, intrinsic pragma, and old-value
semantics. A real 2007-08 compiler check confirmed emitted `lock xadd` bytes.
Four follow-up generations across two atomic targets all produced a compiling
candidate, but none matched exactly. Sessions: `atomic-guidance-20261008-r{1,2}`.

Combined guidance + lean-history validation finished: 36 jobs, 7 exact, 35
compilable, 166,838 tokens. This recovered compilation but did not improve exact
matches versus the original 10/36. Default history retention was restored; zero
history remains an explicit experimental benchmark option. Do not treat
compilation conversions or fuzzy scores as evidence of exact-match improvement.

A shorter-rules experiment retains all target evidence and original history.
Validation sessions: `compact-rules-20261008-k2-r{1,2}`: 36 jobs, 9 exact,
32 compilable, 149,687 tokens. Current full-rules control with atomic guidance:
36 jobs, 10 exact, 34 compilable, 171,191 tokens. Short rules saved 12.6% tokens
but did not improve quality; they remain experimental rather than default.

Unfenced output extraction previously kept only the nearest struct and lost
earlier helper types, extern declarations and intrinsic pragmas. Extraction now
preserves that preamble. A real compiler validated recovered atomic source;
follow-up atomic runs compiled in round one in all four trials (previous old-value
guidance runs compiled in round one in none). These are combined generation and
extraction changes, not an isolated causal estimate for extraction alone. Exact
matches remain zero for these two targets.

Startup benchmark, eight concurrent index requests: cold parallel loads read the
source-index cache eight times in 7.343s; serial warmup then parallel access read
it once in 1.136s. This local measurement includes warmup and demonstrates avoided
duplicate loads, not end-to-end mining throughput. Reproduce with
`python benchmarks/startup.py`. Worker startup now warms the index once before
parallel loops.

Reproduce: `python benchmarks/history.py --session UNIQUE --keep 2 0 --repeats 2`.
The runner reads the existing hidden corpus and records isolated telemetry. Keep
the corpus and compiler flags fixed across arms. Historical pre-guidance results
require the pre-guidance code; rerunning current code changes both arms.

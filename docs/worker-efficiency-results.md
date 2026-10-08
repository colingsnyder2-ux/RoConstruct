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

Adaptive tiny-only history follow-up: 36 jobs, 10 exact, 31 compilable, 170,639
tokens. It did not sustain the earlier tiny-only benefit across the complete
run; default history remains unchanged. Both all-target and tiny-only lean
history are experimental benchmark options.

Live fixed-prompt concurrency test (not decompilation throughput): eight requests
with concurrency one took 6.428s and 6.958s; concurrency eight took 0.966s and
1.056s. Every batch returned 8/8 correct replies and used 232 tokens. Two batches
of 64 simultaneous requests returned 64/64 correct replies in 1.270s and 1.233s,
using 1,856 tokens each. CLI cloud concurrency now follows worker count by default;
explicit `--cloud-concurrency` overrides it. URI workers share the same limiter.

Single-round thinking-enabled generation (8,192-token cap for targets over 48
bytes; tiny targets thinking-disabled): 36 jobs, 8 exact, 16 compilable,
256,213 tokens. Twenty requests hit the token cap with no source output.
Sessions: `single-reasoned-20261008-k2-r{1,2}`. This is not a paired causal
estimate against two-round controls, but demonstrates severe reasoning-budget
starvation. Worker `thinking=auto` now disables thinking for DeepSeek on all
sizes; explicit enabled remains honored. Other providers retain their policy.
OpenAI-chat telemetry records provider-reported reasoning tokens separately
when available (null otherwise); these are a subset of output tokens, not
additional tokens to charge or add to totals.

Assembly column-padding compression was tested without removing addresses,
instruction bytes, or operands. Compressed: 36 jobs, 7 exact, 32 compilable,
178,939 tokens. Unchanged control: 36 jobs, 8 exact, 34 compilable, 181,825
tokens. Savings were only 1.6%, with worse observed quality; the experiment hook
was removed. Sessions: `asm-padding[-control]-20261008-k2-r{1,2}`.

ABI-corrected structured reconstruction: 36 jobs, 7 exact, 36 compilable,
204,361 tokens. Reference-guided reconstruction: 36 jobs, 5 exact, 34 compilable,
159,318 tokens. Both remain optional strategies; neither demonstrates an
exact-match gain over the direct-generation controls above. These small samples
are exploratory, not proof of statistically reliable differences.

Reproduce: `python benchmarks/history.py --session UNIQUE --keep 2 0 --repeats 2`.
For full generation-and-compilation batch timing, use `--workers N --no-resume`
with a fresh session. The runner warms the reference index once, as parallel
workers do, and records warmup separately from batch wall time. Resumed batches
are explicitly labeled and must not be used as throughput measurements.

The URI setup now offers an optional auto preset: two rounds for DeepSeek or
functions up to 48 bytes, four otherwise, maximum target size 512 bytes, Rev.ng off unless
explicitly selected. Explicit round overrides remain supported. This is an
experimental resource policy, not a measured quality improvement; existing
fast/balanced/deep defaults are unchanged. Benchmark its round policy with
`--auto-preset`; this local runner does not exercise server leases or Rev.ng.

The initial size-only auto policy (two tiny/four larger rounds) used 398,581
tokens for 36 jobs, with 10 exact and 36 compilable; batches 12.016s/10.062s.
All exact matches occurred by round two. Compared with the two-round
compiler-warmup control (174,415 tokens, 10 exact, 34 compilable), this did
not justify 2.3x tokens. Auto now caps DeepSeek at two rounds regardless of
size; explicit fast/balanced/deep or advanced round overrides remain unchanged.
Session: `auto-preset-20261008-k2-r{1,2}`. Other models' four-round policy
is not validated by this DeepSeek-only experiment.

Cold target-function cache validation: eight simultaneous readers of the real
41MB, 36,971-row function index previously opened it eight times in 5.906s,
returning separate objects. Single-load locking opened it once in 0.372s and
returned the identical object to all threads. Both function-index and mapped
executable-image caches now serialize initial loads. Reproduce with
`python benchmarks/target_startup.py --workers 8`. This is local startup time,
not an end-to-end throughput multiplier.

Compiler discovery was a second cold-start race: concurrent cache misses each
recursively searched the tools tree and probed compiler executables. Parallel
workers now discover compilers once before launching loops. Fixed-corpus
18-thread validation: startup 3.125s, batches 7.781s and 4.828s. The preceding
single-load-only run took 59.172s cold and 7.062s warm. Including startup, the
new first batch was 10.906s. These are exploratory local generation/compilation
measurements, not server mining throughput or a universal multiplier.
Compiler-warmup arm: 36 jobs, 10 exact, 34 compilable, 174,415 tokens;
serial comparison: 36 jobs, 8 exact, 36 compilable, 168,309 tokens, batches
57.828s and 52.047s. Different draws and execution order prevent attributing
quality differences to concurrency. Sessions: `throughput-compilerwarm18-20261008`
and `throughput-warmed1-20261008`, each suffixed `-k2-r{1,2}`.

The runner reads the existing hidden corpus and records isolated telemetry. Keep
the corpus and compiler flags fixed across arms. Historical pre-guidance results
require the pre-guidance code; rerunning current code changes both arms.

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

Binary-only prompt ablation omits later-version source clues but retains full
assembly, extracted facts and rules. Validation: 36 jobs, 8 exact, 35 compilable,
147,981 tokens (15.2% below the compiler-warmup control); batches 9.266s/5.250s.
No demonstrated exact-match gain, so source clues remain default. Reproduce
with `--binary-only`; sessions `binary-only-20261008-k2-r{1,2}`.

Temperature zero: 36 jobs, 6 exact, 35 compilable, 172,453 tokens;
both batches 5.781s. It saved only 1.1% versus the compiler-warmup control,
with fewer observed matches. Default temperature remains 0.2; the benchmark
runner accepts `--temperature` for explicit experiments. Sessions:
`temperature-zero-20261008-k2-r{1,2}`. Temperature zero is not fully deterministic
across provider calls, and this small sample does not establish causality.

Generic pre-call push-order hints were also rejected: 36 jobs, 7 exact,
35 compilable, 183,917 tokens. The experimental hook was removed. A separate
real-compiler diagnostic on `004017c0` confirmed that swapping two API call
arguments alone converts one 98% candidate to 100%; the model did not reliably
learn that correction from the generic hints. Sessions: `call-stack-20261008-k2-r{1,2}`.

Selective source clues (only targets up to 128 bytes) were checked with four
repeats against a four-repeat control: 72 jobs per arm. Selective: 19 exact,
70 compilable, 303,936 tokens. Control: 17 exact, 70 compilable, 337,816
tokens. Token use fell 10.0%; the two-match difference is not proof of a
match-rate gain. These are repeated draws over 18 targets, not 72 independent
functions. Optional DeepSeek auto now applies this cutoff; explicit presets
retain source clues. Reproduce with `--source-hint-max-size 128`; sessions
`selective-source[-control]-20261008-k2-r{1,2,3,4}`. This was selected on the
same corpus and still needs separate-corpus validation before broader defaults.

Separate holdout validation is now complete. `benchmarks/holdout-2007-08.json`
contains six locally solved functions per size bucket, excludes all RTTI units
from the tuning corpus, and chooses the first address per unit per bucket
before taking six in address order. No candidate source is supplied. Frozen
before either arm ran; four repeats per arm, 72 jobs each. Selective: 6 exact,
60 compilable, 510,072 tokens. Control: 7 exact, 59 compilable, 574,859 tokens.
Savings: 11.3% overall; large-only 18.8% (258,168 vs 318,131 tokens), with
20 vs 19 compilable and zero exact in both. All exacts were on unchanged tiny
prompts; small draw differences do not prove improvement or regression.
Selective batch times: 10.266/7.562/7.984/7.157s; control:
12.032/8.093/7.469/8.469s. Execution order/provider jitter remain confounders.
Sessions: `holdout-{selective,control}-20261008-k2-r{1,2,3,4}`. Use `--corpus`
to reproduce without overwriting the tuning corpus. Future benchmark start/end
records include corpus SHA-256 and non-secret generation configuration.

Holdout output-cap trial (2,048 rather than implicit 1,024 tokens): 72 jobs,
6 exact, 59 compilable, 554,829 tokens, 24 truncated replies. Selective control:
6 exact, 60 compilable, 510,072 tokens, 25 truncated replies. Higher cap did
not fix runaway class expansion and increased tokens 8.8%. Worker URI already
uses a 2,048-token default; this experiment does not justify changing it.
Session: `holdout-budget2048-20261008-k2-r{1,2,3,4}`.

Minimal-layout instruction trial at 1,024 tokens: 72 jobs, 5 exact,
63 compilable, 510,344 tokens, 16 truncated replies. It reduced truncation
but did not demonstrate an exact-match gain; remains experimental. Session:
`holdout-minimal-layout-20261008-k2-r{1,2,3,4}`. A direct diagnostic on the
25-byte `00403d00` showed a 2,048-token response listing 204 invented numbered
fields without emitting the function. This is generation bloat, not evidence
that the actual function needs a larger output budget.

Resetting chat history only after a truncated reply with no complete function
was then tested at unchanged caps/rounds: 72 jobs, 4 exact, 66 compilable,
467,832 tokens, 14 truncations. Selective control was 6 exact, 60 compilable,
510,072 tokens, 25 truncations. Savings 8.3%; compilation improved in this
sample, but no demonstrated match gain. This opt-in discards malformed history
and asks for one compact function in the existing next round; it does not add
rounds or rewrite source. Session: `holdout-reset-truncated-20261008-k2-r{1,2,3,4}`.
Reproduce with `--reset-truncated`. Defaults remain unchanged pending additional
validation; this follow-up was tuned on the holdout and is exploratory.

The runner reads the existing hidden corpus and records isolated telemetry. Keep
the corpus and compiler flags fixed across arms. Historical pre-guidance results
require the pre-guidance code; rerunning current code changes both arms.

Follow-up strategy checks (all DeepSeek Flash, 18 workers, four repeats, 72 jobs
unless noted; same compiler, holdout, 2 rounds, 2,048 output cap, truncated-history
reset, selective source hints): direct reset-only control: 7 exact, 66 compilable,
422,816 input tokens. Combining reset with minimal layout: 4 exact, 64 compilable,
425,042 tokens. Two independent candidates on hard functions: 4 exact, 63
compilable, 341,346 input tokens. Reference strategy: 5 exact, 67 compilable,
369,789 input tokens. No broad strategy wins on exact count and compilation
together; leave production strategy unchanged. Sessions use prefixes
`holdout-{reset2048-control,combined,diverse2,structured,reference}-20261008`.

Structured tiny-only check (`size <= 32`) showed a promising DeepSeek result. On
the 2007-08 tiny holdout, eight repeats: direct 14/48 exact and 47/48
compilable at 176,742 input tokens; structured 19/48 exact and 46/48 compilable
at 213,464 tokens. On six separate 2008-06 tiny functions with the 2008 compiler,
eight repeats: direct 25/48 exact, 47/48 compilable, 82,043 tokens; structured
29/48 exact, 48/48 compilable, 89,949 tokens. Combined, structured raised exact
matches 39→48 and compile conversions were neutral (94/96 each), with 17.2% more
input tokens; tokens per exact match fell about 5%. These are repeated draws on
12 functions, not independent 96-function evidence. Promising for cloud DeepSeek
tiny targets; not yet enough to change default.

Local `qwen2.5-coder:7b-instruct` tiny check on the same six 2008-06 functions:
direct four repeats produced 4/24 exact, 15/24 compilable, and 2,506 output
tokens. Structured first repeat produced 0/6 exact, 4/6 compilable; one request
hit its 180s timeout. Stopped remaining repeats because latency contradicted the
speed objective. This argues against globally routing all models through
structured mode. Input-token usage is unavailable from the local provider.

`benchmarks/history.py` supports `--model`, `--client`, `--max-size`, and
`--diverse-candidates` to reproduce these stratified tests. Do not treat the
exploratory runs as an automatic-tuning result; keep direct as default until a
larger, model-specific holdout confirms quality and latency gains.

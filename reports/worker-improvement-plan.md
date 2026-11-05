# RoConstruct worker improvement plan

## Evidence

Current 2008-06 telemetry: 711 jobs, 1 exact match, 583 successful compile attempts out of 1,227, 51.0 seconds average LLM time, 443 `no_gain` jobs, 128 `bad_reply` jobs, and 9 timeouts. Structured generation dominates the sample (632 jobs), so direct/reference comparisons remain underpowered.

## Priority order

### 1. Make generation measurable and cheap

Add per-round prompt tokens, model load time, output tokens, and stop reason to worker telemetry. Set output budgets from function size and stop immediately on malformed/non-C++ output. Keep one fixed 21-target smoke set and require repeated direct/structured/reference runs before accepting a change.

Gate: lower median wall time and `bad_reply` rate without lowering compile-job rate.

### 2. Fix the high-frequency candidate failures

Build a small deterministic preflight classifier for inline asm, qualified definitions, undeclared receiver types, invalid member initializers, and pointer/object confusion. Feed one compact typed diagnosis to the next round. Do not add broad repair rewrites; reject or regenerate candidates that violate the source contract.

Gate: each rule must convert or prevent a measured failure class on held-out targets.

### 3. Improve structure-first input

Replace the current text CFG summary with a bounded JSON-like IR: blocks, successors, loop back-edges, calls, stack offsets, ECX/`this` evidence, returns, and branch signedness. Keep assembly and trusted pseudocode separate. Add a structural validator comparing candidate branch/call/return counts before compilation.

Gate: fewer C++ compile failures on medium/large functions; no claim of semantic correctness from structure alone.

### 4. Retrieval, not source dumping

Index verified source by client, class, method, call targets, literals, and normalized instruction shape. Retrieve at most one short method window plus metadata. Mark speculative relationships separately. Benchmark retrieval hit/no-hit pairs on the same target set.

Gate: compile rate or exact rate improves at fixed prompt-token budget.

### 5. Candidate search only after quality improves

Sample 3 diverse candidates for difficult functions, compile all, then rank by exact match, opcode/branch agreement, compile status, and only then fuzzy score. Preserve top-k sources and reject duplicates. Do not add a learned reranker until a held-out candidate set exists.

Decaf supports this direction: many samples plus compiler/back-translation feedback and reranking are central, but its results use much larger models and non-MSVC data, so RoConstruct needs a local pilot first. [Decaf](https://arxiv.org/abs/2605.11501)

Gate: at least one exact/compile conversion per additional inference budget; otherwise revert to one candidate.

### 6. Speed controls

Use 7B for tiny/medium functions, 14B only for a measured hard bucket. Keep one model loaded per worker, use bounded workers, and tune `num_ctx`/`num_predict` by size. Ollama exposes stream completion, keep-alive, prompt-cache counts, and generation timing; record these before changing concurrency. [Ollama generate API](https://docs.ollama.com/api/generate)

Gate: report exact matches per wall-hour and tokens per compiled candidate, not score averages alone.

### 7. MSVC pilot, no training yet

Create 100–300 legally usable MSVC 2005/2008 function pairs split by project and function family. Include constructors, virtuals, templates, pointer-heavy code, and optimization variants. Validate source-to-function boundaries and exact compiler flags first. Fine-tuning is allowed only if the pilot shows reliable pairs and a held-out compile/exact-match gain.

## Experiment sequence

1. Freeze a 21-target corpus and run direct/structured/reference, 3 repeats, same 7B model and rounds.
2. Add only telemetry + output-budget controls; rerun.
3. Add failure classifier/preflight; rerun.
4. Add bounded retrieval; rerun.
5. Add 3-candidate search on the hard bucket; compare exact matches per wall-hour.
6. Test 14B only on the hard bucket; stop if compile/exact gain does not repay its wall time.

Every step must preserve original candidates, compiler diagnostics, session IDs, model, flags, target list, and timestamps. No change is accepted from fuzzy-score movement alone.

# Full worker plan audit

Source: the pasted worker plan. This is the complete verification list; `[x]` means code and current evidence exist, `[~]` means partial/pending runtime evidence, `[ ]` means not finished.

## Phase 0 — measure first

- [x] Lease-to-finished duration.
- [x] Source, Rev.ng, LLM, and compile phase timings.
- [x] Round scores, output bytes, and output-token estimates.
- [x] Model, client, function size, and unit per job.
- [x] Source-hint usage and source-candidate compile hit.
- [x] Categorized API/timeout/bad-reply/compile/no-gain failures.
- [x] Append-only local JSON telemetry and session summary.

## Phase 1 — reliability

- [x] Retry transient GET/server failures with backoff.
- [x] Distinguish bad request, auth, server, and offline failures.
- [x] Independent lease heartbeat and lease-loss check before submit.
- [x] Reconnect refreshes server info and eligible clients.
- [x] Session state stores model, completed, matches, and failures.
- [x] Release paths cover normal failure and Ctrl+C.
- [x] Bounded whole-job/LLM/Rev.ng/compiler timeouts.
- [x] Cache stable compiler, source, example, and client data.
- [x] Full local traceback plus short terminal error.

## Phase 2 — selection

- [x] Priority uses source confidence, leaf/unit, near-complete score, difficulty, attempts, and size.
- [x] Server stores shape, calls, source confidence, difficulty, and attempts per model.
- [x] Cooldown prevents repeated simultaneous/wasteful leases.
- [x] Repeated failures extend cooldown exponentially.
- [x] Automatic routing favors small models for easy leaves and measured winners otherwise.
- [x] Per-model attempt cap forces a different model/profile after repeated failure.

## Phase 3 — source-first

- [x] 2016 index covers classes, methods, paths, declarations, bodies, includes, inheritance, literals, and tokens.
- [x] Retrieval ranks class/unit/name/literal overlap and returns bounded snippets/methods.
- [x] Source candidates compile with target compiler before LLM.
- [x] Exact source hit submits; partial source becomes LLM baseline.
- [x] Compile failures retain concise useful context.
- [x] Local recipes cover G3D/Lua/JPEG/PNG/RakNet/Roblox modules where available.
- [~] Broad arbitrary app-method compile success coverage.

## Phase 4 — binary facts

- [x] Direct call targets and caller lists.
- [x] Imported APIs and external direct calls.
- [x] Strings, data references, global reads/writes.
- [x] Virtual slots, stack arguments, calling convention.
- [x] Branches, constants, and sibling layout.
- [x] New fact fields persisted across 345,661 rows.
- [~] Complete semantic call graph and perfect data-reference recovery.

## Phase 5 — nearest retrieval

- [x] Unit/class-nearest solved examples.
- [x] Assembly-shape matching and compiler/client-aware fallback.
- [x] Source token/AST-like shape metadata.
- [x] Example size cap and per-worker cache.
- [x] Full structural AST index rebuild completed for 80,351 files (resumable builder).

## Phase 6 — deterministic generation

- [x] Empty, constant, getter, setter, constructor, destructor, thunk, wrapper, and global patterns.
- [x] Imported wrappers, forwarding, singleton/global access, and string/literal patterns.
- [x] Math/member add/sub/multiply/xor/neg and bool-test patterns.
- [x] Batch candidate compilation with isolated namespaces.
- [~] Exhaustive STL/runtime/MFC/XTP/vector/container/template families.

## Phase 7 — LLM pipeline

- [x] Deterministic target classifier.
- [x] Minimal draft followed by compile repair and assembly-diff repair.
- [x] Strict one-code-block output schema and bounded examples/source.
- [x] Partial best source is preserved; regressions do not replace it.
- [x] Installed-model selection, profiles, retry caps, telemetry, and routing.
- [~] Full-corpus measured model win-rate evidence.

## Phase 8 — prompt/context speed

- [x] One-to-two example cap and bounded source bodies.
- [x] Ollama keep-alive, output cap, streamed stop, and per-round context reuse.
- [x] Tiny/simple functions skip Rev.ng; complex/source-missing functions use it.
- [x] Rev.ng output is bounded and cached in-process.

## Phase 9 — compiler throughput

- [x] Compiler environment/path cache.
- [x] Source/object/function extraction caches.
- [x] Safe deterministic batching and two-thread source candidate compilation.
- [x] No uncontrolled LLM/compiler concurrency; bounded `roc worker --workers N`.
- [x] Persistent source-hash compiler-error cache (`work/compile-errors.json`).

## Phase 10 — feedback loop

- [x] All round scores and generated source attempts retained locally.
- [x] Model, prompt profile, score, duration, and failure metadata retained.
- [x] Failure clustering covers calling convention, type, syntax, symbol, and API failures.
- [x] Repeated failures promote rules/templates and quarantine entries.
- [x] Quarantined examples are excluded from few-shot retrieval.
- [x] High-quality 100% attempts promote into `work/worker-promoted.json`; recurring failures generate reusable source-pattern templates.

## Phase 11 — setup/UI

- [x] `roc doctor` checks server, clients, compilers, Ollama, Docker, source, and Rev.ng.
- [x] `roc model` shows/selects/resets installed default model.
- [x] `roc worker --dry-run` shows clients, model, profile, and worker count.
- [x] Fast/balanced/deep presets and source-only mode.
- [x] `roc source-status` reports source coverage.
- [x] `roc benchmark-models` fixed, hidden, baseline, full, and resumable modes.
- [x] `roc benchmark-models --progress` reports resumable records without GPU work.
- [x] Clear setup/error commands in README.

## Phase 12 — validation

- [x] Tests cover ranking, extraction, leases, cooldown, models, shapes, caches, and generators.
- [x] Server rejects foreign/expired lease submissions, preventing duplicate lease writes.
- [x] Hidden corpus separates tiny/medium/large and source-present/source-absent targets.
- [x] Metrics track matches/hour, score gain, GPU minutes, compile time, failures, source hits, and model stats.
- [~] Full 168-target x 2-model benchmark completion (resumable; partial records retained).

## Current gates

- [x] `python tests/test_roc.py` passes.
- [x] Python byte-compilation passes.
- [x] `roc doctor` and `roc source-status` pass.
- [x] All 345,661 analysis rows contain new fact fields.
- [~] Complete every `[~]` item above.

# Worker improvement checklist

Implemented and verified:

- [x] User-selectable Ollama model; automatic preferred/default model; `roc model`.
- [x] `roc doctor` dependency check.
- [x] `roc doctor` reports Docker availability alongside compilers/Ollama/source/Rev.ng.
- [x] `roc model-stats` reports measured jobs/matches/improvements/time per model.
- [x] Model telemetry also reports match rate, score gain, and GPU-minutes per match.
- [x] `roc worker --dry-run` setup preview.
- [x] `fast`, `balanced`, `deep` worker presets.
- [x] `--source-only` mode runs deterministic candidates without Ollama.
- [x] Safe GET/API retries and clearer network errors.
- [x] API failures are categorized as bad request, auth, server, or offline.
- [x] Reconnect refreshes server info and eligible client/compiler flags.
- [x] Worker session state persists model, completed count, matches, and failures under `work/worker-sessions/`.
- [x] Heartbeat thread and lease release on normal failure/Ctrl+C.
- [x] Heartbeat detects lease loss and abandons work before submit.
- [x] Server validates lease ownership/expiry before accepting submit.
- [x] Deterministic `auto.candidates()` attempted before Ollama.
- [x] Unit-aware nearest matched examples, capped to short examples.
- [x] 2016 source index snippets injected into prompts.
- [x] Source hint ranking adds target identifier and literal overlap; metadata stays bounded.
- [x] 2016 source coverage command: `roc source-status`.
- [x] RTTI/source unit, call count, import clues, `this` offsets, and return facts in prompts.
- [x] Target relocated references now add global addresses and printable strings to prompt facts.
- [x] Analysis rows now persist imports, strings, data refs, virtual-slot clues, stack args, branches, and constants.
- [x] Analysis rows persist explicit `this` reads/writes and inferred caller/callee cleanup convention.
- [x] Retrieved 2016 source clues include bounded declarations, methods, includes, inheritance, literals, and tokens.
- [x] Focused method-body extraction feeds prompts without whole-file stuffing.
- [x] Analyzer persists direct call targets and caller lists for source-neighbor retrieval.
- [x] Analyzer distinguishes imported calls from direct calls leaving the local function set.
- [x] Analyzer persists nearby sibling-function layout per unit.
- [x] Incremental fact refresh persisted the new call/global fields across 345,661 rows without rerunning the slow all-analysis command.
- [x] Compile-result cache for repeated source candidates.
- [x] Compiler environment/path discovery is cached per compiler build.
- [x] Compiler errors are cached by source/client/build hash.
- [x] Ollama keep-alive and output cap; Rev.ng timeout reduced to 120 seconds.
- [x] Ollama generation request timeout bounded at 180 seconds.
- [x] Whole-job deadline bounded at 600 seconds; timeout releases lease with cooldown.
- [x] Ollama generation streams, stops after closing code fence, and disconnects on timeout.
- [x] Prompt stages distinguish compile repair from assembly-diff repair.
- [x] Deterministic target classifier selects leaf/getter, ctor/setter, wrapper, math, or unknown stage before drafting.
- [x] Per-model conservative context/output profiles; unknown models remain supported.
- [x] Per-model retry caps prevent oversized models/round budgets from wasting GPU time.
- [x] Automatic routing uses fast qwen2.5-coder:7b for tiny leaf jobs until measured telemetry selects a better installed model; explicit choice is preserved.
- [x] Routing upgrades/downgrades from accumulated measured match-rate telemetry when enough jobs exist.
- [x] Per-job JSON telemetry: model, scores, rounds, output size, source hints, Rev.ng, duration, failure.
- [x] Per-round output token estimate is retained alongside output bytes.
- [x] Per-job phase timings: source compile, Rev.ng, LLM, compile seconds, categorized failure reason.
- [x] Full exception trace is retained locally; terminal error stays short.
- [x] `roc failures` clusters recurring compile/API errors from retained attempts.
- [x] Promoted failure quarantine is enforced when retrieving few-shot examples.
- [x] `roc benchmark-models` creates a deterministic tiny/medium/large fixed corpus and reports telemetry.
- [x] Periodic and final worker session summaries.
- [x] Server prioritizes known units and near-complete scores.
- [x] Server stores calls, source confidence, and estimated difficulty for priority ordering.
- [x] Functions persist normalized asm shapes; server serves shape-matched examples with fallback.
- [x] No-gain/failure leases receive bounded server cooldowns, reducing repeated GPU waste.
- [x] Repeated attempts exponentially extend cooldown (capped at one hour).

Verified evidence:

- [x] `python tests/test_roc.py` passes all smoke tests.
- [x] Python byte-compilation passes for changed modules.
- [x] `roc doctor` reports 3 compilers, Ollama, 2016 source, Rev.ng, and 7 clients ready.
- [x] `roc source-status` indexed 75,833 classes/namespaces and 295,758 functions.
- [x] Existing shared `work/refsource.json` is ~114 MB; live hint test returned `ROBLOX2016-main/Network/Replicator.ChangePropertyItem.h`.
- [x] `roc source-status --build-meta` persisted `work/refsource-meta.json` for 80,351 source files (~113 MB).
- [x] Local fixed-target benchmark run: 3 hidden targets, qwen14b 1/3 at 100%, qwen7b-instruct 0/3 at 100%; qwen7b was faster per job.
- [x] `benchmark-models --baseline` records/compares hidden-corpus match-rate and score-gain regressions.
- [x] Live local server + worker dry-run succeeded.
- [x] Live one-job worker run leased, drafted, released, and wrote telemetry.

Not yet automated end-to-end:

- [x] Compile matching 2016 library files directly before LLM (RakNet/G3D/Lua/JPEG/PNG); arbitrary app methods still need extraction.
- [x] Partial source matches become the LLM repair baseline; exact matches submit immediately.
- [x] 2016 source candidate compiles use a bounded two-thread CPU pool.
- [x] Vtable-slot clues and source inheritance metadata; complete call-graph semantics/full data-reference extraction remain.
- [x] Persisted source-token hashes/declarations/normalized AST-like shapes plus structural AST nodes for 80,351 files.
- [x] Fixed-target local benchmark supports resumable full-corpus model comparison (`--full --resume`); smoke run measured qwen14b/qwen7b.
- [x] Hard 180-second Ollama request boundary; streamed socket closes on timeout (no worker-side hung process).
- [x] Compiler and preprocessor subprocesses have 120-second hard timeouts.
- [x] Bounded parallel compiler candidate pool and bounded worker loops via `roc worker --workers N` (1-32).
- [x] Failure clustering classifies recurring errors; `roc failures --promote` saves rule, template, and quarantine files.

Master-plan coverage:

- [x] Phase 0 metrics: job time, model/client/unit, score rounds, output size, source-hint count, Rev.ng, failures, session summary.
- [x] Phase 1 reliability: idempotent GET retry, heartbeat, release paths, local caches, bounded Rev.ng, telemetry.
- [x] Phase 2 selection: known-unit and near-100% priority; unit-aware examples.
- [x] Phase 2 difficulty score, per-model attempt counts/routing, capability routing, and cooldown policy.
- [x] Phase 3 source index: class/function/path lookup, cached 114 MB index, focused snippets, prompt integration.
- [x] Phase 3 minimum-declaration arbitrary app-method extraction/context + bounded compile attempts; [ ] broad arbitrary-method compile success coverage.
- [x] Phase 4 binary facts: calls, imports, `this` offsets, returns, strings/global refs, vtable clues, persisted call edges/callers.
- [ ] Complete call-graph semantics/full data-reference recovery; [x] extraction code and persisted refresh now cover all 345,661 indexed rows for internal/external calls, global reads/writes, and core edges.
- [x] Phase 5 unit-nearest examples, size cap, fallback examples, per-session cache.
- [x] Phase 5 asm-shape nearest-example retrieval plus persisted source-token/structural-AST metadata for all 80,351 files.
- [x] Phase 6 deterministic candidates run before LLM, including getter/setter, ctor, thunk, wrapper, math, and bool-shape grids.
- [ ] Phase 6 complete constructor/thunk/STL/MFC/XTP/math/template expansion.
- [x] Phase 7 staged compile-repair vs diff-repair prompts, source clues, output schema/cap.
- [x] Phase 7 fixed-target benchmark runner and resumable full-corpus mode; [ ] complete full-corpus win-rate evidence.
- [x] Phase 8 context caps, Ollama keep-alive, output cap, 120-second Rev.ng cap, simple-function fast path.
- [x] Phase 8 response-stop streaming plus per-round Ollama context reuse.
- [x] Real two-round Ollama context smoke test passed with qwen2.5-coder:7b-instruct.
- [x] Phase 9 compiler result cache.
- [x] Phase 9 object/function extraction cache; [x] bounded parallel candidate compilation.
- [x] Phase 10 append-only attempt telemetry and retained round scores.
- [x] Phase 10 failure clustering + rule/template suggestion promotion + noisy-target quarantine.
- [x] Phase 11 model selection, doctor, dry-run, presets, source coverage command, clear setup docs.
- [x] Phase 11 benchmark-models corpus/report command and source-only worker mode; actual per-model corpus runs remain manual.
- [x] Phase 12 smoke tests, byte-compile checks, live server dry-run, live one-job worker run.
- [x] Phase 12 hidden corpus: 168 solved targets with source/score omitted, balanced across seven local client datasets and three sizes; baseline comparison tracks match/score regression.
- [x] Benchmark metadata separates source-present and source-absent targets.

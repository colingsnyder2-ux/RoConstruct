# Worker improvement checklist

Implemented and verified:

- [x] User-selectable Ollama model; automatic preferred/default model; `roc model`.
- [x] `roc doctor` dependency check.
- [x] `roc model-stats` reports measured jobs/matches/improvements/time per model.
- [x] `roc worker --dry-run` setup preview.
- [x] `fast`, `balanced`, `deep` worker presets.
- [x] `--source-only` mode runs deterministic candidates without Ollama.
- [x] Safe GET/API retries and clearer network errors.
- [x] Reconnect refreshes server info and eligible client/compiler flags.
- [x] Worker session state persists model, completed count, matches, and failures under `work/worker-sessions/`.
- [x] Heartbeat thread and lease release on normal failure/Ctrl+C.
- [x] Heartbeat detects lease loss and abandons work before submit.
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
- [x] Compile-result cache for repeated source candidates.
- [x] Compiler environment/path discovery is cached per compiler build.
- [x] Ollama keep-alive and output cap; Rev.ng timeout reduced to 120 seconds.
- [x] Ollama generation request timeout bounded at 180 seconds.
- [x] Ollama generation streams, stops after closing code fence, and disconnects on timeout.
- [x] Prompt stages distinguish compile repair from assembly-diff repair.
- [x] Per-model conservative context/output profiles; unknown models remain supported.
- [x] Automatic routing sends tiny leaf jobs to installed qwen2.5-coder:7b; explicit model choice is preserved.
- [x] Per-job JSON telemetry: model, scores, rounds, output size, source hints, Rev.ng, duration, failure.
- [x] Per-job phase timings: source compile, Rev.ng, LLM, compile seconds, categorized failure reason.
- [x] Full exception trace is retained locally; terminal error stays short.
- [x] `roc failures` clusters recurring compile/API errors from retained attempts.
- [x] `roc benchmark-models` creates a deterministic tiny/medium/large fixed corpus and reports telemetry.
- [x] Periodic and final worker session summaries.
- [x] Server prioritizes known units and near-complete scores.
- [x] Server stores calls, source confidence, and estimated difficulty for priority ordering.
- [x] Functions persist normalized asm shapes; server serves shape-matched examples with fallback.
- [x] No-gain/failure leases receive bounded server cooldowns, reducing repeated GPU waste.

Verified evidence:

- [x] `python tests/test_roc.py` passes all smoke tests.
- [x] Python byte-compilation passes for changed modules.
- [x] `roc doctor` reports 3 compilers, Ollama, 2016 source, Rev.ng, and 6 clients ready.
- [x] `roc source-status` indexed 75,833 classes/namespaces and 295,758 functions.
- [x] Existing shared `work/refsource.json` is ~114 MB; live hint test returned `ROBLOX2016-main/Network/Replicator.ChangePropertyItem.h`.
- [x] Live local server + worker dry-run succeeded.
- [x] Live one-job worker run leased, drafted, released, and wrote telemetry.

Not yet automated end-to-end:

- [x] Compile matching 2016 library files directly before LLM (RakNet/G3D/Lua/JPEG/PNG); arbitrary app methods still need extraction.
- [x] Partial source matches become the LLM repair baseline; exact matches submit immediately.
- [x] 2016 source candidate compiles use a bounded two-thread CPU pool.
- [x] Vtable-slot clues and source inheritance metadata; complete call-graph semantics/full data-reference extraction remain.
- [ ] Full persisted source-token/AST similarity index (bounded token metadata + asm-shape retrieval implemented).
- [ ] Model benchmark/routing by measured match rate (fixed-target `--run` exists; no full run verified yet).
- [x] Hard 180-second Ollama request boundary; [ ] OS-level kill for a separately hung model process.
- [x] Compiler and preprocessor subprocesses have 120-second hard timeouts.
- [x] Bounded parallel compiler candidate pool; [ ] broader worker concurrency controls.
- [ ] Failure clustering that auto-generates new deterministic templates.

Master-plan coverage:

- [x] Phase 0 metrics: job time, model/client/unit, score rounds, output size, source-hint count, Rev.ng, failures, session summary.
- [x] Phase 1 reliability: idempotent GET retry, heartbeat, release paths, local caches, bounded Rev.ng, telemetry.
- [x] Phase 2 selection: known-unit and near-100% priority; unit-aware examples.
- [ ] Phase 2 full difficulty model/per-model retry policy; [x] stored difficulty, model-attempt counts, capability routing, cooldown.
- [x] Phase 3 source index: class/function/path lookup, cached 114 MB index, focused snippets, prompt integration.
- [ ] Phase 3 arbitrary app-method compile; [x] focused method extraction and recipe/source compile-before-LLM.
- [x] Phase 4 binary facts: calls, imports, `this` offsets, returns, strings/global refs, vtable clues, persisted call edges/callers.
- [ ] Complete call-graph semantics and full data-reference recovery; core references/edges are persisted.
- [x] Phase 5 unit-nearest examples, size cap, fallback examples, per-session cache.
- [x] Phase 5 asm-shape nearest-example retrieval; source-token/AST index remains.
- [x] Phase 6 existing deterministic candidate generators run before LLM.
- [ ] Phase 6 complete constructor/thunk/STL/MFC/XTP/math/template expansion.
- [x] Phase 7 staged compile-repair vs diff-repair prompts, source clues, output schema/cap.
- [ ] Phase 7 fixed-target model benchmark results; [x] fixed-target runner, telemetry comparison, static profiles, and basic leaf routing.
- [x] Phase 8 context caps, Ollama keep-alive, output cap, 120-second Rev.ng cap, simple-function fast path.
- [x] Phase 8 response-stop streaming; [ ] Ollama prompt-prefix/context reuse.
- [x] Phase 9 compiler result cache.
- [x] Phase 9 object/function extraction cache; [x] bounded parallel candidate compilation.
- [x] Phase 10 append-only attempt telemetry and retained round scores.
- [ ] Phase 10 failure clustering/template promotion/quarantine.
- [x] Phase 11 model selection, doctor, dry-run, presets, source coverage command, clear setup docs.
- [x] Phase 11 benchmark-models corpus/report command and source-only worker mode; actual per-model corpus runs remain manual.
- [x] Phase 12 smoke tests, byte-compile checks, live server dry-run, live one-job worker run.
- [ ] Phase 12 hidden benchmark corpus and tracked match-rate/hour regressions (local fixed corpus exists; hidden isolation remains).

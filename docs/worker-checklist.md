# Worker improvement checklist

Implemented and verified:

- [x] User-selectable Ollama model; automatic preferred/default model; `roc model`.
- [x] `roc doctor` dependency check.
- [x] `roc model-stats` reports measured jobs/matches/improvements/time per model.
- [x] `roc worker --dry-run` setup preview.
- [x] `fast`, `balanced`, `deep` worker presets.
- [x] `--source-only` mode runs deterministic candidates without Ollama.
- [x] Safe GET/API retries and clearer network errors.
- [x] Heartbeat thread and lease release on normal failure/Ctrl+C.
- [x] Deterministic `auto.candidates()` attempted before Ollama.
- [x] Unit-aware nearest matched examples, capped to short examples.
- [x] 2016 source index snippets injected into prompts.
- [x] 2016 source coverage command: `roc source-status`.
- [x] RTTI/source unit, call count, import clues, `this` offsets, and return facts in prompts.
- [x] Target relocated references now add global addresses and printable strings to prompt facts.
- [x] Analysis rows now persist imports, strings, data refs, virtual-slot clues, stack args, branches, and constants.
- [x] Retrieved 2016 source clues include bounded declarations, methods, includes, inheritance, literals, and tokens.
- [x] Analyzer persists direct call targets and caller lists for source-neighbor retrieval.
- [x] Compile-result cache for repeated source candidates.
- [x] Ollama keep-alive and output cap; Rev.ng timeout reduced to 120 seconds.
- [x] Ollama generation request timeout bounded at 180 seconds.
- [x] Prompt stages distinguish compile repair from assembly-diff repair.
- [x] Per-model conservative context/output profiles; unknown models remain supported.
- [x] Per-job JSON telemetry: model, scores, rounds, output size, source hints, Rev.ng, duration, failure.
- [x] Periodic and final worker session summaries.
- [x] Server prioritizes known units and near-complete scores.
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
- [ ] Vtable slots, inheritance, complete call graph semantics, and full data-reference extraction.
- [ ] Full source-token/AST similarity index (asm-shape retrieval now implemented).
- [ ] Model benchmark/routing by measured match rate.
- [ ] Hard job cancellation deadline for a hung local model process.
- [ ] Parallel compiler candidate pool with bounded CPU concurrency.
- [ ] Failure clustering that auto-generates new deterministic templates.

Master-plan coverage:

- [x] Phase 0 metrics: job time, model/client/unit, score rounds, output size, source-hint count, Rev.ng, failures, session summary.
- [x] Phase 1 reliability: idempotent GET retry, heartbeat, release paths, local caches, bounded Rev.ng, telemetry.
- [x] Phase 2 selection: known-unit and near-100% priority; unit-aware examples.
- [ ] Phase 2 full difficulty model, per-model attempt history, capability routing; cooldown implemented.
- [x] Phase 3 source index: class/function/path lookup, cached 114 MB index, focused snippets, prompt integration.
- [ ] Phase 3 direct arbitrary-method extraction and compile-before-LLM.
- [x] Phase 4 basic binary facts: calls, imports, `this` offsets, returns, persisted direct call edges/callers.
- [x] Phase 4 basic strings/global refs; [ ] vtable slots, inheritance, full data references.
- [x] Phase 5 unit-nearest examples, size cap, fallback examples, per-session cache.
- [x] Phase 5 asm-shape nearest-example retrieval; source-token/AST index remains.
- [x] Phase 6 existing deterministic candidate generators run before LLM.
- [ ] Phase 6 complete constructor/thunk/STL/MFC/XTP/math/template expansion.
- [x] Phase 7 staged compile-repair vs diff-repair prompts, source clues, output schema/cap.
- [ ] Phase 7 fixed-target model benchmark/routing; telemetry comparison + static profiles implemented.
- [x] Phase 8 context caps, Ollama keep-alive, output cap, 120-second Rev.ng cap, simple-function fast path.
- [ ] Phase 8 Ollama prompt-prefix/context reuse and response-stop streaming.
- [x] Phase 9 compiler result cache.
- [ ] Phase 9 bounded parallel candidate compilation and object extraction cache.
- [x] Phase 10 append-only attempt telemetry and retained round scores.
- [ ] Phase 10 failure clustering/template promotion/quarantine.
- [x] Phase 11 model selection, doctor, dry-run, presets, source coverage command, clear setup docs.
- [ ] Phase 11 benchmark-models; source-only worker mode implemented.
- [x] Phase 12 smoke tests, byte-compile checks, live server dry-run, live one-job worker run.
- [ ] Phase 12 hidden benchmark corpus and tracked match-rate/hour regressions.

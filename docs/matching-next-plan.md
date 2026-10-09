# Matching Next Plan

## Proven automation

`roc repair` supports bounded `--offset`/`--limit`, score refresh, permutation trials, mutation-family `--category`, JSON stdout, persistent `--json-out`, dry-run safety, and append-only findings logs.

## Research order

1. Run small `--dry-run --json-out` batches by mutation family.
2. Keep only candidates that improve exact byte score.
3. Re-run promising families on 90%+ partials.
4. Use exact compile verification before applying source changes.
5. Reserve superoptimization/IR synthesis for remaining register-only mismatches.

## Current blocker

`00675890` remains 98%. Only known mismatch is target `mov ecx, eax` versus generated `mov ecx, esi`. Tested source types, lifetimes, receivers, pragmas, attributes, and compiler flags have not changed it. Generic flags are unlikely to solve this; source/data-flow search or old-MSVC instruction-level synthesis is next.

## Next escalation

Prototype bounded 32-bit x86 peephole search around mismatching instruction window. Preserve live registers/memory, enumerate only equivalent short rewrites, score exact bytes, and require compiler/source provenance before applying. Run on one 98% function first; batch only after no false improvements.

## New research: verifier-backed synthesis

Use a two-stage pipeline: (1) enumerate tiny x86-32 instruction-window rewrites under live-register and memory constraints; (2) prove candidate equivalence with symbolic execution before compiling/scoring. STOKE demonstrates stochastic x86 superoptimization and equivalence checking, but targets x86-64. Alive2 provides SMT-backed translation validation for LLVM IR, not this MSVC x86 binary directly. Souper targets LLVM IR. Therefore the practical RoConstruct version is a small Capstone/SMT-backed window verifier, with compiler-backed source mutations still required for accepted fixes. Sources: https://github.com/StanfordPL/stoke, https://github.com/AliveToolkit/alive2, https://github.com/google/souper.

Automation rule: keep `roc repair` as the batch driver; add the verifier as a bounded category, emit JSON proof/rejection records, and never apply a binary-only rewrite. First test target is `00675890`, window is the `mov ecx,eax` / `mov ecx,esi` mismatch.

## Fresh full plan

1. Freeze baseline. Save flags, source hash, score, relocation-masked byte diff, disassembly diff, and report path. Never trust stale scores.
2. Classify mismatch: encoding/immediate, CFG/branch, call ABI, memory alias, stack layout, register allocation, or unknown. Route only to matching families.
3. Build CFG/data flow. Lift target/generated x86-32; identify blocks, edges, calls, defs, uses, memory reads/writes, and live-in/live-out registers. Reject uncertainty.
4. Mine donors. Search exact same-unit functions for matching call chains, return carriers, field offsets, and tail shapes. Transfer only legal source idioms.
5. Expand source search: evaluation-order DAGs, temporary lifetimes, declaration scopes, receiver/result types, alias qualifiers, call wrappers, pointer/reference carriers, and lifetime fences. Rank by predicted live-range change.
6. Compiler matrix. Test only untried compiler builds, internal optimizer switches, and flag interactions. Record rejection separately; never save speculative flags automatically.
7. Verify binary hypotheses. Enumerate tiny register moves/splits/reorders only in mismatch windows. Prove with SMT/symbolic execution under live-register and memory constraints. Require source/compiler provenance before acceptance.
8. Active learning. Mine the findings log by mismatch class and outcome. Prioritize measured gains; down-rank repeated zero-candidate families. Keep exact functions as regression tests.
9. Mass runner. Use bounded `roc repair --addr ... --category ... --json-out ... --dry-run` shards and verifier batch files. Apply only compiler-backed candidates; exact 100 required.
10. Stop rules. 100 = exact masked bytes. 99/98 = partial evidence only. Stop a family after documented zero-candidate evidence unless new evidence changes rank.

Fresh tool research: angr provides scriptable CFG/static analysis and symbolic execution; BAP provides binary analysis, an interpreter, and symbolic execution. Candidates for CFG/data-flow validation, not automatic source recovery. Sources: https://docs.angr.io/en/latest/, https://github.com/BinaryAnalysisPlatform/bap.

`/GL` follow-up: do not test it through object-only scoring. Microsoft requires `/LTCG` at link time for `/GL` objects and notes those objects are not usable by normal linker utilities. Future experiment: complete miniature link unit -> `/LTCG` -> extract final function -> score.

Pipeline proof now passes for a standalone DLL: set VC `LIB`, compile with `/GL`, pass `/LTCG` after `/link`, then inspect the linked output. The target runner still needs function extraction and target-compatible link context.

Extraction proof now passes too: `pefile` locates exported `ltcg_probe` at RVA `0x72d0` in `work/ltcg-probe.dll` and reads final linked bytes. Next runner can reuse PE export/section extraction before integrating target scoring.

Reusable helper added: `roc/ltcg.py:build_dll(build, source, output)`. It sets the matching VC `LIB`, invokes `/GL` plus linker-side `/LTCG`, and returns the linked DLL path. It does not yet score target functions or invent exports.

`roc/ltcg.py:export_bytes(dll, name, size)` now extracts an exported function's RVA and final linked bytes. Target sources still need an explicit export/wrapper or a linker map/function-table extraction path.

Map path added: `build_dll(..., map_output)` emits an MSVC map; `map_symbols()` reads public function RVAs, including non-exported `_ltcg_probe`. This is the preferred next extraction path for target-compatible linked units.

`map_bytes(dll, map, symbol, size)` now converts MSVC map `Rva+Base` correctly using the PE image base and extracts bytes for non-exported symbols.

CLI added: `roc ltcg BUILD SOURCE OUTPUT --map MAP` runs the linker-aware build in one repeatable command. It defaults to `/O2 /GS /EHsc /MD`; `--flags` overrides the linked-unit compiler flags. It builds artifacts only; scoring/extraction remains a separate explicit step.

New isolation mode: `--opaque-extra SOURCE` compiles helper sources without `/GL`, then links them into the `/GL` caller. This preserves opaque external-call behavior while still testing caller LTCG register allocation.

Real-target experiment: compile `00675890.cpp` with `/GL`, `/LTCG`, `/FORCE:UNRESOLVED`, and export its decorated `func` symbol. Score extracted linked function only after disassembling through `ret`; this isolates linker effects from object-only scoring.

Stub experiment: `roc ltcg` accepts repeated `--extra` sources. Link matching member stubs to remove unresolved calls, retain the decorated target symbol, extract through `ret`, and score. Stubs are diagnostic only; never count them as recovered source.

Prototype exists: `python -m roc.verify_window "mov ecx,eax" "mov ecx,esi"`. It reports `not-equivalent`; adding `--equal eax=esi` reports `equivalent`. Next integration must derive equalities from surrounding data flow, not guess them.

New allocator research: MSVC documents automatic allocation and says `register` requests are ignored. LLVM's allocator source exposes the useful abstraction: live intervals, interference, register-class constraints, splitting, and recoloring. Adapt those concepts to the generated/target instruction window; source mutations should be ranked by whether they alter live-range pressure, not by arbitrary syntax. Sources: https://learn.microsoft.com/en-us/cpp/build/reference/og-global-optimizations?view=msvc-170, https://learn.microsoft.com/en-us/cpp/c-language/register-storage-class-specifier?view=msvc-170, https://llvm.org/doxygen/RegAllocGreedy_8cpp.html.

Prototype added: `roc/pressure.py` estimates distinct registers and conservative backward live-set hints per instruction window. Simple `mov/lea/pop/xor` destination kills, basic-block splitting, numeric jump-target extraction, and per-block pressure records are modeled; symbolic targets and aliases remain unmodeled.

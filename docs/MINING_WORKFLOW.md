# Function mining workflow

Use this file only for an explicit function-mining/server-score assignment.
Native recovery/class swaps use `NATIVE_AGENT.md` and `NATIVE_SWAP_BATCH.md`;
do not run the bulk passes below as native integration work.

## Get set up (downloads are fine)

1. `roc doctor` - lists what is missing and how to fix it. (Remill/LLVM is optional; env overrides are documented in `docs/AGENT_GUIDE.md`.)
2. `roc install --yes` - exact historical compilers.
3. `roc client-fetch <client>` then `roc analyze <client>` - binary and function list.
4. `roc pull <client>` - everyone's current sources, so you never redo matched work.
5. `roc config --user NAME --server URL` if `roc submit` says they are missing.

## How matching work is done (current methods, 2026-10-12)

Start with `roc research log` (newest entries):
they say what just worked, what was parked, and what to try next. Don't repeat a
variant recorded there as rejected.

1. **Free automatic passes first:** `roc mass`, `roc auto`, `roc xcopy`, `roc donor`.
2. **Near-miss repair (main source of new 2008 exacts).** Take current 90-99% sources
   in a size band (for example 70-94 bytes, then 95-129, ...). Read the target
   disassembly against yours (`roc check`, `roc classify`) and fix only what the
   bytes prove. Fixes that have worked:
   - a wrong immediate constant;
   - storage sizes read from the allocation size the target passes to `new`;
   - by-value argument sizes read from stack offsets;
   - `__declspec(dllimport)` on Win32 APIs called through the IAT;
   - `volatile` to force evaluation order;
   - removing `volatile` to let stores reorder;
   - `/fp:fast` for x87 ordering.
   One hypothesis per trial.
3. **Compiler gates.** Try each candidate under both 2008 compiler builds (VS2005
   50727 and VS2008 RTM 21022) × a few flag profiles (`O2`, `O1`, `Od/Ob0`,
   `GS-`/`GS`, `EHsc`, `MD`). Pin a winner with `// roc-flags:` / `// roc-cl:` lines.
   If the whole grid fails, park the function and move on.
4. **Authentic vendor families.** Explicitly instantiate real library templates
   (G3D `Array`, STL `vector`/`pair`, Boost) for element types observed in the
   binary. Compile each instantiation under the config grid and fan the objects out
   against all unresolved functions.
5. **Propagation.** A repaired source often fixes siblings: scan it against other
   unresolved functions of the same shape.
6. **Libraries.** Library configuration for 2008 is largely done (XTP, Ogre, zlib,
   ATL/MFC). Change a recipe in `roc/libs.py` only with new evidence: the exact
   upstream version, or the vendor's build prelude and defines.
7. **Boundaries.** Fix function extents only with proof, via `work/<client>/bounds.json`.
   A `BOUNDS:` line in `roc check` output is such a proof: submit the source anyway (the
   server re-check records it too). Only the server host runs `roc extents <client> --apply`
   then `roc analyze <client>`, which hot-reseeds the live server.

Write bulk trials as a recipe in `research/recipes.json` (op `grid` or `fanout`),
not a new script; generated units go through `libs.add_unit` so every PC can rebuild
them. Keep each campaign's evidence in `work/<campaign>-<date>/`: sources, hashes,
diffs, server receipts and a summary. Compiling locally is free, so submit only
gains, with `roc submit <client> [addr ...]`.

Player/LLM submissions belong in Player Mining. Include the actual model:
`roc submit <client> [addr ...] --model gpt-6.1-sol` for GPT-6.1 Sol; use your own
model name for other LLMs. Never label LLM work as `roc repair`, `roc auto`, or
another automatic command: those labels route to Server Mining.

Afterwards append one dated entry to `research/log.jsonl` with
`roc research note TITLE TEXT`, covering:
- what was tried;
- the exacts gained;
- the rejected variants;
- what to try next.


# RoConstruct

Matching decompilation of old Roblox clients: write C++ that the client's original
MSVC compiles to the exact target bytes. A function counts only when the group
server re-verifies it byte-identical.

Run commands as `roc.cmd <cmd>` (Windows) or `./roc.sh <cmd>` (Linux); `roc --help`
lists them all.

## Get set up (downloads are fine)

1. `roc doctor` - lists what is missing and how to fix it.
2. `roc install --yes` - exact historical compilers.
3. `roc client-fetch <client>` then `roc analyze <client>` - binary and function list.
4. `roc pull <client>` - everyone's current sources, so you never redo matched work.
5. `roc config --user NAME --server URL` if `roc submit` says they are missing.

## Where the knowledge is

- `docs/AI_WORKER_GUIDE.md` - acceptance rules, repair advice, pitfalls. Read first.
- `docs/NEXT_EXPERIMENTS.md`, `docs/EXPERIMENTS.md` - what to try next, what already failed.
- `docs/investigations/` - one write-up per campaign (`matching-findings.md` is the log).
- `roc/libs.py` - library recipes (exact upstream source + flags per client).
- `benchmarks/` - reusable runners from past campaigns (`raknet_2008.py`,
  `library_fill.py`, `lib_sweep.py`, ...). Read one before writing a new one.

## How matching work is done (current methods, 2026-10-12)

Start with the newest entries at the end of `docs/investigations/matching-findings.md`:
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

Write bulk trials as runners under `benchmarks/` (copy the structure of an existing
one). Keep each campaign's evidence in `work/<campaign>-<date>/`: sources, hashes,
diffs, server receipts and a summary. Compiling locally is free, so submit only
gains, with `roc submit <client> [addr ...]`. Afterwards append one dated entry to
`docs/investigations/matching-findings.md`, covering:
- what was tried;
- the exacts gained;
- the rejected variants;
- what to try next.

## Rules

- Current focus is 2008-06. Never touch client 2009-12 (no mining, testing or submitting).
- A source that matches is a codegen analog: don't claim it is the original declaration.
- No inline assembly, `__emit`, byte blobs or patched target bytes.
- Never invent struct fields, offsets or ABIs: derive them from the binary or a compile.
- Never overwrite a better stored source; submit only improvements.
- Don't edit `clients/` or `tools/` by hand. Don't delete files you didn't create.
- Don't `git push`. Contributors share results through `roc submit`.

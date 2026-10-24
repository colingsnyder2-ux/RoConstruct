# RoConstruct

Matching decompilation of old Roblox clients: write C++ that the client's original
MSVC compiles to the exact target bytes. A function counts only when the group
server re-verifies it byte-identical.

Run commands as `roc.cmd <cmd>` (Windows) or `./roc.sh <cmd>` (Linux); `roc --help`
lists them all.

## Assigned single-function recovery

When the wrapper supplies an assigned source, evidence packet, check command and
120-second triage budget, setup is already complete. Read this file once, then
read the assigned source and `initial_evidence_file` together when supplied.
Older wrappers supply only `evidence_file`: first read its JSON through
`roc.agent_recovery.initial_evidence(packet, evidence_file)` in a fresh Python
command. This tested reader retains full target assembly, facts and native
declarations while deferring duplicated source, neighbour bodies and sibling
source. Read those full-packet sections when the current hypothesis needs them.
This path uses current disk code without restarting the controller. Follow the
recovery preamble and assignment: they constrain the general campaign workflow below.
In `docs/AGENT_GUIDE.md`, read Goal and acceptance first; consult other sections
only for the current evidence or command. Do not read the whole guide, history,
recipes or logs before the first experiment. Record a specific blocker if the
packet lacks the native declaration or ABI evidence needed for a useful draft.
All rules below still apply; the wrapper handles submissions and propagation.

## Get set up (downloads are fine)

1. `roc doctor` - lists what is missing and how to fix it. (Remill/LLVM is optional; env overrides are documented in `docs/AGENT_GUIDE.md`.)
2. `roc install --yes` - exact historical compilers.
3. `roc client-fetch <client>` then `roc analyze <client>` - binary and function list.
4. `roc pull <client>` - everyone's current sources, so you never redo matched work.
5. `roc config --user NAME --server URL` if `roc submit` says they are missing.

## Where the knowledge is

- `docs/AGENT_GUIDE.md` - the one current guide: acceptance rules, tool routing, order
  of work, experiment-memory schema, automatic worker. Read first.
- `research/lessons.json` - ranked, receipt-backed lessons; append each trial to
  `work/agent-memory/attempts.jsonl` (shared with other PCs through the server).
- `research/recipes.json` - named compiler-only experiments with recorded results;
  run them with `roc research list|plan|run NAME`.
- `research/log.jsonl` - the dated findings log (`roc research log`, `roc research note`); the
  older address-level log is frozen in RoConstruct-findings `reports/matching-findings-20261012.md`.
- `roc/libs.py` - library recipes (exact upstream source + flags per client).
- `research/reports.json` - index of old campaign reports (full text in
  RoConstruct-findings `reports/`): history, not instructions.
- `docs/SETUP.md`, `docs/SERVER.md` - install, models, dashboard, hosting, packages.

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

## Known 2008-06 findings (don't rediscover these)

- XTP is at about 98.5%. The winning recipe is `xtp-11.2.2-lib-strlen`: it preincludes
  `XTPDLLExports.h`, defines `_LIB`, and marks the CString accessors noinline. Before
  sweeping any library, find its vendor build prelude the same way.
- Ogre 1.4.5 ships as `rgmain.dll` (recipe `ogre-1.4.5`, flags
  `/Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD`, no `/O2` for that DLL replay).
  The exe also contains Roblox's Ogre subclasses/forks and header templates.
  Client-import headers (`#undef OGRE_NONCLIENT_BUILD`) plus authentic method
  bodies and inherited layouts have recovered dozens more. Their winning exe
  flags often include `/O2`; use per-source evidence, not the DLL flags globally.
  Read the `ogre-*` lessons in `research/lessons.json` and the `ogre-*` recipes in
  `research/recipes.json` before new Ogre work.
- WildMagic is not in 2008-06. Functions attributed to it are Roblox templates.
- A second zlib 1.2.3 copy (0x7a3e90-0x7a99b0) was built with VS2005 50727 and
  `ZLIB_WINAPI` (recipe `zlib-1.2.3-winapi`).
- The exe statically links atls.lib, mfcs90.lib RTM and comsupp.lib (recipes
  `msvc-atlmfc-rtm`, `msvc-comsupp-rtm`). Archive sources need a non-empty `roc-flags`.
- What remains is mostly unattributed Roblox app code. Near-miss repair and
  propagation pay off there; more library sweeps mostly don't.

## Rules

- Default research focus is 2008-06. Agent workers honor the selected client;
  All clients authorizes every registered client, including 2009-12. Keep each
  client's sources, compiler configuration and evidence separate.
- A source that matches is a codegen analog: don't claim it is the original declaration.
- No inline assembly, `__emit`, byte blobs or patched target bytes.
- Never invent struct fields, offsets or ABIs: derive them from the binary or a compile.
- Never overwrite a better stored source; submit only improvements.
- Don't edit `clients/` or `tools/` by hand. Don't delete files you didn't create.
- Don't `git push`. Contributors share results through `roc submit`.

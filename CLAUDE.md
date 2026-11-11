# RoConstruct

## Choose the task before running commands

**Native task** (`NATIVE_AGENT.md`, native recovery, class swaps, runnable integration):
follow `docs/NATIVE_AGENT.md` and `docs/NATIVE_SWAP_BATCH.md`. Work on real native
classes, implemented methods and authentic headers. Blocker repair is secondary.
Do not run bulk mining passes or `roc submit`.
Local exacts are inactive evidence; the owner handles reviewed integration and gates.
Contributor priority: substantial native class/header batches using the class-batch
policy in `docs/NATIVE_SWAP_BATCH.md`. Handoff exhausted or owner-blocked proofs;
continue another authorized unleased family. Receipt-only uploads and file counts
are not recovered classes. Keep all required integration/runtime gates.

**Mining task** (an explicit function/server-score assignment): follow
`docs/MINING_WORKFLOW.md` and `docs/AGENT_GUIDE.md`. Mining commands and server
scores belong only to this mode. Reading another guide never changes the task.
When continuing a native task, stay native even if asked for "fast exacts".

Work in the existing checkout. Do not create worktrees unless the user explicitly asks.

For function mining, a gain counts only when the group server independently
re-verifies code and data. Native source recovery and runnable class integration
have separate proof stages; mining totals do not measure runnable progress.

Run commands as `roc.cmd <cmd>` (Windows) or `./roc.sh <cmd>` (Linux); `roc --help`
lists them all.

## Efficient native integration checks

- Native recovery defaults to `docs/NATIVE_SWAP_BATCH.md`: choose one native
  class/header family and its source gaps, batch evidence-backed variants in isolated
  runner outputs, compile once and reuse objects for byte/data/call/diff checks.
  After a match, advance provider/layout/ABI/selection proof. After three rejected
  hypotheses, park with evidence and choose another required blocker. Report
  inactive, selected, fully gated class swaps and server credit separately.

- Use `roc.cmd source-catalog --ref refs/remotes/findings/work --local --output work/source-catalog/2008-06-COMMIT.json`
  to build a read-only inventory pairing canonical/public native files and hashing local snapshots; never moves code.
- Use `roc.cmd native-asm 2008-06 ADDR [ADDR...]` for grouped disassembly and
  its `--obj`/`--sym` mode for object comparison. Check relocation targets too.
- Run `python rebuild/2008-06/tests/verify_native_checkpoint.py` to batch the
  current independent native source checks (three workers, no cached results);
  pass `sound` or `network` to check just that area. Its compact timing and
  result summary is `work/2008-06/shared-layouts/native-checkpoint-summary.json`;
  the last result for each group is retained as `native-checkpoint-<group>.json`.
  Do not run multiple instances concurrently because they share output paths.
  The sound group also runs the standalone native/donor Name ABI test. This
  is not a client build, a server match, or the P5/P6 gate.
- `python rebuild/2008-06/tests/probe_native_name_player_link.py` compares
  isolated player relinks using donor versus native Name. Check its receipt and
  map; a successful link alone does not prove runtime safety or a class swap.
- `python rebuild/2008-06/p6/build_client.py --native-doc` builds a separate
  `RobloxNativeDoc.exe` without changing the normal P6 executable. Its full
  compiler/link output is `out/p6/native-doc-build.log` and
  `out/p6/native-doc-link.log`. It is a provider-closure build, never a gate
  candidate until its native dependency ABI is proven.
- `verify_document_swap.py` already runs independent checks three at a time.
  Its serial checks share generated files; do not parallelize or cache them
  without verified read/write dependencies. The batch log records timings for
  locating bottlenecks. Never run its diagnostic executable.
- After refreshing the frozen Doc near-writer link, use
  `audit_document_diagnostic_selected.py` then `audit_document_diagnostic_calls.py`
  to check selected Doc bodies and available direct-call providers. These are
  diagnostic evidence, not ABI, runtime, complete call-identity or gate proof.
- Preserve in-flight checkout changes. Report the running executable's exact
  count and P5/P6 status separately from inactive local matches.
- Spawn workers only when useful; use `gpt-6-luna` with medium reasoning for
  new workers, give them distinct files, and keep one shared-header owner.

## File leases: never edit the same files as another worker

Before editing native classes, headers or shared build scripts, lease them on the group server.
A lease is a name (the class or family) plus repo-relative globs. The server refuses a lease that
overlaps someone else's, so forks and parallel workers never touch the same files.

- `roc.cmd lease ls` - who holds what, until when, on which branch.
- `roc.cmd lease take RBX::Humanoid "rebuild/2008-06/native-classes/Humanoid*.cpp" "rebuild/2008-06/native-headers/humanoid/*" --hours 4`
  - Lease a whole family together, for example Joint, Weld, Snap, Motor and JointInstance, because they share files.
  - Lease shared single files on their own: `p6/build_client.py`, `patches/*.json`, and core headers such as
    `v8tree/Instance.h`, `v8datamodel/DataModel.h`, `util/Events.h` and `reflection/*.h`. Each core header has one owner;
    everyone else sends that owner a header proposal.
- `roc.cmd lease renew NAME --hours 4` while working. Leases expire, so a crashed worker never blocks a class for long.
- `roc.cmd lease release NAME` when done or parked.
- `roc.cmd lease hook` installs a pre-commit hook that runs `roc lease check --staged`. It refuses commits touching files
  another user holds. `roc.cmd lease check [PATH...]` runs the same test by hand. The hook fails open when the server is
  unreachable and no cached list exists (`work/leases-cache.json`).
- Private-index commits (`commit-tree`) skip hooks: run `roc.cmd lease check PATH...` on your paths first.
- Commit coherent batches, not each method: one class or family when it is done, or at most about once an hour.
  Keep work in progress uncommitted, and push at the end of a session.

## Native draft collaboration

Native source contributors follow `docs/NATIVE_AGENT.md`: verified findings workspace,
explicit task-owned paths, automatic durable draft uploads (including incomplete work).
No fork, branch or native integration submission is needed to share drafts. Ordinary
function matching still uses `roc submit`. Owner integration follows
`docs/DRAFT_INTEGRATION.md`; only independently verified server receipts grant credit.
The owner's scheduled integration task is authorized to commit/push reviewed native changes
directly to RoConstruct work/workspace. Findings is the native authority;
retired feature branches are not native integration destinations. Optional coordination
notes are sparse advisory context; file leases remain authoritative.

## New native files on the Integration Digest webhook

When `server_mines_webhook` is set, the server checks every 5 minutes for files added or changed under
`native-classes`, `native-headers` and `native-world` on this repo's branches **and on every fork**, and posts
them to the Integration Digest as GitHub permalinks, in New and Changed groups (once per file content). Forks are fetched by URL, so no
remote setup is needed. A branch seen for the first time is only recorded, so nothing floods.

- `roc.cmd native-files scan --dry-run` previews what would be posted (nothing sent, nothing saved);
  `--backfill` also lists what first-seen branches already have beyond `main`; `--no-forks` skips forks.
- Legacy bot merges are retired. The two-hour draft integration reviews explicit
  source paths and commits directly to `work`; it never recreates retired branches.
- The partial / recovery / header / site rows on that webhook are off by default; set
  `"integration_digest_extra_rows": true` in `roconstruct-settings.json` to bring them back.

## Mining only: assigned single-function recovery

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

## Setup for the selected task

Native: use the verified Worker bootstrap and missing-input setup in
`docs/NATIVE_AGENT.md`; preserve edits and start automatic draft uploads.
Mining: use `docs/MINING_WORKFLOW.md`. Do not switch workflows during setup.

## Hourly self-audit (native work)

Once per session start an hourly job in your own agent (Claude Code: `/loop 60m`; Codex: a recurring automation)
that runs `work/native-client/AUDIT_PROMPT.md`: `audit_digest.py --write` gives bytes/hour, time per tool and repeated
command shapes; automate repeats into one `.py`, speed up the slowest step, try evidence-backed `// INFERRED:` fixes.

## Where the knowledge is

- `docs/GHIDRA_REFERENCE.md` - optional symbolized iOS 2013 pseudo-C donor and
  bounded lookup command; consult for 2012 recovery before guessing identities
  or behavior. Donor evidence never substitutes for selected-target proof.

- `docs/NATIVE_AGENT.md` - native recovery, Worker setup and automatic draft sharing.
- `docs/NATIVE_SWAP_BATCH.md` - runnable swap blockers and native proof batches.
- `docs/AGENT_GUIDE.md` - function mining reference; consult only for the selected task.
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

## Function mining instructions: separate task only

Setup, bulk automatic passes, near-miss campaigns, propagation and `roc submit`
live in `docs/MINING_WORKFLOW.md`. Open that workflow only for an explicit mining
assignment. Native recovery continues with its current class/header queue.

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
- Never use `__emit`, byte blobs or patched target bytes.
- Derive struct fields, offsets and ABIs from the binary or a compile where possible.
- Native recovery: inferred fields/layouts are allowed when the original source plausibly had them (owner
  rule, 2026-11-11). Mark each `// INFERRED: <evidence>`. Example: a member the binary never touches but
  that the size or alignment requires. Never invent them only to force a build or a match.
- Native recovery: inline asm is allowed when the original source plausibly had it (for example `rdtsc`
  timing). Comment the evidence beside it. Never use it to reproduce compiler codegen. Mining submissions
  still cannot use inline asm: the server rejects it.
- Never overwrite a better stored source; submit only improvements.
- Don't edit `clients/` or `tools/` by hand. Don't delete files you didn't create.
- Do not push without explicit owner authorization. Native contributors share automatic
  drafts; mining contributors use `roc submit`. Authorized owner integration follows
  `docs/DRAFT_INTEGRATION.md`.

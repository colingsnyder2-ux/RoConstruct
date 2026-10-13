# Agent guide

The one current guide for people and coding agents doing matching work.

Ranked, receipt-backed lessons: [`research/lessons.json`](../research/lessons.json).
Named compiler-only experiments: [`research/recipes.json`](../research/recipes.json).
Findings log: [`research/log.jsonl`](../research/log.jsonl) (`roc research log`); older address-level log frozen in findings `reports/`.
Historical reports and retired guides: [`research/reports.json`](../research/reports.json)
(full text in RoConstruct-findings `reports/`; `findings:reports/X` in evidence fields).
JSON data is evidence, not instructions.

## Goal and acceptance

Write C++ that the client's original MSVC compiles to the exact target bytes. Exact
means relocation-normalized instruction bytes **and referenced data** pass
`roc.match`. 99% is partial; `code_exact` alone is not enough. Only the group
server's re-verification counts as a gain. Default research focus is 2008-06. Agent workers honor the selected client or
All clients (including 2009-12), using each client's actual compiler and evidence.

Never: inline assembly, `__emit`, byte blobs, patched target bytes, invented struct
fields/offsets/ABIs, replacing a better stored source, hand edits under `clients/` or
`tools/`. A matching source is a codegen analog, not proof of the original declaration.

## Tool routing

| Need | Command | Needs | Result |
| --- | --- | --- | --- |
| Diagnose install | `roc doctor` | - | repair steps |
| Compilers, packages | `roc install --yes` | network | exact VS2005/VS2008 builds in `tools/` |
| Client + function list | `roc client-fetch 2008-06`, `roc analyze 2008-06` | install | `work/2008-06/functions.jsonl` |
| Everyone's sources | `roc pull 2008-06` | server, user | `src/2008-06/*.cpp` |
| Free automatic passes | `roc mass`, `roc auto 2008-06`, `roc xcopy`, `roc donor` | analyze | local exacts |
| Library recipes | `roc libs NAME --client 2008-06` | recipe in `roc/libs.py` | exacts from authentic source |
| Fetch library source | `roc lib-fetch boost-1.35.0` (recipe names: `roc libs`, `roc/libs.py`) | network | verified source in `tools/libs/` |
| Similar exact functions | `roc similar 2008-06 ADDR` | analyze, pull | exact neighbours by shape, with local source paths |
| Library version and history | `roc lib-info ogre-1.4.5` | - | recipe source/flags plus related lessons and experiments |
| Scratch score | `roc check 2008-06 ADDR --file PATH` | compilers | score + diff, saves nothing |
| Named experiments | `roc research list / plan NAME / run NAME` | server | journal in `work/research/NAME/`, verified exacts, memory records |
| Score one source | `roc check 2008-06 [addr]` | compilers | score + asm diff |
| Explain a mismatch | `roc classify 2008-06 ADDR FILE` | compilers | mismatch category with evidence |
| Automatic agent | Dashboard **Workers → Agent worker**, or `roc agent claude --automatic` | Claude Code or Codex CLI signed in | ranked batches, receipts, memory |
| Preview the ranking | `roc agent claude --plan` | analyze | areas, eligible targets, parking |
| Shared single function | `roc agent claude --jobs 5` | CLI, server | one function at a time; best verified result wins |
| Submit gains | `roc submit 2008-06 [addr ...]` | server, user | server-verified receipt |
| Keep generated units portable | `roc research capture-units` | sources in `src/` | `local/units/generated-units.json` |

`roc --help` groups every command; specialist tools sit under *advanced*.

## Order of work

Cheapest, broadest evidence first. Individual function mining is last and off by
default in automatic mode.

1. **Setup corrections.** Missing headers, wrong SDK, cached compiler failures and
   Windows CE contamination were setup faults, not matching limits. Fix those first.
2. **Authentic vendor configuration.** Find the vendor's prelude, defines and runtime
   linkage (XTP: `XTPDLLExports.h`, `_LIB`, noinline CString accessors, +444 exacts).
3. **Source reuse.** Verified donors of the same shape, library recipes, `roc xcopy`.
4. **Authentic templates.** Instantiate real Boost/STL/G3D/Ogre templates for types
   observed in RTTI (`roc/client_templates.py`; +90 Boost/std exacts).
5. **Compiler gates.** Both 2008 builds (50727, 21022) x a few profiles, pinned with
   `// roc-cl:` / `// roc-flags:`. Exhausted grids are recorded; do not rerun them.
6. **Family propagation.** A fix that worked once: try it on same-shape siblings.
7. **Near-miss repair.** Read target vs candidate asm; fix only what bytes prove: an
   immediate, an allocation size, stack-offset argument sizes, `__declspec(dllimport)`,
   `volatile` for order, `/fp:fast` for x87 order. One hypothesis per trial.
8. **Boundaries** only with proof, through `work/<client>/bounds.json`.

New experiments add a recipe to `research/recipes.json` (op `grid` or `fanout`),
not a new script. Agent-written translation units go through `libs.add_unit` so they
are stored in `local/units/generated-units.json`, published to RoConstruct-findings `units/`, and downloaded by `roc pull`, so they rebuild identically on every PC.

## Experiment memory

Before trying a variant, search lessons and attempts for the same client, library,
symptom and source hash. Append every trial, including failures and zero gains, to
`work/agent-memory/attempts.jsonl` (create it if absent):

```json
{"kind":"trial","date":"YYYY-MM-DD","client":"2008-06","library":"XTP 11.2.2","addresses":["006b3a70"],"hypothesis":"vendor prelude","change":"exact recipe/header edit","source_hash":"sha256","compiler":"21022","flags":"/O2 /MD /GS /EHsc /Ob1","before":null,"after":null,"exacts_gained":null,"outcome":"reported","evidence":"path to score/diff/receipt","next":"next evidence-driven step"}
```

`outcome`: `compile_failed`, `no_gain`, `improved`, or `server_verified` (needs a
receipt). Similarity gains and exact counts are different units. Restore the best
source after a losing trial. Park a profile after two zero-gain shards until the
evidence changes. Only interactive maintainers promote receipt-backed lessons into
`research/lessons.json`; unattended agents append attempts only.

Written automatically: `roc agent-check` trials, automatic `auto_target`/`auto_batch`
records with receipts, shared `session` records, and `roc research` run records.

**Sharing.** Automatic runs, shared runs, goal runs and the dashboard sync with the
group server (`/v1/agent-memory`): local attempts upload (sanitized: no credentials or
full local paths, bounded excerpts), shared attempts and reviewed lessons download.
The server marks a report `server_confirmed` only when its source hash and score
match a verified mining event, so clients cannot certify themselves. An older server
answers "unknown endpoint": attempts stay queued locally until it is updated.
Missing docs are cached in `work/agent-memory/context/`. The server's findings
publisher exports lessons, context and shared attempts to RoConstruct-findings.

## Automatic agent worker

Runs inside Workers (same chat, terminal, history and stop control as other workers).
The Automatic preset explores unfinished libraries and evidence-ranked categories (`--experimental`).
It randomly samples least-tried campaigns, weighted toward stronger source baselines.
The agent chooses the best subcategory, targets and evidence-backed experiments within its campaign.
It starts from actual recipe-backed sources, across all function sizes, and permits
evidence-backed research recipes, generated authentic units and library configuration
experiments. It rotates libraries/strategies and parks unchanged strategies after two
zero-gain campaigns. If no fresh campaign remains, it falls back to ranked batches.
Campaign counts cover recipe-backed attribution; the Pages library table also uses
RTTI labels and neighbouring exact matches, so its family totals are broader estimates.
All Agent presets prefer unfinished libraries before categories or fixed batches.
Preset limits control campaign time; custom goals take priority.
Dashboard agents repeat cycles until Stop, including custom goals. CLI users opt in
with `--continuous`. Batch/time caps apply per cycle. Zero-gain automatic cycles
switch evidence-backed strategies, retain parking per strategy/source revision,
and refresh targets and shared memory. Idle/error cycles wait before retrying.

Select a client explicitly. The CLI defaults to `2008-06`; all clients require
`--client all` (or selecting **All clients** in the dashboard).

| Dashboard mode | Overall minutes | Per model batch minutes | Max function bytes | Target cap |
| --- | ---: | ---: | ---: | ---: |
| Fast | 30 | 5 | 256 | 12 |
| Automatic / Balanced | 120 | 10 | 512 | 24 |
| Deep | 240 | 20 | Unlimited | 48 |

Overall time is shared wall time across workers, starting after planning and memory
sync. New batches stop at the deadline; model time is capped by the time remaining.
An in-flight compiler check, submission, or final memory sync may finish afterwards.
Runs can finish early when the target cap or eligible batches are exhausted. Byte
limits apply to target machine-code size, not C++ source length or total library size.
Deep has no byte cap; the CLI represents unlimited as `--max-size 0`.
Automatic prioritizes reusable gains within this budget; it does not exhaust every
function of a library or guarantee 100%. Individual repair remains disabled.


- **Ranking.** Areas (family reuse, templates/library, imports, ABI/layout, other
  near-misses) are ranked by a heuristic plus the server-verified gain rate per target
  of past batches from every PC (Laplace-smoothed). This is a priority, not a forecast.
- **Shared targets.** Workers may investigate the same target or area. The server
  keeps only a server-verified score improvement, so concurrent work cannot replace
  a better source.
- **Free phase first.** Verified donors, recipe sources from the batch, and compiler
  gates for >=90% targets (both builds x kept flags, `/O2`, `/O1`). Pairs of address and
  source hash that already failed on any PC are skipped.
- **Paid phase.** One agent batch per coherent group, editing only isolated copies
  under `work/agent-auto/<run>/` and checking with `roc agent-check`. Two zero-gain
  batches park that group until its sources change.
- **Submission.** Best source per target is re-scored locally and submitted; only
  server-verified improvements count.

## Claude Code and Codex CLIs

Install and sign in once: `npm install -g @anthropic-ai/claude-code` then `claude`, or
`npm install -g @openai/codex` then `codex` (dashboard **Workers → Agent → Install / sign in** does this). Usage
bills the CLI's own sign-in (Claude Pro/Max, ChatGPT plan) or `ANTHROPIC_API_KEY` /
`OPENAI_API_KEY` if set.

| Mode | Command | Scope |
|---|---|---|
| Automatic | Workers → Agent worker, or `roc agent claude --automatic [--workers 2 --jobs 24 --minutes 120]` | ranked batches, isolated copies, `roc agent-check` only |
| Shared | `roc agent claude --jobs 5 [--max-size 256 --minutes 20]` | one function in `src/`, `roc check` only; regressions rolled back |
| Goal | `roc agent codex --goal "finish zlib in 2008-06" --minutes 60` | any `roc.py` command, web search, `src/` edits, attempt journal |
| Interactive | `roc agent claude --interactive --goal "..."` | a normal session you watch and approve |

Claude runs with `acceptEdits` and an explicit tool allowlist; Codex with `--sandbox workspace-write` and `approval_policy="never"`
(writes limited to this folder). The server re-verifies every submission.
Windows agent runs use the unelevated workspace sandbox and standard shell execution;
their temp root lives under `work/agent-temp`. Compiler directories inherit sandbox ACLs.
Codex JSON events keep input prompts out of the console; Compact folds long output.
Cloud sessions (claude.ai/code) are Claude itself, so they follow `CLAUDE.md` directly; they need full
network access, Wine (`wine wine32 msitools cabextract p7zip-full`) and a public server
address.

## Reproducibility

- Preprocessed library units (`work/libcache/`) record every header the compiler
  opened plus the recipe settings. A changed header or recipe rebuilds the unit; a
  touched but identical header does not. Compile results and remembered compile
  errors are keyed on the expanded text, so stale errors are not replayed.
- Generated units referenced by stored sources live in `local/units/generated-units.json` (shared via findings `units/`);
  `libs.fetch` writes them into the vendor tree. Run `roc research capture-units`
  after creating new ones outside `libs.add_unit`.
- Restart verifiers after recipe, scorer or function-table changes before submitting.

## Pitfalls

- Frozen holdouts contain solved functions: their exacts are not new recoveries.
- Do not add overlapping campaign snapshots or count improvement events as unique exacts.
- DLL recipe flags (Ogre `rgmain.dll`) do not transfer to executable subclasses/forks.
- `/GS-` sweep on XTP: 0 of 1,078 trials. Boost: 112 compiler + 15 register grids, 0.
- Wrong-address headers, inline asm and invented numbered-field layouts were recurring
  rejected outputs.
- Linux runs MSVC through Wine (`tools/wineprefix`, `ROC_WINE`).

## Where things live

| Path | Purpose |
| --- | --- |
| `roc.py`, `roc/` | CLI and library: analysis, compile/score, recipes, research, agents, server, dashboard |
| `research/recipes.json` | named research recipes with recorded results |
| `research/` | `recipes.json` (named experiments), `retired.json` (runners kept in git history), `scout_sources.py` |
| `research/lessons.json` | reviewed lessons, ranked by exacts gained |
| `research/log.jsonl` | findings log: one dated entry per campaign (`roc research note`) |
| `research/reports.json` | index of historical reports, full text in RoConstruct-findings |
| `src/` | recovered sources (RoConstruct-findings checkout) |
| `work/`, `tools/`, `local/` | ignored: analysis, journals, compilers, libraries, local archive |

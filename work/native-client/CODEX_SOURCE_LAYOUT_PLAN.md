# Codex plan: native source layout cleanup (2008-06)

Goal: turn `rebuild/2008-06/native-classes` + `native-headers` (1,653 + 434 files today) into a
source tree that looks like Roblox's own 2007/08 tree — original file names and folders, one
.cpp per original translation unit, no recovery artifacts — **without changing a single byte of
generated code** and without disturbing the naming / LLM lanes running in parallel.

## Ground truth for the layout (already in the repo, nothing to download)

- `work/native-client/webservice-pdb-source-paths.txt` — 1,788 original source paths recorded in
  `WebService.pdb` (RBXGS 0.3.676, built 2007-12-20 from the same engine tree; PDB extracted from
  `tools/rbxgs_msi/rbxgs676.msi`). Lower-cased. Shape:
  `client\app\v8datamodel\*.cpp`, `client\app\include\v8datamodel\*.h`, `client\app\v8world`,
  `client\app\v8tree`, `client\app\util`, `client\app\gui`, `client\app\humanoid`,
  `client\app\lua-5.1.1\src`, `client\rbxview`, `client\network`, `client\rendering\appdraw`,
  `client\rendering\renderlib`, `client\rendering\g3d\...`.
- `tools/openrbx/Client/**` — public OpenRBX decompilation of the same era: original-case file
  names (PDB paths are lower-case), file-level style, `#pragma once` / include conventions.
- `work/native-client/identity_unlock_pdb.py` — reads WebService.pdb publics + module procs.
  Extend it (see "Line info" below) instead of writing a new PDB reader.
- Do not use the 2016 leak for layout; the 2007 PDB paths are authentic and closer in time.

## Hard rules

1. Codegen must not change. Every move/merge/cleanup batch proves, per translation unit, that the
   compiled `.obj` code+data sections and symbol tables are identical before and after
   (relocation targets compared by symbol name). Any diff → revert that file.
2. Lease before touching: `roc.cmd lease take <family> <globs> --hours 4`. One family per batch.
   Core headers (`v8tree/Instance.h`, `v8datamodel/DataModel.h`, `util/Events.h`,
   `reflection/*.h`) only through their lease owner.
3. Do not edit: `work/native-client/native_llm.py`, `native_transplant_*.py`,
   `native_identity_evidence.py`, `native_template_gate.py`, `roc/server.py`,
   `work/2008-06/identity-registry.json`, any `identity_unlock_*.py` / `unnamed-identities*.json`
   (owned by the identity-unlock session), `clients/`, `tools/`.
4. `git mv` only (keep history). Never delete a file you did not create; a file made redundant by
   a merge is moved to `rebuild/2008-06/native-classes/_merged/` with a pointer comment, and the
   owner deletes later.
5. Keep every `// INFERRED: <evidence>` comment and every authentic inline-asm evidence comment.
6. No `__emit`, byte blobs, or patched bytes. Commit per family; never push.

## Phase 0 — start now (read-only, zero interference)

1. **Path-consumer inventory** → `work/native-client/layout/consumers.json`. Grep every place
   that names native source paths: `rebuild/2008-06/p6/build_client.py`, `patches/*.json`,
   `rebuild/2008-06/tests/*.py`, `verify_document_swap.py`, census / identity binding JSONs,
   `docs/source-links.json`, `work/native-client/prove-out` (feeds the website — read only),
   lease globs, the Integration Digest scanner (`roc native-files scan`). For each: file, how the
   path is used (literal, glob, derived), and how it must be rewritten.
2. **Function → original file map** → `work/native-client/layout/function-files.json`.
   - Extend `identity_unlock_pdb.py` to read C13 line info (DEBUG_S_LINES + DEBUG_S_FILECHKSMS in
     each module stream): every WebService function → source file + first line.
   - Exe functions with the same decorated name (registry + `unnamed-identities.json`) inherit
     that file and line. Order within a file = PDB line order (cross-check with link order in the
     exe; they should agree).
   - Functions not in WebService (client-only: MFC app, IDE, XTP glue): owner class → header
     from the PDB path list, else OpenRBX path, else `client\app\<area>\<Class>.cpp` by the
     class's namespace/area, flagged `inferred_path`.
3. **Rename map (dry run)** → `work/native-client/layout/source-layout-map.json`:
   `{current_path: {target_path, evidence: pdb|openrbx|class-rule, merge_group, case_source}}`.
   Original-case names from OpenRBX / header `class` spelling; folders from PDB paths.
   Flag conflicts (two current files → same target with overlapping definitions).
4. **Artifact lint** → `work/native-client/layout/native_lint.py` + report JSON. Detect, never fix
   yet:
   - recovery-unit names: `AppUnit*`, `AppLeaves2008*`, `*2008.cpp` suffixes, `roc_*`, hashes in
     file names, `vendor_i*`;
   - LLM / tool residue: `FUN_`, `sub_`, `func_`, `LAB_`, `recovered*`, `Native*` invented names,
     `// TODO(llm)`, generated banners, Ghidra casts (`(int)(char)`), `undefined4`, `CONCAT`,
     `unaff_`, `in_stack_`;
   - duplicate definitions of one symbol in several files; stub bodies; `#if 0` blocks;
     unused local helper copies of real headers; include of `roc_*` scratch headers;
   - style drift from OpenRBX: header guards vs `#pragma once`, include order
     (own header first), namespace block style, tabs vs spaces, brace style.
5. **Plan report** → `work/native-client/layout/PLAN_REPORT.md`: counts per category, the merge
   groups, expected file count after cleanup, risky items.

## Artifact taxonomy (survey 2026-11-16, native-classes + native-headers)

| Artifact | Files | What it is | Removal rule |
|---|---|---|---|
| Explicit class instantiations `template class X<...>;` under "Template members emitted by this unit" | 248 | Scaffolding: forces this TU to emit template members the original emitted implicitly from code not recovered yet | Remove a line only when a build without it still defines every member it emitted (per-symbol check against the final link map / object set). Mostly Phase 4. `template class` also emits members the original never used; harmless under /OPT:REF but not authentic. |
| Explicit function instantiations `template R T<...>::f<...>();` | 158 | Same, for single members (e.g. `Creatable<Instance>::create<RunService>`) | Same rule |
| `#pragma auto_inline/optimize/intrinsic` | 72 | Codegen steering to reach byte match | Keep only with donor/OpenRBX evidence (e.g. rbxgs). Otherwise flag: usually a wrong per-TU flag set or wrong TU grouping; retry without after Phase 3 merges |
| `__declspec(noinline)` | 82 | Same; some already marked `INFERRED` with donor evidence | Same |
| Placeholder identifiers in code (`entity->func_0067d3d0()`) | 6 | Calls to functions with no real name yet | Replace with identity-tier names (`unnamed-identities.json`, then inferred tier, flagged) |
| Placeholder names in comments (`func_`, `sub_`, `FUN_`) | ~127 | Recovery notes | Move to sidecar evidence |
| Address / evidence comments (`// Original 00405aa0 ...`, batch notes, "Batch 17 rejected") | 715 | Proof notes | Move into a per-function sidecar (`<file>.evidence.json`: address, size, proof receipt, notes); keep short `// INFERRED:` lines in source |
| Provenance banners ("mined exact source ... verbatim", `roc_*` source ids) | ~66 | Tool provenance | Sidecar / build table |
| `#if 0` blocks | 18 | Dead experiments | Remove (codegen-neutral, still verify) |
| File names `AppUnit*`, `AppLeaves2008*`, `*2008*.cpp`, `Mined*`, `vendor_i*`, `accepted/` subtree | ~140+ | Recovery-unit names | Phase 2 rename map |
| Ghidra residue (`undefined4`, `CONCAT`, `unaff_`) | ~0 | none found in code (matches were prose) | lint keeps watching |

Explicit instantiations and codegen pragmas are load-bearing today: removing them can break the
link or change bytes. They are the last artifacts to go, and only per-symbol / per-function proof
removes them.

## Phase 1 — tooling (now; still no moves)

1. `layout_apply.py --dry-run|--apply --family X`: applies one family from the map (git mv,
   rewrite includes, rewrite every consumer from consumers.json, update lease globs in its own
   lease only).
2. `layout_verify.py --family X`: compile each touched TU before/after with the recorded flags,
   compare sections + symbols + reloc targets; run `python rebuild/2008-06/tests/verify_native_checkpoint.py`
   (never two instances at once); report P5/P6 status unchanged.
3. Make the native LLM lane / transplant tools **write new files at the mapped target path**
   (send the proposal to the owner of `native_llm.py`; do not edit it).

## Phase 2 — moves (owner-scheduled freeze window per family)

Order: leaf families first (gui, tool, humanoid, util), then v8world, v8datamodel, rbxview / app
(MFC), network, rendering; core-header families last.
Per family: lease → `layout_apply --apply` → `layout_verify` → commit
"layout: <family> to original paths (codegen identical)".

## Phase 3 — combine and clean (after each family is moved)

1. **Merge split units** into their original TU (e.g. `AppLeaves2008DHTMLWindow*.cpp` →
   `client/app/.../DHTMLWindow.cpp`), functions ordered by PDB line order. Watch for things a merge
   can change: static-init order, anonymous-namespace collisions, COMDAT selection, `#pragma`
   state, `/Ob` inlining across now-shared statics. Prove identical codegen per function; if a
   merge changes bytes, keep the split and record why.
2. **Remove artifacts** found by the lint (Phase 0.4) where removal leaves codegen identical:
   tool comments, invented helper names (rename to the real name when the identity tiers have
   one), dead `#if 0`, duplicate helper copies → include the real header.
3. **Style pass** to OpenRBX conventions (formatting only, verified identical objects).
4. Headers: one header per class at `client/app/include/<area>/<class>.h` (PDB path), declarations
   ordered like the vtable / PDB, `// INFERRED:` kept.

## Phase 4 — when naming/integration finishes ("add the rest")

1. Re-run Phase 0.2/0.3 on the final registry + `unnamed-identities.json`; every new native file
   lands directly at its mapped path (no new `AppUnit*` files).
2. Inferred-tier names (`unnamed-identities-inferred.json`, flagged) stay in a clearly marked
   `// INFERRED NAME:` comment block per function; a later pass swaps them for real names as the
   identity tiers promote them (script: re-apply names from the tiers, rebuild, verify identical).
3. Produce an export tree `out/source-tree-2008-06/` laid out exactly like the PDB paths
   (`client/app/...`, plus a VS2008 `.vcproj`/solution listing files in original folders) for
   reading/browsing; the repo tree stays the build authority.
4. Write `docs/SOURCE_LAYOUT.md`: mapping rules, evidence types, how new files get their path.
5. Repeat for 2009-12 with its own PDB/OpenRBX evidence (separate map; never mix clients).

## More ideas worth doing

- **PDB line info → exact TU membership** also gives link order per object; use it to split
  `AppUnit*` files that hold several original TUs.
- **Per-TU compiler flags**: functions grouped by original TU should share flags; outliers in a
  merged group flag a wrong merge or a wrong grouping.
- **Static/global data placement**: PDB module streams (S_LDATA32/S_GDATA32) name each TU's
  statics → move globals into the right file.
- **Header include graph** from PDB checksum lists per module (which headers each original .obj
  included) → reproduce original include lists.
- **Lint as pre-commit hook** for native paths (warn-only) so new LLM drafts stop reintroducing
  artifacts.
- **Website**: show original path per function (from function-files.json) next to proof status.

## Paste-ready Codex prompt

> Read `work/native-client/CODEX_SOURCE_LAYOUT_PLAN.md` and do Phase 0 and Phase 1 only. Outputs
> go under `work/native-client/layout/`. Read-only on every native source file; no moves, no
> edits outside `work/native-client/layout/`. Respect the hard rules and the do-not-edit list.
> Commit locally in one batch when Phase 0 reports and Phase 1 tools are done; do not push.
> Report: consumer count, mapped files by evidence type, artifact counts, merge groups, and the
> proposed family order for Phase 2.

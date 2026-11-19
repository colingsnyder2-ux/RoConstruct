# 2008-06 source layout: phases, plan and status

Status as of 2026-11-18. Source of truth for the plan is `work/native-client/CODEX_SOURCE_LAYOUT_PLAN.md`;
the running log is `work/native-client/layout/PHASE_STATUS.md`. This file is the one-page summary.

## Goal

Turn the native recovery tree (`rebuild/2008-06/native-classes` and `native-headers`, about 3,100
files) into a source tree that looks like Roblox's own: original file names and folders, one
`.cpp` per original translation unit, no recovery artifacts, with no change to generated code.
The end state is a source-only client that rebuilds a byte-identical `Roblox.exe`.

## Decision that shaped the work (2026-11-17)

Live files are **not moved**. 358 live scripts read `native-classes/` and `native-headers/`
(drafts, the digest scanner, coverage tools, LLM lanes), so a move would drop files out of all of
them. Instead a generated **export tree** is written to `rebuild/2008-06/layout/` and published on
branch `layout/2008-06`. Phase 2 (in-place moves) is replaced by this export.

## Phase table

| Phase | What it is | State |
| --- | --- | --- |
| 0. Inventory | Map every file to an original path; lint for recovery artifacts | Done; rerun by the pipeline |
| 1. Tools | Apply, verify, export and compare tools | Done; 63 tests pass |
| 2. Moves | In-place `git mv` per family | Replaced by the export tree (see above) |
| 3. Merge and clean | Join split pieces into their original file; strip scaffolding | Partly done: 108 merged units; cleanup runs on every export |
| 4. Final tree | One consistent tree, one header per class, builds as a tree | Started: tree check passes for most units; failures and held headers remain |
| 5. Source-only client | Build `Roblox.exe` from source only, and make it run | Not started |
| 6. Byte-exact executable | Full-file SHA-256 equal to the original | Not started |

## Current numbers

Branch `origin/layout/2008-06` at `6ff796401f`: **479 files**.

- **Code bytes with source in the export:** 15.93% of 3,742,156 bytes.
  - original path (main tree): 226,870 bytes, 119 files
  - inferred path: 104,653 bytes, 85 files
  - merged unit, complete: 61,574 bytes, 29 files
  - merged unit, partial: 203,100 bytes, 79 files
- **Merged units:** 108, built from 268 pieces; 79 are partial.
- **Proof for single `.cpp` files:** objects identical to their live originals (204 files).
- **Website** (`docs/`, from `integration.json`): Authentic 6.04% and Organized 9.83% of code bytes.
  Authentic is the main tree with an identical object. Organized is the inferred-path files and merged units.

Files held back, by reason: no original path 1,866; merge or conflict 822; wrapper around donor or
library source 15; inferred path with no folder evidence 12; variant header 11; changed since map 6;
identity review 5.

## Phase 3: merge and clean (what exists)

- **Cleanup:** recovery notes (addresses, compiler-flag pins, donor and proof remarks) move to
  `evidence.json`. `// INFERRED:` lines stay. Whitespace is tidied. A cleaned file is kept only if it
  compiles to the same object; otherwise the verbatim copy is published.
- **Merges, in the order tried:** whole group; reversed piece order; each group minus one piece;
  greedy largest provable subset. Redefinition errors are repaired by dropping the duplicate block.
  A merge is kept only if every function and data symbol of the pieces comes back byte-identical
  with the same relocation targets.
- **Limit of the proof:** link order and initializer order are not proven for any merged unit.
- **Left over:** 26 groups do not compile once joined (conflicting local definitions), 27 compile
  but the code differs when joined, 56 are not attempted (target under `unclassified/`), and 228
  pieces are left out of partial merges. These need per-group source edits.

## Phase 4: final tree (what exists and what failed)

The **tree check** compiles each exported unit against the exported headers first and requires the
same object (single files) or the same symbols (merged units) as the live source.

- **Result:** 187 of 204 single files and 82 of 87 merged units pass. 98 of 167 exported headers are
  compile-proven by a passing unit.
- **Held back:** 11 variant headers (for example `v8world/Edge.h`, `v8datamodel/Surface.h`, G3D
  `Vector3.h`). The native tree has two versions of these, and an original-layout tree holds one.
- **Why singles fail:** 12 of 17 fail with a class defined twice (two copies of one header reached by
  different include paths); 2 fail for other compile reasons; 4 compile to different code.
  Targeted trials that remove the exported header defining the duplicated class are being tested.
- **Still to do for this phase:**
  - one canonical header per class (23 header names exist twice)
  - remove forced template instantiations, `#pragma` steering and `noinline` markers, one at a time
  - replace inferred names as real names arrive
  - export a browsable tree and a project listing; write `docs/SOURCE_LAYOUT.md`

## Phase 5: source-only client (blocked; ledger started 2026-11-18)

One build entry point over the cleaned tree producing `Roblox.exe` from source: no donor objects,
no extracted bytes, no stub shells. Track every function and data item still supplied by donor,
replay or stub objects until the list is empty. Runtime gates beyond P5/P6: launch, open and save a
place, physics steps, render a frame, run Lua, join a local server, IDE windows, a crash-free soak,
and behaviour diffs against the original exe on the same inputs.

## Phase 6: byte-exact executable (blocked; gap measured 2026-11-18)

Matching functions is necessary but not enough. The linker output must match too: code layout and
padding, ICF and `/OPT:REF` choices, `.rdata` (strings, RTTI, switch and EH tables), `.data` and
`.bss`, imports, `.reloc`, `.rsrc` (rebuilt from recovered `.rc` and assets), PE header fields, the
Rich header, and the debug directory. No post-link patching. Facts from the original: not
Authenticode-signed; linker 9.0; timestamp `0x485b465d`; the Rich header implies exactly 627 VS2008
C++ objects and 89 C objects, so the cleaned tree must end with that many translation units.

## What measures progress, and what it leaves out

- **The percentages above are against the whole 3.74 MB executable.** About 27% of it is library
  code that has no Roblox source path: XTP (Codejock UI, 22.8%), MSVC `std` (3.8%) and ATL/MFC
  (0.6%). Against the Roblox-owned part (about 2.7 MB) the same coverage is roughly 22%.
- **26% of the bytes are unnamed functions.** Naming gives a function its path but not its source.
  It still needs a native body that compiles to the same bytes.
- **The census file** that placement relies on (`prove-out/OgreNativeFull/checks.json`, owned by the
  recovery lane) does not list 5,276 integrated or exact addresses (23.1% of bytes), so the layout
  percentages are probably undercounted. This is unresolved.

## How to run

```powershell
# map, export, tidy, prove, tree check, local commit on layout/2008-06 (never pushes)
python work/native-client/layout/layout_pipeline.py --refresh --branch
# commit an existing export without rebuilding it
python work/native-client/layout/layout_pipeline.py --commit-only
# tests
python work/native-client/layout/test_layout.py
```

A full run takes from 15 minutes (warm caches) to over 3 hours when the machine is busy, because the
other lanes edit shared headers during compiles; the check runner then rejects those compiles. They
are retried once and otherwise left unverified, not counted as failures.

## Files

| File | Purpose |
| --- | --- |
| `layout_pipeline.py` | The one-command pipeline |
| `layout_export.py`, `layout_clean.py`, `layout_census.py` | Export, tidy, and placement from the census |
| `coff_compare.py` | Object and per-symbol comparison |
| `inventory.py` | Builds `source-layout-map.json` |
| `rebuild/2008-06/layout/` (branch `layout/2008-06`) | The export, plus `receipt.json`, `evidence.json`, `coverage.json`, `authentic.json`, `organized.json` |
| `PHASE_STATUS.md` | Dated log of every step |
| `work/native-client/CODEX_SOURCE_LAYOUT_PLAN.md` | The original plan |

## Open decisions

- Show a "Roblox-owned code" percentage next to the whole-executable one on the website.
- Per-header choice where the tree has two versions of one header.
- Whether to put workers on the 26 non-compiling and 27 code-changing merge groups (per-group source
  edits under file leases).
- The Phase 6 RSDS GUID: it is random per link, so reproducing it needs a build-environment hook on
  the linker. That is an owner decision, since post-link patching is forbidden.


## Phase 5/6 ledger (2026-11-18)
- Phase 6 needs 627 C++ and 89 C translation units (Rich header). The export holds 342 source files
  (133 original-path .cpp, 163 inferred-path .cpp, 46 .c) against 716 needed: 374 TUs short.
  The map names 454 distinct target .cpp/.c paths; the other 262 TUs have no name evidence yet.
- Phase 5 blockers, in order: (1) the 26% unnamed functions have no source; (2) 80 merge groups
  (478 KB) stay split, 0 of 12 whole-group trials passed; (3) header variants (camera-zoom overlay,
  Rect/Stats/Http/NetworkSettings held) must become one header set; (4) no eligible provider set:
  RBXGS donor sources are 2007 and unproven; (5) the first link trace (Build B, gates/mesh-pilot,
  56 undefined symbols so far) belongs to the other lane.
- Nothing here lets a source-only link run yet; no claim is made beyond the table above.

## Mesh-pilot undefined symbols by kind (2008-11-18, 56 total)
- 25 MSVC runtime and import symbols (CRT, std::exception, type_info, `__CxxThrowException`, `__imp_*`): come from the
  VS2008 toolchain libraries and the system DLLs, not Roblox source. A source-only build links them; nothing to recover.
- 2 global operator new/delete (`??2@`, `??3@`): CRT.
- 8 boost thread symbols (recursive_mutex, lock_error, call_once): third-party boost 1.34.1 source, vendor lane.
- 4 G3D: `System::alignedMalloc/alignedFree` (g3dcpp/System.cpp) and `Vector2::zero` (g3dcpp/Vector2.cpp) are exported
  at original paths and object-identical; `Vector3::xy` (g3dcpp/Vector3.cpp) is the next to check.
- 17 RBX: 7 NormalId-family symbols (util/NormalId.cpp, exported, original path); 10 Mesh and LevelBuilder symbols
  exist only under inferred/ (path not proven), so they cannot count as Authentic providers.
- So the real Roblox-source gap in this pilot is the 10 Mesh/LevelBuilder symbols and the proof of their original path;
  the other 46 are provided by exported sources or by the toolchain and vendor libraries.
- Checked: `Vector3::xy` is defined in the exported g3dcpp/Vector3.cpp (line 362). The G3D side of the pilot is covered.
- Mesh path evidence: `Mesh::allocVertex`, `freeVertex`, ctor and dtor sit in `RenderBaseMeshConstruction2008.cpp` (1 census vote) and
  `RenderBaseMeshVertices2008.cpp` (3 votes), both named `client/rendering/renderlib/Mesh.cpp` by OpenRBX case only, no PDB path.
  They merge into one `inferred/` unit, which counts as Organized. Authentic counts only single-file, original-path, object-identical
  exports, so merged Mesh stays out of Authentic whatever its path evidence.
- LevelBuilder and Bevel `build`: the pieces `ViewNewBevelMesh.cpp` and `ViewNewWedgeMesh.cpp` map to `unclassified/builder.cpp`
  (class-rule only, no path). Codex's two candidates (rbxview/quadvolume.cpp, renderlibnew/quadvolume.cpp) have no census votes. Unresolved.

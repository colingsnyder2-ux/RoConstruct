# Source layout phase status

This is a historical checkpoint, not a completion claim. Later findings and
current limits are in `CHECKPOINT_INPUTS.md`, `CONSUMER_STATUS.md` and
`MAPPING_REVIEW.md`. The user later instructed direct runs without wake-run.

| Phase | State | Remaining proof |
| --- | --- | --- |
| 0: inventory | Reports generated | Resolve path/membership ambiguity and review lint candidates before any migration |
| 1: tools | Prototypes tested; native validation blocked | Real frozen native compiler/link fixtures; checkpoint integration; reviewed consumer rewrites |
| 2: moves | Blocked | Live leases, per-family freeze, approved mappings and unchanged-TU proof |
| 3: merge/clean | Blocked | Phase 2 plus original TU evidence, per-symbol code/data proof and full-link placement |
| 4: final tree | Pending | Final registry, approved paths, source-only export and VS2008 project validation |
| 5: source-only client | Pending | Zero donor/replay/stub coverage and all required client/runtime gates |
| 6: exact executable | Pending | Complete source build, original layout/link/data/resources/debug reproduction and full-file hash |

The live lease request failed: the sandbox rejected the socket connection to
`http://127.0.0.2:8765` (WinError 10013). Cached leases are insufficient to acquire
ownership. No native file may be moved or edited until a live lease is available.

The wake-run launcher also failed before arming because it could not write its
job record under `C:/Users/colin/.codex/wake-runs/` (PermissionError). Native long
gates require this watcher, so none were launched directly as a workaround.

The requested local commit is blocked too: `git add` could not create
`.git/index.lock` (Permission denied). No task files were staged or committed.

Protected producer and identity scripts are being edited by other lanes. The
consumer inventory and OWNER_PROPOSAL.md identify their required path changes;
they remain untouched here.

No compiler, full link, P5/P6, runtime or exact-executable gate has passed in this
layout session. Tool regression tests alone do not establish native codegen proof.

Latest report: 2,361 files, 2,255 consumer files, 96 merge/conflict groups.
Mapping evidence: 224 PDB basename matches, 17 OpenRBX matches, 251 inferred;
1,869 unmapped. The PDB reader agrees with all 17,594 existing procedure records;
14,983 donor procedures have a source line. Target functions with an unambiguous
decorated-name donor line: 4,935. See input-snapshot.json for concurrent changes.

## 2026-11-17: export route replaces in-place moves (owner decision)

Phase 2 moves are not performed: 358 live scripts read `native-classes/` / `native-headers/`, so a
moved file drops out of drafts, digest, coverage and LLM lanes. Instead `layout_export.py` copies
owner-approved one-to-one mappings to their original paths under `rebuild/2008-06/layout/`
(locally git-excluded; published on local branch `layout/2008-06`, not pushed yet).

- Manifests: `families/gui-export.json` (owner-approved six gui renames + headers),
  `families/clean-pdb-export.json` (provisional: same class of mapping, pending owner review).
- Exported: 113 files (21 `.cpp`, 92 headers). Each `.cpp` compiled beside its live original with
  `native_check_runner.py`; objects identical by `tu_signature` (`gates/clean-pdb-export/compare.json`).
- Held back: RakPeer, SimpleMutex, SocketLayer, Vector3 `.cpp` (absolute local path in `native-flags`).
- Live map (phase01, 35 min): 2,659 files; 2,151 unmapped; 226 pdb; 265 class-rule; 17 openrbx; 104 merge groups.
- Digest: `roc/native_files_notify.py` NATIVE_DIRS now includes `rebuild/2008-06/layout/` (uncommitted; server restart needed).

Not proven: no merge/split, no artifact cleanup, no source-only client, no P5/P6/runtime gate.
Phases 3-6 remain gated on naming the unmapped units and on full-link proofs.

## 2026-11-17 (later): one-command pipeline with cleanup

`python work/native-client/layout/layout_pipeline.py --refresh --branch` (3.5 min; was 35+ min for
phase01 alone): refresh the map without the consumer survey (`LAYOUT_SKIP_CONSUMERS`), select clean
one-to-one PDB mappings, export, tidy (`layout_clean.py`: recovery notes to `evidence.json`,
whitespace), prove, commit local branch `layout/2008-06`. `--commit-only` commits an existing export.
Push stays manual. Idempotent: an unchanged export leaves the branch unchanged.

Result: 113 files. 15 `.cpp` tidied and object-identical; 6 `.cpp` verbatim and object-identical
(tidied form changed the object or unit uses a vendor profile); 59 headers tidied (token-identical,
no line-sensitive macros); 33 headers verbatim. Header tidying is not compile-proven.
`families/auto-export.json` replaces the two hand-written manifests as the pipeline input.

## 2026-11-17 (evening): inferred tier, local-path scrub, automatic merges

Pipeline now also (a) exports conflict-free OpenRBX/address-evidence mappings under `inferred/`,
(b) lets a file with an absolute local path through only when tidying removes it (evidence is
scrubbed to `{root}`), (c) attempts every `.cpp` merge group: members joined by lowest address,
compiled under each member's flag set, kept only when `compare_merge(dedupe=True)` passes.
Result: 180 files; 10 merged units (24 pieces); 55 inferred-path files. Full run ~9 min.
Local branch `layout/2008-06` committed, not pushed (owner: do not push yet).
Not proven for merges: link order, initializer order, full-link placement.

## 2026-11-17 (afternoon): census-based original paths

Finding: of 2,151 files with no original path, 1,027 sources contain no addresses (banners were
removed 11-14), so the address-comment mapper had nothing to match. Only ~255 wait on unnamed
functions. `layout_census.py` reads the recovery lane's `prove-out/OgreNativeFull/checks.json`
(read-only) and gives a unit the original `.cpp` that all of its uniquely owned PDB-named functions
belong to. Validation against PDB file-name matches: 56 agree, 0 disagree (18 disagreed before
shared COMDAT symbols were excluded). Map now: 362 census, 226 pdb, 230 class-rule, 16 openrbx,
1,825 unmapped. Export: 309 files (293 single, 16 merged units from 39 pieces), local commit
49aa115f0f, not pushed. Run took 66 min because of 159 merge groups; a merge verdict cache
(`gates/pipeline/merge-cache.json`) and a two-vote rule for the main tree were added afterwards.

## 2026-11-17 (night): merge improvements, concurrency hardening, OpenRBX vote

- A 4h12m run finished worse (284 files): another lane edited shared headers mid-compile and the
  runner rejected 82 compiles ("inputs changed"). Pipeline now retries such compiles once, marks
  what is still rejected `unverified` (not exported, not cached) and never caches such merge verdicts.
- Verdict caches: `gates/pipeline/single-cache.json` (keyed on live text + exported text) and
  `merge-cache.json` (keyed on merged text + flag sets, with a `why` for failures). Rerun: 54 min.
- Merge step: exact duplicate definition blocks dropped when joining; reverse piece order also tried.
  Result a9dc5f3689 (local, not pushed): 310 files = 288 single + 22 merged units from 52 pieces.
  Remaining merge failures: 34 do not compile (conflicting, not identical, local definitions),
  8 compile with symbol differences.
- `layout_census.py` now also votes with OpenRBX-named functions (evidence `census-openrbx`,
  inferred tier) and drops a unit whose PDB vote and OpenRBX vote contradict each other
  (seen: CRobloxDoc.cpp voted to ScriptContext.cpp by PDB, robloxdoc.cpp by OpenRBX).
- Live tree grew to 3,087 files while this ran.
- OpenRBX-vote run (67 min): local commit ee7a66066f, not pushed. 336 files = 312 single + 24 merged
  units from 57 pieces (369 of 3,118 live files). Map: 226 pdb, 459 census, 146 census-openrbx,
  307 class-rule, 11 openrbx, 1,969 unmapped; 4 units held for contradicting census votes.
  authentic.json: 1,058 addresses.
- Error-driven merge repair (drop the block a redefinition error points at, retry, proof decides):
  run 49 min, commit c77bc16554 pushed to origin/layout/2008-06 on 2026-11-18. 339 files = 312 single
  + 27 merged units from 68 pieces. Merge groups: 27 pass (2 through repair), 26 do not compile,
  22 compile with symbol differences. authentic.json: 1,058 addresses.
- 2026-11-18: merge failure details now recorded in `merge-cache.json` (`target`, `detail`).
  `compare_merge(dedupe=True)` pairs same-named locals first and treats same-bytes/same-relocation
  locals as interchangeable; unpaired locals are reported as differences, not as "ambiguous".
  Outcome: no new merges. All 18 "symbols differ" groups are real codegen changes when the pieces
  share one unit (functions inline or emit differently); the 26 non-compiling groups have
  conflicting, non-identical local definitions. Mechanical merge work is exhausted at 27 units;
  the rest needs per-group source consolidation.
- 2026-11-18: receipt-only commit 1331a01190 pushed. New rule in inventory: an unmapped header whose
  `native-headers/<folder>` matches a unique original include area gets `<area>/<name>` as an
  inferred path (evidence `area-folder`; recovery-style names skipped). 56 mapped, 44 exported.
  Local commit 1faa19da1e, not pushed: 383 files = 356 single + 27 merged units.
  Map: 226 pdb, 459 census, 146 census-openrbx, 306 class-rule, 56 area-folder, 11 openrbx, 1,905 unmapped.
- Verb group checked by hand: `Verb.cpp` holds functions of two original files (verb.cpp and,
  per OpenRBX, commands.cpp: the RunStateVerb/EditSelectionVerb destructors). The right fix there
  is a split of the native piece, not a merge; this is per-group source work in the recovery lane.
- 2026-11-18: 189 `.cpp` merge groups exist; only ~70 had been attempted. Skips: 62 groups with a
  vendor-profile member (57 mixed, 5 all-vendor), 56 under `unclassified/`, 2 with a local path.
  Mixed groups now merge their normal pieces and list the vendor ones as `left_out` (partial merge);
  all-vendor groups are attempted with the profile line kept. Run 19 min, commit 58cfe7e286 pushed:
  393 files = 356 single + 37 merged units from 97 pieces (10 partial); 453 of 3,109 live files covered.
  Merge groups: 37 pass, 46 do not compile, 27 compile with real symbol differences.
- 2026-11-18: leave-one-out merges (groups of 3-6 pieces: whole group first, then each group minus
  one piece; left-out piece recorded). Run 35 min, commit 3678c1205b pushed: 412 files = 356 single
  + 56 merged units from 149 pieces (29 partial); 505 of 3,109 live files covered.
- 2026-11-18: census as a check on PDB file-name matches. Where the unit's own functions vote for the
  same file (51 units) the lexical review flags are cleared; where they vote elsewhere the unit is
  held for identity review (Verb.cpp: PDB vote verb.cpp, OpenRBX vote commands.cpp, matching the
  hand check). Commit 72444d6a63 pushed: 427 files = 371 single (219 main tree) + 56 merged units;
  520 of 3,109 live files covered.
- Vendor wrappers with path-encoded names (17 match a PDB path) are not exported: they only
  `#include` donor or library source, so a copy at the original path would not be native source.
- 2026-11-18: greedy subset fallback for failed merge groups (pieces offered biggest first, each kept
  only if the joined unit still reproduces every symbol of its pieces; a single piece is a valid
  result). Run 25 min, commit 80a4d82abb pushed: 480 files = 371 single + 109 merged units from 274
  pieces (82 partial, 33 of them one piece only; 228 pieces left out); 645 of 3,109 live files covered.
- 2026-11-18: (a) thin wrappers (only comments and preprocessor lines; they `#include` library or
  `work/libcache` units) are no longer exported: 15 held, 16 had been published. (b) `census-shared`
  votes: a unit with no uniquely owned function is placed by line-located, non-template PDB functions
  that exactly two pieces define (11 agree / 0 disagree; 47 mapped, inferred tier). Of 1,412
  plain-named unmapped sources: 759 own nothing uniquely, 296 have an owner class without path
  evidence, 148 hold only unnamed functions, 106 are not in the census.
  Commit df94d9b6ff pushed: 454 files = 344 single + 110 merged units from 280 pieces (81 partial);
  624 of 3,109 live files covered, no wrappers.
- 2026-11-18: `coverage.json` on the branch (pipeline `coverage()`): code bytes whose native source is
  in the export. 590,317 of 3,742,156 bytes (15.77%): original path 216,966 (114 files, 995
  functions); inferred path 102,146; merged complete 61,574; merged partial 209,631.
  Commit 09ad16b703 pushed. This is the Phase 4/5 progress measure; no link or runtime claim.
- 2026-11-18: lexical review flags (addresses cited in a file's text) now apply only to `.cpp` rows
  placed by file name or by those citations and not confirmed by the census. Headers and census
  paths no longer carry them. Review-held files 50 -> 6. Commit 4bb3a10bc4 pushed: 498 files = 388
  single (236 main tree) + 110 merged units; 668 of 3,109 live files; 16.11% of code bytes.
- 2026-11-18, Phase 4 first step: `tree_check()` compiles every proven single `.cpp` with the export's
  include roots ahead of the live ones and requires the object of the live original.
  First run: 164/204 units same, 84/184 headers exercised by a passing unit. Failures cluster on
  native variant headers that shadow the header other units build with. Rule: a header used by >= 3
  failing units and no passing unit is held back (blaming every header of a failing unit held 28,
  mostly innocent). Result, commit 99f712d87f pushed: 178/204 units same, 98/174 headers
  compile-proven, 10 variant headers held (v8world Edge/Primitive/World, v8datamodel
  Surface/Surfaces/Selection/MouseCommand/SelectionChanged, util/Vector6, tool/MegaDragger).
  26 units still differ: 15 G3D/GLG3D library units (the exported G3D Vector3.h/Matrix3.h are native
  variants that other units pass with), 5 inferred client/win units, 6 others. 488 files total.
- 2026-11-18: trial hold-back in the tree check (remove the exported header most failing units share,
  keep the removal only if fewer units fail and none regresses; max 3 trials). The exported G3D
  Vector3.h and Matrix3.h (native overlay variants) are now held. Commit fc5e1d5ae1 pushed:
  195/204 units build identically from the exported headers, 94/172 headers compile-proven,
  12 variant headers held, 486 files. Still differing: Widget.cpp, GroupDragTool.cpp,
  PartDragTool.cpp, GFont.cpp and five inferred client/win and network units.
- 2026-11-18: tree check extended to merged units (built from the exported headers, per-symbol proof
  against their pieces). Commit 4d6c3ade8a pushed: 195/204 single units and 95/110 merged units build
  identically from the exported headers; 94/172 headers compile-proven; 486 files. 15 merged units
  differ (mostly inferred client/win and v8datamodel units); they do not drive header hold-back yet.

## 2026-11-18 (late): merge leftovers, push, republish
- Tree check run finished: commit cdeca76b77 (520 files, 17.41% coverage; single 198/229, merged 65/112). Pushed to origin/layout/2008-06; site republished; server restarted.
- Merge leftovers: 80 groups, about 478 KB of code. Added layout_pipeline.drop_definitions (function-level duplicate remover used by repair()). Whole-group trial of the 12 eligible groups: 0 pass (6 do not compile, 5 symbols differ, 1 member does not compile alone).
- Causes: mis-grouped pieces (http.cpp: winhttp.h vs wininet.h cannot share a unit), overlapping rewrites (camera, accoutrement), per-piece header variants (camera-zoom overlay). Needs per-group source and header decisions, not automation.
- Phases 5 and 6: not started here. Blocked on provenance rules (SOURCE_ONLY_STATUS.md) and the Build B first-link trace owned by the other lane.

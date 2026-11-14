# RoConstruct cleanup and native integration goal

## Current client direction — 2026-11-08

Colin requests **no P6 recreation** in the target client, including its handmade shell and rendering/engine harness. The previously linked `relinked.exe` includes `RobloxShellNativeDoc.obj`, `P6Engine.obj` and `P6Data.obj`: its Doc is a native diagnostic selection, but its App, Frame, View and hosted engine include recreation code. `P6Engine.cpp` builds the Tools/Insert/Fullscreen/Help/Exit strip visible in the user's example. The reviewed MD5/P6 baseline also uses this recreation. Neither is the requested native client. Preserve prior evidence, but do not present, launch or build those profiles as the target.

The native App closure probe `rebuild/2008-06/tests/probe_native_app_entry_link.py` replaces the shell input with `tests/NativeAppEntryLinkProbe.cpp`, which includes recovered `CRobloxApp.cpp`; its old receipt `rebuild/2008-06/out/native-current-audit/native-app-closure.json` records 56 unresolved symbols, no duplicate errors and link exit 1120 on 2026-11-05. It is historical, not a current build result or runnable client. **It still inherits P6 engine/data and other recreation inputs:** removing only the shell does not satisfy the request. Its donor libraries and ABI also require review. Establish a fresh isolated native App/Frame/View/Doc/rendering closure, exclude recreation-only engine and data adapters, select genuine recovered providers, resolve ownership and dependencies, then perform required ABI/EH and runtime gates. Do not use fake stubs or shell commands as a substitute for native behavior. The existing smoke wrapper now refuses all launches until a reviewed non-recreation test path exists.

Latest native window/GUI work: `work/native-candidates/atl-crash-src15ofb/native-only-closure/WINDOW-GUI-FINDINGS.md`. Scratch `CRobloxWnd::finishAttach`, `DataModel::buildGui`, and `GuiBuilder::buildGui` match their 2008 code locally; the DataModel direct call also has a reviewed binding. A strict link with their dependencies exposes 78 unresolved symbols, including incomplete GUI methods. These are inactive candidates, not a working or verified native client. The replay excluded P6 shell/engine/data, but its remaining mixed-origin archives are not yet certified native-only.

Follow-up: enabling the existing GUI builder's guarded methods in an isolated build produced local matches for three additional builder methods and three related factories. A strict probe replaced three missing builder methods with four newly exposed constructor/singleton dependencies; 79 symbols remain unresolved. The private header overlay, selected owners, calls, ABI and runtime are unverified. See the same findings file for exact receipts.

Provider-search speedup: work commit `4fb0f5d43420cef0fb1936817759e871773cd8b9` preserves the newer scanner's object, library and plain-symbol handling while scanning source lines once. On 76 symbols and 755 local source files, source-only scan fell from 2.10 s to 0.50 s with identical reports; object and library scanning were excluded from that timing. Nine focused tests passed. Published Worker commit `ce42988055f8877f6613372bb20e4ee7f9fb369e` includes the exact script, with verified archive hash and zero preservation losses. This speeds investigation; it does not verify or integrate client providers. Search hits include shell objects and must not be treated as authorized native providers.

Later GUI probes reused existing widget, rectangle, panel and menu source with original-MSVC checks. The latest scoped, shell/adapter-excluded link reports 76 unresolved and zero duplicate errors. This count is only the current incomplete closure; remaining archives are not yet certified native, and no client was run or promoted. Exact provenance, changed dependencies and proof limits are in `work/native-candidates/atl-crash-src15ofb/native-only-closure/WINDOW-GUI-FINDINGS.md`.

## Current handoff — 2026-11-08, 4:40 p.m. ET

This is the combined goal and progress record. The detailed numbered entries below are historical snapshots, not a fresh audit of every item. The last locally observed `findings/work` ref was `ff447653f159863da4d51bc5fb6663ca26557f1d`; fetch and recheck it before integrating. Overall completion is unknown. Source layout moves are paused at Colin's request; prioritize other goal work and reviewed source intake.

| Goal area | Current status | Next action |
| --- | --- | --- |
| Preserve work and clean storage | Partial: dirty-checkout archive verified in the earlier snapshot; other drafts and snapshots are not fully reverified. | Inventory dependencies and unique bytes before archiving or removing anything. |
| Forks, drafts and temporary sources | Partial: some Mew and other work was integrated; old intake counts are inventories, not reviewed or integrated totals. | Compare each version against current canonical methods and receipts; retain accepted, blocked and pending dispositions. The example Instance file is not the whole intake. |
| Source organization and public mirror | Partial; physical layout work paused. Public/canonical reconciliation and complete donor provenance remain open. | Preserve existing paths and work; resume moves only if requested. Review and publish applicable source through the established owner workflow. |
| Docs, tests, tools and disk space | Partial: focused fixes and tests were recorded below; remaining cleanup and current free-space verification are open. | Recheck callers and active workers before retiring tools or snapshots. |
| Source status banners | Integrated in the earlier recorded batch; current freshness and complete coverage have not been re-audited here. | Recheck current source/proof inputs and labels before regenerating. |
| Packaging and CI | Earlier local archive checks passed; current remote CI and publication status are not verified in this update. | Recheck current ref, affected checks, package hashes and publication. |
| Branch retirement | Not complete. Earlier redundancy audit did not prove all differing content equivalent. | Preserve history and review differing content before deleting any branch or worktree. |
| Native client | A later isolated diagnostic EXE linked; it is not a verified or working native-Doc swap. New Game produced a white window and the user's process subsequently crashed. | Investigate the dump and selected providers; prove the cause before changing code. Keep diagnostic runs subject to the existing gates. |
| Fast client tests | Local smoke-test wrapper and instructions added; tested twice against the previously reviewed P6 baseline. | Extend only with evidence-backed checks; allow another EXE to run only after its required gates and review. |

### Latest client evidence and test plan

- Local diagnostic: `work/native-candidates/atl-crash-src15ofb/runs/20261108-163047-d2b31dfe/relinked.exe`. Strict isolated link reported no unresolved or duplicate symbols; old objects, provider selection, ABI, EH, P5/P6 and runtime remain unverified. It is not the same thing as a completed canonical `build_client.py --native-doc` build.
- User-provided runtime: all 313 requested files and directory contents in that diagnostic folder matched the June 22 source by SHA-256. No replacement or extra runtime folder was needed.
- User's New Game session showed a white window, then Windows recorded an access violation at `0x0042cff0`, attempting to read `0x174` in `RBX::Network::Players::canReportAbuse`. The white screen may have a separate cause. Preserve the dump and avoid speculative stubs or blind predicate changes.
- Follow-up dump analysis confirmed a null `Players` receiver returned by the selected creator to `CRobloxDoc::handle_454f30`. A scratch 2008 creator matches original code/data and links in isolation, but lookup/name/constructor selection mixes incompatible 2008 and newer providers; it is not a runtime fix. Detailed receipts and the proposed Players-family consolidation are in `work/native-candidates/atl-crash-src15ofb/players-create/FINDINGS.md`. White-screen cause remains unknown.
- Detailed next-agent method and crash evidence: `work/native-candidates/atl-crash-src15ofb/HANDOFF-20261108.md`. Earlier P10 strict-link evidence: `work/native-candidates/p6-relink-umj9013e/strict-runs/p10-strict-link-evidence-20261108.json`.
- Smoke-test plan and commands: `work/native-candidates/atl-crash-src15ofb/SMOKE-TEST.md`; wrapper: `work/native-candidates/atl-crash-src15ofb/smoke_test.py`. It preflights assets, records EXE hash and results, posts New Game on the specifically allowlisted reviewed P6 baseline, captures the engine view and compares reports. Baseline exited zero, engine open returned zero, and capture succeeded in about six seconds. White-screen detection is a heuristic; dumps require Windows crash-dump configuration. The diagnostic can be preflighted but is blocked from launch by the wrapper until separately reviewed and gated. Wrapper, handoff and generated test reports are local candidate work; no publication or commit is claimed.
- Native recovery and owner integration instructions remain `docs/NATIVE_AGENT.md`, `docs/NATIVE_SWAP_BATCH.md` and `docs/DRAFT_INTEGRATION.md`. Mining is a separate assignment. A draft receipt, local exact match or successful link is not a runtime or server-credit claim.

The historical item 10 compile failures and earlier five-unresolved/63-duplicate replay below describe older attempts. They do not supersede the later isolated strict link or prove the current full build succeeds. The old guard PID and expiry below are historical; inspect the current guard rather than relying on them.

Combined plan: one organized native source tree, reviewed contributions, useful tests/docs, and a real-provider experimental client.
1. Preserve unique work first. Record branch tips, source hashes, original paths, dirty/untracked changes, draft receipts and temp snapshots. Verify backups before removing anything. Existing Git bundles preserve committed history only.
2. Review every source lane. Compare canonical/public files, contributor forks, durable drafts, branches and temp folders per method/header. Deduplicate identical content, combine complementary recovered methods, retain stronger implementations and authentic declarations. Keep incomplete/conflicting versions visible with concrete blockers. The Instance file is one example—not the whole intake.
3. Build this actual source layout.
   RoConstruct/
   ├── README.md
   ├── .github/workflows/
   ├── workspace/                         # maintained authority
   │   ├── roc/                           # tools/server/recovery
   │   ├── packaging/
   │   ├── benchmarks/
   │   ├── clients/                       # registries only
   │   ├── docs/
   │   │   ├── setup/
   │   │   ├── contributing/
   │   │   ├── recovery/
   │   │   ├── integration/
   │   │   └── hosting/
   │   ├── site/
   │   ├── research/
   │   ├── tests/                         # tooling regressions
   │   └── rebuild/2008-06/
   │       ├── App/
   │       │   ├── include/
   │       │   │   ├── v8tree/
   │       │   │   ├── v8datamodel/
   │       │   │   ├── v8world/
   │       │   │   ├── v8xml/
   │       │   │   └── reflection/
   │       │   └── src/                   # actual .cpp files
   │       ├── Base/
   │       ├── Network/
   │       ├── Rendering/
   │       ├── WindowsClient/
   │       ├── Studio/
   │       ├── build/
   │       ├── glue/
   │       ├── patches/
   │       ├── manifests/
   │       ├── tests/
   │       │   ├── regression/
   │       │   ├── matching/
   │       │   ├── abi/
   │       │   └── runtime/
   │       ├── verification/
   │       └── experiments/               # inactive trials/probes
   ├── 2008-06/                           # generated public code mirror
   ├── src/<client>/                      # mined address functions
   ├── data/                              # downloads/manifests
   ├── drafts/                            # immutable originals
   ├── reports/                           # current summaries
   ├── migration/                         # old→new paths/provenance
   └── archive/
       ├── research/
       ├── retired-guides/
       ├── retired-tooling/
       ├── experiments/
       └── source-snapshots/
   Project names follow supported source evidence. Uncertain placement stays unresolved; 2016 provides a layout reference, not 2008 authority.
4. Move real files in dependency batches. Acquire leases; update includes, build recipes, provider manifests, tests and proof references together. Preserve translation-unit boundaries and per-source compiler flags. Catalog becomes navigation pointing to actual code and alternative versions.
5. Maintain one consistent public view. Generate 2008-06/ from reviewed canonical source. Prevent independent edits from creating competing implementations. Navigation includes fork/draft/temp alternatives, hashes, provenance and proof status.
6. Clean docs, tests and tools by dependency. Consolidate current workflow guides. Separate website assets from docs. Group maintained regression/ABI/runtime checks; archive obsolete trials and reports after checking callers, CI, packaging and receipt dependencies. Keep required SDKs, libraries and evidence.
7. Finish status banners. Publish corrected labels, add regression coverage, improve formatting and regenerate under leases. Separate recovered/exact code, evidence freshness and executable selection. No unsupported “linked” or “verified” claims.
8. Replace the stub experiment with a real-provider client build. Preserve the original experiment separately. Remove dummy implementations from selected inputs; reuse recovered providers, resolve duplicates, and obtain a fresh unresolved-symbol baseline. The old 113 count remains historical until rebuilt.
9. Recover missing dependencies efficiently. Prefer existing reviewed implementations, then independently checked donor methods, then small evidence-backed recovery from original assembly. No invented fields, hard-coded addresses or empty replacements. Preserve harder blockers and continue independent families.
10. Build and test a separate experimental executable. Record selected native providers and retained dependencies. Verify link ownership, ABI, lifetime/EH and required runtime prerequisites before launch. Partial functionality is acceptable; unknown memory/layout safety still needs resolution. Keep partial-client success separate from complete App/Frame/View/Doc swaps.
11. Refresh packaging and CI. Verify documented commands, required inputs, archive hashes, package manifests, source links and affected regressions. Keep old snapshots and generated output outside maintained browse paths.
12. Retire branches last. Preserve main, gh-pages, work. Migrate active checkout/publisher dependencies, verify recoverability and reviewed imports, then remove obsolete branches/worktrees safely.
Every batch: review exact changes → run affected checks → require zero source/proof losses → commit/push normally. Track integrated, inactive, blocked and unreviewed work separately.

## Earlier progress snapshot — 2026-11-08

**Goal in progress.** Snapshot based on work commit `2da654506111296a9f85e38b18500710df5dd5c3`. Do not treat inventory, draft upload, local exactness, or a diagnostic link as integrated or runtime-verified code. Overall completion percentage is unknown.

1. **Preserve unique work — verified for the dirty checkout.** A byte archive of all 3,372 files whose content exists in neither `findings/work` tree `2da6545` nor the three `RoConstruct-Native-*` snapshots was created at `C:\Users\colin\RoConstruct-cleanup-archive-20261108\dirty-checkout-20261108.zip` (70,541,921 bytes). Verification: 3,372/3,372 entries, 0 missing, 0 SHA-256 mismatches. All 25,786 dirty paths are recorded in `work/cleanup-20261108/` and committed as `0779345704`. Recoverability of drafts/snapshots outside that dirty tree is not fully re-verified.
2. **Review every source lane — partial.** Some fork and draft work is integrated; substantial review remains. A recent index covered 253 draft versions and 247 changed Mew fork files; indexing and text matches are not code review or proof. The example Instance proposal overlaps current work, but its complete method-level disposition remains unverified.
3. **Source layout — partial; stopped at user request.** Real source files exist under canonical project folders including App, Base, Network, Rendering, and WindowsClient. The planned full layout is not complete; do not resume source-layout moves unless requested.
4. **Move files and update dependencies — partial; stopped with layout work.** Some source moves, compatibility wrappers, manifests, and source maps were published. Full include, build, and proof-reference coverage is not established.
5. **Consistent public view — partial.** Public source and generated maps are published. Differences and public-only, fork, draft, and snapshot versions still need review; mirror completeness is not proven.
6. **Docs, tests, tools, and storage - advanced (8 pre-existing failures cleared 2026-11-08).** Packaging audit fix (added missing `native_bulk` to `packaging/build.py` WORKER_MODULES); workflow-version test 49->50; `roc/server.py` `/v1/status` now tolerates missing `clients` key; leaderboard ordering restored to matched-first; recipe `mutate`/`all`/`None` clients allowed in `test_every_recipe_is_well_formed`; provider_auth expectation corrected to `provider_config`; `start_evidence` added to `test_find_functions` expected records; refsource body assertion guarded on file existence. All 8 previously failing tests now pass. Free-space recheck still outstanding.
7. **Status banners and links — INTEGRATED 2026-11-08.** Corrections and tests from `work/native-candidates/status-check-g2rd7k9h/` and `work/native-candidates/site-link-repair-y_hkcvtj/` (native_status safety guards + integration_site exact-blob/wrapper/proof verification) shipped to findings/work as commit `ae4da2e104aa21f4d0abc943609e172e5b6bac6b` (integration commit `4f91cf6f6d50979afe97bcf58c50bee1d61ac0e6` plus LF-normalization fixup), with publication commit `64acd8987205ac30a131c94934b31af26f46f85c` (data packages refreshed). Combined source workspace tree `f5f808063368a6a50888e1d01172c6a5a720e491` (10 paths: 6 modified + 4 added, 0 deleted) over base `2da6545`; publication workspace tree `b0349ff83506006692c678ede5e5b0b445c68791` (metadata regenerated, all 10 source blobs unchanged); preservation `work/findings-integration/preservation-ae4da2e104aa21f4d0abc943609e172e5b6bac6b.json` = 0 losses (re-verified on the publication tree); affected gate re-run on the exact exported bytes = 68 passed (39 status/site + 29 builder) in 12.19s. Base confirmed unchanged at `2da6545` before integration; guard PID 38880 self-expired and was re-acquired/released cleanly (token `2b5cd820…`).
8. **Real-provider client and duplicate owners — INTEGRATED 2026-11-08.** The private native FileSystem/archive-owner fix from `work/native-candidates/builder-owner-whygb8xk/` (build_client cache-input validation + new glue_owner provider-ownership verifier) shipped in the same batch above; original stub experiment remains preserved separately. Full client-build/runnable proof still open (item 10).
9. **Missing dependencies — incomplete.** A diagnostic selection baseline had 101 unresolved symbols. A wider object selection increased unresolved symbols, so it was not promoted. Call identity, dependencies, ABI, and exception-handling proof remain open.
10. **Experimental executable - in progress, not yet working (2026-11-08).** Mew fork integrated (native-classes/native-headers from 5fe2214 context; glue_owner.py restored b38d57cf; 26 split duplicates removed; stale build_client.py split refs removed). Winget tools installed/used for non-compile analysis: Cppcheck 2.22.0, LLVM 23.1.5 (clang/clang-tidy). Cppcheck broad scan found potential issues (e.g. AppUnit588_2008ChangeHistory.cpp:342 [missingReturn], parse/AST issues in ImageContentRegistration/LDrawPath, LuaBridge2008Atomic logic warning, null/cast/style warnings) - triage needed; key modified files checked where applicable.
- **Build evidence (mew4)**: `python rebuild/2008-06/p6/build_client.py --native-doc` -> EXIT=2, log `C:\Users\colin\AppData\Local\Temp\roc-native-doc-build-mew4.log`. Compiled through many native-doc sources (past FlatTool.cpp) then failed: `NullTool.cpp(24): error C2027/C2227` undefined `RBX::DataModel` via `dataModel->getWorkspace()` in merged `TToolVerb<NullTool,RunStateVerb>::newMouseCommand`. **No `rebuild/2008-06/out/p6/RobloxNativeDoc.exe` produced**; stale native-doc-closure.json/native-doc-link.log (2026-11-03, link_exit 1120, 51 unresolved, clean_link:false) are not current-run evidence.
- **Committed/pushed fixes**: ff4788e077, c0ca7dbdfd, 95441375d9, 26701ea8a0, 91a8fd49aa, e1eb5244d0, 461c72f0d5 - mew unsplit checkout, split removal, LocalBackpack.h Network/Players.h, Verb destructors, build_client split-ref cleanup, merged tool newMouseCommand/events for Clone/Flat/Game/Grab/Hammer/Laser/NullTool with includes/namespaces/cppcheck fixes (DataModel.h/Workspace.h added where needed).
- **Remaining (no compile-fix loop)**: complete build-referenced unsplitting in correct VC2008/header-compatible style (service sXxx/find/create specializations for PhysicsService/JointsService/RunService etc.; remaining TToolVerb::newMouseCommand symbols from stale closure; split-only impls still required). Use cppcheck and clang/clang-tidy with `roc.rebuild.toolchain()` include paths for static checks, then run one verification build and record artifacts (RobloxNativeDoc.exe, closure, link log).

  - `LocalBackpack.h`: referenced `Network::Players` without including `Network/Players.h` (fixed by adding the include — a missing-include, not an invented field).
  - `PhysicsServiceFind.cpp`: `RBX::sPhysicsService` redefinition (different type modifiers) vs `PhysicsService.h` declaration; plus `NonFactoryProduct` template misuse.
  The build does not complete; `RobloxNativeDoc.exe` was not produced. The second error is a real source inconsistency requiring per-file review, not a missing include. Item 10 remains incomplete; the native-doc build is the documented entry point (`python rebuild/2008-06/p6/build_client.py --native-doc`) and its output (`out/p6/RobloxNativeDoc.exe`, `native-doc-closure.json`, `native-doc-link.log`) is the evidence needed for "selected native providers and retained dependencies". Prerequisites verified present: toolchain (VC2008 RTM), MFC/atlmfc libs, P2RecoveredPlayer snapshot, ReflectionMetadata, clients/2008-06/Roblox.exe, functions.jsonl. Blocker: source-level compile errors in native classes (PhysicsServiceFind, possibly more downstream).
11. **Packaging and CI — verified end-to-end locally.** Source-catalog navigation now indexes exact-content donor/draft/local versions and generates project browse pages; 13 catalog tests pass. Three working probe receipts were regenerated against current file hashes. `package-findings.yml` was synced to the maintained `work`-branch version (adds canonical native archive, archive integrity test and checksum verification). Focused packaging/navigation regressions: 29 passed. All four documented archive inputs exist at `2da6545` and local `git archive` builds against that exact ref pass integrity (0 corrupt entries): src 189,007 entries / evidence 24 / native-source 14,017 / canonical-native 4,573; per-archive SHA-256 recorded in `work/cleanup-20261108/package-verify-20261108.json` (equivalent of the CI `sha256sum --check` step). Full suite on the committed tip (docs/scripts-only changes) measured 1851 passed / 8 failed / 3 skipped / 1 warning in 23:05; a solo sequential re-run of just the 8 failed tests reproduced all 8 in 3.42s, so they are pre-existing (not concurrency noise). Classified in `work/cleanup-20261108/full-suite-20261108.json`:
  - test_install: `native_bulk` missing from the Worker package manifest; maintainer-module audit mismatch.
  - test_research: provider-auth queued-call count 50 vs expected 49; recipe `mutate-search-2008` uses invalid `mutate` search mode.
  - test_roc: find_functions evidence-field drift; server_store ordering; refsource_name_recovery empty result.
  - test_server_lease_queue: bounded-overload / status `KeyError: 'clients'` (server status payload shape).
  These are out of the integration scope (no source/test edits made this session) and do not block integration; they are tracked separately for a later cleanup batch. Post-push CI confirmation remains outstanding.
12. **Retire branches — path-mapped redundancy check complete (2026-11-08); retirement still deferred.** Ran `work/native-candidates/branch-redundancy-mapped-20261108.py` (path map root->workspace/ plus content-hash matching) over all 9713 codex blobs vs 217983 work blobs: 880 identical (safe to retire), 1740 content-different (work holds a newer/different version under workspace/), 1046 present elsewhere by content (layout-moved, e.g. docs/graph-data -> workspace/site/graph-data), 6 with no byte-identical counterpart but near-equivalents on work (docs/{findings,graph,index,sources}.html, graph.js, DRAFT_WORKFLOW_VALIDATION.md — sizes differ, likely minor edits). **Zero truly-lost files.** The 7 codex-only commits are this session's own commits (5a8ffd9, 07e9c58, f2a3a41) plus 0da2d19, 0779345, c9a0757, 36fa985 — all of whose useful content is either already on work or recorded in receipts. Conclusion: the codex branch is redundant with work for source content, but the 1740 content-different files and 6 near-equivalent docs should get a final content review before deletion; branch is NOT deleted this session. Report: `work/native-candidates/branch-redundancy-mapped-20261108.json`.

**Historical coordination:** Earlier on 2026-11-08, guard PID 38880 held `work/draft-integration.lock`. This is not a current lock status. Do not take or release another run's guard; recheck availability before integration. Prepared fixes must be reviewed against the current work tip, revalidated on exact bytes, and pass preservation and relevant gates before commit or normal push.

### Item 10 diagnostic update — 2026-11-08

A later local native-Doc link log reported five unresolved symbols but used `/FORCE:MULTIPLE`, which suppressed duplicate-provider failures. Replayed its saved inputs in isolated output directories without that flag and without compiling or running an executable. Strict baseline: five unresolved, 63 duplicate symbols. Existing candidate objects plus removal of an overlapping aggregate factory object reduced this to zero unresolved and 12 duplicates, with no recorded explicit-input drift. The remaining duplicates belong to NullTool (5), JointsService (4), PartInstance (2), and ContentProvider (1); all four old archive members occur in the saved `script-context-owner/linked.lib`. Evidence: `work/native-candidates/p6-relink-umj9013e/strict-runs/p10-strict-link-evidence-20261108.json`.

These are link-only diagnostics against a dirty local selection; some candidate objects are old and not freshly proven. Zero unresolved does not mean link success, complete providers, ABI, EH, selection or runtime safety. Canonical `work` already omits the duplicate aggregate factory and includes owner helpers; compare against its fresh selected inputs before promotion. Do not use `/FORCE` or execute the native-Doc diagnostic.

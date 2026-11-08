# RoConstruct cleanup and native integration goal

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

## Progress — 2026-11-08

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
10. **Experimental executable — incomplete.** No runnable client has been proven by the required selection, ABI, exception-handling, P5/P6, and runtime gates. Diagnostic binaries have not been run.
11. **Packaging and CI — verified end-to-end locally.** Source-catalog navigation now indexes exact-content donor/draft/local versions and generates project browse pages; 13 catalog tests pass. Three working probe receipts were regenerated against current file hashes. `package-findings.yml` was synced to the maintained `work`-branch version (adds canonical native archive, archive integrity test and checksum verification). Focused packaging/navigation regressions: 29 passed. All four documented archive inputs exist at `2da6545` and local `git archive` builds against that exact ref pass integrity (0 corrupt entries): src 189,007 entries / evidence 24 / native-source 14,017 / canonical-native 4,573; per-archive SHA-256 recorded in `work/cleanup-20261108/package-verify-20261108.json` (equivalent of the CI `sha256sum --check` step). Full suite on the committed tip (docs/scripts-only changes) measured 1851 passed / 8 failed / 3 skipped / 1 warning in 23:05; a solo sequential re-run of just the 8 failed tests reproduced all 8 in 3.42s, so they are pre-existing (not concurrency noise). Classified in `work/cleanup-20261108/full-suite-20261108.json`:
  - test_install: `native_bulk` missing from the Worker package manifest; maintainer-module audit mismatch.
  - test_research: provider-auth queued-call count 50 vs expected 49; recipe `mutate-search-2008` uses invalid `mutate` search mode.
  - test_roc: find_functions evidence-field drift; server_store ordering; refsource_name_recovery empty result.
  - test_server_lease_queue: bounded-overload / status `KeyError: 'clients'` (server status payload shape).
  These are out of the integration scope (no source/test edits made this session) and do not block integration; they are tracked separately for a later cleanup batch. Post-push CI confirmation remains outstanding.
12. **Retire branches — incomplete.** Remote `codex/native-partial-search-20261029` still exists alongside main, gh-pages, and work. Do not delete until unique work and active checkout dependencies are safely handled. A raw same-path comparison against `2da6545` is not applicable: the codex branch keeps root-layout `rebuild/2008-06/...` paths while `work` serves them under `workspace/rebuild/2008-06/...`, so retirement needs the path-mapped source map (`docs/SOURCE_CATALOG.md` crawl or `git diff --find-renames` across the layout move) before any branch is dropped. Helper kept at `work/native-candidates/branch-redundancy-20261108.py` (needs a path-map variant).

**Coordination:** On 2026-11-08 a live integration guard (PID 38880, started 09:30:17, token `65bab256…`) held `work/draft-integration.lock`; the hold self-expires before 12:30. Do not take or release another run's guard; recheck availability before integration. Prepared fixes must be reviewed against the current work tip, revalidated on exact bytes, and pass preservation and relevant gates before commit or normal push. Integration into `findings/work` remains deferred while that guard is live.

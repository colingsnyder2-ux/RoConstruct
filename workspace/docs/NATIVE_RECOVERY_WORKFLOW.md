# Native recovery workflow

Default campaign policy: `docs/NATIVE_SWAP_BATCH.md`. Name one runnable swap
target, track its current blockers, compile evidence-backed variants once per
isolated source, reuse objects for byte/data/call proof, then advance integration
obligations. Stop after three rejected hypotheses. Existing clocks still apply;
this does not authorize resetting budgets or activating unproven providers.

Goal: recover real 2008-06 native code fast. Keep noise, tokens, compiles, and bad promotions low.

## Rules

- Native only. No byte blobs, asm, fake padding, hard-coded addresses, trial-header imports, or runtime claims from object matches.
- Work one proven chain at a time: exact body -> authentic header/layout -> selected provider -> closure/link evidence -> runtime gate.
- Do not touch another worker's dirty path. Lease every native class/header/build-script path first.
- Keep shared headers single-owner. Send evidence, not edits, to header owner.
- Use private-index commits. Commit coherent exact family batches. Do not stage/revert unrelated work.
- Do not run game/UI processes unless needed. P6 closure is provider evidence, not runtime proof.

## Fast loop

Start a function clock before inspection or editing:

```powershell
python -m roc.native_work start 0046b860 --hypothesis "one new source-shape hypothesis" --budget 600
```

Repeated starts resume the same clock and budget. The clock measures elapsed work
including inspection, waits and builds; it is not CPU time. Use the same session
through the hypothesis's trials. The runner refuses another compile for an active
function once its budget expires; it does not kill an already running compiler.
Park it with the specific missing proof rather than resetting the clock. Start a
new session only for a genuinely new hypothesis or new evidence.

1. Read `CLAUDE.md`, newest research notes, leases, and current closure receipt.
2. Pick one blocker with many requesters or one near-exact body. Prefer real layouts/factories over isolated helpers.
3. Inspect target once with grouped `roc.cmd native-asm 2008-06 ADDR [ADDR...]`.
4. Search existing native sources, headers, trial evidence, and provider queue before writing code.
5. Make one evidence-backed change. One hypothesis per trial.
6. Compile independent sources once with `native_check_runner.py`; batch up to three unrelated sources.
7. Promote only exact native-header sources. Park near misses with address, score, diff cause, and next proof needed.
8. After a provider-family gain, run one isolated P6 probe. Use absolute extra-source paths and unique output folder.
9. Record only changed evidence with `roc research note`.
10. Commit/push one coherent batch when requested or session ends.

Finish the clock with evidence or a concrete blocker:

```powershell
python -m roc.native_work finish 0046b860 --outcome blocked --note "first divergence and next required proof"
python -m roc.native_work report --sort seconds
```

Outcomes are `local_exact`, `partial`, `blocked`, or `rejected`; `local_exact`
requires `--receipt PATH`. This records local work, never server acceptance.
Sessions persist under `work/2008-06/native-work/active` and `history`.

Every explicit runner check automatically prints its address, result, check time,
shared source compile time, and active-session elapsed time. Logs live in each
run's `function-timings.jsonl`; checks with an active clock also append to
`work/2008-06/native-work/trials/SESSION/RUN.jsonl`. A source compiled once for
ten checks has one shared compile cost, not ten independently measured recovery
times. Reanalysis logs `mode=analyze` and never pretends to have compiled again.

## Milestone and ownership discipline

- Lease shared headers to one owner per validation batch. Native check runs and
  P6 probes record shared core-header hashes. A core-header change invalidates
  the batch/probe; the check runner also rechecks its actual dependencies at the
  end. Do not accept mixed-header results or disable drift checks to pass them.
- During source recovery, compile only changed sources and necessary local
  regressions. Reuse hash-verified objects with `analyze`; changed-input results
  are historical diagnostics, not current proofs.
- Run one full closure probe after a provider/ABI change or a final integration
  milestone, not after every source variant, recount, or unchanged result. Use
  manifest `"cache": true` routinely; use `false` deliberately for a cold audit.
  Do not run both extras and default probes for the same understood promotion.
- Once a class's own entrypoint inventory is verified (Doc: 54/54 in the reviewed
  diagnostic), work on remaining call identity, exception metadata, virtual-table,
  ownership and dependency ABI obligations. Recount only when the inventory or
  its input hashes change. TU helper counts are not class completion counts.
- For duplicate definitions, `p6_probe.py report RUN` prints both providers from
  `result.json`. Assign one owner, compare both implementations and their unique
  dependencies, then choose one proven provider. Do not blindly drop a library,
  strip functions, weaken checks, or use forced multiple definitions.
- The reviewed closure queue has two unresolved symbols (AxisMoveTool factory
  and CWorkspace XML writer), plus duplicates in ContentProvider, NullTool and
  PartInstance. Use the latest terminal receipt if this queue changes. Bound the
  writer hypothesis to its function budget; do not repeat rejected variants.

## Tool routing

| Need | Use |
| --- | --- |
| Target/calls | `roc.cmd native-asm 2008-06 ADDR [ADDR...]` |
| Exact body, parallel safe | `python rebuild/2008-06/tests/native_check_runner.py start MANIFEST` |
| Existing object analysis only | `native_check_runner.py analyze RUN` |
| Field/layout evidence | `native_layout_evidence.py --thiscall ...` |
| Link blocker order | `native_provider_queue.py --object-dir rebuild/2008-06/out/p6` |
| P6 closure | `p6_probe.py preflight/start/status/report` |
| Main-class coverage | `native_tu_coverage.py LO-HI SOURCES...` |

## Batch discipline

- Group only independent sources. Never overlap P6 builds.
- Use one status read after expected compile time. No polling loops or repeated full builds.
- Reuse completed runner receipts when source/header hashes match.
- Before trusting a JSON-backed cache, verify `key == json.loads(json.dumps(key))`.
  Tuple/list differences silently invalidate every entry. Native-doc regression:
  `python -m pytest tests/test_p6_native_cache.py -q`.
- P6 probe `start` refuses a busy shared build lock; it does not queue behind it.
  Retry only after the active run is terminal.
- Opt-in native include profiles are cache inputs too. An override-header edit
  refreshes its users once; untouched default-profile objects keep their keys.
- Range hits can be identical destructor/template bodies under a wrong symbol. Use ranges only to find candidates; confirm the exact decorated symbol and call targets before promotion.
- For batches of tag initializers or constant tables, also run referenced-data
  checks. Masked code alone can match multiple functions with different strings.
- Keep compiler output capped. For a failed near-match, save only score, byte lengths, first divergence, and call-target delta; never dump a full body diff into the work log.
- Do not copy the Doc noinline-string profile to every new source. Try the
  default profile first for leaf handlers: controller actions, surface clicks,
  and tilt math match with ordinary inline string accessors.
- If a new method needs a different profile, compare every old named body before
  accepting a whole-file flag change. Prefer a shared real class header plus a
  separate method source; InsertObject needs noinline strings, FixedCamera does not.
- Capture closure before/after. Count unique unresolved symbols, not raw linker lines.
- A new unresolved dependency may mean net progress. Record both removed and exposed symbols.

## Promotion bar

Promote source only when all apply:

- Exact masked bytes under correct symbol, compiler, and flags.
- Static helpers must be emitted by authentic recovered callers; never retain a diagnostic bridge merely to force codegen.
- If a COFF body includes an adjacent catch funclet, verify both original extents
  and emitted EH state tables. Keep the full compiled object; never strip a tail
  to turn a prefix match into a promotion.
- Real native headers only; no `tests/` dependency.
- Constructor and destructor/layout evidence for class swaps.
- No duplicate provider or vtable collision in selection.
- P6 closure effect measured when source is selected.
- Audit the actual compiled provider objects, not a separately compiled stand-in.
  `work/2008-06/audit_axis_closure_objects.py RUN MANIFEST-STEM ...` handles
  default and extra-source objects, verifies masked bodies and referenced data,
  and saves source/object hashes. Extra objects resolve through the frozen plan.
- After a shared-header edit, batch-compare unchanged providers with
  `python work/2008-06/audit_provider_regression.py BEFORE_RUN AFTER_RUN`.
  It records every changed/missing old body and object hashes; masked code only,
  so keep separate call-identity, layout and runtime checks.

## Quiet reporting

Only report material deltas:

`area: exacts gained; closure before -> after; next blocker.`

Say `inactive exact` for source/object proof. Say `selected closure` for link-provider proof. Say `runtime passed` only after real gate runs.

## Reuse verified compiler profiles

When a diff expands `shared_ptr<Instance>` cleanup into atomic/refcount calls,
try `/I{headers}/boost-noinline-shared-destructor` before changing control flow.
It adds an out-of-line empty `shared_ptr` destructor; member cleanup stays native.
PhysicsService find 004ccca0 then matches 320 bytes, and its emitted destructor
matches 00600660. Verify both in the consuming object; this is not global ABI proof.
Do not add unreachable locals or branches merely to force an EH state.

For frozen preprocessed service objects, compile the ordinary native source with this existing scoped profile instead of generating another expanded C++ file. First compare every old emitted function against the replacement, then check original bodies/data and callees. Replace the frozen object in the diagnostic source list, run one closure build, and compare all unchanged providers. Selection, ChangeHistory and Visit use this path. An empty explicit destructor body still invokes member destructors; verify emitted cleanup before calling it a stub. Range-only matches can pair unrelated template instances: do not count them without symbol/callee identity.

Native check runner now audits referenced data automatically for exact explicit checks.
Use `verified_checks` with empty `data_mismatches`, alongside `exact_checks`.
Recheck existing objects without compiling via `native_check_runner.py analyze RUN`;
inspect its `changed_input_sources` before treating old evidence as current.
PowerShell batches must check `$LASTEXITCODE` after native edit/setup commands
before dependent builds; `$ErrorActionPreference` alone does not stop them.

`verified_checks` means local bytes + referenced data only; retain actual P6-object,
call-target, ABI, runtime and server verification separately.

### Native Doc compile batches

The diagnostic builder compiles independent Doc provider objects with up to three compiler processes. Each job owns its object and cache entry; output is printed in source-list order. `ROC_NATIVE_DOC_JOBS=1` restores serial execution; values above three are capped. The normal client build is unchanged. Do not overlap probe builds or change provider inputs during a probe. Current provider flags use no debug/PCH output; introducing shared debug/PCH files requires isolation before parallel compilation.

Verification: `python -m pytest tests/test_p6_native_parallel.py tests/test_p6_native_cache.py tests/test_p6_probe.py -q`. A passing closure diagnostic still does not establish ABI, runtime or P5/P6 safety. Compare actual provider objects and count both unresolved symbols and duplicate definitions. Cold-build speedup must be measured; warm-cache timing does not measure compiler scaling.

### RTTI identity is a separate gate

Constructor/destructor bytes and size can match with the wrong fieldless base. Before promoting a class, compare original and native RTTI hierarchy names, base offsets, contained-base counts and attributes. Metadata Properties/Functions/Events derive through Members; giving each an Instance base produced matching masked bodies but incorrect RTTI. The original sInstance is a const char array; retain const char* template parameters while preserving that variable's proven constness.

Local verifier: `python work/2008-06/audit_metadata_rtti_hierarchy.py OBJECT Properties Functions Events`. It rejects the earlier wrong hierarchy. Preserve its whole_hierarchy_exact result, not only direct_family_exact. Symbol-migration regression options are explicit, limited to the proven Instance const-array and metadata Members corrections; they still compare all code bodies and list every rename. They do not establish runtime safety.

### Batch source-shape checks

For a localized scheduling mismatch, generate isolated source variants under work/ and submit one native_check_runner manifest (three compiler workers). Preserve the baseline, compare exact_checks and data_errors, then promote only the simplest exact variant and compile the canonical source again. Avoid sequential one-variant tool turns. View initialization matched by delegating both bindExisting branches to bindName; merging the branches regressed. View routing matched with a scoped copy of the real Boost shared_count header: cache r.pi_ before assigning pi_ and incrementing that same control block. Keep the complete class layout/debug-hook behavior; no surrogate argument struct or manual reference-count ABI. Limit the profile to its proven source until broader regressions are checked.

When a remaining TU body belongs to a dependency, inspect original RTTI and compile its existing source before inventing a fixture. View's seven-byte helper is G3D::Hashable::~Hashable, emitted exactly by the unmodified G3D TextureManager.cpp. Such evidence proves source availability, not selection in the running client.

### Audit existing archive bodies before recovery

Run `python rebuild/2008-06/tests/audit_native_archive.py ARCHIVE CHECK_MANIFEST --member Dragger.obj --member DragUtilities.obj`. The manifest uses the same jobs/checks address and symbol fields as native_check_runner. The tool extracts whole objects into a unique evidence directory, checks original bytes and referenced data, and hashes archive, objects, manifest, tool and original executable. It does not patch or strip libraries. Missing symbols, ambiguous prefixes, different bodies and data mismatches fail. Receipts do not establish callee identity or runtime ABI; inspect call targets separately.

The Axis closure already has exact archive implementations of Dragger::intersectingWorldOrOthers, computeExtents(Array), movePrimitives and DragUtilities::moveAndClean. Reuse them; selecting duplicate replacements raised link collisions from 17 to 21. Redundant proof source is retained under work/2008-06/dragger-archive-audit. Keep new native placement definitions limited to the missing methods. The checker passed the four real methods and rejected both an absent symbol and a deliberately wrong target.

### Avoid duplicate promotion builds

After source checks, layout/lifetime checks and call review pass, a reversible provider addition can go directly into the leased diagnostic builder list. Run one canonical closure probe and audit its actual objects. Save the original list and revert only the new entries if the provider is unsuitable. Use an extras probe first when extraction/ownership or dependency cost is uncertain; do not routinely run both extras and default for the same already-understood addition. Never change inputs during a live probe. Compile/link diagnostics still cannot authorize running the native diagnostic executable.


MouseCommand recovery: the shared rbxgs recipe defines `_RELEASEASSERT` even with `NDEBUG`. Original 00615940 has no assert path; use a source-local `#undef _RELEASEASSERT` before includes for this proven release TU. Its `getPart` also needs the existing `engine-world` profile: constructor/destructor evidence proves the ContactManager pointer at +0x84, whereas the legacy header uses +0x40. This prefix read does not prove allocation or the rest of World ABI. Check original bytes, referenced data, callees and full RTTI before selecting the real source; do not remove native methods merely to silence duplicates.


The original root `sInstance` is a proven exception to mutable class-name arrays: declare `extern const char sInstance[];` and define `extern const char sInstance[] = "Instance";`. Its original template symbols encode `QBDB`, not `PADA`. Keep the root and `pv-parent` header profiles consistent. A mutable declaration caused 49 missing/changed helper names in the 2026-11-04 regression audit; restoring the const form recovered all prior bodies and full Instance RTTI. Preserve unrelated header edits when fixing this single declaration.


### Retained content cache variants

Native Doc cache schema 2 fingerprints source bytes, quoted native dependency bytes, scoped include-profile contents and compiler flags. Each signature owns a retained artifact directory; a later configuration no longer overwrites an earlier one. Timestamp-only touches and exact content/flag rollbacks reuse the matching variant. Real content edits invalidate even when timestamps are preserved. Object and receipt writes are atomic; incomplete receipts are rejected. Existing flat cache entries are retained but ignored by this schema, so the first run is cold.

Validation: cache tests cover A/B/A rollback, source/header edits, preserved timestamps, flag changes and incomplete metadata. The 2026-11-04 validation measured 263.203 seconds cold and 58.516 seconds warm, with all 253 full provider objects byte-identical, 17,701 common bodies unchanged and 25 explicit checks exact. These timings validate cold/warm reuse, not an old-versus-new steady-state speedup. Continue leasing shared headers and keeping inputs stable during probes; cached diagnostics do not prove runtime safety.


### Doc owned-entrypoint audit

Run `python rebuild/2008-06/tests/audit_native_document_entries.py RUN` against a terminal diagnostic run. It derives owned virtual/message targets from the original PE, includes the original runtime-class base getter, audits historical inline/inherited MFC slots, and reports MSVC weak destructor fallback code separately from final linker selection. It compares body bytes and referenced data, including the verified adjacent catch continuation of loadFromString. Missing required providers fail rather than shrinking the denominator.

The current Doc audit covers 58 native symbols at 56 unique original addresses, 39 message entries and all 46 vtable slots. A fresh seven-source batch passes 57 ordinary checks; the remaining 459-byte body plus catch is independently verified. Fresh layout assertions and ctor/dtor checks pass. The old ~75/99 count describes the original translation unit, including unrelated template helpers; it is not the percentage of Doc member methods remaining. These checks do not prove complete call identity, exception metadata, dependency ABI, final PE selection or a live class swap.


Exception tables are a separate obligation: loadFromString at 00454ac0 had identical 459-byte body/catch code while a catch-all handler silently differed from the original std::exception reference catch. The corrected typed catch also matches the original FuncInfo, unwind/try/catch data graph and cleanup callbacks. Preserve this fix. Body/data coverage alone must not be reported as full exception behavior or complete class integration. The original type_info vtable binding is independently anchored by known original RTTI descriptors; this does not prove the whole CRT ABI.


### Archive extraction diagnostics

Use `ROC_NATIVE_DOC_VERBOSE_LIB=full` for actual `Found / Referenced in / Loaded` events. `/VERBOSE:LIB` on this historical linker only reported library searches. Reverse archive references are possible edges, not proof of extraction. Native diagnostic builds save `native-doc-link-command.json` (working directory and exact linker arguments), allowing link-only investigations without recompiling; check input provenance before replaying old arguments. Never execute the diagnostic EXE. A removed duplicate is valid only when the replacement retains every needed real provider and its original ABI.


The localized `boost-function-pod-vtable` profile uses the saved upstream 1.35 Function template and documented local base compatibility changes. Constructor 0055f350 and its manager/invoker match; candidate family checks pass 18/18. This is not a complete upstream Boost release or a live owner switch. Same decorated names can conceal incompatible class/member-pointer ABIs: legacy ContentProvider binding carries 8 bytes and RET12, while native carries 16 and RET20. Activation added two duplicates and was reverted. Keep the new binding inactive until legacy singleton callers/providers migrate; do not force either implementation over incompatible callers. Default rollback 103851 retains 2 unresolved/8 duplicates and 17,707 unchanged old provider bodies.


### Function-level archive consumers

`python rebuild/2008-06/tests/audit_native_archive_consumers.py ContentProvider.obj --run RUN --output RECEIPT.json` maps undefined COFF relocations to owning functions in archive members and saved explicit link inputs. `--family MD5Hasher` narrows a member to another real symbol family. It never compiles or executes the client. These are possible references, not proof of linker extraction; compare the full verbose link events. Repeated template copies are grouped, data references remain separate. Input hashes identify bytes actually read, including any mutable absolute object paths in old link commands; they do not establish those paths still equal their historical build bytes.

Control: `NullTool.obj --family NewNullTool` identifies exactly Workspace.obj / RBX::newNullTool / NewNullTool constructor, agreeing with the independently observed extraction trigger. ContentProvider audit identifies legacy singleton copies in ten archive members. MD5Hasher has one external requesting function, registerImageContent in NativeImageContentRegistrationFull.obj. Six MD5 implementation/factory bodies in the existing donor already match the original; c_str does not. Audit existing providers before recreating them. Receipts: work/2008-06/{content-provider-function-consumers,nulltool-function-consumers,md5-function-consumers,md5-existing-provider-audit}.json. No class ownership or runtime gain claimed.


### Fast isolated link replay

`python rebuild/2008-06/tests/relink_native_document.py RUN [--add path.obj]` replays a terminal diagnostic link into a unique work directory with explicit-input and linker hashes, before/after drift checks, full log and symbol-set comparison. No compilation, provider deletion or executable launch. Response file avoids Windows command-length limits. It does not establish historical input identity or fingerprint implicit default libraries; original ABI obligations remain. Baseline control 20261104-110155-027cb17e reproduced the exact two unresolved/eight duplicate symbol sets in 1.063 link seconds versus the prior 60.312-second full build. This measures avoided compilation, not a compiler speedup. Additive ScriptFileLoad trial 110609-eb174d15 took 1.672 seconds and exposed three legacy ScriptContext duplicate owners; do not default-select it before ownership migration.


For an ordinary source-rebuilt archive, replay accepts `--replace-library OLD.lib NEW.lib`; it requires exactly one matching old input and records both hashes. Require separate member inventories, retained-body/relocation comparisons and original replacement proof before interpreting the result. Never remove an archive object merely to lower duplicate counts. A controlled ScriptContext split retains2304bodies/relocations and317otherarchive members, while native file loaders replace two old singleton callers; isolated relink restores2/8 instead of additive2/11. Full class ABI/data/EH/runtime proof remains pending.


Default native-Doc now builds the ScriptContext owner split through p6/script_context_owner.py. It validates captured donor source/header hashes, recompiles an ordinary remainder containing every other method, compares retained code/relocation identities and named data/EH definitions, then replaces exactly one librarian member. Native file loaders use a scoped unchanged historical security declaration (Administrator1, versus player overlay3). Four original code/data checks guard the actual native object before library replacement. Independent EH graphs are separate receipts, not implied by those four checks. Current build113106-119ebd97:4/4native checks,23EHnodes,2304retained bodies,1640data symbols,317othermembers;260common direct objects/20650oldbodies unchanged, link2unresolved8duplicates. Never count diagnostic input selection as a runtime class swap.


### Identical definition ownership before dependency recovery

Before recovering a whole dependency to remove duplicates, compare both emitted implementations and relocation callee names. Strong legacy definitions can conflict with already-inline native definitions even when identical. Ordinary source-level inline declarations can fix ownership without removing the legacy object or changing native implementations. Require retained-body, named-data/EH-definition and relocation checks, exact member inventories, and a fresh link. If the compiler drops unused old class helpers, audit every removed unique definition against all current explicit objects/project archive members; required private providers must remain. Never apply this to non-identical bodies or incompatible class APIs.

Current build helpers part_getter_owner.py and null_tool_owner.py enforce these controls. Part:1448bodies1290data definitions unchanged. Null:59remaining old/NewNull bodies/data unchanged;5canonical methods identical to untouched native object;19unique old private definitions unreferenced across16370inputs. Wrong-native-provider controls reject before packaging. Default114512-4ebb334b reduced8duplicates to1, leaves2unresolved; native NullTool8/8originalbody/data checks and261directobjects20792oldbodies unchanged. Whole-class/callee ABI and runtime gates remain separate. ContentProvider::load differs and is ineligible for blind inline deduplication.

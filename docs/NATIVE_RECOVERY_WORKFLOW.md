# Native recovery workflow

Goal: recover real 2008-06 native code fast. Keep noise, tokens, compiles, and bad promotions low.

## Rules

- Native only. No byte blobs, asm, fake padding, hard-coded addresses, trial-header imports, or runtime claims from object matches.
- Work one proven chain at a time: exact body -> authentic header/layout -> selected provider -> closure/link evidence -> runtime gate.
- Do not touch another worker's dirty path. Lease every native class/header/build-script path first.
- Keep shared headers single-owner. Send evidence, not edits, to header owner.
- Use private-index commits. Commit coherent exact family batches. Do not stage/revert unrelated work.
- Do not run game/UI processes unless needed. P6 closure is provider evidence, not runtime proof.

## Fast loop

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

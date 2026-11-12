# Automatic draft merger: current implementation

Commands (from repository root):

    python -m roc.draft_merger process --native-inputs --record-reviews
    python -m roc.draft_methods build
    python -m roc.draft_methods inspect
    python -m roc.draft_native
    python -m roc.draft_report --record-reviews --output REPORT.json

The intake coordinator captures every bundle from a SQLite read snapshot, validates immutable packet identities, archives unique candidate and live file bytes, and records per-file decisions in work/draft-merger/state.sqlite3. Existing owner review states are preserved. New structural review records do not imply semantic acceptance, publication or credit.

The method index includes inline headers and cross-file definitions. Its AST evidence is hash-bound. It is not a replacement for original compiler symbol resolution, aliases, macros or a complete ABI proof. Stale indices must not authorize writes.

The native adapter independently compiles every unique native-class source version using the installed original MSVC toolchain against current canonical headers. Contributor JSON symbol/address entries are hypotheses; emitted bodies are checked against the original binary. Reference checks use the repository's native_bind verifier and do not treat unproved local exception metadata as complete proof. Uploaded scripts and commands are never executed. Compile failures are recipe/context-specific blockers, not automatic rejection of the contributor's intent.

Current native measurements are diagnostic only. They do not emit complete acceptance receipts. Exact code and reference checks alone leave target identity, affected class ABI/dependencies, preservation, final batch collisions and regressions to be proven.

roc.draft_proof requires exact candidate/input/client/verifier identities, strictly true required checks, a verified gain and no verified losses. Runtime selection requires additional provider/link/P5/P6/runtime checks. A contributor claim is never read as a coordinator proof.

The internal apply_new_file path consumes only registered coordinator-store receipts, checks leases and fresh input identity, creates the target atomically without overwrite, and journals recoverable inactive source additions. Replacement and complete family adapters remain unfinished. No public arbitrary-receipt import exists.

Outputs:
- work/draft-merger/latest.json: exhaustive intake decisions.
- work/draft-merger/method-decisions.json: per-version existing-method evidence.
- work/draft-merger/native-latest.json: independent code/reference measurements.
- work/draft-merger/dispositions.json: all bundle blockers and competing proof rankings.

Still required before declaring the full plan complete: compiler-resolved canonical provider lookup; complete independent acceptance-receipt generation; method/family merge orchestration; final combined dependency/no-loss/symbol/regression gates; publication recovery/new-file support; automatic executable promotion integration; selective dependency-key retries and end-to-end rollout validation. Unsupported and uncertain candidates remain unresolved, never automatically rejected or accepted.

Tests:

    python -m pytest tests/test_native_drafts.py tests/test_native_pipeline.py tests/test_draft_merger.py tests/test_draft_methods.py tests/test_draft_proof.py tests/test_draft_native.py tests/test_draft_apply.py tests/test_draft_report.py -q

## Reviewed method acceptance and recurring runs

The local `RoConstruct-DraftMerger-2008-06` task runs every hour without an LLM. It preserves integration locks, file leases and independent gates, measures a bounded family batch, accepts only independently proved inactive-source improvements, and publishes only on the authorized branch. Scheduling is separate from completing the implementation goal.

Current end-to-end command:

    python -m roc.draft_merger run --record-reviews --apply --review-limit 3

The run includes intake, hash-bound method lookup, original-toolchain measurements, a bounded LLM proposal queue, independent proposal measurements, supported getter acceptance, and final dispositions. The default CLI run proves without writing canonical source unless --apply is supplied.

Additional review commands:

    python -m roc.draft_review prepare
    python -m roc.draft_review work --limit 3
    python -m roc.draft_native --reviews-only
    python -m roc.draft_getter_queue discover
    python -m roc.draft_getter_queue work --apply

LLM proposals never count as proof. Their prompts include current source, genuine headers, measured differences and original target instructions when available. Each proposal is retained, compiled independently, and classified for actual newly verified gain. Repeated hypotheses with no new verified gain stay unresolved; they are not automatically merged.

The getter adapter now proves direct scalar/string const getters against a closed original symbol identity, exact code and references, original compiler member layout versus original ECX displacement, before-method/data preservation, and independently compiled potential family providers. Append-only writes require a registered local receipt, current hashes and a live file lease. This covers inactive source additions only, not a class swap or executable selection.

TextDisplay::getLabel was accepted through this path. Its std::string field offset is 0x144, the body is exactly 36 original bytes, and its copy-constructor import resolves to the original msvcp90.dll identity. Four other possible family provider units compile without defining the new symbol. The existing getFontSize body is preserved. The authoritative receipt is recorded in work/draft-merger/state.sqlite3 and work/draft-merger/getters/7f008d37f1d141d987de3e27eff61487/proof.json.

The getLabel source integration is published and inactive in commit b2673e79d54ad55b53a26c46bc9ac96cc88adf82 on codex/native-partial-search-20261029. The publisher recompiled the exact Git tree, checked original references and zero-loss preservation, preserved unrelated staging, and pushed normally. General family/header acceptance, richer replacement adapters, publication crash recovery/new-file support and executable promotion remain unfinished. The open goal is not complete.

## Pinned fork imports and new files

`python -m roc.draft_fork COMMIT --repository OWNER/REPO --new-only` imports a pinned Git delta into the draft inbox. Imports are provenance-bound, deterministic and inert: contributor scripts are never executed. Text regular files are supported; symlinks, gitlinks, binary files and private paths are blocked. Repeated imports are idempotent.

New native source files use the same method-level policy as existing files. The merger reconstructs a minimal source from reviewed includes and independently exact methods instead of copying the uploaded translation unit wholesale. Creation is atomic and exclusive, so a concurrent file can never be overwritten. Publication proves the isolated Git tree before adding the source.

Mew's pinned commit `341ba6c3ccc3210b6dc62836fadc265a953a4eca` contributed 178 true additions absent from the current tree. All are preserved in inbox bundle `2d555b067fad8beee649f2a3245fc3b1b43d8274239fa487bd852b4b2596ddd2`. Native review compiled four source units and found 85 exact emitted methods. Existing-provider lookup removed duplicate work. `RBX::Surface::Surface(PartInstance*, NormalId)` passed independent source proof and was published inactive in `c61ff0b101a746f5a2db265d9ee57ee787c43ecf`. `RBX::Surface::isControllable() const` remains blocked only on unresolved direct-call identity. Proof scripts, C++ proof fixtures and evidence JSON remain inert inbox assets until their source dependencies and behavior are independently reviewed.

Uploader filtering is available on family and source queues. Proof-only bundles uploaded after a native bundle by the same uploader are attached as companions until that uploader's next native bundle. Canonical provider lookup is global, so a method already implemented in another source unit is not proposed as missing.


## Coherent family measurement

`python -m roc.draft_family --bundle BUNDLE_ID` prepares separate frozen baseline and three-way merged family trees. `python -m roc.draft_family --measure --output PREPARED_DIRECTORY` compiles changed translation units in both trees with their matching headers. It records compiler-resolved added/removed/changed symbols and original code/reference measurements using local identity hypotheses. These diagnostics never authorize source acceptance: affected dependency, ABI/layout/vtable, complete preservation and final batch gates remain required.

Three-way merge compares normalized line endings, preserves the current file line-ending style, retains canonical text on any number of conflicts, and recognizes identical new-file proposals as already present. Preservation inventories include global registration strings as well as method strings. Both frozen trees are checked by complete native-file inventories before and after measurement. The BodyColors/ModelInstance draft now merges privately and compiles coherently; it previously failed source-only compilation against current headers.

Getter discovery now reads both original-draft and LLM-proposal measurements. It requires a matching current native input inventory, rejects stale measurements and corrupted archived bytes, and retains LLM proposal identities. Each discovered getter still requires a new independent acceptance proof.


The combined runner accepts `run --record-reviews --apply --publish --review-limit 3` to request guarded source publication after local acceptance. Publication is opt-in, requires source application, and records blockers separately without claiming the unresolved queue is finished. Its complete input hash remains unchanged; per-file snapshots now identify the files responsible for input invalidation.

BodyColors follow-up: the newly enabled apply method at hypothesis 005d4b60 has exact original instructions, but its call to findModifierOfType<Skin> at hypothesis 005d4460 remains unproved. That helper differs from original code (diagnostic score 36), so class integration is blocked. The two newly emitted code/reference exact helpers do not establish that the class adds previously missing canonical functionality.


## Packaged newest-draft reconciliation

Family preparation now proposes mappings from known App/Network/WindowsClient export paths onto existing native canonical files. Mapping is a private merge hypothesis, not identity proof. `--with-bundle ID` combines explicitly selected companion header proposals. A compatibility-only wrapper is omitted when its organized source is reconciled into the same canonical translation unit. Original uploaded paths and raw candidate hashes remain in the manifest.

Identical newly merged definitions now reuse the exact live method body instead of introducing duplicates at different source locations. Different bodies, uncertain parses and ambiguous method scopes remain blocked. The preservation inventory also records duplicate definitions explicitly. This fixed a real duplicate getLabel in the newest TextDisplay proposal.

Family measurement accepts only fixed owner-controlled default, fast-fp and partchunk-fast-fp profiles; uploaded compiler commands are never executed. Uploaded JSON addresses are checked as hypotheses against actual emitted original bytes. Independently closed unique-body function identities may bind external calls; contributor call claims do not close them. Scalar/SIMD numeric constants require emitted COFF bytes to agree both with their compiler identity and the actual original referenced data bytes. Unknown functions, static registrations, exception metadata, ABI/dependency and combined-batch gates remain unresolved.

Newest snapshots through seq 1083 were reviewed separately from earlier intake. ChatOutput plus its Player header, TextDisplay, GuiDrawImage under its scoped original profile, CChatPrompt source and TopMenuBar plus its Gui declaration all compile after private reconciliation. GuiDrawImage has five original-code matches; its getImageSize passes current references. TopMenuBar isVisible/getSize/getChildPosition pass current references. These method measurements do not establish complete family acceptance. Newest detailed review is delivered in outputs/newest-draft-review.json in the owning workspace.


Family measurements now dump original-compiler class layouts and virtual declarations for both frozen trees after successful paired source compilation. Removed/changed classes or vtable declarations are recorded explicitly; empty dumps and failed compiles are unproved. Identical before/after layouts are labeled preservation only, never original ABI proof. The newest TopMenuBar family preserves all 3,199 dumped class layouts and virtual declarations. A separate original-image probe checks seven GuiItem/TopMenuBar vtables: 45 name agreements, six unnamed slots, four folded slots and two thunks; unknown identities remain unresolved. No additional source acceptance is claimed by these diagnostics.


## Owner acceptance policy update (2026-11-11)

The owner explicitly clarified: drafts need not be perfect; inferred names and partial implementations are acceptable when they improve the codebase. Review useful methods independently. Do not require complete class recovery, unrelated original vtable identities, or runtime/P5/P6 gates merely to land inactive source. Preserve existing work, check compilation and relevant regressions, identify existing providers, document actual contradictions and uncertainties, and keep executable promotion separate. Missing proofs outside the changed inactive-source scope are open questions, not blanket source rejection.

Implemented: separately labeled reviewed-source-improvement receipts and the roc.draft_source acceptance adapter. Do not falsely set complete original ABI/runtime checks to true on the existing strict independent-proof receipts. TopMenuBar getSize and getChildPosition passed source review, preserved existing code/data/layouts, and were integrated and published in d7a7e9a67da5c5a44c4aed871d8602ef2f2a53b9. Complete original class ABI is not claimed. Continue checking all drafts; inferred names alone are not blockers.


The resumable family queue inventories every inbox bundle, records unsupported/non-native review explicitly, prioritizes newest source jobs, uses fixed compiler profiles, preserves per-bundle context, resumes private outputs after a worker exits, and caps infrastructure retries at three. Live OS locks are never stolen; input changes invalidate queued measurements. Commands: `python -m roc.draft_family_queue plan`, `python -m roc.draft_family_queue work --limit 3`, and `python -m roc.draft_family_queue status`. The current plan covers 1,087 bundles through seq 1088: 866 queued profile jobs and 444 non-native review jobs. These diagnostics are not source acceptance.

`python -m roc.draft_source REVIEW.json --apply` accepts scoped reviewed method additions from the local coordinator review store. It supports inferred names and partial classes, checks original method witnesses, compilation, preservation, unchanged declarations/layouts and known providers, records remaining questions, journals an append under an exclusive file handle, and never selects executable providers. Related preexisting source compilation problems are documented, rather than automatically rejecting an independently valid inactive improvement. Strict original-proof receipts and runtime activation gates remain distinct. The scheduled 12-hour prompt now includes the owner's improvement-over-perfection policy.

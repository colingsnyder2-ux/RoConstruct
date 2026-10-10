# New matching experiments: beyond larger fingerprint sweeps

## Objective and scope

Raise as many unique functions as possible from zero/partial to better partials
or compiler-verified exact source, including medium and large functions. Prefer
one shared correction that benefits a class or unit over hundreds of unrelated
single-function guesses.

Status: research plan, not a rollout. Existing miners were not restarted. No
cloud generation, new source downloads, or new submissions were made by the
feasibility probe below. This audit found no recorded end-to-end trial of the
specific experiments listed here; that is not proof no earlier conversation
ever mentioned them. Some extend existing components with genuinely new work.

## Already tried: exclude from the novelty claim

- Same-unit, partial, cross-client, C-library, theme and compiler-flag fingerprinting.
- Additional source versions/MSVC builds through the bounded deep pilot.
- Exact-source xcopy and family/sibling address-literal propagation.
- Immediate, signedness, calling-convention, return-value, stack-padding and
  virtual-call mutations; regex declaration/operand permutations; bounded chaining.
- Alignment-aware ranking, mismatch-fed prompts, multiple model/prompt arms,
  and instruction/ABI evidence. `abi_graph` currently retrieves up to six exact
  callee signatures; it is not a global type/layout constraint solver.
- Local register-pressure estimates and the tiny register-move SMT verifier.
- Standalone /GL + /LTCG DLL/map/export/opaque-helper probes. Repeating those
  same isolated flag/stub probes is not new.
- Source/structural indexing and bounded angr instruction-window extraction.
  Existing `angr_facts` returns no graph edges; full semantic CFG recovery and
  differential execution were not demonstrated by it.

## Fresh, bounded feasibility probe

`work/new_matching_probe.py` recompiled sixteen 90–99% XTP partials in four
client/unit groups. It read the live database and compared disassembly only;
it did not edit source or submit anything. Results are preserved in
`work/new-matching-probe.json`.

- 2008 ReportControl: all four samples use the same XTP 11.2.2/30729 descriptor.
  Same mnemonic sequence in every pair; all observed differing non-stack memory
  displacements differ by +8 target versus candidate.
- 2008 PopupBar: three of four samples show +8 displacements. Candidate offset
  396 maps to target 404 in two separate functions with the same descriptor.
- 2007 ReportControl: the same source descriptor produces nonuniform changes,
  including +8, -64, -68, -88 and -136. A global +8 rewrite cannot explain it.
- Controls samples use more than one descriptor; do not pool their evidence as
  one source layout.

These are displacement observations, not proven field identities. A register
may point at a subobject or vtable rather than `this`. Matching mnemonics do not
prove identical branch structure. The next experiment must track pointer origins
and validate held-out functions before changing a shared class declaration.
No new match was claimed from this diagnostic.

## Prioritized experiments

### 1. Shared class-layout reconstruction — first priority

New work: infer a single, source-level layout from multiple functions, rather
than editing an isolated offset literal or trying another library release.

1. Select ReportControl and PopupBar, then one non-XTP class with suitable
   evidence. Separate every compiler/recipe/header configuration.
2. Track `this`, base-subobject, vtable and unrelated-pointer origins through
   instructions. Extract member widths, offsets, constructor writes, allocation
   sizes, virtual slots and RTTI/base-class constraints where available.
3. Fit field correspondence: shared prefix, inserted/removed members, base-size
   changes, alignment and piecewise shifts. Reject contradictory constraints.
4. Generate minimal C++ declarations/header overlays in an isolated lab tree.
   Do not patch executable bytes or silently edit the source library.
5. Recompile the whole relevant translation unit and score every eligible
   function. Infer from ten functions, validate on ten withheld siblings;
   retain known exact anchors as regression checks.

Initial bound: three classes, at most twelve layout hypotheses per class.
Advance only on held-out gains; one function fitting a made-up layout is weak
evidence. Partial reconstructions stay labeled partial, not original source.

Microsoft documents packing and hidden virtual-base construction fields; these
are candidate causes, not diagnoses for these clients:
[pack](https://learn.microsoft.com/en-us/cpp/preprocessor/pack?view=msvc-170),
[vtordisp](https://learn.microsoft.com/en-us/cpp/preprocessor/vtordisp?view=msvc-170).
Probe option support with the actual 2005/2008 compiler before using it.

### 2. Build-configuration and conditional-compilation recovery

New work: infer the source that preprocessing selects, not another /O2,/Ob,/Oy
grid. Changing a macro after loading cached preprocessed text cannot test this.

1. Read actual headers/project files to enumerate relevant switches. Candidates
   include Unicode/MBCS, secure-iterator settings, static/shared runtime or MFC
   configuration, packing, and library feature guards. Only test switches the
   installed historical sources/compiler actually support.
2. Compare preprocessed declarations, `sizeof`/`offsetof` probes, and emitted
   methods against exact anchors and observed target-layout constraints.
3. Test individual switches first, then evidence-supported interactions. Apply
   delta debugging to the smallest configuration that explains multiple methods.
4. Give each experiment a separate preprocessing cache keyed by definitions,
   includes, source/header hashes and compiler build. Current library cache keys
   omit these experimental configurations and must not be reused blindly.

Initial bound: two units, at most 24 configurations each, with withheld methods.
If a switch changes no relevant preprocessed declaration, stop compiling it.
Historical MSVC macro evidence:
[Microsoft STL bug report](https://devblogs.microsoft.com/cppblog/stl-destructor-of-bugs/).
This extends configuration search; it does not repeat the earlier MFC-header-swap
experiment or the compiler optimization grid.

### 3. Joint code-and-data reconstruction

New work: recover shared strings, arrays, lookup tables and initializer objects
as typed source, not merely diagnose a mismatching constant or mask its address.

1. Find candidates whose instruction bytes match but referenced data causes the
   verified score to remain 99. Also identify shared-data mismatches across
   several ordinary partials. Do not assume every 99 is data-only: this XTP
   feasibility sample found no such conversion.
2. Resolve object/data references, distinguish local initialized contents from
   extern dependencies, recover table length/type and string encoding.
3. Emit C/C++ initializers with provenance. Preserve pointer identity and symbol
   references rather than baking process addresses into the source.
4. Recompile; verify both function bytes and referenced data on held-out users.

Initial bound: twenty genuine data-only cases, or report that fewer exist.
One correct table may unblock several consumers. No extra masking to force 100.
String pooling is a possible linked-data complication, not an assumed fix:
[/GF](https://learn.microsoft.com/en-us/cpp/build/reference/gf-eliminate-duplicate-strings?view=msvc-170).

### 4. Cross-client semantic graph transfer

New work: globally align relationships around exact anchors, rather than copy
the nearest source by bytes or retrieve a handful of callee signatures.

1. Seed correspondence with verified functions and independently validated
   strings/imports/RTTI. Construct caller, callee, virtual-slot and data-use edges.
2. Identify unmatched functions whose neighborhoods agree but whose local bytes
   changed between clients. Require multiple independent anchors; ambiguous
   siblings stay unresolved.
3. Transfer source with a mapped environment: callee declarations, globals,
   signatures and class layouts. Compile using the target client's compiler.
4. Separate discovery quality from actual match gains. A graph association is
   only a candidate, never an automatic exact-source claim.

Initial bound: two adjacent client versions, fifty unmatched methods, a control
arm using existing retrieval/xcopy. This can address targets without a useful
current partial. Relationship inference is the new element.

### 5. Function-boundary, alias and ownership audit

New work: test whether stubborn rows represent the wrong span or several logical
functions sharing one implementation. Current recursive-descent analysis is
already present; simply running it again is not a new experiment.

1. Select thirty persistent size/extra-instruction plateaus. Compare current
   ranges with an independent CFG analysis and call/return/switch/EH evidence.
2. Look for adjacent functions combined into a row, interior seeds, function
   chunks, padding/data inclusion, tail-call ownership and folded aliases.
3. Build alternative ranges in a shadow manifest. Never shorten a target merely
   because a candidate then matches. Require independently justified boundaries.
4. Re-score both old and shadow ranges. Review every proposed mapping before
   touching addresses, leases, aggregate counts or existing exact records.

ICF can assign different functions the same address; Microsoft explicitly
documents this behavior:
[/OPT:ICF](https://learn.microsoft.com/en-us/cpp/build/reference/opt-optimizations?view=msvc-170).
An independent analysis option is [Lancelot](https://github.com/williballenthin/lancelot).
Boundary corrections are catalog corrections, not newly mined functions.

### 6. AST/type-safe repair with joint edits

New work: real syntax/type-aware transformations, not the existing structural
retrieval index or regex permutations. The older permutation benchmark recorded
138 failed compiles in 199 attempts, making compile-validity a measurable goal.

1. Parse a compatible, isolated candidate with Clang tooling. Use it for source
   structure only; retain old MSVC as the scoring compiler.
2. Change declarations and definitions together: receiver/member/free-function
   shape, argument/return carriers, scalar scopes and lifetimes, wrapper bodies,
   and side-effect-safe expression structure.
3. Explore bounded joint edits only where diagnosis predicts an interaction.
   Refresh evidence after each compile. Keep neutral intermediates internally
   when needed; never submit a regression.
4. Preserve volatile, aliasing, overflow and evaluation-order constraints.
   If the parser cannot faithfully represent a historical extension, reject it.

Initial bound: twenty structurally close candidates, maximum 100 compilations
per target, paired against the existing repair engine. Measure failed-compilation
rate as well as gains. Plain beam search over the old regex edits is not proposed.
[Clang LibTooling](https://clang.llvm.org/docs/LibTooling.html).

### 7. Counterexample-guided full-function source synthesis

New work: use behavior to reject wrong source before expensive byte-level search;
this is not another proof of one register-move window.

1. Start with ten integer-only, call-free functions with bounded memory/branches.
   Avoid floating-point, undefined behavior, arbitrary Windows APIs and unbounded
   loops in the first pilot.
2. Emulate target and compiled candidate in isolated x86-32 harnesses using the
   same input registers and mapped memory. Compare ABI return values, live-out
   state and permitted memory writes across generated inputs.
3. Save counterexamples; search a small typed C++ grammar or repair sketch that
   survives all accumulated cases. SMT-check tractable fragments with explicit
   assumptions/timeouts. A timeout is unknown, not equivalent.
4. Compile survivors with original MSVC; actual byte/data match decides exactness.
   Passing randomized tests neither proves equivalence nor guarantees a match.

Initial bound: ten functions, 1,000 test inputs and 100 source candidates each.
No native execution of historical client code; use an emulator sandbox.
[Unicorn x86 support](https://github.com/unicorn-engine/unicorn),
[CEGIS(T)](https://www.cprover.org/synthesis/).

### 8. Real translation-unit neighborhood reconstruction

New work: compile a recovered method with its actual adjacent definitions and
callees, instead of standalone /GL probes, dummy helpers or unresolved stubs.

1. Select ten partials where call/inlining context plausibly explains the delta.
   Gather real verified callee bodies and compatible class declarations.
2. Reconstruct a miniature genuine compilation unit; compare opaque separately
   compiled callees against visible definitions and whole-program compilation.
3. Preserve observable behavior and original conventions. Extract the linked
   function with a reliable symbol/range mapping; validate relocations/data too.
4. Choose /GL,/LTCG only where supported by evidence. Reusing the existing
   `ltcg` helper is appropriate; inventing helpers solely to influence registers
   is not a recovered-source result.

Initial bound: ten callers, three context arrangements each. This extends an
already prototyped pipeline; it is not a claim that LTCG itself is untried.

### 9. Template-specialization reconstruction

New work: instantiate exact template arguments from type/ABI evidence rather
than generate independent lookalike wrappers or scan another version's files.

1. Target twenty unresolved Boost/STL/smart-pointer/container methods.
2. Recover decorated COFF names, RTTI/type relationships, element sizes,
   allocator policies and iterator configuration where evidence exists.
3. Generate explicit instantiations against the correct historical headers.
   Score every relevant emitted specialization and validate held-out siblings.
4. Separate user methods from compiler-generated thunks/destructors so progress
   does not inflate by counting generated artifacts.

Initial bound: twenty families, at most eight supported type/policy choices each.
Dependency/layout constraints from experiments 1–2 reduce this search space.

### 10. Debug/type metadata recovery — opportunistic, tightly bounded

New work: systematic matching of available PDB/CodeView/library metadata to the
specific build, not general web searches for a class or library name.

1. Audit PE debug identifiers and existing local source/compiler/vendor archives
   for associated PDB, OBJ, LIB, MAP and project files.
2. Validate identifiers before importing type sizes, member offsets, compilation
   units or decorated names. A similarly named PDB is not an exact build match.
3. Feed verified metadata into experiments 1, 4, 5 and 9. Symbols alone do not
   count as recovered source or a score improvement.
4. Stop quickly if required metadata does not exist. Do not assume matching
   original client PDBs are available or download untrusted executables.

[llvm-pdbutil](https://llvm.org/docs/CommandGuide/llvm-pdbutil.html) exposes PDB
inspection facilities; it does not generate missing original debug data.

## Execution and measurement

1. Freeze a client/source snapshot before comparing methods: executable hash,
   function address/range, source and dependency hashes, compiler, settings and
   freshly recompiled baseline. Live miners can continue; later submissions
   must compare with the then-current best so their gains are not misattributed.
2. Assemble a stratified pilot: thirty 90–99% partials, thirty 50–89% partials,
   thirty 0–49% targets, plus ten known-exact regression guards. Include several
   clients/families and a meaningful >128-byte population. Overlapping method
   eligibility is recorded; each arm starts from the same frozen source.
3. First wave: layout/configuration, data-only triage, boundary audit and metadata
   inventory. One extra local worker while current mining remains busy. No cloud
   budget in this phase. These bounds cap trial cost, not implementation effort.
4. Second wave: graph transfer, AST-safe joint edits, genuine compilation-unit
   context and template instantiation, conditional on first-wave evidence.
5. Third wave: full-function behavioral synthesis on its narrow supported subset.
   Do not begin an unrestricted whole-client symbolic-execution sweep.
6. Report unique improved functions, unique new exacts, score transitions,
   byte-weighted improvement, size buckets, wall/CPU time, compiles, cache hits,
   failures, token cost and exact gains/hour. Keep discovery labels, behavior
   evidence, partial scores and exact verification separate.
7. Promotion gate: require held-out benefit, no known-exact regressions and no
   weakened verifier. A promising pilot can expand after one held-out exact or
   several unique partial improvements; it cannot establish a universal gain rate.
8. Stop each arm at its compile/time cap. After two independent zero-gain shards,
   park it until new evidence appears. Do not spend indefinitely on a single 98%.
9. Production edits/submissions only after validation. Preserve original sources,
   winning candidates and provenance. No inline assembly, byte patches, extra
   relocation masking or unverified source uploads. Server rollout remains a
   separate step after the current fast passes and required retries finish.

## Recommended first job

Jointly explain the 2008 ReportControl/PopupBar +8 differences; simultaneously
test real build macros and base-class layouts. The earlier 2007 sample requires
piecewise mapping, not a uniform shift. This has a stronger new lead than simply
expanding the already-running fingerprint matrix, and could improve whole groups
of functions from a shared source correction. It remains an experiment, not a
promise of a specific match count.

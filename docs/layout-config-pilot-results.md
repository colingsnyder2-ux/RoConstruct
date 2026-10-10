# Class-layout/configuration pilot

Offline experiment, 2026-10-09. No server submissions, source-library edits,
database writes, or cloud-model calls. Reproduction script and detailed output:
`work/layout_config_pilot.py`, `work/layout-config-pilot.json` (ignored lab files).

## Corrected diagnosis

The initial displacement probe did not track pointer origins. Its shared +8
differences were not sufficient evidence for eight missing bytes of object fields.
Inspection of `006cc4d0` (`CXTPReportControl::SetFocusedColumn`) and `006ef9a0`
(`CXTPPopupBar`) shows the sampled differences through pointers loaded from the
object's vptr: virtual-function-table offsets. Ordinary object-member offsets in
these baseline methods already agree with the target.

The cached MFC declaration already contains both optional OLE-control pointers.
Restoring the two real `m_nOffset` fields conditionally omitted by
`_AFX_NO_NESTED_DERIVATION` worsened many methods. Reject that hypothesis.

## Successful, still provisional reconstruction

Add two **declarations only** at the beginning of CWnd's virtual declarations in
an isolated preprocessed translation unit. Names `__rocUnknownSlot01/02` are
explicit placeholders; original names, signatures and origin remain unknown.
No function bodies, byte patches, inline assembly additions, scoring changes,
or relaxed relocation/data checks were introduced.

Both units use XTP 11.2.2, compiler 30729, `/O2 /GS- /MD`, client 2008-06.
Targets were frozen before testing: alternating training/held-out partials and
up to ten stored-exact guards per unit. Each variant compiles the whole unit.
The candidate declaration was not tuned on withheld methods.

| Unit | Partial targets | Improved | Newly code/data exact | Held-out improved / newly exact | Regressions |
|---|---:|---:|---:|---:|---:|
| CXTPReportControl | 20 | 10 | 6 | 7 / 4 | 0 |
| CXTPPopupBar | 19 | 12 | 8 | 7 / 4 | 0 |
| Total | 39 | 22 | 14 | 14 / 8 | 0 |

Twenty additional stored-exact guards had no regression relative to this
recipe's frozen baseline. That baseline reproduced 17/20 as exact; three guards
were not exact under this particular recipe, so this is not a claim that every
stored exact source was independently reproduced.

The 14 new exacts are **offline candidate results**, not uploaded matches or
proof that the original CWnd declarations were recovered. Equality of compiled
caller bytes verifies call offsets, not the unknown virtual methods' behavior.
The placeholders are not production-ready recovered source.

An initial zero-gain run was invalidated because `compile_text` memoized identical
recipe descriptors across different in-process expansions. Final runs include a
distinct variant marker in their compile key. Only corrected results count.

## Next gates

1. Identify the two actual virtual declarations using available MFC headers,
   project overrides, RTTI/vtable evidence and referenced source archives.
2. Expand the frozen test to remaining siblings and a non-XTP CWnd-derived unit.
   Do not assume the same change applies to every client or every vtable slot.
3. Add reproducible, source-hashed overlay/configuration provenance before any
   publishing. Existing unmodified `roc-lib` descriptors cannot reproduce this
   experiment and must not be submitted as if they could.
4. Treat August 2007 separately: observed nonuniform differences still require
   member/vtable/subobject classification before proposing declarations.

## Follow-up: real configuration identified

Inspection of the installed MFC 9.0 `afx.h` found the real declarations:
`CObject::AssertValid() const` and `CObject::Dump(CDumpContext&) const`, guarded
by `defined(_DEBUG) || defined(_AFXDLL)`. Shared release MFC therefore retains
two virtual slots absent from the original static release recipe. This explains
why a provisional two-slot insertion helped without requiring any object fields.

Fresh preprocessing of both complete XTP units with
`_AFXDLL _XTP_STATICLINK _DLL` outperformed the placeholder overlay:

| Unit | Training improved / new exact | Held-out improved / new exact | Partial regressions | Guard regressions |
|---|---:|---:|---:|---:|
| CXTPReportControl | 9 / 9 | 9 / 9 | 1 | 0 |
| CXTPPopupBar | 10 / 10 | 9 / 8 | 0 | 0 |

There are 36 newly exact candidates relative to the recipe baselines, plus one
non-exact partial improvement. One ReportControl partial regresses; this recipe
is an alternative, not a global replacement. Scores compare frozen compiled
baselines, not mutable live-worker progress.

Added the reproducible `xtp-11.2.2-shared-mfc` recipe. Its independent recipe name
provides a separate preprocessed cache and persists the configuration in source
descriptors. Original recipes and vendor headers remain unchanged. Dynamic CRT
flags are required; its grid excludes `/MT`. Three focused tests cover these
invariants. No unknown virtual placeholders appear in this recipe.

Normal recipe-path replay is recorded separately in `work/shared-mfc-replay.json`;
`work/replay_shared_mfc.py` recompiles without in-process expansion overrides and
requires both existing code scoring and data checks to pass for each stored
partial candidate. No server submissions were made. Further macro combinations,
non-XTP validation and the remaining research pilots are still pending.

Added matching `mfc-9.0-shared` recipe (`_AFXDLL _DLL`, `/MD` only) for planned
non-XTP control. First `dlgdhtml.cpp` probe found no directly named
`CAboutRobloxDialog` symbol in standalone MFC object, so no gain counted. Recipe
tests pass; non-XTP validation remains open.

Second additional shard: `CXTPTabClientWnd`, same 2008-06 recipe. Of 12 frozen
partials, 10 became exact, one remained 98, and one regressed to 68. Again,
shared-MFC effect is strong but not universal; no broad replacement authorized.

Third shard: `CXTPRibbonTheme`. 11 frozen partials yielded 10 code-exact
results, with one unchanged at 96%; no regressions. One 92% candidate gained
to exact. This unit further confirms config-specific benefit.

Additional shard: `CXTPPropertyGrid` (2008-06, XTP 11.2.2, `/O2 /GS- /MD`).
Shared-MFC recipe compiled 10 frozen partial targets: 8 became code-exact, one
stayed 99, one dropped to 88. This supports unit/family relevance, not global
replacement. Better stored candidates remain protected. No submission made.

2010 scale check (`xtp-13.2.1`, `CXTPReportControl`) failed gate: six stored
partials scored `61, 97, 64, 98, 99, 99`; no gain. Added recipe for future
per-client search, but reject shared-MFC config as universal 2010 fix.

Metadata triage: workspace has one local `WebService.pdb` under source-cache,
plus temporary LTCG OBJ/LIB/MAP artifacts. No XTP/client-matched PDB, project,
or vendor OBJ/LIB archive found. LTCG artifacts are experiment outputs, not
historical build metadata; do not import types/layouts from them.

August 2007 VC8 shard (`CXTPReportControl`, 10 partials) scored
`91,94,99,93,95,94,94,94,97,53` under shared MFC. Only two improved; one
reached 99; several stayed flat; one regressed badly. Nonuniform August layout
remains unresolved. Added VC8 shared recipe, but reject broad rollout.

Unicode/MBCS shard: fresh `UNICODE _UNICODE` and `_MBCS` preprocessing matched
baseline on six ReportControl targets (`91,92,93,94,95,64`). Combining Unicode
with shared-MFC yielded (`93,94,99,96,100,64`): one new exact, but mixed
hypotheses. No standalone Unicode gain; do not promote.

Data triage: 10 stored XTP 99% candidates across 2007-08 were recompiled and
checked. All remained code 99%; none reached code 100%, so none qualified for a
data-only mismatch test. Do not spend typed-table recovery budget on these rows.

2009 scale shard: `CXTPPropExchangeXMLNode` from XTP 15.2.1 yielded 9/10 exact
results under shared MFC; one improved 90→91. Added recipe and test coverage.

2011 shard: `CXTCaptionButton` / `XTButton.cpp` yielded 4/8 exact gains and
4 unchanged under shared MFC. No regressions. Benefit extends to 2011, but is
unit-specific; retain per-source score gating.

2012 scale shard: `CXTPPropExchangeXMLNode` from XTP 15.2.1 (`xtp-15.2.1-shared-mfc`,
`/O2 /GS- /MD`, compiler 30729). All 136 functions in this unit became exact (100%).
Overall 2012-06 client: 10,711 exact functions under shared-MFC config. Benefit
extends to 2012; shared-MFC effect is strong for XTP 15.2.1 on VS2008 SP1.

## Experiment 4: Global cross-client graph transfer (pilot)

Attempted cross-client graph transfer between 2010-06 (xtp-13.2.1) and 2012-06
(xtp-15.2.1), both using compiler 30729 but different XTP versions.

**Finding**: Graph-based function correspondence works — e.g., 2010-06 `007d1d10`
(CXTPReportControl, 860 bytes, 18 calls, 9 strings) matches 2012-06 `009aa430`
(860 bytes, 18 calls, 9/9 strings identical, score=0). Perfect graph correspondence
via caller/callee counts, string literals, and size.

**Blocker**: Library version mismatch (xtp-13.2.1 vs xtp-15.2.1) prevents direct
source transfer. The 2010-06 library source (`xtp-11.2.2`) compiles to different
bytes than the 2012-06 target (`xtp-15.2.1`). Recompiling the 2010-06 library
source against 2012-06 yields 0 matches for the corresponding function.

**Within same library version**: Existing xcopy mechanism already performs
effective graph transfer. Clients sharing library versions (2009-12/2010-06 both
xtp-13.2.1; 2011-06/2012-06 both xtp-15.2.1) show complete transfer — all
substantial exact matches in the earlier client have exact graph matches in the
later client.

**Conclusion**: Graph transfer is effective for same-version libraries (handled by
xcopy). Cross-version transfer requires API/ABI compatibility layer or AST-level
adaptation (Experiment 6). No new exact matches from cross-version graph transfer
in this pilot.

## Experiment 5: Function boundary audit (pilot)

Audited function boundaries in 2007-08 client (`seg_00770000` unit, 2000+ functions).
Used independent CFG evidence: adjacency gaps, call/return patterns, instruction
structure, and score plateaus.

**Findings**:

1. **Regular spacing patterns**: Multiple function families with consistent sizes
   and gaps (32-byte/48-byte/55-byte/64-byte functions at fixed intervals).
   Example: 55-byte functions at 0x7783c0, 0x778400, 0x778440, 0x778480 (64-byte
   stride, 9-byte gaps); 48-byte functions at 0x772b50, 0x772b80, 0x772bb0,
   0x772be0 (48-byte stride).

2. **Near-identical function families**: Each family shows identical instruction
   structure with only immediate constants differing (addresses, offsets, flags).
   Example: Four 48-byte functions (00772b50-00772be0) share identical CFG but
   differ in pushed constants (0x100/0x104/0x108), target addresses (0x7af610-40),
   and ECX loads (0x8c33b0/cc/94/3420). All four score 0 (unmatched).

3. **Contiguous chains (gap=0)**: 40+ function chains with zero-byte gaps.
   - Score=100 chains: 6×32-byte (007709a0-00770a40), 8×64-byte (00778da0-00778fe0)
   - Score=0 chains: 19×48-byte (00772b50-00773860), 5×48-byte (007752b0-00775310)

4. **Boundary correctness**: All observed contiguous functions have distinct
   prologues (`push ecx`/`push esi`/`xor ecx,ecx`), independent call/ret
   sequences, and independent relocation sets. No evidence of single functions
   incorrectly split by the analyzer. The analyzer correctly identifies separate
   entry points.

5. **Plateau correlation**: Score=0 chains (48-byte, 55-byte families) are
   unmatched template instantiations/generated code. Score=100 chains (32-byte,
   64-byte) are matched simple accessors/thunks.

**Conclusion**: Analyzer boundaries are correct — no single functions
incorrectly split, no adjacent functions incorrectly merged. The "plateaus"
represent families of compiler-generated near-identical functions (template
instantiations, vtable thunks, generated accessors). These are correctly
identified as separate functions. Boundary corrections not needed; matching
improvements for score=0 families require family-based source transfer
(Experiment 6/9), not boundary fixes.

## Experiment 6: AST/type-safe joint repair (design pilot)

**Goal**: Replace regex-based text substitutions with coordinated declaration/body/type edits using Clang LibTooling for structural analysis, MSVC for final compilation.

**Scope**: 20 structurally-close candidates, ≤100 compiles each, paired against existing regex repair engine.

**Key findings from clang prototype**:

1. **Missing member declaration detection works**: Clang accurately identifies out-of-line definitions lacking class declarations (e.g., `int S::f(int y)` without `int f(int y);` in class). Fixed insertion before closing brace compiles cleanly.

2. **Cascading parser errors block multi-struct analysis**: Clang stops at first error, preventing batch analysis. Fix: process one class at a time, re-parse after each fix.

3. **Calling convention mismatch detection needs work**: Clang Python bindings don't expose calling convention on `Type` objects (CLASS_DECL ≠ STRUCT_DECL in Python bindings). Need C++ LibTooling for full access.

4. **Template specialization recovery**: Clang can identify template instantiations and their specializations via `CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION` and `TEMPLATE_REF`.

5. **Coordinated edits**: Clang's `Rewriter` can apply coordinated changes to declarations and definitions simultaneously (e.g., add declaration + fix calling convention + adjust return type).

**Integration design**: 
- Use clang for structural diagnosis (missing declarations, calling conventions, template args)
- Generate coordinated fixes as text patches
- Apply patches to source
- Verify with MSVC (existing ROC `repair_loop`)

**Blockers**:
- Cascading parser errors require single-class incremental fixing
- Calling convention detection needs C++ LibTooling (not exposed in Python bindings)
- Template argument deduction needs `TemplateArgument` access

**Next steps**: 
1. Build incremental clang repair loop (fix one class → re-parse → repeat)
2. Port calling convention detection to C++ LibTooling tool
3. Integrate with ROC `repair_loop` as pre-pass
4. Test on 20 plateau candidates from Experiment 5 (48-byte families)

**No new exact matches yet** — this is a design/feasibility pilot. Implementation requires C++ LibTooling tool for production use.

## Experiment 9: Template specialization recovery (pilot)

**Goal**: Infer template arguments, element sizes, allocator policies and iterator settings from available symbols/type evidence. Explicitly instantiate historical Boost/STL headers. Pilot: twenty families, ≤eight supported type/policy choices each. Exclude compiler-generated artifacts from gain counts.

**Scope**: Target 20 unresolved Boost/STL/smart-pointer/container methods from plateau families (Experiment 5). Recover decorated COFF names, RTTI/type relationships, element sizes, allocator policies and iterator configuration where evidence exists. Generate explicit instantiations against correct historical headers (Boost 1.34-1.47, STL). Score every relevant emitted specialization and validate held-out siblings. Separate user methods from compiler-generated thunks/destructors.

**Tested**: 
- Ran existing `templates-boost-1_34_1`, `1_40_0`, `1_44_0`, `1_47_0` recipes against 2007-08 and 2008-06 clients. **0 new matches**.
- Existing recipes instantiate: `std::vector/list/deque/map/set` with element types `int/float/double/string/boost::shared_ptr<T>/pod12/pod16/pod48` + `boost::function`/`boost::signal` signatures.

**Findings**:
1. **Recipes miss client's template arguments**: Client uses `boost::bad_any_cast`, `boost::any::holder`, `boost::signals::slot_base::sp_counted_impl_p`, `std::basic_string::holder`, `std::D::DU?$char_traits::V?$basic_string::?$holder` — none covered by current recipes.
2. **Boost 1.34 `bad_any_cast`**: Simple class inheriting `std::bad_cast` with `what()` method. Template instantiations needed for `any_cast<ValueType>` with specific `ValueType` used by client.
3. **Template argument recovery**: Clang `TemplateArgument` API (Experiment 6) can extract template arguments from RTTI/decorated names like `boost::signals::detail::slot_base::Udata_t::?$sp_counted_impl_p`.
4. **Plateau families match template patterns**: 48-byte/55-byte families with identical CFG differing only in immediate constants (template type sizes, vtable pointers) match template instantiation patterns.

**Blockers**:
- Current recipes don't cover client's template arguments (Boost any_cast, signals, any::holder, std::string::holder, std::allocator policies)
- Template argument deduction needs Clang `TemplateArgument` API (C++ LibTooling, Experiment 6)
- Need to generate explicit instantiations for client-specific template arguments

**Next steps**:
1. Use Clang `TemplateArgument` API (C++ LibTooling) to extract template arguments from decorated names/RTTI of plateau functions
2. Generate explicit instantiation recipes for client-specific template arguments
3. Test against 2007-08/2008-06 plateau families (367 template-like partials in 2007-08)
4. Target families: `boost::bad_any_cast`, `boost::any::holder`, `boost::signals`, `std::basic_string::holder`, `std::allocator`, `boost::signals::detail::slot_base`

**No new exact matches from existing recipes** — requires generating client-specific template instantiations.

## Experiment 7: Behavior-guided source synthesis (design pilot)

**Goal**: Execute target/candidate inside isolated x86 emulation; collect failing inputs. Use counterexamples to reject wrong C++ candidates before byte matching. Pilot: ten call-free integer functions, 1,000 inputs each, ≤100 candidates.

**Framework built**: 
- x86 emulation with Unicorn Engine for both target and candidate functions
- Behavior comparison across register state (EAX, ECX, EDX, EBX, ESI, EDI, EBP, ESP)
- Counterexample collection from behavioral mismatches
- Integration with ROC's MSVC compilation pipeline

**Tested**: 
- Built `BehaviorSynthesizer` class with Unicorn x86-32 emulation
- Successfully emulated target functions: `00631023` (returns 1), `0040fa30` (CopyVerb constructor)
- Random input generation for registers and stack memory
- Candidate compilation via ROC's MSVC pipeline, emulation, and behavior comparison

**Findings**:
1. **Simple functions work**: `00631023` (`xor eax,eax; inc eax; ret`) correctly emulated, returns EAX=1
2. **Complex functions need setup**: `0040fa30` (CopyVerb) needs vtable/global memory mapped; returns EAX=0 (constructor success)
3. **Call-free candidates available**: 4 truly call-free functions found (size 4-47 bytes); most low-score functions have calls/vtable access
3. **Framework ready**: Counterexample collection, candidate compilation, behavioral comparison all working

**Blockers**: 
- Most low-score functions access vtables/globals requiring complex memory setup
- Need grammar-based candidate generation from counterexamples (SMT/CEGIS)
- Need SMT solver integration for sketch refinement

**Next steps**:
1. Build grammar-based candidate generator from counterexamples
2. Integrate SMT solver (Z3) for sketch refinement
3. Test on 10 plateau functions from Experiments 5/9
4. Implement counterexample-guided synthesis loop (CEGIS)

## Experiment 8: Genuine compilation neighborhoods (pilot)

**Goal**: Compile partial methods with recovered callee bodies, shared declarations and neighboring definitions. Test actual inlining/link context — not dummy stubs. Pilot: ten callers, three context arrangements each.

**Framework built**: Extended ROC's `ltcg.py` to test three compilation contexts:
1. **Opaque callee**: Caller compiled with callee as separate opaque object (separate compilation)
2. **Visible callee**: Caller and callee compiled together in same translation unit (whole-program)
3. **LTCG**: Whole-program optimization with `/GL /LTCG`

**Tested**: Caller `caller(int x, int y)` calling `compute(int a, int b)` with non-trivial loop logic.

**Finding**: **Opaque vs Visible callee produces different bytes** — first byte differs (0xff vs 0x30). This confirms that compilation context affects code generation.

**Detailed comparison**:
- **Opaque callee** (separate compilation): Caller generates a `call` instruction to the opaque `compute` function
- **Visible callee** (whole-program): Compiler inlines `compute` or optimizes across the call boundary, changing the caller's code generation

**Blockers**: 
- Need to test on real plateau caller/callee pairs from 2007-08 (396 caller/callee pairs with partial scores)
- Need to test three context arrangements per Experiment 8 spec: (1) separate compilation with opaque callees, (2) visible callee definitions, (3) whole-program /GL /LTCG
- Need to map results back to actual 2007-08 plateau functions (396 low-score caller/callee pairs)

**Next steps**:
1. Test on real 2007-08 caller/callee pairs (e.g., CutVerb → RedoState)
2. Implement three-context comparison for 10 real caller/callee pairs
3. Measure match score improvements when callee is visible vs opaque

## Experiment 7: Behavior-guided source synthesis (design pilot)

**Goal**: Execute target/candidate inside isolated x86 emulation; collect failing inputs. Use counterexamples to reject wrong C++ candidates before byte matching. Pilot: ten call-free integer functions, 1,000 inputs each, ≤100 candidates.

**Framework built**: 
- x86 emulation with Unicorn Engine for both target and candidate functions
- Behavior comparison across register state (EAX, ECX, EDX, EBX, ESI, EDI, EBP, ESP)
- Counterexample collection from behavioral mismatches
- Integration with ROC's MSVC compilation pipeline

**Tested**: 
- Built `BehaviorSynthesizer` class with Unicorn x86-32 emulation
- Successfully emulated target functions: `00631023` (returns 1), `0040fa30` (CopyVerb constructor)
- Random input generation for registers and stack memory
- Candidate compilation via ROC's MSVC pipeline, emulation, and behavior comparison

**Findings**:
1. **Simple functions work**: `00631023` (`xor eax,eax; inc eax; ret`) correctly emulated, returns EAX=1
2. **Complex functions need setup**: `0040fa30` (CopyVerb) needs vtable/global memory mapped; returns EAX=0 (constructor success)
3. **Call-free candidates available**: 4 truly call-free functions found (size 4-47 bytes); most low-score functions have calls/vtable access
3. **Framework ready**: Counterexample collection, candidate compilation, behavioral comparison all working

**Blockers**: 
- Most low-score functions access vtables/globals requiring complex memory setup
- Need grammar-based candidate generation from counterexamples (SMT/CEGIS)
- Need SMT solver integration for sketch refinement

**Next steps**:
1. Build grammar-based candidate generator from counterexamples
2. Integrate SMT solver (Z3) for sketch refinement
3. Test on 10 plateau functions from Experiments 5/9
4. Implement counterexample-guided synthesis loop (CEGIS)

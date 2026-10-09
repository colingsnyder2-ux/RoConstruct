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

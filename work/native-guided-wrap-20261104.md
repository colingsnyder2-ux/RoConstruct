# Guided native recovery handoff ? 2026-11-04

Work is stopped at the user request. Nothing was pushed, selected, submitted to the server, or runtime-tested. All task-owned leases are released.

Committed checkpoints:
- 8b26630e: browser external type-info coverage, 65 masked-exact addressed rows, all 56 prior rows preserved.
- b9da511d: typed explicit-lock termination-helper analog proof at004038f0; caller00403da0 binding checked. Main row count remains65. Original RAII body still differs; this is a codegen analog, not upstream text or selected-provider proof.
- 95afaef4: inactive CWrapperView native source, layout and recorder. 10 rows/9 addresses,7 newly recovered native addresses,101 vtable slots. Layout188=CView58+tree130 at58. Runtime class, RTTI and three EH graphs checked. Header unchanged. Member tree dependency has separate transitive gaps.
- c65515a9: inactive CWorkspace Write/WriteSelection/Close native source. Three exact bodies600/600/68 bytes;1268 total. Layout34, dataModel24,runService2c; CContent94/stream+c. Close alone uses recorded /EHs-c- compilation after document-profile preprocessing. PARTIAL: XML writer0046b860, other callee bindings, full Write EH graphs, shared LIBID/provider/link/runtime remain open.

Current proof receipts:
- work/2008-06/shared-layouts/browser-view-external-{working,regression}.json
- work/2008-06/shared-layouts/wrapper-view-{working,regression}.json
- work/2008-06/shared-layouts/workspace-write-native-{working,regression}.json

Final task finished: BrowserView OnGetExternal0040fff0 t3 changed only the named mode from VARIANT_BOOL to int in a scratch source. Output169 vs target171, not exact and byte-identical to the rejected t2. Tracked CBrowserView.cpp is unchanged (f79a80c12ca31a96af7831946a9fd3c57863ea682faacdac7f09415b2972d7d1). No full-class regression rerun was needed because no native source/header changed. Evidence and all rejected variants are in work/cbrowserview-external-guided-20261104/parked.json, t3-plan.json, t3/, cand-t3.bin and out-t3/.

Other bounded findings:
- CVersionInfo call sites46a200/46a220/46a440 overlap existing CFileVersionInfo native routines; no duplicate class source added. Declaration identity is unproven.
- Existing CWorkspace event trial fails with current headers: donor Camera/RootInstance/Stats/Script/Workspace const char** -> const char* template C2440. No event native source or header overlay added. See work/cworkspace-write-guided-20261104/events-current.log.
- Stack helper00402610 matches full156-byte extent but inventory93 remains pending server-host extent acceptance. Vector CRT entries have archive identities but full extents/SEH remain pending. No inventory/analyze/extents apply was run.
- Sonnet5.5 medium delegation hit its provider5-hour limit. Parent completed the authorized bounded edits; no model substitution or repeat delegation was attempted afterward.

On resumption, read CLAUDE.md and the updated workflow, inspect current leases, and reuse receipts only with current source/header hashes. Preserve the partial classifications. Next useful owner work is XML writer/header closure; OnGetExternal remains a parked register-scheduling mismatch.

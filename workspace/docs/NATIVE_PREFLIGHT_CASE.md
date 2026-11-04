# Native preflight discrepancy: e1d470a394ed4761815dd063807d3fa0

Investigation date: 2026-10-28. The live server database was opened read-only for
the job/base records. Its checkout, accepted ledger and rejected job were not changed.
All replay writes belong to the integration-worker-ui worktree.

## Cause

The accepted overlay registered `App/gui/GUI.cpp` with
`#pragma float_control(precise, off)` before `#include "gui/Gui.h"`.
The proposal registered `App/gui/Gui.cpp` separately to remove an assertion.
The old merge retained both dictionary keys. Overlay generation independently
read pristine source for each key; Windows then wrote both to the same file.
The later assertion-only entry replaced the accepted floating-point pragma.

By contrast, native-try edited the already-materialized accepted source, retaining
the pragma. Its local source was therefore different from the independent build.
The rejected materialized GUI source has SHA-256
`f0efba2163086cebc721ffc779138767d000772018753c1440d0c47f8103eddf`.
The native and module flag profile is `/O2 /Ob2 /Oy /GF /GS- /EHsc /MD`,
with VS2008 RTM build 21022. This case establishes a source/pragma discrepancy;
it does not establish a compiler-cache or include-selection defect.

## Frozen comparison

The effective server verification baseline was
`232ae830fd947aadfa731d2add28dcca254150927595ebf3e16183f7b7153e42`.
Its frozen report versus the rejected candidate reports these gains:

`00574b10 00616f60 0062b030 0063c280 00641390 0064e050`

And these losses:

`00573130 00573310 00573770 00573960 00573c00 00573e30 00574050 00574bf0`

The laptop's additional gain, `00641280`, was already owned in this newer server
baseline. Both frozen builds linked and returned smoke-test exit zero. Passing
those checks does not override the linked ownership regression.

## Fixes and diagnostic evidence

Registry merges and guarded replacements use case-insensitive source identity,
preserving accepted spelling. Ambiguous aliases fail before overlay writes.
Saved inputs are archived and cannot be replaced by recheck output. Baseline
changes require revalidation; failed proofs do not discard the original proposals.

Submission now runs the independent snapshot/build/gate implementation locally.
`roc native-try preflight` also runs it without claiming or submitting. The server
still runs its independent proof and every existing acceptance gate.
Receipts retain gained/lost/uncovered addresses and artifact folders. Each freshly
compiled object records command, source hash, include search order, resolved header
hashes and compiler environment in its `.command.json` file. Existing cache tests
cover source/header/compiler changes, flags, include ordering and shadowing.

Local evidence root:
`work/preflight-e1d470/`. It contains the original job/base records, the effective
baseline overlay, the fetched guide revision, and private replay outputs.
The guide was fetched from findings `bfb48043f94cd6cd67aec2cbb8a8ff1c539832a9`
before editing. Worker workflow version 6 includes the shared preflight module.

## Replay validation

The corrected six-file batch was independently recompiled and linked in
`work/preflight-e1d470/corrected-replay/`. Module ownership rose from 3,220 to 3,226:
the six server-relative gains above, with zero losses. The module linked, smoke
returned zero, and all existing acceptance gates passed: M2/M4a/M5, size/base,
linked ownership and global distinct coverage. Global distinct coverage rose to 9,891.
Its `integration-result.json`, `replay-receipt.json` and `integration-*.log` retain
the full reports. All eight previously lost GUI bodies are exact in the fresh object.

The negative control in `work/preflight-e1d470/missing-pragma-replay/` removes only
the accepted FP pragma from that same corrected registry. Its fresh GUI source
hash exactly equals the rejected candidate's hash above. Compiler arguments and
resolved include hashes are identical after normalizing private snapshot paths;
`source-compiler-audit.json` records the comparison. Its fresh GUI object loses
the same eight bodies. The full module links and smoke returns zero, but ownership
falls to 3,218: six gains and eight losses against the frozen baseline.
M2/M4a/M5 also return zero, but the unchanged ownership gate rejects the batch:
`Need new module ownership without losing existing owned bodies`. All eight losses
are uncovered elsewhere; global distinct coverage is 9,883. Its `replay-receipt.json`
records all gained/lost/uncovered addresses and the rejection reason.

Focused regression suite: 244 passed, one optional real-snapshot benchmark skipped.
Worker package verification imports all 47 shipped Python modules, includes the
shared verifier/preflight implementation, and validates ZIP SHA-256 against the
download manifest. The code and package are published without resubmitting this job.

## Remaining limits

No job was submitted or resubmitted; local replay earns no credits. The live server
checkout and database remain unchanged, so server receipt improvements require a
normal code upgrade when the operator can safely do so. The standalone linked
preflight orchestration has regression tests; the real replay exercised its shared
independent build and gate implementation rather than contacting submission APIs.

Cold builds remain expensive. Some unchanged objects also rebuilt across copied
snapshots in this environment; that conservative cache-miss behavior is not fully
diagnosed. Both compared GUI objects were freshly compiled, so it cannot explain
away the controlled pragma regression. There is no evidence here of stale-object
acceptance or a flag/header mismatch causing these eight losses.

Existing limitations remain: two size mismatches, 32 base-probe headers not checked,
and the M4b render milestone not linked. These are unchanged and are not newly
waived checks; this replay does not establish full client runtime compatibility.

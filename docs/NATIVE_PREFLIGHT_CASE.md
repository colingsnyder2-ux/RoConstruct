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

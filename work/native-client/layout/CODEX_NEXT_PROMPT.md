# Codex prompt: merge groups, naming and link trace

Context: branch `layout/2008-06` (export tree `rebuild/2008-06/layout/`, tool `work/native-client/layout/layout_pipeline.py`,
status `work/native-client/layout/PHASES_PLAN_AND_STATUS.md`). Read that file's "Phase 5/6 ledger" first. Never push without
the owner's OK. Use `roc.cmd lease` before editing native classes, headers or shared build scripts.

## Task 1: merge groups (about 478 KB of code, 80 groups still split)

A group is several native pieces that map to one original file. The pipeline merges them only when the joined unit reproduces
every function and data symbol of the pieces byte for byte (`compare_merge`, `dedupe=True`). A 12-group whole-group trial
passed 0. Causes found:

- `client/app/util/http.cpp`: `HttpWinHttp.cpp` (winhttp.h) cannot share a unit with `HttpWinInet.cpp` (wininet.h): macro and type
  redefinitions. It belongs to another original file. Find that file's name (PDB path list, OpenRBX, census) or keep it apart.
- `client/app/v8datamodel/accoutrement.cpp`: compiles after `repair()`, but `AppUnit5B0_2008Accoutrement.cpp` calls
  `Weld::setC1`, which `native-headers/v8datamodel/JointInstance.h` does not declare. Needs a header proposal to the
  JointInstance.h owner, then retry.
- `client/app/v8datamodel/camera.cpp`: compiles after two repairs, bytes differ. `CameraControl.cpp` is built with the
  `/I{headers}/camera-zoom` overlay, the other pieces without it. Settle one Camera header set that reproduces all pieces.
- Biggest by bytes: http (34 KB), rakpeer (34 KB), robloxtreectrl (20 KB), sound (18 KB), modelinstance (18 KB),
  reliabilitylayer (18 KB), contentprovider (15 KB), camera (14 KB).

Method per group: `overrides/README.md` (hand-consolidated file plus manifest entry). Only a file that passes `compare_merge`
is kept. Do not claim link or initializer order.

Reusable scratch tools (copy them out of the session scratchpad if gone): a trial script that joins a group, compiles with
the first piece's flags, runs `layout_pipeline.repair()` up to 6 times and compares to the member objects.

## Task 2: names (other lane)

About 26% of code bytes have no identity. Already used: PDB paths, OpenRBX, census voting, reflection and RTTI bindings,
iOS 2013 and RBXGS donor matches, nearest-matched briefs. Do not add guessed names as Authentic: inferred names stay in the
`inferred/` tier and stay labelled.

## Task 3: first link trace (Build B, native-only client)

`work/native-client/layout/gates/mesh-pilot/undefined.json` lists 56 undefined symbols for the mesh family. Resolve them from
exported sources only: no donor objects, no `RobloxShell`, no extracted bytes, no post-link patching
(`SOURCE_ONLY_STATUS.md`). Report each remaining provider as unresolved rather than filling it with a stub.

## Report

For every group or symbol: result (kept, held, unresolved), proof used, files changed. Report Organized and Authentic
separately (Authentic = original path, object-identical, census-unique; ceiling about 73% because 27% is library code).

## Working rules (no branch switch)

- Stay on the current checkout branch. `rebuild/2008-06/layout/` is gitignored here; `layout_pipeline.py --branch` builds the
  `layout/2008-06` commit with git plumbing and never touches the checkout.
- Hand-consolidated files go in `work/native-client/layout/overrides/` plus a `manifest.json` entry. Stage only those and the
  tool files you changed.
- Do not run `--tree` (about 100 minutes) until overrides exist.
- Link-trace result so far: 10 providers have PDB-path source in the export (7 NormalId functions in util/normalid.cpp,
  alignedMalloc and alignedFree in g3dcpp/system.cpp, Vector2::zero in g3dcpp/vector2.cpp); mesh functions exist only under
  inferred/; LevelBuilder has two unproved quadvolume.cpp candidates; 39 symbols (runtime, MSVC, Boost, CRT, imports) unresolved.

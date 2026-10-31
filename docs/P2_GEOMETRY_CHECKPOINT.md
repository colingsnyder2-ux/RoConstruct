# P2 flat producer checkpoint, 2026-10-31

Imported OpenCode milestone claims were checked against current local files.
Entity code was preserved. `--p3test` is absent from this revision's parser, and
missing-place paths silently use the built-in fixture. These are acceptance gaps.

Original BrickMesh constructor calls flat producer `004e2c80` at `004e5449`;
its other branch calls `004e3720`. Factory sources `004e54e0` and `004e58b0`
are available locally. Which original factory/branch the loaded fixture executes
still requires runtime proof. The flat provider is the existing
`rbxgs-view-dll roc_espclaude_f7a520dca9a7cb3a.cpp`, not the Ogre upload helper.

Existing provider compiled under VS2008 RTM 21022 and its recorded flags.
Object SHA-256: `e03c70ad2d1513572dd7624ae8ce9a3c18e6b7678740d69548f15d70a1162c53`.
A link-only probe forced its actual decorated `populate` symbol against the
player's transitive dependency libraries: 27 unresolved symbols and duplicate
G3D providers. Narrowing its donor include from BrickMesh.cpp to BrickMesh.h
compiled, removed cache/constructor pollution, and left 24 unresolved symbols.
Core gaps include Level2008 construction, native vertex-bank ownership, and
uvwToObject instances. No stub definitions or arbitrary global arrays were added.
This is a failed integration probe, not P2 completion.

The unchanged local player rebuilt with linked=True/test_exit=0, but a separate
normal-environment selftest in a fresh capture directory exited 5: initial and
moved pixel controls failed; removed and empty passed. The shorter build smoke
result must not be substituted for those pixel controls.

EXE SHA-256: `f67a53d7bd526b561d920940288859c97dcd1f60bb20954cd420c0dfb3c5b49e`.
Observed tooling revision: `313bf5f7aad653f2af2df2904cdae2dc6a48b158` plus existing
local player changes. Source hashes, captured images, full symbol inventories,
compile/link receipts and logs are in `work/2008-06/p2-flat-producer/`.
Actual loaded DLL paths were not traced. This was not a clean second-worktree
reproduction. The prior checkpoint was retained there as `checkpoint-before.md`.

Continue from `work/2008-06/player-roadmap.md`. Native Level/vertex-bank ABI
resolution precedes a player wiring change. P2 remains open; no later milestone
is advanced by these diagnostics. The separate source-view fix is documented in
GRAPH.md (`roc source CLIENT ADDRESS`).

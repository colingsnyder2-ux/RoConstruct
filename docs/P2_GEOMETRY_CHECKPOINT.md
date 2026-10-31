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

## Follow-up: orientation providers and baseline isolation

Six authentic NormalId template instances now have a reproducible module target:
`roc rebuild 2008-06 module p2-mesh-orientation --no-notify`. Its linked asymmetric
fixture passes. Producer link errors reduced from 24 to 18. The player module
also compiles these providers; no byte-exact credit is claimed.

Earlier failed pixel controls used local white-material/stock-Entity debugging
changes. Those files remain untouched. An isolated snapshot using committed
91903d1caf player sources plus the pre-existing local RbxEntityLocal.cpp passes
all four normal-environment pixel controls. Hashes and captures are retained in
`work/2008-06/p2-flat-producer/snapshot-runtime/`. The local entity provider is
absent from the old commit, so this is not a clean-clone reproducibility claim.

Native Level destructor evidence adds a real prerequisite: 004dd340 calls
005489b0, which calls backend cleanup 005486e0. The Level +24 resource is deleted
through 0054ac70 -> 006824e0 (Ogre::RbxSubMesh). Reusing the donor Level destructor
alone would omit backend cleanup. Vertex-bank initialization 00547f60 reserves
slot zero across the position, normal, tangent, UV and reference-count arrays.
P2 remains open pending coherent native bank and backend-resource integration.

## Backend upload group

`roc rebuild 2008-06 module p2-mesh-backend --no-notify` now builds and passes a
hidden D3D9 test. Existing 00679ae0/0067c130 upload bodies and 00678470/006824e0
RbxSubMesh construction/destruction use genuine SDK and Boost declarations.
Size/offset checks replace padded mining declarations. Tests cover both index
widths, asymmetric bounds, normal/UV channels, 32 teardown cycles, registry return
to zero and release of GPU buffer ownership. Optional colour upload is not yet
exercised; the current recovered level upload passes null colours.

This closes a backend prerequisite, not P2: the loaded Part still needs its
recovered level-0 producer and reference-counted vertex-bank ownership connected.
`work/2008-06/p2-flat-producer/backend-receipt.json` records this test image and
source hashes. Geometry bounds-cache removal remains the Level owner's work.


## Loaded block producer integration (P2 still open)

`p2-block-mesh` now builds and passes 32 recovered-producer/upload/teardown cycles,
including smooth/studded faces, alternating 16/32-bit uploads, asymmetric bounds,
retained G3D references, repeated-upload reuse and zero live refs/levels/backends.
Existing 004e2c80 body and face templates run against one typed bank using native
00547f60/00548000/00547fc0/00548640 algorithms and measured Level offsets.

`roc rebuild 2008-06 module p2-recovered-player --no-notify` provides an isolated,
published source target preserving newer local player edits. Loaded Part now owns
that recovered mesh; renderer retains it through RbxEntity lifetime. Handwritten
box vertices/indices were removed from this target. Existing entity provider stays
unchanged. SDK SubMesh animation lookup requires a non-owning metadata Mesh parent;
leaving the native detached submesh parent null caused an access violation, resolved
by setting its parent without transferring deletion ownership.

Normal --selftest passes initial/moved/removed/empty pixel controls (1891/2152/0/0).
Source hashes, executable/map hashes, logs and captures are recorded under
work/2008-06/p2-flat-producer/recovered-runtime/. Recheck receipt for exact tested
revision; build-only quick execution does not count as visual evidence.

This is recovered geometry integration, not full P2 closure. Fixed-function colour
material remains diagnostic; full native Mesh/factory ABI, shared indices and scene
bounds-cache ownership are not integrated. Original modifier/humanoid selection,
bevel policy, child signals, non-box and >=30-stud producer paths remain open.
Read tests/p2-recovered/README.md for scope. No later milestone advanced.

Next: prove/integrate full native Mesh factory/owner and material path, preserving
this passing isolated target. Then P3 shape/lifecycle/resource baseline, followed
by remaining roadmap. Do not overwrite local Player2008/PlayerEngine/RbxEntity.h.


## Full Mesh owner and capture correction

Native 00548570/00548a90 now have a typed 0x88-byte Mesh owner. Compile-time checks
cover levels0c, ShadowSurface18, radius4c, index vector50, vertex vector68,
shadow-backend80 and kind84. The 004e53c0 matched analog's AABox declarations are
false semantic labels: member constructors prove vector stride2/12, and the
004e3570 caller confirms index/vertex output roles. Tests exercise both Level
backend destruction and the separate Mesh shadow backend branch. Shadow element
types retain donor evidence; remaining native shadow behavior is not complete.

Normal acceptance initially captured Codex desktop pixels. The original Ogre1.4
screenshot API uses GetFrontBufferData; that receipt cannot establish a geometry
regression. A harness-only D3D9 backbuffer read fixes occlusion deterministically
for selftest and frame captures. Owner changes preserve all four controls with
zero leaked levels/refs/backends; inspect native-owner-backbuffer-runtime receipt
for the exact revision and output hashes.

Next factory evidence: 004e58b0 uses boost::recursive_mutex (00563090 maintains a
recursion count at+8), cache mutex offset20 and allocation30. Initial bevel flag
009413c0 is1. Factory first builds with bevel0.065, then calls the same004e2c80
again with bevel0/buildingShadowMesh=true. Current direct constructor bypasses
factory cache and this paired-level policy, keeping P2 open. Integrate that
existing source next, including its purge and shared resource ownership.

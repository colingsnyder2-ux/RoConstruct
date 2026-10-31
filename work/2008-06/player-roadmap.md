# Current player checkpoint

P2 IN PROGRESS; P0 clean-worktree gate and P3-P10 remain unproven.
Last pushed revision a2cf9bc1b0 records tested source a03ec3bcbf.
Owner-layout commit3043e89063; capture-corrected tested source c301f9241e.
Receipt: p2-flat-producer/native-owner-backbuffer-runtime/receipt.json.
Normal pixel controls1891/2152/0/0 pass; levels/refs/backends zero.
Separate --frames240 falling.rbxl smoke exits0, y=-3.80274, models2 and cleanup0.
Falling fixture remains local/unversioned: this does not close clean-worktree P0.
Known-good isolated target: `roc rebuild 2008-06 module p2-recovered-player --no-notify`.
Normal --selftest passes 1891/2152/0/0 pixels and zero levels/refs/backends;
receipt: p2-flat-producer/recovered-runtime/receipt.json. Loaded DLL paths/hashes
are captured. Existing owner Player2008.cpp/PlayerEngine.cpp/RbxEntity.h untouched.

Recovered 004e2c80 produces loaded small block level0; 00549a50 uploads it through
0067c130 to measured RbxSubMesh. Entity implementation was preserved. No handwritten
box geometry in this target. Still diagnostic material and partial original selector.

Current experiment: replace the levels-only owner with measured full 0x88-byte Mesh.
00548570 constructs levels +0c, ShadowSurface +18 (34 bytes), radius +4c, vectors
+50/+68, backend +80 and kind +84. 00548a90 proves +80 owns a RbxSubMesh resource.
Matched 004e53c0 analog incorrectly calls the vectors AABoxes: 0054c500 proves
stride2 index storage and 0054d940 stride12 vertex storage; 004e3570 output calls
confirm roles. Compile-time offsets/size and standalone lifetime tests pass. Normal run exposed
front-buffer capture contamination (Codex pixels, not rendered window). Ogre1.4
writeContentsToFile uses GetFrontBufferData. New writeBackbuffer reads the same
window render surface before Present using GetRenderTargetData; probe and final run pass
1891/2152/0/0 while occluded. Exact-revision receipt saved under
p2-flat-producer/native-owner-backbuffer-runtime/. No entity changes involved.
Evidence: p2-flat-producer/native-owner-evidence.json and factory-abi-disassembly.txt.
Shadow element types retain donor Mesh.h evidence; do not claim all shadow paths proven.

Next after final owner tests: original 004e58b0 factory/cache. Its existing mined
source declares recursive_mutex; binary locks cache+20 and counts at+2c:
00563090 +8 recursion count proves boost::recursive_mutex (12 bytes); earlier
plain-mutex inference confused backend mutex offset with size and is rejected.
Existing factory declaration agrees. Retain original
variation selection, lifetime and purge semantics; trace bevel policy rather than
forcing an undocumented value. Initialized useBevels byte009413c0=1: factory
builds first level with bevel0.065 then calls same004e2c80 again with bevel0 and
buildingShadowMesh=true. Current direct constructor bypasses this paired policy.
Native geometry cache/shared indices/materials and
full selector still keep P2 open. No active server claims/jobs.

## Earlier observations (historical; current state above takes precedence)

# Current player checkpoint — verified observations, not imported status claims

P2 OPEN. Graph implementation exists and focused graph tests pass. Existing entity
work remains untouched. No manual geometry replacement has passed in this run.

Revision observed: 313bf5f7aad653f2af2df2904cdae2dc6a48b158 plus existing local
player changes, preserved in p2-start-local.patch. Another publisher advanced HEAD
from 91afdf056c during this session; no branch switch/pull/reset performed.

Original static connection: BrickMesh constructor 004e53c0 calls flat population
004e2c80 at 004e5449 when any of its three branch-control arguments is zero.
Other branch calls 004e3720 at 004e5431. Factory bodies 004e54e0 and 004e58b0 are
available via `roc source`; selected original runtime factory/branch for the
loaded block remains unproven. Do not mark this static connection as runtime proof.

Existing flat source: rbxgs-view-dll roc_espclaude_f7a520dca9a7cb3a.cpp.
Original wrapper remains src/2008-06/004e2c80.cpp. It compiles to a 2275-byte
populate function. Compiled object and full symbol inventory saved under
work/2008-06/p2-flat-producer/. This is compilation evidence, not native integration.

Forced-link probe with current player's transitive dependency libraries fails:
27 unresolved symbols plus duplicate G3D providers. Specific direct prerequisites
include Level2008 constructor (native 004dd2e0), meshPositions/meshNormals,
meshBevel, buildingShadowMesh, flatTextureOrigin, and six uvwToObject specializations.
The unit includes donor BrickMesh.cpp, introducing unrelated cache/constructor
requirements. Full linker results: link-with-player-dependencies.json.
Do not satisfy these with empty bodies, fake layouts, or arbitrary global arrays.

Baseline build: `roc rebuild 2008-06 player --no-notify` linked=True/test_exit=0.
Normal-environment --selftest in a fresh capture directory exited 5:
initial/moved green=0 FAIL; removed/empty PASS. Therefore prior P0/P2 pixel claims
are not established for this exact EXE. Hash and source input hashes are in
p2-flat-producer/baseline-runtime/receipt.json; images and logs retained there.
DLL load paths were not traced, and this was not a clean second-worktree build.

Current parser does not implement --p3test, and missing files fall back to the
built-in place. Prior P3 status cannot be adopted. P3-P10 remain unproven.

Follow-up experiment completed: replacing donor BrickMesh.cpp include with
BrickMesh.h compiles and removes donor cache/constructor requirements, but still
fails linkage (24 unresolved symbols). narrow-compile.json and narrow-link.json
retain results. This remains an isolated probe, not a replacement player path.

Next bounded experiment: resolve native Level constructor 004dd2e0 and vertex-bank
ownership against the actual flat producer calls; select coherent G3D/RenderLib
providers without duplicate VAR definitions. Do not supply arbitrary arrays or
stub Level construction. Re-run normal pixel controls after successful linkage.

Source viewing fixed separately: `roc source CLIENT ADDRESS [--json|--output PATH]`.
Readable factory files: work/2008-06/source-view/004e54e0.cpp and 004e58b0.cpp.
Pending claims/jobs: none acquired by this session.

## Continued P2 prerequisite work

Added PlayerMeshOrientation.cpp: authentic NormalId template body plus six explicit
instances, preserving existing helpers. `roc rebuild 2008-06 module
p2-mesh-orientation --no-notify` links/runs successfully. Asymmetric (2,3,5)
fixture checks all six signed axis mappings. Forced producer probe now has 18
unresolved symbols instead of 24. No new byte-exact/native credit claimed.
Player config includes this unit; build linked=True/test_exit=0 with all recorded
source inputs stable before/after. See orientation-build-inputs.json.

Important correction to earlier baseline interpretation: local Player2008.cpp
contains white-material/stock-Entity diagnostic changes relative to 91903d1caf.
Those explain the green pixel failures; the recovered entity code was not redone.
A separate player-snapshot used committed 91903d1caf player sources plus the
existing local RbxEntityLocal.cpp (missing from that commit), with every input
hashed. Isolated P2PlayerBaseline builds and all four normal-environment pixel
controls pass: initial 1891 green pixels, moved 2152, removed/empty zero.
EXE and input hashes: snapshot-runtime/receipt.json. This does not prove a clean
clone can build; RbxEntityLocal.cpp remains a required local input to preserve.
All original local diagnostic files remain untouched.

Native lifetime evidence saved in native-lifetime-evidence.json:
- 004dd340 -> 005489b0 -> 005486e0. Native Level destructor includes backend cleanup;
  defaulting a derived donor destructor would omit resource removal.
- Cleanup's +24 pointer is an Ogre::RbxSubMesh: delete thunk 0054ac70 calls
  006824e0. Existing source has actual imported SubMesh base + EdgeData deletion.
- 00682150 is used for geometry bounds-cache removal. Its mined label
  forgetLightPosition/Light* is an analog, not the actual key's semantic type.
- Bank globals: positions 009738f0, normals 009738fc, tangents 00973928,
  UVs 00973934, reference counts 009738c4, free list 009738ac.
- 00548570 -> 00547f60 initializes all arrays to size 1; reference-count slot 0
  starts at 1. Preserve this reserved slot. 00548000 allocates/reuses slots.

Next command: `roc source 2008-06 0067c130 --output
work/2008-06/source-view/0067c130.cpp`. Trace returned submesh ownership into the
native Level +24 cleanup before adapting the recovered producer/upload group.
Use passing isolated snapshot as renderer baseline; do not overwrite local debug
work or redo entity implementations. P2 and later milestones remain open.

## Recovered backend upload group

PlayerMeshBackend.h/.cpp adapts existing 00679ae0 vertex-buffer upload, 0067c130
indexed upload, 00678470 constructor and 006824e0 destructor to genuine Ogre SDK
and Boost declarations. No padded SubMesh/VertexData or fabricated vtable methods.
Compile-time checks prove SubMesh c4, RbxSubMesh f0, bounds cc, radius ec,
VertexData38, IndexData14, context30 and mutex24 for this compiler/profile.

Repro command: `roc rebuild 2008-06 module p2-mesh-backend --no-notify`.
It links and exits0. Hidden D3D9 fixture checks 16/32-bit indices, asymmetric bounds,
normal/UV channels, 32 create/destroy cycles, empty registry and sole retained GPU
buffer ownership after mesh destruction. Optional colour-data upload remains
unexercised; current 00549a50 caller passes null colours. Recorded target quirk
repeats the red component in all colour channels; retained rather than guessed.

Ownership: createIndexed returns a detached Ogre::RbxSubMesh (parent=null,
useSharedVertices=false), owns VertexData/IndexData, and records it in the typed
context. destroyIndexed removes that registry entry and deletes the submesh/edges.
Geometry bounds-cache removal remains the Level owner's responsibility; not
claimed integrated. No new native/server credit. backend-receipt.json records
EXE/input hashes and the module report.

Push permission explicitly granted by user; verified commits through bf99dbe0ab
pushed normally to origin/codex/native-partial-search-20261029. No force pushes.

Next: adapt the existing 004e2c80 producer and 00549a50 upload together around a
single typed, reference-counted Level/vertex bank. Preserve slot0 initialization
and original reuse/refcount algorithms (00547f60/00548000/00547fc0/00548640).
Use the isolated passing player snapshot; original local debug/entity files stay
untouched. Do not add arbitrary array aliases to satisfy the old donor linker.
Native shared-index path and full scene bounds-cache lifetime remain open.


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

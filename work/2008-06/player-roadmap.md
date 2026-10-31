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

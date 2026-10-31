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

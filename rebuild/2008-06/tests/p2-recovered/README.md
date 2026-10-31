# Isolated recovered-block player

Build: `roc rebuild 2008-06 module p2-recovered-player --no-notify`.
Run `rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe --selftest`
without ROC_BUILD. Run in a fresh directory with rgmain.dll/rgdx.dll discoverable.

The baseline Player2008/PlayerEngine/PlayerScene/RbxEntity.h came from 91903d1caf;
RbxEntityLocal.cpp preserves the already-working local provider. This separate
module keeps newer local player diagnostics untouched. Entity implementations
are preserved, including their existing omitted shadow behavior; this work does
not claim to complete those native functions.

The scene owns a reference-counted BlockMesh; its measured 40-byte Level owns
indices and a detached RbxSubMesh. Renderer retains the same owner until entity
removal. Geometry comes from existing 004e2c80 producer/face templates, native
vertex-bank algorithms, 00549a50 upload, and 0067c130 backend. The Ogre Mesh is
bounds/animation metadata only, with no handwritten vertex/index geometry.
An explicit non-owning parent is needed by SDK SubMesh::getVertexAnimationType.
Delete entity, release geometry, then remove metadata/material before Ogre shutdown.

Scope: ordinary small block, native-default paired bevel/flat levels, 16-bit level0 upload in this player.
Standalone p2-block-mesh tests exercise both index widths and smooth/studded faces.
Part colours currently use a diagnostic fixed-function material, not the original
atlas/material path. Full Mesh member layout now has compile-time checks against 00548570/00548a90;
shadow element semantics outside exercised paths remain donor-backed hypotheses.
Shared-index branch, scene bounds-cache
registration/removal, modifier/humanoid branch selection, non-box/large geometry,
child signals and complete original material/surface behavior remain unintegrated.
The small-block selector does not yet reproduce all original preconditions.
No P2/P3 completion, whole-executable reconstruction, or new server match claimed.

Evidence/checkpoint: work/2008-06/player-roadmap.md and
work/2008-06/p2-flat-producer/recovered-runtime/receipt.json.

Capture correction: Ogre 1.4 window writeContentsToFile reads the desktop front
buffer, so occluding apps can contaminate pixel controls. writeBackbuffer uses
D3DDEVICE/DDBACKBUFFER attributes from the real Ogre D3D9 window, renders without
Present, reads that surface with GetRenderTargetData, saves RGB PNG and presents.
Selftest and frame captures share it. Screenshot failures must fail the run;
no desktop/foreground fallback. The renderer/entity/geometry path stays the same.

Factory/cache: existing 004e58b0 now selects up to four variants per size/surface/
BrickColor key, including native default bevel0.065 first level and flat second
level through the same004e2c80 producer. Measured cache is0x30 with recursive mutex
at20 and creation counter2c. Original004e5710 purge drops cache-only references;
keys/count remain. Renderer metadata/material is shared by geometry identity and
removed at its last renderer user, accounting for Ogre's three system references.
Call flushUnused after entities/chunks are gone, before Ogre shutdown.

`roc rebuild 2008-06 module p2-block-factory --no-notify` stresses512 requests,
paired level geometry/upload widths, and the every100-creation recursive purge.
`P2RecoveredPlayer.exe --cachetest <absolute path to tests/fixtures/cache-blocks.rbxl>`
loads nine overlapping same-key Parts, removes one, reopens, and checks two9->8->0
cycles with metadata/material counts returning to baseline. This closes cache
integration coverage, not the complete P3 acceptance gate or original material path.

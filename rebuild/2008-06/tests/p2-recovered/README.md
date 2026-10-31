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

Scope: ordinary small block, flat/no-bevel LOD, 16-bit upload in this player.
Standalone p2-block-mesh tests exercise both index widths and smooth/studded faces.
Part colours currently use a diagnostic fixed-function material, not the original
atlas/material path. Native whole Mesh ABI, shared-index branch, scene bounds-cache
registration/removal, modifier/humanoid branch selection, non-box/large geometry,
child signals and complete original material/surface behavior remain unintegrated.
The small-block selector does not yet reproduce all original preconditions.
No P2/P3 completion, whole-executable reconstruction, or new server match claimed.

Evidence/checkpoint: work/2008-06/player-roadmap.md and
work/2008-06/p2-flat-producer/recovered-runtime/receipt.json.

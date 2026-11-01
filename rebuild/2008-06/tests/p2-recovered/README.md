# Isolated recovered-mesh player

P3 now passes on source0dcbf70f18: ordinary blocks and native balls, repeated
mixed-shape lifetime controls and original-client silhouette comparison.
See p3-acceptance-audit.md for exact receipts and remaining context/native limits.

Build: `roc rebuild 2008-06 module p2-recovered-player --no-notify`.
Stage original Content with tests/stage_demo_content.py (see SkyboxDemo.md).
Default launch uses the red studded block and skybox. ROC_TEXTURE_STRIP remains
an optional developer override; otherwise assets resolve beside the executable.
ROC_SKY_SPHERE supplies the original sky sphere image for reflective materials;
that branch is not exercised by this ordinary opaque-block gate.
Run `rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe --selftest`
without ROC_BUILD. Run in a fresh directory with rgmain.dll/rgdx.dll discoverable.

The baseline Player2008/PlayerEngine/PlayerScene/RbxEntity.h came from 91903d1caf;
RbxEntityLocal.cpp preserves the already-working local provider. This separate
module keeps newer local player diagnostics untouched. Entity implementations
are preserved, including their existing omitted shadow behavior; this work does
not claim to complete those native functions.

The scene owns a reference-counted Mesh base (BlockMesh or SphereMesh); its measured 40-byte Level owns
indices and a detached RbxSubMesh. Renderer retains the same owner until entity
removal. Geometry comes from existing 004e2c80 producer/face templates, native
vertex-bank algorithms, 00549a50 upload, and 0067c130 backend. The Ogre Mesh is
bounds/animation metadata only, with no handwritten vertex/index geometry.
Original00684fd0 getRenderOperation now binds detached submesh data directly.
The earlier non-owning parent workaround is removed; SubMesh parent stays null.
Delete entity, release geometry, then remove metadata/material before Ogre shutdown.

P2 scope: ordinary small block, native-default paired bevel/flat levels, 16-bit level0 upload in this player.
P3 adds the recovered six-face sphere producer and measured factory cache. Balls
use original shaded Surfaces.png through getMaterial; the harness explicitly
uses mipmaps/AA0 when the full native texture context is absent (P6 dependency).
Standalone p2-block-mesh tests exercise both index widths and smooth/studded faces.
Part colours now come from the original atlas UVs and recovered Material/Level/
TextureProxy plus007ab0a0 backend setup. Diagnostic unlit/manual color pass is
removed. Recovered007aacc0/007a9d30 lighting uses the rebuilt model's actual sky
parameters and proven005e1a40 defaults for extra fields absent from the donor
Lighting class. This remaining model/scene bridge is explicit; no complete native
Lighting/View/RenderScene ABI is claimed. Full Mesh layout has checks against 00548570/00548a90;
shadow element semantics outside exercised paths remain donor-backed hypotheses.
Shared-index branch, modifier/humanoid branch selection, other shapes/large geometry,
child signals and complete original material/surface behavior remain unintegrated.
The small-block selector does not yet reproduce all original preconditions.
P2 completion is assessed in p2-acceptance-audit.md against the ordinary block
gate. P3 is audited separately. Whole-executable reconstruction and new server
credit are not claimed by these runtime milestones.

Evidence/checkpoint: work/2008-06/player-roadmap.md and
work/2008-06/p2-flat-producer/p2-acceptance-runtime/receipt.json.
Current sky demo/capture evidence: work/2008-06/sky-demo-final/receipt.json.

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
keys/count remain. Renderer bounds metadata is shared by geometry identity and
removed at its last renderer user, accounting for Ogre's three system references.
Call flushUnused after entities/chunks are gone, before Ogre shutdown.

`roc rebuild 2008-06 module p2-block-factory --no-notify` stresses512 requests,
paired level geometry/upload widths, and the every100-creation recursive purge.
`P2RecoveredPlayer.exe --cachetest <absolute path to tests/fixtures/cache-blocks.rbxl>`
loads nine overlapping same-key Parts, removes one, reopens, and checks two9->8->0
cycles with metadata/material counts returning to baseline. This closes cache
integration coverage, not the complete P3 acceptance gate or original scene path.

Material refs belong to chunks and renderer entries. Geometry metadata remains
shared by geometry identity; materials have their own native weak-cache/lifetime,
and are assigned per SubEntity. Existing entity methods are preserved; one
missing original SubEntity render-op override bypasses stock animation-data
selection. Allocation15c and lodIndex134 have compile checks. Owner debug files
remain unchanged.
The pre-material EXE/map/DLLs are preserved locally in
work/2008-06/p2-flat-producer/pre-material-player-0f567d02e8/ with pinned hashes.

Pixel metric changed with native lighting. The unchanged fixture's Color3(0,1,0)
quantizes to period BrickColor RGB(40,127,70). Its lit face is about(23,72,40),
so the previous diagnostic unlit threshold G>120 produces only8/9 pixels and
fails initial/moved. Those captures/results are retained in native-material-player-probe/.
The new classifier requires G>50, G>2R,2G>3B. Initial/moved area>300, opposite
region noise<30, removal/empty controls and all camera/fixture settings remain
unchanged. Receipts identify the metric and retain old-threshold counts for
comparison. This test update does not substitute for original-client comparison
or prove complete original scene/selector coverage. Those remaining branches
must be tracked separately from the exercised ordinary-block gate.

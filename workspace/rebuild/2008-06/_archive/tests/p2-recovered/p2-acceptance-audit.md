# P2 acceptance: ordinary block, 2026-10-31

Verdict: **PASS for the roadmap's ordinary block / first-detail-level gate** at
source revision3f89605232. This is not completion of the entire roadmap.

Plan authority: Desktop ROADMAP-2008-06.md, P2. The reference image/PE and the
older checkpoint are evidence sources; they do not expand this milestone into
whole-executable reconstruction. The tested target is P2RecoveredPlayer, leaving
the owner's newer Player2008/PlayerEngine/RbxEntity diagnostics intact.

| Requirement | Inspected evidence | Result |
|---|---|---|
| Reconstruct an ordinary block and first detail level | Anchored asymmetric2x1x1 loaded by actual DataModel XML deserialization. Original004e58b0 factory /004e2c80 producer and00549a50 /0067c130 upload form real level0. Hardware trace ties its Mesh, Level and SubMesh addresses together. | Pass |
| Replace value-only mesh stand-in with proven ownership | Measured88-byte Mesh,28-byte Level and original G3D intrusive reference contract; chunk, factory and renderer retain actual MeshRef. Compile assertions,32 owner lifetimes,512 factory requests and purge/removal tests. No handwritten box vertices/indices. Sizes are hexadecimal. | Pass |
| Compile EXE-owned entity/subentity methods; reuse corrected declarations | Map selects RbxEntityLocal.obj for creation, destruction and recovered00684fd0 render operation. Subentity allocation15c and lodIndex134 compile checks. Existing entity methods preserved; one missing render-op override added. | Pass |
| Use original DLL interfaces at evidenced boundaries | Genuine Ogre declarations; native render-op calls original SubMesh::_getRenderOperation. Normal-run receipt records actually loaded rgmain.dll/rgdx.dll paths and hashes. | Pass |
| Investigate node cache when exercised | Original set/get/remove globe0097dbc4 distinguished from node transforms+228. Setter, lookup and removal integrated; map/Pair/Sphere size checks and lifetime tests. Level cleanup removes backend key after deletion. | Pass for touched ordinary branch |
| Disable ManualObject fallback | Loaded block uses original producer and native SubEntity render operation. drawModels has no ManualObject or manual geometry fallback. | Pass |
| Four pixel controls | Normal process, ROC_BUILD unset: initial1879 in A/0 in B; moved0 in A/2080 in B; removed0; empty0. Same camera/fixture and area/noise limits. Metric explicitly changed for native lighting, described below. | Pass |
| Identify linked provider and show it executes for loaded Part | DR0..DR3 hardware breakpoints trace producer, upload, entity creation, actual render-op and destruction; original map symbols and addresses recorded. Debug stage from loaded fixture precedes producer. No target code bytes patched. | Pass |
| Check transform and teardown on removal | CFrame move shifts pixels between fixed regions. Same traced entity is destroyed between P2_STAGE_BEFORE_REMOVE and P2_STAGE_AFTER_REMOVE. Final levels/vertex refs/backends/sphere entries all0; two cache9->8->0 cycles return mesh/material counts to baseline. | Pass |
| Do not pass solely through temporary geometry adapter | Missing00684fd0 override had forced a fabricated SubMesh parent link because stock SubEntity selected animation data. Original override now directly binds detached geometry; link removed, parent stays null and is asserted during cache cycles. Hardware trace proves same SubMesh reaches actual native render-op. | Pass |

The Ogre Mesh retained by the harness supplies Entity bounds/metadata, not mesh
geometry, Level ownership or an alternate render operation. SceneModel remains
an enumeration/transform facade over the rebuilt DataModel. Complete original
View/RenderScene layouts, aggregation, all selector branches and unused shadow/
animation behavior remain later integration work. Their absence is not credited
as whole-class recovery. The passing path now executes recovered geometry,
ownership and rendering methods rather than merely a stand-in producing pixels.

The unchanged fixture's green quantizes to period BrickColor RGB(40,127,70).
Native ambient/atlas shading produces a face around(23,72,40), so the old unlit
G>120 mask sees only8/9 pixels. Acceptance explicitly uses G>50,G>2R,2G>3B;
area>300 and opposite-region noise<30 remain unchanged. The exact-revision
receipt keeps both masks' counts from the same captures. No camera, fixture or
native lighting values were changed to force a result. Original-client visual
comparison and non-box silhouette comparison are not claimed here.

Authoritative receipts under work/2008-06/p2-flat-producer/:

- p2-acceptance-runtime/receipt.json: normal runs, executable/map/source/input
  hashes, loaded DLL paths, captures, resource baselines and falling smoke.
- p2-acceptance-trace/receipt.json: hardware breakpoint sites, object identity
  chain and phase ordering, same four controls and zero teardown counts.
- native-render-operation-evidence.json / disassembly: original vtable slot3,
  address00684fd0 and native field/allocation evidence. Local rebuild report
  identifies that function; no new server-verified matching credit is claimed.
- sphere-unit-runtime/receipt.json and earlier factory/material/light receipts
  remain prerequisite evidence; no changed prerequisite source is silently reused.

P0 clean-second-worktree/sustained collision proof, P3 complete lifecycle/non-box
gate, P4-P10 and full native inventory/executable identity remain open. Next
user-requested deliverable: default skybox, red studded block, real screenshot or
spinning video. Keep that demo separate from the green acceptance fixture.

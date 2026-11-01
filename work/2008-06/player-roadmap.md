# Current player checkpoint

SoundService shutdown005ba970 recovered at source73bde390ae: clear stock
channels/children, detach both sound caches, clear them, release FMOD. The
diagnostic builds and existing tests pass; shutdown is not yet selected or
runtime-tested. Evidence: p4-sound-close-73bde390ae/ and
p4-sound-close-runtime-73bde390ae/. Native provider callbacks and playback open.

At sourced7fe02f730, native SoundChannel releaseChannel005b97f0 and listener
subscription005bc5b0 are recovered; provider detach shares the release body.
Sound asset/cache/vector diagnostics pass, but the channel methods remain
unselected because onAncestorChanged and dependencies are not yet linked.
Evidence: p4-sound-listener-d7fe02f730/ and
p4-sound-listener-runtime-d7fe02f730/.

SoundChannel pieces at source2a68b59182: constructor005bc480, destructor
005b7680, parent acceptance00565ff0, provider detach005b9840, heartbeat005ba3d0,
and spatial update005b9920 use genuine application types. Constructor and
destructor locally identify the target addresses; sound diagnostics pass.
These objects remain unselected/unexecuted: channel construction needs native
onAncestorChanged and dependencies. Evidence: p4-sound-channel-2a68b59182/
and p4-sound-channel-runtime-2a68b59182/. P4 audio remains open.

Audio listener-vector helper005b70c0 integrated at source113d3a3fb5 with real
Math/Vector3 types and original +/-5000 limits. Diagnostic verifies denormal
cleanup, clamp, infinity rejection and untouched output on rejection; previous
cache and FMOD loader tests also pass. Evidence: p4-sound-vector-113d3a3fb5/
and p4-sound-vector-runtime-113d3a3fb5/. It is not yet called by heartbeat.

Audio cache cleanup005ba2e0 integrated at source288f3ac6f4. The diagnostic
compiles the same body with public test access (VS2008 encodes private access in
symbol names): seeded in-use retention, probabilistic eviction, detach and reload
pass with real FMOD. The production private symbol and heartbeat remain untested.
Evidence: p4-sound-gc-288f3ac6f4/ and p4-sound-gc-runtime-288f3ac6f4/.

Audio progress at source075c77b59f: SoundService destructor 005bb120 now uses
genuine automatic member/base destruction and locally identifies the target in
the owned-symbol report. Sound asset diagnostic still passes, but the destructor
object is not selected or exercised. A direct service/cache test could not link:
onEvent and onServiceProvider are missing. That temporary test was removed.
Recover those callbacks and their real dependencies before claiming service or
audible playback. Evidence: p4-sound-destructor-075c77b59f/ and
p4-sound-destructor-runtime-075c77b59f/.

P4 cylinder path integrated at source0948e83bac. Native constructor004fd6b0,
builder004fd430, endcap004fd4a0, side004fd530 and one-variation factory004eef30
now render through the shared bank and ordinary material. Unit test checks
geometry,32 clean lifetimes, shared cache and 100-creation purge. Rotated authored
fixture matches original-client silhouette at IoU0.991203 (gate0.98); comparison
is silhouette only. Same-source PBB/sphere/player builds and P3 lifetime,
selftest/cachetest pass. Evidence: p4-cylinder-0948e83bac/ and
p4-cylinder-lifetime-0948e83bac/. User Bread Factory:784 visible models,
8 valid geometries with empty materials, 0 missing geometry; its XML has8 fully
transparent Parts. User place and derived captures remain private. Older counts
below describe earlier revisions. P4 and full roadmap remain open.

Next: native SoundService/Channel factory, reflection, lifecycle and audible
playback; original large-block and additional real-place coverage, then P5-P10.
SoundService constructor/cache sources exist but have not run; no padding or
fabricated ABI. Preserve newer local Player2008/PlayerEngine/RbxEntity work.

P4 real-place crash FIXED on source3cd3585b2d: verified Humanoid destructor
object supplied vtable with extra onGuidChanged slot. Instance::readProperties
called bare ret as readProperty, corrupting stack. Module config now explicitly
excludes that one incompatible verified swap; actual Humanoid.obj vtable slot11
points to Instance::readProperty. Seven additional swapped methods auto-fell back
due missing helpers; forced-link count119->111, local unique object matches
3323->3318. Track these in P9; no exact/server credit claim. Evidence:
p4-humanoid-vtable-fix-3cd3585b2d/, p4-real-place-audit.md.
Independent authored Humanoid fixture now loads, retains1, clean shutdown.
User Bread Factory full XML loads with68 Humanoids and renders2frames exit0.
792 models:480 geometry/status0,312 unsupported/status3; cleanup allzero.
User input/map/log/image remain local; only sanitized hashes/counts committed.
Reflection fix: original renderer007ab0a0 references skyspheremap.jpg at
00874a44; stage original external sky/skyspheremap.jpg and set its default path,
preserving ROC_SKY_SPHERE override. Authored reflective-sphere test passes.
Normal P4 assets/Humanoid/reflection, P3 lifetime/selftest/cachetest and P4 sound
asset tests pass same revision; rebuild-tool pytest8 passed.
Next: original dispatch004ef930 non-mega shape1->004edb20 factory->004f4cb0
producer, shape2->004eef30->004fd6b0. Selector004e5f80 threshold30.0. XML
contains300 size>=30 block candidates and4 shape2; not exact omitted mapping.
Trace and integrate native large-block mesh with real source, not a manual box;
then cylinder, lifecycle and original comparison. Audio and P5-P10 remain open.


P4 real-place probe on sourcea9eb20a932: user supplied OnlyRetroRobloxHere
maps/Base contains seven 2008E/M/L compressed XML places. Bread Factory Tycoon
2008E (786 Parts, no HTTP asset URLs) crashes0xc0000005. Isolated Home model
with either Humanoid reproduces; removing both Humanoids passes, while removing
Scripts or value objects alone does not. Crash still reproduces with Humanoid
health properties removed. New --load-only flag confirms crash during model
deserialization before renderer; control without Humanoid loads/closes. Root
cause and exact original callee not proven; debug EIP observed in stack region.
Input hashes and bounded evidence:p4-user-place-analysis-a9eb20a932/. User map
and derived XML remain local, not committed. P4 asset5cases and P3 lifetime/
selftest/cachetest pass same revision. Next trace Humanoid factory/parent and
ancestry callbacks, particularly state construction; verify with actual map and
original client, do not remove Humanoids as a fix. Audio work remains open.


P4 SoundService constructor recovered at source29cf44360b. Genuine members,
normal base constructors, original name Soundscape, doppler1/distance10/rolloff1,
NoReverb, G3D::System::getTick, null FMOD, empty maps; no fabricated padding.
Native005bc160 and constant00827490 prove initialization;005083d0 maps to
G3D getTick. Local owned-symbol report identifies unique005bc160; no server
credit claimed. Diagnostic build and existing sound asset test pass, receipt
p4-sound-service-ctor-29cf44360b/. Constructor object is not selected by the
diagnostic executable and has not run. Native primary vtable slot12 resolves
onServiceProvider005bdcf0; original attachment source and disassembly show
listener removal/addition, stats detach/create, close/open FMOD, stock sounds.
Next recover destructor, heartbeat and attachment and their real dependencies;
then instantiate genuine SoundService and test cache identities/playback.
Native audio/P4 remains OPEN.


P4 SoundService cache method recovered at source e37a158e83. Original call
005bceb0 -> 005bb5f0 selects maps at +0x180/+0x1a0, returns cached shared Sound
or allocates0x30 and invokes ctor005b6f70. Genuine SoundService::loadSound now
implements that algorithm with actual typed members. Local owned-symbol report
identifies its object code uniquely with 005bb5f0; this is not server credit.
Sound diagnostic builds/executes0 on the same source; receipt
p4-sound-cache-e37a158e83/. The new method is not selected in the diagnostic
executable and has not run: service construction and runtime cache behavior
remain open. Next recover genuine service/channel constructors, factory and
lifecycle, then exercise same-ID cache identity, 2D/3D separation and playback.


P4 overlay correction verified at sourcea225dbb170. Prior raw-donor sound
diagnostic witness and software-setting result are superseded: actual app overlay
already restores GuidItem<Instance>. Native RTTI and global descriptor initializers
prove correct bases/ownership. Sound module now uses app overlay; static descriptors
yield Instance0x130, SoundChannel0x170, SoundService0x1c8 without padding. Shared
rbxgs-app, sound diagnostic, canonical player build/test0. Normal sound, five disk
asset controls, P3 lifetime/selftest/cachetest all pass. Receipts:
p4-sound-overlay-a225dbb170/, p4-assets-overlay-a225dbb170/,
p4-lifetime-overlay-a225dbb170/. Audible SoundService/Channel path remains open.
Next: recover genuine SoundService constructor/cache and SoundChannel factory,
reflection, lifecycle and heartbeat; then play authored tone and compare original.


P4 sound overlay correction IN PROGRESS. Prior a67fa9d7e2 diagnostic compiled
raw donor headers; canonical app already had GuidItem<Instance> in its overlay.
Thus previous 560-byte service layout witness describes raw donor, not canonical
engine; earlier sound test wrote the software setting using an inconsistent header.
Native RTTI confirms GuidItem base; original descriptor initializers007f5220,
007f5250,007f5280,007f52b0 construct global descriptors. Sound module now uses
the same app overlay and static descriptor declarations; compile-time checks for
Instance0x130, SoundChannel0x170, SoundService0x1c8 pass in first build. Shared
app, diagnostic and player rebuild running sequentially; verify all before
recording a new revision and rerunning normal tests. Preserve prior evidence as
superseded, do not claim audible playback.


P4 audio prerequisite PASSED at sourcea67fa9d7e2, not full audio/P4. New
PlayerNativeSound.cpp integrates real Sound constructor/get/detach/destructor
using genuine Sound.h members and existing005bc6f0 algorithm; no padded mining
declarations. Sound size0x30,SoundId0x20,actual SDKcreatesoundinfo0x6c asserted.
Constructor locally matches unique005b6f70, no new server credit claimed.
SDK4.08.08 headers used with real targetDLL reporting4.14.06; undecorated C
System_Create import alias preserves stdcall. get() singletonContentProvider is
the existing offline adapter; June get(context) provider discovery still open.
Diagnostic NOSOUND only:16lifetimes,cache hits,detach/reload,2D/3D,missingasset,
all5512PCM16samples match authored440Hz within1unit,11024bytes; provider cache
cleared beforePCMverification. ActualFMODDLLpath/hash pins original dependency.
Receipt:work/2008-06/p4-sound-asset-a67fa9d7e2/receipt.json.
Native descriptors005bb860/005bb7f0 prove classesSound/SoundService; ctor005bc160
sets default nameSoundscape. Fixed glue's incorrect SoundChannel class string
toSound, rebuilt rbxgs-app explicitly and canonicalplayer. Same-revision normal
P4asset5cases and mixed-shapeP3lifetime/selftest/cachetest allPASS:
p4-assets-sound-regression-a67fa9d7e2/,p4-sound-lifetime-a67fa9d7e2/.
Next native edge:005bceb0->005bb5f0 SoundService::loadSound selects2D/3D map,
returns cached sharedSound or creates/inserts genuineSound. Existing source
p4-sound-service-cache-source.cpp has correct algorithm but padded declarations:
do not adopt declarations. Before service integration fix proven donor ABI issue:
compiler layout SoundService560(0x230), four embedded descriptors444/472/500/528;
nativefactory00440a00->00440980 allocates456(0x1c8) and calls005bc160. Its actual
system134/myDisabled1c0 vs donor12c/1b8. Resolve descriptor static/global ownership
then remaining8-byte base prefix with evidence, never padding. Witness:
p4-sound-layout/compiler-output.txt, p4-sound-service-create-instance.txt.
SoundService/Channel lifecycle, real reflection/factory, heartbeat/callbacks,
audible output and original audio comparison still OPEN. No builds live. Owner
debug3files remain39insertions/12deletions; docsprogress is local build output.

P4 original asset comparison advanced after88e67662d4. Unmodified oracle in new
work/2008-06/original-p4-reference/ with independent copied Content, no junction
writes. Same2fixtures render same quadrant orientation/red sphere; Explorer
shows Gallery->Brick/Other and positions-2/+2. Missingmesh omits panel;
missingtexture uses same green standardmaterial fallback. compare_p4_assets.py
passes independent original/rebuilt color-region checks; captured JPG/tree and
asset-comparison.json retain bounded evidence. No full RGB/UI/camera parity.
Controls39300/27148 required process termination after UI close failed; no clean
original shutdown credited. All original processes terminal, authored copied
assets restored. P4 still OPEN for native audio.
Actual FMOD IAT/thunk proof:p4-fmod-import-calls.json. SystemCreate/init calls
in005ba060; createSound in005bc6f0; playSound in005bceb0; update in005bc2c0.
Unit labels unreliable. Saved005ba060 source uses opaque padded layout: reject
its declarations, derive genuine SoundService/base/member layout before adopting
algorithm. Sound.h donor and glue names SoundChannel/SoundService differ from
observed original Soundscape service naming. Next: trace actual class descriptor
initializers and constructor, then recover nativeSound wrapper/createSound and
wire authored tone.wav through deserialized sound and original FMOD path.

P4 IN PROGRESS, source88e67662d4. Canonical build linked/test0. Normal/default
launch reads disk places; native00500b90/00500780 FileMesh and004eb190 file
texture branch integrated with existing entities. Actual RBX::SpecialShape
child/property signals now supported for FILE_MESH. Overlay fixes Content XML
type and absent xsi:nil parsing, proven at0056cd80/0058f6c0; rbxgs-app rebuilt.
CC0 panel.mesh/quadrants.png/tone.wav separated from original external assets.
Both disk fixtures pass from clean CWD: panel1model at0; nestedgallery2models
at-2/+2. Four UV quadrant pixels verified, sphere864source/1296GPUindices.
Missingmesh hides geometry/status3, missingtexture renders ordinary fallback,
badplace exits1. All render cleanup counters0. Final receipts pin exact source,
EXE/map/content/fixtures, actual loaded DLL paths/hashes and observer:
work/2008-06/p4-disk-assets-88e67662d4/receipt.json.
Same EXE mixed-shape P3 lifetime/selftest/cachetest all PASS:
work/2008-06/p4-lifetime-regression-88e67662d4/receipt.json.
Audit:rebuild/2008-06/tests/p2-recovered/p4-local-assets-audit.md.
P4 NOT COMPLETE: original-client comparison and native sound path remain open;
tone.wav unused. No native camera consumption credited by XML camera reference.
Next: stage separate original-reference Content (never write through prior
content junction), open same two disk fixtures, compare selected assets/materials
and missingasset behavior. Then native audio recovery. Existing owner3debugfiles
still39insertions/12deletions, docs/rebuild-progress.json local build output kept.

P3 PASSED at source0dcbf70f18. Audit:
rebuild/2008-06/tests/p2-recovered/p3-acceptance-audit.md. Native ball path now
integrated with genuine Mesh/Level/builder/cache members; no entity redo. Shared
MeshRef now targets Mesh base. Sphere geometry294vertices/864QUAD indices/1296GPU
indices; unit32lifetimes/sharedreuse/100creationpurge pass. Normal GPU sphere
renders10757pixels, fill.7858. HW trace proves sphere ctor Mesh->Level->uploaded
SubMesh->actual RbxSubEntity render operation->entity teardown, EXE unpatched.
Final normal selftest/cachetest and P2 hardware trace also pass.

Mixed block/ball --p3test repeats both full lifetime cycles: resize/move/rotate,
reparent,detach/reattach,insert/remove,removeBrick,emptyplace,reopen. Other retains
node/mesh/size/transform and exact foreground silhouette throughout. Initial red
color-threshold oracle failed1pixel due curved-surface lighting; color counts kept,
geometric foreground mask is now the gate. Mesh/material/texture/root-node counts
return3/3/0/0; native levels/refs/backends/sphere entries0. Final receipts:
p3-mixed-lifetime-0dcbf70f18/,p3-sphere-final-0dcbf70f18/,
p2-flat-producer/p3-sphere-block-final-trace-0dcbf70f18/.

Original target staged unmodified in work/2008-06/original-sphere-reference/
(EXE SHA2fbb...764); content junction points to original RCC period assets.
Original CLI opens versioned sphere-reference.rbxl with explicit identity Camera
at0,0,10/focus0. Captured helper JPEG vs rebuilt same-fixture backbuffer PNG:
normalizedIoU.98403556 passes fixed.98, manualboxcontrol.79270935 fails.9.
Earlier tilted ZoomExtents capture failed.97932256; retained, threshold unchanged.
Reference proof:p3-reference-proof-0dcbf70f18/; rebuilt comparison:
p3-aligned-player-0dcbf70f18/comparison.json. Original UI helper close failed;
owned test PID35304 terminated after capture, clean original exit not credited.

Known adapter: standard TextureProxy previously null-read805. Null harness context
now explicitly enables mipmaps/AA0; genuine +805/+800 reads preserved for real
context. Full renderer context is P6/native work, not an invented padded object.
stage_demo_content.py now also stages original textures/Surfaces.png. Rebuild
p2-native-material explicitly after its sources change; canonical player reuses
cached dependency archives. Owner3debugfiles still39insertions/12deletions.
Next P4: read roadmap gate, build two redistributable disk places exercising
parent/child refs, local texture/mesh/sound and observed failure behavior; compare
against original. Current findings package36160f15 still pins P0; later source
package publication must include these committed P3 inputs. No P4-P10 completion.

P3 block lifetime subgate PASSED at sourcee7145c8a63. Canonical player builds,
normal --p3test lifetime-blocks.rbxl,selftest,cachetest all exit0. Two in-process
cycles cover initial2parts,resize/move/rotate,reparentwithinWorkspace,detach/
reattach,insertion/removal,removeBrick,emptyplace,reopen. Red Other retains node,
geometry,dimensions,position/orientation and exact2450-pixel silhouette across
all16stages. Resize/rotation model values checked. Insert adds1314foreground
pixels at85,159..118,198; removal restores exact preceding frame. Baselines
mesh3/material3/texture0/rootchildren0 restored; refs/levels/backends/spheres0.
Receipt:work/2008-06/p3-lifetime-accepted-e7145c8a63/receipt.json pins EXE/map,
fixture,sources,observer,actual DLLs,CSV,captures and independent image audit.
P3 remains OPEN: native non-box production/reference silhouette still absent.

Ball trace saved:work/2008-06/p3-ball-trace-e7145c8a63/. Native Part ctor installs
00826f94; slot10=004ef930. Shape0 branch004f00a4 calls004eea30; factory alloc8c,
ctor004fcfb0,geometryKind2@84,QUADS Level, builder00500d80 then00500d30,6elements.
Builder00827134 slots:00500d30,004fcec0,004fcf50,004fcf20,004fce90,004fcf80,
004fcef0. Facewrapper004fce90 passes actual callback004fabb0 to004fbdb0. Callback
normalizes vertex, copies unitnormal, component-scales radius; UV unchanged.
Resolved roc-lib source for004fce90 points at CylinderMesh.cpp (wrong callback
family), and004fabb0 metadata calls it TorsoBuilder. Do not trust those names or
adopt padded mining structs. Genuine QuadVolume.h LevelBuilder has halfSize,
surfaceTypes,LevelRef,textureScale; native elements offset20 agrees. Next recover
six face templates/shared-bank access and non-mega material path, then integrate
native sphere subtype/cache and compare against original. No entity redo.

P0 PASSED at source51cc35d301, findings36160f15c42b980a9ea93de4a633bf597dd44617.
Full published byte audit covers7978files,zero mismatches. Publication preserved
22existing diagnostic/module/verification files instead of removing newer work.
Initial publication078008c7 changed two fixture line endings through Git filters;
retained audit proves failure. Fixed publisher validates raw blob identity and
uses --no-filters, repairing unchanged-manifest bad blobs. Actual local bare-Git
regression passes, plus exporter regression. Final remote audit passes every hash.
Next open gate P3: isolated recovered player currently has cachetest, not owner's
p3test. Preserve owner test; integrate full lifetime controls and a native non-box
producer, compare silhouette against original. Non-box path currently omitted
explicitly in PlayerScene.cpp; do not replace with a manual box or stock sphere.

P0 clean-build/runtime gate proven at source51cc35d301. Detached worktree
C:/Users/colin/roc-p0 started tracked-clean with zero reconstructed outputs;
only tools junction shares pinned compilers/vendor dependencies. Official client
fetch/analyze, doctor150021022 and canonical player build complete. Player
linked=True/test_exit=0. Separate normal processes selftest0,falling240=0,
stability600=0,missing-place=1. CSV independently verifies all600 anchored/stable
floor samples and final300 Brick samples exactly-3.8027389, ideal-3.8 tolerance.01.
Evidence:work/2008-06/p0-clean-proof-51cc35d301/ includes actual loaded DLL paths,
EXE/map/fixture hashes,28 library/tool pins,721 command hashes and build reports.
Cold native-material test exit1 was absent ROC_TEXTURE_STRIP; unchanged binary
with staged original strip exits0. Original failure retained, no blanket green.

Found export defect: named-harness filter dropped direct-layer and included.cpp
sources, fixtures and staging scripts. Exporter now retains test source inputs;
regression passes. Fresh candidate from clean source51 has7959files, no missing
module test-layer sources;71required test inputs audited. Candidate lives at
C:/Users/colin/roc-p0/work/2008-06/p0-source-export-51cc35d301. Final publication
adds preserved remote files; publication-final-byte-audit.json pins result.
Existing owner source changes stay39insertions/12deletions, unstaged.
Original source/candidate receipt remains immutable; its published=false records
pre-publication state. Final publication audit supersedes that state.
Read-only findings status handle17424 remains live in lazy-fetch subprocess;
do not restart it merely because output is quiet. Fresh build35318 and runtime
60909 completed0; export96992 completed0. No builds currently active.

Requested demo COMPLETE / user accepted. Sourceb8cd526f04 builds/exits0. Default
launch now shows red4x1.2x2 anchored block, full2x4 stud rows, period default sky.
Original004d9e00 material template byte-confirmed at00940660; polar UV basis
corrected for stock Ogre (+90up,-90down), all six GPU views match source images.
Fractional2.5 depth caused cut stud rows; demo uses whole4x2 dimensions. Real
180-frame/30fps/6s VP8 capture and PNG:work/2008-06/sky-demo-final/.
Receipt pins same source/EXE/DLLs/assets, full video decode180, six-view errors,
missing-sky exit8, missing-place exit1, default no-argument launch and normal
WM_CLOSE exit0. Content staged beside EXE; no developer env needed for demo.
Original external assets are not committed; exact June distribution unproven.

Final same-revision P2 regression:1879/2080/0/0 pixels, two cache cycles,
zero levels/refs/backends/spheres, hardware identity/removal trace pass.
Receipts:p2-flat-producer/final-sky-p2-regression/receipt.json and
final-sky-p2-trace/receipt.json. Existing owner debug edits preserved.

User now requests resuming roadmap. Next first open gate: P0 clean second-worktree
reproduction and sustained falling stability / missing-place error. Then full P3
lifecycle and non-box silhouette. P2 ordinary-block gate stays passed. No P4-P10
completion claimed by default sky/demo; custom Sky/service/startup integration
remains later work. Reuse immutable prerequisite receipts, do not redo entity work.

P2 PASSED for ordinary block/first-level gate at source3f89605232. Acceptance
audit:rebuild/2008-06/tests/p2-recovered/p2-acceptance-audit.md. Normal receipt:
p2-flat-producer/p2-acceptance-runtime/receipt.json. Hardware receipt:
p2-flat-producer/p2-acceptance-trace/receipt.json. Four controls1879/2080/0/0,
two cache cycles, levels/refs/backends/spheres0. Existing lit metric documented;
same captures retain old unlit-mask failure counts. No whole-roadmap completion.

Critical final edge: native SubEntity vtable0084e90c slot3=00684fd0
getRenderOperation. Existing recovered source directly calls detached SubMesh
_getRenderOperation, avoiding stock animation-data selection. Added only that
override plus native size15c/lod134 compile checks; existing entity methods and
owner debug edits preserved. Removed fabricated SubMesh parent link; cachetest
asserts parent remains null. Hardware breakpoints prove exact Mesh->level0->
uploaded SubMesh->created child->actual render-op identity. Same parent entity
is destroyed between before/after removal DebugString stage events. EXE bytes
unchanged by observer, actual DLL identities pinned. No server exact credit.

Next: requested default skybox + red studded block demo and actual screenshot/
spinning video. Use real identified period assets and recovered skybox setup;
keep green selftest fixture/camera separate. Then continue remaining roadmap
gates. P0 clean-worktree/stability and complete P3-P10 remain unproven. Full
enclosing scene/Lighting classes, aggregation, non-box/shared-index/selector and
unused shadow branches remain separately tracked; do not mistake P2 for these.

Earlier checkpoints below retain investigation history and are superseded by
the scoped acceptance verdict above.

User follow-up: after P2, make skybox work with a default skybox and a visible red
block with studs. Use identified original period sky assets; default demo camera
must show the studded face. Keep green acceptance fixture separate. This is an
additional deliverable, not permission to skip unfinished P2 connections.
When that demo is finished, deliver an actual rendered screenshot or a video of
it spinning; user prefers either. Prefer a short spinning video if capture tools
are available. Capture the real player output, not a synthetic mockup.

Sphere-cache lifetime now integrated at sourcead921338f6. p2-mesh-backend,
p2-block-mesh,p2-block-factory,p2-recovered-player all link/test0. Three normal
unit processes pass; receipt:p2-flat-producer/sphere-unit-runtime/receipt.json.
Normal player selftest1879/2080/0/0 and two cache cycles pass; final cleanup
levels/refs/backends/spheres all0. Falling240 smoke still y=-3.80274. Player
receipt:p2-flat-producer/sphere-player-runtime/receipt.json. Backend key is
registered from original007aba1d/007abae7 behavior and erased after Level backend
deletion per00548766. Tests cover stable mapped references,zero key,missing
error,update,erase,32 retained Level lifetimes and two reload cycles. Empty
global map persists like native initializer; no all-heap-freed claim.

Setter00682350 stored extent211 cut the final short jump in half. Actual
00682422->006823f0 ends00682424, then int3 padding: full size212. Full disassembly
and hashes in sphere-setter-extent.json/sphere-setter-full-disassembly.txt. No
client registry/server extent edited, no new exact credit. Shared-index removal
at00548992 remains outside exercised first-level branch. Prior passing player
EXE/map/DLLs preserved locally in pre-sphere-player-e177bc4a9e/.

Next: audit remaining P2 requirements against the actual roadmap, keeping the
ordinary block/first-level scope distinct from full-executable P9/P10 work.
Remaining bridge questions are original scene/node use, metadata parent and
selector, plus original-client runtime/visual proof. Current native node table
0084d30c has116 slots:64=00681190 _update,86=006817e0 _updateBounds,
87=00681560 _findVisibleObjects,110=00681f90 setTransform,111=006818e0
getTransform,112=00681a00 hasTransform,113/114/115 sphere set/get/has.
These names must be checked against the binary; mined units are provisional.
The owner entity implementations and debug edits remain unchanged. P2 remains
open pending that acceptance audit; do not equate these cache tests with closure.

Material/light player integration tested at sourcee177bc4a9e. Build links/exits0;
normal selftest passes1879/2080/0/0, two cache9->8->0 cycles return mesh/material
counts to baseline; cleanup levels/refs/backends all0. Falling240 smoke still
y=-3.80274,2models; not a P0 sustained/clean-worktree proof. Receipt:
p2-flat-producer/native-material-player-runtime/receipt.json. Loaded DLLs, source,
EXE/map, actual asset, captures, fixture and selected providers hashed. Entity
implementation and newer owner debug files unchanged. Known-good pre-material
EXE/map/DLLs preserved locally in pre-material-player-0f567d02e8/.

004eb190 is Part vtable5, ordinary path gets mega-material with color/alpha/
reflectance. Chunk and renderer retain real MaterialRef.007ab0a0 backend assigns
material per SubEntity; no diagnostic unlit/manual color pass. Actual model sky
parameters feed recovered lights; extra native Lighting fields use005e1a40
defaults because the donor model lacks them. This bridge keeps P2 open.

Pixel metric explicitly changed: unchanged fixture quantizes to40/127/70 and
native-lit face is about23/72/40. Old unlit G>120 threshold fails8/9pixels;
final receipt retains its counts from the exact same captures. New metric
G>50,G>2R,2G>3B keeps original area>300/noise<30 and removal/empty gates. No
fixture/camera/light-value change to force the gate. Original-client visual
comparison remains unproven. Initial smoke also exposed wrong caller indexing
of unused addedEntities; replaced with existing Entity::getSubEntity(0), without
editing entity implementations.

Next P2 edge: native global sphere cache. Node ctor00674160/vtable0084d30c;
actual setSphere slot113=00682350, getSphere114=00682040, has115=00682100.
Sphere map lives at0097dbc4, distinct from per-node transform map+228.006822e0
initializes map;00682150 removes key. Level cleanup005486e0 calls removal at
00548766 and00548992, currently omitted by backend. Evidence:
p2-flat-producer/node-sphere-next-edge.json and disassembly. Stored00682350
source is empty/unmatched: do not adopt it. Recover real set/update/remove
algorithm and hook original Level cleanup; exercise exact cache lifetime. Then
replace remaining scene/metadata/selector bridges; do not mark P2 complete merely
because lit pixels pass. P3-P10 and P0 clean-worktree/stability remain open.

Lighting prerequisite tested at source33b464e8f6. p2-lighting build/test and
normal process exit0. Receipt:p2-flat-producer/native-lighting-runtime/receipt.json.
004dab50 is the real light-state writer: Lighting+270..2d0 -> Scene+338..398.
005e1a40 proves zero tints,brightness1,ambient.5,main diffuse/specular and fill
diffuse/scale1,fill specular0. Typed Settings value group has no invented
enclosing padding. 007aacc0 preset and007a9d30 setup tests cover actual light
state, bounds placement, clamping, tint, flags, surplus lights and retained fill.
Important corrected source interpretation:007aa1a6/007aa1c0 compares field and
automatic-object addresses, not RGB zero. Initial specular normalization test8
failed; original instructions disprove that expectation. Zero multiplier stays
zero. Full native Lighting class ABI and sky environment path remain unproven.
Next: preserve known-good player EXE/DLLs before rebuilding; wire native MaterialRef
ownership, renderer backend and actual lighting inputs into isolated p2-recovered
player. Remove diagnostic unlit/manual color material. Do not change entity code
or owner Player2008/PlayerEngine/RbxEntity debug edits. Run normal four controls
and cache cycles, save exact-revision evidence; full scene/selector still open.

Renderer material prerequisite now tested at sourceb78e67f137. Original007ab0a0
pass setup extracted into PlayerMaterialBackend.cpp using measured native types.
Build/test and normal-process test exit0; receipt at
p2-flat-producer/native-material-backend-runtime/receipt.json. All five mesh-kind
branches, two-pass creation, reuse, lit diffuse/ambient/specular/shininess,
depth bias/write, transparency blending and real atlas binding checked. Alpha
texture and reflection image branches retained but not runtime exercised. This
does not establish the enclosing RenderScene ABI. Next: derive actual lighting
values/setup007a9d30, then wire material/proxy/backend into published player.
Player remains unchanged, owner debug files preserved, P2 remains open.

Native material prerequisite now tested at source18624d7141. Modules
p2-texture-interop/p2-native-material link and exit0; normal-process runs also
exit0. Receipt:p2-flat-producer/native-material-runtime/receipt.json. Measured
Material/Level/TextureProxy hierarchy, offsets and five emitted vtables checked
against original tables/RTTI. Fixed-slot calls cover Material2/3 and Level2/3.
MSVC reverses overloaded virtual declaration groups; declarations now emit the
original order. Real mega atlas resolution,32 weak-cache/backend lifetimes and
texture GC pass. No verified_sinks in either map. Legacy file/shade resolver
branches remain runtime-unproven. Player executable/source remain unchanged.
Next: original renderer material creation007ab0a0 and lighting007a9d30; do not
adopt the mined padded scene/owner declarations. P2 remains open.

P2 IN PROGRESS. Factory/cache and native-default paired levels now integrated.
Tested source:0f567d02e8; receipt:p2-flat-producer/factory-runtime/receipt.json.
Builds:p2-block-factory, p2-block-mesh, p2-recovered-player all link/exit0.
Normal --selftest:1879/2080/0/0 pixels; all four pass. --cachetest versioned
cache-blocks.rbxl:two9->8->0 cycles pass, mesh/material counts return to baseline.
All cleanup levels/vertex refs/backend counts zero. Separate falling240 smoke
settles y=-3.80274 with2models and clean shutdown; fixture remains local/unversioned.
512-lookups/120-key factory fixture passes, including both upload widths and
recursive every100-creation purge. Loaded DLL paths/hashes and linked map symbols
recorded. P0 clean-second-worktree and P3-P10 remain unproven.

Launch target:rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe.
Build:`roc rebuild 2008-06 module p2-recovered-player --no-notify`.
Use normal environment (unset ROC_BUILD) and a fresh capture directory.
Existing owner Player2008.cpp/PlayerEngine.cpp/RbxEntity.h remain untouched.
Earlier known-good source c301f9241e retained in native-owner-backbuffer-runtime/.

Recovered 004e2c80 produces loaded small block level0; 00549a50 uploads it through
0067c130 to measured RbxSubMesh. Entity implementation was preserved. No handwritten
box geometry in this target. Still diagnostic material and partial original selector.

Owner layout verified: levels-only owner replaced with measured full 0x88-byte Mesh.
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

Current completed edge: 004e58b0 factory/cache and004e5710 purge integrated with
measured Lookup/Variations20-byte records and48-byte cache. Retains four variants,
recursive mutex, every100-creations purge, and native default paired bevel/flat
levels. Geometry-shared renderer metadata/material survives removal of one user;
SDK's three system references matter. Initial one-reference check leaked resources
(cachetest exit11); corrected to RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS+1.
Factory fixture512 lookups/120 new keys passes; direct flat regression passes.
Normal selftest1879/2080/0/0 passes; cachetest two9->8->0 cycles returns every
mesh/material/level/ref/backend count to baseline. Final tested revision0f567d02e8 recorded in factory-runtime/receipt.json.
Versioned fixture: rebuild/2008-06/tests/fixtures/cache-blocks.rbxl.

Current material prerequisite: source248136093f builds p2-image-core and
p2-texture-atlas, both link/exit0. Normal-process receipt:atlas-runtime/receipt.json.
Existing007add10 shading and007ae4e0 expansion produce2048x256 RGB atlas from
real64x256 strip. Full GPU bytes match CPU reference in device FPU mode, neutral
palette/shading anchors/cache identity/missing file/teardown pass. CPU/GPU images
saved. Factory player hash remains identical to0f567d02e8 acceptance executable.

Important decoder correction: old G3D linked library routes PNG entry points into
verified_sinks.obj traps. Native debug runner and map prove breakpoint0040e494.
Clean p2-image-core recompiles real G3D/IJG and bundled libpng1.2.7 in a separate
output; final core/atlas maps contain no verified_sinks. Existing libraries remain
preserved. Do not route new image code through the old sink-bearing library.

GPU comparison initially differed byone: D3D9 changes x87 precision0009001f to
000a001f. CPU palette computed before device creation differed from the native
post-device upload. Compare in same device FPU state; no tolerance or forced
precision preservation was added. Real strip hashdc5418f1...dae85e4 matches both
August2007 client and RCCService0.3.784.0 installer (PEMay14,2008). Exact June2008
asset identity remains unproven; record it as external dependency, not replacement art.

Earlier next edge (ownership prerequisite now completed above): native Material/Level/TextureProxy ownership and original renderer material
creation for this same block. Read atlas-material-evidence.json first. Material
size18, Level38; constructor007ad230 leaves matte null (no donor alphaOnlyVersion
call); destructor007ad310 unregisters Ogre material. Native Level slot2 resolves
proxy with context, slot3 returns proxy ref: provisional donor order was wrong;
new declarations account for MSVC overload reversal and emitted tables pass.
TextureProxyBase is30 bytes with eight slots: dtor, set/getint28, set/getfloat2c,
getSize, resolve, shade. Donor getSize slot1 is incompatible with native slot5.
00551bf0 initializes28=1,2c=1.0. Native RenderNew proxy fields30/34/38/3c/40/44/48/54
and Mega extra60/allocation64 have binary evidence. Do not invent padded classes
or placeholder virtual methods. Exported source007ae4e0 contains the existing
atlas body; current helper deliberately does not claim the full proxy class ABI.

P2 stays open: atlas is standalone, player material still diagnostic. Native scene
bounds-cache/shared-index, selector/child handling and remaining roadmap still open.
No new server-native credit or active claims/jobs.

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

## P4 checkpoint: large blocks (bc2b8d80a4)

This checkpoint supersedes the older open-status notes above. P2 and P3 ordinary
block/sphere paths passed their recorded acceptance tests. P4 remains open.
The 004f4cb0 large-block surface builder and four-variation factory now render
through the existing native mesh bank and ordinary surface material. At source
revision bc2b8d80a4, PBB GPU/lifetime/cache tests, P3 sphere and mixed lifetime
regressions, player build and selftest passed. In the supplied Bread Factory map,
780 of 792 models render (formerly 480); 12 remain status 3. Cleanup counters
return to zero. Sanitized evidence is in p4-pbb-bc2b8d80a4 and
p4-pbb-lifetime-bc2b8d80a4; user map and captures stay private. Original-client
large-block comparison and shadow branch are unproven. No server exact claimed.

Next: trace cylinder builder 004fd430 and transforms 004fd4a0/004fd530, compare
the original, integrate and test remaining shapes. Then complete P4 native sound,
real-place fidelity and the remaining roadmap. Preserve newer local player files.

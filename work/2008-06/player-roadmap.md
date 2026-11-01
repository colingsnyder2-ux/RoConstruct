# P5 local input and renderer precision checkpoint

Source 1f22f9eb1c connects the address-identified 005cb530 PlayerController
behavior to an opt-in local-player fixture, existing Humanoid joint builder,
and a focused Win32 UserInputBase adapter. WASD/arrow precedence, diagonal
normalization, camera pan, jump and idle controls pass. A joined six-part
character walks and stays together; a visible run with injected real Windows
W/Q input moves torso about 9.5 units and camera about 4 units, then closes
cleanly. This uses donor Humanoid movement physics, an explicitly created local
Players service, and a harness camera; it is not normal-launch/original physics
parity. Cursor-lock member offset 0x3c was compiler-verified against the target
controller getter. Evidence: p5-controller-1f22f9eb1c/ and
p5-controller-layout-1f22f9eb1c/.

Two earlier fixed-step runs spun in TimerService: D3D9 changed x87 to 24-bit
precision, rounding a 0.01-second timer delay to zero at epoch-scale time.
Original renderer setup 0067ab34..0067abfd forces Floating-point mode to
Consistent; the player now does likewise. The regression shows 53-bit precision,
nonzero delay and one callback instead of four. Eight alternating controller
starts pass afterward: p5-controller-stress-1f22f9eb1c/. P0, P3, P4, P5 script,
anchor and sound regressions pass at the same source revision.

P5 remains open: native frame/scheduler and character physics, original
fixed-step comparison, automatic local spawn, camera/input integration and
full real-place coverage. The anchor/heartbeat/Win32 adapters remain tracked.

# P5 anchor/drag overlap checkpoint

Source bf2c154c4c fixes a reproduced access violation when dragging an
unanchored live Part. Original descriptor 007f4810 binds Anchored getter
00598d40 to the individual Primitive +a9 flag; the prior donor getter used
the aggregate. Original setters 005e8050/005e80d0/005e8140 update +a8/+a9/+aa
and signal the world on aggregate changes. The legacy Anchor registry shim now
creates/removes its object for transitions through any flag. It remains a shim;
original stage 0064cc40/0064ccf0 swaps AnchorJoint and FreeJoint instead.

All eight flag combinations pass. Lua-driven release/reanchor/release and
drag/anchor overlap pass, settle at y=-3.8027389, and repeat identically after
reopen. P5 script, P3 lifetime, P4 asset and audio controls pass. Evidence:
p5-anchor-overlap-before/, p5-anchor-overlap-bf2c154c4c/ and the matching
p5-anchor-*-bf2c154c4c/ regression receipts. Native joint integration, original
physics comparison, normal launch, character input and full P5 remain open.

# P5 scripted play checkpoint

Source a8b6964fcd adds an opt-in --p5-play diagnostic: the existing RunService
play transition starts serialized workspace Scripts. Fixed-step harness emits
Stepped and Heartbeat after DataModel::step, following the existing reconstructed
runProc order; this is a shim, not yet verified original frame-loop code.
Authored controls prove edit mode idle, immediate play script, wait(0.1) pending
after one frame and resumed by ten, and disabled script idle. P3 lifetime,
selftest and cache controls pass. Evidence: p5-script-controls-a8b6964fcd/
and p5-script-regressions-a8b6964fcd/.

P5 remains open: original scheduler/timing comparison, normal visible launch
and input, local character/controller, anchoring transitions and original
fixed-step physics comparison. Do not claim native scheduler equivalence from
the donor/rebuild shim.

# P4 acceptance checkpoint; begin P5

At source 866583a618, two authored disk places load from clean working
directories; expected model positions, source geometry, texture quadrants and
material fallback match bounded original-client observations. Removed mesh,
removed texture and bad path controls pass. Redistributable fixture assets and
original external dependencies are listed in p2-recovered/p4-local-assets-audit.md
and the P4 staging receipts. The original and rebuilt clients both play the
authored looping 2D tone: loopback 440 Hz amplitude ratio 0.99994 and RMS
ratio 0.99994. Rebuilt player closes cleanly; original required terminating its
owned process after window close. Raw loopback audio was not saved. Evidence:
p4-assets-compare-HEAD/ and p4-audio-compare-HEAD/. Original and rebuilt
captures remain local; receipts pin their hashes and source revision.

P4 scoped acceptance passes for these fixtures. This is not full place,
renderer or audio parity: later user-place GUI classes, spatial/scripting audio,
original startup/UI, and ContentProvider contextual ownership remain open.
The audio observer uses optional local SoundCard; it is not yet packaged.
Begin P5: recover frame/input, scripting, character/controller and anchoring
behavior; preserve the known anchoring shim until its original is verified.

# Sound controls and device checkpoint

Source 729294d0b3 recovers Volume and Looped setters/getters, PlayOnRemove,
IsPlaying/IsPaused and Play/Pause/Stop reflection. Serialized non-default
properties pass, and descriptor dispatch drives a real FMOD channel with
volume/loop/pause/stop verified. Device test opens native FMOD via WASAPI
(output9) and reports the test tone playing; hearing it is not independently
verified. Player rebuild, fixture load and P3 lifetime/self/cache tests pass.
Evidence: p4-sound-controls-runtime-729294d0b3/,
p4-sound-controls-load-729294d0b3/ and
p4-sound-controls-regressions-729294d0b3/.

Same user place retains six of eight sounds. The missing two are beneath
StarterGui > ScreenGui; neither class name appears as an ASCII string in the
original executable. This does not prove absence of equivalent GUI behavior.
P4 remains open: original audio comparison, real-place full asset handling,
Sound callback/security equivalence and remaining compatibility.

# Sound service and factory checkpoint

Source bbe43074c2 connects recovered SoundService provider lifecycle, stock
sounds, SoundChannel ancestry, SoundId and PlayCount, and FMOD playback to
the isolated player. Tests pass for 14 stock sounds and service detachment,
serialized SoundId, and injected FMOD NOSOUND play/pause/stop/detach. P3
lifetime/self/cache regressions pass. User-place control: six of eight Sounds
retained (previously zero); the other two sit under StarterGui > ScreenGui.
Evidence: p4-sound-service-runtime-bbe43074c2/,
p4-sound-service-load-bbe43074c2/ and
p4-sound-service-regressions-bbe43074c2/. User place/log remain private.

P4 remains open: test injects FMOD system; normal device startup and audible
output are unproven. Sound volume/loop/play-on-remove reflection and script
methods need recovery, plus missing GUI hierarchy and remaining place assets.
The ContentProvider singleton is an adapter for the original contextual lookup.
Do not treat recovered-source labels as proof of byte matching.

# SoundId reflection checkpoint

Source 2a03269d2b adds SoundId Content text/XML adapter. Isolated descriptor
roundtrip, native FMOD loader and stats tests pass; evidence in
p4-sound-reflection-runtime-HEAD/. This does not instantiate SoundChannel,
prove original byte identity, or close P4 sound. WIP patch predates this test
and needs manual adaptation.

# Sound attachment investigation (unfinished)

Native provider callback 005bdcf0, stock loaders 005bdb10/005bd6d0 and
SoundId setter 005bd360 are drafted in p4-sound-attachment-wip.patch, outside
the active build. Forcing a real SoundService constructor exposed missing
sStockSound and SoundChannel ancestry
005bd890. SoundId reflection now has tested behavioral glue (not byte-matched).
Recover and link the remaining behaviors before adapting the patch; do not
replace them with stubs. The constructor test currently fails to link, so
service attachment and P4 audio remain unproven.

# Current player checkpoint

At sourcebf6f987578, recovered StockSound constructor005bd250 and SoundService
stats item005bcc40/005bcd80. A real stats-constructor test exposed a pre-existing
use-after-free: two Stats overlay templates dropped shared ownership before
parenting. Both now retain the child until parent ownership is established.
Stats test verifies four children and live memory/value/function counters;
sound/24-preset FMOD tests, app/player builds, P3 regressions and user-place
render counts784 visible/8 transparent all pass. Sound deserialization still
retains0 and P4 audio remains open. Evidence: p4-sound-stats-build-bf6f987578/,
p4-sound-stats-runtime-bf6f987578/, p4-sound-stats-load-bf6f987578/ and
p4-sound-stats-lifetime-bf6f987578/. User input stays private.

SoundService heartbeat005bc2c0 recovered at source91fa2d1c88 with real
Workspace/Camera/PVInstance/Part types, listener sanitization, five-second cache
collection and FMOD update. Original RTTI00947f1c identifies PVInstance; the
five-second constant comes from008358a8. Sound diagnostics pass, but the service
object/heartbeat remain unselected and unexecuted until provider attachment.
Evidence: p4-sound-heartbeat-91fa2d1c88/ and
p4-sound-heartbeat-runtime-91fa2d1c88/.

Reverb005b8880 recovered at source3bc3f92f3b. All24 real SDK preset structs
match original target bytes under x86 emulation; invalid enums/null system skip.
Original Room and PaddedCell share one preset. Actual FMOD NOSOUND accepts the
Room preset; existing audio diagnostics pass. Evidence: p4-reverb-build-3bc3f92f3b/
and p4-reverb-runtime-3bc3f92f3b/. Service method remains unexecuted in player.

SoundService::openFmod005ba060 is recovered at source091c56b252 against real
overlay/FMOD fields: original gates, driver/version checks, stereo fallback,
3D settings, reverb and exception cleanup. Original zero-initialized global flag
is represented locally; its settings connection remains unproven. Existing sound
diagnostic passes but openFmod is unselected/unexecuted pending service lifecycle
and reverb. Evidence: p4-sound-open-091c56b252/ and
p4-sound-open-runtime-pinned-091c56b252/. Audio/P4 remain open.

At sourcef34d1b3e46, the authored Workspace Sound fixture loads but retains
zero Sounds. A user-supplied place with8 serialized Sounds likewise retains0;
its2 Humanoids match both RTTI and class-name traversal. One Sound was directly
under Workspace. The player map lacks Sound creator symbols; exact registration
and lifecycle linkage still need proof. Diagnostic counts and sanitized receipts:
p4-sound-load-f34d1b3e46/; user XML/logs remain private. Next recover
SoundChannel::onAncestorChanged and real dependencies, then register native
factory, retain serialized Sound and test playback. P4 remains open.

At source50fff4e96c, SoundService 3D settings005b97b0 and reflection callback
005ba020 are recovered; original initializer007f5220 identifies the callback.
Sound diagnostic passes; these methods are unselected/unexecuted until service
attachment works. Evidence: p4-sound-settings-50fff4e96c/ and
p4-sound-settings-runtime-50fff4e96c/. Of58 readable supplied compressed XML
places,39 contain Sound instances; four further files were unreadable/non-XML.

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

## P5 checkpoint: original character spawn (0f8a33aff3)

The opt-in `--p5-spawn` loads four externally staged original character assets through
the donor `Player::loadCharacter()` and attaches the existing controller. MD5 digest
buffer/format corrections follow target 0055e320; the Lua object bridge now reads
userdata as its stored shared pointer rather than treating it as a Value. Three MD5
vectors pass. At revision 0f8a33aff3, 120-frame idle/input runs load seven models,
move the torso from z=25.5 to z=9.49949 under input, and clean mesh counters to zero.
P0, P3 lifetime, P4 asset/sound prerequisites and P5 controller/script regressions
pass. Receipts are in p5-*-0f8a33aff3; original assets remain external.

P5 is incomplete: the Head SpecialMesh has no geometry (status 3), and original
Sound and Animate scripts report errors, including missing Humanoid.FreeFalling.
Normal launch, camera integration, native joint/physics and scheduler parity remain
unproven. Donor loadCharacter differs from target's bool signature; no parity claim.
The target mesh dispatcher 004ef930 routes SpecialShape HEAD_MESH to createHead;
trace its original call and integrate the recovered head producer next. Then address
actual Humanoid signals and animation runtime, testing against the original client.

Head dispatch update: entry 0 of the original 004f02e0 jump table calls
004ef430 (matched HeadMesh factory), which constructs via 00500180 and
004fdaf0. See p5-head-trace.md. Trace virtual face builders next.

## P5 checkpoint: character head (4732a013da)

Original HeadMesh factory 004ef430 / constructor 00500180 and recovered
004fdcc0 / 004fdbd0 face transforms now feed the existing mesh bank and
scene. See p5-head-trace.md. Original-character 120-frame idle and movement
runs now render all seven models; the head has 1944 source quad indices and
2916 backend indices. Cleanup counters return to zero. Same-revision spawn,
controller, P3 lifetime and P4 asset regression receipts are in
p5-head-*-4732a013da. The 004fdbd0 source is 97% matched, and full original
client visual comparison and decal support remain unproven.

P5 remains open: original humanoid Sound and Animate scripts error, including
missing FreeFalling signal. Recover and integrate actual humanoid state event
registration and firing before claiming script functionality; then normal launch,
camera, native physics/joints and scheduler parity.

FreeFalling trace: descriptor initialization 007f68d0; original state entry
00667810 fires true and exit 00667930 fires false. See p5-freefall-trace.md.

## P5 checkpoint: FreeFalling transitions (9484069c6b)

Registered the original bool signal and integrated Freefall entry/exit fires
and Head/Torso friction save/restore, traced to 007f68d0, 00667810 and 00667930.
At revision 9484069c6b, direct transition checks observe true then false,
zero friction during freefall, and restored distinct values afterward. Spawn,
controller, script and lifetime regressions pass; original Sound script no
longer logs the missing FreeFalling member during 120-frame idle/input runs.
Receipts are in p5-freefall-*-9484069c6b. This does not establish original
physics or sound playback parity. Animate still reports an error at
GetPlayerFromCharacter (line 113); trace the Lua call and its arguments next.

At b9a76e6c2a, direct native local-player lookup passes inside controller
checks, alongside idle/input/script/live-input regression runs. Lua controls
show object and method lookup succeed, but invoking the method fails with a
function-valued error. Evidence: p5-lookup-controller-b9a76e6c2a/receipt.json
and p5-player-lookup-trace.md. Continue tracing the Lua member-call boundary.

## P5 checkpoint: Lua instance conversion (38adac8064)

The recovered 0056f8c0 Object-to-Instance Value conversion is integrated into
the rebuilt reflection ABI. Bridge userdata checks now balance the Lua stack.
At revision 38adac8064, a direct Lua-state test proves Instance identity and
unchanged stack depth, and an authored script confirms GetPlayerFromCharacter
returns the local Player. Spawn, controller, script, lifetime, P4 assets, sound
prerequisite and P0 regressions pass; receipts are in p5-lua*-38adac8064.
Original Animate proceeds past its former lookup error but stops on the missing
Climbing signal. Its actual state behavior is traced in p5-climbing-trace.md;
full animation, climbing, sound playback, native physics and P5 remain open.

## P5 checkpoint: climbing detection probe (ff34299c3b)

Correcting the older trace: original Climbing is state 9, not 10. The factory,
transition and predicate jump tables show a detected-climb predicate enters
state 9 and its inverse exits. Diagnostic candidate-box and 17-ray sweep uses
the recovered 00644a30 / 00644c80 behavior and 006432e0 filter with the
rebuilt contact manager. At ff34299c3b it detects a near rung and rejects
empty, distant, tall wall, behind, character-descendant and noncollidable
controls. Spawn, controller and lifetime regressions also pass. Receipts are
in p5-climb-*-ff34299c3b.

This is not wired into runtime humanoid states; original-client sensor parity,
state transitions, force behavior and Climbing event remain open. The 00666410
and 00666550 recovered sources identify desired velocity and force paths; port
them with the state transitions, then compare movement and signal output.

## P5 checkpoint: adapted climb state (226e4308cc)

The recovered climb detector now drives an adapted donor-ABI Climbing state.
It uses the 00666410 velocity/heading transform, the no-floor part of
00666550 force math, 006432e0 ray filtering, and the 006451c0 limb policy.
Climbing signals are registered and fired. Original character Animate and
Sound scripts no longer log their prior missing-event errors in the 120-frame
spawn control; full playback and animation fidelity are not proven.

At 226e4308cc, a near-rung input run emits nine Climbing events (peak 15.8392),
delivers the event to Lua, and reaches torso y=3.6511 at frame 18 versus
2.8146 for the noncollidable control. The event stops after leaving the sensor;
idle stays stable. Sensor, controller, authored script, spawn, P3 lifetime,
P4 assets/sound prerequisite and P0 regressions pass. Receipts are in
p5-climb-*-226e4308cc. The original-client comparison, floor reaction and
moving-floor velocity, exact state transitions, avatar/camera integration,
full animation/sound behavior, and later milestones remain open.

The existing RunService constructor overlay had accidentally omitted
runDisabled initialization, causing path-dependent missed script starts. It now
initializes false, verified after constructing over poisoned memory.

## P5 checkpoint: character camera adapter (7143c96f2c)

The opt-in `--p5-native-camera` path now drives Ogre from the existing
DataModel character camera's position, rotation, horizontal FOV converted to
viewport vertical FOV, and clip planes. The default staged sky is enabled in
this mode. The camera subject retains the actual Instance rather than an
invalid ModelInstance downcast. The character-focus/occlusion implementation
in glue_camera.cpp and the skybox remain behavioral reconstructions, not
byte-verified original implementations; see p5-camera-adapter.md.

At 7143c96f2c, the 120-frame movement test moves actor z by -15.9994 and the
camera by the same amount relative to its idle control; the turn test changes
look x to -0.7041. Ogre/native position and rotation agree to 1e-5 or better,
and projection conversion and clipping checks pass. A focused real-time
spawn test moves actor z from 25.5 to 16.0328 and turns camera look x to
-0.7973, then exits cleanly. Camera, controller, climb, spawn, script,
lifetime, P4 asset and P0 receipts are in p5-camera*-7143c96f2c.

This is opt-in; normal launch, original camera/occlusion comparison, mouse
input, original frame-loop/physics parity, P5's complete acceptance and later
milestones remain open.

## P5 checkpoint: standalone play path (c76495854b)

The recovered-player harness now launches an authored playable place with no
arguments; `--play [path]` also accepts XML or gzip places. `--demo` retains the
red studded block. Original character assets remain externally staged. This is
not the original client bootstrap; see p5-play-path.md.

At c76495854b, two focused no-argument launches, keyboard movement and turn,
collision, Lua touch response, reopening, XML/gzip loading and corrupt-gzip
rejection pass. Camera, climb, controller, spawn, script, lifetime, P4 assets,
P0 and demo checks also pass. Receipts are in p5-*-c76495854b.

One supplied place loaded for 30 frames with 798 models, 790 status 0 and 8
status 4; it produced 74 missing-member Lua errors. Its serialized Workspace
contains 91 IntValue, 9 StringValue, 201 ObjectValue and 8 NumberValue objects.
The cause is unproven: compare loaded class counts and hierarchy next. Only
hashes and aggregate results are recorded. P5 and later milestones remain open,
including original-client behavior and startup comparisons.

## P5 checkpoint: place class inventory (353cd4e2f5)

`--load-only` now reports class counts and exits after closing. At 353cd4e2f5,
build and selftest pass; authored fixture loads and closes. On the supplied
place, serialized Workspace has 126 Models, 786 Parts, 91 IntValues, 9
StringValues, 201 ObjectValues and 8 NumberValues. Loaded DataModel has 126
Models, 786 Parts and zero of those value classes. Receipt:
p5-inventory-353cd4e2f5/receipt.json. Class counts use different traversal
roots; missing values are definitive here because the larger loaded root has
zero. Reconstructed factory registration calls classDescriptor but does not
establish these creators; forcing getCreator references alone did not change
the counts. Creator/descriptor implementation and serialized Value properties
still need recovery and verification before claiming script compatibility.

## P5 checkpoint: value instances (62955063a7)

Behavioral glue now creates IntValue, StringValue, BoolValue, NumberValue and
ObjectValue, registers Value properties, resolves object references and emits
Changed on mutations. The 2008 executable contains NumberValue, not FloatValue.
These bodies are reconstructions, not byte-verified original code. Other value
types, native event ordering/parity and wider gameplay remain unproven.

At 62955063a7, authored XML and Lua verify serialized values, object reference,
mutations, nil reference and Changed callbacks. Build, P0, lifetime, P4 assets
and script scheduling regressions pass. On the same supplied place, inventory
now reports all 91 IntValue, 9 StringValue, 201 ObjectValue and 8 NumberValue
objects; 30-frame script error stacks fall from 74 to 6. This is not proof of
playability. Exact-revision receipts are in p5-values-*-62955063a7 and
p5-supplied-values-62955063a7. Next investigate remaining missing-member
errors and integrate the remaining value classes without claiming P5 complete.

## P5 checkpoint: typed values and signals (8474b02525)

The behavioral value reconstruction now includes Vector3Value, Color3Value,
BrickColorValue and CFrameValue. Lua signal dispatch marshals these four types;
unknown signal arguments push nil to preserve the Lua stack. At 8474b02525,
the authored fixture verifies deserialization, writes and Changed callbacks
for all nine value classes, including reference clearing. Build, script, P0,
lifetime and P4 asset regressions pass. Receipts are in p5-typed-*-8474b02525.
These reconstructed implementations and event ordering are not native parity.

The supplied place still reports six script errors in 30 frames. A separate
static inspection finds all six failing script expressions refer to direct
children absent from their serialized parent models; see the aggregate-only
p5-typed-map-audit receipt. This does not prove the place is playable or rule
out other runtime issues. Continue testing other supplied places and roadmap
acceptance; P5 and later milestones remain open.

## P5 checkpoint: contact and script startup (a4af240151)

A ball-block contact with overlapping bounds but no actual collision called an
unconditional connector-removal helper with a null connector. The ball-block
caller now checks for a connector, consistent with the existing ball-ball caller.
A directly detached script is no longer started, and detached script naming no
longer constructs a string from null. Authored fixtures reproduced both crashes
before the fixes and pass afterward, including the removed script not running.
Build, P0, lifetime, values and script scheduling regressions pass. Receipts are
in p5-contact-script-*-a4af240151.

At ce27d11d18 another supplied place ran 30 frames with 1,796 rendered models,
zero script error stacks and clean exit (p5-rocket-audit-ce27d11d18). A different
supplied place reached 30 frames and reported clean mesh cleanup at a4af240151,
but then exited with access violation 0xc0000005; the shutdown cause remains
unproven (p5-golf-negative-a4af240151). Neither run proves full playability or
native parity. Trace shutdown next; P5 and later milestones remain open.

## P5 checkpoint: detached-script registry (3e7fa3c6ec)

The remaining supplied-place shutdown crash reached ScriptContext::closeState
with a stale Script pointer. Temporary lifetime tracing showed a removed script
being registered again after detachment, then destroyed before cleanup. The
registration path now rejects scripts without a parent, complementing the
existing start guard. This is a behavioral repair, not byte-verified parity.

At 3e7fa3c6ec, the formerly crashing supplied place completed four independent
30-frame runs with clean shutdown and no script error stacks. Two authored
removal fixtures completed 16 runs total, including removal of a containing
model. P0, script scheduling, value, contact, scene lifetime and P4 asset
regressions pass. Receipts are in p5-*-3e7fa3c6ec; only hashes and aggregates
from the supplied place are saved. Longer gameplay, other lifecycle cases,
original-client comparison, P5 and later milestones remain unproven.

## P5 checkpoint: combined play scenario (3090182770)

An authored place now combines visible character input, camera turning,
collision-triggered Lua, two anchor transitions and final release onto an
anchored floor. At 3090182770 fixed-step movement triggers transitions at
frames 43, 51 and 60, then the block settles at y=1.00014246; idle control
stays anchored at y=12. Reopening reproduces the same sample hash. A focused
visible run moves the character about 6.44 studs, turns the camera, triggers
both changes and exits cleanly. Receipt: p5-combined-3090182770.

Three independently supplied places also complete 240 frames with clean
shutdown and no reported script error stacks: final model counts 881, 1,796
and 7,469; five of the first place's models report status 4. Receipts:
p5-long-map-*-3090182770. These are bounded smoke tests, not gameplay or asset
parity. The combined run uses reconstructed frame, camera and anchor adapters;
the required original-client fixed-step comparison and later milestones remain
open. Do not mark P5 complete on this evidence.

## P5 checkpoint: original falling comparison (0bc4b85c42)

A newly authored offset falling-block fixture was run in the original June 2008
executable and reconstructed player. The original editor run was sampled via
read-only process memory: three independent matching position copies moved and
agreed; two static copies were excluded. Twelve original wall-time observations
were compared against the rebuilt 60 Hz fixed-step trace within a two-frame
timing window. Two independent runs pass: maximum best-window error 0.079
studs; original settles at y=-3.8072393 and rebuilt at y=-3.80272245, difference
0.004517. Rebuilt floor anchoring and mesh cleanup pass. Exact-revision receipts are in
p5-original-fall-*-0bc4b85c42.

This measures one authored fall and bounce, not direct original single-step
control, full physics, anchor-cycle, scheduler or input equivalence. The
original process required forced termination after its window-close request;
the rebuilt process exited normally. Continue original anchor-cycle and
fixed-step investigation; P5 and later milestones remain open.

## P5 checkpoint: original anchor cycle (e9be161e82)

An authored fixture now drives release, re-anchor and final release in both
clients. Three separately moved marker Parts confirm the original Lua setters
completed; two matching process-memory position copies per marker and block
were sampled read-only. In two runs original marker changes occurred at roughly
0.094, 0.250-0.265 and 0.422 seconds; rebuilt fixed-step transitions occurred
at frames 6, 15 and 24. The original re-anchor plateau is about y=17.271,
rebuilt about y=17.796: a real 0.525-stud difference. Twelve original real-time
observations pass a deliberately broad 1.25-stud, +/-3-frame comparison window;
maximum observed best-window difference is 0.525. Both settle within 0.00452
studs of each other. Receipts: p5-original-anchor-*-e9be161e82.

This is a bounded comparison, not proof of exact fixed-step or anchor parity.
Original required forced termination after window close; rebuilt exited cleanly.
Investigate the re-anchor discrepancy and original scheduler/frame-loop, then
continue remaining P5 and later milestones.

## P5 checkpoint: recovered waiting-thread behavior (6c7b1ff3a8)

Original function 00621590 has server-reported 100% source in
`roc_espclaude_1f29ee3c3c2214e7.cpp`: WaitingThread stores requested/elapsed
time as doubles and resume pushes both elapsed and heartbeat time to Lua.
The rbxgs overlay now adapts those behaviors to its existing interfaces; the
integrated object has not itself been verified byte-identical. A shared fixture
checks both wait return values are numeric in the original and rebuilt clients.

At 6c7b1ff3a8 the original returned about 0.1000, 0.1667, 0.1667 seconds for
waits of 0.1, 0.15 and 0.15; rebuilt returned 0.1000, 0.1500, 0.1500. Thus
precision and return-value recovery does not resolve the one-frame discrepancy;
original heartbeat cadence and scheduler/clock ordering remain unproven. The
probe, anchor cycle, combined live play, script/lifetime, P0, value, P4 assets
and 240-frame supplied-place tests pass. Receipts are in p5-*-6c7b1ff3a8.
The original required forced termination after close. P5 remains incomplete.

## P5 checkpoint: original script cadence (396376bf09)

Direct original-client Lua probes show Heartbeat and Stepped each at about
1/30 second, not the harness's previous 1/60 second. Six long waits and six
sub-frame waits confirm the same 30 Hz quantization. The harness now emits Lua
Stepped and Heartbeat at the observed cadence while retaining 60 Hz internal
Stepped notifications and physics calls for the donor humanoid. That split is
an explicit compatibility shim: changing the donor humanoid to 30 Hz caused
its character to launch upward. The original frame loop and humanoid behavior
still need recovery.

At executable SHA 46c7be1227e9..., original and rebuilt heartbeat, stepped,
and all twelve wait observations agree within 1e-5 seconds. Anchor transitions
now occur at rebuilt frames 6, 16 and 26; original re-anchor plateau y=17.27142
versus rebuilt y=17.27860, difference 0.00718 studs (previously 0.525). The
later bounce comparison uses a +/-3-frame, 0.75-stud window and observed maximum
best-window error about 0.193 studs; final difference is 0.00452. Original
process still needed forced termination after window close. Receipts are
p5-cadence-{heartbeat,stepped,short,wait}-396376bf09 and
p5-cadence-anchor-28a9ad64a4; later observer-only commits preserve the same exe.

Combined visible play, controller, climb, anchor, P0, scripts, value, assets and
a 240-frame supplied place pass; corresponding p5-cadence-* receipts name their
exact revisions. A concurrent removal test exposed that independent scripts can
start in either order; its fixture now waits before the removed script's marker,
so it verifies cancellation without assuming startup ordering. P5 remains open:
native frame-loop/humanoid reconstruction, exact step parity and other roadmap
acceptance remain unproven.

## P5 checkpoint: adapted original running force (033913505c)

The previously guessed Running force is replaced by an adaptation of the
server-reported byte-matched 00666550 RunningBase::onComputeForce source. It
uses the original torque, altitude, acceleration, low-friction and floor
reaction formulas. Bounds come from 00666350/006663a0 and original executable
constants: max (1000,10000,1000), min (-1000,0,-1000). Climbing shares that
force path with its existing reconstructed state; contact-point floor velocity
is adapted from 00643a70. Donor class layouts, state transitions, goal update,
floor scaling and direct byte identity remain unproven.

With the force adaptation, 30 Hz internal Stepped updates no longer launch the
character. The prior 60 Hz internal notification shim was removed; physics
still runs at 60 Hz in the harness. At 033913505c, grounded idle, movement,
climb, exit, Lua events, noncollidable and idle controls, live controls and
combined play pass. On an authored moving floor, floor moves 3.993 studs and
the character 3.319; stationary control stays put. A low-friction floor moves
the character 2.411 studs versus 15.999 on normal friction. Original heartbeat
and anchor comparisons, P0, spawn, scripts, lifetime, assets, values and a
240-frame supplied-place run pass. Receipts are p5-nativeforce-*-033913505c.
Original character/moving-floor comparison, recovered frame loop, native state
ABI and later milestones remain open; do not claim full P5 parity.

## P5 checkpoint: original humanoid comparisons (c3f6475891)

A shared authored character fixture now runs in the original client and the
rebuild. Four wall-time observations are compared with 30/60/90/120 rebuilt
fixed frames; two moving memory copies each for torso and head agree, with the
head staying 1.5 studs above the torso. Scripted walking passes bounded 0.8
stud horizontal / 0.16 vertical tolerances; observed maxima are 0.533 and
0.098 studs. Two moving-platform runs also pass those bounds: floor motion
matches within 0.001 studs at sampled times, while rebuilt rider trails the
floor about 0.26-0.43 studs farther than original. Receipts:
p5-original-walk-c3f6475891 and p5-original-platform-*-c3f6475891. Earlier
independent walk repeats are p5-humanoid-original-*-b5f903a918.

Original and rebuilt joint construction differs, original samples are real-time
rather than direct single stepping, and original process closure required
forced termination. These tests do not establish complete humanoid, input or
physics parity. The rider lag remains a real discrepancy. Original 00644000
has recovered floor-sensor source with torso-bottom and corner rays; compare it
with the current single-center donor sensor next. P5 and later milestones stay
open.

## P5 checkpoint: original floor sensor adaptation (24be78e1e2)

Adapted recovered 00644000 floor sensing to the donor ABI: a downward ray
starts at the torso bottom, then tries its four corners, with leg-length and
existing-floor distance rules from the original. An authored edge fixture
remains standing with its center outside the floor but a torso corner over it;
a control with every corner outside falls. Floor sensing, force/friction,
controller, climbing, spawn and combined play checks pass at 24be78e1e2.
Receipts: p5-floor-sensor-24be-*.

Original/rebuilt walk and moving-floor comparisons pass their existing bounded
tolerances. In one moving-floor run the rebuilt rider lags 0.13-0.30 studs
farther than the original, still a discrepancy; this alone does not prove a
causal improvement over earlier samples. Original joint construction and
wall-time sampling differ, and original closure required forced termination.
This is an adaptation, not byte-identical integration; native loop, state ABI,
full humanoid parity, P5 acceptance and later milestones remain open.

## P5 native frame-loop investigation

Recovered source locates RunService::runProc at 00555190, its DataModel lock
and step at 00554880, the gated outer step at 00578e50, and the run-mode,
Workspace/idle and event dispatch at 00578ca0. The original has deadline,
view wait, scheduler-item and interruptible wait behavior absent from the
current reconstructed loop. See p5-native-frame-loop-trace.md. No native
frame-loop integration or full P5 acceptance is claimed.

## P5 checkpoint: 30 Hz simulation batching (f4fa486adf)

The player harness now accumulates render elapsed time and calls DataModel::step
once per 1/30-second play tick, matching the original outer frame period, then
emits Stepped and Heartbeat. Zero elapsed frames no longer invent 1/60 second
in the live loop. A timing control verifies zero/half tick cause no step, one
tick advances 1/30 second, and a two-tick input advances twice. Edit-mode
positive-time behavior remains the existing harness behavior.

At f4fa486adf, timing, floor edge, force, controller, climbing, spawn, combined
play and P0 controls pass. Original walk, moving floor, Stepped and Heartbeat
bounded comparisons also pass. Receipts: p5-batched-f4fa-*; original process
closure still required forced termination. Rider lag and differing joint
construction remain. This change batches donor physics but does not integrate
the native scheduler, world stages, view synchronization or run-mode logic;
see p5-native-frame-loop-trace.md. P5 and later milestones remain open.

## P5 checkpoint: scaled standing altitude (11f424ae13)

Adapted original 00643360: desired standing height is floor-contact Y plus
half torso grid height plus left-leg grid height, or right-leg height if left
is absent. The 0.5 factor comes from executable float 0x819bac. The prior
constant 3 only handled standard dimensions. An authored 4-stud-leg walking
character matches original within existing bounded comparisons: rebuilt torso
settles at 5.000, original around 4.905; standard walk and moving-floor
comparisons also pass. Right-leg fallback is source-derived but not separately
exercised. Normal timing, floor, force, controller, climb, spawn, combined and
P0 checks pass. Receipts: p5-altitude-11f4-*.

A separate diagnostic starting the tall actor touching the floor reproduced a
locked torso and access-violation shutdown twice (0xc0000005), after mesh
cleanup. See p5-altitude-11f4-initial-contact/; fixture and receipt saved.
Cause and original behavior are unverified. Keep this failure open alongside
native scheduler, physics/state parity and later roadmap milestones.

## P5 checkpoint: joint-service startup and contact teardown (109f9894fe)

Original DataModel initializer 0057a9f0 creates JointsService. The rebuilt
startup omitted it, so AutoDestroy events had no listener. Debugging the
initial-contact failure showed a freed primitive (freed-heap fill) reached from
EdgeList::removeEdge during JointStage teardown. Startup now attaches the
existing JointsService and its AutoJoin/AutoDestroy listeners. The donor
NonFactoryProduct uses a null class-name template; this non-factory service
is parented directly and returns the null Name rather than dereferencing it.
This adapts the original startup behavior, not the original 2008 service ABI.

The previously crashing initial-contact fixture now exits cleanly twice; mesh
cleanup and snapshots pass. P0, P4 asset cases, timing, floor, force, controller,
climb, spawn and combined play pass. Original tall/standard walk and moving
floor bounded comparisons pass at 109f9894fe. Receipts: p5-joints-109f-*.
Initial-contact joint behavior itself has not been compared against original;
full scheduler, joint lifecycle, humanoid parity and P5 remain open.

## P5 checkpoint: original movement heading (68be7ec06b)

Adapted original 00666410 running goal: nonzero walk direction sets target
heading, shortest wrapped difference from torso heading is multiplied by 8,
then passed to the recovered running-force path. Previously the rebuilt torso
kept facing -Z while walking sideways. A script records the torso look vector
as a four-stud marker; original and rebuild now match for both left and right
walks at four observed times. Maximum marker-component difference in these
runs was 0.0014 studs. Before adaptation the rightward rebuilt marker stayed at
(177.25, 67.75), while original turned to roughly (181.25, 71.75) in X/Z.

At 68be7ec06b, timing, joint contact, floor, force, controller, climbing,
spawn, combined play and P0 controls pass; original tall and moving-floor
comparisons also pass. Receipts: p5-turn-68be-*. Original sampling is wall time
within 35 ms of fixed-step targets; joint construction differs and the original
process required forced termination. This is a donor-ABI adaptation; reverse,
turning-in-place, ramps, animation and full state/scheduler parity remain open.

## P5 checkpoint: original jump discrepancy (6052d0d73c)

Two authored fixtures now measure original and rebuilt torso/head positions
at eleven times over four seconds, using original read-only process-memory
copies and fixed-step rebuilt snapshots. These are observations, not parity
passes: original wall-time samples may differ by up to 35 ms; joint construction
also differs and original closure required forced termination.

At 6052d0d73c, a jump requested after one second gave original/rebuilt torso
Y of 10.38/9.07 at 1.25 s and 7.18/4.96 at 1.5 s. A jump requested after
0.2 s showed original/rebuilt Y 3.01/8.60 at 0.75 s: the rebuilt actor jumped
after landing while original did not in this run. Receipts:
p5-jump-6052-grounded/ and p5-jump-6052-early/.

Original 00667a40 uses a force based on a 50 velocity target and gain 5000,
with opposing floor force. A first donor-ABI adaptation produced an extra
landing rebound and worse sampled agreement, so it was reverted. Next trace
native jump/freefall transitions, contact solver and when the jump request is
cleared; implement and retest rather than claiming parity from the force alone.
P5 and all later unfinished milestones remain open.

## P5 checkpoint: transient controls on state construction (a05a67263b)

Original HumanoidState constructor 00643e00 calls the setters at 005dc270
(Jump) and 005dc230 (Strafe) with false. The donor state constructor now
adapts those resets. An authored airborne fixture records Jump as a marker:
original and rebuilt both retain it at 0.25/0.5 s and clear it by 0.75 s
through 2 s. This observes Jump; Strafe reset is source-derived but not yet
independently compared. The observer uses original wall-time samples within
35 ms of fixed-step targets and forced original termination.

This does not resolve jump physics or near-floor buffering: the early request
still yields a rebuilt jump absent from the sampled original. A high fall also
rebounds much higher in the rebuild: at 1 s original/rebuilt torso Y was about
2.96/17.31. Investigate original contact and state-transition behavior next.
P0, timing, joint contact, floor, force, controller, climbing, spawn, combined
play and original right-turn checks pass. Receipts: p5-state-a05a-*; P5 remains
open.

## P5 checkpoint: Novetus 2008M Animate and motor transforms (e49dd2e24c)

The user-supplied Novetus 2008M content contains character.rbxm and an Animate
script. Its character model matches the previously staged model by SHA-256;
its Animate, Sound and Health scripts differ, so their provenance and original
2008-client equivalence are not assumed. Novetus also supplies Play_Solo.lua,
a custom launcher script using CreateLocalPlayer, RunService:run and
LoadCharacter. The player already loads the character and those four assets
through its adapted Player::loadCharacter path.

Running now emits speed changes using the 00666b20/00643330 half/double
threshold, enabling the supplied Animate script. The donor clump graph also
needs motor-angle invalidation to propagate moving joints to part transforms.
With actual Novetus 2008M content, idle and disabled-Animate controls remain
still; walking changes desired and actual hip angles and moves the right leg
relative to the torso by 0.882 studs across the measured window. Movement stops
when input stops. The control edits only a local temporary copy of the asset.
A local animated preview from separate fixed-frame runs is in
p5-novetus-e49d-walk-preview/walk.gif; user assets and images remain local.

Full Novetus content initially crashed when swoosh.wav was available. Tracing
identified the empty RaiseRange::removeIndex stub during Heartbeat listener
removal. Its replacement follows target 00420740 range updates, including
nested dispatch; self/next/previous/nested removal controls and the full content
run now pass. Sound startup is covered; audible output is not verified.

At e49dd2e24c, Novetus animation controls, P0, P4 asset cases, timing, joint,
floor, force, controller, climbing, spawn and combined play pass. Original
right-turn and moving-floor bounded comparisons pass. Receipts:
p5-novetus-e49d-*. Original-client animation, all poses, audio playback,
jump physics, scheduler and full P5 remain open.

At ce9c96c76b, the recovered player enables Ogre stencil-modulative shadows,
as used by the 2008 renderer. Recovered geometry supplies shadow volumes; this
is an integration adaptation, not proof of original shadow-mesh fidelity.
Block, sphere and cylinder controls cast shadows; moving and removing the part
updates them. P3 lifetime/cache, Novetus animation and a 606-model supplied
place pass. Receipts: ce9c96c-shadow, ce9c96c-shadow-p3,
ce9c96c-shadow-animation and ce9c96c-shadow-supplied. Meshes exceeding 32767
vertices do not cast stencil shadows; shadow distance is currently 300 studs.

## P5 checkpoint: bounce source and landing state (3dc292489e)

Original 00649320 is attributed to rbxgs Constants::getElasticMultiplier.
Its thresholds and multipliers, read from the pinned original executable,
match the donor implementation: .05/.28, .26/.42, .51/.57, .76/.8, else 1.
Existing original block observations independently show a bounce from y=-4.009
at 0.5s to y=9.164 at 0.797s. Preserve bouncing; do not force zero restitution.
The 3dc292489e probe and receipt p5-elasticity-source-322f7a5c31 pin the bytes
and prior observation. This does not establish character landing parity.

Correction: source analog names in factory 00643660 were misleading. RTTI
identifies state 5 as Landed (constructor 00643550, timer 0.45 seconds),
and state 6 as Running (constructor 00666ac0, timer 0.25 seconds). The
donor Freefall onStep switches directly to Running.


## P5 checkpoint: Landed identity and transitions (df7973e8c7)

Original RTTI and 00644670 predicate jump table identify state 3 Freefall,
state 5 Landed, state 6 Running. Transition table 0084a92c maps Freefall +
floor to Landed, Landed + no floor back to Freefall, and Landed + expired
timer to Running. The state-5 constructor stores 0.45 seconds; common update
006451c0 subtracts step time. The prior checkpoint's state-6 identification
was wrong. Static receipt: p5-landed-source-verify/receipt.json.

A donor-ABI trial inserted a separate timed Landed state; observed high-fall
and early-jump trajectories remained unchanged, while walking passed. Trial
was reverted: extra donor Running warmup and transition ordering need tracing
before a correct integration. Observational receipts p5-landed-probe-* cover
the trial executable only; they are not exact committed-source evidence.
Original bouncing remains intentional. Restored player build and P3 lifetime,
selftest and cache checks pass at df7973e8c7. P5 remains open.

## P5 checkpoint: limb CanCollide during high fall (80641d326d)

Original descriptor 007f4870 binds getter 00598d20 and setter 0059dd80.
The getter combines the drag byte and the inverse of Primitive+0xab; setter
inverts CanCollide before invoking 005e75e0. Thus 0xab is connected to the
public collision property, not merely a ray filter. Original state update
006451c0 calls 00643bc0/00643c20 with values from the state's vtable.
Freefall, Landed and Running all select the same limb flags in their vtables.

A new fixture records whether both legs report CanCollide. At 0.25, 0.5,
0.75 and 1.0 seconds the original marker says false while the rebuilt marker
says true; at 1.5 and 2 seconds both report false. Original timing is wall
clock +/-35 ms and the clients have different startup/joint construction.
Receipt: p5-limb-final-comparison. This is a measured mismatch, not an
assertion that limb collision alone causes the character bounce discrepancy.

Trials to apply state flags on donor state swaps and each donor state step did
not alter the early samples, so they were reverted. Trace when the rebuilt
Humanoid receives its world and first Stepped event before modifying the
lifecycle. The clean player was rebuilt at 80641d326d; original bouncing is
preserved. P5 remains open.

## P5 checkpoint: original limb collision timing (6ab57daa3c)

The donor now applies original state limb collision flags after each Humanoid
step for Freefall, Running and Climbing. In six high-fall samples, original and
rebuilt legs both report CanCollide=false (previously rebuilt was true for the
first four). The target's state virtuals and 006451c0 drive the same flags;
this is a donor-ABI adaptation, not full state-machine integration.

Important build correction: `roc rebuild 2008-06 player` reuses existing
dependency libraries. Earlier trial edits to rbxgs-client.json and engine glue
were not compiled into the player; their negative results are invalid. Rebuild
`roc rebuild 2008-06 module rbxgs-app --no-notify` before the player whenever
engine overlay or glue changes, then verify the executable and receipts. Both
modules were rebuilt before this change's tests.

At 6ab57daa3c, original leg-property comparison, original walking, climbing,
P3 lifetime/self/cache and Novetus animation pass. Original high-fall
comparison remains observational: maximum sampled vertical difference is
14.29 studs, so collision flags alone did not resolve rebound. Receipts:
p5-limb-verified-{original,walk,climb,p3,animation,airborne}. Original process
closure required forced termination. Native state machine, start-up, character
fall and remaining P5 gates remain open.

## P5 checkpoint: player dependency refresh (497e8fafda)

`roc rebuild 2008-06 player` and `module player` now refresh six maintained
engine/render dependencies in declared order, stop on failed dependency tests,
and only then link the player. Image and material tests use the staged player
SurfacesStrip when ROC_TEXTURE_STRIP is unset; an explicit override wins.
Vendor libraries outside this list remain cached. This replaces the manual
rbxgs-app rebuild instruction above; staging external Content is still needed.

At 497e8fafda, the normal command rebuilt and tested all six dependencies
and the player successfully. Thirteen build-tool tests and P3 lifetime,
selftest and cache checks passed. Receipts: p5-refresh-497e and
p5-refresh-497e-p3. Full rebuild is slower than the prior stale-library path.
This improves build reliability; character physics and P5 remain open.

## P5 checkpoint: original Landed transition (86025f59f9)

Adapted original state table: Freefall and Climbing enter Landed on floor;
Landed returns to Freefall without floor or to Running after 0.45 seconds.
The donor-ABI Landed uses recovered Running force/goal behavior. Its Running
handoff carries floor and movement goals forward to avoid a donor-frame pause;
that handoff is an adaptation, not an original ABI claim.

After rebuilding the actual engine and player, the early-jump fixture now
agrees with original within 0.243 studs across eleven samples (previous
maximum about 5.60); the observer enforces a 0.6-stud bound. Original wall
samples are within 35 ms of fixed-step targets; joint construction differs,
and original termination was forced. Walking, climbing, spawn/controller,
Novetus animation, P3 lifetime/cache, combined play, live input and reopening
pass. Receipts: p5-landed-verified-*. Grounded jump and high fall remain
observational: maximum differences 2.22 and 14.29 studs respectively. Do not
remove bounce; trace original force/contact/state timing next. P5 remains open.

## P5 checkpoint: recovered jump force (de264cd8ec)

00667a40's server-matched source, with original constants 0084ced0=5000 and
0084ced4=50, applies a velocity-target force limited by the smaller torso and
floor branch masses, subtracts existing branch force, and reacts on the floor.
The donor Jumping state now adapts this behavior and the original 0.5-second
timeout instead of applying a one-step mass*50/dt impulse. Body/state layouts
and floor ownership remain donor adaptations; no byte-identical runtime claim.
The engine dependency and player were explicitly rebuilt for this revision.

Early-jump comparison remains within 0.162 studs across eleven samples;
controller, combined play/reopen/live input, Novetus animation and P3
lifetime/cache pass. In grounded-jump observation, original/rebuilt torso Y
at 1.5 seconds was 7.18/8.34 (previous rebuild 4.96), but at 2 seconds was
2.97/5.56: an extra rebound. Maximum sampled difference 2.59 studs. Original
wall samples are within 35 ms; joint construction differs and original needed
forced termination. Receipts p5-jump-force-verified-*. This source-aligned
change does not close jump/contact parity; investigate landing and floor force
ordering next. High-fall discrepancy and remaining P5 gates remain open.

## P5 checkpoint: recovered horizontal air control (6cc844c0df)

Original 00667510 updates desired velocity through 00643b60 (walk direction
scaled by 16). Original 006675d0 applies gain 1250, acceleration limits from
00666350/006663a0, branch mass, and explicitly zeroes vertical force. The
donor Flying path previously supplied only yaw torque. Its desired velocity
and horizontal force now adapt those recovered behaviors. Engine and player
were rebuilt; original state layouts and timing remain donor adaptations.

A high-fall walking fixture passes the bounded horizontal check at 0.5 s
(error 0.533 studs, bound 0.8). Later observations remain mismatched: about
1.60 studs horizontal error at 2 s, alongside the known vertical rebound.
The air observer explicitly treats later samples and vertical motion as
observations, not parity passes. Ground walking, early jump (maximum 0.162
studs), P3 lifetime/cache and Novetus animation pass at 6cc844c0df. Receipts:
p5-air-verified, p5-air-verified-{walk,early,p3,animation}. Original uses wall
samples within 35 ms, different joint construction, and forced termination.
Full air/landing physics, native frame/state integration and P5 remain open.

## P5 checkpoint: initialize replacement landing state (40cbe42fa2)

Original Humanoid callback 005dc740 reaches 00645450 (direct call at
005dc782). That wrapper runs state update 006451c0, transition 006453a0,
and the selected state's goal update. Recovered 006453a0 destroys the old
state, constructs the replacement and immediately updates it before goal
update. Donor transitions left the replacement's floor unset until next tick.
Landed now refreshes floor and goals before its first force. This constructor
initialization adapts the native ordering; full state lifetime/ABI integration
remains open, including donor construction-before-destruction ordering.

At 40cbe42fa2, maximum observed high-fall torso error fell from 14.29 to
1.65 studs and grounded-jump error from 2.59 to 1.16. Early-jump bounded
comparison passes at maximum 0.096 studs. Original walking, climbing, Novetus
animation and P3 lifetime/self/cache pass. Receipts:
p5-land-prime-verified-{airborne,grounded,early,walk,climb,animation,p3}.
Original samples are wall time within 35 ms of fixed-step targets, joint
construction differs and original termination was forced. These improvements
do not close physics parity or P5; preserve original bouncing and investigate
remaining state/timing and contact differences next.

## P5 checkpoint: timing sensitivity and tandem ownership (be12214a62)

Claude owns P6 in roc-p6; Codex continues P5 here under TANDEM.md. Both
original-client runs below held and released the shared desktop lock; only
observer-owned original processes were closed/terminated.

The airborne observer now additionally samples rebuilt frames 13,14,16,17
around its first comparison, retaining the original exact-time delta and
existing early-jump gate. This diagnoses sensitivity without claiming original
simulation-time access. At the same executable, one run had maximum exact
sample error 0.07493 studs; a repeat had 3.14027 at the impact sample (0.5s).
Both first samples agreed within 0.01005 studs; later settled samples within
0.075. Therefore previous max-error comparisons can change with original
wall-clock phase even without code changes. Do not tune physics to one such
maximum. Next add an original Lua simulation-time marker and align observations
by that clock. Receipts: p5-tandem-fall-timing and its -repeat. These are
observational; fixed-step/contact parity and P5 remain open.

## P5 checkpoint: simulation-time-aligned high fall (46537cf31d)

New authored p5-simtime-fall.rbxl freezes thirteen Stepped callback records
in anchored, noncolliding marker Parts. Each marker contains the simulation
timestamp and torso height from the same callback; both clients run identical
Lua. The observer reads the original markers through read-only process memory,
requires at least two agreeing updated copies, and compares against rebuilt
marker snapshots. All recorded timestamps must agree within 0.0001 seconds;
the vertical gate is 0.1 studs. Original markers freeze after sampling, so
foreground-launch wall-time phase no longer selects the measured pose.

Two runs at 46537cf31d reproduce all thirteen samples exactly. Maximum original
versus rebuilt height difference is 0.07494 studs; before landing it remains
under 0.022. Thus earlier multi-stud maxima on this high fall were wall-clock
sampling artifacts after the landing initialization fix. Receipts:
p5-simtime-verified and p5-simtime-verified-repeat. This closes the bounded
high-fall comparison for this fixture, not all character/contact physics.
Original joint construction still differs and closure required forced
termination of the observer-owned process. Desktop locks released in TANDEM.
Next apply frozen simulation-time sampling to grounded jump and air movement,
then continue native frame/state lifetime integration and other P5 gates.

## P5 checkpoint: simulation-time jump and air samples (8599e32205)

Frozen callback sampling now supports two additional authored fixtures. Jump
records torso Y around the scripted one-second request; air records torso X
through a 30-stud fall with WalkDirection set after 0.2 seconds. Thirteen
original/rebuilt timestamps agree within 0.0001 seconds for each run; at least
two updated original memory copies agree. Air checks X within 0.01 studs
through one second, then records later positions without claiming parity.
Receipt fields retain delta_y as the scalar difference; measured_coordinate
identifies X versus Y explicitly.

At 8599e32205, air X agrees within 0.000001 studs through one second, then
lags original by about 0.532 at 1.5 seconds and 0.530 thereafter. Jump differs
by 1.415 at 1.1 seconds, 0.126 at 1.3, and -1.807 at 1.6, with original
minus rebuilt velocity differing by roughly -6.44 studs/s over that interval.
This confirms a real jump trajectory difference after removing wall-time
phase; its cause is not established. Check original and donor force/substep
integration and state handoff next. Receipts: p5-simtime-jump-verified and
p5-simtime-air-verified. Original joint construction still differs, closure
needed forced termination, and desktop locks were released in TANDEM. P5
and complete jump/air parity remain open.

## P5 checkpoint: initialize replacement Jumping state (cdc32458ec)

The frozen velocity fixture established a one-tick takeoff delay: at 1.0667s
original torso velocity was 48.424 while rebuilt was still near zero; at 1.1s
rebuilt reached 48.328, producing the apparent 6.44-stud/s flight difference.
This was not evidence to change jump gain or gravity. Jumping now refreshes
its floor before first force, adapting the same 006453a0 immediate replacement
update used for Landed. The engine and player were explicitly rebuilt.

At cdc32458ec, simulation timestamps align and the committed gates pass:
maximum sampled jump-position difference 0.1035 studs (bound 0.12); in-flight
velocity difference 0.0961 studs/s (bound 0.12 after 1.05s). Pre-jump original
velocity remains about -1 versus rebuilt near zero. P3 lifetime/cache and
Novetus animation pass. Receipts: p5-jump-prime-verified-{position,velocity,p3,
animation}. The Jump flag probe sampled zeros in both clients; it does not
establish request timing or callback order independently.

Spawn movement regression had an old 10..14 final-Z range from before recovered
air control. Holding forward at frames 12..71 now moves 16.0016 studs, consistent
with original 16-stud/s goals. At 51065029a9 its gate checks displacement against
idle baseline at 16 +/-0.15 studs; idle remains separately bounded. Receipt:
p5-jump-prime-spawn-current. Original joint construction and callback/state
lifetime still differ. This closes bounded jump position/flight velocity for
this fixture, not complete humanoid parity or P5. Desktop locks released.

## P5 checkpoint: initialize replacement air goal (5d94151e0d)

Original transition wrapper 00645450 calls replacement update and goal update
before the next force; Flying/Freefall goal update 00667510 obtains walk
velocity through 00643b60. Donor Flying initialized desired velocity to zero
until a later step. Its constructor now adapts the immediate goal initialization
from Humanoid walk direction. No class layout changed; engine/player rebuilt.

At 5d94151e0d, frozen air X samples remain within 0.000001 studs through one
second and improve from 0.5304 to 0.0031 studs error at three/four seconds.
The temporary 0.532/0.531 offset at 1.5/2s remains. The gate now covers early
and late intervals at 0.01 studs and keeps that intermediate gap observational.
Frozen jump, original walking, P3 lifetime/cache, spawn and Novetus animation
pass. Receipts: p5-air-prime-verified and its -jump, -walk, -p3, -spawn,
-animation siblings. Desktop lock released in TANDEM.

Full state lifetime/order remains donor-based. Original RunningNoPhysics
constructor 00667370 and StrafingNoPhysics 00667210 use base 0066f070; these
states are absent from the donor path. Trace their entry/exit and common
velocity implementation before deciding whether they explain the remaining
landing offset. Do not claim complete air/state parity or P5 from these gates.

## P5 checkpoint: native active-state and job registration (590c4c73f4)

Observer now audits live original states after frozen sampling. The pinned
binary's RTTI identifies twelve primary state vtables. Native Humanoid callback
005dc740 uses listener offset 0x1a4 and state-holder offset 0x7c, proving owner
base+0x220. Each candidate must be referenced back from that owner's active
state holder; stale heap vtables alone are not accepted.

At 590c4c73f4 the settled fall has one active RunningNoPhysics state
(vtable 0084ce10). The moving fixture has one active Dead state (0084cce0)
after leaving the bounded floor by the later audit. Frozen comparison gates
still pass. Receipts: p5-native-state-all-fall and p5-native-state-all-air.
Initial limited coverage failed the moving audit; expanding to all twelve
RTTI-verified state types resolved it without weakening owner validation.

Recovered MovingNoPhysicsBase constructor 0066f070 sets Primitive flag aa,
holds torso/control-scope ownership and registers its SimJob. Direct calls
0066f267 ->005e93b0 (stage type 6 lookup) and 0066f26e ->0064d1e0 ->0064d0f0
connect that registration. Existing source for 0064d0f0 pushes the job into a
stage list and stores its iterator; source analog Edge names are provisional.
Moving update 0066f2c0 sets frame and velocity directly, including signed
vertical correction; this explains why matching force-only movement does not
prove native RunningNoPhysics behavior. Donor SimJobStage only manages
Mechanisms and lacks this registration interface. Next integrate the existing
job source with removal/stepping ownership verified, then native state entry
and exit. Do not substitute another guessed state before that edge is proven.
No shared ABI edits made. Desktop locks released; P5 remains open.

## P5 checkpoint: SimJob registration/removal contract (ba2e1b7dfe)

Live RunningNoPhysics now verifies its secondary SimJob at state+0xa0,
secondary vtable 0084cdf8, saved iterator owner/node at job+0x1c/+0x20,
node payload back to the job, and both reciprocal ring links. Owner active-state
validation remains required. Receipt: p5-simjob-links-verified. Frozen fall
gate still passes. This proves a registered live job, not merely matching
vtable bytes in stale memory.

Dispatch correction: secondary virtual entries at 0084cdf8 are destructor
00667400 and two copies of thunk 00667160. The latter adjusts this by -0xa0
and reaches 0066eaa0, returning the torso assembly via 005d90a0/005e7570;
these are identity queries, not movement callbacks. Actual motion is the state
goal-update virtual 006672b0 ->0066f2c0. Do not invent a virtual step interface
on SimJob. Native stage registration is part of assembly/simulation ownership.

Removal: scalar destructor 00667410 ->MovingNoPhysicsBase destructor 0066ee10
->release 0066ed50 clears torso flag aa with 005e8140, disconnects ancestry,
finds stage through 005e93b0, removes job through 0064d1f0 ->0064d180,
releases control-scope ownership through 005e9040 and resets torso shared_ptr.
The stage removal first updates job grouping via 005e53a0, erases saved list
iterator, and clears assembly+0x40 through job's assembly query. Next resolve
005e53a0's vector element/assembly contract and stage ownership before adding
this native dependency; donor SimJobStage is not ABI-compatible. No shared ABI
changes made. Desktop released; full P5 remains open.

## P5 checkpoint: tracker collection and linked lifetime gate (fc6d0dd4ce)

005e53a0 is not an assembly-vector transfer: its elements are tracker observers
whose first field is their tracked owner. Recovered source removes each tracker
from its old owner's vector, then appends/reassigns it to the destination (or
clears it). Existing donor MechanismTracker::setMechanism/transferTrackers in
Mechanism.cpp implement this contract and already serve stage removal. This
resolves the opaque collection role in SimJob constructor 005e50f0; it does
not establish an original C++ declaration from the analog names alone.

New --p5-job-tracker-check exercises three trackers across two owners,
transfer followed by old-owner deletion, individual detach, then transfer to
null and last-owner deletion. It runs in the linked player and passes at
fc6d0dd4ce; map selects transferTrackers from linked:Mechanism.obj. Local COFF
comparison finds no byte-identical original address for that donor body, so
no native byte credit is claimed. P3 lifetime/self/cache regressions pass.
Receipts: p5-job-tracker-verified and p5-job-tracker-verified-p3.

Native single-assembly SimJob wrapper constructor 005e51e0 extends the 36-byte
base by one assembly pointer at +0x24; both identity slots return that pointer
through 0074eed0. Donor Mechanism instead stores an assembly set. Next split
base tracker/list ownership from donor mechanism grouping, preserving this
linked lifecycle gate and verified native registration/removal contracts.
Log shared layout changes in TANDEM before implementation. Full native job
and no-physics state integration, and P5, remain open.

## P5 checkpoint: shared SimJob ownership base (9919e46fd5)

The engine overlay now extracts SimJob's tracker vector and list iterator from
donor Mechanism grouping. SimJob has the evidenced destructor/assembly-identity
slots and compiles to 36 bytes with the historical compiler; its two identity
queries stay separate from movement dispatch. Mechanism derives from this base
while retaining the donor assembly set and its existing stage iterator. This is
an intermediate ownership integration, not the native single-assembly wrapper
or native job-stage registration. Native and donor grouping remain distinct.

MechanismTracker now accepts SimJob owners through setJob/getJob, while existing
setMechanism/getMechanism callers retain their source API. getMechanism returns
null for a non-mechanism job; such jobs are not yet registered in active player
stage traversal. Tests cover transfer between mechanism and non-mechanism owners,
old-owner destruction, individual detach and final-owner destruction. Stage
traversal must use the generic API when native jobs are added next.

Engine/player rebuilt successfully. At 9919e46fd5, cross-job lifetime/base size,
P3 lifetime/self/cache, spawn, original frozen fall/jump and Novetus animation
all pass. Receipts: p5-simjob-base-verified plus -p3, -spawn, -fall, -jump,
-animation. Layout change and rebuild completion logged in TANDEM; header users
must merge the matching source before relinking. No server native-byte credit
claimed. Next integrate stage registration/removal using this shared base and
existing recovered source; RunningNoPhysics and full P5 remain open.

## P5 checkpoint: shared stage registration (c241e32733)

SimJobStage now registers donor mechanisms in the shared SimJob list, alongside
its existing mechanism-only grouping list. Generic insertJob/removeJob use the
recovered 0064d0f0/0064d180 list-and-tracker contract: store the iterator, transfer
observers to the next job with 004cb480 wraparound, erase the saved iterator,
and detach all observers when removing the final job. Jobs remain caller-owned.
The donor mechanism reporter restarts at its own first mechanism if its tracker
was transferred to a non-mechanism job; it does not dereference a null grouping.

This integrates the list/observer portion, not the full native assembly binding:
original insertion/removal also writes/clears assembly+0x40. Donor Assembly still
has its mechanism-group pointer. That association, the 40-byte single-assembly
wrapper (005e51e0), and native RunningNoPhysics remain next. Before enabling the
state, verify flag-aa release versus assembly re-entry ordering; do not blindly
overwrite donor grouping with the native job pointer.

At c241e32733 engine/player build and smoke tests pass with zero compile errors.
Linked stage insert/remove providers come from linked:SimJobStage.obj. The
ownership gate covers three non-mechanism jobs, saved iterator payloads, middle
removal, tail wraparound, final detach and caller-owned destruction. P3 lifetime,
self/cache and spawn/movement regressions pass. Original frozen fall/jump checks
pass (maximum Y errors about .07494/.10348). Novetus animation checked separately.
Receipts: p5-simjob-stage-verified (including build-receipt.json), -p3, -spawn,
-fall, -jump and -animation. No original declaration or native byte identity is
claimed for the adapted stage. P5 remains open; Claude retains P6 ownership.

## P5 checkpoint: active single-assembly jobs (e61d0b6cbb)

Original 0064d200 allocates 40 bytes and calls 005e51e0; RTTI at 0083f73c
identifies AssemblySimJob deriving from SimJob. The active stage now uses this
single-assembly ownership model instead of donor Mechanism groups. Local class
AssemblyJob has the evidenced pointer after the 36-byte base. SimJobStage's one
job list compiles to 44 bytes. insert/remove bind/clear the assembly owner,
transfer observers, and erase the saved iterator. Assembly add/remove own and
delete the ordinary wrapper in original order. Legacy Mechanism remains only
for source compatibility and ownership diagnostics, outside stage traversal.

Assembly's owner API and existing reporter now accept generic SimJob owners;
packet-budget resume/ignore tests visit non-mechanism jobs. This changes the
existing donor network API, not its protocol fidelity. P7 remains open. Stage
numbering and Assembly's other fields still follow the donor pipeline: matching
sizes alone do not establish native ABI equivalence or server byte credit.

Engine/player build passes with zero compile errors. P3 lifetime/self/cache,
spawn/movement, real actor AssemblyJob identity/back-pointer, tracker lifetime,
reporter resume/ignore, frozen original fall/jump and Novetus animation pass.
Receipts: p5-assembly-job-verified (build-receipt.json includes RTTI/provider/source
hashes), -p3, -spawn, -fall, -jump-retry and -animation. First jump observation
failed foreground acquisition before play; retry passed without code changes.
The original observer now verifies RunningNoPhysics's torso -> Primitive+0x5c
-> object+0x24 -> assembly+0x40 points back to its registered state job, with
anchor flags [0,0,1]. Original fall/jump Y bounds remain .1/.12 respectively.

Next: recover anchor-joint pipeline before enabling native MovingNoPhysicsBase.
005e8140 routes through 005e94a0/005e94e0 to ClumpStage's 0064cc40/0064ccf0.
The existing matched source is tools/openrbx/Client/App/v8world/ClumpStage2.cpp:
insert AnchorJoint before removing FreeJoint, and reverse on release. Its
TreeStage/Assembly2 dependencies differ from the active donor pipeline; inspect
and integrate those ownership edges rather than force world->update inside a
state constructor. Local original observation confirms the clump and root
assembly can be the same object, unlike donor's separate Clump/Assembly types.
RunningNoPhysics, native frame/scheduler and full P5 remain open. P6 stays Claude's.

## Updated priority: P5 stop line closed; merge P6 next (730f303138)

Colin replaced the full-roadmap ordering: close landing/high-fall at documented
bounds, stop donor physics tuning, merge P5/P6, recover shared native headers,
then swap exact sources class by class with both gates green. Real native P6
comes before P9/P10; P7/P8 are deferred. This supersedes the earlier plan to keep
working on RunningNoPhysics before merging.

P5 passes the agreed stop line on engine revision 730f303138. High-fall maximum
Y error is .07493234 (< .10); landing/jump maximum is .10347796 (< .12).
Original anchor-cycle plateau differs by 0.00000004 and final contact by
0.00008751 (< .015/.01). Combined real input, collision, one Lua trigger,
release/reanchor/release, reopen and clean shutdown pass. P3 lifetime/self/cache,
spawn, animation, tracker ownership and all eight ground-joint flag combinations
pass. Builder tests: 48 passed. Evidence: work/2008-06/p5-stopline-gate/receipt.json
and its hashed receipts. Stop physics tuning here.

The recovered-source tree/assembly/sleep pipeline now uses AnchorJoint/FreeJoint;
the old Anchor registry is outside the active build. Cached incompatible
TreeStage/SleepStage providers were excluded in favor of source compiled against
the active ABI. Excluded source objects are now pruned from archives. A copied
sleep-removal stub initially erased velocity on reanchor; ordinary assembly
removal now preserves it, matching the independent original oracle. Diagnostic
failure hashes remain in p5-native-world-debug/failure-receipt.json.

Gate clarification: collision arrival moved from frame 58 to 40 under the new
contact path. Combined acceptance checks one trigger while W is held and the
unchanged 8/10-frame script waits, rather than an unverified arrival timestamp.
Anchor's first-fall check permits wake-pending; the original comparator retains
its existing +/-3-frame/.75-stud window and stricter plateau/contact bounds.

New selection-based baseline: 2,935 relocation-normalized code matches among
13,865 known engine/player function bodies selected in the final PE. The counter
rechecks COFF bodies against mapped PE bytes; this excludes unrelated system
functions and does not prove data/ABI correctness, execution coverage, or raw PE
identity. Per-module rows: p5-stopline-build/selected-functions.json. Do not use
the mined total as integration progress.

Next merge claude/p6-startup-20261101 (d40f3ecd35) into this branch, rebuild the
combined client and run P6's scoped gates. Preserve the separate distinction:
Claude's MFC shell has a scoped gate pass; real mined CRobloxApp/CMainFrame still
need integration. Then establish one shared header owner at a time, beginning
with CRobloxDoc (152 bytes), CRobloxView (496), CMainFrame (1204) and Humanoid
states. runtime-classes.json provides size evidence, not complete field layouts.


## Merged client baseline and shared layout start (6f9be17cb5)

P6 merged at 49fffcf262. The client now stages this checkout's current P5
runtime and links its current engine libraries. The final scoped P6 gate passes
on executable SHA-256 6f7b6751f1857d2726b84831e809d41e78e7cc3ef573ba8ee4ef52f31e2b57ca:
ordinary launch/close twice, three clean 30-sample held-input runs, selection and
drag, edit/save/reopen, commands and original-client saved-file open control.
The drag observer now resolves the owned live CView bounds and checks foreground.
Earlier runs affected by manual input or stale click geometry are not passes.
Evidence: p6-merged-gate-final/receipt.json and evidence-manifest.json.

The same merged PE selects 2,997 relocation-normalized code matches among 14,344
known source bodies, with zero COFF-to-PE mismatches. This is selected code,
not runtime coverage, complete native layouts, data identity or raw PE identity.
Full per-module details: p6-merged-gate-final/selected-functions.json.
P5 remains PASS at the documented stop line; no physics changes since 730f303138.
Real native P6 remains OPEN: CRobloxApp/CMainFrame are still the scoped shell.

Shared layout evidence now reproduces original RTTI and independently verifies
runtime size records (shared-layouts/original-evidence.json). CRobloxDoc derives
through VerbBinder<CRobloxDoc, CDocument>. View also has VerbBinder plus
VerbContainer at 0x78 and three listener bases at 0xa0/0xa4/0xa8. CMainFrame has
a FillToolColor/BrickColor listener at 0xf0. HumanoidState has INamed and
HitTestFilter; MovingNoPhysicsBase adds SimJob at 0xa0. These original hierarchies
must replace the shell's simpler declarations only after member types are proven.

Codex owns new shared-header recovery; Claude keeps UI implementation ownership.
No active shared header/class swap yet. Next: resolve binder map semantics and
Doc members, then compile pinned size/offset probes. Both gates after each swap.
P7/P8 stay deferred; donor physics tuning stays stopped.


Shared header checkpoint 0254dea8e6: native Doc binding 00451a60 and command
routing 00451690 establish map<UINT, const Name*> storage. New inactive
native-headers/VerbBinder.h compiles with MSVC 21022. Four base/binder size
checks pass; Doc binder constructor 00451590 matches all 86 bytes after masking
relocations. Evidence: shared-layouts/binder-compile.json. No active class swap
or executable-count gain claimed. Next recover routing definitions and Doc
owned members before integration; P5/P6 remain on the unchanged passing binary.


## Shared Doc storage and exact binding checkpoint (30f5fbbd6b)

CRobloxDoc candidate now has complete 0x98 storage with no padding fields:
owned XML snapshot 0x74, vector<Verb*> 0x78, StandardVerbs* 0x90 and
CWorkspace* 0x94. Original run/stop and destruction independently identify
these ownership edges; auto_ptr is a supported owning-pointer codegen choice,
not a recovered original template spelling. All original Doc virtual override
positions are declared; their bodies still need recovery.

Pinned MSVC 21022 probe passes complete size, four member offsets and 46-slot
COFF vtable shape. Constructor 00451ac0 matches 124 bytes; bindExisting
00451a10 matches 78; bindOwned 00451a60 matches 91 (relocations masked).
Bodies use shared native fields. Binding compilation refined the initial UINT
map hypothesis to DWORD keys with UINT arguments, and recovered name-read
before map-update ordering. Binder constructor 00451590 remains exact, 86 bytes.
Evidence: shared-layouts/document-compile.json, binder-compile.json and updated
original-evidence.json, all pinned to 30f5fbbd6b and source hashes.

No active class swap yet. Passing merged client SHA is unchanged; current
selected count remains 2997/14344, P5 stop-line PASS and P6 scoped PASS. Real
native P6 remains open. Next Doc command routing and lifecycle bodies, followed
by View/Frame/Humanoid shared declarations. Native View construction also
identifies embedded CRobloxWnd at 0xb0, CMenu at 0x178, CReflectorWnd at 0x180;
these are leads pending their full member declarations, not padded replacements.
The source pointer for native CRobloxWnd constructor 0045c730 names generated
mfc-9.0-shared/roc_ui_network_window_ee9082b9a35d3d1a.cpp, absent from this local
recipe tree and generated-unit registry. Original constructor bytes remain
available; recover or retrieve its actual source before integrating that edge.


## Doc lifecycle dependency evidence (56d1dad3f3)

Pinned compiler verifies seven Doc bodies: constructor124, bindExisting78,
bindOwned91, OnNewDocument149, OnCloseDocument5, GetRuntimeClass6, CreateObject89.
Original EH metadata proves a std::exception reference catch. Initialization
00451b60 and logging00428850 remain explicit unlinked edges. Shared native
StandardVerbs composition yields exact998-byte destructor. Recovered XML union
includes double: size40/alignment8, exact138-byte destructor. Doc destructor
remains OPEN204/198 (extra binder vptr store); rejected compiler profiles and
source provenance are in native-classes/source-manifest.json.

Original dual TYPELIB proves shared IWorkspace/IContent GUIDs, HRESULT/retval
signatures, VARIANT arguments and x86 slots. Original RTTI supplies the COM
workspace base order. Its shared-pointer pointee at0x2c still needs proof before
a complete CWorkspace header and Doc cleanup/routing integration.

Four receipts in shared-layouts (document-compile, binder-compile,
original-evidence, original-typelib) pin source revision56d1dad3f3. All nine
proof source hashes were rechecked against current files and that committed
revision after unrelated concurrent commits advanced HEAD. Stronger verifier
checks were restored after a stale overwrite; incoming copy preserved locally
in TANDEM. No class swap occurred: merged exe hash unchanged, P5 stop-line
PASS/P6 scoped PASS, selected code2997/14344 unchanged. Native P6, remaining
shared classes and P9/P10 remain open. Other agent edits preserved.


Workspace owner trace: +0x2c is shared_ptr<RBX::RunService>. Original initialization0046b5c0 calls DataModel service getter004530f0, whose factory00405fa0 allocates0x2d8 and calls00556b00. Constructor stores vtable0082d4c4 at00556b94; its complete-object RTTI names RunService. Service-name literal0082d328 independently says RunService. Prior GuiItem attribution was an ambiguous shared_from template match, not pointee proof. Evidence: shared-layouts/workspace-owner-trace.json. Next complete CWorkspace shared fields with DataModel and RunService owners, then Doc cleanup. Active executable unchanged.


CWorkspace shared storage candidate added: genuine ATL bases in original RTTI order, DataModel and RunService shared owners. MSVC21022 passes size0x34, owner offsets0x24/0x2c and safety-base size8. Probe NativeWorkspaceLayout.cpp; receipt shared-layouts/workspace-compile.json pins source hashes. Candidate remains abstract/inactive: COM overrides, callbacks, constructor/destructor and safety bodies pending. No active ABI swap or runtime-count change.


CWorkspace constructor0046ab60 now matches33 bytes; typed DataModel getter0046a940 matches43. Native MIDL interfaces require novtable: omitting it emitted an extra primary interface-vptr store (39-byte constructor). Shared RobloxLib interfaces now carry that SDK convention. Storage checks still pass. Candidate inactive; callbacks/COM methods and Doc cleanup remain open. Running executable/count unchanged.


Doc typed getDataModel candidate: original00403040 is47 bytes; straightforward shared_ptr ternary compiles274 bytes, including with noinline on the workspace getter. Candidate remains inactive and unverified; avoid claiming an exact match. Next inspect return-value construction and lifetime behavior before integration. Existing runtime unchanged.


Doc getter00403040 now matches all47 bytes with relocations masked: explicit early return avoids ternary shared_ptr temporaries. Typed workspace call retained. Receipt shared-layouts/document-compile.json pins 1945d77c23. Inactive; runtime and gates unchanged.


Doc DeleteContents source port at 2de64d130b now uses typed DataModel lock, owned-verb cleanup, StandardVerbs deletion, workspace cleanup/Release, current-document handling and CDocument cleanup in original order. Original workspace cleanup call is 0046b0e0. Compiler accepts shared types and existing Doc gates pass; body is459 bytes vs original449, not exact, and cleanup/current-document links remain unresolved. Candidate stays inactive; no class swap or runtime gate change claimed.


Doc DeleteContents004513c0 now matches449 bytes with relocation fields masked. Caching end iterator, as in recovered source, removed the 10-byte mismatch. Verified at 147e8d8b5e; document-compile.json records the body. Workspace cleanup0046b0e0 and current-document helper00405aa0 remain unresolved; class inactive. Doc destructor still204/198. No selected-executable or runtime gate changes.


Workspace cleanup boundary: MSVC21022 compiled donor DataModel::getWorkspace to offset0x218, while original getter0046a970 reads0x204. Evidence shared-layouts/datamodel-workspace-boundary.json and NativeDataModelProbe.cpp. The existing donor accessor cannot safely implement native CWorkspace::cleanup; recover native DataModel layout/accessor before connecting this ownership edge. No runtime or gate change.


Original DataModel RTTI recorded at 89c4a45b9d: ServiceProvider at0, VerbContainer at0x1c8, IDataState at0x1f0, Evaluator at0x1f4, RunTransition listener at0x1f8. Instance hierarchy includes GuidItem at0 and enable_shared_from_this at0xe4; donor declarations differ. Evidence shared-layouts/datamodel-rtti.json, generated from original executable by record_native_layouts.py. Native full fields/size remain open; no active ABI swap.


Native DataModel factory0057c080 allocates0x264 bytes and calls constructor0057b9f0; constructor writes original DataModel RTTI vtable008303cc and initializes workspace member at0x204. Destructor0057ad70 independently writes the same vtable. Original-binary instructions and hashes saved in shared-layouts/datamodel-rtti.json at aedd5224d9. Remaining fields and inherited layouts require recovery; no class swap.


Native DataModel constructor boundary receipt at ff46ffa855: 15 member writes and 13 calls extracted from original0057b9f0. Original constructs workspace at0x204, initializes paired owners at0x1fc/0x200,0x20c/0x210,0x214/0x218, and constructs members at0x21c/0x224; other initialized boundaries include0x22c,0x230,0x234,0x250,0x258,0x259,0x25c/0x260. Types beyond independently proven fields remain open. Receipt shared-layouts/datamodel-constructor.json; reproducible with record_datamodel_constructor.py. No active ABI change.


Native DataModel member type evidence at aea284c006: +0x204 is shared_ptr<Workspace>; +0x21c and +0x224 are shared_ptr<GuiRoot>. Constructor calls factories00576ff0/00577090; allocated objects write original RTTI vtables00833a54/0082f9fc for Workspace/GuiRoot. The shared-pointer factory behavior and constructor arguments remain in original-binary trace; names of the two GuiRoot fields remain unproven. Reproduce record_datamodel_members.py; receipt shared-layouts/datamodel-members.json. No active ABI swap.


DataModel constructor type trace: +0x234 invokes imported MSVCP90 std::basic_string<char> default constructor and ends at0x250; +0x25c/+0x260 hold a shared recursive mutex: allocated object calls Boost recursive_mutex constructor00563070, then control-block constructor00576c80. Evidence shared-layouts/datamodel-value-members.json; names and unrelated fields still open. No active ABI change.


MSVC21022 class-layout comparison: native DataModel size0x264 vs donor0x27c. Original RTTI versus compiler report gives native/donor VerbContainer0x1c8/0x1c0, IDataState0x1f0/0x1e8, Evaluator0x1f4/0x208, RunTransition listener0x1f8/0x20c and workspace0x204/0x218. GuidItem is native primary base, whereas donor stores Guid at instance tail. Differences are not a uniform offset; native Instance/ServiceProvider and IDataState layouts need recovery, not a constant adjustment. Evidence datamodel-layout-comparison.json and datamodel-donor-layout.log. No active ABI change.


Native IDataState recovered as a four-byte interface, two virtual slots setDirty/isDirty. Original DataModel RTTI shows no StateStack base; vtable0083030c points to0057b020/0057b030, accessing DataModel dirty byte0x258 from interface offset0x1f0. MSVC21022 native interface size gate passes. Candidate shared header is inactive; donor IDataState still embeds StateStack and must not be treated as ABI-equivalent. Evidence shared-layouts/idatastate.json.


Native GuidItem<Instance> shared declaration recovered from existing openrbx source. MSVC21022 confirms Guid size8 and GuidItem size0x10, consistent with original RTTI: primary GuidItem at0 followed by AbstractFactoryProduct at0x10. Probe currently uses donor Guid type, so method semantics remain unproven and declaration is inactive. Evidence shared-layouts/guiditem-compile.json at 8b27441d91. Full native Instance/ServiceProvider remains open.


Native Instance hierarchy candidate at 5ac7039870 uses GuidItem primary base, original RTTI order, native event-type spellings and recovered member types. MSVC21022 confirms size0x130, association0xec and parent0x104; compiler layout evidence in shared-layouts/instance-compile.json and instance-layout.log. Full virtual signatures, ownership lifetimes and dependent classes remain open; source is inactive and donor runtime unchanged.


Native ServiceProvider candidate at c1aedcaf36 builds on native Instance and original three-notifier RTTI. MSVC21022 confirms size0x1c8, serviceArray0x190 and serviceMap0x1a8, matching original00568bf0 member boundaries. Existing source supplies container type candidates; virtual behavior and ownership still require proof. Receipt shared-layouts/service-compile.json. Inactive; no runtime change.


Native DataModel base probe at 5c3a4c18bd combines recovered Instance/ServiceProvider, VerbContainer, IDataState, Evaluator and RunTransition listener. MSVC21022 reproduces original RTTI offsets 0x1c8/0x1f0/0x1f4/0x1f8 and base extent0x1fc. Split native VerbContainer declaration avoids donor StateStack-based IDataState; existing constructor source matches original00583460, 40 bytes with relocations masked. Reproduce record_native_datamodel_bases.py; receipt shared-layouts/datamodel-bases.json. Probe omits DataModel members; none of these classes are active or yet proven behaviorally complete.


Native DataModel +0x20c/+0x210 is shared_ptr<RunService>: initialization0057a9f0 calls independently traced RunService getter004530f0 and stores its shared owner at0057ab20. Verified original instruction bytes and prior factory RTTI; datamodel-members.json pins observer revision464a00f92f. Remaining owner types still need proof; no active ABI swap.

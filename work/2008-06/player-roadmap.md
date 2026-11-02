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


Native DataModel shared owners resolved: +0x1fc LocalBackpack and +0x214 StarterPackService. Original initialization calls getters00578930/004b3960 and stores returned shared owners; their factories invoke constructors005fceb0/005d0fc0, whose vtable RTTI identifies exact pointees. All six consecutive owner types now evidenced in datamodel-members.json at dfddcb3f5f. Remaining non-owner member types and method ABI still open; no active swap.


Native DataModel storage candidate at 3aefaca713: full0x264 size, six key member offsets, Lock size12 and workspace accessor0x204 pass MSVC21022 probe. Fields combine original constructor/RTTI/owner evidence with existing recovered0057a1b0 declaration; virtual methods, construction, ownership and full ABI remain open. Native Verb split and ServiceClient declaration remove prior shared-header collisions; Doc probe passes nine body checks, base probe matches four RTTI offsets and VerbContainer constructor40 bytes. Doc destructor still OPEN204/198. Receipts datamodel-compile.json, datamodel-bases.json and document-compile.json pin same source revision. No active class swap; merged exe hash unchanged, P5/P6 scoped baseline PASS and selected code2997/14344 unchanged.


Native Selection layout candidate at da05c686d1: size0x174, notifier0x130, ancestor listener0x150, selection storage0x154, filtered list0x15c. Original factory00409620 allocation and RTTI agree; MSVC21022 compiler probe, Doc and DataModel probes pass. Workspace DrawChanged notifier original offset0x344 documented in workspace-selection-rtti.json; full Workspace renderer/base layout and cleanup linkage remain open. Candidate Selection inactive; original executable hash unchanged and scoped baseline2997/14344 remains. Receipts pin da05c686d1.

Native CWorkspace cleanup candidate at a501d1e3a2 compiles (MSVC21022): 242/242 bytes, relocation-normalized mismatch in listener-call register scheduling. Constructor and getDataModel remain exact. Service lookup alias and closeDataModel linkage remain unresolved; workspace notifier +0x344 uses RTTI evidence. Candidate inactive; no runtime gate or coverage claim. Receipt: shared-layouts/workspace-cleanup-compile.json.

Correction at 16f379d992: cleanup calls selection lookup 00415200 (which 004153b0 also calls); 004153b0 additionally creates Selection if absent. Candidate now names non-creating lookup findSelection; symbol/linkage still open. Doc and DataModel compiler probes pass at this revision. No active swap.

Selection lookup source at b6a48fa540: CWorkspace now calls original-shaped ServiceProvider::find<Selection>() symbol, with existing recovered service-cache template compiled against native candidate layout. Lookup 386/320 bytes, cleanup 242/242; both remain non-exact, unlinked and inactive. Class-name initialization, shared_ptr destruction and target linkage remain open. Doc and DataModel compiler probes pass; receipt shared-layouts/selection-lookup-compile.json pins source revision. No P5/P6 rerun: active client unchanged.

Selection service lookup candidate b47729ee61 uses recovered Name::declare template; initialization call sequence matches original shape. MSVC21022 probe compiles, 404/320 bytes: shared_ptr destruction still inlined unlike original, relocation targets unresolved. Explicit destructor specialization caused compiler ICE and was discarded. No runtime swap; selection-name-compile.json pins evidence.

Document destructor resolved at 9235c01ed5: original recovered VerbBinder is __declspec(novtable), removing extra vtable store. MSVC21022 candidate now matches original 00451940, 198 bytes with relocations masked; probe requires this match. Doc virtual-slot/layout, DataModel and base compiler probes pass. Relocated call targets and other Doc virtual bodies remain unverified; inactive class, no P5/P6 swap.

Doc native methods at 6373c250da: SetModifiedFlag 0044fad0 (166 bytes) and SetTitle 0044fb80 (199 bytes) match original with relocations masked. Probe now enforces 11 Doc bodies plus three destructors; all pass. Call-target linkage and remaining virtual methods still open. Candidate inactive; no P5/P6 rerun or running-exe count change.

Doc IsModified 004508f0 recovered at 2daa5d7d1b: DataModel lock and virtual dirty query compile to original 377 bytes with relocations masked. Regression probe passes 12 Doc bodies and three destructors. Call-target linkage and remaining virtual methods unverified; no active swap or running-exe count change.

Doc DoSave 0044f8d0 recovered at 7320c51b95: 213-byte relocation-masked match, regression probe passes 13 Doc bodies and three destructors. Two guarded predicate calls target original 00495e60/00495e70; semantic names and linkage remain unresolved, as do other virtual bodies. Candidate inactive; running-exe count and P5/P6 gates unchanged.

Doc save predicate identities at 514ce31479: original call chains reach cached NetworkClient and NetworkServer service lookups, with original name initializers pointing to those strings. Recovered Client/Server source supplies matching static method symbols; candidate now uses them. 13 Doc body/compiler checks pass. Full network declarations and linked implementations remain unverified; no runtime swap. Evidence shared-layouts/document-save-predicates.json.

Working-tree Doc OnOpenDocument candidate: existing recovered 004533f0 source integrated into shared class. MSVC21022 probe matches 628 bytes with relocations masked; 14 Doc bodies and three destructors pass. Workspace load, history-service create/setEnabled, reporting targets and full history ABI remain unlinked/unverified. Probe document-open-working-probe.json hashes working-tree sources; no active swap or runtime gate change.

Working-tree DataModel::Lock implementation recovered from existing source. Constructor 00411b40 (152 bytes), doLock 00576f00 (128), destructor 005773c0 (145) match with relocations masked; new repeatable compiler probe datamodel-lock-working-probe.json pins source hashes. This closes candidate Doc lock bodies, but relocated targets and native linking remain unverified; no runtime swap.

Working-tree Doc OnSaveDocument 0044f9b0 recovered via native IWorkspace::SaveToFile and CComBSTR: 279-byte relocation-masked match. Doc compiler gate now checks 15 methods and three destructors. Full COM workspace implementation and relocation targets remain open; candidate inactive, runtime unchanged.

Working-tree CWorkspace::writeXmlModel 0046ab90 integrated from recovered source. Constructor, DataModel getter, XML writer pass repeatable compiler probe (writer 245 bytes relocation-masked); Doc, DataModel and lock probes also pass. XmlElement/serializer and writeChildren targets must still be linked and validated; runtime unchanged.

Working-tree command routing: native Doc getVerbContainer 00450890 (95 bytes) and VerbBinder::OnCmdMsg 00451690 (507) match with relocations masked. UINT map key matches routing; explicit DWORD casts preserve bindExisting/bindOwned body matches. Doc compiler gate passes 16 bodies, routing and three destructors. Independent standalone binder constructor probe fails 80/86 after prior novtable change: original constructor writes binder vtable, while Doc destructor match requires suppressing a binder vtable write. Treat shared binder ABI as unresolved; no active swap until reconciled. Receipts document-routing-working-probe.json; failed binder probe not overwritten.

DataModel lock probe now verifies six direct call relocations against original target addresses, including constructor -> doLock and lock/unlock routines; compiler proof passes. Binder conflict confirmed: original Doc constructor 00451ac0 calls 00451590, whose 86-byte body writes binder vtable 00817c24. Current novtable candidate suppresses that store, compiling to 80 bytes; Doc destructor matches only after suppression. This remains an ABI/codegen mismatch, not a passed constructor.

Working-tree Instance::writeChildren 00558110 integrated from existing source: 160-byte relocation-masked match. Corrected native Instance XML declarations to global XmlElement, consistent with original headers and serializer; Doc, DataModel and Workspace probes pass. writeChildren call target and XML child operations still require linked verification; no runtime swap. Earlier statement that original binder itself was proven novtable is withdrawn: recovered surrogate used novtable, but original constructor store contradicts it.

Workspace XML writer working probe now verifies five original direct call targets, including SerializerV2::newRootElement 00591a30, Instance::writeChildren 00558110 and native lock ctor/dtor. Recovered SerializerV2::newRootElement from existing source: compiler match 401 bytes with relocations masked. Dependency data and final linking unverified; inactive candidates only.

Serializer root compiler gate now also checks emitted XmlElement::addAttribute<const char*> body against 00591970 (118-byte relocation-masked match), plus three original attribute-call targets and Name::declare target. Data globals, initialization order and final linked runtime remain unverified; no active class swap.

Original Doc MFC message map recovered as data inventory: getter 00455d20 returns map 00817f0c, entries 00817f18 contain 39 command/notification records plus terminator. document-message-map-working.json records each ID, signature and original handler address; handler bodies/names and linked map remain open. Serializer probe additionally matches 0058c920 XmlNameValuePair string constructor (103 bytes) and verifies attribute->constructor call. No active swap.

Working-tree Doc MFC message map reconstructed from original 39 records. Compiler probe verifies all IDs/codes/signatures, terminator, handler relocation symbols, base map pointer, GetMessageMap (6 bytes) and common enable handler (18 bytes); 18 Doc bodies, routing and three destructors match. Address-named handler declarations remain unresolved, original map handler targets/data still need runtime linkage; no active swap.

Doc pause handler 00455460 recovered from existing source: locks DataModel and requests RunService paused state; MSVC21022 emits 281-byte relocation-masked match. Message map binds handler; compiler probe now checks 19 Doc bodies plus routing, map and destructors. RunService creation/setRunState linked targets and full runtime remain unverified; donor RunService header requires native-layout validation before activation.

Native RunService working candidate replaces incompatible donor layout: donor sizeof 0x22c vs original factory allocation 0x2d8; corrected candidate 0x2d8, state 0x1b4 and nine constructor-observed fields match offsets. Recovered 00556b00 constructor (531 bytes) and 00554da0 setRunState (106 bytes) match with relocations masked; RunService, Doc and DataModel compiler probes pass. Some fields, runDisabled, bases, call/data relocations and runtime integration remain unverified. No active swap.

Native notifier recovery: original raises increment the listener cursor before callback. Shared native Events header now follows recovered iteration and exception signature; RunService state and transition notifier bodies match 00554ae0 (131 bytes) and 00554a60 (123). RunService constructor/state methods still match; four notifier base displacements agree with original RTTI and compiler output. Doc, workspace and DataModel probes pass. Relocated targets, other Notifier instantiations and runtime ABI remain unverified; no active swap.

RunService notifier callbacks now independently verified: state callback 00554750 (185 bytes), transition callback 00554690 (full 189 bytes). Function index truncates transition callback at 66-byte exception boundary; full PE comparison checks operand-aligned relocation fields and three INT3 bytes before next function. Four state->raise->callback direct call targets verified. Candidate remains inactive; data/EH relocation identity and runtime gates remain open.

Working-tree Doc play handler 00455820 snapshots XML then starts RunService: 504-byte relocation-masked match. Pause and play probe additionally verifies all 19 direct-call relocation targets, including service creation, state transition, XML root and child serialization. RunService and Doc compiler gates pass; service creation implementation and runtime linkage remain open; no active swap.

Native ServiceProvider::create<RunService> 004530f0 integrated from existing source, matching 228 bytes with relocations masked. Probe checks original find/create/setParent call targets; RunService lookup 00452c80 remains 404/320 bytes. Doc and RunService probes pass; candidates remain unlinked/inactive, P5/P6 runtime unchanged.

Binder constructor/destructor conflict resolved in working tree: remove surrogate novtable and explicit empty destructor; inherited virtual destructor remains implicit. Standalone binder constructor 00451590 (86 bytes), Doc destructor 00451940 (198 bytes), Doc constructor, routing and all 20 Doc body checks now match with relocations masked. Both binder and Doc probes pass against same source hashes. Original vtable targets, EH data and runtime linking remain open; inactive candidate.

CRobloxView native base-only compiler probe now matches original RTTI: VerbContainer +0x78, service listeners +0xa0/+0xa4, Players listener +0xa8; base extent 0xac. Evidence view-bases-working-probe.json. Complete 0x1f0 View storage, CRobloxWnd/CMultiPlayerPane fields and virtual methods remain open; no fake padding and no runtime swap. Service lookup /Ob0-/Ob1 and inline-depth experiments did not match and were discarded.

View member CMultiPlayerPane candidate: native CWnd-derived 0x58 size, child pointer +0x54. Original 00432e60 creates CChatPrompt via CRuntimeClass 0080df88 and stores it at +0x54; RTTI identifies pane vtable. Constructor 00432e30 (25 bytes) and destructor 00432e50 (11 bytes) match with relocations masked. Remaining virtual methods and linkage open; candidate inactive.

Native CRobloxWnd base-only probe matches original RTTI: CWnd +0, IRunView +0x54, IMetric +0x58; base extent 0x5c. Original View constructor and component RTTI verify embedded CRobloxWnd +0xb0, CMenu +0x178, CMultiPlayerPane +0x180. Full window/View member types, virtual methods and linkage remain open; candidates inactive.

CMultiPlayerPane working candidate now includes native MFC runtime class, two-entry message map and OnSize/OnDestroy. Six bodies match with relocations masked; both original message records and handler symbols match. OnSize second call is provisional updateLayout alias for original MFC thunk 006a0c68 (ordinal 2069); actual imported symbol remains unverified and must be resolved before linking. Full pane vtable/runtime not yet gated; no active swap.

CMultiPlayerPane OnSize alias resolved: original 006a0c68 thunk imports mfc90.dll ordinal 2069, SDK mfc90.def identifies CWnd::Default(). Replaced provisional updateLayout call with Default(). Probe verifies original thunk/import/export mapping for Default, MoveWindow (4529), and OnDestroy (4760), plus six body matches and message map. Runtime integration remains open.

CChatPrompt native candidate: CEditView base, size 0xa8; selection +0x88, shared chat +0x8c, CBrush +0x94, shared context +0x9c, result +0xa4. Original allocation/RTTI corroborate size, CEditView/CBrush/ChatEnter; constructor 00411be0 matches 72 bytes with relocations masked. Pointee types, destructor, virtual slots and linkage still require proof. Multiplayer pane now uses typed CChatPrompt pointer; its probe still passes. No runtime swap.

CMultiPlayerPane initialize 00432e60 reconstructed: 180-byte relocation-masked match; two additional MFC thunks verified against SDK export ordinals. ChatPrompt bind target 00412800 remains declared pending real body/linkage. Corrected ChatPrompt +0x9c context from GuiItem to DataModel: shared pointer is passed to native DataModel::Lock; +0xa4 is Players pointer, traced through creation factory and original RTTI. Prior GuiItem spelling was based on folded shared_from implementation and was not type proof. ChatPrompt/pane compiler probes pass; no active runtime swap.

Chat binding 00412800 recovered in shared candidate: 446-byte relocation-masked match, 11 original direct-call targets verified. Added ChatEnter candidate using donor GuiItem: size 0x148, owner +0x144 and constructor 00411720 (100 bytes) match. Constructor deliberately does not initialize owner, matching original. GuiRoot parent adapter, GuiItem vtable, service implementations and runtime linkage remain open; no active swap.

Chat bind parent conversion corrected: original GuiRoot RTTI shows GuiRoot, GuiItem and Instance at offset zero; replaced provisional reinterpret cast with typed conversion using recovered hierarchy. ChatPrompt binding and ChatEnter constructor probes pass. GuiItem complete virtual ABI still unverified; no active swap.

ABI correction: original ChatEnter, GuiRoot, RunService and Workspace primary vtable slot 0 points to 0047d410 (ret); current shared GuidItem candidate emits deleting destructors there. Added explicit OPEN vtable diagnostics to ChatEnter and RunService probes; relocation-masked constructor matches did not prove vtable contents. Experiment with a non-destructor virtual slot produced matching slot shape but was reverted: original method identity and GuidItem lifetime semantics remain unproven. No native Instance-derived class is cleared for active swap until resolved.

GuidItem primary-slot mismatch resolved in working tree using existing 2008 recovered declaration roc_instance_guid_callback_5e8a3f385d045a38.cpp: primary virtual slot is onGuidChanged(), not a virtual destructor. Candidate callback emits ret, matching original slot 0047d410; ChatEnter and RunService vtable probes now pass this slot. Doc, DataModel, Workspace, ChatPrompt and affected constructor probes pass. Other virtual slots, GUID registration/destruction, relocated targets and runtime linkage remain unverified; no active swap.

Native GuiItem getChildPosition corrected against original 00411810: donor assertion absent in original; zero-vector behavior remains. ChatEnter primary-table comparison now compiles and matches nine GuiItem bodies plus ChatEnter constructor, including 24-byte getChildPosition. ChatPrompt, pane and Doc compiler probes pass. Other inherited virtuals, data and runtime linkage remain unverified; no active swap.

GuiItem lifetime recovered from existing source: native constructor 005739d0 matches 236 bytes and implicit destructor 00411540 matches 122 bytes with relocations masked. Original constructor/destructor calls to Instance ctor/dtor and setName verified. Explicit user-written destructor emitted extra vtable stores, so retained compiler-generated implicit destructor. ChatEnter probe still passes; Instance lifetime implementation and runtime integration remain open.

Instance lifetime candidate compiled against shared native header: constructor 0055b7e0 is 377 vs original 375 bytes; destructor 0055a540 is 557 vs original 572 bytes. Neither relocation-masked body matches. Existing ctor source uses surrogate layout (62%); destructor source uses surrogate types. Candidate remains inactive; compare instructions and resolve base/member lifetime before linking. No runtime swap or P5/P6 gate claim.

Instance lifetime candidate now matches: ctor 0055b7e0 (375 bytes), dtor 0055a540 (572 bytes), relocation-masked. Original construction order requires enable_shared_from_this first; GuidItem needs false initialization, nonvirtual destructor and novtable. Probe verifies selected original direct calls including GuidItem destructor 004b3760. ChatEnter, GuiItem and RunService probes pass after changes. Destructor implementation, remaining virtuals, relocation data and runtime linkage still open; no active swap. Evidence instance-lifetime-working-probe.json.

GuidItem<Instance> destructor 004b3760 reconstructed from recovered source against shared native layout: 149-byte relocation-masked match; four direct calls verified. Registry interfaces and globals remain provisional pending symbol/data proof and implementation; candidate inactive. Evidence guid-item-working-probe.json. No P5/P6 runtime swap.

Guid constructor 005a8300 integrated from recovered source into inactive shared candidate: 46-byte relocation-masked match; boost::call_once target 00557330 verified. GuidItem destructor now calls actual boost::call_once rather than provisional alias; its body and four direct targets still match. Globals, registry implementation, data relocations and runtime linkage remain open. Evidence guid-working-probe.json and guid-item-working-probe.json.

GUID initialization chain recovered: initializer 005a8260 (116 bytes), generateGUID 005a8140 (178), helper 005a80d0 (110) match relocation-masked original alongside constructor. Original generation calls out-of-line helper then prefixes RBX; adapted donor combined them. Selected calls to generation, helper, Name::declare and boost::call_once verified. Name registry, data identity and runtime linkage open; inactive, no gate change. Evidence guid-working-probe.json.

CMainFrame native base-only compiler probe now matches original RTTI: real CXTPMDIFrameWnd at 0, Listener<FillToolColor, BrickColor> at +0xf0, combined extent 0xf4. Original full runtime size 0x4b4; members and virtuals remain open. Uses actual XTP 11.2.2 headers, no padding substitute. Evidence main-frame-bases-working-probe.json; inactive, no runtime gate change.

CMainFrame original constructor 004321f0 confirms embedded CXTWindowPos +10c, CXTPDockingPaneManager +138, CXTPTabClientWnd +284, CXTThemeManager +3b4 and CXTPStatusBar +3e0. Actual XTP headers compile with respective 2c/14c/124/2c/d4 sizes; theme vtable RTTI confirms class. Unknown intervening members still open; no padding or runtime swap. Updated main-frame-bases-working-probe.json.

CMainFrame native shared base header now includes typed contiguous XTP components and three pane pointers: CXTSplitterWnd +3a8, CDataModelPropGrid +3ac, CSelectionCaption +3b0. Original allocation/constructor sites and each class RTTI vtable verified; compiler validates component/pointer ordering and sizes. Ownership cleanup, intervening members, complete class and runtime integration remain open. Updated main-frame-bases-working-probe.json.

Inactive full-size CMainFrame layout candidate now compiles at 0x4b4 with major member offsets verified; no padding arrays. Original MFC imports verify CString +108; MonitorFromWindow result verifies HMONITOR +fc. The pointer identities at +f4/+100, exact ownership, state semantics, virtuals and class linkage remain provisional. CMainFrameBases and grouped members are layout probes, not proof of original class hierarchy or construction ABI; no runtime swap. Updated main-frame-bases-working-probe.json.

CMainFrame candidate now uses original direct base classes and direct embedded members instead of probe-only grouping; size/offsets remain verified. Recovered FillToolColor listener onEvent 0042fb20 compiles to 95-byte relocation-masked match, with four original call targets verified including CXTPControlPopupColor::SetColor. Inactive; remaining virtual ABI, pointer ownership and runtime gates open. Evidence main-frame-color-working-probe.json and main-frame-bases-working-probe.json.

CMainFrame listener vtable slot confirmed against original 0042fb20. Fixed previously inherited XTP primary GetRuntimeClass: DECLARE_DYNAMIC/IMPLEMENT_DYNAMIC now emit CMainFrame primary slot and 0042e460 body matches. Class metadata data and remaining vtable/runtime linkage still open. Pane reset 00430440 matches boost::scoped_ptr<CWnd>::reset in separate compiler probe, but template identity is not uniquely proven; retained provisional raw fields. Evidence main-frame-color-working-probe.json, frame-pane-owner-working-probe.json. No active swap.

CMainFrame native MFC message map reconstructed: all 40 records and handler symbols match original 00811630; GetMessageMap 004321c0 relocation-masked body matches, parent resolves to CMDIFrameWnd via original mfc90 ordinal 4000. Most handlers are declarations pending recovery; OnPaint calls original thunk target CWnd::Default. Color callback probe still passes. Inactive; class vtable, handler implementations and runtime gates open. Evidence main-frame-map-working-probe.json.

CMainFrame pane helper 0042e570 and six message handlers now match original relocation-masked bodies; recovered helper uses real CXTPDockingPane::SetFocus rather than surrogate return-value guess. Six direct call targets verified. Layout, 40-entry map and color callback probes revalidated against current header. Other handlers/ownership and runtime swap open. Evidence main-frame-commands-working-probe.json.

Five more CMainFrame command/update handlers recovered, including property-pane docking and fullscreen toggle; eleven handler bodies plus pane helper match relocation-masked originals. Selected call targets verified; show/hide/fullscreen implementations and other handlers remain open. Frame layout, map and color probes pass current header. No active swap; P5/P6 executable unchanged.

CMainFrame fullscreen transition 00431b40 (169 bytes) and display restore 00430160 (330 bytes) now match relocation-masked original against shared native fields. Verified selected direct call targets and original fullscreen Win32 imports; restore source previously reported 91% with surrogate fields. Layout/map/color probes pass. Display configuration path and runtime linkage remain open; no runtime swap. Evidence main-frame-commands-working-probe.json.

Recovered CMainFrame OnActivate 00431bf0, OnActivateApp 00430360 and OnWindowPosChanging 0042ef10: all relocation-masked exact. Original MFC import thunks/ordinals for CFrameWnd::OnActivate, CWnd::Default, ShowWindow and ModifyStyle verified. configureFullscreen 004318b0 and full class integration remain open; no runtime swap. Evidence main-frame-commands-working-probe.json.

CMainFrame OnGetMinMaxInfo 00431c40 now matches 152 bytes relocation-masked and selected call targets. Original writes ptMaxPosition to zero, not ptMinTrackSize as surrogate source implied; real MINMAXINFO declaration corrected behavior. Frame-size settings class/singleton names remain provisional although target addresses verified; runtime linkage open. Evidence main-frame-commands-working-probe.json.

CMainFrame OnDestroy 00430b40 recovered with real MFC/XTP types: 132-byte relocation-masked match; native calls to restore, SaveWindowPos, persistent-state handler, CMDIFrameWnd::OnDestroy and tail-jump tab detach verified. Layout/map/color probes pass current header. Frame-state persistence dependency and runtime swap remain open. Evidence main-frame-commands-working-probe.json.

Correction to prior OnDestroy note: target 004307e0 initializes menu/toolbars and returns bool; it is not frame-state persistence. Updated candidate declaration/call to initializeToolbars(false); OnDestroy still matches and dependent probes pass. Original toolbars include Standard, Mouse, Test, Camera and Command; exact initializer remains open.

Native toolbar initializer 004307e0 now matches 448 bytes relocation-masked using real XTP types; all 11 direct call operands and 26 hidden-command data values match original. Setter at 006c1ea0 and global 0096617c use provisional names/types pending identity and linkage; positionToolbar 004303a0 remains open. Frame layout/map/color/commands probes pass current header. No runtime swap. Evidence main-frame-toolbars-working-probe.json.

Toolbar provisional methods resolved to original XTP source: 004303a0 is CXTPCommandBarsSiteBase<CMDIFrameWnd>::DockRightOf (146-byte relocation-masked match), and 006c1ea0 is CXTPToolBar::EnableDocking (13-byte match). Initializer now calls these real methods, no surrogate setter or frame wrapper. Toolbar and frame probes pass. Global 0096617c identity, remaining integration and runtime gates still open. Evidence main-frame-toolbars-working-probe.json.

Resolved original global 0096617c to CXTPCommandBar::s_nExpandDelay: original SetPopuped 006b6ed0 (252 bytes) matches vendored XTP source and references that exact address at corresponding relocation; used real static member in initializer. Toolbar initializer and docking probes pass; original data linkage and runtime swap remain open. Evidence main-frame-toolbars-working-probe.json.

Frame layout-save candidate 004309f0 now uses real CXTPPropExchangeXMLNode, ShowWorkspace, RemoveAll and DestroyAll. It is NOT exact: 224 vs 230 bytes because candidate inlines CString conversion where original calls mfc90 ordinal 910; exchangeLayout dependency remains open. Compiler probe records this mismatch, other frame probes pass. No runtime swap.

CMainFrame exchangeLayout 0042f9d0 reconstructed with native XTP prop-exchange types: 336-byte relocation-masked match, selected five original direct-call targets verified. Uses real section ownership and command-bars, shortcut, options and docking serializers. Layout-save caller remains 224/230 bytes due CString conversion import; frame probes pass. No runtime swap. Evidence main-frame-commands-working-probe.json.

Frame editor-chrome restore 00430f50 now uses native XTP XML loader and actual pane handlers; corrected boolean toolbar flag and reversed misleading show/hide candidate names. Candidate remains nonexact at 220/226 bytes due same CString conversion import; hide path remains 224/230. Both mismatches explicitly recorded, all other frame probes pass. Runtime swap open.

CMainFrame OnClose 00431f10 candidate now covers keep-alive deletion, fullscreen state and XTP layout save; 230/236 bytes, nonexact for same CString conversion import. Verified original destructor and fullscreen call targets, but keep-alive class identity/ABI remains provisional. Command probe separately reports this partial; repeated docking and section-release call sites now verified. No runtime swap.

Frame keep-alive owner corrected from provisional CFrameKeepAlive to RBX::worker_thread: original 004273a0 jumps to worker_thread destructor 00595cb0; existing 2008 source compiles to its 178-byte relocation-masked match, and actual worker_thread is 0x14 bytes as allocated by OnCreate. OnClose candidate keeps same 230/236 mismatch due CString. Synchronization/data linkage and runtime swap remain open; related frame probes pass.

LoginRenewer constructor 004277d0 recovered with worker_thread base: 162-byte relocation-masked match, URL/callback/bind/worker constructor targets verified; source names still provisional. Frame monitor setup 004302b0 matches 161 bytes using actual MonitorFromWindow and warning logging. Candidate keepAlive now uses scoped_ptr<worker_thread>, consistent with observed reset/destruction, but exact template identity remains unproven. Frame probes pass; no runtime swap. Evidence login-renewer-working-probe.json and main-frame-commands-working-probe.json.

CMainFrame OnCreate 00431d00 now matches 524 bytes relocation-masked, using actual XTP classes, LoginRenewer and scoped owner. Probe also matches inherited InitCommandBars 0042ef40 and scoped reset 00430ec0, verifies 25 selected direct targets, six status indicator values and original MyXTPCommandBars runtime class name. Corrected prior surrogate interpretation: docking enables alpha context and stickers, not show-contents dragging. MyXTPCommandBars metadata, icon initializer, remaining ABI and runtime gates remain open; no active swap. Evidence main-frame-create-working-probe.json.

MyXTPCommandBars candidate now uses real CXTPCommandBars base and MFC dynamic creation: original runtime metadata size 0xcc and schema verified; CreateObject 0042f950, GetRuntimeClass 0042e4b0 and base getter 0042e4a0 match relocation-masked bodies. OnCreate now references actual class metadata symbol rather than provisional global and still matches. Remaining vtable targets, metadata relocations and runtime gates open. Evidence my-xtp-command-bars-working-probe.json.

MyXTPCommandBars original vtable slot 33 is an AddCustomBar override, not inherited: reconstructed 0042e470 (48-byte relocation-masked match), verifying base AddCustomBar and EnableDocking calls; candidate slot corrected. Fifteen inherited XTP slots (22-32,34-37) match original target bodies using existing XTP objects. MFC slots/data relocations and runtime gates remain open; no active swap. Evidence my-xtp-command-bars-working-probe.json.

MyXTPCommandBars audit: scalar-deleting destructor body 0042f9b0 matches (30 bytes); candidate vector-deleting vtable symbol may fold to scalar body but link identity remains unverified. Original MFC slots 5-21 resolve to exact candidate decorated symbols through mfc90 import ordinals; slots 2-4 are folded release no-ops. Together with 15 XTP body matches and AddCustomBar override, vtable evidence strengthened. Native class not yet linked or gated. Evidence my-xtp-command-bars-working-probe.json.

Active native swap: MyXTPCommandBars now integrated into merged P6 shell via real runtime class; build passes, P6 scoped gate passes on executable SHA-256 54ad66b0ee792b8835eda9d577a75ce89683b54f04771add2d7b1b7afce82bf4. P5 combined idle/play/reopen/live passes; P5 stop-line executable hash unchanged 6c961826d69371da5f63758e4902a95076b00528fe366e57d146ca6eb28146cb, preserving prior fall/jump tolerance evidence. Five MyXTPCommandBars functions verified in linked exe against original with relocations masked; original target/data relocations and overall exact object-function count not newly measured. Dirty worktree: evidence binds source and artifact hashes, not HEAD alone. Evidence p6-myxtp-swap-20261101/swap-evidence.json. Native P6 and later roadmap remain open.

Post-swap executable comparison: 3,002/14,370 selected known-source PE functions match relocation-masked code, versus prior 2,997/14,344 using same selected-code observer. This is a different metric from the requested 331/4,152 object functions: current player module archive report is 335/4,277, not PE selection and excludes the new P6 class. Do not present either as exact linked object-function count; that requested measurement remains open. P5/P6 gate status remains PASS as scoped in swap-evidence.json.

Resolved three frame CString mismatches via existing xtp-11.2.2-lib-imports recipe: its preprocessing explicitly marks imported CString conversion noinline. With that recipe, hide-editor 004309f0 (230), show-editor 00430f50 (226), and OnClose 00431f10 (236) all match relocation-masked code; each references the original mfc90 ordinal 910 conversion. Normal-compile probe remains correctly marked partial; actual future build must use matching preprocessing recipe. Native runtime integration remains open. Also removed duplicate concurrent roc integrator options that prevented all CLI commands; roc --help and py_compile pass. Evidence main-frame-string-recipe-working-probe.json.

Frame OnCreate now calls actual recovered InitializeAllIcons symbol at 0042f490 rather than a provisional alias; its 524-byte code and direct call still match. Full icon TU remains blocked on missing roc_espeon_nativeatlimagewidthdecl2e5804ac680a6dd9.cpp include alias and non-RTM recipe references; RTM replay confirms the alias is missing. A manual substitution using stock atlimage generated different icon code and was discarded. roc source lookup and py_compile pass after removing duplicate CLI options while preserving unrelated changes. No runtime swap.

Recovered usable icon TU from existing 21022 preprocessed cache despite missing ATL alias source: cache dependency manifest confirms present server source hash. Recompilation matches InitializeAllIcons 0042f490 (1211), InitializeIcons 0042f380 (271), SetIcon 0042f290 (237), loadIcon 0042f0a0 (485) relocation-masked; selected direct targets verified. Cache is not a substitute for missing alias source: fresh preprocessing, full data linkage and runtime swap remain open. Evidence frame-icons-cached-working-probe.json.

Fresh icon TU replay now works without historical ATL alias: reconstruct from installed RTM atlimage.h by removing GetWidth definition and marking CImage constructor, destructor, HBITMAP conversion, Create and GetPixelAddress overloads noinline, consistent with cached preprocessed unit. All four original icon functions match relocation-masked bodies (1211, 271, 237, 485 bytes). Historical alias bytes, remaining relocation/data linkage and runtime integration remain unverified. Reproducible evidence: shared-layouts/frame-icons-fresh-working-probe.json; test: rebuild/2008-06/tests/record_native_frame_icons_fresh.py. No active swap or new gate claim.

DataModel notifier coordination: shared native DataModel typed casts compile to ServiceAdded +0x150 and ServiceRemoving +0x170, matching View registration offsets; ServiceProvider RTTI separately supports the inherited base types. Reproducible evidence shared-layouts/datamodel-notifier-working-probe.json; Claude response logged in TANDEM.md. Candidate remains inactive; no new runtime gate claim.

Merged Claude P6 commit 6da8e40862 as f6e8dccfd3; no conflicts, existing local changes retained. After merge, record_native_document.py passes 20 Doc bodies and destructor checks; record_native_view.py passes 242-byte ctor and 371-byte dtor relocation-masked after compiling NativeViewLayout.cpp. Tests include existing dirty shared headers; evidence is source/object scoped, not clean HEAD alone. Active client unchanged; previous P5/P6 gates remain prior-swap evidence.

Native frame icons: recovered separate ATL::CImage::GetWidth definition, matching original 00442c80 (4 bytes) and preserving icon caller out-of-line. Existing P2ImageCore GImage object has memory constructor 005105b0 (187 bytes) and destructor 0050e230 (44 bytes) matching relocation-masked; icon caller relocations verified against both originals and width getter. Evidence frame-icons-fresh-working-probe.json and frame-icon-image-deps-working-probe.json. Full GImage layout/data, other dependencies, active linkage and runtime gates remain open.

Native icon dependency link probe: real GImage header compiles with size 0x14 and width/height/channels offsets 8/c/10, consistent with original destructor pixel-pointer access +4. Isolated P6 link succeeds with fresh icon and GetWidth objects when gdiplus.lib is added; map confirms icon initializer, getter and GImage memory constructor linked. Initial link without GDI+ failed on GdiplusShutdown. Output is separate and initializer is forced but never called; no active swap or P5/P6 gate claim. Evidence shared-layouts/frame-icons-isolated-link-working-probe.json.

Native icon initializer active in merged shell: original XTP image manager ownership/call sequence wired, fresh original icon TU and separate width getter built and linked with GDI+. Five icon bodies confirmed in running PE with relocations masked. P6 scoped gate full retry PASS; first attempt had ordinary-launch second close hang, cause unresolved; two standalone subsequent twice-launch checks also passed. P5 combined gate PASS and stop-line player hash unchanged. Selected known-source observer reports 3002/14368 (excludes icon objects in native-layouts; not requested total). Scope and hashes in p6-native-icons-retry-20261101/swap-evidence.json. Full native CMainFrame, data/relocations and raw exe match remain open.

P6 ordinary-close hang follow-up: six instrumented runs each found the main Roblox frame and exited 0; first gate hang remains unexplained, not declared fixed. Logs and exact executable/observer hashes: p6-close-investigation-20261101/receipt.json. Native icon generator was force-added because rebuild tree is gitignored.

Native HumanoidState prefix: inactive shared declaration uses RTTI-proven INamed +0 and HitTestFilter +4; MSVC probe verifies humanoid pointer +8, float +c and bools +10/+11 against original 00643e00 constructor. Constructor also calls G3D::CoordinateFrame ctor at +40 and +70. Prefix is deliberately incomplete, not native object size; remaining fields, semantics, virtual ABI, lifecycle and runtime swap open. Evidence shared-layouts/humanoid-state-prefix-working-probe.json. No P5/P6 gate claim for this inactive declaration.

Humanoid floor-state inactive relative layout now compiles: bool +20, shared ownership +24/+28, contact vector +2c, float fields +38/+3c, CoordinateFrames +40/+70. Original 006451c0 directly verifies flag, reference, vector and frame accesses; 006435c0 verifies shared-control decrement and G3D alignedFree-backed array at +14; getter 00643d30 returns stored object +228. PartInstance identity and field meanings are inferred; array element type and full native state remain open. Evidence shared-layouts/humanoid-floor-working-probe.json. No runtime swap or new gate claim.

Humanoid factory 00643660 audited against original jump table, allocator call, constructor calls and constructor-installed primary-vtable RTTI: enum cases 0..11 = FallingDown(a0), GettingUp(a8), Jumping(a8), Freefall(c0), Flying(a8), Landed(cc), Running(cc), RunningNoPhysics(114), StrafingNoPhysics(114), Climbing(cc), Seated(a0), Dead(a0). Hex sizes. Previously mined 100% factory source labels were misleading (e.g. case 1 Ragdoll and case 6 Landed); do not reuse its names or sizes without this evidence. Does not yet prove state members or runtime behavior. Evidence shared-layouts/humanoid-factory-working-probe.json.

Selected-code observer now includes the two externally built native icon objects when their names appear in the P6 link map; missing linked objects cause failure. Current PE yields 3018/14394 relocation-masked matches, zero COFF-to-PE mismatches, including 16 uniquely matched icon-object functions. This expands observer scope versus 3002/14368; not a same-scope gain and not the requested exact-function count. Receipt p6-native-icons-retry-20261101/selected-including-icons.json. Gate status unchanged.

CMainFrame constructor 004321f0 trial: recovered cached-source semantics against real XTP/MFC types; adding provisional scoped ownership for three pane fields and marking std::string size/c_str noinline yields 483-byte relocation-masked match with ten original call targets verified. Constructor accesses actual FileSystem::getUserAppDataDirectory(true,NULL) and FillTool::color listener. Raw-pointer current candidate still differs; scoped_ptr versus auto_ptr identity, pane class/destructor ABI, lock globals, exception metadata and active runtime linkage unproven. Trial is generated in out; shared header remains raw pending proof. Evidence shared-layouts/main-frame-constructor-trial-working-probe.json. No runtime swap or new gate claim.

CMainFrame destructor 00432000 inactive trial now matches 309 bytes relocation-masked with provisional pane scoped owners and synthetic first vtable slots; selected calls verified, including XTP destructors, listener removal, worker_thread, and MFC ordinal 4262 CCmdTarget::InternalRelease. Original pane destructors use virtual slot +4, unlike earlier one-slot stubs. Constructor trial still matches after adjusting those stubs. Actual pane types/ownership template, resource pointee, globals, EH metadata and runtime linkage remain unproven; shared candidate is not swapped. Evidence shared-layouts/main-frame-destructor-trial-working-probe.json.

Frame pane RTTI verified in original PE: CSelectionCaption derives CXTCaption/CWnd, CDataModelPropGrid derives CSelectionPropGrid/CPropGrid/CXTPPropertyGrid/CWnd, CXTSplitterWnd derives CSplitterWnd/CWnd. Primary deleting-destructor slot +4 resolves respectively to wrappers 00466920/00431140/00708d30 and destructors 00466510/004310f0/00708280. Constructor/destructor trials now use incomplete declarations based on real XTP bases instead of synthetic vtable slots; both still match relocation-masked. Actual complete pane layouts, virtual ABI and owner template remain open. Evidence main-frame-pane-rtti-working-probe.json and updated frame constructor/destructor trial receipts. No active swap.

Frame docking handler 004314e0 calls the same replacement function 00430440 for all three pane owners at 00431587/004315f5/00431699. A real boost::scoped_ptr<CWnd>::reset emits an exact 32-byte relocation-masked match; std::auto_ptr<CWnd>::reset emits 34 different bytes with different ordering/self-check. This supports scoped ownership and rules out that standard auto_ptr implementation as the directly called reset, but folding means exact original template identity remains unproven. Inactive compiler evidence shared-layouts/frame-pane-ownership-working-probe.json. No runtime swap or new gate claim.

Recovered inactive ActiveDocView native interface and lifetime: constructor 00405d50 (43), destructor 00405d80 (26), std::set insert 005e8c40 (239) and erase 005e9f60 (106) all match relocation-masked; original calls and pure virtual RTTI/vtable verified. Global registry at 0096c23c corresponds to set shape; its initialization/data identity, callback pointee types and remaining exception/relocation ABI remain unverified. Original CDataModelPropGrid callback 00442900 returns with ret 0x10, consistent with two by-value shared_ptr arguments. Evidence shared-layouts/active-doc-view-working-probe.json. Inactive, no gates rerun.

Cleanup/native-source checkpoint 2026-11-01: old nested packages, pilot folders, root build outputs, unused diagnostics and redundant findings Source archived with hash receipts; newer sources retained. Source/{App,Network,RbxView,Rendering,Recovered,Include} exposes canonical project divisions. Player and P6 rebuild pass; P5 combined and P6 scoped gates pass current artifacts. Fall max y error 0.07493234 < .10. Jump original Run failed before measurements, so no fresh jump pass. Selected PE observer 3018/14394 unchanged (no integration gain). Recovered CRobloxDHtmlDialog constructor/destructor/runtime class/deleting destructor/OnInitDialog/eventsink getter/external dispatch/two browser callbacks/URL trust wrapper: ten relocation-masked matches; inactive pending complete vtable/data/EH and runtime gate. Evidence cleanup-rebuild-verification-20261101/receipt.json and shared-layouts/dhtml-dialog-working-probe.json. Full native roadmap remains open.

Native dialog continuation: CRobloxDHtmlDialog has ten matching bodies, 121 original virtual slots verified against MFC ordinals or local bodies, native runtime size 0x130 and event entry data checked. Constructor-forced isolated link retains 19 class bodies; primary vector-deleting slot resolves to scalar deleting destructor as expected. Native CAboutRobloxDialog now has ten matching constructor/destruction/runtime/message/HTML events/init/document-complete/OK/factory/base-getter bodies. Explicit derived destructor required original vptr stores; base destructor remains compiler-generated. DoDataExchange 00401390 and its CFileVersionInfo/G3D helpers remain next missing native edge. Existing generated DoDataExchange source uses provisional aliases; actual 00509840 is G3D::System::describeSystem, GL methods are G3D::GLCaps, and 0046a440 requests FileVersion (not ProductVersion). Do not activate base alone: About HTML ButtonOK needs derived DHTML map and UpdateData(FALSE). No runtime swap or integration gain; active P5/P6 artifacts still match previous gates. Evidence shared-layouts/dhtml-dialog-working-probe.json and shared-layouts/dhtml-dialog-isolated-link/receipt.json.

Native About swap: full CAboutRobloxDialog and CRobloxDHtmlDialog now replace generic CDialog in adapted OnAbout. Existing native DoDataExchange source adopted with real G3D::System/GLCaps and shared CFileVersionInfo types; 732-byte DDX body and four GL display helpers match. File-version constructor/Create/GetFileVersion/Reset match; typed GetVersionInfo remains 203-byte register mismatch and receives zero exact credit. Fresh P5 combined and P6 scoped gates PASS. Original About HTML shows version 0, 3, 809, 0 and system info. Physical Escape stopped Computer Use before manual OK activation; that UI action is unproven. Same observer, reconstructed old shell COFF checked against saved old PE, zero COFF/PE mismatches: 3018/14394 -> 3049/14468 selected relocation-masked matches (+31 net). This differs from original 331/4152 metric and raw PE identity. Exact source/artifact evidence p6-native-about-swap-20261101/swap-evidence.json. Native CRobloxApp/CMainFrame and remaining roadmap open.

Typed frame-pane recovery: original RTTI identifies RBX::CMarshalWindow : ATL::CWindowImpl<CMarshalWindow,CWindow,CWinTraits<0x56000000,0>>. Real ATL::CCriticalSection (not CComAutoCriticalSection) makes constructor 00432c50 match 140 bytes and critical ctor 004328c0 match 113. Native post 00432950, OnFinalMessage 00432a70, message map 00432a90, inherited GetWindowProc 0041a400 and deleting dtor 00432b10 match. Explicit marshal-window dtor required original vptr store. OnDestroy remains 179-byte/8-byte-difference mismatch, no credit. Native EventData RTTI identifies EventDataBase and weak ownership +4/+8; weak pointee is not yet verified. MarshaledListener actual std::vector<EventDataBase*> + thread id + CMarshalWindow pointer gives size 0x24, ctor 004661e0 118 and dtor 004663c0 113 both match. FilteredListener adds no storage. Typed CSelectionCaption : CXTCaption + ActiveDocView + FilteredListener, with DataModel/Selection shared owners, gives native size 0x1c8 and offsets 0x1b8/0x1c0; ctor 00466880 150, GetRuntimeClass 00465de0 6 and filter 00466670 5 match. Complete message/virtual ABI, callback pointee identities, registry globals/dispatch and property-grid layout remain open. Frame ctor/destructor trials now include this real caption header and still match 483/309. Evidence shared-layouts/frame-marshalling-working-probe.json. Inactive: active native About EXE and player hashes match prior P5/P6 gates; no new runtime count credit (3049/14468 selected matches retained).

Property-grid/shared-frame checkpoint: CPropGrid/CSelectionPropGrid/CDataModelPropGrid use real CXTPPropertyGrid, Listener bases, boost::recursive_mutex, pointer vector/maps/set and string set. Sizes 0x238/0x244/0x248 and member offsets pass. Eight lifecycle/runtime bodies match in separate TUs; four tree-ctor call sites bind to matching native helpers (three distinct constructors). Prior mined TU incorrectly treated last two trees as pointer maps; corrected from native node widths/calls. Pointer payload identities and full virtual/message/selection behavior remain open. Canonical CMainFrame now owns actual recovered pane types with scoped_ptr; ctor/dtor remain 483/309-byte matches without generated header substitutions. All seven coupled frame probes pass. Fixed stale color-vtable fixture to compile real ctor; restored original CString conversion at save/restore/close sites after detecting wrong GetString import hidden by relocation masking. Three obsolete generated header/trial stubs archived with hashes. Active EXEs unchanged; prior P5/P6 gates remain artifact-valid, running selected metric 3049/14468, no runtime gain. Findings export copied 8336 files but exact verification found concurrently modified launcher/four verification indexes and unowned Source reappeared; clean export NOT claimed, live files preserved. Evidence shared-layouts/frame-property-grid-checkpoint.json. Next: selection/property callbacks and caption/marshal behavior/vtables before frame runtime swap.

# Native frame pane callback checkpoint

Recovered 14 relocation-masked bodies across active-document activation/refresh,
property-grid model changes, caption lifecycle, selection changes and text.
00405aa0 gets both current/previous models through CRobloxDoc::getDataModel;
ActiveDocView second argument corrected from Instance to DataModel. Native
571-byte activation and 75-byte refresh use real Boost/STL/shared declarations.
Caption text uses AbstractFactoryProduct::getClassName/Name, not the mined
fake reflection descriptor. Message map at 0081bb1c, CWnd parent import ordinal
4030, WM_CREATE and selected calls/global references verified.

Evidence: shared-layouts/pane-callbacks-working-probe.json. Coupled marshalling,
property-grid and frame constructor probes pass. Sources remain inactive;
P5/P6 executable hashes still match About-swap gate receipts. No runtime
credit added; runtime gates not repeated without a swap. Next: marshaled
selection dispatch/detach and window registry, then remaining pane/frame ABI.

# Native marshal/window checkpoint

27/27 selected window, registry, listener, event and caption lifecycle bodies
match. Native queue insertion/removal, dispatch/filter and detach recovered.
GetWndClassInfo uses inherited ATL implementation; Create 00432b50 matches.
Old EventDataBase 0x0c/weak-pointer hypothesis disproven by destructor00421110:
base4, derived strong source owner+4/+8, listener+0x0c, event+0x10, total0x20.
Real remove body resolves EventData destructor unwind state; corrected base
lifetime resolves OnDestroy. Six physical layouts verified.

Isolated NativeMarshalWindowRuntime PE retains11 selected exact-body matches.
Three hidden runs prove two-thread window reuse, reference counts, dispatch,
queued-event deletion, destroyed HWNDs and empty registry: executed2/deleted4.
Fixture event is diagnostic; this does not prove native Selection payload
delivery or game integration. Original global initialization remains open.
14 pane callbacks, property-grid layouts and frame ctor/dtor probes pass.
Evidence: shared-layouts/marshal-dispatch-checkpoint.json and bound receipts.
P5/P6 game hashes unchanged; metric stays3049/14468, zero game credit here.
Next edge: CSelectionPropGrid::setSelection00442650 (destructor00430700),
then remaining property behavior before native frame swap and P5/P6 gates.

# Native property-grid behavior checkpoint

Twelve selected bodies match using shared headers and real Boost/STL/MFC/XTP:
selection setter00442650 (680), grouping add/remove00442350/00439660,
instance add/remove004423f0/00439cd0, selection event00442490 (325), property
event00439370 (267), OnCreate004385f0 (62), GetMessageMap00440d20 (6),
refresh00439d70 (754), reflection rebuild004391d0 (327), and slot90 dispatch
thunk00438010 (8). Selected call/storage/message bindings verified separately.

Corrected provisional types: +0x218 groups ClassDescriptor pointers to vectors
of shared Instances, not strings. Original RTTI type0092f58c/COL008802e8 and
one-slot pure vtable008137a4 prove CPropGrid::Item; vector+19c, map+1b4 values
and set+1f8 hold Item pointers, not Instance or primary XTP item pointers.
Physical grid sizes remain238/244/248 hex. Native map008145dc routes WM_CREATE
and WM_USER+101. SDK primary vtable has90 slots; CPropGrid adds slot90 for
property-row creation00440e30. Existing CPropGridItem lifecycle tests did not
prove these payload identities; earlier placeholder hypotheses are superseded.

Refresh matches with actual DataModelLock.cpp definitions visible in the same
translation unit. Recorded compiler recipe pairs existing genuine sources;
no copied anonymous lock layout or placeholder body. Rebuild walks authentic
ClassDescriptor derived classes and property containers under reflection sync.
Its addProperty callback is virtual:00438010 is a dispatch thunk, not the body.

Coupled eight grid lifecycle bodies, 14 pane callbacks, frame ctor483/dtor309
and physical layouts pass. Evidence: shared-layouts/selection-grid-checkpoint.json.
Sources remain inactive. P5/P6 artifact hashes unchanged; selected game count
stays3049/14468 with zero integration gain. Next: native property-row factory
00440e30 (1321 bytes), concrete editor layouts/constructors, reverse-map type
and complete bindings before native frame swap and runtime gates.

# Native editor constructor / Item-layout checkpoint

Corrected CPropGrid::Item size4 hypothesis: one RTTI slot proves virtual order,
not storage extent. Constructor0043a070 (125) and collector00439600 (91) now
match using real vector<const ClassDescriptor*>+4 and grid pointer+1c, size32.
Collector recursively caches actual derived-class descriptors. Outer grid sizes
remain238/244/248 hex because they store Item pointers. Earlier size4 assertion
is superseded; do not use it as layout evidence.

Six editor constructor bodies match: bool XItem0043a0f0 and XBoolItem0043d330,
float0043a650, int0043ab10, Color30043af00, string0043b860. Five of12 actual
factory constructor paths covered. Generic rows use genuine SDK bases, Item32
and descriptor pointer. SDK field+fc is m_bHidden, not m_nFlags: rows start
hidden until update. Native std::string c_str import verified by exact named
MSVCP90 import using existing noinline getter recipe. Real category lookup
00438630 (83) matches genuine FindItem/AddCategory/Expand behavior. Constructor
units and category compile separately; source pairing changes MSVC inlining.

Original factory allocations and RTTI/base offsets mapped for all12 branches.
No anonymous storage/editor placeholder classes introduced. Current evidence:
shared-layouts/property-editor-checkpoint.json binds14 grid bodies, seven
editor/category bodies, physical layouts, frame ctor/dtor and14 pane callbacks.
Editor update and SDK override bodies are still unresolved, so constructors
do not establish complete classes or runtime equivalence.

Source audit: mined row attachment unit roc_claudeA_selgridbd1b79475b721655.cpp
uses fake static Map::find storage to force caller stack reuse. Preserved as
experiment, excluded from native adoption; audit receipt records its hash.
Recover actual category insertion, descriptor map and Item-vector attachment
00439ba0 instead. Next: remaining editor fields/constructors/virtual behavior,
real attachment and factory00440e30 before frame swap and runtime gates.
P5/P6 executable hashes unchanged. Selected game metric remains3049/14468;
zero game integration gain from these inactive sources. No commit.

# Native property attachment and value checkpoint

Four real row-attachment bodies and six editor value-operation bodies match relocation-masked original code. Three attachment callees also match. Six constructor bodies cover five of twelve factory paths. Float equality and two numeric parsers remain nonexact; editor update, write, apply and factory remain open. Receipts: shared-layouts/property-attachment-working-probe.json and editor-values-working-probe.json. Source hashes checked against current tree. These candidates remain inactive; no executable integration credit or new runtime gate claimed.

# Doc live-swap preparation

Native Doc now has five additional relocation-masked matching handlers: undo 00453670, redo 004538b0, their enable/caption handlers 00453750/00453990, and selection enable 00453af0. Direct history/selection calls verified in shared-layouts/document-history-working.json; history query names remain provisional, imported bindings and live linkage open. Original compiler recipe marks std::string::c_str and CString conversion noinline. Baseline 20-body Doc constructor/destructor probe also passes. Candidate remains inactive. Message-map handlers still need complete implementations; no live swap or new P5/P6 gate claimed.

Doc/View and server follow-up: five Doc history/selection handlers now pass reproducible profile and direct-call checks, alongside the 20-body Doc constructor/destructor probe. View service scaffolding at 00452a00/0058c5e0 replaced with typed ChangeHistoryService factory and method declarations; target calls and original binary type string verified. View full OnInitialUpdate remains nonmatching; service layout, names and linkage unproven. DataModel notifier bases at +150/+170 use typed inheritance. No live swap. Read-only server DB: last accepted integration 2026-10-31 17:06:56 UTC; subsequent RunService jobs failed on missing P2Lighting ownership artifact and 39 credited bodies missing from refreshed baseline. Server ownership guard should remain; investigate baseline preservation. Evidence shared-layouts/server-gap-investigation.json.

Doc command continuation: pause enable 00454040 (303), stop enable 00454170 (396), and run enable 00454300 (393) now match relocation-masked original code. Original RunService, Players::findLocalPlayer and network client call targets verified by record_native_document_history.py; existing 20 Doc bodies and constructor/destructor probe still pass. Eight additional Doc handlers are inactive, leaving 20 of the previously identified 28 handler symbols unresolved. P5/P6 unchanged; no live swap.

Doc status handlers 00450a70 and 00450c00 each match 387 bytes relocation-masked; original direct targets 005757d0/005757e0 verified. DataModel now declares nonvirtual timing accessors; their implementation, names and linked behavior remain open. Ten additional Doc command bodies and baseline 20 plus constructor/destructor probe pass. No live swap or P5/P6 rerun.

DataModel timing accessors 005757d0 and 005757e0 now use typed RunService game time and G3D Stopwatch::smoothFPS; both match original 13-byte bodies. Added inline accessors do not change storage. Evidence shared-layouts/datamodel-timing-working.json; full RunService lifetime and linked runtime remain open. Existing Doc 20-body constructor/destructor and ten-command probes pass. No runtime swap or new gates.

Doc script enable 00454490 matches 309 bytes with genuine donor ScriptContext declaration and inline globalState check. Factory target 0042de90 verified. This proves accessed field offset 0x138 only; complete ScriptContext constructor/destructor and runtime ABI remain unproven. Eleven additional Doc command bodies and original 20-body Doc lifecycle probe pass. No live swap.

ScriptContext layout correction: original destructor 005ae730 calls boost::thread destructor 005a6840 on owned +1cc, not shared-count release. Replaced provisional shared owner with candidate int +1c8 and scoped boost::thread +1cc. Compiler asserts size 0x1f8 and allocator +1f0; destructor matches all 435 bytes and direct thread destructor target. Constructor remains one byte different (504/504), so complete layout/lifetime remains unproven. Twelve Doc command and original Doc lifecycle probes pass. Evidence shared-layouts/scriptcontext-lifetime-current.json. No live swap or new P5/P6 gates.

Doc simulation duty-cycle status 00450d90 matches 401 bytes; typed DataModel accessor 005757f0 matches 35 bytes under original /fp:fast. Direct target verified, three DataModel timing accessors and thirteen Doc command bodies pass; prior 20-body Doc lifecycle probe passes. No live swap; P5/P6 unchanged.

Doc heap status 00454920 matches 409 bytes with original noinline string profile; direct 005a6bc0 target identified as existing RBX::Log::formatMem in real vendor Log.h/Log.cpp, replacing provisional free-function label. Fourteen Doc command bodies and 20-body Doc lifecycle probe pass; ScriptContext full lifecycle remains unproven. No live swap or new P5/P6 gates.

Doc abuse-report enable handler 00454f30 matches 297 bytes; original direct Players factory 00412710 and predicate 00496390 observed. Predicate name and byte return type provisional; real implementation/linkage still open. Fifteen Doc command matches, original 20-body lifecycle probe pass; no live swap or new P5/P6 gates.

Correction to abuse-report 00454f30: genuine donor Network/Players.h declares bool canReportAbuse() const; previous unsigned-char declaration matched bytes but contradicted donor ABI. Changed to bool, candidate 293/297 nonexact, removed exact credit pending original ABI proof. Original predicate 00496390 checks reporter+174 or Client::clientIsPresent (0049fe20). Trial using genuine Players.h fails compilation with current native Instance interface; preserve error evidence, no activation. Doc 20-body lifecycle and fourteen command probes pass.

Players predicate recovery: actual donor Network/Players.h declares bool canReportAbuse; real implementation 00496390 matches 33 bytes and its Client::clientIsPresent target 0049fe20. Doc now includes genuine Players declaration, removing provisional local class. Restored donor Instance nonvirtual typed-parent/root helpers and XmlState forward declaration; real Instance constructor/destructor still match. Native IRenderable header uses accepted player overlay access, without layout change. Fourteen Doc command bodies, 20 Doc lifecycle bodies and Instance lifecycle probes pass. Players complete constructor/destructor/layout and Doc abuse handler exactness remain unproven; no live swap. Evidence shared-layouts/players-abuse-working.json.

Real Players donor constructor 0049bdc0 and destructor 00499630 match 461/503 bytes using shared native Instance and accepted IRenderable declarations. Original factory 00411fd0 allocates 0x1b0; compiler fixture verifies Players size. Original abstract-base vtable 008227b0 -> adjusting thunk 00499850 -> deleting destructor 00499fb0 -> real destructor verified. Full virtual/data bindings and runtime activation remain open. Evidence shared-layouts/players-lifetime-working.json. No live swap or new P5/P6 gate.

Doc save-selection handler 0044f7c0 matches original 258-byte body with existing CString noinline profile. Original IWorkspace virtual slot 8 (+0x20) verified against recovered SaveSelectionToFile interface; original BSTR constructor direct target 00401180 verified. Fifteen Doc command bodies and baseline Doc constructor/destructor probe pass. No live swap or fresh P5/P6 gates.

Doc publish/save dialog dependency: original RTTI establishes CSaveToRobloxDialog : CRobloxDHtmlDialog. Recovered URL overload 0044eeb0 (140), save-dialog ctor 0045fe80 (101), dtor 0045fe20 (18); all match relocation-masked. Original factory/SetExternalDispatch and destructor calls verified, MFC import ordinal 6275, size 0x130 fixture passes. Existing 10 DHTML and About bodies, Doc lifecycle and 15 command probes pass. Complete virtual/data bindings, derived dialogs and runtime remain open; no live swap or new P5/P6 gates. Evidence shared-layouts/save-dialog-working.json.

Doc publish/save commands 0044fc50/0044fcc0 each match 104 bytes using real derived dialog types; derived constructors 0044f500/0044f660 each match 148 bytes under CString noinline profile. Native base constructor/destructor and existing DHTML/About/Doc probes pass. Original 004060d0 copies a global CString at 0096dcf0; applicationBaseUrl declaration remains unresolved until global identity/initialization verified. Derived vtable/data bindings, complete class behavior, live swap and P5/P6 gates remain open. Evidence shared-layouts/save-dialog-working.json and document-history-working.json.

Application BaseUrl global 0096dcf0: original CRT initializer 007ef840, destructor 007fade0 and accessor 004060d0 match typed CString source (23/11/32 bytes). All global relocations bind to same original address; 0044c760 references same storage and BaseUrl registry key 00816bb8. Complete settings/startup flow still unverified and inactive; no live swap. Evidence shared-layouts/application-base-url-working.json.

Save dialog event ABI: original base adds GetMessageMap, GetEventSinkMap and GetDHtmlEventMap overrides; recovered all three plus WindowClosing 0045ff20. WindowClosing cancel pointer is VARIANT_BOOL* (16-bit), not BOOL*; corrected before activation. All four bodies match, including shared-address empty message map; count three new original addresses. Original 111 primary and 10 sink slots show derived classes differ from save base only in deleting destructor; same pattern verified in compiled objects. Event sink entries, event ID/handler/string bindings verified. Further base vtable/data linkage and runtime still open; Doc seventeen-command probe passes. No live swap. Evidence save-dialog-working.json.

Save dialog derived constructor relocation audit now verifies BaseUrl accessor 004060d0, CString concatenation 0040e160, base constructor 0045fe80, original primary/sink vtables, and exact /IDE/Upload.aspx and /UI/Save.aspx?type=Model literals. Constructor code equality alone did not establish these bindings. Updated reproducible verifier passes; original CRT global/startup population and runtime linkage still open. No live swap or P5/P6 rerun.

Isolated P6-derived link now retains both native publish/save dialog constructors, WindowClosing and BaseUrl global/accessor with existing P6 and engine objects. Link passes; map and input/object/library hashes saved, reproducible by tests/record_native_save_dialog_link.py. This forces symbols into a separate diagnostic PE only; no dialog invoked, startup BaseUrl population/complete runtime ABI unproven, active binaries and gates unchanged. Evidence shared-layouts/save-dialog-link-working.json.

Doc stop/reset handler 00455580 now uses real RunService, DataModel::clearContents, SerializerV2::load and Workspace::joinAllHack; 669-byte relocation-masked body matches. Direct calls 00554da0, 00578ef0, 00593500 and 005a0de0 verified. 005a0de0 tail-jumps to World::joinAll; donor Workspace.cpp names wrapper joinAllHack. Dependencies/full World ABI and runtime still open. Baseline Doc ctor/dtor and 18 command probes pass. No live swap or new P5/P6 gates. Evidence document-history-working.json.

Doc model-insert command 00450f30 matches 436 bytes using native CFileDialog, ifstream, DataModel lock and CWorkspace::insert. Direct original insert target 0046b9d0 verified; CWorkspace insert implementation and linked behavior remain open. Nineteen Doc command and existing Doc constructor/destructor probes pass. No live swap or new gates.

CWorkspace insert dependency audit: original 0046ae30 consumes a 28-byte value, unlike donor const-reference declaration; 00421cb0 finds the provider and invokes Selection factory 00409620. Original insert checks [CWorkspace+2c]+1b4 (current header identifies RunService); constructor/destructor and identity still require proof. Parser, serializer, insertion and selection targets recorded in shared-layouts/workspace-insert-dependency-evidence.json. Doc constructor/destructor and 20 bodies reverified at 3895281473 in document-after-insert-audit.json. No live swap or new P5/P6 gates.

CWorkspace::insert inactive native-type candidate compiles; 715 vs original 606 bytes, not exact. Parser ctor/destructor inlining differs; name-lookup symbol identity, all dependency bindings and exception behavior remain unproved. Native Doc (20 bodies), Doc commands (19), Instance ctor/dtor, workspace constructor/getter/writer, RunService probes pass after header additions. See shared-layouts/workspace-insert-candidate.json. No live swap or new P5/P6 gates.

Original TextXmlParser ctor 00415350 and dtor 004147c0 prove map<string,string> at +0x28: donor sizeof 0x28 was wrong for June; native overlay restores sizeof 0x48. Constructor matches 91 bytes. With verified MSVCP90 basic_ios::rdbuf import profile, CWorkspace::insert original 606-byte main body matches; catch funclet, parser dtor (88 vs 82), full link and runtime remain unproved. Doc 20-body and 19-command probes pass. No live swap, P5/P6 not rerun.

CWorkspace insert 0046b9d0: 606-byte main plus 91-byte catch funclet match under original MSVCP90 rdbuf import profile; all five catch relocations and targets verified. TextXmlParser implicit destructor 004147c0 matches 82 bytes when compiled separately with /Ob1; ctor 00415350 matches 91 bytes. Test uses a separate destructor declaration in the insert compiler profile; unified build/link and remaining main-call binding verification remain open. Native Doc probes pass; no live swap, no new P5/P6 gates.

Insert dependency progress: Selection::front 00413c20 matches 235 bytes, including original empty-selection behavior; Selection::setSelection iterator template 00413b00 matches 141. Seventeen insert main call relocation identities mapped to original targets; actual linker resolution remains to be checked. Probe shared-layouts/workspace-insert-candidate.json passes. No live swap, P5/P6 not rerun.

Native insert isolated P6-derived link now succeeds, no unresolved symbols; map verifies parser destructor, Selection::front, Instance class lookup, and existing exact getClassNameStr from RbxgsApp linked Instance.obj. Corrected previous provisional name lookup: original compares class names. Lookup 0046ae30 matches 349 bytes; existing getter 0041f2b0 matches 44. Evidence shared-layouts/workspace-insert-link.json and workspace-insert-candidate.json. Compiler profile has separate parser-dtor declaration; runtime invocation and Doc swap remain unproved; no new P5/P6 gates.

Full native Doc shell diagnostic: generated shell replaces adapted CRobloxDoc with native declaration, compiles, then link fails with 28 unresolved symbols after including already-proven timing and Players predicate objects (initial 32). Eight Doc message handlers, SaveModified, initializeCommands, workspace load, history/service and verb lifetimes remain. Exact input hashes/errors: shared-layouts/document-swap-link-trial.json. No runtime swap; P5/P6 not rerun.

Native workspace load 0046aa70 matches 155 bytes with all four original direct targets. Shared document exception logger 00428850 matches 146 bytes and original StandardOut targets; both original Doc error paths now call it. Doc lifecycle and 19 command probes pass. Isolated native Doc link unresolved count 28 -> 25; evidence workspace-load-working.json, document-exception-working.json, document-swap-link-trial.json. No runtime swap or P5/P6 gates.

Doc script heap command 004545d0 matches 480 bytes with original GC, allocator, formatting, thread and StandardOut targets; ScriptContext::gc 005a86c0 matches 24 and LuaAllocator::getHeapStats 005c8940 matches 20. Doc lifecycle and 20 command probes pass; isolated Doc link errors 25 -> 23. No runtime swap or P5/P6 gates. Evidence shared-layouts/document-history-working.json and document-swap-link-trial.json.

Original Verb, RunStateVerb and EditSelectionVerb destructors plus Verb enabled/checked, EditSelectionVerb enabled and Selection ServiceClient createService now match seven bodies; original direct calls verified. Added native bodies to isolated Doc link: unresolved 23 -> 20. Doc lifecycle and 20 command probes pass. Constructor, complete vtable and live behavior of related classes remain open. Evidence shared-layouts/verb-lifetime-queries.json, document-swap-link-trial.json; no P5/P6 gate.

CWorkspace safety methods match original 00404d20/00404db0, including both direct site-check calls to 00403b60 and original COM vtable slots. Workspace constructor and destructor 0046ab60/0046a9b0 both match. Site validation remains unresolved, never stubbed. Doc lifecycle and 20 command probes pass; isolated Doc link 20 -> 19 unresolved. Evidence workspace-safety-working.json, workspace-after-safety.json and document-swap-link-trial.json. No runtime swap or P5/P6 gates.

Workspace site URL/zone lookup 00403210 matches original 505 bytes using real IObjectWithSite, IServiceProvider, IWebBrowser2 and IInternetSecurityManager; IID values verified against original PE. Original location-URL failure behavior preserved. Workspace ctor/dtor, safety slots and Doc probes pass. Domain/site validation 00403b60 remains unresolved; isolated Doc link still 19 errors. Evidence workspace-safety-working.json; no live swap or P5/P6 gates.

Workspace URL trust and security-zone checks 0041dcd0/0041dd40 match original with original MFC CString import profile and verified direct call targets. Existing linked RBX::Http::trustCheck 0056a2e0 differs (624 vs original 638 bytes); do not treat it as native exact. checkSite 00403b60 candidate compiles but is not exact; error reporter/context and runtime linkage remain unresolved. Evidence workspace-site-trust-working.json. No live swap, no P5/P6 gates.

Native Doc abuse-report command 0044fd30 matches 195 bytes with original BaseUrl and DHTML constructor targets; Doc ctor/dtor, 20 baseline bodies and 21 command probes pass. Isolated Doc link unresolved 19 -> 18. The visit/server command helper at 0044ff40 uses original register-passing convention (ECX and EDI); genuine DocumentLaunch.cpp candidate compiles but does not match (396 original, 389 profile), so not linked. No live swap or P5/P6 gates.

Selection service cache restored from existing native sources: find<Selection> 00415200 (320 bytes), doGetClassIndex 00413810 (91), newIndex 00572690 (12), and class-name lookup 00572a90 (167) match, with direct targets checked. Shared Name declare template adopted from accepted native header, no storage changes; original cache/once-flag identity and live ABI remain unproven. Native Doc/workspace/verb probes pass; isolated Doc link now 17 unresolved. Evidence service-selection-working.json and document-swap-link-trial.json. No P5/P6 gates or live swap.

ChangeHistoryService native candidate: original factory size 0x1a4, RTTI and typed list/iterators/flags/connections checked; constructor 0058ab90 and destructor 0058c1c0 both match including direct targets. Undo/redo query methods 00587b70/00587a90 also match. Context identity, record behavior, vtable/data linkage and runtime remain open. Doc probes pass; isolated Doc link unresolved 17 -> 15. Evidence change-history-layout-working.json and document-swap-link-trial.json; no P5/P6 gates.

Original change-history play/unplay 00588780/0058a130 and record dispatch 00588710/0058a040 match native source; original direct calls and unplay-property target checked. Diagnostic Doc link unresolved 15 -> 16 because two history methods resolve while three deeper record operations remain. Doc lifecycle and 21 command probes pass. History record behavior/data/vtable and live swap remain open; P5/P6 not rerun. Evidence change-history-layout-working.json and document-swap-link-trial.json.

HistoryItem play 00588440 and undo 00589a20 now match 140 and 541 bytes; undo map lookup, deque and play targets verified. Isolated Doc link 16 -> 15 unresolved. Original descriptor virtual slot 5 handles Reflection::Value, while donor slot 5 accepts std::string; ABI remains incompatible and history playback must not be activated until corrected. Twenty-one Doc command probes and change-history probe pass. No live swap or new P5/P6 gates. Evidence change-history-layout-working.json, history-property-abi-conflict.json, document-swap-link-trial.json.

ChangeHistoryService::setEnabled 0058c8b0 matches original 97 bytes; security context, permission check, start, reset, disconnect and permission-string relocations verified. Diagnostic link now 16 unresolved: setEnabled resolves but start/reset remain. Reset candidate 0058c3c0 is 271/300 bytes, inactive and not linked. No live swap; P5/P6 not rerun.

ChangeHistoryService::reset 0058c3c0 matches 300 bytes after restoring implicit record destructor. HistoryRecord constructor 0058bf20 and destructor 0058bed0 match 90/77 bytes; HistoryItem implicit destructor 00589720 matches 174. Direct map/lifetime targets checked; HistoryItem constructor and descriptor ABI remain unproven. Isolated Doc link 17 -> 15 unresolved after real record constructor and destructor bodies; start and property operations still missing. Change-history probes pass; no live swap or new P5/P6 gates.

History startup ABI: original event globals identify DescendantAdded, DescendantRemoving, ItemChanged; callback thunks dispatch vtable slots 16-18. Added those virtual declarations and verified compiled slots against original. All three callback bodies 0058b870/0058b970/0058ba70 now match 241/241/193 bytes with direct targets and RTTI relocations checked. Evidence history-start-abi.json and change-history-layout-working.json. Event signal ABI, item construction and activation remain unproven; no live swap or P5/P6 rerun.

HistoryRecord::get 0058b6c0 matches 431 bytes; HistoryItem constructor 00589890, copy constructor 00589cd0, destructor 00589720 and reset 00588f60 match 185/144/174/70 bytes. Original map, copy, destructor and reset call targets verified. Diagnostic Doc link incorporates callback and lookup bodies: 15 -> 18 unresolved when new deeper dependencies exposed, then reset reduces to 17. Signal/property ABIs and live integration remain unproven; no P5/P6 rerun.

HistoryItem::update 00589650, captureAll 00589530 and capture 005894c0 match 205/283/25 bytes; parent descriptor global 00973d34, capture callbacks and direct targets verified. Restored donor propParent declaration and getParent accessor; property virtual ABI still incompatible and not called. Instance ctor/dtor, 21 Doc command bodies and change-history probes pass. Diagnostic Doc link still 17 unresolved, now including captureProperty and reflection iterator increment. No live swap or P5/P6 rerun.

Property iterator correction: donor left Iterator::operator++ undefined; original 005882f0 inlines vector iteration. Restored typed increment specialization in history source and compiled that unit without /D_RELEASEASSERT, matching original 158-byte loop and all state methods. Earlier 197-byte helper was nonmatching despite exact captureAll caller. Diagnostic Doc link 17 -> 16 unresolved; property ABI conflict remains. Change-history probe passes; no live swap or P5/P6 rerun.

Isolated 2008 descriptor candidate from existing roc_property_genuine_all_variant_overrides_header4b48a3f3f80fea74.cpp restores missing isWriteOnly/getVariant/setVariant slots. With candidate only, HistoryItem captureProperty 00589410 (176), applyProperty 005872a0 (37), unplayProperty 005884d0 (563) match, including direct targets and parent global. Diagnostic Doc link 16 -> 13 unresolved. This trial mixes incompatible descriptor ABIs and must never run: descriptor ctor/dtor, full slots, actual Value identity, global storage and cross-module linkage still unproven. Production shared header unchanged. Evidence history-property-trial.json and document-swap-link-trial.json; no P5/P6 rerun.

Parent-property isolated ABI proof: constructor 00559920 (169) and deleting destructor 00631180 (47) both match when IIDREF uses original novtable behavior; constructor vtable addresses and direct targets verified. Original get/set object's slots 0/1 both return false, slots 2/3 are getter/setter; candidate restores isWriteOnly slot and concrete RefPropDescriptor override 00565960 matches 10 bytes. Original virtual slots 4/5 still need real bodies, remaining descriptor families and cross-module layout unverified. Trial only; live shared headers unchanged. Evidence history-property-trial.json. Diagnostic Doc link still 13 unresolved; no P5/P6 rerun.

Parent-property ABI trial now matches original concrete getVariant 00585420 (254), setVariant 005da5b0 (144), GetSetImpl getter 005cf660 (41) and setter 00563b00 (55); direct Value/shared_ptr targets and four get/set vtable slots verified. Parent descriptor constructor/deleting destructor and history methods still match. Other descriptor families, full vtables and cross-module ABI remain unproven; isolated trial only, no live header change. Diagnostic Doc link remains 13 unresolved. Evidence history-property-trial.json; P5/P6 not rerun.

Parent descriptor ABI trial additionally matches isReadOnly 0059d490 (9), equalValues 005ee1d0 (50), getRefValue 00585360 (30). Tested setRefValue 005cd810 candidate remains nonexact (58 vs 52) and is not counted or linked. XML serializer/value types, remaining slots, other descriptor families and cross-module ABI remain unproven. Isolated proof history-property-trial.json passes; no live swap or P5/P6 rerun.

Recovered ChangeHistoryService::onServiceProvider override 0058c4f0 (76), including reset/disconnect targets; original and compiled primary vtable slot 12 checked. Parent RefPropDescriptor::setRefValue 005cd810 now matches 52 bytes with original polymorphic_cast target 005599d0. Both isolated probes pass. Context lifetime, descriptor ABI across modules and live swap remain unproven; Doc diagnostic has 13 unresolved, with existing object inputs (not a clean build of concurrent source edits). P5/P6 not rerun.

History startup source 0058c620 now matches all 656 bytes in isolated 2008 signal-declaration trial. Verified original record ctor, visit, commit, merge, signal connect targets, four callback thunks, three event globals and base string. Adding trial to diagnostic Doc link resolves start but exposes six deeper missing symbols, changing 13 -> 18 unresolved. Signal ownership/implementation and event data remain unverified; trial mixes ABIs, never run. Evidence history-start-trial.json and document-swap-link-trial.json; no production header change or P5/P6 rerun.

History startup traversal: restored donor visitDescendents template in isolated Instance overlay and original noinline CopyOnWrite::read profile. Original traversal 004a27e0 (358), read 004915b0 (42) and callback wrapper 00587420 (162) match; direct bindings and recursion verified. Diagnostic Doc link 18 -> 17 unresolved. Signal/descriptor ABIs and data ownership still unverified; overlay remains trial only, never run. Evidence history-start-trial.json and document-swap-link-trial.json; no P5/P6 rerun.

History startup signal trial: restored grouped connect(source, slot, group) overload based on existing TSignalDesc implementation. Original connect 004a3340 and 00588fb0 (71 each), shared signal lookup 005875e0 (82), and boost signal connect methods 004a3020/00588db0 (325 each) match with key direct targets verified. Diagnostic Doc link 17 -> 15 unresolved. Signal instance lifetime/layout, descriptor ownership/data and production ABI remain unverified; trial object remains inactive and must not run. Evidence history-start-trial.json and document-swap-link-trial.json. No P5/P6 rerun.

History checkpoint path: isolated typed startup trial now matches record empty 00587a20 (112), commit 0058c2c0 (245), mergeFirst 0058bf80 (363), prepare 0058c0f0 (199), record merge 0058bcb0 (402). Original call targets and merge-property callback verified; prepare's trim target is mergeFirst. Diagnostic link 15 -> 14 after commit/mergeFirst/prepare, then 16 after record merge exposes three deeper dependencies. Descriptor and signal ABIs remain unverified; trial must not run. Evidence history-start-trial.json and document-swap-link-trial.json; no P5/P6 rerun.

Corrected history record merge ABI: original 0058bcb0 calls std::map::operator[](key) then HistoryItem::operator=(value); prior provisional insertRecord(key,value)->finish() matched caller bytes but had wrong callee stack cleanup and was removed. Default HistoryItem ctor 00589950 (93), assignment 005899b0 (110), property merge 005894e0 (80), map operator[] 0058bba0 (269) now match with direct calls checked. Restored original ItemChanged signal global in isolated trial: constructor 00578790 (296), global initializer 007f3440 (37) and global cleanup 007fd660 (63) match; original global address 009751b0 and cleanup offset +18 verified. Diagnostic link 16 -> 13 unresolved, including new connectGeneric dependency. Signal/descriptor ABI remains unverified; trial must not run. Evidence history-start-trial.json, document-swap-link-trial.json. No live swap or P5/P6 rerun.

ItemChanged generic event connection recovered from existing native SignalDescImpl sources: connectGeneric 0057b680 (219), positional signal connect 00577d60 (275), generic slot constructor 0057acb0 (180) match original bytes and key targets. Original ItemChanged descriptor RTTI/vtable slots 0-2 checked against 0083004c, including connectGeneric slot 1. Diagnostic Doc link 13 -> 12 unresolved; history startup now has no unresolved symbols in this mixed-ABI diagnostic, but descriptor ownership, remaining virtuals and cross-module runtime remain unproven, so never run. Evidence history-start-trial.json and document-swap-link-trial.json. No live swap or P5/P6 rerun.

ChangeHistoryService service lookup 00452a00 (320), creation 00453000 (228), class-index getter 0044f360 (91), and Creatable factory 004150d0 (120) match, with original direct targets checked. Find and create require separate compiler profiles; explicit template instantiation separated to avoid selecting wrong COMDAT. Adding both and native service lifetime to diagnostic resolves Doc create, then exposes 14 more unresolved constructors/vtables/data: 12 -> 26. Shared cache identity, service descriptor and lifetime ABI remain unproven; mixed-ABI diagnostic must never run. Evidence service-history-working.json and document-swap-link-trial.json; no live swap or P5/P6 rerun.

Native Instance lifetime diagnostic: adding native ctor/dtor exposed duplicate createChild from RbxgsApp/Instance.obj. Both candidate and archive createChild match original 0055a470 (35 bytes) and bind same direct target 00420190. Added diagnostic-only compile profile omitting the duplicate candidate body, preserving both source providers; no forced linker override. Instance ctor/dtor still match. Link conflict resolves, while native Instance vtable/lifetime exposes additional unresolved dependencies: total 37. Full Instance/archive ABI remains unproven, mixed diagnostic must never run. Evidence instance-link-profile.json, instance-after-service-link.json, document-swap-link-trial.json; no live swap or P5/P6 rerun.

Native Instance base callbacks: seven callbacks match original bytes and history-service vtable targets, including parent notification 00557490. Adding them reduces diagnostic link errors 37 -> 23. Runtime ABI remains unproven; diagnostic must not run. Evidence instance-callbacks-working.json and document-swap-link-trial.json; no live swap or P5/P6 rerun.

Workspace site-check investigation: candidate 00403b60 is 393 vs original 399 bytes; adding it to the isolated Doc diagnostic changes 23 -> 25 errors and reveals missing zone validation, error reporter and GUID data. The out-of-line CString conversion hypothesis changed the candidate to 446 bytes and did not match, so the trial was reverted. Existing linked Http trustCheck also differs (624 vs 638 bytes). Candidate remains excluded; evidence workspace-site-trust-working.json. No swap or gate rerun.

GUID registry diagnostic: existing destructor 004b3760 still matches and exposes six registry dependencies (23 -> 28 link errors). Recovered lock 00563090 and unlock 005630e0 match original bytes, reducing errors 28 -> 26. Initial unlock candidate had reversed Windows imports, hidden by relocation masking; corrected and added original IAT target checks for both methods. Mutex identity and runtime semantics remain unproven; neither is runtime-cleared. Evidence guid-item-working-probe.json, guid-registry-mutex-working.json and document-swap-link-trial.json. No swap or gate rerun.

GUID registry initializer 0049a040 matches original bytes (96) with allocation, constructor 00499d60 and registry pointer 009705e8 targets checked. Adding it to the isolated link resolves initializer and globals but exposes the registry constructor: 26 -> 24 errors. Constructor, removal, global identity/ownership and runtime ABI remain open; diagnostic must not run. Evidence guid-registry-initialize-working.json and document-swap-link-trial.json. No swap or gate rerun.

Registry constructor trial: a 44-byte std::set<Guid::Data> plus mutex candidate matches 00499d60 (82 bytes) and direct targets 00589190 and 00563070. This does not prove the tree's actual key/value type, destructor or cross-TU layout; trial conflicts with provisional opaque declaration and is not linked. Evidence guid-registry-constructor-trial.json. No swap or gate rerun.

Registry container correction: original _Eqrange 004ad940 checks node flag at +0x19, whereas set<Guid::Data> uses +0x15. A map<Guid::Data, Instance*> candidate matches the original 171-byte _Eqrange, key erase 004af4c0 (106), iterator erase 004983f0 (220), and registry constructor. Mapped value identity, relocated calls, destructor and cross-module ownership still need proof; candidate remains isolated. Existing provisional remove name corresponds to standard tree erase, not yet linked as a native implementation. Evidence guid-registry-constructor-trial.json. No swap or gate rerun.

Registry map target audit: all direct calls in the three candidate tree methods resolve to their original comparator and tree helpers. Original registration 0049bba0 loads the same registry global and stores its GuidItem this pointer through the map slot at 0049bc12; original RTTI places GuidItem at Instance offset 0. This supports the pointer-valued map candidate, but does not prove its destructor or ownership. No swap or gate rerun.

Inactive shared GUID registry declaration now uses the supported GUID-to-Instance pointer map. GuidItem destructor still matches original 004b3760 and its erase target 004af4c0; shared registry constructor matches 00499d60 with original call targets. Diagnostic link resolves map removal and constructor, exposing mutex construction: 24 -> 23 errors. Registry destructor, singleton identity, mutex construction and cross-module ABI remain unproven; diagnostic must not run. Evidence guid-item-working-probe.json, guid-registry-constructor-trial.json and document-swap-link-trial.json. No swap or gate rerun.

Recovered Boost recursive mutex constructor 00563070 (31 bytes) and critical-section allocator 00594c10 (126 bytes). Original call and Windows import targets verified, including exception construction/throw targets; diagnostic link 23 -> 22 errors. Mutex and registry destruction, exception data identity, singleton identity and runtime ABI remain unproven; diagnostic must not run. Evidence guid-registry-mutex-working.json, guid-critical-section-working.json and document-swap-link-trial.json. No swap or gate rerun.

Doc active-document binding: existing recovered setActiveDocument(bool, CRobloxDoc*) matches 00405aa0, and its activeRobloxDoc global is original 0096c238. An isolated Doc compiler profile maps provisional names to these existing symbols; DeleteContents 004513c0 still matches 449 bytes with both original targets verified. Adding the recovered object changes diagnostic link 22 -> 24 errors, exposing three unprovided active-document globals rather than the old mismatched function. Shared data construction/ownership and ABI remain unproven; diagnostic must not run. Coordinated permanent Doc rename in TANDEM.md. Evidence document-history-working.json and document-swap-link-trial.json. No swap or gate rerun.

Active-document data recovery: native Doc pointer, ActiveDocView set and DataModel shared pointer reproduce original zero state and four static initialization/cleanup functions 007ee720, 007ee750, 007fa090 and 007fa050 with direct targets verified. Adding these globals resolves their diagnostic link errors: 24 -> 20. Full startup order, cross-module ownership and ABI remain unproven; diagnostic must not run. Evidence active-document-data-working.json and document-swap-link-trial.json. No swap or gate rerun.

ChangeHistoryService name: original 004137a0 passes literal "ChangeHistoryService" at 00948df8 directly; provisional generic template loaded an external pointer and differed by one byte. Specialized the inactive name declaration to match original 101 bytes, literal, Name::declare target and guard/cache data references; diagnostic link 20 -> 19 errors. Other factory/name consumers, shared cache ownership and ABI remain unproven; diagnostic must not run. Evidence service-history-working.json and document-swap-link-trial.json. No swap or gate rerun.

ChangeHistoryService FactoryProduct::getClassName now matches original 00587c80 (23 bytes), original secondary vtable slot 008318b4, once flag, callback and direct calls. Diagnostic link 19 -> 18 errors. Shared factory lifecycle and ABI remain unproven; diagnostic must not run. Evidence service-history-working.json and document-swap-link-trial.json. No swap or gate rerun.

Recovered Instance(const char*) constructor used by the ChangeHistoryService factory chain: original 0055b960 (377 bytes) matches with selected original direct calls verified. Default ctor and destructor remain matched; rebuilt duplicate-safe link profile retains 18 diagnostic errors. Factory base constructor, vtables and cross-module runtime ABI remain unproven. Evidence instance-after-service-link.json, instance-link-profile.json and document-swap-link-trial.json. No swap or gate rerun.

ChangeHistoryService factory chain: donor Object.h overlay adds the recovered forwarding constructor; FactoryProduct 005871d0 (97) and DescribedCreatable 0058a8d0 (153) match original and direct calls. Original class descriptor 0058a2a0 (101), literal, guard, storage, constructor/cleanup targets and cleanup body 007fd930 match after correcting donor pointer-based name. Instance and ChangeHistory constructor/destructor checks still pass. Diagnostic link 18 -> 21 error lines: constructor resolves but adds references to the four already-missing Instance virtuals. Factory intermediate vtable/data identity, descriptor ABI, registry cleanup and runtime ownership remain unproven; diagnostic must not run. Evidence change-history-factory-working.json, change-history-layout-working.json and document-swap-link-trial.json. No swap or gate rerun.

Instance::readProperty 00559170 (185 bytes) matches original and direct calls using the recovered property-descriptor trial; donor descriptor calls wrong virtual slot +0x18 versus original +0x24. Original ChangeHistoryService vtable slot 11 and all selected direct/data/import targets verified. Adding trial object resolves three diagnostic error lines: 21 -> 18. Descriptor ABI and data remain unproven; mixed diagnostic must not run. Evidence instance-read-property-trial.json and document-swap-link-trial.json. No swap or gate rerun.

Instance::onAncestorChanged 0055acc0 (348 bytes), signal fire 0049d200 (175) and notifier raise 00558730 (138) match original. Callback vtable slot, original signal global 00973c38, direct calls and imports verified. Adding the callback removes three missing-vtable lines while exposing its missing signal global: diagnostic 18 -> 16. Signal descriptor initialization/identity and helper dependencies remain unproven; mixed diagnostic must not run. Evidence instance-ancestor-trial.json and document-swap-link-trial.json. No swap or gate rerun.

Instance descendant callbacks trial: recovered donor event bodies compile, but original listener check uses vector size while donor uses empty; changing the isolated profile to size still fails to match both methods because of codegen and exception-frame differences. Both candidates remain inactive and unlinked; see instance-descendant-trial.json. No swap or gate rerun.

Descendant-removal profile: original 0055ae90 (241 bytes), vtable slot 008318d4, signal global 00973ca0 and direct targets match when isolated listener/signal calls use a no-unwind profile. However that profile generates nonmatching fire (124 vs 175 bytes) and notifier raise helpers, so the candidate is not linked or runtime-cleared. Evidence instance-descendant-trial.json. No swap or gate rerun.

Descendant-removal split profile: separate donor-profile instantiations of signal fire 0049d200 (175) and notifier raise 00558660 (202) match originals and direct targets; no-unwind callback emitted separately without the nonmatching added callback. Both objects are in isolated diagnostic, with helper object first: 16 -> 14 error lines as removal resolves and its signal global appears. Linker COMDAT selection, signal data/ABI and runtime behavior remain unproven; diagnostic must not run. Evidence instance-descendant-trial.json and document-swap-link-trial.json. No swap or gate rerun.

Descendant-added callback: using original getParent accessor yields matching 0055ae20 (97 bytes), original vtable slot 008318d0, direct calls and signal global 00973e40. Event constructor 00558910 and separately compiled donor notifier raise 00557e80 also match. Adding trial callback resolves three missing virtual lines but exposes its signal global: 14 -> 12 error lines. Helper COMDAT selection, signal data, event ABI and runtime behavior remain unproven; diagnostic must not run. Evidence instance-descendant-trial.json and document-swap-link-trial.json. No swap or gate rerun.

Signal identity correction: original ancestry and descendant callbacks and history startup use the same Instance static signal objects; declarations and isolated callbacks now bind those existing symbols. Archive Instance.obj has byte-matching initializers/cleanup but its two descendant events use "DescendentAdded"/"DescendentRemoving" and "descendent", whereas original strings are "DescendantAdded"/"DescendantRemoving" and "descendant". New native definitions match original strings, descriptor ctor and six initializer/cleanup bodies; inserting them exposes three duplicate archive definitions (12 diagnostic error lines). Removing the entire archive Instance.obj in a separate filtered-library diagnostic avoids duplicates but exposes 935 unresolved references across 43 unique symbols, including setParent; both archives preserved. Need targeted source-level replacement, not a forced linker override. Signal ABI/runtime ownership remain unproven. Evidence instance-signal-archive-audit.json, document-swap-link-trial.json, document-swap-native-instance-trial.json. Instance and ChangeHistory ctor/dtor and history-start probes pass; no swap or P5/P6 rerun.

Targeted donor Instance experiment: rebuilt existing patched donor source in isolation; all 2,139 normalized function bodies and relocation symbols match archived Instance.obj. Rebuilding with only the three signal definitions omitted retains 2,127 matching bodies and relocation symbols; all three signal references remain external and are supplied by the native definitions. Separate filtered-library diagnostic now links past the duplicate globals without forced overrides: 9 remaining error lines, all Doc command/lifecycle or workspace site-check. Donor and native runtime ABI, remaining data and helper COMDAT selection still unproven; diagnostic must not run. Evidence instance-filtered-donor-trial.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

Doc insert-model handler 00455c30 (237 bytes) matches original with MFC conversion profile, direct targets, string data and MFC/MSVCP import ordinals checked against local import library. Doc constructor/destructor and existing body/layout probes remain passing after adding nonvirtual loadFile declaration. Filtered diagnostic still has 9 errors: handler resolves but original loadFile 00455a20 dependency appears. MFC data/Doc runtime ABI and loadFile implementation remain unproven; diagnostic must not run. Evidence document-insert-model-working.json, document-after-insert-model.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

Doc loadFile 00455a20 (526 bytes) and ContentId constructor 004377c0 (76) match under recovered library call boundaries; all direct and imported targets verified. Doc ctor/dtor and DataModel size/offset probes still pass after nonvirtual declarations. Filtered diagnostic 9 -> 11 errors: loadFile resolves while isUrl, content-provider service and loadFromString become visible. Provider identity, ContentId destructor, DataModel lifetime and runtime ABI remain unproven; diagnostic must not run. Evidence document-load-file-working.json, document-after-load-file.json, datamodel-after-load-file.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

ContentProvider::isUrl 0055bd10 (54 bytes) matches original http/https classifier, literal contents and string find imports. Filtered Doc diagnostic 11 -> 10 errors. ContentProvider service identity and ABI remain unproven; diagnostic must not run. Evidence content-provider-url-working.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

Doc loadFromString 00454ac0 matches the original analyzed 385-byte function and its adjacent 74-byte catch continuation, with direct calls, imported string methods, literal and catch continuation target verified. Original analyzer excludes that continuation; exception metadata still needs independent verification. Filtered diagnostic 10 -> 9 errors. ScriptContext/ValueCollection ownership, EH metadata and runtime ABI remain unproven; diagnostic must not run. Evidence document-load-string-working.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

ContentProvider identity correction: original 0041eea0 calls service find/create, factory 0041e5d0 allocates 0x19c, and constructor 00562c30 installs vtable 0082df6c whose RTTI names RBX::ContentProvider. Replaced invented DataModel::getContentProvider declaration with the real ServiceProvider::create<ContentProvider> call; Doc loadFile still matches original. Existing donor ContentProvider is a noncopyable singleton rather than native service, so its class layout and lifecycle need reconstruction; diagnostic still has 9 errors and must not run. Evidence document-load-file-working.json and document-swap-filtered-donor-trial.json. No swap or P5/P6 rerun.

ContentProvider isolated layout trial: reconstructed original Instance-derived service size 0x19c and six member offsets using existing event/worker types. Constructor 00562c30 (418) and destructor 00562e60 (270) match original, with direct targets and ten vtable addresses checked in both. Original RTTI spells the class-name template as a char-array symbol while shared candidate currently uses pointer form; dependent type semantics, vtable slots, exception metadata and runtime ownership remain open. Trial is not linked or runtime-cleared. Evidence content-provider-layout-trial.json. No swap or P5/P6 rerun.

ContentProvider service trial: original find 0041ed60 (320), create 0041eea0 (228), factory 0041e5d0 (120), class index 0041e050 and literal-backed name 0041dfe0 match with direct targets checked. Separate candidate constructor/destructor and layout still pass. A separate filtered diagnostic resolves provider create but adds three class-name/descriptor/worker dependencies: 9 -> 11 error lines. The provisional pointer-based template spelling differs from original char-array RTTI; native layout/ownership and COMDAT selection remain unproven, so diagnostic must not run. Evidence content-provider-service-trial.json, content-provider-layout-trial.json and document-swap-provider-trial.json. No swap or P5/P6 rerun.

ContentProvider descriptor and class-name trial: getClassName 0055ddb0 matches original vtable slot 0082df60, once-flag and call targets; descriptor 005612b0 (101) and cleanup 007fcc00 match with original literal, base descriptor, guard, storage and ctor/atexit targets. Provider diagnostic 11 -> 9 errors; processRequests remains unresolved. Pointer-vs-array RTTI identity, worker and runtime ABI remain unproven; diagnostic must not run. Evidence content-provider-layout-trial.json, content-provider-service-trial.json and document-swap-provider-trial.json. No swap or P5/P6 rerun.

- ContentProvider trial: corrected request queue element to ContentRequest (0x38), including callbacks; constructor/destructor matches alone did not prove the element type. Native worker 005620f0 matches 950 bytes and selected call targets; layout and service trials pass. Filtered-donor/provider diagnostic still has 9 unresolved symbols, now including readContent. Trial only; no runtime swap or P5/P6 gate implied.

- Content callback trial: corrected mined readContent signature to RequestCallback/RequestResult. Original 0055dc80 main body matches 224 bytes; callback target 005aae30 checked. Catch funclet and exception metadata remain unproven. Adding candidate reduces isolated filtered-donor/provider link errors 9 -> 8; still incompatible diagnostic, never run.

- Content callback EH evidence: original 0055dd60 catch funclet matches all 70 bytes; checked logging targets, message literal and original x86 EH try/catch table, including std::exception type and catch displacement. Linked EH metadata and runtime ABI remain unproven. Provider diagnostic still has 8 unresolved symbols. Workspace site-check profile experiment replacing inline CString conversion widened candidate 393 -> 446 bytes versus original 399; experiment rejected, candidate remains inactive.

- Document launch handler trial: 004500d0/004501c0/004502b0 reproduce 232/232/187 bytes and original direct call targets and URL literals against actual shared CRobloxDoc header. Trial launch helper 0044ff40 still differs (376 vs 396 bytes; Ob1/Ob2 369); do not link candidate or count as live. Original helper uses compiler-specialized register passing and other dependencies remain unproven. Evidence document-launch-trial.json. No runtime swap or P5/P6 rerun.

- Document launch trial: recovered original helper 0044ff40 (396 bytes) including original app/thread lookups, ShellExecute import and error literals; all three command bodies remain exact. Real CString operators and existing applicationBaseUrl replace provisional helper names. The save-before-launch helper 0044fe00 matches 312 bytes and SaveToFile slot, string literals and selected call targets. Its temporary diagnostic bridge adds a call not in original; never run. Filtered-provider link now has 6 errors: five earlier Doc/site dependencies plus FileSystem::getUserAppDataDirectory. EH linkage and runtime ABI remain open; no P5/P6 rerun.

- Filesystem dependency: extracted original VistaAPIs methods plus getUserAppDataDirectory directly from mined source, avoiding duplicate getCacheDirectory. Directory body 005a7ac0 (992 bytes) and integrity body 005a7780 (263) match; selected calls and strings checked. Filtered-provider diagnostic unresolved errors 6 -> 5. ATL data, exception metadata and runtime ABI remain unproven; Doc save helper still uses a temporary diagnostic bridge. No runtime swap or P5/P6 rerun. Evidence filesystem-trial.json and document-swap-provider-trial.json.

- Doc SaveModified trial: original 00455060 (1020 bytes) and Visit::getUploadUrl 0044f1b0 (36) match using shared document/workspace/service declarations; selected model, lock, run state and dialog calls checked. Visit service lookup 00452b40 (320) matches selected call targets under isolated compiler profile. Profile uses generated empty shared_ptr destructor solely to expose original calls; COMDAT destructor selection, Visit ctor/dtor, RTTI and runtime are NOT proven. Filtered-provider diagnostic errors 5 -> 4. Temporary launch bridge and other ABI concerns remain; never run diagnostic. No live swap or P5/P6 rerun. Evidence document-save-modified-trial.json, visit-service-trial.json and document-swap-provider-trial.json.

- Native LDraw command 00454c90 matches 664 bytes using real Doc/Workspace/ScriptContext types and selected direct targets. Candidate parser destructor 0046f100 matches 15 bytes, original vtable address and string offset. Constructor, 0046f200 parser, map lifetime/layout, RTTI and exception metadata remain unproven. Adding handler and destructor changes isolated provider diagnostic 4 -> 5 unresolved: original handler resolved, parser constructor and parse introduced. Trial must not run; P5/P6 not rerun. Evidence document-ldraw-trial.json and document-swap-provider-trial.json.

- LDraw parser constructor 0046f110 matches 184 bytes against the same typed candidate as its 15-byte destructor. Verified original vtable 0081cb74, singleton storage 0096ee60, map-root constructor 0046d710, path helper 0055d0b0 and XML filename. Map root uses recovered 0x7c container layout but its constructor/destructor and ownership remain unproven. Diagnostic errors 5 -> 7 as constructor resolves and map-root, path helper and global dependencies appear. This remains an incompatible trial; no P5/P6 rerun. Evidence document-ldraw-trial.json and document-swap-provider-trial.json.

- LDraw path helpers 0055d0b0 (145), asset folder getter 0055c4c0 (50) and initializer 0055c3e0 (214) match original with selected globals, imports and literals checked. Original 007faff0 deletes map singleton at shutdown: replaced provisional raw pointer with std::auto_ptr candidate; parser constructor remains exact and candidate map destructor matches 19 bytes. Asset string startup/cleanup 007f2c10/007fcbf0 match 23/11 bytes. Map-root ctor/dtor, shared ownership across subsystems and runtime ABI remain unproven. Filtered-provider diagnostic 7 -> 5 errors. No runtime swap or P5/P6 rerun. Evidence ldraw-path-trial.json, document-ldraw-trial.json, document-swap-provider-trial.json.

- LDraw map root original 0046d710 constructor (1950 bytes) and 0046d590 destructor (349) match using shared native XmlElement/TextXmlParser and typed map fields; vtable/selected calls checked. Sixteen original XML tag initializers match with exact storage and literal bindings. Adding constructor reveals 24 new dependencies, then tag integration removes 16: diagnostic errors 5 -> 29 -> 13. Element lifetime/layouts, XML registry ownership, linked RTTI and runtime remain unproven; never run trial, P5/P6 not rerun. Evidence ldraw-map-lifetime-trial.json, ldraw-tags-trial.json and document-swap-provider-trial.json.

- LDraw map operations: five element/map bodies plus three constructor/destructor thunks match original bytes; vtable entries and selected bindings checked. Candidate classifiers remain excluded because they differ (233/241, 332/344, 233/241 bytes). Diagnostic unresolved errors 13 -> 8. Map ABI, container destructor selection and exception/runtime ownership remain unproven; no runtime swap or P5/P6 rerun. Evidence ldraw-operations-trial.json and document-swap-provider-trial.json.

- LDraw map filename getter, part lookup and insertion now match original 0046cb00/0046d0a0/0046d480 with selected target checks; diagnostic errors 8 -> 7. Native case-insensitive comparator 0046f9f0 matches 543 bytes with original STL imports verified, but three classifier bodies remain unmatched and excluded. No live swap or P5/P6 rerun. Evidence ldraw-operations-trial.json, ldraw-compare-trial.json, document-swap-provider-trial.json.

- Native LDraw parser candidate now uses std::string/streams, typed map owner and observed 0x90 part layout; compiler profile produces 926 bytes vs original 922, not exact and excluded from link. Part/model lifetimes and ABI remain unproven. Map filename getter, part lookup and insertion remain exact after header changes; map-root, asset and Doc LDraw probes rerun successfully. Filtered diagnostic remains 7 unresolved, P5/P6 not rerun. Evidence ldraw-parse-trial.json and document-swap-provider-trial.json.

- LDraw parser 0046f200 now matches 922 bytes after preserving the original two-argument find_first_not_of import. Model and Part constructors/destructors, scalar-deleting thunks and model add match six original bodies with vtable checks; model writeLua 0046f6b0 matches 362 bytes. Discovered original LDrawItem slot +4 and corrected trial declaration to pure virtual bool writeLua; Part override target 0046f000 still unresolved. Diagnostic 7 -> 11 when parser introduced, then 11 -> 7 after lifetimes/model writer (new Part writer exposed). Profile-only; linked RTTI, destructor selection, resource ownership and runtime remain unproven. P5/P6 not rerun. Evidence ldraw-parse-trial.json, ldraw-entities-trial.json, ldraw-write-trial.json, document-swap-provider-trial.json.

- LDraw Part virtual writeLua 0046f000 (251 bytes), case-insensitive map lookup 0046d110 (215), first part lookup 0046e370 (27), and parent writer 0046ef70 (139) match original bodies with selected bindings and vtable checked. Adding Part writer exposed six helpers, two lookup helpers and parent writer resolve three; diagnostic 7 -> 9 unresolved. Remaining Part shape/color/transform helpers and map classifiers are incomplete. Related map, parser, lifetime and model writer probes pass after shared trial header changes. Linked RTTI, resource ownership and runtime remain unproven; no swap or P5/P6 rerun. Evidence ldraw-part-write-trial.json, ldraw-part-parent-trial.json, ldraw-operations-trial.json and document-swap-provider-trial.json.

- LDraw color writer 0046ecf0 (71), map color lookup 0046d080 (28), and shape writer 0046eb40 (421) match original with selected call/import/literal bindings. Shape writer requires native two-argument find_first_of and preserved shape value across stream output. Diagnostic errors 9 -> 7; Part transform writer and three map classifiers remain. Dependent native layout/constructor/destructor profiles rerun successfully. No runtime swap or P5/P6 rerun. Evidence ldraw-part-color-trial.json, ldraw-part-shape-trial.json and document-swap-provider-trial.json.

- LDraw transform writer 0046ed40 matches 546 bytes against typed Part layout; verified atof/ostream bindings, +0.05/-0.05 constants and CFrame literals. Filtered-provider diagnostic errors 7 -> 6; remaining three LDraw classifiers and three Doc/site methods. No runtime swap or P5/P6 rerun. Evidence ldraw-part-transform-trial.json and document-swap-provider-trial.json.

- LDraw classifiers 0046cb80, 0046cc80 and 0046cde0 now match 241/344/241 bytes using actual std::string and explicit temporary lifetime scopes; original case-insensitive comparator target and all seven literals verified. Filtered-provider diagnostic link errors 6 -> 3: initializeCommands, handle_453c30, workspace checkSite. Diagnostic remains incompatible and must not run: shared_ptr profile destructor selection, native service ABI, temporary Doc path bridge, RTTI and EH remain unproven. No live swap or P5/P6 rerun. Evidence ldraw-operations-trial.json and document-swap-provider-trial.json.

- Doc execute handler 00453c30 matches 1027 bytes using actual XTP control, native Doc/Workspace and provider types, with selected calls and original XTP virtual slot verified. Corrected intended edit behavior: EM_SETSEL followed by EM_SCROLLCARET; no Clear. Original 00451300 is Boost iostreams copy_impl, not a custom void copyStream; compiling real Boost copy reproduces its 179-byte body and removes the false dependency. Filtered-provider link errors 3 -> 2: initializeCommands and workspace checkSite. Provider getContent selection, native XTP runtime vtables, shared_ptr COMDAT, Doc ABI and exception metadata remain unproven; diagnostic must not run. Provider ctor/dtor/service/worker probes rerun and pass after nonvirtual declaration additions. No live swap or P5/P6 rerun. Evidence document-execute-trial.json and document-swap-provider-trial.json.

- ContentProvider::getContent 00561f20 matches 354 bytes with selected original targets and literal verified. Adding the trial exposed duplicate donor getContent and missing native loadContent: diagnostic now has four errors including pre-existing initializeCommands and checkSite. Native getContent is isolated, not active; cache implementation, ABI and runtime ownership remain unproven. No P5/P6 rerun. Evidence content-get-trial.json and document-swap-provider-trial.json.

- ContentProvider::loadContent 00561980 now matches 1192 bytes using the native trial layout; selected asset/hash, URL, mutex and HTTP call targets verified. Provider constructor/destructor, service, worker and getContent trials reran successfully. Adding it resolves loadContent but exposes nativeFindAsset and nativeFindHashFile: diagnostic now has five errors including duplicate donor getContent and existing initializeCommands/checkSite. Trial remains unsafe to run; no swap or P5/P6 gates. Evidence content-load-trial.json and document-swap-provider-trial.json.

- Rebuilt donor glue without duplicate getContent: archive baseline and every retained function match bytes and relocation symbols; 32 getContent-related functions/COMDAT helpers disappear. Filtered-provider diagnostic errors 5 -> 4: initializeCommands, checkSite, nativeFindAsset and nativeFindHashFile. Native findAsset candidate compiles to 306 bytes vs original 300 and is excluded. Diagnostic remains ABI-incompatible and must not run; P5/P6 not rerun. Evidence content-filtered-donor-trial.json and document-swap-provider-trial.json.

- Native asset and hash lookup helpers match original 00560460 (300 bytes) and 0055fdc0 (262 bytes), with selected call/import bindings checked. Provider diagnostic now resolves both and exposes original 0055f940 cache-path helper: three errors remain (initializeCommands, checkSite, cache path). Cache-path candidate compiles to 294/294 bytes but instruction ordering differs; excluded. Trial remains incompatible and must not run; P5/P6 not rerun. Evidence content-find-asset-trial.json, content-find-hash-trial.json, document-swap-provider-trial.json.

- Cache-path helper 0055f940 now matches 294 bytes: original uses static linkage, which changes compiler register ordering. Original cache directory, ATL manager, SetString and atexit call targets verified. Filtered Doc diagnostic errors 3 -> 2: initializeCommands and checkSite. FileSystem cache-directory provider remains donor/reconstructed, static-state identity and runtime ABI unproven; trial must not run. P5/P6 not rerun. Evidence content-cache-path-trial.json and document-swap-provider-trial.json.

- Replaced reconstructed FileSystem cache directory in filtered Doc diagnostic with recovered native 005a7ea0 (548 bytes, selected calls verified); consolidated native user app-data directory 005a7ac0 (992) and integrity 005a7780 (263) into same trial object, all exact. Filtered donor rebuild verifies retained function bytes/relocations. Diagnostic remains two unresolved: initializeCommands and checkSite. Runtime ABI, data and EH remain unproven; P5/P6 not rerun. Evidence content-cache-directory-trial.json and document-swap-provider-trial.json.

- Native CRobloxDoc::initializeCommands 00451b60 now matches 3108 bytes using candidate shared Doc/Workspace/DataModel/StandardVerbs headers; selected calls and three vtable addresses verified. Forced original CString conversion import and evaluated Name lookup before map insertion. Adding initializer resolves its link error but exposes 36 additional command, workspace factory, verb and constructor dependencies: diagnostic 2 -> 37 errors. Scoped-pointer reinterpretation, class lifetimes, vtables, RTTI and runtime ABI remain unproven; trial must not run. No P5/P6 rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Native CWorkspace::getWorkspace 0046a970 (17 bytes) and Verb constructor 005833e0 (125) match original, reducing initializer diagnostic errors 37 -> 35. StandardVerbs constructor 005c7ea0 (2676) also matches with selected constructor/vtable targets verified; adding it resolves that constructor but exposes 117 unresolved command methods, raising diagnostic 35 -> 151. StandardVerbs destructor was previously matched; child constructors, vtables, data and runtime ABI remain unproven. No live swap or P5/P6 rerun. Evidence initializer-dependencies-trial.json, standard-verbs-constructor-trial.json, document-swap-provider-trial.json.

- Native RunStateVerb constructor 0057e330 matches 146 bytes against shared native DataModel/Verb/ServiceClient layout; original Verb constructor and vtable targets checked. Constructor paired with previously verified destructor 0057dfd0, though complete vtable, service ownership and runtime layout remain unproven. Diagnostic errors 151 -> 150; no live swap or P5/P6 rerun. Evidence initializer-dependencies-trial.json and document-swap-provider-trial.json.

- Native EditSelectionVerb constructor 0057e730 (175 bytes) matches original, paired with previously verified destructor 0057e050. Native shared_from<Workspace> 00618a40 (364) matches, including selected shared ownership calls. Generic ServiceClient constructor avoids duplicate explicit specialization. Diagnostic errors 150 -> 149. Workspace header here is donor; inherited layout, shared ownership, vtables and runtime ABI remain unproven. No live swap or P5/P6 rerun. Evidence initializer-dependencies-trial.json and document-swap-provider-trial.json.

- Ten native selection/camera command constructors at 0057e7e0..0057ea10 match 47 bytes each; checked base constructor target, original name literals and vtable RTTI class names. Linking resolves ten constructor edges but exposes virtual command methods: diagnostic errors 149 -> 162. Vtable slots, full lifetimes and runtime ABI remain unproven; trial must not run. P5/P6 not rerun. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Camera command isChecked trials expose real donor Workspace ABI mismatch: native camera interface +0x288, donor +0x270. All four compiled bodies otherwise normalize to originals 0057dcb0/0057dce0/0057dd10/0057dd40. Normalization is comparison only, not linked code. Recover Workspace bases and prove constructor/destructor before using these methods; do not run diagnostic. Diagnostic remains 162 errors, no P5/P6 rerun. Evidence camera-checked-donor-mismatch.json.

- Original Workspace camera interface is ICameraOwner at +0x288: RTTI and both original Workspace constructor 005a4d90 and destructor 005a28c0 independently write its vtable 00833998 there. Eighteen shared base offsets confirmed by both functions, including RootInstance interfaces and Workspace-specific bases. Donor +0x270 remains excluded; full native Workspace/RootInstance declarations and member lifetimes remain unproven. No runtime swap or P5/P6 rerun. Evidence workspace-camera-layout-evidence.json.

- Four native rotate/tilt/controller command constructors 0057f650..0057f6e0 match 47 bytes each, with original name literals, base-call targets and RTTI names checked. Native RotateAxisCommand and ControllerCommand constructors 0057f450/0057f4c0 also match 108 bytes with base-call and vtable targets verified. Their original virtual behavior remains unresolved: diagnostic rose 162 -> 166, then remained 166 after base constructors. No runtime swap or P5/P6 rerun. Evidence axis-command-constructors-trial.json, initializer-dependencies-trial.json and document-swap-provider-trial.json.

- Eight native basic verb constructors 0057d2d0..0057d4a0 and 0057e8d0 match original, including selected base calls, labels and original RTTI. FirstPerson and ForceAssertion doIt bodies match original 0070bdf0 ret 4 and both vtable slots checked, so their empty bodies are evidence-backed. Linking exposes additional virtual methods: diagnostic errors 166 -> 170. Complete command lifetimes and runtime ABI remain unproven; no P5/P6 rerun. Evidence basic-verb-constructors-trial.json and document-swap-provider-trial.json.

- Corrected inactive TToolVerb::newMouseCommand ABI: original Arrow factory 005c6270 returns raw pointer in EAX with plain ret; original caller 005c6f00 passes EAX directly. Prior shared_ptr return would require a hidden result pointer and was unsafe. Doc constructor/destructor (20 bodies), initializer, StandardVerbs constructor/destructor and verb lifecycle checks pass after header correction. Diagnostic still has 170 link errors; no runtime swap or P5/P6 rerun. Evidence tool-factory-abi.json and document-after-tool-factory.json.

- Recovered native TToolVerb::doIt 005c6f00 for all 26 tool types: each compiles to original 64 bytes, Workspace call targets match and all original vtable slots checked. Filtered diagnostic errors 170 -> 144. Existing donor Workspace::setDefaultMouseCommand differs from original (43 vs 76 bytes); setMouseCommand matches bytes with relocation fields masked, but linked targets and native Workspace ABI still unproven. Trial remains unsafe to run; no P5/P6 rerun. Evidence tool-verb-actions-trial.json and document-swap-provider-trial.json.

- Native Arrow tool factory 005c6270 versus donor class: original allocates 0x20 and initializes field +0x1c; donor allocates 0x24 and initializes +0x20. Other 124 bytes match with relocations masked after comparison-only normalization. Do not link donor factory; recover real MouseCommand/ArrowTool inheritance and prove both constructors/destructors. Diagnostic remains 144 errors, no P5/P6 rerun. Evidence arrow-factory-donor-mismatch.json.

- Added inactive shared MouseCommand header candidate by removing donor-only undoState field: native constructor 006159f0 (42) and scalar-deleting destructor 00615a20 (45) both match, as does Arrow factory 005c6270 (126) using original 0x20 Arrow allocation and vtable targets. Trial link resolves Arrow factory but exposes two duplicate donor MouseCommand lifetime symbols: diagnostic errors 144 -> 145. Donor MouseCommand object must be safely filtered; Arrow lifetimes, full vtable and runtime ABI remain unproven. No P5/P6 rerun. Evidence mousecommand-lifetime-trial.json, arrow-factory-donor-mismatch.json and document-swap-provider-trial.json.

- Rebuilt donor MouseCommand without duplicate constructor/destructor: baseline archive function bytes and relocation symbols match, and all 173 retained function bodies match rebuilt baseline. Removal also suppresses 20 compiler-emitted helpers, including vtable-associated inline methods; their replacement selection and data are unproven. Filtered diagnostic eliminates duplicate definitions: errors 145 -> 143. Retained donor methods still use donor layout and may be ABI-incompatible; never run trial. No P5/P6 rerun. Evidence mousecommand-filtered-donor-trial.json and document-swap-provider-trial.json.

- Native NullTool factory 005c7610 (102 bytes) matches using shared 0x1c MouseCommand layout. Existing NullTool constructor 00618110 (32) and scalar deleting destructor 00618130 (43) match original, with MouseCommand call targets and both vtable addresses checked. Native MouseCommand non-deleting destructor 00615780 (20) independently matches as well. Filtered diagnostic errors 143 -> 142. Other virtual slots, linked ABI and runtime remain unproven; no P5/P6 rerun. Evidence nulltool-factory-trial.json, mousecommand-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered GameTool factory 005c76b0 (102), constructor 00640280 (89), destructor 00640220 (90), deleting destructor 006402e0 (30), and isSticky 00640300 (96), each exact with selected original targets. Linking GameTool resolves its factory but exposes four remaining virtual/name methods: diagnostic 142 -> 145. Candidate GameTool header remains isolated; full vtable, class identity and runtime ABI unproven. No P5/P6 rerun. Evidence gametool-lifetime-trial.json and document-swap-provider-trial.json.

- GameTool onMouseIdle 0063fad0, getCursorName 00617e40, getName 00640450 and its once/name helpers 005c5f30/005c6220, onMouseHover 00640190, and canDrag 00640150 match original. Hover call targets and cursor-literal addresses verified; canDrag uses donor PartInstance header, whose full layout remains unproven. Diagnostic errors 145 -> 143 after idle/name, then 144 after hover exposes dependencies, remaining 144 after canDrag exposes lockedInPlace. Runtime ABI and name-static identity remain unproven; no P5/P6 rerun. Evidence gametool-lifetime-trial.json and document-swap-provider-trial.json.

- Native MouseCommand unlocked-part path 00616000 (117 bytes) matches; candidate filter destructor 00615b80 (161), existing donor filter constructor 00660380 (287), and filtered existing MouseCommand::getPart 00615d90 (372) match original bytes with selected targets checked. Diagnostic errors 144 -> 143. Workspace, filter vtables, shared ownership, linked callees and runtime ABI remain unproven; no P5/P6 rerun. Evidence mouse-unlocked-filter-trial.json and document-swap-provider-trial.json.

- GameTool onMouseDown 00640360 matches 237 bytes with native 0x44 PartDragTool declaration and selected original targets. Existing PartDragTool object constructor 00665f20 (479), destructor 00665bd0 (188) and deleting destructor 00665cc0 (30) independently match original; selected MouseCommand, RunDragger, MegaDragger and vtable targets checked. Diagnostic errors 144 -> 143; PartInstance::lockedInPlace remains unresolved. Full Part/Workspace/drag behavior and runtime ABI remain unproven; no P5/P6 rerun. Evidence gametool-lifetime-trial.json, partdrag-lifetime-trial.json and document-swap-provider-trial.json.

- Original PartInstance constructor 0059d4d0 and destructor 0059b970 both use embedded Primitive at +0x228; Primitive destructor vtable RTTI identifies RBX::Primitive. The unresolved lockedInPlace 00599530 uses the same member. Server sources for Part constructor/destructor locally recheck 100%, but use different provisional headers; full shared Part/Primitive declarations and linked call targets remain unproven. Existing donor Part stores a pointer instead, so it cannot safely supply this path. No swap or P5/P6 rerun. Evidence part-embedded-primitive-evidence.json.

- Recovered typed PartInstance::lockedInPlace 00599530 (191 bytes), using 2008 Part/Primitive/Joint declarations. Same profile compiles original Part constructor 0059d4d0 (785) exactly; lock method's joint iteration and normal conversion targets checked. Diagnostic errors 143 -> 141. Existing donor Primitive::getNextJoint differs from original, and recipe uses provisional Guid declarations; Part/Primitive/Joint destructors, complete layouts and linked behavior remain unproven. Diagnostic must not run; P5/P6 not rerun. Evidence part-lock-profile.json and document-swap-provider-trial.json.

- Typed 2008 Primitive joint first/next methods 005e7b90 (15) / 005e7ba0 (37) match originals. Candidate Edge index fields also preserve exact Part constructor 0059d4d0; Edge constructors/destructors and full layouts remain unproven. Renamed only donor joint methods in an isolated rebuilt profile; all 216 retained function bytes and relocation symbols match archive baseline. Diagnostic duplicate errors 143 -> 141; retained donor methods can still assume old layout, so this trial is unsafe to run. No P5/P6 rerun. Evidence joint-iteration-profile.json, primitive-filtered-donor-trial.json and document-swap-provider-trial.json.

- Workspace::setDefaultMouseCommand 005a0610 (76) and default NewNullTool factory 005a0280 (91) match original in an isolated typed profile. Existing NewNullTool constructor 00618160 (109), destructor 00617de0 (90) and deleting destructor 006181d0 (30) match with selected targets; Workspace constructor 005a4d90 (1124) also matches under profile. Renamed donor default-command definition locally; 1590 other function bytes/relocations match baseline. Diagnostic retains 141 errors. Partial MouseCommand interface, Workspace bases, donor methods, vtables and runtime ABI remain unproven; no P5/P6 rerun. Evidence workspace-default-profile.json, default-mousecommand-factory-trial.json, workspace-filtered-donor-trial.json and document-swap-provider-trial.json.

- Workspace site error wrapper 00429330 matches all 43 bytes; original call targets 00427c20 and 004290b0, GUID_NULL address, and 008164f8 GUID bytes verified. Adding wrapper to inactive diagnostic keeps 142 errors: reporter resolved, two downstream helpers exposed, and GUID resolved. Helper bodies, GUID identity and runtime ABI remain unproven. Do not run diagnostic; P5/P6 not rerun. Evidence workspace-error-trial.json and document-swap-provider-trial.json.

- Recovered typed status logger 00427c20 matches 349 bytes, including original StandardOut singleton/print and shared_ptr destructor call targets. Linked donor singleton and print bodies independently match original. Inactive diagnostic errors 142 -> 141. StandardOut runtime ABI and error-core helper remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-status-trial.json and document-swap-provider-trial.json.

- Original ATL ANSI AtlReportError 004290b0 instantiated directly from the VS2008 vendor header matches 332 bytes; selected ATL, CRT and Win32 call targets verified. Workspace error wrapper now calls the actual ATL symbol. Inactive diagnostic errors 141 -> 140; transitive helper bodies and runtime ABI remain unproven. Do not run diagnostic; P5/P6 not rerun. Evidence atl-error-core-trial.json and document-swap-provider-trial.json.

- Verified all 26 original TToolVerb isChecked vtable slots use the same RTTI comparison, each with its own matching tool type descriptor. Donor Workspace stores current command at +0x398 versus original +0x3b0, and its accessor adds an assertion: candidate differs (70 versus 44 bytes) and is not linked. Original shared Workspace layout still required. No P5/P6 rerun. Evidence tool-checked-donor-mismatch.json.

- Tested constructor and destructor against the same provisional Workspace class profile: constructor 005a4d90 matches 1124 bytes, but destructor 005a28c0 differs (755 versus 878 bytes). This disproves treating the constructor match as full layout proof. Candidate base/notifier/profiler lifetimes need recovery before the class can be shared or run. Evidence workspace-shared-lifetime-trial.json; regenerate its input with record_native_workspace_default_trial.py first. No P5/P6 rerun.

- Correcting the provisional profiler virtual lifetime and notifier vector lifetime produces one profile where both Workspace constructor 005a4d90 (1124 bytes) and destructor 005a28c0 (878 bytes) match. Destructor's RootInstance, VerbContainer, render bucket and moving-manager targets verified. Intermediate profiler-only variant still differs (807 bytes). Profile retains placeholder base/profiler storage and does not prove full class layout or safe linking; no live swap or P5/P6 run. Evidence workspace-lifetime-profiler-variant.json and workspace-lifetime-profiler-notifier-variant.json.

- Replaced trial notifier's void-pointer storage with typed Listener pointers and RaiseRange; Workspace constructor/destructor remain exact. Independently verified current/sticky command offsets +0x3b0/+0x3b4 through original constructor, destructor, setter and tool predicate. Full shared layout still incomplete. Evidence workspace-command-layout-evidence.json and updated lifetime profile. No live swap or P5/P6 run.

- Instantiated original ATL CComObject<CWorkspace>::CreateInstance from vendor header: 00450370 matches 209 bytes when the recovered FinalConstruct and protected-refcount declarations are present. Constructor 00401910 and FinalConstruct 0046b5c0 targets verified. Diagnostic maps initializer's temporary alias to the native factory; errors 140 -> 153 as the CWorkspace COM vtable, event handlers, GUIDs, COM map and FinalConstruct dependencies become visible. Isolated declarations and generated vtables still need validation; do not run diagnostic. No P5/P6 rerun. Evidence workspace-factory-trial.json and document-swap-provider-trial.json.

- Factory object constructor 00401910 also matches 68 bytes. Inventoried all 34 slots across its six original vtable groups: 21 emitted local bodies match, QueryInterface differs, and 12 slots remain external. Original targets for those external methods are recorded to guide recovery; slot inventory is not a runtime ABI proof. Updated link diagnostic remains 153 errors. Evidence workspace-factory-vtables-trial.json and workspace-factory-trial.json. No P5/P6 rerun.

- Typed CWorkspace Workspace/Selection event handlers 0046a990 (11 bytes) and 0046ab10 (70) match, including invalidateRunViews 00555350 and SelectionChanged destructor 00422c60 targets. Existing linked RunService invalidate body also matches 281 bytes. Inactive diagnostic errors 153 -> 151. Shared class declarations, RunService layout and runtime ABI remain unproven; do not run diagnostic. Evidence workspace-events-trial.json and document-swap-provider-trial.json. No P5/P6 rerun.

- Native CWorkspace::Close 0046b500 matches 68 bytes with MFC module-state guard and /EHs-c-; cleanup target 0046b0e0 verified. Existing selected cleanup body remains nonmatching (242/242 bytes, different instructions), and disabling exception handling requires runtime validation. Inactive diagnostic errors 151 -> 150. Do not run diagnostic; no P5/P6 rerun. Evidence workspace-close-trial.json and document-swap-provider-trial.json.

- Cleanup compiler-profile comparison: five MSVC 21022 optimization/inlining variants all differ from 0046b0e0. Difference includes listener-pointer register scheduling. Original inactive source restored and workspace object/Close/link receipts regenerated; diagnostic remains 150 errors. Evidence workspace-cleanup-profiles.json and workspace-revalidated.json. No live swap or P5/P6 rerun.

- Recovered IWorkspace IID at 008164b8 and RobloxLib LIBID at 008164e8 directly from original type-info holder 00928754 (version 1.2). Compiled bytes match both originals. Inactive diagnostic errors 150 -> 148; COM holder identity and runtime ABI remain unproven. Do not run diagnostic; no P5/P6 rerun. Evidence workspace-guids-trial.json and document-swap-provider-trial.json.

- Recovered CWorkspace ATL COM map from original 0080aea8: IWorkspace, IDispatch and ISupportErrorInfo at offsets 0, 0 and 4; compiled entries and referenced GUID bytes match. Same isolated header produces exact QueryInterface 00402730 (28 bytes), factory 00450370 and object constructor 00401910. QueryInterface's ATL helper target 00402280 verified. Diagnostic errors 148 -> 147; interface implementations, COM lifetime and runtime remain unproven. Do not run diagnostic; no P5/P6 rerun. Evidence workspace-com-map-trial.json and document-swap-provider-trial.json.

- Promoted the recovered COM map, protected FinalConstruct and IWorkspace/listener declarations into the shared inactive CWorkspace header; removed trial-only duplicate declarations. Revalidated constructor, destructor, safety, site trust, event handlers, Close, ATL factory/COM map and document initializer. Diagnostic still has 147 errors; methods and class ownership are incomplete. No live swap or P5/P6 rerun. Evidence workspace-revalidated.json, workspace-safety-working.json, workspace-com-map-trial.json and document-swap-provider-trial.json.

- Typed CWorkspace::FinalConstruct candidate is 373 bytes, matching original except Workspace draw notifier offset: donor +0x32c, original +0x344. All selected original creation, lock, RunService, shared ownership, Selection and notifier call targets verified. Normalized offset matches only as a diagnostic and is not linked. Recover real shared Workspace hierarchy before activation; no live swap or P5/P6 rerun. Evidence workspace-finalconstruct-mismatch.json.

- Typed DataModel::createDataModel(bool) 0057c100 matches 161 bytes, with original factory 0057c080, Lock 00411b40/005773c0 and initializeContents 0057a9f0 targets verified. Added two nonvirtual/static declarations to shared DataModel header; 0x264 size and existing member offsets revalidated. +0x259 flag naming, referenced constructors, ownership and runtime remain unproven. Candidate stays inactive; no live swap or P5/P6 rerun. Evidence datamodel-create-trial.json and datamodel-create-layout-revalidated.json.

- Compiled real donor Workspace base casts and compared 11 offsets against original RTTI. Instance child notifier +0x24, controllable +0x130 and renderable +0x1a0 agree; camera +0x288 and every measured subsequent Workspace base are 24 bytes later in the original. This localizes the first discrepancy between ModelInstance's renderable base and RootInstance's camera base; it does not establish the missing member types. Evidence workspace-donor-base-offsets.json. No live swap or P5/P6 rerun.

- Tested recovered ModelInstance vector at +0x1ec in an isolated donor-header overlay. Typed ModelInstance constructor 00585630 (594 bytes, /fp:fast) and destructor 00584790 (421 bytes) both match, with selected base/coordinate/property targets verified. The same overlay makes CWorkspace::FinalConstruct 0046b5c0 match 373 bytes. Added this method and DataModel creation to diagnostic: errors remain 147 as initializeContents is exposed. Vector element type/semantics, full layouts, shared ownership and donor/native ABI remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence model-vector-lifetime-trial.json, workspace-finalconstruct-vector-trial.json and document-swap-provider-trial.json.

- With the same provisional ModelInstance vector and an assertion-free Workspace command accessor, Arrow, Null, Game, Fill, Dropper and ModelSetPrimaryPart TToolVerb::isChecked bodies match their original 44-byte functions and RTTI descriptors. Diagnostic errors 147 -> 141. Workspace accessor semantics, vector element type, complete class hierarchy and live RTTI ownership remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence tool-checked-multi-trial.json and document-swap-provider-trial.json.

- Typed DataModel::initializeContents 0057a9f0 matches 502 bytes and selected call targets. Corrected recovered source's wrong default-command call: original targets Workspace::setNullMouseCommand 005a2730, not 005a0610. Typed null-command setter matches 43 bytes and calls original setMouseCommand 005a1fc0. Rebuilt filtered donor with both command setters renamed, preserving all unchanged function bytes/relocations. Diagnostic errors 141 -> 142 as native initialization resolves and PhysicsService/JointsService creation become visible. Layouts, donor data and runtime ownership remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence datamodel-initialize-trial.json, workspace-null-trial.json, workspace-filtered-donor-trial.json and document-swap-provider-trial.json.

- Typed ServiceProvider::create specializations for JointsService 004b3a50 and PhysicsService 004cd7e0 both match 228 bytes and original find, allocation, class-index and setParent targets. Diagnostic errors 142 -> 143 as two find methods and PhysicsService allocation become visible. Initial typed find candidates differ and are excluded from diagnostic. Static cache identity, service layouts and runtime ownership remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence world-service-factories-trial.json, world-service-find-mismatch.json and document-swap-provider-trial.json.

- Typed PhysicsService allocation 004cd760 (120 bytes, size 0x158), constructor 004cd5b0 (233) and destructor 005e8d30 (177) match, with selected constructor/shared-owner/base targets verified. Including them in the inactive diagnostic changes errors 143 -> 146 as class name/descriptor and physics listener methods become visible. Static identity, complete vtables, layouts and runtime ownership remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence world-service-full-trial.json and document-swap-provider-trial.json.

- PhysicsService assembly-on/off event candidates 005e9110/005e9130 each match 32 bytes; original vtable slots and fromPrimitive/onAdded/onRemoved targets verified. Existing donor PartInstance::fromPrimitive also matches 27 bytes. Event bodies resolve in inactive diagnostic; onAdded/onRemoved are exposed, leaving 146 errors. Event payload meaning, service vtables, Part/Primitive layout and runtime remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence world-service-all-trial.json and document-swap-provider-trial.json.

- Typed PhysicsService::onRemoved 005e9040 matches 196 bytes, including original set erase, shared-from, signal fire and descriptor addresses. Inactive diagnostic replaces that unresolved body with its still-unresolved signal descriptor; errors remain 146. onAdded candidate still differs despite equal size under two iterator profiles and is excluded. Signal identity, Part/Primitive layout and runtime remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence world-service-complete-trial.json, world-service-actions-secure-trial.json and document-swap-provider-trial.json.

- Verified the typed set insertion body called by PhysicsService::onAdded matches original 005e8c40 (239 bytes). Its caller still differs in stack allocation despite equal size; neither caller nor unverified signal descriptor was added to diagnostic. Diagnostic remains 146 errors. Evidence world-service-actions-trial.json and document-swap-provider-trial.json. No P5/P6 rerun.

- JointsService null-name service lookup 004b34c0 matches 174 bytes, including once, index and vector-resize targets. Trial retains the generic lookup's unreachable name branch to reproduce original exception metadata; it is not live code. Diagnostic errors 146 -> 145; class metadata, service cache identity and runtime remain unproven. PhysicsService find still differs. No P5/P6 rerun; do not run diagnostic. Evidence world-service-joints-find-trial.json and document-swap-provider-trial.json.

- PhysicsService find 004ccca0 matches 320 bytes with the recovered name path and out-of-line shared_ptr destructor; selected original targets verified and existing shared_ptr destructor matches 00600660. Diagnostic remains 145 errors as the class-name symbol is exposed. Original PhysicsService RTTI uses a char-array template argument (3QBDB); provisional class uses a pointer (3PBDB), and its generated name declaration differs (102 vs 101 bytes). This is an ABI mismatch despite matching method bodies: do not run or promote the class until corrected. Evidence physics-find-trial.json and document-swap-provider-trial.json. No P5/P6 rerun.

- Reused the original array-name PhysicsService source unit: constructor 004cd5b0, destructor 005e8d30 and allocation 004cd760 match, and original class-name bytes at 0083f858 plus 3QBDB RTTI spelling are verified. Replaced provisional pointer-name lifetime object in diagnostic; removed its incompatible find candidate. Three duplicate inline Instance bodies were changed to declarations only, with native lifetime matches retained. Diagnostic remains 145 errors; correct-array Physics find, Instance metadata, ownership and runtime ABI are still open. Do not run diagnostic; no P5/P6 rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- PhysicsService find 004ccca0 (320 bytes) and Name::doDeclare 004c9b70 (101 bytes) now both match using original array-name templates; original class-name data and selected call targets verified. Diagnostic errors 145 -> 144. Native array-name lifetime and lookup now agree, but shared ServiceProvider/Instance hierarchy, cache identity and runtime remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence physics-array-find-trial.json and document-swap-provider-trial.json.

- Verified and supplied original Instance name array at 0082d6a0; array-name classDescriptor 0040ad80 also matches with original name/root-descriptor targets. Corrected recovered PhysicsService unit's Boost shared_count exception branch to original try/delete/rethrow behavior: 004ca3c0 now matches 131 bytes with allocation, deleter, vtable and rethrow targets verified. Diagnostic errors 144 -> 142. Shared Instance hierarchy, metadata identity, class ownership and runtime remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence physics-array-lifetime-trial.json, physics-array-find-trial.json and document-swap-provider-trial.json.

- Moved PhysicsService assembly on/off event bodies into the original array-name lifetime profile. Both match 005e9110/005e9130 (32 bytes), with original fromPrimitive and onAdded/onRemoved call targets checked. Rebuilt joint factory object without its pointer-name event bodies; diagnostic still has 142 errors. onRemoved remains in the provisional shared-header profile; class layout, signal/data identity and runtime remain unproven. Do not run diagnostic; no P5/P6 rerun. Evidence: physics-array-lifetime-trial.json, world-service-joints-find-trial.json, document-swap-provider-trial.json.

- Moved PhysicsService::onRemoved to the original array-name profile: 005e9040 matches 196 bytes and the original erase/shared_from/fire/signal targets. shared_from and shared_from_this match and lead to weak-count constructor 00411ad0. Removed the recovered unit's incorrect no-exception weak-count definition; PartInstance donor constructor matches 104 bytes, though linker selection remains unproven. Diagnostic now exposes another no-exception Boost function-call path and rises 142 -> 143 unresolved errors. Signal identity, full PartInstance layout and runtime remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- Excluded recovered unit's incompatible no-exception Boost function1 call operator. The PartInstance donor's matching specialization matches original 00496a00 (190 bytes); traced original signal callback chain to that address. Diagnostic errors 143 -> 142. Link selection, remaining signal identity and runtime ABI remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered PhysicsService AssemblyAdded/AssemblyRemoved signal descriptors and original part parameter name from native initializer references. Initializers 007f6e40/007f6e60 match 32 bytes each; descriptor constructor 005e8df0 matches 194 bytes, with original name, descriptor, storage and constructor targets checked. Diagnostic replaces unresolved eventRemoved with a newly exposed Boost GenericSlotWrapper no-exception allocation dependency; still 142 errors. Runtime initialization order, class layout and ownership remain unproven; do not run diagnostic. No P5/P6 rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- Restored Boost shared_count pointer constructor's original allocation-failure cleanup/rethrow path. Physics signal connectGeneric 0049de70 (219 bytes) matches and its original vtable slot targets the matching GenericSlotWrapper shared_count constructor 0041a620 (131 bytes); operator new and C++ rethrow targets checked. Diagnostic errors 142 -> 141. Live class/data ownership, COMDAT selection and runtime remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- PhysicsService::onAdded 005e8f70 now matches 203 bytes in the array-name profile: retaining std::set insertion's actual pair result reproduces original stack layout. Its shared_from, signal, eventAdded and insert targets match; set insertion 005e8c40 also matches 239 bytes. Diagnostic errors 141 -> 140. PartInstance inheritance, runtime ownership, data and link selection remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence physics-array-lifetime-trial.json and document-swap-provider-trial.json.

- Reused recovered Math::matrixRotateY source for RotateSelectionVerb::getRotationAxis: original 0057d520 matches 24 bytes, original vtable slot plus matrixRotateY and Matrix3 copy targets verified. Existing Math.obj matrixRotateY also matches 005de800. Diagnostic errors 140 -> 139. Axis command lifetime, Matrix3 ABI, COMDAT selection and runtime remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence rotate-axis-trial.json and document-swap-provider-trial.json.

- TiltSelectionVerb original getter 0057dc60 establishes Workspace camera interface offset +0x288 and virtual slot +8. Donor Workspace profile compiles same 65-byte shape but uses +0x270 and slot +4; rejected from diagnostic. This is evidence against treating the newer donor Workspace layout as native; full layout and constructor/destructor proof remain open. Diagnostic remains 139 errors, P5/P6 not rerun. Evidence tilt-axis-donor-mismatch.json.

- Cross-checked native Workspace camera interface against constructor and destructor vtable writes: +0x288 uses table 00833998, slots +4/+8 target 005a05a0/005a0210. Native slot +4 reads object pointers at +0x3fc and +0x404. Filtered donor getGCamera matches 005a0210 (13 bytes), but donor getCamera is 262 bytes versus original slot body 17; layout and pointer ownership remain unproven. No diagnostic code promoted; errors remain 139 and P5/P6 not rerun. Evidence workspace-camera-layout-evidence.json.

- Verified native Workspace constructor initializes the +0x3fc/+0x400 pair and passes +0x404 to factory 0045db40; original destructor releases reference-count controls at +0x408 and +0x400. This supports two owned pointer pairs and constrains the native camera getter; first pointee type, complete class layout and runtime remain unproven. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence workspace-camera-layout-evidence.json.

- Confirmed Workspace +0x404 factory 0045db40 allocates 0x1e8 and calls 005cd9a0; constructor vtable RTTI identifies RBX::Camera and establishes its GCamera member at +0x130. Constructor/destructor evidence continues to support a reference-counted Camera pair at +0x404/+0x408; full Workspace layout and first pair's type remain unproven. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence workspace-camera-layout-evidence.json.

- Tested mined 0046c230 ExecScript algorithm against actual CWorkspace/MFC headers and tentative helper declaration. Native-header port compiles to 580 bytes versus original 511 and is not an exact match; helper identity and URL binding are unproven. Excluded from diagnostic rather than promote server credit or scaffolding as integration. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence workspace-execscript-port-mismatch.json.

- ExecScript 0046c230 now matches 511 bytes in an isolated native-header profile when original imported CString conversion and std::string c_str are kept out of line. Verified URL predicate 0055bd10 and internal script helper 0046b230; the tentative helper declaration uses SAFEARRAY**, while separately mined helper source describes IDispatch**, so result ownership/type and complete ABI require resolution before linking. Normal inline header profile remains 580 bytes. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence workspace-execscript-port-mismatch.json.

- Resolved ExecScript result type: embedded IWorkspace typelib specifies SAFEARRAY(VARIANT)* output; original helper 0046b230 writes the return of 004165e0, which calls SafeArrayCreate(VT_VARIANT). Corrected mined helper's IDispatch** assumption. Added matching 0046c230 body to inactive document diagnostic and declared native helper in CWorkspace; ExecScript unresolved is replaced by helper 0046b230 unresolved, so errors remain 139. Helper implementation, class lifetime and runtime remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-execscript-port-mismatch.json and document-swap-provider-trial.json.

- Recovered CWorkspace::execScript helper 0046b230 using native DataModel::Lock, ScriptContext, TrustedCOM identity and ValueCollection: 717/717 bytes match, with security check, four argument conversions, service creation, execution, SAFEARRAY conversion, unlock and error targets verified. Diagnostic resolves helper but exposes LuaArgs::push and makeSafeArray: 139 -> 140 errors. Conversion implementations, class lifetime, ownership and runtime remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-execscript-helper-trial.json and document-swap-provider-trial.json.

- Rebuilt SAFEARRAY conversion with real ATL CComSafeArray<VARIANT> and Reflection::ValueCollection. Its GetAt accessor 00415b00 matches all 135 bytes and original bounds/error call targets; builder 004165e0 remains 189 vs 168 bytes under normal headers, including extra checked-vector access. Excluded builder from diagnostic; iterator security configuration and value conversion need proof. Diagnostic remains 140 errors; P5/P6 not rerun. Evidence safearray-builder-mismatch.json.

- Recovered native LuaArgs::push VARIANT conversion 0042db20 (692 bytes), using real Reflection::Value and shared LuaArgs declarations. Corrected the donor Value template constructor to accept the original const-reference input; float, bool, integer and string constructors plus vector push_back match original targets and bytes. Diagnostic errors 140 -> 139. Value destructor, type singleton identity, conversions' full runtime ownership, all affected shared-header consumers and live swap remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence lua-args-trial.json, workspace-execscript-helper-trial.json and document-swap-provider-trial.json.

- Original Value-to-VARIANT converter 00416370 checks RTTI for std::string, ContentId and vector<Reflection::Value>; its nested-vector branch calls SAFEARRAY builder 004165e0 recursively. Mined matching stub mislabeled this last type vector<Instance>, so must not be promoted as native source. Existing ATL accessor still matches; builder remains excluded. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence safearray-builder-mismatch.json.

- Tested typed Value-to-VARIANT conversion with real Reflection::Value, ContentId and nested ValueCollection rather than mined stub types. Candidate 635 bytes differs from original 00416370 (615 bytes); temporary reference accessor and ContentId lifetime remain unproven, so candidate is excluded. Diagnostic remains 139 errors; P5/P6 not rerun. Evidence value-variant-mismatch.json.

- Recovered CWorkspace::ExecUrlScript 0046c430: 841/841 bytes match using native content service, stream copy, script helper and original SAFEARRAY output. Verified original URL fetch, stream copy, helper, string import and error targets. Diagnostic errors 139 -> 138. ContentProvider profile is provisional; initialization, shared layouts, script ownership and runtime remain unproven. Do not run diagnostic; P5/P6 not rerun. Evidence workspace-execurl-trial.json and document-swap-provider-trial.json.

- Recovered CWorkspace SaveToFile 0046c780 (403 bytes) and SaveSelectionToFile 0046b8d0 (253 bytes), including original vtable entries, DataModel locking and XML writer call targets. Added both to inactive diagnostic: two save-method errors replaced by writeXmlSelection 0046b750 and write 0046b860, leaving 138 errors. Those writer signatures, ownership, class lifetime and live ABI remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-save-trial.json and document-swap-provider-trial.json.

- Recovered TextXmlWriterWithEmbeddedContent: RTTI identifies original vtable 0081c848, and a typed profile with ContentProvider member matches both constructor 0046b550 (98 bytes) and implicit destructor 0046b1e0 (77 bytes), including ContentId set and InstanceHandle map destructor targets. An explicit destructor differs, and CWorkspace::write caller still differs (130 vs 112 bytes in the implicit profile); no shared header or diagnostic promotion yet. Diagnostic remains 138 errors; P5/P6 not rerun. Evidence workspace-xml-writer-mismatch.json.

- Recovered CWorkspace::writeXmlSelection 0046b750 (261 bytes) and instance-to-XML collector 0057e140 (140 bytes). Verified root creation, DataModel lock, native Selection service, collector and unlock bindings plus original virtual Instance::write slot. Diagnostic errors 138 -> 137. Donor Workspace projection, Selection layout, XML ownership and live class ABI remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-selection-serializer-trial.json and document-swap-provider-trial.json.

- Recovered CWorkspace::Insert 0046c920 (416 bytes) and ContentId insertion helper 0046bc90 (220 bytes). Verified original COM vtable, URL trust check, content provider, stream insertion and error targets. Diagnostic errors 137 -> 136. ContentProvider profile, trust behavior, class lifetime and live ABI remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-insert-url-trial.json and document-swap-provider-trial.json.

- Recovered CContent COM base layout from original RTTI: ISupportErrorInfo at +0, IContent/IDispatch +4, ATL root +8, stringstream +0xc, object size 0x94. Typed CComObject<CContent>::CreateInstance 0046ac90 matches 209 bytes and scalar deleting destructor 00416950 matches 67 bytes, including original vtables, stream constructor/destructor and allocator targets. CContent Upload, COM map data/GUID identity and runtime ownership remain unproven; not yet linked into document diagnostic. Errors remain 136; P5/P6 not rerun. Evidence content-factory-trial.json.

- Recovered CContent::Upload 004166a0 (457 bytes) and native exception reporter 00429360 (49 bytes), including original URL trust, Http::post, error-context and vtable targets. Verified IContent IID against original typelib and CLSID_Content bytes against original 00816518; original typelib identifies Content coclass with that CLSID. HTTP implementation, COM map identity and runtime ownership remain unproven; not yet linked into diagnostic. Diagnostic remains 136 errors; P5/P6 not rerun. Evidence content-upload-trial.json.

- Recovered CWorkspace::Write 0046bd70 and WriteSelection 0046bfd0, 600 bytes each, using original CContent factory and XML roots. Verified COM vtable entries, factory, writer and error-call targets; inserted both plus CContent factory, Upload and GUID profiles into inactive diagnostic. Two COM methods resolve but writer/error dependencies add three references: diagnostics 136 -> 137. XML writer, error helper definitions, COM data identity, HTTP donor and live ownership remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-write-trial.json, content-factory-trial.json, content-upload-trial.json and document-swap-provider-trial.json.

- Recovered native HRESULT reporter 00427d80 (206 bytes) and Workspace exception throw 0046ad70 (177 bytes), using real COleException, original E_NOTIMPL status, formatting, logging and ATL error targets. Added both to inactive document diagnostic: errors 137 -> 135. MFC exception data identity, XML writer ownership and live class ABI remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence workspace-hresult-trial.json, workspace-raise-error-trial.json and document-swap-provider-trial.json.

- Verified CContent original COM map 0080ead0: all 48 bytes, three IID values and interface offsets [4,4,0] match, plus QueryInterface 00416900 and IContent thunk 00416920 match their original bodies and dispatch targets. Rebuilt inactive diagnostic with verified factory object; errors remain 135. Actual linker data selection, full vtables and live ownership remain unproven; do not run diagnostic. P5/P6 not rerun. Evidence content-factory-trial.json and document-swap-provider-trial.json.

- CContent Upload's real Http constructor 00409750 (77 bytes) and destructor 005df620 (78 bytes) match; donor Http::post 00569a40 matches 155 bytes with original request-method targets. Both donor request backends differ (1835 vs 2515 and 1835 vs 2261 bytes), so exact Upload/post does not establish native HTTP behavior. Diagnostic remains 135 errors; no runtime promotion or P5/P6 rerun. Evidence content-upload-trial.json and document-swap-provider-trial.json.

- Inventoried all 13 CContent COM vtable slots against original tables 0080eabc/0080ea98: 11 locally emitted methods match their original bodies. Upload and deleting-destructor vtable references are external in that object; their corresponding bodies were verified separately, but final linker alias/data selection remains unproven. Diagnostic remains 135 errors; do not run. P5/P6 not rerun. Evidence content-factory-trial.json and document-swap-provider-trial.json.

- Recovered Http::trustCheck 0056a2e0 from the existing rbxgs source: isolated body matches all 638 bytes, with original initializer, URL predicates and static-data addresses identified. Initializer candidate differs (216 vs 180 bytes), and donor isRobloxSite differs (550 vs 381); donor isScript matches 288 bytes. Therefore security behavior and shared static-data identity remain unproven; trial stays excluded from the diagnostic. Errors remain 135; P5/P6 not rerun. Evidence http-trust-trial.json.

- Tested SAFEARRAY builder with MSVC _SECURE_SCL=0: candidate shrinks from 189 to 166 bytes versus original 168, but vector storage shifts from original +0xc/+0x10 to +4/+8. Reject profile due to ABI mismatch. Original ATL accessor still matches. No diagnostic promotion; 135 link errors, P5/P6 not rerun. Evidence safearray-builder-mismatch.json.

- Recovered ReportAbuseVerb::doIt 0044f700 using native AfxGetApp and PostMessage: all 36 bytes, original vtable slot 008172f0, MFC module-state and USER32 import targets match. Added to inactive document trial; linker errors 135 -> 134. Document/verb layouts and runtime remain unproven; P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered ExitCommand::doIt 0044f730 using candidate native frame and real document view methods: 105 bytes match, original vtable slot 00817314 and MFC/USER32 targets verified. Added to inactive document trial; linker errors 134 -> 133. Full frame/document ABI, vtable selection and runtime remain unproven; P5/P6 not rerun. Evidence exit-command-trial.json and document-swap-provider-trial.json.

- Recovered ReportAbuseVerb::isEnabled 004532d0: exact 277-byte body using native document DataModel, lock, Players factory and canReportAbuse. Verified original vtable slot 008172e8 and all direct target addresses. Added to inactive trial; errors 133 -> 132. Players and document runtime ABI and ownership remain unproven; P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Verified CameraPanLeft, CameraPanRight and CameraZoomExtents isEnabled slots each point to original 00565950 (mov al,1; ret). Implemented the three native bodies and verified their original vtable slots. Inactive diagnostic errors 132 -> 129. Remaining camera paths depend on unresolved Workspace +0x288 camera interface and full layout; runtime and P5/P6 remain unverified. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered ModelInstance +0x1ec as vector<IModelModifier*> from original remove 00584fc0: dynamic-cast RTTI identifies Instance and IModelModifier, iteration uses 4-byte pointer elements. Added actual member to shared ModelInstance header; native ModelInstance constructor 00585630 (594 bytes) and destructor 00584790 (421 bytes) match. Workspace candidate now matches 11 original RTTI base offsets, including ICameraOwner +0x288 and VerbContainer +0x2ec. Restored donor ServiceClient constructor and recovered exact CameraVerb constructor 0057e3d0 (146 bytes): diagnostic replaces its unresolved constructor with unresolved base doIt, staying 129 errors. Diagnostic mixes preexisting objects from before shared-header change and is not live ABI proof; rebuild affected objects before a runtime trial. P5/P6 not rerun. Evidence model-vector-lifetime-trial.json, workspace-native-base-offsets.json, document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered four camera tilt/zoom isEnabled bodies at 0057d570/590/5b0/5d0 (30 bytes each), using verified Workspace camera interface +0x288 and real Camera::canTilt/canZoom declarations. All original method bodies, vtable slots and direct call targets match. Inactive diagnostic errors 129 -> 125. Existing linked objects predate shared ModelInstance header update; rebuild affected objects and verify Camera implementation and full Workspace runtime ABI before a live trial. P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered native FixedCamera isChecked 0057d5f0 (34 bytes) and seven CameraVerb/pan/tilt/zoom action bodies 005819a0..00581b60. All bodies and original vtable slots match; verified camera and SoundService direct targets, SoundService RTTI and zoom constant. Diagnostic errors 125 -> 120; newly exposed dependencies are SoundService::playSound and Camera::panUnits/tiltUnits. Existing linked objects predate shared ModelInstance update; rebuild affected objects before any runtime trial. P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered Camera::panUnits 005cc930 (111 bytes) and tiltUnits 005cc890 (155 bytes) using native Camera/G3D types and original constants. Verified exact bodies, cameraGoal access, original call targets, and radians constant bytes. Added inactive trial: linker errors 120 -> 118. Camera full lifetime/ownership and linked dependency identity remain unproven; diagnostic includes older objects requiring rebuild. P5/P6 not rerun. Evidence camera-units-trial.json and document-swap-provider-trial.json.

- Recovered SoundService::playSound 005bd820 using native stockSounds map and SoundChannel::play: 98 bytes match, including map lookup and original direct-call/import targets. Added to inactive diagnostic; linker errors 118 -> 117. SoundService lifetime/map ownership, SoundChannel implementation and runtime remain unproven; older objects need rebuild. P5/P6 not rerun. Evidence sound-service-play-trial.json and document-swap-provider-trial.json.

- Recovered FixedCameraCommand::doIt 0057d620 (80 bytes), ChangeHistory lookup 0058a9e0 (65 bytes) and history dispatch 0058c5c0 (30 bytes) with native DataModel/Instance/ChangeHistory types. Exact bodies, original vtable slot, RTTI and direct targets verified. Diagnostic errors 117 -> 116. Shared header changes require rebuilding older dependent objects; full runtime ownership remains unproven. P5/P6 not rerun. Evidence camera-history-trial.json, document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered CameraModelViewCommand::doIt 00581bc0 using native Workspace viewport and setImageServerView: 58-byte body, original vtable slot and rendering/sound targets match. Inactive diagnostic errors 116 -> 115; actual rendering implementation/link selection and full Workspace runtime ABI remain unproven. Older objects require rebuild after shared-header changes; P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered Attach/Track/Follow/Watch camera isChecked methods 0057dcb0/ce0/dd10/dd40: each 35-byte body and original vtable slot match, using corrected Workspace camera interface. Rebuilt affected selection-command trial; inactive diagnostic errors 115 -> 111. Other objects still predate shared-header changes; class lifetime and runtime remain unproven. P5/P6 not rerun. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Corrected CameraVerb's selection client from Selection to FilteredSelection<PVInstance>. Original CameraCenter isEnabled 00582300 -> service-client 00581d80 -> provider helper 00580800 -> service factory 005805d0 -> allocation 0057f710 -> constructor 0057eeb0; original constructor vtable RTTI identifies FilteredSelection<PVInstance>. CameraVerb constructor remains exact after correction. Diagnostic remains 111 errors; filtered-selection lifetime and runtime are unproven, older objects need rebuild. P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Recovered typed FilteredSelection<PVInstance> hierarchy and members in shared Selection.h. Original 0057eeb0 constructor (258 bytes) and 0057f040 destructor (288 bytes) both match, including original RTTI vtable, Instance::setName and Selection::removeFilteredSelection targets. ISelectionBase requires novtable for constructor fidelity. A CameraCenter isEnabled candidate still differs (226/250/251 bytes vs original 229) and remains excluded. Recompiled document and selection-command trials; diagnostic remains 111 errors, other old objects still need rebuild. P5/P6 not rerun. Evidence filtered-selection-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered CameraCenterCommand::isEnabled 00582300 (229 bytes), its FilteredSelection service-client 00581d80 (186 bytes), and context lookup 00580800 (65 bytes); exact bodies, original vtable and service-creation targets verified. Diagnostic still 111 errors: replaces CameraCenter unresolved method with underlying ServiceProvider::create<FilteredSelection<PVInstance>> unresolved. Other objects remain stale after shared-header changes; runtime and P5/P6 unverified. Evidence document-initialize-trial.json, filtered-selection-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered provider factory 005805d0 for FilteredSelection<PVInstance> (228-byte exact body) and selection-change callback 0057fba0 (185 bytes, original RTTI/vector calls and interface vtable verified). Constructor/destructor remain exact. Factory resolves provider create but exposes provider find 0057fd20; selection callback resolves separately, leaving diagnostic 111 errors. A generic find candidate is 386 vs 174 bytes; trivial no-name variant is 123 vs 174 and lacks original exception lifetime. Excluded. Service-index singleton identity, remaining class lifetime and runtime unproven; stale objects require rebuild; P5/P6 not rerun. Evidence filtered-selection-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered CameraCenterCommand::doIt 005823f0: native 562-byte body matches with filtered selection, original extents union, fixed camera focus, sound and dirty-state calls. Verified original vtable and key targets. Split camera declarations and compiled action separately with original /fp:fast; existing document initialization and filtered-selection lifetime verification still pass. Inactive diagnostic errors 111 -> 110. Filtered-selection provider find, singleton identity and full runtime ABI remain unproven; older objects need rebuild. P5/P6 not rerun. Evidence camera-center-action-trial.json and document-swap-provider-trial.json.

- Tested typed CameraZoomExtentsCommand::doIt 00582f50 using native Workspace, PV filtered selection, Extents, camera, sound and history APIs. Candidate is 691 bytes like original but differs in final Extents assignment/store ordering; implicit assignment and three expression variants also failed. Original vtable slot verified. Candidate stays excluded; diagnostic remains 110 errors. Full ABI/ownership remains unproven; P5/P6 not rerun. Evidence camera-zoom-extents-mismatch.json.

- CameraZoomExtentsCommand::doIt 00582f50 now matches all 691 bytes in an isolated profile adding __declspec(noalias) to Extents::unionWith; the original union routine makes no calls, but its original declaration is unknown. Verified original vtable slot and selection, camera, sound and history targets. Normal header remains a documented mismatch. Diagnostic errors 110 -> 109 with profile; old objects still need rebuild and full ABI, singleton identity and runtime remain unproven. P5/P6 not rerun. Evidence camera-zoom-extents-profile.json and document-swap-provider-trial.json.

- Recovered InsertDecal constructor 0041dd60 (47 bytes) and verified its scalar deleting destructor 005c6090 (30 bytes), original vtable and EditSelectionVerb lifetime calls. noinline preserves original constructor call boundary in document initialization. Diagnostic stays at 109 errors: constructor resolves, revealing InsertDecal::createInstance. Shared lifetime/layout and runtime still unproven; other objects need rebuild; P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Corrected InsertDecal/InsertTexture createInstance return type to shared_ptr<Decal>: original consumer 0041f040 calls Decal texture setter 00598610 and native constructors identify Decal/Texture by RTTI. Typed wrappers 0041e650/0041e670 match exactly, but their emitted native factories allocate donor sizes 0x15c/0x164 versus original 0x16c/0x174, so wrappers and unsafe factories remain excluded. Diagnostic remains 109 errors. Original Decal/Texture constructor/destructor layout and runtime still unproven; P5/P6 not rerun. Evidence decal-factory-mismatch.json and document-swap-provider-trial.json.

- Identified 16-byte Decal/Texture discrepancy: native FaceInstance RTTI includes IRenderable at +0x130, with indices/bucket initialized by constructor. Added native base; FaceInstance constructor 005ef530 (191 bytes) and destructor 00597500 (79 bytes) both match. Decal and Texture factory allocation sizes now match 0x16c/0x174 and both factory wrappers/factories match; Decal constructor/destructor and Texture constructor also match. Texture destructor target and full virtual ownership remain unproven, so factory wrappers remain excluded from diagnostic. Shared-header consumers need rebuilding; P5/P6 not rerun. Evidence face-instance-lifetime.json, decal-lifetime-trial.json and decal-factory-revalidated.json.

- Proved Texture original delete path via boost control vtable 0080f18c -> dispose 0048ee50 -> Texture base vtable 00832960 -> adjustor 00598950 -> scalar delete 00598970 -> FactoryProduct<Texture,Decal> destructor 00597da0 -> Decal destructor 00597d30. The actual FactoryProduct destructor matches 93 bytes and binds original Decal destructor; both derived constructors and Face/Decal destruction were already verified. Added exact InsertDecal/InsertTexture factory wrappers and native lifetime objects to inactive diagnostic. Both unresolved wrapper errors resolve, but old donor FaceInstance.obj/Decal.obj introduce three duplicate constructors: errors 109 -> 110. Do not run; donor object filtering/rebuild, complete virtual slots, data identity, stale-object rebuild and P5/P6 remain outstanding. Evidence decal-lifetime-trial.json, document-initialize-trial.json and document-swap-provider-trial.json.

- Removed outdated donor FaceInstance.obj and Decal.obj from inactive filtered archive, resolving three duplicate constructors and exposing real missing dependencies. Recovered FaceInstance::askSetParent 0062e190 (36 bytes): original Face/Decal/Texture vtable slot, PartInstance RTTI and dynamic-cast targets match. Added original FaceInstance name string; classDescriptor still differs (102 vs 101 bytes), so data identity remains unproven. Diagnostic errors 110 -> 114 after donor filtering -> 111 after askSetParent and name. Decal factory base constructors/class names and other ABI dependencies remain unresolved; older objects need rebuild. P5/P6 not rerun. Evidence face-instance-lifetime.json and document-swap-provider-trial.json.

- Recovered Decal/Texture DescribedCreatable and FactoryProduct base constructor chains (00598340/00598790/00597550/005985a0), plus both original class-name and literal-backed registration bodies (00597d80/00597e20/0041de20/0041de90). Exact bytes, base calls and original class-name vtable slots verified. Diagnostic errors 111 -> 107; original singleton/data identity and full virtual/runtime behavior still require proof, and older dependent objects need rebuild. P5/P6 not rerun. Evidence decal-lifetime-trial.json and document-swap-provider-trial.json.

- Recovered InsertDecal target selection 0041ef90 (174 bytes) and isEnabled 0041f280 (34 bytes). Original RTTI confirms allowed PartInstance or SpecialShape; selection lookup/front, EditSelectionVerb check and vtable slot match. Diagnostic errors 107 -> 106. Selection ownership, full class ABI and runtime remain unproven; stale dependent objects need rebuild. P5/P6 not rerun. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Document swap verification: `python rebuild/2008-06/tests/verify_document_swap.py` runs 13 dependency checks in parallel, then checks the diagnostic linker result. Latest: 13 pass, linker exit 1120, 106 errors, 45.7 s. This rebuilds only those dependencies; remaining trial objects are older, and the diagnostic must not be run.

- Integrated native StopCommand::isEnabled 00582770 into inactive document diagnostic. All 25 bytes match; original RTTI, vtable slot and ServiceClient call target verified. Link errors 106 -> 105. Other objects remain stale; full ABI and runtime unproven. P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Integrated native RunCommand::isEnabled 00582700 and ResetCommand::isEnabled 005827c0 into inactive document diagnostic. Both match 56 bytes, original RTTI/vtable slots and service/network call targets. Diagnostic link errors 105 -> 103; linked provider bodies, older objects, complete ABI and runtime remain unproven. P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Integrated native Run/Stop/Reset doIt bodies 00582740/00582790/00582800 and shared permission helper 0057d250 into inactive document diagnostic. Three 39-byte methods and 120-byte helper match; original vtable slots, permission/service/state call targets and exception literal checked. Diagnostic errors 103 -> 100. Provider bodies, exception data identity, older objects, complete ABI and runtime remain unproven. P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Batched native AnchorVerb/TranslucentVerb/CanCollideVerb constructors and BoolPropertyVerb base constructor into inactive document diagnostic. All four match original bytes; RTTI, original labels and base-call bindings verified. Three previous constructor errors resolve, exposing BoolPropertyVerb methods and base constructor; integrating base leaves 99 errors (100 -> 99). Original property behavior, ownership, older objects and runtime ABI remain unproven. P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Integrated FirstPersonCommand::isEnabled 0057d9c0 into inactive document trial: 33-byte match, original RTTI/vtable and Camera::isFirstPersonCamera target verified. Diagnostic remains 99 errors: the command error is replaced by its missing native camera predicate. Original predicate RTTI identifies Instance -> ICameraSubject -> ICharacterSubject, reading +0x3c; ICharacterSubject layout and getter require further proof. Old objects, provider ABI and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Isolated Camera::isFirstPersonCamera 005ccb00 matches all 71 bytes using provisional inline ICharacterSubject cursor-lock getter; all three original RTTI descriptors and dynamic-cast target verified. Existing P5 compiler-layout evidence places the donor field at +0x3c, but constructor/destructor and semantics remain unproven. Kept object out of link. Diagnostic still 99 errors; P5/P6 not run. Evidence camera-first-person-trial.json.

- Audited ICharacterSubject lifetime: donor constructor 00641320 (109 bytes) and Humanoid constructor 005db280 (565 bytes) match original; original Humanoid calls base at +0x14c, and subject constructor initializes cursor-lock at +0x3c. Actual character-vtable destructor path 0083d388 -> 005d8090 (subtract 0x14c) -> 005d8400 -> Humanoid destructor 005d7d20. Donor destructor differs (726 vs 698 bytes), so lifetime/ABI remains unproven and camera predicate remains excluded. Diagnostic stays 99 errors; P5/P6 not run. Evidence character-lifetime-audit.json.

- Follow-up: recovered verified/0003.obj already contains exact 698-byte Humanoid destructor 005d7d20; ordinary donor destructor differs. Verified object emits an extra onGuidChanged virtual slot, shifting readProperty from original slot 11 to 12, so it remains unsafe to swap. Updated character-lifetime-audit.json; no runtime promotion or P5/P6 gate.

- Shared-header Humanoid destructor trial matches original 698 bytes and emits readProperty at original vtable slot 11, avoiding previous verified object extra-slot mismatch. Both constructor matches retained. Destructor call targets, complete vtables, RTTI/data identity and runtime still unproven; trial not selected or run. P5/P6 not run. Evidence character-lifetime-audit.json.

- Verified shared-header Humanoid destructor selected call targets and RTTI type descriptors for all 17 original Humanoid vtable addresses. Notifier symbols use Descendant spelling while donor ctor symbols use Descendent; symbol/data identity and full vtable slots must be reconciled before link promotion. Runtime and P5/P6 remain untested. Evidence character-lifetime-audit.json.

- Original Humanoid RTTI hierarchy proves DescendantAdded/DescendantRemoving spelling used by shared Instance header; donor Humanoid constructor emits different Descendent names despite byte match. Rebuild/reconcile dependent donor objects before any link or runtime swap. Automated hierarchy assertions added to character-lifetime-audit.json; P5/P6 not run.

- Shared-header Humanoid constructor trial 005db280 has correct 565-byte size but differs: original clears five bits at +0x1e8 (mask e0), candidate clears four (f0), and relocation sets differ. Fifth bit and targets remain unproven; candidate excluded. Shared-header destructor reverified. Evidence humanoid-constructor-mismatch.json and character-lifetime-audit.json. No P5/P6 run.

- Identified fifth Humanoid +0x1e8 bit 0x10 as strafe: original setter 005dc230 and movement reader 0066f2c0 both access it. Provisional overlay adds and initializes strafe; shared-header Humanoid constructor now matches all 565 bytes relocation-masked. Full bindings, layout, RTTI and destructor under same overlay remain unproven; not linked or run. Evidence humanoid-constructor-mismatch.json. P5/P6 not run.

- Same provisional strafe overlay now passes Humanoid constructor and destructor byte checks (565/698), destructor readProperty slot 11, constructor ICharacterSubject call and original camera vtable, plus native Descendant notifier spelling. Whole-class lifetime, other virtual slots, data and runtime still unproven; no link or P5/P6 run. Evidence humanoid-constructor-mismatch.json.

- Strengthened Humanoid strafe evidence: original PlayerController 005cb530 calls original bit-4 setter 005dc230 at 005cb723 and 005cb7de; original movement reader 0066f3b6 checks same bit. Automated assertions accompany same-overlay constructor/destructor matches. Property descriptor identity, full class ABI and runtime remain unproven; P5/P6 not run. Evidence humanoid-constructor-mismatch.json.

- Proved original Strafe property identity: initializer 007f6690 binds descriptor 0097a5c0, getter 005d7540, setter 005dc230 and Control/Strafe literals. Getter reads bit 4 at Humanoid +0x1e8. Automated assertions added; static data construction, full ABI and runtime remain unproven. P5/P6 not run. Evidence humanoid-constructor-mismatch.json.

- Compiled native Humanoid::getStrafe using same provisional shared-layout overlay: matches original 005d7540 exactly. Constructor and destructor remain exact under same overlay. Setter, property static construction, complete class ABI and runtime still unproven; no P5/P6 run. Evidence humanoid-constructor-mismatch.json.

- Native Humanoid::setStrafe 005dc230 now matches 55 bytes under provisional shared-header overlay, including original raisePropertyChanged 0040db00 and propStrafe 0097a5c0 bindings. Getter, ctor/dtor remain exact in same profile. Instance notification declaration, property static construction, whole ABI and runtime require integration; no P5/P6 run. Evidence humanoid-constructor-mismatch.json.

- Native Strafe descriptor initializer 007f6690 matches 91 bytes with original getter, setter and descriptor addresses under provisional shared-header overlay. Descriptor constructor/destructor, registration, static identity, full ABI and runtime remain unproven; no link promotion or P5/P6 run. Evidence humanoid-constructor-mismatch.json.

- Strafe descriptor constructor 005da8b0 (193 bytes) and static cleanup 007ff340 (29 bytes) also match under provisional shared overlay. Their relocation targets, registration identity, full lifetime/ABI and runtime remain unproven; not promoted. P5/P6 not run. Evidence humanoid-constructor-mismatch.json.

- Verified Strafe descriptor constructor and cleanup original call/data bindings, both original RTTI vtable types and both property base/interior addresses. Registration, complete dependency ABI and runtime still unproven; no link promotion or P5/P6. Evidence humanoid-constructor-mismatch.json.

- Batched Track/Follow/Watch camera-enabled native candidates: Track 71 vs 77 bytes, Follow/Watch 76 vs 75; all nonmatching and excluded. Recorded isolated source and compiler evidence for next iteration. Document diagnostic still 99 errors; selection lifetime ABI unproven, P5/P6 not run. Evidence camera-selection-enabled-mismatch.json.

- TrackCameraCommand::isEnabled 00582e50 now matches all 77 bytes with native Selection and original selection/service targets and vtable slot verified. Diagnostic link errors 99 -> 98. Follow/Watch remain nonmatching isolated trials; ownership, stale objects and runtime unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json, camera-selection-enabled-mismatch.json and document-swap-provider-trial.json.

- Follow/Watch camera-enabled candidates now 77 vs original 75 bytes. Original returns via AL without zeroing EAX; candidate inserts xor eax,eax. Five O1/O2/inline compiler profiles fail exact match; experiment remains isolated. Diagnostic remains 98 errors; P5/P6 not run. Evidence camera-selection-enabled-mismatch.json.

- Follow/Watch camera-enabled methods now match original 00582ea0 (75 bytes) using a named bool return; both original vtable slots and selection/service targets verified. Diagnostic errors 98 -> 96. Earlier mismatch receipt remains historical. Service ownership, older objects and runtime unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- AttachCameraCommand::isEnabled 00582d70 now matches 221 bytes using temporary native ServiceClient and its shared lifetime. Original vtable slot and both createService targets verified. Document diagnostic link errors 96 -> 95. Full service ownership, stale objects and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Attach/Watch camera actions 00581360/005815a0 match 131 bytes each; original vtable slots, filtered-selection and history call targets verified. Diagnostic link errors 95 -> 93. Camera/service ownership, stale objects and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Track/Follow camera actions 005813f0/00581510 match 278/131 bytes, original vtable slots, selection/service and history calls. Document diagnostic link errors 93 -> 91. Full camera/selection ownership, stale objects and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Batched Group/Weld/Snap/Duplicate selection-enabled methods: all match original bytes and vtable slots; original selection/service calls verified. Document diagnostic errors 91 -> 87. Selection ownership, stale objects and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Ungroup selection predicate 00582b50 and child test 0057e110 match 90/43 bytes in isolated trial; original RTTI confirms FilteredSelection<ModelInstance>. Provisional findFirst helper 0057edb0 has same 172-byte length but mismatches, so no link promotion; helper name, bindings, ownership and runtime unproven. P5/P6 not run. Evidence ungroup-selection-trial.json.

- Ungroup predicate, child test and ModelInstance filtered findFirst helper now match 90/43/172 bytes; original slot and call targets verified. Added provisional findFirst declaration to shared Selection header; 13 dependency checks pass. Diagnostic remains 87 errors: Ungroup error replaced by missing ModelInstance filtered-selection factory. Remaining objects stale; no runtime/P5/P6 claim. Evidence ungroup-selection-trial.json, selection-command-constructors-trial.json and document-swap-provider-trial.json.

- ModelInstance filtered-selection provider factory 005806c0 matches 228 bytes with original find/create/index/parent targets. Integrated inactive diagnostic; error count remains 87 because missing create becomes missing find. Model factory lifetime, identity, stale objects and runtime unproven; P5/P6 not run. Evidence filtered-selection-lifetime-trial.json and document-swap-provider-trial.json.

- Original PVInstance and ModelInstance filtered-selection provider lookups 0057fd20/0057fdd0 are the same 174-byte normalized body; automated check verifies both flags, callbacks, class indices and common call targets. One real template may cover both missing symbols, but authentic exception-lifetime source remains unproven; no link promotion. P5/P6 not run. Evidence filtered-lookup-pair.json.

- ControllerCommand::isEnabled 00582ef0 and PVInstance isControllable predicate 0057d550 match native bytes; PV filtered findFirst also matches shared 0057edb0. Original two vtable slots and service/helper targets verified. Diagnostic errors 87 -> 85. Filtered ownership, other stale objects and runtime unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Primary/Secondary controller actions 00581920/00581960 match 62 bytes each in isolated shared-header overlay; original vtable, helper 00581890 and history targets verified. Helper signature/name and implementation remain provisional, so no link promotion. P5/P6 not run. Evidence controller-actions-trial.json.

- Recovered controller action pipeline: Primary/Secondary actions, shared applyController, different-controller selection helper, callback and for_each match original six bodies and selected call/vtable targets. Updated shared declarations. Thirteen dependent checks pass; diagnostic errors 85 -> 83. Other objects stale and full ABI/runtime unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- InsertObject, InsertService and CopyVerb constructors match original 47-byte bodies, RTTI, labels and base calls; initializer remains exact with original call boundaries. Diagnostic still 83 errors: constructors replaced by their missing action methods. Full command ownership and runtime remain unproven; P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- PasteVerb constructor 004134d0 matches 87 bytes with original Verb base call and Paste/PasteInto labels. Diagnostic 83 -> 84 errors: constructor resolves, exposing isEnabled and doIt. Full clipboard ownership and runtime unproven; P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- PasteVerb::isEnabled 004154a0 matches 107 bytes with original vtable, clipboard imports, Roblox format literal, shared format data and selection call. Shared format helper intended for copy/paste actions; complete static identity/runtime still unproven. Diagnostic 84 -> 83 errors; P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- CutVerb constructor 00413920 and DeleteSelectionVerb container overload 00413870 match 66/114 bytes and original base calls; Cut RTTI confirms base layout. Shared header updated; 13 dependency checks pass. Diagnostic 83 -> 85 errors as missing base/action dependencies surface. Other objects stale; P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- Cut DeleteBase overload 00581010 matches 117 bytes and original EditSelectionVerb base call; document initialization and selection/controller checks pass. Diagnostic remains 85 errors as base-constructor dependency surfaces. Other objects stale; P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- EditSelectionVerb container constructor 00580b50 matches 174 bytes with original Verb, Workspace service creation 00490af0 and shared ownership 00618a40 bindings. Earlier inline getWorkspace candidate had wrong call target and was discarded. Shared header updated; 13 dependent checks pass; diagnostic 85 -> 84 errors. Other objects stale; full ABI/runtime and P5/P6 unproven. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- CutVerb::doIt 00413490 matches 61 bytes using native Copy command dispatch then DeleteBase action; original vtable and both direct targets verified. Diagnostic 84 -> 83 errors; underlying Copy/Delete implementation, clipboard lifetime and runtime remain unproven. P5/P6 not run. Evidence document-initialize-trial.json and document-swap-provider-trial.json.

- DeleteBase::doIt 00581090 matches 540 native bytes with original vtable, permission, selection, parent, sound, history and RTTI targets. Integrated inactive diagnostic; errors 83 -> 80. Full selection ownership, sound/data identity, stale objects and runtime remain unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Weld/Snap selection actions 00582990/00582a70 match 213 bytes each, original vtables, permission, selection, callback, sound and history targets verified. Diagnostic remains 80 errors: action symbols replaced by missing recursive weld/snap callbacks. Callback behavior, object ownership, stale objects and runtime unproven; P5/P6 not run. Evidence selection-command-constructors-trial.json and document-swap-provider-trial.json.

- Recovered recursive weld/snap surface visitors 0057eb80/0057e530 from original source: each matches 291 bytes and original cast, Surface and iteration targets. Added inactive objects to diagnostic and batch verifier; link errors 80 -> 78. PartInstance/surface ownership, stale objects and runtime remain unproven; P5/P6 not run. Evidence surface-visitors-trial.json and document-swap-provider-trial.json.

- Surface visitor dependency audit: linked donor PartInstance::getSurfaces and Surface get/set match original bodies; donor Surfaces::operator[] differs (default Back vs original Top). Existing native original source compiled as 005ecc00 exact 72-byte inactive replacement. Avoid duplicate ownership until full link rebuild; P5/P6 not run. Evidence surfaces-lookup-trial.json.

- Inactive native CInsertObjectDialog (fork, Claude): layout 0xfc proven by CRuntimeClass 0080f2e0 plus constructor 0041fe00 and destructor 0041ff40 (parent shared_ptr +0x74, instance vector +0x7c, class-name CString +0x94, selected shared_ptr +0x98, CClassImages +0xa0, CListCtrl +0xa8). 11 of 12 class bodies match under MSVC 21022 with the document-swap flags: constructor, destructor, scalar deleting destructor, GetRuntimeClass, _GetBaseClass, GetMessageMap, OnInitDialog, OnNMDblclk, DoDataExchange (444 bytes), compareItems and the local CListCtrl deleting destructor. Every relocation is bound and verified: MFC imports by RTM ordinal, internal targets, literals, vtable 0080f48c (84/91 slots, the rest shared ICF thunks), CRuntimeClass and the NM_DBLCLK message-map entry. Open: addClasses 004202b0 needs Reflection::Metadata::Class (+0x104 base, +0x130..0x132 flags, +0x154 image index) and the 0041fcf0 settings singleton layouts; CClassImages 00413230/00412f30 bodies. Receipt shared-layouts/insert-object-dialog-working.json; probe tests/record_native_insert_object_dialog.py.
- CClassImages (the dialog's +0xa0 member): constructor 00413230 (455 bytes, IDB_CLASSIMAGES 133 through XTP CXTPImageManagerIcon::LoadBitmapFromResource, alpha/masked branches, std::runtime_error messages), destructor 00412f30 and the CClassImages/CBitmap deleting destructors match with targets verified; compiled with /UNOMINMAX /D_XTP_STATICLINK and the XTP Source include. The probe now covers 15 exact bodies.
- CInsertObjectDialog dependencies recovered (inactive): Metadata::Item 0x150 / Class 0x158 / Metadata::Reflection 0x134 and AuthoringSettings 0x134 layouts (ShowDepricatedObjects +0x130, ShowPreliminaryObjects +0x131 from the bound-property initializers). Exact with verified targets: Metadata::Class::getImageIndex 0041fb30 and GlobalSettingsItem<AuthoringSettings>::singleton 0041fcf0, AuthoringSettings constructor/destructors 0040d140/0040a990/0040ab90, GlobalSettingsItem destructors 0040a6c0/0040a7c0, FactoryProduct destructor 0040a0e0, Creatable create 0040d410 and its shared_ptr constructor 0040c6b0. Probe total 25 exact bodies. addClasses 004202b0 parked at 711/713 (register allocation only) after a source-shape grid: the condition computed into a bool local, catch (std::exception&) from FuncInfo 008d3f88, for_each/boost::lambda for the derived loop and the 3-argument InsertItem each closed part of the gap. GlobalSettingsItem constructor 0040ccc0 needs const char* const template parameters in shared reflection templates (literal "Authoring" folded).
- Inactive native CUploadPlaceDialog (fork, Claude): CSaveToRobloxDialog subclass with no own members (constructor 0044f5c0 stores only vtables 0081757c/00817550; deleting destructor 0044f5a0 forwards to ~CSaveToRobloxDialog). Both bodies exact under the CString PCXSTR noinline profile with targets verified (applicationBaseUrl 004060d0, "/Game/Upload.aspx" 00817738, CString operator+ 0040e160, base constructor 0045fe80, imports by ordinal); original vtables equal CPublishAsPlaceDialog's. New files only; receipt shared-layouts/upload-place-dialog-working.json.
- Inactive native CSettingsDialog (fork, Claude): layout 0x3d4 from CRuntimeClass 0081bd90 and CreateObject operator new(0x3d4), constructor 00466e10 and destructor 00466ca0 (CXTSplitterWnd +0x74, CSettingsExplorer* +0x18c, CSettingsPropGrid +0x190 = CSelectionPropGrid with its own vtables). 9 bodies exact with targets verified: constructor, destructor, deleting destructor, GetRuntimeClass, _GetBaseClass (shared 0041f9b0), GetMessageMap, CreateObject, the reset-settings BN_CLICKED 1002 handler and OnInitDialog (442 bytes). Open: CInstanceExplorer::setRoot 00421a50 and the CInstanceExplorer layout; CSettingsExplorer runtime functions. Probe tests/record_native_settings_dialog.py (shared helper tests/native_bind.py); receipt shared-layouts/settings-dialog-working.json.
- Inactive native CRenderSettings (fork, Claude): GlobalSettingsItem<CRenderSettings> with layout 0x17c from Creatable create 00408ed0 (malloc 0x17c), constructor 00448c60 and destructor 00448e60: graphics/bevel/antialiasing/shadow/frame-rate-manager enums +0x130..+0x140, shading quality and mesh detail floats +0x144..+0x150, delaySwapBuffer +0x154, profileName +0x158, fullscreen/window Vector2int16 +0x174/+0x178; class statics aaSamples 00930668, aggregateSize 00942df8. 113 bodies exact under document-swap + /fp:fast with targets verified (constructor, destructors and thunks, every getter/setter, singleton, factory, property descriptor initializers and GetSet bodies). 00448e60/00448eb0 match as raw ranges (bounds: the analysis has one 111-byte row). Open: literal-folding GlobalSettingsItem/classDescriptor (const char* const template parameter), 2008 EnumPropDescriptor/EnumDesc layouts, boost shared_count tail. Shared Instance.h gains the nonvirtual raisePropertyChanged declaration (0040db00). Receipt shared-layouts/render-settings-working.json.
- Inactive native CRobloxControlColorSelector (fork, Claude): XTP CXTPControl subclass (BrickColor palette), size 0x184 from IMPLEMENT_SERIAL CRuntimeClass 00931c34 and CreateObject operator new(0x184); members +0x174 selected, +0x178 pressed, +0x17c color-picked flag, +0x180 COLORREF; static colors vector 0096dd24 of CColorInfo (12 bytes). 40 rows exact with targets verified (constructor, deleting destructors, runtime class, Draw 585 bytes, HitTest, OnClick, OnExecute, SetColor, addColor, CColorInfo vector instantiations, static initializers); both vtables (82/23 slots) verified slot by slot, inherited slots against compiled XTP 11.2.2 bodies. std::_Uninit_fill_n 0044e5d0 matches as 104-byte prefix plus the catch block at 0044e638 (bounds split). Receipt shared-layouts/roblox-control-color-selector-working.json.
- Inactive native CPatchedControlComboBox (fork, Claude): CXTPControlComboBox subclass with no own members (size 0x1e0 from IMPLEMENT_SERIAL CRuntimeClass 0092ecc8 and CreateObject operator new; deleting destructor forwards to ~CXTPControlComboBox). 7 of 7 own bodies exact with targets verified (runtime class, Compare, CreateObject, Clone, deleting destructor and thunk); vtables 00810914 (96) and 008108b4 (23) verified slot by slot against CXTPControlComboBox's and compiled XTP bodies. Receipt shared-layouts/patched-control-combo-box-working.json.
- Inactive native CScriptEditor (fork, Claude): Scintilla::CScintillaView subclass, size 0x160 (CRuntimeClass 0081b208, CreateObject operator new 0x160), Listener/MarshaledListener bases at +0xec/+0xf0/+0x114, members from constructor 00465010 and destructor 00465830 (DataModel mutex, frame, script, runService, flags, CFont). 51 bodies exact with targets verified under the PCXSTR/c_str/size noinline profile: lifecycle and thunks, runtime class, message map, setScript (659), OnInitialUpdate (1324), saveScript, notifications, bookmark/margin/fold command and UI-update handlers, MarshaledListener constructors/destructors. reload 00465550 matches as a raw 668-byte range (bounds). Shared DataModel.h gains getMutex declarations (00464710/00464750) and Instance.h desc_Name (00973d54). Open: PropertyChanged inline-copy templates. Receipt shared-layouts/script-editor-working.json.
- Inactive native CWebToolbox (fork, Claude): CSecureHtmlView/CHtmlView subclass, size 0x100 (CRuntimeClass 0081c4a8, CreateObject operator new 0x100), members +0xf8 CWnd* (read only) and +0xfc CComPtr<IDispatch> external; declaration-only CSecureHtmlView.h (0xf8, flag +0xf4). 14 bodies exact with targets verified under the PCXSTR noinline profile: CreateObject, deleting destructor, runtime class, message map, OnInitialUpdate (/IDE/ClientToolbox.aspx), OnActivateView, OnGetExternal, OnGetHostInfo, window-activate overrides and the five message handlers. Receipt shared-layouts/web-toolbox-working.json.
- Inactive native CSecureHtmlView (fork, Claude): CHtmlView subclass (0xf8, bool +0xf4), base of CWebToolbox and the browser views. 7 bodies exact (GetRuntimeClass/GetThisClass folded, constructor, destructors, PreCreateWindow, OnAmbientProperty with DLCTL 0x1730, OnBeforeNavigate2 using checkDialogUrl 0041dcb0 and the URL helper 00465b50) with targets verified. Open: URL helper 00465b50. Receipt shared-layouts/secure-html-view-working.json.
- Inactive native CBrowserView with CIDEBrowserView/CPlayBrowserView (fork, Claude): CXTPCommandBarsSiteBase<CSecureHtmlView> subclass, size 0x2d0 (CRuntimeClass 0080cf58 and CreateObject), members from constructor 004108b0 and destructor 00410950 (command bars, history list<string>, address combo, CXTPToolBar, external CComPtr, back/forward flags, home URL). 47 addresses exact (49 symbol checks) under document-swap + XTP with PCXSTR/IsEmpty noinline: lifecycle for all three classes, XTP site template, navigation overrides, toolbar/command handlers, message map; 14 of 19 XTP call targets body-proven against compiled XTP 11.2.2. Declarations: CBrowserDoc (: CNullDoc), CBrowserFrameWnd, CBrowserViewExternal. Open: OnGetExternal 0040fff0 (2-instruction scheduling), DeleteItem/_Buynode bounds. Receipt shared-layouts/browser-view-working.json.
- Inactive native CClassTreeView (fork, Claude): object-browser class pane, CReflectionTreeView (novtable, no data) : CXTTreeView, size 0xb0 (CRuntimeClass 00812504, CreateObject new 0xb0), members CImageList +0xa0, CMemberTreeView* +0xa8, CDeclarationView* +0xac. 31 rows exact with targets verified (lifecycle and thunk, runtime class, message map, OnCreate, image-list helper, OnSelChanged, OnInitialUpdate, addClass, addEnum, rank, compareItems, CReflectionTreeView::setItemStyle, Reflection sync static, for_each instantiation, XTTreeViewBase header inlines); vtables 104/104 and 30/33 slots verified. Noinline profile: PCXSTR, c_str, EnumDescriptor enumsBegin/enumsEnd. Receipt shared-layouts/class-tree-view-working.json.
- Inactive native CMemberTreeView (fork, Claude): object-browser member pane, CReflectionTreeView : CXTTreeView, size 0xb4 (CRuntimeClass 0081253c, CreateObject new 0xb4): CImageList +0xa0, showInherited +0xa8, current descriptor +0xac, CDeclarationView* +0xb0. 34 rows exact with targets verified (lifecycle and thunk, runtime class, message map, OnCreate, OnSelChanged, showClass 483, showEnum, addSignal, addEnumItem, argument formatting and for_each instantiations); vtables 104/104 and 30/33. setItemStyle now takes the Metadata::Item base (same bytes; CClassTreeView re-verified); Metadata.h gains Member and the three member lookups (00443ab0/b00/b50). Open: addProperty/addFunction need inline isPublic/getSignature in a native copy of the donor reflection headers (sign-off). Receipt shared-layouts/member-tree-view-working.json.
- Inactive native CDeclarationView (fork, Claude): object-browser declaration pane, CHtmlView subclass, size 0x114 (CRuntimeClass 008124e8, CreateObject new 0x114) with eight CComQIPtr members +0xf4..+0x110 (document and the Declaration/OwnerDiv/Owner/SummaryDiv/Summary/DeprecatedElement/PreliminaryElement elements, named from the item() strings). 12 bodies exact plus 2 dependency COMDATs, targets verified (lifecycle, runtime class, empty message map, OnInitialUpdate, OnDocumentComplete 2074, setContent 1092, argument formatting); all 140 vtable slots verified. Open: showDescriptor 00435860 (inline getSignature, same blocker as CMemberTreeView::addFunction). Receipt shared-layouts/declaration-view-working.json.

# P4: user-provided 2008 place and Humanoid crash

Code revision `3cd3585b2d`; evidence is under `work/2008-06/`. The supplied
2008E Bread Factory Tycoon is an external user input and is not redistributed.
Its decompressed XML hash is recorded in `p4-bread-runtime-3cd3585b2d/receipt.json`.

## Humanoid failure and correction

Before the fix, the whole place crashed during `--load-only`. One nested Home
model reproduced the failure with either Humanoid; removing both Humanoids made
the model load. Removing Scripts, value objects, or Humanoid health properties
did not fix it. Those controls were diagnostic only: the actual fix retains the
Humanoids.

The reentrant hardware-breakpoint observer showed the Humanoid constructor,
factory and object conversion return; `Instance::read` reaches `readProperties`.
At the call at 0044306d on the old executable, the Humanoid's virtual slot 11
selected 00550210, a bare `ret`, instead of Instance::readProperty (which takes
two stack arguments). Each property leaked eight stack bytes until execution
jumped into the stack. The old link map attributed the Humanoid GuidItem vtable
to `verified_0003.obj`, dragged into the image with the verified Humanoid
destructor. That vtable has an extra `onGuidChanged` slot relative to the
application's current Instance overlay. This is an ABI mismatch in the linked
combination; it does not invalidate the server's byte match for the isolated
destructor.

`rbxgs-app.json` now records a `verified_exclude` for that destructor and
`roc/rebuild.py` applies module-specified exclusions in addition to the existing
build-cache exclusion list. The link selects the Humanoid object's compatible
vtable and slot 11 points to Instance::readProperty. No target executable bytes
are patched. The native destructor and owning class layout still require proper
integration; this is tracked work, not an exact-reconstruction claim.

The forced-link build initially kept 118 verified swaps after the explicit
exclusion. Its resolver then returned seven more swaps to their ordinary providers
because `KernelIndex::~KernelIndex` and `Instance::onGuidChanged` helpers were
unresolved; the final forced-link result kept 111. The local object-function
unique-match count moved from 3323 to 3318. Neither number is an independently
verified server credit. P9 must account for these providers and restore native
integration without reintroducing incompatible vtables.

The authored `humanoid-load.rbxl` passes with exactly one retained Humanoid and
clean shutdown. The user place loads and retains 68 Humanoids, matching its XML;
it also completes two rendered frames and zero geometry cleanup counters. The
new `--load-only` path and `CountHumanoids` inspect actual DataModel descendants.
They do not establish character control, animation, or original-client parity.

## Reflection asset and remaining geometry

Once Humanoid loading worked, a reflective Part exposed an uncaught Ogre error:
the harness passed an empty spherical-reflection filename. Original renderer
007ab0a0 references `skyspheremap.jpg` at 00874a44 (operand 007ac3b3). The
period Content tree supplies `sky/skyspheremap.jpg`; normal launches now use that
path unless `ROC_SKY_SPHERE` is explicitly set. `stage_demo_content.py` stages
the external file with the same preserve-differing check as other assets; the
image is not committed. The authored reflective-sphere fixture loads the
`skysphmap` texture and renders 10757 foreground pixels on this revision.

The full place reports 792 scene models: 480 rendered and 312 return status 3
for unsupported geometry. The harness camera does not frame the whole map. XML
inspection found 300 Part size records with a dimension >=30 and four shape-2
Parts; these totals are not a one-to-one classification of the 312 omissions.
Original selector 004e5f80 uses a proven 30.0 threshold at 00874d88. In the
non-mega branch, target dispatch 004ef930 calls 004edb20 for shape 1 and 004eef30
for shape 2; their factory paths allocate 0x8c and call constructors 004f4cb0
and 004fd6b0 respectively. Existing resolved source files and disassembly are
saved, but their mined class names/layouts remain provisional. Next trace and
integrate the actual large-block producer, then cylinder, with original-client
comparisons and resource lifecycle checks. Do not claim the map fully rendered.

Normal P4 asset, reflection and Humanoid tests, mixed P3 lifetime/selftest/cache
regressions and eight rebuild-tool tests pass. P4 native SoundService playback,
remaining geometry, camera, full real-place fidelity and P5-P10 remain open.

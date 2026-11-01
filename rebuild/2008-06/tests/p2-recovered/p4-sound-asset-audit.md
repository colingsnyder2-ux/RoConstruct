# P4 Sound asset prerequisite

This is the native memory-loader prerequisite, not completed player audio.
`p4-sound-asset` compiles `PlayerNativeSound.cpp` against genuine donor Sound and
SDK declarations. No padded mining declarations are integrated.

## Native identity

Original FMOD import thunk xrefs are retained in `p4-fmod-import-calls.json`.
They establish these call stages, independently of unreliable mined unit labels:

| Target | Evidence |
| --- | --- |
| 005ba060 | FMOD_System_Create and System::init calls |
| 005bc6f0 | System::createSound, receiver handle+0/system+4/id+0xc/is3D+0x2c |
| 005bceb0 | System::playSound and Channel initialization |
| 005bc2c0 | System::update and listener attributes |
| 005ba410 | Sound destructor: release handle, clear it, destroy id string |

The measured small Sound has real fields fmod_sound, system, refCount, SoundId,
is3D. sizeof(Sound)=0x30, sizeof(SoundId)=0x20 compile assertions pass. Its genuine
constructor locally matches unique target 005b6f70 in the module's owned-symbols
report. This is local compiler evidence, not a new independent server credit.

The existing SDK is FMOD 4.08.08. Its actual FMOD_CREATESOUNDEXINFO declaration
has 27 real members, size 0x6c, exactly the size passed at native 005bc7a9/c5.
The diagnostic actually loads the target's shipped FMOD DLL, which reports
version 0x00041406. The SDK version is not presented as the target build's SDK.
The C System_Create export is undecorated in the DLL/generated import library;
an explicit linker alias retains the header's stdcall invocation. No wrapper
code or convention change is used.

## Integrated algorithm

`Sound::get()` retains lazy handle caching, ContentId byte loading,
OPENMEMORY (copying, not OPENMEMORY_POINT), is3D 0x10 flag, software/hardware
0x40/0x20 choice from GameSettings, zeroed 108-byte create-info, actual encoded
byte length, createSound error reporting/exception, and native handle return.
Detach/destruction releases and clears the handle. Constructor field initialization
comes from the existing recovered source and is independently locally matched.

Known adaptation: the donor exposes get() and a singleton ContentProvider.
June get(context) obtains its ContentProvider from the context instance. The
offline player already uses this singleton provider bridge for meshes; this unit
uses the same root/cache. Warning reporting omits the original user-setting gate.
These are explicit native integration gaps. SoundService/SoundChannel lifecycle,
callbacks, reflection and heartbeat are not supplied by this unit. The unrelated
declared Sound::release() remains unimplemented pending identity proof.

## Verified diagnostic

`P4SoundAssetTest` selects FMOD NOSOUND only in the test, and explicitly selects
software samples through GameSettings. It verifies:

- target DLL runtime version and actual loaded module path;
- 16 create/cache-hit/detach/reload/destruction cycles;
- all 5,512 decoded PCM16 samples against authored 440Hz source, within one
  quantization unit, mono/16bit/11,024 PCM bytes;
- provider cache release before PCM verification, exercising FMOD byte ownership;
- 2D and 3D mode flags;
- missing local asset returns null repeatedly;
- original class-name bindings Sound and SoundService.

`record_p4_sound.py` runs normally from a fresh output directory with build/visual
overrides removed and pins source, donor/SDK headers, fixture, EXE/map and DLL.
NOSOUND verifies decoded assets and ownership. Audible playback, native service
integration, original audio comparison and P4 completion remain open.

## Class-name correction

The glue previously called SoundChannel "SoundChannel". The original has no such
plain string. Native descriptor singleton 005bb860 pushes string "Sound" at
0094d310, while 005bb7f0 pushes "SoundService" at0094d2f4. Service constructor
005bc160 sets default instance name "Soundscape" at00837e90. Channel constructor
005bc480 sets "Sound". Original UI also shows Soundscape. The glue now uses the
proved class name "Sound" and retains service class "SoundService". This correction
does not by itself establish a working deserialization factory for either class.

Next: trace factory/constructor/property registration and recover real
SoundService/SoundChannel methods, using genuine members. Reject saved source
opaque padded declarations and wrong Script.cpp/Ogre donor resolutions. Then
load authored tone.wav through a serialized Sound and native playback/heartbeat,
capture actual audio, and compare with the original.

Additional ABI witness: VS2008 `/d1reportSingleClassLayoutSoundService` reports
donor SoundService size 560 (0x230), system at300/0x12c, mySoundDisabled at440,
and four embedded property descriptor objects at444/472/500/528. Original factory
00440a00 calls00440980, which allocates0x1c8/456 at0044099f and calls actual
constructor005bc160 at004409c4. Native system is0x134, mySoundDisabled0x1c0.
The donor embeds descriptors that cannot fit this original allocation; establish
their static/global ownership and correct declarations before integrating the
service. Even after removing those instance descriptors, its base/member prefix
still differs by8 bytes. Do not fill that difference with invented padding.
Witness files: `work/2008-06/p4-sound-layout/` and native factory disassemblies.

This raw-donor layout warning is superseded by the application overlay correction
in `work/2008-06/player-roadmap.md`: the canonical types have the measured sizes.
The genuine SoundService destructor body is empty; its compiler-generated member
and base destruction locally identifies target 005bb120 in the owned-symbols
report. A diagnostic that constructs the service still cannot link because
onEvent and onServiceProvider are missing. The temporary diagnostic was removed;
constructor, destructor and cache remain unexercised, and no server match is
claimed. Recover those two native callbacks and their actual dependencies next.

The 005ba2e0 cleanup algorithm now uses the genuine SoundId/shared_ptr map and
Sound members. It retains in-use entries and randomly detaches/erases unused
ones when the sample reaches the original 0.7 threshold. Its isolated FMOD
diagnostic compiles the same body with public test access because VS2008 encodes
private access in the symbol; it verifies seeded retention, eviction and reload
after detachment. This does not exercise the production private symbol or the
SoundService heartbeat. Native service linking and playback remain open.

The listener-vector helper 005b70c0 is integrated with genuine Math/Vector3
types. Original constants at 00837604 and 00826de0 are -5000 and +5000. The
diagnostic checks denormal-to-zero, component clamping, infinity rejection and
unchanged output after rejection. Heartbeat does not yet call this helper.

SoundChannel constructor 005bc480, destructor 005b7680, parent acceptance
00565ff0, provider detach 005b9840, heartbeat 005ba3d0 and spatial update
005b9920 are recovered against real declarations. The constructor/destructor
locally identify their original addresses. A temporary construction test did
not link: onAncestorChanged remains missing (askSetParent was subsequently
implemented). The channel object is therefore not selected or runtime-tested.
The spatial and detach error reporting uses the same documented warning-gate
adaptation as the asset loader. No audible playback or server credit is claimed.

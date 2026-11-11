# 2013 iOS / 2014 Android donor and C++03 backport check

Date: 2026-11-10. Scope: evidence only. No native source, header, or provider selection was changed.

## Answer

There is no safe "convert 2016 source to the June 2008 client" button. A converter can possibly remove a small set of C++11 spellings from an isolated, already-compatible function. It cannot make a 2013/2016 body a June-2008 Windows body: class layout, virtual-slot order, third-party APIs, CRT/STL ABI, platform code, and behaviour have all moved.

Use later sources as a **name / owner / algorithm clue**, then reconstruct the 2008 implementation against the 2008 EXE and compile it with VS2008.

## What was already tried

`mobile-donor-measurement/measurement.json` is a small 2026-11-06 pilot:

| Unit | result |
|---|---|
| RunService | 3 pre-existing 2008 bodies recompiled exact |
| Instance parenting | 2 pre-existing 2008 bodies recompiled exact |
| Workspace XML writer | 1 exact; other comparison was near/different |

It produced zero new source methods, exact bodies, ABI proofs, selected providers, or gated swaps. `MOBILE_REFERENCE_PILOT.md` also checked the Name family. That was identity evidence only, not a donor/body swap.

So mobile has **not** already received a broad App/Network/Rendering recovery pass.

## Fresh mobile evidence

### iOS 2013 (real source provenance)

The IPA is `2013-12_2.132.41333`; the ARM32 executable has named source/object records but no full Windows-compatible type/ABI data.

| Family | named mobile evidence | 2008 meaning |
|---|---|---|
| ContentProvider | `ContentProvider.cpp`, `ContentProvider::getFile` at `0x0081b2ac` | same broad operation: load, register, throw on failure; signature/cache differ |
| Network | `Client.cpp`, `ClientReplicator.cpp`, `ServerReplicator.cpp` | later client/server split; do not paste into monolithic 2008 network owners |
| PhysicsService | `PhysicsService.cpp`, lifecycle plus assembly on/off callbacks | useful name/control-flow cue; body is materially evolved |
| RunService | `App/util/RunStateOwner.cpp` | later ownership move, not a 2008 provider proof |
| Renderer/serializer | no matching queried iOS donor result for old Ogre bridge or SerializerV2 | no candidate body from this pass |

`ContentProvider::getFile` is the clearest continuity check. The iOS body uses `privateLoadContent(..., 2, -1.0)`, registers the file, then throws an error. The 2008 body uses `loadContent(ticket, 2, 0)`, its own cache route, registers, then throws a different CRT/STL expression. Same intent; not the same binary contract.

### Android 2014 (not 2013)

The available Android item is `2014-06_2.155.47886`, ARM ELF32, dynamic symbols only. It has useful demangled identity evidence:

* `RBX::ContentProvider::getFile(RBX::ContentId)` at `0x00f9d32d`
* `RBX::ContentProvider::loadContent`, `getContent`, and registration/service template symbols
* `RBX::RunService` creation, `Name::declare`, and ServiceProvider index symbols

This confirms service/registration vocabulary survived into Android. It does not supply debug source provenance, MSVC calling convention, x86 offsets, or an acceptable 2008 binary target. Android must not be mixed with iOS identity or used as Windows layout proof.

## 2008 C++ versus 2016 C++ -- the real gap

| Layer | VS2008 / C++03 era | 2016 source era | Why conversion fails |
|---|---|---|---|
| Language | no lambdas, `auto`, range-for, `nullptr`, `decltype`, rvalue refs, variadics, `enum class`, `noexcept` | C++11+ forms common | some syntax can be rewritten, but only locally |
| Standard library | old MSVC `std` implementation / CRT | newer STL facilities, move-aware containers, changed headers | replacement types can alter allocation, ownership, exceptions, and symbols |
| ABI | 32-bit MSVC 2008 object/RTTI/vtable/name-mangling contract | later compiler/library contracts; 2016 tree also has mobile/Unix builds | a compiling body can still call wrong method slots or access wrong fields |
| Dependencies | Boost 1.34.1 and RakNet 3.0 in the 2008 build | 2016 uses later dependency/platform generations (including RakNet 4.036) | headers, callbacks, templates, and link symbols are incompatible |
| Architecture | older monolithic subsystem boundaries | owners moved/split: e.g. network client/server, RunState owner | matching names do not imply matching declarations or behaviour |

The important split: **C++03 conversion solves spelling. Native recovery must also solve ABI, dependencies, and exact 2008 behaviour.**

## Open-source converter test

The credible open-source candidate is [cppbackport](https://github.com/sed-szeged/cppbackport), described in its [paper](https://arxiv.org/abs/2405.07204). It transforms selected C++11 constructs (notably `auto`, lambdas, range-for, and in-class initialization) into C++03 form. It requires a compilable Clang-based build database.

Local probe clone: `C:\Users\colin\RoConstruct\work\cppbackport-probe`. The checked README requires LLVM/Clang/clang-extra 3.6 plus source patches. The default command path lacks `clang`/`clang++`; a separately installed LLVM 23 exists but has incompatible APIs and no Clang development headers. More importantly, the tool claims language transformation only; it cannot translate old Roblox declarations, provider selection, Windows ABI, or dependency APIs.

Follow-up toolchain trial: official LLVM 3.6.2 Windows binary was extracted,
without system installation, under
`C:\Users\colin\RoConstruct\work\cppbackport-toolchain\installer-extract`.
Its `clang.exe --version` reports 3.6.2. Official LLVM 3.6.2, Clang 3.6.2 and
clang-tools-extra 3.6.2 source archives were also assembled with cppbackport in
the documented tree shape. All four required Clang patches reject that official
source release. A nearby official Clang 3.7.0 source trial rejects them too.
The patch headers name particular SVN working revisions, so cppbackport needs a
now-unpinned historical LLVM/Clang checkout, not a reproducible 3.6 release.
It is therefore not a runnable conversion path yet. Do not weaken/rebase those
compiler patches blindly: that would make the transform unverified.

Historical-source follow-up: the archived LLVM Clang mirror was queried by its
embedded SVN revision data. The documented `release_36` branch ends at SVN
`r240324`, before the patch's `r242392` context. A trunk snapshot at `r242404`
was fetched directly. On that source, three of four non-Sema patches apply
cleanly (`ASTMatchFinder`, `ignoremsasm`, and template-parameter printing).
`unknownattrib.patch` still fails because the generated attribute implementation
already changed. This patch is not optional: cppbackport directly references
`clang::UnknownAttr` to strip preserved unknown attributes. The next real build
trial therefore needs a source pin/rebase for this one compiler-internal patch,
plus matching LLVM and clang-tools-extra snapshots. This is a toolchain task;
it remains separate from all Roblox recovery files.

### Verified local syntax-converter smoke test

The historical toolchain follow-up is now runnable, but only as a **syntax
converter**. A separate, local-only Clang snapshot/tool workspace was assembled
at `C:\Users\colin\RoConstruct\work\cppbackport-toolchain`; no recovery
source or provider header was changed. `backport.exe --help` starts successfully
from `build-r242-cmake36h\bin\backport.exe`.

Smoke input:

```cpp
int total() {
    auto sum = 0;
    return sum;
}
```

Running `-no-db -in-place -multiple-transforms` accepted one transform and
produced `int sum = 0;`. `clang++ -std=c++03 -fsyntax-only` accepts transformed
output. This proves one mechanical C++11-to-C++03 path works locally.

It does **not** prove 2016 Roblox source portable to 2008. First run with a
standard-library include exposed old tool include handling; direct conversion of
real 2016 units still needs exact compile commands and old dependency headers.
Even successful transformed syntax still requires 2008 declarations, ABI,
provider, link, and EXE-behaviour proof.

Additional local probes established scope more precisely:

| C++11 construct | Result | C++03 syntax check |
|---|---|---|
| `auto` local | converted to concrete `int` | pass |
| range-for over builtin array | lowered to begin/end pointer loop | pass |
| non-capturing lambda + second auto pass | lowered to static functor function pointer | pass |
| in-class integer initializer | lowered to generated constructor initializer | pass |
| `decltype(value)` declaration | lowered to `int` | pass |
| trailing-return `auto f() -> int` | lowered to ordinary concrete return syntax | pass |
| rvalue-reference ctor/parameter plus explicit rvalue cast | lowered using generated `backport::rv<T>` shim | pass |
| `nullptr` | lowered to generated pointer/member-pointer conversion helper | pass |
| method `override` | lowered to `/* override */` by existing attribute pass | pass |
| class/method `final` | lowered to inert comment by existing attribute pass | pass |
| `static_assert(expr, message)` | lowered to a negative-array C++03 typedef | pass for true expressions |
| `constexpr` variable | lowered to `const` | pass for integral global/static/class cases |

The adapter initially crashed during dependency scan on Windows paths and
unresolved includes. In the local-only tool workspace, null include entries are
now ignored and source identity has a no-timestamp fallback. A
`compile_commands.json` probe with an external local header works when its
old-Clang command paths use forward slashes (`C:/...`): it transformed `auto`
in the include-using source and passed C++03 syntax checking. This does not
make current MSVC STL headers usable by the old Clang tool; real conversion
still needs a matching old compiler/dependency include configuration.

The first trailing-return limitation was repaired locally in the converter's
`ModifyFunctions` pass. It now handles non-template, defined functions with a
concrete trailing result type by replacing the leading `auto` plus `-> Type`
with the semantic result type. Smoke checks cover a free function, namespace
`static` function, and class member function; each output passed C++03 syntax.
Dependent template trailing returns remain on the tool's existing specialized
path and are not covered by this new concrete-function pass.

The converter also now lowers `nullptr` without the unsafe blanket `nullptr`
to `0` rewrite. It injects a C++03 `backport::nullptr_t` helper once per source
file, with pointer and member-pointer conversions, then rewrites literals to
`::backport::nullptr_value`. Pointer comparison, member-pointer return, and
boolean-context smoke cases all passed C++03 syntax checks.

Bare `noexcept` now lowers to C++03 `throw()`, using the converter AST's
`EST_BasicNoexcept` tag rather than a text-wide replacement. A free declaration,
free definition, and `const` member definition passed C++03 syntax checks; a
combined `nullptr` plus `noexcept` body also passes. `noexcept(expression)` is
intentionally unchanged (`EST_ComputedNoexcept`), since C++03 has no faithful
equivalent. `throw()` is only closest syntax/termination behavior, not proof of
2016 exception semantics or VS2008 runtime behavior.

The normal converter command now discovers both features itself: its feature
scanner routes a source containing `nullptr` or bare `noexcept` to the multiple
transform pass. A default-command smoke file containing both lowered both
constructs and passed C++03 syntax checking. This remains an isolated local
converter capability, not a bulk-source-port authorization.

The default command already handles method `override`: its existing attribute
pass changes it to an inert `/* override */` comment. A virtual base/derived
method smoke source passed C++03 syntax checking after that rewrite. This
removes only compile-time override checking; it cannot establish that a 2016
virtual layout or override target agrees with 2008.

That same attribute pass changes class and method `final` into inert comments.
A final class plus final virtual method passed C++03 syntax checking. It removes
only compile-time inheritance/override sealing; it is not a layout or vtable
compatibility guarantee.

The local converter now lowers each accepted `static_assert(expr, message)` to
`typedef char backport_static_assert_line_N[(expr) ? 1 : -1]`. Global and class
scope true-expression cases pass C++03 syntax checks. A false assertion is
rejected by the converter's C++11 front end before rewriting, as the original
source compiler would reject it; the replacement form likewise preserves the
compile-time failure. The C++11 diagnostic message is not retained in C++03.

`constexpr` variables now lower to `const`; global, namespace-static and class
static integral cases (including an array bound) passed C++03 syntax checking.
`constexpr` functions remain unsupported: C++03 cannot in general preserve
their compile-time evaluation role.

### Automated cross-era pilot

The first semantic pilot uses an already independently recovered method only as
a calibration case: 2016 `Network/Client.cpp::Client::clientIsPresent` delegates
to `findClient`; the 2008 source inlines the simple lookup. The local
`cppbackport-toolchain/tools/inline_simple_helper.py` reads the actual 2016
helper, substitutes its one local into its return expression, then substitutes
that expression at the 2016 caller. Its generated body is byte-equivalent after
whitespace normalization to the known 2008 `Client::clientIsPresent` body. This
is a narrow, automatic source-rewrite proof, not new recovery credit and does
not alter native source. The same generic one-local path also reduces 2016
`Server::serverIsPresent` and exactly matches its independent 2008 body.

The first non-recovered follow-up, `Client::OnReceive`, was rejected before
porting. The 2016 declaration takes only `Packet*`; 2008 target `004a1070`
takes `RakPeerInterface*, Packet*`. Its EXE starts with the old base call using
both arguments and dispatches packet bytes `0x0d..0x16`; later source packet
handling and peer ownership cannot be assumed compatible. No body was copied
or converted. This is the intended scale-up gate: apply automatic rewrites only
when target signature, called-provider ABI and observed packet/data protocol all
agree first.

The next non-recovered pair passed that gate narrowly. The tool reduced 2016
`Players::frontendProcessing` to
`findServiceProvider(context) && !serverIsPresent(context, testInDatamodel)`
and `backendProcessing` to the matching `!clientIsPresent` expression. A C++03
harness using only the required 2008-shaped declarations syntax-checks both
generated bodies. The original targets corroborate the shapes: `00495e80`
calls `findServiceProvider` then `Server::serverIsPresent`, while `00495eb0`
calls `findServiceProvider` then `Client::clientIsPresent`, returning false on
no provider or positive presence. These are generated candidate bodies only:
no native source was changed, and VS2008 object/relocation checks still precede
any integration.

The same no-local-return path generated `Players::clientIsPresent` forwarding
to `Client::clientIsPresent` and `Players::serverIsPresent` forwarding to
`Server::serverIsPresent`. Both join the C++03 harness. Their 2008 targets are
stronger than a shape-only match: `00495e60` is a tail jump to the old Client
presence method and `00495e70` a tail jump to the old Server presence method.
They remain unintegrated generated candidates pending the usual VS2008 object
and source-selection checks.

A third non-recovered candidate, `Players::findLocalCharacter`, uses the donor
body unchanged and only substitutes the independently observed 2008 declaration
signature (`const Instance*`). The generated C++03 harness passes. Target
`0049aca0` calls the old local-player lookup, tests null, then reads that
player's character at `+0x170`, matching the donor's null-guard then
`player->getCharacter()` flow. It too remains a candidate until a VS2008 object
and relocation check confirms the source/provider selection.

### Cross-era packet batches

The isolated converter workspace now has a read-only candidate ranker plus packet
writer. It joins 2016 definition shape with an exact 2008 header class/name/
parameter-count candidate, marks a textual 2008 definition as do-not-overwrite,
and records 2013 iOS symbol/source matches, 2008 header include/provider hints,
and required target gates. It emitted App batches of 50 and 34 candidates and a
Rendering batch of 50 candidates; small remainders are explicitly non-runnable.
These packets are triage inputs only. They do not claim a target address, ABI,
provider selection, library compatibility, an exact body, or a recovered method.
The separate Network pilot batch remains six independently constrained generated
bodies and its C++03 harness passes; this is not a VS2008 object proof.

### Helper-inline candidate: HopperBin::onLocalOtherClicked

`2016/App/v8datamodel/Hopper.cpp` is a one-call wrapper: `onLocalOtherClicked`
calls `disable()`. The 2013 iOS export identifies both (`onLocalOtherClicked`
at `0x00595c9c`, `disable` at `0x00594348`); its pseudo-C for `disable` has the
same active guard, SCRIPT_BIN signal, active clear, property notification and
Workspace default-command reset. Target 2008 `005d1370` has that exact control
flow over the independently declared 2008 offsets (`binType +0x1a0`, `active
+0x1a4`). The isolated `inline_void_helper.py` mechanically inlined the donor
helper into the target signature and its dedicated C++03 harness syntax-checks.
It is an unintegrated candidate only: target-header member/provider declarations
and a real VS2008 object/relocation comparison remain required before any swap.
The same guarded no-argument void-helper rule now runs through the batch engine;
the Hopper one-item proof batch regenerated the same body and its harness passed.

The batch ranker was tightened after validating `BallBallContact::getConnector`:
2016 and iOS both return the connector field and 2008 `0060cbc0` returns `+0x34`,
but that body already exists inline in `Contact2008.h`. Header-inline bodies now
join source bodies as do-not-overwrite rather than appearing as missing recovery.
After this correction, unresolved evidence packets are App 50 + 17, Rendering
48, and Network 12. Only the 50/48 groups meet the configured 20--200 batch size.

### Direct-body candidate: MultiJoint::getJointK

`2016/App/v8world/MutilJoint.cpp` returns `G3D::min(getPrimitive(0)->getJointK(),
getPrimitive(1)->getJointK())` with no post-C++03 feature. The named iOS 2013
body reads the two primitive computed JointK values then returns their minimum.
The 2008 target `00646af0` independently reads its two native primitive pointers,
forces each computed JointK at `+0xec`, and performs the floating minimum.
The target declaration is `float MultiJoint::getJointK()` in `Joints2008.h`.
The batch engine `extract_body` rule copied the body under that target signature;
its isolated C++03 harness passes. This is still not a source swap or VS2008
object proof; provider/header selection and relocation proof remain open.

`Primitive::getFirstContact` joined the same direct-body batch. The 2016 body
returns the first item in `contacts`; iOS 2013 tests its contact-array count
then returns the first pointer; 2008 `005e7bd0` likewise tests count at `+0x20`
and returns the first pointer from `+0x1c`. The independently declared target
signature is `Contact* Primitive::getFirstContact()`. Generated C++03 harness
passes; it remains unintegrated pending the same real compiler/relocation gates.

### Addressed direct-body batch screen

The batch generator now requires a C++03 donor body plus an addressed one-line
2008 declaration and emits a target-signature candidate file only. Across the
Network/App/Rendering queues it produced 15 candidates and rejected 112 for
missing/complex declarations or source extraction. The 15 are below the minimum
20-function integration batch, and are explicitly marked `needs_compile_and_exe_proof`.
Only `MultiJoint::getJointK` and `Primitive::getFirstContact` have dedicated
C++03 harness passes; no generated file was copied into native sources.

`Primitive::setDragging` was removed from that candidate set after the
tri-era target screen. Both 2016 and named iOS 2013 call `setFixed` directly;
the 2008 target `005e8050` recomputes its three fixed-state flags and conditionally
calls either PhysicsService notification target. Same method name/signature is
not enough: this is behavioral drift, not a C++11-to-C++03 conversion task.

### Scalable target-complexity screen

`work/cppbackport-toolchain/tools/screen_addressed_batch.py` now obtains all
target body sizes in one grouped `native-asm` invocation and writes a review-only
JSON queue. Its first 14 generated candidates yielded three small manual-review
targets: HopperBin (87 bytes), MultiJoint (102), and Primitive::getFirstContact
(15). The other 11 are 187--1452-byte deferred targets. This is a batch-priority
filter only, never behavioral, ABI, provider, or code-match proof. It scales to
the 20--200 generated-candidate batches before any native-file change.

### Native Hopper proof: HopperBin::onLocalOtherClicked

The screen found an existing native owner (`native-classes/Hopper.cpp`) with
the addressed method declared but missing. Donor shape required one 2008 API
translation: 2016's `deselectedSignal()` is old `desc_Deselected.fire(this)`;
the later `raisePropertyChanged(desc_Active)` has no 2008 target instruction
and was excluded. The resulting 2008 body has the target's signal path, active
clear, `ServiceProvider::find<Workspace>`, and tail call to
`Workspace::setDefaultMouseCommand`. It compiles under pinned VS2008 RTM and is
byte-exact to target `005d1370` (87 bytes). COFF relocation symbols independently
name the signal lookup/invocation, `ServiceProvider::find<Workspace>`, and
`Workspace::setDefaultMouseCommand`; their original target addresses are
`0056b620`, `004b5950`, `00491e50`, and `005a2730`. This is an inactive native
source recovery only; linked-provider selection and runtime gates remain open.

`MultiJoint::getJointK` was the next small tri-era body, but remains inactive.
Its native owner uses donor `v8world/IPipelined.h`; including the complete native
`Primitive2008.h` needed for `Primitive::getJointK` introduces a duplicate
`IPipelined` provider (`IPipelined2008.h`) and fails VS2008. The source edit was
reverted. This is a provider-conflict hotspot for an isolated header-overlay
experiment, not a safe batch conversion.

`Primitive::getFirstContact` did integrate into its existing part-embedded
native owner. The 2016 `contacts.getFirst()` API does not exist in its 2008
`EdgeList`; target assembly proves the old representation as count then first
`edges` pointer, so converter lowering uses `edges.size() > 0 ? edges[0] : NULL`.
Pinned VS2008 emits an exact 15-byte body at `005e7bd0`, with no COFF relocations.
It is inactive native recovery; selection/link/runtime gates remain open.

The same target-owned lowering now recovered the adjacent leaf methods
`Primitive::getFirstJoint() const` and `Primitive::getFirstEdge() const`. 2016
uses `joints.getFirst()` / `joints.getEdge(0)` and `contacts.getFirst()`; the
2008 header exposes the older `EdgeList::edges` representation instead. Target
`005e7b90` tests `joints` count at `+0x3c` then returns its first `+0x38` edge;
target `005e7b00` performs that test then falls back to contacts count `+0x20`
and first edge `+0x1c`. The 2008 lowerings use those existing containers directly.
One pinned VS2008 RTM compile checked all three Primitive leaves exact: 27 bytes
at `005e7b00`, 15 bytes at `005e7b90`, and 15 bytes at `005e7bd0` (run
`20261110-124942-d750d253`). The two new bodies assert zero direct calls; target
and COFF checks agree. All three remain inactive pending provider selection,
link, ABI, and runtime gates.

### Larger conversion proof: Player::onCharacterChangedFrontend

The first larger non-native-recovered candidate was `Player::onCharacterChangedFrontend`
at `004924e0` (217 bytes). The 2016 source retained the outer local-player and
Workspace/camera structure but moved later Humanoid setup and event connections
into this function. The 2008 EXE instead directly finds the old Humanoid subject,
sets the Camera subject/type/distance, zooms, then restores the default mouse
command. The mechanical converter candidate was therefore rejected as-is and
lowered against the 2008 declarations/target: native `Camera` and `Humanoid`
providers, `CUSTOM_CAMERA`, and the target's old `13.0f` distance.

The first VS2008 RTM compile was instruction-exact but exposed the one behavior
constant delta: donor-era `10.0f` produced data `00 00 20 41`; the EXE requires
`13.0f` (`00 00 50 41`). With that target-derived edit, run
`20261110-125611-755ec712` is byte- and referenced-data-exact for all 217 bytes.
Candidate COFF relocations name `Players::findLocalPlayer`,
`ServiceProvider::find<Workspace>`, `Humanoid::modelIsCharacter`, the three
Camera APIs (`setCameraType`, `setDistanceFromTarget`, `zoom`) plus
`setCameraSubject`, and `Workspace::setDefaultMouseCommand`; their target call
sites agree with `004924e0`. It is inactive native recovery only; selected
provider/link/ABI/runtime gates remain open.

### Parked near-exact: Player::doPeriodicIdleCheck

The neighboring `Player::doPeriodicIdleCheck` has both a 2016 descendant and a
bundled rbxgs-era body. The old body maps all target behavior: service-presence
guard, old `lastActivityTime`, 120-second idle check, local Player/client test,
`Idled` signal, and a 30-second `TimerService` reschedule. Target `00494650`
also proves that the donor `RBXASSERT` is not present in the 2008 binary, so it
was omitted.

VS2008 then reaches a 248-byte / 240-byte near match. The remaining eight-byte
gap is solely the compiler ordering around `event_Idled.fire`: the target converts
the double idle interval directly into the outgoing float slot, while the current
native signal provider spills then reloads the float. Three bounded source forms
(donor assertion, no assertion, explicit `SignalSource` / float conversion) did
not change that provider-template lowering. The semantic old body remains an
inactive candidate; exact recovery is parked pending a safe scoped reflection
signal-provider experiment. No claim of byte exactness for this method.

Other "backport" libraries found are not converters. For example, BackportCpp targets C++11 and later, so it cannot make VS2008/C++03 code.

### 20--200 batch automation: v8world old-source queue

The backport queue now also consumes C++03 rbxgs source, not only 2016 bodies.
It de-duplicates archived `roc_*` copies by owner/method/arity, skips existing
native/header bodies, regenerates the addressed target signature, and groups up
to 200 candidates. The first v8world pass produced 24 addressed, non-native
source candidates. A grouped target screen classified 10 unique small targets,
6 complex targets, and 8 address-owner collisions. Collision rows are held for
ICF/alias review automatically rather than selecting a random provider. This is
batch generation and a safety filter, not a bulk native-source write.

The first new small queue item, `Primitive::getNextContact` (`005e7be0`, 37 B),
was rejected before source edit. 2016/rbxgs use `prev->getNext(this)` returning
an Edge pointer. The 2008 target reads old per-side Edge fields as an index,
increments it, bounds-checks the native contact `edges` array, then returns the
array entry. The part-embedded Primitive header intentionally has no native Edge
field provider; importing the donor Edge would assert the wrong pointer ABI. It
is parked as an Edge-provider recovery, not converted with invented fields.

`Primitive::getCoordinateFrame() const` is a stronger tri-era body match:
rbxgs and 2016 both reduce to the old `body->getPV().position` access. The
recovered C++03 body compiles to the same 22-byte control flow at `005e82c0`
(including its direct `Body::updatePV` call), but returns `pv + 0x88`; the EXE
returns `pv + 0x94`. The target-owned `Body2008.h` independently documents
`PV pv` at `+0x94`, while this Primitive unit must presently include the donor
`v8kernel/Body.h`, whose older layout places it at `+0x88`. Both Body providers
define the same class and cannot coexist in this include profile. The semantic
native body is retained inactive; exactness is parked behind a scoped native
Body-provider/include-profile repair. No padding or raw-offset workaround was
added. Probe: `20261110-131248-ec14b9e4` (95%, 22 bytes).

`Primitive::onNewTouch` adds a second batch-proven old-source wrapper. The
rbxgs body calls the same namespace helper twice, reversing `p0` and `p1`.
Its VS2008 body is exact at `005e7530` (30 bytes; run
`20261110-131612-37b1a8d7`). Target calls at offsets 14 and 21 both reach
`005e74c0`; candidate COFF REL32 entries at offsets 13 and 20 both name
`?newTouch@RBX@@YAXPAVPrimitive@1@0@Z`. The helper's full 2008 provider,
selection, ABI, link, and runtime gates remain open, so this is inactive
native recovery rather than an enabled provider.

`Primitive::setController` is a third old-C++03 recovery in this batch. Its
null-to-`NullController` normalization and redundant-store guard are unchanged
from rbxgs. VS2008 is exact at `005e85e0` (34 bytes; run
`20261110-131730-6029ba88`); its only COFF REL32 names
`NullController::getStaticNullController` at call offset 11, matching the EXE
destination `00599e50`. It remains inactive pending selected-provider, link,
ABI, and runtime gates.

## Safe experiment boundary

Try a converter only when all are true:

1. One isolated `.cpp` function is already owned by a known 2008 header.
2. Its called APIs/types already exist in the selected 2008 providers.
3. The only deltas are mechanical C++11 syntax.
4. The result passes the smallest original VS2008 probe and exact EXE check.

Do not feed a whole 2016 module or headers to a converter. First practical queue: ContentProvider helper-sized functions, then service registration helpers. Reject Network/Rendering body ports until their 2008 declarations, dependency versions, and vtable/field evidence are individually proven.

## Next evidence work

1. Map iOS names to 2008 symbols and rank only exact declaration matches.
2. Use Android dynamic symbols as name/registration corroboration only.
3. For each candidate, compare 2008 assembly + provider headers before writing a C++03 body.
4. If a single candidate is syntax-only, build a pinned local converter setup in a separate tool workspace; never modify recovery sources in bulk.

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

Other "backport" libraries found are not converters. For example, BackportCpp targets C++11 and later, so it cannot make VS2008/C++03 code.

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

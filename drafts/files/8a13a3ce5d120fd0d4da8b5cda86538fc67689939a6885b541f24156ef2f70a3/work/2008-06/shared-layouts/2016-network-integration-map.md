# 2016 donor -> 2008 Network integration map

Status: donor vocabulary only.  2016 source is not ABI/layout/body authority for
2008-06.  Every 2008 row below is independently checked from the 2008-06 EXE;
candidate bodies still need VS2008 object, relocation and provider-selection proof.

Donor: `Artifaqt/ROBLOX2016`, `main` commit `e0cfac59fea3a5b986843e65b0fda286e439f9fc`
(GitHub tree/API read 2026-11-10).  Relevant donor targets: `Network`, `App`,
`AppDraw`, `GfxBase`, `GfxCore`, `GfxRender`, `RbxG3D`.

## Names which survive, but changed shape

| 2008 target | 2016 vocabulary | 2008 independent EXE proof | integration use |
| --- | --- | --- | --- |
| `RBX::Network::Client` | `Client`, `disconnect`, `clientIsPresent`, `onServiceProvider` | ctor `004a0990`: base ctor `0049ff10`, Client vtables `00822f4c..00822e88`, service name source `00938c88` | rank ownership of client lifecycle only; reject later ticket/cloud/session helpers |
| `RBX::Network::Server` | `Server`, `serverIsPresent`, `onServiceProvider`, replicator factory | ctor `004a4b30`: Server vtables `0082367c..008235c4`; fields initialized at `+144..+160`; container ctor at `+164` | rank server lifecycle/factory callers only; no 2016 security/protocol fields |
| `RBX::Network::IdSerializer` | Replicator dictionary/packet ownership | ctor `004b94a0`: `Instance` ctor `0055b7e0`; dictionary `+130`; map `+2b54`; vtables `0082534c..008252cc` | template/provider queue; current dictionary declaration is 2008-specific |
| `RBX::Network::Replicator` | `Replicator`, `ItemSender`, `ProcessPacketsJob`, item families | ctor `004b9bd0`: `PluginInterface +2b74`, sender `+2b80`, receiver `+2b84`, stats `+2b88`, packet collections after `+2b90`, peer `+2d50` | rank packet/job/item unnamed callees; do not import 2016 virtual list/layout |
| `NetworkSettings` | physics send/receive configuration | Replicator ctor reads `NetworkSettings +134/+138` to choose sender/receiver | preserve 2008 two-enum provider switch; reject expanded 2016 properties |

Cross-era semantic anchor: 2016 `Network/Client.cpp::Client::disconnect(int)`
removes children, closes `serverId`, then shuts down the peer.  2008 `0049f0f0`
does exactly that core sequence (`removeAllChildren` `0055afd0`, peer close slot
`+64`, shutdown slot `+28`); `0049f130` is same path with 3000 ms.  2016 adds
logging/unlock and a peer wrapper, so it is an owner/intent hint only, not a body
or declaration donor.

Second anchor: 2016 `Server::onServiceProvider` disconnects/reset Players on old
provider, delegates to `Super`, then creates/attaches Players and installs a
connection on new provider.  2008 `004a4100` follows same lifecycle core:
`Players::setConnection(NULL)`, peer shutdown/removal, base provider callback,
`create<Players>`, then `Players::setConnection`.  Its `ClientProxy` connection
and fields are 2008-specific.  This makes `NetworkClientServer2008Server.cpp`
the high-confidence owner cluster for provider lifecycle calls, not a 2016 body
donor.

`roc.cmd native-asm 2008-06 004a0990 004a4b30 004b94a0 004b9bd0` independently
shows these stores/calls.  On 2026-11-10, VS2008 RTM
`record_native_replicator.py` passed: 51 exact rows (32 distinct addresses), one
recorded non-exact row, 32 vtables and verified targets.  It proves bounded
`IdSerializer` base-chain explicit instantiations; it does not prove
`Replicator` ctor/dtor or full layout.

## Owner/call queues

1. `004b9bd0` construction graph -> `Replicator` item/job/packet helpers:
   `ItemSender`, `MarkerItem`, `ProcessPacketsJob`, `SendDataJob`, `StreamJob`.
   2016 confirms family names only.  Start with 2008 callers, RTTI and vtable slot
   evidence, then target-specific VS2008 objects.
2. Physics provider fork -> `PhysicsSender` / `RoundRobinPhysicsSender` /
   `DirectPhysicsReceiver` / `InterpolatingPhysicsReceiver`.  EXE allocations in
   `004b9bd0`: `0x74`, `0x18`, `0x08`, `0x3c`; this is stronger than donor naming.
   On 2026-11-10, VS2008 RTM `record_native_network_physics.py` passed six exact
   rows, two vtables and verified targets; four larger provider groups remain open.
3. Serialization/template queue -> `IdSerializer::WaitItem`, string dictionary,
   map/vector destructors.  Explicit-instantiation trial only for an EXE-observed
   symbol/address; `ReplicatorBases.cpp` already proves a bounded base-chain set.
4. Registration queue -> Network class descriptors, `sClient`, `sServer`,
   `sReplicator`, static signal/item registration.  Search static initializers and
   descriptor constructors before adding factory declarations.

## Provider-conflict / include rules

2016 target include graphs mix `App`, `Network`, `Rendering`, `G3D`, Boost,
RakNet and platform trees.  Highest collision names: `Client`, `Server`,
`Replicator`, `NetworkSettings`, `SceneManager`, `RenderSettings`, `Texture`.

* Include 2008 paths explicitly: `Network/Client2008.h`, `Network/Server2008.h`,
  `Network/Replicator2008.h`, `Network/IdSerializer.h`.
* No donor `Network/*.h` drop-in.  Their RakNet namespace, Boost/container sizes,
  reflected-property surface and virtual interfaces drifted.
* Keep `IdSerializer` explicit instantiations isolated.  Template owner/provider
  selection must be verified through COFF relocations, not link success.

## Rendering boundary

2016 has `GfxBase/GfxCore/GfxRender/RbxG3D/AppDraw`; 2008 owns Ogre/RbxGfx
classes (`OgreVisualEngine`, `OgreRbxSceneManager`, `RenderScene`,
`TextureProxyBase`).  Treat this as a subsystem move, not same-class proof.
Use it to rank visual-engine, scene, material, texture and view candidate queues;
reject D3D11/GL/new-graphics headers/bodies for 2008.

2008 binary/header anchors for safe owner ranking:

* `Ogre::RbxSceneManager`: `0x8c04`, 229 vtable slots at `0084ed34`, local
  `PrefabType` slot 228.  Its 2016 `GfxRender::SceneManager` names rendering
  responsibilities, but has unrelated `DeviceContext`/framebuffer API.
* `RBX::RenderBase::RenderSceneBase`: `0x268`, six slots at `00827424`; use
  2008 `RenderScene`/`RenderSceneNew` for bodies, never 2016 render-pass code.
* `RBX::TextureProxyBase`: `0x30`, eight slots at `0082d168`; 2008 G3D refcount
  ABI is provider authority.  2016 texture managers/GL/D3D types are vocabulary
  only.

Likely 2008 translation-unit clusters: `OgreRbxSceneManager.cpp` for Ogre fork
methods; `RenderSceneBase2008.cpp`, `RenderSceneNew2008.cpp` for render-scene
methods; `RenderMaterial*.cpp` and `TextureProxy*.cpp` for texture/material
methods.  Verify every candidate by original call/data relocations before moving
it between these units.

## Build/runtime probes suggested by donor target topology

* Static link probes: consumer object first, then immediate 2008 provider family;
  vary only one provider shard.  Record selected symbols, not merely successful
  resolution.
* Runtime gate categories: base/app unit, multiplayer/network, physics/perf,
  RCC/thumb render, test-hook integration.
* Platform split: 2016 has `_WIN32` and `RBX_PLATFORM_DURANGO` paths.  2008
  Windows probes must not inherit Durango/mobile branches.

## Network include / provider-risk map

The 2016 Network target is one object-library family: it explicitly includes App,
Rendering, TBB and VMProtect configuration, plus local `include`, RakNet and
`ClientShared` roots.  Its source list splits the old broad network surface into
peer/client/server, replicator item families, physics sender/receiver families,
packet/cache/filter, player/services and bundled RakNet.  Use this only to make
small 2008 link shards; it is not evidence that those later providers link to a
VS2008 target.

Highest fan-in headers from the 2016 core shape are `Replicator.h` (28 includes),
`Server.h` (13), `PhysicsSender.h` (13), `Peer.h` (12), and
`NetworkSettings.h` (4).  `Player.cpp` (68 includes) and `Players.cpp` (50) are
provider-conflict hotspots, crossing Network, V8DataModel, XML, Script, Util,
World, Gfx/AppDraw and RakNet.  Do not provider-swap those translation units.

Safe 2008-first shards are: `Client/Server/Peer/Replicator` lifecycle;
`PhysicsSender/PhysicsReceiver` packet handling; ContentProvider and XML helpers;
then Player/Players only after their individual old include providers are pinned.
Potential same-name collision groups: `Client`, `Server`, `Peer`, `Replicator`,
`Player(s)`, `NetworkSettings`, `ContentProvider`, `Workspace`, `Service`,
`Serializer`, `Texture` and `SceneManager`.  Include 2008 paths explicitly;
never rely on donor include-root ordering.

Current 2008 proof strength for this ordering: `IdSerializer/Replicator/Marker`
has 51 exact rows (32 distinct addresses) and 32 vtables; physics sender/receiver
has six exact rows and two vtables; `Network::Player` has 98 exact rows; and
`Network::Players` has 100 exact rows and 13 vtables.  The Players verifier now
cleans its generated pending-header overlay before compiling and recognizes the
already-promoted `Player::rebuildBackpack` declaration, preventing stale generated
headers from masking the real 2008 result.  All of these are VS2008/original-target
proofs, not claims of donor binary compatibility.

Owner-hint queue from the existing 2008 string/source map (ranked only for next
disassembly/target proof): `0049bf90` and `0049c7b0` -> `Network/Players.cpp`;
`004a0a70` -> `Network/Client.cpp`; `004b7250`, `004b6f00`, `004b7a30` and
`004b7f20` -> `Network/Replicator.cpp` / its ChangeProperty/Event item family;
`004b0800` -> Replicator NewInstance item family; `004c83b0` ->
`DirectPhysicsReceiver.cpp`; `004c9120` -> `PhysicsReceiver.cpp`.  This is a
string-vocabulary rank, not a symbol recovery: require matching 2008 calls,
RTTI/vtables, fields and VS2008 codegen before naming an unknown function.

Packet taxonomy is a hard donor-header reject.  2016 `PacketIds.h` begins its
custom sequence at RakNet `ID_USER_PACKET_ENUM` and defines later protocol,
schema, dictionary and security IDs.  2008 target dispatch instead proves
physics packet byte `0x50` in `Replicator` `004abc00`, and the Players receive
switch starts at `0x51`/`0x52` in `0049d770`; Client dispatch covers a separate
`0x0d..0x16` range and Server handles `0x10`.  Use 2016 packet names only to
rank likely network concerns.  Never copy its enum values, packet order or
protocol handshake into the 2008 build.

## App / rendering target-generation split

2016 `App` is a single object target spanning `v8tree`, `v8datamodel`,
`v8world`, `v8xml`, reflection, script, util and Lua; it also compiles selected
`ClientShared` sources.  That explains why a later App header can silently pull a
wrong provider into an old recovery build.  For 2008, retain translation-unit
clusters (tree/datamodel/world/XML/reflection) and link one old cluster at a
time; do not recreate the 2016 monolith.

2016 Rendering deliberately splits `g3d`, `AppDraw`, `RbxG3D`, `GfxBase`,
`GfxCore` and `GfxRender`.  This confirms a generation move away from the 2008
Ogre/RbxGfx boundary, so those later libraries are rejected as 2008 providers.

Platform seam: 2016 App selects `util/Win/FileSystem.cpp`, `MemoryStats.cpp`,
`ProgramMemoryChecker.cpp`, `MachineIdUploader_Windows.cpp` and `SleepingJob.cpp`
under `WIN32`; Android, Unix and Apple select different files (including ObjC on
Darwin).  A 2008 Windows recovery may use the old Windows seam only after
original imports/calls prove it.  Never trial Android/Apple/mobile donor paths
against the 2008 executable.

## Factory / static-registration evidence

2016 `factoryregistration.cpp` is a later central registry.  It retains strong
class vocabulary (`DataModel`, `Workspace`, `ServiceProvider`, `ContentProvider`,
`PhysicsService`, `RunService`, `JointsService`, `Lighting`, `Team(s)`,
`Player`, `Camera`, `Script`, `PartInstance`, joints, tools and value classes)
and `RBX_REGISTER_TYPE`/`RBX_REGISTER_CLASS` patterns.  Use it to rank static
initializer and `FactoryProduct` owner candidates only.  The 2008 provider uses
distributed `FactoryProduct`/`DescribedCreatable` template instantiations and
different RTTI/registration order, so the donor registration unit is rejected
as source/header authority.

A real 2008 provider collision was found and contained in the verifier: source
`PhysicsService.cpp` directly includes the native `engine-world/v8world/World.h`,
while `PhysicsService.h` asks for `v8world/World.h`; the generic include roots
otherwise resolved that second path to a donor World header and redefined
`World`, `AutoJoin`, `AutoDestroy`, `AssemblyPhysicsOn` and `AssemblyPhysicsOff`.
`record_native_services.py` now places a generated forwarding include ahead of
generic roots, so both routes resolve to the exact same 2008 header.  The
VS2008 proof passes: 145 distinct exact addresses (35 layout, 10 JointsService,
13 PhysicsService, 87 NetworkSettings), 12 vtables, two pending-only rows.

## Donor test taxonomy -> 2008 runtime gates

2016 test target names supply useful gate categories, not 2008 test bodies:
App unit tests cover ContentProvider, cluster replication/change-history,
network/security/RakNet, reflection, serialization/XML/WebSerializer, settings
and URL parsing; base tests cover scheduler, signals, crypto and containers;
RobloxTest splits physics quick/long/perf/distributed/multiplayer; RCC targets
cover server/client scenarios, authoring and thumbnails; RbxTestHooks is a
separate hook DLL.  Therefore gate recovered 2008 work by isolated unit/object
proof first, then network packet/replication, physics, serialization/reflection,
content/cache, Studio shell, and RCC/thumbnail only when matching old imports
and runnable target boundaries exist.  Do not run later test bodies as 2008
behavior proof.

## Dependency-generation hard reject

2008 uses Boost `1.34.1` and RakNet `3.0 09/07/07`; the donor Network tree
declares RakNet `4.036` (2012, protocol 5), and its CMake build is C++11/Unix or
Android-oriented with a different object-library aggregation.  This is direct
ABI/header conflict evidence.  Never use donor Boost/RakNet headers, container
internals, function wrappers, packet structs, link order or build flags for a
VS2008 recovery.  Confine 2016 use to vocabulary, broad owner clusters and test
categories; use the local 2008 dependency roots for every compile probe.

## Studio shell move

2016 `RobloxStudio/RobloxIDEDoc.cpp` retains high-level document vocabulary:
open/load/save, data-model initialization, view/action routing, toolbar/menu
mapping, content load/save, simulation, undo/redo and script/debugger work.  It
is a Qt `RobloxIDEDoc` shell, however, while 2008 owns MFC `CRobloxDoc`/
`CRobloxView`/document units.  Rank 2008 unnamed shell methods by these broad
responsibility groups, but reject Qt classes, UI actions and body text as donor
code.

The isolated 2008 document verifier passes its storage layout, 20 document
bodies, XML/StandardVerbs destructors and exact document destructor.  Receipt:
`shared-layouts/document-2016-studio-proof.json`.  This proves old MFC targets,
not a 2016 UI compatibility claim.

## Reflection / serialization boundary

2016 preserves useful vocabulary (`Descriptor`, `PropertyDescriptor`,
`FunctionDescriptor`, `EventDescriptor`, `ClassDescriptor`, XML serializers),
but its reflection ABI is materially later: descriptor attributes/lockdown,
security permissions, XML read/write flags, richer property functionality and
remote events are not 2008 declaration authority.

2008 evidence instead gives these owner queues:

* `00444dd0` is `RBX::Metadata::Reflection::load`: opens a file, constructs a
  `TextXmlParser`, reads XML through `MergeBinder`, then calls `Classes::addClass`
  for root/classes/member categories.  Candidate helpers belong to
  `MetadataReflectionLoad.cpp`, `MetadataClasses*`, `MetadataMemberLookup.cpp`,
  not generic 2016 reflection sources.
* `00445020` is the reflection singleton/lifecycle path.  It creates the
  reflection object once, derives a module-relative path and calls `load`.
  Treat static storage plus `_atexit` as registration/lifetime dependency, not a
  normal factory body.
* `00591a30` (`SerializerV2::newRootElement`) creates the XML root then calls
  `addAttribute` three times; `00591970` allocates `XmlNameValuePair` and calls
  its constructor at `0058c920`.  This ranks XML free/member utilities and
  `SerializerRoot.cpp` together.
* 2008 `PropertyDescriptor` has `LEGACY/UI/STREAMING/STANDARD` functionality
  and stream-write state.  Rank unnamed property bodies from these flags and
  `BoundProp`/`PropDescriptor` templates; reject donor security/XML-policy
  members until target RTTI/calls prove them.

Existing VS2008 verifier `record_native_serializer_root.py` covers the bounded
serializer root, XML attribute, value constructor and direct targets.  Its proof
does not authorize broader 2016 serializer or reflection imports.

Run result: the isolated VS2008 object exactly matches `SerializerV2::newRootElement`
at `00591a30`, XML attribute construction at `00591970`, and
`XmlNameValuePair` construction at `0058c920`; the root retains one target-proven
`Name::declare` call and three target-proven `addAttribute` calls.  Receipt:
`shared-layouts/serializer-root-2016-integration-proof.json`.

## ContentProvider continuity assessment

2016 retains `ContentProvider` vocabulary: `getContent`, `loadContent`,
`getFile`, `registerFile`, URL checks, cache and request queue.  It is useful for
owner ranking of the existing 2008 `ContentProvider*.cpp` cluster.  It is not a
direct recovery multiplier: 2008 has a `0x19c` provider with list/map/mutex and
`worker_thread`; 2016 uses `AsyncHttpCache`, threads, priorities and later
reflection/network APIs.  The 2008 `getContent`/`getFile` bodies must stay with
`NativeContentProvider.h` and their target proof.  Result: semantic boost only,
not enough to announce as a massive cross-chat recovery source.

One narrow continuity result is now target-proven: 2016 `isHttpUrl` and 2008
`ContentProvider::isUrl` both classify `http://`/`https://`; the 2008 VS2008
object matches target `0055bd10` exactly (54 bytes) with the two target strings
and the original `std::string::find` import.  This proves only the 2008 helper.

The existing 2008 probe queue also passes for the provider constructor/destructor
and layout, `getContent`, `loadContent`, local-cache path, hash-file and
asset-file lookup.  Prioritize this one 2008 cluster for recovery, but keep 2016
as owner/name evidence: these passes are from 2008 source plus original targets,
not donor code reuse.

`getFile`, `registerFile`, `findHashFile` and `findAsset` preserve the same
high-level sequence in 2016, which confirms their owner grouping.  The actual
shapes differ: 2008 `getFile` calls `loadContent(ticket, 2, 0)` on a pointer and
formats the failure through G3D; 2016 uses `blockingLoadContent` into a value,
later cache objects and RBX exceptions.  Do not transplant this body.  Current
2008 service-lookup/factory and `readContent`/catch/exception-metadata verifiers
pass, adding safe target proof to this queue.

No source/header change, swap activation or runnable-client claim in this receipt.

# Research Dossier for Claude (2026-11-26)

Read-only static audit of `work/native-client/mass-tools/snap/RobloxQT.exe` + `qt.map` + `clients/2008-06/Roblox.exe` + `codecollide.py`. Zero Claude-owned files touched, zero links run.

---

## 1. CRITICAL: 18 Corrupted `sClassName` Symbols (Not Just `sMotor`!)

`sMotor` was only the visible tip of the iceberg. Out of `229` `?s<Class>@...@@3(PADA|QBDB|PBDB)` symbols in `snap/qt.map`, **18 have mismatched array vs pointer ABIs** (`3QBDB`/`3PADA` = `char[]` ASCII bytes vs `3PBDB` = `const char*` 4-byte pointer):

### A. 14 `3QBDB` Arrays Holding 4-Byte Pointers (Garbage Class Names!)
Every one of these reads a 4-byte pointer address as ASCII text inside `Name::declare<sX>()`:
- `?sHat@RBX@@3QBDB` (`009b6b58`) -> `c4 b4 a1 00`
- `?sAutoJoint@RBX@@3QBDB` (`009bd108`) -> `ec a4 a1 00`
- `?sContentProvider@RBX@@3QBDB` (`009bd10c`) -> `00 e7 a1 00`
- `?sDataModel@RBX@@3QBDB` (`009bd110`) -> `60 0f a2 00`
- `?sFaceInstance@RBX@@3QBDB` (`009bd114`) -> `90 4a a2 00`
- `?sGlobalSettings@RBX@@3QBDB` (`009bd118`) -> `f0 c2 a1 00`
- `?sGlue@RBX@@3QBDB` (`009bd11c`) -> `8c 2f a2 00`
- `?sJointInstance@RBX@@3QBDB` (`009bd120`) -> `58 4a a2 00`
- `?sMotor@RBX@@3QBDB` (`009bd124`) -> `ac d7 a1 00` (`?sMotor@RBX@@3PADA` at `00f0bbfc` has real `"Motor\0"`)
- `?sPVInstance@RBX@@3QBDB` (`009bd128`) -> `a0 4a a2 00`
- `?sRotateV@RBX@@3QBDB` (`009bd12c`) -> `b0 79 a2 00`
- `?sRunService@RBX@@3QBDB` (`009bd130`) -> `fc 4b a2 00`
- `?sSelection@RBX@@3QBDB` (`009bd134`) -> `44 fb a1 00`
- `?sServiceProvider@RBX@@3QBDB` (`009bd138`) -> `10 e7 a1 00`

### B. 4 `3PBDB` Pointers Holding Raw ASCII Bytes (Crash on Dereference!)
Dereferencing these loads ASCII bytes as a pointer (e.g. `0x74736e49` = `"Inst"` -> instant AV):
- `?sInstance@RBX@@3PBDB` (`0099f7f8`) -> `ptr=0x74736e49` (`"Inst"`)
- `?sNetworkSettings@RBX@@3PBDB` (`0099fb98`) -> `ptr=0x7774654e` (`"Netw"`)
- `?sMarker@Network@RBX@@3PBDB` (`009a37a8`) -> `ptr=0x7774654e` (`"Netw"`)
- `?sDebugSettings@RBX@@3PBDB` (`009b0478`) -> `ptr=0x75626544` (`"Debu"`)

**Root cause & 1-rule fix:** `spellalias.py` / alias generation must **NEVER** alias `3QBDB`/`3PADA` (array) <-> `3PBDB` (pointer). Only alias `3QBDB` <-> `3PADA` (array-to-array); emit real `const char*` pointer globals for `3PBDB`.

---

## 2. CRITICAL: `240` `rgmain.dll` Non-`__imp_` Data/Vtable Thunks Breakdown

Full report: `work/native-client/mass-tools/dll_data_audit.json` (`240/240` in `rgmain:rgmain.dll`, `0` in MFC/CRT/FMOD):
- **`19` `const_data`**: `msDummyPlaneList`, `BLANK`, `Matrix4::IDENTITY`, `Quaternion::IDENTITY`, `Vector3::ZERO/UNIT_X/Y/Z`, `Math::PI/TWO_PI/HALF_PI/POS_INFINITY/fDeg2Rad/fRad2Deg`, etc. -> safe to copy from `rgmain.dll` at startup.
- **`150` `vtable_or_rtti`**: `??_7...@Ogre@@6B@` -> safe to copy from `rgmain.dll` at startup.
- **`71` `mutable_data`** split into:
  - **`15` safe const-like masks/strings**: `SceneManager::ENTITY_TYPE_MASK`, `FX_TYPE_MASK`, `LIGHT_TYPE_MASK`, `STATICGEOMETRY_TYPE_MASK`, `WORLD_GEOMETRY_TYPE_MASK`, `USER_TYPE_MASK_LIMIT`, `ResourceGroupManager::*_RESOURCE_GROUP_NAME`, `FACTORY_TYPE_NAME` (`BillboardChainFactory`/`BillboardSetFactory`/`EntityFactory`), `RENDER_QUEUE_INVOCATION_SHADOWS`, `AutoConstantDictionary` -> safe to copy at startup.
  - **`56` LIVE OGRE STATE** (WARNING: copying *before* `Ogre::Root` construction leaves local pointers `NULL` forever!):
    - **`20` `Ogre::Singleton<T>::ms_Singleton` pointers**: `Root`, `TextureManager`, `MeshManager`, `OverlayManager`, `LogManager`, `HardwareBufferManager`, `ResourceGroupManager`, `SceneManagerEnumerator`, `ShadowTextureManager`, `GpuProgramManager`, `HighLevelGpuProgramManager`, `ArchiveManager`, `ControllerManager`, `DynLibManager`, `FontManager`, `Profiler`, `ResourceBackgroundQueue`, `ExternalTextureSourceManager`, `DDSCodec::msInstance`, `Codec::ms_mapCodecs`.
    - Live containers: `Pass::msDirtyHashList`, `Pass::msPassGraveyard`, `Pass::msHashFunc`, `StringInterface::msDictionary`, `AnimableObject::msAnimableDictionary`, `Compiler2Pass::mBNFTokenState/mClientTokenStates`.
    - **Only 8 `ca_*` EXE objects reference these live singletons**: `ca_0046dfc0.obj`, `ca_0046e040.obj`, `ca_004dc480.obj`, `ca_00516a10.obj`, `ca_0055d330.obj`, `ca_005d6ac0.obj`, `ca_ca_0068e2b0.obj`, `ca_00693a90.obj`. Keep an eye on `ms_Singleton` NULL faults when rendering Parts/Overlays/Textures!

---

## 3. All `21` `stub_ret_audit.json` Mismatches Are 6-Byte Adjustor Thunks!

Every single entry in `work/native-client/mass-tools/stub_ret_audit.json` is an un-generated 6-byte `this`-adjustor thunk in `Roblox.exe`:
- **`thiscall` adjustors (`add/sub ecx, N; jmp target`)**:
  - `func_0048d0a0` (`4x`): `add ecx, 4; jmp 0x422c60`
  - `func_005897d0` (`2x`): `add ecx, 4; jmp 0x589720`
  - `func_00595780` (`1x`): `add ecx, 4; jmp 0x595700`
  - `func_00708260`, `func_00772960`, `func_00799560`, `func_0074ef10`, `func_0041bd10`, `func_0041bd00`, `func_0062bc60`, `func_005d0b20`, `func_005d0b30`, `func_005df860`, `func_005df850`, `func_0040bc10`
- **COM `stdcall` adjustors (`sub dword ptr [esp+4], N; jmp target`)** — these are the **#1 top vtable stub slots** (`CComContainedObject<CApp>`, `CComObject<CApp>`, `CBrowserViewExternal`, `CWorkspace`):
  - `func_00408000` (`-0x14 -> 0x40f6c0`), `func_00407ff0` (`-0xc -> 0x407f50`), `func_00402ad0` (`-8 -> 0x4029a0`), `func_00402a90` (`-8 -> 0x402960`), `func_00407e90` (`-0x14 -> 0x407e60`), `func_00407e80` (`-0xc -> 0x407e60`).

**Action:** Extending `deldtor_gen.py`'s adjustor pass to emit `sub [esp+4], N; jmp` COM adjustors + `func_00xxxxxx`-targeted `ecx` adjustors eliminates all `21` mismatches AND the top COM vtable stub slots in one pass.

---

## 4. Top Real Non-MFC Called Stubs for Milestones M2–M5

Filtered `stubcall_audit.json` (`461` called stubs, `1,515` vtable slots) to remove dead `CMFC*`/`CMenuImages` noise:
1. **`func_0066fc00` (`10x` from `AdornRbxGfx::box`)** = **`RBX::AdornRbxGfx::uniqueName()` -> RETURNS `std::string` BY VALUE (`sret`)!** Calling this `return 0` stub during Part selection/adorn rendering leaves a `std::string` uninitialized -> **guaranteed `0xC0000374` heap corruption!**
2. **`func_005e3870` (`8x` from `005e3b30`)** = **`JointInstance::JointInstance(Joint*)`** -> breaks creating any Joint (Weld/Snap/Glue/Rotate/Motor).
3. **`func_005e2760` (`WeldJoint` vtable slot 0)** = **`RigidJoint`/`WeldJoint` deleting dtor** (`mov [esi], 0x83e07c; call ~Joint 0x645490`).
4. **`RBX::Reflection::Tuple`** (`??1Tuple` `8x`, `??0Tuple(unsigned)` `5x`, `??0Tuple(const Tuple&)` `5x`) -> breaks `BoundFuncDesc::call<Tuple>` & `ProfilingItem::getTimes`.
5. **`func_004e7880` (`20x`)**, **`func_004e7810` (`4x`)**, **`func_005b87a0` (`5x`)**, **`func_004b6890` (`4x`)**, **`func_004b6ab0` (`3x`)**, **`func_00449460` (`3x` from `CRobloxModule::open`)**.
6. **View/Editor/Camera/Network**: `??_ECRobloxView` (`4x`), `??_ECScriptEditor` (`3x`), `ModelInstance::getCameraIgnorePrimitives` (`3x`), `StockSound` slot 1 (`func_005b7890`), `ClientProxy` slot 0 (`func_004a19a0`).
7. **2 `CStringT` `sret` stubs** (`stub_sret_audit.json`): `AFXGetRegPath` (`4x`), `CStringT`-returning member (`2x`).

---

## 5. `classsweep.py` Status (Ready to Re-Run!)

- `getCreators` (`0040c570` in `snap/RobloxQT.exe`) is now clean: uses its own dedicated guard `0x112aa58` and returns `std::map` at `0x112aa38`.
- `auto/classsweep.json` (`isnil=116`) was stale from **yesterday before the `flag@@3JA` & `creatorinit.py` fixes**!
- Re-running `classsweep.py` on the current exe should immediately walk all ~102 registered creators. (Once it works, extending it to also get/set properties + `clone()` + XML serialize gives full M2+M4 coverage in 1 run.)

---

## 6. `codecollide.py` Top Risk Map (`1,045` Colliding CODE Symbols, `7,746` Renames)

Highest-impact collisions waiting for A/B test behind a flag:
- `??$create@VPlayer@Network@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@...` — **`93` distinct orig `create<T>` functions** colliding!
- `??$?0PAVScript@RBX@@VDeleter@...@@shared_count` — **`140` distinct orig `shared_count<T*>` ctors** colliding!
- `FactoryProduct<Script>` ctor (`57` distinct) & `Described<Script>::classDescriptor` (`57` distinct).
- `Instance::classDescriptor` (`43` distinct), `RunService::classDescriptor` (`36` distinct), `rootDescriptor` (`20` distinct), `PropDescriptor::getset` (`38` distinct).
- Analog helpers: `initMoo` (`157`), `moo2` (`157`), `fn_a` (`94`), `_make_fn` (`94`), `Base::Base` (`81`).

---

## 7. Quick-Win Action Order for Next 2 Batched Links
1. **Fix all 18 `sClassName` array/pointer corruptions** (forbid `3QBDB`/`3PADA` <-> `3PBDB` aliasing).
2. **Cover `15` const-like Ogre `mutable_data` + watch `20` `ms_Singleton` pointers** in `rgmain.dll` batch.
3. **Add `sub [esp+4], N` COM adjustors + `func_00xxxxxx` `ecx` adjustors** to `deldtor_gen.py` (clears all `21` `stub_ret_audit` entries + top COM vtable slots).
4. **Recover `0066fc00` (`AdornRbxGfx::uniqueName` `sret` heap bomb!), `005e3870` (`JointInstance` ctor), `005e2760` (`WeldJoint` dtor), and `Reflection::Tuple` ctors/dtor**.
5. **Re-run `classsweep.py`**, wire `shard_libs.py`, and A/B test `codecollide.py`.

---

## 8. RBX Vtable RTTI Audit (`4,670` RBX Vtables — `dynamic_cast` Crash Map)

Checked `vtable[-1]` (CompleteObjectLocator) on all `4,670` RBX vtables in `snap/RobloxQT.exe`:
- **15 vtables have `NULL` RTTI locator** (`dynamic_cast` / `askSetParent` crashes!):
  - **4 still in `su_ni_ca_qt_base_stubs.obj` (ENTIRE VTABLE IS A STUB!)**:
    - `??_7LocalScript@RBX@@6B@` (`00d51560`) -> inserting/parenting `LocalScript` crashes!
    - `??_7?$DescribedCreatable@VBodyVelocity@RBX@@VBodyMover@2@$1?sBodyVelocity@2@3PADA@RBX@@6B@` (`00d4e560`)
    - `??_7ReplicatorStatsItem@Replicator@Network@RBX@@6B@` (`00d53560`)
    - `??_7?$sp_counted_impl_pd@PAVRenderStatsItem@CRobloxWnd@@...` (`00d4f560`)
  - **11 in `vt_orig_remap.obj` missing COL**: `HopperBin`, `Tool`, `BackpackItem`, `VerbWidget`, `ShirtGraphic`, `Skin` (`DescribedCreatable`/`FactoryProduct` intermediate vtables).
- **24 vtables in `vt_orig_remap.obj` have `STUB` (`dat_008a*`) RTTI locators**: `Backpack`, `BodyColors`, `Clothing`, `Pants`, `Shirt`, `StarterPackService`, `LocalBackpack`, `LocalBackpackItem`, `LegacyHopperService`.
- **`0` corrupt/out-of-range RTTI pointers** — all other `4,631` RBX vtables have valid RTTI!

---

## 9. M3–M5 Subsystem Readiness (`snap/qt.map` Real vs Stubbed)

| Subsystem | Real | Stubs | % Real | Key Remaining Blockers |
|---|---:|---:|---:|---|
| **Studio Tools** | 274 | 54 | **83.5%** | `MouseCommand::getName`, `ScriptMouseCommand::getCursorId`, `WorkspaceView::clearMouseCommand` |
| **Lua / Script** | 1,368 | 316 | **81.2%** | `LocalScript` vtable (`su_ni_ca_qt_base_stubs`), `Values`/`lua_State` `functor_manager` |
| **Sound / FMOD** | 432 | 105 | **80.4%** | `getClassIndex<SoundService>`, `SoundChannel::askSetParent`, `func_005b87a0` (`FMOD %d: %s`), `StockSound` dtor `005b7890` |
| **Humanoid / Char** | 784 | 210 | **78.9%** | `polymorphic_cast<Humanoid*>`, `Type::singleton<ControllerType>`, enum map dtors |
| **XML / Serializer** | 309 | 159 | **66.0%** | `IdSerializer::WaitItem` map/vector helpers, `TypedPropertyDescriptor<shared_ptr<vector<...>>>::readValue` |
| **Physics / World** | 455 | 325 | **58.3%** | Mostly `boost::bind` `World` stats callbacks (`addressof`/`init`), `WeldJoint` dtor `005e2760`, `JointInstance` ctor `005e3870` |
| **Network / RakNet** | 1,023 | 1,974 | **34.1%** | `Listener` / `IdSerializer` templates, `ClientProxy` slot 0 (`004a19a0`), `Replicator` property helpers (`004b6890`/`004b6ab0`) |

---

## 10. Decoded Identities of Top Unnamed Called Stubs

- `func_004e7880` (`20x`) & `func_004e7810` (`4x`): G3D `alignedMalloc` + `memset` container allocation helpers.
- `func_0066fc00` (`10x`): **`AdornRbxGfx::uniqueName()`** (`std::string` `sret` return -> `0xC0000374` heap bomb on Part adorn!).
- `func_005e3870` (`8x`): **`JointInstance::JointInstance(Joint*)`** (PartInstance::fromPrimitive + weak_ptr[2] ctor).
- `func_005b87a0` (`5x`): **FMOD error check/log** (`"FMOD %d: %s"` -> `StandardOut::print`).
- `func_004b6890` (`4x`) & `func_004b6ab0` (`3x`): Reflection `Property::setValue` / `Type::singleton` helpers (Replicator).
- `func_00449460` (`3x`): `CRobloxModule::open` (`AfxGetModuleState` + `EndWaitCursor`).
- `func_005b7890` (`StockSound` slot 1): `??_EStockSound@@WBDA@AEPAXI@Z` (deleting dtor adjustor).
- `func_005e2760` (`WeldJoint` slot 0): `RigidJoint`/`WeldJoint` scalar deleting dtor (`mov [esi], 0x83e07c; call ~Joint`).

---

## 11. `141` High-Impact Crash-On-Call Template Stubs (`critical_template_stubs.json`)

Full list in `work/native-client/mass-tools/critical_template_stubs.json`. Every one of these returns `0` (`NULL` reference/pointer/index `0`) when called:
1. **`ServiceProvider::getClassIndex<T>()` — `26` stubs (`0` instant aliases)**:
   - `ChangeHistoryService`, `Client`, `ControllerService`, `DebrisService`, `FlagStandService`, `GeometryService`, `IdManager`, `JointsService`, `Lighting`, `LocalBackpack`, `Players`, `SoundService`, `FilteredSelection<Instance>`, `FilteredSelection<PartInstance>`, `Stats::Item`, etc.
   - **Impact:** Returning `0` makes all of them collide on Service slot `0` in `ServiceProvider`! Fixable in 1 bulk generator (`template unsigned int RBX::ServiceProvider::getClassIndex<T>();`).
2. **`Reflection::Type::singleton<T>()` & `RefType::singleton<T>()` — `44` stubs**:
   - `PartInstance*`, `Instance*`, `ModelInstance*`, `Hole*`, `SoundId`, `AllEnumDescriptors*`, `EnumDescriptor*`, `EnumDescriptor::Item*`, `shared_ptr<SignalInstance>`, `shared_ptr<Lua::ThreadRef::Node>`, `const char*`.
   - **Impact:** Returns `NULL` `const Type&` -> crashes `RefPropDescriptor` (`Part0`/`Part1`/`CameraSubject`/`PrimaryPart`/`Parent`/`Target`), Lua enums, and Sound properties!
3. **`boost::polymorphic_cast<T, U>()` — `47` stubs**:
   - `TypedPropertyDescriptor<int/float/double/string/BrickColor/Color3/CoordinateFrame/Vector3/TextureId/SoundId/bool/shared_ptr<Instance>>*`, `Humanoid*`, `BodyPosition*`, etc.
   - **Impact:** Returns `NULL` instead of `dynamic_cast<T>(u)` -> crashes Property Grid & Lua property access! Fixable in 1 bulk generator (`template T boost::polymorphic_cast<T, U>(U*);`).
4. **`Named<Base, sName>::getName()` — `12` stubs**:
   - Humanoid states: `Flying`, `GettingUp`, `Running`, `Freefall`, `Jumping`, `FallingDown`, `Seated`, `MovingNoPhysicsBase`.
   - Studio tools: `BoxSelectCommand`, `ToolMouseCommand`, `DecalTool`.
   - **Impact:** Returns `NULL` `const Name&` -> crashes Humanoid state machine (Play Solo) and Studio tool selection!
5. **`StringConverter<T>::convertToString` (`sret` `std::string`!) — `12` stubs**:
   - `BrickColor`, `Color3`, `SoundId`, `TextureId`, `Vector2int16`, `boost::signals::connection`, `EnumDescriptor*`, `EnumDescriptor::Item*`, `AllEnumDescriptors*`, `shared_ptr<SignalInstance>`, `shared_ptr<Lua::ThreadRef::Node>` + `TextureId::convertToValue`.
   - **Impact:** Returns uninitialized `std::string` (`sret`!) -> `0xC0000374` heap corruption on Property Grid / XML string conversion!

---

## 12. `.CRT$XCU` & 41 Insertable Classes Health

- **`.CRT$XCU` in `snap/RobloxQT.exe`**: `975 / 975` non-null initializer slots are **REAL** (`0` stubbed XCU slots!).
- **41 Insertable Classes descriptor health**: **`37 / 41` have ZERO stubbed descriptors**. Only `4` have stubbed static descriptors:
  - `Humanoid`: `?propHealth`, `?propMaxHealth` (`2` stubbed / `18` real)
  - `SpawnLocation`: `?prop_SpawnForcefieldDuration` (`1` stubbed / `6` real)
  - `Skin`: `?prop_skinColor` (`1` stubbed / `2` real)
  - `Shirt`: `?prop_leftSleeveColor`, `?prop_rightSleeveColor`, `?prop_torsoColor` (donor 2007 props; 2008 uses `ShirtTemplate`/`Outfit2`).

---

## 13. `ServiceProvider::create<T>` / `find<T>` (`21` Stubs) & `Creatable::create<T>` (`4` Stubs)

- **21 stubbed `ServiceProvider::create<T>` / `find<T>`** (return `NULL` when called!):
  - `JointsService` (breaks welds/snaps/motors), `SpawnerService` (breaks `SpawnLocation`/Play Solo spawn), `ControllerService` (breaks Play Solo character input), `FlagStandService`, `GeometryService`, `IdManager`, `Lighting`, `RunService`, `StatsService`, `Teams`, `FilteredSelection<Instance>`, `Stats::Item`.
- **Only `4` stubbed `Creatable::create<T>` left in the entire binary**:
  - `IdManager`, `Replicator(SystemAddress, RakPeer*)`, `Server`, `WorkspaceStatsItem(Workspace*, World*)`.

---

## 14. Full Un-Truncated `sret` UDT Stub Scan (`full_sret_stubs.json`)

Scanning ALL `461` called stubs + ALL `1,515` vtable stub slots (resolving `func_00xxxxxx` via `identity-registry.json`) found **`12` `DANGER` by-value UDT (`sret`) stubs** (heap corruption on destructor exit):
- **RBX Reflection / FactoryProduct `sret` bombs** (in live vtables & direct calls):
  - `RefPropertyDescriptor::getStringValue` (`std::string` `sret` in `RefPropDescriptor` vtable!)
  - `TypedPropertyDescriptor<...>::getStringValue` (`2x` `std::string` `sret` in vtables!)
  - `FactoryProduct<...>::Creator::create` (`2x` `boost::shared_ptr<Object>` `sret` in `Creator` vtables!)
  - `StringConverter<...>::convertToString` (`2x` `std::string` `sret` direct calls!)
- **Non-RBX**: `AFXGetRegPath` (`4x` `CStringT`), `AFX_GLOBAL_DATA::RegisterWindowClass` (`2x` `CStringT`), `CMFCRibbonButton::GetToolTipText` (`1x`), `Ogre::GpuProgram::Cmd*::doGet` (`2x`).

---

## 15. Exact Original Vtable & COL Addresses for `LocalScript` & Missing-RTTI Vtables

From `clients/2008-06/Roblox.exe`:
- `??_7LocalScript@RBX@@6B@`: orig vtable `00831594`, COL `008981a4` (`dat_008981a4`) — currently in `su_ni_ca_qt_base_stubs.obj`!
- `??_7?$DescribedCreatable@VBodyVelocity@RBX@@VBodyMover@2@$1?sBodyVelocity@2@3PADA@RBX@@6B@`: orig `008476dc`, COL `008b8254` — currently in `su_ni_ca_qt_base_stubs.obj`!
- `??_7ReplicatorStatsItem@Replicator@Network@RBX@@6B@`: orig `00824fbc`, COL `0088de94` — currently in `su_ni_ca_qt_base_stubs.obj`!
- `vt_orig_remap.obj` missing-COL orig addresses: `HopperBin` `0083b4d0` (COL `008a5c28`), `Tool` `00841d20` (COL `008b1390`), `ShirtGraphic` `0083c5bc` (COL `008a789c`), `Skin` `0083c82c` (COL `008a7d54`), `Backpack` `0083b8bc` (COL `008a5f24`), `Clothing` `0083c68c` (COL `008a7978`), `Shirt` `00821f64` (COL `008886c8`), `Pants` `00821e94` (COL `008884bc`).

### Exact 6 RBX `sret` Heap-Corruption Bombs (will fire when selecting a Part in Property Grid!)
1. `?getStringValue@?$TypedPropertyDescriptor@W4FormFactor@PartInstance@RBX@@@Reflection@RBX@@UBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBVDescribedBase@23@@Z` (`2x` in vtables — `PartInstance::FormFactor`!)
2. `?convertToString@?$StringConverter@VBrickColor@RBX@@@RBX@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVBrickColor@2@@Z` (`PartInstance::BrickColor`!)
3. `?convertToString@?$StringConverter@VColor3@G3D@@@RBX@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVColor3@G3D@@@Z` (`PartInstance::Color`!)
4. `?getStringValue@RefPropertyDescriptor@Reflection@RBX@@MBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBVDescribedBase@23@@Z` (`RefPropDescriptor<AutoJoint, PartInstance>`!)
5. `?create@Creator@?$FactoryProduct@VDebugSettings@RBX@@VItem@GlobalSettings@2@$1?sDebugSettings@2@3PBDB@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ`
6. `?create@Creator@?$FactoryProduct@VServer@Network@RBX@@VPeer@23@$1?sServer@23@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@@boost@@XZ`

---

## 16. Lua M4 Blockers Caught Statically (`Bridge::className` + `lua_longjmp` RTTI!)

1. **`11` `Lua::Bridge<T>::className` static pointers are ZEROED (`NULL`) in `qt_stubs`** — calling `luaL_newmetatable` / `luaL_checkudata` in Lua will crash immediately on `Instance`, `Vector3`, `CFrame`, `Color3`, `BrickColor`, `RBXScriptSignal`, `Enum`, `Enums`, `EnumItem`:
   - `Bridge<G3D::Color3, true>::className = "Color3";`
   - `Bridge<G3D::Vector3, true>::className = "Vector3";`
   - `Bridge<G3D::CoordinateFrame, true>::className = "CFrame";`
   - `Bridge<BrickColor, true>::className = "BrickColor";`
   - `Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>::className = "Object";`
   - `Bridge<boost::shared_ptr<Reflection::SignalInstance>, false>::className = "RBXScriptSignal";`
   - `Bridge<boost::signals::connection, true>::className = "RBXScriptConnection";`
   - `Bridge<boost::shared_ptr<ThreadRef::Node>, false>::className = "shared_ptr<ThreadRef::Node>";`
   - `Bridge<const AllEnumDescriptors*, true>::className = "Enums";` / `EnumDescriptor*` = `"Enum"` / `Item*` = `"EnumItem"`.
2. **`??_R0PAUlua_longjmp@@@8` is the ONLY real C++ exception TypeDescriptor stubbed in the entire binary** (out of 6 total stubbed `??_R0`s)! Any Lua script error (`throw lua_longjmp*`) will fail `catch(lua_longjmp*)` and terminate the process until `??_R0PAUlua_longjmp@@@8` is emitted (3-line TU: `struct lua_longjmp; void _f() { try { throw (lua_longjmp*)0; } catch (lua_longjmp*) {} }`).
3. **`ServiceProvider::getClassIndex<ScriptContext>()`** is also stubbed (`0` collision) + `LuaArguments` (`ctor`/`dtor`/`get`) + `YieldingThreads::WaitingThread` ctor.

---

## 17. `136` Stubbed RBX Data Globals — 5 Major Runtime Hazards Caught Statically

1. **3 Vcall Thunks Placed in Non-Executable `.data` (`su_ni_ca_qt_base_stubs.obj` -> DEP/NX Crash!)**:
   - `??_9Instance@RBX@@$B7AE` (`00d59560`), `??_9Instance@RBX@@$BM@AE` (`00d5a560`), `??_9PartChunk@View@RBX@@$BCE@AE` (`00d5b560`).
2. **4 `MeshFactory` `std::map` Caches Colliding on ONE Zeroed Address `00f08560`**:
   - `decalCache` for `CylinderAlongXMesh`, `PBBMesh`, `SphereMesh` AND `textureCache` for `PBBMesh` all sit at `00f08560` (unconstructed `std::map` -> crash on Cylinder/Sphere/Decal render!), plus zeroed `BrickMesh::bevel`, `normalPerturbation`, `widthInset`, `RenderNew::shadeResourceGroup`, `emptyPartMaterial`.
3. **All `13` Humanoid Physics Constants Zeroed (`0.0f` -> Character Cannot Walk/Turn/Jump in M5!)**:
   - `Jumping`: `jumpVelocityGrid`, `kJumpP`.
   - `Running`: `kAltitudeD`, `kAltitudeP`, `kMoveP`, `kTurnAccelMax`, `kTurnP`, `autoTurnSpeed`, `manualTurnSpeed`, `maxMoveAccelerationGrid` (`Vector3`).
   - `Flying`: `kTurnAccelMax`, `kTurnP`, `turnSpeed`.
4. **Lua `game:GetService()` / `game:service()` & `11` Core `Reflection::Type` Singletons Zeroed**:
   - `?func_GetService@ServiceProvider@RBX@@` (`00de5560`) and `?func_service@ServiceProvider@RBX@@` (`00dea560`).
   - `11` `?type@?1???$singleton<int/float/double/string/shared_ptr<Instance>/BrickColor/Color3/ContentId/Vector2int16/Vector3/bool>@Type@Reflection@RBX@@` in `qt_stubs.obj` (`0100ae20..0100aec0`, only `0x10` bytes apart!).
5. **6 Joint Creators & Sound/XML Globals Zeroed**:
   - `FactoryProduct<Glue/Rotate/RotateP/RotateV/Snap/Weld, JointInstance>::creator` (`00dc5560..00dcb560`).
   - `SoundChannel`: `soundIdProperty`, `loopedProperty`, `playCountProperty`; `SoundService::prop_AmbientReverb`.
   - XML: `name_DeleteItem` (`00e26560`), `tag_binary` (`00e9a560`).

---

## 18. Clean Checks (Verified Zero Issues!)
- **MFC `_messageEntries` command handlers**: `290 / 290` handlers across all `24` message-map tables are REAL (`0` stubbed Studio menu/toolbar commands!).
- **Static-local guard/flag collisions in `rename.json`**: `0` remaining (all resolved!).
- **`.CRT$XCU` static initializers**: `975 / 975` non-null slots are REAL (`0` stubbed!).

---

## 19. Exact Humanoid Physics & BrickMesh Constants (Currently Zeroed in `qt_stubs`)

- `Flying::turnSpeed = 6.0f`, `Flying::kTurnP = 7500.0f`, `Flying::kTurnAccelMax = 120000.0f`
- `Jumping::kJumpP = 5000.0f`, `Jumping::jumpVelocityGrid = 50.0f`
- `Running::manualTurnSpeed = 4.0f`, `Running::autoTurnSpeed = 8.0f`, `Running::kTurnP = 7500.0f`, `Running::kTurnAccelMax = 160000.0f`, `Running::kMoveP = 1250.0f`, `Running::kAltitudeP = 10000.0f`, `Running::kAltitudeD = 1250.0f`
- `BrickMesh::normalPerturbation = 0.05f` (orig `00826e3c`), `BrickMesh::bevel = 0.0f` (orig `00826e38`), `BrickMesh::widthInset = 0.0f`

---

## 20. `51` Instant Verified Aliases Added to `aliases_gemini.txt` (`View<->ViewNew` + Access Specifier)

All `51` targets verified REAL (non-stub) in `snap/qt.map`, appended directly to `work/donorfree-route/aliases_gemini.txt`:
- **`43` `RBX::View::` <-> `RBX::ViewNew::` aliases**: `buildFace<0..5>`, `CylinderAlongXMesh`, `PBBMesh`, `TorsoMesh`, `WedgeMesh` ctors & deleting dtors, `LevelBuilder`, `MaterialFactory`, `Part`, `PartChunk` dtors, `BrickMesh::bevel`/`normalPerturbation`, `Table<RenderSurfaceTypes>`.
- **`8` `@@0/1/2` access-specifier-only aliases**:
  - **6 core `Lua::Bridge<T>::className`** (`DescribedBase`, `SignalInstance`, `BrickColor`, `Color3`, `CoordinateFrame`, `Vector3` -> `0040a420.obj`, `00415b90.obj`, `005a8830.obj`, `005a8850.obj` — fixes M4 Lua metatable `NULL` crashes!).
  - **`MeshFactory<PBBMesh>::decalCache` & `textureCache`** (`@@2` -> `@@0` in `004d7680.obj` — fixes the `00f08560` zeroed `std::map` collision!).

---

## 21. `+38` More Verified Aliases Added (`aliases_gemini.txt` Now `91` Lines, `0` Bad Targets)

- **`35` `struct`/`class` (`U` <-> `V`) exact-ABI aliases**: `shared_ptr<DescribedBase>`, `shared_ptr<Instance>`, `shared_ptr<Script>`, `list<ChatMessage>`, `SharedPtr<Ogre::Resource>`, `vector<Reflection::Value>`, `ReferenceCountedPointer<G3D::VARArea>`, etc.
- **`3` `RenderNew` <-> `Render` namespace aliases** (in addition to the `43` `View` <-> `ViewNew` aliases).
- All `91/91` targets in `work/donorfree-route/aliases_gemini.txt` verified REAL (non-stub) in `snap/qt.map`.

---

## 22. Delta Audit on New Link (`1795704978`)

### Massive Drops Confirmed
- **`dll_data_audit`**: `240 -> 50` (**`0` `const_data`, `0` `vtable_or_rtti`**; only `50` `mutable_data` Ogre thunks left!).
- **`stub_ret_audit`**: `21 -> 3` (`18` adjustors fixed; only `00772960`, `0072ea40`, `00799560` left).
- **`data_zero_audit`**: `16 -> 2` zeroed strings (`sVisit`, `sStockSound`, all 14 constants fixed!).
- **`sClassName` array+ptr VA collisions**: `8 -> 0` (all `sNetworkSettings`/`sDebugSettings`/`sGlobalSettings`/`sMotor` `3QBDB`/`3PADA`/`3PBDB` bytes are now valid!).
- **`vtable_stub_slots`**: `1,515 -> 1,266` (`-249`); **`total_stubs`**: `48,083 -> 47,342` (`-741`).

### New High-Priority Catches in `1795704978`
1. **`_lua_setlevel` (`30x` called — NEW #1 called stub!)**: Lua 5.1 `void lua_setlevel(lua_State *from, lua_State *to) { to->nCcalls = from->nCcalls; }` (2 instructions, needed for Lua coroutines/threads in M4).
2. **`3` Zeroed MFC `GetThisMessageMap` Globals (`su_ni_ca_qt_base_stubs.obj`)**:
   - `?messageMap@?1??GetThisMessageMap@CClassTreeView@@` (orig `00812ec8` — Explorer tree view!)
   - `?messageMap@?1??GetThisMessageMap@CRobloxReportView@@` (orig `008187b0`)
   - `?messageMap@?1??GetThisMessageMap@CWebToolbox@@` (orig `0081c73c` — Toolbox!)
3. **2 Zeroed Scalar Constants (`su_ni_ca_qt_base_stubs.obj`)**:
   - `?p@?1??getNextStateIndex@Body@RBX@@SAHXZ@4HA` (orig `0095a898`, initial value `1`!)
   - `__real@41d00000` (orig `00842428`, `26.0f`!)

---

## 23. `_ThrowInfo` (`_TI*`) C++ Exception Audit (`37` Tables — `3` Broken!)

Scanned all `37` `_ThrowInfo` tables in `snap/RobloxQT.exe` (`work/native-client/mass-tools/throwinfo_audit.json`). **`34/37` are clean; ONLY `3` are broken** (any `throw` of these crashes `_CxxThrowException`):
1. **`__TI2PAUlua_longjmp@@`** (`010120d0`, `qt_stubs.obj`): **entire `_ThrowInfo` is zeroed** -> every Lua script error (`luaD_throw`) crashes `_CxxThrowException`! (Fixed by a 3-line TU: `struct lua_longjmp; void _f() { try { throw (lua_longjmp*)0; } catch (lua_longjmp*) {} }` — also emits `??_R0PAUlua_longjmp@@@8`.)
2. **`__TI2?AVruntime_error@RBX@@`** (`00b13494`, `005809d0.obj`): `pmfnUnwind=STUB(??1runtime_error@RBX@@UAE@XZ)` and `CT[0].copyFn=STUB(??0runtime_error@RBX@@QAE@ABV01@@Z)` -> every `throw RBX::runtime_error` hits `return 0` stubs on copy/unwind!
3. **`__TI1?AUException@@`** (`00b0a208`, `004aa8a0.obj`): `CT[0].copyFn=STUB(??0Exception@@QAE@ABU0@@Z)`.

---

## 24. `??_9` Vcall Thunks (`15` Non-Exec DEP Crashes!), `__real@`/`__xmm@`, & EH Tables (`7,744` Clean!)

1. **`15` `??_9*` vcall thunks are placed in NON-EXECUTABLE `.data`** (`su_ni_ca_qt_base_stubs.obj` / `qt_stubs.obj` -> instant DEP/NX crash if called via `boost::mem_fn`/`boost::bind`!):
   - **Property Grid `ValueItem` (5)**: `EnumGridItemBase` (`$BBAA`), `GridItemBase` Vector3/float (`$BPA`), `IntGridItemBase` int/Vector3 (`$BPM`).
   - **RBX Engine (5)**: `Instance` (`$B7`, `$BM`), `PartChunk` (`$BCE`), `View::View` (`$BCA`, `$BCI`).
   - **XTP UI (5)**: `CXTPControlComboBoxList` (`$BCCI`, `$BCCM`), `CXTPDialogBar` (`$BBOM`), `CXTPReportControl` (`$BCHA`, `$BCHE`).
   - **Fix**: all `15` are trivial `mov eax, [ecx]; jmp [eax+offset]` vcall thunks (same dummy-polymorphic-class trick already in `deldtor_gen.py`!).
2. **Verified clean**:
   - **`7,744 / 7,744` `__ehfuncinfo$` EH tables**: **`0` stubbed unwind funclets, `0` stubbed catch `pType`s**!
   - **`__real@` / `__xmm@` non-zero float/SSE stubs**: ONLY `1` (`__real@41d00000` = `26.0f`, already fixed in Claude's batch), **`0` `__xmm@` stubs**!

---

## 25. MFC `CRuntimeClass` & `GetThisMessageMap` Audit (Script Editor & Studio UI)

1. **Lua Script Editor (`CScintilla*`) `GetRuntimeClass` & `GetThisMessageMap` are STUBS (`su_ni_ca_qt_base_stubs.obj`)**:
   - `?GetRuntimeClass@CScintillaCtrl@@UBEPAUCRuntimeClass@@XZ` (`007cefc0`)
   - `?GetRuntimeClass@CScintillaDoc@@UBEPAUCRuntimeClass@@XZ` (`007cefc8`)
   - `?GetRuntimeClass@CScintillaView@@UBEPAUCRuntimeClass@@XZ` (`007cefd0`)
   - `?GetThisMessageMap@CScintillaView@@KGPBUAFX_MSGMAP@@XZ` (`007cf0d0`)
   - `?GetThisMessageMap@CScintillaFindReplaceDlg@@KGPBUAFX_MSGMAP@@XZ` (`007cf0c8`)
   - **Impact**: opening a `Script` in Studio's Scintilla editor (M4) will fail `IsKindOf`/message dispatch until these are bound!
2. **`13+` Studio `messageMap` static locals in `qt_stubs.obj` / `su_ni_ca_qt_base_stubs.obj`**:
   - In `su_ni_ca_qt_base_stubs.obj`: `CClassTreeView`, `CRobloxReportView`, `CWebToolbox`.
   - In `qt_stubs.obj` (`00fd8710..00fd8ee0`): `CMainFrame`, `CPropGrid`, `CInstanceExplorer`, `CInsertObjectDialog`, `CObjectBrowser`, `CMemberTreeView`, `CDeclarationView`, `CBrowserView`, `CBrowserFrameWnd`, `CAboutRobloxDialog` (verify whether real `GetThisMessageMap()` already uses a different local vs these stubs).
3. **MFC base `CRuntimeClass` gap**: `?classCWnd@CWnd@@2UCRuntimeClass@@B` (`pre19595_linked:verified_0089.obj`) has `m_pfnGetBaseClass = STUB(?classCCmdTarget@CCmdTarget@@2UCRuntimeClass@@B)`, and `CCmdTarget`'s `_dispatchEntries`/`_eventsinkEntries`/`_interfaceEntries` are in `su_ni_ca_qt_base_stubs.obj`.

---

## 26. PE `.rsrc` Resources (`100%` Match!) & `getClassIndex`/`Type::singleton` Header Note

- **PE `.rsrc` diff (`Roblox.exe` vs `snap/RobloxQT.exe`)**: **`0` missing resource IDs** across all resource types (dialogs, menus, bitmaps, icons, HTML, string tables are 100% intact).
- **Why `getClassIndex<T>` & `Type::singleton<T>` emitted empty objs in `rbxinst.py`**:
  - `native-headers/v8tree/Service.h` only *declares* `template<class Class> static size_t getClassIndex();` (inline body is in donor `tools/rbxgs/Client/App/include/v8tree/Service.h`).
  - `native-headers/reflection/type.h` only *declares* `template<typename T> static const Type& singleton();` (each type has an explicit specialization `template<> const Type& Type::singleton<T>()`; `RefType::singleton<T>()` has the inline template body).

---

## 27. Event / Signal / `Notifier` Stubs (M4 Lua Events & M5 Play Solo)

1. **Critical `SignalDescImpl` / `TSignalDesc` stubs (break Lua `:connect()` & `Instance.Changed`!)**:
   - `?newSignalInstance@?$TSignalDesc@$$A6AXXZ@Reflection@RBX@@UBEPAVSignalInstance@23@AAVSignalSource@23@@Z` -> returns `NULL` for ALL `void()` signals (`Humanoid.Died`, `DataModel.Closing`, `OutfitChanged`).
   - `?connectGeneric@?$SignalDescImpl@$0A@$$A6AXXZ@Reflection@RBX@@` (`void()`) and `?connectGeneric@?$SignalDescImpl@$00$$A6AXM@Z@Reflection@RBX@@` (`void(float)`, e.g. `Humanoid.Running`/`Climbing`) -> return uninitialized `boost::signals::connection` (`sret`!).
   - `?findSig@?$TSignalDesc@$$A6AXPBVPropertyDescriptor@Reflection@RBX@@@Z@Reflection@RBX@@` -> `Instance.Changed` signal lookup!
   - `GenericSlotAdapter::operator()` for `void()` (`$0A@$$A6AXXZ`) and `void(bool)` (`$00$$A6AX_N@Z`) -> Lua callbacks on `void()`/`void(bool)` signals never fire!
2. **`Notifier` `connect` stubs (M5 Play Solo character/backpack events)**:
   - `Notifier<Instance, ChildAdded/ChildRemoved>::connect<shared_ptr<Backpack/Player>>`
   - `Notifier<Player, CharacterAdded/CharacterRemoving>::connect<shared_ptr<Player>>`

---

## 28. Delta Audit on Link `1795706891` (Huge Drops!)

### Verified Drops
- **`total_stubs`**: `47,342 -> 46,369` (`-973` stubs!).
- **`data_zero_audit`**: **`strings=0`, `ptrs=0`!** (All `3` MFC `GetThisMessageMap`s, all strings, and `__real@41d00000` fixed; only `Body::getNextStateIndex` `p` remains as a non-`dat_` scalar).
- **`??_9` non-exec vcall thunks**: **`15 -> 0`!**
- **`lua_longjmp` ThrowInfo / `??_R0`**: **`1 -> 0`!**
- **`ServiceProvider::getClassIndex<T>`**: **`26 -> 6`** (`20` fixed!).
- **`boost::polymorphic_cast`**: **`47 -> 11`** (`36` fixed!).

### Still Open in `1795706891`
- `_lua_setlevel` (`30x` called) is still stubbed in `qt.map` (check if `luarbx` or binding skipped it).
- `shared_count(const weak_count&)` (`00414c40`) + `add_ref_lock` (`004144f0`) + `bad_weak_ptr` ThrowInfo (`00b24bcc`) are all real & clean — so the `File->New` `bad_weak_ptr` is a real expired-`weak_ptr` / `shared_from_this()` exception from a caller.
- Remaining template stubs: `Type::singleton` (`44`), `Named::getName` (`12`), `StringConverter` (`12`), `polymorphic_cast` (`11`), `getClassIndex` (`6`).

---

## 29. Delta Audit on Link `1795708364`

- **`_lua_setlevel`**: **`30x -> 0`** (fixed! `Lua` called stub sites dropped `37 -> 7`; total `call_sites` `905 -> 876`).
- **`data_zero_audit`**: `strings=0`, `ptrs=0`, `49` scalars (`Body::getNextStateIndex` `p` + `dat_007f*`).
- **`dll_data_audit`**: `50` `mutable_data` Ogre thunks (`0` const, `0` vtable/RTTI).
- **`stub_ret_audit`**: `3` (`00772960`, `0072ea40`, `00799560`).
- With vcall restriction + pre-`rbxinst` rerun: `vcall_9=15`, `getClassIndex=26`, `polymorphic_cast=11`, `Type_singleton=44`, `Named_getName=12`, `StringConverter=12`.

---

## 30. Clean `9/9` Ladder Restored (`1795712631` — All `41/41` Insert Items Pass!)

- `featladder.json`: **`9/9` ALL `ok=ok`** (including `Motor` -> `41/41` insert items!).
- Clean metrics on `1795712631`: `total_stubs=46,425`, `vtable_stub_slots=1,273`, `call_sites=879`, `stub_ret_audit=3`, `data_zero_audit: strings=0, ptrs=0`, `dll_data_audit: 50 mutable_data (0 const, 0 vtable/RTTI)`.
- **Ready for M2–M5 sweeps**: re-run `classsweep.py` (still stale at `mtime=1795646573`), then Insert Part + Tools + Lua script + `.rbxl` save/load + Play Solo.

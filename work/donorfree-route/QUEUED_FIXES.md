# Queued layout merge fixes

DONE 2026-11-22 17:2x: items 1 (Verb split, VerbDerivedDtors2008.cpp 4/4 exact), 2 (AdornRbxGfx external
counter, 37/37 + 11/11 exact), 3 placeholders removed (Players.h part still open), 4 include-flag fixes (all compile;
exact except pre-existing partials). Header batch 1 (44 ports) installed: 1294/1295 identical, 0 changed.
Check tool: work/donorfree-route/exact_check.py SOURCE...

Each fix edits a native source; re-run the affected exact checks and the layout pipeline afterwards.

1. **Verb.cpp merge** (`inferred/client/app/v8tree/Verb.cpp`): move `RunStateVerb::~RunStateVerb` and
   `EditSelectionVerb::~EditSelectionVerb` (exe 0057dfd0, 0057e050, next to RunStateVerb ctor 0057e330 and the
   Commands.cpp stats verbs 0057d9f0..) out of `native-classes/Verb.cpp` into their own source curated to
   `client/app/v8datamodel/Commands.cpp`. With `~Verb` (005832c0, v8tree/Verb.cpp) in the same TU MSVC inlines it
   into those dtors in every member order, so they cannot share a file with it.
2. **AdornRbxGfx.cpp merge**: `native-classes/AdornRbxGfx.cpp:34` `static int nameCounter;` -> `int nameCounter;`
   (global 0097da58; AdornRbxGfx2d.cpp's finishRenderPass is exact only with external linkage). Re-check both files'
   functions exact (AdornRbxGfx.cpp:76 uses nameCounter++).
3. **RobloxView.cpp merge** (11 members): native-classes/CRobloxView.cpp:84 and :90 hold empty placeholder bodies
   `onEvent(Players*, SuperSafeChanged) {}` (00458ea0) and `onEvent(ServiceProvider*, ServiceRemoving) {}` (00459d60)
   whose real bodies are Inferred_00458ea0.cpp and CRobloxViewRecovery_00459d60.cpp. Delete the two placeholders.
   CRobloxViewRecovery_00459d60.cpp also fails alone (C2440 static_cast Instance* -> Players*): native
   Network/Players.h does not show Players : Instance - owner's CoreHeaderFixes lease holds Players.h.
4. **Workspace.cpp** (12 members, mostly tool-factory files mapped there): ctor `Workspace(IDataState*)` and
   `onChildChanged` change when joined - a member's inline-able body gets inlined. Bisect members; the tool factory
   files may belong to another original file (check per-address evidence).
5. **tool.cpp** (12 members incl. 5 donor_i wrappers): `setBackendToolStateNoReplicate`, `setGrip`, `onAncestorChanged`
   change when joined. Same bisect.
6. **PropGrid.cpp** (6 members): `brickColorName` changes plus a float literal and `_XTPLEX_ATTR_RESTARTRUNLOOP` data
   drop out; likely one member's static data/inline interaction. Bisect.

## Native sources that do not compile alone (16 real; 79 more were only "inputs changed" during the run)
- Missing vendor /I in native-flags: AppLeaves2008IDEDocManagerCtor (Platform.h), PlayersLifetime + ProfiledRakPeer
  (raknet DS_LinkedList.h), Inferred_007a9c40 (OgreEntity.h); ClumpStageRecovery_0064cf10 (v8world/TreeStage.h).
- Double definition (native + donor header both pulled, like Quaternion): AppUnit570_2008Reflection (ClassDescriptor),
  Guid (Guid), MeshIdStringConverter (ContentId), AssociationLifetime (Association dtor), DebrisService
  (DescribedCreatable ctor).
- Stale against current native headers: InstanceParent (isAncestorOf), InstanceDescendantPropagation
  (signalDescendentAdded), CRobloxViewRecovery_00459d60 (static_cast Instance* -> Players*).
- Other: WorldJointRotate (ROTATE enum clash), CAtlComModule_Term_007a61d8 (CXTIconHandle), func_0044ce20 (CRobloxModule).
- 18 FunctorInst_*/BinderTemplates C2770: regenerate with functor_lane.py (reflection/signal.h changed).

Staged for item 1: `work/donorfree-route/staged-sources/VerbDerivedDtors2008.cpp` -> copy to native-classes, remove the
two dtor lines from native-classes/Verb.cpp, verify 0057dfd0 / 0057e050 exact (runner checks) and Verb.cpp's
005833e0 still exact, add curated path `VerbDerivedDtors2008 -> client/app/v8datamodel/Commands.cpp`.

Staged flag lines for the missing-include files (add as line 1, then verify each file's checks still exact):
- PlayersLifetime.cpp, ProfiledRakPeer.cpp: `// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source` (same as AppLeaves2008Exposer.cpp; RakNet is vendor)
- Inferred_007a9c40.cpp: append ` /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include` (Ogre 1.4.5 vendor recipe include)
- AppLeaves2008IDEDocManagerCtor.cpp: `Platform.h` is Scintilla's; add ` /I{headers}/../../../tools/libs/scintilla-mfc-1.20` (as the Scintilla wrapper units do)
- ClumpStageRecovery_0064cf10.cpp: no native `v8world/TreeStage.h` exists - needs a header port (add to the header-port batch), not a flag.

Header-port follow-up: `native-headers/util/Association.h` is the donor 2007 text (object-neutral, so no regression), but
native-classes/AssociationLifetime.cpp defines `~Association` out of line (C2995 against the donor's inline body) - the
2008 header likely declared it only. Make the 2008 form once AssociationLifetime's exactness is checked.

Header batch 2 (promotions) NOT kept: GuiEvent.h (datamodel-2008 variant) breaks 190 dependents (C2143, needs its profile
siblings), UIEvent.h (uievent-native) lacks the default ctor donor Mouse.h needs, IStage.h (kernel-stages) lacks
COLLISION_STAGE and changed 1 object. TextureProxyBase.h (partchunk-profile) broke nothing: re-prove it alone.
- InstanceParent.cpp: stale duplicate (2007 API isAncestorOf/signalDescendent*); contains() exact in InstanceContainment.cpp, setParent 0055a8f0 drafted in InstanceRecovery_00559350.cpp. Superseded - owner may retire it.
- InstanceDescendantPropagation.cpp + InstanceRecovery setParent: blocked on the batch-31 Instance.h proposal (isAncestorOf 004c9c50, signalDescendentAdded 00558220 / Removing 00558370, ChildAdded/ChildRemoved payloads) - core header owner.
- ClumpStageRecovery_0064cf10.cpp: obsolete mining analog (sub_0064cf10 process(Object*)); the real onEdgeAdded/onEdgeRemoving are in ClumpStageRecovery_0064cec0.cpp. Superseded - owner may retire it.
- Fake stubs (empty bodies, invented names, false MATCH comments): CAtlComModule_Term_007a61d8.cpp, func_0044ce20.cpp - retire.
- PropGrid.cpp merge: every member breaks the anchor; shared _XTPLEX_ATTR_RESTARTRUNLOOP data + duplicate XItem<TextureId>/<Vector3>/<int> instances -> members built with different XTP/MFC profile flags. Fix = harmonize member native-flags to the original unit's set, then re-merge.
- Workspace.cpp merge: anchor AppUnit5A0 + 10 members merge clean; breakers ModelSetFrontTool (inlined Math::getWorldNormal / Vector3 ops), WorkspaceRecovery_005a05c0 (inlined World::reset/assertNotInStep), and WorkspaceFindTopInstance / WorkspaceJoin / WorkspaceLifetime do not compile joined (duplicate defs).
- Header batch 3 (donor copies of IStage.h/UIEvent.h/GuiEvent.h at the root): 16 of 574 objects change (Accoutrement, Creators, ModelInstance, RootInstance, PartInstance...) because the moved text's quoted includes now resolve to native siblings. Needs hand-written 2008 headers.
- native-headers/v8datamodel/Gyro.h still uses the donor &sX pointer-form class names (C2440 char** -> const char*): convert to 2008 array form; then add RefPropDescriptor<Rocket, PartInstance> to RefPropDescriptorBatchB2008.cpp.
- Reflection headers: native headers make TypedPropertyDescriptor<Enum> and <RawPointer*> vtables that the 2008 exe does
  not have (no RTTI .?AV?$TypedPropertyDescriptor@W4... / @PAV...). ~100 "missing" string/XML members and the enum/pointer
  generic members come from that. Fix in the native reflection headers (EnumPropDescriptor / RefPropDescriptor must not
  instantiate TypedPropertyDescriptor<Enum/T*>'s vtable), not with more bodies. Core header - owner decision.

## From unowned-exact worker 2026-11-22
- Header need: native-headers/v8world/Primitive2008.h must declare `RigidJoint* getFirstRigidAt(Edge*)` (005e7c10), `getFirstRigid()` (005e7c80), `getNextRigid(RigidJoint*)` (005e7ca0). getNextRigid is `getFirstRigidAt(joints.edges[idx+1] or NULL)` (tail jmp); 005e7ca0 is in the unowned-exact set. getFirstRigidAt was 93 B vs 97 B (see PrimitiveState.cpp batch 42).
- 64 unowned-exact addrs are already exact in existing native files (list in side-session notes folder): need receipts, not new code.
- 64 of the 588 'Other remaining' are byte-exact in existing native files (e.g. AppUnit5ECSurfaces.cpp 27 initializers 007f7180-007f75d0 + 005eca30/ecaf0/ecb50) but need call/reference identity proof for a receipt (runner analyze --index-output refuses: 'proof incomplete'); the scheduled work/native-client/prove.py --all run creates those.

## Donor-free link data symbols (unowned-exact worker, 2026-11-23)
Closed (data definitions in new native-classes files): BlockFaceTables2008, MouseCommandStatics2008, NativeGlobalData2008, ClassStatics{Debug,Part,World,Reflection,Gui,Humanoid,View,Sound,ThreadRef,Chunk,RenderStats,CrashReporter}2008. Link: RBX unresolved 382 -> 346, total 1308 -> 1264.
Still open, need a header change or are non-trivial:
- LogManager::mainLogManager (`?mainLogManager@LogManager@@1PAVMainLogManager@@A`, protected/private static): native-headers/LogManager.h lacks `static MainLogManager* mainLogManager;`. Value: null (.bss).
- characterArchivableSetter (`RBX::characterArchivableSetter`, TypedPropertyDescriptor<bool>::GetSet*): no native header declares it; referenced from Player::loadCharacter. Needs the declaration (Player.h / Instance.h area) and exe address.
- NIIWriter::NII_message / NII_callbackTag (const char[]): only local externs in NewInstanceItemRecovery_004afc70.cpp; string text must be taken from the exe at the pushes in 004afc70.
- sX class-name constants (`?sPart@RBX@@3PADA` etc.): references expect `char sPart[]` (PADA) or `const char* const` (QBDB) but the definitions in AppUnit*Names.cpp are the other form; header/definition mismatch, not a missing definition.
- Bridge<T>::className, FactoryProduct::creator, prop_*/desc_*/event_* descriptors, font2d, shadeResourceGroup, GlobalSettings::mutex: non-scalar, need their constructors (EnumDesc/SignalDesc/PropDescriptor templates) linked first.

- Instance::raisePropertyChanged 0040db00: boot stub uses `ret 4` override (make_stubs.py RET_BYTES). Real fix = header: Instance.h needs
  `static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged` and inline PropertyChanged/Property copy ctors
  (worker body: rebuild/2008-06/tests/NativeInstancePropertyChangedWorker.cpp). Parked in AppUnit40C_2008Metadata.cpp (leased by queue 45-sc04).
- Type::singleton<Tuple>/<PartInstance::FormFactor> have no exe counterpart: stand-ins in TypeSingletonsBoot2008.cpp; delete with the EnumPropDescriptor/Tuple signature header fix.

- RunService::runProc 0055 5190 (run-thread loop: getRealTime, Stopwatch tick/tock, helpers 00554880/00554ed0/005550a0/00554e10; stub uses ret 8 override).
- WorldLifetime.cpp / AppUnit5A0_2008Workspace.cpp: profiler-parent hookups parked (World member offsets past +0xb8 are off by 0xc in engine-world/World.h; kernel-stages and donor stage headers conflict). Fix = reconcile World.h layout (set<> at +0xc4 .. profilers at +0xfc..+0x110) then restore hookups.
- 2008 has no CollisionStage: removed donor getCollisionStage() call from World().

- STATIC AUDITS (no run needed): `python work/donorfree-route/vtable_audit.py > vtable_audit.txt` (229 of 1426 vtables differ in slot count at 11-23 11:20; 82 are 1-3 slots vs >8 in the exe: GuiRoot/GuiItem/Widget family is donor-shaped (primary vtable starts with GuiItem::process), Hopper/Backpack/HopperBin/StarterPack, Clothing/BodyColors/Skin, Glue/Motor/Rotate*/Snap/Weld (5 vs 16), Decal/Texture, ContentItem<..>, FilteredSelection<..>, CSelectionPropGrid 2 vs 92). Each needs its native header's virtuals rewritten to the 2008 slot list (rtti_vtable.py gives the exe slots with names). `gen_sp_members.py` generates ServiceProvider find/create instances from stubs. make_stubs.py derives `ret N` from undname signatures.
- CORRECTION (11-23 11:30): the first vtable_audit run overcounted (it read a small secondary vtable on multi-inheritance classes; GuiRoot/Hopper/etc. were false positives). Refined audit takes our largest vtable per class: 138 mismatched, 23 differ by >=3 slots (ATL CComObject wrappers, XTP CXTPControl/DockingPane/PaintManager 3 short, Flag 37 vs 41 (!), SignalDesc<Player/Players> 3 vs 7, GImage::Error). Real queue: Flag (4 virtuals missing), SignalDesc types, then the XTP ones. The File->New heap-eip crash is NOT explained by vtable counts.
- EnumPropDescriptor<C,E> vtable is 17 slots vs 18 in the exe (Camera/HopperBin/PartInstance enum props, property grid path): exe order after readValue(11): 12 A(getset value -> table lookup [desc+0xdc], -1 on miss), 13 setIndexValue, 14 getEnumValue (tail jmp getset->getValue), 15 setEnumValue(isValue check), 16 B (getset value -> table [desc+0xac], 0 on miss), 17 setStringValue(Name) 00448610; slot 8 is setStringValue(std::string) 0060c120 (ours puts the Name overload at 8 and the string one last). property.h base declares (getIndexValue, setIndexValue, getEnumValue, setEnumValue) - reconcile names/order and add the missing 6th virtual.

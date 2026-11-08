"""Binding maps for tests/record_native_services.py (not a recorder; imported by it).

EXTERNAL: call/data targets outside the rows proven here, each the address the original instruction uses (read at
the call sites of the listed rows). FOLDED: bodies this unit emits that the original keeps once (ICF / COMDAT).
DATA: descriptor objects and statics the original pushes.
"""
EXTERNAL = {
    '??$?0PAVJointsService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVJointsService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x4ac710,   # call site in shared_ptr<JointsService> ctor 004ad610 (2008 boost form, not compared)
    '??$?0PAVPhysicsService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVPhysicsService@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x4ca3c0,   # call site in ??$?0VPhysicsService@RBX@@VDeleter@?$Creatable@VIn
    '??$?0VGlue@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VGlue@RBX@@@boost@@QAE@PAVGlue@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b27e0,   # call site in ??$create@VGlue@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??$?0VRotate@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VRotate@RBX@@@boost@@QAE@PAVRotate@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b2a50,   # call site in ??$create@VRotate@RBX@@PAVJoint@2@@?$Creatable@VIn
    '??$?0VRotateP@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VRotateP@RBX@@@boost@@QAE@PAVRotateP@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b2cc0,   # call site in ??$create@VRotateP@RBX@@PAVJoint@2@@?$Creatable@VI
    '??$?0VRotateV@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VRotateV@RBX@@@boost@@QAE@PAVRotateV@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b2f30,   # call site in ??$create@VRotateV@RBX@@PAVJoint@2@@?$Creatable@VI
    '??$?0VSnap@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VSnap@RBX@@@boost@@QAE@PAVSnap@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b2300,   # evidence ??$?0VSnap@RBX@@VDeleter@?$Creatable@VInstance@RBX; call site in ??$create@VSnap@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??$?0VWeld@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@?$shared_ptr@VWeld@RBX@@@boost@@QAE@PAVWeld@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@3@@Z': 0x4b2570,   # call site in ??$create@VWeld@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??$shared_from@VPartInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VPartInstance@RBX@@@boost@@PAVPartInstance@0@@Z': 0x618a40,   # evidence ??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_; call site in ?onAdded@PhysicsService@RBX@@AAEXPAVPartInstance@2
    '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,   # evidence ??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@; call site in ??0?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shar
    '??0?$NonFactoryProduct@VInstance@RBX@@$0A@@RBX@@QAE@XZ': 0x409960,   # call site in ??0JointsService@RBX@@QAE@XZ
    '??0?$_Tree@V?$_Tset_traits@PAVPartInstance@RBX@@U?$less@PAVPartInstance@RBX@@@std@@V?$allocator@PAVPartInstance@RBX@@@4@$0A@@std@@@std@@QAE@ABU?$less@PAVPartInstance@RBX@@@1@ABV?$allocator@PAVPartInstance@RBX@@@1@@Z': 0x64b2a0,   # evidence ??0?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$le; call site in ??0PhysicsService@RBX@@QAE@XZ
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # call site in ?classDescriptor@?$Described@VPhysicsService@RBX@@
    '??0Glue@RBX@@QAE@PAVJoint@1@@Z': 0x5e4920,   # call site in ??$create@VGlue@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,   # evidence ??0Instance@RBX@@IAE@XZ; call site in ??0?$NonFactoryProduct@VInstance@RBX@@$1?sPhysicsS
    '??0Rotate@RBX@@QAE@PAVJoint@1@@Z': 0x5e4a60,   # call site in ??$create@VRotate@RBX@@PAVJoint@2@@?$Creatable@VIn
    '??0RotateP@RBX@@QAE@PAVJoint@1@@Z': 0x5e4b90,   # call site in ??$create@VRotateP@RBX@@PAVJoint@2@@?$Creatable@VI
    '??0RotateV@RBX@@QAE@PAVJoint@1@@Z': 0x5e4d30,   # call site in ??$create@VRotateV@RBX@@PAVJoint@2@@?$Creatable@VI
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,   # evidence ??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDe; call site in ??0?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shar
    '??0Snap@RBX@@QAE@PAVJoint@1@@Z': 0x5e44f0,   # call site in ??$create@VSnap@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,   # evidence ??0Value@Reflection@RBX@@QAE@XZ; call site in ??0?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shar
    '??0Weld@RBX@@QAE@PAVJoint@1@@Z': 0x5e4710,   # call site in ??$create@VWeld@RBX@@PAVJoint@2@@?$Creatable@VInst
    '??1?$_Tree@V?$_Tset_traits@PAVPartInstance@RBX@@U?$less@PAVPartInstance@RBX@@@std@@V?$allocator@PAVPartInstance@RBX@@@4@$0A@@std@@@std@@QAE@XZ': 0x64b230,   # evidence ??1?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@U?$le; call site in ??1PhysicsService@RBX@@UAE@XZ
    '??1?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@QAE@XZ': 0x4199e0,   # evidence ??1?$list@UItem@SignatureDescriptor@Reflection@RBX; call site in ??__Fevent_AssemblyAdded@RBX@@YAXXZ
    '??1?$shared_ptr@VGlue@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1?$shared_ptr@VRotate@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1?$shared_ptr@VRotateP@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1?$shared_ptr@VRotateV@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1?$shared_ptr@VSnap@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1?$shared_ptr@VWeld@RBX@@@boost@@QAE@XZ': 0x600660,   # evidence ??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,   # evidence ??1ClassDescriptor@Reflection@RBX@@UAE@XZ; call site in ??__Ffoo@?1??classDescriptor@?$Described@VPhysicsS
    '??1IRenderableBucket@RBX@@QAE@XZ': 0x5dd2c0,   # call site in ??1JointsService@RBX@@UAE@XZ
    '??1Instance@RBX@@UAE@XZ': 0x55a540,   # evidence ??1Instance@RBX@@MAE@XZ; call site in ??1JointsService@RBX@@UAE@XZ
    '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,   # evidence ??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoJo
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,   # evidence ?_Buynode@?$list@UItem@SignatureDescriptor@Reflect; call site in ??0?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shar
    '?_Incsize@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEXI@Z': 0x682cc0,   # evidence ?_Incsize@?$list@UItem@SignatureDescriptor@Reflect; call site in ??0?$SignalDesc@VPhysicsService@RBX@@$$A6AXV?$shar
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,   # call site in ?getClassName@?$NonFactoryProduct@VInstance@RBX@@$
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,   # evidence ?classDescriptor@?$Described@VInstance@RBX@@$1?sIn; call site in ?classDescriptor@?$Described@VPhysicsService@RBX@@
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,   # evidence ?declare@Name@RBX@@SAABV12@PBDH@Z; call site in ??$doDeclare@$1?sPhysicsService@RBX@@3QBDB@Name@RB
    '?erase@?$_Tree@V?$_Tset_traits@PAVPartInstance@RBX@@U?$less@PAVPartInstance@RBX@@@std@@V?$allocator@PAVPartInstance@RBX@@@4@$0A@@std@@@std@@QAEIABQAVPartInstance@RBX@@@Z': 0x5e9f60,   # evidence ?erase@?$_Tree@V?$_Tset_traits@PAVScript@RBX@@U?$l; call site in ?onRemoved@PhysicsService@RBX@@AAEXPAVPartInstance
    '?fire@?$SignalDescImpl@$00$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z@Reflection@RBX@@QAEXPAVSignalSource@23@V?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x49d200,   # evidence ?fire@?$SignalDescImpl@$00$$A6AXV?$shared_ptr@VIns; call site in ?onAdded@PhysicsService@RBX@@AAEXPAVPartInstance@2
    '?fromPrimitive@PartInstance@RBX@@SAPAV12@PAVPrimitive@2@@Z': 0x599f80,   # evidence ?fromPrimitiveConst@PartInstance@RBX@@SAPBV12@PBVP; call site in ?onEvent@PhysicsService@RBX@@MAEXPBVWorld@2@UAssem
    '?getJointOwner@Joint@RBX@@QBEPAVIJointOwner@2@XZ': 0x6cb020,   # call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoDe
    '?insert@?$_Tree@V?$_Tset_traits@PAVPartInstance@RBX@@U?$less@PAVPartInstance@RBX@@@std@@V?$allocator@PAVPartInstance@RBX@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tset_traits@PAVPartInstance@RBX@@U?$less@PAVPartInstance@RBX@@@std@@V?$allocator@PAVPartInstance@RBX@@@4@$0A@@std@@@std@@_N@2@ABQAVPartInstance@RBX@@@Z': 0x5e8c40,   # evidence ?insert@?$_Tree@V?$_Tset_traits@PAVPrimitive@RBX@@; call site in ?onAdded@PhysicsService@RBX@@AAEXPAVPartInstance@2
    '?onAdded@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z': 0x5dd4c0,   # evidence ?onAdded@IRenderableBucket@RBX@@IAEXPAVIRenderable; call site in ?onDescendentAdded@JointsService@RBX@@EAEXPAVInsta
    '?onDescendentAdded@Instance@RBX@@UAEXPAV12@@Z': 0x55ae20,   # evidence ?onDescendentAdded@Instance@RBX@@MAEXPAV12@@Z; call site in ?onDescendentAdded@JointsService@RBX@@EAEXPAVInsta
    '?onDescendentRemoving@Instance@RBX@@UAEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x55ae90,   # evidence ?onDescendentRemoving@Instance@RBX@@MAEXABV?$share; call site in ?onDescendentRemoving@JointsService@RBX@@EAEXABV?$
    '?onRemoving@IRenderableBucket@RBX@@IAEXPAVIRenderable@2@@Z': 0x5dd4d0,   # evidence ?onRemoving@IRenderableBucket@RBX@@IAEXPAVIRendera; call site in ?onDescendentRemoving@JointsService@RBX@@EAEXABV?$
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,   # evidence ?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$c; call site in ??0JointsService@RBX@@QAE@XZ
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,   # evidence ?setParent@Instance@RBX@@QAEXPAV12@@Z; call site in ?onEvent@JointsService@RBX@@EAEXPBVWorld@2@UAutoDe
    '_atexit': 0x6a17af,   # call site in ??__Eevent_AssemblyAdded@RBX@@YAXXZ
    # NetworkSettings unit
    '??$?0PAVNetworkSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVNetworkSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x49e620,   # call site in ??$?0VNetworkSettings@RBX@@VDeleter@?$Creatab
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,   # evidence ??0?$TypedPropertyDescriptor@_N@Reflecti; call site in ??$?0VNetworkSettings@RBX@@@?$BoundProp@H$00@
    '??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,   # evidence ??0?$TypedPropertyDescriptor@M@Reflectio; call site in ??$?0VNetworkSettings@RBX@@@?$BoundProp@M$00@
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,   # evidence ??0?$TypedPropertyDescriptor@_N@Reflecti; call site in ??$?0VNetworkSettings@RBX@@@?$BoundProp@_N$00
    '??0?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4PhysicsReceiveMethod@NetworkSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4PhysicsReceiveMethod@NetworkSettings@2@@std@@@6@$0A@@std@@@std@@QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4PhysicsReceiveMethod@NetworkSettings@2@@std@@@1@@Z': 0x446110,   # evidence ??0?$_Tree@V?$_Tmap_traits@W4Number@Bric; call site in ??0?$EnumDesc@W4PhysicsReceiveMethod@NetworkS
    '??0?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4PhysicsSendMethod@NetworkSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4PhysicsSendMethod@NetworkSettings@2@@std@@@6@$0A@@std@@@std@@QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4PhysicsSendMethod@NetworkSettings@2@@std@@@1@@Z': 0x446110,   # evidence ??0?$_Tree@V?$_Tmap_traits@W4Number@Bric; call site in ??0?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z': 0x56c590,   # evidence ??0EnumDescriptor@Reflection@RBX@@IAE@PB; call site in ??0?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '??0Item@GlobalSettings@RBX@@QAE@XZ': 0x409e00,   # call site in ??0?$FactoryProduct@VNetworkSettings@RBX@@VIt
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,   # evidence ??0runtime_error@std@@QAE@ABV?$basic_str; call site in ??0?$GlobalSettingsItem@VNetworkSettings@RBX@
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4PhysicsReceiveMethod@NetworkSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4PhysicsReceiveMethod@NetworkSettings@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,   # evidence ??1?$_Tree@V?$_Tmap_traits@W4Number@Bric; call site in ??1?$EnumDesc@W4PhysicsReceiveMethod@NetworkS
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4PhysicsSendMethod@NetworkSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4PhysicsSendMethod@NetworkSettings@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,   # evidence ??1?$_Tree@V?$_Tmap_traits@W4Number@Bric; call site in ??1?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,   # call site in ??1?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ': 0x4077d0,   # evidence ?_Tidy@?$vector@V?$basic_string@DU?$char; call site in ??1?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '?addPair@?$EnumDesc@W4PhysicsReceiveMethod@NetworkSettings@RBX@@@Reflection@RBX@@AAEXW4PhysicsReceiveMethod@NetworkSettings@3@PBD@Z': 0x64d530,   # evidence ?addPair@?$EnumDesc@W4BinType@HopperBin@; call site in ??0?$EnumDesc@W4PhysicsReceiveMethod@NetworkS
    '?addPair@?$EnumDesc@W4PhysicsSendMethod@NetworkSettings@RBX@@@Reflection@RBX@@AAEXW4PhysicsSendMethod@NetworkSettings@3@PBD@Z': 0x64d530,   # evidence ?addPair@?$EnumDesc@W4BinType@HopperBin@; call site in ??0?$EnumDesc@W4PhysicsSendMethod@NetworkSett
    '?convertToItem@?$EnumDesc@W4PhysicsSendMethod@NetworkSettings@RBX@@@Reflection@RBX@@QBEPBVItem@EnumDescriptor@23@ABW4PhysicsSendMethod@NetworkSettings@3@@Z': 0x446d40,   # call site in ?lookup@?$EnumDesc@W4PhysicsSendMethod@Networ
    '?convertToValue@?$EnumDesc@W4PhysicsSendMethod@NetworkSettings@RBX@@@Reflection@RBX@@QBE_NABVName@3@AAW4PhysicsSendMethod@NetworkSettings@3@@Z': 0x5ed300,   # call site in ?lookup@?$EnumDesc@W4PhysicsSendMethod@Networ
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,   # call site in ??0?$GlobalSettingsItem@VNetworkSettings@RBX@
    '?lookup@Name@RBX@@SAABV12@PBD@Z': 0x554290,   # evidence ?lookup@Name@RBX@@SAABV12@PBD@Z; call site in ?lookup@?$EnumDesc@W4PhysicsSendMethod@Networ
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,   # evidence ?raisePropertyChanged@Instance@RBX@@QAEX; call site in ?setPhysicsSendMethod@NetworkSettings@RBX@@QA
}
DATA = {
    '?sPhysicsService@RBX@@3QBDB': 0x83f858,   # pushed in ??$doDeclare@$1?sPhysicsService@RBX@@3QBDB@Name@RB
    '_event_AssemblyAdded': 0x97abec,   # pushed in ??__Eevent_AssemblyAdded@RBX@@YAXXZ
    '_event_AssemblyRemoved': 0x97ac20,   # pushed in ??__Eevent_AssemblyRemoved@RBX@@YAXXZ
    # NetworkSettings unit
    '?s@?1??singleton@?$EnumDesc@W4PhysicsReceiveMethod@NetworkSettings@RBX@@@Reflection@RBX@@SAABV234@XZ@4V234@A': 0x971118,   # pushed in ?singleton@?$EnumDesc@W4PhysicsReceiveMethod@Netwo
    '?s@?1??singleton@?$EnumDesc@W4PhysicsSendMethod@NetworkSettings@RBX@@@Reflection@RBX@@SAABV234@XZ@4V234@A': 0x971028,   # pushed in ?singleton@?$EnumDesc@W4PhysicsSendMethod@NetworkS
    '?sNetworkSettings@RBX@@3QBDB': 0x823ec0,   # pushed in ?classDescriptor@?$Described@VNetworkSettings@RBX@
    '?sing@?$GlobalSettingsItem@VNetworkSettings@RBX@@$1?sNetworkSettings@2@3QBDB@RBX@@0PAV12@A': 0x9706d0,   # pushed in ??1?$GlobalSettingsItem@VNetworkSettings@RBX@@$1?s
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,   # pushed in ??0?$GlobalSettingsItem@VNetworkSettings@RBX@@$1?s
    '__real@42b40000': 0x82438c,   # pushed in ??0NetworkSettings@RBX@@QAE@XZ
    '_prop_ExtraPingVariance': 0x97131c,   # pushed in ??__Fprop_ExtraPingVariance@RBX@@YAXXZ
    '_prop_MaxSendBPS': 0x971210,   # pushed in ??__Fprop_MaxSendBPS@RBX@@YAXXZ
    '_prop_MaxSendBuffer': 0x97122c,   # pushed in ??__Fprop_MaxSendBuffer@RBX@@YAXXZ
    '_prop_MinExtraPing': 0x9713a8,   # pushed in ??__Fprop_MinExtraPing@RBX@@YAXXZ
    '_prop_PhysicsMtuAdjust': 0x971370,   # pushed in ??__Fprop_PhysicsMtuAdjust@RBX@@YAXXZ
    '_prop_PhysicsReceive': 0x97129c,   # pushed in ?setPhysicsReceiveMethod@NetworkSettings@RBX@@QAEX
    '_prop_PhysicsReplicationUpdateRate': 0x971264,   # pushed in ??__Fprop_PhysicsReplicationUpdateRate@RBX@@YAXXZ
    '_prop_PhysicsSend': 0x9712c0,   # pushed in ?setPhysicsSendMethod@NetworkSettings@RBX@@QAEXABW
    '_prop_PrintInstances': 0x97138c,   # pushed in ??__Fprop_PrintInstances@RBX@@YAXXZ
    '_prop_PrintPacketBuffer': 0x971248,   # pushed in ??__Fprop_PrintPacketBuffer@RBX@@YAXXZ
    '_prop_PrintPhysicsErrors': 0x9713c4,   # pushed in ??__Fprop_PrintPhysicsErrors@RBX@@YAXXZ
    '_prop_PrintProperties': 0x971280,   # pushed in ??__Fprop_PrintProperties@RBX@@YAXXZ
    '_prop_ReplicationMtuAdjust': 0x971338,   # pushed in ??__Fprop_ReplicationMtuAdjust@RBX@@YAXXZ
    '_prop_SendRate': 0x971300,   # pushed in ??__Fprop_SendRate@RBX@@YAXXZ
    '_prop_Test1': 0x9712e4,   # pushed in ??__Fprop_Test1@RBX@@YAXXZ
    '_prop_Test2': 0x9713e0,   # pushed in ??__Fprop_Test2@RBX@@YAXXZ
    '_prop_Test3': 0x9713fc,   # pushed in ??__Fprop_Test3@RBX@@YAXXZ
    '_prop_Test4': 0x971354,   # pushed in ??__Fprop_Test4@RBX@@YAXXZ
}
FOLDED = {
    # EnumDesc<E>::lookup is one ICF-shared body for both NetworkSettings enums (0x4aa0d0, row of the Send instance)
    '?lookup@?$EnumDesc@W4PhysicsReceiveMethod@NetworkSettings@RBX@@@Reflection@RBX@@UBEPBVItem@EnumDescriptor@23@PBD@Z': 0x4aa0d0,
}
# Targets whose own rows are not exact here (not attempted, or exact only in the pending build): bound by the address
# the original vtable slot / instruction uses; listed separately so they never count as proof.
UNPROVEN = {
    '?onServiceProvider@JointsService@RBX@@EAEXPBVServiceProvider@2@0@Z': 0x5e5b50,
    '?onServiceProvider@PhysicsService@RBX@@MAEXPBVServiceProvider@2@0@Z': 0x5e8ec0,
    '?onEvent@PhysicsService@RBX@@MAEXPBVWorld@2@UAssemblyPhysicsOn@2@@Z': 0x5e9110,    # pending-build-only row
    '?onEvent@PhysicsService@RBX@@MAEXPBVWorld@2@UAssemblyPhysicsOff@2@@Z': 0x5e9130,   # pending-build-only row
    '??$?0P8NetworkSettings@RBX@@BE?AW4PhysicsReceiveMethod@01@XZP801@AEXABW4201@@Z@?$EnumPropDescriptor@VNetworkSettings@RBX@@W4PhysicsReceiveMethod@12@@Reflection@RBX@@QAE@PBD0P8NetworkSettings@2@BE?AW4PhysicsReceiveMethod@32@XZP832@AEXABW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x4aaae0,   # EnumPropDescriptor constructor (not exact: 2008 reflection.h); called in ??__Eprop_PhysicsReceive@RBX@@YAXXZ
    '??$?0P8NetworkSettings@RBX@@BE?AW4PhysicsSendMethod@01@XZP801@AEXABW4201@@Z@?$EnumPropDescriptor@VNetworkSettings@RBX@@W4PhysicsSendMethod@12@@Reflection@RBX@@QAE@PBD0P8NetworkSettings@2@BE?AW4PhysicsSendMethod@32@XZP832@AEXABW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x4aa9a0,   # EnumPropDescriptor constructor (not exact: 2008 reflection.h); called in ??__Eprop_PhysicsSend@RBX@@YAXXZ
}
NOT_ATTEMPTED_NETWORK = {
    '004aa9a0/004aaae0': 'EnumPropDescriptor<NetworkSettings, PhysicsSendMethod/PhysicsReceiveMethod> constructors: the 2008 '
                         'reflection.h constructor (call_once singleton twice, EnumDesc reference at +0x20) differs from '
                         'the shared native header (same finding as Feature 0060bd80)',
    '004aa700/004aa770': 'call_once wrappers of EnumDesc<E>::singleton (jmp 004aa6a0 / 004aa710), emitted only by that '
                         '2008 constructor',
    '004aaa80': 'EnumPropDescriptor virtual (getset getValue, then the EnumDesc item vector +0xdc/+0xe0): 2008 layout',
}
NOT_ATTEMPTED = {
    '005e5b50': 'JointsService::onServiceProvider: ServiceProvider::find<Workspace> 00490af0 and Workspace world +0x2e4 '
                '(no native Workspace.h); disconnect/connect Notifier<World,AutoJoin> (World +0) / <World,AutoDestroy> (+0x20)',
    '005e8ec0': 'PhysicsService::onServiceProvider: same Workspace dependency; Notifier<World,AssemblyPhysicsOn/Off> at '
                'World +0x40/+0x60 (the donor World.h has neither notifier base)',
    '004ca3c0': 'boost::detail::shared_count(PhysicsService*, Creatable<Instance>::Deleter) (110 bytes): the 2008 boost '
                'form (try/catch, no bad_alloc check) differs from the donor boost 1.34.1 header (131 bytes)',
}
FPN = '?$FactoryProduct@VNetworkSettings@RBX@@VItem@GlobalSettings@2@$1?sNetworkSettings@2@3QBDB@RBX@@'
DCN = '?$DescribedCreatable@VNetworkSettings@RBX@@VItem@GlobalSettings@2@$1?sNetworkSettings@2@3QBDB@RBX@@'
GSI = '?$GlobalSettingsItem@VNetworkSettings@RBX@@$1?sNetworkSettings@2@3QBDB@RBX@@'
DSN = '?$Described@VNetworkSettings@RBX@@$1?sNetworkSettings@2@3QBDBV' + FPN[:-6] + '@2@@Reflection@RBX@@'
EDS = '?$EnumDesc@W4PhysicsSendMethod@NetworkSettings@RBX@@@Reflection@RBX@@'
EDR = '?$EnumDesc@W4PhysicsReceiveMethod@NetworkSettings@RBX@@@Reflection@RBX@@'
NS = 'NetworkSettings@RBX@@'
# (initializer, atexit) per property, in definition order: the atexit address is the one each initializer pushes.
PROPS = [('PrintInstances', 0x7f1df0, 0x7fbf10), ('PrintProperties', 0x7f1e20, 0x7fbef0),
         ('PrintPacketBuffer', 0x7f1e50, 0x7fbd50), ('PrintPhysicsErrors', 0x7f1e80, 0x7fbd70),
         ('Test1', 0x7f1eb0, 0x7fbd90), ('Test2', 0x7f1ee0, 0x7fbdb0), ('Test3', 0x7f1f10, 0x7fbdd0),
         ('Test4', 0x7f1f40, 0x7fbdf0), ('MaxSendBPS', 0x7f1f70, 0x7fbf50), ('MinExtraPing', 0x7f1fa0, 0x7fbf30),
         ('ExtraPingVariance', 0x7f1fd0, 0x7fbe10), ('PhysicsSend', 0x7f2000, 0x7fbe70),
         ('PhysicsReceive', 0x7f2040, 0x7fbe50), ('PhysicsReplicationUpdateRate', 0x7f2080, 0x7fbe30),
         ('MaxSendBuffer', 0x7f20b0, 0x7fbe90), ('PhysicsMtuAdjust', 0x7f20e0, 0x7fbeb0),
         ('ReplicationMtuAdjust', 0x7f2110, 0x7fbed0), ('SendRate', 0x7f2140, 0x7fbf70)]
NETWORK_ROWS = [
    (0x4a9b70, '??1' + FPN + 'MAE@XZ'),
    (0x4a9bf0, '??0' + FPN + 'IAE@XZ'),
    (0x4a9bd0, '??_E' + FPN + 'OCE@AEPAXI@Z'), (0x4a9be0, '??_E' + FPN + 'OGE@AEPAXI@Z'),
    (0x4aa820, '??_E' + FPN + 'OBA@AEPAXI@Z'), (0x4aa830, '??_E' + FPN + 'OBE@AEPAXI@Z'),
    (0x4aa840, '??_E' + FPN + 'OEE@AEPAXI@Z'), (0x4aa850, '??_E' + FPN + 'OIE@AEPAXI@Z'),
    (0x4aa860, '??_E' + FPN + 'OKE@AEPAXI@Z'), (0x4aa870, '??_E' + FPN + 'OME@AEPAXI@Z'),
    (0x4aa880, '??_G' + FPN + 'MAEPAXI@Z'),
    (0x4a9c50, '??$getset@P8NetworkSettings@RBX@@BE?AW4PhysicsSendMethod@'),
    (0x4a9ca0, '??$getset@P8NetworkSettings@RBX@@BE?AW4PhysicsReceiveMethod@'),
    (0x4a9cf0, '??1' + DSN + 'UAE@XZ'),
    (0x4a9d00, '??1' + GSI + 'MAE@XZ'),
    (0x4a9d60, '??_E' + NS + 'WKE@AEPAXI@Z'), (0x4a9d70, '??_E' + NS + 'WME@AEPAXI@Z'),
    (0x4a9d80, '??_E' + NS + 'WBE@AEPAXI@Z'), (0x4aad00, '??_E' + NS + 'WCE@AEPAXI@Z'),
    (0x4aad10, '??_E' + NS + 'WEE@AEPAXI@Z'), (0x4aad20, '??_E' + NS + 'WGE@AEPAXI@Z'),
    (0x4aad30, '??_E' + NS + 'WIE@AEPAXI@Z'), (0x4aad40, '??_E' + NS + 'WBA@AEPAXI@Z'),
    (0x4aad50, '??_G' + NS + 'UAEPAXI@Z'),
    (0x4a9d90, '?getClassName@' + FPN + 'UBEABVName@2@XZ'),
    (0x4a9db0, '??1' + EDS + 'EAE@XZ'), (0x4a9f40, '??1' + EDR + 'EAE@XZ'),
    (0x4aa0d0, '?lookup@' + EDS),
    (0x4aa110, '??_G' + EDS + 'EAEPAXI@Z'), (0x4aa130, '??_G' + EDR + 'EAEPAXI@Z'),
    (0x4aa150, '??0' + EDS + 'AAE@XZ'), (0x4aa2c0, '??0' + EDR + 'AAE@XZ'),
    (0x4aa430, '??$?0VNetworkSettings@RBX@@@?$BoundProp@_N$00@'),
    (0x4aa500, '??$?0VNetworkSettings@RBX@@@?$BoundProp@H$00@'),
    (0x4aa5d0, '??$?0VNetworkSettings@RBX@@@?$BoundProp@M$00@'),
    (0x4aa6a0, '?singleton@' + EDS + 'SAABV123@XZ'), (0x4aa710, '?singleton@' + EDR + 'SAABV123@XZ'),
    (0x4aa780, '??0' + DCN + 'IAE@XZ'),
    (0x4aa8a0, '??0' + GSI + 'IAE@XZ'),
    (0x4aabc0, '??0NetworkSettings@RBX@@QAE@XZ'),
    (0x4aad70, '?setPhysicsSendMethod@' + NS),
    (0x4aada0, '?setPhysicsReceiveMethod@' + NS),
    (0x409e60, '?askAddChild@Item@GlobalSettings@RBX@@MBE_NPBVInstance@3@@Z'),   # inline in GlobalSettings.h
    (0x445220, '?getPhysicsSendMethod@' + NS),        # ICF-shared getter body
    (0x6a6ee0, '?getPhysicsReceiveMethod@' + NS),     # ICF-shared getter body
    (0x49e510, '??$doDeclare@$1?sNetworkSettings@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x49e580, '??$callDoDeclare@$1?sNetworkSettings@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x49ec80, '?classDescriptor@' + DSN + 'SAAAVClassDescriptor@23@XZ'),
    (0x7fba30, '??__Ffoo@?1??classDescriptor@' + DSN),
    (0x7fbfa0, '??__Fs@?1??singleton@' + EDS), (0x7fbf90, '??__Fs@?1??singleton@' + EDR),
] + [(init, '??__Eprop_%s@RBX@@YAXXZ' % n) for n, init, _ in PROPS] + [(fin, '??__Fprop_%s@RBX@@YAXXZ' % n) for n, _, fin in PROPS]


def network_vtables(check_vtable, layout_obj, network_obj, gi):
    """NetworkSettings-unit vtables, slot by slot from the main-build object (Instance vtable 0082d884 is the reference
    for inherited slots)."""
    out = {}
    for key, symbol, address, own_class in (
            ('NetworkSettings', '??_7NetworkSettings@RBX@@' + gi, 0x824344, 'NetworkSettings'),
            ('GlobalSettingsItem', '??_7' + GSI + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x824074, ''),
            ('DescribedCreatable', '??_7' + DCN + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x8241e4, ''),
            ('FactoryProduct', '??_7' + FPN + '6B?$GuidItem@VInstance@RBX@@@1@@', 0x823fb4, '')):
        out[key] = check_vtable(network_obj, symbol, address, 0x82d884, own_class)
    out['EnumDesc_PhysicsSendMethod'] = check_vtable(network_obj, '??_7' + EDS + '6B@', 0x8240b8)
    out['EnumDesc_PhysicsReceiveMethod'] = check_vtable(network_obj, '??_7' + EDR + '6B@', 0x8240c4)
    assert out['NetworkSettings'][2]['original'] == '00409e60', out['NetworkSettings'][2]
    return out

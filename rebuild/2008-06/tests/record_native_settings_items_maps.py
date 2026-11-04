"""Rows and binding maps for tests/record_native_settings_items.py (not a recorder; imported by it).

EXTERNAL: call/data targets outside the rows proven here, each the address the original instruction uses (read at
the call sites of the listed rows). FOLDED: bodies this unit emits that the original keeps once (ICF / COMDAT).
DATA: descriptor objects and statics the original pushes. UNPROVEN: targets whose own rows are not exact here.
"""

# ---- names ------------------------------------------------------------------------------------------------------
FPG = '?$FactoryProduct@VGameSettings@RBX@@VItem@GlobalSettings@2@$1?sGameSettings@2@3QBDB@RBX@@'
DCG = '?$DescribedCreatable@VGameSettings@RBX@@VItem@GlobalSettings@2@$1?sGameSettings@2@3QBDB@RBX@@'
GSG = '?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGameSettings@2@3QBDB@RBX@@'
DSG = '?$Described@VGameSettings@RBX@@$1?sGameSettings@2@3QBDBV' + FPG[:-6] + '@2@@Reflection@RBX@@'
FPD = '?$FactoryProduct@VDebugSettings@RBX@@VItem@GlobalSettings@2@$1?sDebugSettings@2@3QBDB@RBX@@'
DCD = '?$DescribedCreatable@VDebugSettings@RBX@@VItem@GlobalSettings@2@$1?sDebugSettings@2@3QBDB@RBX@@'
GSD = '?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDebugSettings@2@3QBDB@RBX@@'
DSD = '?$Described@VDebugSettings@RBX@@$1?sDebugSettings@2@3QBDBV' + FPD[:-6] + '@2@@Reflection@RBX@@'
EDE = '?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@@Reflection@RBX@@'
EDA = '?$EnumDesc@W4AssertAction@Debugable@RBX@@@Reflection@RBX@@'
EDT = '?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@RBX@@'
DS = 'DebugSettings@RBX@@'
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'
STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'


def thunks(prefix, cls, kind, table):
    """??_E adjustor thunks: (address, offset code) -> rows."""
    return [(address, '??_E' + cls + kind + code + '@AEPAXI@Z') for address, code in table]


# (property, initializer, atexit) in definition order; the atexit address is the one each initializer pushes.
GAME_PROPS = [('FunnyPhysics', 0x7f5560, 0x7fe640), ('ChatHistory', 0x7f5590, 0x7fe620),
              ('ChatScrollLength', 0x7f55c0, 0x7fe600), ('SoundEnabled', 0x7f55f0, 0x7fe5c0),
              ('SoftwareSound', 0x7f5620, 0x7fe5e0)]
DEBUG_PROPS = [('ShaderModel', 0x7f2c30, 0x7fceb0), ('VideoMemory', 0x7f2c60, 0x7fce90), ('CpuSpeed', 0x7f2c90, 0x7fce70),
               ('CpuCount', 0x7f2cc0, 0x7fccd0), ('OsPlatformId', 0x7f2cf0, 0x7fccf0), ('OsVer', 0x7f2d20, 0x7fcef0),
               ('SystemProductName', 0x7f2d50, 0x7fced0), ('GlVendor', 0x7f2d80, 0x7fcd10), ('GfxCard', 0x7f2db0, 0x7fcd30),
               ('CPU', 0x7f2de0, 0x7fcd50), ('RAM', 0x7f2e10, 0x7fcd70), ('Resolution', 0x7f2e40, 0x7fcd90),
               ('SoundWarnings', 0x7f2e70, 0x7fcf30), ('StackTracingEnabled', 0x7f2ea0, 0x7fcf10),
               ('IoEnabled', 0x7f2ed0, 0x7fcdb0), ('ShowAnchors', 0x7f2f00, 0x7fcdf0), ('ShowPartCoords', 0x7f2f40, 0x7fcdd0),
               ('ShowUnalignedParts', 0x7f2f80, 0x7fcc10), ('ShowModelCoords', 0x7f2fc0, 0x7fcc30),
               ('ShowWorldCoords', 0x7f3000, 0x7fcc50), ('30FpsThrottle', 0x7f3080, 0x7fcc70),
               ('DistributedPhysics', 0x7f30c0, 0x7fcc90), ('ProfilerWindow', 0x7f3100, 0x7fcf70),
               ('ProfilerBucketTimeSpan', 0x7f3140, 0x7fcf50), ('ValidatingDebug', 0x7f3180, 0x7fccb0),
               ('AssertAction', 0x7f31c0, 0x7fce50), ('ErrorReporting', 0x7f3200, 0x7fce30)]
DEBUG_PENDING_PROPS = [('PhysicsEnviromentalThrottle', 0x7f3040, 0x7fce10)]


def props(table):
    return [(init, '??__Eprop_%s@RBX@@YAXXZ' % n) for n, init, _ in table] + \
           [(fin, '??__Fprop_%s@RBX@@YAXXZ' % n) for n, _, fin in table]


LAYOUT_ROWS = [
    (0x407820, '??$create@VDebugSettings@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VDebugSettings@RBX@@@boost@@XZ'),
    (0x407450, '??$?0VDebugSettings@RBX@@' + DLR + '1@@?$shared_ptr@VDebugSettings@RBX@@@boost@@QAE@PAVDebugSettings@RBX@@' + DLR + '3@@Z'),
]
GAME_ROWS = [
    (0x5bf0d0, '??1' + FPG + 'MAE@XZ'),
    (0x5bf180, '??0' + FPG + 'IAE@XZ'),
    (0x5bf560, '??_G' + FPG + 'MAEPAXI@Z'),
    (0x5bf1e0, '??1' + DSG + 'UAE@XZ'),
    (0x5bf1f0, '??1' + GSG + 'MAE@XZ'),
    (0x5bf7e0, '??_GGameSettings@RBX@@UAEPAXI@Z'),
    (0x5bf260, '?getClassName@' + FPG + 'UBEABVName@2@XZ'),
    (0x5bf280, '?classDescriptor@' + DSG + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bf2f0, '??$?0VGameSettings@RBX@@@?$BoundProp@_N$00@'),
    (0x5bf3c0, '??$?0VGameSettings@RBX@@@?$BoundProp@H$00@'),
    (0x5bf490, '??0' + DCG + 'IAE@XZ'),
    (0x5bf580, '??0' + GSG + 'IAE@XZ'),
    (0x5bf680, '??0GameSettings@RBX@@QAE@XZ'),
    (0x44a0e0, '??$doDeclare@$1?sGameSettings@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x44a8b0, '??$callDoDeclare@$1?sGameSettings@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x7fe660, '??__Ffoo@?1??classDescriptor@' + DSG),
    (0x44bee0, '?singleton@' + GSG + 'SAAAVGameSettings@2@XZ'),
    (0x44bdc0, '??$create@VGameSettings@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VGameSettings@RBX@@@boost@@XZ'),
    (0x44b850, '??$?0VGameSettings@RBX@@' + DLR + '1@@?$shared_ptr@VGameSettings@RBX@@@boost@@QAE@PAVGameSettings@RBX@@' + DLR + '3@@Z'),
] + thunks('', FPG, 'O', [(0x5bf130, 'CE'), (0x5bf140, 'EE'), (0x5bf150, 'GE'), (0x5bf160, 'KE'), (0x5bf170, 'BE'),
                          (0x5bf530, 'IE'), (0x5bf540, 'ME'), (0x5bf550, 'BA')]) \
  + thunks('', 'GameSettings@RBX@@', 'W', [(0x5bf770, 'CE'), (0x5bf780, 'EE'), (0x5bf790, 'GE'), (0x5bf250, 'IE'),
                                          (0x5bf7a0, 'KE'), (0x5bf7b0, 'ME'), (0x5bf7c0, 'BA'), (0x5bf7d0, 'BE')]) \
  + props(GAME_PROPS)

DEBUG_ROWS = [
    (0x563b40, '??1' + FPD + 'MAE@XZ'),
    (0x563be0, '??0' + FPD + 'IAE@XZ'),
    (0x565590, '??_G' + FPD + 'MAEPAXI@Z'),
    (0x564040, '??1' + DSD + 'UAE@XZ'),
    (0x5640a0, '??1' + GSD + 'MAE@XZ'),
    (0x565bd0, '??_GDebugSettings@RBX@@UAEPAXI@Z'),
    (0x564150, '?getClassName@' + FPD + 'UBEABVName@2@XZ'),
    (0x564ee0, '?classDescriptor@' + DSD + 'SAAAVClassDescriptor@23@XZ'),
    (0x5654b0, '??0' + DCD + 'IAE@XZ'),
    (0x5655b0, '??0' + GSD + 'IAE@XZ'),
    (0x565ac0, '??0DebugSettings@RBX@@QAE@XZ'),
    (0x406700, '??$doDeclare@$1?sDebugSettings@RBX@@3QBDB@Name@RBX@@CAABV01@XZ'),
    (0x406e80, '??$callDoDeclare@$1?sDebugSettings@RBX@@3QBDB@Name@RBX@@CAXXZ'),
    (0x7fcf90, '??__Ffoo@?1??classDescriptor@' + DSD),
    # accessors
    (0x563100, '?getValidatingDebug@' + DS), (0x565d70, '?setValidatingDebug@' + DS),
    (0x563110, '?getAssertAction@' + DS), (0x565da0, '?setAssertAction@' + DS),
    (0x563120, '?getShowAnchoredParts@' + DS), (0x565bf0, '?setShowAnchoredParts@' + DS),
    (0x563130, '?getShowUnalignedParts@' + DS), (0x565c20, '?setShowUnalignedParts@' + DS),
    (0x563140, '?getShowPartCoordinateFrames@' + DS), (0x565c50, '?setShowPartCoordinateFrames@' + DS),
    (0x445220, '?getErrorReporting@' + DS),   # ICF-shared getter body (also NetworkSettings::getPhysicsSendMethod)
    (0x565dd0, '?setErrorReporting@' + DS),
    # descriptor plumbing
    (0x563a80, '??$getset@P8DebugSettings@RBX@@BE_NXZP812@AEX_N@Z@'),
    (0x563d10, '??$getset@P8DebugSettings@RBX@@BEMXZ@'),
    (0x563d50, '??$getset@P8DebugSettings@RBX@@BEHXZ@'),
    (0x563d90, '??$getset@P8DebugSettings@RBX@@BE?AV?$basic_string@'),
    (0x563e20, '??$getset@P8DebugSettings@RBX@@BENXZP812@AEXN@Z@'),
    (0x563e70, '??$getset@P8DebugSettings@RBX@@BE?AW4AssertAction@'),
    (0x563ec0, '??$getset@P8DebugSettings@RBX@@BE?AW4ErrorReporting@'),
    (0x563ad0, '?setValue@?$GetSetImpl@P8DebugSettings@RBX@@BENXZ'),
    (0x563b00, '?setValue@?$GetSetImpl@P8DebugSettings@RBX@@BE?AW4ErrorReporting@'),
    (0x563c60, '??0?$TypedPropertyDescriptor@N@Reflection@RBX@@IAE@'),
    (0x564f50, '??$?0P8DebugSettings@RBX@@BEMXZH@?$PropDescriptor@VDebugSettings@RBX@@M@'),
    (0x564ff0, '??$?0P8DebugSettings@RBX@@BEHXZH@?$PropDescriptor@VDebugSettings@RBX@@H@'),
    (0x565090, '??$?0P8DebugSettings@RBX@@BE?AV?$basic_string@'),
    (0x565130, '??$?0VDebugSettings@RBX@@@?$BoundProp@_N$00@'),
    (0x565200, '??$?0P8DebugSettings@RBX@@BE_NXZP801@AEX_N@Z@?$PropDescriptor@VDebugSettings@RBX@@_N@'),
    (0x5652b0, '??$?0P8DebugSettings@RBX@@BENXZP801@AEXN@Z@?$PropDescriptor@VDebugSettings@RBX@@N@'),
    # EnumDesc<ErrorReporting>, EnumDesc<Debugable::AssertAction>
    (0x564a60, '??0' + EDE + 'AAE@XZ'), (0x564d70, '??0' + EDA + 'AAE@XZ'),
    (0x564550, '??1' + EDE + 'EAE@XZ'), (0x564870, '??1' + EDA + 'EAE@XZ'),
    (0x564a00, '??_G' + EDE + 'EAEPAXI@Z'), (0x564a40, '??_G' + EDA + 'EAEPAXI@Z'),
    (0x565360, '?singleton@' + EDE + 'SAABV123@XZ'), (0x565440, '?singleton@' + EDA + 'SAABV123@XZ'),
    (0x7fcfc0, '??__Fs@?1??singleton@' + EDE), (0x7fcfa0, '??__Fs@?1??singleton@' + EDA),
    (0x5642c0, '?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@'
                'V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAE?AViterator@'),
    (0x5644a0, '??A?$map@PBVName@RBX@@W4ErrorReporting@'),
] + thunks('', FPD, 'O', [(0x563ba0, 'CE'), (0x563bb0, 'EE'), (0x563bc0, 'GE'), (0x563bd0, 'BE'), (0x565550, 'BA'),
                          (0x565560, 'IE'), (0x565570, 'KE'), (0x565580, 'ME')]) \
  + thunks('', 'DebugSettings@RBX@@', 'W', [(0x564100, 'CE'), (0x564110, 'EE'), (0x564120, 'IE'), (0x564130, 'ME'),
                                           (0x564140, 'BE'), (0x565ba0, 'GE'), (0x565bb0, 'KE'), (0x565bc0, 'BA')]) \
  + props(DEBUG_PROPS)

DEBUG_PENDING_ROWS = [
    (0x563150, '?getShowModelCoordinateFrames@' + DS), (0x565c80, '?setShowModelCoordinateFrames@' + DS),
    (0x5631b0, '?getEnvironmentalThrottle@' + DS), (0x565d40, '?setEnvironmentalThrottle@' + DS),
    (0x563dd0, '??$getset@P8DebugSettings@RBX@@BE?AW4EThrottle@'),
    (0x564be0, '??0' + EDT + 'AAE@XZ'), (0x5646e0, '??1' + EDT + 'EAE@XZ'), (0x564a20, '??_G' + EDT + 'EAEPAXI@Z'),
    (0x5653d0, '?singleton@' + EDT + 'SAABV123@XZ'), (0x7fcfb0, '??__Fs@?1??singleton@' + EDT),
] + props(DEBUG_PENDING_PROPS)

# ---- generated header copies (pending build only) -----------------------------------------------------------------
# Proposed declarations for v8world/World.h (engine owner): the 2008 EnumDesc<World::EThrottle> 00564be0 registers
# "EnviromentalPhysicsThrottle" with DefaultAuto 0, Disabled 1, Random 2, Always 3 (strings 0082e358..0082e33c,
# type_info 009452a0), and the DebugSettings accessors 005631b0/00565d40 read/write the int static at 0097ac54. The
# static's name is provisional.
PROPOSAL_WORLD_ANCHOR = '''		static bool disableEnvironmentalThrottle;
'''
PROPOSAL_WORLD = '''		enum EThrottle
		{
			DefaultAuto,
			Disabled,
			Random,
			Always
		};
		static EThrottle environmentalThrottle;
'''
# v8datamodel/Camera.h (donor, pulled in by the native ModelInstance.h): the 2008 DescribedCreatable takes const char*
# (same copy as tests/record_native_appearance.py).
CAMERA_FIX = (('extern const char* sCamera;', 'extern char sCamera[];'),
              ('DescribedCreatable<Camera, Instance, &sCamera>', 'DescribedCreatable<Camera, Instance, sCamera>'))

# ---- vtables (key, unit, compiled symbol, original address, own class, inherited-slot reference) ---------------------
GI = '6B?$GuidItem@VInstance@RBX@@@1@@'
VTABLES = [
    ('GameSettings', 'game', '??_7GameSettings@RBX@@' + GI, 0x838774, 'GameSettings', 0x82d884),
    ('GameSettings_GlobalSettingsItem', 'game', '??_7' + GSG + GI, 0x8385f4, '', 0x82d884),
    ('GameSettings_DescribedCreatable', 'game', '??_7' + DCG + GI, 0x8386b4, '', 0x82d884),
    ('GameSettings_FactoryProduct', 'game', '??_7' + FPG + GI, 0x838534, '', 0x82d884),
    ('DebugSettings', 'debug', '??_7DebugSettings@RBX@@' + GI, 0x82e6e4, 'DebugSettings', 0x82d884),
    ('DebugSettings_GlobalSettingsItem', 'debug', '??_7' + GSD + GI, 0x82e2ac, '', 0x82d884),
    ('DebugSettings_DescribedCreatable', 'debug', '??_7' + DCD + GI, 0x82e534, '', 0x82d884),
    ('DebugSettings_FactoryProduct', 'debug', '??_7' + FPD + GI, 0x82e1a4, '', 0x82d884),
]

# ---- binding maps -------------------------------------------------------------------------------------------------
EXTERNAL = {
    '??$singleton@N@Type@Reflection@RBX@@SAABV012@XZ': 0x56cd10,   # evidence ??$singleton@N@Type@Reflection@RBX@@SAAB; target in ??0?$TypedPropertyDescriptor@N@Reflection@RBX@@IAE
    '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,   # evidence ??0?$TypedPropertyDescriptor@_N@Reflecti; target in ??$?0P8DebugSettings@RBX@@BEHXZH@?$PropDescriptor@
    '??0?$TypedPropertyDescriptor@M@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@M@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x445610,   # evidence ??0?$TypedPropertyDescriptor@M@Reflectio; target in ??$?0P8DebugSettings@RBX@@BEMXZH@?$PropDescriptor@
    '??0?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x443230,   # evidence ??0?$TypedPropertyDescriptor@V?$basic_st; target in ??$?0P8DebugSettings@RBX@@BE?AV?$basic_string@DU?$
    '??0?$TypedPropertyDescriptor@_N@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedPropertyDescriptor@_N@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x40a290,   # evidence ??0?$TypedPropertyDescriptor@_N@Reflecti; target in ??$?0P8DebugSettings@RBX@@BE_NXZP801@AEX_N@Z@?$Pro
    '??0?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4AssertAction@Debugable@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4AssertAction@Debugable@2@@std@@@6@$0A@@std@@@std@@QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4AssertAction@Debugable@2@@std@@@1@@Z': 0x446110,   # evidence ??0?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??0?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '??0?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4EThrottle@World@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4EThrottle@World@2@@std@@@6@$0A@@std@@@std@@QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4EThrottle@World@2@@std@@@1@@Z': 0x446110,   # evidence ??0?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??0?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@R
    '??0?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAE@ABU?$less@PBVName@RBX@@@1@ABV?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@1@@Z': 0x446110,   # evidence ??0?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??0?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@
    '??0ClassDescriptor@Reflection@RBX@@QAE@AAV012@PBD@Z': 0x5708f0,   # target in ?classDescriptor@?$Described@VDebugSettings@RBX@@$
    '??0EnumDescriptor@Reflection@RBX@@IAE@PBDABVtype_info@@@Z': 0x56c590,   # evidence ??0EnumDescriptor@Reflection@RBX@@IAE@PB; target in ??0?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '??0Item@GlobalSettings@RBX@@QAE@XZ': 0x409e00,   # target in ??0?$FactoryProduct@VDebugSettings@RBX@@VItem@Glob
    '??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z': 0x56c650,   # evidence ??0PropertyDescriptor@Reflection@RBX@@IA; target in ??0?$TypedPropertyDescriptor@N@Reflection@RBX@@IAE
    '??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z': 0x409d50,   # evidence ??0runtime_error@std@@QAE@ABV?$basic_str; target in ??0?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDe
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4AssertAction@Debugable@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4AssertAction@Debugable@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,   # evidence ??1?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??1?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4EThrottle@World@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4EThrottle@World@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,   # evidence ??1?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??1?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@R
    '??1?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAE@XZ': 0x553d80,   # evidence ??1?$_Tree@V?$_Tmap_traits@W4Number@Bric; target in ??1?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@
    '??1ClassDescriptor@Reflection@RBX@@UAE@XZ': 0x40abc0,   # evidence ??1ClassDescriptor@Reflection@RBX@@UAE@X; target in ??__Ffoo@?1??classDescriptor@?$Described@VDebugSet
    '??1EnumDescriptor@Reflection@RBX@@MAE@XZ': 0x56c080,   # target in ??1?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '??1Instance@RBX@@UAE@XZ': 0x55a540,   # evidence ??1Instance@RBX@@MAE@XZ; target in ??1?$FactoryProduct@VDebugSettings@RBX@@VItem@Glob
    '??8const_iterator@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QBE_NABV012@@Z': 0x5ecca0,   # evidence ??8const_iterator@?$_Tree@V?$_Tmap_trait; target in ?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4Err
    '?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAEXXZ': 0x609bd0,   # evidence ?_Dec@const_iterator@?$_Tree@V?$_Tset_tr; target in ?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4Err
    '?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAEXXZ': 0x68dfa0,   # evidence ?_Inc@const_iterator@?$_Tree@V?$_Tmap_tr; target in ?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4Err
    '?_Insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@2@ABU?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@2@@Z': 0x668010,   # evidence ?_Insert@?$_Tree@V?$_Tmap_traits@PAVPrim; target in ?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4Err
    '?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ': 0x4077d0,   # evidence ?_Tidy@?$vector@V?$basic_string@DU?$char; target in ??1?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '?addPair@?$EnumDesc@W4AssertAction@Debugable@RBX@@@Reflection@RBX@@AAEXW4AssertAction@Debugable@3@PBD@Z': 0x64d530,   # evidence ?addPair@?$EnumDesc@W4BinType@HopperBin@; target in ??0?$EnumDesc@W4AssertAction@Debugable@RBX@@@Refle
    '?addPair@?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@RBX@@AAEXW4EThrottle@World@3@PBD@Z': 0x64d530,   # evidence ?addPair@?$EnumDesc@W4BinType@HopperBin@; target in ??0?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@R
    '?addPair@?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@@Reflection@RBX@@AAEXW4ErrorReporting@DebugSettings@3@PBD@Z': 0x64d530,   # evidence ?addPair@?$EnumDesc@W4BinType@HopperBin@; target in ??0?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,   # target in ?getClassName@?$FactoryProduct@VDebugSettings@RBX@
    '?classDescriptor@?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x40ad80,   # evidence ?classDescriptor@?$Described@VInstance@R; target in ?classDescriptor@?$Described@VDebugSettings@RBX@@$
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,   # evidence ?declare@Name@RBX@@SAABV12@PBDH@Z; target in ??$doDeclare@$1?sDebugSettings@RBX@@3QBDB@Name@RBX
    '?do_lock@recursive_mutex@boost@@AAEXXZ': 0x563090,   # target in ?singleton@?$GlobalSettingsItem@VGameSettings@RBX@
    '?do_unlock@recursive_mutex@boost@@AAEXXZ': 0x5630e0,   # target in ?singleton@?$GlobalSettingsItem@VGameSettings@RBX@
    '?format@G3D@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PBDZZ': 0x509b10,   # target in ??0?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDe
    '?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4ErrorReporting@DebugSettings@2@U?$less@PBVName@RBX@@@std@@V?$allocator@U?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@std@@@6@$0A@@std@@@std@@_N@2@ABU?$pair@QBVName@RBX@@W4ErrorReporting@DebugSettings@2@@2@@Z': 0x681a50,   # evidence ?insert@?$_Tree@V?$_Tmap_traits@PBVName@; target in ?insert@?$_Tree@V?$_Tmap_traits@PBVName@RBX@@W4Err
    '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 0x40db00,   # evidence ?raisePropertyChanged@Instance@RBX@@QAEX; target in ?setAssertAction@DebugSettings@RBX@@QAEXW4AssertAc
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,   # evidence ?setName@Instance@RBX@@UAEXABV?$basic_st; target in ??0?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDe
    '?setParent@Instance@RBX@@QAEXPAV12@@Z': 0x55a8f0,   # evidence ?setParent@Instance@RBX@@QAEXPAV12@@Z; target in ?singleton@?$GlobalSettingsItem@VGameSettings@RBX@
    '?singleton@GlobalSettings@RBX@@SA?AV?$shared_ptr@VGlobalSettings@RBX@@@boost@@XZ': 0x5690f0,   # evidence ?singleton@GlobalSettings@RBX@@SA?AV?$sh; target in ?singleton@?$GlobalSettingsItem@VGameSettings@RBX@
    '_atexit': 0x6a17af,   # target in ??__Eprop_30FpsThrottle@RBX@@YAXXZ
}
DATA = {
    '?assertAction@Debugable@RBX@@2W4AssertAction@12@A': 0x94627c,   # pushed in ?getAssertAction@DebugSettings@RBX@@QBE?AW4AssertA
    '?environmentalThrottle@World@RBX@@2W4EThrottle@12@A': 0x97ac54,   # pushed in ?getEnvironmentalThrottle@DebugSettings@RBX@@QBE?A
    '?mutex@GlobalSettings@RBX@@2Vrecursive_mutex@boost@@A': 0x974aa0,   # pushed in ?singleton@?$GlobalSettingsItem@VGameSettings@RBX@
    '?s@?1??singleton@?$EnumDesc@W4AssertAction@Debugable@RBX@@@Reflection@RBX@@SAABV234@XZ@4V234@A': 0x9743c0,   # pushed in ??__Fs@?1??singleton@?$EnumDesc@W4AssertAction@Deb
    '?s@?1??singleton@?$EnumDesc@W4EThrottle@World@RBX@@@Reflection@RBX@@SAABV234@XZ@4V234@A': 0x9742d0,   # pushed in ??__Fs@?1??singleton@?$EnumDesc@W4EThrottle@World@
    '?s@?1??singleton@?$EnumDesc@W4ErrorReporting@DebugSettings@RBX@@@Reflection@RBX@@SAABV234@XZ@4V234@A': 0x9741e0,   # pushed in ??__Fs@?1??singleton@?$EnumDesc@W4ErrorReporting@D
    '?sDebugSettings@RBX@@3QBDB': 0x82dfb8,   # pushed in ??$doDeclare@$1?sDebugSettings@RBX@@3QBDB@Name@RBX
    '?sGameSettings@RBX@@3QBDB': 0x838478,   # pushed in ??$doDeclare@$1?sGameSettings@RBX@@3QBDB@Name@RBX@
    '?showAnchoredParts@PartInstance@RBX@@2_NA': 0x975f8c,   # pushed in ?getShowAnchoredParts@DebugSettings@RBX@@QBE_NXZ
    '?showModelCoord@ModelInstance@RBX@@2_NA': 0x9753d9,   # pushed in ?getShowModelCoordinateFrames@DebugSettings@RBX@@Q
    '?showPartCoord@PartInstance@RBX@@2_NA': 0x975f8d,   # pushed in ?getShowPartCoordinateFrames@DebugSettings@RBX@@QB
    '?showUnalignedParts@PartInstance@RBX@@2_NA': 0x975f8e,   # pushed in ?getShowUnalignedParts@DebugSettings@RBX@@QBE_NXZ
    '?sing@?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDebugSettings@2@3QBDB@RBX@@0PAV12@A': 0x96c318,   # pushed in ??0?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDe
    '?sing@?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGameSettings@2@3QBDB@RBX@@0PAV12@A': 0x96dd10,   # pushed in ??0?$GlobalSettingsItem@VGameSettings@RBX@@$1?sGam
    '?validatingDebug@Debugable@RBX@@2_NA': 0x974ac0,   # pushed in ?getValidatingDebug@DebugSettings@RBX@@QBE_NXZ
    '__TI2?AVruntime_error@std@@': 0x8d1bc8,   # pushed in ??0?$GlobalSettingsItem@VDebugSettings@RBX@@$1?sDe
    '_prop_30FpsThrottle': 0x9746fc,   # pushed in ??__Eprop_30FpsThrottle@RBX@@YAXXZ
    '_prop_AssertAction': 0x974630,   # pushed in ??__Eprop_AssertAction@RBX@@YAXXZ
    '_prop_CPU': 0x9747c8,   # pushed in ??__Eprop_CPU@RBX@@YAXXZ
    '_prop_ChatHistory': 0x977750,   # pushed in ??__Eprop_ChatHistory@RBX@@YAXXZ
    '_prop_ChatScrollLength': 0x977734,   # pushed in ??__Eprop_ChatScrollLength@RBX@@YAXXZ
    '_prop_CpuCount': 0x974718,   # pushed in ??__Eprop_CpuCount@RBX@@YAXXZ
    '_prop_CpuSpeed': 0x974734,   # pushed in ??__Eprop_CpuSpeed@RBX@@YAXXZ
    '_prop_DistributedPhysics': 0x9745f8,   # pushed in ??__Eprop_DistributedPhysics@RBX@@YAXXZ
    '_prop_ErrorReporting': 0x97476c,   # pushed in ??__Eprop_ErrorReporting@RBX@@YAXXZ
    '_prop_FunnyPhysics': 0x9776e0,   # pushed in ??__Eprop_FunnyPhysics@RBX@@YAXXZ
    '_prop_GfxCard': 0x974518,   # pushed in ??__Eprop_GfxCard@RBX@@YAXXZ
    '_prop_GlVendor': 0x9746e0,   # pushed in ??__Eprop_GlVendor@RBX@@YAXXZ
    '_prop_IoEnabled': 0x974614,   # pushed in ??__Eprop_IoEnabled@RBX@@YAXXZ
    '_prop_OsPlatformId': 0x97468c,   # pushed in ??__Eprop_OsPlatformId@RBX@@YAXXZ
    '_prop_OsVer': 0x9746c4,   # pushed in ??__Eprop_OsVer@RBX@@YAXXZ
    '_prop_PhysicsEnviromentalThrottle': 0x9744f4,   # pushed in ??__Eprop_PhysicsEnviromentalThrottle@RBX@@YAXXZ
    '_prop_ProfilerBucketTimeSpan': 0x974654,   # pushed in ??__Eprop_ProfilerBucketTimeSpan@RBX@@YAXXZ
    '_prop_ProfilerWindow': 0x9745c0,   # pushed in ??__Eprop_ProfilerWindow@RBX@@YAXXZ
    '_prop_RAM': 0x974550,   # pushed in ??__Eprop_RAM@RBX@@YAXXZ
    '_prop_Resolution': 0x974670,   # pushed in ??__Eprop_Resolution@RBX@@YAXXZ
    '_prop_ShaderModel': 0x9745a4,   # pushed in ??__Eprop_ShaderModel@RBX@@YAXXZ
    '_prop_ShowAnchors': 0x9747ac,   # pushed in ??__Eprop_ShowAnchors@RBX@@YAXXZ
    '_prop_ShowModelCoords': 0x9744bc,   # pushed in ??__Eprop_ShowModelCoords@RBX@@YAXXZ
    '_prop_ShowPartCoords': 0x9745dc,   # pushed in ??__Eprop_ShowPartCoords@RBX@@YAXXZ
    '_prop_ShowUnalignedParts': 0x974588,   # pushed in ??__Eprop_ShowUnalignedParts@RBX@@YAXXZ
    '_prop_ShowWorldCoords': 0x9746a8,   # pushed in ??__Eprop_ShowWorldCoords@RBX@@YAXXZ
    '_prop_SoftwareSound': 0x9776fc,   # pushed in ??__Eprop_SoftwareSound@RBX@@YAXXZ
    '_prop_SoundEnabled': 0x977718,   # pushed in ??__Eprop_SoundEnabled@RBX@@YAXXZ
    '_prop_SoundWarnings': 0x9744d8,   # pushed in ??__Eprop_SoundWarnings@RBX@@YAXXZ
    '_prop_StackTracingEnabled': 0x97456c,   # pushed in ??__Eprop_StackTracingEnabled@RBX@@YAXXZ
    '_prop_SystemProductName': 0x974750,   # pushed in ??__Eprop_SystemProductName@RBX@@YAXXZ
    '_prop_ValidatingDebug': 0x974534,   # pushed in ??__Eprop_ValidatingDebug@RBX@@YAXXZ
    '_prop_VideoMemory': 0x974790,   # pushed in ??__Eprop_VideoMemory@RBX@@YAXXZ
}
UNPROVEN = {  # targets whose rows are not exact here (not attempted, or pending-build-only)
    '??$?0P8DebugSettings@RBX@@BE?AW4AssertAction@Debugable@1@XZP801@AEXW4231@@Z@?$EnumPropDescriptor@VDebugSettings@RBX@@W4AssertAction@Debugable@2@@Reflection@RBX@@QAE@PBD0P8DebugSettings@2@BE?AW4AssertAction@Debugable@2@XZP832@AEXW4452@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x565790,   # target in ??__Eprop_AssertAction@RBX@@YAXXZ
    '??$?0P8DebugSettings@RBX@@BE?AW4EThrottle@World@1@XZP801@AEXW4231@@Z@?$EnumPropDescriptor@VDebugSettings@RBX@@W4EThrottle@World@2@@Reflection@RBX@@QAE@PBD0P8DebugSettings@2@BE?AW4EThrottle@World@2@XZP832@AEXW4452@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x5656b0,   # target in ??__Eprop_PhysicsEnviromentalThrottle@RBX@@YAXXZ
    '??$?0P8DebugSettings@RBX@@BE?AW4ErrorReporting@01@XZP801@AEXW4201@@Z@?$EnumPropDescriptor@VDebugSettings@RBX@@W4ErrorReporting@12@@Reflection@RBX@@QAE@PBD0P8DebugSettings@2@BE?AW4ErrorReporting@32@XZP832@AEXW4432@@ZW4Functionality@PropertyDescriptor@12@@Z': 0x565870,   # target in ??__Eprop_ErrorReporting@RBX@@YAXXZ
    '??$?0PAVDebugSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVDebugSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x406ed0,   # target in ??$?0VDebugSettings@RBX@@VDeleter@?$Creatable@VIns
    '??$?0PAVGameSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@1@@shared_count@detail@boost@@QAE@PAVGameSettings@RBX@@VDeleter@?$Creatable@VInstance@RBX@@@4@@Z': 0x44a8c0,   # target in ??$?0VGameSettings@RBX@@VDeleter@?$Creatable@VInst
    '?cpu@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x5638c0,   # target in ??__Eprop_CPU@RBX@@YAXXZ
    '?cpuCount@DebugSettings@RBX@@QBEHXZ': 0x563290,   # target in ??__Eprop_CpuCount@RBX@@YAXXZ
    '?cpuSpeed@DebugSettings@RBX@@QBEHXZ': 0x563260,   # target in ??__Eprop_CpuSpeed@RBX@@YAXXZ
    '?get30FpsThrottle@DebugSettings@RBX@@QBE_NXZ': 0x5631a0,   # target in ??__Eprop_30FpsThrottle@RBX@@YAXXZ
    '?getDistributedPhysics@DebugSettings@RBX@@QBE_NXZ': 0x563190,   # target in ??__Eprop_DistributedPhysics@RBX@@YAXXZ
    '?getProfilerBucketTimeSpan@DebugSettings@RBX@@QBENXZ': 0x563180,   # target in ??__Eprop_ProfilerBucketTimeSpan@RBX@@YAXXZ
    '?getProfilerWindow@DebugSettings@RBX@@QBENXZ': 0x563170,   # target in ??__Eprop_ProfilerWindow@RBX@@YAXXZ
    '?getShowModelCoordinateFrames@DebugSettings@RBX@@QBE_NXZ': 0x563150,   # target in ??__Eprop_ShowModelCoords@RBX@@YAXXZ
    '?getShowWorldCoordinateFrames@DebugSettings@RBX@@QBE_NXZ': 0x563160,   # target in ??__Eprop_ShowWorldCoords@RBX@@YAXXZ
    '?gfxcard@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x5634b0,   # target in ??__Eprop_GfxCard@RBX@@YAXXZ
    '?glVendor@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x563430,   # target in ??__Eprop_GlVendor@RBX@@YAXXZ
    '?osPlatformId@DebugSettings@RBX@@QBEHXZ': 0x563330,   # evidence ?osPlatformId@DebugSettings@RBX@@QBEHXZ; target in ??__Eprop_OsPlatformId@RBX@@YAXXZ
    '?osVer@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x5632c0,   # evidence ?osVer@DebugSettings@RBX@@QBE?AV?$basic_; target in ??__Eprop_OsVer@RBX@@YAXXZ
    '?ram@DebugSettings@RBX@@QBEHXZ': 0x563940,   # target in ??__Eprop_RAM@RBX@@YAXXZ
    '?resolution@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x563970,   # target in ??__Eprop_Resolution@RBX@@YAXXZ
    '?set30FpsThrottle@DebugSettings@RBX@@QAEX_N@Z': 0x565d10,   # target in ??__Eprop_30FpsThrottle@RBX@@YAXXZ
    '?setDistributedPhysics@DebugSettings@RBX@@QAEX_N@Z': 0x565ce0,   # target in ??__Eprop_DistributedPhysics@RBX@@YAXXZ
    '?setProfilerBucketTimeSpan@DebugSettings@RBX@@QAEXN@Z': 0x563a20,   # target in ??__Eprop_ProfilerBucketTimeSpan@RBX@@YAXXZ
    '?setProfilerWindow@DebugSettings@RBX@@QAEXN@Z': 0x5639f0,   # target in ??__Eprop_ProfilerWindow@RBX@@YAXXZ
    '?setShowModelCoordinateFrames@DebugSettings@RBX@@QAEX_N@Z': 0x565c80,   # target in ??__Eprop_ShowModelCoords@RBX@@YAXXZ
    '?setShowWorldCoordinateFrames@DebugSettings@RBX@@QAEX_N@Z': 0x565cb0,   # target in ??__Eprop_ShowWorldCoords@RBX@@YAXXZ
    '?shaderModel@DebugSettings@RBX@@QBEMXZ': 0x563a50,   # target in ??__Eprop_ShaderModel@RBX@@YAXXZ
    '?systemProductName@DebugSettings@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ': 0x563370,   # target in ??__Eprop_SystemProductName@RBX@@YAXXZ
    '?videoMemory@DebugSettings@RBX@@QBEHXZ': 0x563230,   # target in ??__Eprop_VideoMemory@RBX@@YAXXZ
}
FOLDED = {
}
NOT_ATTEMPTED = {
    '0044a8c0/00406ed0': 'boost::detail::shared_count(GameSettings*/DebugSettings*, Creatable<Instance>::Deleter) (110 '
                         'bytes): the 2008 boost form (try/catch, no bad_alloc check) differs from the donor boost 1.34.1 '
                         'header (131 bytes); same finding as PhysicsService 004ca3c0',
    '005656b0/00565790/00565870': 'EnumPropDescriptor<DebugSettings, EThrottle/AssertAction/ErrorReporting> constructors: the '
                                  '2008 reflection.h constructor (call_once singleton twice, EnumDesc reference at +0x20) '
                                  'differs from the shared native header (same finding as NetworkSettings 004aa9a0)',
    '005653c0/00565430/005654a0': 'call_once wrappers of EnumDesc<E>::singleton (jmp 00565360 / 005653d0 / 00565440), emitted '
                                  'only by that 2008 constructor',
    '00565960/00565970': 'EnumPropDescriptor virtuals over the 2008 getset layout',
    '00563230/00563260/00563290/00563330/005632c0/00563370/00563430/005634b0/005638c0/00563940/00563970/00563a50/005631c0':
        '"Profile" getters (VideoMemory, CpuSpeed, CpuCount, OsPlatformId, OsVer, SystemProductName, GlVendor, GfxCard, '
        'CPU, RAM, Resolution, ShaderModel) and their 107-byte helper 005631c0 (constructed/destroyed around 00501ae0): '
        'need the 2008 render-spec / registry declarations, none in the native headers',
    '00563160/00565cb0': 'ShowWorldCoords accessors over the static at 00976899 (donor Workspace::showWorldCoord): the donor '
                         'Workspace.h does not compile under the native headers (Camera/RootInstance/Stats class-name '
                         'templates) and there is no native Workspace.h',
    '00563190/00565ce0/005631a0/00565d10': 'DistributedPhysics (00974e61) and 30FpsThrottle (00946790) accessors: the '
                                           'owning class of these statics is not identified',
    '00563170/00563180/005639f0/00563a20': 'ProfilerWindow / ProfilerBucketTimeSpan accessors over the Profiling statics '
                                           '0094f640 / 0094f638 (setters clamp with the constant 00827988): no native '
                                           'Profiler header',
    '00563ce0/00563f10/00563f60/00563ff0/00564050/00564170/005641e0/00564290': 'boost::any holder and '
        'TypedPropertyDescriptor virtual helpers emitted for the string/float/int/double descriptors (2008 reflection '
        'templates; not identified in this pass)',
    '00563c40/00563cd0': 'std::fill / allocator::max_size helpers (ICF-shared std bodies)',
    '007fcc00': 'atexit destroying a ClassDescriptor static at 00974028 (owner not identified)',
}

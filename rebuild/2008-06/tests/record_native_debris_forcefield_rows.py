"""ForceField rows, maps and checks for tests/record_native_debris_forcefield.py (2008-06, inactive)."""
import struct

FPF = '?$FactoryProduct@VForceField@RBX@@VInstance@2@$1?sForceField@2@3PADA@RBX@@'
DCF = '?$DescribedCreatable@VForceField@RBX@@VInstance@2@$1?sForceField@2@3PADA@RBX@@'
DSF = '?$Described@VForceField@RBX@@$1?sForceField@2@3PADAV' + FPF[:-6] + '@2@@Reflection@RBX@@'
DLR = 'VDeleter@?$Creatable@VInstance@RBX@@@'

FORCE_FACTORY = (0x5c1520, 0x148, 0x62d6b0)
FORCE_LAYOUT_NOTE = ('0x148 (005c1520); Instance, IRenderable +0x130 (index2d +0x134, index3d +0x138, bucket +0x13c), '
                     'rendered (bool) +0x140, sparkleCycle +0x144; class name "ForceField" (char[] 0095c3a8)')

# Layout probe rows (explicit Creatable<Instance>::create<ForceField> instantiation).
FORCE_LAYOUT_ROWS = [
    (0x5c1520, '??$create@VForceField@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VForceField@RBX@@@boost@@XZ'),
    (0x5c1470, '??$?0VForceField@RBX@@' + DLR + '1@@?$shared_ptr@VForceField@RBX@@@boost@@QAE@PAVForceField@RBX@@' + DLR + '3@@Z'),
]
# The ForceField unit built from the current headers.
FORCEFIELD_ROWS = [
    (0x62d0c0, '??1' + FPF + 'MAE@XZ'),
    (0x62d120, '??0' + FPF + 'IAE@XZ'),
    (0x62d180, '??_E' + FPF + 'OCE@AEPAXI@Z'),
    (0x62d190, '??_G' + FPF + 'MAEPAXI@Z'),
    (0x62d1b0, '??_E' + FPF + 'OGE@AEPAXI@Z'), (0x62d1c0, '??_E' + FPF + 'OIE@AEPAXI@Z'),
    (0x62d1d0, '??_E' + FPF + 'OKE@AEPAXI@Z'), (0x62d1e0, '??_E' + FPF + 'OBA@AEPAXI@Z'),
    (0x62d1f0, '??_E' + FPF + 'OBE@AEPAXI@Z'),
    (0x62d300, '??1' + DSF + 'UAE@XZ'),
    (0x62d3e0, '?getClassName@' + FPF + 'UBEABVName@2@XZ'),
    (0x62d5f0, '??0' + DCF + 'IAE@XZ'),
    (0x62d690, '??_E' + FPF + 'OEE@AEPAXI@Z'), (0x62d6a0, '??_E' + FPF + 'OME@AEPAXI@Z'),
    (0x62d6b0, '??0ForceField@RBX@@QAE@XZ'),
    (0x62d7a0, '??_EForceField@RBX@@WGE@AEPAXI@Z'), (0x62d7b0, '??_EForceField@RBX@@WIE@AEPAXI@Z'),
    (0x62d7c0, '??_EForceField@RBX@@WKE@AEPAXI@Z'), (0x62d7d0, '??_EForceField@RBX@@WME@AEPAXI@Z'),
    (0x62d7e0, '??_EForceField@RBX@@WBA@AEPAXI@Z'), (0x62d7f0, '??_EForceField@RBX@@WBE@AEPAXI@Z'),
    (0x62d800, '??_EForceField@RBX@@WCE@AEPAXI@Z'), (0x62d810, '??_EForceField@RBX@@WEE@AEPAXI@Z'),
    (0x62d820, '??1ForceField@RBX@@UAE@XZ'),
    (0x62d8d0, '??_GForceField@RBX@@UAEPAXI@Z'),
    (0x5c0400, '?classDescriptor@' + DSF + 'SAAAVClassDescriptor@23@XZ'),
    (0x5bf9c0, '??$doDeclare@$1?sForceField@RBX@@3PADA@Name@RBX@@CAABV01@XZ'),
    (0x5bffb0, '??$callDoDeclare@$1?sForceField@RBX@@3PADA@Name@RBX@@CAXXZ'),
    (0x7fe720, '??__Ffoo@?1??classDescriptor@' + DSF),
    # current complete 112-byte extent; isProtectedRecursive has its own 0062d380 extent
    (0x62d310, '?hasForceField@ForceField@RBX@@CA_NPAVInstance@2@@Z'),
]
# Trivial inline virtual bodies that the original folds with identical bodies elsewhere (ICF). Compared and bound so
# the vtable slots are proven, but recorded in their own group and not counted as recovered addresses.
FORCE_TRIVIAL_ROWS = [
    (0x565950, '?shouldRender3dAdorn@ForceField@RBX@@MBE_NXZ'),                         # mov al, 1; ret
    (0x60a2f0, '?shouldRender2d@IRenderable@RBX@@MBE_NXZ'),                             # xor al, al; ret
    (0x70bdf0, '?render2d@IRenderable@RBX@@UAEXPAVAdorn@2@@Z'),                         # ret 4
    (0x458e90, '?render3dSelect@IRenderable@RBX@@UAEXPAVAdorn@2@W4SelectState@2@@Z'),   # ret 8
]
FORCE_NON_EXACT_ROWS = []  # shared_count now checked against its complete 131-byte extent

FORCE_UNPROVEN = {
    '??$?0PAVForceField@RBX@@' + DLR + '1@@shared_count@detail@boost@@QAE@PAVForceField@RBX@@' + DLR + '4@@Z': 0x5c13e0,   # 005c14a1
}
# Built with NATIVE_FORCEFIELD_PENDING against the generated Workspace / Instance copies: never counted.
# ('slice', row, lo, hi) compares a body against bytes lo..hi of one function-list row (the 0062d310 row holds two
# functions: hasForceField 0062d310..0062d380 and the ancestor walk 0062d380..0062d3cc).
FORCE_PENDING_ROWS = [
    (0x62d090, '?askSetParent@ForceField@RBX@@MBE_NPBVInstance@2@@Z'),
    (0x62d200, '?renderPart@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@PAVAdorn@RBX@@H@Z'),
    (0x62d380, '?isProtectedRecursive@ForceField@RBX@@CA_NPAVInstance@2@@Z'),
    (0x62d3d0, '?isProtected@ForceField@RBX@@SA_NPAVInstance@2@@Z'),
    (0x62d400, '??$visitDescendents@V?$bind_t@'),
    (0x62d570, '?render3dAdorn@ForceField@RBX@@MAEXPAVAdorn@2@@Z'),
]
FORCE_PENDING_REASONS = {
    '0062d200': 'not exact even in the pending build: reads the 2008 PartInstance float at +0x328 (the native '
                'PartInstance.h has its provisional transparency at +0x1e8; sizes match, field identity unproven)',
}
FORCE_EXTERNAL = {
    '??0Instance@RBX@@QAE@XZ': 0x55b7e0,                       # FactoryProduct ctor 0062d123
    '??1IRenderable@RBX@@QAE@XZ': 0x47d410,                    # ~ForceField 0062d89f (folded empty body)
    '?setName@Instance@RBX@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z': 0x55af90,  # 0062d773
    '?getPart@PartInstance@RBX@@QBEABVPart@2@XZ': 0x59aa90,   # renderPart 0062d29d
    '?selectionBox@Draw@RBX@@SAXABVPart@2@PAVAdorn@2@ABVColor4@G3D@@@Z': 0x676e00,   # renderPart 0062d2a3 (Draw.cpp)
    '?numChildren@Instance@RBX@@QBEIXZ': 0x48ae20,             # hasForceField 0062d31c
    '?read@?$CopyOnWrite@V?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@RBX@@QBE?AV?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@boost@@XZ': 0x4915b0,  # visitDescendents 0062d430
    '??$shared_from@VInstance@RBX@@@RBX@@YA?AV?$shared_ptr@VInstance@RBX@@@boost@@PAVInstance@0@@Z': 0x618a40,  # render3dAdorn 0062d5d5
}
FORCE_DATA = {
    '?sForceField@RBX@@3PADA': 0x95c3a8,   # "ForceField" (doDeclare 005bf9c0, classDescriptor 005c0400)
}
FORCE_FOLDED = {
    '??1' + DCF + 'UAE@XZ': 0x62d300,
    '??_G' + DCF + 'UAEPAXI@Z': 0x62d190,
    '?className@' + FPF + 'SAABVName@2@XZ': 0x62d3e0,
    '??$declare@$1?sForceField@RBX@@3PADA@Name@RBX@@SAABV01@XZ': 0x62d3e0,
}
FORCE_NOT_ATTEMPTED = {
    '0062d950/0062d8f0': 'GeometryService FactoryProduct ctor/dtor that follow the ForceField unit (not ForceField)',
}

# Proposed declarations for shared headers (not edited; generated copies for the pending build only).
PROPOSAL_INSTANCE_ANCHOR = '    Instance* getChild(size_t i) { return (*children)[i].get(); }\n'
PROPOSAL_INSTANCE = '''    template<typename Function>
    void visitDescendents(Function func) const   // 0062d400 (bind_t instance used by ForceField::render3dAdorn)
    {
        if (children)
        {
            boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = c->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin();
            for (; iter != end; iter++)
            {
                func(*iter);
                (*iter)->visitDescendents(func);
            }
        }
    }
'''


def write_pending(root, pending):
    """Generate the pending include overlay: Instance.h + visitDescendents, declaration-only Workspace."""
    (pending / 'v8tree').mkdir(parents=True, exist_ok=True)
    (pending / 'v8datamodel').mkdir(parents=True, exist_ok=True)
    text = (root / 'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text()
    assert text.count(PROPOSAL_INSTANCE_ANCHOR) == 1
    (pending / 'v8tree/Instance.h').write_text(text.replace(PROPOSAL_INSTANCE_ANCHOR, PROPOSAL_INSTANCE_ANCHOR + PROPOSAL_INSTANCE))
    (pending / 'v8datamodel/Workspace.h').write_text(
        (root / 'rebuild/2008-06/tests/NativeDebrisForceFieldPendingWorkspace.h').read_text())


def forcefield_vtables(check_vtable, force_obj, gi):
    vt = {}
    vt['ForceField'] = check_vtable(force_obj, '??_7ForceField@RBX@@' + gi, 0x84682c, 0x82d884, 'ForceField')
    assert len(vt['ForceField']) == 16
    assert vt['ForceField'][3]['symbol'].startswith('?askSetParent@ForceField') and vt['ForceField'][3]['original'] == '0062d090'
    vt['ForceField_IRenderable'] = check_vtable(force_obj, '??_7ForceField@RBX@@6B@', 0x846798)
    assert [s['original'] for s in vt['ForceField_IRenderable']] == ['0060a2f0', '00565950', '0070bdf0', '0062d570', '00458e90']
    vt['ForceField_FactoryProduct'] = check_vtable(force_obj, '??_7' + FPF + gi, 0x846694, 0x82d884, 'ForceField')
    vt['ForceField_DescribedCreatable'] = check_vtable(force_obj, '??_7' + DCF + gi, 0x846754, 0x82d884, 'ForceField')
    return vt


def forcefield_rtti(original, bases):
    assert original.vtable_class(0x84682c) == ('.?AVForceField@RBX@@', 0)
    assert original.vtable_class(0x846798) == ('.?AVForceField@RBX@@', 0x130)
    fb = bases(0x84682c)
    assert fb['.?AVIRenderable@RBX@@'] == 0x130 and fb['.?AV' + DCF] == 0, fb
    for address, text in ((0x95c3a8, 'ForceField'), (0x84686c, 'ForceField')):
        assert original.string(address) == text, (hex(address), text)
    assert struct.unpack('<f', original.data(0x845934, 4))[0] == struct.unpack('<f', struct.pack('<f', 1.0 / 15))[0]
    assert struct.unpack('<f', original.data(0x819bac, 4))[0] == 0.5

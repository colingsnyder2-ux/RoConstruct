"""Verify the inactive native RBX::CleanStage / JointStage / SimJobStage / SimJob / AssemblySimJob / Kernel recovery
(2008-06).

Builds (document-swap flags plus /fp:fast /U_RELEASEASSERT, VS2008 RTM 21022), all from the current native headers
native-headers/v8world/{CleanStage,JointStage,SimJobStage,SimJob}2008.h and native-headers/v8kernel/Kernel2008.h:
  * tests/NativeKernelStagesLayout.cpp       sizeof / offset probe (mov eax, imm32; ret);
  * native-classes/CleanStage2008.cpp        the CleanStage unit (0064a310..0064a510, with the header-inline IStage
                                             COMDATs stepWorld 0064a380 / getKernel 0064a390);
  * native-classes/IWorldStage2008.cpp       IWorldStage::getMetric 0064a3d0 (no donor body);
  * native-classes/JointStage2008.cpp        the JointStage unit rows that need no ClumpStage / native Primitive;
  * native-classes/SimJobStage2008.cpp       SimJobStage::onEdgeAdded 0064d060 / onEdgeRemoving 0064d090;
  * native-classes/SimJobStage2008Ctor.cpp   SimJobStage() 0064d300 and ??_G 0064d380 (news the 2008 Kernel, which
                                             cannot share a unit with the donor Edge.h -> IPipelined.h -> Kernel.h);
  * native-classes/SimJob2008.cpp            SimJob() / ~SimJob / ??_G, AssemblySimJob(assembly);
  * native-classes/Kernel2008.cpp            Kernel ??_G and the numBodies / numPoints / numConnectors leaves;
  * CleanStage2008.cpp, JointStage2008.cpp, SimJobStage2008.cpp and Kernel2008.cpp again with
    /DNATIVE_KERNEL_STAGES_PENDING and a generated copy of the donor v8kernel/IStage.h carrying the 2008 StageType values
    (CLEAN 0 ... SIMJOB 6, KERNEL 7; under out/native-layouts/kernel-stages-pending): only the getStageType bodies
    differ, and they are fold proofs (folded original bodies, never counted), recorded pending-build-only.

The headers use non-colliding names (*2008.h): v8world/JointStage.h / SimJobStage.h are included by the donor World.h,
v8kernel/Kernel.h by the donor IPipelined.h, so headers at those paths would shadow the donors for most engine units.
No new header shadows a donor header (no donor file has these names).

Every exact row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the address
the original instruction uses and verified: imports by DLL export name, string literals by bytes, constants by bytes,
type descriptors and vtables by original RTTI names, own symbols by the row proven here, folded bodies by their
address, and the remaining externals by the explicit EXTERNAL / DATA maps (call sites read in the original
disassembly). A symbol binds to one address across all rows. Vtables are compared slot by slot from the objects built
with the current (non-pending) headers. Writes work/2008-06/shared-layouts/kernel-stages-working.json.
Set NATIVE_KERNEL_STAGES_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
DONOR = ROOT / 'tools/rbxgs/Client/App/include'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
LAYOUT = R / 'tests/NativeKernelStagesLayout.cpp'
SOURCES = {
    'clean': R / 'native-classes/CleanStage2008.cpp',
    'worldstage': R / 'native-classes/IWorldStage2008.cpp',
    'joint': R / 'native-classes/JointStage2008.cpp',
    'simjobstage': R / 'native-classes/SimJobStage2008.cpp',
    'simjobstage_ctor': R / 'native-classes/SimJobStage2008Ctor.cpp',
    'simjob': R / 'native-classes/SimJob2008.cpp',
    'kernel': R / 'native-classes/Kernel2008.cpp',
}
HEADERS = [R / 'native-headers/v8world/CleanStage2008.h', R / 'native-headers/v8world/JointStage2008.h',
           R / 'native-headers/v8world/SimJobStage2008.h', R / 'native-headers/v8world/SimJob2008.h',
           R / 'native-headers/v8kernel/Kernel2008.h']
DISCOVER = bool(os.environ.get('NATIVE_KERNEL_STAGES_DISCOVER'))
UNIT = ['/fp:fast', '/U_RELEASEASSERT']   # no RBXASSERT code in these units (e.g. ~IStage in ??_G 0064a3a0)

# Pending: the 2008 StageType values (getStageType bodies 00416690 / 007286a0 / 0077d810 / 005e2790 / 006fa3f0 /
# 007359e0 / 005cb9d0 / 0077d800 return 0 .. 7); the donor IStage.h has no CLEAN_STAGE and numbers JOINT 0 .. KERNEL 8.
PENDING = OUT / 'kernel-stages-pending'
(PENDING / 'v8kernel').mkdir(parents=True, exist_ok=True)
istage = (DONOR / 'v8kernel/IStage.h').read_text()
DONOR_ENUM = istage[istage.index('JOINT_STAGE = 0x0,'):istage.index('KERNEL_STAGE = 0x8,') + len('KERNEL_STAGE = 0x8,')]
STAGES_2008 = ['CLEAN_STAGE', 'JOINT_STAGE', 'CLUMP_STAGE', 'TREE_STAGE', 'ASSEMBLY_STAGE', 'SLEEP_STAGE',
               'SIMJOB_STAGE', 'KERNEL_STAGE']
assert istage.count(DONOR_ENUM) == 1
(PENDING / 'v8kernel/IStage.h').write_text(istage.replace(
    DONOR_ENUM, '\n\t\t\t\t'.join('%s = 0x%x,' % (n, i) for i, n in enumerate(STAGES_2008))))
PENDING_FLAGS = ['/I' + str(PENDING), '/DNATIVE_KERNEL_STAGES_PENDING']


def build(name, src, extra=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + list(extra) + flags[i:] + UNIT + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


OBJ, FLAGS = {}, {}
OBJ['layout'], FLAGS['layout'] = build('NativeKernelStagesLayout', LAYOUT)
for key, src in SOURCES.items():
    OBJ[key], FLAGS[key] = build('NativeKernelStages_' + key, src)
for key in ('clean', 'joint', 'simjobstage', 'kernel'):
    OBJ[key + '_pending'], FLAGS[key + '_pending'] = build('NativeKernelStages_%s_pending' % key, SOURCES[key],
                                                           PENDING_FLAGS)

# ---- layout ---------------------------------------------------------------------------------------
SIZES = {'nativeCleanStageSize': 0x10, 'nativeJointStageSize': 0x50, 'nativeSimJobStageSize': 0x2c,
         'nativeSimJobSize': 0x24, 'nativeAssemblySimJobSize': 0x28, 'nativeKernelSize': 0x24}
raw = OBJ['layout'].read_bytes()
for fn, size in SIZES.items():
    name_, body_, _ = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + fn + '@@'))
    assert body_ == b'\xb8' + struct.pack('<I', size) + b'\xc3', (fn, body_.hex())

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}


def norm(symbol):
    return symbol


# ---- externals: address the original instruction uses, read at the call sites listed ----------------
EXTERNAL = {
    '??2@YAPAXI@Z': 0x6a0920, '??3@YAXPAX@Z': 0x6a067a,
    # IPipelined (2008 bodies): 00645830 `currentStage = stage; ret 4` (evidence name putInKernel; putInPipeline /
    # putInStage have the same body), 00645820 `currentStage = NULL; ret 4`, 00645840 `currentStage =
    # currentStage->upstream; ret 4`.
    '?putInPipeline@IPipelined@RBX@@QAEXPAVIStage@2@@Z': 0x645830,         # CleanStage 0064a3eb / 0064a4db
    '?putInStage@IPipelined@RBX@@QAEXPAVIStage@2@@Z': 0x645830,            # JointStage 006683bb, SimJobStage 0064d06c
    '?removeFromPipeline@IPipelined@RBX@@QAEXPAVIStage@2@@Z': 0x645820,    # CleanStage 0064a414 / 0064a540
    '?removeFromStage@IPipelined@RBX@@QAEXPAVIStage@2@@Z': 0x645840,       # JointStage 00668420, SimJobStage 0064d0a4
    '?onPrimitiveAdded@JointStage@RBX@@QAEXPAVPrimitive@2@@Z': 0x6685b0,   # CleanStage 0064a3f4
    '?onPrimitiveRemoving@JointStage@RBX@@QAEXPAVPrimitive@2@@Z': 0x668850,  # CleanStage 0064a40c
    '??0JointStage@RBX@@QAE@PAVIStage@1@PAVWorld@1@@Z': 0x668470,          # CleanStage() 0064a34c (row not built)
    '?_Tidy@?$list@PAVSimJob@RBX@@V?$allocator@PAVSimJob@RBX@@@std@@@std@@IAEXXZ': 0x682b40,   # ??_G 0064d38f
    '??0?$list@PAVSimJob@RBX@@V?$allocator@PAVSimJob@RBX@@@std@@@std@@QAE@XZ': 0x61a200,       # 0064d367
    '?insert@?$_Tree@V?$_Tset_traits@PAVJoint@RBX@@U?$less@PAVJoint@RBX@@@std@@V?$allocator@PAVJoint@RBX@@@4@$0A@'
    '@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tset_traits@PAVJoint@RBX@@U?$less@PAVJoint@RBX@@@std@@V?$alloca'
    'tor@PAVJoint@RBX@@@4@$0A@@std@@@std@@_N@2@ABQAVJoint@RBX@@@Z': 0x5e8c40,                   # 0066835c
    '?insert@?$_Tree@V?$_Tmap_traits@PAVPrimitive@RBX@@PAVJoint@2@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@U?$pa'
    'ir@QAVPrimitive@RBX@@PAVJoint@2@@std@@@5@$00@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAVPrimi'
    'tive@RBX@@PAVJoint@2@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@U?$pair@QAVPrimitive@RBX@@PAVJoint@2@@std@@@5'
    '@$00@std@@@std@@_N@2@ABU?$pair@QAVPrimitive@RBX@@PAVJoint@2@@2@@Z': 0x668210,   # 0066837d / 0066839e (evidence: same type)
    '?erase@?$_Tree@V?$_Tset_traits@PAVJoint@RBX@@U?$less@PAVJoint@RBX@@@std@@V?$allocator@PAVJoint@RBX@@@4@$0A@@st'
    'd@@@std@@QAEIABQAVJoint@RBX@@@Z': 0x5e9f60,                            # 00668437
    '??1?$_Tree@V?$_Tmap_traits@PAVPrimitive@RBX@@PAVJoint@2@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@U?$pair@QA'
    'VPrimitive@RBX@@PAVJoint@2@@std@@@5@$00@std@@@std@@QAE@XZ': 0x553d80,  # ~JointStage 0066854e
    '??1?$_Tree@V?$_Tset_traits@PAVJoint@RBX@@U?$less@PAVJoint@RBX@@@std@@V?$allocator@PAVJoint@RBX@@@4@$0A@@std@@@'
    'std@@QAE@XZ': 0x64b230,                                                # ~JointStage 0066855b
}
DATA = {}
# ICF / trivial-wrapper folds: the original keeps one body where these units emit several identical ones.
FOLDED = {
    '?getAssemblyConst@AssemblySimJob@RBX@@UAEPAVAssembly@2@XZ': 0x74eed0,  # `mov eax, [ecx+0x24]; ret`
    '?getAssembly@AssemblySimJob@RBX@@UAEPAVAssembly@2@XZ': 0x74eed0,
    '??_GAssemblySimJob@RBX@@UAEPAXI@Z': 0x5e5190,                          # both vtables hold the SimJob ??_G
    '?getKernel@Kernel@RBX@@UAEPAV12@XZ': 0x7188c0,                         # `mov eax, ecx; ret` (evidence name)
    '?getStageType@CleanStage@RBX@@UAE?AW4StageType@IStage@2@XZ': 0x416690,  # `xor eax, eax; ret` (pending proof)
    '?getStageType@JointStage@RBX@@UAE?AW4StageType@IStage@2@XZ': 0x7286a0,  # `mov eax, 1` (pending proof)
    '?getStageType@SimJobStage@RBX@@UAE?AW4StageType@IStage@2@XZ': 0x5cb9d0,  # `mov eax, 6` (pending proof)
    '?getStageType@Kernel@RBX@@UAE?AW4StageType@IStage@2@XZ': 0x77d800,     # `mov eax, 7` (pending proof)
}
# Bodies emitted by these units whose bytes equal the folded original body (checked, not counted).
FOLD_PROOF = [
    ('simjob', '?getAssemblyConst@AssemblySimJob@RBX@@UAEPAVAssembly@2@XZ', 0x74eed0),
    ('simjob', '?getAssembly@AssemblySimJob@RBX@@UAEPAVAssembly@2@XZ', 0x74eed0),
    ('simjob', '??_GAssemblySimJob@RBX@@UAEPAXI@Z', 0x5e5190),
    ('kernel', '?getKernel@Kernel@RBX@@UAEPAV12@XZ', 0x7188c0),
]
# getStageType bodies: only the pending build (2008 StageType) defines them; recorded pending-build-only.
PENDING_FOLD_PROOF = [
    ('clean_pending', '?getStageType@CleanStage@RBX@@UAE?AW4StageType@IStage@2@XZ', 0x416690),
    ('joint_pending', '?getStageType@JointStage@RBX@@UAE?AW4StageType@IStage@2@XZ', 0x7286a0),
    ('simjobstage_pending', '?getStageType@SimJobStage@RBX@@UAE?AW4StageType@IStage@2@XZ', 0x5cb9d0),
    ('kernel_pending', '?getStageType@Kernel@RBX@@UAE?AW4StageType@IStage@2@XZ', 0x77d800),
]
NON_EXACT_ROWS = [
    (0x668280, '?removeFromMap@JointStage@RBX@@AAEXPAVJoint@2@PAVPrimitive@2@@Z', 'joint',
     'same length and instructions; only the prologue push order of esi / edi differs (register allocation), no source '
     'form tried (lower_bound / upper_bound loop, break / return / while variants) reproduces it'),
    (0x5fb650, '??0Kernel@RBX@@QAE@PAVIStage@1@@Z', 'kernel',
     'the 2008 KernelData is 0x3c (new 0x3c, constructor 005fb5f0) and CodeProfiler 0xc048 (new 0xc048, constructor '
     '005c43a0); the donor KernelData.h / util/Profiling.h give 0x30 / 0x20040'),
    (0x5faca0, '??1Kernel@RBX@@UAE@XZ', 'kernel',
     'the 2008 CodeProfiler has a virtual destructor (005fad00 deletes profilingKernel through slot 0); the donor '
     'Profiler has none; the rest (--numKernels, ~KernelData call, ~Array, ~IStage) is identical'),
]
UNPROVEN = {'??0Kernel@RBX@@QAE@PAVIStage@1@@Z': 0x5fb650,                  # SimJobStage() 0064d33c
            '??1Kernel@RBX@@UAE@XZ': 0x5faca0,                              # Kernel ??_G 005fb0c3
            '?removeFromMap@JointStage@RBX@@AAEXPAVJoint@2@PAVPrimitive@2@@Z': 0x668280}
# Vtable slots whose bodies are not built here: bound to the address the original vtable holds (names / call sites).
SLOT_EXTERNAL = {
    '?stepWorld@Kernel@RBX@@UAEXHH_N@Z': 0x5fb3f0,                          # evidence name
    '__purecall': 0x6a16be,                                                 # import thunk, verified below
}

ROWS = {
    'clean': [
        (0x64a310, '??0CleanStage@RBX@@QAE@PAVIStage@1@PAVWorld@1@@Z'),
        (0x64a380, '?stepWorld@IStage@RBX@@UAEXHH_N@Z'),
        (0x64a390, '?getKernel@IStage@RBX@@UAEPAVKernel@2@XZ'),
        (0x64a3a0, '??_GCleanStage@RBX@@UAEPAXI@Z'),
        (0x64a3e0, '?onPrimitiveAdded@CleanStage@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x64a400, '?onPrimitiveRemoving@CleanStage@RBX@@QAEXPAVPrimitive@2@@Z'),
        (0x64a420, '?onJointPrimitiveNulling@CleanStage@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z'),
        (0x64a460, '?onJointPrimitiveSet@CleanStage@RBX@@QAEXPAVJoint@2@PAVPrimitive@2@@Z'),
        (0x64a4d0, '?onEdgeAdded@CleanStage@RBX@@UAEXPAVEdge@2@@Z'),
        (0x64a510, '?onEdgeRemoving@CleanStage@RBX@@UAEXPAVEdge@2@@Z'),
    ],
    'worldstage': [
        (0x64a3d0, '?getMetric@IWorldStage@RBX@@UAEHW4MetricType@12@@Z'),
    ],
    'joint': [
        (0x667f70, '?edgeHasPrimitivesDownstream@JointStage@RBX@@AAE_NPAVEdge@2@@Z'),
        (0x668340, '?insertToListAndMap@JointStage@RBX@@AAEXPAVEdge@2@@Z'),
        (0x6683b0, '?onEdgeAdded@JointStage@RBX@@UAEXPAVEdge@2@@Z'),
        (0x6683f0, '?onEdgeRemoving@JointStage@RBX@@UAEXPAVEdge@2@@Z'),
        (0x668520, '??1JointStage@RBX@@UAE@XZ'),
        (0x668590, '??_GJointStage@RBX@@UAEPAXI@Z'),
    ],
    'simjobstage': [
        (0x64d060, '?onEdgeAdded@SimJobStage@RBX@@UAEXPAVEdge@2@@Z'),
        (0x64d090, '?onEdgeRemoving@SimJobStage@RBX@@UAEXPAVEdge@2@@Z'),
    ],
    'simjobstage_ctor': [
        (0x64d300, '??0SimJobStage@RBX@@QAE@PAVIStage@1@PAVWorld@1@@Z'),
        (0x64d380, '??_GSimJobStage@RBX@@UAEPAXI@Z'),
    ],
    'simjob': [
        (0x5e50f0, '??0SimJob@RBX@@QAE@XZ'),
        (0x5e5150, '??1SimJob@RBX@@UAE@XZ'),
        (0x5e5190, '??_GSimJob@RBX@@UAEPAXI@Z'),
        (0x5e51e0, '??0AssemblySimJob@RBX@@QAE@PAVAssembly@1@@Z'),
    ],
    'kernel': [
        (0x5fb0c0, '??_GKernel@RBX@@UAEPAXI@Z'),
        (0x5faa20, '?numBodies@Kernel@RBX@@QBEHXZ'),
        (0x5faa30, '?numPoints@Kernel@RBX@@QBEHXZ'),
        (0x5faa40, '?numConnectors@Kernel@RBX@@QBEHXZ'),
    ],
}

LOCAL_EH = nb.LOCAL_EH
UNBOUND = []
binding = {}   # symbol -> (address, row) for the one-address-per-symbol check


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def verify(obj, rows, own, strict=True, record=True):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
                how = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                how = 'literal %r' % literal[:-1].decode()
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert norm(rtti) == norm('.' + symbol[5:-2]), (name, symbol, hex(value), rtti)
                how = 'RTTI %s' % rtti
            elif symbol.startswith('__real@'):
                assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
                how = 'constant %s' % symbol[7:]
            elif symbol.startswith('??_7'):
                rtti, at = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert norm(rtti) == norm('.?AV' + cls), (name, symbol, hex(value), rtti)
                how = 'vtable RTTI %s offset %#x' % (rtti, at)
            elif symbol in own:
                assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
                how = 'own row'
            elif symbol in FOLDED:
                assert FOLDED[symbol] == value, (name, symbol, hex(value))
                how = 'folded'
            elif symbol in DATA:
                assert DATA[symbol] == value, (name, symbol, hex(value))
                how = 'data'
            elif symbol in EXTERNAL:
                assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
                how = 'external' + (' (evidence name)' if norm(names.get(value, '')) == norm(symbol) else '')
            elif symbol in UNPROVEN:
                assert UNPROVEN[symbol] == value, (name, symbol, hex(value))
                how = 'call target of a non-exact row'
            elif symbol in SLOT_EXTERNAL:
                assert SLOT_EXTERNAL[symbol] == value, (name, symbol, hex(value))
                how = 'call target bound at the call site (row not built / pending)'
            elif symbol.startswith('??_B?1??') or symbol.startswith('??_B?3??') or symbol.startswith('?$S') or '?$TSS' in symbol:
                how = 'local static'
            else:
                UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
                continue
            if record:
                prev = binding.setdefault(symbol, (value, name))
                assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
non_rows = [(resolve(OBJ[w], [(a, k)])[0], w) for a, k, w, _ in NON_EXACT_ROWS]
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
strict = not DISCOVER
groups = {k: verify(OBJ[k], rows, own, strict) for k, rows in resolved.items()}
non_out = [verify(OBJ[w], [r], own, strict=False)[0] for r, w in non_rows]
for row, (_, _, _, why) in zip(non_out, NON_EXACT_ROWS):
    if row['exact'] and not DISCOVER:
        raise AssertionError('non-exact row unexpectedly exact: %s' % row['address'])
    row['exact'], row['reason'] = False, why


def fold_proofs(items, status):
    out = []
    for which, symbol, address in items:
        body, refs = {n: (b, r) for n, b, r in match.coff_functions(OBJ[which].read_bytes())}[symbol]
        target, target_refs = target_of(address)
        ok = match.exact_match(target, target_refs, body, refs)
        assert ok or DISCOVER, ('fold body differs', symbol, hex(address))
        out.append({'symbol': symbol, 'folded_into': '%08x' % address, 'body_equal': ok, 'counted': False,
                    'build': which, 'status': status})
    return out


fold_out = fold_proofs(FOLD_PROOF, 'current headers')
pend_out = fold_proofs(PENDING_FOLD_PROOF, 'pending-build-only')
# the current-header builds define no getStageType body (the donor StageType has no 2008 values)
for which in ('clean', 'joint', 'simjobstage', 'kernel'):
    assert not [x for x in match.coff_functions(OBJ[which].read_bytes()) if x[0].startswith('?getStageType@')], which
if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g in list(groups.values()) + [non_out]:
        for r in g:
            if not r['exact']:
                print('NOT EXACT', r['address'], r['symbol'][:110], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, '\n'.join(UNBOUND)
d = lambda a: struct.unpack('<I', original.data(a, 4))[0]
assert original.imported(0x6a16be)[1] == '_purecall', original.imported(0x6a16be)

# ---- vtables from the objects built with the current headers, slot by slot ---------------------------------
slot_names = {}
for table_ in (own, FOLDED, EXTERNAL, UNPROVEN, SLOT_EXTERNAL):
    for k, v in table_.items():
        slot_names.setdefault(k, v)


def compiled_vtable(obj, symbol):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    slots = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        if offset >= start:
            slots[(offset - start) // 4] = symbols[index][0]
    return [slots[i] for i in range(len(slots))]


def check_vtable(obj, symbol, address):
    """Each slot holds the address bound to its symbol (row, fold, external) or the evidence name."""
    out, bad = [], []
    for i, slot in enumerate(compiled_vtable(obj, symbol)):
        value = d(address + 4 * i)
        if slot.startswith('??_E') and '??_G' + slot[4:] in slot_names:
            expect, how = slot_names['??_G' + slot[4:]], 'bound (??_G)'
        else:
            expect, how = slot_names.get(slot), 'bound'
        ok = expect == value if expect is not None else norm(names.get(value, '')) == norm(slot)
        if expect is None:
            how = 'evidence name'
        out.append({'slot': i, 'symbol': slot, 'original': '%08x' % value, 'ok': ok, 'how': how})
        if not ok:
            bad.append((i, slot, hex(value)))
    assert not bad, (symbol, bad)
    return out


VTABLES = (('clean', 'CleanStage', 0x84b05c, 7), ('joint', 'JointStage', 0x84cf64, 7),
           ('simjobstage_ctor', 'SimJobStage', 0x84b174, 7), ('simjob', 'SimJob', 0x83f72c, 3),
           ('simjob', 'AssemblySimJob', 0x83f73c, 3), ('kernel', 'Kernel', 0x84105c, 4))
vt = {}
for which, cls, address, count in VTABLES:
    assert original.vtable_class(address) == ('.?AV%s@RBX@@' % cls, 0), (cls, original.vtable_class(address))
    vt[cls] = check_vtable(OBJ[which], '??_7%s@RBX@@6B@' % cls, address)
    assert len(vt[cls]) == count, (cls, len(vt[cls]))

# ---- RTTI bases ------------------------------------------------------------------------------------------------


def bases(vtable):
    hierarchy = d(d(vtable - 4) + 16)
    out = {}
    for i in range(d(hierarchy + 8)):
        bcd = d(d(hierarchy + 12) + 4 * i)
        out.setdefault(original.string(d(bcd) + 8), struct.unpack('<i', original.data(bcd + 8, 4))[0])
    return out


STAGE_BASES = {'.?AVIWorldStage@RBX@@': 0, '.?AVIStage@RBX@@': 0}
for address, cls in ((0x84b05c, 'CleanStage'), (0x84cf64, 'JointStage'), (0x84b174, 'SimJobStage')):
    want = dict(STAGE_BASES)
    want['.?AV%s@RBX@@' % cls] = 0
    assert bases(address) == want, (hex(address), bases(address))
NONCOPYABLE = '.?AVnoncopyable@noncopyable_@boost@@'
assert bases(0x83f72c) == {'.?AVSimJob@RBX@@': 0, NONCOPYABLE: 4}
assert bases(0x83f73c) == {'.?AVAssemblySimJob@RBX@@': 0, '.?AVSimJob@RBX@@': 0, NONCOPYABLE: 4}
assert bases(0x84105c) == {'.?AVKernel@RBX@@': 0, '.?AVIStage@RBX@@': 0}

# ---- allocation sizes in the original creators --------------------------------------------------------------


def alloc_before(function, size, callee):
    body, _, _ = match.target('2008-06', '%08x' % function)
    push = (b'\x6a' + bytes([size])) if size < 0x80 else (b'\x68' + struct.pack('<I', size))
    at = body.index(push)
    while True:
        new = body.index(b'\xe8', at)
        if (function + new + 5 + struct.unpack_from('<i', body, new + 1)[0]) & 0xffffffff == 0x6a0920:
            break
        at = new + 1
    call = body.index(b'\xe8', new + 5)
    while (function + call + 5 + struct.unpack_from('<i', body, call + 1)[0]) & 0xffffffff != callee:
        call = body.index(b'\xe8', call + 1)
    return push.hex()


ALLOC = [
    (0x5ea920, 0x10, 0x64a310, 'World() -> CleanStage(NULL, world)'),
    (0x64a310, 0x50, 0x668470, 'CleanStage() -> JointStage(this, world)'),
    (0x668470, 0x30, 0x64cfd0, 'JointStage() -> ClumpStage(this, world) (row not built: ClumpStage 0x30)'),
    (0x64b8e0, 0x2c, 0x64d300, 'SleepStage() -> SimJobStage(this, world)'),
    (0x64d300, 0x24, 0x5fb650, 'SimJobStage() -> Kernel(this)'),
    (0x64d200, 0x28, 0x5e51e0, 'SimJobStage (assembly added) -> AssemblySimJob(assembly)'),
    (0x5fb650, 0x3c, 0x5fb5f0, 'Kernel() -> KernelData()'),
    (0x5fb650, 0xc048, 0x5c43a0, 'Kernel() -> CodeProfiler("Kernel")'),
]
alloc = [{'creator': '%08x' % f, 'size': hex(s), 'constructor': '%08x' % c, 'note': n, 'push': alloc_before(f, s, c)}
         for f, s, c, n in ALLOC]
assert names.get(0x5ea920, '') == '??0World@RBX@@QAE@XZ'
# numKernels: Kernel() 005fb6eb increments, ~Kernel 005facc5 decrements the same static.
for function, offset, opcode in ((0x5fb650, 0x9b, b'\xff\x05'), (0x5faca0, 0x25, b'\xff\x0d')):
    body, _, _ = match.target('2008-06', '%08x' % function)
    assert body[offset:offset + 2] == opcode and struct.unpack_from('<I', body, offset + 2)[0] == 0x97b5b8, hex(function)
# Every stage vtable slot 2 / 3 / 6 is the shared forwarding body (rows 0064a380 / 0064a390 / 0064a3d0).
for address in (0x84b05c, 0x84cf64, 0x84b174):
    assert (d(address + 8), d(address + 12), d(address + 24)) == (0x64a380, 0x64a390, 0x64a3d0), hex(address)

sha = nb.sha
paths = [Path(__file__).resolve(), LAYOUT] + list(SOURCES.values()) + HEADERS
exact = sorted({r['address'] for g in groups.values() for r in g if r['exact']})
assert not set(exact) & {r['address'] for r in non_out}
all_groups = dict(groups)
all_groups['not_exact'] = non_out
PROPOSALS = {
    'v8kernel/IStage.h (engine owner; extends the KERNEL_STAGE = 7 proposal of record_native_world_joints.py)':
        'the 2008 StageType is CLEAN_STAGE 0, JOINT_STAGE 1, CLUMP_STAGE 2, TREE_STAGE 3, ASSEMBLY_STAGE 4, '
        'SLEEP_STAGE 5, SIMJOB_STAGE 6, KERNEL_STAGE 7 (getStageType bodies 00416690 / 007286a0 / 0077d810 / 005e2790 '
        '/ 006fa3f0 / 007359e0 / 005cb9d0 / 0077d800; no COLLISION / SEPARATE stage vtable exists in 2008). With that '
        'enum the getStageType bodies here are exact fold proofs (pending-build-only).',
    'v8world/IWorldStage.h (engine owner)': 'IWorldStage::getMetric is header-inline in 2008: `return '
        'getDownstreamWS()->getMetric(metricType);` (0064a3d0 sits among the CleanStage COMDATs; built here out of '
        'line in native-classes/IWorldStage2008.cpp until the header carries it).',
    'v8world/IPipelined.h (engine owner)': 'the 2008 bodies: putInPipeline / putInStage / putInKernel share 00645830 '
        '(`currentStage = stage`), removeFromPipeline 00645820 (`currentStage = NULL`), removeFromStage 00645840 '
        '(`currentStage = currentStage->getUpstream()`, takes the stage argument), removeFromKernel 00645860, getKernel '
        '00645850 (getStage(KERNEL_STAGE = 7) 006457e0). Declarations already match the donor.',
    'v8world/ClumpStage.h (engine owner)': 'the 2008 ClumpStage is 0x30 bytes (JointStage() 00668470 news 0x30 for '
        'ClumpStage(this, world) 0064cfd0); the donor declares 0x1cc. JointStage() 00668470 is not built until a 2008 '
        'ClumpStage declaration exists.',
    'v8kernel/KernelData.h (kernel owner)': 'the 2008 KernelData is 0x3c (Kernel() 005fb650 news 0x3c, constructor '
        '005fb5f0; ~KernelData 005fa970 is out of line); the donor has four 0xc index arrays (0x30). numBodies / '
        'numPoints / numConnectors read +0x4 / +0x10 / +0x1c, so the first three arrays keep the donor offsets.',
    'util/Profiling.h (util owner)': 'the 2008 CodeProfiler is 0xc048 bytes (Kernel() 005fb650 news 0xc048 for '
        'CodeProfiler("Kernel") 005c43a0) and has a virtual destructor (~Kernel 005fad00 deletes it through slot 0).',
    'v8kernel/Kernel.h, v8world/JointStage.h, SimJobStage.h (original paths)': 'promote Kernel2008.h / '
        'JointStage2008.h / SimJobStage2008.h once the owners of the units that include IPipelined.h / World.h have '
        're-run their recorders: Kernel is 0x24 (no maxBodies / maxPoints / maxConnectors); SimJobStage holds a '
        'std::list<SimJob*>; CleanStage (new) precedes JointStage in the 2008 pipeline.',
}
receipt = {
    'class': 'RBX::CleanStage, JointStage, SimJobStage, SimJob, AssemblySimJob, Kernel (+ IWorldStage::getMetric, '
             'IStage::stepWorld / getKernel COMDATs)',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM)',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths},
    'objects': {p.name: sha(p) for p in OBJ.values()},
    'layout': {
        'CleanStage': '0x10 (005ea920): IWorldStage only (upstream +0x4, downstream +0x8, world +0xc)',
        'JointStage': '0x50 (0064a310): incompleteJoints +0x10 (std::set<Joint*>), jointMap +0x30 '
                      '(std::multimap<Primitive*, Joint*>)',
        'SimJobStage': '0x2c (0064b8e0): simJobs +0x10 (std::list<SimJob*>)',
        'SimJob': '0x24 (005e51e0): vptr, mechanisms +0x4 (std::vector), stageIterator +0x1c (list iterator); '
                  'boost::noncopyable at mdisp 4',
        'AssemblySimJob': '0x28 (0064d200): assembly +0x24',
        'Kernel': '0x24 (0064d300): IStage, inStepCode +0xc, kernelData +0x10, realTimeConnectors +0x14 (G3D::Array), '
                  'profilingKernel +0x20; static numKernels 0097b5b8',
    },
    'rows': all_groups,
    'fold_proof': fold_out,
    'pending_build_only': pend_out,
    'exact_function_rows': exact,
    'vtables': vt,
    'allocations': alloc,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
(ROOT / 'work/2008-06/shared-layouts/kernel-stages-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native kernel stages: %d distinct function rows exact (%s); %d non-exact rows not counted; %d fold proofs '
      '(+%d pending-build-only); targets and %d vtables verified'
      % (len(exact), ', '.join('%s %d' % (k, sum(r['exact'] for r in g)) for k, g in groups.items()), len(non_out),
         len(fold_out), len(pend_out), len(vt)))

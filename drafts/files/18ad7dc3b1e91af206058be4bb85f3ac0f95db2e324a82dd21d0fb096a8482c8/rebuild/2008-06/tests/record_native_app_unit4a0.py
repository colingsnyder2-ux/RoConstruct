"""Verify the inactive 2008-06 native rows of the application range 004a0000..004a4000 and record its unit map.

Unit map summary (boundary evidence in UNIT_MAP below; rows counted by other receipts are listed as 'ADDR counted by
RECEIPT' text, never as quoted bare addresses):
  * 004a0000..004a156f: the tail of Network/Client.cpp (Client owner: native-headers/Network/Client2008.h, counted by
    network-client-server2008): the event / bound-function descriptor instances SignalDesc<Client, ...> and
    BoundFuncDesc<Client, ...> (built here from native-classes/AppUnit4A0ClientDescriptors.cpp), the
    void(std::string, int, std::string) signal machinery (SignalDescImpl<3, ...>: reflection/signal.h has no
    three-argument specialization, proposal), Client::connect 004a0a70 and OnReceive 004a1070 (not declared).
  * 004a1560: Feature::getTopBottom (feature receipt; identical-code folded getter, also the Server "Port" getter).
  * 004a1570..004a3fff (continues past the range): Network/Server.cpp with Server::ClientProxy. Built here:
    isReplicator / _Count_if, the "Port" PropDescriptor<Server, int> instances (native-classes/
    AppUnit4A0ServerDescriptors.cpp), ServiceProvider::find<Server> with getClassIndex<Server>
    (AppUnit4A0ServiceFind.cpp) and the Message / Hint creation COMDATs the unit emits (AppUnit4A0Creators.cpp).
    Server::stop / getClientCount are exact only in a pending build (Server2008.h proposal; not counted). ClientProxy
    members stay blocked on the Replicator layout (network-client-proxy / network-replicator2008 receipts).

Builds (document-swap flags, VS2008 RTM 21022, RakNet 3.x headers tools/rbxgs/Client/Network/raknet30/Source):
  * creators, client, server: the three units above; find: AppUnit4A0ServiceFind.cpp with the committed
    native-headers/boost-noinline-shared-destructor profile first on the include path (the original calls the
    shared_ptr<Instance> destructor out of line, as in record_native_app_unit450.py);
  * pending: AppUnit4A0ServerDescriptors.cpp with /DNATIVE_APPUNIT4A0_PENDING against a generated copy of
    Network/Server2008.h under out/app-unit4a0/pending (the proposed stop / getClientCount declarations). Rows exact
    only there are recorded as pending_build_only (exact=false) and never counted.
No unit declares a class with a vtable of its own, so there is no vtable slot check; the descriptor vtables the
constructors store are verified by their original RTTI names. No header is created (nothing is shadowed).

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address; an address may carry several
symbols (identical-code folding), each of whose bodies must be exact there. Every REL32/DIR32 target of every proven
row is verified: imports by DLL export name, strings and constants by bytes, vtables by original RTTI names, type
descriptors by their decorated name, throw infos by their catchable types, own (proven) rows, and the remaining
externals by the explicit EXTERNAL map (call-site evidence in comments). Counted rows are the proven rows inside the
range that no other receipt counts.
Writes work/2008-06/shared-layouts/app-unit4a0-working.json.
Set NATIVE_APP_UNIT4A0_DISCOVER=1 to list unbound targets instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from collections import deque
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
HDR = R / 'native-headers'
OUT = nb.OUT / 'app-unit4a0'
OUT.mkdir(parents=True, exist_ok=True)
PENDING_DIR = OUT / 'pending'
RAKNET = ['/I' + str(ROOT / 'tools/rbxgs/Client/Network/raknet30/Source')]
SOURCES = {'creators': R / 'native-classes/AppUnit4A0Creators.cpp',
           'client': R / 'native-classes/AppUnit4A0ClientDescriptors.cpp',
           'server': R / 'native-classes/AppUnit4A0ServerDescriptors.cpp',
           'find': R / 'native-classes/AppUnit4A0ServiceFind.cpp'}
PROFILE = {'find': ['boost-noinline-shared-destructor']}
HEADERS = [HDR / h for h in ('v8datamodel/Message.h', 'Network/Client2008.h', 'Network/Server2008.h',
                             'Network/Peer2008.h', 'Network/Replicator2008.h', 'reflection/reflection.h',
                             'reflection/signal.h', 'v8tree/Service.h', 'util/Object.h',
                             'boost-noinline-shared-destructor/boost/detail/shared_count.hpp')]
HEADERS = [h for h in HEADERS if h.exists()]
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4A0_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4a0-working.json'
RANGE = (0x4a0000, 0x4a4000)


def build(name, src, profile=(), pending=False):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    pre = ['/I' + str(HDR / p) for p in profile] + (['/I' + str(PENDING_DIR)] if pending else [])
    flags = flags[:i] + pre + flags[i:] + RAKNET + (['/DNATIVE_APPUNIT4A0_PENDING'] if pending else []) + \
        ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


# ---- pending header copy: Server2008.h plus the proposed declarations -------------------------------------------------
SERVER_ANCHOR = '\t\t\tServer();                                                               // 004a4b30\n'
SERVER_PROPOSAL = ('\t\t\tvoid stop(int blockDuration);                                           // 004a1880 (proposal)\n'
                   '\t\t\tint getClientCount();                                                   // 004a2250 (proposal)\n')
_server_h = (HDR / 'Network/Server2008.h').read_text()
assert _server_h.count(SERVER_ANCHOR) == 1
(PENDING_DIR / 'Network').mkdir(parents=True, exist_ok=True)
(PENDING_DIR / 'Network/Server2008.h').write_text(_server_h.replace(SERVER_ANCHOR, SERVER_ANCHOR + SERVER_PROPOSAL))

OBJ, FLAGS = {}, {}
for _k, _src in SOURCES.items():
    OBJ[_k], FLAGS[_k] = build('NativeAppUnit4A0_' + _k, _src, PROFILE.get(_k, ()))
OBJ['pending'], FLAGS['pending'] = build('NativeAppUnit4A0_server_pending', SOURCES['server'], pending=True)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l)['size'] for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}
d32 = lambda a: struct.unpack('<I', original.data(a, 4))[0]

STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
SPI = 'V?$shared_ptr@VInstance@RBX@@@boost@@'
CL = 'VClient@Network@RBX@@'
DEL = 'VDeleter@?$Creatable@VInstance@RBX@@@'

# ---- identity roots per unit: (address, symbol pattern, evidence) -----------------------------------------------------
ROOTS = {
    'creators': [
        (0x4a3850, ['??$create@VMessage@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VMessage'],
         'called by Creator::create 004a38f5; malloc 0x15c = sizeof(Message) (v8datamodel/Message.h)'),
        (0x4a38d0, ['?create@Creator@?$FactoryProduct@VMessage@RBX@@VInstance@2@'],
         'slot 0 of the FactoryProduct<Message> Creator vtable 008236c0'),
        (0x4a3b80, ['??$?0VHint@RBX@@' + DEL, '?$shared_ptr@VHint@RBX@@@boost@@QAE@PAVHint'],
         'called by create<Hint> 004a4da1 (shared_ptr<Hint>(Hint*, Deleter), enable_shared_from_this hook-up)'),
        (0x4a3b60, ['??_EHint@RBX@@WIE@AEPAXI@Z'], 'Hint vtables 008237f4 / 00823a34 / 00823b10 (this -= 0x84)'),
        (0x4a3b70, ['??_EHint@RBX@@WBE@AEPAXI@Z'], 'Hint vtables 0082383c / 00823a7c / 00823b58 (this -= 0x14)'),
        (0x4a39e0, ['??_E?$FactoryProduct@VMessage@RBX@@VInstance@2@', '@OBE@AEPAXI@Z'],
         'FactoryProduct<Message> vtables 0082374c / 0083d9e8 (this -= 0x14)'),
        (0x4a39f0, ['??1?$DescribedCreatable@VMessage@RBX@@VInstance@2@'],
         'unwind funclet 007c7d03 (one jmp to ~FactoryProduct<Message> 004a3980)'),
    ],
    'client': [
        (0x4a0020, ['??0?$SignalDesc@' + CL + '$$A6AX' + STR + SPI + '@Z@Reflection@RBX@@QAE@PBD00@Z'],
         'static initializer 007f1bd0; stores vtable 008230b0 (RTTI SignalDesc<Client, void(string, shared_ptr<Instance>)>)'),
        (0x4a02e0, ['??0?$SignalDesc@' + CL + '$$A6AX' + STR + '@Z@Reflection@RBX@@QAE@PBD0@Z'],
         'static initializer 007f1c00; stores vtable 008230d0 (RTTI SignalDesc<Client, void(string)>)'),
        (0x4a03b0, ['??0?$BoundFuncDesc@' + CL + '$$A6AX' + STR + 'HHH@Z$03@Reflection@RBX@@QAE@'],
         'static initializer 007f1b60; stores vtable 008230e0 (RTTI BoundFuncDesc<Client, void(string, int, int, int), 4>)'),
        (0x4a04b0, ['?execute@?$BoundFuncDesc@' + CL + '$$A6AX' + STR + 'HHH@Z$03@'], 'vtable 008230e0 slot 1'),
        (0x4a0690, ['??_G?$BoundFuncDesc@' + CL + '$$A6AX' + STR + 'HHH@Z$03@'], 'vtable 008230e0 slot 0'),
        (0x4a06b0, ['??0?$BoundFuncDesc@' + CL + '$$A6AXH@Z$00@Reflection@RBX@@QAE@'],
         'static initializer 007f1ba0; stores vtable 008230ec (RTTI BoundFuncDesc<Client, void(int), 1>)'),
        (0x4a0780, ['?execute@?$BoundFuncDesc@' + CL + '$$A6AXH@Z$00@'], 'vtable 008230ec slot 1'),
    ],
    'server': [
        (0x4a17f0, ['?isReplicator@@YA_N' + SPI + '@Z'],
         'evidence name; pushed by getClientCount 004a227f as the _Count_if predicate'),
        (0x4a1af0, ['??$_Count_if@PB' + SPI + 'P6A_NV12@@Z@std@@'], 'called by getClientCount 004a2286'),
        (0x4a3f80, ['??$?0P8Server@Network@RBX@@BEHXZH@?$PropDescriptor@VServer@Network@RBX@@H@'],
         'static initializer 007f1cf0 ("Port", "Data", getter 004a1560, flags 5); stores vtable 00823898'),
        (0x4a1b70, ['?setValue@?$GetImpl@P8Server@Network@RBX@@BEHXZ@?$PropDescriptor@VServer@Network@RBX@@H@'],
         'GetImpl<int (Server::*)() const> vtable 008234d0 slot 3 (also the Mouse GetImpl vtables, identical code)'),
    ],
    'find': [
        (0x4a1d00, ['??$callDoGetClassIndex@VServer@Network@RBX@@@ServiceProvider@RBX@@SAXXZ'],
         'pushed by find<Server> 004a3e61 as the call_once function (one jmp to doGetClassIndex<Server> 004a1760)'),
        (0x4a3e40, ['??$find@VServer@Network@RBX@@@ServiceProvider@RBX@@QBEPAVServer@Network@1@XZ'],
         'called by Server::serverIsPresent 004a40d0 (bound as an external there by network-client-server2008)'),
    ],
}
# Rows exact only in the pending build (never counted): (address, symbol, evidence)
PENDING_ROWS = [
    (0x4a1880, '?stop@Server@Network@RBX@@QAEXH@Z',
     'evidence name; rakPeer +0x140 IsActive (slot 11) then Shutdown(blockDuration, 0) (slot 10), removeAllChildren'),
    (0x4a2250, '?getClientCount@Server@Network@RBX@@QAEHXZ',
     'evidence name; count_if(children, isReplicator) through _Count_if 004a1af0'),
]

# ---- externals: the address the original instruction uses (call site in the comment) ---------------------------------
STRING_T = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
ITEM_LIST = '?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@'
EXTERNAL = {
    'creators': {
        '??0Message@RBX@@QAE@XZ': 0x5dd120,  # 004a3895 (Message() of the effects unit)
        '??$?0PAVMessage@RBX@@' + DEL + '1@@shared_count@detail@boost@@QAE@PAVMessage@RBX@@' + DEL + '4@@Z': 0x4a3710,  # 004a37c8
        '??$?0PAVHint@RBX@@' + DEL + '1@@shared_count@detail@boost@@QAE@PAVHint@RBX@@' + DEL + '4@@Z': 0x4a3a00,  # 004a3ba8
        # the vector deleting destructors the original adjustor thunks jump to (004a39e4 / 004a3b67 / 004a3b74)
        '??_E?$FactoryProduct@VMessage@RBX@@VInstance@2@$1?sMessage@2@3QBDB@RBX@@MAEPAXI@Z': 0x5dd100,
        '??_EHint@RBX@@UAEPAXI@Z': 0x4a4d20,
        '??1?$FactoryProduct@VMessage@RBX@@VInstance@2@$1?sMessage@2@3QBDB@RBX@@MAE@XZ': 0x4a3980,  # 004a39f0 (effects row)
    },
    'client': {
        # classDescriptor<Client> (Client2008.h, network-client-server2008 unit): 004a0042 / 004a0302 / 004a03d7 / 004a06d9
        '?classDescriptor@?$Described@' + CL + '$1?sClient@23@3PADAV?$FactoryProduct@' + CL + 'VPeer@23@$1?sClient@23@3PADA'
        '@3@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x49eb30,
        '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,  # 004a004f / 004a030f
        '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,  # 004a03df
        '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,  # 004a0069 / 004a074b / 0049ee70
        '??$singleton@H@Type@Reflection@RBX@@SAABV012@XZ': 0x56cbc0,  # 004a041a
        '??$singleton@' + STRING_T + '@Type@Reflection@RBX@@SAABV012@XZ': 0x56cdf0,  # 004a0075
        '??$singleton@V?$shared_ptr@VInstance@RBX@@@boost@@@Type@Reflection@RBX@@SAABV012@XZ': 0x56cae0,  # 004a00c9
        '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,  # 004a0736
        '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,  # 004a0082 / 004a0403
        '??$convert@H@Value@Reflection@RBX@@QAEAAHXZ': 0x56ea60,  # 004a05de / 004a0816
        '??$convert@' + STRING_T + '@Value@Reflection@RBX@@QAEAA' + STRING_T + 'XZ': 0x56f0b0,  # 004a0602
        '?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z': 0x594b40,  # 004a0756
        # list<SignatureDescriptor::Item>::_Buynode (try / catch(...) body the analysis splits at its catch funclet, so
        # bound by the call site only) and _Incsize (support row of other receipts): 004a009e / 004a00a9
        '?_Buynode@' + ITEM_LIST + 'IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@'
        'SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,
        '?_Incsize@' + ITEM_LIST + 'IAEXI@Z': 0x682cc0,
    },
    'server': {
        # classDescriptor<Server> (Server2008.h, network-client-server2008 unit): 004a3fe0
        '?classDescriptor@?$Described@VServer@Network@RBX@@$1?sServer@23@3PADAV?$FactoryProduct@VServer@Network@RBX@@VPeer'
        '@23@$1?sServer@23@3PADA@3@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x49eba0,
        # TypedPropertyDescriptor<int> constructor (shared reflection instance; app-unit440 open row): 004a3fed
        '??0?$TypedPropertyDescriptor@H@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD1V?$auto_ptr@VGetSet@?$TypedProperty'
        'Descriptor@H@Reflection@RBX@@@std@@W4Functionality@PropertyDescriptor@12@@Z': 0x4432a0,
    },
    'find': {
        '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,  # 004a3e68 / 004a3ee0
        '?findServiceByClassName@ServiceProvider@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@ABVName@2@@Z': 0x572a90,  # 004a3ef5
        '?resize@?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@'
        'QAEXIV?$shared_ptr@VInstance@RBX@@@boost@@@Z': 0x4124c0,  # 004a3eb2 (try / catch body split by the analysis)
        '?newIndex@ServiceProvider@RBX@@SAIXZ': 0x572690,  # 004a1790
        '??4shared_count@detail@boost@@QAEAAV012@ABV012@@Z': 0x4025b0,  # serviceArray store
        '??1?$shared_ptr@VInstance@RBX@@@boost@@QAE@XZ': 0x600660,  # out-of-line shared_ptr<Instance> destructor
        # Name::declare<sServer> COMDATs the linker took from the Players unit: 004a3edb / 004a3ee8
        '??$callDoDeclare@$1?sServer@Network@RBX@@3PADA@Name@RBX@@CAXXZ': 0x496900,
        '??$doDeclare@$1?sServer@Network@RBX@@3PADA@Name@RBX@@CAABV01@XZ': 0x496240,
        # function-local statics of the getClassIndex<Server> / doGetClassIndex<Server> / declare<sServer> templates
        '?flag@?1???$getClassIndex@VServer@Network@RBX@@@ServiceProvider@RBX@@SAIXZ@4JA': 0x970d18,
        '?flag@?1???$declare@$1?sServer@Network@RBX@@3PADA@Name@RBX@@SAABV12@XZ@4JA': 0x97028c,
        '?index@?1???$doGetClassIndex@VServer@Network@RBX@@@ServiceProvider@RBX@@SAIXZ@4IA': 0x970d08,
        '??_B?1???$doGetClassIndex@VServer@Network@RBX@@@ServiceProvider@RBX@@SAIXZ@51': 0x970d0c,
    },
}
DATA_EXTERNAL = {k for u in EXTERNAL.values() for k in u if '?1??' in k or k.startswith('??_B')}


def load_bodies(obj):
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {}
    for n, b, r in match.coff_functions(raw):
        start, section = definitions[n]
        table = sections[section]
        rel = []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if 0 <= offset < len(b):
                rel.append((offset, symbols[index][0], kind))
        bodies.setdefault(n, (b, r, rel))
    return bodies


TARGET = {}


def target_of(address):
    if address not in TARGET:
        body, refs, _ = match.target('2008-06', '%08x' % address)
        TARGET[address] = (body, refs)
    return TARGET[address]


def throw_info_names(value):
    array = d32(value + 12)
    return [original.string(d32(d32(array + 4 + 4 * i) + 4) + 8) for i in range(d32(array))]


class Closure:
    def __init__(self, unit, roots, external):
        self.unit, self.external = unit, external
        self.obj = OBJ[unit]
        self.bodies = load_bodies(self.obj)
        self.raw = Path(self.obj).read_bytes()
        self.index = match._coff_data_index(self.raw)
        self.used, self.unbound = set(), []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        queue = deque()
        self.roots = {}
        for address, pattern, evidence in roots:
            hits = [n for n in self.bodies if not nb.LOCAL_EH.match(n) and all(p in n for p in pattern)]
            if DISCOVER and len(hits) != 1:
                print('ROOT', unit, '%08x' % address, pattern, [h[:150] for h in hits])
                continue
            assert len(hits) == 1, ('root pattern must select one symbol', unit, pattern, hits)
            self.roots[address] = hits[0]
            queue.append((address, hits[0], 'root: ' + evidence))
        while queue:
            address, symbol, reason = queue.popleft()
            if address in self.proven:
                if symbol not in self.aliases[address]:
                    if self.exact_at(symbol, address):
                        self.aliases[address].append(symbol)
                    else:
                        self.not_exact.setdefault(address, (symbol, 'folded alias: ' + reason))
                continue
            if not self.exact_at(symbol, address):
                self.not_exact.setdefault(address, (symbol, reason))
                continue
            self.proven[address], self.aliases[address], self.why[address] = symbol, [symbol], reason
            _, _, rel = self.bodies[symbol]
            target, _ = target_of(address)
            for offset, sym, kind in rel:
                if kind == 20:
                    value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                    if value in FUNCTIONS and sym in self.bodies and not nb.LOCAL_EH.match(sym) \
                            and sym not in self.external:
                        queue.append((value, sym, 'called by %08x' % address))
        self.own = {}
        for address, syms in self.aliases.items():
            for s in syms:
                prev = self.own.setdefault(s, address)
                assert prev == address, ('one address per symbol', s, hex(prev), hex(address))
        self.checked = {a: self.verify(a, s) for a, s in sorted(self.proven.items())}

    def exact_at(self, symbol, address):
        if symbol not in self.bodies or address not in FUNCTIONS:
            return False
        body, refs, _ = self.bodies[symbol]
        target, target_refs = target_of(address)
        return len(body) == len(target) and match.exact_match(target, target_refs, body, refs)

    def resolve(self, owner, sym, value):
        sections, symbols, definitions, _ = self.index
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(sym), (owner, sym, hex(value), hit)
            return '%s!%s' % hit
        if sym.startswith('__real@'):
            assert original.data(value, len(sym[7:]) // 2) == bytes.fromhex(sym[7:])[::-1], (owner, sym)
            return 'constant %s' % sym[7:]
        if sym.startswith('??_C@'):
            pos, at = definitions[sym]
            literal = self.raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (owner, sym, hex(value))
            return 'string %r' % literal[:-1].decode('latin-1')
        if sym.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = sym[4:sym.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (owner, sym, hex(value), rtti)
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if sym.startswith('??_R0'):
            name = '.' + sym[5:-2]
            assert original.string(value + 8) == name, (owner, sym, hex(value), original.string(value + 8))
            return 'type descriptor %s' % name
        if sym.startswith('__TI'):
            got = throw_info_names(value)
            cls = sym[sym.index('?'):]
            assert got and got[0] == '.' + cls, (owner, sym, hex(value), got)
            return 'throw info, catchable types %s' % ' '.join(got)
        if sym in self.own:
            assert self.own[sym] == value, (owner, sym, hex(value), hex(self.own[sym]))
            return 'own row'
        if sym in self.external:
            assert self.external[sym] == value, (owner, sym, hex(value), hex(self.external[sym]))
            self.used.add(sym)
            return 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
        return None

    def verify(self, address, symbol):
        body, refs, rel = self.bodies[symbol]
        target, _ = target_of(address)
        sections, symbols, definitions, _ = self.index
        verified, local = {}, set()
        for offset, sym, kind in rel:
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                start, section = definitions[symbol]
                code = self.raw[sections[section][4] + start:]
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                    & 0xffffffff
            if nb.LOCAL_EH.match(sym):
                local.add(sym)
                continue
            how = self.resolve(symbol, sym, value)
            if how is None:
                self.unbound.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50],
                                                                          symbol[:50], address + offset))
                continue
            verified[sym] = '%s (%s)' % (hex(value), how)
        return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}

    def check(self):
        if DISCOVER:
            print('==', self.unit)
            print('\n'.join(sorted(set(self.unbound))))
            for a, (s, r) in sorted(self.not_exact.items()):
                print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
            for a in sorted(self.proven):
                print('PROVEN %08x %s %s' % (a, self.proven[a][:110], self.why[a][:40]))
            print('UNUSED EXTERNAL', sorted(set(self.external) - self.used))
            return
        assert not self.unbound, '\n'.join(self.unbound)
        assert sorted(self.used) == sorted(self.external), sorted(set(self.external) - self.used)
        assert not self.not_exact, {('%08x' % a): v for a, v in self.not_exact.items()}
        for root_address in self.roots:
            assert root_address in self.proven, ('root not proven', '%08x' % root_address)


CLOSURES = {k: Closure(k, ROOTS[k], EXTERNAL[k]) for k in ROOTS}
for _c in CLOSURES.values():
    _c.check()

# ---- pending build: exact only there, never counted -------------------------------------------------------------------
PENDING_BODIES = load_bodies(OBJ['pending'])
pending_out = []
for address, symbol, evidence in PENDING_ROWS:
    body, refs, _ = PENDING_BODIES[symbol]
    target, target_refs = target_of(address)
    exact = len(body) == len(target) and match.exact_match(target, target_refs, body, refs)
    if not DISCOVER:
        assert exact, ('pending row not exact', '%08x' % address, symbol)
    pending_out.append({'address': '%08x (pending build only; not counted)' % address, 'symbol': symbol,
                        'size': len(body), 'target_size': len(target), 'exact': False, 'pending_build_only': True,
                        'bytes_exact_in_pending_build': exact, 'evidence': evidence,
                        'pending_reason': 'needs the proposed Server::stop / getClientCount declarations; verified '
                                          'only against the generated out/app-unit4a0/pending/Network/Server2008.h'})
    assert symbol not in load_bodies(OBJ['server']), ('pending symbol leaked into the main build', symbol)
if DISCOVER:
    for p in pending_out:
        print('PENDING', p['address'], p['bytes_exact_in_pending_build'], p['size'], p['target_size'])
    sys.exit(0)


def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            # older receipts: any entry marked exact outside pending sections
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk({k: v for k, v in data.items() if 'pending' not in k})
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault(int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_functions = sorted(a for a in FUNCTIONS if RANGE[0] <= a < RANGE[1])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
proven = {}
for k, c in CLOSURES.items():
    for a in c.proven:
        prev = proven.setdefault(a, (k, c))
        if prev[0] != k:
            # the same address proven in two units must carry exact bodies in both (COMDAT duplicates)
            assert c.exact_at(c.proven[a], a) and prev[1].exact_at(prev[1].proven[a], a)
counted = sorted(a for a in proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere)
assert not set(counted) & set(elsewhere)
support = sorted(a for a in proven if a not in counted)
for a, _, _ in PENDING_ROWS:
    assert a not in counted


def row_entry(a, note=None):
    k, c = proven[a]
    entry = {'address': '%08x' % a if note is None else '%08x (%s)' % (a, note), 'unit': k, 'symbol': c.proven[a],
             'folded_symbols': c.aliases[a][1:], 'identity': c.why[a]}
    if note is None:
        entry['exact'] = True
    entry.update(c.checked[a])
    return entry


rows_out = [row_entry(a) for a in counted]
support_out = [row_entry(a, ('counted by ' + ', '.join(sorted(set(elsewhere[a])))) if a in elsewhere else
                         'outside the range %08x..%08x; support, not counted' % RANGE) for a in support]

UNIT_MAP = {
    'client 004a0000..004a155f': (
        'Network/Client.cpp tail (the unit starts at 0049ed30 in the app-unit49c-2008 map). Boundary evidence: '
        'the descriptor vtables 008230b0 / 008230c0 / 008230d0 / 008230e0 / 008230ec (RTTI SignalDesc<Client, ...> / '
        'BoundFuncDesc<Client, ...>) stored by the constructors 004a0020 / 004a0150 / 004a02e0 / 004a03b0 / 004a06b0 '
        '(static initializers 007f1bd0 / 007f1c20 / 007f1c00 / 007f1b60 / 007f1ba0), Client() 004a0990 (string '
        '"NetworkClient"), Client::connect 004a0a70 (strings "localhost", "192.168", "Failed to start network '
        'client"), OnReceive 004a1070 (evidence name; "Client::OnReceive packet %d: %s"). The '
        'void(std::string, int, std::string) signal (SignalDesc 004a0150, connectGeneric 004a1480 = vtable 008230c0 '
        'slot 1, slot / adapter / function3 bodies 004a0860 / 004a0900 / 004a0c90 / 004a0e50 / 004a0f00 / 004a0fb0) '
        'needs SignalDescImpl<3, S>, which reflection/signal.h does not have (proposal). Owner of the Client class: '
        'native-headers/Network/Client2008.h (network-client-server2008).'),
    'feature-getter 004a1560': (
        'a 7-byte getter identical-code folded with Feature::getTopBottom (feature receipt); the "Port" property '
        'getter of Server (static initializer 007f1cf0 pushes it).'),
    'server 004a1570..004a3fff': (
        'Network/Server.cpp with Server::ClientProxy (continues past 004a4000 to 004a504f: onServiceProvider '
        '004a4100, Server() 004a4b30, OnReceive 004a4dc0). Boundary evidence: ClientProxy vtables 00823474 / '
        '008233c4 (RTTI .?AVClientProxy@Server@Network@RBX@@; dtor 004a18c0, ctor 004a1ed0, create<ClientProxy> '
        '004a21c0 malloc 0x2d78), Server vtable 0082367c (dtor 004a3540), strings "Started network server %s" / '
        '"Failed to start network server" (Server::start 004a1d80), "Received remotePlayer %s from %s" '
        '(ClientProxy::OnReceive 004a2c20), the "Port" PropDescriptor<Server, int> (vtable 00823898, GetImpl vtable '
        '008234d0, static initializer 007f1cf0), and the Message / Hint creation COMDATs the Server unit emits '
        '(the unit creates Hints / Messages for remote players): shared_count / shared_ptr / create<Message> / '
        'Creator::create, Message / Hint destructors and thunks, Name::doDeclare<sMessage / sHint>, '
        'classDescriptor<Message / Hint> (effects / creatable-shared-count receipts and this one). Owners: '
        'Network/Server2008.h / ClientProxy2008.h (network-client-server2008, network-client-proxy) and '
        'v8datamodel/Message.h (effects).'),
    'excluded / library code': (
        'no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row and no separately linked library object in the '
        'range: the std::_Tree / vector / boost.signals / boost.shared_ptr bodies are Roblox-instantiated templates '
        '(element types std::string, shared_ptr<Instance>, ClientProxy, Message, Hint, Player; signatures of the '
        'Client events), owned by the units above.'),
    'counted here': 'the rows listed in exact_function_rows (details in rows).',
}

NOT_BUILT = [
    ('004a0150 / 004a1480 / 004a0860 / 004a0900 / 004a0c90 / 004a0e50 / 004a0f00 / 004a0fb0',
     'the void(std::string, int, std::string) Client event: SignalDesc constructor (three names, ret 0x10) and '
     'SignalDescImpl<3, S>::connectGeneric (vtable 008230c0 slot 1) with the signal3 slot / GenericSlotAdapter / '
     'function3 bodies it reaches: reflection/signal.h stops at two arguments (core header; proposal)'),
    ('004a0a70', 'Client::connect(std::string server, int serverPort, int clientPort, int threadSleepTime) (the '
     'BoundFuncDesc<Client, void(string, int, int, int), 4> target): not declared in Network/Client2008.h'),
    ('004a1070', 'Client::OnReceive (1026 B, declared): not attempted (packet switch, Players / Replicator calls)'),
    ('004a1570 / 004a18c0 / 004a19a0..004a1a30 / 004a1ed0 / 004a1f70 / 004a20a0 / 004a21c0',
     'ClientProxy members, thunks, shared_ptr<ClientProxy> and create<ClientProxy>: blocked on the native 2008 '
     'Replicator layout (network-client-proxy receipt)'),
    ('004a1880 / 004a2250', 'Server::stop / getClientCount: exact only in the pending build (pending_build_only)'),
    ('004a1a40 / 004a2eb0 / 004a2fa0 / 004a22c0 / 004a1f90 + 004a200f',
     'std::set<std::string> instances (_Lbound 004a1a40, find 004a2fa0, insert 004a2eb0, _Insert 004a22c0, _Buynode '
     'with its catch funclet): generic STL instances on std::string that other units also call (find from 00669fa0, '
     'insert from 0066a070), i.e. not Roblox-instantiated templates only this unit references; library code, not '
     'recovered here'),
    ('004a1c70 / 004a2150 / 004a1d10 / 004a2180 / 004a2950 / 004a2ac0 / 004a27e0 / 004a3020 / 004a3170 / '
     '004a31d0 / 004a3290 / 004a3340 / 004a2c20 + 004a2e05 + 004a2e5f / 004a1d80',
     'ClientProxy / Replicator / Player plumbing (shared_ptr<Player> polymorphic cast, visitDescendents with a '
     'Replicator bind, findTargetPlayer, OnReceive with its catch funclets, Server::start): need ClientProxy '
     'members, Replicator declarations or Server::start (not declared); not attempted'),
    ('004a1d70', '~DescribedCreatable<Server> / ~Described<Server> one-jump body (unwind funclets 007c7cb3 / '
     '007c7e03): no unit here emits it (Server destructor counted elsewhere); not built'),
]
proven_in_range = {a for a in proven if RANGE[0] <= a < RANGE[1]}
unbuilt = ['%08x not built' % a for a in range_functions if a not in proven_in_range and a not in range_counted]

REJECTED = {
    'BoundFuncDesc<Client, void(int), 1> through `template class` (the no-default constructor)':
        '159/193 B at 004a06b0: the original stores a Value(int) default (new 8, any::holder<int> vtable 008106cc, '
        'ret 0x18), i.e. the constructor with a default argument',
    'isReplicator with internal linkage (donor `static`)':
        'not emitted in the main build (its only user getClientCount is pending); the mangling is the same, so it is '
        'defined with external linkage',
}
PROPOSALS = {
    'native-headers/Network/Server2008.h (network-client-server owner)': (
        'Declare `void stop(int blockDuration);` (004a1880, evidence name ?stop@Server@Network@RBX@@QAEXH@Z: '
        'rakPeer +0x140 IsActive slot 11 / Shutdown(blockDuration, 0) slot 10, then removeAllChildren 0055afd0) and '
        '`int getClientCount();` (004a2250, evidence name ?getClientCount@Server@Network@RBX@@QAEHXZ: '
        'children +0x108, _Count_if 004a1af0 with isReplicator 004a17f0). Both bodies are exact in this receipt\'s '
        'pending build (native-classes/AppUnit4A0ServerDescriptors.cpp under NATIVE_APPUNIT4A0_PENDING); they can '
        'then be counted. The "Port" property getter (static initializer 007f1cf0 passes 004a1560 with adjustor 0: '
        'return outgoingPort) also needs an `int getPort() const` declaration for its PropDescriptor object.'),
    'native-headers/Network/Client2008.h (network-client-server owner)': (
        'Declare `void connect(std::string server, int serverPort, int clientPort, int threadSleepTime);` (004a0a70, '
        'the BoundFuncDesc<Client, void(string, int, int, int), 4> target registered by 007f1b60) so it can be built.'),
    'native-headers/reflection/signal.h (core owner)': (
        'Add the SignalDescImpl<3, S> specialization (and the SignalDesc three-name-plus constructor) for the 2008 '
        'three-argument Client event void(std::string, int, std::string) (SignalDesc ctor 004a0150, ret 0x10; '
        'connectGeneric 004a1480 in vtable 008230c0).'),
}

paths = [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS
receipt = {
    'class': 'RBX Network::Client / Network::Server unit template and descriptor instances of the application range '
             '004a0000..004a4000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags; find unit with the boost-noinline-shared-destructor '
                'profile',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in paths},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any quoted bare address in another receipt as counted there.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'not_built_reasons': ['%s: %s' % x for x in NOT_BUILT],
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'pending_build_only': pending_out,
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. No new header.',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit4a0: %d counted exact rows; %d support rows; %d pending-build-only; %d range rows, %d counted '
      'elsewhere, %d not built' % (len(counted), len(support_out), len(pending_out), len(range_functions),
                                   len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))

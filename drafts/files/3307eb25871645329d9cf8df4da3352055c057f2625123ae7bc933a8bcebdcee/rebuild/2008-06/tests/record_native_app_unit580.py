"""Map and verify the 2008-06 application range 00580000..00584000 (inactive native recovery, app unit 580).

Unit map (written to the receipt's unit_map with the evidence asserted below):
  * the StandardVerbs / command verbs object (starts at 0057d250 in the app-unit57c range, ends at 005831ff): the
    Creatable / FactoryProduct instances of the Feature.cpp classes (Hole / MotorFeature / VelocityMotor) and the
    ServiceProvider::create<FilteredSelection<..>> instances 00580040..0058084f, then the verb bodies 00580850..
    (JoinCommand, ClearStarterpack, Group / Ungroup / Duplicate / Delete / Rotate / MoveUp / MoveDown, camera and
    controller verbs, ServiceClient<..>::createService instances, BoolPropertyVerb, CameraCenter, CanNotSelect, run
    state verbs, Weld / Snap, Attach / Track / Follow / Watch camera, CameraZoomExtents 00582f50 last);
  * v8tree/VerbContainer.cpp object 00583210..005834af (setVerbParent, getVerb, ~Verb, ~VerbContainer, Verb ctor,
    VerbContainer ctor);
  * v8datamodel/ModelInstance.cpp from 005834b0 (built and counted by app-unit57c-2008; not built here).
No library unit (Ogre, G3D, boost, CRT, MFC/ATL, XTP, zlib, Lua, RakNet) and no excluded MFC class
(CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView) is in the range.

Builds (VS2008 RTM 21022, document-swap flags plus each source's own `native-flags` line):
  * committed native-classes of other owners, compiled read-only and unchanged (JoinCommand.cpp, ClearStarterpack.cpp,
    GroupSelectionVerb.cpp, UngroupSelectionVerb.cpp, SelectionVerbStates.cpp, RotateAxisAction.cpp,
    MoveUpSelectionVerb.cpp, MoveDownSelectionVerb.cpp, ControllerApply.cpp, ControllerActions.cpp,
    ControllerEnabled.cpp, BoolPropertyVerb.cpp, CameraCenterCommand.cpp, RunStateCommands.cpp, VerbQueries.cpp,
    WeldSnapActions.cpp, DuplicateSelectionVerb.cpp, CameraZoomExtentsAction.cpp, FilteredSelectionFactory.cpp,
    FilteredSelectionService.cpp, SoundServiceProvider.cpp, Verb.cpp, VerbBaseLifetime.cpp, VerbContainer.cpp);
  * new sources of this lease: native-classes/AppUnit580Creators.cpp (Feature Creatable / Creator instances) and
    native-classes/AppUnit580CameraVerbs.cpp (camera verb bodies and the VerbContainer-taking EditSelectionVerb /
    DeleteBase constructors, whose committed copy sits in the CRobloxDoc file DocumentInitialize.cpp, not compiled).
No new header is created (nothing shadowed).

Rows are seeded from the original vtables (located by their RTTI complete object locator, one vtable per class, slot
asserted) and from direct call sites read in the original, then reached by relocation closure. Every REL32/DIR32
target of an exact row is bound to the address the original instruction uses, one address per symbol per build, and
verified (own rows, imports by name, literals by bytes, RTTI by name, vtables by RTTI, evidence names, or symbols an
exact row of another receipt names at that address; the rest is the EXTERNAL map with the call site it was read
from). A row is counted only when it is exact in a main build, lies in the range, and no other receipt counts it.
Writes work/2008-06/shared-layouts/app-unit580-working.json.
"""
import json
import re
import struct
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
NC = R / 'native-classes'
OUT = nb.OUT
OUT.mkdir(parents=True, exist_ok=True)
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit580-working.json'
RANGE = (0x580000, 0x584000)
HEADER_DIR = R / 'native-headers'

COMMITTED = ['JoinCommand', 'ClearStarterpack', 'GroupSelectionVerb', 'UngroupSelectionVerb', 'SelectionVerbStates',
             'RotateAxisAction', 'MoveUpSelectionVerb', 'MoveDownSelectionVerb', 'ControllerApply', 'ControllerActions',
             'ControllerEnabled', 'BoolPropertyVerb', 'CameraCenterCommand', 'RunStateCommands', 'VerbQueries',
             'WeldSnapActions', 'DuplicateSelectionVerb', 'CameraZoomExtentsAction', 'FilteredSelectionFactory',
             'FilteredSelectionService', 'SoundServiceProvider', 'Verb', 'VerbBaseLifetime', 'VerbContainer']
OWN = ['AppUnit580Creators', 'AppUnit580CameraVerbs']
SOURCES = {k: NC / (k + '.cpp') for k in COMMITTED + OWN}
HEADERS = [HEADER_DIR / h for h in ('StandardVerbs.h', 'NativeCameraCommands.h', 'v8datamodel/Feature.h',
                                    'v8datamodel/Selection.h', 'v8tree/Verb.h', 'v8tree/VerbContainer.h')]


def pinned_profile(src):
    """The source's own `native-flags` line (if any): /I directories go first; every other flag must already be in the
    document-swap base flags (checked) or be /fp:fast (appended)."""
    m = re.search(r'^// native-flags: (.*)$', src.read_text(), re.M)
    first, extra = [], []
    if not m:
        return first, extra
    base = set(nb.flags())
    for f in m.group(1).split():
        if f.startswith('/I'):
            first.append('/I' + f[2:].replace('{headers}', str(HEADER_DIR)))
        elif f not in base:
            assert f == '/fp:fast', (src.name, f)
            extra.append(f)
    return first, extra


def build(name, src):
    first, extra = pinned_profile(src)
    obj = OUT / ('NativeU580_' + name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + first + flags[i:] + extra + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, (name, log[-4000:])
    return name, obj, flags


with ThreadPoolExecutor(4) as pool:
    built = list(pool.map(lambda kv: build(*kv), SOURCES.items()))
objs = {n: o for n, o, f in built}
all_flags = {n: f for n, o, f in built}

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
pe = original.pe
IMG = pe.get_memory_mapped_image()
BASE = original.image
d = lambda a: struct.unpack_from('<I', IMG, a - BASE)[0]
TEXT = next(s for s in pe.sections if s.Name.startswith(b'.text'))
TEXT_LO = BASE + TEXT.VirtualAddress
TEXT_HI = TEXT_LO + TEXT.Misc_VirtualSize
TEXT_DATA = TEXT.get_data()
RDATA = next(s for s in pe.sections if s.Name.startswith(b'.rdata'))
RDATA_LO = BASE + RDATA.VirtualAddress
RDATA_HI = RDATA_LO + RDATA.Misc_VirtualSize
FUNCS = sorted((int(x['addr'], 16), x['size'], x['kind']) for x in map(json.loads, (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()))
FUNC_AT = {a: (s, k) for a, s, k in FUNCS}
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def norm(symbol):
    return symbol.replace('3QBDB', '3PBDB').replace('3PADA', '3PBDB')


# ---- original evidence helpers ------------------------------------------------------------------------------------
def vtable_of(cls):
    """The one complete-object vtable (in .rdata, offset 0) whose RTTI type descriptor names `.?AV<cls>@`."""
    name = ('.?AV' + cls + '@\0').encode()
    found = []
    for m in re.finditer(re.escape(name), IMG):
        td = BASE + m.start() - 8
        for m2 in re.finditer(re.escape(struct.pack('<I', td)), IMG):
            col = BASE + m2.start() - 12
            if not RDATA_LO <= col < RDATA_HI or d(col) != 0 or d(col + 4) != 0:
                continue
            for m3 in re.finditer(re.escape(struct.pack('<I', col)), IMG):
                v = BASE + m3.start() + 4
                if RDATA_LO <= v < RDATA_HI:
                    found.append(v)
    assert len(found) == 1, (cls, [hex(x) for x in found])
    assert original.vtable_class(found[0]) == ('.?AV' + cls + '@', 0)
    return found[0]


REFS = {}   # target -> set of rel32 call/jmp sites in .text
for m in re.finditer(b'[\xe8\xe9]', TEXT_DATA):
    i = m.start()
    if i + 5 > len(TEXT_DATA):
        break
    t = (TEXT_LO + i + 5 + struct.unpack_from('<i', TEXT_DATA, i + 1)[0]) & 0xffffffff
    if 0x57d000 <= t < 0x584000:
        REFS.setdefault(t, set()).add(TEXT_LO + i)


def call_site(target):
    """A direct call to `target` read in the original (decoded as an instruction of its containing row)."""
    for s in sorted(REFS.get(target, ())):
        owner = max((a for a, sz, k in FUNCS if a <= s), default=None)
        if owner is None or s >= owner + FUNC_AT[owner][0]:
            continue
        for ins in CS.disasm(original.data(owner, FUNC_AT[owner][0]), owner):
            if ins.address == s and ins.mnemonic == 'call' and ins.op_str == hex(target):
                return 'call %08x in %08x' % (s, owner)
    raise AssertionError('no decoded call to %08x' % target)


# ---- verification maps ----------------------------------------------------------------------------------------
def receipt_symbols():
    """symbol -> addresses where an exact row of another receipt names that symbol (any key layout)."""
    out = {}

    def walk(o, f):
        if isinstance(o, dict):
            a, s = o.get('address'), o.get('symbol')
            if isinstance(a, str) and isinstance(s, str) and o.get('exact') is True:
                m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})$', a.strip())
                if m:
                    out.setdefault(s, {}).setdefault(int(m.group(1), 16), set()).add(f)
            for v in o.values():
                walk(v, f)
        elif isinstance(o, list):
            for v in o:
                walk(v, f)
    for path in sorted((ROOT / 'work/2008-06/shared-layouts').glob('*.json')):
        if path == RECEIPT:
            continue
        try:
            walk(json.loads(path.read_text()), path.name)
        except Exception:
            continue
    return out


RECEIPT_SYMBOLS = receipt_symbols()
# Externals of the compiled rows that no build here defines (rows outside this range or not built), each bound at the
# original instruction of the first exact row that uses it (one address per symbol across all builds; asserted).
# Corroboration, where it exists, is noted: an evidence name, or an exact row of another receipt at that address.
EXTERNAL = {
    '??RDeleter@?$Creatable@VInstance@RBX@@@RBX@@QAEXPAVInstance@2@@Z': (0x405e30, 'Creatable<Instance>::Deleter, '
        'called by the shared_count instances 005800f0 / 00580360 (creatable-shared-count binds the same)'),
    '?front@Selection@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ': (0x413c20, 'JoinCommand::isEnabled 00580850'),
    '?back@Selection@RBX@@QBE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ': (0x57e660, 'JoinCommand::isEnabled 00580850; '
        'verbs-unit row of the app-unit57c range'),
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@QBEPAVSelection@1@XZ': (0x4153b0, 'JoinCommand::isEnabled 00580850'),
    '??$create@VSelection@RBX@@@ServiceProvider@RBX@@SAPAVSelection@1@PBVInstance@1@@Z': (0x421cb0,
        'ServiceClient<Selection>::createService 00581cc0'),
    '??$create@VWorkspace@RBX@@@ServiceProvider@RBX@@QBEPAVWorkspace@1@XZ': (0x490af0,
        'EditSelectionVerb(VerbContainer*, ..) 00580b50'),
    '??$create@VStarterPackService@RBX@@@ServiceProvider@RBX@@QBEPAVStarterPackService@1@XZ': (0x490d70,
        'ClearStarterpack::isEnabled 00580ae0'),
    '?clientIsPresent@Client@Network@RBX@@SA_NPBVInstance@3@_N@Z': (0x495e60, 'checkRunPermissions 0057d250 / '
        'RunCommand::isEnabled 00582700; network-players counts 00495e60 as Players::clientIsPresent (the committed '
        'verb sources declare it under Network::Client: a naming note for their owner, codegen identical)'),
    '?serverIsPresent@Server@Network@RBX@@SA_NPBVInstance@3@_N@Z': (0x495e70, 'checkRunPermissions 0057d250; '
        'network-players counts 00495e70 as Players::serverIsPresent (same naming note)'),
    '??$getValue@_N@ConstProperty@Reflection@RBX@@QBE_NXZ': (0x4ad000, 'testBooleanProperty (BoolPropertyVerb unit)'),
    '??$setValue@_N@Property@Reflection@RBX@@QAEXAB_N@Z': (0x4ad1e0, 'SetBooleanProperty (BoolPropertyVerb unit)'),
    '??0Matrix3@G3D@@QAE@ABV01@@Z': (0x513220, 'CameraCenterCommand::doIt 005823f0 (G3D Matrix3 copy; evidence '
        'name ??4Matrix3, identical code)'),
    '?identity@Matrix3@G3D@@SAABV12@XZ': (0x513e20, 'CameraCenterCommand::doIt 005823f0'),
    '?call_once@boost@@YAXP6AXXZAAJ@Z': (0x557330, 'ServiceProvider::create<FilteredSelection<..>> 005805d0 / 005806c0'),
    '??0Instance@RBX@@QAE@XZ': (0x55b7e0, 'NonFactoryProduct<Instance> ctor in the FilteredSelection factories '
        '(evidence name ??0Instance@RBX@@IAE@XZ: access differs, codegen identical)'),
    '?setSelection@Selection@RBX@@QAEXPAVInstance@2@@Z': (0x567770, 'GroupSelectionVerb::doIt 00580c00 '
        '(native Selection.h comment 00567770)'),
    '?newIndex@ServiceProvider@RBX@@SAIXZ': (0x572690, 'ServiceProvider::doGetClassIndex<FilteredSelection<..>>'),
    '?unionWith@Extents@RBX@@QAEXABV12@@Z': (0x57dee0, 'CameraCenterCommand::doIt 005823f0; verbs-unit row of the '
        'app-unit57c range'),
    '?snapInstance@RBX@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (0x57e530, 'SnapSelectionVerb::doIt 00582a70'),
    '?weldInstance@RBX@@YAXV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (0x57eb80, 'WeldSelectionVerb::doIt 00582990'),
    '?group@Workspace@RBX@@QAE?AV?$shared_ptr@VModelInstance@RBX@@@boost@@V?$_Vector_const_iterator@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@0@Z':
        (0x57ea90, 'GroupSelectionVerb::doIt 00580c00'),
    '?findFirst@?$FilteredSelection@VPVInstance@RBX@@@RBX@@QAEPAVPVInstance@2@P6A_NPAV32@@Z@Z': (0x57edb0,
        'ControllerCommand::isEnabled 00582ef0 (ICF-shared with findFirst<ModelInstance>, exact in '
        'ungroup-selection-trial)'),
    '??RUngroupOperation@RBX@@QBEXABV?$shared_ptr@VInstance@RBX@@@boost@@@Z': (0x57fb10,
        'UngroupSelectionVerb::doIt 00580d10'),
    '?newRootElement@SerializerV2@@SAPAVXmlElement@@XZ': (0x591a30, 'DuplicateSelectionVerb::doIt 00582bb0'),
    '?setImageServerView@Workspace@RBX@@QAEXABVRect2D@G3D@@@Z': (0x5a5890, 'CameraModelViewCommand::doIt 00581bc0'),
    '?playSound@SoundService@Soundscape@RBX@@QAEXW4SoundType@3@@Z': (0x5bd820, 'verb doIt bodies (exact in '
        'sound-service-play-trial)'),
    '??0SoundService@Soundscape@RBX@@QAE@XZ': (0x5bc160, 'Creatable<Instance>::create<SoundService> (out-of-range '
        'support row of the SoundServiceProvider build)'),
    '?zoom@Camera@RBX@@QAE_NM@Z': (0x5cce80, 'CameraZoomIn / ZoomOut doIt 00581b10 / 00581b60'),
    '?safeRotate@MegaDragger@RBX@@QAEXABVMatrix3@G3D@@@Z': (0x60e310, 'RotateAxisCommand::rotateAboutAxis'),
    '??0MegaDragger@RBX@@QAE@PAVPartInstance@1@ABV?$vector@PAVPVInstance@RBX@@V?$allocator@PAVPVInstance@RBX@@@std@@@std@@PAVRootInstance@1@@Z':
        (0x60e540, 'RotateAxisCommand::rotateAboutAxis'),
    '??$shared_from@VWorkspace@RBX@@@RBX@@YA?AV?$shared_ptr@VWorkspace@RBX@@@boost@@PAVWorkspace@0@@Z': (0x618a40,
        'EditSelectionVerb(VerbContainer*, ..) 00580b50 (ICF-shared shared_from<T>; exact in humanoid2008 / '
        'local-backpack as other instances)'),
}
UNBOUND = []
PENDING = {}       # symbol -> (address, first use) for externals resolved across builds
LOCAL_EH = nb.LOCAL_EH


class Build:
    def __init__(self, name, obj):
        self.name, self.obj = name, Path(obj)
        self.raw = self.obj.read_bytes()
        self.sections, self.symbols, self.definitions, self.starts = match._coff_data_index(self.raw)
        self.bodies = {n: (b, r) for n, b, r in match.coff_functions(self.raw)}
        self.binding = {}
        self.rows = {}
        self.queue = []

    def sym(self, prefix, *parts):
        hits = [n for n in self.bodies if n.startswith(prefix) and all(p in n for p in parts) and not LOCAL_EH.match(n)]
        assert len(hits) == 1, (self.name, prefix, parts, hits)
        return hits[0]

    def bind(self, symbol, value, origin):
        prev = self.binding.setdefault(symbol, (value, origin))
        assert prev[0] == value, (self.name, 'inconsistent', symbol, hex(prev[0]), prev[1], hex(value), origin)

    def literal(self, symbol):
        pos, at = self.definitions[symbol]
        table = self.sections[at]
        return self.raw[table[4] + pos:table[4] + table[3]].split(b'\0')[0] + b'\0'

    def classify(self, symbol, value, where):
        if symbol in self.bodies and not LOCAL_EH.match(symbol):
            self.bind(symbol, value, where)
            self.queue.append((value, symbol))
            return 'own row'
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (where, symbol, hex(value), hit)
            return '%s!%s' % hit
        if symbol.startswith('??_C@'):
            lit = self.literal(symbol)
            assert original.data(value, len(lit)) == lit, (where, symbol, hex(value))
            return 'literal %r' % lit[:-1].decode('latin1')
        if symbol.startswith('??_R0') and symbol.endswith('@8'):
            rtti = original.string(value + 8)
            assert norm(rtti) == norm('.' + symbol[5:-2]), (where, symbol, hex(value), rtti)
            return 'RTTI %s' % rtti
        if symbol.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = symbol[4:symbol.index('@@6B') + 2]
            assert norm(rtti) == norm('.?AV' + cls), (where, symbol, hex(value), rtti)
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if (symbol.startswith('__real@') or symbol.startswith('__xmm@')) and symbol in self.definitions:
            pos, at = self.definitions[symbol]
            table = self.sections[at]
            size = 8 if len(symbol) == 7 + 16 else 4 if symbol.startswith('__real@') else 16
            data = self.raw[table[4] + pos:table[4] + pos + size]
            assert original.data(value, size) == data, (where, symbol, hex(value), original.data(value, size).hex())
            return 'constant %s' % data.hex()
        if norm(names.get(value, '')) == norm(symbol) and symbol not in self.definitions:
            return 'external (evidence name)'
        if symbol in RECEIPT_SYMBOLS and value in RECEIPT_SYMBOLS[symbol] and symbol not in self.definitions:
            return 'external (exact row of %s)' % ', '.join(sorted(RECEIPT_SYMBOLS[symbol][value]))
        if symbol in EXTERNAL and symbol not in self.definitions:
            assert EXTERNAL[symbol][0] == value, (where, symbol, hex(value), hex(EXTERNAL[symbol][0]))
            return 'external (%s)' % EXTERNAL[symbol][1]
        if symbol in self.definitions and symbol not in self.bodies:
            return 'own static'
        # cross-build: an external here, resolved later as a row of another build (one address per symbol overall)
        prev = PENDING.setdefault(symbol, (value, '%s in %s' % (self.name, where)))
        assert prev[0] == value, ('inconsistent external', symbol, hex(prev[0]), prev[1], hex(value), self.name, where)
        return 'CROSS'

    def row(self, address, name):
        key = (address, name)
        if key in self.rows:
            return
        body, refs = self.bodies[name]
        try:
            target, target_refs, _ = match.target('2008-06', '%08x' % address)
        except SystemExit as error:
            self.rows[key] = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': None,
                              'exact': False, 'bounds': str(error)}
            return
        exact = len(target) == len(body) and match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target),
                 'exact': exact}
        self.rows[key] = entry
        if not exact:
            return
        start, section = self.definitions[name]
        table = self.sections[section]
        code = self.raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = self.symbols[index][0]
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            how = self.classify(symbol, value, name)
            if how is None:
                UNBOUND.append('%s: %s in %s -> %s' % (self.name, symbol, name, hex(value)))
                continue
            self.bind(symbol, value, name)
            verified[symbol] = '%s (%s)' % (hex(value), how)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})

    def run(self, seeds):
        for address, name, origin in seeds:
            self.bind(name, address, origin)
            self.queue.append((address, name))
        while self.queue:
            value, symbol = self.queue.pop(0)
            self.row(value, symbol)
        return self


builds = {name: Build(name, obj) for name, obj in objs.items()}
B = builds


def slot_seed(build, cls, slot, prefix, *parts):
    """Seed `build`'s body for slot `slot` of the vtable whose RTTI names `cls`."""
    v = vtable_of(cls)
    target = d(v + 4 * slot)
    return build, (target, build.sym(prefix, *parts), 'vtable %08x (%s) slot %d' % (v, cls, slot))


def call_seed(build, target, prefix, *parts):
    return build, (target, build.sym(prefix, *parts), call_site(target))


SEEDS = [
    slot_seed(B['JoinCommand'], 'JoinCommand@RBX@', 2, '?isEnabled@JoinCommand@'),
    slot_seed(B['JoinCommand'], 'JoinCommand@RBX@', 4, '?doIt@JoinCommand@'),
    slot_seed(B['ClearStarterpack'], 'ClearStarterpack@RBX@', 2, '?isEnabled@ClearStarterpack@'),
    slot_seed(B['ClearStarterpack'], 'ClearStarterpack@RBX@', 4, '?doIt@ClearStarterpack@'),
    slot_seed(B['GroupSelectionVerb'], 'GroupSelectionVerb@RBX@', 4, '?doIt@GroupSelectionVerb@'),
    slot_seed(B['SelectionVerbStates'], 'GroupSelectionVerb@RBX@', 2, '?isEnabled@GroupSelectionVerb@'),
    slot_seed(B['UngroupSelectionVerb'], 'UngroupSelectionVerb@RBX@', 4, '?doIt@UngroupSelectionVerb@'),
    slot_seed(B['SelectionVerbStates'], 'DuplicateSelectionVerb@RBX@', 2, '?isEnabled@DuplicateSelectionVerb@'),
    slot_seed(B['DuplicateSelectionVerb'], 'DuplicateSelectionVerb@RBX@', 4, '?doIt@DuplicateSelectionVerb@'),
    slot_seed(B['SelectionVerbStates'], 'DeleteSelectionVerb@RBX@', 4, '?doIt@DeleteBase@'),
    slot_seed(B['VerbQueries'], 'DeleteSelectionVerb@RBX@', 2, '?isEnabled@EditSelectionVerb@'),
    slot_seed(B['RotateAxisAction'], 'RotateSelectionVerb@RBX@', 4, '?doIt@RotateAxisCommand@'),
    slot_seed(B['MoveUpSelectionVerb'], 'MoveUpPlateVerb@RBX@', 4, '?doIt@MoveUpSelectionVerb@'),
    slot_seed(B['MoveDownSelectionVerb'], 'MoveDownSelectionVerb@RBX@', 4, '?doIt@MoveDownSelectionVerb@'),
    slot_seed(B['ControllerEnabled'], 'PrimaryControllerCommand@RBX@', 2, '?isEnabled@ControllerCommand@'),
    slot_seed(B['ControllerActions'], 'PrimaryControllerCommand@RBX@', 4, '?doIt@PrimaryControllerCommand@'),
    slot_seed(B['ControllerActions'], 'SecondaryControllerCommand@RBX@', 4, '?doIt@SecondaryControllerCommand@'),
    slot_seed(B['CameraCenterCommand'], 'CameraCenterCommand@RBX@', 4, '?doIt@CameraCenterCommand@'),
    slot_seed(B['AppUnit580CameraVerbs'], 'CameraCenterCommand@RBX@', 2, '?isEnabled@CameraCenterCommand@'),
    slot_seed(B['CameraZoomExtentsAction'], 'CameraZoomExtentsCommand@RBX@', 4, '?doIt@CameraZoomExtentsCommand@'),
    slot_seed(B['BoolPropertyVerb'], 'AnchorVerb@RBX@', 3, '?isChecked@BoolPropertyVerb@'),
    slot_seed(B['BoolPropertyVerb'], 'AnchorVerb@RBX@', 4, '?doIt@BoolPropertyVerb@'),
    slot_seed(B['SelectionVerbStates'], 'CanNotSelectCommand@RBX@', 4, '?doIt@CanNotSelectCommand@'),
    slot_seed(B['SelectionVerbStates'], 'WeldSelectionVerb@RBX@', 2, '?isEnabled@WeldSelectionVerb@'),
    slot_seed(B['SelectionVerbStates'], 'SnapSelectionVerb@RBX@', 2, '?isEnabled@SnapSelectionVerb@'),
    slot_seed(B['WeldSnapActions'], 'WeldSelectionVerb@RBX@', 4, '?doIt@WeldSelectionVerb@'),
    slot_seed(B['WeldSnapActions'], 'SnapSelectionVerb@RBX@', 4, '?doIt@SnapSelectionVerb@'),
    call_seed(B['AppUnit580CameraVerbs'], 0x580b50, '??0EditSelectionVerb@RBX@@IAE@PAVVerbContainer@'),
    call_seed(B['AppUnit580CameraVerbs'], 0x581010, '??0DeleteBase@RBX@@IAE@PAVVerbContainer@'),
    call_seed(B['VerbContainer'], 0x583210, '?setVerbParent@VerbContainer@'),
    call_seed(B['VerbBaseLifetime'], 0x5832c0, '??1Verb@RBX@@UAE@XZ'),
    call_seed(B['AppUnit580Creators'], 0x5803f0, '??$?0VVelocityMotor@RBX@@VDeleter@', '?$shared_ptr@VVelocityMotor@'),
    # CameraVerb's own vtable (constructor-time; RTTI .?AVCameraVerb@RBX@@) holds CameraVerb::doIt in slot 4; the
    # derived camera verbs inline it, so this is its only reference
    slot_seed(B['AppUnit580CameraVerbs'], 'CameraVerb@RBX@', 4, '?doIt@CameraVerb@'),
    call_seed(B['VerbContainer'], 0x583460, '??0VerbContainer@RBX@@QAE@PAV01@@Z'),
]
for cls in ('AttachCameraCommand', 'TrackCameraCommand', 'FollowCameraCommand', 'WatchCameraCommand'):
    SEEDS.append(slot_seed(B['SelectionVerbStates'], cls + '@RBX@', 2, '?isEnabled@%s@' % cls))
    SEEDS.append(slot_seed(B['SelectionVerbStates'], cls + '@RBX@', 4, '?doIt@%s@' % cls))
for cls in ('RunCommand', 'StopCommand', 'ResetCommand'):
    SEEDS.append(slot_seed(B['RunStateCommands'], cls + '@RBX@', 2, '?isEnabled@%s@' % cls))
    SEEDS.append(slot_seed(B['RunStateCommands'], cls + '@RBX@', 4, '?doIt@%s@' % cls))
for cls in ('CameraPanLeftCommand', 'CameraPanRightCommand', 'CameraTiltUpCommand', 'CameraTiltDownCommand',
            'CameraZoomInCommand', 'CameraZoomOutCommand', 'CameraModelViewCommand'):
    SEEDS.append(slot_seed(B['AppUnit580CameraVerbs'], cls + '@RBX@', 4, '?doIt@%s@' % cls))
for cls, base, cname in (('MotorFeature', 'Feature', 'sMotorFeature'), ('Hole', 'Feature', 'sHole'),
                         ('VelocityMotor', 'JointInstance', 'sVelocityMotor')):
    rtti = 'Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?%s@2@3QBDB@RBX@' % (cls, base, cname)
    SEEDS.append(slot_seed(B['AppUnit580Creators'], rtti, 0, '?create@Creator@?$FactoryProduct@V%s@' % cls))

for build, seed in SEEDS:
    build.run([seed])

# cross-build closure: an external of one build that another build defines is bound there (and must be exact there)
RESOLVED = {}
changed = True
while changed:
    changed = False
    for symbol, (value, origin) in sorted(PENDING.items()):
        if symbol in RESOLVED:
            continue
        owners = [b for b in builds.values() if symbol in b.bodies and not LOCAL_EH.match(symbol)]
        for b in owners:
            b.run([(value, symbol, 'external of %s, bound at its original target' % origin)])
        rows = [r for b in owners for k, r in b.rows.items() if k == (value, symbol)]
        if rows:
            RESOLVED[symbol] = '%s row of %s' % ('exact' if all(r['exact'] for r in rows) else 'NOT exact',
                                                 ', '.join(b.name for b in owners))
            changed = True

UNRESOLVED = {s: v for s, v in PENDING.items() if s not in RESOLVED}
for b in builds.values():
    for r in b.rows.values():
        for s, txt in list(r.get('verified_targets', {}).items()):
            if txt.endswith('(CROSS)'):
                r['verified_targets'][s] = txt.replace('(CROSS)', '(%s)' % RESOLVED.get(s, 'UNRESOLVED'))
if UNRESOLVED:
    for s, (v, o) in sorted(UNRESOLVED.items(), key=lambda x: x[1]):
        print('UNRESOLVED %08x %s  [%s]' % (v, s, o))
    raise SystemExit('unresolved externals: %d' % len(UNRESOLVED))

# one address per symbol across all builds (own rows and externals alike)
GLOBAL = {}
for b in builds.values():
    for symbol, (value, origin) in b.binding.items():
        GLOBAL.setdefault(symbol, {}).setdefault(value, []).append('%s: %s' % (b.name, origin))
for symbol, values in GLOBAL.items():
    assert len(values) == 1, ('symbol bound to several addresses', symbol, {hex(k): v for k, v in values.items()})
for symbol, (value, origin) in PENDING.items():
    assert set(GLOBAL.get(symbol, {value: 0})) == {value}, symbol

# ---- counting -----------------------------------------------------------------------------------------------------
def walk_methods(o, out):
    if isinstance(o, list):
        for e in o:
            walk_methods(e, out)
    elif isinstance(o, dict):
        if 'address' in o and o.get('exact') is True:
            out.append(o['address'])
        else:
            for v in o.values():
                walk_methods(v, out)


def addr_of(x):
    if isinstance(x, dict):
        x = x.get('address') or x.get('addr') or ''
    m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', str(x))
    return int(m.group(1), 16) if m else None


OTHER = {}   # address -> receipts that count it (top-level exact_function_rows rule)
for path in sorted((ROOT / 'work/2008-06/shared-layouts').glob('*.json')):
    if path == RECEIPT:
        continue
    try:
        data = json.loads(path.read_text())
    except Exception:
        continue
    if not isinstance(data, dict):
        continue
    if 'exact_function_rows' in data:
        rows = data['exact_function_rows']
    elif isinstance(data.get('exact_addresses'), list):
        rows = data['exact_addresses']
    elif isinstance(data.get('exact_unique_addresses'), list):
        rows = data['exact_unique_addresses']
    else:
        rows = []
        walk_methods(data.get('methods', []), rows)
    for r in (list(rows) if isinstance(rows, (list, dict)) else []):
        a = addr_of(r)
        if a is not None:
            OTHER.setdefault(a, set()).add(path.name)

ALL_ROWS = [dict(r, build=b.name) for b in builds.values() for r in b.rows.values()]
by_addr = {}
for r in ALL_ROWS:
    by_addr.setdefault(int(r['address'], 16), []).append(r)

VERBS_UNIT = (0x57d250, 0x583200)
CONTAINER_UNIT = (0x583210, 0x5834b0)


def unit_of(a):
    if VERBS_UNIT[0] <= a < VERBS_UNIT[1]:
        return 'StandardVerbs / command verbs object'
    if CONTAINER_UNIT[0] <= a < CONTAINER_UNIT[1]:
        return 'v8tree/VerbContainer.cpp object'
    if 0x5834b0 <= a < 0x585c60:
        return 'v8datamodel/ModelInstance.cpp object'
    return None


def referrers(a):
    sites = sorted(REFS.get(a, ()))
    return ['%08x' % s for s in sites]


COUNT_NOTES = {}
counted = []
for a in sorted(by_addr):
    rows = by_addr[a]
    key = '%08x' % a
    if not RANGE[0] <= a < RANGE[1] or not any(r['exact'] for r in rows):
        continue
    if a in OTHER:
        COUNT_NOTES[key] = 'counted by ' + ', '.join(sorted(OTHER[a]))
        continue
    exact = [r for r in rows if r['exact']]
    counted.append(key)
    refs = referrers(a)
    COUNT_NOTES[key] = '%s; %s exact in %s; direct callers %s' % (
        unit_of(a), ' / '.join(sorted({r['symbol'] for r in exact})), ', '.join(sorted({r['build'] for r in exact})),
        ', '.join(refs) if refs else 'none (vtable slot)')
assert all(int(a, 16) not in OTHER for a in counted)


def hexed(a):
    return '0x' + a   # non-counted rows never appear as a quoted bare address (bare-address recorders)


def row_out(r):
    out = dict(r)
    out.pop('build', None)
    if out['address'] not in counted:
        out['address'] = hexed(out['address'])
    return out


groups = {b.name: [row_out(r) for r in b.rows.values()] for b in builds.values()}
support = sorted({r['address'] for r in ALL_ROWS if r['exact']} - set(counted))
inexact = {(r['address'], r['symbol']): r for r in ALL_ROWS if not r['exact']}

# ---- range map ----------------------------------------------------------------------------------------------------
REASON = {
    0x583220: 'VerbContainer::getVerb(const Name&): no committed native body (VerbContainer.cpp holds only the ctor '
              'and setVerbParent); not built',
    0x5832e0: '~VerbContainer: no committed native body; not built',
    0x583380: 'VerbContainer::getVerb(const std::string&): no committed native body; not built',
    0x583490: 'VerbContainer ??_G (vtable 00830b7c slot 0): not emitted by the VerbContainer.cpp build',
    0x581e40: 'FilteredSelection<PVInstance>::onServiceProvider-shaped Instance override (412 B: Instance::'
              'onServiceProvider 0055acc0, rootSelection = shared_from(Selection) at +0x134, push_back into the '
              'Selection filteredSelections vector +0x154): the read-only native v8datamodel/Selection.h declares no '
              'such override (proposal), not built',
    0x581fe0: 'the same FilteredSelection override for the second instance (ModelInstance); not built (proposal)',
}
range_map = []
range_rows = [x for x in FUNCS if RANGE[0] <= x[0] < RANGE[1]]
for a, size, kind in range_rows:
    key = '%08x' % a
    rows = by_addr.get(a, [])
    if key in counted:
        status = 'counted here'
    elif a in OTHER:
        status = 'counted by ' + ', '.join(sorted(OTHER[a]))
    elif kind == 'eh':
        status = 'catch funclet row'
    elif a in REASON:
        status = REASON[a]
    elif rows:
        status = 'compiled, not exact: ' + '; '.join('%s %d B vs %s B (%s)' % (r['symbol'][:60], r['size'],
                                                                                r['target_size'], r['build'])
                                                     for r in rows)
    elif unit_of(a) == 'v8datamodel/ModelInstance.cpp object':
        status = 'ModelInstance.cpp row (app-unit57c-2008 range owner builds this object); not built here'
    else:
        status = 'not reached'
    range_map.append('%s %d %s [%s]: %s' % (key, size, kind, unit_of(a) or '-', status))

in_range_other = [a for a, s, k in range_rows if a in OTHER]

# ---- unit boundary evidence (asserted) -----------------------------------------------------------------------------
BOUNDARY = []
# the verbs object: CameraZoomExtentsCommand::doIt 00582f50 (vtable slot 4) is its last row and ends at 00583203;
# the next row 00583210 is VerbContainer::setVerbParent (the VerbContainer.cpp build is exact there)
v = vtable_of('CameraZoomExtentsCommand@RBX@')
assert d(v + 16) == 0x582f50 and 0x582f50 + FUNC_AT[0x582f50][0] <= 0x583210
assert not any(0x582f50 < a < 0x583210 for a in FUNC_AT)
BOUNDARY.append('CameraZoomExtentsCommand vtable %08x slot 4 = 00582f50 (%d B), the last verbs-unit row; next row '
                '00583210 setVerbParent' % (v, FUNC_AT[0x582f50][0]))
assert any(r['exact'] for r in by_addr.get(0x583210, []))
# the VerbContainer object ends with the VerbContainer ctor 00583460 + its ??_G 00583490 (vtable of VerbContainer);
# 005834b0 ModelInstance::getModelInPrimary starts the ModelInstance object (app-unit57c-2008 counts it)
vc = vtable_of('VerbContainer@RBX@')
BOUNDARY.append('VerbContainer vtable %08x (RTTI .?AVVerbContainer@RBX@@) slot 0 = %08x' % (vc, d(vc)))
assert 0x5834b0 in OTHER and 'app-unit57c-2008-working.json' in OTHER[0x5834b0]
# the creator / factory rows at the start of the range belong to the verbs object: their Creator vtables' RTTI
for cls, base, cname, slot0 in (('MotorFeature', 'Feature', 'sMotorFeature', 0x580040), ('Hole', 'Feature', 'sHole', 0x5802b0),
                                ('VelocityMotor', 'JointInstance', 'sVelocityMotor', 0x580520)):
    cv = vtable_of('Creator@?$FactoryProduct@V%s@RBX@@V%s@2@$1?%s@2@3QBDB@RBX@' % (cls, base, cname))
    assert d(cv) == slot0, (cls, hex(d(cv)))
    BOUNDARY.append('FactoryProduct<%s>::Creator vtable %08x slot 0 = %08x' % (cls, cv, slot0))
for lit, at in ((b'Insufficinet permissions\0', None),):
    assert IMG.find(lit) >= 0
BOUNDARY.append('checkRunPermissions 0057d250 ("Insufficinet permissions") opens the verbs object (app-unit57c map)')

receipt = {
    'class': 'App unit 580: StandardVerbs / command verb bodies, Feature Creatable instances and the VerbContainer '
             'object of 00580000..00584000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags plus each source\'s own native-flags line',
    'flags': all_flags,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve()] + list(SOURCES.values()) + HEADERS},
    'objects': {Path(p).name: nb.sha(p) for p in objs.values()},
    'unit_map': {
        'StandardVerbs / command verbs object 0x0057d250..0x005831ff (starts in the app-unit57c range)':
            'Creatable / FactoryProduct instances of the Feature.cpp classes 0x00580040..0x0058057f (Creator vtables '
            'by RTTI; shared_count rows counted by creatable-shared-count), ServiceProvider::create<FilteredSelection<'
            'PVInstance / ModelInstance>> 0x005805d0 / 0x005806c0 and the static create<SoundService / FilteredSelection>'
            '(const Instance*) 0x005807b0 / 0x00580800, then the verb bodies from JoinCommand::isEnabled 0x00580850 to '
            'CameraZoomExtentsCommand::doIt 0x00582f50, interleaved with ServiceClient<RunService / Selection / '
            'FilteredSelection<PVInstance>>::createService 0x00581c00 / 0x00581cc0 / 0x00581d80 and two '
            'FilteredSelection Instance overrides 0x00581e40 / 0x00581fe0.',
        'v8tree/VerbContainer.cpp object 0x00583210..0x005834af': 'setVerbParent, getVerb(Name), ~Verb, ~VerbContainer, '
            'getVerb(string), Verb(VerbContainer*, string), VerbContainer(VerbContainer*) and its ??_G.',
        'v8datamodel/ModelInstance.cpp object from 0x005834b0': 'built and counted by app-unit57c-2008 (not built here).',
        'library code': 'none in the range (the boost / std bodies are Roblox instantiations over the verb types)',
        'excluded classes': 'none: no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView rows. The camera verb bodies '
            'also sit in the committed CRobloxDoc file DocumentInitialize.cpp, which is not compiled here.',
    },
    'boundary_evidence': BOUNDARY,
    'range': '0x00580000..0x00584000',
    'range_functions': len(range_rows),
    'range_rows_counted_by_other_receipts': len(in_range_other),
    'range_rows_counted_here': len(counted),
    'range_map': range_map,
    'exact_function_rows': counted,
    'count_evidence': {a: COUNT_NOTES[a] for a in counted},
    'exact_support_rows': [hexed(a) + ': ' + COUNT_NOTES.get(a, 'outside the range (support)') for a in support],
    'rows': groups,
    'not_exact_rows': [{'address': hexed(r['address']), 'symbol': r['symbol'], 'size': r['size'],
                        'target_size': r['target_size'], 'build': r['build']} for r in inexact.values()],
    'externals': {s: '0x%08x: %s' % v for s, v in sorted(EXTERNAL.items())},
    'cross_build_targets': RESOLVED,
    'proposals': {
        'native-headers/v8datamodel/JointInstance.h (JointInstance owner; same as feature-working proposal_joint_'
        'instance_h)': 'Creatable<Instance>::create<VelocityMotor> 0x005804a0 allocates 0x170 (push 0x170 before '
            'operator new); the current headers give sizeof(VelocityMotor) 0x160 (JointInstance lacks the 2008 '
            '`weak_ptr<PartInstance> part[2]` at +0x140). With the proposed JointInstance layout the AppUnit580Creators '
            'build is exact there (only the immediate differs now).',
        'native-headers/v8datamodel/Selection.h (Selection owner)': 'FilteredSelection<T> overrides an Instance '
            'virtual (0x00581e40 / 0x00581fe0, 412 B each: calls Instance::onServiceProvider 0055acc0, sets '
            'rootSelection (+0x134) from ServiceProvider::create<Selection> 00421cb0 via shared_from 00618a40, and '
            'pushes the ISelectionBase subobject into Selection::filteredSelections (+0x154)); declare it to build '
            'those two rows.',
        'committed verb sources (JoinCommand.cpp, RunStateCommands.cpp, GroupSelectionVerb.cpp, ...; their owners)':
            'they declare clientIsPresent / serverIsPresent under a local Network::Client / Network::Server; the '
            'targets 00495e60 / 00495e70 are Players::clientIsPresent / serverIsPresent in network-players (include '
            'Network/Players.h instead; codegen identical).',
    },
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit580: %d counted exact rows (range %d rows, %d counted elsewhere), %d support rows, '
      '%d compiled rows not exact' % (len(counted), len(range_rows), len(in_range_other), len(support), len(inexact)))
print('counted:', ' '.join(counted))
for line in range_map:
    if 'counted' not in line.split(': ', 1)[1][:12]:
        print('  ', line[:200])

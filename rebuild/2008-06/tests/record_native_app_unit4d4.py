"""Verify the inactive 2008-06 native rows of the application range 004d4000..004d8000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * 004d4000..004d6f4f: RakNet 3.0 library code (the tail of Rand.cpp, RakSleep.cpp, NetworkIDManager.cpp, the
    DataStructures::List<RPCNode*> dtor, StringTable.cpp, SHA1.cpp, DataBlockEncryptor.cpp, rijndael.cpp and
    CheckSum.cpp). Never recovered here.
  * 004d6f50..004d8000 (continues past the range): the ViewNew::ViewRbxGfx unit (ViewNew/ViewRbxGfx.cpp): inline
    SceneManager / Lighting / LightingParameters members whose COMDATs the linker took from this object, the
    ViewRbxGfx leaves, and the template instances the unit emits. The members are recovered by
    tests/record_native_render_scene.py (render-scene owner); this recorder builds only the template instantiations
    no receipt counts: the ViewBase auto_ptr destructors, the boost.function managers of the two `this` binds, the
    workspace descendant visit and the boost.any holder of the Lighting-changed slot.

Build: native-classes/AppUnit4D4ViewTemplates.cpp with the document-swap flags, VS2008 RTM 21022, /fp:fast (the
ViewRbxGfx unit profile of tests/record_native_render_scene.py). It includes RenderLib/ViewNew2008.h and
v8tree/Instance.h read-only and creates no header (nothing is shadowed). No pending build: no body here needs a missing
declaration.

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address; an address may carry several
symbols (identical-code folding), each of whose bodies must be exact there. Every REL32/DIR32 target of every proven
row is verified: imports by DLL export name, vtables by original RTTI names, type descriptors by their decorated name,
own (proven) rows, and the remaining externals by the explicit EXTERNAL map (call-site evidence in comments). Counted
rows are the proven rows inside the range that no other receipt counts.
Writes work/2008-06/shared-layouts/app-unit4d4-working.json. Never writes a quoted bare address of a row it does not
count (some recorders treat any such string in another receipt as counted there).
Set NATIVE_APP_UNIT4D4_DISCOVER=1 to list unbound targets instead of asserting.
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
OUT = nb.OUT / 'app-unit4d4'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit4D4ViewTemplates.cpp'
HEADERS = [HDR / 'RenderLib/ViewNew2008.h', HDR / 'RenderLib/ViewBase2008.h', HDR / 'ViewNew/MaterialFactory2008.h',
           HDR / 'RenderLib/SceneManager2008.h', HDR / 'v8tree/Instance.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT4D4_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit4d4-working.json'
RANGE = (0x4d4000, 0x4d8000)


def build(name, src):
    obj = OUT / (name + '.obj')
    flags = nb.flags() + ['/fp:fast', '/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = build('NativeAppUnit4D4ViewTemplates', SOURCE)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l)['size'] for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}

VIEW = 'ViewRbxGfx@ViewNew@RBX@@'
SPI = 'V?$shared_ptr@VInstance@RBX@@@boost@@'
BIND_BOOL = 'V?$bind_t@XV?$mf1@XV' + VIEW + '_N@_mfi@boost@@'
BIND_DESC = 'V?$bind_t@XV?$mf1@XV' + VIEW + SPI + '@_mfi@boost@@'
HOLDER = '?$holder@V?$function@$$A6AX_N@ZV?$allocator@X@std@@@boost@@@any@boost@@'

# ---- identity roots: (address, symbol pattern, evidence) ----------------------------------------------------------------
# A pattern is a list of substrings; it must select exactly one compiled symbol (resolved below and written to the
# receipt), whose body must be exact at the address.
ROOTS = [
    (0x4d71c0, ['??1?$auto_ptr@VSceneManager@RenderBase@RBX@@@std@@QAE@XZ'],
     'unwind funclets 007c9c96 / 007d5fbf on ViewBase::sceneManager +0x4 (delete through the SceneManager ??_G, slot 6)'),
    (0x4d7870, ['??1?$auto_ptr@VMaterialFactory@ViewNew@RBX@@@std@@QAE@XZ'],
     'unwind funclet 007c9cb7 on ViewBase::materialFactory +0x10 (calls ~MaterialFactory, then operator delete)'),
    (0x4d77b0, ['?manage@?$functor_manager@' + BIND_BOOL],
     'compares the functor type with the RTTI type descriptor 00940b90 (bind_t<mf1<void, ViewRbxGfx, bool>>)'),
    (0x4d7810, ['?manage@?$functor_manager@' + BIND_DESC],
     'compares the functor type with the RTTI type descriptor 00940c30 (bind_t<mf1<void, ViewRbxGfx, shared_ptr>>)'),
    (0x4d7c00, ['??$visitDescendents@' + BIND_DESC],
     'ViewRbxGfx ctor 004d9bba (children +0x108, recursion 004d7cd2; ViewG3D ctor 004dbe31 shares the body by ICF)'),
    (0x4d7d50, ['??$?0V?$function@$$A6AX_N@ZV?$allocator@X@std@@@boost@@@any@boost@@QAE@'],
     'callers 004d8264 / 005da11e: new 0x28, holder ctor 004d7a10 (slot of the Lighting-changed connection)'),
    (0x4d7a80, ['?clone@' + HOLDER], 'any::holder<function<void(bool)>> vtable 00826bd4 slot 2'),
    (0x4d7a70, ['?type@' + HOLDER], 'any::holder<function<void(bool)>> vtable 00826bd4 slot 1'),
]
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # The out-of-line, non-virtual MaterialFactory destructor declared by ViewNew/MaterialFactory2008.h (its body releases
    # four RCPs whose +0xc pointee type is not derived, so it is not built): also called by ~ViewBase 004d89a5 and the
    # ViewRbxGfx / ViewG3D ctor and dtor paths 004d9afe / 004db540 / 004dbd75.
    '??1MaterialFactory@ViewNew@RBX@@QAE@XZ': 0x4d7460,  # 004d787a
}
JOINED = {}
DATA_EXTERNAL = set()


def load_bodies():
    raw = Path(OBJ).read_bytes()
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


def joined_target(rows):
    body, refs = b'', []
    for a in rows:
        t, r = target_of(a)
        refs += [x + len(body) for x in r] if r and isinstance(r[0], int) else list(r)
        body += t
    return body, refs


class Closure:
    def __init__(self, roots):
        self.bodies = load_bodies()
        self.raw = Path(OBJ).read_bytes()
        self.index = match._coff_data_index(self.raw)
        self.used, self.unbound = set(), []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        self.data_checked = {}
        queue = deque()
        for address, pattern, evidence in roots:
            hits = [n for n in self.bodies if not nb.LOCAL_EH.match(n) and all(p in n for p in pattern)]
            assert len(hits) == 1, ('root pattern must select one symbol', pattern, hits)
            queue.append((address, hits[0], 'root: ' + evidence))
        while queue:
            address, symbol, reason = queue.popleft()
            if address in self.proven:
                if symbol not in self.aliases[address]:
                    assert self.exact_at(symbol, address), ('folded alias not exact', '%08x' % address, symbol)
                    self.aliases[address].append(symbol)
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
                            and sym not in EXTERNAL and sym not in JOINED:
                        queue.append((value, sym, 'called by %08x' % address))
        self.own = {}
        for address, syms in self.aliases.items():
            for s in syms:
                prev = self.own.setdefault(s, address)
                assert prev == address, ('one address per symbol', s, hex(prev), hex(address))
        self.joined = {}
        for sym, rows in JOINED.items():
            body, refs, _ = self.bodies[sym]
            target, target_refs = joined_target(rows)
            assert len(target) == len(body) and match.exact_match(target, target_refs, body, refs), ('joined', sym)
            self.joined[sym] = rows[0]
        self.checked = {a: self.verify(a, s) for a, s in sorted(self.proven.items())}

    def exact_at(self, symbol, address):
        if symbol not in self.bodies or address not in FUNCTIONS:
            return False
        body, refs, _ = self.bodies[symbol]
        target, target_refs = target_of(address)
        return match.exact_match(target, target_refs, body, refs)

    def resolve(self, owner, sym, value):
        """Verify one relocation target; returns a description or None (unbound)."""
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
        if 'stored_vtable' in sym:
            return self.verify_table(owner, sym, value)
        if sym in self.own:
            assert self.own[sym] == value, (owner, sym, hex(value), hex(self.own[sym]))
            return 'own row'
        if sym in self.joined:
            assert self.joined[sym] == value, (owner, sym, hex(value))
            return 'joined rows (bounds evidence)'
        if sym in EXTERNAL:
            assert EXTERNAL[sym] == value, (owner, sym, hex(value), hex(EXTERNAL[sym]))
            self.used.add(sym)
            return 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
        return None

    def verify_table(self, owner, sym, value):
        """A constant boost.function manager table: bytes equal and every slot one of the proven rows."""
        if sym in self.data_checked:
            assert self.data_checked[sym][0] == value, (owner, sym, hex(value))
            return self.data_checked[sym][1]
        sections, symbols, definitions, _ = self.index
        pos, at = definitions[sym]
        table = sections[at]
        size = table[3] - pos
        mine = self.raw[table[4] + pos:table[4] + table[3]]
        theirs = original.data(value, size)
        slots = []
        masked = set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= pos
            if not 0 <= offset < size:
                continue
            assert kind == 6, (sym, kind)
            target = struct.unpack_from('<I', theirs, offset)[0]
            slot = symbols[index][0]
            how = self.resolve(sym, slot, target)
            if how is None:
                self.unbound.append("    %r: %#x,   # %s in table %s" % (slot, target, names.get(target, '')[:50],
                                                                      sym[:50]))
                how = 'UNBOUND'
            slots.append('%s -> %#x (%s)' % (slot[:60], target, how))
            masked.update(range(offset, offset + 4))
        assert all(mine[k] == theirs[k] for k in range(size) if k not in masked), (owner, sym)
        how = 'manager table (%s)' % '; '.join(slots)
        self.data_checked[sym] = (value, how)
        return how

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
            print('\n'.join(sorted(set(self.unbound))))
            for a, (s, r) in sorted(self.not_exact.items()):
                print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
            for a in sorted(self.proven):
                print('PROVEN %08x %s %s' % (a, self.proven[a][:110], self.why[a][:40]))
            print('PROVEN', len(self.proven), 'in range', sum(1 for a in self.proven if RANGE[0] <= a < RANGE[1]))
            print('UNUSED EXTERNAL', sorted(set(EXTERNAL) - self.used))
            return
        assert not self.unbound, '\n'.join(self.unbound)
        assert sorted(self.used) == sorted(EXTERNAL), sorted(set(EXTERNAL) - self.used)
        assert not self.not_exact, {('%08x' % a): v for a, v in self.not_exact.items()}
        for symbol, address in EXTERNAL.items():
            assert address in FUNCTIONS or original.imported(address) is not None or symbol in DATA_EXTERNAL, \
                (symbol, hex(address))


MAIN = Closure(ROOTS)
MAIN.check()
if DISCOVER:
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
            walk(data.get('methods', []))
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
counted = sorted(a for a in MAIN.proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere)
assert not set(counted) & set(elsewhere)
support = sorted(a for a in MAIN.proven if a not in counted)


def row(a, note):
    return dict({'address': '%08x (%s)' % (a, note), 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                 'identity': MAIN.why[a]}, **MAIN.checked[a])


rows_out = [dict({'address': '%08x' % a, 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                  'identity': MAIN.why[a], 'exact': True}, **MAIN.checked[a]) for a in counted]
support_out = [row(a, ('counted by ' + ', '.join(sorted(set(elsewhere[a])))) if a in elsewhere else
                   'outside the range %08x..%08x' % RANGE) for a in support]

NOT_BUILT = [
    ('004d4120..004d6f00', 'RakNet 3.0 library code (evidence names / openrbx-raknet sources): randomMT 004d4120 (the end '
     'of Rand.cpp, 004d0000 map), RakSleep 004d4170 (Sleep import), NetworkIDManager::GET_OBJECT_FROM_ID 004d4180, '
     'DataStructures::List<RPCNode*> dtor 004d41e0, StringTable 004d41f0..004d42a0, CSHA1 004d42e0..004d5930 '
     '(Transform 004d4310, GetHash 004d58a0, ??_G 004d5930), DataBlockEncryptor 004d5980..004d5b70, rijndael '
     '004d5d30..004d6bc0 and CheckSum::Add 004d6f00: library, never recovered here'),
    ('004d6f80 / 004d6fb0 / 004d6fe0 / 004d6ff0', 'inline Lighting property getters (ColorShift_Top +0x270 and '
     'ColorShift_Bottom +0x27c returned by value through the hidden pointer, Brightness +0x288 on the x87 stack, Ambient '
     '+0x28c), referenced only by the Lighting descriptor initializers 007f6bd0 / 007f6c10 / 007f6b90 / 007f6c50: the '
     'native v8datamodel/Lighting2008.h declares the fields but no getters (proposal)'),
    ('004d7020', 'the implicit G3D::LightingParameters copy constructor (two GCamera copies 00513220; callers in '
     'ViewRbxGfx / ViewG3D 004d9d1e / 004dad0c / 004dbf8c / 004dc1fd and 007b15b1): a compiler-generated member of a '
     'G3D library class, emitted only by its (blocked) Lighting callers; not built'),
    ('004d71a0 / 004d71b0', 'ViewRbxGfx static debug switch (analog name setDebug: stores its bool in the globals '
     '0094065c and 009413c0) and the getter of 0094065c (callers 0045d0f9 / 0045e272): neither member nor the two '
     'globals are declared in RenderLib/ViewNew2008.h or any native header (proposal)'),
    ('004d71d0', 'thiscall equality on the first word (ret 4) called by the AggregatingSceneManager rows 00540eed / '
     '0054451d / 0054689d: a RenderBase bucket key comparison, render-scene owner (MaterialBase / BucketKey blocker)'),
    ('004d71f0', 'a 5-byte jump to the destructor 00507d00 (member at offset 0) used by unwind funclets of several '
     'units: the class is not derived'),
    ('004d7200 / 004d7220', 'std::map<BrickColor::Number, Color4> _Min / _Max (evidence names): ICF-folded tree '
     'helpers, compared but not counted by the ogre-rbx-node receipt; BrickColor owner'),
    ('004d72b0 / 004d76c0', 'Name::doDeclare for the Sky class name (static local, Name::declare 00553f90) and its '
     'jump thunk: Sky / effects owner (pending build in the effects receipt)'),
    ('004d7380 / 004d73a0 (+ 004d73c0) / 004d73e0 / 004d7420', 'Ogre::SharedPtr<Resource> / SharedPtr<DataStream> '
     'destructors, destroy and ??_G (vtables 00826bc4 / 00826bb4): Ogre 1.4.5 header templates used by unwind '
     'funclets of many units (007af387..007edd2a) and ICF-folded with SharedPtr<RbxSky> (ogre-scene-manager receipt '
     'compares them, not counted); not built here'),
    ('004d7460', 'MaterialFactory destructor: the +0xc pointee type is not derived (ViewNew/MaterialFactory2008.h '
     'declares the destructor only); bound here as the external callee of the auto_ptr destructor'),
    ('004d7560', 'G3D::ReferenceCountedPointer<T>::operator= (setPointer 00598fa0), ICF-shared by 16 callers in mesh, '
     'material and Ogre units: a G3D header template whose element type is not provable from this unit'),
    ('004d7580 (+ 004d7590) / 004d7730 / 004d7750', 'eh vector destructor calls (006a165b with the element dtor '
     '00502a70) for G3D::Table entry arrays of the ViewNew mesh factories: ViewNew mesh owner (MeshFactory types)'),
    ('004d7640 / 004d7680 / 004d76e0', 'RCP member releases at +0x10 / +0x18 and an RCP holder ??_G (callers '
     '00546fd8 / 0054bf13): G3D RenderDevice / ViewNew mesh factory types, not declared natively'),
    ('004d7ea0', 'std::_Tree::erase of the MeshFactory<PBBMesh> DecalKey map (796 B, caller 004d88fc): ViewNew mesh '
     'owner (key / value types not declared)'),
]
proven_in_range = {a for a in MAIN.proven if RANGE[0] <= a < RANGE[1]}
unbuilt = ['%08x' % a + ' not built' for a in range_functions if a not in proven_in_range and a not in range_counted]

UNIT_MAP = {
    'raknet 004d4000..004d6f4f': (
        'RakNet 3.0 library (continues the 004d0000 map: ReliabilityLayer / RPCMap / SimpleMutex / Rand). Boundary '
        'evidence: randomMT 004d4120 tail-jumps to reloadMT 004d3ff0 (Rand.cpp); RakSleep 004d4170 calls the Sleep '
        'import; CSHA1 rows use the CSHA1 vtable / RTTI; DataBlockEncryptor rows read keySet +0x258 and call the '
        'rijndael key schedule; CheckSum::Add 004d6f00 ends the library block. Library code, not recovered.'),
    'view-rbxgfx 004d6f50..': (
        'ViewNew/ViewRbxGfx.cpp (continues past 004d8000: ViewBase dtor 004d8920, ctor 004d8a20, ViewRbxGfx ctor '
        '004d9990, render 004daf10, dtor 004db4f0). Boundary evidence: the SceneManager inline dtor / ctor 004d6f50 / '
        '004d6f60 open the object (vtable 00826b44 RTTI .?AVSceneManager@RenderBase@RBX@@), the ViewRbxGfx vtable '
        '00826c70 slots 004d7180 / 004d7370 / 004d76d0, the boost.function type descriptors 00940b90 / 00940c30 '
        '(bind_t<mf1<void, ViewRbxGfx, ...>>) compared by the managers 004d77b0 / 004d7810, the any::holder vtable '
        '00826bd4, and the unwind funclets 007c9c4e..007c9cb7 of the ViewRbxGfx ctor that call the auto_ptr '
        'destructors 004d71c0 / 004d7870. Members counted by render-scene; template instances counted here.'),
    'excluded / library code': (
        'no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row. RakNet (004d4120..004d6f00), the Ogre SharedPtr '
        'header templates, the G3D LightingParameters copy and the generic RCP operator= are library code. The '
        'auto_ptr / boost.function / boost.any / visitDescendents bodies built here are Roblox-instantiated '
        'templates (element or functor types SceneManager / MaterialFactory / ViewRbxGfx binds), whose COMDATs the '
        'linker took from this unit.'),
    'counted here': 'the template instances listed in exact_function_rows (rows below).',
    'bounds': (
        'two analysed rows each hold two functions: 004d73a0 (63 B) is SharedPtr destroy (ends with ret at 004d73bf) '
        'plus a SharedPtr destructor at 004d73c0 (31 B); 004d7580 (32 B) is two 16-byte eh-vector-destructor '
        'thunks (ret at 004d758f, second at 004d7590). Report only; no bounds.json change.'),
}
REJECTED = {}
PROPOSALS = {
    'v8datamodel/Lighting2008.h (Lighting owner)': (
        'Add the inline property getters the Lighting descriptors use: `G3D::Color3 getColorShift_Top() const { return '
        'colorShiftTop; }` (004d6f80: copies +0x270..+0x278 through the hidden return pointer, ret 4), '
        '`G3D::Color3 getColorShift_Bottom() const { return colorShiftBottom; }` (004d6fb0, +0x27c), `float '
        'getBrightness() const { return brightness; }` (004d6fe0: fld +0x288; ret) and `G3D::Color3 getAmbient() '
        'const { return ambient; }` (004d6ff0, +0x28c); referenced by the descriptor initializers 007f6bd0 / 007f6c10 '
        '/ 007f6b90 / 007f6c50. Not compiled here (no pending build).'),
    'RenderLib/ViewNew2008.h (render-scene owner)': (
        'Declare the ViewRbxGfx static debug switch 004d71a0 (cdecl, bool argument: stores it in the byte globals '
        '0094065c and 009413c0; caller 0045d0f9) and its static getter 004d71b0 (returns 0094065c; caller 0045e272), '
        'with the two globals (009413c0 is also read by the BrickMesh create functions 004e54e0 / 004e58b0, see the '
        'viewnew-brick-build receipt). Names are not derived (analog: setDebug / showFrameRate / showProfile).'),
    'ViewNew/MaterialFactory2008.h (render-scene owner)': (
        'Carried over: the +0xc member type of MaterialFactory is still needed for its destructor 004d7460, which '
        'the auto_ptr destructor 004d7870 counted here calls.'),
}

receipt = {
    'class': 'ViewRbxGfx unit template instances of the application range 004d4000..004d8000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve(), SOURCE] + HEADERS},
    'objects': {'main': nb.sha(OBJ)},
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'not_built_reasons': ['%s: %s' % x for x in NOT_BUILT],
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'pending_build_only': [],
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. No new header.',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit4d4: %d counted exact rows; %d support rows; %d range rows, %d counted elsewhere, %d not built'
      % (len(counted), len(support_out), len(range_functions), len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))

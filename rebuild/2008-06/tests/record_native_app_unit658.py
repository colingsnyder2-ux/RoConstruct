"""Verify the inactive 2008-06 native rows of the application range 00658000..00660000.

Unit map (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are written there as
'ADDR counted by RECEIPT' text, never as quoted bare addresses):
  * SafeChat unit tail ..00658897 (the unit starts at 00657c40): boost trim helpers, ChatOption ctors / dtor,
    loadChildren, getMessage, loadChatTree, the call_once body SafeChat_singleton 006587e0 and SafeChat::singleton
    00658880. Built here: native-classes/AppUnit658SafeChat.cpp against the read-only gui owner header
    native-headers/GuiHud2008/GuiBuilder2008.h. Pending rows build only with NATIVE_APPUNIT658_PENDING against a
    generated copy of that header (out/), are recorded exact=false (pending-build-only) and are never counted.
  * SimBody unit 006588a0..0065925e (Body/Primitive owner, body-primitive2008-working.json): not built here.
  * Edge unit 00659260..006592aa: native-classes/AppUnit658Edge.cpp against the new
    native-headers/AppUnit658/Edge.h (a new path: it shadows no donor header).
  * SpatialHash unit 006592b0..0065b5c4, Lua 5.1 library 0065b5d0..0065fee2, Cofm unit 0065fef0.. (body-primitive2008).

Builds: document-swap flags, VS2008 RTM 21022 (no /fp:fast needed; nothing here uses x87 arithmetic).
Every counted row is relocation-masked exact against the original, and every REL32/DIR32 target is bound to the
address the original instruction uses and verified: imports by DLL export name, own symbols by the row proven here,
file statics and the unit's own uncounted functions by one address per symbol, the remaining externals by the explicit
EXTERNAL map. The Edge layout (offsets, sizeof, novtable, slot order) is checked by a generated probe compiled from the
current headers, and setPrimitive is compared with slot 4 of the BallBallContact vtable (RTTI-identified).
A row is counted only when no other receipt counts it (top-level exact_function_rows, or exact_addresses /
exact_unique_addresses / exact method entries for older receipts).
Writes work/2008-06/shared-layouts/app-unit658-working.json.
Set NATIVE_APP_UNIT658_DISCOVER=1 to list unbound targets and non-exact rows instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
OUT = nb.OUT / 'app-unit658'
OUT.mkdir(parents=True, exist_ok=True)
PENDING_DIR = OUT / 'pending'
SOURCES = {
    'edge': R / 'native-classes/AppUnit658Edge.cpp',
    'safechat': R / 'native-classes/AppUnit658SafeChat.cpp',
}
EDGE_H = R / 'native-headers/AppUnit658/Edge.h'
GUI_H = R / 'native-headers/GuiHud2008/GuiBuilder2008.h'
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT658_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit658-working.json'


def build(name, src, extra=(), first=()):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(p) for p in first] + flags[i:] + list(extra) + ['/Fo' + str(obj), str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log
    return obj, flags


# ---- generated pending copy of the gui owner header (proposal; never committed) ----------------------------------
PROPOSAL_CHATOPTION = '''	class ChatOption
	{
	public:
		std::vector<ChatOption*> children;                           // +0x00 (006034f7)
		std::string text;                                            // +0x18 (006035a7)

	public:
		ChatOption(std::string text);                                // 00658170 (new(0x34) in loadChildren 0065840d)
		ChatOption();                                                // 00658100 (new(0x34) in loadChatTree 00658712)
		~ChatOption();                                               // 00658200 (evidence name)
	};

	class SafeChat
	{
	private:
		boost::scoped_ptr<ChatOption> chatRoot;                      // +0x00 (00603808)

	public:
		SafeChat()                                                   // inline in SafeChat_singleton 006587e0
		{
			loadChatTree();
		}
		ChatOption* getChatRoot()
		{
			return chatRoot.get();
		}
		std::string getMessage(std::vector<std::string> code);       // 006584e0
	private:
		void loadChatTree();                                         // 00658660
		void loadChildren(ChatOption* parent, const XmlElement* parentElement);  // 00658360
	public:
		static SafeChat& singleton();                                // 00658880
	};
'''
text = GUI_H.read_text()
m = re.search(r'\tclass ChatOption\n.*?\n\tclass SafeChat\n.*?\n\t};\n', text, re.S)
assert m, 'GuiBuilder2008.h ChatOption / SafeChat block not found'
pending_text = text[:m.start()] + PROPOSAL_CHATOPTION + text[m.end():]
pending_text = pending_text.replace('namespace RBX\n{', 'class XmlElement;\n\nnamespace RBX\n{', 1)
(PENDING_DIR / 'GuiHud2008').mkdir(parents=True, exist_ok=True)
(PENDING_DIR / 'GuiHud2008/GuiBuilder2008.h').write_text(pending_text)

# ---- generated layout probe on the current headers ----------------------------------------------------------------
LAYOUT_SRC = OUT / 'NativeAppUnit658Layout.cpp'
LAYOUT_SRC.write_text('''// generated by tests/record_native_app_unit658.py: Edge.h offsets and slot order
#include <stddef.h>
#include "AppUnit658/Edge.h"
#define CHECK(name, cond) typedef char name[(cond) ? 1 : -1]
struct NativeAppUnit658Layout
{
	CHECK(edgeStateAt8, offsetof(RBX::Edge, edgeState) == 0x8);
	CHECK(prim0AtC, offsetof(RBX::Edge, prim0) == 0xc);
	CHECK(prim1At10, offsetof(RBX::Edge, prim1) == 0x10);
	CHECK(index0At14, offsetof(RBX::Edge, index0) == 0x14);
	CHECK(index1At18, offsetof(RBX::Edge, index1) == 0x18);
	CHECK(inEdgeListAt1C, offsetof(RBX::Edge, inEdgeList) == 0x1c);
	CHECK(edgeSize20, sizeof(RBX::Edge) == 0x20);
};
// concrete probe so that the compiler emits a vtable with Edge's slot order (slot 3 getEdgeType, slot 4 setPrimitive)
class NativeAppUnit658ProbeEdge : public RBX::Edge
{
public:
	NativeAppUnit658ProbeEdge() : RBX::Edge(0, 0) {}
	virtual EdgeType getEdgeType() const { return CONTACT; }
};
RBX::Edge* nativeAppUnit658MakeProbeEdge()
{
	return new NativeAppUnit658ProbeEdge();
}
''')

OBJ, FLAGS = {}, {}
OBJ['edge'], FLAGS['edge'] = build('NativeAppUnit658_edge', SOURCES['edge'])
OBJ['safechat'], FLAGS['safechat'] = build('NativeAppUnit658_safechat', SOURCES['safechat'])
OBJ['layout'], FLAGS['layout'] = build('NativeAppUnit658_layout', LAYOUT_SRC)
OBJ['safechat_pending'], FLAGS['safechat_pending'] = build(
    'NativeAppUnit658_safechat_pending', SOURCES['safechat'], ['/DNATIVE_APPUNIT658_PENDING'], [PENDING_DIR])

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}

STR = 'V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@'
# ---- externals: address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    '?call_once@boost@@YAXP6AXXZAAJ@Z': 0x557330,      # singleton 0065888a (bound the same way by app-unit424 / 40c)
    '??2@YAPAXI@Z': 0x6a0920,                          # operator new (SafeChat_singleton 006587fa, CRT)
    '??3@YAXPAX@Z': 0x6a067a,                          # operator delete (00658859, CRT)
    '?loadChatTree@SafeChat@RBX@@AAEXXZ': 0x658660,    # SafeChat_singleton 00658821 (pending build only)
}
# the unit's own functions and file statics that are not counted rows: one address per symbol
LOCAL_STATIC_AT = {
    '?SafeChat_singleton@@YAXXZ': 0x6587e0,            # pushed by singleton 00658885 (row recorded below, not counted)
    '_once_SafeChat_singleton': 0x97d940,              # once_flag pushed by singleton 00658880
    '_sing': 0x97d944,                                 # read by singleton 0065888f, swapped at 00658838
}
UNBOUND = []
binding = {}

# (address, symbol or unique prefix): one entry per counted address
ROWS = {
    'edge': [
        (0x659260, '??0Edge@RBX@@QAE@PAVPrimitive@1@0@Z'),
        (0x659290, '?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z'),
    ],
    'safechat': [
        (0x658880, '?singleton@SafeChat@RBX@@SAAAV12@XZ'),
    ],
}
# rows built only against the generated pending header: recorded exact=false (pending-build-only), never counted
PENDING_ROWS = [
    (0x658100, '??0ChatOption@RBX@@QAE@XZ'),
    (0x658170, '??0ChatOption@RBX@@QAE@' + STR + '@Z'),
    (0x658200, '??1ChatOption@RBX@@QAE@XZ'),
    (0x6587e0, '?SafeChat_singleton@@YAXXZ'),
]
NON_EXACT_ROWS = [
    (0x6587e0, '?SafeChat_singleton@@YAXXZ', 'safechat',
     'current headers: GuiBuilder2008.h declares no SafeChat constructor (the original inlines SafeChat() { '
     'loadChatTree(); }, a call to 00658660) and no ~ChatOption (the original calls 00658200); the implicit members '
     'make this body differ. See the pending row and the proposal.'),
]
REJECTED = {
    'ChatOption(std::string text) : text(text) (pending build)': (
        '125 / 140 B: the original default-constructs text (006581bd) and then assigns it (006581cf); the body '
        'assignment `this->text = text;` is used instead'),
}


def target_of(address):
    body, refs, _ = match.target('2008-06', '%08x' % address)
    return body, refs


def resolve(obj, rows):
    funcs = match.coff_functions(Path(obj).read_bytes())
    out = []
    for address, key in rows:
        hits = [x for x in funcs if x[0] == key] or [x for x in funcs if x[0].startswith(key) and not nb.LOCAL_EH.match(x[0])]
        if DISCOVER and len(hits) != 1:
            print('UNRESOLVED', '%08x' % address, key[:120], [h[0][:120] for h in hits])
            continue
        assert len(hits) == 1, ('%08x' % address, key, [h[0] for h in hits])
        out.append((address, hits[0][0]))
    return out


def bind_value(raw, sections, symbols, definitions, name, body, target, address, own, record=True):
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
        if nb.LOCAL_EH.match(symbol):
            local.add(symbol)
            continue
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(symbol), (name, symbol, hex(value), hit)
            how = '%s!%s' % hit
        elif symbol.startswith('__real@'):
            assert original.data(value, len(symbol[7:]) // 2) == bytes.fromhex(symbol[7:])[::-1], (name, symbol, hex(value))
            how = 'constant %s' % symbol[7:]
        elif symbol in own:
            assert own[symbol] == value, (name, symbol, hex(value), hex(own[symbol]))
            how = 'own row'
        elif symbol in EXTERNAL:
            assert EXTERNAL[symbol] == value, (name, symbol, hex(value), hex(EXTERNAL[symbol]))
            how = 'external' + (' (evidence name)' if names.get(value, '') == symbol else ' (call-site identification)')
        elif symbol in LOCAL_STATIC_AT:
            assert LOCAL_STATIC_AT[symbol] == value, (name, symbol, hex(value), hex(LOCAL_STATIC_AT[symbol]))
            how = 'unit static / own uncounted function (one address per symbol)'
        else:
            UNBOUND.append("    %r: %#x,   # %s in %s" % (symbol, value, names.get(value, '')[:60], name[:60]))
            continue
        if record:
            prev = binding.setdefault(symbol, (value, name))
            assert prev[0] == value, ('inconsistent', symbol, hex(prev[0]), prev[1], hex(value), name)
        verified[symbol] = '%s (%s)' % (hex(value), how)
    return verified, local


def verify(which, rows, own, strict=True, record=True):
    raw = Path(OBJ[which]).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    result = []
    for address, name in rows:
        body, refs = bodies[name]
        target, target_refs = target_of(address)
        exact = match.exact_match(target, target_refs, body, refs)
        entry = {'address': '%08x' % address, 'symbol': name, 'size': len(body), 'target_size': len(target), 'exact': exact}
        if not exact:
            assert not strict or DISCOVER, (name, entry['address'], len(body), len(target))
            result.append(entry)
            continue
        verified, local = bind_value(raw, sections, symbols, definitions, name, body, target, address, own, record)
        entry.update({'verified_targets': verified, 'local_eh': sorted(local)})
        result.append(entry)
    return result


resolved = {k: resolve(OBJ[k], rows) for k, rows in ROWS.items()}
own = {}
for rows in resolved.values():
    for address, name in rows:
        own.setdefault(name, address)
groups = {k: verify(k, rows, own) for k, rows in resolved.items()}

non_out = []
for address, key, which, why in NON_EXACT_ROWS:
    row = verify(which, resolve(OBJ[which], [(address, key)]), own, strict=False, record=False)[0]
    assert not row['exact'] or DISCOVER, ('non-exact row unexpectedly exact', row['address'])
    row.update({'exact': False, 'reason': why, 'address': row['address'] + ' (not counted)'})
    non_out.append(row)

pending_out = []
pending_own = dict(own)
for address, key in PENDING_ROWS:
    pending_own.setdefault(key, address)
for row in verify('safechat_pending', resolve(OBJ['safechat_pending'], PENDING_ROWS), pending_own, strict=False,
                  record=False):
    row['pending_build_exact'] = row.pop('exact')
    row['exact'] = False
    row['reason'] = 'pending-build-only: needs the GuiBuilder2008.h ChatOption / SafeChat proposal'
    row['address'] += ' (pending-build-only, not counted)'
    pending_out.append(row)

if DISCOVER:
    print('\n'.join(sorted(set(UNBOUND))))
    for g, rows in list(groups.items()) + [('pending', pending_out)]:
        for r in rows:
            if not r.get('exact') and not r.get('pending_build_exact'):
                print('NOT EXACT', g, r['address'], r['symbol'][:90], r['size'], r['target_size'])
    sys.exit(0)
assert not UNBOUND, UNBOUND

# ---- vtable / RTTI checks on the object built from the current headers ------------------------------------------
BALLBALL_VTABLE = 0x8436bc
assert original.vtable_class(BALLBALL_VTABLE) == ('.?AVBallBallContact@RBX@@', 0)
raw = Path(OBJ['layout']).read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
vt_name = '??_7NativeAppUnit658ProbeEdge@@6B@'
start, section = definitions[vt_name]
table = sections[section]
slots = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    if kind == 6 and offset >= start and (offset - start) % 4 == 0:
        slots[(offset - start) // 4] = symbols[index][0]
slots = {k: v for k, v in slots.items() if k < 8}
assert slots.get(4) == '?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z', slots
assert slots.get(3) == '?getEdgeType@NativeAppUnit658ProbeEdge@@UBE?AW4EdgeType@Edge@RBX@@XZ', slots
assert slots.get(1) == '?putInKernel@IPipelined@RBX@@UAEXPAVKernel@2@@Z', slots
assert slots.get(2) == '?removeFromKernel@IPipelined@RBX@@UAEXXZ', slots
original_slots = ['%08x' % struct.unpack('<I', original.data(BALLBALL_VTABLE + 4 * i, 4))[0] for i in range(6)]
assert original_slots[4] == '%08x' % own['?setPrimitive@Edge@RBX@@UAEXHPAVPrimitive@2@@Z'], original_slots
edge_ctor = Path(OBJ['edge']).read_bytes()
assert b'??_7Edge@RBX@@6B@' not in edge_ctor, 'Edge must stay novtable (the original Edge() stores no vtable)'
vtable_check = {
    'probe_vtable_slots_current_headers': {str(k): v for k, v in sorted(slots.items())},
    'BallBallContact_vtable': 'RTTI .?AVBallBallContact@RBX@@ at offset 0; slot 4 is Edge::setPrimitive (proven here); '
                              'slots 1 / 2 / 3 are Contact / BallBallContact overrides (world-shapes owner)',
    'edge_novtable': 'no ??_7Edge@RBX@@6B@ in the Edge object',
}


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
                out.setdefault('%08x' % int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
exact_rows = sorted({r['address'] for rows in groups.values() for r in rows if r['exact']})
double = {a: elsewhere[a] for a in exact_rows if a in elsewhere}
assert not double, double
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if '00658000' <= a < '00660000'}
total_rows = sum(1 for line in open(ROOT / 'work/2008-06/functions.jsonl')
                 if 0x658000 <= int(json.loads(line)['addr'], 16) < 0x660000)

# Unit map. Addresses of rows this receipt does not count appear only inside prose strings (never as a bare quoted
# address), so recorders that treat any quoted bare address as counted do not drop them.
UNIT_MAP = {
    'safechat 00657c40..00658897 (tail in range)': (
        'SafeChat.cpp (unit starts at 00657c40 getChatTreeFile, before this range). In range: boost::algorithm trim '
        'helpers 00658020 (called only by 006582f6) and trim(std::string&, locale) 006582b0 (called by loadChildren '
        '006583f6 and 0066a276); ChatOption() 00658100 and ChatOption(std::string) 00658170 (ret 0x1c, string by '
        'value; both after new(0x34): vector 0x18 + string 0x1c), ~ChatOption 00658200 (evidence name, for_each delete '
        'of children), loadChildren 00658360 (findFirstChildByTag / getValue / findNextChildWithSameTag evidence names, '
        'utterance Name), getMessage 006584e0 (boost::lexical_cast<int> 005be120, ret 0x1c), loadChatTree 00658660 '
        '(TextXmlParser::parse 0058f6c0, new(0x34), "ROOT"), SafeChat_singleton 006587e0 (new(4); scoped_ptr reset of '
        'the file static 0097d944) and SafeChat::singleton 00658880 (call_once with the once_flag 0097d940; '
        'GuiBuilder::buildChatMenu calls it at 00603803). Built here: singleton (counted); ChatOption ctors / dtor and '
        'SafeChat_singleton are pending-build-only. Not attempted: the trim helpers (boost templates), loadChildren, '
        'getMessage, loadChatTree (they also need the XmlElement API and the utterance Name static).'),
    'simbody 006588a0..0065925e': (
        'SimBody.cpp (Body/Primitive owner, Body2008.h): mulMatrixMatrixTranspose helper 006588a0 (only caller '
        '0065898a), computeRotVel 00658920 (only caller step 00659062), PV::pvAtLocalCoord 00658a00 and '
        'PV::pvAtLocalOffset 00658c50 (evidence names; out-of-line copies emitted in this unit), the Quaternion '
        'product 00658a30 (only caller step 006590b7), SimBody() 00658ae0 and getOwnerPV 00658ca0 (counted by '
        'body-primitive2008-working.json), update 00658d20 (near miss there) and step 00658fb0 (not attempted there). '
        'Not built here: the SimBody layout belongs to the body-primitive2008 owner.'),
    'edge 00659260..006592aa': (
        'Edge.cpp: Edge(Primitive*, Primitive*) 00659260 (evidence name; called by Contact() 00606c20) and '
        'Edge::setPrimitive 00659290 (slot 4 of the BallBallContact vtable 008436bc). Built here, both counted.'),
    'spatial-hash 006592b0..0065b5c4': (
        'SpatialHash.cpp (2008, not a template): floor-to-int Vector3 helper 006592b0 (calls floor 006a1bb0; callers '
        '006594a1 / 00659554 / 006595aa), box helpers 00659330 / 00659370 / 006593d0 / 00659460 / 006594b0 / '
        '00659510 / 006595d0, hash-node find / remove / create 00659670..00659f90 (SpatialHash::collide 00659a10, '
        'the contact-candidate scan 00659c20 called by ContactManager 0060d4b9), erase / addNode / onPrimitiveAdded '
        '0065a080..0065a4e0 (onPrimitiveAdded called by ContactManager 0060cc32), changeMinMax 0065a5d0, '
        'primitiveExtentsChanged 0065a950, the Roblox-instantiated std::vector helpers 00659f60 / 0065a830 / 0065ac20 / '
        '0065aee0 / 0065af80 / 0065b430 (resize with 8-byte elements; only this unit calls them), ~SpatialHash '
        '0065b1b0 (called by ~ContactManager 0060cd1d) and SpatialHash(ContactManager*, ...) 0065b4e0 (called at '
        '0060d29e; levels: vector constructor iterator over 4 x 0x18 at +0xc, counters +0x6c..+0x88, level count '
        'static 009625a8). No committed native header declares SpatialHash (ContactManager2008.h forward-declares '
        'it); not attempted in this pass: needs the allocation size at 0060d29x, the node / bucket element types and '
        'the 2008 Primitive spatial fields (Primitive2008.h +0x60..+0x80).'),
    'lua 0065b5d0..0065fee2': (
        'Lua 5.1 library (evidence names): lgc.c reallymarkobject 0065b5d0 .. luaC_linkupval 0065c510, ltm.c '
        'luaT_init 0065c570 .. luaT_gettmbyobj 0065c600, lvm.c luaV_tonumber 0065c660 .. luaV_execute 0065d2c0, '
        'ltable.c hashnum 0065e3e0 .. luaH_setstr 0065f150, lstring.c 0065f1a0..0065f3f0, lfunc.c 0065f450..0065f7e0, '
        'lzio.c 0065f830..0065f990, ldump.c 0065f9f0..0065fe70: library code, not recovered.'),
    'cofm 0065fef0..': (
        'Cofm.cpp: Cofm(Body*) 0065fef0, getMass 0065ff10, updateIfDirty 0065ff20 (evidence names), counted by '
        'body-primitive2008-working.json; continues past 00660000.'),
}
BOUNDS = (
    '0065833f is the end of trim(std::string&, locale) 006582b0; 00658340..00658358 (25 B, `if (p) { p->~ChatOption(); '
    'operator delete(p); }`, the out-of-line ~scoped_ptr<ChatOption> / ~SafeChat) is a separate function whose only '
    'reference is the EH unwind funclet at 007dbf1e; the analysed extent of 006582b0 (169 B) includes it. No '
    'bounds.json change made.')
PROPOSALS = {
    'native-headers/GuiHud2008/GuiBuilder2008.h (gui hud owner)': (
        'declare in ChatOption `ChatOption(std::string text);` 00658170, `ChatOption();` 00658100 and `~ChatOption();` '
        '00658200 (evidence name ??1ChatOption@RBX@@QAE@XZ; both ctors follow new(0x34) = sizeof(ChatOption)), and in '
        'SafeChat an inline `SafeChat() { loadChatTree(); }` (SafeChat_singleton 006587e0 zeroes chatRoot and calls '
        '00658660 inline), `std::string getMessage(std::vector<std::string>);` 006584e0, private `void loadChatTree();` '
        '00658660 and `void loadChildren(ChatOption*, const XmlElement*);` 00658360 (plus `class XmlElement;` at global '
        'scope). The recorder generates this copy under rebuild/2008-06/out/native-layouts/app-unit658/pending/; '
        'with it ChatOption(), ChatOption(std::string), ~ChatOption and SafeChat_singleton build as recorded in '
        'pending_rows.'),
}

receipt = {
    'class': 'RBX Edge and SafeChat rows of the application range 00658000..00660000 (2008-06), inactive',
    'compiler': 'VS2008 RTM 21022',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)): nb.sha(p) for p in list(SOURCES.values()) + [Path(__file__).resolve(), EDGE_H,
                GUI_H]},
    'objects': {k: nb.sha(v) for k, v in OBJ.items()},
    'range_total_rows': total_rows,
    'unit_map': UNIT_MAP,
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any quoted bare address in another receipt as counted there.
    'range_rows_counted_by_other_receipts': ['%s counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'layout': {
        'Edge.h': 'checked by the generated probe: edgeState +0x8, prim0 +0xc, prim1 +0x10, index0 +0x14, '
                      'index1 +0x18, inEdgeList +0x1c, sizeof 0x20; novtable',
    },
    'vtables': vtable_check,
    'rows': groups,
    'not_exact': non_out,
    'pending_rows': pending_out,
    'rejected': REJECTED,
    'bounds': BOUNDS,
    'proposals': PROPOSALS,
    'exact_function_rows': exact_rows,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit.',
}
RECEIPT.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS app-unit658: %d counted exact rows (%s) of %d range rows; %d not exact, %d pending-build-only '
      '(%d exact in the pending build)'
      % (len(exact_rows), ' '.join(exact_rows), total_rows, len(non_out), len(pending_out),
         sum(1 for r in pending_out if r['pending_build_exact'])))

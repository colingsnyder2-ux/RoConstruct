"""Machine-derived member layouts per class from the owner's Ghidra DB (rbx2008m.db) -> ghidra-layouts.json.
  python work/native-client/ghidra_layouts.py        (rebuild; ~1 min)
  import ghidra_layouts; ghidra_layouts.layout_hint('RBX::Humanoid')   # compact prompt text
Offsets come from `*(T *)(param_1 + 0xNN)` / `param_1[N]` in decompiled bodies of the class's own methods (param_1 = this),
plus the DB's type_offsets table. Heuristic: aliases of this (local = param_1) are not followed."""
import collections
import json
import re
import sqlite3
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
DB = 'file:C:/Users/colin/RBXBanland/work/re/rbx2008m.db?mode=ro'
OUT = HERE / 'ghidra-layouts.json'

CAST = re.compile(r'\*\(([\w\s:<>,]+?\s*\**)\s*\*\)\(\(?(?:int\)\s*)?param_1\s*\+\s*(0x[0-9a-fA-F]+|\d+)\)')
IDX = re.compile(r'\bparam_1\[(\d+)\]')
PARAM = re.compile(r'\(\s*(?:[\w:]+\s+)*?([\w:<>,]+\s*\**)\s*param_1\s*[,)]')
NEW = re.compile(r'=\s*operator_new\((0x[0-9a-fA-F]+|\d+)\);')
FCALL = re.compile(r'\b(?:FUN_|thunk_FUN_)?([0-9a-f]{8})\(|\bFUN_([0-9a-f]{8})\(')


def kind_width(t):
    t = t.strip()
    if '*' in t:
        return 4, 'pointer'
    for pat, w, k in ((r'float', 4, 'float'), (r'double|longlong|undefined8|__int64|ulonglong', 8, 'double/int64'),
                      (r'short|undefined2|ushort|wchar', 2, 'short'), (r'char|byte|bool|undefined1|uchar', 1, 'byte'),
                      (r'int|long|uint|undefined4|dword', 4, 'int'), (r'undefined', 4, 'int')):
        if re.search(pat, t):
            return w, k
    return 0, t


def owners():
    sys.path.insert(0, str(HERE)); sys.path.insert(0, str(ROOT)); sys.argv = sys.argv[:1]
    import native_llm as m
    from roc import integration_site
    reg = m.load_registry()
    inferred = json.loads((HERE / 'owner-classes.json').read_text())
    def owner(a):
        if a in inferred:
            return inferred[a]['class']
        row = reg.get(a) or {}
        sig = re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', row.get('signature') or ''))
        h = re.search(r'__\w+ ((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)::~?[A-Za-z_]\w*\(', sig)
        if h and h.group(1) not in ('RBX', 'std', 'boost', 'G3D'):
            return h.group(1)
        return row.get('owner_class') or None
    exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
    rem = {a: v for a, v in json.loads((HERE / 'remaining-classified.json').read_text()).items() if a not in exact}
    return m, reg, owner, rem


def declared(header, cls):
    """(offsets declared in `// +0x..` style comments, member-line count, confidence) of cls's class body."""
    try:
        text = Path(header).read_text(errors='replace')
    except OSError:
        return set(), 0, 'none'
    leaf = re.escape(cls.split('::')[-1])
    mt = re.search(r'\b(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % leaf, text)
    if not mt:
        return set(), 0, 'none'
    i, d = mt.end(), 1
    while i < len(text) and d:
        d += (text[i] == '{') - (text[i] == '}'); i += 1
    body = text[mt.end():i]
    offs = {int(x, 16) for c in re.findall(r'//[^\n]*|/\*.*?\*/', body, re.S)
            for x in re.findall(r'(?:\+|off(?:set)?\s*|@\s*)0x([0-9a-fA-F]+)', c)}
    members = sum(1 for l in body.splitlines() if ';' in l and '(' not in l and not l.strip().startswith('//'))
    return offs, members, 'comments' if offs else 'order-only'


def build():
    m, reg, owner, rem = owners()
    classes = collections.defaultdict(list)
    for a, v in rem.items():
        if v.get('bucket') == 'vendor-library':
            continue
        c = owner(a)
        if c:
            classes[c].append(a)
    db = sqlite3.connect(DB, uri=True)
    cls_of = {a: owner(a) for a in reg}
    mem = collections.defaultdict(lambda: collections.defaultdict(lambda: {'w': set(), 'k': set(), 'f': {}}))
    sizes = collections.defaultdict(collections.Counter)
    ctor = {a: c for a, c in cls_of.items() if c in classes and (reg[a].get('name') or '').startswith('??0')}
    for addr, text in db.execute("select addr, decompiled from functions where program='RobloxApp_client.exe'"):
        c = cls_of.get(addr)
        text = text or ''
        if c in classes:
            pt = PARAM.search(text.split('{')[0])
            pw = kind_width(pt.group(1))[0] if pt and '*' in pt.group(1) else 4
            for t, off in CAST.findall(text):
                w, k = kind_width(t)
                e = mem[c][int(off, 0)]; e['w'].add(w); e['k'].add(k); e['f'][addr] = 1
            for n in IDX.findall(text):
                e = mem[c][int(n) * (pt and pw or 4)]; e['w'].add(pw); e['k'].add('int'); e['f'][addr] = 1
        for mt in NEW.finditer(text):               # operator_new(N) whose next call is a known constructor
            call = re.search(r'\bFUN_([0-9a-f]{8})\(', text[mt.end():mt.end() + 400])
            if call and call.group(1) in ctor:
                sizes[ctor[call.group(1)]][int(mt.group(1), 0)] += 1
    vt = {r[0] for r in db.execute("select name from types where name like '%::vftable'")}
    tofs = collections.defaultdict(dict)
    for t, off, n in db.execute("select tname, off, n from type_offsets"):
        tofs[t][off] = n
    res = {}
    for c, addrs in classes.items():
        members = {}
        for off, e in mem.get(c, {}).items():
            members[off] = {'off': hex(off), 'widths': sorted(x for x in e['w'] if x), 'kinds': sorted(e['k']),
                            'uses': len(e['f']), 'example': next(iter(e['f']))}
        for off, n in tofs.get(c, {}).items():
            if off not in members:
                members[off] = {'off': hex(off), 'widths': [], 'kinds': ['types-table'], 'uses': n, 'example': None}
        sz = sizes.get(c)
        h = m.declaring_header(c)
        offs, nmem, conf = declared(h, c) if h else (set(), 0, 'none')
        res[c] = {'size': sz.most_common(1)[0][0] if sz else None,
                  'size_evidence': ('operator_new(N) before constructor call, counts ' + json.dumps({hex(k): v for k, v in sz.items()})) if sz else None,
                  'vtable': c + '::vftable' in vt or 0 in members,
                  'remaining_functions': len(addrs),
                  'members': [members[o] for o in sorted(members)],
                  'native_header': str(h) if h else None, 'header_confidence': conf, 'header_member_lines': nmem,
                  'undeclared_offsets': [hex(o) for o in sorted(members) if o not in offs]}
    OUT.write_text(json.dumps(res, indent=1))
    return res


def layout_hint(cls, limit=1500):
    d = json.loads(OUT.read_text()).get(cls)
    if not d:
        return ''
    head = f"{cls} size={d['size']} vtable={d['vtable']}\n"
    lines = [f"{x['off']}: {'/'.join(map(str, x['widths'])) or '?'}b {'/'.join(x['kinds'])} x{x['uses']}"
             for x in sorted(d['members'], key=lambda x: int(x['off'], 16))]
    return (head + chr(10).join(lines))[:limit]


if __name__ == '__main__':
    r = build()
    print('classes', len(r), 'members', sum(len(v['members']) for v in r.values()),
          'with size', sum(v['size'] is not None for v in r.values()), 'with header', sum(bool(v['native_header']) for v in r.values()))
    for c, v in sorted(r.items(), key=lambda kv: -kv[1]['remaining_functions'])[:15]:
        print(f"{c:45} rem={v['remaining_functions']:3} members={len(v['members']):3} undeclared={len(v['undeclared_offsets']):3} size={v['size']} hdr={v['header_confidence']}")

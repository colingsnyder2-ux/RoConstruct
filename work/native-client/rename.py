"""Route 1, no LLM: link the server's byte-exact analogs under their real names.
For each unresolved symbol with an exact analog (link/addrmap.json):
  1. compile src/2008-06/ADDR.cpp with its own '// roc-cl' / '// roc-flags'
  2. find the object function that is byte-identical to ADDR (fingerprint.Target.same)
  3. rename it to the real mangled symbol; rename every symbol its relocations reach to the real name of the
     2008 address the exe relocation points at (native_asm.label: rebuilt names, IAT, MFC thunks)
  4. keep only that one definition (strip_symbols), write link/renamed/ADDR.obj
Any relocation whose 2008 target has no known real name is a blocker; that object is not emitted.
usage: python work/native-client/rename.py [ADDR ...]   -> link/rename.json"""
import json, os, re, struct, subprocess, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild, match, native_asm, fingerprint

ROOT = rebuild.ROOT
CLIENT = '2008-06'
NC = ROOT / 'work/native-client'
WORK = NC / 'rename'
OUT = Path(os.environ['ROC_RENAME_OUT']) if os.environ.get('ROC_RENAME_OUT') else NC / 'link/renamed'
WORK.mkdir(exist_ok=True)
OUT.mkdir(parents=True, exist_ok=True)
REL32, DIR32 = 0x14, 0x06
_SC = {}
exec(open(ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read(), _SC)


def known_symbols():
    """Every symbol some link input defines (engine + shell objects, module/vendor libs): a name the analog
    already spells this way resolves to real code as-is."""
    rsp = NC / 'link/link.rsp'
    out = set()
    for line in rsp.read_text().splitlines():
        p = Path(line.strip().strip('"'))
        if p.suffix == '.obj' and p.exists():
            out |= {n for n, k in _SC['symbols'](p.read_bytes()).items() if k != 'undef'}
        elif p.suffix == '.lib' and p.exists():
            out |= _SC['archive_symbols'](p)
    return out


def symtab(data):
    """[(index, name, secnum, cls)] and the parsed header."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    out, i = [], 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIhHBB', data, symptr + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            off = strtab + struct.unpack_from('<I', raw, 4)[0]
            name = data[off:data.index(b'\0', off)]
        else:
            name = raw.rstrip(b'\0')
        out.append((i, name.decode('latin-1'), secnum, cls, value))
        i += 1 + naux
    return out, (nsec, symptr, nsym, optsz, strtab)


def relocations(data, func_symbol):
    """[(offset in function, type, symbol index)] for the named function."""
    syms, (nsec, symptr, nsym, optsz, _) = symtab(data)
    s = next(x for x in syms if x[1] == func_symbol)
    sec, value = s[2] - 1, s[4]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * sec)
    out = []
    for k in range(nrel):
        off, idx, typ = struct.unpack_from('<IIH', data, relptr + 10 * k)
        out.append((off - value, typ, idx, rawptr + off))
    return out


def rename(data, mapping):
    """Rename symbols by index -> new name (appended to the string table)."""
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    size = struct.unpack_from('<I', data, strtab)[0]
    extra = bytearray()
    for idx, name in mapping.items():
        struct.pack_into('<II', data, symptr + 18 * idx, 0, size + len(extra))
        extra += name.encode('latin-1') + b'\0'
    struct.pack_into('<I', data, strtab, size + len(extra))
    return bytes(data[:strtab + size] + extra + data[strtab + size:])


def vtable_name(va):
    """Single-inheritance vtable at va -> ??_7Class@@6B@ from its RTTI complete object locator."""
    base, image = match._image(CLIENT)
    rd = lambda a: struct.unpack_from('<I', image, a - base)[0] if base <= a < base + len(image) - 4 else None
    col = rd(va - 4)
    if not col or rd(col) != 0 or rd(col + 4) != 0:      # signature 0, offset 0: the primary vtable only
        return None
    td = rd(col + 12)
    if not td:
        return None
    raw = bytes(image[td + 8 - base:td + 8 - base + 200]).split(b'\0', 1)[0].decode('latin-1')
    if not raw.startswith(('.?AV', '.?AU')):
        return None
    return '??_7' + raw[4:] + '6B@'


HEADER_NAMES = {}   # addr -> mangled, from namer.py (header-declared members, compiler-decorated)
REGISTRY = {}


def load_registry():
    try:
        return json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    except (OSError, ValueError):
        return {}


def real_name(va):
    row = REGISTRY.get('%08x' % va)
    if row and not row.get('placeholder'):
        return row['name']
    if '%08x' % va in HEADER_NAMES:
        return HEADER_NAMES['%08x' % va]
    vt = vtable_name(va)
    if vt:
        return vt
    lab = native_asm.label(CLIENT, va)
    if not lab or lab.startswith('fn_'):
        return None
    lab = re.sub(r'^(MFC|ATL|CRT)\s+', '', lab).split()[0]
    if '!' in lab:          # IAT slot: dll!name -> the object refers to __imp_<decorated>; keep analog's own name
        return ''
    return lab


def convert(addr, symbol, target):
    src = ROOT / 'src' / CLIENT / (addr + '.cpp')
    text = src.read_text(errors='replace')
    cl = int((re.search(r'//\s*roc-cl:\s*(\d+)', text) or [0, 21022])[1])
    flags = (re.search(r'//\s*roc-flags:\s*(.+)', text) or [0, '/O2 /GS- /EHsc /MD'])[1].split()
    if match.reject_asm(text) if hasattr(match, 'reject_asm') else False:
        return dict(status='rejected', why='inline asm')
    obj = WORK / (addr + '.obj')
    code, log = rebuild.run(rebuild.toolchain(cl), 'cl', ['/nologo', '/c', '/w'] + flags + ['/Fo' + obj.name, str(src)], WORK)
    if code or not obj.exists():
        return dict(status='compile', why=[l for l in log.splitlines() if 'error' in l][:3])
    data = obj.read_bytes()
    hit = next((f for f in match.coff_functions(data) if target.same(addr, f[1], f[2]) is not None), None)
    if not hit:
        return dict(status='nomatch', why='no object function is byte-identical to the target')
    fsym = hit[0]
    syms = {i: (n, sec) for i, n, sec, cls, v in symtab(data)[0]}
    cls_of = {i: cls for i, n, sec, cls, v in symtab(data)[0]}
    base, image = match._image(CLIENT)
    mapping, blockers, refs = {}, [], {}
    for off, typ, idx, fileoff in relocations(data, fsym):
        name, sec = syms[idx]
        addend = struct.unpack_from('<i', data, fileoff)[0]
        site = int(addr, 16) + off
        word = struct.unpack_from('<I', image, site - base)[0]
        if typ == DIR32:
            va = word - addend
        elif typ == REL32:
            va = (site + 4 + struct.unpack_from('<i', image, site - base)[0]) - addend
        else:
            continue
        if cls_of[idx] == 3 or name.startswith(('??_C@', '__ehhandler$', '__unwindfunclet$', '$', '.')):
            continue                      # object-local (EH funclet, string literal, jump table): travels with it
        if name in KNOWN or name.startswith(('___security_cookie', '__CxxFrameHandler', '__except_handler', '__chkstk', '__EH_prolog')):
            continue                      # already the real name of something the link defines
        real = CHAIN.get('%08x' % va) or real_name(va)
        refs[name] = '%08x' % va
        if real is None and os.environ.get('ROC_RENAME_PLACEHOLDER'):  # shortcut closure pass: unnamed callee/data keep a placeholder name
            real = ('func_%08x' if va < 0x7c0000 else 'dat_%08x') % va
        if real is None:
            blockers.append('%s -> %08x (no real name known)' % (name, va))
        elif real and real != name:
            mapping[idx] = real
    if blockers:
        return dict(status='blocked', analog=fsym, why=blockers[:8], refs=refs)
    fidx = next(i for i, (n, s) in syms.items() if n == fsym)
    mapping[fidx] = symbol
    data = rename(data, mapping)
    if not os.environ.get('ROC_RENAME_KEEP_HELPERS'):  # shortcut closure pass keeps the analog's comdat helpers (std/boost templates)
        data = rebuild.strip_symbols(data, keep={symbol})
    (OUT / (addr + '.obj')).write_bytes(data)
    return dict(status='renamed', analog=fsym, renamed={syms[i][0]: n for i, n in mapping.items()})


KNOWN, CHAIN = set(), {}


def apply_registry(paths, gates):
    """Rename tracked placeholders only; never guess source identifiers."""
    changed, planned, blocked = [], {}, []
    for root in paths:
        root = Path(root)
        files = root.rglob('*') if root.is_dir() else [root]
        for path in files:
            if path.suffix.lower() not in ('.c', '.cc', '.cpp', '.cxx', '.h', '.hpp', '.inl', '.inc'):
                continue
            text = path.read_text(errors='surrogateescape')
            new = text
            for addr, row in REGISTRY.items():
                if row.get('placeholder'):
                    continue
                pattern = r'\b(?:roc_)?func_' + addr + r'\b'
                if not re.search(pattern, new):
                    continue
                if not re.fullmatch(r'[A-Za-z_][A-Za-z_0-9]*', row['name']):
                    blocked.append({'path': str(path), 'address': addr, 'linker_name': row['name']})
                    continue
                new = re.sub(pattern, lambda _: row['name'], new)
            if new != text:
                planned[path] = new
    if blocked:
        raise SystemExit(json.dumps({'status': 'semantic-rename-required', 'blocked': blocked,
                                     'renames_applied': 0}))
    if planned and not gates:
        raise SystemExit('source renames require affected gates via --gate=COMMAND')
    for path, new in planned.items():
        path.write_text(new, errors='surrogateescape')
        changed.append(str(path))
    for gate in gates:
        if subprocess.run(gate, cwd=ROOT, shell=True).returncode:
            raise SystemExit('affected gate failed: ' + gate)
    print(json.dumps({'renames_applied': len(changed), 'changed_files': changed, 'gates': gates}))


def main():
    global REGISTRY
    if '--apply-registry' in sys.argv:
        at = sys.argv.index('--apply-registry')
        tail = sys.argv[at + 1:]
        gates = [x[7:] for x in tail if x.startswith('--gate=')]
        paths = [x for x in tail if not x.startswith('--gate=')]
        if not paths:
            raise SystemExit('--apply-registry needs source/header paths')
        REGISTRY = load_registry()
        apply_registry(paths, gates)
        return
    amap = json.load(open(os.environ.get('ROC_ADDRMAP') or NC / 'link/addrmap.json'))
    jobs = {v['exact'][0]: s for s, v in amap.items() if v['exact']}
    RJ = Path(os.environ['ROC_RENAME_JSON']) if os.environ.get('ROC_RENAME_JSON') else NC / 'link/rename.json'
    res = json.load(open(RJ)) if RJ.exists() else {}
    for obj in OUT.glob('*.obj'):                 # earlier conversions stay recorded
        if res.get(obj.stem, {}).get('status') != 'renamed':
            defs = [n for n, k in _SC['symbols'](obj.read_bytes()).items() if k == 'strong']
            res[obj.stem] = dict(symbol=defs[0] if defs else '?', status='renamed')
    sel = sys.argv[1:] or sorted(a for a in jobs if res.get(a, {}).get('status') != 'renamed')
    target = fingerprint.Target(CLIENT)
    REGISTRY = load_registry()
    global KNOWN
    KNOWN = known_symbols()
    if (NC / 'link/names.json').exists():
        HEADER_NAMES.update(json.load(open(NC / 'link/names.json')))
    CHAIN.update({a: r['symbol'] for a, r in res.items() if r.get('status') == 'renamed'})
    CHAIN.update({a: s for a, s in jobs.items()})   # calls between targets resolve to their real names
    for addr in sel:
        try:
            res[addr] = dict(symbol=jobs[addr], **convert(addr, jobs[addr], target))
        except Exception as e:      # one bad analog must not stop the batch
            res[addr] = dict(symbol=jobs[addr], status='error', why=repr(e)[:200])
        print(addr, res[addr]['status'], res[addr].get('why', '') if res[addr]['status'] != 'renamed' else '', flush=True)
    json.dump(res, open(RJ, 'w'), indent=1)
    from collections import Counter
    print(Counter(r['status'] for r in res.values()))


if __name__ == '__main__':
    main()

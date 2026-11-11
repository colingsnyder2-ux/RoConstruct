"""Exact decorated names for the 2008-06 Ogre layer, from vtables + real headers + the compiler (no guessing, no LLM).

For every exe vtable whose RTTI class is in namespace Ogre, RBX::RenderNew / RBX::ViewNew, or has an Ogre base:
  1. RTTI (complete object locator -> type descriptor, class hierarchy) gives the class and subobject offset;
  2. a probe TU includes the header that declares the class (native-headers first, then the Ogre 1.4.5 client
     headers, OGRE_NONCLIENT_BUILD undefined) and makes the compiler emit that class's own vtable:
       P1 `p->T::~T()` (inline / implicit destructor), P2 `T::~T() {}` (out-of-line destructor),
       P3 `struct RocProbe : T { ~RocProbe(); }` (dllimport / inaccessible: names other than the dtor are T's);
  3. the probe vtable's relocations, slot by slot, are the decorated names of the exe slot functions.
Validation: slot counts must agree, and every exe slot that is an rgmain.dll import thunk must carry exactly the
probe's name for that slot (a header that disagrees with the binary names nothing for that vtable).
usage: python work/native-client/ogre/ogre_names.py [CLASS-SUBSTRING ...]
  -> link/ogre_names.json {addr: mangled}, link/ogre_aliases.json {addr: [names]} (folded bodies),
     link/ogre_vtables.json {vtable va: ??_7 symbol}, link/ogre_names_report.json"""
import hashlib, json, os, re, struct, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import rebuild, match, native_asm  # noqa: E402

CLIENT = '2008-06'
LINK = HERE / 'link'
PROBE = HERE / 'probe'
NH = ROOT / 'rebuild/2008-06/native-headers'
OGRE_INC = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
TC = rebuild.toolchain(21022)
UNDNAME = Path(TC['cl']).parent / 'undname.exe'
JOBS = int(os.environ.get('ROC_JOBS', '6'))


# ---------- COFF ----------
def coff(data):
    """(sections [(name, rawsize, rawptr, relptr, nrel)], symbols {index: (name, secnum, value, cls)})."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    secs = []
    for k in range(nsec):
        n, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * k)
        secs.append((n.rstrip(b'\0').decode('latin-1'), rawsize, rawptr, relptr, nrel))
    syms, i = {}, 0
    while i < nsym:
        raw, value, secnum, typ, cls, naux = struct.unpack_from('<8sIhHBB', data, symptr + 18 * i)
        if raw[:4] == b'\0\0\0\0':
            off = strtab + struct.unpack_from('<I', raw, 4)[0]
            raw = data[off:data.index(b'\0', off)]
        syms[i] = (raw.rstrip(b'\0').decode('latin-1'), secnum, value, cls)
        i += 1 + naux
    return secs, syms


def section_relocs(data, secs, k):
    """{offset in section: symbol index} for section k (0-based)."""
    _, _, _, relptr, nrel = secs[k]
    return {struct.unpack_from('<I', data, relptr + 10 * j)[0]: struct.unpack_from('<I', data, relptr + 10 * j + 4)[0]
            for j in range(nrel)}


def obj_vtables(data):
    """[(symbol, subobject offset, [slot symbol names])] for every vtable an object defines."""
    secs, syms = coff(data)
    out = []
    for i, (name, secnum, value, cls) in syms.items():
        if not name.startswith('??_7') or secnum <= 0:
            continue
        k = secnum - 1
        rel = section_relocs(data, secs, k)
        col = rel.get(value - 4)
        off = None
        if col is not None:
            cname, csec, cval, _ = syms[col]
            if csec > 0:
                off = struct.unpack_from('<I', data, secs[csec - 1][2] + cval + 4)[0]
        slots, at = [], value
        while at in rel:
            slots.append(syms[rel[at]][0])
            at += 4
        out.append((name, off, slots))
    return out


# ---------- exe RTTI ----------
def exe_vtables():
    """[(raw class '.?AV..', vtable va, subobject offset, [slot va], [base raw names])]."""
    import pefile
    from roc import clients
    from roc.analyze import reloc_sites
    pe = pefile.PE(str(clients.exe_path(CLIENT, clients.load()[CLIENT])))
    base = pe.OPTIONAL_HEADER.ImageBase
    text = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.text')
    lo, hi = base + text.VirtualAddress, base + text.VirtualAddress + text.Misc_VirtualSize
    image = pe.get_memory_mapped_image()
    rd = lambda va: struct.unpack_from('<I', image, va - base)[0]
    name_at = lambda td: image[td + 8 - base:td + 8 - base + 300].split(b'\0')[0].decode('latin-1')
    relocs = reloc_sites(pe)
    rs = set(relocs)
    out = []
    for site in relocs:
        if lo <= site < hi:
            continue
        col = rd(site)
        if col + 12 not in rs or rd(col) != 0:
            continue
        raw = name_at(rd(col + 12))
        if not raw.startswith(('.?AV', '.?AU')):
            continue
        chd = rd(col + 16)
        n, arr = rd(chd + 8), rd(chd + 12)
        bases = [name_at(rd(rd(arr + 4 * j))) for j in range(1, n)] if n < 200 else []
        vt, fns = site + 4, []
        while vt in rs and lo <= rd(vt) < hi:
            fns.append(rd(vt))
            vt += 4
        out.append((raw, site + 4, rd(col + 4), fns, bases))
    return out


def ogre_layer(raw, bases):
    return ('@Ogre@@' in raw or '@RenderNew@RBX@@' in raw or '@ViewNew@RBX@@' in raw
            or any('@Ogre@@' in b for b in bases))


def undname(raws):
    """raw RTTI names -> C++ type spelling (undname on the type descriptor symbol)."""
    syms = ['??_R0' + r[1:] + '@8' for r in raws]
    out = {}
    for k in range(0, len(syms), 50):
        text = subprocess.run([str(UNDNAME)] + syms[k:k + 50], capture_output=True, text=True).stdout
        for sym, cpp in re.findall(r'Undecoration of :- "(.*?)"\s*is :- "(.*?)"', text):
            cpp = re.sub(r"^\s*(class|struct)\s+|\s*`RTTI Type Descriptor'\s*$", '', cpp)
            out['.' + sym[5:-2]] = cpp if '??' not in cpp else None
    return out


# ---------- headers ----------
_HEADERS = None


def headers():
    global _HEADERS
    if _HEADERS is None:
        _HEADERS = [(p, p.read_text(errors='replace')) for p in sorted(NH.rglob('*.h'))] + \
                   [(p, p.read_text(errors='replace')) for p in sorted(OGRE_INC.glob('*.h'))]
    return _HEADERS


def header_for(cpp):
    """Headers (best first) defining the outermost-found class of a C++ type name like A::B<C>::D."""
    plain = re.sub(r'<.*>', '', cpp)
    parts = plain.split('::')
    found = []
    for depth in range(len(parts), 0, -1):
        leaf = parts[depth - 1]
        rx = re.compile(r'(?m)^\s*(?:template\s*<[^>]*>\s*)?(?:class|struct)\s+(?:_OgreExport\s+|__declspec\([^)]*\)\s*)?'
                        + re.escape(leaf) + r'\b[^;(]*\{')
        for p, t in headers():
            if rx.search(t) and all(re.search(r'namespace\s+' + ns + r'\b', t) for ns in parts[:depth - 1]
                                    if ns in ('Ogre', 'RBX', 'RenderNew', 'ViewNew', 'G3D')):
                found.append(p)
        if found:
            break
    return found


def includes_for(cpp):
    """Headers for the class itself plus each class named in its template arguments."""
    inc = header_for(cpp)[:1]
    for arg in re.findall(r'(?:class|struct)\s+([\w:]+)', cpp):
        inc += header_for(arg)[:1]
    return list(dict.fromkeys(inc))


def flags():
    import native_bind as nb
    f = nb.flags()
    i = next(k for k, x in enumerate(f) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    return f[:i + 1] + ['/I' + str(OGRE_INC)] + f[i + 1:] + ['/wd4005', '/wd4702']


def probe(key, cpp, incs):
    """Try P1/P2/P3; -> (form, qualifier substituted for RocProbe or None, [(vtsym, off, slots)]) or error text."""
    leaf = re.sub(r'<.*>', '', cpp).split('::')[-1]
    head = ''.join('#include "%s"\n' % p.as_posix() for p in incs)
    forms = [
        ('P1', 'typedef %s RocT;\nvoid roc_probe(RocT* p) { p->RocT::~RocT(); }\n' % cpp),
        ('P2', '%s::~%s() {}\n' % (cpp, leaf)),
        ('P3', 'typedef %s RocT;\nstruct RocProbe : RocT { ~RocProbe(); };\nRocProbe::~RocProbe() {}\n' % cpp),
    ]
    outer = re.sub(r'<.*>', '', cpp).rsplit('::', 1)[0] if '::' in cpp else None
    if outer and outer.split('::')[-1] not in ('Ogre', 'RBX', 'RenderNew', 'ViewNew'):
        # a protected nested class: name it through a class derived from its outer class
        acc = 'struct RocAcc : %s { typedef %s RocT0; };\ntypedef RocAcc::RocT0 RocT;\n' % (outer, cpp)
        forms.append(('P1n', acc + 'void roc_probe(RocT* p) { p->RocT::~RocT(); }\n'))
    else:
        acc = 'typedef %s RocT;\n' % cpp
    # P4: construct in place (the constructor stores the vptr even when the destructor's store is optimised out);
    # RocAny converts to any pointer parameter, tried with 0..4 arguments
    any_ = '#include <new>\nstruct RocAny { template<class U> operator U*() const { return 0; } };\n'
    for n in range(5):
        forms.append(('P4.%d' % n, any_ + acc + 'void roc_probe(void* p) { ::new(p) RocT(%s); }\n'
                      % ', '.join(['RocAny()'] * n)))
    errs = []
    for form, body in forms:
        src = PROBE / ('%s_%s.cpp' % (key, form))
        obj = src.with_suffix('.obj')
        src.write_text('#pragma warning(disable: 4005 4702 4250)\n' + head + body)
        if obj.exists():
            obj.unlink()
        code, log = rebuild.run(TC, 'cl', flags() + ['/Fo' + str(obj), str(src)], PROBE)
        if code or not obj.exists():
            errs.append('%s: %s' % (form, next((l.strip() for l in log.splitlines() if 'error' in l), log[-200:])[:200]))
            continue
        vts = obj_vtables(obj.read_bytes())
        if form == 'P3':
            vts = [v for v in vts if v[0].startswith('??_7RocProbe@@')]
        else:
            vts = [v for v in vts if v[0].startswith('??_7' + RAW_OF[cpp][4:])]
        if vts:
            return form, (vts, [n for n, *_ in coff(obj.read_bytes())[1].values()])
        errs.append('%s: compiled, no vtable emitted' % form)
    return None, errs


RAW_OF = {}


def main():
    LINK.mkdir(parents=True, exist_ok=True)
    PROBE.mkdir(parents=True, exist_ok=True)
    want = sys.argv[1:]
    tables = [t for t in exe_vtables() if ogre_layer(t[0], t[4])]
    cpp = undname(sorted({t[0] for t in tables}))
    # the class itself (not just a template argument) must be Ogre-layer
    tables = [t for t in tables if not cpp.get(t[0]) or re.sub(r'<.*>', '', cpp[t[0]]).startswith(
        ('Ogre::', 'RBX::RenderNew::', 'RBX::ViewNew::')) or any('@Ogre@@' in b for b in t[4])]
    classes = sorted({t[0] for t in tables if cpp.get(t[0])})
    if want:
        classes = [c for c in classes if any(w in cpp[c] for w in want)]
    for c in classes:
        RAW_OF[cpp[c]] = c
    iat = native_asm.names(CLIENT)
    base, image = match._image(CLIENT)

    def import_name(va):
        """rgmain/other dll import thunk (jmp [iat]) -> imported decorated name."""
        raw = bytes(image[va - base:va - base + 6])
        if raw[:2] != b'\xff\x25':
            return None
        lab = iat.get(struct.unpack_from('<I', raw, 2)[0], '')
        return lab.split('!', 1)[1] if '!' in lab else lab

    def one(c):
        key = re.sub(r'\W+', '_', cpp[c])[:60] + '_' + hashlib.sha1(c.encode()).hexdigest()[:8]
        incs = includes_for(cpp[c])
        if not incs:
            return c, dict(status='no-header')
        form, vts = probe(key, cpp[c], incs)
        if form is None:
            return c, dict(status='probe-fail', headers=[p.relative_to(ROOT).as_posix() for p in incs], why=vts)
        return c, dict(status='probed', form=form, headers=[p.relative_to(ROOT).as_posix() for p in incs],
                       vts=vts[0], syms=vts[1])

    with ThreadPoolExecutor(JOBS) as pool:
        probed = dict(pool.map(one, classes))

    names, aliases, vtnames, report = {}, {}, {}, {}
    qual = lambda c: c[4:]                        # '.?AVRbxSceneManager@Ogre@@' -> 'RbxSceneManager@Ogre@@'
    for raw, vt, off, fns, bases in tables:
        if raw not in probed:
            report['%08x' % vt] = dict(cls=cpp.get(raw) or raw, status='no-cpp-name' if not cpp.get(raw) else 'skipped')
            continue
        p = probed[raw]
        row = dict(cls=cpp[raw], slots=len(fns), status=p['status'])
        report['%08x' % vt] = row
        if p['status'] != 'probed':
            row.update(why=p.get('why'), headers=p.get('headers'))
            continue
        sub = (lambda n: n.replace('RocProbe@@', qual(raw))) if p['form'] == 'P3' else (lambda n: n)
        cand = [v for v in p['vts'] if v[1] == off] or p['vts']
        cand = [v for v in cand if len(v[2]) == len(fns)]
        if len(cand) != 1:
            row.update(status='slot-count', probe=[(v[0], v[1], len(v[2])) for v in p['vts']])
            continue
        vtsym, _, slots = cand[0]
        slots = [sub(n) for n in slots]
        if p['form'] == 'P3':
            # RocProbe's destructor is public; T's deleting destructors carry T's own destructor access letter,
            # which the probe object spells in its reference to ??1T
            acc = next((s[len('??1' + qual(raw)):][:1] for s in p['syms'] if s.startswith('??1' + qual(raw))), None)
            for pre in ('??_G', '??_E'):
                slots = [pre + qual(raw) + acc + n[len(pre + qual(raw)) + 1:]
                         if acc and n.startswith(pre + qual(raw)) else n for n in slots]
        bad, named, imports = [], {}, 0
        for i, (fn, n) in enumerate(zip(fns, slots)):
            imp = import_name(fn)
            if imp is not None:
                imports += 1
                if n not in (imp, '_' + imp):           # C imports decorate as _name
                    bad.append('slot %d %08x import %s != header %s' % (i, fn, imp, n))
            elif n == '__purecall':
                bad.append('slot %d %08x exe body, header pure' % (i, fn))
            else:
                named['%08x' % fn] = n
        if bad:
            row.update(status='header-disagrees', why=bad[:6], mismatches=len(bad))
            continue
        row.update(status='named', form=p['form'], vtable_symbol=sub(vtsym), imports_validated=imports, named=len(named))
        vtnames['%08x' % vt] = sub(vtsym)
        for a, n in named.items():
            aliases.setdefault(a, [])
            if n not in aliases[a]:
                aliases[a].append(n)
            names.setdefault(a, n)
    folded = {a: v for a, v in aliases.items() if len(v) > 1}
    json.dump(names, open(LINK / 'ogre_names.json', 'w'), indent=1, sort_keys=True)
    json.dump(folded, open(LINK / 'ogre_aliases.json', 'w'), indent=1, sort_keys=True)
    json.dump(vtnames, open(LINK / 'ogre_vtables.json', 'w'), indent=1, sort_keys=True)
    json.dump(report, open(LINK / 'ogre_names_report.json', 'w'), indent=1, sort_keys=True)
    from collections import Counter
    st = Counter(r['status'] for r in report.values())
    print('ogre-layer vtables %d (%d classes) | %s' % (len(tables), len(classes), dict(st)))
    print('named %d exe addresses (%d folded with >1 name), %d vtable symbols, %d import slots validated'
          % (len(names), len(folded), len(vtnames), sum(r.get('imports_validated', 0) for r in report.values())))
    return names


if __name__ == '__main__':
    main()

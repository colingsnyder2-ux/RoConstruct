"""Batch route-1 conversion of the Ogre layer: server-exact analogs -> linkable, byte-proven objects (no LLM).

For each Ogre-layer address with src/2008-06/ADDR.cpp (RTTI unit Ogre:: / RBX::RenderNew / RBX::ViewNew, or named
by ogre_names.py):
  1. compile the analog exactly as the server does (match.compile_text: roc-cl / roc-flags / roc-lib units);
  2. find the object function byte-identical to ADDR (fingerprint.Target.same) whose data refs also match
     (match.data_check); route 2: if none, hex literals equal to an exe relocation value in ADDR are replaced by
     `(unsigned)roc_abs_X` (an extern symbol: same encoding, now with a relocation) and the analog recompiled;
  3. every relocation target is renamed to the real name of the 2008 address the exe relocation points at:
     ogre_names.json / namer names.json (headers), ogre_vtables.json / RTTI vtables and type descriptors, IAT
     (__imp_X) and import thunks, rebuilt library symbols, roc-lib analog symbols; a callee with no real name but
     its own convertible analog gets a synthetic name roc_fn_ADDR and is emitted too (greatest fixpoint: a
     job survives only while every relocation it needs resolves);
  4. the function is renamed (its real name; folded-body aliases are added as extra symbols), other definitions
     stripped, and the written object is re-proven against the exe bytes.
usage: python work/native-client/ogre/ogre_convert.py [ADDR ...]
  -> renamed/ADDR.obj, link/ogre_convert.json {addr: {status, symbol, ...}},
     link/importlibs/*.lib exact PE import-table providers (including ordinals)."""
import json, os, re, struct, sys
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
NC = HERE.parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(NC))
from roc import match, native_asm, fingerprint, rtti, rebuild, delink  # noqa: E402
import rename as r1  # noqa: E402  route-1 COFF helpers (read-only reuse)

CLIENT = '2008-06'
SRC = ROOT / 'src' / CLIENT
OUT = (Path(os.environ['OGRE_OUT']) if os.environ.get('OGRE_OUT') else HERE / 'renamed').resolve()
LINK = (Path(os.environ['OGRE_LINK']) if os.environ.get('OGRE_LINK') else HERE / 'link').resolve()
JOBS = int(os.environ.get('ROC_JOBS') or max(4, (os.cpu_count() or 8) - 2))
CACHE = (Path(os.environ['OGRE_CACHE']) if os.environ.get('OGRE_CACHE') else HERE / 'cache').resolve()


def compile_cached(text):
    """match.compile_text with a disk cache. Failures are cached too (as .err) so they are not retried."""
    import hashlib
    CACHE.mkdir(exist_ok=True)
    match.reject_asm(text)
    cache_text = text
    directives = match.directives(text)
    if directives.get('lib'):
        from roc import libs
        recipe, _, path = directives['lib'].partition(' ')
        build = int(directives.get('cl') or 21022)
        # Metadata-only packets do not change when a vendor TU/header changes.
        # Key on the same expanded source match.compile_text actually compiles.
        cache_text += '\n' + libs.unit(recipe, path.strip(), build)
    key = hashlib.sha1(cache_text.encode('utf-8', 'replace')).hexdigest()
    obj, err = CACHE / (key + '.obj'), CACHE / (key + '.err')
    if obj.exists():
        return obj.read_bytes()
    if err.exists():
        raise match.CompileError(err.read_text())
    try:
        data = match.compile_text(CLIENT, text)
    except Exception as e:
        err.write_text(str(e)[:2000])
        raise
    obj.write_bytes(data)
    return data
MAX_JOBS = int(os.environ.get('OGRE_MAX_JOBS', '5000'))
REL32, DIR32 = 0x14, 0x06
DEFAULT_SCOPE = ('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew')
SCOPE = tuple(s for s in os.environ.get('ROC_SCOPE', ','.join(DEFAULT_SCOPE)).split(',') if s)
LOCAL = ('??_C@', '__TI', '__CTA', '__CT??', '__ehhandler$', '__unwindfunclet$', '__catch$', '$', '.', '__real@', '__xmm@')
RUNTIME = ('___security_cookie', '___CxxFrameHandler', '__except_handler', '__chkstk', '__EH_prolog', '__alloca_probe',
           '__ftol2', '__CIcos', '__CIsin', '__CIsqrt', '__CIpow', '__CIfmod', '__CIatan2', '__CIexp', '__CIlog',
           '___CxxThrowException@8', '__purecall', '__fltused', '__allmul', '__alldiv', '__aulldiv', '__allrem',
           '__aullrem', '__allshl', '__allshr', '__aullshr', '___CppXcptFilter', '__RTDynamicCast', '__ftol2_sse')

TARGET = None
BASE = IMAGE = None


def load(name):
    # A batch run points LINK at its own empty dir; ogre_names.py writes HERE/link.
    for p in (LINK / name, HERE / 'link' / name, NC / 'link' / name):
        if p.exists():
            return json.load(open(p))
    return {}


def load_registry():
    try:
        return json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    except (OSError, ValueError):
        return {}


NAMES = {}       # addr -> authentic decorated name (headers)
REGISTRY = {}    # addr -> whole-exe identity row
ALIASES = {}     # addr -> [names] for folded bodies
VTABLES = {}     # vtable va -> ??_7 symbol
LIBNAMES = {}    # addr -> symbol of its roc-lib analog (vendor source compiled with real names)
DESCRIPTORS = {}
IAT_IMPORTS = None  # IAT VA -> exact COFF import-pointer symbol (including PE ordinal imports)


def exe_reloc_values(va, size):
    return {struct.unpack_from('<I', IMAGE, va + o - BASE)[0] for o in TARGET.exe_relocs(va, size)}


def import_pointers():
    """Build exact import-map libs from the PE import directory, never from code.

    This also supplies MSVCP90: its matching import library is absent from the
    bundled compiler.  Ordinal imports have no C spelling, so their output
    object needs the exact import pointer symbol produced by an import .def
    ``@ordinal NONAME`` entry.  Providers live under ``link/importlibs``.
    """
    global IAT_IMPORTS
    if IAT_IMPORTS is None:
        import pefile
        pe = pefile.PE(str(ROOT / 'clients' / CLIENT / 'Roblox.exe'))
        out = LINK / 'importlibs'
        out.mkdir(parents=True, exist_ok=True)
        IAT_IMPORTS = delink.import_libs(pe, out, rebuild.toolchain(21022))
    return IAT_IMPORTS


def proof_same(addr, code, relocs):
    """Return target bytes for a body proved under COFF relocation semantics.

    Base-relocated exe words must be emitted as object relocations: accepting a
    literal there would reintroduce the masked-absolute-address hole.  REL32
    call targets have no PE base relocation, however, so their object fields
    must be union-masked with the target for the pre-link proof.  refs_of()
    subsequently derives and proves each of those call targets before output.
    """
    va = int(addr, 16)
    exe_relocs = TARGET.exe_relocs(va, len(code))
    if not exe_relocs <= set(relocs):
        return None
    exe = bytes(IMAGE[va - BASE:va - BASE + len(code)])
    return exe if match.exact_match(exe, exe_relocs, code, relocs) else None


def proof_why(addr, code, relocs):
    """Compact deterministic rejection detail for a failed re-proof."""
    va = int(addr, 16)
    exe_relocs = TARGET.exe_relocs(va, len(code))
    missing = sorted(exe_relocs - set(relocs))
    if missing:
        return 'missing object relocations at ' + ','.join('%x' % x for x in missing[:8])
    exe = bytes(IMAGE[va - BASE:va - BASE + len(code)])
    mask = exe_relocs | set(relocs)
    diff = [i for i, (x, y) in enumerate(zip(exe, code)) if i not in mask and x != y]
    return ('unmasked bytes differ at ' + ','.join('%x' % x for x in diff[:8]) if diff else
            'proof rejected without visible body delta')


def literal_map(va, size, data):
    """{literal in the route-1 object: exe value} at exe relocation sites the object leaves unrelocated
    (the server's masked check accepts any literal there, so a source literal can differ from the exe's)."""
    out = {}
    exe_rel = TARGET.exe_relocs(va, size)
    for name, code, relocs in match.coff_functions(data):
        if len(code) != size:
            continue
        for p in exe_rel - set(relocs):
            out[struct.unpack_from('<I', code, p)[0]] = struct.unpack_from('<I', IMAGE, va + p - BASE)[0]
    return out


def route2(text, va, size, lits=None):
    """Hardcoded absolute addresses -> extern symbols (same instruction encoding plus a relocation)."""
    vals = exe_reloc_values(va, size)
    lits = lits or {}
    code = '\n'.join(l for l in text.splitlines() if not l.lstrip().startswith('//'))
    used = set()

    def sub(m):
        v = int(m.group(1), 16)
        v = lits.get(v, v)
        if v in vals:
            used.add(v)
            return '((unsigned)roc_abs_%08x)' % v
        return m.group(0)
    # MSVC-era analogs commonly spell address literals 0xNNNNNNNNUL.  The
    # old trailing word-boundary pattern could not see those constants.
    literal = r'\b(0[xX][0-9a-fA-F]{6,8})(?:[uUlL]*)\b'
    lines = [l if l.lstrip().startswith('//') else re.sub(literal, sub, l) for l in text.splitlines()]
    if not used:
        return None
    del code
    decl = ''.join('extern "C" char roc_abs_%08x[];\n' % v for v in sorted(used))
    return decl + '\n'.join(lines) + '\n'


def import_method_wrappers(text):
    """Replace a trivial mined ``thiscall`` wrapper with its real dllimport method.

    Miners sometimes model a library member as a local class method which calls
    an imported function pointer.  That proves the main body, but VS2008 also
    emits unproved local wrapper COMDATs.  A one-call inline member has same
    source semantics when declared dllimport; only use this alternate source
    form when its recompiled target body proves exact.
    """
    out = text
    changed = False
    ptr = re.compile(r'^extern\s+(.+?)\s*\(\s*__thiscall\s*\*\s*(\w+)\s*\)\s*'
                     r'\(\s*(\w+)\s*\*\s*(?:,\s*([^;]*?))?\s*\);\s*$', re.M)
    wrappers = [(m.group(2), m.group(3)) for m in ptr.finditer(text)]
    for fn, cls in wrappers:
        # Only a literal single-call inline member may be replaced.  This
        # is not a general decompiler rewrite and never changes a nontrivial
        # mined method.
        body = re.compile(r'\ninline\s+(?:[^\n{]*?\s+)?' + re.escape(cls) + r'::'
                          r'(~?' + re.escape(cls) + r'|operator[^\s(]+|\w+)\s*\(([^)]*)\)\s*\{\s*'
                          r'(?:return\s+)?' + re.escape(fn) +
                          r'\s*\(\s*this(?:\s*,\s*[^;]*?)?\s*\)\s*;\s*\}\s*\n', re.S)
        hit = body.search(out)
        if not hit:
            continue
        method, args = hit.group(1), hit.group(2)
        # Implementations name arguments while declarations commonly do not.
        # Permit that spelling difference, but never choose between overloads.
        decl = re.compile(r'^([ \t]*)([^;(\r\n]*?)(?<![A-Za-z0-9_~])' + re.escape(method) +
                          r'\s*\(([^;\r\n]*)\)\s*;\s*$', re.M)
        declarations = list(decl.finditer(out))
        if len(declarations) != 1:
            continue
        dhit = declarations[0]
        out = (out[:dhit.start()] + dhit.group(1) + '__declspec(dllimport) ' + dhit.group(2) + method +
               '(' + dhit.group(3) + ');' + out[dhit.end():])
        # The declaration replacement can move the inline body; find it again
        # before deleting.  Never apply offsets captured from a prior string.
        hit = body.search(out)
        if not hit:
            return None
        out = out[:hit.start()] + '\n' + out[hit.end():]
        pnow = next((p for p in ptr.finditer(out) if p.group(2) == fn and p.group(3) == cls), None)
        if not pnow:
            return None
        out = out[:pnow.start()] + out[pnow.end():]
        changed = True
    return out if changed else None


def has_mined_body(text):
    """True unless a roc-lib directive is the packet's only C++ body."""
    if not match.directives(text).get('lib'):
        return True
    return any(line.strip() and not line.lstrip().startswith(('#', '//')) for line in text.splitlines())


def source_policy_violations(text):
    """Reject bodies that model unknown class storage through raw byte offsets.

    A byte match cannot turn a ``char* + 0xNN`` reinterpretation into proved
    layout.  Keep the analog available as evidence, but never emit it as a
    link provider.  This is deliberately syntax-narrow: normal arithmetic,
    ``offsetof`` assertions, and authentic declared fields remain allowed.
    """
    bad = []
    if re.search(r'\bproxyField\s*(?:<|\()', text):
        bad.append('proxyField raw-offset view')
    if re.search(r'(?:reinterpret_cast|static_cast)\s*<\s*(?:const\s+)?(?:unsigned\s+)?char\s*\*\s*>\s*\([^)]*\)\s*\+\s*(?:0[xX][0-9a-fA-F]+|\d+)', text):
        bad.append('byte-pointer plus constant offset layout view')
    if re.search(r'reinterpret_cast\s*<[^>]+>\s*\(\s*static_cast\s*<\s*char\s*\*\s*>\s*\([^)]*\)\s*\+\s*0x[0-9a-f]+', text, re.I | re.S):
        bad.append('char-pointer plus hexadecimal offset reinterpretation')
    return bad


def effective_source_policy(text):
    """Apply source policy to the actual roc-lib TU, not only its metadata wrapper."""
    bad = source_policy_violations(text)
    lib = match.directives(text).get('lib', '')
    recipe, _, path = lib.partition(' ')
    if not recipe or not path.strip():
        return bad
    try:
        from roc import libs
        vendor = libs.fetch(recipe) / path.strip().replace('/', os.sep)
        if vendor.is_file():
            bad += source_policy_violations(vendor.read_text(errors='replace'))
    except (OSError, SystemExit):
        pass                            # compile path reports missing recipe/source normally
    return list(dict.fromkeys(bad))


def compile_one(addr):
    try:
        return _compile_one(addr)
    except (Exception, SystemExit) as e:     # one bad analog/address must not stop the batch
        return dict(status='error', why=[repr(e)[:200]])


def _compile_one(addr):
    """-> dict(status, obj bytes, fsym, route) for the analog's byte-identical function, else a failure status."""
    src = SRC / (addr + '.cpp')
    if not src.is_file():
        return dict(status='no-source', why=['no mined packet'])
    text = src.read_text(errors='replace')
    policy = effective_source_policy(text)
    if policy:
        return dict(status='source-policy', why=policy)
    row = match._functions(CLIENT).get(addr)
    if not row:
        return dict(status='no-function')
    grade = re.search(r'^// from server:\s*(\d+)%', text, re.M)
    if grade and int(grade.group(1)) < 100:
        return dict(status='unmined', why=['server analog %s%%' % grade.group(1)])
    if row.get('kind') != 'code' and not grade:
        return dict(status='unmined', why=['target row is %s; source has no server provenance' % row.get('kind')])
    # A roc-lib directive replays a vendor .cpp through match.compile_text.
    if match.directives(text).get('lib'):
        if not has_mined_body(text):
            if os.environ.get('OGRE_VENDOR_SOURCE') != '1':
                return dict(status='vendor-source',
                            why=['roc-lib replay only; enable OGRE_VENDOR_SOURCE=1 for exact vendor lane'])
        else:
            text = re.sub(r'^// roc-lib:.*\n', '', text, flags=re.M)
    va, size = int(addr, 16), len(match.target(CLIENT, addr)[0])
    imported = import_method_wrappers(text)
    # Prefer import declarations: they can preserve VS2008's real EH cleanup
    # thunk instead of emitting a local wrapper COMDAT.  Exact proof remains
    # the acceptance gate; ordinary mined source is the fallback.
    tries = ([('import-wrapper', imported)] if imported else []) + [('route1', text)]
    # Only a replay-only vendor packet still carries roc-lib here: its symbols are the vendor's real names.
    lib = bool(match.directives(text).get('lib'))
    replay = match.directives(text).get('lib', '').partition(' ')[2].strip().replace('\\', '/')
    name_proved = lib and not Path(replay).name.startswith('roc_')
    r2 = None
    extent = None
    last = 'nomatch'
    for route, t in tries:
        try:
            data = compile_cached(t)
        except (Exception, SystemExit) as e:  # CompileError, SystemExit (local-only tree)
            last = 'compile-fail'
            why = str(e).strip().splitlines()[:2]
            continue
        funcs = match.coff_functions(data)
        if extent is None:
            from roc import bounds_proof
            extent = bounds_proof.tail_proof(CLIENT, addr, funcs)
        # A whole-library object can contain several identical masked bodies.
        # Prefer target-owned evidence over symbol-table order: an address map,
        # then the miner's explicit `(function NAME)` provenance line.  Only
        # constrain selection when that exact symbol is actually in this obj.
        wanted = NAMES.get(addr)
        if not wanted:
            m = re.search(r'^// (?:library|standard library) .+ \(function (.+)\)$', text, re.M)
            wanted = m.group(1) if m else None
        if wanted and any(name == wanted for name, _, _ in funcs):
            funcs = [f for f in funcs if f[0] == wanted]
        for name, code, relocs in funcs:
            proven_extent = extent if extent and extent['symbol'] == name else None
            expected = proven_extent['new'] if proven_extent else size
            if len(code) != expected:         # a shorter body could equal a prefix of the target
                continue
            exe = proof_same(addr, code, relocs)
            if exe is None:
                continue
            _, bad = match.data_check(CLIENT, addr, exe, match.coff_data_refs(data, name))
            if bad:
                last = 'data-mismatch'
                continue
            return dict(status='match', obj=data, fsym=name, code=code, relocs=relocs,
                        route=route, lib=lib, name_proved=name_proved, size=len(code), extent=proven_extent)
        if last != 'data-mismatch':
            last = 'nomatch'
        if route == 'route1' and not lib:
            r2 = route2(text, va, size, literal_map(va, size, data))
            if r2:
                tries.append(('route2', r2))
    if extent:
        return dict(status='extent', why=['clean target extent %d -> %d' % (extent['old'], extent['new'])], extent=extent)
    return dict(status=last, why=why if last == 'compile-fail' else None, route2_tried=bool(r2))


def relocations(data, fsym):
    """rename.relocations, but for the *defined* symbol of that name (an object can also hold an undefined twin)."""
    syms, (nsec, symptr, nsym, optsz, _) = r1.symtab(data)
    s = next(x for x in syms if x[1] == fsym and x[2] > 0)
    sec, value = s[2] - 1, s[4]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * sec)
    return [(off - value, typ, idx, rawptr + off) for off, idx, typ in
            (struct.unpack_from('<IIH', data, relptr + 10 * k) for k in range(nrel))]


def relocation_slots(data, fsym):
    """Like relocations(), but fourth value is COFF relocation symbol-index slot."""
    syms, (nsec, symptr, nsym, optsz, _) = r1.symtab(data)
    s = next(x for x in syms if x[1] == fsym and x[2] > 0)
    sec, value = s[2] - 1, s[4]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * sec)
    return [(struct.unpack_from('<I', data, relptr + 10 * k)[0] - value,
             struct.unpack_from('<H', data, relptr + 10 * k + 8)[0],
             struct.unpack_from('<I', data, relptr + 10 * k + 4)[0], relptr + 10 * k + 4)
            for k in range(nrel)]


def patch_eh_imports(data, patches):
    """Give exact EH imports private undefined symbols; never alias main-body refs."""
    if not patches:
        return data
    data = bytearray(data)
    made = {}
    for slot, name in patches:
        if name not in made:
            _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
            strtab = symptr + nsym * 18
            size = struct.unpack_from('<I', data, strtab)[0]
            rec = struct.pack('<IIIhHBB', 0, size, 0, 0, 0, 2, 0)
            tail = bytearray(data[strtab:])
            encoded = name.encode('latin-1') + b'\0'
            struct.pack_into('<I', data, 12, nsym + 1)
            struct.pack_into('<I', tail, 0, size + len(encoded))
            data = bytearray(data[:strtab] + rec + tail[:size] + encoded + tail[size:])
            made[name] = nsym
        struct.pack_into('<I', data, slot, made[name])
    return bytes(data)


def output_body(data, sym, size):
    """(code, reloc offsets) for one retained external symbol, fixed to its proven size.

    strip_symbols removes neighbouring definitions in a shared .text section.
    coff_functions then has no later symbol boundary and would incorrectly
    absorb that unreachable tail into this symbol.  The original byte-proven
    body size is the authoritative boundary here.
    """
    syms, (nsec, symptr, nsym, optsz, _) = r1.symtab(data)
    found = [(i, sec, value) for i, name, sec, cls, value in syms if name == sym and sec > 0 and cls == 2]
    if len(found) != 1:
        return None
    _, secnum, value = found[0]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * (secnum - 1))
    # .bss has no file bytes.  Never treat the COFF header at offset zero as
    # synthetic storage; callers that can prove an all-zero BSS range handle it.
    if not rawptr or value + size > rawsize:
        return None
    relocs = [off - value for off, _, _ in
              (struct.unpack_from('<IIH', data, relptr + 10 * k) for k in range(nrel))
              if value <= off < value + size]
    return bytes(data[rawptr + value:rawptr + value + size]), relocs


def prune_unused_comdat_data(data):
    """Drop only compiler data sections unreachable from retained COFF sections.

    Code/data bytes stay untouched. Follow relocations and associative COMDAT
    edges before dropping; keep ordinary data and initializer sections as roots.
    """
    syms, (nsec, _, _, optsz, _) = r1.symtab(data)
    sections = [struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * k) for k in range(nsec)]
    targets = {i: sec for i, _, sec, _, _ in syms}
    candidates = {i + 1 for i, s in enumerate(sections) if s[9] & 0x1000 and not s[9] & (0x20 | 0x800)
                  and not s[0].startswith((b'.CRT', b'.tls'))}
    live = {i + 1 for i, s in enumerate(sections) if not s[9] & 0x800 and i + 1 not in candidates}
    edges = {}
    for i, s in enumerate(sections, 1):
        edges[i] = {targets.get(struct.unpack_from('<I', data, s[5] + k * 10 + 4)[0], 0) for k in range(s[7])}
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    i = 0
    while i < nsym:
        _, value, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', data, symptr + 18 * i)
        if cls == 3 and aux and sec > 0 and value == 0:
            parent, selection = struct.unpack_from('<HB', data, symptr + 18 * (i + 1) + 12)
            if selection == 5:
                edges.setdefault(parent, set()).add(sec)
        i += 1 + aux
    pending = list(live)
    while pending:
        for sec in edges.get(pending.pop(), ()):
            if sec > 0 and sec not in live and not sections[sec - 1][9] & 0x800:
                live.add(sec)
                pending.append(sec)
    drop = {name for _, name, sec, cls, _ in syms if cls == 2 and sec in candidates - live}
    return rebuild.strip_symbols(data, drop=drop) if drop else data


def data_proved(data, sym, va, size):
    """Generated data must match target bytes, or prove a zero BSS range."""
    hit = output_body(data, sym, size)
    target = IMAGE[va - BASE:va - BASE + size]
    if hit:
        return hit[0] == target and not hit[1]
    syms, (_, _, _, optsz, _) = r1.symtab(data)
    found = [(sec, value) for _, name, sec, cls, value in syms if name == sym and sec > 0 and cls == 2]
    if len(found) != 1 or any(target):
        return False
    secnum, value = found[0]
    sh = 20 + optsz + 40 * (secnum - 1)
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, sh)
    # MSVC COFF encodes BSS's allocated extent in SizeOfRawData while its
    # PointerToRawData is zero.  A raw-backed section was handled above.
    if rawptr or value + size > rawsize:
        return False
    return not any(value <= struct.unpack_from('<I', data, relptr + 10 * k)[0] < value + size for k in range(nrel))


def export_symbol(data, index):
    """Promote one selected internal COFF definition for its standalone link object."""
    data = bytearray(data)
    _, _, _, symptr, _, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    data[symptr + 18 * index + 16] = 2
    return bytes(data)


def eh_unwind_actions(addr, size):
    """Return x86 MSVC FuncInfo unwind-action VAs for one target body.

    This recognizes only the old MSVC handler thunk shape used by the target:
    ``push handler`` in the body, then ``mov eax, FuncInfo; jmp handler``.
    Every pointer is range- and magic-checked before use.  It is evidence for
    companion cleanup thunks, not a declaration/layout source.
    """
    lo, hi = BASE, BASE + len(IMAGE)
    code = IMAGE[int(addr, 16) - BASE:int(addr, 16) - BASE + size]
    for at in range(len(code) - 5):
        if code[at] != 0x68:
            continue
        handler = struct.unpack_from('<I', code, at + 1)[0]
        if not lo <= handler <= hi - 10:
            continue
        h = IMAGE[handler - BASE:handler - BASE + 10]
        if h[0] != 0xb8 or h[5] != 0xe9:
            continue
        info = struct.unpack_from('<I', h, 1)[0]
        if not lo <= info <= hi - 16 or struct.unpack_from('<I', IMAGE, info - BASE)[0] not in (0x19930520, 0x19930522):
            continue
        states, table = struct.unpack_from('<iI', IMAGE, info - BASE + 4)
        if not 0 <= states <= 64 or not lo <= table <= hi - states * 8:
            continue
        return [struct.unpack_from('<I', IMAGE, table - BASE + 8 * i + 4)[0] for i in range(states)]
    return []


def eh_import_patches(data, fsym, addr, size):
    """Private-symbol patches for imports used only by exact EH cleanup thunks.

    The normal relocation graph starts at the selected function, so an import
    used solely by ``__unwindfunclet$...`` would retain its mined spelling.
    Patch its relocation only when that whole companion body proves against
    one target FuncInfo unwind action and its word is a target base relocation.
    A compiler can reuse one undefined symbol index for a different main-body
    import; a private symbol prevents that false alias from changing either.
    """
    actions = eh_unwind_actions(addr, size)
    if not actions:
        return []
    syms, _ = r1.symtab(data)
    names = {i: n for i, n, sec, cls, value in syms}
    patches = []
    for name, code, relocs in match.coff_functions(data):
        if not name.startswith('__unwindfunclet$' + fsym + '$'):
            continue
        hits = [va for va in actions if va and proof_same('%08x' % va, code, relocs) is not None]
        if len(hits) != 1:
            continue
        va = hits[0]
        for off, typ, idx, slot in relocation_slots(data, name):
            if off not in TARGET.exe_relocs(va, len(code)):
                continue
            target = struct.unpack_from('<I', IMAGE, va - BASE + off)[0]
            real, how = real_name(target, names[idx])
            if real:
                patches.append((slot, real))
    return patches


def refs_of(job, addr):
    """[(symbol index, analog name, target va, type, kind)]; kind local|runtime|ref."""
    data, fsym = job['obj'], job['fsym']
    syms, _ = r1.symtab(data)
    by = {i: (n, sec, cls) for i, n, sec, cls, v in syms}
    out = []
    for off, typ, idx, fileoff in relocations(data, fsym):
        name, sec, cls = by[idx]
        if typ not in (REL32, DIR32):
            continue
        if not 0 <= off < job['size']:
            out.append((idx, name, None, typ, 'outside'))   # a catch funclet etc. past the proven body
            continue
        addend = struct.unpack_from('<i', data, fileoff)[0]
        site = int(addr, 16) + off
        word = struct.unpack_from('<I', IMAGE, site - BASE)[0]
        tva = word - addend if typ == DIR32 else (site + 4 + struct.unpack_from('<i', IMAGE, site - BASE)[0]) - addend
        if cls == 3 or name.startswith(LOCAL):
            out.append((idx, name, None, typ, 'local'))
            continue
        kind = 'runtime' if name.startswith(RUNTIME) else 'ref'
        out.append((idx, name, tva, typ, kind))
    return out


_SYSLIB = None


def syslib():
    """(public symbols of the VC/SDK/ATL-MFC libraries, {undecorated C import: [__imp_ symbols]})."""
    global _SYSLIB
    if _SYSLIB is None:
        tc = rebuild.toolchain(21022)
        syms = set()
        for d in ('vc_lib', 'sdk_lib', 'atlmfc_lib'):
            for lib in Path(tc[d]).glob('*.lib'):
                syms |= r1._SC['archive_symbols'](lib)
        imps = {}
        for s in syms:
            m = re.fullmatch(r'__imp__(\w+?)(@\d+)?', s)
            if m:
                imps.setdefault(m.group(1), set()).add(s)
        _SYSLIB = syms, imps
    return _SYSLIB


def c_import(imp, thunk):
    """Decorated name of a C import from the import libraries (stdcall @N included), or None if ambiguous."""
    c = syslib()[1].get(imp, set())
    if len(c) != 1:
        return None
    s = next(iter(c))
    return s[len('__imp_'):] if thunk else s


def primary_vtable(va):
    """??_7X@@6B@ only for a single-inheritance primary vtable (COL offset 0, hierarchy without MI/VI)."""
    rd = lambda a: struct.unpack_from('<I', IMAGE, a - BASE)[0] if BASE <= a < BASE + len(IMAGE) - 4 else None
    col = rd(va - 4)
    if not col or rd(col) != 0 or rd(col + 4) != 0 or not rd(col + 16):
        return None
    if rd(rd(col + 16) + 4) & 3:
        return None
    vt = r1.vtable_name(va)
    return vt


SCALARS = {'C': ('signed char', 1, 'b'), 'D': ('char', 1, 'b'), 'E': ('unsigned char', 1, 'B'),
           'F': ('short', 2, 'h'), 'G': ('unsigned short', 2, 'H'), 'H': ('int', 4, 'i'),
           'I': ('unsigned int', 4, 'I'), 'J': ('long', 4, 'i'), 'K': ('unsigned long', 4, 'I'),
           'M': ('float', 4, 'f'), 'N': ('double', 8, 'd'), '_N': ('bool', 1, 'B'),
           '_J': ('__int64', 8, 'q'), '_K': ('unsigned __int64', 8, 'Q')}
DATA = {}        # va -> C definition line of a synthetic data symbol (typed from the analog's mangled name)
DATA_SIZES = {}  # va -> exact target storage size required in the generated COFF object
_SECTIONS = None


def data_section(va):
    """(name, raw end va) of the exe section holding va, or None (pefile, read once)."""
    global _SECTIONS
    if _SECTIONS is None:
        import pefile
        pe = pefile.PE(str(ROOT / 'clients' / CLIENT / 'Roblox.exe'), fast_load=True)
        b = pe.OPTIONAL_HEADER.ImageBase
        _SECTIONS = [(s.Name.rstrip(b'\0').decode(), b + s.VirtualAddress, b + s.VirtualAddress + s.Misc_VirtualSize,
                      b + s.VirtualAddress + s.SizeOfRawData) for s in pe.sections]
    for n, lo, hi, raw in _SECTIONS:
        if lo <= va < hi:
            return n, raw
    return None


def data_def(tva, analog_name):
    """C definition of `roc_data_<va>` with the analog's scalar/pointer type and the exe's value, or None.
    Values come from the binary; pointers only when null (a non-null pointer needs its target's symbol)."""
    sec = data_section(tva)
    if not sec or sec[0] not in ('.data', '.rdata'):
        return None
    m = re.search(r'@@[23](.+)$', analog_name)
    if not m:
        return None
    t = m.group(1)
    cv = t[-1]
    if cv not in 'AB':
        return None
    const = 'const ' if cv == 'B' or sec[0] == '.rdata' else ''
    name = 'roc_data_%08x' % tva
    zero = tva >= sec[1]                     # past the section's raw data: zero-filled (.bss)
    # `?name@@3QBDB` is a const char object in MSVC mangling.  Accept it only
    # when the target itself is a complete printable .rdata C string.  This is
    # a typed source literal, not a copied byte blob or an inferred layout.
    if t == 'QBDB':
        if zero or sec[0] != '.rdata' or TARGET.exe_relocs(tva, 1):
            return None
        end = IMAGE.find(b'\0', tva - BASE, sec[1] - BASE)
        if end < 0:
            return None
        raw = IMAGE[tva - BASE:end]
        if not raw or any(c not in (9, 10, 13) and not 0x20 <= c <= 0x7e for c in raw):
            return None
        literal = (raw.decode('ascii').replace('\\', '\\\\').replace('"', '\\"')
                   .replace('\t', '\\t').replace('\n', '\\n').replace('\r', '\\r'))
        DATA_SIZES[tva] = len(raw) + 1
        return 'extern "C" const char %s[] = "%s";' % (name, literal)
    if t[0] in 'PQ':
        size, ctype = 4, 'void*'
        relocated = bool(TARGET.exe_relocs(tva, 4)) if not zero else False
        if not zero and (relocated or struct.unpack_from('<I', IMAGE, tva - BASE)[0]):
            return None
        DATA_SIZES[tva] = size
        return '%sextern "C" %s %s%s = 0;' % ('', ctype + (' const' if const else ''), name, '')
    if t[:-1] not in SCALARS:
        return None
    ctype, size, fmt = SCALARS[t[:-1]]
    if zero:
        v = 0
    else:
        if TARGET.exe_relocs(tva, size):
            return None
        v = struct.unpack_from('<' + fmt, IMAGE, tva - BASE)[0]
    if isinstance(v, float):
        import math
        if not math.isfinite(v):
            return None
        lit = ('%.9g' % v) if fmt == 'f' else ('%.17g' % v)
        if not re.search(r'[.e]', lit):
            lit += '.0'
        lit += 'f' if fmt == 'f' else ''
        if struct.pack('<' + fmt, float(lit.rstrip('f'))) != struct.pack('<' + fmt, v):
            return None
    else:
        lit = str(v)
    DATA_SIZES[tva] = size
    return 'extern "C" %s%s %s = %s;' % (const, ctype, name, lit)


def real_name(tva, analog_name):
    """(name, source) for a relocation target; name '' keeps the analog's own spelling (validated C import)."""
    a = '%08x' % tva
    row = REGISTRY.get(a)
    if row and not row.get('placeholder') and row.get('name_source') != 'import-table':
        return row['name'], 'registry:' + row['name_source']
    if a in NAMES:
        return NAMES[a], 'header'
    if a in VTABLES:
        return VTABLES[a], 'vtable'
    iat = native_asm.names(CLIENT).get(tva)
    if iat and '!' in iat:
        imp = iat.split('!', 1)[1]
        exact = import_pointers().get(tva)
        if exact:
            return exact, 'iat-ordinal' if imp.startswith('#') else 'iat-map'
        if imp.startswith('?'):
            return '__imp_' + imp, 'iat'
        if re.fullmatch(r'__imp__%s(@\d+)?' % re.escape(imp), analog_name):
            return '', 'iat'
        dec = c_import(imp, False)
        return (dec, 'iat-c') if dec else (None, 'iat-c:' + imp)
    if iat:
        return iat, 'rebuilt'
    th = native_asm.thunk_label(CLIENT, tva)
    if th:
        th = re.sub(r'^(MFC|ATL|CRT)\s+', '', th).split()[0]
        if '!' in th:
            imp = th.split('!', 1)[1]
            if imp.startswith('?'):
                return imp, 'thunk'
            if re.fullmatch(r'_%s(@\d+)?' % re.escape(imp), analog_name):
                return '', 'thunk'
            dec = c_import(imp, True)
            return (dec, 'thunk-c') if dec else (None, 'thunk-c:' + imp)
        return th, 'thunk'
    vt = primary_vtable(tva)
    if vt:
        return vt, 'rtti-vtable'
    if tva in DESCRIPTORS:
        return '??_R0' + DESCRIPTORS[tva][1:] + '@8', 'rtti-descriptor'
    if a in LIBNAMES:
        return LIBNAMES[a], 'lib'
    if tva in DATA:
        return (('_roc_data_' + a) if DATA[tva] else None), 'data'
    d = data_def(tva, analog_name)
    if d:
        DATA[tva] = d
        return '_roc_data_' + a, 'data'
    return None, None


def own_name(addr, job):
    row = REGISTRY.get(addr)
    if row and row.get('kind') == 'code' and not row.get('placeholder'):
        return row['name'], 'registry:' + row['name_source']
    if addr in NAMES:
        return NAMES[addr], 'header'
    if job.get('name_proved') and re.match(r'^(\?|_[A-Za-z])', job['fsym']):
        return job['fsym'], 'lib'
    if row and row.get('kind') == 'code':
        return row['name'], 'registry:' + row['name_source']
    return 'func_' + addr, 'placeholder'


def add_aliases(data, sym, aliases):
    """Extra external symbols at the same section/value as sym (folded identical bodies with several names)."""
    if not aliases:
        return data
    data = bytearray(data)
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    size = struct.unpack_from('<I', data, strtab)[0]
    syms, _ = r1.symtab(bytes(data))
    i = next(i for i, n, sec, cls, v in syms if n == sym and cls == 2 and sec > 0)
    value, secnum, typ = struct.unpack_from('<IhH', data, symptr + 18 * i + 8)
    recs, names = bytearray(), bytearray()
    for n in aliases:
        recs += struct.pack('<IIIhHBB', 0, size + len(names), value, secnum, typ, 2, 0)
        names += n.encode('latin-1') + b'\0'
    struct.pack_into('<I', data, 12, nsym + len(aliases))
    tail = bytearray(data[strtab:])
    struct.pack_into('<I', tail, 0, size + len(names))
    return bytes(data[:strtab] + recs + tail[:size] + names + tail[size:])


def scope():
    funcs = match._functions(CLIENT)
    if os.environ.get('ROC_ALL_ANALOGS') == '1':
        # Scale mode remains source-only: compile_one() rejects replay-only
        # roc-lib packets before compilation.  Callers still choose a small
        # address slice and OGRE_MAX_JOBS; this only supplies generic roots.
        out = []
        for a in funcs:
            p = SRC / (a + '.cpp')
            if not p.exists():
                continue
            text = p.read_text(errors='replace')
            if re.search(r'^// from server:\s*100%', text, re.M) and has_mined_body(text):
                out.append(a)
        return sorted(out)
    s = {a for a, r in funcs.items() if r['unit'].startswith(SCOPE)}
    if SCOPE == DEFAULT_SCOPE:
        s |= set(load('ogre_names.json'))
        s |= {a for a, n in load('names.json').items() if re.search(r'@(Ogre|RenderNew@RBX|ViewNew@RBX)@@', n)}
    return sorted(a for a in s if (SRC / (a + '.cpp')).exists() and
                  re.search(r'^// from server:\s*100%', (SRC / (a + '.cpp')).read_text(errors='replace'), re.M))


def main():
    global TARGET, BASE, IMAGE
    OUT.mkdir(parents=True, exist_ok=True)
    LINK.mkdir(parents=True, exist_ok=True)
    TARGET = fingerprint.Target(CLIENT)
    TARGET.index = {}                        # same() only; never pool-matching
    BASE, IMAGE = match._image(CLIENT)
    REGISTRY.update(load_registry())
    NAMES.update({a: row['name'] for a, row in REGISTRY.items()
                  if not row.get('placeholder') and row.get('kind') == 'code'
                  and row.get('name_source') != 'import-table'})
    NAMES.update(load('names.json'))         # namer.py (header address comments)
    for a, n in load('ogre_names.json').items():
        NAMES.setdefault(a, n)
    ALIASES.update(load('ogre_aliases.json'))
    VTABLES.update(load('ogre_vtables.json'))
    DESCRIPTORS.update({va: n for va, n in rtti.descriptors(CLIENT).items() if n.startswith(('.?AV', '.?AU'))})
    roots = sys.argv[1:] or scope()
    rootset = set(roots)
    jobs, queue = {}, list(roots)
    funcs = match._functions(CLIENT)
    with ThreadPoolExecutor(JOBS) as pool:
        while queue and len(jobs) < MAX_JOBS:
            batch = [a for a in dict.fromkeys(queue) if a not in jobs][:MAX_JOBS - len(jobs)]
            queue = []
            for a, res in zip(batch, pool.map(compile_one, batch)):
                jobs[a] = res
                if res['status'] == 'match' and res.get('name_proved') and re.match(r'^(\?|_[A-Za-z])', res['fsym']):
                    LIBNAMES.setdefault(a, res['fsym'])
            # pull in unnamed callees that have their own analogs (candidates for synthetic names)
            for a in batch:
                if jobs[a]['status'] != 'match':
                    continue
                try:
                    jobs[a]['refs'] = refs_of(jobs[a], a)
                except Exception as e:
                    jobs[a] = dict(status='error', why=[repr(e)[:200]])
                    continue
                for idx, n, tva, typ, kind in jobs[a]['refs']:
                    if kind == 'ref' and tva is not None:
                        t = '%08x' % tva
                        if t in funcs and t not in jobs and real_name(tva, n)[0] is None and (SRC / (t + '.cpp')).exists():
                            queue.append(t)
            print('compiled %d jobs (%d matched)' % (len(jobs), sum(j['status'] == 'match' for j in jobs.values())), flush=True)

    # Greatest fixpoint, linearly.  A previous all-live rescan was correct but
    # could walk the full relocation graph once per dependency-chain level.
    # Resolve each reference once, then propagate drops along its reverse job
    # edges.  Final reasons are computed against the final live set below.
    alive = {a for a, j in jobs.items() if j['status'] == 'match'}
    known = r1.known_symbols() | syslib()[0]

    def refs_missing(a, live, deps=None):
        miss = []
        for idx, n, tva, typ, kind in jobs[a]['refs']:
            if kind == 'local' or kind == 'runtime':
                continue
            if kind == 'outside':
                miss.append('%s (relocation outside the proven body)' % n)
                continue
            name, how = real_name(tva, n)
            target = '%08x' % tva
            if name is not None:
                continue
            if target in live:
                if deps is not None:
                    deps.add(target)
                continue
            if n in known and not how:
                continue                 # analog already spells a symbol the link defines
            miss.append('%s -> %08x%s' % (n, tva, ' (%s)' % how if how else ''))
        return miss

    reverse, queued = {}, set()
    queue = []
    # data_def() learns a scalar's usable synthetic name from whichever
    # relocation first carries its mangled type.  Stabilize those names before
    # deciding any job is initially dead; otherwise an early caller can be
    # queued even though a later caller makes the same data target resolvable.
    for a in sorted(alive):
        refs_missing(a, alive)
    for a in sorted(alive):
        deps = set()
        miss = refs_missing(a, alive, deps)
        if miss:
            queue.append(a)
            queued.add(a)
        for target in deps:
            reverse.setdefault(target, set()).add(a)
    while queue:
        dead = queue.pop()
        if dead not in alive:
            continue
        alive.remove(dead)
        for caller in reverse.get(dead, ()):
            if caller in alive and caller not in queued:
                queue.append(caller)
                queued.add(caller)
    # A name provider can become available while discovery warms data/lib
    # names.  Reverse propagation is deliberately conservative, so restore
    # any job whose final references are all independently resolvable.  This
    # cannot revive an unresolved cycle: refs_missing checks the current live
    # set and every restored node has no missing edge.
    matched = {a for a, j in jobs.items() if j['status'] == 'match'}
    while True:
        restore = {a for a in matched - alive if not refs_missing(a, alive)}
        if not restore:
            break
        alive |= restore
    blockers = {a: refs_missing(a, alive) for a, j in jobs.items()
                if j['status'] == 'match' and a not in alive}

    report = {}
    for a, j in sorted(jobs.items()):
        in_scope = a in rootset
        if j['status'] != 'match':
            report[a] = dict(status=j['status'], scope=in_scope, why=j.get('why'), route2_tried=j.get('route2_tried'))
            continue
        if a not in alive:
            report[a] = dict(status='blocked', scope=in_scope, why=blockers.get(a, [])[:8],
                             missing=sorted({m.split(' -> ')[1][:8] for m in blockers.get(a, []) if ' -> ' in m}))
            continue
        sym, how = own_name(a, j)
        data = j['obj']
        eh_patches = eh_import_patches(data, j['fsym'], a, j['size'])
        data = patch_eh_imports(data, eh_patches)
        st = r1.symtab(data)[0]
        syms = {i: n for i, n, sec, cls, v in st}
        defined = {i for i, n, sec, cls, v in st if sec > 0}
        mapping, srcs = {}, Counter()
        if eh_patches:
            srcs['eh-unwind'] += len(eh_patches)
        for idx, n, tva, typ, kind in j['refs']:
            if kind in ('local', 'runtime'):
                continue
            name, src = real_name(tva, n)
            if name is None and '%08x' % tva in alive:
                name, src = own_name('%08x' % tva, jobs['%08x' % tva])[0], 'job'
            elif name is None:
                name, src = '', 'known'
            srcs[src] += 1
            if name and name != n:
                if idx in mapping and mapping[idx] != name:
                    report[a] = dict(status='blocked', scope=in_scope,
                                     why=['%s names two targets: %s / %s' % (n, mapping[idx], name)])
                    break
                mapping[idx] = name
        else:
            fidx = next(i for i, n in syms.items() if n == j['fsym'] and i in defined)
            for i, n in syms.items():        # an undefined twin of the function's own name refers to it too
                if n == j['fsym'] and i != fidx and i not in mapping:
                    mapping[i] = sym
            if fidx in mapping and mapping[fidx] != sym:
                report[a] = dict(status='blocked', scope=in_scope, why=['function symbol also a relocation target'])
                continue
            mapping[fidx] = sym
            # Strip while symbols still have their source identities.  If a
            # relocation refers to another *defined* body in this whole-TU
            # object, renaming first turns that unwanted definition into the
            # target name and accidentally preserves it.  strip_symbols then
            # makes its relocation an undefined twin; rename that twin after.
            if next(cls for i, n, sec, cls, v in st if i == fidx) != 2:
                data = export_symbol(data, fidx)
            out = rebuild.strip_symbols(data, keep={j['fsym']})
            out = r1.rename(out, mapping)
            out = prune_unused_comdat_data(out)
            out = add_aliases(out, sym, [n for n in ALIASES.get(a, []) if n != sym])
            # re-prove the written object
            hit = output_body(out, sym, j['size'])
            if not hit or hit[0] != j['code'] or proof_same(a, hit[0], hit[1]) is None:
                if not hit:
                    why = ['output symbol missing: ' + sym]
                elif hit[0] != j['code']:
                    why = ['output symbol body changed: ' + sym]
                else:
                    why = [proof_why(a, hit[0], hit[1])]
                if os.environ.get('OGRE_DEBUG_FAILED'):
                    (LINK / ('failed-' + a + '.obj')).write_bytes(out)
                report[a] = dict(status='reproof-fail', scope=in_scope, why=why)
                continue
            (OUT / (a + '.obj')).write_bytes(out)
            report[a] = dict(status='renamed', scope=in_scope, symbol=sym, name_source=how, route=j['route'],
                             analog=j['fsym'], ref_sources=dict(srcs), extent=j.get('extent'))
    write_data_defs(report)
    for stale in OUT.glob('*.obj'):
        if report.get(stale.stem, {}).get('status') != 'renamed' and stale.stem in report:
            stale.unlink()                   # only objects this script wrote for an address it re-ran
    json.dump(report, open(LINK / 'ogre_convert.json', 'w'), indent=1)
    summary(report)
    return report


def write_data_defs(report):
    """roc_data.cpp: one typed definition per synthetic data symbol a renamed object uses; compiled to renamed/."""
    used = set()
    for a, r in report.items():
        if r['status'] == 'renamed':
            path = OUT / (a + '.obj')
            if not path.is_file():
                # Never let an interrupted/failed object write turn into a
                # false renamed result or abort the whole deterministic run.
                in_scope = r.get('scope', False)
                r.clear()
                r.update(status='error', scope=in_scope,
                         why=['emitted object missing: ' + path.name])
                continue
            used |= set(re.findall(rb'_roc_data_([0-9a-f]{8})', path.read_bytes()))
    lines = [DATA[int(u, 16)] for u in sorted(used) if DATA.get(int(u, 16))]
    covered = {u.decode(): DATA_SIZES[int(u, 16)] for u in used if DATA.get(int(u, 16))}
    src = LINK / 'roc_data.cpp'
    src.write_text('// generated by ogre_convert.py: data the converted objects reference, typed from each analog\'s\n'
                   '// mangled name, value read from the 2008-06 exe (zero past raw data). Synthetic names.\n'
                   + '\n'.join(lines) + '\n')
    tc = rebuild.toolchain(21022)
    code, text = rebuild.run(tc, 'cl', ['/nologo', '/c', '/O2', '/GS-', '/Fo' + str(OUT / 'roc_data.obj'), str(src)], HERE)
    if code:
        (OUT / 'roc_data.obj').unlink(missing_ok=True)
        for a, r in report.items():
            if r.get('status') == 'renamed' and re.search(rb'_roc_data_[0-9a-f]{8}', (OUT / (a + '.obj')).read_bytes()):
                in_scope = r.get('scope', False)
                r.clear()
                r.update(status='data-compile-fail', scope=in_scope,
                         why=['generated typed data did not compile'])
        json.dump({'definitions': len(lines), 'bytes': 0, 'addresses': {}, 'status': 'compile-fail'}, open(LINK / 'data-metrics.json', 'w'))
        print('data definitions: %d (compile FAILED: %s)' % (len(lines), text[-300:]))
        return
    obj = (OUT / 'roc_data.obj').read_bytes()
    bad = [u for u in used if not data_proved(obj, '_roc_data_' + u.decode(), int(u, 16), DATA_SIZES[int(u, 16)])]
    if bad:
        json.dump({'definitions': len(lines), 'bytes': 0, 'addresses': {}, 'status': 'proof-fail'}, open(LINK / 'data-metrics.json', 'w'))
        for a, r in report.items():
            if r.get('status') == 'renamed' and re.search(rb'_roc_data_(' + b'|'.join(bad) + rb')', (OUT / (a + '.obj')).read_bytes()):
                in_scope = r.get('scope', False)
                r.clear()
                r.update(status='data-proof-fail', scope=in_scope,
                         why=['generated data proof failed: ' + bad[0].decode()])
        print('data definitions: %d (proof FAILED at %s)' % (len(lines), bad[0].decode()))
        return
    json.dump({'definitions': len(lines), 'bytes': sum(covered.values()), 'addresses': covered,
               'status': 'proved'}, open(LINK / 'data-metrics.json', 'w'))
    print('data definitions: %d (compile/proof ok)' % len(lines))


def summary(report):
    sc = [r for r in report.values() if r['scope']]
    print('scope %s analogs: %d | %s' % (','.join(SCOPE), len(sc), dict(Counter(r['status'] for r in sc))))
    ren = [r for r in sc if r['status'] == 'renamed']
    print('  renamed by name source: %s | route2: %d' % (dict(Counter(r['name_source'] for r in ren)),
                                                        sum(r['route'] == 'route2' for r in ren)))
    helpers = [r for r in report.values() if not r['scope']]
    print('callee helpers pulled in: %d | %s' % (len(helpers), dict(Counter(r['status'] for r in helpers))))
    miss = Counter(m for r in report.values() if r['status'] == 'blocked' for m in r.get('missing', []))
    print('top missing callee/data addresses:', ' '.join('%s(%d)' % kv for kv in miss.most_common(12)))


if __name__ == '__main__':
    main()

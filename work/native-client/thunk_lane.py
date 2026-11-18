"""Thunk lane (no model).  A remaining 5-byte `jmp TARGET` function is a forwarding function: its content is its target.
When TARGET is already byte-exact (proven symbol + source known from the census), generate the forwarder:

  target Name::doDeclare<sX>      -> `template void RBX::Name::callDoDeclare<RBX::sX>();`
  target member  R C::f(args)     -> `struct Thunk_<addr> : C { R sub_<addr>(args); };`  body `return C::f(args);`
  target free/static R f(args)    -> `R sub_<addr>(args) { return f(args); }`

The unit includes the target's own proved source (its headers, flags line).  Names sub_<addr>/Thunk_<addr> are
INFERRED placeholders (owner rule 2026-11-16: inferred names are allowed when labelled); the body is proven by bytes
and by the jump's relocation to the proven target.  Destructor targets are skipped (they need the owning class).
  python work/native-client/thunk_lane.py [--limit N] [--jobs 3]     # run thunk_survey.py first"""
import argparse
import ctypes
import json
import re
import shutil
import sys
import time
import uuid
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=3)
ap.add_argument('--only', default='', help='comma separated addresses')
args = ap.parse_args()
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import agent_prove  # noqa: E402
import shared_json  # noqa: E402
import inline_alias  # noqa: E402
from roc import native_bulk, rebuild  # noqa: E402

RUNNER = native_bulk.checker()
TC = rebuild.toolchain(21022)
DEFAULT_FLAGS = '// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS'
INCLUDE_CLASSES = '/I{headers}/../native-classes'

CLASSES = ROOT / 'rebuild/2008-06/native-classes'
LOCK = HERE / 'prove-out/CENSUS.lock'
dbghelp = ctypes.windll.dbghelp


def undecorate(symbol):
    buf = ctypes.create_string_buffer(4096)
    return buf.value.decode() if dbghelp.UnDecorateSymbolName(symbol.encode(), buf, 4096, 0) else ''


def split_args(text):
    out, depth, cur = [], 0, ''
    for ch in text:
        depth += ch in '<('
        depth -= ch in '>)'
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    return [a for a in out + [cur.strip()] if a and a != 'void']


NONTYPE = re.compile(r'&[^,<>]*?((?:\w+::)*\w+)(?=\s*[,>])')


def cxx(name):
    """undname text -> C++ spelling (non-type template arguments)."""
    return NONTYPE.sub(r'\1', name)


SIG = re.compile(r'^(?:(public|protected|private): )?(virtual |static )?(.*?)\b(__thiscall|__cdecl|__stdcall|__fastcall) (.+?)\((.*)\)\s*(const)?\s*$')


def forwarder(addr, symbol):
    """C++ text of the forwarder for a target symbol, or (None, reason)."""
    declare = re.search(r'\?\?\$doDeclare@\$1\?(\w+)@((?:\w+@)*)@3', symbol)
    if declare:
        scope = '::'.join(reversed([s for s in declare.group(2).split('@') if s]))
        return 'template void RBX::Name::callDoDeclare<%s::%s>();\n' % (scope, declare.group(1)), 'callDoDeclare'
    und = undecorate(symbol)
    hit = SIG.match(und)
    if not hit:
        return None, 'signature not parsed'
    access, kind, ret, conv, name, params, const = hit.groups()
    name = cxx(name)
    if '::~' in name and not params.strip().strip('void'):
        base = name.rsplit('::~', 1)[0]
        note = '// INFERRED: %s is a 5-byte jump to %s: the destructor of a derived class with nothing of its own to '\
               'destroy; the class name is a placeholder.\n' % (addr, name)
        return [(note + 'struct %sThunk_%s : %s { ~Thunk_%s(); };\nThunk_%s::~Thunk_%s() {}\n'
                 % (spec, addr, base, addr, addr, addr), 'destructor forwarder' + tag)
                for spec, tag in (('__declspec(novtable) ', ' (novtable)'), ('', ''))], 'destructor'
    if '::~' in name or re.search(r'::(\w+)::\1$', '::' + name) or 'operator' in name or '`' in und:
        return None, 'special member'
    ret = ret.strip()
    params = split_args(params)
    if any('...' in p for p in params) or access == 'private':
        return None, 'private or variadic'
    decl = ', '.join('%s p%d' % (p, i) for i, p in enumerate(params))
    call = ', '.join('p%d' % i for i in range(len(params)))
    do = '' if ret == 'void' else 'return '
    note = '// INFERRED: %s is a 5-byte jump to %s; the forwarder name and owner are placeholders.\n' % (addr, name)
    if conv == '__thiscall':
        cls = name.rsplit('::', 1)[0]
        return (note + 'struct Thunk_%s : %s { %s sub_%s(%s)%s; };\n%s Thunk_%s::sub_%s(%s)%s { %s%s(%s); }\n'
                % (addr, cls, ret, addr, decl, ' const' if const else '', ret, addr, addr, decl, ' const' if const else '',
                   do, name, call)), 'member forwarder'
    return note + '%s %s sub_%s(%s) { %s%s(%s); }\n' % (ret, conv, addr, decl, do, name, call), 'free forwarder'


_PE = None
_DEFS = None
NAME_DEF = re.compile(r'\b(s[A-Z]\w*)\s*(?:\[\s*\])?\s*=\s*"([^"\\]{1,60})"')
SCOPE = re.compile(r'namespace\s+(\w+)\s*\{|\{|\}')


def image_string(va):
    """printable C string at VA of the original image, or None."""
    global _PE
    if _PE is None:
        import pefile
        _PE = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    try:
        data = _PE.get_data(va - _PE.OPTIONAL_HEADER.ImageBase, 64)
    except Exception:                                            # noqa: BLE001
        return None
    end = data.find(b'\0')
    text = data[:end] if end > 0 else b''
    return text.decode('latin-1') if text and all(32 <= c < 127 for c in text) else None


def name_definitions():
    """{string: [(qualified variable, defining .cpp)]} for `sX[] = "String"` name definitions in native units."""
    global _DEFS
    if _DEFS is None:
        _DEFS = {}
        for path in sorted(CLASSES.glob('*.cpp')):
            if path.name.startswith(('Thunk_', 'WF_')):
                continue
            text = path.read_text(errors='replace')
            for hit in NAME_DEF.finditer(text):
                stack = []
                for tok in SCOPE.finditer(text[:hit.start()]):
                    if tok.group(0) == '}':
                        if stack:
                            stack.pop()
                    else:
                        stack.append(tok.group(1))
                scope = '::'.join(x for x in stack if x)
                _DEFS.setdefault(hit.group(2), []).append(((scope + '::' if scope else '::') + hit.group(1), str(path)))
    return _DEFS


_DECLS = None


def declared_name(text):
    """(definition line, qualified variable, header) for the header declaration `extern <type> s<Text>...;`."""
    global _DECLS
    if not re.fullmatch(r'[A-Za-z]\w*', text or ''):
        return None
    if _DECLS is None:
        _DECLS = {}
        headers = ROOT / 'rebuild/2008-06/native-headers'
        for path in sorted(headers.rglob('*.h'), key=lambda q: (len(q.relative_to(headers).parts), str(q))):
            if '-' in path.relative_to(headers).parts[0]:        # per-unit variant snapshots
                continue
            body = path.read_text(errors='replace')
            for hit in re.finditer(r'^[ \t]*extern\s+([^;=()]*?)\b(s[A-Z]\w*)\s*(\[\s*\])?\s*;', body, re.M):
                stack = []
                for tok in SCOPE.finditer(body[:hit.start()]):
                    if tok.group(0) == '}':
                        if stack:
                            stack.pop()
                    else:
                        stack.append(tok.group(1))
                _DECLS.setdefault(hit.group(2), (hit.group(1).strip(), bool(hit.group(3)), [x for x in stack if x],
                                                 path.relative_to(headers).as_posix()))
    hit = _DECLS.get('s' + text)
    if not hit:
        return None
    ctype, array, scope, header = hit
    line = '%s s%s%s = "%s";' % (ctype, text, '[]' if array else '', text)
    for ns in reversed(scope):
        line = 'namespace %s { %s }' % (ns, line)
    # the comment goes on its own line: at the end of the line it would swallow the closing brace
    line = '// INFERRED: s%s is declared in %s and defined nowhere in the native tree; its value is read from the image.\n%s' % (
        text, header, line)
    return line, '::'.join(scope + ['s' + text]), header


def declare_variants(target):
    """A doDeclare<sX> body (101 bytes in this client) references the name string of sX.  Every doDeclare is
    byte-identical with relocations masked, so the string - not a twin's symbol - says which sX the target is."""
    from roc import match
    import struct
    try:
        body, relocs = match.target('2008-06', target)[:2]
    except BaseException:                                        # noqa: BLE001  not a function start: sys.exit inside
        return []
    if len(body) != 101:
        return []
    out = []
    for off in relocs:
        text = image_string(struct.unpack('<I', body[off:off + 4])[0])
        for var, source in name_definitions().get(text, []) if text else []:
            out.append(('template void RBX::Name::callDoDeclare<%s>();\n' % var, 'callDoDeclare', source))
        if text and not name_definitions().get(text):
            made = declared_name(text)
            if made:                            # header-only unit: include the declaring header, define the name
                out.append(('%s\ntemplate void RBX::Name::callDoDeclare<%s>();\n' % (made[0], made[1]), 'callDoDeclare',
                            str(ROOT / 'rebuild/2008-06/native-headers' / made[2])))
            elif not out:
                out.append((None, 'name string "%s" has no native variable' % text, None))
    return out


def bind(rows):
    while LOCK.is_file():
        time.sleep(30)
    path = HERE / 'class-identity-bindings.json'
    def add(doc):
        have = {(r.get('symbol'), r.get('address')) for r in doc['identity_bindings']}
        doc['identity_bindings'] += [r for r in rows if (r['symbol'], r['address']) not in have]
        return doc
    shared_json.update(path, add)


def one(row):
    addr, target = row['addr'], row['target']
    named = declare_variants(target)
    if named:                                   # callDoDeclare<sX>, sX identified by the string its target references
        result = None
        for code, kind, source in named[:3]:
            if code is None:
                return addr, 'skip: ' + kind, ''
            try:
                result = attempt(addr, target, source, code, kind)
            except Exception as error:                           # noqa: BLE001
                result = (addr, kind + ' -> lane error', repr(error)[:160])
            if result[1].endswith('EXACT'):
                break
        return result
    symbol, source = proven(target)
    if not symbol:
        return addr, 'target symbol unknown', ''
    if not source or not Path(source).is_file():
        return addr, 'target source missing', str(source)[-90:]
    code, kind = forwarder(addr, symbol)
    if not code:
        return addr, 'skip: ' + kind, ''
    result = None
    for code, kind in (code if isinstance(code, list) else [(code, kind)]):     # spellings; the proof picks
        try:
            result = attempt(addr, target, source, code, kind)
        except Exception as error:                               # noqa: BLE001  one thunk never stops the lane
            import traceback
            result = (addr, kind + ' -> lane error', repr(error)[:120] + ' @ ' + ' <- '.join(l.strip() for l in traceback.format_exc().splitlines()[-7:-1])[:400])
        if result[1].endswith('EXACT'):
            break
    return result


def attempt(addr, target, source, code, kind):
    """One proof per thunk (a proof is ~3 minutes of disk I/O): compile (5 s), read the forwarder's decorated symbol
    from the object, bind it to the address, prove once in a private folder, then move the identical file into place
    (credit follows the file's content hash, so no second proof is needed)."""
    src = Path(source)
    is_header = src.suffix == '.h'
    first = '' if is_header else src.read_text(errors='replace').split('\n', 1)[0]
    flags = first.rstrip() if first.startswith('// native-flags:') else DEFAULT_FLAGS
    if INCLUDE_CLASSES not in flags:
        flags += ' ' + INCLUDE_CLASSES          # "#include <target unit>" resolves from the draft folder and from native-classes
    final = CLASSES / ('Thunk_%s.cpp' % addr)
    folder = HERE / 'lane-drafts' / final.stem
    folder.mkdir(parents=True, exist_ok=True)
    unit = folder / final.name                  # own folder: the prover hashes the source's directory
    while LOCK.is_file():
        time.sleep(30)
    unit.write_text('%s\n// %s: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)\n#include "%s"\n%s'
                    % (flags, addr, src.as_posix().split('native-headers/')[-1] if is_header else src.name, code),
                    encoding='utf-8')
    needle = 'callDoDeclare' if kind == 'callDoDeclare' else ('Thunk_' + addr) if kind.startswith('destructor') else 'sub_' + addr

    def fail(status, text=''):
        unit.unlink(missing_ok=True)
        shutil.rmtree(HERE / 'prove-out' / ('prove-' + final.stem), ignore_errors=True)   # ~70 MB per failed proof
        return addr, kind + ' -> ' + status, text.replace('\n', ' | ')[:260]

    job_dir = folder / ('job-%s' % uuid.uuid4().hex[:10])      # one per spelling (two in the same second collided)
    try:
        job = RUNNER.compile_job({'source': str(unit), 'checks': [], 'ranges': [], 'layouts': []}, job_dir, TC)
        obj = Path(str(job.get('object') or ''))
    except Exception as error:                                   # noqa: BLE001
        return fail('compile harness error', repr(error))
    if not obj.is_file():
        return fail('COMPILE FAILED', ' | '.join(agent_prove.compile_errors(job_dir, '')[:3]))
    if True:
        if needle == 'callDoDeclare':               # the real symbol: callDoDeclare<sX>, sX taken from the proven target
            leaf = re.search(r'callDoDeclare<(?:::)?(?:\w+::)*(\w+)>', code).group(1)
            want = b'callDoDeclare@$1?' + leaf.encode() + b'@'
        else:
            want = (b'??1Thunk_' + addr.encode() + b'@@') if kind.startswith('destructor') else (b'sub_' + addr.encode() + b'@')
        names = sorted({n.decode('latin-1') for n in re.findall(rb'\?[\x21-\x7e]{4,400}', obj.read_bytes()) if want in n}, key=len)
        if not names:
            return fail('forwarder symbol not emitted (inlined or discarded)')
        bind([{'symbol': names[0], 'address': addr, 'votes': 1, 'identity_evidence':
               ('callDoDeclare<sX> instantiation: 5-byte jump to the proven doDeclare<sX> at %s' if needle == 'callDoDeclare' else
                'INFERRED: thunk_lane forwarder named for this address; 5-byte jump to proven %s') % target}])
    status, text = agent_prove.verdict(unit, {addr: needle})[addr]
    if status == 'REJECTED':
        extra = inline_alias.rows(HERE / 'prove-out' / ('prove-' + final.stem) / 'manifest.json', {addr})
        if extra:
            bind(extra)
            status, text = agent_prove.verdict(unit, {addr: needle})[addr]
    if status != 'EXACT':
        return fail(status, text)
    shutil.move(str(unit), str(final))                           # identical content: the proof receipt still applies
    rel = final.relative_to(ROOT).as_posix()
    shared_json.update(HERE / 'class-lane-new-sources.json', lambda lst: lst if rel in lst else lst + [rel], [])
    return addr, kind + ' -> EXACT', ''


checks = json.loads((HERE / 'prove-out/OgreNativeFull/checks.json').read_text())['jobs']
PROVEN = {}
for job in checks:                                  # proven symbol + source per address (smallest source wins: faster units)
    size = Path(job['source']).stat().st_size if Path(job['source']).is_file() else 1 << 30
    for c in job['checks']:
        if c['addr'] not in PROVEN or size < PROVEN[c['addr']][2]:
            PROVEN[c['addr']] = (c['symbol'], job['source'], size)
SYMBOL_SOURCE = {}
for job in checks:
    if Path(job['source']).is_file() and not Path(job['source']).name.startswith(('Thunk_', 'WF_')):
        for c in job['checks']:
            SYMBOL_SOURCE.setdefault(c['symbol'], job['source'])
PROVEN = {a: (s, f) for a, (s, f, _) in PROVEN.items()}
# Targets proven by a per-source family (not in the census checks): symbol from that family's manifest.
from roc import integration_site  # noqa: E402
for _try in range(4):                               # the scan races with files other lanes add or remove
    try:
        INACTIVE = integration_site.inactive_code(ROOT)
        break
    except FileNotFoundError:
        time.sleep(5)
_MANIFEST = {}


def proven(target):
    symbol, source = _proven(target)
    if symbol and (not source or not Path(source).is_file() or 'lane-drafts' in str(source)):
        source = SYMBOL_SOURCE.get(symbol)
    return symbol, source


def _proven(target):
    if target in PROVEN:
        return PROVEN[target]
    hit = INACTIVE.get(target)
    if not hit or not hit[1] or not str(hit[2]).startswith('native-bulk:'):
        return None, None
    source = hit[3][0] if len(hit) > 3 and hit[3] else None
    if str(hit[0]).startswith('?') and source:          # the entry already carries the decorated symbol
        return hit[0], str(ROOT / source)
    family = str(hit[2]).split(':', 1)[1]
    if family == 'OgreNativeFull' and source:           # census family: use the source's own proof receipt
        family = 'prove-' + Path(source).stem
    if family not in _MANIFEST:
        path = HERE / 'prove-out' / family / 'manifest.json'
        rows = json.loads(path.read_text(encoding='utf-8'))['families'][0]['symbols'] if path.is_file() else []
        _MANIFEST[family] = {r['addr']: r['symbol'] for r in rows if r.get('status') == 'inactive_exact' and r.get('addr')}
    symbol = _MANIFEST[family].get(target)
    if not symbol and source:                           # census rows of that source (per-source cache, small)
        import gzip
        import hashlib
        cached = HERE / 'prove-cache' / (hashlib.sha1(source.encode()).hexdigest()[:20] + '.json')
        try:
            entry = json.loads(cached.read_text())
            rows = entry.get('harvest_rows')
            if rows is None and entry.get('harvest_ref'):
                ref = HERE / 'prove-out/OgreNativeFull/rows' / (entry['harvest_ref'] if entry['harvest_ref'].endswith('.gz') else entry['harvest_ref'] + '.json.gz')
                rows = json.loads(gzip.open(ref, 'rt', encoding='utf-8').read())
            symbol = next((r['symbol'] for r in rows or [] if r.get('status') == 'inactive_exact' and r.get('addr') == target), None)
        except (OSError, ValueError):
            symbol = None
    source = hit[3][0] if len(hit) > 3 and hit[3] else None
    return (symbol, str(ROOT / source)) if symbol and source else (None, None)


rows = [r for r in json.loads((HERE / 'jmp-thunks.json').read_text()) if r['kind'] == 'target exact'
        and not (CLASSES / ('Thunk_%s.cpp' % r['addr'])).is_file()]
rows.sort(key=lambda r: ('::~' in r['target_name'], r['addr']))     # destructor targets (skipped) last
done_path = HERE / 'thunk-lane-done.json'
done = json.loads(done_path.read_text()) if done_path.is_file() else {}
rows = [r for r in rows if (r['addr'] in args.only.split(',') if args.only else r['addr'] not in done)][:args.limit or None]
print('thunk lane: %d thunks' % len(rows), flush=True)
exact = 0
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(one, rows):
        exact += status.endswith('EXACT')
        done[addr] = status
        done_path.write_text(json.dumps(done, indent=1))
        print(addr, status, detail, flush=True)
print('RESULT thunk lane: %d exact of %d' % (exact, len(rows)), flush=True)

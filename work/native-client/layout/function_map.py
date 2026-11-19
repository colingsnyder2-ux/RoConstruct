"""docs/function-map.json: a best-guess original source file for every code function of the 2008 exe.

Tiers, strongest first (the first that applies wins; none of them is a proof of the 2008 path):
  E  the 2008 exe itself: the function uses a __FILE__ string (assert, exception) naming its source file; the folder
     comes from the real builds (PDB, iOS, Android, 2016 leak) that list a file of that name
  L  library: the function is byte-identical to code built from an upstream library file (mining recipe + file)
  P  the same decorated name sits in a file of the 2007 server PDB, or a census vote ties it to a PDB/OpenRBX-named native piece
  I  same-named function in the iOS Dec 2013 build, whose debug map gives the source file
  M  the same (Class, method) is defined in exactly one file of the 2016 source leak (leak_index.py); 2016 is far from 2008,
     so this ranks below the iOS 2013 debug map
  N  the native piece that holds the function has an inferred or curated path
  X  exception tables: the function is a catch or cleanup funclet, or the frame-handler stub, of a parent function whose
     FuncInfo lists it (a proof of the parent, so of its file once the parent is placed)
  S  same class: the function's class has most of its other functions in one file
  U  also: a slot target of exactly one vtable (vtables.py, from the exe's RTTI) whose class has most of its other slot targets
     in one file (95% right held out)
  U  same RTTI unit: the exe's own class label for the function (vtable / nearest RTTI class) has most of its other
     functions in one file
  D  same data: a global or string the function uses is used by other functions that are all in one file
  F  one user: in the static-initializer region (0x7c0000 and up) a global used by one strongly placed function of one file;
     94% right held out. Elsewhere one user is only 79% right, so it is not used there
  J  between two functions of its own class that are both in one file (for classes split across files; 96% right held out)
  Q  property initializer: ??__Eprop_<Name> belongs with the get/set/is<Name> accessors, when all of those are in one file
  V  same RTTI class, split across files: one file still holds at least 60% (weaker than U)
  Z  library class name: the class of the function's RTTI unit is named like exactly one upstream library file
     (CXTPFoo -> XTPFoo.cpp); the file is the upstream one, so it is a library placement, not a Roblox path
  m  class file: at a file boundary, the class is defined in exactly one file of the 2016 leak (else of the iOS 2013 build) and
     that file is also one of the files placed within 30 functions of this one; about 63% right for classes in general
  A  last resort: the file of the nearest placed function by address, skipping library files. Where the two neighbours are in
     different files (a file boundary) a call link to one side decides, then the same RTTI class, then the next function;
     right for 76% of strongly placed functions, only about 40-60% at boundaries, so the weakest placement
  Y  name match: the class of the function's RTTI unit has the same name as one file in the builds we hold (CFoo -> foo.cpp);
     about 63% right on classes whose file is known; the weakest placement
  W  same RTTI class, counting every tier that placed its other functions (including the weak ones): for classes no real
     build covers, such as the MFC app layer; a guess about a guess
  H  look-alike next door: functions within 30 places of it with the same instruction pattern and nearly the same size are
     all in one file (at least 2 of them)
  T  template instantiation of a class whose functions are in one file (the linker keeps the instantiation with its first user)
  K  every caller of the function is in one file (static helpers, thunks)
  B  stub next door: a tiny function (thunk, exception funclet) that starts where the previous function ends sits in that
     function's file
  R  range fill: the linker places one object file's code in one block, so a function between two
     functions of the same file is in that file
  G  similarity: name_match.py named the function from the Ghidra exports (strings, callees, float constants) and the
     iOS debug map gives that name one file
  C  class rule: the function's class is thought to live in that file (a guess, weak)
  O  OpenRBX (Dec 2007 decompilation) names the file: its folders are a decompiler's arrangement, not the build's, so this
     is the weakest tier and is used only where nothing from a real build (PDB, iOS, exe strings) says anything
Anything left is unassigned. Paths are lower-cased 'client/...' like the site's tree; libraries are 'libraries/<lib>/<file>'.

Run (after inventory.py and site_libs.py):  python work/native-client/layout/function_map.py
"""
import bisect
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
ROOT = HERE.parents[2]
TIERS = 'ELPIMNXSUVDQHJFTKBRGCOWYZmA'
STRONG = {'pdb': 'P', 'census': 'P', 'census-shared': 'P', 'census-openrbx': 'O', 'openrbx': 'O',
          'ios-debug-map': 'I'}
STUB_SIZE = 48     # a function this small that starts right after another one is treated as its stub
GAP = 0x10000      # a range fill never spans more than this many bytes between two functions of the same file
WINDOW = 200       # ... or more than this many functions
UNIT_SHARE = 0.8   # share of a class's strongly placed functions one file must hold for the class rule (U) to apply to the rest
UNIT_SHARE_LOW = 0.6   # the weaker version (V): a class split across files, where one file still holds most of it


def clean_unit(label):
    """The class of an RTTI unit label without mangling residue, like the site's map: 'RBX::VScriptContext::?$FactoryProduct::Creator'
    -> 'RBX::ScriptContext' (a template instantiation goes with the class it is instantiated for)."""
    out = []
    for raw in label.split('::'):
        if raw.startswith('?$'):
            break
        seg = re.sub(r'^(?:P8|PAV|PAU|PBV|PAX|W4|V|U)(?=[A-Z_])', '', raw)
        if len(seg) < 3 or seg[0] in '$?@' or seg[0].isdigit():
            continue
        out.append(seg)
    return '::'.join(out)


def low(path):
    path = path.replace('\\', '/').lower()
    path = path.removeprefix('rebuild/2008-06/')
    return path if path.startswith(('client/', 'libraries/', 'f:/', 'rbxgs/')) else 'client/' + path


def build():
    import layout_census
    import layout_ios

    funcs, callers, meta, meta_calls = {}, {}, {}, {}
    with open(ROOT / 'work/2008-06/functions.jsonl', encoding='utf-8') as lines:
        for line in lines:
            row = json.loads(line)
            if row.get('kind') == 'code':
                funcs[row['addr'].lower()] = row['size']
                callers[row['addr'].lower()] = [c.lower() for c in row.get('callers', [])]
                meta_calls[row['addr'].lower()] = [t.lower() for t in row.get('call_targets', [])]
                meta[row['addr'].lower()] = (row.get('unit') or '', tuple(row.get('data_refs', [])) + tuple(row.get('strings', [])), clean_unit(row.get('unit') or ''), row.get('shape') or '')
    names = {a: (e or {}).get('name') or '' for a, e in json.loads((HERE / 'function-files.json').read_text(encoding='utf-8')).items()}

    claims = collections.defaultdict(dict)            # addr -> {tier: path}

    # E: file-name strings of the exe (file_strings.py) resolved to a folder by the real builds
    import source_tree_sources
    tagged = source_tree_sources.build()[0]
    real = collections.defaultdict(set)
    for tag in 'pial':
        for path in tagged[tag]:
            if path.endswith(('.cpp', '.cc', '.c')):
                real[path.rsplit('/', 1)[-1]].add(path)
    fs_path = HERE / 'file-strings.json'
    for row in json.loads(fs_path.read_text(encoding='utf-8')) if fs_path.exists() else []:
        name = row['file'].replace('\\', '/').lower()
        if not name.endswith(('.cpp', '.cc', '.c')) or '/' in name.rstrip('/') and name.startswith(('c:/', 'd:/')):
            continue
        cands = sorted(p for p in real.get(name.rsplit('/', 1)[-1], ()) if p.endswith('/' + name.lstrip('./')) or '/' not in name)
        for addr in row['functions']:
            other = claims[addr]
            pick = next((c for c in cands if c in {other.get('P'), other.get('I'), low(other.get('N', ''))} ), None) if other else None
            if pick is None and len(cands) == 1:
                pick = cands[0]
            if pick is None and len(cands) > 1:
                known = [c for c in cands if c in tagged['p']]
                pick = known[0] if len(known) == 1 else None
            if pick:
                claims[addr]['E'] = pick

    # L: library files matched by bytes (docs/data holds recipe + file per function)
    libs = json.loads((ROOT / 'docs/library-files.json').read_text(encoding='utf-8'))['libs'] if (ROOT / 'docs/library-files.json').exists() else []
    base = {}
    for lib in libs:
        for rel, status, _b, _n in lib['files']:
            base.setdefault((lib['name'], rel.rsplit('/', 1)[-1].lower()), 'libraries/%s/%s' % (lib['name'], rel))
    import site_libs
    data = json.loads((ROOT / 'docs/data/2008-06.json').read_text(encoding='utf-8'))
    for f in data['funcs']:
        src = f[5]
        if not src or f[2] != 100:
            continue
        recipe, name = src[0].lower(), src[1].replace('\\', '/').rsplit('/', 1)[-1].lower()
        for lib, (prefixes, _t, _g) in site_libs.TABLE.items():
            if recipe.startswith(prefixes) and not name.startswith('roc_'):
                path = base.get((lib, name))
                if path:
                    claims['%08x' % f[0]]['L'] = path.lower().replace('libraries/' + lib.lower(), 'libraries/' + lib)
                break

    # P/O/C: per-function evidence from the inventory (decorated-name match with the 2007 PDB, OpenRBX, class rule)
    for addr, entry in json.loads((HERE / 'function-files.json').read_text(encoding='utf-8')).items():
        path = entry.get('target_path')
        if not path or not path.lower().endswith(('.cpp', '.c', '.cc')):
            continue
        tier = {'pdb': 'P', 'openrbx': 'O', 'class-rule': 'C'}.get(entry.get('evidence'))
        if tier:
            claims[addr.lower()][tier] = low(path)

    # G: a name guessed by similarity (name_match.py), then the iOS debug map's file for that name
    guesses = HERE / 'name-guesses.json'
    if guesses.exists():
        for addr, (name, _score, _raw, files) in json.loads(guesses.read_text(encoding='utf-8')).items():
            if len(files) == 1 and files[0].endswith(('.cpp', '.cc', '.c')):
                claims[addr.lower()]['G'] = low(files[0])

    # M: same (Class, method) in the 2016 leak
    leak_path = HERE / 'leak-index.json'
    if leak_path.exists():
        leak = json.loads(leak_path.read_text(encoding='utf-8'))['files']
        for addr, name in names.items():
            key = layout_ios.msvc(name) if name.startswith('?') else None
            if key and len(key) >= 2 and addr in funcs:
                cls = key[-2]
                method = cls if key[-1] == '<init>' else '~' + cls if key[-1] == '<fini>' else key[-1]
                got = leak.get('%s::%s' % (cls, method), [])
                if len(got) == 1 and got[0].endswith(('.cpp', '.cc', '.c')):
                    claims[addr]['M'] = got[0]

    # I: iOS 2013 same-named function
    jobs = json.loads(layout_census.CHECKS.read_text(encoding='utf-8'))['jobs']
    ios = layout_ios.index()
    for job in jobs:
        for check in job['checks']:
            files = ios.get(layout_ios.msvc(check['symbol']) or (), {})
            if len(files) == 1:
                claims[check['addr'].lower()]['I'] = low(next(iter(files)))

    # N and census-backed P/O: the native piece that holds the function, with the path it was given
    rows = json.loads((HERE / 'source-layout-map.json').read_text(encoding='utf-8'))
    piece = {}
    for key, row in rows.items():
        if row.get('target_path') and key.endswith(('.cpp', '.c')):
            piece[(ROOT / key).resolve().as_posix().casefold()] = (low(row['target_path']), STRONG.get(row.get('evidence'), 'N'))
    owners = collections.defaultdict(set)
    for job in jobs:
        got = piece.get(Path(job['source']).resolve().as_posix().casefold())
        if got:
            for check in job['checks']:
                owners[check['addr'].lower()].add(got)
    for addr, got in owners.items():
        if len({p for p, _ in got}) == 1:               # a function two differently-named pieces both hold stays unclaimed
            path, tier = next(iter(got))
            claims[addr].setdefault(tier, path)

    # Strong placements from the last run on the full census. The census file is regenerated by the recovery lane and is
    # missing for hours; a run on the fallback snapshot keeps what the full run knew instead of forgetting it.
    keep_path = HERE / 'strong-tiers-snapshot.json'
    if keep_path.exists():
        for addr, (path, tier) in json.loads(keep_path.read_text(encoding='utf-8')).items():
            if addr in funcs and tier not in claims[addr]:
                claims[addr][tier] = path

    # choose: real-build evidence first, inference next, the weak guesses last
    chosen = {}
    for addr, c in claims.items():
        for tier in 'ELPIMN':
            if tier in c and addr in funcs:
                chosen[addr] = (c[tier], tier)
                break

    strong = dict(chosen)
    meta['__eh__'] = eh_parents(funcs)
    infer(funcs, chosen, names, callers, layout_ios, meta)
    class_range(funcs, chosen, meta)
    for addr, c in claims.items():                       # weak guesses only where nothing better placed the function
        if addr in funcs and addr not in chosen:
            for tier in 'GCO':
                if tier in c:
                    chosen[addr] = (c[tier], tier)
                    break
    infer(funcs, chosen, names, callers, layout_ios, meta)
    by_base = collections.defaultdict(set)                 # Y: class name -> the one file of that name in the builds we hold
    for tag in 'pialo':
        for path in tagged[tag]:
            if path.endswith(('.cpp', '.cc', '.c')) and not path.startswith(('client/boost', 'client/rendering/mesa', 'client/rendering/sdl')):
                by_base[path.rsplit('/', 1)[-1]].add(path)
    for addr in funcs:
        if addr not in chosen:
            clean = meta.get(addr, ('', (), '', ''))[2]
            cls = clean.split('::')[-1] if clean else ''
            for cand in (cls, cls[1:] if cls[:1] == 'C' and cls[1:2].isupper() else ''):
                got = by_base.get(cand.lower() + '.cpp', set()) if cand else set()
                if len(got) == 1:
                    chosen[addr] = (next(iter(got)), 'Y')
                    break
    lib_base = collections.defaultdict(set)                # Z: upstream library files by name
    for lib in libs:
        for rel, _status, _b, _n in lib['files']:
            if rel.endswith(('.cpp', '.c', '.cc')) and not rel.startswith('('):
                lib_base[rel.rsplit('/', 1)[-1].lower()].add('libraries/%s/%s' % (lib['name'], rel))
    for addr in funcs:
        if addr not in chosen:
            clean = meta.get(addr, ('', (), '', ''))[2]
            cls = clean.split('::')[-1] if clean else ''
            for cand in (cls, cls[1:] if cls[:1] == 'C' else ''):
                got = lib_base.get(cand.lower() + '.cpp', set()) if len(cand) > 4 else set()
                if len(got) == 1:
                    chosen[addr] = (next(iter(got)), 'Z')
                    break
    infer(funcs, chosen, names, callers, layout_ios, meta)
    order_final = sorted(funcs, key=lambda a: int(a, 16))                       # A: every function gets a path
    class_file = collections.defaultdict(set)                                   # m: class -> files defining it (leak first, then iOS)
    leak_p = HERE / 'leak-index.json'
    if leak_p.exists():
        for key, fl in json.loads(leak_p.read_text(encoding='utf-8'))['files'].items():
            class_file[('leak', key.split('::')[0])].update(fl)
    for key, fl in layout_ios.index().items():
        if len(key) >= 2:
            class_file[('ios', key[-2])].update(low(f) for f in fl)
    call_targets_of = {a: [t for t in (meta_calls.get(a) or ())] for a in funcs}
    for i, addr in enumerate(order_final):
        if addr in chosen:
            continue
        prev = next((order_final[j] for j in range(i - 1, max(i - 400, -1), -1)
                     if order_final[j] in chosen and not chosen[order_final[j]][0].startswith('libraries/')), None)
        nxt = next((order_final[j] for j in range(i + 1, min(i + 400, len(order_final)))
                    if order_final[j] in chosen and not chosen[order_final[j]][0].startswith('libraries/')), None)
        if prev and nxt and chosen[prev][0] != chosen[nxt][0]:
            # a file boundary: the function is often a third file's. Held out, a call link to one side was right 60% of the
            # time, the same RTTI class 43%, the next function 41%, the previous one 33%.
            cname = (class_key(names.get(addr, ''), layout_ios) or (None,))[-1] or (meta.get(addr, ('', (), '', ''))[2].split('::')[-1] or None)
            cfiles = None
            for src in ('leak', 'ios'):
                got = class_file.get((src, cname)) if cname else None
                if got and len(got) == 1:
                    cfiles = next(iter(got))
                    break
            around = {chosen[order_final[j]][0] for j in range(max(0, i - 30), min(len(order_final), i + 31)) if order_final[j] in chosen}
            if cfiles and cfiles in around:
                chosen[addr] = (cfiles, 'm')
                continue
            links = set(callers.get(addr, ())) | {t.lower() for t in (call_targets_of.get(addr) or ())}
            near_prev = [order_final[j] for j in range(max(0, i - 8), i)]
            near_next = [order_final[j] for j in range(i + 1, min(len(order_final), i + 9))]
            lp, ln = any(x in links for x in near_prev), any(x in links for x in near_next)
            unit = meta.get(addr, ('', (), '', ''))[2]
            if lp != ln:
                near = chosen[prev][0] if lp else chosen[nxt][0]
            elif unit and (meta.get(prev, ('', (), '', ''))[2] == unit) != (meta.get(nxt, ('', (), '', ''))[2] == unit):
                near = chosen[prev][0] if meta.get(prev, ('', (), '', ''))[2] == unit else chosen[nxt][0]
            else:
                near = chosen[nxt][0]
        else:
            near = chosen[prev][0] if prev else (chosen[nxt][0] if nxt else None)
        if near:
            chosen[addr] = (near, 'A')
    build.last = (strong, names, callers, layout_ios, meta)
    return funcs, chosen, claims


TEMPLATE_ARG = re.compile(r'\?\$\w+@V(\w+)@(\w+)@@')


def eh_parents(funcs):
    """{funclet or stub address: parent function address} from the x86 exception tables of the 2008 exe.

    A function with try/catch or unwinding pushes the address of a stub (mov eax, FuncInfo ; jmp __CxxFrameHandler3).
    FuncInfo lists every unwind action and catch handler of that one function.
    """
    import file_strings
    import struct
    data = file_strings.EXE.read_bytes()
    secs = file_strings.sections(data)[1]
    text = next(x for x in secs if x[0] == '.text')
    code = data[text[3]:text[3] + text[4]]

    def dword(va):
        for _n, base, vsize, raw, rsize in secs:
            if base <= va and va + 4 <= base + min(vsize, rsize):
                return struct.unpack_from('<I', data, raw + va - base)[0]
        return None

    starts = sorted(int(a, 16) for a in funcs)

    def owner(va):
        i = bisect.bisect_right(starts, va) - 1
        return '%08x' % starts[i] if i >= 0 and va < starts[i] + funcs['%08x' % starts[i]] else None

    parents = {}
    for m in re.finditer(rb'\xb8....\xe9', code, re.S):  # mov eax, FuncInfo ; jmp __CxxFrameHandler3
        info = struct.unpack_from('<I', code, m.start() + 1)[0]
        if dword(info) not in (0x19930520, 0x19930521, 0x19930522):
            continue
        va = text[1] + m.start()
        needle, hits, at = b'\x68' + struct.pack('<I', va), set(), 0
        at = code.find(needle)
        while at != -1:                                                         # push offset stub: in the parent's prologue
            hits.add(owner(text[1] + at))
            at = code.find(needle, at + 1)
        hits.discard(None)
        if len(hits) != 1:
            continue
        parent = next(iter(hits))
        kids = []
        unwind = dword(info + 8)
        for i in range(min(dword(info + 4) or 0, 512)):                         # unwind map: {toState, action}
            kids.append(dword(unwind + 8 * i + 4))
        tries, ntry = dword(info + 16), dword(info + 12) or 0
        for i in range(min(ntry, 256)):                                         # try blocks -> handler arrays
            handlers, n = dword(tries + 20 * i + 16), dword(tries + 20 * i + 12) or 0
            for j in range(min(n, 64)):                                         # {adjectives, type, dispCatchObj, handler}
                kids.append(dword(handlers + 16 * j + 12))
        for kid in kids:
            if kid and '%08x' % kid in funcs and '%08x' % kid != parent:
                parents['%08x' % kid] = parent
    return parents


def class_key(name, layout_ios):
    """('RBX', 'Instance') for ?x@Instance@RBX@@..., ('CAboutRobloxDialog',) for ?x@CAboutRobloxDialog@@...; None for operators etc."""
    if name.startswith(('??__E?', '??__F?')):                # static member initializer: ??__E?var@Class@NS@@... is Class's
        name = name[5:]
    parts = layout_ios.msvc(name) if name.startswith('?') else None
    return parts[:-1] if parts and len(parts) >= 2 else None


def template_class(name):
    m = TEMPLATE_ARG.search(name)
    return (m.group(2), m.group(1)) if m else None


def class_files(chosen, names, layout_ios, skip=None):
    """{class key: file} when one file holds at least 80% of the class's strongly assigned functions (at least 2)."""
    votes = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        if tier in 'PI' and addr != skip:
            key = class_key(names.get(addr, ''), layout_ios)
            if key:
                votes[key][path] += 1
    out = {}
    for key, counter in votes.items():
        path, n = counter.most_common(1)[0]
        if n >= 2 and n / sum(counter.values()) >= 0.8:
            out[key] = path
    return out


def unit_files(chosen, meta, skip=None, which=0, share=None, tiers='EPIN'):
    """{RTTI unit label: file} when one file holds at least 80% of the unit's strongly assigned functions (at least 2)."""
    votes = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        unit = meta.get(addr, ('', (), ''))[which]
        if tier in tiers and addr != skip and unit and not unit.startswith(('seg_', '(unnamed')):
            votes[unit][path] += 1
    out = {}
    for unit, counter in votes.items():
        path, n = counter.most_common(1)[0]
        if n >= 2 and n / sum(counter.values()) >= (share or UNIT_SHARE):
            out[unit] = path
    return out


def data_files(chosen, meta, skip=None, minimum=2):
    """{data address: file} when at least 2 strongly assigned functions use it and all are in one file."""
    votes = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        if tier in 'EPIN' and addr != skip:
            for ref in set(meta.get(addr, ('', ()))[1]):
                votes[ref][path] += 1
    return {ref: next(iter(c)) for ref, c in votes.items() if len(c) == 1 and sum(c.values()) >= minimum}


def look_alike(addr, funcs, chosen, meta, order, place, reach=30):
    """The one file shared by every near neighbour with the same instruction pattern and a similar size, if at least two."""
    shape = meta.get(addr, ('', (), '', ''))[3]
    if len(shape) < 12:
        return None
    i, size, files, hits = place[addr], funcs[addr], set(), 0
    for j in range(max(0, i - reach), min(len(order), i + reach + 1)):
        other = order[j]
        if j == i or other not in chosen or meta.get(other, ('', (), '', ''))[3] != shape:
            continue
        if abs(funcs[other] - size) <= max(4, 0.15 * size) and chosen[other][1] in 'EPINSUD':
            files.add(chosen[other][0])
            hits += 1
    return next(iter(files)) if hits >= 2 and len(files) == 1 and not next(iter(files)).startswith('libraries/') else None


PROP_INIT = re.compile(r'^\?\?__E(?:prop_|tag_)?(\w+?)@RBX@@')
ACCESSOR = re.compile(r'^\?(?:get|set|is)(\w+?)@\w+@')


def accessor_files(chosen, names):
    acc = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        m = ACCESSOR.match(names.get(addr, ''))
        if m and tier in 'PIE':
            acc[m.group(1)][path] += 1
    return {prop: next(iter(c)) for prop, c in acc.items() if len(c) == 1}


def class_range(funcs, chosen, meta):
    """J: unplaced functions that sit between two strongly placed functions of their own class which share one file."""
    by = collections.defaultdict(list)
    for a, (path, tier) in chosen.items():
        if tier in 'EPIN':
            for which in (0, 2):
                u = meta.get(a, ('', (), '', ''))[which]
                if u and not u.startswith(('seg_', '(unnamed')):
                    by[(which, u)].append((int(a, 16), path))
    for v in by.values():
        v.sort()
    keys = {k: [x[0] for x in v] for k, v in by.items()}
    added = {}
    for addr in funcs:
        if addr in chosen:
            continue
        va, found = int(addr, 16), set()
        for which in (0, 2):
            k = (which, meta.get(addr, ('', (), '', ''))[which])
            lst = by.get(k)
            if lst:
                i = bisect.bisect_left(keys[k], va)
                if 0 < i < len(lst) and lst[i - 1][1] == lst[i][1] and not lst[i][1].startswith('libraries/'):
                    found.add(lst[i][1])
        if len(found) == 1:
            added[addr] = (next(iter(found)), 'J')
    chosen.update(added)


def infer(funcs, chosen, names, callers, layout_ios, meta):
    """S, T, K to a fixed point, then R. Each round only reads functions chosen before it."""
    classes = class_files(chosen, names, layout_ios)
    units = unit_files(chosen, meta)
    vt_path = HERE / 'vtables.json'
    vt_class, vt_files = {}, {}
    if vt_path.exists():
        owners = collections.defaultdict(set)
        for cls, slots in json.loads(vt_path.read_text(encoding='utf-8')).items():
            for slot in slots:
                owners[slot].add(cls)
        vt_class = {a: next(iter(c)) for a, c in owners.items() if len(c) == 1 and a in funcs}
        votes = collections.defaultdict(collections.Counter)
        for a, c in vt_class.items():
            if a in chosen and chosen[a][1] in 'EPIN':
                votes[c][chosen[a][0]] += 1
        vt_files = {c: v.most_common(1)[0][0] for c, v in votes.items()
                    if sum(v.values()) >= 2 and v.most_common(1)[0][1] / sum(v.values()) >= UNIT_SHARE}
    clean_units = unit_files(chosen, meta, which=2)     # the class without mangling residue: a fallback for template instantiations
    low_units = unit_files(chosen, meta, share=UNIT_SHARE_LOW)
    any_units = unit_files(chosen, meta, tiers='EPINXSUDQHTKBRGCO')
    any_clean = unit_files(chosen, meta, which=2, tiers='EPINXSUDQHTKBRGCO')
    low_clean = unit_files(chosen, meta, which=2, share=UNIT_SHARE_LOW)
    data = data_files(chosen, meta)
    data1 = data_files(chosen, meta, minimum=1)
    accessors = accessor_files(chosen, names)
    order_all = sorted(funcs, key=lambda a: int(a, 16))
    place_all = {a: i for i, a in enumerate(order_all)}
    for _round in range(6):
        added = {}
        eh = meta.get('__eh__', {})
        for addr in funcs:
            if addr in chosen:
                continue
            if addr in eh and eh[addr] in chosen and not chosen[eh[addr]][0].startswith('libraries/'):
                added[addr] = (chosen[eh[addr]][0], 'X')
                continue
            name = names.get(addr, '')
            key = class_key(name, layout_ios)
            if key and key in classes:
                added[addr] = (classes[key], 'S')
                continue
            if vt_class.get(addr) in vt_files:
                added[addr] = (vt_files[vt_class[addr]], 'U')
                continue
            unit, _refs, clean, _shape = meta.get(addr, ('', (), '', ''))
            if unit in units:
                added[addr] = (units[unit], 'U')
                continue
            if clean in clean_units:
                added[addr] = (clean_units[clean], 'U')
                continue
            refs0 = {data[r] for r in set(meta.get(addr, ('', ()))[1]) if r in data}
            if len(refs0) == 1:                                   # shared data outranks the weak class rule
                added[addr] = (next(iter(refs0)), 'D')
                continue
            if unit in low_units or clean in low_clean:
                added[addr] = (low_units.get(unit) or low_clean[clean], 'V')
                continue
            if unit in any_units or clean in any_clean:
                added[addr] = (any_units.get(unit) or any_clean[clean], 'W')
                continue
            refs = {data[r] for r in set(meta.get(addr, ('', ()))[1]) if r in data}
            if len(refs) == 1:
                added[addr] = (next(iter(refs)), 'D')
                continue
            m = PROP_INIT.match(name)
            if m and m.group(1) in accessors:
                added[addr] = (accessors[m.group(1)], 'Q')
                continue
            got = look_alike(addr, funcs, chosen, meta, order_all, place_all)
            if got:
                added[addr] = (got, 'H')
                continue
            if int(addr, 16) >= 0x7c0000:
                one = {data1[r] for r in set(meta.get(addr, ('', ()))[1]) if r in data1}
                if len(one) == 1:
                    added[addr] = (next(iter(one)), 'F')
                    continue
            tkey = template_class(name)
            if tkey and tkey in classes:
                added[addr] = (classes[tkey], 'T')
                continue
            files = {chosen[c][0] for c in callers.get(addr, ()) if c in chosen and c != addr}
            unknown = [c for c in callers.get(addr, ()) if c not in chosen and c != addr]
            if len(files) == 1 and not unknown and not next(iter(files)).startswith('libraries/'):
                added[addr] = (next(iter(files)), 'K')
        if not added:
            break
        chosen.update(added)
    order = sorted(funcs, key=lambda a: int(a, 16))
    addrs = [int(a, 16) for a in order]
    place = {a: i for i, a in enumerate(order)}
    for i in range(1, len(order)):                       # B: stubs go with the function that ends where they start
        addr, prev = order[i], order[i - 1]
        if addr not in chosen and funcs[addr] <= STUB_SIZE and prev in chosen and addrs[i] - (addrs[i - 1] + funcs[prev]) <= 15                 and not chosen[prev][0].startswith('libraries/'):
            chosen[addr] = (chosen[prev][0], 'B')
    for i, addr in enumerate(order):
        if addr in chosen:
            continue
        left = next((order[j] for j in range(i - 1, max(i - WINDOW, -1), -1) if order[j] in chosen), None)
        right = next((order[j] for j in range(i + 1, min(i + WINDOW, len(order))) if order[j] in chosen), None)
        if left and right and chosen[left][0] == chosen[right][0] and not chosen[left][0].startswith('libraries/')                 and addrs[place[right]] - addrs[place[left]] <= GAP:
            chosen[addr] = (chosen[left][0], 'R')


def holdout(funcs, chosen, names, callers, layout_ios, meta):
    """How often S and K would have picked the file a strongly assigned function already has (leave one out)."""
    out = {}
    strong = [a for a, (p, t) in chosen.items() if t in 'PI']
    ok = n = 0
    for addr in strong:
        key = class_key(names.get(addr, ''), layout_ios)
        if not key:
            continue
        got = class_files(chosen, names, layout_ios, skip=addr).get(key)
        if got:
            n += 1
            ok += got == chosen[addr][0]
    out['S'] = (ok, n)
    ok = n = 0
    for addr in strong:
        files = {chosen[c][0] for c in callers.get(addr, ()) if c in chosen and chosen[c][1] in 'PI' and c != addr}
        if len(files) == 1 and len(callers.get(addr, ())) >= 1:
            n += 1
            ok += next(iter(files)) == chosen[addr][0]
    out['K'] = (ok, n)
    uv = collections.defaultdict(collections.Counter)      # votes once, then leave one out by subtracting it
    dv = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        if tier in 'EPIN':
            unit = meta.get(addr, ('',))[0]
            if unit and not unit.startswith(('seg_', '(unnamed')):
                uv[unit][path] += 1
            for ref in set(meta.get(addr, ('', ()))[1]):
                dv[ref][path] += 1
    ok = n = 0
    for addr in strong:
        unit, own = meta.get(addr, ('',))[0], chosen[addr][0]
        if unit not in uv:
            continue
        c = uv[unit].copy()
        c[own] -= 1
        total = sum(v for v in c.values() if v > 0)
        if total:
            best, hits = c.most_common(1)[0]
            if hits >= 2 and hits / total >= UNIT_SHARE:
                n += 1
                ok += best == own
    out['U'] = (ok, n)
    ok = n = 0
    for addr in strong:
        unit, own = meta.get(addr, ('',))[0], chosen[addr][0]
        if unit not in uv:
            continue
        c = uv[unit].copy()
        c[own] -= 1
        total = sum(v for v in c.values() if v > 0)
        if total:
            best, hits = c.most_common(1)[0]
            if hits >= 2 and UNIT_SHARE_LOW <= hits / total < UNIT_SHARE:
                n += 1
                ok += best == own
    out['V'] = (ok, n)
    av = collections.defaultdict(collections.Counter)      # the same, counting the weak tiers too (what W does)
    for addr, (path, tier) in chosen.items():
        unit = meta.get(addr, ('',))[0]
        if unit and not unit.startswith(('seg_', '(unnamed')):
            av[unit][path] += 1
    ok = n = 0
    for addr in strong:
        unit, own = meta.get(addr, ('',))[0], chosen[addr][0]
        if unit not in av:
            continue
        c = av[unit].copy()
        c[own] -= 1
        total = sum(v for v in c.values() if v > 0)
        if total:
            best, hits = c.most_common(1)[0]
            if hits >= 2 and hits / total >= UNIT_SHARE:
                n += 1
                ok += best == own
    out['W'] = (ok, n)
    order = sorted(funcs, key=lambda a: int(a, 16))
    ok = n = 0
    for i in range(1, len(order)):
        addr, prev = order[i], order[i - 1]
        if addr in chosen and chosen[addr][1] in 'PI' and funcs[addr] <= STUB_SIZE and prev in chosen                 and int(order[i], 16) - (int(order[i - 1], 16) + funcs[prev]) <= 15 and chosen[prev][1] in 'PI':
            n += 1
            ok += chosen[prev][0] == chosen[addr][0]
    out['B'] = (ok, n)
    eh = meta.get('__eh__', {})
    ok = n = 0
    for addr, parent in eh.items():
        if addr in chosen and chosen[addr][1] in 'PI' and parent in chosen and chosen[parent][1] in 'PI':
            n += 1
            ok += chosen[addr][0] == chosen[parent][0]
    out['X'] = (ok, n)
    out['X children found'] = (len(eh), len(eh))
    ok = n = 0
    for addr in strong:
        own, got = chosen[addr][0], set()
        for ref in set(meta.get(addr, ('', ()))[1]):
            c = dv.get(ref)
            if not c:
                continue
            c = c.copy()
            c[own] -= 1
            live = {f: v for f, v in c.items() if v > 0}
            if len(live) == 1 and sum(live.values()) >= 2:
                got.add(next(iter(live)))
        if len(got) == 1:
            n += 1
            ok += next(iter(got)) == own
    out['D'] = (ok, n)
    order = sorted(funcs, key=lambda a: int(a, 16))
    place = {a: i for i, a in enumerate(order)}
    ok = n = 0
    for addr in strong:
        held = chosen.pop(addr)
        got = look_alike(addr, funcs, chosen, meta, order, place)
        chosen[addr] = held
        if got:
            n += 1
            ok += got == held[0]
    out['H'] = (ok, n)
    return out



def main(check=None):
    """Write docs/function-map.json. The held-out accuracy checks take minutes: run them with --holdout (or check=True)."""
    check = ('--holdout' in sys.argv) if check is None else check
    funcs, chosen, claims = build()
    files = {}
    rows = []
    for addr in sorted(funcs, key=lambda a: int(a, 16)):
        got = chosen.get(addr)
        if got:
            index = files.setdefault(got[0], len(files))
            rows.append([int(addr, 16), funcs[addr], index, got[1]])
        else:
            rows.append([int(addr, 16), funcs[addr], -1, ''])
    names = [p for p, _ in sorted(files.items(), key=lambda kv: kv[1])]
    # contested: a real build (exe string, PDB, iOS) names another file for the same function
    contested = collections.defaultdict(collections.Counter)
    for addr, (path, tier) in chosen.items():
        for other_tier in 'EPI':
            alt = claims.get(addr, {}).get(other_tier)
            if alt and alt != path and tier in 'EPI':
                contested[path][alt] += 1
    total = sum(funcs.values())
    tier_bytes = collections.Counter()
    tier_funcs = collections.Counter()
    for _a, size, idx, tier in rows:
        tier_bytes[tier or '-'] += size
        tier_funcs[tier or '-'] += 1
    result = {'note': 'best-guess source file per code function; tiers E L P I N S T K R C O (see function_map.py); never a proof of the 2008 path',
              'files': names, 'functions': rows,
              'contested': {p: dict(c.most_common(2)) for p, c in contested.items()},
              'tiers': {t: {'functions': tier_funcs[t], 'bytes': tier_bytes[t]} for t in TIERS + '-' if tier_funcs[t]}}
    (ROOT / 'docs/function-map.json').write_text(json.dumps(result, separators=(',', ':')), encoding='utf-8')
    import layout_census
    if layout_census.CHECKS.name == 'checks.json':             # the full census was there: remember its strong placements
        snap = {a: [p, t] for a, (p, t) in chosen.items() if t in 'EPIN'}
        (HERE / 'strong-tiers-snapshot.json').write_text(json.dumps(snap, separators=(',', ':')), encoding='utf-8')
    print('code functions', len(rows), 'bytes', total)
    for t in TIERS + '-':
        if tier_funcs[t]:
            print('  %s %6d functions %9d bytes %5.1f%%' % (t, tier_funcs[t], tier_bytes[t], 100 * tier_bytes[t] / total))
    print('files', len(names))
    if not check:
        print('  (held-out accuracy checks skipped; run with --holdout)')
        return
    strong, nm, cl, li, mt = build.last
    for tier, (ok, n) in holdout(funcs, strong, nm, cl, li, mt).items():
        print('  holdout %s: would pick the file the strong tiers already gave in %d of %d cases (%.0f%%)' % (tier, ok, n, 100 * ok / max(n, 1)))
    main.metrics = {'unassigned_share': tier_bytes['-'] / total,
                    'holdout': {t: (ok / n if n else None) for t, (ok, n) in holdout(funcs, strong, nm, cl, li, mt).items()}}


if __name__ == '__main__':
    main()

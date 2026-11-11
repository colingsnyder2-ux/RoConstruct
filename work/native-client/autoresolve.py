"""Auto-find source files that define the unresolved externals in link/probe.json.
 1. parse each mangled name -> (class, member); text-prefilter candidate .cpp files for 'Class::member'
 2. compile only those candidates (engine flags + overlay headers) to work/native-client/idx/*.obj
 3. read the objects' real defined symbols (symcheck) -> index symbol -> [files]
 4. write link/autoresolve.json: per symbol the ranked providers (named sources first, then the smallest mined unit)
usage: python work/native-client/autoresolve.py [--compile]   (no flag = prefilter report only)"""
import json, re, sys, concurrent.futures as cf
from pathlib import Path
sys.path.insert(0, '.')
from roc import rebuild

ROOT = rebuild.ROOT
OUT = ROOT / 'work/native-client'
IDX = OUT / 'idx'
IDX.mkdir(exist_ok=True)
unres = json.load(open(OUT / 'link/probe.json'))['unresolved']

_sc = {}
exec(open(ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read().split('def archive_symbols')[0], _sc)

SRC_ROOTS = [ROOT / 'tools/rbxgs/Client', ROOT / 'work/upstream/OpenRBX/Client']


def parse(sym):
    """('Class','member') for ?member@Class@..@@ ; ('', 'name') for free functions / data; None for templates."""
    m = re.match(r'\?\??(\w+)@(\w+)@', sym)
    if m and not sym.startswith('??$'):
        return m.group(2), m.group(1)
    m = re.match(r'\?(\w+)@@', sym)
    if m:
        return '', m.group(1)
    m = re.match(r'\?\?\$(\w+)@', sym)       # template function: match on the function name
    if m:
        return '', m.group(1)
    m = re.match(r'\?\?[01]?(\w+)@', sym)    # ctor/dtor ??0Class@@
    if m:
        return m.group(1), m.group(1)
    return None


want = {}
for s in unres:
    p = parse(s)
    if p:
        want[s] = p
print('parsed', len(want), 'of', len(unres))

texts, cand = {}, {}
cache_path = OUT / 'link/autoresolve-prefilter.json'
if '--use-prefilter' in sys.argv and cache_path.is_file():
    cached = json.load(open(cache_path))
    for symbol, paths in cached.get('resolved_candidates', {}).items():
        for value in paths:
            path = (ROOT / value).resolve()
            if path.is_file():
                cand.setdefault(path, set()).add(symbol)
                texts[path] = path.read_text(errors='replace')
else:
    files = []
    for r in SRC_ROOTS:
        if r.exists():
            files += [p for p in r.rglob('*.cpp')]
    for p in files:
        try:
            texts[p] = p.read_text(errors='replace')
        except OSError:
            pass
    for s, (cls, mem) in want.items():
        pat = (cls + '::' + mem) if cls else None
        for p, t in texts.items():
            if (pat and pat in t) or (not cls and re.search(r'\b' + re.escape(mem) + r'\s*\(', t)):
                cand.setdefault(p, set()).add(s)
named = [p for p in cand if not p.name.startswith('roc_')]
mined = [p for p in cand if p.name.startswith('roc_')]


def missing_decomp(path, text):
    """Reject source whose direct local header chain needs an absent decomp stand-in."""
    texts_to_check = [text]
    for include in re.findall(r'^\s*#include\s+"([^"]+)"', text, re.M):
        header = path.parent / include
        if header.is_file():
            texts_to_check.append(header.read_text(errors='replace'))
    return any(re.search(r'^\s*#include\s+[<"]decomp\.h[>"]', value, re.M)
               and not (path.parent / 'decomp.h').is_file() for value in texts_to_check)


blocked_sources = {p: 'requires absent decomp.h'
                   for p, text in texts.items() if p in cand and missing_decomp(p, text)}
print('candidate files', len(cand), '(named', len(named), 'mined', len(mined), ') covering',
      len({s for v in cand.values() for s in v}), 'symbols')
if '--compile' not in sys.argv:
    res = {s: sorted(str(p.relative_to(ROOT)).replace('\\', '/') for p, symbols in cand.items() if s in symbols)
           for s in unres}
    json.dump({'scope': 'text prefilter only; no compile, byte proof, provider selection, or promotion',
               'resolved_candidates': {s: paths for s, paths in res.items() if paths},
               'missing': [s for s, paths in res.items() if not paths],
               'blocked_sources': {str(p.relative_to(ROOT)).replace('\\', '/'): why
                                   for p, why in blocked_sources.items()}},
              open(OUT / 'link/autoresolve-prefilter.json', 'w'), indent=1)
    sys.exit()

limit = None
if '--max-files' in sys.argv:
    limit = int(sys.argv[sys.argv.index('--max-files') + 1])
only_source = None
if '--source' in sys.argv:
    only_source = (ROOT / sys.argv[sys.argv.index('--source') + 1]).resolve()

spec = rebuild.load_module('2008-06', 'rbxgs-app')
ov = rebuild.build_overlay('2008-06', spec['name'], spec.get('overlay'))
incs = rebuild._overlaid([rebuild._spec_path('2008-06', i) for i in spec['test_includes']], [], ov)[0]
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/w', '/DBOOST_ALL_NO_LIB'] + \
        ['/D' + d for d in spec['test_defines'].split()] + ['/I' + str(i) for i in incs]
tc = rebuild.toolchain(21022)


def comp(p):
    name = re.sub(r'\W', '_', str(p.relative_to(ROOT)))[-90:] + '.obj'
    obj = IDX / name
    if not obj.exists():
        code, log = rebuild.run(tc, 'cl', flags + ['/I' + str(p.parent), '/Fo' + name, str(p)], IDX)
        if code or not obj.exists():
            return p, None, log[-1000:]
    return p, obj, ''


index, failed, failures, nonproviders = {}, 0, {}, []
chosen = sorted((p for p in cand if p not in blocked_sources),
                key=lambda p: (p.name.startswith('roc_'), -len(cand[p]), str(p)))
prior = {}
try:
    prior = json.load(open(OUT / 'link/autoresolve.json'))
except (OSError, json.JSONDecodeError):
    pass
if '--retry-known' not in sys.argv:
    known = set(prior.get('compiled_nonproviders', [])) | set(prior.get('compile_failures', []))
    chosen = [p for p in chosen if str(p.relative_to(ROOT)).replace('\\', '/') not in known]
if only_source is not None:
    chosen = [p for p in chosen if p.resolve() == only_source]
if limit is not None:
    chosen = chosen[:limit]
if '--plan-only' in sys.argv:
    json.dump({'scope': 'compiled-provider selection only; no compile or provider claim',
               'chosen_sources': [str(p.relative_to(ROOT)).replace('\\', '/') for p in chosen],
               'skipped_known': sorted(known) if '--retry-known' not in sys.argv else [],
               'blocked_sources': {str(p.relative_to(ROOT)).replace('\\', '/'): why
                                   for p, why in blocked_sources.items()}},
              open(OUT / 'link/autoresolve-plan.json', 'w'), indent=1)
    sys.exit()
with cf.ThreadPoolExecutor(int(__import__('os').environ.get('ROC_JOBS', 12))) as pool:
    for p, obj, error in pool.map(comp, chosen):
        if obj is None:
            failed += 1
            failures[str(p.relative_to(ROOT)).replace('\\', '/')] = error
            continue
        defs = {n for n, k in _sc['symbols'](obj.read_bytes()).items() if k != 'undef'}
        matches = cand[p] & defs
        if not matches:
            nonproviders.append(str(p.relative_to(ROOT)).replace('\\', '/'))
        for s in matches:
            index.setdefault(s, []).append((str(p.relative_to(ROOT)), len(defs)))
print('compile failed', failed, '| symbols with a real provider', len(index), 'of', len(unres))
res = {}
for s, v in index.items():
    v.sort(key=lambda x: (x[0].split('/')[-1].startswith('roc_'), x[1]))   # named first, then fewest other symbols
    res[s] = v[:5]
all_failures = dict(prior.get('compile_failures', {}))
all_failures.update(failures)
all_nonproviders = sorted(set(prior.get('compiled_nonproviders', [])) | set(nonproviders))
json.dump({'scope': 'compiled source provider candidates only; no byte proof or provider selection',
           'resolved': res, 'missing': [s for s in unres if s not in res],
           'compiled_sources': [str(p.relative_to(ROOT)).replace('\\', '/') for p in chosen],
           'compile_failures': all_failures,
           'compiled_nonproviders': all_nonproviders,
           'blocked_sources': {str(p.relative_to(ROOT)).replace('\\', '/'): why
                               for p, why in blocked_sources.items()}},
          open(OUT / 'link/autoresolve.json', 'w'), indent=1)

"""python vlink.py [RSP] [--check MAP]: virtual linker. Predicts lld's symbol resolution for a planned rsp WITHOUT
linking: objects in order (first external definition wins: /FORCE:MULTIPLE), archives (.lib) only fill names still
undefined (first archive in order that exports them), /alternatename:A=B only when A is still undefined and B
resolves (chains followed), the rest stays undefined (/FORCE:UNRESOLVED -> 0) -- the zero-address class.
Writes auto/vlink_owner.json {name: owner} and auto/vlink_undef.json, and with --check MAP measures agreement with a
real lld map (owner per name) so the prediction can be trusted before audits run on it.
ponytail: ignores /OPT:REF liveness and COMDAT selection subtleties (any = first); --check shows what that costs."""
import json, os, pickle, re, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H.parents[1])); sys.path.insert(0, str(H))
from roc.rebuild import coff_externals
import defined_now
args = sys.argv[1:]
rsp = Path(next((a for a in args if a.lower().endswith('.rsp')), H / 'linkexp/qt.rsp'))
chk = args[args.index('--check') + 1] if '--check' in args else None
cf = H / 'link/obj_ext_cache.pkl'
cache = pickle.load(open(cf, 'rb')) if cf.exists() else {}
objs, libs, alts = [], [], {}
for l in rsp.read_text(errors='replace').splitlines():
    t = l.strip().strip('"')
    if t.lower().startswith('/alternatename:'):
        a, _, b = t[15:].partition('=')
        alts.setdefault(a, b)            # lld: the first /alternatename for a name wins
    elif t.lower().endswith('.obj'):
        objs.append(t)
    elif t.lower().endswith('.lib'):
        libs.append(t)
owner, undef_refs, dirty = {}, set(), False
for p in objs:
    v = cache.get(p)
    try:
        st = os.stat(p)
    except OSError:
        continue
    if not v or v[0] != st.st_mtime or v[1] != st.st_size:
        try:
            v = (st.st_mtime, st.st_size, coff_externals(open(p, 'rb').read()))
        except Exception:
            continue
        cache[p] = v; dirty = True
    base = Path(p).name
    for n, d in v[2].items():
        if d:
            owner.setdefault(n, base)
        else:
            undef_refs.add(n)
if dirty:
    pickle.dump(cache, open(cf, 'wb'), protocol=4)
lib_names = []
for p in libs:
    if os.path.exists(p):
        try:
            lib_names.append((Path(p).stem.lower(), defined_now.lib_symbols(p)))
        except Exception:
            pass


def resolve(n, depth=0):
    if n in owner:
        return owner[n]
    for lib, names in lib_names:
        if n in names:
            owner[n] = lib + ':lib'
            return owner[n]
    if n in alts and depth < 8:
        r = resolve(alts[n], depth + 1)
        if r:
            return r
    return None


pred, undef = {}, []
for n in sorted(undef_refs | set(alts)):
    r = resolve(n)
    if r:
        pred[n] = r
    elif n in undef_refs:
        undef.append(n)
pred.update({n: o for n, o in owner.items()})
zero = [n for n in undef if n in alts]   # an alias exists but its target never resolves -> address 0
(H / 'auto/vlink_owner.json').write_text(json.dumps(pred))
(H / 'auto/vlink_undef.json').write_text(json.dumps({'undefined': undef, 'zero_alias': zero}, indent=0))
print('vlink: objects %d, libs %d, aliases %d -> defined %d, undefined refs %d (alias->missing: %d %s)'
      % (len(objs), len(libs), len(alts), len(pred), len(undef), len(zero), zero[:5]))
if chk:
    real = {}
    for l in open(chk, errors='replace'):
        p = l.split()
        if len(p) >= 4 and ':' in p[0] and not p[0].startswith('0000:'):
            real.setdefault(p[1], re.sub(r'^pre\d+_', '', p[-1]))   # lld prints duplicate base names as pre<N>_<name>
    both = [n for n in real if n in pred and not n.startswith(('$', '.', '__unwind', '__ehhandler', '__catch', '__try'))]
    agree = [n for n in both if pred[n] == real[n] or (pred[n].endswith(':lib') and ':' in real[n] and pred[n].split(':')[0] in real[n].lower())]
    dis = [n for n in both if n not in agree]
    print('check vs %s: names compared %d, agree %.2f%%' % (Path(chk).name, len(both), 100.0 * len(agree) / max(1, len(both))))
    for n in dis[:12]:
        print('   %-60s pred %-40s real %s' % (n[:60], pred[n][:40], real[n][:40]))

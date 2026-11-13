"""Closure loop (owner-authorized shortcut): relink the stub-backed client from the server's byte-exact analogs.
Each round: link chosen.json + glue + analogs so far (no stubs) -> every undefined symbol with a known exe address gets its analog
(rename.py: compile src/2008-06/ADDR.cpp, find the byte-identical object function, rename it and its callees to real names;
unnamed callees keep func_<addr> / dat_<addr> via ROC_RENAME_PLACEHOLDER) -> add the analog -> repeat until nothing new links.
Whatever is still undefined is stubbed by relink_big's mkstub as before.
usage: python auto_closure.py [max_rounds]      state: work/native-client/shortcut/closure/"""
import json, os, re, subprocess, sys
from pathlib import Path
sys.path.insert(0, '.')
from roc.rebuild import coff_externals
H = Path('work/native-client/shortcut')
C = H / 'closure'
(C / 'renamed').mkdir(parents=True, exist_ok=True)
rounds = int(sys.argv[1]) if len(sys.argv) > 1 else 6
closure = json.load(open('work/native-client/claude-identity-closure-v5.json'))
symaddr = {b['symbol']: b['addr'] for b in closure['bindings'] if b.get('addr')}
chosen = json.load(open(H / 'chosen.json'))
glue = [(H / o).resolve().as_posix() for o in json.load(open(H / 'glue.json'))]
base = Path('work/native-client/link/selected-engine-cumulative.json').resolve().as_posix()
DUPS = H / 'dups.json'
tried = json.load(open(C / 'tried.json')) if (C / 'tried.json').exists() else {}


def link(objs):
    json.dump({'selected': [{'object': c} for c in objs]}, open(H / 'receipt-closure.json', 'w'))
    env = dict(os.environ, ROC_NODEFAULTLIB='libboost_thread-vc80-mt-1_34_1.lib,libboost_date_time-vc80-mt-1_34_1.lib,libboost_signals-vc80-mt-1_34_1.lib', ROC_STRONG_OWN='1', ROC_ENGINE_ABI='1', ROC_LINK_RES=os.path.normpath(str((H / 'Roblox2008.res').resolve())),
               ROC_LINK_EXTRA=base + ';' + (H / 'receipt-closure.json').resolve().as_posix())
    if DUPS.exists():
        env['ROC_DEDUPE'] = str(DUPS.resolve())
    if (H / 'shell_wins.json').exists():
        env['ROC_SHELL_WINS'] = str((H / 'shell_wins.json').resolve())
    for _ in range(4):
        subprocess.run([sys.executable, 'work/native-client/linkprobe.py'], env=env, capture_output=True)
        pr = json.load(open('work/native-client/link/probe.json'))
        if not pr['duplicates']:
            break
        found = set(json.load(open(DUPS))) if DUPS.exists() else set()
        found |= {m.group(1) for d in pr['duplicates'] for m in [re.search(r'\((\?[^)]*)\)\s*$', d)] if m}
        for _try in range(5):
            try:
                DUPS.write_text(json.dumps(sorted(found)))
                break
            except OSError:
                import time; time.sleep(1)
        env['ROC_DEDUPE'] = str(DUPS.resolve())
    return pr


def learn_addresses():
    """Callee names seen by rename.py (analog relocation -> exe address) fill in symbols the identity closure lacks."""
    subprocess.run([sys.executable, str(H / 'helper_addrs.py')], capture_output=True, text=True)
    h = C / 'helper_addrs.json'
    if h.exists():
        for sym, va in json.load(open(h)).items():
            if not sym.startswith(('func_', 'dat_')):
                symaddr.setdefault(sym, va)
    f = C / 'rename.json'
    if not f.exists():
        return
    for a, r in json.load(open(f)).items():
        if r.get('status') != 'renamed':
            continue
        for orig, va in (r.get('refs') or {}).items():
            symaddr.setdefault(r.get('renamed', {}).get(orig, orig), va)


def address_of(sym):
    m = re.fullmatch(r'(?:func|dat)_([0-9a-f]{8})', sym)
    return m.group(1) if m else symaddr.get(sym)


def fix_imports(folder):
    """rename.py labels an IAT slot 'DLL!name'; the linker knows it as __imp_name (import library thunk slot)."""
    sys.path.insert(0, 'work/native-client')
    import rename as rn
    for o in Path(folder).glob('*.obj'):
        data = o.read_bytes()
        syms = rn.symtab(data)[0]
        mp = {i: '__imp_' + n.split('!', 1)[1] for i, n, sec, cls, v in syms if '.dll!' in n and sec == 0}
        if mp:
            o.write_bytes(rn.rename(data, mp))


def strip_lib_dups(folder):
    """A kept comdat helper that the import library also defines (e.g. std::string members the exe imports): drop our copy."""
    from roc import rebuild
    text = Path('work/native-client/link/link.txt').read_text(errors='replace')
    n = 0
    for m in re.finditer(r'LNK2005:.*?\((\?[^)]*)\)\s+already defined in (\S+\.obj)', text):
        sym, obj = m.group(1), m.group(2)
        o = Path(folder) / obj
        if o.exists():
            o.write_bytes(rebuild.strip_symbols(o.read_bytes(), drop={sym}))
            n += 1
    return n


def build_index():
    """symbol -> compiled native/engine-abi objects that define it (templates the identity closure has no address for)."""
    idx = {}
    for d in ('work/native-client/obj-engine-abi', 'work/native-client/obj'):
        for o in sorted(Path(d).glob('*.obj')):
            if 'Trial' in o.name:
                continue
            for sym, defined in coff_externals(o.read_bytes()).items():
                if defined:
                    idx.setdefault(sym, []).append(o.resolve().as_posix())
    return idx


INDEX = build_index()
EXTRA = json.load(open(C / 'extra.json')) if (C / 'extra.json').exists() else []
selected = sorted(p.as_posix() for p in (C / 'renamed').glob('*.obj'))
for r in range(rounds):
    pr = link(chosen + glue + selected + EXTRA)
    if strip_lib_dups(C / 'renamed'):
        pr = link(chosen + glue + selected + EXTRA)
    un = pr['unresolved']
    learn_addresses()
    jobs = {}
    for s in un:
        a = address_of(s)
        if a and int(a, 16) < 0x7c0000 and s not in tried:
            jobs[s] = a
    added = 0
    for s2 in un:
        if address_of(s2) is None and s2 in INDEX:
            cand = [c for c in INDEX[s2] if c not in EXTRA and c not in chosen]
            if cand:
                EXTRA.append(cand[0]); added += 1
    json.dump(EXTRA, open(C / 'extra.json', 'w'), indent=0)
    print('round', r,'extra objs added', added,'|', 'selected', len(selected), 'unresolved', len(un), 'new jobs', len(jobs), flush=True)
    if not jobs and not added:
        break
    am = {s: {'exact': [a]} for s, a in jobs.items()}
    json.dump(am, open(C / 'addrmap.json', 'w'))
    env = dict(os.environ, ROC_RENAME_PLACEHOLDER='1', ROC_RENAME_KEEP_HELPERS='1', ROC_ADDRMAP=str((C / 'addrmap.json').resolve()),
               ROC_RENAME_OUT=str((C / 'renamed').resolve()), ROC_RENAME_JSON=str((C / 'rename.json').resolve()))
    subprocess.run([sys.executable, 'work/native-client/rename.py', *sorted(set(jobs.values()))], env=env, capture_output=True, text=True)
    fix_imports(C / 'renamed')
    res = json.load(open(C / 'rename.json'))
    new = 0
    for s, a in jobs.items():
        st = res.get(a, {}).get('status')
        tried[s] = st
        if st == 'renamed':
            new += 1
    json.dump(tried, open(C / 'tried.json', 'w'), indent=0)
    selected = sorted(p.as_posix() for p in (C / 'renamed').glob('*.obj'))
    print('  renamed', new, 'of', len(jobs), {k: sum(1 for v in tried.values() if v == k) for k in set(tried.values())}, flush=True)
    if not new:
        break
json.dump(chosen + EXTRA + [s for s in selected], open(H / 'chosen_closure.json', 'w'), indent=0)
print('wrote chosen_closure.json with', len(selected), 'analogs')

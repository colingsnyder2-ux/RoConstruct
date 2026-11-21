"""One text block per address (target < 12 KB) a worker can read instead of exploring (no model).
  python work/native-client/context_pack.py ADDR
Sections: family_status, original asm with named relocation targets, owner facts, owner header + compiler member
offsets, mined analog, 3 nearest matched examples (nearest_matched.py), Ghidra hint, rules."""
import json
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
BUDGET = 11800


def _run(args, limit):
    try:
        r = subprocess.run([sys.executable] + args, cwd=ROOT, capture_output=True, text=True, encoding='utf-8',
                           errors='replace', timeout=120, env={**__import__('os').environ, 'PYTHONIOENCODING': 'utf-8'})
        return (r.stdout or r.stderr).strip()[:limit]
    except Exception as e:                                         # noqa: BLE001
        return '(unavailable: %r)' % e


def find_header(owner):
    leaf = re.sub(r'<.*', '', owner or '').split('::')[-1]
    if not leaf:
        return None
    for p in (ROOT / 'rebuild/2008-06/native-headers').rglob(leaf + '.h'):
        if not any('-' in x for x in p.relative_to(ROOT / 'rebuild/2008-06/native-headers').parts[:1]):
            return p
    return None


def cached_layout(hp, cls):
    """Read class_workflow's cached compiler layout without importing it (same cache file and format)."""
    cache = HERE / 'workflow-layouts' / (re.sub(r'\W+', '_', hp.as_posix().split('native-headers/')[-1]) + '.json')
    if not cache.is_file():
        return ''
    leaf = cls.split('::')[-1]
    for name, row in json.loads(cache.read_text()).items():
        if name.split('::')[-1] == leaf:
            return 'sizeof(%s) = 0x%x\n' % (name, row['size']) + '\n'.join(
                '+0x%x %s' % (mm['offset'], mm['name'].split()[-1]) for mm in row['members'][:160])
    return ''


def asm_text(addr):
    """native-asm in-process with the (slow, 30 s) symbol map cached on disk."""
    import pickle
    from roc import match, native_asm
    cache = HERE / 'nearest-index' / 'asm-names.pkl'
    stamp = len(list((ROOT / 'rebuild/2008-06/out').glob('**/*.tudiff.json')))
    try:
        c = pickle.load(open(cache, 'rb'))
        if c['stamp'] != stamp:
            raise ValueError
        native_asm.names.cache_clear()
        native_asm.names = lambda client, _n=c['names']: _n
    except Exception:                                              # noqa: BLE001
        pickle.dump({'stamp': stamp, 'names': native_asm.names('2008-06')}, open(cache, 'wb'))
    body, relocs, info = match.target('2008-06', addr)
    return '\n'.join('%08x %s' % (a, t) for a, t, _ in native_asm.lines(body, int(addr, 16), relocs, '2008-06'))


def pack(addr, header=None, cls=None, layout_fn=None):
    t0 = time.time()
    addr = addr.lower().zfill(8)
    owners = json.loads((HERE / 'research-owners/owners.json').read_text()) if (HERE / 'research-owners/owners.json').is_file() else {}
    row = owners.get(addr) or {}
    cls = cls or row.get('owner')
    hp = (ROOT / header) if header else find_header(cls)
    parts = ['##### CONTEXT PACK %s (pre-computed; read this instead of exploring) #####' % addr]
    parts.append('--- (a) status ---\n' + _run(['work/native-client/family_status.py', addr], 1400))
    parts.append('--- (b) original assembly (relocation targets named) ---\n' + asm_text(addr)[:3200])
    if row:
        parts.append('--- (c) owner facts ---\n' + '\n'.join('%s: %s' % (k, str(v)[:200]) for k, v in row.items()))
    if hp and hp.is_file():
        parts.append('--- (d) owner header %s (first 6 KB) ---\n%s' % (hp.relative_to(ROOT).as_posix(), hp.read_text(errors='replace')[:6000]))
        try:
            table = cached_layout(hp, cls)
            if not table:
                if layout_fn is None:
                    import class_workflow
                    layout_fn = class_workflow.layout_table
                table = layout_fn(hp.relative_to(ROOT).as_posix(), cls)
            if table:
                parts.append('--- compiler member offsets ---\n' + table[:1500])
        except Exception:                                          # noqa: BLE001
            pass
    analog = ROOT / 'src/2008-06' / (addr + '.cpp')
    if analog.is_file():
        parts.append('--- (e) mined analog: STATEMENT ORDER ONLY, NEVER COPY ITS STRUCTS ---\n' + analog.read_text(errors='replace')[:2000])
    try:
        import nearest_matched as nm
        near = []
        for s, a, r in nm.nearest(addr, 3):
            near.append('# %s sim=%.2f size=%d %s\n%s' % (a, s, r['size'], Path(r['src']).name, nm.function_text(r['src'], r['sym'])[:900]))
        if near:
            parts.append('--- (f) 3 nearest byte-exact matched functions (same compiler shape; native source) ---\n' + '\n\n'.join(near))
    except Exception:                                              # noqa: BLE001
        pass
    try:
        import ghidra_hint
        g = ghidra_hint.hint(addr, 1400)
        if g:
            parts.append('--- (g) ' + g)
    except Exception:                                              # noqa: BLE001
        pass
    parts.append('--- (h) RULES --- real classes only; never define class/struct/union/pad/extern in native .cpp; mark guesses '
                 '`// INFERRED: <evidence>`; prove with `python work/native-client/agent_prove.py FILE ADDR=name`.')
    text = '\n\n'.join(parts)
    if len(text) > BUDGET:                                         # trim the largest soft sections first
        text = text[:BUDGET - 200] + '\n...(truncated)...\n' + parts[-1]
    return text + '\n[pack built in %.1fs]' % (time.time() - t0)


if __name__ == '__main__':
    out = pack(sys.argv[1])
    print(out)
    print('SIZE', len(out.encode('utf-8', 'replace')), file=sys.stderr)

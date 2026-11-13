"""Mined exact analog (src/2008-06/ADDR.cpp, placeholder names/structs) -> authentic C++ on the real headers.
Loop per target: agent rewrites the analog against the real declarations -> compile with the shell's flags ->
the object must define the exact unresolved symbol -> byte diff vs the 2008 target (roc native-asm --obj).
Tiers: exact (byte match), compiles (right symbol, bytes differ), failed. Only exact/compiles are adoptable.

  python work/native-client/convert.py prepare [ADDR ...]     build workspaces from link/addrmap.json
  python work/native-client/convert.py check ADDR              compile + prove one candidate (agents call this)
  python work/native-client/convert.py run [--agent codex|claude] [--limit N] [--minutes M] [ADDR ...]
  python work/native-client/convert.py adopt                   copy exact candidates into native-classes
"""
import json, os, re, subprocess, sys, shutil, time
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild, agent

ROOT = rebuild.ROOT
NC = ROOT / 'work/native-client'
WS = NC / 'convert'
RESULTS = WS / 'results.json'
HDRS = [ROOT / 'rebuild/2008-06/native-headers', ROOT / 'rebuild/2008-06/out/RbxgsApp/overlay', ROOT / 'tools/rbxgs/Client']
DONORS = [ROOT / 'tools/rbxgs/Client', ROOT / 'work/upstream/OpenRBX/Client']
FLAGS_LINE = '// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string'


def targets():
    m = json.load(open(NC / 'link/addrmap.json'))
    return {v['exact'][0]: dict(symbol=s, **v) for s, v in m.items() if v['exact']}


_TEXTS = {}


def texts(root, exts):
    key = (root, tuple(sorted(exts)))
    if key not in _TEXTS:
        out = []
        for p in root.rglob('*'):
            if p.suffix in exts:
                try:
                    out.append((p, p.read_text(errors='replace')))
                except OSError:
                    pass
        _TEXTS[key] = out
    return _TEXTS[key]


def grep(roots, pattern, exts, limit=6, skip_mined=False):
    rx = re.compile(pattern)
    hits = []
    for r in roots:
        for p, t in texts(r, exts):
            if skip_mined and p.name.startswith('roc_'):
                continue
            if rx.search(t):
                hits.append(p)
                if len(hits) >= limit:
                    return hits
    return hits


def body_of(text, cls, mem):
    """First 'cls::mem(...) {...}' definition with its braces balanced."""
    m = re.search(r'[^\n;{}]*\b' + re.escape(cls) + r'::' + re.escape(mem) + r'\s*\([^;{]*\)[^;{]*\{', text)
    if not m:
        return None
    i, depth = m.end() - 1, 0
    for j in range(i, len(text)):
        depth += {'{': 1, '}': -1}.get(text[j], 0)
        if depth == 0:
            return text[m.start():j + 1].strip()
    return None


def prepare(addr, t):
    d = WS / addr
    d.mkdir(parents=True, exist_ok=True)
    cls, mem = t['class'], t['member']
    shutil.copy(ROOT / 'src/2008-06' / (addr + '.cpp'), d / 'analog.cpp')
    asm = subprocess.run([sys.executable, str(ROOT / 'roc.py'), 'native-asm', '2008-06', addr], cwd=ROOT,
                         capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
    (d / 'target.asm').write_text(asm)
    decl = grep(HDRS, r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s*)?' + re.escape(cls) + r'\b[^;]*\{', {'.h', '.hpp'})
    donors = []
    for p in grep(DONORS, re.escape(cls) + '::' + re.escape(mem) + r'\s*\(', {'.cpp'}, limit=12):
        b = body_of(p.read_text(errors='replace'), cls, mem)
        if b:
            donors.append('// from %s\n%s\n' % (p.relative_to(ROOT), b))
    (d / 'donor_2007.cpp').write_text('\n'.join(donors[:4]) or '// no 2007 body found\n')
    task = dict(addr=addr, symbol=t['symbol'], cls=cls, member=mem,
                headers=[str(p) for p in decl], check='python "%s" check %s' % (Path(__file__).resolve(), addr))
    (d / 'task.json').write_text(json.dumps(task, indent=1))
    (d / 'instructions.md').write_text(INSTRUCTIONS.format(**task, hdr='\n'.join('- ' + h for h in task['headers']) or '- (none found: search rebuild/2008-06/native-headers)'))
    if not (d / 'candidate.cpp').exists():
        (d / 'candidate.cpp').write_text(FLAGS_LINE + '\n// %s %s::%s\n' % (addr, cls, mem))
    return d


INSTRUCTIONS = """# Convert one mined analog into authentic 2008 C++

Target: `{symbol}` = `{cls}::{member}` at 2008-06 address `{addr}`.

Files here:
- `analog.cpp`: a server-verified byte-exact analog. Its struct names, field names and helpers are PLACEHOLDERS
  (e.g. `reserved0[0x70]`, `Service`, `f()`); the instruction stream is the truth.
- `target.asm`: the real 2008 disassembly.
- `donor_2007.cpp`: the Dec 2007 source of the same method when one exists (behaviour hint; 2008 may differ).
- Real declarations of `{cls}` (read these; do NOT edit headers):
{hdr}

Write `candidate.cpp`: keep its first `// native-flags:` line, `#include` the real headers, and define
`{cls}::{member}` with the real member names/types so it compiles to the same instructions as `analog.cpp`.
Rules: no inline asm, no byte blobs, no invented struct fields or offsets, no new classes standing in for real ones,
no stubs. Only this one function (plus `extern` declarations of real globals if needed).

Test with: `{check}` -- it prints EXACT, COMPILES (right symbol, bytes differ, with a diff), or an error.
Iterate until EXACT or you run out of ideas; then stop. If the real header is missing a member the analog
needs at a known offset, write that as one line in `blocker.txt` (offset, use, evidence) and stop.
"""


def check(addr, quiet=False):
    d = WS / addr
    task = json.loads((d / 'task.json').read_text())
    import importlib.util
    spec = importlib.util.spec_from_file_location('inv', NC / 'inventory_flags.py')
    inv = importlib.util.module_from_spec(spec); spec.loader.exec_module(inv)
    src = d / 'candidate.cpp'
    code, text = rebuild.run(rebuild.toolchain(21022), 'cl', inv.flags_for(src) + ['/Focandidate.obj', str(src)], d)
    obj = d / 'candidate.obj'
    if code or not obj.exists():
        errs = [l for l in text.splitlines() if 'error' in l][:12]
        out = dict(tier='failed', why='compile', detail=errs)
    else:
        from roc import match
        syms = [f[0] for f in match.coff_functions(obj.read_bytes())]
        if task['symbol'] not in syms:
            out = dict(tier='failed', why='symbol', detail=['wanted ' + task['symbol']] + ['have ' + s for s in syms[:8]])
        else:
            r = subprocess.run([sys.executable, str(ROOT / 'roc.py'), 'native-asm', '2008-06', addr, '--obj', str(obj),
                                '--sym', task['symbol']], cwd=ROOT, capture_output=True, text=True, encoding='utf-8', errors='replace')
            diff = r.stdout
            exact = 'first divergence' not in diff and '\n-' not in diff and '\n+' not in diff
            out = dict(tier='exact' if exact else 'compiles', detail=diff.splitlines()[:60])
    if not quiet:
        print({'exact': 'EXACT', 'compiles': 'COMPILES (bytes differ)', 'failed': 'FAILED: ' + out.get('why', '')}[out['tier']])
        print('\n'.join(out['detail']))
    return out


def run_agent(d, kind, minutes):
    prompt = 'Read instructions.md in this folder and do the task. Work only in this folder.'
    if kind == 'claude':
        argv = [shutil.which('claude') or 'claude', '-p', prompt, '--permission-mode', 'acceptEdits',
                '--allowedTools', 'Read,Grep,Glob,Edit,Write,Bash', '--add-dir', str(ROOT)]
        inp = None
    else:
        argv = agent.command('codex', None)
        argv[0] = shutil.which('codex') or 'codex'
        argv[argv.index('-C') + 1] = str(d)
        argv[-1:-1] = ['--skip-git-repo-check', '--ephemeral']
        inp = prompt
    try:
        subprocess.run(argv, cwd=d, input=inp, capture_output=True, text=True, encoding='utf-8', errors='replace',
                       timeout=minutes * 60)
    except subprocess.TimeoutExpired:
        pass


def main():
    a = sys.argv[1:]
    cmd = a.pop(0) if a else 'run'
    WS.mkdir(parents=True, exist_ok=True)
    res = json.loads(RESULTS.read_text()) if RESULTS.exists() else {}
    if cmd == 'check':
        sys.exit(0 if check(a[0])['tier'] == 'exact' else 1)
    if cmd == 'adopt':
        n = 0
        for addr, r in res.items():
            if r['tier'] == 'exact':
                t = json.loads((WS / addr / 'task.json').read_text())
                dst = ROOT / 'rebuild/2008-06/native-classes' / ('Conv2008_%s_%s_%s.cpp' % (t['cls'], t['member'].strip('~'), addr))
                body = (WS / addr / 'candidate.cpp').read_text()
                lines = body.splitlines()
                dst.write_text('\n'.join(lines[:1] + ['// %s (%s) converted from the exact server analog src/2008-06/%s.cpp; byte-exact vs 2008.' % (t['symbol'], t['cls'] + '::' + t['member'], addr)] + lines[1:]) + '\n')
                n += 1
        print('adopted', n)
        return
    kind = 'claude'
    limit, minutes = 10 ** 6, 15
    if '--agent' in a:
        i = a.index('--agent'); kind = a[i + 1]; del a[i:i + 2]
    if '--limit' in a:
        i = a.index('--limit'); limit = int(a[i + 1]); del a[i:i + 2]
    if '--minutes' in a:
        i = a.index('--minutes'); minutes = int(a[i + 1]); del a[i:i + 2]
    ts = targets()
    sel = a or [x for x in sorted(ts) if res.get(x, {}).get('tier') != 'exact']
    for addr in sel[:limit]:
        d = prepare(addr, ts[addr])
        if cmd == 'prepare':
            print('prepared', d)
            continue
        t0 = time.time()
        run_agent(d, kind, minutes)
        r = check(addr, quiet=True)
        r['seconds'] = round(time.time() - t0)
        res[addr] = r
        RESULTS.write_text(json.dumps(res, indent=1))
        print(addr, ts[addr]['class'] + '::' + ts[addr]['member'], r['tier'], r['seconds'], 's', flush=True)


if __name__ == '__main__':
    main()

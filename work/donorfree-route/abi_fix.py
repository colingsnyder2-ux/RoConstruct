"""python abi_fix.py [--apply]: make every caller declaration of a draft helper match the helper's own definition, when that
definition agrees with the original exe's ABI (callee `ret N` and ecx use, as autorecover.target_abi reads them).
Without --apply it only reports. Prints the changed caller files (recompile them)."""
import re, subprocess, sys
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
NC = ROOT / 'rebuild/2008-06/native-classes'
PROTO = re.compile(r'extern\s+"C"\s+([^;{()]*?)\s*(__fastcall|__stdcall|__cdecl)?\s*(\**)\s*(fn_([0-9a-f]{8}))\s*\(([^)]*)\)\s*([;{])')
src = (H / 'autorecover.py').read_text()
ns = {'re': re}
exec(src[src.index('def target_abi'):src.index('def callee_conventions')], ns)


def exe_abi(a):
    out = subprocess.run([sys.executable, str(H / 'annot_dis.py'), a, '-n', '0x1000'], capture_output=True, text=True, cwd=ROOT).stdout
    lines = []
    for l in out.splitlines():
        if l.rstrip().endswith('int3'):
            break
        lines.append(l)
    t = ns['target_abi']('\n'.join(lines))
    n = int(re.search(r'ret (\d+)', t).group(1)) if 'ret ' in t else 0
    return ('thiscall' if t.startswith('__thiscall') else 'stdcall' if t.startswith('__stdcall') else 'cdecl'), n


def params(p):
    p = p.strip()
    return [] if p in ('', 'void') else [x.strip() for x in p.split(',')]


def abi_of(conv, ps):
    stack = 4 * len(ps)   # ponytail: 4 bytes per parameter; by-value structs (std::string) need a manual fix
    if conv == '__fastcall':
        return 'thiscall', max(stack - 8, 0)
    return ('stdcall', stack) if conv == '__stdcall' else ('cdecl', 0)


defs, uses = {}, {}
for f in NC.glob('AutoRecover_*.cpp'):
    t = f.read_text(errors='replace')
    for m in PROTO.finditer(t):
        a = m.group(5)
        if m.group(7) == '{' and f.stem.endswith(a):
            defs[a] = (m, f)
        elif m.group(7) == ';':
            uses.setdefault(a, []).append((m, f))
changed = set()
for a, (dm, df) in sorted(defs.items()):
    dabi = abi_of(dm.group(2), params(dm.group(6)))
    bad = [(m, f) for m, f in uses.get(a, []) if abi_of(m.group(2), params(m.group(6))) != dabi]
    if not bad:
        continue
    eabi = exe_abi(a)
    ok = dabi == eabi or (dabi[0] == eabi[0] == 'cdecl')
    print('%s def %s exe %s callers %d -> %s' % (a, dabi, eabi, len(bad), 'fix callers' if ok else 'definition wrong: redo draft'))
    if not ok or '--apply' not in sys.argv:
        continue
    if re.search(r'[A-Za-z_]\w*::|(?!(?:void|int|unsigned|char|short|long|float|double|bool|const|signed))[A-Z]\w*', dm.group(1) + dm.group(6)):
        print('   skipped: prototype uses class types; redo the callers instead: ' + ' '.join(f.stem[-8:] for m, f in bad))
        continue
    proto = 'extern "C" %s %s %s%s(%s);' % (dm.group(1).strip(), dm.group(2) or '', dm.group(3), dm.group(4), dm.group(6).strip())
    for m, f in bad:
        t = f.read_text(errors='replace')
        t = t.replace(m.group(0), ' '.join(proto.split()), 1)
        f.write_text(t)
        changed.add(f.name)
print('changed callers: ' + ' '.join(sorted(changed)))

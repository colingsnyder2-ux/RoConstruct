"""Name::callDoDeclare<sX> instantiations, proven by bytes and relocation identity.

Convert rows `RBX::Name::callDoDeclare<&RBX::sX>` belong to the translation unit
that defines `sX`.  Per defining native source: probe TU = `#include <source>` +
explicit instantiations (array name, no `&`: it decays to the `const char*`
template parameter).

Proof per row (doDeclare<sX> bodies are byte-identical for every sX, so bytes
alone cannot pick the address):
  1. callDoDeclare<sX> object bytes == original bytes at its closure address;
  2. its jump lands on one original address whose bytes equal doDeclare<sX>;
  3. that doDeclare's relocation to sX resolves, in the original image, to the
     same initialized data (string) the native source defines for sX
     (roc.native_bulk.audit_references data comparison).

--apply SOURCE...: lease, append proven lines, recompile, re-prove from the
source's own object, require no lost exact symbol; else restore.  Never commits.
"""
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match, native_bulk  # noqa: E402
import native_template_probe as probe  # noqa: E402

BLOCK = '// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).'


def rows_by_source():
    queue = json.loads((HERE / 'claude-conversion-queue.json').read_text())['classes']
    rows = [m for r in queue if r['owner'] == 'RBX::Name' for m in r['methods'] if m['state'] == 'convert']
    sources = {p: p.read_text(errors='replace') for p in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp')}
    out = defaultdict(list)
    for m in rows:
        found = re.search(r'\?\?\$callDoDeclare@\$1\?(\w+)@((?:\w+@)*)@?3', m['symbol'])
        if not found:
            continue
        var, scope = found[1], found[2]
        ns = '::'.join(reversed([s for s in scope.split('@') if s]))
        owner = [p for p, t in sources.items() if re.search(r'\b%s\s*(\[\s*\])?\s*=' % var, t)]
        if len(owner) == 1:
            out[owner[0]].append(('template void RBX::Name::callDoDeclare<%s%s>();' % (ns + '::' if ns else '::', var),
                                  m['symbol'], m['addr']))
    return out


def sx_ok(raw, symbol, body, cand, targets, var):
    target, target_relocs = targets.body(cand)
    if len(target) != len(body[0]) or not match.exact_match(target, target_relocs, *body):
        return False
    refs, errors = native_bulk.audit_references(raw, symbol, body[0], target, target_relocs, int(cand, 16), targets, {})
    mine = [r for r in refs if r['symbol'].startswith('?%s@' % var)]
    return bool(mine) and not [e for e in errors if e.endswith(': ' + mine[0]['symbol'])]


def prove(raw, rows, targets):
    bodies = {s: (b, r) for s, b, r in match.coff_functions(raw)}
    proved = []
    for line, symbol, addr in rows:
        if symbol not in bodies:
            continue
        body, relocs = bodies[symbol]
        target, target_relocs = targets.body(addr)
        callee = symbol.replace('??$callDoDeclare@', '??$doDeclare@').replace('@Name@RBX@@CAXXZ', '@Name@RBX@@CAABV01@XZ')
        if len(target) != len(body) or not match.exact_match(target, target_relocs, body, relocs) or callee not in bodies:
            continue
        refs, _ = native_bulk.audit_references(raw, symbol, body, target, target_relocs, int(addr, 16), targets, {})
        landing = [r['address'] for r in refs if r['symbol'] == callee]
        var = re.search(r'\$1\?(\w+)@', symbol)[1]
        if len(landing) == 1 and sx_ok(raw, callee, bodies[callee], landing[0], targets, var):
            proved.append((line, symbol, addr))
    return proved


def compile_probe(source, lines, flags, out):
    tu, keep, code = out / 'probe.cpp', list(lines), 1
    for _ in range(20):
        tu.write_text('#include "%s"\n' % source.as_posix() + '\n'.join(l for l, _, _ in keep) + '\n', encoding='utf-8')
        code, log, _ = probe.compile_tu(flags, tu, out / 'probe')
        bad = {int(n) for n in re.findall(r'probe\.cpp\((\d+)\)', log) if int(n) >= 2}
        if not code or not bad:
            break
        keep = [k for i, k in enumerate(keep, 2) if i not in bad]
    return code, keep


def lease(path):
    rel = path.resolve().relative_to(ROOT).as_posix()
    done = subprocess.run(['cmd', '/c', str(ROOT / 'roc.cmd'), 'lease', 'take', 'claude-name-' + path.stem, rel, '--hours', '4'],
                          cwd=ROOT, capture_output=True, text=True)
    return done.returncode == 0


def apply(source, proved, flags, out, targets):
    if not lease(source):
        return 'leased by another worker'
    code, _, _ = probe.compile_tu(flags, source, out / 'before')
    if code:
        return 'source does not compile'
    base = probe.exact((out / 'before/candidate.obj').read_bytes(), targets)
    original = source.read_bytes()
    nl = b'\r\n' if b'\r\n' in original else b'\n'
    source.write_bytes(original.rstrip(b'\r\n') + nl + nl.join([b'', BLOCK.encode()] + [l.encode() for l, _, _ in proved]) + nl)
    code, _, _ = probe.compile_tu(flags, source, out / 'after')
    raw = b'' if code else (out / 'after/candidate.obj').read_bytes()
    after = probe.exact(raw, targets) if raw else {}
    lost = [s for s, a in base.items() if sorted(after.get(s, [])) != sorted(a)]
    again = prove(raw, proved, targets) if raw else []
    if code or lost or len(again) != len(proved):
        source.write_bytes(original)
        return 'reverted (compile=%s lost=%d reproved=%d/%d)' % (code, len(lost), len(again), len(proved))
    return 'applied'


def main():
    do_apply = '--apply' in sys.argv
    only = [a for a in sys.argv[1:] if not a.startswith('--')]
    targets, check = native_bulk.Targets('2008-06'), probe.runner()
    total = applied = 0
    for source, lines in sorted(rows_by_source().items()):
        if only and source.stem not in only:
            continue
        out = HERE / 'claude-name-declare' / source.stem
        flags = probe.flags_for(check, source, out)
        code, keep = compile_probe(source, lines, flags, out)
        proved = prove((out / 'probe/candidate.obj').read_bytes(), keep, targets) if not code else []
        status = apply(source, proved, flags, out, targets) if do_apply and proved else None
        total += len(proved)
        applied += len(proved) if status == 'applied' else 0
        (out / 'probe.json').write_text(json.dumps({'source': source.relative_to(ROOT).as_posix(), 'tried': len(lines),
                                                    'compiled': 0 if code else len(keep), 'proved': proved,
                                                    'apply': status}, indent=1) + '\n')
        print(source.name, 'tried', len(lines), 'compiled', 0 if code else len(keep), 'proved', len(proved), status or '', flush=True)
    print('total proved', total, 'applied', applied)


if __name__ == '__main__':
    main()

"""Rewrite exact leaf mined packets onto a native class's real header.

A leaf packet (src/2008-06/ADDR.cpp) is a byte-exact stand-in method that only
reads/writes fields of `this` (no calls, no externs).  Everything needed for a
real definition is proven elsewhere:

  signature  closure symbol (mangled name) of that address
  offsets    compiler layout of the packet's struct (/d1reportAllClassLayout)
  members    compiler layout of the real header as the host native source sees it

Per row: packet field offsets -> host member at the same offset; rewrite the
body with those member names under the proven signature; append to a probe TU
`#include "<host>"` + definitions; drop lines the compiler rejects; keep a
line only if its own mangled symbol is byte-exact at its closure address.

--declare: a method the real class does not declare (C2039) gets its proven
non-virtual declaration added before the class's closing brace (no layout or
vtable change; refused when the name is already declared, so no overload set
changes).  The header edit is reverted unless a line using it is proven.
--apply appends kept lines to the host and keeps them (and header edits) only
if the host loses no exact symbol; else original bytes are restored.
No layout, offset or signature is invented: an unmapped offset blocks the row.

Caller must hold the host and header leases.  Never commits.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import rebuild  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
import native_template_probe as probe  # noqa: E402
from native_class_layout import parse  # noqa: E402

SRC = ROOT / 'src/2008-06'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
KW = {'if', 'return', 'while', 'for', 'switch', 'sizeof', 'else', 'do'}
DECL = re.compile(r'^(?:public|protected|private): (?:virtual )?(.*?)__thiscall (.+)::(\w+)\((.*)\)\s*(const)?\s*$')
BLOCK = '// Methods recovered from exact mined packets: field offsets mapped to this header by compiler layout.'
DECL_BLOCK = '// Declarations proven by closure symbols of byte-exact recovered methods.'
FOLDED = {a: {r['symbol'] for r in rows} for a, rows in
          json.loads((HERE / 'identity-names-by-address.json').read_text()).items()}
for _row in json.loads((HERE / 'claude-conversion-queue.json').read_text())['classes']:
    for _m in _row['methods']:
        FOLDED.setdefault(_m['addr'], set()).add(_m['symbol'])


def norm(t):
    return re.sub(r'\b(?:class|struct|enum|union) ', '', t).strip()


def leaf_rows(owner):
    queue = json.loads((HERE / 'claude-conversion-queue.json').read_text())['classes']
    row = next(r for r in queue if r['owner'] == owner)
    out = []
    for m in row['methods']:
        if m['state'] != 'convert' or not DECL.match(m['declaration']):
            continue
        path = SRC / ('%s.cpp' % m['addr'])
        if not path.exists():
            continue
        text = path.read_text(errors='replace')
        code = re.sub(r'//.*', '', text)
        if 'roc-lib' in text or 'extern' in code:
            continue
        found = re.search(r'(\w+)::(\w+)\s*\(([^)]*)\)\s*(const)?\s*\{(.*)\}', code, re.S)
        if not found:
            continue
        body = found[5].strip()
        # ponytail: body ends at the last brace; packets with a trailing namespace close keep one extra '}'
        if body.count('{') != body.count('}'):
            body = body[:body.rfind('}')].strip()
        if [w for w in re.findall(r'([A-Za-z_]\w*)\s*\(', body) if w not in KW]:
            continue
        # raw `this`+offset arithmetic or pointer casts carry no member identity (council gains review)
        if re.search(r'\(\s*(?:unsigned\s+)?(?:char|int|void|short|long)\s*\*+\s*\)|\bthis\s*\+|\breinterpret_cast\b', body):
            continue
        # ICF-folded body: one address, several symbols -> identity not proven by bytes
        if len(FOLDED.get(m['addr'], ())) > 1:
            continue
        out.append(dict(m, packet=path, struct=found[1], params=found[3], body=body))
    return out


def layout(source, folder, extra=()):
    folder.mkdir(parents=True, exist_ok=True)
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl',
                            list(extra) + ['/nologo', '/EHsc', '/Zs', '/d1reportAllClassLayout', str(source)], folder)
    return parse(log.replace('\r', ''))


def member_name(text):
    return text.split('[')[0].strip()


def rewrite(row, host_members, folder):
    classes = layout(row['packet'], folder)
    struct = next((v for k, v in classes.items() if k.split('::')[-1] == row['struct']), None)
    if struct is None:
        return None, 'packet-layout-missing'
    by_name = {member_name(m['name']): m['offset'] for m in struct['members'] if m['depth'] == 0}
    body = row['body']
    mapping = {}
    for name in [n for n in by_name if re.search(r'\b%s\b' % re.escape(n), body)]:
        target = [m for m in host_members if m['offset'] == by_name[name] and not m['name'].startswith('{vfptr}')
                  and not re.match(r'_*(?:pad|unknown|reserved|gap)', m['name'], re.I)]
        if not target:
            return None, 'no-host-member@0x%x' % by_name[name]
        target.sort(key=lambda m: m['depth'])
        mapping[name] = member_name(target[0]['name'])
    ret, owner, method, params, const = DECL.match(row['declaration']).groups()
    types = [norm(p) for p in re.split(r',(?![^<]*>)', params) if p.strip() and p.strip() != 'void']
    names = [re.findall(r'(\w+)\s*(?:\[[^\]]*\])?\s*$', p.strip())[0]
             for p in row['params'].split(',') if p.strip() and p.strip() != 'void']
    if len(names) != len(types):
        return None, 'param-count'
    for name in mapping:
        body = re.sub(r'\b%s\b' % re.escape(name), '__m_' + name, body)
    for name, real in mapping.items():
        body = body.replace('__m_' + name, real)
    body = re.sub(r'\b%s\b' % re.escape(row['struct']), owner.split('::')[-1], body)
    signature = '%s %s::%s(%s)%s' % (norm(ret), owner, method,
                                     ', '.join('%s %s' % (t, n) for t, n in zip(types, names)), ' const' if const else '')
    return ' '.join((signature + ' { ' + body + ' }').split()), None


def probe_loop(host, flags, lines, result, output):
    for row in result['rows']:
        if row['line'] and (row['blocked'] or '').startswith('compile'):
            row['blocked'] = None
    tu, compiled, code = output / 'probe.cpp', list(lines), 1
    for _ in range(60):
        tu.write_text('#include "%s"\n' % host.as_posix() + '\n'.join(l for l, _, _ in compiled) + '\n', encoding='utf-8')
        code, log, _ = probe.compile_tu(flags, tu, output / 'probe')
        bad = {int(n) for n in re.findall(r'probe\.cpp\((\d+)\)', log) if int(n) >= 2}
        for n in bad:
            row = next(r for r in result['rows'] if r['line'] == compiled[n - 2][0])
            row['blocked'] = 'compile: ' + next((l.split(': ', 1)[-1] for l in log.splitlines()
                                                  if 'probe.cpp(%d)' % n in l), '')[:160]
        if not code or not bad:
            break
        compiled = [c for i, c in enumerate(compiled, 2) if i not in bad]
    return code, compiled


def lease(path):
    """Take a claude-leaf lease on one file before editing it; False if someone else holds it."""
    rel = path.resolve().relative_to(ROOT).as_posix()
    name = 'claude-leaf-' + re.sub(r'\W+', '-', path.stem)
    done = subprocess.run(['cmd', '/c', str(ROOT / 'roc.cmd'), 'lease', 'take', name, rel, '--hours', '4'],
                          cwd=ROOT, capture_output=True, text=True)
    return done.returncode == 0


def restore(headers):
    for path, original in headers.items():
        path.write_bytes(original)


def add_declarations(owner, host, flags, rows, output):
    """Declare proven non-virtual members before the class's closing brace."""
    if not rows:
        return {}
    short = owner.split('::')[-1]
    _, log, _ = probe.compile_tu(flags + ['/Zs', '/showIncludes'], host, output / 'includes')
    included = [Path(l.split(':', 2)[2].strip()) for l in log.splitlines() if l.startswith('Note: including file:')]
    opener = re.compile(r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?%s\b[^;{()]*\{' % re.escape(short))
    for path in included:
        if 'native-headers' not in str(path) or not path.exists():
            continue
        raw = path.read_bytes()
        text = raw.decode('utf-8', errors='surrogateescape')
        found = opener.search(text)
        if not found:
            continue
        depth, at = 0, found.end() - 1
        for at in range(found.end() - 1, len(text)):
            depth += {'{': 1, '}': -1}.get(text[at], 0)
            if depth == 0:
                break
        body = text[found.end():at]
        at = text.rfind('\n', 0, at) + 1  # insert before the closing brace's line, keep its indent
        newline = '\r\n' if '\r\n' in text else '\n'
        decls = []
        for row in rows:
            access, rest = row['declaration'].split(': ', 1)
            ret, _, method, params, const = DECL.match(row['declaration']).groups()
            if rest.startswith('virtual') or re.search(r'\b%s\s*\(' % method, body):
                row['blocked'] = 'declaration: virtual or name already declared'
                continue
            params = ', '.join(norm(p) for p in re.split(r',(?![^<]*>)', params) if p.strip())
            decls.append('%s:%s    %s %s(%s)%s;' % (access, newline, norm(ret), method, params, ' const' if const else ''))
        if not decls:
            return {}
        if not lease(path):
            for row in rows:
                row['blocked'] = 'declaration: header leased by another worker'
            return {}
        block = newline + DECL_BLOCK + newline + newline.join(decls) + newline
        path.write_bytes((text[:at] + block + text[at:]).encode('utf-8', errors='surrogateescape'))
        return {path: raw}
    for row in rows:
        row['blocked'] = 'declaration: class definition not found in included native-headers'
    return {}


def host_for(owner):
    short = owner.split('::')[-1]
    best = None
    for path in CLASSES.glob('*.cpp'):
        n = len(re.findall(r'\b%s::\w+\s*\(' % re.escape(short), path.read_text(errors='replace')))
        if n and (best is None or n > best[0]):
            best = (n, path)
    return best[1] if best else None


def run(owner, output, apply_it, declare):
    targets, check = Targets('2008-06'), probe.runner()
    rows = leaf_rows(owner)
    host = host_for(owner)
    result = {'owner': owner, 'leaf_rows': len(rows), 'host': host and host.relative_to(ROOT).as_posix(), 'rows': []}
    if not rows or not host:
        result['blocked'] = 'no host native source' if rows else 'no leaf rows'
        return result
    flags = probe.flags_for(check, host, output)
    host_layout = layout(host, output / 'host-layout', [f for f in flags if f.startswith(('/I', '/D'))])
    # the layout dump names classes without namespace; short-name collisions are caught by the byte gate
    members = (host_layout.get(owner) or host_layout.get(owner.split('::')[-1]) or {}).get('members', [])
    if not members:
        result['blocked'] = 'host layout lacks %s' % owner
        return result
    lines = []
    for row in rows:
        line, why = rewrite(row, members, output / 'packet' / row['addr'])
        result['rows'].append({'addr': row['addr'], 'symbol': row['symbol'], 'declaration': row['declaration'],
                               'line': line, 'blocked': why})
        if line:
            lines.append((line, row['symbol'], row['addr']))
    code, _, _ = probe.compile_tu(flags, host, output / 'baseline')
    if code:
        result['blocked'] = 'host does not compile'
        return result
    base = probe.exact((output / 'baseline/candidate.obj').read_bytes(), targets)
    code, compiled = probe_loop(host, flags, lines, result, output)
    headers = {}
    if declare:
        wanted = [r for r in result['rows'] if (r['blocked'] or '').startswith('compile: error C2039')
                  and "'%s' : is not a member" % DECL.match(r['declaration'])[3] in r['blocked']]
        headers = add_declarations(owner, host, flags, wanted, output)
        if headers:
            code, compiled = probe_loop(host, flags, lines, result, output)
    result['declared'] = sorted(p.relative_to(ROOT).as_posix() for p in headers)
    if code or not compiled:
        result['proved'] = 0
        restore(headers)
        return result
    grown = probe.exact((output / 'probe/candidate.obj').read_bytes(), targets)
    kept = [c for c in compiled if grown.get(c[1]) == [c[2]]]
    for c in compiled:
        row = next(r for r in result['rows'] if r['line'] == c[0])
        row['blocked'] = None if c in kept else 'compiled, not byte-exact at %s' % c[2]
    result['proved'] = len(kept)
    if not apply_it or not kept:
        restore(headers)
        return result
    if not lease(host):
        restore(headers)
        result.update(applied=False, blocked='host leased by another worker')
        return result
    original = host.read_bytes()
    newline = b'\r\n' if b'\r\n' in original else b'\n'
    tail = newline.join([b'', BLOCK.encode()] + [l.encode() for l, _, _ in kept]) + newline
    host.write_bytes(original.rstrip(b'\r\n') + newline + tail)
    code, _, _ = probe.compile_tu(flags, host, output / 'after')
    after = {} if code else probe.exact((output / 'after/candidate.obj').read_bytes(), targets)
    lost = sorted(s for s, a in base.items() if sorted(after.get(s, [])) != sorted(a))
    proven = [c for c in kept if after.get(c[1]) == [c[2]]]
    if code or lost or len(proven) != len(kept):
        host.write_bytes(original)
        restore(headers)
        result.update(applied=False, reverted=True, lost=lost[:20], compile_failed=bool(code))
    else:
        result.update(applied=True, addresses=[a for _, _, a in proven])
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('owners', nargs='+')
    ap.add_argument('--output', type=Path, default=HERE / 'claude-leaf-rewrite')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--declare', action='store_true', help='add missing non-virtual declarations to the real header')
    args = ap.parse_args()
    for owner in args.owners:
        folder = args.output.resolve() / re.sub(r'\W+', '_', owner)
        result = run(owner, folder, args.apply, args.declare)
        folder.mkdir(parents=True, exist_ok=True)
        (folder / 'leaf.json').write_text(json.dumps(result, indent=1) + '\n')
        tally = {}
        for r in result['rows']:
            key = (r['blocked'] or 'proved').split(':')[0].split('@')[0]
            if 'already has a body' in (r['blocked'] or ''):
                key = 'inline-in-header'
            tally[key] = tally.get(key, 0) + 1
        print(json.dumps({k: result.get(k) for k in ('owner', 'host', 'leaf_rows', 'proved', 'declared', 'applied', 'blocked', 'lost')}),
              tally, flush=True)


if __name__ == '__main__':
    main()

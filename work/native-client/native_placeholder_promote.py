"""Promote placeholder-lane exacts (placeholder-lane/results.json) into native source.
  member: the INFERRED declaration goes into the owner class of its real native header (leased), the body into a new
          rebuild/2008-06/native-classes/Inferred_<addr>.cpp that includes that header;
  free:   Inferred_<addr>.cpp with the native headers the body names.
Each new TU is re-proved standalone (native-bulk, closure evidence); a TU that is not exact is deleted and its header
edit reverted.  Serial (header edits).  Promoted rows: placeholder-lane/promoted.json.  Then register the new TUs into
the census: python work/native-client/prove.py --quiet --rounds 2 <files>.
Usage: python native_placeholder_promote.py [--limit N]"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

ARGS = sys.argv[1:]
sys.argv = sys.argv[:1]
import native_llm as m              # noqa: E402
import native_creator_gate as cg    # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--retry-missing', action='store_true', help='only rows that failed re-proof before')
args = ap.parse_args(ARGS)
ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
LANE = ROOT / 'work/native-client/placeholder-lane'
DONE = LANE / 'promoted.json'
done = json.loads(DONE.read_text()) if DONE.is_file() else {}
FLAGS = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL'


def roc(*a):
    return subprocess.run([str(ROOT / 'roc.cmd'), *a], cwd=ROOT, capture_output=True, text=True)


def last_body(addr):
    tries = sorted((LANE / addr).glob('try*.cpp'))
    for t in reversed(tries):
        code = re.findall(r'```(?:cpp|c\+\+)\s*\n(.*?)```', t.read_text(errors='replace'), re.S)
        if code:
            return code[-1]
    return None


def insert_decl(header, cls, decl, addr):
    text = header.read_text(errors='replace')
    if 'sub_%s' % addr in text:
        return text, text
    leaf = cls.split('::')[-1]
    found = re.search(r'^[ \t]*(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text, re.M)
    if not found:
        return text, None
    depth, end = 0, found.end() - 1
    for end in range(found.end() - 1, len(text)):
        depth += {'{': 1, '}': -1}.get(text[end], 0)
        if depth == 0:
            break
    start = text.rfind('\n', 0, end) + 1                 # insert before the closing brace's own line, keep its indent
    if text[start:end].strip():
        start = end
    indent = re.match(r'[ \t]*', text[found.start():]).group(0)
    line = '%spublic:\n%s\t%s   // INFERRED: %s, placeholder name (identity tier), body byte-proved (Inferred_%s.cpp)\n' % (
        indent, indent, decl.strip(), addr, addr)
    return text, text[:start] + line + text[start:]


def from_probe(addr):
    """Free-function TU from the probe the lane actually proved (placeholder-lane/<addr>/probe.cpp): its includes and
    /I roots, made repo-relative ({headers} token), and its body.  The last try file alone loses the includes the lane
    resolved (vendor/App headers), so ~60 exacts failed re-proof as 'reproof-missing'."""
    probe = LANE / addr / 'probe.cpp'
    if not probe.is_file():
        return None
    text = probe.read_text(errors='replace')
    first, rest = text.split('\n', 1)
    if not first.startswith('// native-flags:'):
        return None
    hdr = HEADERS.as_posix()
    root = ROOT.as_posix()

    def rel_dir(path):
        q = Path(path).as_posix()
        if q.lower().startswith(hdr.lower()):
            return '{headers}' + q[len(hdr):]
        if q.lower().startswith(root.lower()):
            return '{headers}/../../..' + q[len(root):]
        return None
    flags, idirs = [], []
    for tok in first[len('// native-flags:'):].split():
        if tok.startswith('/I') and '/shadow' in Path(tok[2:]).as_posix():
            continue                           # private header copy with the inferred declaration (promote edits the real one)
        if tok.startswith('/I'):
            r = rel_dir(tok[2:])
            if r is None:
                return None
            if not r.startswith('{headers}') or r != '{headers}':
                flags.append('/I' + r)
            idirs.append(Path(tok[2:]).as_posix())
        else:
            flags.append(tok)
    includes = []
    for inc in re.findall(r'^#include "([^"]+)"', rest, re.M):
        q = Path(inc).as_posix()
        if q.lower().startswith(hdr.lower() + '/'):
            includes.append(q[len(hdr) + 1:])
            continue
        if '/include/' in q:                   # vendor tree (g3d, boost, ...): the compiler profile has these roots
            includes.append(q.rsplit('/include/', 1)[1])
            continue
        base = next((d for d in sorted(idirs, key=len, reverse=True) if q.lower().startswith(d.lower() + '/')), None)
        if base is None:                       # header outside every /I root: add its folder as one
            r = rel_dir(str(Path(q).parent))
            if r is None:
                return None
            flags.append('/I' + r)
            includes.append(Path(q).name)
        else:
            includes.append(q[len(base) + 1:])
    body = re.sub(r'^#include .*$', '', rest, flags=re.M).strip()
    return ' '.join(flags), includes, body


def promote_probe(addr, flags, includes, body):
    if m.invented_externs(body) or m.OFFSET_HACK.search(body):
        return 'no-clean-body'
    tu = CLASSES / ('Inferred_%s.cpp' % addr)
    lease = 'inferred-%s' % addr
    if roc('lease', 'take', lease, tu.relative_to(ROOT).as_posix(), '--hours', '1').returncode:
        return 'blocked-lease'
    try:
        named = 'sub_' + addr not in body
        note = ('// %08x: real name from the identity registry; body byte-proved against the native headers (named lane)'
                % int(addr, 16) if named else
                '// INFERRED: sub_%s (placeholder name for %08x from the identity tier; body byte-proved by the placeholder '
                'lane, includes as the lane resolved them)' % (addr, int(addr, 16)))
        tu.write_text('// native-flags: %s\n%s\n%s\n%s\n' % (flags, note, ''.join('#include "%s"\n' % i for i in includes), body))
        needle = 'sub_' + addr
        if named:
            real = (m.load_registry().get(addr) or {}).get('name') or ''
            hit = re.match(r'\?(\w+)@', real)
            needle = hit.group(1) if hit else needle
        work = LANE / addr / 'promote'
        sym = cg.discover_symbol(work, [str(tu)], '', addr, needle)
        status = cg.gate_code(work, [str(tu)], '', {addr: sym})[0][addr] if sym else 'missing'
        if status != 'inactive_exact':
            tu.unlink(missing_ok=True)
            return 'reproof-' + status
        return 'promoted'
    finally:
        roc('lease', 'release', lease)


def promote(addr, row):
    probe = from_probe(addr)
    if probe and not (row.get('class') and row.get('decl')):   # free function: exactly the source the lane proved
        return promote_probe(addr, *probe)
    body = last_body(addr)
    if probe:                                   # member: the proved body and its resolved includes; decl goes below
        body = ''.join('#include "%s"\n' % i for i in probe[1]) + probe[2]
        row = dict(row, flags=row.get('flags') or probe[0])
    if not body or m.invented_externs(body) or m.OFFSET_HACK.search(body):
        return 'no-clean-body'
    # Keep the answer's includes the lane compiled with: native ones by tree path, SDK/vendor (<boost/...>, afxwin.h) as is.
    model_inc = re.findall(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', body, re.M)
    sdk = ''.join('#include <%s>\n' % i for i in model_inc if not (HEADERS / i).is_file())
    native_inc = [i for i in model_inc if (HEADERS / i).is_file()]
    body = re.sub(r'^\s*#\s*include\s*[<"][^>"]+[>"].*$', '', body, flags=re.M)
    cls, decl = row.get('class') or '', row.get('decl') or ''
    tu = CLASSES / ('Inferred_%s.cpp' % addr)
    lease = 'inferred-%s' % addr
    globs = [tu.relative_to(ROOT).as_posix()]
    header = None
    if cls and decl:
        path = m.declaring_header(cls)
        header = Path(path) if path and Path(path).is_relative_to(HEADERS) else None
        if not header:
            return 'no-header'
        globs.append(header.relative_to(ROOT).as_posix())
        includes = [header.relative_to(HEADERS).as_posix()]
    else:
        includes = [Path(h).relative_to(HEADERS).as_posix() for h in
                    (m.declaring_header(c) for c in dict.fromkeys(re.findall(r'\b(RBX::\w+(?:::\w+)?)', body)))
                    if h and Path(h).is_relative_to(HEADERS)][:4] or ['util/Name.h']
    taken = roc('lease', 'take', lease, *globs, '--hours', '1')
    if taken.returncode:
        return 'blocked-lease'
    old = None
    try:
        if header:
            old, new = insert_decl(header, cls, decl, addr)
            if new is None:
                return 'class-not-found'
            header.write_text(new)
        includes += [i for i in native_inc if i not in includes]
        text = sdk + ''.join('#include "%s"\n' % i for i in includes)
        guards = sorted(set(re.findall(r'^\s*#\s*ifdef\s+(NATIVE_\w+)', ''.join(
            (HEADERS / i).read_text(errors='replace') for i in includes if (HEADERS / i).is_file()), re.M)))
        named = 'sub_' + addr not in body          # --named lane: the real registry name, not a placeholder
        note = ('// %08x: real name from the identity registry; body byte-proved against the native headers (named lane)'
                % int(addr, 16) if named else
                '// INFERRED: %s (placeholder name for %08x from the identity tier; body byte-proved against the native '
                'headers by the placeholder lane)' % ((cls + '::' if cls else '') + 'sub_' + addr, int(addr, 16)))
        tu.write_text('// native-flags: %s%s\n%s\n%s%s\n%s\n'
                      % (row.get('flags') or FLAGS, ''.join(' /D' + g for g in guards), note,
                         ''.join('#define %s\n' % g for g in guards), text, body.strip()))
        work = LANE / addr / 'promote'
        needle = 'sub_' + addr
        if named:
            real = (m.load_registry().get(addr) or {}).get('name') or ''
            needle = re.match(r'\?(\w+)@', real).group(1) if re.match(r'\?(\w+)@', real) else needle
        sym = cg.discover_symbol(work, [str(tu)], '', addr, needle)
        status = cg.gate_code(work, [str(tu)], '', {addr: sym})[0][addr] if sym else 'missing'
        if status != 'inactive_exact':
            tu.unlink(missing_ok=True)
            if header and old is not None:
                header.write_text(old)
            return 'reproof-' + status
        return 'promoted'
    finally:
        roc('lease', 'release', lease)


results = json.loads((LANE / 'results.json').read_text())
verdict = {}
for r in map(m._json, m.LOG.read_text(encoding='utf-8').splitlines()):
    if r and r.get('status') in ('inactive_exact', 'retracted'):
        verdict[r['addr']] = r['status']          # latest wins: a fresh honest exact supersedes a retraction
retracted = {a for a, s in verdict.items() if s == 'retracted'}
todo = [(a, r) for a, r in results.items() if r['status'] == 'inactive_exact' and a not in retracted and done.get(a) != 'promoted'
        and not (args.retry_missing and done.get(a) not in ('reproof-missing', 'reproof-draft'))]
todo = todo[:args.limit or None]
print('placeholder exacts to promote', len(todo), flush=True)
for addr, row in todo:
    done[addr] = promote(addr, row)
    DONE.write_text(json.dumps(done, indent=1))
    print(addr, row.get('class') or 'free', done[addr], flush=True)
print({s: list(done.values()).count(s) for s in set(done.values())})

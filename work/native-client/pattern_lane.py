"""Pattern lane for tiny functions (no model calls).  A remaining function of <= 32 bytes whose assembly is a plain
accessor - `mov eax,[ecx+N]; ret`, `mov al/ax,[ecx+N]`, `lea eax,[ecx+N]; ret`, `fld [ecx+N]; ret`, or a setter
`mov eax,[esp+4]; mov [ecx+N],eax; ret 4` - is tried against every data member of its class (one judge per candidate, in a private copy of the class header);
the first candidate whose bytes equal the original wins (real symbol), so promotion works as for model answers.
Hits: pattern-lane-hits.json (merged by `lane_runner.py promote`) + placeholder-lane/<addr>/try9.cpp.
  python work/native-client/pattern_lane.py [--jobs 8]"""
import argparse
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=8)
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'pattern', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.regate:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, ROOT, OUT, HEADERS, results = lane['m'], lane['ROOT'], lane['OUT'], lane['HEADERS'], lane['results']
reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
inferred = json.loads((HERE / 'unnamed-identities-inferred.json').read_text())

GETTER = re.compile(r'^(?:mov|movzx|movsx) (?:eax|al|ax), (?:byte|word|dword) ptr \[ecx \+ (0x[0-9a-f]+)\]$')
LEA = re.compile(r'^lea eax, \[ecx \+ (0x[0-9a-f]+)\]$')
FLD = re.compile(r'^fld (?:dword|qword) ptr \[ecx \+ (0x[0-9a-f]+)\]$')
SETTER = re.compile(r'^mov (?:dword|byte|word) ptr \[ecx \+ (0x[0-9a-f]+)\], (?:eax|al|ax|edx)$')


def shape(addr):
    asm = lane['target_asm'](addr)
    ins = [re.sub(r'\s+', ' ', l.split('  ', 1)[1].split(';')[0].strip()) for l in asm.splitlines()
           if re.match(r'^[0-9a-f]{8}\s', l)]
    ins = [i for i in ins if i and i != 'int3' and i != 'nop']
    if len(ins) == 2 and ins[1] == 'ret':
        for kind, pat in (('get', GETTER), ('ref', LEA), ('getf', FLD)):
            hit = pat.match(ins[0])
            if hit:
                return kind
    if len(ins) == 3 and ins[0].startswith('mov eax, dword ptr [esp + 4]') and SETTER.match(ins[1]) and ins[2].startswith('ret'):
        return 'set'
    return None


def members(text, leaf):
    found = re.search(r'(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text)
    if not found:
        return []
    depth, out, i = 1, [], found.end()
    body_start = i
    while i < len(text) and depth:
        depth += {'{': 1, '}': -1}.get(text[i], 0)
        i += 1
    body = text[body_start:i - 1]
    flat = re.sub(r'\{[^{}]*\}', ';', body)                      # drop inline bodies
    for decl in flat.split(';'):
        decl = re.sub(r'//[^\n]*', '', decl).strip()
        decl = re.sub(r'^(?:public|private|protected)\s*:\s*', '', decl)
        if not decl or '(' in decl or decl.startswith(('typedef', 'friend', 'enum', 'class', 'struct', 'using', 'static')):
            continue
        hit = re.match(r'^(?:mutable\s+)?([\w:<>,\s\*&]+?)\s*\b(\w+)\s*(?:\[\d+\])?$', decl)
        if hit and not hit.group(1).strip().endswith(('public', 'private', 'protected')):
            out.append((hit.group(1).strip(), hit.group(2)))
    return out


def run(addr):
    kind = shape(addr)
    if not kind:
        return addr, 'not-a-pattern'
    row = results.get(addr, {})
    cls = row.get('class') or (reg.get(addr) or {}).get('owner_class') or ''
    if not cls:
        name = (inferred.get(addr) or {}).get('name') or ''
        hit = re.match(r'\?\w+@(\w+)@((?:\w+@)*)@', name)
        if hit:
            cls = '::'.join([p for p in hit.group(2).split('@') if p][::-1] + [hit.group(1)])
    if not cls:
        return addr, 'no-class'
    header = lane['class_header'](cls)
    if not header or not Path(header).is_relative_to(HEADERS):
        return addr, 'no-header'
    fields = members(Path(header).read_text(errors='replace'), cls.rsplit('::', 1)[-1])
    if not fields:
        return addr, 'no-members'
    name = (reg.get(addr) or {}).get('name') or ''
    real = re.match(r'\?(\w+)@', name) if name and not name.startswith(('func_', 'sub_')) else None
    fn = real.group(1) if real else 'sub_' + addr
    for typ, mem in fields[:60]:
        if kind == 'get':
            decl, body = '%s %s() const;' % (typ, fn), '%s %s::%s() const { return %s; }' % (typ, cls, fn, mem)
        elif kind == 'getf':
            if typ not in ('float', 'double'):
                continue
            decl, body = '%s %s() const;' % (typ, fn), '%s %s::%s() const { return %s; }' % (typ, cls, fn, mem)
        elif kind == 'ref':
            decl, body = 'const %s& %s() const;' % (typ, fn), 'const %s& %s::%s() const { return %s; }' % (typ, cls, fn, mem)
        else:
            decl, body = 'void %s(%s v);' % (fn, typ), 'void %s::%s(%s v) { %s = v; }' % (cls, fn, typ, mem)
        reply = 'CLASS: %s\n```decl\n%s\n```\n```cpp\n%s\n```' % (cls, decl, body)
        try:
            status, detail, c2, d2 = lane['judge'](OUT / addr, addr, reply, body)
        except Exception:                                            # noqa: BLE001
            continue
        if status == 'inactive_exact':
            (OUT / addr).mkdir(parents=True, exist_ok=True)
            (OUT / addr / 'try9.cpp').write_text(reply)
            return addr, 'inactive_exact', cls, decl
    return addr, 'no-member-matched'


targets = sorted([a for a, v in cl.items() if v['size'] <= 32 and v['bucket'] != 'vendor-library'], key=lambda a: cl[a]['size'])
print('pattern candidates: %d' % len(targets), flush=True)
hits_path = HERE / 'pattern-lane-hits.json'
hits = json.loads(hits_path.read_text()) if hits_path.is_file() else {}
counts = {}
with ThreadPoolExecutor(args.jobs) as pool:
    for res in pool.map(run, targets):
        addr, status = res[0], res[1]
        counts[status] = counts.get(status, 0) + 1
        if status == 'inactive_exact':
            hits[addr] = {'cls': res[2], 'decl': res[3], 'model': 'pattern-lane'}
            hits_path.write_text(json.dumps(hits, indent=1))
            print('  %s exact (%s)' % (addr, res[2]), flush=True)
print('RESULT pattern lane: %s' % counts, flush=True)

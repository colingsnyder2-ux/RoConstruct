"""No-model analog -> native converter.  A server-exact mined analog declares a placeholder receiver
`struct S { char pad[0x1c]; T field; ... }` and defines `R S::f(args) {...}`.  When the registry names the function
`Owner::name(sig)` and Owner has a native header whose compiler layout has a member at every offset the analog touches,
rewrite mechanically: drop S, `S::f` -> `Owner::name` (registry return/param types, analog param names), field -> member.
Gate with native_placeholder_llm.compile_and_gate (decorated symbol must equal the registry's) and keep only
inactive_exact.  Scratch: work/native-client/analog-convert/.  Exacts -> rebuild/.../AnalogConv_<addr>.cpp.
  python work/native-client/analog_convert.py [--survey] [--limit N] [--jobs J] [--max-structs K]"""
import argparse
import collections
import json
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--survey', action='store_true', help='classify only, no compiles')
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=6)
ap.add_argument('--addr', action='append', default=[])
ARGS = ap.parse_args()
LOCK = HERE / 'prove-out/CENSUS.lock'
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parents[1]))
import ast, os, types, argparse as _ap   # noqa: E401,E402
import native_llm as _m                  # noqa: E402
import native_creator_gate as _cg        # noqa: E402


def _load_lane():
    """native_placeholder_llm has no __main__ guard (importing it RUNS the model lane): exec only its helper defs."""
    src = (HERE / 'native_placeholder_llm.py').read_text()
    keep = [n for n in ast.parse(src).body if n.lineno < 570 and n.lineno not in (22, 23, 28, 29, 30, 31, 32, 34, 35, 36, 45)
            and not (isinstance(n, ast.Expr) and n.lineno == 40)]
    mod = types.ModuleType('pl_helpers')
    mod.__dict__.update(m=_m, cg=_cg, sys=sys, os=os, re=re, json=json, Path=Path, collections=collections, time=time,
                        ARGS=[], args=_ap.Namespace(limit=0, jobs=1, max_size=8192, named='', polish=False, regate=False),
                        results_store=None, results={})
    import subprocess
    mod.subprocess = subprocess
    exec(compile(ast.Module(keep, []), 'pl_helpers', 'exec'), mod.__dict__)
    return mod


pl = _load_lane()
import native_class_layout as ncl     # noqa: E402
from roc import rebuild, integration_site  # noqa: E402
m = pl.m
ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
OUT = HERE / 'analog-convert'
OUT.mkdir(exist_ok=True)
SIZES = {'char': 1, 'bool': 1, 'unsigned char': 1, 'short': 2, 'unsigned short': 2, 'int': 4, 'unsigned': 4,
         'unsigned int': 4, 'long': 4, 'unsigned long': 4, 'float': 4, 'double': 8, '__int64': 8}


def match_brace(text, i):
    d = 0
    for k in range(i, len(text)):
        d += {'{': 1, '}': -1}.get(text[k], 0)
        if d == 0:
            return k
    return -1


def split_top(s, sep):
    out, d, cur = [], 0, ''
    for ch in s:
        d += {'<': 1, '>': -1, '(': 1, ')': -1, '{': 1, '}': -1}.get(ch, 0)
        if ch == sep and d == 0:
            out.append(cur)
            cur = ''
        else:
            cur += ch
    return out + ([cur] if cur.strip() else [])


def parse_struct(text):
    """-> (struct name, start, end, {field: (offset, type)}, [reasons]) for the one placeholder struct."""
    found = list(re.finditer(r'(?:^|(?<=[;}\s]))(?:struct|class)\s+(\w+)\s*\{', text, re.M))
    owners = [x for x in found if re.search(r'\b%s::~?\w+\s*\(' % x.group(1), text)]
    if len(owners) != 1:
        return None, 'receiver-structs=%d' % len(owners)
    if len(found) != 1:
        return None, 'extra-placeholder-structs=%d' % (len(found) - 1)
    f = owners[0]
    end = match_brace(text, f.end() - 1)
    end += 1 + (1 if text[end + 1:end + 2] == ';' else 0)
    body = text[f.end():end - 2]
    fields, off, virt = {}, 0, 'virtual' in body
    if virt:
        off = 4
    for decl in split_top(body, ';'):
        d = re.sub(r'\b(?:public|private|protected)\s*:', '', decl).strip()
        if not d or '(' in d:
            continue
        pad = re.match(r'(?:unsigned\s+)?char\s+\w+\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]$', d)
        if pad:
            off += int(pad.group(1), 0)
            continue
        fm = re.match(r'(.+?)[\s*&]+(\w+)(?:\s*\[\s*(\w+)\s*\])?$', d.replace('*', '* '))
        if not fm:
            return None, 'unparsed-field'
        t = fm.group(1).strip()
        size = 4 if '*' in d or '&' in d else SIZES.get(t)
        if not size:
            return None, 'unknown-field-type'
        if fm.group(3):
            return None, 'array-field'
        off = (off + size - 1) // size * size
        fields[fm.group(2)] = (off, d)
        off += size
    return (f.group(1), f.start(), end, fields), None


def cxx(t):
    t = re.sub(r'\b(?:class|struct|enum|union) ', '', t)
    return re.sub(r'\s+', ' ', t).strip()


def parse_sig(sig):
    """registry undecorated signature -> (ret, qualified name, [param types], const, static)."""
    s = re.sub(r'\b(?:public|protected|private):', '', sig)
    static = 'static ' in s
    s = re.sub(r'\b(?:virtual|static|__thiscall|__cdecl|__stdcall|__fastcall)\b', '', s).strip()
    p = s.find('(')
    # the qualified name starts after the last space before '(' at template depth 0
    head, depth, cut = s[:p], 0, 0
    for i, ch in enumerate(head):
        depth += {'<': 1, '>': -1}.get(ch, 0)
        if ch == ' ' and depth == 0:
            cut = i
    ret, name = head[:cut].strip(), head[cut:].strip()
    close = s.rfind(')')
    params = [cxx(x) for x in split_top(s[p + 1:close], ',') if x.strip() and x.strip() != 'void']
    return cxx(ret), name, params, 'const' in s[close:], static


def layout_for(header):
    """compiler layout {qualified class: {offset: member}} for HEADER (cached)."""
    key = Path(header).relative_to(HEADERS).as_posix().replace('/', '_') + '.v2'
    cache = OUT / 'layouts' / (key + '.json')
    if cache.is_file():
        return json.loads(cache.read_text())
    cache.parent.mkdir(exist_ok=True)
    probe = cache.with_suffix('.cpp')
    probe.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL\n#include "%s"\n' % Path(header).resolve().as_posix())
    flags = [f for f in ncl.runner().compiler_flags(probe) if f != '/c']
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Zs', '/d1reportAllClassLayout', str(probe)], cache.parent)
    (cache.with_suffix('.log')).write_text(log)
    classes = {k: v for k, v in ncl.parse(log).items()}
    out = {}
    for k, v in classes.items():
        out.setdefault(k, {'size': v['size'], 'members': []})
        out[k]['members'] = [mm for mm in v['members'] if mm['depth'] <= 1 or True]
    cache.write_text(json.dumps({'exit': code, 'classes': out}))
    return {'exit': code, 'classes': out}


def member_at(layout, owner, offset):
    """member name whose offset equals OFFSET in OWNER's compiler layout (leaf-name matching for qualified owners)."""
    leaf = owner.split('::')[-1]
    for name, row in layout['classes'].items():
        if name.split('::')[-1] == leaf and (owner in name or True):
            hits = [mm for mm in row['members'] if mm['offset'] == offset and not mm['name'].startswith(('{vfptr', '{vbptr', '<'))
                    and not re.search(r'\bchar \w+\[\d+\]$', '')]
            if hits:
                nm = re.search(r'(\w+)(?:\[\d+\])?$', hits[0]['name'])
                return nm.group(1) if nm else None, row['size']
    return None, 0


def convert(addr, reg_row, header):
    """-> (code, reasons) mechanical rewrite or (None, reason)."""
    text = (ROOT / 'src/2008-06' / (addr + '.cpp')).read_text(errors='replace')
    if re.search(r'^\s*namespace\b', text, re.M):
        return None, 'analog-namespaced'
    st, why = parse_struct(text)
    if not st:
        return None, why
    sname, s0, s1, fields = st[0], st[1], st[2], st[3]
    defs = list(re.finditer(r'(?m)^([\w:<>\s\*&]*?)\b%s::(~?\w+)\s*\(([^)]*)\)\s*(const)?\s*\{' % sname, text))
    if len(defs) != 1:
        return None, 'target-defs=%d' % len(defs)
    d = defs[0]
    ret, qname, params, const, static = parse_sig(reg_row['signature'])
    owner = reg_row['owner_class']
    aparams = [x for x in split_top(d.group(3), ',') if x.strip() and x.strip() != 'void']
    if len(aparams) != len(params):
        return None, 'param-count %d vs %d' % (len(aparams), len(params))
    names = [(re.search(r'(\w+)\s*(?:\[\d*\])?$', x) or [None, 'a%d' % i])[1] for i, x in enumerate(aparams)]
    # an unnamed analog parameter is just a type: the name is that type word -> use a%d
    names = [n if n not in SIZES and n not in ('void', 'int') else 'a%d' % i for i, n in enumerate(names)]
    layout = layout_for(header)
    if layout.get('exit') not in (0, None) and not layout['classes']:
        return None, 'layout-compile-failed'
    mapped = {}
    for fname, (off, _) in fields.items():
        member, _ = member_at(layout, owner, off)
        if not member:
            return None, 'no-member-at-0x%x' % off
        mapped[fname] = member
    leaf = qname.split('::')[-1]
    plist = ', '.join('%s %s' % (t, n) for t, n in zip(params, names))
    head = '%s %s::%s(%s)%s' % (ret, owner, leaf, plist, ' const' if const else '')
    end = match_brace(text, d.end() - 1)
    body = text[d.end() - 1:end + 1]
    for fname, member in mapped.items():
        body = re.sub(r'\b%s\b' % re.escape(fname), member, body)
    for old, new in zip([re.search(r'(\w+)\s*(?:\[\d*\])?$', x)[1] for x in aparams if re.search(r'\w+\s*$', x)], names):
        pass
    rest = (text[:s0] + text[s1:d.start()] + text[end + 1:])
    rest = re.sub(r'^//.*$', '', rest, flags=re.M).strip()
    return ('%s\n%s\n%s\n' % (rest, head, body)).lstrip(), None


def main():
    reg = m.load_registry()
    ina = integration_site.inactive_code(ROOT)
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    rem = [a for a in sorted(cl) if not (ina.get(a) and ina[a][1])]
    stats, rows = collections.Counter(), {}
    jobs = []
    for a in (ARGS.addr or rem):
        r = reg.get(a) or {}
        oc, sig = r.get('owner_class') or '', r.get('signature') or ''
        src = ROOT / 'src/2008-06' / (a + '.cpp')
        if not src.is_file():
            stats['no-analog'] += 1
            continue
        text = src.read_text(errors='replace')
        padded = bool(re.search(r'\bchar\s+\w+\s*\[', text))
        if not oc or oc == '>' or '::' not in sig and not sig:
            stats['no-owner'] += 1
            continue
        h = pl.class_header(oc)
        if not h:
            stats['owner-no-header'] += 1
            continue
        if not padded:
            stats['no-pad-struct'] += 1
            continue
        stats['qualified-pad+header'] += 1
        n = len(re.findall(r'^[ \t]*(?:struct|class)\s+\w+\s*\{', text, re.M))
        stats['qualified-1struct' if n == 1 else 'qualified-%dstructs' % n] += 1
        if True:
            jobs.append((len(text), a, r, h))
    print('survey', dict(stats), flush=True)
    jobs.sort(key=lambda j: j[0])
    jobs = jobs[:ARGS.limit or None]
    if ARGS.survey:
        return
    res_path = OUT / 'results.json'
    results = json.loads(res_path.read_text()) if res_path.is_file() else {}

    def one(job):
        _, a, r, h = job
        try:
            code, why = convert(a, r, h)
        except Exception as e:                 # noqa: BLE001
            return a, 'convert-error', repr(e)[:200], None
        if not code:
            return a, 'unmappable', why, None
        (OUT / ('%s.cpp' % a)).write_text(code)
        invented = m.invented_externs(code)
        if invented:
            return a, 'invented-extern', ','.join(invented), code
        if re.search(r'\b\w*pad\w*\s*\[', code) or m.OFFSET_HACK.search(code):
            return a, 'offset-hack', '', code
        sig = r['signature']
        pl.NAMED[a] = (r['name'], sig)
        try:
            st, detail = pl.compile_and_gate(OUT / 'work' / a, [str(h)], code, a)
        except Exception as e:                 # noqa: BLE001
            return a, 'gate-error', repr(e)[:200], code
        return a, st, (detail or '')[:300], code

    counts = collections.Counter()
    with ThreadPoolExecutor(ARGS.jobs) as pool:
        for a, st, detail, code in pool.map(one, jobs):
            counts[st] += 1
            results[a] = {'status': st, 'detail': detail, 'class': reg[a]['owner_class']}
            res_path.write_text(json.dumps(results, indent=1))
            print(a, st, detail.replace('\n', ' ')[:140], flush=True)
            if st == 'inactive_exact':
                for _ in range(90):
                    if not LOCK.is_file():
                        break
                    time.sleep(60)
                if LOCK.is_file():
                    results[a]['detail'] += ' (census lock: not written)'
                    continue
                tu = CLASSES / ('AnalogConv_%s.cpp' % a)
                inc = '#include "%s"\n' % Path(pl.class_header(reg[a]['owner_class'])).relative_to(HEADERS).as_posix()
                tu.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL\n// %s %s: mechanical analog rewrite '
                              '(analog_convert.py), byte-proved standalone\n%s%s' % (a, reg[a]['name'][:100], inc, code))
    print('RESULT', dict(counts), flush=True)


main()

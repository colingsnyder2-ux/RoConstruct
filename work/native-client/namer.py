"""Authentic 2008 address -> mangled name, from the native headers only (no guessing, no LLM).
A header comment ties Class::member to an address (addrmap.scan_all). Compiling
    template<class T> void use(T) {}   ...   use(&Class::member);
against that real header makes the compiler emit the exact decorated name as an undefined external.
Overloaded, private or ctor/dtor members fail to compile and are skipped (reported).
usage: python work/native-client/namer.py   -> link/names.json {addr: mangled}"""
import json, re, sys, collections
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[1]))
sys.path.insert(0, str(HERE))
from roc import rebuild
import addrmap
import inventory_flags

ROOT = rebuild.ROOT
WORK = HERE / 'namer'
WORK.mkdir(exist_ok=True)
FLAGS = '// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string'
_SC = {}
exec(open(ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read().split('def archive_symbols')[0], _SC)


def namespaces(header, cls):
    """Namespaces still open where header declares class cls."""
    text = header.read_text(errors='replace')
    m = re.search(r'(?:class|struct)\s+(?:__declspec\([^)]*\)\s*)?' + re.escape(cls) + r'[^;]*\{', text)
    if not m:
        return None
    out = []
    for nm in re.finditer(r'namespace\s+(\w+)\s*\{', text[:m.start()]):
        seg = text[nm.end():m.start()]
        if seg.count('{') - seg.count('}') >= 0:
            out.append(nm.group(1))
    return out


def definition(cls, mem, line):
    """Header declaration line -> out-of-class definition with a body valid for any return type."""
    code = line.split('//')[0].strip()
    if not code.endswith(';') or '{' in code or 'template' in code or 'operator' in code:
        return None
    code = code[:-1].strip()
    code = re.sub(r'\)\s*=\s*0\s*$', ')', code)                     # pure virtual
    code = re.sub(r'^(?:(?:virtual|static|explicit|inline|afx_msg|friend)\s+|__declspec\([^)]*\)\s*)+', '', code)
    m = re.search(r'(~?' + re.escape(mem) + r')\s*\(', code)
    if not m:
        return None
    head, rest = code[:m.start()], code[m.start():]
    rest = re.sub(r'\s*=\s*[^,()]+(?=[,)])', '', rest)                # default arguments
    return '%s%s::%s { throw 0; }' % (head, cls, rest)


def build(header, items):
    """items: [(cls, mem, addr, line)] -> {addr: mangled} for the ones that compile."""
    lines = [FLAGS, '#include <afxwin.h>', '#include "%s"' % header.as_posix(), '#pragma warning(disable: 4702 4715)']
    calls = {}
    for cls, mem, addr, decl in items:
        d = definition(cls, mem, decl)
        ns = namespaces(header, cls)
        if not d or ns is None:
            continue
        calls[len(lines) + 1] = (cls, mem, addr)
        lines.append(''.join('namespace %s { ' % n for n in ns) + d + ' }' * len(ns))
    if not calls:
        return {}, None
    for attempt in range(8):
        src = WORK / (re.sub(r'\W', '_', header.stem) + '.cpp')
        src.write_text('\n'.join(lines) + '\n')
        code, text = rebuild.run(rebuild.toolchain(21022), 'cl', inventory_flags.flags_for(src) + ['/c', '/Fo' + src.stem + '.obj', str(src)], WORK)
        if not code:
            break
        bad = {int(n) for n in re.findall(re.escape(src.name) + r'\((\d+)\)\s*:\s*(?:fatal )?error', text, re.I)}
        hit = [n for n in bad if n in calls]
        if not hit:
            return {}, 'header: ' + next((l for l in text.splitlines() if ' error ' in l), '?')[:160]
        for n in hit:
            lines[n - 1] = '// skipped: ' + lines[n - 1]
            calls.pop(n)
        if not calls:
            return {}, None
    else:
        return {}, 'gave up'
    defined = [n for n, k in _SC['symbols']((WORK / (src.stem + '.obj')).read_bytes()).items() if k != 'undef']
    out = {}
    for cls, mem, addr in calls.values():
        if mem == cls:
            pre = '??0%s@' % cls
        elif mem == '~' + cls:
            pre = '??1%s@' % cls
        else:
            pre = '?%s@%s@' % (mem, cls)
        cand = [n for n in defined if n.startswith(pre)]
        if len(cand) == 1:
            out[addr] = cand[0]
    return out, None


def main():
    found, where = addrmap.scan_all()
    by_header = collections.defaultdict(list)
    for (cls, mem), addrs in found.items():
        if (cls, mem) in where and len(addrs) == 1:
            hdr, line = where[(cls, mem)]
            by_header[hdr].append((cls, mem, next(iter(addrs)), line))
    names, problems = {}, {}
    for header, items in sorted(by_header.items()):
        got, err = build(header, items)
        names.update(got)
        if err:
            problems[header.name] = err
        print('%-40s %d/%d%s' % (header.name, len(got), len(items), ('  ' + err[:90]) if err else ''), flush=True)
    json.dump(names, open(HERE / 'link/names.json', 'w'), indent=1, sort_keys=True)
    print('named', len(names), 'addresses from', len(by_header), 'headers;', len(problems), 'headers did not compile alone')


if __name__ == '__main__':
    main()

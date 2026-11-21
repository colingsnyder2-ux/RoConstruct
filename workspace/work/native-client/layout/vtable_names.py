"""Name unnamed vtable slot targets from class headers (declaration order of virtual methods).

For a class D with a primary vtable in the 2008 exe, the k-th slot is the k-th entry of D's virtual list: the primary base's
list first, an override keeping the base's position, new virtuals appended in declaration order. Headers come from the
2007 rbxgs decompilation, the Codejock XTP source and the 2016 leak (local sparse checkout). A class is used only when
its already-named slots agree with the header list (at least 2 agree and at least 80% of the comparable ones), so a class
that gained or lost virtuals between versions is skipped, not guessed.

Writes vtable-names.json: {slot address: [owner class, method, header source, aligned slots, class]}.
Run: python work/native-client/layout/vtable_names.py
"""
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
ROOT = HERE.parents[2]
SOURCES = [('rbxgs 2007', ROOT / 'tools/rbxgs/Client'), ('XTP 11.2.2', ROOT / 'tools/libs/xtp-11.2.2/Source'),
           ('leak 2016', ROOT / 'local/references/roblox2016-src'), ('MFC 9.0', ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
CLASS = re.compile(r'\b(?:class|struct)\s+(?:[A-Z_]+\s+)?([A-Za-z_]\w*)\s*(?::\s*([^{;]+))?\{')
VIRTUAL = re.compile(r'\bvirtual\b[^;{}()]*?(~?\s*[A-Za-z_]\w*)\s*\(')


def base_names(clause):
    """[(name, [class arguments])] from 'public Notifier<A, B>, private Reflection::Described<C, &D>'.

    Roblox classes get their real base through a template wrapper (Described<Self, ..., Base>), so the arguments that are
    plain class names are kept as candidates.
    """
    out, depth, cur, inner, args, arg = [], 0, [], [], [], []
    for ch in clause + ',':
        if ch == '<':
            depth += 1
            if depth == 1:
                continue
        elif ch == '>':
            depth = max(depth - 1, 0)
            if depth == 0:
                args.append(''.join(arg))
                arg = []
                continue
        if ch == ',' and depth == 0:
            words = re.sub(r'(?:public|private|protected|virtual)', ' ', ''.join(cur)).split()
            if words:
                names = []
                for raw in args:
                    for part in re.split(r',', raw):
                        part = part.strip()
                        if part and not part.startswith('&') and re.fullmatch(r'[\w:]+', part):
                            names.append(part.split('::')[-1])
                out.append((words[-1].split('::')[-1], names))
            cur, args, arg = [], [], []
        elif depth == 0:
            cur.append(ch)
        elif depth >= 1:
            arg.append(ch)
    return out


SKIP_DIRS = ('boost', 'lua', 'g3d', 'ogre', 'mesa', 'sdl', 'zlib', 'png', 'ijg', 'unittest', 'test')


def strip(text):
    text = re.sub(r'/\*.*?\*/', ' ', text, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', text)


def body_of(text, start):
    """The text between the braces that open at text[start - 1], and the index after the closing brace."""
    depth, i = 1, start
    while i < len(text) and depth:
        c = text[i]
        depth += (c == '{') - (c == '}')
        i += 1
    return text[start:i - 1], i


def classes_in(text):
    """{class: (bases, [virtual method names in order])} for the classes defined in one header."""
    text = strip(text)
    out = {}
    for m in CLASS.finditer(text):
        name = m.group(1)
        bases = base_names(m.group(2) or '')
        body, _ = body_of(text, m.end())
        # members of the class itself only: drop nested braces (inline bodies, nested types)
        flat, depth = [], 0
        for ch in body:
            if ch == '{':
                depth += 1
            elif ch == '}':
                depth -= 1
            elif depth == 0:
                flat.append(ch)
        virtuals = []
        flat = ''.join(flat)
        # MFC macros that declare virtual methods at their position
        flat = re.sub(r'DECLARE_(?:DYNAMIC|DYNCREATE|SERIAL|OLECREATE\w*)\s*\([^)]*\)', ' virtual GetRuntimeClass( ', flat)
        flat = re.sub(r'DECLARE_MESSAGE_MAP\s*\(\s*\)', ' virtual GetMessageMap( ', flat)
        for v in VIRTUAL.finditer(flat):
            name_v = re.sub(r'\s+', '', v.group(1))
            if name_v not in virtuals:
                virtuals.append(name_v)
        if name not in out or virtuals:
            out[name] = (bases, virtuals)
    return out


def collect():
    table = {}                                        # class -> (bases, virtuals, source)
    for label, root in SOURCES:
        if not root.exists():
            continue
        for path in root.rglob('*.h'):
            parts = [p.lower() for p in path.relative_to(root).parts]
            if any(p.startswith(SKIP_DIRS) for p in parts) or 'roblox2016-src' in str(root) and parts[0] not in ('app', 'base', 'network', 'rendering', 'clientbase', 'clientshared', 'win'):
                continue
            try:
                found = classes_in(path.read_text(encoding='utf-8', errors='replace'))
            except OSError:
                continue
            for name, (bases, virtuals) in found.items():
                if virtuals and (name not in table or label.startswith('rbxgs')):
                    table[name] = (bases, virtuals, label)
    return table


def overlay(slots, virtuals, name):
    index = {m: i for i, (m, _o) in enumerate(slots)}
    for method in virtuals:
        if method == '~' + name and any(m.startswith('~') for m, _ in slots):
            i = next(i for i, (m, _o) in enumerate(slots) if m.startswith('~'))
            slots[i] = ('~' + name, name)
        elif method in index:
            slots[index[method]] = (method, name)
        else:
            slots.append((method, name))
            index[method] = len(slots) - 1
    return slots


def linear(name, table, depth=0):
    """[(method, owner)] in vtable order for the primary chain of name."""
    if name not in table or depth > 12:
        return []
    bases, virtuals, _ = table[name]
    slots = []
    for bname, args in bases:                       # the primary vtable comes from the first base that has virtual methods
        for arg in args:                            # a template wrapper: its real base is one of its class arguments
            if arg != name and arg in table:
                slots = linear(arg, table, depth + 1)
                if slots:
                    if bname in table and bname != arg:
                        slots = overlay(list(slots), table[bname][1], bname)
                    break
        if slots:
            break
        slots = linear(bname, table, depth + 1)
        if slots:
            break
    return overlay(list(slots), virtuals, name)


def short(cls):
    m = re.match(r'\.\?A[VU](\w+?)@', cls)
    return m.group(1) if m else None


def main():
    import layout_ios
    table = collect()
    vt = json.loads((HERE / 'vtables.json').read_text(encoding='utf-8'))
    names = {a: (e or {}).get('name') or '' for a, e in json.loads((HERE / 'function-files.json').read_text(encoding='utf-8')).items()}

    def method_of(addr):
        n = names.get(addr, '')
        if n.startswith(('??_G', '??_E')):
            return '~'
        k = layout_ios.msvc(n) if n.startswith('?') else None
        if not k:
            return None
        return '~' if k[-1] == '<fini>' else k[-2] if k[-1] == '<init>' else k[-1]

    out, stats = {}, collections.Counter()
    for cls, slots in vt.items():
        d = short(cls)
        lin = linear(d, table) if d else []
        if not lin:
            continue
        stats['classes with a header list'] += 1
        agree = clash = 0
        for k, addr in enumerate(slots[:len(lin)]):
            m = method_of(addr)
            if m:
                same = m == lin[k][0] or (m == '~' and lin[k][0].startswith('~'))
                agree += same
                clash += not same
        if agree >= 2 and agree / (agree + clash) >= 0.8:
            stats['aligned classes'] += 1
            for k, addr in enumerate(slots[:len(lin)]):
                if not method_of(addr) and (names.get(addr, '').startswith('func_') or not names.get(addr)):
                    meth, owner = lin[k]
                    if not meth.startswith('~'):
                        out[addr] = [owner, meth, table[owner][2], agree, d]
                        stats['slots named'] += 1
        else:
            stats['classes skipped (not aligned)'] += 1
    (HERE / 'vtable-names.json').write_text(json.dumps(out, separators=(',', ':')), encoding='utf-8')
    print(len(table), 'header classes with virtuals;', dict(stats), '| distinct functions named:', len(out))


if __name__ == '__main__':
    main()

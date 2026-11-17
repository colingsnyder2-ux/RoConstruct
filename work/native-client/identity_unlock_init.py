"""Route 1: name unnamed dynamic initializers (??__E) and atexit destructors (??__F).

Evidence, strongest first:
  creator  - body stores a ??_7Creator@?$FactoryProduct@...vtable (??__F) or stores the
             address of such a Creator object into getCreators()[name] (??__E).  The
             static is RBX::FactoryProduct<...>::creator (util/Object.h), mangled like
             the one registry row that already names it.
  pair     - an initializer that atexit-registers a named ??__F<G> is ??__E<G>, and the
             atexit target of a named ??__E<G> is ??__F<G>.
  decl     - the initializer constructs a global (mov ecx, imm) whose address is
             commented on a native-classes declaration, or pushes a string literal that
             one Reflection descriptor declaration (native-classes, then rbxgs 2007)
             uses with the same owner class as the constructor called.
Read-only except for work/native-client/identity-unlock-init.json.
"""
import glob
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, insns, named, refs, unnamed, IMG, BASE  # noqa: E402

ATEXIT = 0x6a17af
OUT = ROOT / 'work/native-client/identity-unlock-init.json'


def cstr(va):
    o = va - BASE
    e = IMG.index(b'\0', o)
    return IMG[o:e].decode('latin1')


def body(va):
    out = []
    for i in insns(va):
        out.append(i)
        if i.mnemonic in ('ret', 'jmp'):
            break
    return out


def facts(va):
    ii = body(va)
    f = {'atexit': None, 'creator_vt': None, 'creator_store': None, 'this': [], 'strings': [], 'ctors': [],
         'gdata': []}
    for j, i in enumerate(ii):
        r = refs(i)
        if i.mnemonic == 'call' and r == [ATEXIT] and j and refs(ii[j - 1]):
            f['atexit'] = refs(ii[j - 1])[0]
        if i.mnemonic == 'call' and r:
            n = named(r[0])
            if n and n['name'].startswith(('??0', '??$?0')):
                f['ctors'].append(n['name'])
        if i.mnemonic == 'mov' and i.op_str.startswith('dword ptr [0x'):
            row = REG.get('%08x' % r[-1]) if r else None
            if row and row['kind'] == 'vtable' and row['name'].startswith('??_7Creator@?$FactoryProduct@'):
                f['creator_vt'] = (r[0], row['name'])
        if i.mnemonic == 'mov' and i.op_str.startswith('dword ptr [eax], 0x'):
            f['creator_store'] = r[-1]
        if i.mnemonic == 'mov' and i.op_str.startswith('ecx, 0x') and 0x900000 <= r[0] < 0xa00000:
            f['this'].append(r[0])
        if (i.mnemonic == 'mov' and i.op_str.startswith(('ecx, 0x', 'dword ptr [0x'))) or \
                (i.mnemonic.startswith('fst') and '[0x' in i.op_str):
            for v in r[:1]:
                row = REG.get('%08x' % v)
                if row and row['kind'] == 'data' and row['name'].startswith('?') and not row.get('placeholder'):
                    f['gdata'].append(row['name'])
        if i.mnemonic == 'push' and r:
            row = REG.get('%08x' % r[0])
            if row and row['kind'] == 'string':
                f['strings'].append(cstr(r[0]))
            elif not row and 0x800000 <= r[0] < 0x900000:  # unregistered literal in .rdata
                txt = cstr(r[0])
                if 2 <= len(txt) <= 64 and txt.isprintable():
                    f['strings'].append(txt)
    return f


def global_key(g):
    """Registry data name -> the part between ??__E and @@YAXXZ.
    Namespace/global variables (storage '3') use the bare qualified name
    (??__EcloseFunction@RBX@@YAXXZ); class statics (storage 0/1/2) the full decorated
    name (??__E?color@FillTool@RBX@@2V...@A@@YAXXZ), as registry rows show.
    Function-local statics (?x@?N??...) are initialized inline: None."""
    m = re.match(r'\?(\w+(?:@\w+)*)@@([0-3])', g)
    if not m or '@?' in g.split('@@')[0]:
        return None
    return m.group(1) if m.group(2) == '3' else g


def creator_global(vt):
    # ??_7Creator@<FP>6B@  ->  ?creator@<FP>0VCreator@12@B
    assert vt.startswith('??_7Creator@') and vt.endswith('6B@')
    return '?creator@' + vt[len('??_7Creator@'):-3] + '0VCreator@12@B'


# ---- declaration index (native-classes first, then rbxgs) -----------------
DECL = re.compile(r'^\s*(?:static\s+)?(?:const\s+)?((?:Reflection::)?\w+)\s*<([^;{]*?)>\s+(\w+)\s*\(([^;]*?)\)\s*;(.*)$')


def scan_decls():
    rows = []
    for pat, tier in (('rebuild/2008-06/native-classes/*.cpp', 'native-classes'),
                      ('tools/rbxgs/Client/**/*.cpp', 'rbxgs')):
        for path in glob.glob(str(ROOT / pat), recursive=True):
            if Path(path).name.startswith('roc_'):  # generated scratch, not authentic source
                continue
            ns, depth, stack = [], 0, []
            try:
                lines = open(path, errors='ignore').read().splitlines()
            except OSError:
                continue
            pending = None
            for ln, line in enumerate(lines, 1):
                code = line.split('//')[0]
                m = re.match(r'\s*namespace\s+(\w+)\s*(\{)?', code)
                if m:
                    pending = m.group(1)
                    if m.group(2):
                        stack.append((pending, depth))
                        depth += 1
                        pending = None
                        code = code[m.end():]
                elif pending and code.strip().startswith('{'):
                    stack.append((pending, depth))
                    pending = None
                    depth += 1
                    code = code.strip()[1:]
                if depth == len(stack):  # only namespace scope
                    d = DECL.match(line)
                    if d and '"' in d.group(4):
                        lits = re.findall(r'"([^"]*)"', d.group(4))
                        addr = re.findall(r'\b00[0-9a-fA-F]{6}\b', d.group(5))
                        rows.append({'tier': tier, 'path': str(Path(path).relative_to(ROOT)).replace('\\', '/'),
                                     'line': ln, 'tmpl': d.group(1).split('::')[-1], 'args': d.group(2),
                                     'var': d.group(3), 'lits': lits, 'addr': [a.lower() for a in addr],
                                     'ns': [s for s, _ in stack]})
                for ch in code:
                    if ch == '{':
                        depth += 1
                    elif ch == '}':
                        depth -= 1
                        while stack and stack[-1][1] >= depth:
                            stack.pop()
    return rows


def scoped(var, ns):
    return var + ''.join('@' + n for n in reversed(ns))


def main():
    targets = set(unnamed())
    funcs = [a for a in sorted(REG) if '007e0000' <= a < '00800000' and REG[a]['kind'] == 'code']
    F = {a: facts(int(a, 16)) for a in funcs}
    glob_of = {}      # addr -> (G, evidence)  G = mangled global or scoped "var@ns@"
    creator_at = {}   # creator object address -> G
    for a, f in F.items():
        if f['creator_vt']:
            g = creator_global(f['creator_vt'][1])
            creator_at[f['creator_vt'][0]] = g
            glob_of[a] = ('F', g, {'kind': 'creator-vtable-store', 'vtable': f['creator_vt'][1],
                                   'object': '%08x' % f['creator_vt'][0]})
    for a, f in F.items():
        if a not in glob_of and f['creator_store'] in creator_at:
            glob_of[a] = ('E', creator_at[f['creator_store']],
                          {'kind': 'creator-map-store', 'object': '%08x' % f['creator_store']})
    for a, f in F.items():  # body constructs/stores a registry-named global
        keys = list(dict.fromkeys(k for k in map(global_key, f['gdata']) if k))
        if a not in glob_of and len(keys) == 1:
            # every registry ??__E lies in 007ee720-007f9ff0, every ??__F in 007fa050-00801ab0
            letter = 'E' if a < '007fa000' else 'F'
            glob_of[a] = (letter, keys[0], {'kind': 'named-data-global', 'global': f['gdata'][0]})
    regcount = defaultdict(int)
    for v in REG.values():
        regcount[v['name']] += 1
    for a in funcs:  # already named initializers/destructors (skip names shared by folded bodies)
        n = REG[a]['name']
        if not REG[a].get('placeholder') and n[:5] in ('??__E', '??__F') and n.endswith('@@YAXXZ') \
                and regcount[n] == 1:
            glob_of.setdefault(a, (n[4], n[5:-7], {'kind': 'registry-name', 'symbol': n}))

    decls = scan_decls()
    by_addr = defaultdict(list)
    by_lit = defaultdict(list)
    for d in decls:
        for x in d['addr']:
            by_addr[x].append(d)
        if d['lits']:
            by_lit[d['lits'][0]].append(d)
    for a, f in F.items():
        if a in glob_of or f['atexit'] is None:
            continue
        cand = []
        for t in f['this']:
            cand += [(d, 'source-address-comment') for d in by_addr.get('%08x' % t, []) if d['tier'] == 'native-classes']
        if not cand and f['strings'] and f['ctors']:
            tms = re.findall(r'\?\$(\w+)@', f['ctors'][0])
            owner = re.match(r'\?\?0\?\$\w+@V(\w+)@', f['ctors'][0])
            for lit in f['strings']:
                for tier in ('native-classes', 'rbxgs'):
                    # every literal of the declaration must be pushed by the initializer
                    same = [d for d in by_lit.get(lit, []) if d['tier'] == tier and d['tmpl'] in tms
                            and set(d['lits']) <= set(f['strings'])]
                    hit = [d for d in same if owner and re.match(r'\s*' + owner.group(1) + r'\b', d['args'])]
                    # the constructor's owner can be an ICF alias; a literal unique within the
                    # descriptor template is enough on its own
                    if hit:
                        cand = [(d, 'reflection-literal+ctor-owner') for d in hit]
                    elif len({scoped(d['var'], d['ns']) for d in same}) == 1:
                        cand = [(d, 'reflection-literal-unique') for d in same]
                    if cand:
                        break
                if cand:
                    break
        names = {scoped(d['var'], d['ns']) for d, _ in cand}
        if len(names) == 1:
            d, why = cand[0]
            glob_of[a] = ('E', names.pop(), {'kind': why, 'source': '%s:%d' % (d['path'], d['line']),
                                             'literal': d['lits'][:1], 'this': ['%08x' % t for t in f['this']]})

    out = {}

    def emit(addr, letter, g, ev):
        if addr not in targets or addr in out or (letter == 'E') != (addr < '007fa000'):
            return
        sym = '??__' + letter + g + '@@YAXXZ'
        out[addr] = {'name': sym, 'owner_class': None, 'signature': None, 'kind': 'code',
                     'name_source': 'identity-unlock-init', 'evidence': ev + [{'kind': 'decorated-signature', 'symbol': sym}]}

    for a, (letter, g, ev) in glob_of.items():
        f = F[a]
        if letter == 'E':
            emit(a, 'E', g, [ev])
            if f['atexit'] is not None:
                emit('%08x' % f['atexit'], 'F', g, [ev, {'kind': 'atexit-target-of', 'initializer': a}])
        else:
            emit(a, 'F', g, [ev])
    # initializer whose atexit target has a known ??__F global; an ICF-folded destructor
    # registered by several initializers names none of them
    pushers = defaultdict(int)
    for f in F.values():
        if f['atexit'] is not None:
            pushers[f['atexit']] += 1
    for a, f in F.items():
        t = '%08x' % f['atexit'] if f['atexit'] is not None else None
        if t in glob_of and glob_of[t][0] == 'F' and pushers[f['atexit']] == 1:
            emit(a, 'E', glob_of[t][1], [glob_of[t][2], {'kind': 'registers-atexit', 'destructor': t}])
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    from collections import Counter
    print(len(out), Counter(r['evidence'][0]['kind'] for r in out.values()))


if __name__ == '__main__':
    main()

"""Method-declaration skeletons for classes that have no native header.

Every line comes from a bound mangled symbol: access, virtual/static, const,
calling convention and full signature are encoded in the name.  Virtual
methods are listed in vftable slot order read from the original image when the
class's primary vftable is bound.  No data member is emitted: field layout is
not proven here, so a skeleton is NOT a usable header yet.  Output goes to
work/, never to native-headers.
"""
import argparse
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc.native_bulk import Targets  # noqa: E402
from native_conversion_queue import owner, undecorate  # noqa: E402

DECL = re.compile(r'^(public|protected|private): (.*)$')


def member(declaration, scope):
    """('public', 'virtual void f(int) const') with the owner qualifier and __thiscall removed."""
    hit = DECL.match(declaration)
    if not hit or scope + '::' not in hit[2]:
        return None
    text = hit[2].replace('__thiscall ', '').replace(scope + '::', '', 1).replace('(void)', '()')
    return hit[1], re.sub(r'\s+', ' ', text).strip()


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--min-methods', type=int, default=3)
    args = ap.parse_args()
    closure = json.loads(args.closure.read_text())
    targets = Targets('2008-06')
    by_addr = defaultdict(list)
    vftables = defaultdict(list)
    for row in closure['bindings']:
        by_addr[row['addr']].append(row['symbol'])
        if row['symbol'].startswith('??_7') and row['symbol'].endswith('@@6B@'):
            vftables[owner(row['symbol'])].append(row['addr'])
    args.output.mkdir(parents=True, exist_ok=True)
    index = []
    for cls in json.loads(args.queue.read_text())['classes']:
        scope = cls['owner']
        if cls['headers'] or cls['template'] or not scope or '`' in scope or len(cls['methods']) < args.min_methods:
            continue
        slots = {}
        if len(vftables.get(scope, ())) == 1:
            va, i = int(vftables[scope][0], 16), 0
            while va + 4 * i in targets.relocs and i < 512:
                slots['%08x' % struct.unpack('<I', targets.data(va + 4 * i, 4))[0]] = i
                i += 1
                if '%08x' % (va + 4 * i) in by_addr:  # next named object starts here
                    break
        groups, seen = defaultdict(list), set()
        for method in sorted(cls['methods'], key=lambda m: (slots.get(m['addr'], 10 ** 6), m['addr'])):
            parsed = member(method['declaration'], scope)
            if not parsed or parsed in seen:
                continue
            seen.add(parsed)
            slot = slots.get(method['addr'])
            note = '  // %s%s %s' % (method['addr'], '' if slot is None else ' slot %d' % slot, method['state'])
            groups[parsed[0]].append('    %s;%s' % (parsed[1], note))
        if not groups:
            continue
        parts = scope.split('::')
        body = ['// Declarations proven by bound mangled symbols (identity evidence only).',
                '// Field layout, base classes and class size are NOT proven: not a usable header yet.']
        body += ['namespace %s {' % ns for ns in parts[:-1]] + ['class %s' % parts[-1], '{']
        for access in ('public', 'protected', 'private'):
            if groups[access]:
                body += [access + ':'] + groups[access]
        body += ['};'] + ['}' for _ in parts[:-1]]
        name = re.sub(r'[^A-Za-z0-9_.-]', '_', scope) + '.h'
        (args.output / name).write_text('\n'.join(body) + '\n', encoding='utf-8')
        index.append({'owner': scope, 'file': name, 'declarations': len(seen),
                      'vftable_slots_ordered': sum(m['addr'] in slots for m in cls['methods'])})
    index.sort(key=lambda r: -r['declarations'])
    (args.output / 'index.json').write_text(json.dumps(index, indent=1) + '\n')
    print('skeletons', len(index), 'declarations', sum(r['declarations'] for r in index),
          'slot-ordered', sum(r['vftable_slots_ordered'] for r in index))
    print([(r['owner'], r['declarations']) for r in index[:12]])


if __name__ == '__main__':
    main()

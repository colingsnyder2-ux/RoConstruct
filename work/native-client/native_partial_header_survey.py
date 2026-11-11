"""Survey: can exact mined packets of one class be merged into a proven-partial header?

Per owner (claude-conversion-queue.json, state 'convert'):
  library-ref   packet body lives in a roc-lib library source (no stand-in to merge)
  stand-in      packet declares its own `struct S { char pad[N]; T fN; ... }`
Per stand-in packet: field offsets/types it declares, and its fake externs
(`sub_XXXXXX`, `gXXXXXX`) with whether the closure names that address.
Merged per owner: offsets with one type agreed vs conflicting.

Read-only.  Output claude-partial-header-survey.json.
"""
import json
import re
from collections import defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SRC = ROOT / 'src/2008-06'
FIELD = re.compile(r'^\s*([A-Za-z_][\w:<>\s\*&]*?[\s\*&])f([0-9a-fA-F]+)\s*(\[[^\]]*\])?\s*;', re.M)
EXTERN = re.compile(r'\b(sub|g)_?([0-9a-fA-F]{6,8})\b')

names = json.loads((HERE / 'identity-names-by-address.json').read_text())
queue = json.loads((HERE / 'claude-conversion-queue.json').read_text())['classes']
report = []
for row in queue:
    methods = [m for m in row['methods'] if m['state'] == 'convert']
    if len(methods) < 8 or row['template']:
        continue
    fields, kinds = defaultdict(set), defaultdict(int)
    externs, named = set(), set()
    for m in methods:
        path = SRC / ('%s.cpp' % m['addr'])
        text = path.read_text(errors='replace') if path.exists() else ''
        if '// roc-lib:' in text:
            kinds['library-ref'] += 1
            continue
        if not re.search(r'char\s+pad', text):
            kinds['no-pad-struct'] += 1
        else:
            kinds['stand-in'] += 1
        for typ, off, arr in FIELD.findall(text):
            fields[int(off, 16)].add(' '.join(typ.split()) + (arr or ''))
        for kind, addr in EXTERN.findall(text):
            a = addr.lower().zfill(8)
            externs.add(a)
            if names.get(a):
                named.add(a)
    conflicts = {hex(o): sorted(t) for o, t in fields.items() if len(t) > 1}
    report.append({'owner': row['owner'], 'headers': row['headers'], 'convert': len(methods), 'kinds': dict(kinds),
                   'offsets': len(fields), 'agreed_offsets': len(fields) - len(conflicts), 'conflicts': conflicts,
                   'externs': len(externs), 'externs_named': len(named)})
report.sort(key=lambda r: -r['convert'])
(HERE / 'claude-partial-header-survey.json').write_text(json.dumps(report, indent=1) + '\n')
for r in report[:25]:
    print(r['convert'], r['owner'][:34], r['kinds'], 'offs', r['agreed_offsets'], '/', r['offsets'],
          'ext', r['externs_named'], '/', r['externs'])

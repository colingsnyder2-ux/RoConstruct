"""One screen of facts per address, from every source an agent used to read by hand (no model, no proof, ~2 s).
  python work/native-client/family_status.py ADDR [ADDR ...]
Prints: size and bucket, identity from the binary (rule, identity, family size mode: a body whose size differs from its
family's usual size is probably the wrong premise), owner/declaration facts, which lane unit exists, identity rows bound
to the address, and the last lane verdict.  An address with a lane unit or a non-workflow identity row is already done."""
import collections
import glob
import json
import os
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]


def load(name, default):
    try:
        return json.loads((HERE / name).read_text(encoding='utf-8'))
    except (OSError, ValueError):
        return default


if len(sys.argv) < 2:
    sys.exit(__doc__)
cl = load('remaining-classified.json', {})
ident = load('research-twins/identities.json', {}).get('unique', {})
owners = load('research-owners/owners.json', {})
rows = load('class-identity-bindings.json', {}).get('identity_bindings', [])
bound = collections.defaultdict(list)
for r in rows:
    bound[r.get('address')].append(r)
sizes = collections.defaultdict(list)
for a, v in ident.items():
    sizes[re.sub(r'<.*', '', v['identity'])].append(v.get('size'))
done = {}
for name in ('twin-lane-done.json', 'thunk-lane-done.json', 'functor-lane-done.json'):
    for a, s in load(name, {}).items():
        done.setdefault(a, []).append('%s: %s' % (name.split('-')[0], str(s)[:140]))
units = {}
for p in glob.glob(str(ROOT / 'rebuild/2008-06/native-classes/*.cpp')):
    m = re.match(r'(Thunk|TwinInst|FunctorInst|WF)_.*?([0-9a-f]{8})', os.path.basename(p))
    if m:
        units.setdefault(m.group(2), []).append(os.path.basename(p))
for addr in sys.argv[1:]:
    addr = addr.lower()
    c = cl.get(addr) or {}
    print('== %s  %s B  %s  %s' % (addr, c.get('size', '?'), c.get('bucket', '(not in remaining)'), c.get('name', '')))
    i = ident.get(addr)
    if i:
        fam = re.sub(r'<.*', '', i['identity'])
        modal = collections.Counter(sizes[fam]).most_common(1)[0]
        flag = '' if i.get('size') == modal[0] else '   <-- SIZE DIFFERS from the family\'s usual %s B (%d of %d): check the premise' % (
            modal[0], modal[1], len(sizes[fam]))
        print('  identity [%s]: %s%s' % (i['rule'], i['identity'][:160], flag))
    o = owners.get(addr)
    if o:
        print('  owner %s | %s | %s' % (o.get('owner'), o.get('declaration') or o.get('name') or '(no name)', o.get('method')))
    if addr in units:
        print('  UNIT EXISTS:', ', '.join(units[addr]), '(already proved by a lane)')
    for r in bound.get(addr, []):
        print('  identity row: %s  [%s]' % (r.get('symbol', '')[:110], str(r.get('identity_evidence'))[:70]))
    for d in done.get(addr, []):
        print('  lane:', d)
    if not (i or o or units.get(addr) or bound.get(addr)):
        print('  no structural fact for this address')

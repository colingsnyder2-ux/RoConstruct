"""Address-order identity for groups of byte-identical bodies (no model, no new source).  When several remaining
addresses share one candidate set (identical `EnumDesc<E>::~EnumDesc` bodies: each address matches every symbol), the
registry name of each address is accepted only if (a) it is in that candidate set, (b) no other address of the group
claims it, and (c) the group's address order equals the names' sorted order - the linker placed these instantiations
in name order, which is independent evidence the registry names are not shuffled.  Writes order-identity-bindings.json.
  python work/native-client/order_identity.py   (refuses while a census runs)"""
import collections
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
import native_llm as m  # noqa: E402

reg = m.load_registry()
cands = json.loads((HERE / 'ambiguous-candidates.json').read_text())
groups = collections.defaultdict(list)
for addr, symbols in cands.items():
    if len(symbols) > 1:
        groups[tuple(symbols)].append(addr)
out, stat = [], collections.Counter()
for symbols, addrs in groups.items():
    if len(addrs) < 3:                                   # order evidence needs a run, not a pair
        stat['group-too-small'] += 1
        continue
    addrs.sort()
    names = [(reg.get(a) or {}).get('name') or '' for a in addrs]
    keep = [(a, n) for a, n in zip(addrs, names) if n in symbols]
    if len(keep) < 3 or len({n for _, n in keep}) != len(keep):
        stat['names-missing-or-shared'] += 1
        continue
    seq = [n for _, n in keep]
    if seq != sorted(seq):
        stat['not-monotone'] += 1
        continue
    stat['group-bound'] += 1
    for a, n in keep:
        out.append({'symbol': n, 'address': a, 'votes': 1,
                    'identity_evidence': 'registry name in byte-equal candidate set; %d-address run in sorted name order'
                                         % len(keep)})
print(dict(stat), 'bindings', len(out))
(HERE / 'order-identity-bindings.json').write_text(json.dumps(
    {'scope': 'identity evidence only: identical-body groups bound by registry name + address order (order_identity.py)',
     'sources': {}, 'identity_bindings': out}, indent=1))

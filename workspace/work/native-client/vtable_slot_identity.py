"""Vtable-slot identity (no model, real evidence).  A compiled object that defines a vftable `??_7X@@6B...@` lists,
slot by slot, the symbol of each virtual function (relocations inside the vftable data).  When that vftable's 2008
address V is known (evidence bindings), the original image holds at V + 4*k the address of the same slot's function.
Symbol S in slot k is bound to that address A when A is a remaining function and S compiled byte-equal to A (it is one
of A's census candidates).  The census still audits everything.  -> vtable-slot-bindings.json
  python work/native-client/vtable_slot_identity.py [--dry]"""
import argparse
import collections
import gzip
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--dry', action='store_true')
args = ap.parse_args()
if not args.dry and (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: writing evidence now would void it')
sys.path.insert(0, str(ROOT))
from roc import integration_site, match  # noqa: E402

FAMILY = HERE / 'prove-out/OgreNativeFull'
base, image = match._image('2008-06')
exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - exact
vft = collections.defaultdict(set)                 # vftable symbol -> known addresses
for f in HERE.glob('*bindings*.json'):
    try:
        data = json.loads(f.read_text())
    except (OSError, ValueError):
        continue
    for b in (data.get('identity_bindings') or data.get('bindings') or []) if isinstance(data, dict) else []:
        if isinstance(b, dict) and str(b.get('symbol', '')).startswith('??_7') and b.get('address'):
            try:
                vft[b['symbol']].add(int(b['address'], 16))
            except ValueError:
                pass
a2s = collections.defaultdict(set)
objects = set()
for entry in json.loads((FAMILY / 'ledger.json').read_text()).values():
    if entry.get('object'):
        objects.add(entry['object'])
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (FAMILY / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(FAMILY / 'rows' / entry['harvest_ref']))
    if isinstance(rows, str):
        rows = json.loads(rows)
    for r in rows or []:
        cands = r.get('candidates') or '[]'
        for c in (json.loads(cands) if isinstance(cands, str) else cands):
            a2s[c].add(r['symbol'])
# More vftable addresses from the exact functions themselves: an exact function at address F references `??_7X` with
# a DIR32 relocation at offset o; the original dword at F + o is that vftable's address.
exact_addr = collections.defaultdict(set)
for a, v in integration_site.inactive_code(ROOT).items():
    if v[1]:
        exact_addr[v[0]].add(int(a.split('+')[0], 16))
derived = collections.defaultdict(collections.Counter)
for path in sorted(objects):
    try:
        raw = Path(path).read_bytes()
        secs, syms, functions, starts = match._coff_data_index(raw)
    except (OSError, struct.error):
        continue
    for name, (value, sec) in functions.items():
        if len(exact_addr.get(name, ())) != 1:
            continue
        f = next(iter(exact_addr[name]))
        _, _, _, _, rawptr, relptr, _, nrel, _, _ = secs[sec]
        later = [x for x in starts.get(sec + 1, ()) if x > value]
        end = min(later) if later else value + 65536
        for k in range(nrel):
            off, index, kind = struct.unpack_from('<IIH', raw, relptr + 10 * k)
            if value <= off < end and kind == 0x06 and index in syms and syms[index][0].startswith('??_7'):
                try:
                    addend = struct.unpack_from('<i', raw, rawptr + off)[0]
                    target = (struct.unpack_from('<I', image, f + (off - value) - base)[0] - addend) & 0xffffffff
                except struct.error:
                    continue
                derived[syms[index][0]][target] += 1
for name, counter in derived.items():
    if name not in vft and len(counter) == 1:
        vft[name].add(next(iter(counter)))
votes = collections.defaultdict(collections.Counter)          # address -> symbol votes
stat = collections.Counter()
for path in sorted(objects):
    try:
        raw = Path(path).read_bytes()
        secs, syms, functions, starts = match._coff_data_index(raw)
    except (OSError, struct.error):
        stat['object-missing'] += 1
        continue
    for name, (value, sec) in functions.items():
        if not name.startswith('??_7') or len(vft.get(name, ())) != 1:
            continue
        v = next(iter(vft[name]))
        _, _, _, _, _, relptr, _, nrel, _, _ = secs[sec]
        later = [s for s in starts.get(sec + 1, ()) if s > value]
        end = min(later) if later else value + 4096
        for k in range(nrel):
            off, index, kind = struct.unpack_from('<IIH', raw, relptr + 10 * k)
            if value <= off < end and kind == 0x06 and index in syms:
                try:
                    target = '%08x' % struct.unpack_from('<I', image, v + (off - value) - base)[0]
                except struct.error:
                    continue
                stat['slots'] += 1
                if target in remaining:
                    stat['slots-into-remaining'] += 1
                    if syms[index][0] in a2s.get(target, ()):
                        votes[target][syms[index][0]] += 1
out = []
for addr, counter in sorted(votes.items()):
    if len(counter) == 1:
        symbol = next(iter(counter))
        out.append({'symbol': symbol, 'address': addr, 'votes': counter[symbol],
                    'identity_evidence': 'vtable slot: the original vftable holds this address in the slot where the '
                                         'compiled vftable references this symbol; body byte-equal'})
    else:
        stat['slot-conflict'] += 1
print(dict(stat), 'known vftables', sum(1 for v in vft.values() if len(v) == 1))
print('bindings: %d%s' % (len(out), ' (dry)' if args.dry else ''))
for b in out[:5]:
    print(' ', b['address'], b['symbol'][:90])
if not args.dry:
    (HERE / 'vtable-slot-bindings.json').write_text(json.dumps(
        {'scope': 'identity from vftable slot position (vtable_slot_identity.py)', 'sources': {},
         'identity_bindings': out}, indent=1))

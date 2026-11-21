"""Reference-consistent identity (no model, real evidence).  Identical bodies at different addresses differ in what
they reference: the compiled symbol S references symbols C1..Cn at fixed offsets; each candidate address A has
original relocation targets at the same offsets.  A is consistent with S when every referenced symbol whose 2008
address is KNOWN (census-exact symbols, evidence bindings, unique registry names) is the target A references there.
S is bound to A when A is the ONLY consistent candidate of S, S is the only consistent symbol of A, and at least one
known reference discriminated (ruled out another candidate) - so the pick rests on callee identity, not on bytes alone.
The census still audits bytes, relocations and every reference.  -> ref-consistent-bindings.json
  python work/native-client/ref_consistent_identity.py [--dry]   (refuses to write while a census runs)"""
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
sys.argv = sys.argv[:1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import integration_site, match  # noqa: E402
import native_llm as m                    # noqa: E402

FAMILY = HERE / 'prove-out/OgreNativeFull'
base, image = match._image('2008-06')
exact = {a: v[0] for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - set(exact)

# symbol -> known 2008 addresses
known = collections.defaultdict(set)
for a, s in exact.items():
    known[s].add(int(a.split('+')[0], 16))       # merged extents are keyed 'owner+funclet'
for f in HERE.glob('*bindings*.json'):
    if f.name == 'ref-consistent-bindings.json':
        continue
    try:
        data = json.loads(f.read_text())
    except (OSError, ValueError):
        continue
    for b in (data.get('identity_bindings') or data.get('bindings') or []) if isinstance(data, dict) else []:
        if isinstance(b, dict) and b.get('symbol') and b.get('address'):
            try:
                known[b['symbol']].add(int(b['address'], 16))
            except ValueError:
                pass
reg = m.load_registry()
names = collections.Counter((r or {}).get('name') for r in reg.values())
for a, r in reg.items():
    n = (r or {}).get('name') or ''
    if n and names[n] == 1 and n[0] in '?_' and not n.startswith(('?sub_', '?func_')) and a not in remaining:
        known[n].add(int(a, 16))


def dword(va):
    return struct.unpack_from('<I', image, va - base)[0]


def original_target(addr, off, kind):
    try:
        if kind == 0x14:                                       # REL32
            return (addr + off + 4 + struct.unpack_from('<i', image, addr + off - base)[0]) & 0xffffffff
        if kind == 0x06:                                       # DIR32
            return dword(addr + off)
    except struct.error:
        pass
    return None


_objects = {}


def references(obj_path, symbol, size):
    """[(offset in function, kind, referenced symbol name, addend)] for SYMBOL in the object."""
    if obj_path not in _objects:
        try:
            raw = Path(obj_path).read_bytes()
            _objects[obj_path] = (raw, match._coff_data_index(raw))
        except (OSError, struct.error):
            _objects[obj_path] = None
    if not _objects[obj_path]:
        return None
    raw, (secs, syms, functions, _) = _objects[obj_path]
    if symbol not in functions:
        return None
    start, sec = functions[symbol]
    _, _, _, _, rawptr, relptr, _, nrel, _, _ = secs[sec]
    out = []
    for k in range(nrel):
        off, index, kind = struct.unpack_from('<IIH', raw, relptr + 10 * k)
        if start <= off < start + size and index in syms and kind in (0x14, 0x06):
            addend = struct.unpack_from('<i', raw, rawptr + off)[0] if kind == 0x06 else 0
            out.append((off - start, kind, syms[index][0], addend))
    return out


rows_for = collections.defaultdict(list)       # symbol -> (object, size, candidates)
a2s = collections.defaultdict(set)
for entry in json.loads((FAMILY / 'ledger.json').read_text()).values():
    rows = entry.get('harvest_rows')
    if rows is None and entry.get('harvest_ref') and (FAMILY / 'rows' / entry['harvest_ref']).is_file():
        rows = json.load(gzip.open(FAMILY / 'rows' / entry['harvest_ref']))
    if isinstance(rows, str):
        rows = json.loads(rows)
    for r in rows or []:
        cands = r.get('candidates') or '[]'
        cands = json.loads(cands) if isinstance(cands, str) else cands
        if cands and any(c in remaining for c in cands) and entry.get('object'):
            rows_for[r['symbol']].append((entry['object'], int(r.get('size') or 0), tuple(cands)))
            for c in cands:
                a2s[c].add(r['symbol'])

def solve():
    """One pass over every symbol with the current `known` map -> (bindings, stats)."""
    consistent = collections.defaultdict(set)      # symbol -> consistent candidate addresses
    discriminated = set()                          # symbols where a known reference ruled out a candidate
    stat = collections.Counter()
    for symbol, lst in rows_for.items():
        obj, size, cands = lst[0]
        refs = references(obj, symbol, size)
        if refs is None:
            stat['no-object'] += 1
            continue
        usable = [(off, kind, name, addend) for off, kind, name, addend in refs if known.get(name) and name != symbol]
        if not usable:
            stat['no-known-reference'] += 1
            continue
        for a in set().union(*[set(c) for _, _, c in lst]):
            ok = True
            for off, kind, name, addend in usable:
                target = original_target(int(a.split('+')[0], 16), off, kind)
                if target is None or (target - addend) & 0xffffffff not in known[name]:
                    ok = False
                    break
            if ok:
                consistent[symbol].add(a)
            else:
                discriminated.add(symbol)
    found = []
    for symbol, addrs in consistent.items():
        if len(addrs) != 1:
            # Identical copies (same bytes AND same references at several addresses, e.g. one template instance
            # emitted by several libraries): the symbol names each remaining copy where no other symbol competes.
            copies = [x for x in addrs if x in remaining
                      and not {t for t in a2s[x] if t != symbol and x in consistent.get(t, ())}]
            if addrs and symbol in discriminated and copies:
                for x in copies:
                    found.append({'symbol': symbol, 'address': x, 'votes': 1, 'identity_evidence':
                                  'inferred: reference-consistent identical copy (%d addresses share bytes and references)' % len(addrs)})
                stat['identical-copies'] += len(copies)
            else:
                stat['several-consistent' if addrs else 'none-consistent'] += 1
            continue
        a = next(iter(addrs))
        if a not in remaining:
            stat['consistent-address-already-exact'] += 1
            continue
        rivals = {s for s in a2s[a] if s != symbol and a in consistent.get(s, ())}
        evidence = ('reference-consistent: the only byte-equal candidate whose original references match the known '
                    'addresses of the symbols this body references')
        if rivals:
            # True twins (same bytes, same references): bytes cannot choose.  The registry name of the address
            # breaks the tie when it is one of them (INFERRED tier, owner-approved).
            if (reg.get(a) or {}).get('name') != symbol:
                stat['address-has-other-consistent-symbol'] += 1
                continue
            evidence = 'inferred: reference-consistent twin chosen by the registry name of the address'
            stat['twin-by-registry'] += 1
        elif symbol not in discriminated and len(set().union(*[set(c) for _, _, c in rows_for[symbol]])) > 1:
            stat['not-discriminated'] += 1
            continue
        found.append({'symbol': symbol, 'address': a, 'votes': 1, 'identity_evidence': evidence})
        stat['bound'] += 1
    return found, stat


out, seen = [], set()
for rnd in range(6):                               # fixed point: a binding is a known callee for the next pass
    found, stat = solve()
    new = [b for b in found if (b['symbol'], b['address']) not in seen]
    if not new:
        break
    for b in new:
        seen.add((b['symbol'], b['address']))
        known[b['symbol']].add(int(b['address'].split('+')[0], 16))
        out.append(b)
    print('pass %d: +%d' % (rnd + 1, len(new)))
print(dict(stat))
if not args.dry:
    (HERE / 'ref-consistent-bindings.json').write_text(json.dumps(
        {'scope': 'identity by reference consistency over byte-equal candidates (ref_consistent_identity.py)',
         'sources': {}, 'identity_bindings': out}, indent=1))
print('bindings: %d%s' % (len(out), ' (dry)' if args.dry else ''))
for b in out[:6]:
    print(' ', b['address'], b['symbol'][:90])

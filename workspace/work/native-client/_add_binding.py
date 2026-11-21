"""Append rows to class-identity-bindings.json: _add_binding.py EVIDENCE SYMBOL=ADDR ... (dedup by address+symbol)."""
import json, sys
p = 'work/native-client/class-identity-bindings.json'
d = json.load(open(p))
ev = sys.argv[1]
have = {(r['symbol'], r['address']) for r in d['identity_bindings']}
for a in sys.argv[2:]:
    sym, addr = a.rsplit('=', 1)
    if (sym, addr) not in have:
        d['identity_bindings'].append({'symbol': sym, 'address': addr, 'identity_evidence': ev, 'votes': 1})
json.dump(d, open(p, 'w'), indent=1)

"""mkbind.py OUT.json 'ADDR=SYMBOL' ...  (or --merge: append bindings to an evidence file keeping existing ones)"""
import json, sys
out = sys.argv[1]
try: cur = json.load(open(out))
except OSError: cur = {'scope': 'template-instantiation identity evidence (callee addresses read from the original calls of exact-by-bytes owners)', 'identity_bindings': []}
have = {(b['symbol'], b['address']) for b in cur['identity_bindings']}
for a in sys.argv[2:]:
    ad, sym = a.split('=', 1)
    if (sym, ad) not in have:
        cur['identity_bindings'].append({'symbol': sym, 'address': ad, 'identity_evidence': 'original call target of byte-identical owner body', 'votes': 1})
json.dump(cur, open(out, 'w'), indent=1)
print(len(cur['identity_bindings']))

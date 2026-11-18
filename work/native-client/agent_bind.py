"""Add identity rows for byte-equal bodies in one command (replaces hand edits of class-identity-bindings.json).

  python work/native-client/agent_bind.py "SYMBOL" ADDR "evidence text" ["SYMBOL" ADDR "evidence" ...]

Waits while a census runs, skips rows already present, refuses an address or real symbol already bound differently.
Use `INFERRED: ...` evidence for placeholder/inferred names.  Then rerun agent_prove.py."""
import json
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
PATH = HERE / 'class-identity-bindings.json'
args = sys.argv[1:]
if not args or len(args) % 3:
    sys.exit(__doc__)
while (HERE / 'prove-out/CENSUS.lock').is_file():
    time.sleep(30)
import shared_json  # noqa: E402


def apply(doc):
    rows = doc['identity_bindings']
    by_addr = {r['address']: r['symbol'] for r in rows}
    by_sym = {r['symbol']: r['address'] for r in rows if not r['symbol'].startswith('$')}
    for sym, addr, why in zip(args[0::3], args[1::3], args[2::3]):
        addr = addr.lower()
        if by_addr.get(addr) == sym:
            print('already bound', addr)
        elif addr in by_addr or (sym in by_sym and not sym.startswith('$')):
            print('REFUSED %s: conflicts with existing row %s -> %s' % (addr, by_addr.get(addr) or sym, by_sym.get(sym) or addr))
        else:
            rows.append({'symbol': sym, 'address': addr, 'votes': 1, 'identity_evidence': why})
            by_addr[addr], by_sym[sym] = sym, addr
            print('bound', addr)
    return doc


shared_json.update(PATH, apply)

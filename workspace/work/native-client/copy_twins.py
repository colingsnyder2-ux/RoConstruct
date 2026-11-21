"""Copy-twin evidence: a remaining function whose code is identical to an already proven-exact function (same bytes,
same absolute call/jump targets out of the body, same data references) is another copy of that function (one template /
inline helper compiled into several static libraries).  Bind the exact twin's symbol to the remaining address too
(identity evidence, one symbol at several addresses - native_bulk accepts that when the evidence names each address),
so the census counts it from the native TU that already emits the symbol.  No model calls.
  python work/native-client/copy_twins.py      -> work/native-client/copy-twin-bindings.json"""
import collections
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
from capstone import CS_ARCH_X86, CS_MODE_32, Cs  # noqa: E402
from roc import integration_site, match  # noqa: E402

md = Cs(CS_ARCH_X86, CS_MODE_32)
base, image = match._image('2008-06')


def key(addr):
    try:
        code, _relocs = match.target('2008-06', addr)
    except (KeyError, ValueError, SystemExit):
        return None
    va = int(addr, 16)
    end = va + len(code)
    out = []
    for ins in md.disasm(bytes(code), va):
        if ins.mnemonic in ('call', 'jmp') or ins.mnemonic.startswith('j'):
            op = ins.op_str
            if op.startswith('0x'):
                dest = int(op, 16)
                out.append((ins.mnemonic, 'abs' if not va <= dest < end else 'rel', dest if not va <= dest < end else dest - va))
                continue
        out.append(bytes(ins.bytes))
    return (len(code), tuple(out)) if out else None


cl = json.loads((HERE / 'remaining-classified.json').read_text())
inactive = integration_site.inactive_code(ROOT)
exact = {a: v[0] for a, v in inactive.items() if v[1] and isinstance(v[0], str) and v[0].startswith('?')}
print('exact functions with symbols: %d; remaining: %d' % (len(exact), len(cl)), flush=True)
by_key = collections.defaultdict(list)
for i, (addr, sym) in enumerate(exact.items()):
    k = key(addr)
    if k and k[0] >= 6:
        by_key[k].append((addr, sym))
    if i % 2000 == 0:
        print('  indexed %d' % i, flush=True)
binds, groups = [], 0
for addr in cl:
    k = key(addr)
    twins = by_key.get(k) if k else None
    if not twins:
        continue
    syms = {s for _, s in twins}
    if len(syms) != 1:
        continue                           # identical body under several names: ambiguous, skip
    groups += 1
    binds.append({'symbol': next(iter(syms)), 'address': addr, 'identity_evidence': 'copy-twin of %s' % twins[0][0], 'votes': 1})
(HERE / 'copy-twin-bindings.json').write_text(json.dumps(
    {'scope': 'identity evidence: remaining functions code-identical (bytes, absolute call targets, data refs) to a '
              'proven-exact function; the twin symbol is bound to this copy too', 'identity_bindings': binds}, indent=0))
print('RESULT copy twins: %d remaining functions have a proven twin' % len(binds), flush=True)

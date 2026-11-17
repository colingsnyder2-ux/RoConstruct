"""Learn callee/data reference identities of the creator initializers from the FactoryProductCreators2008 object
(native_reference_alias_bind.py, as native_creator_gate.py does per class) into creator-reference-bindings.json."""
import json, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
FAM = sys.argv[1] if len(sys.argv) > 1 else 'prove-FactoryProductCreators2008'
ARGV = list(sys.argv)
sys.path.insert(0, 'work/native-client'); sys.argv = sys.argv[:1]
import native_llm as m
ROOT = m.ROOT
out = ROOT / 'work/native-client/prove-out' / FAM
obj = sorted(out.glob('objects/*/candidate.obj'), key=lambda p: p.stat().st_mtime)[-1]
OWN = Path(ARGV[2]) if len(ARGV) > 2 else ROOT / 'work/native-client/creator-identity-bindings.json'
ids = json.load(open(OWN))['identity_bindings']
tmp = ROOT / 'work/native-client/creator-partition/alias'
tmp.mkdir(parents=True, exist_ok=True)
def one(b):
    rec = tmp / ('alias-%s.json' % b['address'])
    subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_reference_alias_bind.py'), '--object', str(obj),
                    '--symbol', b['symbol'], '--address', b['address'], '--closure', str(ROOT / 'work/native-client/creator-partition/closure.json'), '--output', str(rec)],
                   cwd=ROOT, capture_output=True, text=True)
    try:
        return json.loads(rec.read_text()).get('identity_bindings', [])
    except (OSError, ValueError):
        return []
OUTF = ROOT / 'work/native-client/creator-reference-bindings.json'
learned = json.load(open(OUTF))['identity_bindings'] if OUTF.is_file() else []
seen = {(b['symbol'], b['address']) for b in learned}
with ThreadPoolExecutor(8) as pool:
    for rows in pool.map(one, ids):
        for b in rows:
            key = (b['symbol'], b['address'])
            if key not in seen and m.plausible_binding(b['symbol'], b['address']):
                seen.add(key); learned.append(b)
json.dump({'scope': 'reference identities of creator initializers learned from byte-exact bodies (native_reference_alias_bind.py)',
           'identity_bindings': learned}, open(OUTF, 'w'))
print('learned', len(learned))

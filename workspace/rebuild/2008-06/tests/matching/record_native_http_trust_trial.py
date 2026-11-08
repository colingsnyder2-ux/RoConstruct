"""Compare the recovered HTTP trust path against original code and bindings."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

probe = root / 'rebuild/2008-06/out/native-layouts/http-trust-probe'
probe.mkdir(exist_ok=True)
source = root / 'rebuild/2008-06/experiments/trials/NativeHttpTrustTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj = probe / 'trial.obj'
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log

def compare(path, prefix, address):
    raw = path.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x' % address)
    start, section = definitions[name]
    table = sections[section]
    bindings = {}
    if len(body) == len(target):
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if 0 <= offset < len(body) - 3:
                value = struct.unpack_from('<I', target, offset)[0]
                if kind == 20:
                    value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                bindings.setdefault(symbols[index][0], set()).add(value)
    return {'address': hex(address), 'symbol': name, 'candidate_size': len(body),
            'original_size': len(target), 'exact': match.exact_match(target, targetrefs, body, refs),
            'bindings': {k: [hex(v) for v in sorted(values)] for k, values in bindings.items()}}

trust = compare(obj, '?trustCheck@Http@RBX@@', 0x56a2e0)
init = compare(obj, '?initializeTrustCheck@RBX@@', 0x569bf0)
donor = root / 'rebuild/2008-06/out/RbxgsApp/linked/Http.obj'
site = compare(donor, '?isRobloxSite@Http@RBX@@', 0x56a160)
script = compare(donor, '?isScript@Http@RBX@@', 0x56a040)
assert trust['exact'] and not init['exact'] and not site['exact'] and script['exact']
for prefix, address in [('?initializeTrustCheck@RBX@@', '0x569bf0'),
                        ('?isRobloxSite@Http@RBX@@', '0x56a160'),
                        ('?isScript@Http@RBX@@', '0x56a040'),
                        ('_trustCheckOnce', '0x974abc'), ('_skipTrustCheck', '0x974ab9')]:
    assert any(k.startswith(prefix) and address in v for k, v in trust['bindings'].items()), prefix
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive trust body matches; initialization and site predicate differ; static data identity and runtime unproven. Do not run.',
           'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)),
           'object_sha256': sha(obj), 'donor_object_sha256': sha(donor),
           'flags': flags, 'trust': trust, 'initialize': init, 'donor_site': site, 'donor_script': script}
(root / 'work/2008-06/shared-layouts/http-trust-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS exact trust body; initializer and donor site predicate mismatch')

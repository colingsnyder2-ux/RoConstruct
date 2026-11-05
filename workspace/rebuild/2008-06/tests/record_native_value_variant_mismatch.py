"""Record typed Value-to-VARIANT port without changing the shared Value ABI."""
import hashlib
import json
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/native-layouts'
probe = out / 'value-variant-probe'
overlay = probe / 'reflection'
overlay.mkdir(parents=True, exist_ok=True)
header = root / 'rebuild/2008-06/native-headers/reflection/type.h'
text = header.read_text()
needle = '\t\t\tbool isVoid() const'
assert text.count(needle) == 1
text = text.replace(needle, '\t\t\ttemplate<typename T> const T& asRef() const { return boost::any_cast<const T&>(value); }\n' + needle)
(overlay / 'type.h').write_text(text)
source = root / 'rebuild/2008-06/tests/NativeValueVariantMismatch.cpp'
obj = probe / 'NativeValueVariantMismatch.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(probe))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, probe)
assert code == 0, log
name, body, refs = next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?valueToVariant@@'))
target, targetrefs, _ = match.target('2008-06', '00416370')
assert len(body) == 635 and len(target) == 615 and not match.exact_match(target, targetrefs, body, refs)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = {'scope': 'Inactive typed candidate mismatch; asRef overlay, ContentId lifetime, original helper bindings and live ABI remain unproven. Do not link or run.', 'source_sha256': sha(source), 'observer_sha256': sha(Path(__file__)), 'header_sha256': sha(header), 'overlay_sha256': sha(overlay / 'type.h'), 'object_sha256': sha(obj), 'symbol': name, 'address': '00416370', 'candidate_size': len(body), 'original_size': len(target), 'exact': False, 'flags': flags}
(root / 'work/2008-06/shared-layouts/value-variant-mismatch.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS typed Value-to-VARIANT mismatch recorded')

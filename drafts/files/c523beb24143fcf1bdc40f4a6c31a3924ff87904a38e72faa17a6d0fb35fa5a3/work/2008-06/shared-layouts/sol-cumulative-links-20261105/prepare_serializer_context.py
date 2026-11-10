"""Separate frozen private declaration profile for the serializer recovery."""
import difflib
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
digest = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
clone = json.loads((HERE / 'clone-context.json').read_text())
basis = Path(clone['private_header'])
assert digest(basis) == clone['private_sha256']
assert digest(clone['canonical_header']) == clone['canonical_sha256']
donor = Path(clone['genuine_donor_header'])
assert re.search(r'void\s+read\(const XmlElement\*\s*element,\s*IReferenceBinder&\s*binder\)', donor.read_text())
text = basis.read_text()
needle = '    static boost::shared_ptr<Instance> fromXmlRoot(::XmlElement*);'
addition = '    void read(const ::XmlElement*, IReferenceBinder&);'
assert text.count(needle) == 1 and addition not in text
shadow = text.replace(needle, needle + '\n' + addition)
assert shadow.replace('\n' + addition, '') == text
destination = HERE / 'serializer-context/v8tree/Instance.h'
destination.parent.mkdir(parents=True, exist_ok=True)
destination.write_text(shadow)
layers = ['metadata-load', 'writer-2008', 'std-noinline-string']
profile = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I' + str(destination.parent.parent)
profile += ''.join(' /I{headers}/' + name for name in layers)
receipt = {'scope': 'Inactive parent-approved genuine nonvirtual declaration experiment. Canonical and clone profiles stay frozen; no fields/bases/virtual changes. Canonical ODR/compatibility and runtime gates remain separate.',
           'canonical_header': clone['canonical_header'], 'canonical_sha256': clone['canonical_sha256'],
           'basis_header': str(basis), 'basis_sha256': digest(basis),
           'genuine_donor_header': str(donor), 'genuine_donor_sha256': digest(donor),
           'private_header': str(destination), 'private_sha256': digest(destination),
           'addition': addition, 'native_flags_environment': profile,
           'existing_profile_source': str(ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionLoad.cpp'),
           'profile_source_sha256': digest(ROOT / 'rebuild/2008-06/native-classes/MetadataReflectionLoad.cpp'),
           'diff': list(difflib.unified_diff(text.splitlines(), shadow.splitlines(), fromfile='frozen clone context', tofile='private nonvirtual read declaration', lineterm='')),
           'parent_lease': 'SolSerializerContext20261105', 'canonical_edits': 0, 'compiles': 0}
(HERE / 'serializer-context.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(json.dumps({'private_header': str(destination), 'sha256': digest(destination), 'canonical_edits': 0}))

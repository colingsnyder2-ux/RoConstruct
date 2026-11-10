"""Materialize the approved private static-declaration context; canonical files stay frozen."""
import hashlib
import json
from pathlib import Path
import difflib

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
canonical = ROOT / 'rebuild/2008-06/native-headers/v8tree/Instance.h'
donor = ROOT / 'tools/rbxgs/Client/App/include/v8tree/Instance.h'
digest = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
assert digest(canonical) == '49ce2d0144378fead1015fd0fce074b67cacc352a15bda5c814913a119fd9114'
assert 'static boost::shared_ptr<Instance> fromXmlRoot(XmlElement*);' in donor.read_text()
text = canonical.read_text()
needle = '    boost::shared_ptr<Instance> clone();  // ?clone@Instance@RBX@@QAE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ'
assert text.count(needle) == 1 and 'fromXmlRoot' not in text
addition = '    static boost::shared_ptr<Instance> fromXmlRoot(::XmlElement*);'
shadow = text.replace(needle, needle + '\n' + addition)
assert shadow.replace('\n' + addition, '') == text
destination = HERE / 'clone-context/v8tree/Instance.h'
destination.parent.mkdir(parents=True, exist_ok=True)
destination.write_text(shadow)
profile = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I' + str(destination.parent.parent)
receipt = {'scope': 'Approved inactive declaration experiment. One genuine static member declaration; canonical ABI/layout/virtual order untouched. Full canonical compatibility/ODR and runtime gates remain separate.',
           'canonical_header': str(canonical), 'canonical_sha256': digest(canonical),
           'genuine_donor_header': str(donor), 'genuine_donor_sha256': digest(donor),
           'private_header': str(destination), 'private_sha256': digest(destination),
           'addition': addition, 'native_flags_environment': profile,
           'diff': list(difflib.unified_diff(text.splitlines(), shadow.splitlines(), fromfile='frozen canonical', tofile='private static declaration', lineterm='')),
           'parent_lease': 'SolCloneContext20261105', 'canonical_edits': 0, 'compiles': 0}
(HERE / 'clone-context.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(json.dumps({'private_header': str(destination), 'sha256': digest(destination), 'canonical_edits': 0}))

"""Use genuine VC9 c_str while preserving the existing out-of-line size profile."""
import difflib
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
digest = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
genuine = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/include/xstring'
old_layer = ROOT / 'rebuild/2008-06/native-headers/std-noinline-string/xstring'
real, old = genuine.read_text(), old_layer.read_text()
cstr = '\tconst _Elem *__CLR_OR_THIS_CALL c_str() const'
size = '\tsize_type __CLR_OR_THIS_CALL size() const'
assert real.count(cstr) == real.count(size) == 1
expected = real.replace(cstr, cstr.replace('\t', '\t__declspec(noinline) ', 1))
expected = expected.replace(size, size.replace('\t', '\t__declspec(noinline) ', 1))
assert '\n'.join(old.splitlines()[3:]) == '\n'.join(expected.splitlines())
text = ('// Inactive per-TU VC9 RTM profile: genuine inline c_str; size remains out of line.\n'
        + real.replace(size, size.replace('\t', '\t__declspec(noinline) ', 1)))
folder = HERE / 'serializer-inline-cstr'
folder.mkdir(exist_ok=True)
# The uploadable .h is the durable source; xstring is its compiler-search copy.
template, materialized = folder / 'xstring.h', folder / 'xstring'
template.write_text(text)
materialized.write_bytes(template.read_bytes())
base = json.loads((HERE / 'serializer-context.json').read_text())
assert digest(base['private_header']) == base['private_sha256']
old_include = '/I{headers}/std-noinline-string'
assert base['native_flags_environment'].count(old_include) == 1
profile = base['native_flags_environment'].replace(old_include, '/I' + str(folder))
receipt = {'scope': 'Inactive second loader hypothesis. Only c_str noinline attribute is removed relative to old code tokens; size noinline retained. All VC9 fields, method bodies, constructors/destructor and other declarations are genuine and unchanged.',
           'genuine_header': str(genuine), 'genuine_sha256': digest(genuine),
           'old_layer': str(old_layer), 'old_layer_sha256': digest(old_layer),
           'uploadable_template': str(template), 'template_sha256': digest(template),
           'materialized_header': str(materialized), 'materialized_sha256': digest(materialized),
           'private_instance_header': base['private_header'], 'private_instance_sha256': base['private_sha256'],
           'native_flags_environment': profile, 'base_profile': str(HERE / 'serializer-context.json'),
           'diff_vs_genuine': list(difflib.unified_diff(real.splitlines(), text.splitlines(), n=2, lineterm='')),
           'parent_lease': 'SolSerializerStringContext20261105', 'canonical_edits': 0, 'compiles': 0}
(HERE / 'serializer-inline-cstr-context.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(json.dumps({'template_sha256': digest(template), 'private_instance_sha256': base['private_sha256'],
                  'canonical_edits': 0, 'compiles': 0}))

"""Build recovered About classes and their existing native source dependencies."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
TC = rebuild.toolchain(21022)
subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/record_native_dhtml_dialog.py')], cwd=ROOT, check=True)
flags = ['/nologo', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
version_source = CLASSES / 'CFileVersionInfo.cpp'
version_flags = flags + ['/c', '/FoNativeFileVersionInfo.obj', str(version_source)]
code, log = rebuild.run(TC, 'cl', version_flags, OUT)
assert code == 0, log

recipe = libs.RECIPES['rbxgs']
data_source = CLASSES / 'CAboutRobloxDialogData.cpp'
data_flags = flags + ['/DBOOST_ALL_NO_LIB'] + ['/D' + d for d in recipe['defines'].split()]
data_flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
code, log = rebuild.run(TC, 'cl', data_flags + ['/P', str(data_source)], OUT)
assert code == 0, log
body = (OUT / 'CAboutRobloxDialogData.i').read_text(encoding='utf8', errors='replace')
# The original TU imports these actual MSVCP90 string members.
for needle in ('\t basic_string()', '~basic_string()', 'const _Elem * c_str() const'):
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
data_translation = OUT / 'NativeAboutDialogData.cpp'
data_translation.write_text(body, encoding='utf8')
data_compile_flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD',
                      '/FoNativeAboutDialogData.obj', str(data_translation)]
code, log = rebuild.run(TC, 'cl', data_compile_flags, OUT)
assert code == 0, log

gl_source = ROOT / 'tools/libs/g3d-6.09/source/roc_large_glcaps_11e595a340f00f1c.cpp'
body = gl_source.read_text(encoding='utf8')
for name, line in (('glVersion', 615), ('driverVersion', 622), ('vendor', 629), ('renderer', 637)):
    needle = '    alwaysAssertM(_loadedExtensions, "Cannot call GLCaps::' + name + ' before GLCaps::init().");'
    assert body.count(needle) == 1
    body = body.replace(needle, '#line ' + str(line) + ' ".\\\\glg3dcpp\\\\GLCaps.cpp"\n' + needle)
needle = '    static std::string _driverVendor = (char*)glGetString(GL_VENDOR);'
assert body.count(needle) == 1
body = body.replace(needle, '    const char* text = (const char*)glGetString(GL_VENDOR);\n'
                           '    static std::string _driverVendor = text ? text : "";')
gl_translation = OUT / 'NativeGLCaps.cpp'
gl_translation.write_text(body, encoding='utf8')
recipe = libs.RECIPES['g3d-6.09-rbx2008']
gl_flags = ['/nologo', '/c', '/O2', '/Gy', '/GS-', '/EHsc', '/MD', '/DNDEBUG']
gl_flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
gl_flags += ['/FoNativeGLCaps.obj', str(gl_translation)]
code, log = rebuild.run(TC, 'cl', gl_flags, OUT)
assert code == 0, log

methods = []
for obj_name, targets in (
    ('NativeFileVersionInfo.obj', (('0046a200', '??0CFile'), ('0046a220', '?Create@'),
                                 ('0046a370', '?GetVersionInfo@'), ('0046a440', '?GetFileVersion@'),
                                 ('0046a4b0', '?Reset@'))),
    ('NativeAboutDialogData.obj', (('00401390', '?DoDataExchange@CAbout'),)),
    ('NativeGLCaps.obj', (('00470770', '?glVersion@'), ('00471070', '?driverVersion@'),
                        ('00470880', '?vendor@'), ('004709a0', '?renderer@'))),
):
    functions = match.coff_functions((OUT / obj_name).read_bytes())
    for address, prefix in targets:
        name, data, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, target_refs, data, refs)
        # Park the typed query's register-allocation mismatch; grant no exact credit.
        assert exact or address == '0046a370', (address, name)
        methods.append(dict(address=address, symbol=name, size=len(data), target_size=len(target),
                            object=obj_name, relocation_masked_match=exact))
paths = [Path(__file__), version_source, data_source, gl_source,
         HEADERS / 'CFileVersionInfo.h', HEADERS / 'CAboutRobloxDialog.h',
         ROOT / 'roc/libs.py', data_translation, gl_translation]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):sha(p) for p in paths}, compiler_build=21022,
               version_flags=version_flags, data_flags=data_compile_flags, gl_flags=gl_flags,
               methods=methods, scope='Source/object evidence. Version query is nonexact; full linkage/runtime evidence recorded separately.')
(ROOT / 'work/2008-06/shared-layouts/about-dependencies-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('About dependencies: %d/%d relocation-masked matches; query mismatch parked' %
      (sum(m['relocation_masked_match'] for m in methods), len(methods)))

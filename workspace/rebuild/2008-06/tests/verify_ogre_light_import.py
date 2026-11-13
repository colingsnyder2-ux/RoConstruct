"""Exercise both the local and DLL light comparators in the rebuilt Ogre link."""
import json
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, native_bulk, rebuild  # noqa: E402
import pefile  # noqa: E402

CLIENT = '2008-06'
SYMBOL = '??RlightsForShadowTextureLess@SceneManager@Ogre@@QBE_NPBVLight@2@0@Z'
OGRE = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
OVERLAY = ROOT / 'rebuild/2008-06/native-headers/OgreLightInline'
BOOST = ROOT / 'tools/rbxgs/Client/boost_1_34_1/src'
OUT = ROOT / 'rebuild/2008-06/out/tests/ogre-light-import'
FORCE = ROOT / 'rebuild/2008-06/out/Ogre/force'


def run(tool, args):
    code, output = rebuild.run(rebuild.toolchain(), tool, args, OUT)
    if code:
        raise RuntimeError('%s failed: %s' % (tool, output[-3000:]))


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    common = ('#include <OgreSceneManager.h>\n'
              'struct Access : Ogre::SceneManager { typedef lightsForShadowTextureLess Comparator; };\n')
    for name in ('Imported', 'Local'):
        (OUT / (name.lower() + '.cpp')).write_text(
            common + 'extern "C" bool call%s(const Ogre::Light* a, const Ogre::Light* b) '
            '{ Access::Comparator c; return c(a, b); }\n' % name)
    (OUT / 'both.cpp').write_text('''#include "force_verified.h"
#include <OgreLight.h>
extern "C" bool callImported(const Ogre::Light*, const Ogre::Light*);
extern "C" bool callLocal(const Ogre::Light*, const Ogre::Light*);
int main() {
    Ogre::Light a, b;
    if (callImported(&a, &a) || callLocal(&a, &a)) return 1;
    a.setCastShadows(true); b.setCastShadows(false);
    if (!callImported(&a, &b) || !callLocal(&a, &b) || callImported(&b, &a) || callLocal(&b, &a)) return 2;
    b.setCastShadows(true); a.tempSquareDist = 1; b.tempSquareDist = 2;
    if (!callImported(&a, &b) || !callLocal(&a, &b) || callImported(&b, &a) || callLocal(&b, &a)) return 3;
    return 0;
}
''')
    for name, includes in (('both', [OGRE, BOOST]), ('imported', [OGRE, BOOST]),
                           ('local', [OVERLAY, OGRE, BOOST])):
        args = ['/nologo', '/c', '/O2', '/Ob2', '/GS-', '/EHsc', '/MD', '/DWIN32', '/DNDEBUG',
                '/DBOOST_ALL_NO_LIB', '/I' + str(FORCE)] + ['/I' + str(p) for p in includes]
        run('cl', args + ['/Fo' + name + '.obj', name + '.cpp'])
    imported = rebuild.coff_externals((OUT / 'imported.obj').read_bytes())
    local = rebuild.coff_externals((OUT / 'local.obj').read_bytes())
    assert imported.get('__imp_' + SYMBOL) is False and local.get(SYMBOL) is False

    out = ROOT / 'rebuild/2008-06/out'
    libs = [out / 'Ogre/linked/linked.lib'] + [out / n / 'linked/linked.lib'
            for n in ('G3D', 'Boost', 'zlib-winapi', 'zlib')]
    libs += [rebuild.dll_pointer_import_lib(CLIENT, 'rgmain.dll', [SYMBOL]),
             rebuild.dll_import_lib(CLIENT, 'rgmain.dll'), 'msvcprt.lib',
             ROOT / 'tools/openrbx/3rdparty/Microsoft DirectX SDK (November 2007)/Lib/x86/dxguid.lib']
    system = ['kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib', 'ole32.lib',
              'oleaut32.lib', 'comdlg32.lib', 'ws2_32.lib', 'winmm.lib', 'opengl32.lib', 'glu32.lib']
    run('link', ['/nologo', '/SUBSYSTEM:CONSOLE', '/MACHINE:X86', '/MAP:both.map', '/OUT:both.exe',
                 'both.obj', 'imported.obj', 'local.obj'] + [str(p) for p in libs] + system)
    lines = (OUT / 'both.map').read_text(errors='replace').splitlines()
    assert any(SYMBOL in line and '__imp_' not in line and 'OgreRbxSceneManager.obj' in line for line in lines)
    receipt = 'work/native-client/ogre-light-reference-corrections.json'
    evidence = json.loads((ROOT / receipt).read_text())
    targets = {'0068e500', '0068e5f0', '006906d0', '00698070', '0069d660', '0069d720'}
    rows = [r for r in evidence['rows'] if r['address'] in targets]
    assert {r['address'] for r in rows} == targets
    _, bindings, blockers, _ = native_bulk.seed_evidence(ROOT, [receipt])
    assert not blockers, blockers
    original = native_bulk.Targets(CLIENT, selected=list(targets))
    source_object = out / 'Ogre/linked/OgreRbxSceneManager.obj'
    raw = source_object.read_bytes()
    functions = {n: (body, relocs) for n, body, relocs in match.coff_functions(raw)}
    providers = {}
    for line in lines:
        columns = line.split()
        if len(columns) >= 4:
            providers.setdefault(columns[1], columns[-1])
    for row in rows:
        assert any(row['symbol'] in line and 'OgreRbxSceneManager.obj' in line for line in lines), row['address']
        body, relocs = functions[row['symbol']]
        target, target_relocs, _ = match.target(CLIENT, row['address'])
        assert set(target_relocs) <= set(relocs) and match.exact_match(target, target_relocs, body, relocs)
        refs, errors = native_bulk.audit_references(raw, row['symbol'], body, target, target_relocs,
                                                    int(row['address'], 16), original, bindings)
        assert not errors, (row['address'], errors)
        for ref in refs:
            if ref['external']:
                continue
            provider = providers.get(ref['symbol'], '')
            assert provider.startswith('linked:'), (ref['symbol'], provider)
            obj = out / 'Ogre/linked' / provider.split(':', 1)[1]
            candidate = next(f for f in match.coff_functions(obj.read_bytes()) if f[0] == ref['symbol'])
            expected, expected_relocs, _ = match.target(CLIENT, ref['address'])
            assert set(expected_relocs) <= set(candidate[2]) and match.exact_match(
                expected, expected_relocs, candidate[1], candidate[2]), ref['address']
    image = pefile.PE(str(OUT / 'both.exe'))
    assert any(d.dll.lower() == b'rgmain.dll' and any(i.name == SYMBOL.encode() for i in d.imports)
               for d in image.DIRECTORY_ENTRY_IMPORT)
    shutil.copy2(rebuild.client_dll(CLIENT, 'rgmain.dll'), OUT / 'rgmain.dll')
    result = subprocess.run([str(OUT / 'both.exe')], cwd=OUT, capture_output=True, text=True, timeout=60)
    if result.returncode:
        raise RuntimeError('comparator test exited %d: %s' % (result.returncode, result.stderr))
    print('PASS local and imported Ogre light comparators')


if __name__ == '__main__':
    main()

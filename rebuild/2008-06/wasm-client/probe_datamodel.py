"""Compile the current 2008 DataModel source with Castle's browser headers."""
import os
import re
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/wasm-castle'))
import port_patches

OUT = ROOT / 'work/wasm-client/datamodel-probe'
OUT.mkdir(parents=True, exist_ok=True)
native, g3d, gl = (OUT / name for name in ('native-include', 'g3d-include', 'gl-include'))
boost_overlay = OUT / 'boost-overlay/boost/algorithm/string/detail'
boost_overlay.mkdir(parents=True, exist_ok=True)
formatter = ROOT / 'tools/rbxgs/Client/boost_1_34_1/src/boost/algorithm/string/detail/formatter.hpp'
text = formatter.read_text()
if 'm_Format(begin(Format), end(Format))' not in text or 'RangeT(begin(Replace), end(Replace))' not in text:
    raise SystemExit('Boost formatter changed; review browser compatibility patch')
(boost_overlay / 'formatter.hpp').write_text(text.replace('begin(Format), end(Format)',
    'boost::begin(Format), boost::end(Format)').replace('begin(Replace), end(Replace)',
    'boost::begin(Replace), boost::end(Replace)'))
find_format = formatter.parents[1] / 'find_format.hpp'
text = find_format.read_text()
if 'Finder(begin(Input), end(Input))' not in text:
    raise SystemExit('Boost find_format changed; review browser compatibility patch')
(boost_overlay.parent / 'find_format.hpp').write_text(text.replace('Finder(begin(Input), end(Input))',
    'Finder(boost::begin(Input), boost::end(Input))'))
for name in ('find_format_all.hpp', 'replace_storage.hpp'):
    text = (formatter.parent / name).read_text()
    text, count = re.subn(r'(?<![\w.:>])(begin|end)\(', r'boost::\1(', text)
    if not count:
        raise SystemExit('Boost ' + name + ' changed; review browser compatibility patch')
    (boost_overlay / name).write_text(text)
port_patches.native_headers(ROOT, native)
port_patches.g3d_headers(ROOT, g3d)
subprocess.run([sys.executable, str(Path(__file__).with_name('compat_headers.py')),
                str(native)], check=True)
shutil.copytree(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/RenderSystems/GL/include', gl, dirs_exist_ok=True)
port_patches.gl_headers(gl)
sdk = ROOT / 'tools/emsdk'
env = dict(os.environ, EMSDK=str(sdk), EM_CONFIG=str(sdk / '.emscripten'),
           EM_CACHE=str(ROOT / 'work/wasm-client/emscripten-cache'))
command = [sys.executable, str(sdk / 'upstream/emscripten/em++.py'), '-std=c++11', '-O1',
           '-fexceptions', '-fms-extensions', '-D__forceinline=inline', '-DNDEBUG', '-DNO_SSE',
           '-DBOOST_HAS_THREADS', '-DBOOST_HAS_PTHREADS', '-ferror-limit=30',
           '-include', 'cstdlib', '-include', 'cmath', '-include', str(Path(__file__).with_name('browser_types.h')),
           *('-I' + str(path) for path in (native, g3d, gl,
               native / 'datamodel-2008',
               native / 'uievent-native',
               ROOT / 'rebuild/2008-06/wasm-castle/compat',
               ROOT / 'tools/rbxgs/Client/Rendering/AppDraw/include',
               ROOT / 'tools/rbxgs/Client/App/include',
               ROOT / 'tools/rbxgs/Client/Rendering/SDL-1.2.6/include',
               ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include',
               OUT / 'boost-overlay',
               ROOT / 'tools/rbxgs/Client/boost_1_34_1/src'))]
failed = False
for name in sys.argv[1:] or ['DataModelCreate.cpp']:
    source = ROOT / 'rebuild/2008-06/native-classes' / name
    if source.parent != ROOT / 'rebuild/2008-06/native-classes' or not source.is_file():
        raise SystemExit('Expected a native-classes filename: ' + name)
    object_file = OUT / (source.stem + '.o')
    object_file.unlink(missing_ok=True)
    result = subprocess.run(command + ['-c', str(source), '-o', str(object_file)],
                            env=env, capture_output=True, text=True)
    log = OUT / (source.stem + '.log')
    log.write_text(result.stdout + result.stderr, encoding='utf-8')
    print(('FAIL ' if result.returncode else 'PASS ') + name + ': ' + str(log), flush=True)
    failed |= result.returncode != 0
raise SystemExit(1 if failed else 0)

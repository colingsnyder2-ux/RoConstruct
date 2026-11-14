"""Build Ogre 1.4.5 from source for Wasm, leaving the native build untouched.

Initial core compilation stage; browser renderer and executable follow separately.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
import re
from pathlib import Path
import shutil
import subprocess
import sys
import port_patches

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OGRE = ROOT / 'tools/libs/ogre-1.4.5/ogrenew'
SDK = ROOT / 'tools/emsdk'
OUT = ROOT / 'work/wasm-castle/build'
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--filter', default='', help='Compile source files containing this text')
parser.add_argument('--workers', type=int, default=4)
parser.add_argument('--stage', choices=('core', 'gl', 'smoke', 'bootstrap', 'rbx', 'support', 'castle'), default='core')
parser.add_argument('--link-only', action='store_true', help='Relink the successful bootstrap object receipt')
args = parser.parse_args()
compiler = SDK / 'upstream/emscripten/em++.py'
if not compiler.exists():
    raise SystemExit('Install SDK: python tools/emsdk/emsdk.py install 7.0.0')
env = dict(os.environ, EMSDK=str(SDK), EM_CONFIG=str(SDK / '.emscripten'))
headers = OUT / 'include'
shutil.copytree(OGRE / 'OgreMain/include', headers, dirs_exist_ok=True)
objects = OUT / 'objects'
objects.mkdir(parents=True, exist_ok=True)
logs = OUT / 'logs'
logs.mkdir(exist_ok=True)
flags = ['-std=c++11', '-O1', '-fexceptions', '-DOGRE_STATIC_LIB', '-DOGRE_NONCLIENT_BUILD',
         '-DOGRE_NO_FREEIMAGE=1', '-DOGRE_NO_DEVIL=1', '-Wno-deprecated-declarations',
         '-Wno-register', '-I' + str(HERE / 'compat'), '-I' + str(headers),
         '-I' + str(OGRE / 'OgreMain/src'),
         '-include', str(HERE / 'compat/LegacyCharTraits.h')]
# wasm32 uses unsigned long for size_t. The original 64-bit branch already
# expresses the required unsigned-int / size_t overload pair, without changing
# Ogre's architecture setting or lying about pointer width.
condition = 'OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_64 || OGRE_PLATFORM == OGRE_PLATFORM_APPLE'
converter = headers / 'OgreStringConverter.h'
converter.write_text(converter.read_text().replace(condition, condition + ' || defined(__EMSCRIPTEN__)'))
if args.stage == 'smoke':
    executable = OUT / 'core_smoke.js'
    subprocess.run([sys.executable, str(compiler), *flags, str(HERE / 'core_smoke.cpp'),
                    str(OUT / 'libOgreMainCore.a'), '-o', str(executable)], env=env, check=True)
    config = (SDK / '.emscripten').read_text()
    node = re.search(r"NODE_JS\s*=\s*\['([^']+)'", config)
    node_path = node.group(1) if node else str(next((SDK / 'node').glob('*/node.exe')))
    result = subprocess.run([node_path, str(executable)], env=env, text=True, capture_output=True)
    (OUT / 'core-smoke.json').write_text(json.dumps({'exit': result.returncode,
        'output': result.stdout + result.stderr, 'wasm_sha256': hashlib.sha256(
            executable.with_suffix('.wasm').read_bytes()).hexdigest()}, indent=2))
    print(result.stdout + result.stderr)
    raise SystemExit(result.returncode)
# External image/font/archive sources get their real Wasm dependencies in a later
# build stage. They are explicitly excluded here, not replaced by stub symbols.
external = {'OgreFreeImageCodec.cpp', 'OgreILCodecs.cpp', 'OgreILImageCodec.cpp',
            'OgreILUtil.cpp', 'OgreFont.cpp', 'OgreZip.cpp'}
makefile = (OGRE / 'OgreMain/src/Makefile.am').read_text()
source_names = set(re.findall(r'\bOgre\w+\.cpp', makefile))
sources = sorted(p for p in (OGRE / 'OgreMain/src').glob('Ogre*.cpp')
                 if p.name in source_names and p.name not in external and 'SSE' not in p.name
                 and args.filter in p.name)
if args.stage in ('gl', 'bootstrap', 'castle'):
    gl = OGRE / 'RenderSystems/GL'
    gl_headers = OUT / 'gl-include'
    shutil.copytree(gl / 'include', gl_headers, dirs_exist_ok=True)
    port_patches.gl_headers(gl_headers)
    flags += ['-I' + str(gl_headers), '-I' + str(gl / 'include'), '-I' + str(gl / 'src/nvparse'),
              '-I' + str(gl / 'src/atifs/include'), '-I' + str(gl / 'src/GLSL/include')]
    names = set(re.findall(r'\b(?:Ogre\w+|glew)\.cpp', (gl / 'src/Makefile.am').read_text()))
    sources = sorted(p for p in (gl / 'src').glob('*.cpp')
                     if p.name in names and args.filter in p.name)
    for folder in (gl / 'src/GLSL/src', gl / 'src/nvparse', gl / 'src/atifs/src'):
        names = set(re.findall(r'[\w.]+\.cpp', (folder / 'Makefile.am').read_text()))
        sources += sorted(p for p in folder.glob('*.cpp') if p.name in names and args.filter in p.name)
    if not args.filter or args.filter in 'BrowserGLSupport.cpp':
        sources += [HERE / 'BrowserGLSupport.cpp', HERE / 'BrowserGLCompat.cpp']
if args.stage in ('bootstrap', 'castle'):
    flags += ['-sUSE_FREETYPE=1', '-I' + str(ROOT / 'work/wasm-castle/deps/stb')]
    sources = [OGRE / 'OgreMain/src/OgreFont.cpp', OGRE / 'OgreMain/src/OgreRoot.cpp',
               OGRE / 'OgreMain/src/GLX/OgreTimer.cpp', OGRE / 'OgreMain/src/GLX/OgreErrorDialog.cpp',
               HERE / 'BrowserPlatform.cpp', HERE / 'BrowserImageCodec.cpp', HERE / 'browser_bootstrap.cpp']
if args.stage in ('rbx', 'support', 'castle'):
    native = OUT / 'native-include'
    g3d = OUT / 'g3d-include'
    port_patches.native_headers(ROOT, native)
    port_patches.g3d_headers(ROOT, g3d)
    flags += ['-I' + str(native), '-I' + str(g3d),
              '-I' + str(OUT / 'gl-include'),
              '-I' + str(ROOT / 'tools/rbxgs/Client/Rendering/g3d/IJG'),
              '-I' + str(ROOT / 'tools/rbxgs/Client/boost_1_34_1/src'),
              '-DNDEBUG', '-DNO_SSE', '-fms-extensions', '-D__forceinline=inline',
              '-DBOOST_HAS_THREADS', '-DBOOST_HAS_PTHREADS']
    names = ('OgreRbxEntity', 'OgreRbxSceneManager', 'OgreRbxSceneManagerSkybox2008', 'OgreRbxSky',
             'OgreRbxSubMesh', 'AppUnit67C_2008SubEntity', 'OgreRbxNodeSceneNode', 'OgreRbxNodeTwoDManager',
             'OgreGeometryBuilder2008', 'OgreGeometryCreate2008', 'OgreGeometryIndexed2008',
             'OgreAutoCylinderTransform', 'OgreGeometryContext2008', 'OgreGeometryVertexProvider2008',
             'OgreRbxEntityAppend2008', 'OgreRbxEntitySetMesh2008', 'OgreSubMeshNames2008',
             'OgreTwoDVertexBuffer2008', 'G3DLightingParameters', 'OgreRbxEntityCamera2008')
    sources = [ROOT / 'rebuild/2008-06/native-classes' / (name + '.cpp') for name in names
               if args.filter in name]
    if args.stage == 'support':
        names = ('OgreVisualEngine', 'G3DSystem', 'G3DBinaryInput', 'G3DVector3', 'G3DVector4',
                 'G3DColor3', 'G3DColor4', 'G3DMatrix3', 'G3Dg3dmath', 'G3Dfileutils',
                 'G3DCoordinateFrame', 'G3Dformat')
        sources = [ROOT / 'rebuild/2008-06/native-classes' / (name + '.cpp') for name in names
                   if args.filter in name]
        sources += [ROOT / 'tools/rbxgs/Client/boost_1_34_1/libs/thread/src' / name
                    for name in ('once.cpp', 'recursive_mutex.cpp', 'exceptions.cpp') if args.filter in name]
    if args.stage == 'castle':
        entry = OUT / 'src/browser_castle.cpp'
        port_patches.castle_entry(ROOT, HERE / 'castle_browser.in.cpp', entry)
        sources = [OGRE / 'OgreMain/src/OgreFont.cpp', OGRE / 'OgreMain/src/OgreRoot.cpp',
                   OGRE / 'OgreMain/src/GLX/OgreTimer.cpp', OGRE / 'OgreMain/src/GLX/OgreErrorDialog.cpp',
                   HERE / 'BrowserPlatform.cpp', HERE / 'BrowserImageCodec.cpp', entry]
if not sources:
    raise SystemExit('No matching source files')

def compile_source(source):
    staged = OUT / 'src' / source.name
    staged.parent.mkdir(exist_ok=True)
    text = source.read_text()
    if source.name == 'OgreStringConverter.cpp':
        text = text.replace(condition, condition + ' || defined(__EMSCRIPTEN__)')
    if source.name == 'nvparse.cpp':
        text = '#include <cstdlib>\n' + text
    if source.name == 'ps_1_4.cpp':
        # Preserve the original unsigned wrap in register-offset tables.
        text = re.sub(r',\s*([RTC]_BASE)\s*,', r', static_cast<unsigned>(\1),', text)
    if source.name == 'OgreRoot.cpp' and args.stage in ('bootstrap', 'castle'):
        # The demo uses loose asset files, not ZIP resource archives. Omit that
        # optional factory registration instead of inventing a ZIP provider.
        text = text.replace('mZipArchiveFactory = new ZipArchiveFactory();', 'mZipArchiveFactory = 0;')
        text = text.replace('ArchiveManager::getSingleton().addArchiveFactory( mZipArchiveFactory );', '')
    if args.stage == 'gl':
        text = port_patches.gl_source(source.name, text)
    if args.stage in ('rbx', 'support', 'castle'):
        text = port_patches.native_source(source.name, text)
    staged.write_text(text)
    command = [sys.executable, str(compiler), *flags, '-I' + str(source.parent),
               '-c', str(staged), '-o', str(objects / (source.stem + '.o'))]
    result = subprocess.run(command, env=env, text=True, capture_output=True)
    (logs / (source.stem + '.log')).write_text(result.stdout + result.stderr, encoding='utf-8')
    print(('PASS ' if result.returncode == 0 else 'FAIL ') + source.name, flush=True)
    return {'source': str(source.relative_to(ROOT)), 'sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
            'compiled': result.returncode == 0, 'command': command}

if args.link_only:
    if args.stage not in ('bootstrap', 'castle'):
        raise SystemExit('--link-only requires --stage bootstrap or castle')
    results = json.loads((OUT / (args.stage + '-compile.json')).read_text())
else:
    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        results = list(pool.map(compile_source, sources))
(OUT / (args.stage + '-compile.json')).write_text(json.dumps(results, indent=2))
print(f'{sum(r["compiled"] for r in results)}/{len(results)} core sources compiled')
if not args.filter and all(r['compiled'] for r in results):
    if args.stage in ('bootstrap', 'castle'):
        target = ROOT / 'work/wasm-castle/site'
        target.mkdir(exist_ok=True)
        emulation = OUT / 'browser-glemu.js'
        port_patches.emulation_library(SDK, emulation)
        command = [sys.executable, str(compiler), '-O1', '-g2', '--emit-symbol-map', '-fexceptions', '-sUSE_FREETYPE=1',
            '-sLEGACY_GL_EMULATION=1', '-sMIN_WEBGL_VERSION=2', '-sMAX_WEBGL_VERSION=2',
            '-sGL_ENABLE_GET_PROC_ADDRESS=1', '-sALLOW_MEMORY_GROWTH=1', '-sASSERTIONS=1',
            '-sFORCE_FILESYSTEM=1', '-Wl,--error-limit=0', '--js-library', str(emulation),
            '--preload-file', str(ROOT / 'work/wasm-castle/native-reference/assets') + '@/assets',
            '--shell-file', str(HERE / 'shell.html'),
            *[str(objects / (Path(r['source']).stem + '.o')) for r in results],
            *([str(OUT / 'libRbxOgre.a'), str(OUT / 'libRbxSupport.a')] if args.stage == 'castle' else []),
            str(OUT / 'libOgreGL.a'), str(OUT / 'libOgreMainCore.a'), '-o', str(target / 'index.html')]
        result = subprocess.run(command, env=env, capture_output=True, text=True)
        (logs / (args.stage + '-link.log')).write_text(result.stdout + result.stderr)
        print((result.stdout + result.stderr)[-4000:])
        (OUT / (args.stage + '-link.json')).write_text(json.dumps({'exit': result.returncode, 'command': command}, indent=2))
        raise SystemExit(result.returncode)
    archive = OUT / {'core': 'libOgreMainCore.a', 'gl': 'libOgreGL.a', 'rbx': 'libRbxOgre.a',
                     'support': 'libRbxSupport.a'}[args.stage]
    archive.unlink(missing_ok=True)
    subprocess.run([sys.executable, str(SDK / 'upstream/emscripten/emar.py'), 'rcs', str(archive),
                    *[str(objects / (Path(r['source']).stem + '.o')) for r in results]],
                   env=env, check=True)
    print('Built ' + str(archive))
raise SystemExit(0 if all(r['compiled'] for r in results) else 1)

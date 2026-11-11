"""Render a frame through the rebuilt engine's real renderer (OpenRBX 2007 RenderLib/RbxView, G3D/GL):
build tests/m4_snapshot.cpp against rbxgs-app + deps, run it, report where the PNG landed.
usage: python work/native-client/snapshot.py"""
import json, shutil, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild

client = '2008-06'
spec = rebuild.load_module(client, 'rbxgs-app')
ws = rebuild.workspace(client)
libs, pending = [ws / 'out' / spec['name'] / 'linked' / 'linked.lib'], list(spec['depends'])
while pending:
    d = rebuild.load_module(client, pending.pop(0))
    lib = ws / 'out' / d['name'] / 'linked' / 'linked.lib'
    if lib not in libs:
        libs.append(lib); pending += d.get('depends', [])
ov = rebuild.build_overlay(client, spec['name'], spec.get('overlay'))
inc = rebuild._overlaid([rebuild._spec_path(client, i) for i in spec['test_includes']], [], ov)[0]
openrbx = [rebuild.ROOT / 'work/upstream/OpenRBX/Client' / p for p in ('Rendering/RenderLib/include', 'RbxView/include', 'RbxView')]
out = ws / 'out' / 'tests' / 'm4_snapshot'
out.mkdir(parents=True, exist_ok=True)
fmod = rebuild.ROOT / 'tools/rbxgs/Client/fmod/api/fmodexL.dll'
if fmod.exists():
    shutil.copy(fmod, out / fmod.name)
import os
os.chdir(out)   # the test writes m4_snapshot.png, log.txt, fmod.log into its cwd
r = rebuild.link_test(client, 'm4_snapshot', libs + [rebuild.ROOT / 'tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib'],
                      includes=openrbx + [rebuild.ROOT / 'rebuild/2008-06/native-donor-2007'] + list(inc),
                      defines=spec['test_defines'], system_libs=('kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib',
                      'shell32.lib', 'ole32.lib', 'oleaut32.lib', 'comdlg32.lib', 'ws2_32.lib', 'winmm.lib', 'opengl32.lib',
                      'glu32.lib', 'setupapi.lib', 'shlwapi.lib', 'uuid.lib'))
print(json.dumps({k: r.get(k) for k in ('compiled', 'linked', 'ran', 'exit')}))
print(r.get('output', '')[-1200:])
print('unresolved', r.get('unresolved', [])[:15])
png = out / 'm4_snapshot.png'
print('PNG', png if png.exists() else 'none')

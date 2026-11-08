"""Diagnose native workspace insert link without modifying the active client."""
import hashlib
import json
import pathlib
import re
import subprocess
import sys

root = pathlib.Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import rebuild
snap = root/'rebuild/2008-06/out'
p6 = snap/'p6'
out = snap/'native-layouts/workspace-insert-link-trial'
out.mkdir(parents=True, exist_ok=True)
spec = rebuild.load_module('2008-06', 'player')
libs = [snap/spec['name']/'linked/linked.lib']
pending = list(spec['depends'])
while pending:
    dep = rebuild.load_module('2008-06', pending.pop(0))
    lib = snap/dep['name']/'linked/linked.lib'
    if lib not in libs:
        libs.append(lib)
        pending += dep.get('depends', [])
libs.append(snap/'XTP/linked/linked.lib')
libs += [rebuild.dll_import_lib('2008-06', dll) for dll in spec['import_dlls']]
objects = [p6/name for name in ['RobloxShell.obj','MyXTPCommandBars.obj','appmodul.obj','P6Engine.obj','P6Data.obj','roblox.res','mfc90.lib']]
objects += [snap/'native-layouts'/name for name in ['NativeFrameIconsFresh.obj','NativeFrameIconWidth.obj','NativeDHtmlDialog.obj','NativeAboutDialog.obj','NativeAboutDialogData.obj','NativeFileVersionInfo.obj','NativeGLCaps.obj','WorkspaceInsertNativeProfile.obj','NativeParserDestructor.obj','SelectionFront.obj','InstanceClassLookup.obj']]
system = ['gdiplus','kernel32','user32','gdi32','advapi32','shell32','ole32','oleaut32','comdlg32','comctl32','ws2_32','winmm','opengl32','glu32','imagehlp','version','wininet','dbghelp','psapi']
forced = '?insert@CWorkspace@@QAEXAAV?$basic_istream@DU?$char_traits@D@std@@@std@@_N@Z'
args = ['/nologo','/SUBSYSTEM:WINDOWS','/MACHINE:X86','/MAP:WorkspaceInsert.map','/OUT:WorkspaceInsert.exe','/NODEFAULTLIB:mfcs90.lib','/MANIFEST:NO','/INCLUDE:'+forced]
args += [str(path) for path in objects+libs] + [name+'.lib' for name in system] + ['/NODEFAULTLIB:'+name for name in rebuild.VENDOR_AUTOLINK]
code, log = rebuild.run(rebuild.toolchain(), 'link', args, out)
(out/'link.log').write_text(log)
errors = [line.strip() for line in log.splitlines() if 'unresolved external symbol' in line or 'already defined' in line]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'revision':subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),
           'script_sha256':sha(pathlib.Path(__file__)), 'link_exit':code, 'forced_symbol':forced,
           'objects':{str(path.relative_to(root)):sha(path) for path in objects},
           'link_flags':args, 'errors':errors,
           'scope':'Isolated diagnostic link only; profile-generated insert object; no runtime swap or P5/P6 gates.'}
exe = out/'WorkspaceInsert.exe'
if code == 0:
    receipt['exe_sha256'] = sha(exe)
    mapfile = out/'WorkspaceInsert.map'
    map_lines = mapfile.read_text(errors='replace').splitlines()
    expected = {'?insert@CWorkspace@@':'WorkspaceInsertNativeProfile.obj',
                '??1TextXmlParser@@QAE@XZ':'NativeParserDestructor.obj',
                '?front@Selection@RBX@@':'SelectionFront.obj',
                '?findFirstChildByClassName@Instance@RBX@@':'InstanceClassLookup.obj',
                '?getClassNameStr@Instance@RBX@@':'linked:Instance.obj'}
    receipt['map_symbols'] = {}
    for symbol, owner in expected.items():
        matches = [line.strip() for line in map_lines if len(line.split()) >= 2
                   and line.split()[1].startswith(symbol) and owner in line]
        assert len(matches) == 1, (symbol, matches)
        receipt['map_symbols'][symbol] = matches[0]
    receipt['map_sha256'] = sha(mapfile)
    receipt['libraries'] = {str(path):sha(path) for path in libs}
(root/'work/2008-06/shared-layouts/workspace-insert-link.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('link_exit:', code, 'errors:', len(errors))
for line in errors[:30]: print(line)

"""python dllimports.py: an import library for every function our link only has as a STUB although a DLL really
exports it (FMOD's C API in fmodex.dll, the GDI+ flat API, the CRT's _invalid_parameter*...). The probe's LIVE_STUBFIX
patched 14 of these at runtime; without the debugger the client crashed before its window appeared. Looks up each stub
name (_Name@N stdcall, _Name cdecl, ?decorated) in the code exports of the DLLs the original exe imports (run/ copies
first, then System32/SysWOW64), writes one .def per DLL and builds linkexp/extra_imports.lib; quicktest.py links it, and
its library filter keeps these names from being stubbed. Data exports are left out (they need __imp_ access)."""
import os, re, sys
from collections import defaultdict
from pathlib import Path
import pefile
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild
orig = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
orig.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
dlls = sorted({d.dll.decode() for d in orig.DIRECTORY_ENTRY_IMPORT} | {'gdiplus.dll'})   # GDI+ is loaded at runtime, not imported


def find(dll):
    for d in (H / 'run', Path(os.environ.get('SystemRoot', r'C:\Windows')) / 'SysWOW64'):
        if (d / dll).exists():
            return d / dll
    return None


exports = {}   # export name -> dll
for dll in dlls:
    p = find(dll)
    if not p:
        continue
    pe = pefile.PE(str(p), fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
    if not hasattr(pe, 'DIRECTORY_ENTRY_EXPORT'):
        continue
    code = [(s.VirtualAddress, s.VirtualAddress + s.Misc_VirtualSize) for s in pe.sections if s.Characteristics & 0x20000000]
    for e in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        if e.name and not e.forwarder and any(lo <= e.address < hi for lo, hi in code):
            exports.setdefault(e.name.decode('latin-1'), dll)
stubs = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    # names a previous extra_imports.lib already supplies stay in (the set only grows; else a rerun built an empty lib)
    if len(p) >= 4 and ':' in p[0] and ('stubs' in p[-1] or p[-1].startswith('extra_imports')):
        stubs.add(p[1])
libnames = set()   # names a LIBRARY member defines in the last map (owner 'lib:member', e.g. MSVCR90 imports)
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0] and ':' in p[-1] and p[-1].lower().startswith(('msvcr', 'msvcrt', 'msvcp', 'libcmt')):
        libnames.add(p[1])
per = defaultdict(list)   # dll -> .def export lines
aliases = []
for s in sorted(stubs):
    m = re.match(r'^_([A-Za-z_]\w*)@(\d+)$', s)
    if m and m.group(1) in exports:
        # undecorated in the .def (lib /def kept 'FMOD_System_Create@4' as the IMPORT name -> 0xC0000139 at load);
        # callers' stdcall symbol reaches it through an alias (the call stays stdcall, like the DLL function)
        per[exports[m.group(1)]].append(m.group(1)); aliases.append('%s=_%s' % (s, m.group(1))); continue
    m = re.match(r'^_([A-Za-z_]\w*)$', s)
    # cdecl spelling only for C-runtime exports: Win32 APIs are stdcall, and binding a cdecl call site to them
    # unbalances the stack (IsWindow/DeleteObject matched as _IsWindow)
    if m and m.group(1) in exports and not s.startswith(('_dat_', '_func_', '_g_', '_fn_')) and exports[m.group(1)].lower().startswith(('msvcr', 'msvcp')):
        per[exports[m.group(1)]].append(m.group(1)); continue
    # CRT exports whose own name starts with '_' (_invalid_parameter_noinfo): cdecl symbol = '_' + name
    # a stub spelled like the CRT EXPORT itself (_invalid_parameter_noinfo; the C symbol is __invalid_parameter_noinfo,
    # which msvcrt.lib already imports): alias to it, the CRT import library defines the real one
    if not s.startswith('__') and s.startswith('_') and ('_' + s) in libnames:
        aliases.append('%s=_%s' % (s, s)); continue
    if s.startswith('?') and s in exports:
        per[exports[s]].append(s)
# grow-only: a name the lib already supplies is owned by '<dll>:<dll>' in the next map, not a stub -> a rerun lost it
import json
_pf = H / 'auto/dllimports_found.json'
try:
    _prev = json.loads(_pf.read_text())
except (OSError, ValueError):
    _prev = {'per': {}, 'aliases': []}
_prev.setdefault('per', {}).setdefault('fmodex.dll', [])
if 'FMOD_System_Create' not in _prev['per']['fmodex.dll'] and 'fmodex.dll' in {exports.get('FMOD_System_Create')}:
    _prev['per']['fmodex.dll'].append('FMOD_System_Create'); _prev.setdefault('aliases', []).append('_FMOD_System_Create@4=_FMOD_System_Create')
for d_, ns_ in _prev['per'].items():
    per[d_].extend(n_ for n_ in ns_ if n_ not in per[d_])
aliases += [a_ for a_ in _prev.get('aliases', []) if a_ not in aliases]
_pf.write_text(json.dumps({'per': {d_: sorted(set(v_)) for d_, v_ in per.items()}, 'aliases': sorted(set(aliases))}, indent=0))
out = H / 'linkexp/extra_imports'
out.mkdir(exist_ok=True)
tc = rebuild.toolchain(21022)
libs = []
for dll, names in per.items():
    base = re.sub(r'\W', '_', dll.lower().replace('.dll', ''))
    df = out / (base + '.def')
    df.write_text('LIBRARY %s\nEXPORTS\n%s\n' % (dll, '\n'.join('    ' + n for n in sorted(set(names)))))
    lf = out / (base + '.lib')
    code_, text = rebuild.run(tc, 'lib', ['/nologo', '/machine:x86', '/def:' + str(df), '/out:' + str(lf)], out)
    if code_:
        print('lib failed for %s: %s' % (dll, text[:200])); continue
    libs.append(str(lf))
if libs:
    code_, text = rebuild.run(tc, 'lib', ['/nologo', '/out:' + str(H / 'linkexp/extra_imports.lib')] + libs, out)
    print('lib merge:', 'ok' if not code_ else text[:200])
(H / 'aliases_dllimports.txt').write_text(chr(10).join(aliases) + (chr(10) if aliases else ''))
print('stubbed names a DLL really exports: %d in %d DLLs -> linkexp/extra_imports.lib' % (sum(len(v) for v in per.values()), len(per)))
for dll, names in sorted(per.items(), key=lambda kv: -len(kv[1]))[:10]:
    print('  %-22s %4d  e.g. %s' % (dll, len(names), ', '.join(names[:3])[:90]))

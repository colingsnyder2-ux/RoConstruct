"""Donor-free link: every native object from a donor_free trial run + vendor libraries only (no content-without-donor-log
or P2*/owner libs, no tools/rbxgs objects). The linker's own unresolved-external list is the honest gap: it counts what is
reachable, not every symbol an unreferenced COMDAT mentions.

    python work/donorfree-route/donorfree_link.py [RESULTS_JSON]    (default: the last all-native trial run)
Writes work/donorfree-route/link/{donorfree.rsp,link.log,unresolved.json}. Diagnostic only: no run, no gate.
"""
import json, os, re, subprocess, sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rebuild   # noqa: E402
sys.path.insert(0, str(Path(__file__).parent))

BASE = ROOT / 'rebuild/2008-06'
OUT = ROOT / 'work/donorfree-route/link'
OUT.mkdir(parents=True, exist_ok=True)
VENDOR = ['Boost', 'G3D', 'G3D-GL', 'Lua', 'LuaCpp', 'MfcAtl', 'RakNet', 'XTP', 'libpng', 'zlib-winapi', 'zlib']
SYSTEM = ['kernel32', 'user32', 'gdi32', 'advapi32', 'shell32', 'ole32', 'oleaut32', 'comdlg32', 'comctl32', 'ws2_32',
          'winmm', 'setupapi', 'winhttp', 'sensapi', 'iphlpapi', 'dinput8', 'opengl32', 'glu32', 'imagehlp', 'version', 'wininet', 'dbghelp', 'psapi', 'gdiplus']


def results_path():
    if len(sys.argv) > 1:
        return Path(sys.argv[1])
    log = (BASE / 'out/donorfree/runner-all-native.log').read_text().strip().splitlines()[-1]
    return Path(json.loads(log)['results'])


from donorfree_link_parse import parse_unresolved   # noqa: E402


def main():
    rows = json.loads(results_path().read_text())
    rows = rows if isinstance(rows, list) else rows['results']
    drop = {d.lower() for d in os.environ.get('DROP_SOURCES', '').split(';') if d}   # sources recompiled after the trial
    objs = [r['object'] for r in rows if r['status'] == 'complete' and Path(r['object']).exists() and Path(r['source']).name.lower() not in drop]
    _ex = [o for o in os.environ.get('EXTRA_OBJS', '').split(';') if o and Path(o).exists()]   # objects compiled after the trial
    # The converted constructor defines incomplete MainLogManager vtables; select the native constructor instead.
    _ex = [o for o in _ex if not (os.path.join('renamed', 'obj') in os.path.normpath(o) and Path(o).name.lower() == '0042a1c0.obj')]
    _conv = [o for o in _ex if os.path.join('renamed', 'obj') in os.path.normpath(o)]
    _cs = set(_conv)
    objs = _conv + objs + [o for o in _ex if o not in _cs]   # exact converted objects first: with /FORCE:MULTIPLE the first definition wins
    args = ['/nologo', '/SUBSYSTEM:WINDOWS', '/MACHINE:X86', '/OPT:REF', '/FORCE:MULTIPLE', '/FORCE:UNRESOLVED',
            '/MANIFEST:NO', '/NODEFAULTLIB:mfcs90.lib', '/MAP:' + str(OUT / 'donorfree.map'), '/OUT:' + str(OUT / 'donorfree.exe')]
    args += ['/NODEFAULTLIB:' + n for n in ('zlib.lib', 'G3D.lib', 'GLG3D.lib', 'sdl.lib', 'sdlmain.lib', 'glut32.lib', 'ToolkitPro1122vc90DS.lib', 'ToolkitPro1122vc90S.lib', 'ToolkitPro1122vc90LDS.lib', 'LIBCMT', 'LIBCMT.lib', 'libcpmt', 'libcpmt.lib', 'libboost_date_time-vc80-mt-1_34_1.lib', 'libboost_iostreams-vc80-mt-1_34_1.lib', 'libboost_signals-vc80-mt-1_34_1.lib', 'libboost_signals-vc90-mt-1_35.lib', 'libboost_thread-vc80-mt-1_34_1.lib', 'libboost_zlib-vc80-mt-1_34_1.lib')]   # analogs' auto-link pragmas: boost is in the vendor libs; static CRT would mix with /MD
    # converted analogs carry auto-link pragmas for libraries we don't link (XTP 15, boost, static CRT): ignore them all
    _dl_cache = OUT / 'defaultlibs.json'
    _keep = {x.lower() for x in [s_ + '.lib' for s_ in SYSTEM] + ['msvcrt.lib', 'msvcrt', 'msvcprt.lib', 'msvcprt', 'oldnames', 'oldnames.lib',
                                                                 'mfc90.lib', 'uuid.lib', 'atls.lib', 'msimg32.lib', 'shlwapi.lib', 'winspool.lib']}
    try:
        _dls = set(json.loads(_dl_cache.read_text()))
    except Exception:
        _dls = set()
    for _o in Path(__file__).parent.joinpath('renamed/obj').glob('*.obj'):
        if _o.stat().st_mtime > (_dl_cache.stat().st_mtime if _dl_cache.exists() else 0):
            _dls |= {m.decode() for m in re.findall(rb'/DEFAULTLIB:"?([A-Za-z0-9_.\-]+)"?', _o.read_bytes())}
    _dl_cache.write_text(json.dumps(sorted(_dls)))
    args += ['/NODEFAULTLIB:' + d for d in sorted(_dls) if d.lower() not in _keep]
    for alias_name in ('aliases.txt', 'aliases_auto.txt', 'aliases_renamed.txt', 'aliases_long.txt', 'aliases_twins.txt', 'aliases_qualname.txt', 'aliases_draftimp.txt'):   # lines: symbol=target (draft helper names -> real functions), via /alternatename
        alias_file = Path(__file__).parent / alias_name
        if alias_file.exists():
            args += ['/alternatename:' + l.strip() for l in alias_file.read_text().splitlines() if '=' in l and not l.startswith('#')]
            # an alias target that only lives in an import library is not pulled in by /alternatename: force it
            args += ['/INCLUDE:' + l.strip().split('=', 1)[1] for l in alias_file.read_text().splitlines()
                     if '=' in l and not l.startswith('#') and l.strip().split('=', 1)[1].startswith('__imp_')]
    args += [str(o) for o in objs]
    args.append(str(BASE / 'out/native-current-audit/mfc90.lib'))   # import thunks first: static MFC copies in the vendor libs have their own module state
    for v in VENDOR:
        lib = BASE / 'out' / v / 'linked/linked.lib'
        if lib.exists():
            args.append(str(lib))
    res = BASE / 'out/native-current-audit/roblox.res'   # the original exe's resources (dialogs, icons, menus)
    if res.exists():
        args.append(str(res))
    for imp in ('rgmain.lib', 'rgdx.lib', 'fmodex.lib'):
        p = BASE / 'out/importlibs' / imp
        if p.exists():
            args.append(str(p))
    args += [s + '.lib' for s in SYSTEM]
    # vendor DirectX SDK (Nov 2007) GUID data: GUID_SysMouse etc. (else a zero-filled stub makes CreateDevice fail)
    args.append(str(ROOT / 'tools/openrbx/3rdparty/Microsoft DirectX SDK (November 2007)/Lib/x86/dxguid.lib'))
    rsp = OUT / 'donorfree.rsp'
    rsp.write_text('\n'.join('"%s"' % a for a in args) + '\n')
    if os.environ.get('ROC_LINK_DISCOVER'):   # plain link only needs the unresolved list: lld gives it in seconds
        r = subprocess.run([sys.executable, str(Path(__file__).parent / 'lld_link.py'), '--discover', '--xtp-first'], capture_output=True, text=True)
        print(r.stdout.strip())
        return
    if os.environ.get('ROC_USE_LLD'):   # opt-in: links in ~5 s but the lld exe still crashes at startup (2026-11-23) -- lld final link (~10 s vs ~60 s); the earlier static-init crash was the helper-copy bug, not lld. lld (~5 s vs ~60 s for link.exe); link.exe if lld fails
        r = subprocess.run([sys.executable, str(Path(__file__).parent / 'lld_link.py'), '--xtp-first'], capture_output=True, text=True)
        if r.returncode == 0 and (OUT / 'donorfree.exe').exists():
            und = sorted(set(re.findall(r'undefined symbol: (\S+)', (OUT / 'lld.log').read_text(errors='replace'))))
            (OUT / 'link.log').write_text(''.join('lld.obj : error LNK2001: unresolved external symbol %s' % u + chr(10) for u in und))
            print(json.dumps({'objects': len(objs), 'exit': 0, 'linker': 'lld', 'unresolved': len(und)}))
            return
    code, log = rebuild.run(rebuild.toolchain(21022), 'link', ['@' + str(rsp)], OUT)
    (OUT / 'link.log').write_text(log)
    unresolved = parse_unresolved(log)
    dup = len(re.findall(r'LNK2005', log))
    bucket = Counter('vendor/runtime' if re.search(r'@(boost|G3D|std|Ogre|ATL|lua)@|^_|CXTP|CWnd|CString|AFX', s) else
                     'RBX' if '@RBX@@' in s else 'other' for s in unresolved)
    (OUT / 'unresolved.json').write_text(json.dumps({'objects': len(objs), 'link_exit': code, 'duplicates_forced': dup,
                                                     'unresolved': len(unresolved), 'buckets': bucket,
                                                     'symbols': unresolved}, indent=1))
    print(json.dumps({'objects': len(objs), 'exit': code, 'duplicates_forced': dup, 'unresolved': len(unresolved),
                      'buckets': bucket}, indent=1))


if __name__ == '__main__':
    main()

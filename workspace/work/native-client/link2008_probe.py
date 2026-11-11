"""Pure-2008 link probe: link ONLY byte-proved 2008 converter objects (work/native-client/ogre/batches/**/renamed)
plus real libraries (recipe-built XTP/Scintilla, MFC 9.0, CRT, system). No 2007 rbxgs donor engine.
Measures how much of the 2008 client already resolves on its own; it is a metric, never a build candidate.

  python work/native-client/link2008_probe.py        -> work/native-client/link2008/{probe.json,link.txt}

Reads converter outputs only; writes only work/native-client/link2008/.  Never runs the exe.
"""
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild  # noqa: E402

OUT = ROOT / 'work/native-client/link2008'
BATCHES = ROOT / 'work/native-client/ogre/batches'
CLIENT = '2008-06'


def symbols(data):
    """{name: 'def'|'undef'} for external symbols of one COFF object."""
    _sc = symbols.__dict__.setdefault('sc', {})
    if not _sc:
        exec(open(ROOT / 'work/rbxgs-rebase/symcheck.py', encoding='utf-8').read().split('def archive_symbols')[0], _sc)
    return {n: ('undef' if k == 'undef' else 'def') for n, k in _sc['symbols'](data).items()}


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    # Newest renamed object per address across every scope/batch (re-runs supersede older output).
    newest = {}
    for path in BATCHES.rglob('renamed/*.obj'):
        key = path.stem
        if key != 'roc_data' and (key not in newest or path.stat().st_mtime > newest[key].stat().st_mtime):
            newest[key] = path
    data_objs = sorted(BATCHES.rglob('renamed/roc_data.obj'), key=lambda p: p.stat().st_mtime, reverse=True)
    # One owner per definition: first object wins, later copies get the symbol stripped to an undefined ref.
    strip = OUT / 'stripped'
    strip.mkdir(exist_ok=True)
    owned, kept, stripped = set(), [], 0
    for path in [newest[k] for k in sorted(newest)] + data_objs:
        raw = path.read_bytes()
        mine = {n for n, k in symbols(raw).items() if k == 'def'}
        drop = mine & owned
        if mine and mine <= owned:
            continue                                     # nothing new in it
        if drop:
            raw = rebuild.strip_symbols(raw, drop=drop)
            path = strip / ('%s-%s.obj' % (path.parent.parent.name, path.stem))
            path.write_bytes(raw)
            stripped += 1
        owned |= mine
        kept.append(path)
    ws = rebuild.workspace(CLIENT)
    mfc = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/lib'
    libs = [p for p in (ws / 'out/XTP/linked/linked.lib', ws / 'out/Scintilla/linked/linked.lib',
                        rebuild.mfc_import_lib(CLIENT), mfc / 'mfcs90.lib', mfc / 'atls.lib') if Path(p).is_file()]
    system = ['msvcrt.lib', 'msvcprt.lib', 'kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib',
              'ole32.lib', 'oleaut32.lib', 'uuid.lib', 'comdlg32.lib', 'comctl32.lib', 'ws2_32.lib', 'winmm.lib',
              'opengl32.lib', 'glu32.lib', 'imagehlp.lib', 'version.lib', 'wininet.lib', 'dbghelp.lib', 'psapi.lib',
              'shlwapi.lib', 'urlmon.lib', 'oledlg.lib', 'msimg32.lib', 'sensapi.lib']
    rsp = OUT / 'link.rsp'
    rsp.write_text('\n'.join('"%s"' % p for p in kept + libs) + '\n')
    code, text = rebuild.run(rebuild.toolchain(), 'link', ['/nologo', '/SUBSYSTEM:WINDOWS', '/MACHINE:X86',
                                                           '/OUT:Roblox2008-pure.exe', '/MAP:Roblox2008-pure.map',
                                                           '@' + str(rsp)] + system, OUT)
    (OUT / 'link.txt').write_text(text, encoding='utf-8')
    unres = sorted(set(rebuild.unresolved_symbols(text)))
    dups = sorted(set(re.findall(r'error LNK2005:\s*(.*?)\s+already defined in', text)))
    code_funcs = {a for a, r in match._functions(CLIENT).items() if r.get('kind') == 'code'}
    covered = {k for k in newest if k in code_funcs}
    size = lambda addrs: sum(len(match.target(CLIENT, a)[0]) for a in addrs)
    total = size(code_funcs)
    groups = collections.Counter(
        'data/roc' if s.startswith(('_roc_', 'roc_')) else 'vtable/rtti' if s.startswith(('??_7', '??_R')) else
        'placeholder fn' if 'roc_fn_' in s else 'named fn/data' for s in unres)
    report = {'scope': 'pure-2008 link probe: converter objects + real libs, no 2007 donor engine; metric only',
              'link_exit_code': code, 'objects': len(kept), 'stripped_duplicates': stripped,
              'covered_functions': len(covered), 'covered_code_bytes': size(covered), 'total_code_bytes': total,
              'covered_pct': round(100 * size(covered) / total, 2), 'unresolved': len(unres),
              'unresolved_kinds': dict(groups), 'duplicates': len(dups), 'unresolved_sample': unres[:40],
              'duplicates_sample': dups[:20]}
    (OUT / 'probe.json').write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps({k: v for k, v in report.items() if not k.endswith('sample')}, indent=1))


if __name__ == '__main__':
    main()

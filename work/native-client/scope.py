"""List the functions in a native-recovery scope, with their recovery status.

  python work/native-client/scope.py rbxapp            -> summary + work/native-client/scope-rbxapp.json
  python work/native-client/scope.py rbxapp --todo     -> only classes with functions not yet byte-exact
  python work/native-client/scope.py rbxapp --queue 15 -> random workable new classes (no almost-done files, leased skipped)

rbxapp = all Roblox code: the MFC/COM app classes (CRobloxView, CMainFrame ...) and the RBX:: engine classes. Everything
that is not a library (XTP, ATL, stock MFC, G3D, Ogre, boost, std, Lua, RakNet ...). Template instantiations are skipped. Names come from work/2008-06/identity-registry.json (decorated, non-placeholder);
status comes from the newest prove-out manifests (exact / draft) and the native-classes sources.
"""
import argparse
import collections
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'
CACHE = HERE / 'scope-cache.json'
LIBRARY = re.compile(r'G3D|Ogre|XTP|CXT[A-Z]|boost|^std|ATL|Scint|[Ll]ua|Rak|CCom|CProxy|\?\$|CSHA1|^_|lib(png|jpeg)|zlib')

MFC = re.compile(r'^(?:[A-Z0-9_$]*V)?C(?:Wnd|FrameWnd|MDIFrameWnd|MDIChildWnd|Edit|Static|ListBox|ComboBox|Button|Brush|Pen|Rgn|Rect|Point|Size|PtrList|PtrArray|ObList|StringList|StringArray|Ole\w*|CmdUI|EnabledCmdUI|Dialog|View|Document|WinApp|WinThread|Object|Archive|File|Exception|DC|ClientDC|PaintDC|WindowDC|GdiObject|Bitmap|Font|Menu|ImageList|ToolBar|StatusBar|ControlBar|SplitterWnd|ScrollView|FormView|EditView|HtmlView|HtmlEditView|DHtmlDialog|PropertySheet|PropertyPage|TreeCtrl|ListCtrl|TabCtrl|SpinButtonCtrl|ProgressCtrl|SliderCtrl|DockState|DockBar|DocTemplate|SingleDocTemplate|MultiDocTemplate|DocManager|MemFile|String|Map\w+|Array|CommandLineInfo|RecentFileList|Mini\w*Wnd)$')   # stock MFC classes, same list as docs/index.html
CHECKBOX = re.compile(r'^C(CheckListBox|CmdTarget|CCmdTarget)$')   # more stock MFC names the site list lacks


def demangled(sym):
    """?f@C@NS@@... -> ['NS', 'C', 'f'] (outermost first); None for C names."""
    if not sym.startswith('?') or sym.startswith('??'):
        return None
    return sym[1:].split('@@')[0].split('@')[::-1]


def app_functions():
    registry = json.loads(REGISTRY.read_text())
    out = {}
    for address, row in registry.items():
        if not isinstance(row, dict) or row.get('placeholder') or row.get('kind') != 'code':
            continue
        name = str(row.get('name') or '')
        if name.startswith('?') and '?$' in name:        # template instantiation: keep Roblox ones, label them by template
            if re.search(r'RBX|rbx', name) and not LIBRARY.search(name.replace('?$', '')):
                out[address] = ('<template>', name)
            continue
        parts = demangled(name)
        if not parts or len(parts) < 2 or LIBRARY.search('::'.join(parts)) or MFC.match(parts[-2]) or CHECKBOX.match(parts[-2]):
            continue
        out[address] = (parts[-2], '::'.join(parts))
    return out


def exact_addresses():
    """Addresses with a byte-exact native body in any local receipt or prove run (roc.integration_site.inactive_code)."""
    import sys
    sys.path.insert(0, str(ROOT))
    from roc.integration_site import inactive_code
    return {a for a, v in inactive_code(ROOT).items() if v[1]}


def load_state(refresh):
    """Names are cached against the registry's size+mtime; exact addresses for 30 minutes (the slow receipt walk)."""
    import time
    stat = REGISTRY.stat()
    key = [stat.st_size, int(stat.st_mtime)]
    cache = {}
    try:
        cache = json.loads(CACHE.read_text())
    except (OSError, ValueError):
        pass
    if refresh or cache.get('registry') != key:
        cache = {'registry': key, 'functions': {a: list(v) for a, v in app_functions().items()}, 'exact_at': 0}
    if refresh or time.time() - cache['exact_at'] > 1800:
        cache['exact'] = sorted(exact_addresses())
        cache['exact_at'] = time.time()
    CACHE.write_text(json.dumps(cache))
    return cache['functions'], set(cache['exact'])


def leased_stems():
    try:
        rows = json.loads((ROOT / 'work/leases-cache.json').read_text()).get('leases', [])
    except (OSError, ValueError):
        return set()
    import time
    return {Path(p).stem for r in rows if r.get('expires', 0) > time.time() for p in r.get('patterns', [])} | {r.get('name', '') for r in rows}


def native_stems():
    return {p.stem for p in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp')}


def queue(classes, limit):
    """Rank unfinished classes: extend partial native files first, then small classes, skipping leased and huge ones."""
    have, leased = native_stems(), leased_stems()
    rows = []
    for cls, (total, done) in classes.items():
        left = total - done
        if left <= 0 or cls == '<template>':
            continue
        bare = cls.lstrip('C') if cls.startswith('C') and len(cls) > 1 and cls[1].isupper() else cls
        stems = [s for s in have if s.lower() in (cls.lower(), bare.lower(), cls.lower() + '2008', bare.lower() + '2008')]
        busy = any(s in leased or 'commit-' + s in leased for s in stems) or cls in leased
        partial = bool(stems) and done > 0
        rows.append((busy, not partial, left > 60, left, cls, total, done, stems))
    import random
    # Random, workable: classes with no native file yet and 3-40 functions left. Partial/almost-done files are where everyone
    # is stuck, so they are only used as a fallback.
    fresh = [r for r in rows if not r[0] and not r[7] and r[5 + 1] * 2 <= r[5] and 3 <= r[3] <= 40]
    fallback = [r for r in rows if not r[0] and r not in fresh and r[3] <= 60]
    random.shuffle(fresh)
    random.shuffle(fallback)
    print('%-4s %-34s %9s  %s' % ('#', 'class', 'exact', 'note'))
    shown = 0
    for busy, not_partial, huge, left, cls, total, done, stems in fresh + fallback:
        note = ('has file, still partial: hard' if stems else 'new class, random pick')
        shown += 1
        print('%-4d %-34s %4d/%-4d  %s' % (shown, cls, done, total, note))
        if shown >= limit:
            break


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('scope', choices=['rbxapp'])
    ap.add_argument('--todo', action='store_true', help='only classes with functions not yet byte-exact')
    ap.add_argument('--queue', type=int, metavar='N', help='ranked list of the next N classes to work on (skips leased classes)')
    ap.add_argument('--refresh', action='store_true', help='ignore the cache')
    args = ap.parse_args()
    functions, exact = load_state(args.refresh)
    classes = collections.defaultdict(lambda: [0, 0])
    for address, (cls, _) in functions.items():
        classes[cls][0] += 1
        classes[cls][1] += address.lower().zfill(8) in exact
    (HERE / 'scope-rbxapp.json').write_text(json.dumps(
        {'functions': {a: n for a, (_, n) in sorted(functions.items())}, 'classes': {c: v for c, v in sorted(classes.items())}}, indent=1))
    print('%d rbxapp functions in %d classes; %d byte-exact in a local proof' % (
        len(functions), len(classes), sum(v[1] for v in classes.values())))
    if args.queue:
        return queue(classes, args.queue)
    for cls, (total, done) in sorted(classes.items(), key=lambda kv: kv[1][1] - kv[1][0]):
        if not args.todo or done < total:
            print('%-34s %3d / %3d' % (cls, done, total))


if __name__ == '__main__':
    main()

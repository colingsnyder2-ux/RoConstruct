"""python cmdcensus.py [EXE] [--orig run/RobloxOrig.exe] [--jobs 4] [--ids auto|FILE] [--limit N]
Crash census of every UI command id (menus, toolbars, string-table prompts of the ORIGINAL exe) in ours vs the original.
Writes auto/cmdcensus_ids.json and auto/cmdcensus.json. --ids FILE: JSON list of ints (or of {id,...} rows)."""
import argparse, ctypes, ctypes.wintypes as w, json, os, struct, subprocess, time
from collections import Counter
from multiprocessing import Pool
from pathlib import Path
H = Path(__file__).parent
ORIG_SRC = H / '../../clients/2008-06/Roblox.exe'


def _res(pe, rtype):
    if not hasattr(pe, 'DIRECTORY_ENTRY_RESOURCE'): return
    for e in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        if e.id == rtype:
            for n in e.directory.entries:
                d = n.directory.entries[0].data.struct
                yield n.id, pe.get_data(d.OffsetToData, d.Size)


def parse_menu(data):
    ver, cb = struct.unpack_from('<HH', data, 0)
    out, pos = [], [4 + cb]
    if ver != 0: return out

    def text():
        p = pos[0]; e = p
        while data[e:e + 2] != b'\0\0': e += 2
        pos[0] = e + 2
        return data[p:e].decode('utf-16le').replace('&', '').split('\t')[0]

    def walk(path):
        while pos[0] < len(data):
            fl, = struct.unpack_from('<H', data, pos[0]); pos[0] += 2
            if fl & 0x10:
                walk(path + [text()])
            else:
                mid, = struct.unpack_from('<H', data, pos[0]); pos[0] += 2
                t = text()
                if mid: out.append((mid, '/'.join(path + [t])))
            if fl & 0x80: return
    walk([]); return out


def collect():
    import pefile
    pe = pefile.PE(str(ORIG_SRC.resolve()))
    ids = {}
    for rid, d in _res(pe, 4):
        try:
            for i, lab in parse_menu(d): ids.setdefault(i, f'menu {rid}: {lab}')
        except Exception as ex: print('menu', rid, 'parse fail', ex)
    for rid, d in _res(pe, 241):
        ver, wd, ht, n = struct.unpack_from('<4H', d, 0)
        for i in struct.unpack_from(f'<{n}H', d, 8):
            if i: ids.setdefault(i, f'toolbar {rid}')
    for blk, d in _res(pe, 6):
        p = 0
        for k in range(16):
            ln, = struct.unpack_from('<H', d, p); p += 2
            s = d[p:p + ln * 2].decode('utf-16le'); p += ln * 2
            i = (blk - 1) * 16 + k
            if ln and 0x8000 <= i <= 0xEFFF: ids.setdefault(i, 'str: ' + s.split('\n')[0][:60])
    return [{'id': i, 'label': l} for i, l in sorted(ids.items())]


u = ctypes.WinDLL('user32', use_last_error=True)
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
u.SendMessageTimeoutW.argtypes = [w.HWND, w.UINT, w.WPARAM, w.LPARAM, w.UINT, w.UINT, ctypes.POINTER(ctypes.c_size_t)]
u.PostMessageW.argtypes = [w.HWND, w.UINT, w.WPARAM, w.LPARAM]


def wins(pid):
    res = []
    def cb(h, _):
        p = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p))
        if p.value == pid and u.IsWindowVisible(h):
            c = ctypes.create_unicode_buffer(64); u.GetClassNameW(h, c, 64)
            t = ctypes.create_unicode_buffer(256); u.GetWindowTextW(h, t, 256)
            res.append((h, c.value, t.value))
        return True
    u.EnumWindows(P(cb), 0); return res


def dialogs(pid): return [(h, t) for h, c, t in wins(pid) if c == '#32770']


def hung(h):
    r = ctypes.c_size_t()
    return not u.SendMessageTimeoutW(h, 0, 0, 0, 2, 2000, ctypes.byref(r))


def run(exe, cid):
    exe = os.path.abspath(exe)
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
    try:
        main, t0 = None, time.time()
        while time.time() - t0 < 40 and p.poll() is None and not main:
            f = [h for h, c, t in wins(p.pid) if c.startswith('Afx:')]
            if f: main = f[0]
            else: time.sleep(0.3)
        if not main: return {'r': 'nowindow' if p.poll() is None else f'died-early {p.poll() & 0xFFFFFFFF:#x}'}
        time.sleep(1); u.PostMessageW(main, 0x111, 0xE100, 0); time.sleep(5)
        if p.poll() is not None: return {'r': f'died-at-new {p.poll() & 0xFFFFFFFF:#x}'}
        before = {t for _, t in dialogs(p.pid)}
        u.PostMessageW(main, 0x111, cid, 0); time.sleep(4)
        rc = p.poll()
        if rc is not None: return {'r': 'DEAD', 'exit': f'{rc & 0xFFFFFFFF:#x}'}
        ds = dialogs(p.pid)
        new = sorted({t for _, t in ds} - before)
        for h, t in ds: u.PostMessageW(h, 0x10, 0, 0)
        return {'r': 'HUNG' if hung(main) else 'alive', 'dialogs': new}
    finally:
        if p.poll() is None: p.kill()


def job(a):
    cid, orig, ours = a
    o = run(orig, cid)
    s = run(ours, cid) if o['r'] == 'alive' else None
    return cid, o, s


def verdict(o, s):
    if o['r'] != 'alive': return 'orig-bad'
    if s['r'] == 'DEAD' or s['r'].startswith('died') or s['r'] == 'nowindow': return 'CRASH'
    if s['r'] == 'HUNG': return 'HUNG'
    return 'DIALOG-DIFF' if o['dialogs'] != s['dialogs'] else 'ok'


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('exe', nargs='?', default='run/RobloxQT.exe')
    ap.add_argument('--orig', default='run/RobloxOrig.exe')
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--ids', default='auto')
    ap.add_argument('--limit', type=int)
    a = ap.parse_args()
    idf = H / 'auto/cmdcensus_ids.json'
    if a.ids == 'auto':
        rows = collect(); idf.write_text(json.dumps(rows, indent=1))
    else:
        known = {r['id']: r['label'] for r in json.loads(idf.read_text())} if idf.exists() else {}
        rows = [{'id': x if isinstance(x, int) else x['id']} for x in json.loads(Path(a.ids).read_text())]
        for r in rows: r['label'] = known.get(r['id'], '')
    if a.limit: rows = rows[:a.limit]
    print(len(rows), 'ids', flush=True)
    import ieclean; t0 = time.time(); ieclean.clean()
    out, lab = [], {r['id']: r['label'] for r in rows}
    try:
        with Pool(a.jobs) as pool:
            for cid, o, s in pool.imap_unordered(job, [(r['id'], a.orig, a.exe) for r in rows]):
                v = verdict(o, s); out.append({'id': cid, 'label': lab[cid], 'orig': o, 'ours': s, 'verdict': v})
                print(f'{cid:#06x} {v:12} {lab[cid][:50]:50} orig={o["r"]} ours={s and s["r"]} {s and s.get("dialogs") or ""}', flush=True)
                (H / 'auto/cmdcensus.json').write_text(json.dumps(sorted(out, key=lambda r: r['id']), indent=1))
    finally:
        ieclean.clean(t0)
    print(Counter(r['verdict'] for r in out))
    for r in sorted(out, key=lambda r: r['id']):
        if r['verdict'] in ('CRASH', 'HUNG'): print(f"{r['verdict']} {r['id']:#06x} {r['label']} {r['ours']}")

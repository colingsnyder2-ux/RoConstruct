"""python dllsym.py ADDR [ADDR...]: name DLL addresses from a probe (72e4616c -> msvcr90.dll!strlen+0x1c). Starts the
client briefly to read each 32-bit module's load base (system DLL bases are fixed per boot), then picks the nearest
export below the address; mfc90 ordinals become decorated names via renamed/ordinals.json."""
import bisect, ctypes, ctypes.wintypes as w, json, os, subprocess, sys, time
from pathlib import Path
H = Path(__file__).parent
k, ps = ctypes.WinDLL('kernel32'), ctypes.WinDLL('psapi')


def modules(exe):
    p = subprocess.Popen([exe], cwd=os.path.dirname(exe))
    mods = {}
    try:
        for _ in range(100):
            time.sleep(0.02)
            h = k.OpenProcess(0x0410, False, p.pid)
            arr = (ctypes.c_void_p * 1024)(); need = w.DWORD()
            if ps.EnumProcessModulesEx(h, arr, ctypes.sizeof(arr), ctypes.byref(need), 0x01):
                for i in range(need.value // 8):
                    nm = ctypes.create_unicode_buffer(300)
                    ps.GetModuleFileNameExW(h, ctypes.c_void_p(arr[i]), nm, 300)
                    mods[arr[i]] = nm.value
            k.CloseHandle(h)
            if p.poll() is not None:
                break
    finally:
        p.kill()
    return mods


def main():
    import pefile
    exe = os.environ.get('PROBE_EXE') or str(H / 'run/RobloxQT.exe')
    mods = sorted(modules(exe).items())
    om = json.load(open(H / 'renamed/ordinals.json')).get('mfc90.dll', {})
    cache = {}
    for a in [int(x, 16) for x in sys.argv[1:]]:
        i = bisect.bisect_right([b for b, _ in mods], a) - 1
        if i < 0:
            print('%08x ?' % a); continue
        base, path = mods[i]
        if path not in cache:
            pe = pefile.PE(path, fast_load=True)
            pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
            ex = sorted((e.address, (e.name.decode() if e.name else om.get(str(e.ordinal), '#%d' % e.ordinal)))
                        for e in getattr(pe, 'DIRECTORY_ENTRY_EXPORT', None).symbols) if hasattr(pe, 'DIRECTORY_ENTRY_EXPORT') else []
            cache[path] = (ex, pe.OPTIONAL_HEADER.SizeOfImage)
        ex, size = cache[path]
        off = a - base
        if off >= size:
            print('%08x ? (past %s)' % (a, os.path.basename(path))); continue
        j = bisect.bisect_right([r for r, _ in ex], off) - 1
        print('%08x %s!%s+%x' % (a, os.path.basename(path), ex[j][1][:100] if j >= 0 else '?', off - (ex[j][0] if j >= 0 else 0)))


if __name__ == '__main__':
    main()

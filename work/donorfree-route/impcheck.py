"""python impcheck.py [EXE]: walk the import directory by hand (pefile stops early on this exe) and check every imported
name/ordinal against the DLL's real exports (run/ first, then SysWOW64; WinSxS-only DLLs like mfc90 are skipped).
A missing entry is exactly what makes the loader fail with STATUS_ENTRYPOINT_NOT_FOUND (0xC0000139) at startup."""
import os, struct, sys
from pathlib import Path
import pefile
H = Path(__file__).parent
exe = sys.argv[1] if len(sys.argv) > 1 else str(H / 'run/RobloxQT.exe')
pe = pefile.PE(exe, fast_load=True)
img = pe.get_memory_mapped_image()
rva, size = pe.OPTIONAL_HEADER.DATA_DIRECTORY[1].VirtualAddress, pe.OPTIONAL_HEADER.DATA_DIRECTORY[1].Size
cstr = lambda r: bytes(img[r:img.find(b'\0', r)]).decode('latin-1')


def exports(dll):
    for d in (H / 'run', Path(os.environ.get('SystemRoot', r'C:\Windows')) / 'SysWOW64'):
        if (d / dll).exists():
            q = pefile.PE(str(d / dll), fast_load=True)
            q.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
            if not hasattr(q, 'DIRECTORY_ENTRY_EXPORT'):
                return set(), set()
            return ({e.name.decode('latin-1') for e in q.DIRECTORY_ENTRY_EXPORT.symbols if e.name},
                    {e.ordinal for e in q.DIRECTORY_ENTRY_EXPORT.symbols})
    return None


bad = 0
for k in range(0, size, 20):
    oft, ts, fwd, name, ft = struct.unpack_from('<IIIII', img, rva + k)
    if not name:
        break
    dll = cstr(name)
    ex = exports(dll)
    thunks = oft or ft
    miss, n = [], 0
    while True:
        t = struct.unpack_from('<I', img, thunks + 4 * n)[0]
        if not t:
            break
        n += 1
        if ex is None:
            continue
        if t & 0x80000000:
            if (t & 0xffff) not in ex[1]:
                miss.append('#%d' % (t & 0xffff))
        else:
            nm = cstr(t + 2)
            if nm not in ex[0]:
                miss.append(nm)
    tag = 'skipped (not in run/ or SysWOW64)' if ex is None else ('%d MISSING: %s' % (len(miss), ', '.join(miss[:5])) if miss else 'ok')
    bad += len(miss)
    print('  %-24s %4d imports  %s' % (dll, n, tag))
print('unresolvable imports: %d' % bad)

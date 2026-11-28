"""python dll_data_audit.py: read-only static audit that finds EVERY DLL-exported DATA symbol
referenced without __declspec(dllimport) in the linked binary.

When an object references a DLL-exported variable `S` without `__imp_`, the linker synthesizes
a `JMP [__imp_S]` thunk (`FF 25 ...`) in `.text` for `S`. Code reading `S` then reads the
thunk's machine code (`0x25FF...`) as data and crashes inside the DLL (exactly the Ogre
`msDummyPlaneList` crash in rgmain.dll).

Snapshots run/RobloxQT.exe + linkexp/qt.map into work/native-client/mass-tools/snap/ first,
then finds every DLL import thunk in `.text` whose mangled name is a DATA symbol (MSVC `@@[0-5]`
static/global variable, or non-function export) AND scans linked .obj files to report the exact
referencing objects!
Writes work/native-client/mass-tools/dll_data_audit.json.
"""
import collections, ctypes, json, re, shutil, sys
from pathlib import Path
import pefile

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_DIR = ROOT / 'work/native-client/mass-tools'
SNAP_DIR = OUT_DIR / 'snap'

_dbg = ctypes.windll.dbghelp
_dbg.UnDecorateSymbolName.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
_dbg.UnDecorateSymbolName.restype = ctypes.c_uint


def und_full(sym: str) -> str:
    buf = ctypes.create_string_buffer(4096)
    n = _dbg.UnDecorateSymbolName(sym.encode('ascii', 'ignore'), buf, 4096, 0)
    return buf.value.decode('ascii', 'ignore') if n else ''


def snapshot():
    SNAP_DIR.mkdir(parents=True, exist_ok=True)
    exe_dst = SNAP_DIR / 'RobloxQT.exe'
    map_dst = SNAP_DIR / 'qt.map'
    shutil.copy2(H / 'run/RobloxQT.exe', exe_dst)
    shutil.copy2(H / 'linkexp/qt.map', map_dst)
    return exe_dst, map_dst


def main():
    exe_path, map_path = snapshot()
    pe = pefile.PE(str(exe_path), fast_load=True)
    ib = pe.OPTIONAL_HEADER.ImageBase
    img = pe.get_memory_mapped_image()

    # Find all DLL thunk entries in qt.map: `0001:xxxx  <sym>  <va>  <lib>:<dll>`
    dll_thunks = []
    imp_syms = {}
    for line in map_path.open(errors='ignore'):
        p = line.split()
        if len(p) >= 4 and ':' in p[0] and len(p[2]) == 8 and ':' in p[-1] and '.dll' in p[-1].lower():
            try:
                va = int(p[2], 16)
            except ValueError:
                continue
            sym, dll = p[1], p[-1]
            if sym.startswith('__imp_'):
                imp_syms[sym[6:]] = (va, dll)
            elif p[0].startswith('0001:'):
                dll_thunks.append((va, sym, dll))

    bad_data = []
    for va, sym, dll in dll_thunks:
        off = va - ib
        if off < 0 or off + 6 > len(img):
            continue
        is_jmp_thunk = (img[off] == 0xFF and img[off + 1] == 0x25)
        if not is_jmp_thunk:
            continue
        # Exact check: vtable/RTTI or C++ data symbol (no '(' in full demangled signature)
        if sym.startswith('??_7') or sym.startswith('??_R'):
            is_data = True
            kind = 'vtable_or_rtti'
            dem = und_full(sym)
        elif sym.startswith('?'):
            dem = und_full(sym)
            is_data = bool(dem) and ('(' not in dem)
            kind = ('const_data' if sym.endswith('B') else 'mutable_data') if is_data else 'func'
        else:
            dem = sym
            is_data = False
            kind = 'func'
        if is_data:
            bad_data.append({
                'sym': sym,
                'demangled': dem,
                'dll': dll,
                'thunk_va': f'{va:08x}',
                'kind': kind,
                'referrers': [],
            })

    # Optional --refs: scan native/linkexp .obj files for referencing objects
    rsp = H / 'linkexp/qt.rsp'
    if '--refs' in sys.argv and bad_data and rsp.exists():
        by_bytes = {x['sym'].encode('ascii', 'ignore'): x for x in bad_data}
        pat = re.compile(b'|'.join(re.escape(k) for k in by_bytes))
        obj_paths = [Path(l.strip().strip('"')) for l in rsp.read_text(errors='ignore').splitlines()
                     if l.strip().strip('"').lower().endswith('.obj') and '\\renamed\\obj\\' not in l.lower()]
        for op in obj_paths:
            try:
                raw = op.read_bytes()
            except OSError:
                continue
            for m in pat.finditer(raw):
                nb = m.group(0)
                item = by_bytes[nb]
                if len(item['referrers']) < 15 and op.name not in item['referrers']:
                    # Check if preceded by __imp_
                    st = m.start()
                    if st < 6 or raw[st - 6:st] != b'__imp_':
                        item['referrers'].append(op.name)

    by_dll = collections.Counter(x['dll'] for x in bad_data)
    by_kind = collections.Counter(x['kind'] for x in bad_data)
    out = {
        'total_dll_thunks': len(dll_thunks),
        'bad_data_thunks': len(bad_data),
        'by_dll': dict(by_dll.most_common()),
        'by_kind': dict(by_kind.most_common()),
        'items': bad_data,
    }
    out_path = OUT_DIR / 'dll_data_audit.json'
    out_path.write_text(json.dumps(out, indent=2))
    print(f"dll_data_audit: total_dll_thunks={len(dll_thunks)} BAD_DATA_THUNKS={len(bad_data)}")
    print("  by_dll:", dict(by_dll.most_common()))
    print("  by_kind:", dict(by_kind.most_common()))
    for x in bad_data[:25]:
        print(f"  [{x['kind']:14s}] {x['dll']:22s} {x['sym'][:80]}  refs={x['referrers'][:3]}")
    print(f"  wrote {out_path}")


if __name__ == '__main__':
    main()

"""python stub_sret_audit.py: scans work/native-client/mass-tools/stubcall_audit.json (461 called
stubs + 1,515 vtable stub slots) for stubs returning a C++ UDT by value (`?AV`, `?AU` in MSVC
mangling — e.g. std::basic_string, boost::shared_ptr, std::auto_ptr, std::vector).
When a `return 0` stub has a hidden `sret` pointer, the caller's stack object stays uninitialized
garbage, causing 0xC0000374 heap corruption when its destructor runs.
Writes work/native-client/mass-tools/stub_sret_audit.json.
"""
import ctypes, json, re
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_DIR = ROOT / 'work/native-client/mass-tools'

_dbg = ctypes.windll.dbghelp
_dbg.UnDecorateSymbolName.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
_dbg.UnDecorateSymbolName.restype = ctypes.c_uint


def und_full(sym: str) -> str:
    buf = ctypes.create_string_buffer(4096)
    n = _dbg.UnDecorateSymbolName(sym.encode('ascii', 'ignore'), buf, 4096, 0)
    return buf.value.decode('ascii', 'ignore') if n else ''


# MSVC mangled return type for UDT by value: after calling convention (`@@[A-Z]{2,3}`),
# return type starts with `?AV` (class), `?AU` (struct), `?BV` (const class), `?BU` (const struct)
SRET_PAT = re.compile(r'@@[A-Z]{2,3}\?[AB][VU]')
DANGEROUS_TYPES = ('basic_string', 'shared_ptr', 'weak_ptr', 'auto_ptr', 'vector', 'map', 'list', 'set', 'ContentId', 'CString', 'any')


def main():
    sc_path = OUT_DIR / 'stubcall_audit.json'
    if not sc_path.exists():
        raise SystemExit('Run stubcall_audit.py first')
    sc = json.loads(sc_path.read_text())

    seen = {}
    for x in sc.get('top_called_stubs', []):
        seen[x['stub']] = {'stub': x['stub'], 'count': x['count'], 'where': 'direct_call', 'callers': x.get('sample_callers', [])[:3]}
    for v in sc.get('vtable_stub_slots', []):
        s = v['target']
        if s not in seen:
            seen[s] = {'stub': s, 'count': 1, 'where': f"vtable:{v['vtable']}[{v['slot']}]", 'callers': [v['vtable']]}

    sret_hits = []
    for s, info in seen.items():
        if SRET_PAT.search(s):
            dem = und_full(s)
            danger = any(dt in s or dt in dem for dt in DANGEROUS_TYPES)
            sret_hits.append({
                'stub': s,
                'demangled': dem,
                'dangerous_dtor': danger,
                'count': info['count'],
                'where': info['where'],
                'callers': info['callers'],
            })

    sret_hits.sort(key=lambda x: (0 if x['dangerous_dtor'] else 1, -x['count'], x['stub']))
    out = {
        'total_checked': len(seen),
        'sret_count': len(sret_hits),
        'dangerous_dtor_count': sum(1 for x in sret_hits if x['dangerous_dtor']),
        'items': sret_hits,
    }
    out_path = OUT_DIR / 'stub_sret_audit.json'
    out_path.write_text(json.dumps(out, indent=2))
    print(f"stub_sret_audit: checked={len(seen)} sret_udt={len(sret_hits)} dangerous_dtor={out['dangerous_dtor_count']}")
    for x in sret_hits[:20]:
        tag = 'DANGER' if x['dangerous_dtor'] else 'udt   '
        print(f"  [{tag}] {x['count']:3d}x {x['where'][:28]:28s} {x['demangled'][:100]}")
    print(f"  wrote {out_path}")


if __name__ == '__main__':
    main()

"""python stubcall_audit.py: read-only static audit of live RobloxQT.exe against linkexp/qt.map.
Snapshots run/RobloxQT.exe and linkexp/qt.map into work/native-client/mass-tools/snap/ first
so concurrent links cannot overwrite them mid-read.
Finds:
  1. Every vtable slot in .rdata/.data pointing to a qt_stubs* address.
  2. Every direct CALL (E8) / JMP (E9) in non-stub .text targeting a qt_stubs* address,
     grouped by target stub, caller function, and subsystem.
Writes work/native-client/mass-tools/stubcall_audit.json.
"""
import bisect, collections, json, re, shutil, struct
from pathlib import Path
import pefile

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_DIR = ROOT / 'work/native-client/mass-tools'
SNAP_DIR = OUT_DIR / 'snap'


def snapshot():
    SNAP_DIR.mkdir(parents=True, exist_ok=True)
    exe_src = H / 'run/RobloxQT.exe'
    map_src = H / 'linkexp/qt.map'
    exe_dst = SNAP_DIR / 'RobloxQT.exe'
    map_dst = SNAP_DIR / 'qt.map'
    shutil.copy2(exe_src, exe_dst)
    shutil.copy2(map_src, map_dst)
    return exe_dst, map_dst


def parse_map(map_path: Path):
    """Returns (syms_by_va, sorted_vas, stub_vas, vtable_vas)."""
    syms = {}
    stub_vas = {}
    vtable_vas = {}
    for line in map_path.open(errors='ignore'):
        p = line.split()
        if len(p) >= 4 and ':' in p[0] and len(p[2]) == 8:
            try:
                va = int(p[2], 16)
            except ValueError:
                continue
            name = p[1]
            obj = p[-1]
            if va == 0:
                continue
            syms[va] = (name, obj)
            if 'stubs' in obj.lower():
                stub_vas[va] = name
            if name.startswith('??_7'):
                vtable_vas[va] = name
    sorted_vas = sorted(syms.keys())
    return syms, sorted_vas, stub_vas, vtable_vas


def owner_of(va, sorted_vas, syms):
    idx = bisect.bisect_right(sorted_vas, va) - 1
    if idx < 0:
        return None, None
    base = sorted_vas[idx]
    if va - base > 0x20000:
        return None, None
    return base, syms[base][0]


def subsystem(name: str) -> str:
    for tag in ['Insert', 'Workspace', 'PartInstance', 'Humanoid', 'Camera', 'View', 'Render',
                'Network', 'Replicator', 'Script', 'Lua', 'Sound', 'Joint', 'Tool', 'Physics',
                'World', 'Kernel', 'Xml', 'ContentProvider', 'DataModel', 'Instance', 'Reflection',
                'CXTP', 'CXT', 'MFC', 'G3D', 'boost']:
        if tag.lower() in name.lower():
            return tag
    return 'Other'


def main():
    exe_path, map_path = snapshot()
    syms, sorted_vas, stub_vas, vtable_vas = parse_map(map_path)
    pe = pefile.PE(str(exe_path), fast_load=True)
    ib = pe.OPTIONAL_HEADER.ImageBase
    img = pe.get_memory_mapped_image()

    # 1. Scan vtables in .rdata / .data for pointers into stub_vas
    vt_stub_hits = []
    vt_sorted = sorted(vtable_vas.keys())
    for vi, vva in enumerate(vt_sorted):
        vname = vtable_vas[vva]
        # Scan up to next symbol or max 128 slots
        next_idx = bisect.bisect_right(sorted_vas, vva)
        end_va = sorted_vas[next_idx] if next_idx < len(sorted_vas) else vva + 512
        slots = min(128, max(0, (end_va - vva) // 4))
        off = vva - ib
        if off < 0 or off + slots * 4 > len(img):
            continue
        for s in range(slots):
            ptr = struct.unpack_from('<I', img, off + s * 4)[0]
            if ptr in stub_vas:
                vt_stub_hits.append({
                    'vtable': vname,
                    'vtable_va': f'{vva:08x}',
                    'slot': s,
                    'target_va': f'{ptr:08x}',
                    'target': stub_vas[ptr],
                })

    # 2. Scan non-stub executable sections for direct E8 (CALL rel32) and E9 (JMP rel32) targeting stub_vas
    call_hits = collections.defaultdict(list)
    subsys_counts = collections.Counter()
    for sec in pe.sections:
        if not (sec.Characteristics & 0x20000000):  # IMAGE_SCN_MEM_EXECUTE
            continue
        sec_va = ib + sec.VirtualAddress
        sec_end = sec_va + sec.Misc_VirtualSize
        data = bytes(img[sec.VirtualAddress:sec.VirtualAddress + sec.Misc_VirtualSize])
        n = len(data) - 5
        i = 0
        while i < n:
            op = data[i]
            if op == 0xE8 or op == 0xE9:
                rel = struct.unpack_from('<i', data, i + 1)[0]
                tgt = (sec_va + i + 5 + rel) & 0xFFFFFFFF
                if tgt in stub_vas:
                    src_va = sec_va + i
                    if src_va not in stub_vas:
                        _, cname = owner_of(src_va, sorted_vas, syms)
                        if cname and 'stubs' not in (syms.get(owner_of(src_va, sorted_vas, syms)[0], ('', ''))[1].lower()):
                            sname = stub_vas[tgt]
                            call_hits[sname].append({'caller': cname, 'site': f'{src_va:08x}', 'op': 'call' if op == 0xE8 else 'jmp'})
                            subsys_counts[subsystem(sname)] += 1
            i += 1

    ranked = sorted(
        [{'stub': k, 'count': len(v), 'subsystem': subsystem(k), 'sample_callers': [x['caller'] for x in v[:5]]}
         for k, v in call_hits.items()],
        key=lambda x: -x['count']
    )

    out = {
        'snapshot_exe': str(exe_path),
        'total_stubs_in_map': len(stub_vas),
        'vtable_stub_slot_count': len(vt_stub_hits),
        'unique_called_stubs': len(ranked),
        'total_call_sites': sum(x['count'] for x in ranked),
        'by_subsystem': dict(subsys_counts.most_common()),
        'vtable_stub_slots': vt_stub_hits[:500],
        'top_called_stubs': ranked[:300],
    }
    out_path = OUT_DIR / 'stubcall_audit.json'
    out_path.write_text(json.dumps(out, indent=2))
    print(f"stubcall_audit: total_stubs={len(stub_vas)} vtable_stub_slots={len(vt_stub_hits)} "
          f"unique_called_stubs={len(ranked)} call_sites={out['total_call_sites']}")
    print("  by_subsystem:", dict(subsys_counts.most_common(10)))
    print("  top 10 vtable stub slots:")
    for h in vt_stub_hits[:10]:
        print(f"    {h['vtable']}[{h['slot']}] -> {h['target']}")
    print("  top 10 called stubs:")
    for r in ranked[:10]:
        print(f"    {r['count']:4d}x [{r['subsystem']}] {r['stub']}")
    print(f"  wrote {out_path}")


if __name__ == '__main__':
    main()

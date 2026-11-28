"""python data_zero_audit.py: compares every non-code (.data/.rdata) global symbol in snapshot
RobloxQT.exe against original Roblox.exe (matched via identity-registry.json and dat_00xxxxxx
names). Flags any symbol that is non-zero in Roblox.exe (strings, pointers, floats, tables)
but all-zero in RobloxQT.exe!
Writes:
  - work/native-client/mass-tools/data_zero_audit.json (full report)
  - work/native-client/mass-tools/data_zero_proposals.cpp (proposed definitions for Claude to review/bind)
"""
import json, re, struct
from pathlib import Path
import pefile

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_DIR = ROOT / 'work/native-client/mass-tools'
SNAP_DIR = OUT_DIR / 'snap'


def is_printable_cstr(b: bytes):
    nul = b.find(b'\x00')
    if nul < 1 or nul > 128:
        return None
    s = b[:nul]
    if all(32 <= c < 127 for c in s):
        return s.decode('ascii')
    return None


def main():
    exe_qt = SNAP_DIR / 'RobloxQT.exe'
    map_qt = SNAP_DIR / 'qt.map'
    if not exe_qt.exists() or not map_qt.exists():
        raise SystemExit('Run stubcall_audit.py first to create snapshot')

    pe_qt = pefile.PE(str(exe_qt), fast_load=True)
    ib_qt = pe_qt.OPTIONAL_HEADER.ImageBase
    img_qt = pe_qt.get_memory_mapped_image()
    exec_ranges_qt = [(ib_qt + s.VirtualAddress, ib_qt + s.VirtualAddress + s.Misc_VirtualSize)
                      for s in pe_qt.sections if (s.Characteristics & 0x20000000)]

    pe_orig = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    ib_orig = pe_orig.OPTIONAL_HEADER.ImageBase
    img_orig = pe_orig.get_memory_mapped_image()

    def in_exec(va):
        return any(a <= va < b for a, b in exec_ranges_qt)

    reg = json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    name_to_orig = {}
    for addr_hex, info in reg.items():
        if isinstance(info, dict) and info.get('name'):
            name_to_orig.setdefault(info['name'], int(addr_hex, 16))

    # Parse non-code symbols from qt.map
    data_syms = []
    for line in map_qt.open(errors='ignore'):
        p = line.split()
        if len(p) >= 4 and ':' in p[0] and len(p[2]) == 8:
            try:
                va = int(p[2], 16)
            except ValueError:
                continue
            name, obj = p[1], p[-1]
            if va == 0 or in_exec(va):
                continue
            if name.startswith(('??_7', '??_R', '__imp_', '__ehhandler', '__unwind')):
                continue
            data_syms.append((va, name, obj))

    # Sort by VA to estimate symbol size in QT
    data_syms.sort(key=lambda x: x[0])
    zeroed = []
    checked = 0
    for idx, (qva, name, obj) in enumerate(data_syms):
        ova = name_to_orig.get(name)
        if ova is None:
            m = re.fullmatch(r'dat_([0-9a-fA-F]{8})', name)
            if m:
                ova = int(m.group(1), 16)
        if ova is None or ova < ib_orig + 0x1000:
            continue
        qoff = qva - ib_qt
        ooff = ova - ib_orig
        if qoff < 0 or ooff < 0 or qoff + 16 > len(img_qt) or ooff + 16 > len(img_orig):
            continue
        # Estimate span up to next symbol (clamped 4..64)
        span = 16
        if idx + 1 < len(data_syms):
            d = data_syms[idx + 1][0] - qva
            if 4 <= d <= 64:
                span = d
        qbytes = bytes(img_qt[qoff:qoff + span])
        obytes = bytes(img_orig[ooff:ooff + span])
        checked += 1
        # Flag if QT is all-zero in first min(span, 16) bytes while Orig is non-zero
        chk_len = min(span, 16)
        if all(b == 0 for b in qbytes[:chk_len]) and any(b != 0 for b in obytes[:chk_len]):
            cstr = is_printable_cstr(bytes(img_orig[ooff:ooff + 128]))
            u32 = struct.unpack_from('<I', obytes, 0)[0]
            kind = 'string' if cstr and len(cstr) >= 2 else ('ptr_in_orig' if 0x401000 <= u32 < 0x9c0000 else 'scalar_or_struct')
            zeroed.append({
                'name': name,
                'qt_va': f'{qva:08x}',
                'orig_va': f'{ova:08x}',
                'obj': obj,
                'span': span,
                'kind': kind,
                'orig_str': cstr,
                'orig_hex': obytes[:min(span, 32)].hex(),
            })

    # Prioritize strings and RBX globals
    zeroed.sort(key=lambda x: (0 if x['kind'] == 'string' else 1, 0 if '@RBX@@' in x['name'] else 1, x['name']))
    out = {
        'checked_data_syms': checked,
        'zeroed_count': len(zeroed),
        'strings_zeroed': sum(1 for x in zeroed if x['kind'] == 'string'),
        'ptrs_zeroed': sum(1 for x in zeroed if x['kind'] == 'ptr_in_orig'),
        'scalars_zeroed': sum(1 for x in zeroed if x['kind'] == 'scalar_or_struct'),
        'items': zeroed[:500],
    }
    out_path = OUT_DIR / 'data_zero_audit.json'
    out_path.write_text(json.dumps(out, indent=2))

    # Write proposed C++ definitions for zeroed char[] class/string names
    props = ['// Proposed definitions from data_zero_audit.py (review before binding)\n']
    for item in zeroed:
        if item['kind'] == 'string' and item['orig_str']:
            # Match ?sFoo@RBX@@3PADA or ?sFoo@RBX@@3QBDB or ?sFoo@Sub@RBX@@3...
            m = re.match(r'^\?(\w+)@((?:\w+@)+)@3(PADA|QBDB|PADA)$', item['name'])
            if m:
                var = m.group(1)
                ns = list(reversed([x for x in m.group(2).split('@') if x]))
                qual = 'const ' if m.group(3) == 'QBDB' else ''
                s = item['orig_str'].replace('\\', '\\\\').replace('"', '\\"')
                props.append(f'// orig {item["orig_va"]} ({item["obj"]})\n')
                props.append(f'namespace {"::".join(ns)} {{ extern {qual}char {var}[] = "{s}"; }}\n')
    prop_path = OUT_DIR / 'data_zero_proposals.cpp'
    prop_path.write_text(''.join(props))

    print(f"data_zero_audit: checked={checked} zeroed={len(zeroed)} "
          f"(strings={out['strings_zeroed']}, ptrs={out['ptrs_zeroed']}, scalars={out['scalars_zeroed']})")
    for x in zeroed[:15]:
        print(f"  [{x['kind']:16s}] {x['name']} orig={x['orig_va']} ({x['obj']}) str={x['orig_str']!r} hex={x['orig_hex'][:16]}")
    print(f"  wrote {out_path} and {prop_path}")


if __name__ == '__main__':
    main()

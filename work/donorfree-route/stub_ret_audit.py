"""python stub_ret_audit.py: report-only audit comparing called stubs' stack-pop (`ret N`) in
snapshot RobloxQT.exe against original RobloxOrig.exe (matched via identity-registry.json /
func_00xxxxxx names). Does NOT modify stub generation or stubret_override.json.
Writes work/native-client/mass-tools/stub_ret_audit.json.
"""
import json, re, struct
from pathlib import Path
import capstone, pefile

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_DIR = ROOT / 'work/native-client/mass-tools'
SNAP_DIR = OUT_DIR / 'snap'


def ret_pops(md, img, ib, va, max_bytes=0x400):
    off = va - ib
    if off < 0 or off >= len(img):
        return set()
    pops = set()
    for ins in md.disasm(bytes(img[off:off + max_bytes]), va):
        if ins.mnemonic == 'ret':
            pops.add(int(ins.op_str, 16) if ins.op_str else 0)
            if len(pops) >= 4:
                break
        elif ins.mnemonic == 'int3' and pops:
            break
    return pops


def main():
    sc_path = OUT_DIR / 'stubcall_audit.json'
    if not sc_path.exists():
        raise SystemExit('Run stubcall_audit.py first to build snapshot + called stub list')
    sc = json.loads(sc_path.read_text())
    called_stubs = {x['stub']: x for x in sc.get('top_called_stubs', [])}
    for v in sc.get('vtable_stub_slots', []):
        called_stubs.setdefault(v['target'], {'stub': v['target'], 'count': 1, 'subsystem': 'vtable', 'sample_callers': [v['vtable']]})

    # Map stub name -> VA in snapshot qt.map
    stub_va = {}
    for line in (SNAP_DIR / 'qt.map').open(errors='ignore'):
        p = line.split()
        if len(p) >= 4 and 'stubs' in p[-1].lower():
            try:
                stub_va[p[1]] = int(p[2], 16)
            except ValueError:
                pass

    # Map mangled name -> orig VA via identity-registry.json
    reg = json.loads((ROOT / 'work/2008-06/identity-registry.json').read_text())
    name_to_orig = {}
    for addr_hex, info in reg.items():
        if isinstance(info, dict) and info.get('name'):
            name_to_orig.setdefault(info['name'], int(addr_hex, 16))

    pe_qt = pefile.PE(str(SNAP_DIR / 'RobloxQT.exe'), fast_load=True)
    ib_qt = pe_qt.OPTIONAL_HEADER.ImageBase
    img_qt = pe_qt.get_memory_mapped_image()

    pe_orig = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    ib_orig = pe_orig.OPTIONAL_HEADER.ImageBase
    img_orig = pe_orig.get_memory_mapped_image()

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    mismatches = []
    checked = 0
    for sname, info in called_stubs.items():
        qva = stub_va.get(sname)
        if not qva:
            continue
        ova = name_to_orig.get(sname)
        if ova is None:
            m = re.fullmatch(r'func_([0-9a-fA-F]{8})', sname)
            if m:
                ova = int(m.group(1), 16)
        if ova is None:
            continue
        qp = ret_pops(md, img_qt, ib_qt, qva, max_bytes=32)
        op = ret_pops(md, img_orig, ib_orig, ova, max_bytes=0x600)
        if not qp or not op:
            continue
        checked += 1
        if qp != op and not (qp & op):
            mismatches.append({
                'stub': sname,
                'orig_va': f'{ova:08x}',
                'qt_va': f'{qva:08x}',
                'qt_ret': sorted(qp),
                'orig_ret': sorted(op),
                'call_count': info.get('count', 0),
                'sample_callers': info.get('sample_callers', [])[:3],
            })

    mismatches.sort(key=lambda x: -x['call_count'])
    out = {'checked_called_stubs': checked, 'mismatch_count': len(mismatches), 'mismatches': mismatches}
    out_path = OUT_DIR / 'stub_ret_audit.json'
    out_path.write_text(json.dumps(out, indent=2))
    print(f"stub_ret_audit: checked={checked} mismatches={len(mismatches)}")
    for m in mismatches[:15]:
        print(f"  {m['call_count']:3d}x {m['stub']} orig={m['orig_va']} qt_ret={m['qt_ret']} vs orig_ret={m['orig_ret']}")
    print(f"  wrote {out_path}")


if __name__ == '__main__':
    main()

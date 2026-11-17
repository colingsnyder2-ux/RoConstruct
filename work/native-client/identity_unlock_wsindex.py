"""Index WebService.dll (RBXGS 0.3.676, VC8, Dec 2007) as a call-graph peer for identity_unlock_ws.py (kept out of the align route: 89-96% on named functions).

Names come from WebService.pdb public symbols (identity_unlock_pdb.py output).  Rows use the
objindex format (symbol, length, call-target symbols, data symbols); addresses carrying several
public names (identical-code folding) are skipped, and calls to them become '?'-free gaps that
never anchor.  Output: work/native-client/identity-unlock-wsindex.pkl.gz

  python identity_unlock_wsindex.py PUBLICS.json [--validate]
--validate runs the caller-alignment rule (>=2 anchors) with only this index on already-named
exe functions and reports right/wrong.
"""
import gzip
import json
import pickle
import sys
from collections import Counter, defaultdict
from pathlib import Path

import capstone
import pefile

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG  # noqa: E402

NC = ROOT / 'work/native-client'
DLL = ROOT / 'tools/rbxgs_msi/WebService.dll'
OUT = NC / 'identity-unlock-wsindex.pkl.gz'


def build(pub_path):
    pub = json.load(open(pub_path))
    pe = pefile.PE(str(DLL), fast_load=True)
    base, img = pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image()
    addrs = sorted(int(a, 16) for a in pub)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    funcs = []
    for k, va in enumerate(addrs):
        end = addrs[k + 1] if k + 1 < len(addrs) else va + 0x400
        end = min(end, va + 0x4000)
        calls = []
        for i in md.disasm(bytes(img[va - base:end - base]), va):
            if i.mnemonic == 'call' and i.op_str.startswith('0x'):
                calls.append(pub.get('%08x' % int(i.op_str, 16), '?unknown'))
            if i.mnemonic == 'ret' and i.address + i.size >= end - 16:
                break
        funcs.append((pub['%08x' % va], end - va, tuple(calls), ()))
    pickle.dump({'funcs': funcs, 'vtables': [], 'objects': [str(DLL)]}, gzip.open(OUT, 'wb'))
    print('webservice funcs', len(funcs))
    return funcs


def validate(funcs):
    from identity_unlock_align import target_refs
    from identity_unlock_common import CODE_STARTS
    by = defaultdict(list)
    for r in funcs:
        by[r[0]].append(r)
    name = {a: v['name'] for a, v in REG.items() if not v.get('placeholder') and not v['name'].startswith('func_')}
    st = Counter()
    for va in CODE_STARTS:
        a = '%08x' % va
        if a not in name or name[a] not in by:
            continue
        tc = target_refs(va)[0]
        for row in by[name[a]]:
            oc = row[2]
            if len(oc) != len(tc):
                st['len-differs'] += 1
                continue
            for j, t in enumerate(tc):
                if t not in name or oc[j].startswith('?unknown'):
                    continue
                anc = sum(1 for k, (x, o) in enumerate(zip(tc, oc)) if k != j and name.get(x) == o)
                bad = any(k != j and x in name and name[x] != o and not o.startswith('?unknown')
                          for k, (x, o) in enumerate(zip(tc, oc)))
                if anc >= 2 and not bad:
                    st['right' if oc[j] == name[t] else 'wrong'] += 1
    print(dict(st))


if __name__ == '__main__':
    f = build(sys.argv[1])
    if '--validate' in sys.argv:
        validate(f)

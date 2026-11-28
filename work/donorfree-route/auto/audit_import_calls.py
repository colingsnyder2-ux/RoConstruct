"""Compare indirect import calls in converted functions with the original."""
import collections, json, re, struct
from pathlib import Path
import capstone, pefile

root = Path(__file__).resolve().parent.parent
orig_pe = pefile.PE(str(root / 'run/RobloxOrig.exe'))
qt_pe = pefile.PE(str(root / 'run/RobloxQT.exe'))
orig = orig_pe.get_memory_mapped_image(); qt = qt_pe.get_memory_mapped_image(); base = 0x400000
orig_imports = {i.address: (d.dll.decode().lower(), i.name.decode() if i.name else '#'+str(i.ordinal)) for d in orig_pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
qt_imports = {}; funcs = {}
renamed = json.loads((root / 'renamed/rename.json').read_text())
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    p = line.split()
    if len(p) < 4 or not re.fullmatch('[0-9a-fA-F]{8}', p[2]):
        continue
    addr = int(p[2], 16)
    if '!' in p[1] and p[0].startswith('0002:'):
        dll, name = p[1].split('!', 1); qt_imports[addr] = (dll.lower(), name)
    m = re.search(r'([0-9a-f]{8})\.obj$', p[-1])
    if m and p[0].startswith('0001:') and 'stubs' not in p[-1]:
        original = m.group(1)
        if p[1] in ('func_' + original, (renamed.get(original) or {}).get('symbol')):
            funcs[int(original, 16)] = addr
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
bad = collections.defaultdict(list); checked = 0
for original, linked in funcs.items():
    a = md.disasm(orig[original-base:original-base+0x400], original)
    b = md.disasm(qt[linked-base:linked-base+0x400], linked)
    for oi, qi in zip(a, b):
        offset = oi.address-original
        if offset != qi.address-linked or oi.mnemonic != qi.mnemonic:
            break
        if oi.bytes[:2] not in (b'\xff\x15', b'\xff\x25') or qi.bytes[:2] != oi.bytes[:2]:
            continue
        old, new = struct.unpack_from('<I', oi.bytes, 2)[0], struct.unpack_from('<I', qi.bytes, 2)[0]
        if old not in orig_imports or new not in qt_imports:
            continue
        checked += 1
        if orig_imports[old] != qt_imports[new]:
            bad[original].append((offset, orig_imports[old], qt_imports[new]))
print('checked', checked, 'import calls; mismatches', sum(map(len, bad.values())), 'in', len(bad), 'functions')
for function, entries in sorted(bad.items()):
    for offset, old, new in entries:
        print('%08x +%x %s!%s -> %s!%s' % (function, offset, *old, *new))

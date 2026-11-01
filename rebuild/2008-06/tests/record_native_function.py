"""Compile one native-class source and compare named functions with the original, relocations masked.
usage: record_native_function.py SOURCE.cpp RECEIPT.json ADDRESS:SYMBOLPREFIX [...]"""
import hashlib, json, sys
from pathlib import Path
import pefile
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild
source = (ROOT / sys.argv[1]).resolve()
recipe = libs.RECIPES['rbxgs']
out = ROOT / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DNOMINMAX', '/DBOOST_ALL_NO_LIB']
flags += ['/D' + v for v in recipe['defines'].split()]
flags += ['/I' + str(ROOT / 'rebuild/2008-06/native-headers'), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
flags += ['/Fo' + source.stem + '.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
if code:
    print(log[-1800:]); sys.exit(1)
original = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
if not original.exists():
    original = Path('C:/Users/colin/RoConstruct/work/2008-06/original-p4-reference/Roblox.exe')
pe = pefile.PE(str(original), fast_load=True)
obj = (out / (source.stem + '.obj')).read_bytes()
rows = []
for spec in sys.argv[3:]:
    address, prefix = spec.split(':')
    target, relocations, _ = match.target('2008-06', address)
    assert target == pe.get_data(int(address, 16) - pe.OPTIONAL_HEADER.ImageBase, len(target))
    found = [(n, b, r) for n, b, r in match.coff_functions(obj) if n.startswith(prefix)]
    if not found:
        rows.append(dict(address=address, error='symbol not compiled', prefix=prefix)); continue
    name, body, crel = found[0]
    rows.append(dict(address=address, symbol=name, target_size=len(target), compiled_size=len(body),
                     relocation_normalized_exact=bool(match.exact_match(target, relocations, body, crel))))
receipt = dict(source=sys.argv[1], source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
               object_sha256=hashlib.sha256(obj).hexdigest(), original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(),
               flags=flags[:-2], functions=rows)
(ROOT / sys.argv[2]).write_text(json.dumps(receipt, indent=1))
print(json.dumps(rows, indent=1))

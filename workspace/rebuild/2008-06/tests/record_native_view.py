"""Compare the candidate CRobloxView constructor with original 00459eb0, relocations masked."""
import hashlib, json, subprocess, sys
from pathlib import Path
import pefile
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match
subprocess.check_call([sys.executable, str(ROOT / 'work/2008-06/p6-trace/probe_view.py')], cwd=ROOT)
obj_path = ROOT / 'rebuild/2008-06/out/native-layouts/NativeViewLayout.obj'
original = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
if not original.exists():
    original = Path('C:/Users/colin/RoConstruct/work/2008-06/original-p4-reference/Roblox.exe')
pe = pefile.PE(str(original), fast_load=True)
obj = obj_path.read_bytes()
rows = []
for address, prefix in (('00459eb0', '??0CRobloxView@@'), ('00459ba0', '??1CRobloxView@@')):
    target, relocations, _ = match.target('2008-06', address)
    assert target == pe.get_data(int(address, 16) - pe.OPTIONAL_HEADER.ImageBase, len(target))
    name, body, candidate_relocations = next((n, b, r) for n, b, r in match.coff_functions(obj) if n.startswith(prefix))
    rows.append(dict(address=address, symbol=name, target_size=len(target), compiled_size=len(body),
                     relocation_normalized_exact=bool(match.exact_match(target, relocations, body, candidate_relocations)),
                     first_difference=next((i for i, (a, b) in enumerate(zip(target, body)) if a != b), None)))
out = ROOT / 'work/2008-06/shared-layouts/view-ctor.json'
sources = [ROOT / 'rebuild/2008-06/tests/NativeViewLayout.cpp',
           ROOT / 'rebuild/2008-06/native-classes/CRobloxView.cpp',
           ROOT / 'rebuild/2008-06/native-headers/CRobloxView.h',
           ROOT / 'work/2008-06/p6-trace/probe_view.py', Path(__file__)]
out.write_text(json.dumps(dict(original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(),
                               object_sha256=hashlib.sha256(obj).hexdigest(),
                               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in sources},
                               methods=rows), indent=1))
print(json.dumps(rows, indent=1))
if not all(row['relocation_normalized_exact'] for row in rows):
    sys.exit(1)

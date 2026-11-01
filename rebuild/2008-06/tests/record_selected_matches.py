"""Count known source functions selected in the player PE, not mined totals."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

exe = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
link_map = exe.with_suffix('.map')
pe = pefile.PE(str(exe))
mapped = {}
for line in link_map.read_text().splitlines():
    row = re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+.*?([^\s:]+\.obj)\s*$', line)
    if row:
        mapped[(row[1], row[3])] = int(row[2], 16)

modules = {}
selected_all, matched_all = set(), set()
for name in ('P2RecoveredPlayer', 'RbxgsApp'):
    folder = ROOT / 'rebuild/2008-06/out' / name
    ownership = json.loads((folder / 'owned-symbols.json').read_text())
    native = {(entry['symbol'], entry['object']): address
              for address, entries in ownership.items() for entry in entries}
    selected, matched, mismatches, rows = set(), set(), set(), []
    for obj in sorted((folder / 'linked').glob('*.obj')):
        for symbol, body, relocations in match.coff_functions(obj.read_bytes()):
            key = (symbol, obj.name)
            address = mapped.get(key)
            if address is None:
                continue
            selected.add(address)
            final = pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, len(body))
            if not match.exact_match(body, relocations, final, relocations):
                mismatches.add(address)
                continue
            if key in native:
                matched.add(address)
                rows.append(dict(symbol=symbol, object=obj.name, pe_address=hex(address),
                                 original_address=native[key], size=len(body)))
    modules[name] = dict(selected_functions=len(selected), selected_code_matches=len(matched),
                         coff_to_pe_mismatches=len(mismatches), matches=rows)
    selected_all.update(selected)
    matched_all.update(matched)

sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               exe_sha256=sha(exe), map_sha256=sha(link_map), observer_sha256=sha(Path(__file__)),
               selected_functions=len(selected_all), selected_code_matches=len(matched_all), modules=modules,
               scope='Known player/engine COFF functions selected by this final PE map, with code bytes rechecked in the PE. Relocated operands are masked; data, ABI, system-library functions, runtime coverage and raw PE identity are separate gates.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('Selected PE code matches: %d / %d known source functions' % (len(matched_all), len(selected_all)))

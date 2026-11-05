import collections
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

from roc import match, rebuild

evidence = Path('work/g3d-native-20261029')
audit, receipts = {}, {}
for slug in ['g3d', 'g3d-gl', 'g3d-png', 'rbx-app', 'rbxgs-app']:
    spec = rebuild.load_module('2008-06', slug)
    folder = rebuild.workspace('2008-06') / 'out' / spec['name']
    map_file = rebuild.workspace('2008-06') / 'out/tests' / spec['test'] / (spec['test'] + '.map')
    owners = collections.defaultdict(list)
    for line in map_file.read_text(errors='replace').splitlines():
        cells = line.split()
        if len(cells) > 2:
            owners[cells[1]].append(line.strip())
    roots = {line.split('/INCLUDE:', 1)[1].split('"')[0]
             for line in (folder / 'force/force_verified.h').read_text().splitlines()}
    checks = []
    for item in json.loads((folder / 'verified/swaps.json').read_text())['swaps']:
        obj_file = folder / 'linked' / ('verified_' + item['obj'])
        if not obj_file.exists():
            continue
        obj = obj_file.read_bytes()
        functions = {name: (body, relocs) for name, body, relocs in match.coff_functions(obj)}
        externals = rebuild.coff_externals(obj)
        for symbol, address in item['keep'].items():
            if symbol not in roots or not externals.get(symbol) or symbol not in functions:
                continue
            body, relocs = functions[symbol]
            target, target_relocs, _ = match.target('2008-06', address)
            _, bad = match.data_check('2008-06', address, target, match.coff_data_refs(obj, symbol))
            checks.append({'symbol': symbol, 'address': address,
                           'code_exact': len(body) == len(target) and match.exact_match(target, target_relocs, body, relocs),
                           'data_exact': not bad, 'map_owner': owners[symbol],
                           'verified_library_owner': any('linked:verified_' in line for line in owners[symbol])})
    assert len(checks) == len(roots), (spec['name'], len(checks), len(roots))
    assert all(c['code_exact'] and c['data_exact'] and c['verified_library_owner'] for c in checks), spec['name']
    report = json.loads((folder / 'report.json').read_text())
    audit[spec['name']] = {'report': report, 'forced_header_roots': len(roots), 'checks': checks}
    receipts[spec['name']] = {'forced_roots': len(roots), 'linked': report['linked'],
        'runtime_exit': report['test_exit'], 'unresolved': report['unresolved'],
        'exact_roots_with_verified_library_owner': len(checks),
        'linked_object_sha256': {p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in (folder / 'linked').glob('*.obj')}}
    print(spec['name'], len(roots), 'exact + correct owner', flush=True)
(evidence / 'forced-root-audit.json').write_text(json.dumps(audit, indent=1))
(evidence / 'final-module-receipts.json').write_text(json.dumps({
    'timestamp': datetime.now(timezone.utc).isoformat(), 'new_server_credits': 0, 'modules': receipts}, indent=1))
placed = json.loads((rebuild.workspace('2008-06') / 'out/placed.json').read_text())
(evidence / 'placed.json').write_text(json.dumps(placed, indent=1))
(evidence / 'placement-receipt.json').write_text(json.dumps({'distinct': len(placed),
    'by_module': dict(collections.Counter(placed.values())),
    'excluded': ['Ogre (12 unresolved)', 'MfcAtl (no valid private completion)'],
    'deferred_stale_modules': ['Boost', 'CodegenAnalogs', 'jpeg', 'libpng', 'Lua', 'RakNet', 'RbxUtil', 'Scintilla', 'XTP', 'zlib-winapi', 'zlib'],
    'server_credit': 0}, indent=1))

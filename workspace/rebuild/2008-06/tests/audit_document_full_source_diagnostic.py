"""Report what the full native CRobloxDoc source selects in its diagnostic PE."""
import hashlib
import json
import re
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match

proof = root/'work/2008-06/shared-layouts'
receipt = json.loads((proof/'document-swap-provider-trial.json').read_text())
assert receipt['link_exit'] == 0 and receipt['full_source']
folder = root/'rebuild/2008-06/out/native-layouts/document-swap-link-trial'
obj = folder/'NativeCRobloxDoc.obj'
functions = {name:(body, refs) for name, body, refs in match.coff_functions(obj.read_bytes())}
selected = set()
for line in (folder/'NativeDoc.map').read_text(errors='replace').splitlines():
    if line.rstrip().endswith('NativeCRobloxDoc.obj'):
        fields = line.split()
        if len(fields) >= 3:
            selected.add(fields[1])
checked = json.loads((proof/'document-current-recheck.json').read_text())
original = {row['symbol']:row['address'] for row in [checked['constructor']] + checked['exact_methods'] + checked['ownership_dependencies']}
rows = []
for symbol, address in original.items():
    if symbol not in selected or symbol not in functions:
        continue
    target, refs, _ = match.target('2008-06', address)
    body, candidate_refs = functions[symbol]
    rows.append({'symbol':symbol, 'address':address,
                 'exact':match.exact_match(target, refs, body, candidate_refs)})
result = {'scope':'Full native CRobloxDoc source in a mixed-ABI diagnostic PE. No runtime, ABI or P5/P6 claim.',
          'native_object_sha256':hashlib.sha256(obj.read_bytes()).hexdigest(),
          'exe_sha256':receipt['exe_sha256'], 'selected_native_doc_symbols':len(selected),
          'checked_original_doc_bodies':len(rows), 'exact_selected_bodies':sum(x['exact'] for x in rows),
          'rows':rows}
(proof/'document-full-source-diagnostic.json').write_text(json.dumps(result, indent=2)+'\n')
print('full Doc selected',len(selected),'checked',len(rows),'exact',result['exact_selected_bodies'])

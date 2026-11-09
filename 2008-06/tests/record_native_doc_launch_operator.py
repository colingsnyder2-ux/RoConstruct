"""Verify the launch CString operator from actual native Doc source."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

out = ROOT / 'work/2008-06/doc-launch-cstring-proof'
out.mkdir(parents=True, exist_ok=True)
symbol = '??HATL@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@0@PBDABV10@@Z'
env = dict(os.environ, NATIVE_CHECK_OUT=str(out), NATIVE_FLAGS='/O2 /Ob0 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS')
checks = ['0044f220=' + symbol] + [a + '=?handle_' + a[2:] + '@CRobloxDoc@@' for a in ('004500d0', '004501c0', '004502b0')] + ['0044ff40=?launch@@']
run = subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/check_native_class.py'), 'native-classes/CRobloxDoc.cpp'] + checks, cwd=ROOT, env=env, text=True, capture_output=True, check=True)
assert '5/5 exact' in run.stdout, run.stdout
obj = out/'CheckCRobloxDoc.obj'
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0] == symbol)
target, target_refs, _ = match.target('2008-06', '0044f220')
assert match.exact_match(target, target_refs, body, refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, section = definitions[name]
table = sections[section]
expected = {'?GetManager@': 0x802fec, '??0?$CStringT@': 0x802fe8, '?GetLength@': 0x802fe0, '??B?$CSimpleStringT@': 0x803ee0, '?StringLength@': 0x802fe4, '?Concatenate@': 0x802fdc}
found = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i)
    offset -= start
    symbol_name = symbols[index][0]
    if kind == 6 and 0 <= offset <= len(body)-4 and symbol_name.startswith('__imp_'):
        original = struct.unpack_from('<I', target, offset)[0]
        prefix = next((p for p in expected if symbol_name[6:].startswith(p)), None)
        assert prefix and original == expected[prefix] and struct.unpack_from('<I', body, offset)[0] == 0, (symbol_name, hex(original))
        found[prefix] = hex(original)
assert set(found) == set(expected), found
eh = out/'eh.json'
subprocess.run([sys.executable, str(ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py'), str(obj), '0044f220', symbol, '--output', str(eh)], cwd=ROOT, check=True)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
result = {'address': '0044f220', 'symbol': name, 'size': len(body), 'original_import_targets': found, 'object_sha256': sha(obj), 'source_sha256': sha(ROOT/'rebuild/2008-06/native-classes/CRobloxDoc.cpp'), 'observer_sha256': sha(Path(__file__)), 'eh_sha256': sha(eh), 'flags': env['NATIVE_FLAGS'], 'scope': 'Inactive actual Doc source under Ob0: body, imports and local EH verified; linked selection, ABI and runtime unproven.'}
(out/'result.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
print(run.stdout, json.dumps(result, indent=2))

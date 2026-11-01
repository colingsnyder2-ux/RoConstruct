"""Verify native document history handlers with their MSVC noinline profile."""
import hashlib, json, struct, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
BASE = json.loads((ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [f for f in BASE['flags'] if f != '/c' and not f.startswith('/Fo')] + ['/P']
pre = OUT / 'document-history-preprocess'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
body = (pre / 'NativeDocumentLayout.i').read_text(errors='replace')
profile = ('const _Elem * c_str() const', 'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );')
for needle in profile:
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
source = OUT / 'NativeDocumentHistoryProfile.cpp'
source.write_text(body)
obj = OUT / 'NativeDocumentHistoryProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, OUT)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for address, destination in [('00453670',0x58a130),('004538b0',0x588780),('00453750',0x587b70),('00453990',0x587a90),('00453af0',0x4153b0),('00454040',0x4530f0),('00454300',0x495e60),('00454170',0x49ac80),('00450a70',0x5757d0),('00450c00',0x5757e0),('00454490',0x42de90),('004547b0',0x5a9120)]:
    name, candidate, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?handle_'+address[2:]+'@CRobloxDoc'))
    target, target_refs, _ = match.target('2008-06', address)
    assert match.exact_match(target, target_refs, candidate, refs), address
    start, section = definitions[name]
    table = sections[section]
    edges = {}
    for i in range(table[7]):
        offset, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        offset -= start
        if 0 <= offset <= len(candidate)-4 and kind == 20:
            edges[symbols[symbol_index][0]] = hex((int(address,16) + offset + 4 + struct.unpack_from('<i',target,offset)[0]) & 0xffffffff)
    assert hex(destination) in edges.values(), address
    rows.append(dict(address=address,size=len(candidate),direct_calls=edges))
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
inputs = [Path(__file__), ROOT/'rebuild/2008-06/native-classes/CRobloxDoc.cpp', ROOT/'rebuild/2008-06/native-headers/CRobloxDoc.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/ChangeHistoryService.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/Selection.h', ROOT/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h', ROOT/'rebuild/2008-06/native-headers/script/ScriptContext.h', ROOT/'rebuild/2008-06/tests/NativeDocumentLayout.cpp']
receipt = dict(sources={str(p.relative_to(ROOT)):sha(p) for p in inputs},object_sha256=sha(obj),profile=profile,preprocess_flags=flags,compile_flags=compile_flags,methods=rows,scope='Inactive compiler proof, direct history targets verified; no runtime integration credit.')
(ROOT/'work/2008-06/shared-layouts/document-history-working.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS: twelve Doc command bodies and direct targets')

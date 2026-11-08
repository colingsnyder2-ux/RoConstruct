"""Verify native asset path helpers without inventing their global state."""
import hashlib
import json
import struct
import sys
from pathlib import Path

import pefile

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/experiments/trials/NativeLDrawPathTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
obj = out/'NativeLDrawPathTrial.obj'
flags += ['/Fo'+str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
rows = []
for prefix,address,expected in [
    ('?resolveMapPath@',0x55d0b0,[('?originalAssetFolder@',0x55c4c0),('__imp_??$?H',0x8023e4),
                                    ('__imp_??0?$basic_string@',0x80245c),('__imp_??1?$basic_string@',0x802468)]),
    ('?originalAssetFolder@',0x55c4c0,[('?assetFolderOnce@',0x973fe4),('?initializeAssetFolder@',0x55c3e0),
                                         ('?call_once@boost@@',0x557330),('?assetFolder@',0x9740f0)])]:
    name,body,refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target,targetrefs,_ = match.target('2008-06',f'{address:08x}')
    assert match.exact_match(target,targetrefs,body,refs)
    start,index = definitions[name]
    section = sections[index]
    bindings = {}
    for i in range(section[7]):
        offset,symbol,kind = struct.unpack_from('<IIH',raw,section[5]+10*i)
        offset -= start
        if 0 <= offset < len(body)-3:
            value = struct.unpack_from('<I',target,offset)[0]
            if kind == 20:
                value = (address+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
            bindings[symbols[symbol][0]] = value
    for symbol,wanted in expected:
        assert any(k.startswith(symbol) and v == wanted for k,v in bindings.items()), (symbol,bindings)
    rows.append({'address':hex(address),'size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()}})
state_source = root/'rebuild/2008-06/tests/NativeLDrawAssetStateTrial.cpp'
state_obj = out/'NativeLDrawAssetStateTrial.obj'
state_flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
state_flags += ['/Fo'+str(state_obj),str(state_source)]
code, log = rebuild.run(rebuild.toolchain(21022),'cl',state_flags,out)
assert code == 0, log
state_raw = state_obj.read_bytes()
lifetimes = []
for prefix,address in [('??__FcurrentMap@','007faff0'), ('??__EassetFolder@','007f2c10'),
                       ('??__FassetFolder@','007fcbf0')]:
    symbol,life,life_refs = next(x for x in match.coff_functions(state_raw) if x[0].startswith(prefix))
    life_target,life_targetrefs,_ = match.target('2008-06',address)
    assert match.exact_match(life_target,life_targetrefs,life,life_refs), address
    expected_global = 0x96ee60 if prefix == '??__FcurrentMap@' else 0x9740f0
    assert struct.pack('<I',expected_global) in life_target
    lifetimes.append({'address':address,'symbol':symbol,'size':len(life),'global':hex(expected_global)})
name,body,refs = next(x for x in match.coff_functions(state_raw) if x[0].startswith('?initializeAssetFolder@'))
target,targetrefs,_ = match.target('2008-06','0055c3e0')
assert match.exact_match(target,targetrefs,body,refs)
sections,symbols,definitions,_ = match._coff_data_index(state_raw)
start,index = definitions[name]
section = sections[index]
bindings = {}
for i in range(section[7]):
    offset,symbol,kind = struct.unpack_from('<IIH',state_raw,section[5]+10*i)
    offset -= start
    if 0 <= offset < len(body)-3:
        value = struct.unpack_from('<I',target,offset)[0]
        if kind == 20:
            value = (0x55c3e0+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        bindings[symbols[symbol][0]] = value
for prefix,wanted in [('__imp__SHGetFolderPathAndSubDirA@24',0x802af4), ('?assetFolder@',0x9740f0),
                      ('?singleton@StandardOut@',0x569620), ('?print@StandardOut@',0x5693a0)]:
    assert any(k.startswith(prefix) and v == wanted for k,v in bindings.items()), (prefix,bindings)
pe = pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe'))
for address,value in [(0x82dc24,b'Roblox\\content\\'), (0x82dbf8,b'Failed to get asset folder from registry')]:
    assert pe.get_string_at_rva(address-pe.OPTIONAL_HEADER.ImageBase) == value
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'flags':flags,'methods':rows,'initializer':{'address':'0055c3e0','size':len(body),
             'source_sha256':sha(state_source),'object_sha256':sha(state_obj),'flags':state_flags,
             'bindings':{k:hex(v) for k,v in bindings.items()},'lifetimes':lifetimes,
             'map_header_sha256':sha(root/'rebuild/2008-06/tests/NativeLDrawMapRootTrial.h')},
           'scope':'Inactive trial. Global ownership, static initialization ordering, exception metadata and runtime remain unproven; never run.'}
(root/'work/2008-06/shared-layouts/ldraw-path-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS native asset folder and map path bodies and bindings')

"""Verify inactive Visit service lookup, using existing provider lookup profile."""
import hashlib
import json
import struct
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root/'rebuild/2008-06/out/native-layouts'
source = root/'rebuild/2008-06/tests/NativeVisitServiceTrial.cpp'
base = json.loads((root/'work/2008-06/shared-layouts/instance-after-service-link.json').read_text())
common = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('InstanceLifetime.cpp')]
flags = [x for x in common if x != '/c'] + ['/DSERVICE_CONTENT_FIND_ONLY','/P',str(source)]
pre = out/'visit-service-pre'
pre.mkdir(exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, pre)
assert code == 0, log
text = (pre/'NativeVisitServiceTrial.i').read_text(errors='replace')
needle = 'template<class T> class shared_ptr\n{\nprivate:'
assert text.count(needle) == 1
profile = pre/'VisitFindProfile.cpp'
profile.write_text(text.replace(needle, 'template<class T> class shared_ptr\n{\npublic:\n    __declspec(noinline) ~shared_ptr() {}\nprivate:', 1))
obj = out/'NativeVisitFindProfile.obj'
compile_flags = ['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(profile)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, candidate, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$find@VVisit@RBX@@@ServiceProvider@'))
target, targetrefs, _ = match.target('2008-06','00452b40')
assert match.exact_match(target,targetrefs,candidate,refs)
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
calls = []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5]+10*i)
    offset -= start
    if kind == 20 and 0 <= offset < len(candidate)-3:
        value = (0x452b40+offset+4+struct.unpack_from('<i',target,offset)[0]) & 0xffffffff
        calls.append((symbols[symbol][0],value))
expected = [('?call_once@boost@@',0x557330), ('??$doGetClassIndex@VVisit',0x44f4a0),
            ('?resize@?$vector@',0x4124c0), ('?call_once@boost@@',0x557330),
            ('??$doDeclare@$1?sVisit',0x44f2f0), ('?findServiceByClassName@ServiceProvider@',0x572a90),
            ('??1?$shared_ptr@VInstance@',0x600660), ('??4shared_count@',0x4025b0),
            ('??1?$shared_ptr@VInstance@',0x600660)]
assert len(calls) == len(expected) and all(n.startswith(p) and v == want for (n,v),(p,want) in zip(calls,expected)), calls
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),
           'preprocess_flags':flags,'compile_flags':compile_flags,'address':'00452b40','size':len(candidate),
           'calls':[{'symbol':n,'target':hex(v)} for n,v in calls],
           'scope':'Inactive compiler profile uses generated noinline empty shared_ptr destructor to expose call sites. Destructor selection, Visit layout, RTTI and runtime remain unproven; never run.'}
(root/'work/2008-06/shared-layouts/visit-service-trial.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS inactive Visit service lookup body and targets')

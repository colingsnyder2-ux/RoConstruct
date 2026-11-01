"""Verify original DataModel status accessors using typed RunService fields."""
import hashlib,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import rebuild,match
out=ROOT/'rebuild/2008-06/out/native-layouts'
base=json.loads((ROOT/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
source=ROOT/'rebuild/2008-06/native-classes/DataModelTiming.cpp'
obj=out/'NativeDataModelTiming.obj'
flags+=['/Fo'+str(obj),str(source)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
assert code==0,log
raw=obj.read_bytes();rows=[]
for address,prefix in [('005757d0','?getGameTime@DataModel@RBX'),('005757e0','?getFrameRate@DataModel@RBX')]:
    symbol,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    target,target_refs,_=match.target('2008-06',address)
    assert match.exact_match(target,target_refs,body,refs),(address,len(body),len(target))
    rows.append(dict(address=address,symbol=symbol,size=len(body)))
paths=[Path(__file__),source,ROOT/'rebuild/2008-06/native-headers/v8datamodel/DataModel.h',ROOT/'rebuild/2008-06/native-headers/util/RunStateOwner.h',ROOT/'tools/rbxgs/Client/Rendering/g3d/include/G3D/Stopwatch.h']
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(ROOT/'work/2008-06/shared-layouts/datamodel-timing-working.json').write_text(json.dumps(dict(sources={str(p.relative_to(ROOT)):sha(p) for p in paths},object_sha256=sha(obj),flags=flags,methods=rows,scope='Inactive typed accessors, relocation-masked original code; full RunService ABI and runtime linkage remain open.'),indent=2)+'\n')
print('PASS: two original DataModel timing bodies')

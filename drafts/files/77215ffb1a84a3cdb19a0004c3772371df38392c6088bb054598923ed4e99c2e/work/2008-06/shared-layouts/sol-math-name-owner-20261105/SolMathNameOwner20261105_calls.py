import sys,json
from pathlib import Path
root=Path.cwd();sys.path.insert(0,str(root/'rebuild/2008-06/tests'));import native_check_runner as r
from roc import match
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105';rows=json.loads((out/'native-evidence.json').read_text());results=[]
# Offsets and destinations reviewed against fresh original disassembly; semantic
# identities also recorded by tilt matrix/quadrant trials. Decoration from COFF.
plans=[[(0x4d,'00513b70','??0Matrix3@G3D@@QAE@MMMMMMMMM'),(0x56,'005de890','?matrixTiltZ@Math@'),(0x62,'00513220','??0Matrix3@G3D@@QAE@ABV'),(0x8c,'005de910','?matrixTiltNegativeZ@Math@'),(0x98,'00513220','??0Matrix3@G3D@@QAE@ABV'),(0xa1,'00513e20','?identity@Matrix3@'),(0xad,'00513220','??0Matrix3@G3D@@QAE@ABV')],[(0x18,'00513240','?getColumn@Matrix3@'),(0x49,'006a1bb0','_floor'),(0x4e,'006a17f0','__ftol2_sse')],[],[(9,'00554270','?getNullName@Name@'),(0x1a,'00554270','?getNullName@Name@'),(0x4b,'00554270','?getNullName@Name@'),(0x54,'00554270','?getNullName@Name@')]]
for row,plan in zip(rows,plans):
 p=Path(row['object']);_,symbols,_,_=match._coff_data_index(p.read_bytes());names=set(v[0] for v in symbols.values());check=row['checks'][0];calls=[]
 for offset,target,prefix in plan:
  found=[n for n in names if n.startswith(prefix)];assert len(found)==1,(prefix,found);calls.append(dict(offset=offset,target=target,symbol=found[0]))
 result=r.analyze_object(dict(checks=[dict(addr=check['addr'],symbol=check['symbol'],calls=calls)],ranges=[],layouts=[]),p);results.append(dict(object=str(p),**result))
(out/'reviewed-call-proof.json').write_text(json.dumps(results,indent=2));print(json.dumps([dict(object=Path(v['object']).name,proof=v['checks'][0]['call_identity']) for v in results],indent=2))

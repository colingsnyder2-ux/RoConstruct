import sys,json,hashlib
from pathlib import Path
root=Path.cwd(); sys.path.insert(0,str(root/'rebuild/2008-06/tests'))
import native_check_runner as r
out=root/'work/2008-06/shared-layouts/sol-math-name-owner-20261105'
cmd=json.loads((root/'work/2008-06/native-doc-relinks/20261105-131253-90ee3d03/command.json').read_text())
specs=[('NativeMathTiltMatricesFull.obj','005de990','?matrixTiltQuadrant@Math@RBX@@SA?BVMatrix3@G3D@@H@Z'),('NativeMathTiltQuadrantFull.obj','005dea60','?toYAxisQuadrant@Math@RBX@@SAHABVCoordinateFrame@G3D@@@Z'),('NativeMathClosestRayFull.obj','005df270','?closestPointOnRay@Math@RBX@@SA?AVVector3@G3D@@ABVRay@4@0@Z'),('NativeNameCompareFull.obj','0041faa0','?compare@Name@RBX@@SAHAAV12@0@Z')]
rows=[]
for name,addr,sym in specs:
 p=next(Path(x) for x in cmd['arguments'] if Path(x).name==name)
 rows.append(dict(object=str(p),sha256=r.sha(p),**r.analyze_object(dict(checks=[dict(addr=addr,symbol=sym)],ranges=[],layouts=[]),p)))
(out/'native-evidence.json').write_text(json.dumps(rows,indent=2))
print(json.dumps(rows,indent=2))

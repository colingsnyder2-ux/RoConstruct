"""Record camera-command ABI mismatch without activating donor Workspace layout."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
source = root / 'rebuild/2008-06/experiments/trials/NativeCameraCheckedTrial.cpp'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
obj = out / 'NativeCameraCheckedTrial.obj'
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')] + ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
functions = match.coff_functions(obj.read_bytes())
rows = []
for cls, address in [('AttachCameraCommand','0057dcb0'),('TrackCameraCommand','0057dce0'),('FollowCameraCommand','0057dd10'),('WatchCameraCommand','0057dd40')]:
    name, body, refs = next(x for x in functions if x[0].startswith('?isChecked@'+cls+'@RBX@@'))
    target, targetrefs, _ = match.target('2008-06', address)
    assert not match.exact_match(target, targetrefs, body, refs)
    donor = struct.pack('<I', 0x270)
    native = struct.pack('<I', 0x288)
    assert body.count(donor) == 2 and target.count(native) == 2
    assert match.exact_match(target, targetrefs, body.replace(donor, native), refs)
    rows.append({'class':cls,'address':address,'size':len(body),'donor_workspace_interface':'0x270','original_workspace_interface':'0x288','normalization_only_matches':True})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
headers = [root / 'rebuild/2008-06/native-headers/StandardVerbs.h', root / 'tools/rbxgs/Client/App/include/v8datamodel/Workspace.h', root / 'tools/rbxgs/Client/App/include/v8datamodel/Camera.h']
receipt = {'source_sha256':sha(source),'observer_sha256':sha(Path(__file__)),'object_sha256':sha(obj),'headers':{str(p.relative_to(root)):sha(p) for p in headers},'flags':flags,'methods':rows,'scope':'Mismatch evidence only; normalization is not compiled or linked. Workspace constructor/destructor and interface offsets require native layout proof.'}
(root / 'work/2008-06/shared-layouts/camera-checked-donor-mismatch.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS mismatch detection: donor +0x270, original +0x288')

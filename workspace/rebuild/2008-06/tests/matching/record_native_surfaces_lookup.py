"""Compare recovered 2008 surface lookup with linked donor implementation."""
import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';source=root/'rebuild/2008-06/experiments/trials/NativeSurfacesLookupTrial.cpp';obj=out/'NativeSurfacesLookupTrial.obj';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out);assert code==0,log
prefix='??ASurfaces@RBX@@QAEA';name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith(prefix));target,targetrefs,_=match.target('2008-06','005ecc00');assert match.exact_match(target,targetrefs,body,refs)
donor=root/'rebuild/2008-06/out/RbxgsApp/linked/glue_surfaces.obj';donor_name,donor_body,donor_refs=next(x for x in match.coff_functions(donor.read_bytes()) if x[0].startswith(prefix));assert not match.exact_match(target,targetrefs,donor_body,donor_refs)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
(root/'work/2008-06/shared-layouts/surfaces-lookup-trial.json').write_text(json.dumps({'address':'005ecc00','size':len(body),'exact':True,'donor_exact':False,'source_sha256':sha(source),'object_sha256':sha(obj),'donor_sha256':sha(donor),'observer_sha256':sha(Path(__file__)),'scope':'Inactive replacement. Original defaults to Top; linked donor defaults to Back. Other members, lifetimes, current link ownership and runtime remain unproven.'},indent=2)+'\n')
print('PASS native surface lookup; linked donor differs')

import hashlib,json,re,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'document-swap-link-trial';proof=root/'work/2008-06/shared-layouts';basepath=proof/'document-swap-provider-trial.json';base=json.loads(basepath.read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for path,value in base['objects'].items():assert sha(root/path)==value,('stale baseline',path)
a=json.loads((proof/'velocity-set-hole-trial.json').read_text());objects=[out/'NativeVelocitySetHoleTrial.obj'];expected=[a['object_sha256']]
for p,h in zip(objects,expected):assert sha(p)==h,('stale object',p)
args=[('/OUT:NativeDocSetHoleProbe.exe' if x.upper().startswith('/OUT:') else '/MAP:NativeDocSetHoleProbe.map' if x.upper().startswith('/MAP:') else x) for x in base['link_flags']]+list(map(str,objects));code,log=rebuild.run(rebuild.toolchain(21022),'link',args,work);(work/'NativeDocSetHoleProbe.log').write_text(log);errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',x)];receipt={'scope':'Isolated incompatible ABI diagnostic; never run.','baseline_errors':len(base['errors']),'baseline_receipt_sha256':sha(basepath),'link_exit':code,'errors':errors,'objects':{str(p.relative_to(root)):sha(p) for p in objects},'observer_sha256':sha(Path(__file__))};(proof/'set-hole-document-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('SetHole probe: exit',code,'errors',len(errors),'baseline',len(base['errors']))

import hashlib,json,re,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts';work=out/'document-swap-link-trial';proof=root/'work/2008-06/shared-layouts';basepath=proof/'document-swap-provider-trial.json';base=json.loads(basepath.read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
for path,value in base['objects'].items():assert sha(root/path)==value,('stale baseline',path)
a=json.loads((proof/'grab-tool-lifetime-trial.json').read_text());obj=out/'NativeGrabToolTrial.obj';assert sha(obj)==a['object_sha256']
b=json.loads((proof/'grab-methods-trial.json').read_text()); c=json.loads((proof/'grab-name-trial.json').read_text());extra=[out/'NativeGrabMethodsTrial.obj',out/'NativeGrabNameTrial.obj'];
for path,record in zip(extra,[b,c]):assert sha(path)==record['object_sha256']
args=[('/OUT:NativeDocGrabProbe.exe' if x.upper().startswith('/OUT:') else '/MAP:NativeDocGrabProbe.map' if x.upper().startswith('/MAP:') else x) for x in base['link_flags']]+[str(obj)]+list(map(str,extra));code,log=rebuild.run(rebuild.toolchain(21022),'link',args,work);(work/'NativeDocGrabProbe.log').write_text(log);errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005)\b',x)];receipt={'scope':'Isolated incompatible ABI diagnostic; never run.','baseline_errors':len(base['errors']),'baseline_receipt_sha256':sha(basepath),'link_exit':code,'errors':errors,'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(proof/'grab-document-probe.json').write_text(json.dumps(receipt,indent=2)+'\n');print('Grab probe: exit',code,'errors',len(errors),'baseline',len(base['errors']))

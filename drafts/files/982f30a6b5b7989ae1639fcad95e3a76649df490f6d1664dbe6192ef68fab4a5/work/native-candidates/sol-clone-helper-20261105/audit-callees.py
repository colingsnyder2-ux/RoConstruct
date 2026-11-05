exec(Path('work/native-candidates/sol-clone-helper-20261105/analyze.py').read_text(encoding='utf-8-sig'))
calls=[{'offset':37,'target':'00593480','symbol':refs[1]['symbol']},{'offset':44,'target':'006a0920','symbol':refs[2]['symbol']},{'offset':100,'target':'00593250','symbol':refs[3]['symbol']},{'offset':217,'target':'005a2fe0','symbol':refs[5]['symbol']}]
manifest={'jobs':[{'source':'native-classes/InstanceFromXmlRoot.cpp','checks':[{'addr':'00559250','symbol':name,'calls':calls}]}]};(out/'proof.json').write_text(json.dumps(manifest,indent=2))
archive=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib');a=archive.read_bytes();o=8;providers=[]
while o+60<=len(a):
 n=int(a[o+48:o+58]);member=a[o:o+16].decode().strip();d=a[o+60:o+60+n];o+=60+n+(n&1)
 if d[:2]!=b'\x4c\x01':continue
 try: fs=match.coff_functions(d)
 except Exception:continue
 for sym,b,rr in fs:
  for c in calls:
   if sym!=c['symbol']:continue
   target,tr,_=match.target('2008-06',c['target']);providers.append({'symbol':sym,'member':member,'sha256':hashlib.sha256(d).hexdigest(),'size':len(b),'original':c['target'],'normalized_exact':match.exact_match(target,tr,b,rr)})
(out/'providers.json').write_text(json.dumps({'archive_sha256':hashlib.sha256(a).hexdigest(),'providers':providers},indent=2));print(json.dumps(providers,indent=2))

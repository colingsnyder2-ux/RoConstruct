import json,hashlib,struct
from pathlib import Path
O=Path('work/2008-06/shared-layouts/sol-archive-resolve-refresh-20261105');P=Path('work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105');ns={};exec((O/'audit.py').read_text().split('manifest=json.loads')[0],ns);H=ns['H'];coff=ns['coff'];bodies=ns['bodies']
a=json.loads((P/'actual-command.json').read_text());r=json.loads((P/'unit-000/receipt.json').read_text());e=json.loads((P/'executed-command.json').read_text());src=Path(a['source']).read_bytes();cand=Path(r['source']).read_bytes();start=src.index(b'bool ArchiveBinder::resolveRefs()');end=src.index(b'bool ArchiveBinder::resolveIDREF',start);assert cand==src[:start]+src[end:]
old=(P/'old.obj').read_bytes();new=(P/'unit-000/candidate.obj').read_bytes();ob=bodies(coff(old));nb=bodies(coff(new));removed=set(ob)-set(nb)
def comdat(b):
 sy,secs=coff(b);_,_,_,ps,nt,_,_=struct.unpack_from('<HHIIIHH',b);sel={};i=0
 while i<nt:
  n,v,s,t,c=sy[i];x=b[ps+i*18:ps+(i+1)*18];na=x[17]
  if c==3 and s>0 and na and n==secs[s][0]:
   aux=b[ps+(i+1)*18:ps+(i+2)*18];sel[s]={'selection':aux[14],'association':struct.unpack_from('<h',aux,12)[0] if aux[14]==5 else None}
  i+=1+na
 return {n:{'comdat':bool(secs[s][3]&0x1000),'section_definition':sel.get(s)} for n,v,s,t,c in sy.values() if s>0 and n in ob and not n.startswith('.')}
x=comdat(old);y=comdat(new);diff={n:[x.get(n),y.get(n)] for n in ob.keys()&nb.keys() if x.get(n)!=y.get(n)}
proof={'source_deletion_only':True,'removed_source_sha256':H(src[start:end]),'args_exact_except_source_outputs_and_runner_pdb':[z for z in e['command'][1:] if not z.startswith(('/Fo','/Fd')) and z!=r['source']]==[z for z in a['args'] if not z.startswith('/Fo') and z!=a['source']],'environment_equal':all(e['environment'][k]==v for k,v in a['environment'].items()),'removed_definition_metadata':{n:{'body':ob[n],'comdat':x.get(n)} for n in sorted(removed)},'retained_comdat_metadata_changes':diff,'vtable':ob['??_7ArchiveBinder@@6B@'],'vtable_equal':ob['??_7ArchiveBinder@@6B@']==nb['??_7ArchiveBinder@@6B@']}
(O/'provenance-refresh.json').write_text(json.dumps(proof,indent=2));print(json.dumps({k:v for k,v in proof.items() if k not in ['removed_definition_metadata','vtable']},indent=2))

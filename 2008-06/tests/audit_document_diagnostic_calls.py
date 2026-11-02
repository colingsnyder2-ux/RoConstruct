"""Audit direct calls from selected Doc methods in frozen diagnostic; never run."""
import hashlib,json,re,struct,sys
from collections import defaultdict
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
proof=root/'work/2008-06/shared-layouts';d=json.loads((proof/'document-diagnostic-selected-code.json').read_text());base=json.loads((proof/'workspace-writer-near-full-worker-probe.json').read_text());folder=root/'rebuild/2008-06/out/native-layouts/worker-writer-near/full-probe';exe=folder/'candidate.exe';linkmap=folder/'candidate.map';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert sha(exe)==d['exe_sha256'] and sha(linkmap)==d['map_sha256']
obj=root/'rebuild/2008-06/out/native-layouts/NativeDocumentHistoryProfile.obj';assert sha(obj)==d['object_sha256'];raw=obj.read_bytes();sections,symbols,defs,_=match._coff_data_index(raw);pe=pefile.PE(str(exe));known=match._functions('2008-06');mapped=defaultdict(list)
for line in linkmap.read_text(errors='replace').splitlines():
 m=re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+.*?([^\s:]+\.obj)\s*$',line)
 if m:mapped[int(m[2],16)].append((m[1],m[3]))
paths={}
for p,h in base['snapshot_objects'].items():
 q=root/p
 if q.exists() and sha(q)==h:paths.setdefault(q.name.lower(),[]).append(q)
cache={}
def get_functions(path):
 if path not in cache:cache[path]={n:(b,r) for n,b,r in match.coff_functions(path.read_bytes())}
 return cache[path]
rows=[]
for item in d['methods']:
 if not item.get('original_match') or not item.get('coff_pe_match'):continue
 symbol=item['symbol'];original_addr=int(item['original_address'],16);pe_addr=int(item['pe_address'],16);target,_,_=match.target('2008-06',item['original_address']);start,index=defs[symbol];table=sections[index]
 for i in range(table[7]):
  offset,si,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);offset-=start
  if kind!=20 or offset<=0 or offset+4>len(target) or target[offset-1] not in (0xe8,0xe9):continue
  orig=(original_addr+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff;loc=pe_addr+offset;disp=pe.get_data(loc-pe.OPTIONAL_HEADER.ImageBase,4)
  if len(disp)!=4:continue
  dest=(loc+4+struct.unpack('<i',disp)[0])&0xffffffff;reloc=symbols[si][0];original=known.get('%08x'%orig);status='original_target_unindexed' if not original else 'provider_not_available';provider=None
  if original:
   original_code,original_relocs,_=match.target('2008-06','%08x'%orig)
   for resolved,owner in mapped.get(dest,[]):
    for path in paths.get(owner.lower(),[]):
     fn=get_functions(path).get(resolved)
     if fn:
      code,refs=fn;final=pe.get_data(dest-pe.OPTIONAL_HEADER.ImageBase,len(code));status='matched' if match.exact_match(original_code,original_relocs,code,refs) and match.exact_match(code,refs,final,refs) else 'different';provider={'symbol':resolved,'object':owner};break
    if provider:break
   if status=='provider_not_available':
    first=pe.get_data(dest-pe.OPTIONAL_HEADER.ImageBase,1)
    if first and first!=original_code[:1]:status='different_first_opcode'
  rows.append({'caller':symbol,'offset':offset,'relocation':reloc,'original_target':hex(orig),'linked_target':hex(dest),'status':status,'provider':provider})
from collections import Counter
result={'scope':'Direct E8/E9 COFF relocations only; indexed original targets and hash-verified snapshot objects. First-opcode differences are checked directly in PE when provider object is unavailable. Relocations masked; data, indirect calls, callee identity and runtime unproven.','exe_sha256':sha(exe),'map_sha256':sha(linkmap),'doc_object_sha256':sha(obj),'counts':dict(Counter(x['status'] for x in rows)),'edges':rows,'observer_sha256':sha(Path(__file__))};(proof/'document-diagnostic-call-audit.json').write_text(json.dumps(result,indent=2)+'\n');print('Doc direct edges:',result['counts']);print('Different:',[(x['relocation'],x['original_target'],x['linked_target']) for x in rows if x['status'].startswith('different')][:20])

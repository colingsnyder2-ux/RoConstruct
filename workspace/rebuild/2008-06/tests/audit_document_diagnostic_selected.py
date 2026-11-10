"""Audit proven Doc bodies in the frozen diagnostic PE; never execute it."""
import hashlib,json,re,sys
from pathlib import Path
import pefile
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match
proof=root/'work/2008-06/shared-layouts';diagnostic=json.loads((proof/'workspace-writer-near-full-worker-probe.json').read_text());assert diagnostic['candidate_exit']==0 and not diagnostic['candidate_errors']
folder=root/'rebuild/2008-06/out/native-layouts/worker-writer-near/full-probe';exe=folder/'candidate.exe';linkmap=folder/'candidate.map';obj=root/'rebuild/2008-06/out/native-layouts/NativeDocumentHistoryProfile.obj';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
expected=next(v for k,v in diagnostic['snapshot_objects'].items() if Path(k).name==obj.name);assert sha(obj)==expected
receipt=json.loads((proof/'document-current-constructor-corrected.json').read_text());functions={n:(b,r) for n,b,r in match.coff_functions(obj.read_bytes())};pe=pefile.PE(str(exe));mapped={}
for line in linkmap.read_text(errors='replace').splitlines():
 m=re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+.*?([^\s:]+\.obj)\s*$',line)
 if m and m[3].lower()==obj.name.lower():mapped[m[1]]=int(m[2],16)
methods=[receipt['constructor']]+receipt['exact_methods']+[x for x in receipt['ownership_dependencies'] if x['symbol'].startswith('??1CRobloxDoc@@')];rows=[]
for m in methods:
 symbol=m['symbol'];address=mapped.get(symbol);item={'symbol':symbol,'original_address':m['address'],'selected':address is not None}
 if address is not None and symbol in functions:
  code,relocs=functions[symbol];original,original_relocs,_=match.target('2008-06',m['address']);final=pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,len(code));item.update(pe_address=hex(address),size=len(code),original_match=match.exact_match(original,original_relocs,code,relocs),coff_pe_match=match.exact_match(code,relocs,final,relocs))
 rows.append(item)
result={'scope':'Frozen mixed-ABI diagnostic PE only; masked relocations, no call-target or runtime proof and no live swap.','exe_sha256':sha(exe),'map_sha256':sha(linkmap),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__)),'methods':rows,'selected':sum(x['selected'] for x in rows),'both_matches':sum(x.get('original_match',False) and x.get('coff_pe_match',False) for x in rows)}
(proof/'document-diagnostic-selected-code.json').write_text(json.dumps(result,indent=2)+'\n');print('Doc methods selected:',result['selected'],'/',len(rows),'original and PE matches:',result['both_matches']);print('Exceptions:',[x for x in rows if not (x.get('original_match') and x.get('coff_pe_match'))])

"""Check original GUID registry global references; no runtime or layout proof."""
import bisect,hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root))
from roc import match
base,image=match._image('2008-06');needle=struct.pack('<I',0x9705e8)
functions=match._functions('2008-06');ranges=sorted((int(k,16),int(k,16)+v['size']) for k,v in functions.items() if v.get('kind')=='code');starts=[x[0] for x in ranges];references=[];all_occurrences=[];offset=0
while True:
 offset=image.find(needle,offset)
 if offset<0:break
 address=base+offset;all_occurrences.append(address);index=bisect.bisect_right(starts,address)-1
 if index>=0 and address<ranges[index][1]:references.append((address,starts[index]))
 offset+=1
expected=[(0x49a077,0x49a040),(0x49a091,0x49a040),(0x49bad9,0x49ba80),(0x49bbe2,0x49bba0),(0x4b37a2,0x4b3760)]
assert references==expected,references
assert all_occurrences==[a for a,_ in expected],all_occurrences
for address,prefix in [(0x49bad9,bytes.fromhex('e80597008d5e20')),(0x49bbe2,bytes.fromhex('e80597008d6f20')),(0x4b37a2,bytes.fromhex('e80597008d6f20'))]:
 assert image[address-base:address-base+len(prefix)]==prefix
sha=lambda b:hashlib.sha256(b).hexdigest()
result={'scope':'All raw occurrences of global address in mapped image fall within four indexed functions; this does not prove absence of computed/indirect references, destructor ABI, or runtime safety.','global':'0x9705e8','references':[{'operand':hex(a),'function':hex(f)} for a,f in references],'image_sha256':sha(image),'functions_sha256':sha((root/'work/2008-06/functions.jsonl').read_bytes()),'observer_sha256':sha(Path(__file__).read_bytes())}
(root/'work/2008-06/shared-layouts/guid-registry-global-references.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS five global references across four indexed functions; reader lock offset +0x20')

import pefile,re,struct,collections,hashlib,json
from pathlib import Path
p=pefile.PE('work/2008-06/original-p4-reference/Roblox.exe');d=bytes(p.__data__);base=p.OPTIONAL_HEADER.ImageBase;image=p.get_memory_mapped_image();r=lambda a:struct.unpack_from('<I',image,a-base)[0] if base<=a<base+len(image)-4 else 0
names={}
for m in re.finditer(rb'\.\?AV[^\x00]{1,400}\x00',d):
 try:a=p.get_rva_from_offset(m.start())+base;names[a-8]=m.group()[:-1].decode('ascii','replace')
 except:pass
found=[]
for section in p.sections:
 if not section.Name.startswith(b'.rdata'):continue
 start=section.VirtualAddress;end=min(len(image),start+section.Misc_VirtualSize)
 for off in range((start+3)&~3,end-20,4):
  sig,ofs,cd,td,ch=struct.unpack_from('<5I',image,off)
  if sig or ofs>0x1000 or cd>0x1000 or td not in names or not (base<=ch<base+len(image)-16):continue
  n=r(ch+8);arr=r(ch+12)
  if not (0<n<40 and base<=arr<base+len(image)-4*n):continue
  bases=[]
  for j in range(n):
   bd=r(arr+j*4);typ=r(bd);name=names.get(typ)
   if name:bases.append(name)
  if not any(x.startswith('.?AVGetSet@?$TypedPropertyDescriptor@') for x in bases):continue
  col=off+base;pat=struct.pack('<I',col);q=0
  while (q:=d.find(pat,q))>=0:
   try:vt=p.get_rva_from_offset(q)+base+4;slots=tuple(r(vt+i*4) for i in range(4));found.append((names[td],vt,slots))
   except:pass
   q+=1
families=collections.Counter();pairs=collections.Counter();rows=[]
for name,vt,slots in found:
 if 'BoundPropGetSet@' in name:fam='BoundPropGetSet'
 elif 'GetSetImpl@' in name:fam='GetSetImpl'
 elif 'GetImpl@' in name:fam='GetImpl'
 elif 'SetImpl@' in name:fam='SetImpl'
 elif 'SurfaceGetSet@' in name:fam='SurfaceGetSet'
 else:fam='UNCLASSIFIED'
 families[fam]+=1;pairs[(fam,slots[:2])]+=1;rows.append({'type':name,'vtable':hex(vt),'slots':[hex(x) for x in slots],'family':fam})
expected={'GetSetImpl':98,'BoundPropGetSet':55,'SurfaceGetSet':18,'GetImpl':11,'SetImpl':2};assert dict(families)==expected,families
for (fam,slots),n in pairs.items():
 value=(0x565950,0x60a2f0) if fam=='GetImpl' else (0x60a2f0,0x565950) if fam=='SetImpl' else (0x60a2f0,0x60a2f0)
 assert slots==value,(fam,slots,n)
assert image[0x565950-base:0x565950-base+3]==bytes.fromhex('b001c3')
assert image[0x60a2f0-base:0x60a2f0-base+3]==bytes.fromhex('32c0c3')
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest();receipt={'scope':'All 184 discoverable RTTI/COL vtables whose hierarchy includes TypedPropertyDescriptor::GetSet. Stripped RTTI, unreferenced classes, runtime ABI and other descriptor hierarchies are unproven.','families':dict(families),'methods':rows,'original_image_sha256':sha('work/2008-06/original-p4-reference/Roblox.exe'),'observer_sha256':sha(__file__)}
Path('work/2008-06/shared-layouts/getset-inventory-worker.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS GetSet RTTI inventory',len(rows),'vtables',dict(families))

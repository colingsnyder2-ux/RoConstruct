exec(open('work/2008-06/shared-layouts/sol-clone-provenance-20261105/catalog.py').read().split('seeds=')[0])
seeds=['00420190','00423980']; refs={}
for value in [0x92dd78,0x96c2b4]:
 refs[hex(value)]=[]
 for f in rows:
  va=int(f['addr'],16);b=bytes(img[va-base:va-base+f['size']])
  if struct.pack('<I',value) in b:refs[hex(value)].append(f['addr']);seeds.append(f['addr'])
a={}
for s in set(seeds):
 f=idx.get(s)
 if f:
  va=int(s,16);b=bytes(img[va-base:va-base+f['size']]);a[s]={'sha256':hashlib.sha256(b).hexdigest(),'asm':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(b,va)]}
strings={hex(v):bytes(img[v-base:v-base+100]).split(b'\0')[0].decode('ascii','replace') for v in [0x94a240]}
(out/'registry.json').write_text(json.dumps({'literal_refs':refs,'strings':strings,'functions':a},indent=2))
print(refs,strings)
for s in ['00420190','00423980']:print(s,'\n'+'\n'.join(a[s]['asm']))
p=Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib');r=p.read_bytes();o=8;providers=[]
by={}
for f in rows:by.setdefault(f['size'],[]).append(f)
while o+60<=len(r):
 n=int(r[o+48:o+58]);member=r[o:o+16].decode().strip();d=r[o+60:o+60+n];o+=60+n+(n&1)
 if d[:2]!=b'\x4c\x01':continue
 try:fs=match.coff_functions(d)
 except Exception:continue
 for s,b,rel in fs:
  if not ('clone@Instance' in s or 'create@' in s or 'Creator@' in s or 'onMouseMove@AxisMoveTool' in s):continue
  hits=[]
  for f in by.get(len(b),[]):
   va=int(f['addr'],16)
   if match.exact_match(bytes(img[va-base:va-base+len(b)]),f.get('relocs',[]),b,rel):hits.append(f['addr'])
  secs,syms,defs,starts=match._coff_data_index(d);v,si=defs[s];sec=secs[si];rels=[]
  for j in range(sec[7]):
   ro,i,k=struct.unpack_from('<IIH',d,sec[5]+j*10)
   if v<=ro<v+len(b):rels.append({'offset':ro-v,'symbol':syms[i][0],'kind':k})
  providers.append({'symbol':s,'size':len(b),'member':member,'member_sha256':hashlib.sha256(d).hexdigest(),'hits':hits,'relocations':rels,'body_hex':b.hex()})
(out/'coff-catalog.json').write_text(json.dumps({'archive_sha256':hashlib.sha256(r).hexdigest(),'providers':providers},indent=2))
for x in providers:print(x['symbol'],x['size'],x['hits'])

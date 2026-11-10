exec(open('work/2008-06/shared-layouts/sol-clone-provenance-20261105/catalog.py').read().split('seeds=')[0])
seeds=['00593250','00593480','00557330','0041e0d0','0041df00','00405da0','00405ce0']
a={}
for s in seeds:
 f=idx.get(s)
 if not f:continue
 va=int(s,16);b=bytes(img[va-base:va-base+f['size']]);a[s]={'index':f,'sha256':hashlib.sha256(b).hexdigest(),'asm':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(b,va)]}
(out/'dispatch.json').write_text(json.dumps(a,indent=2))
for s,v in a.items():print(s,'\n'+'\n'.join(v['asm']))

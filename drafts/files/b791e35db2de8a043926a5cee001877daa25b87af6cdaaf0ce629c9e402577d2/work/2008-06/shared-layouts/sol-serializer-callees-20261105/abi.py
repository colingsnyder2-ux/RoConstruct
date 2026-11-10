import sys,json,struct,hashlib
from pathlib import Path
sys.path.insert(0,str(Path.cwd()))
from roc import libs,match,rebuild
import pefile,capstone
O=Path('work/2008-06/shared-layouts/sol-serializer-callees-20261105');j=json.loads((O/'inventory.json').read_text());pe=pefile.PE('clients/2008-06/Roblox.exe');md=capstone.Cs(3,4);sha=lambda b:hashlib.sha256(b).hexdigest()
headers=['tools/rbxgs/Client/App/include/v8xml/SerializerV2.h','tools/rbxgs/Client/App/include/util/Object.h','tools/rbxgs/Client/App/include/v8tree/Instance.h','tools/rbxgs/Client/App/v8xml/SerializerV2.cpp','rebuild/2008-06/native-headers/metadata-load/v8xml/SerializerV2.h','work/2008-06/shared-layouts/sol-cumulative-links-20261105/serializer-context/v8tree/Instance.h']
r={'headers':{p:sha(Path(p).read_bytes()) for p in headers},'original':{},'vtable_providers':[],'critical_import_definitions':[]}
for a in ['00593250','00592940','00592720','005931e0','00420190','0055b6f0','00443e50','0063fad0','00443eb0','0041fc10']:
 t,tr,_=match.target('2008-06',a);r['original'][a]={'sha256':sha(t),'size':len(t),'asm':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(t,int(a,16))]}
for p in j['guards']:
 path=Path(p['path'])
 if path.suffix.lower() not in ('.lib','.obj'):continue
 for n,b in (libs.archive_members(path) if path.suffix.lower()=='.lib' else [(None,path.read_bytes())]):
  if b'??_7ArchiveBinder@@6B@' in b:
   secs,syms,funcs,starts=match._coff_data_index(b)
   if '??_7ArchiveBinder@@6B@' in funcs:
    v,sec=funcs['??_7ArchiveBinder@@6B@'];sc=secs[sec];rr=[]
    for k in range(sc[7]):
     off,ix,typ=struct.unpack_from('<IIH',b,sc[5]+10*k)
     if v<=off<v+20:rr.append({'slot':(off-v)//4,'symbol':syms[ix][0],'type':typ})
    r['vtable_providers'].append({'path':str(path),'member':n,'sha256':sha(b),'slots':rr})
  if b'__imp___invalid_parameter_noinfo' in b or b'__RTDynamicCast' in b:
   try:d=rebuild.coff_externals(b)
   except Exception:continue
   for s,v in d.items():
    if v and s in ('__imp___invalid_parameter_noinfo','__RTDynamicCast','__imp____RTDynamicCast'):
     r['critical_import_definitions'].append({'path':str(path),'member':n,'sha256':sha(b),'symbol':s,'note':'import COFF definition; selected IAT/DLL/runtime binding not proven'})
for a in [0x92907c,0x929174]:
 r.setdefault('cast_rtti',{})[hex(a)]=pe.get_data(a+8-pe.OPTIONAL_HEADER.ImageBase,100).split(b'\0')[0].decode('ascii')
(O/'abi-evidence.json').write_text(json.dumps(r,indent=2));print(json.dumps({k:v for k,v in r.items() if k!='original'},indent=2))

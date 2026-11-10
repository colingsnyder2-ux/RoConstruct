from pathlib import Path
import sys,json,hashlib,struct
sys.path.insert(0,str(Path.cwd()))
from roc import match,clients,native_asm
import capstone,pefile
out=Path('work/2008-06/shared-layouts/sol-content-abi-20261105')
obj=Path('work/2008-06/native-check-runs/20261105-122951-04c3d3fa/unit-000/candidate.obj')
b=obj.read_bytes(); secs,syms,funcs,_=match._coff_data_index(b)
name=next(n for n in funcs if n.startswith('?load@ContentProvider@RBX@@'))
v,s=funcs[name]; sec=secs[s]; rel=[]
for k in range(sec[7]):
 off,idx,kind=struct.unpack_from('<IIH',b,sec[5]+10*k)
 rel.append(dict(offset=off-v,symbol=syms[idx][0],kind=kind,addend=struct.unpack_from('<I',b,sec[4]+off)[0]))
exe=clients.exe_path('2008-06',clients.load()['2008-06']); pe=pefile.PE(str(exe)); base=pe.OPTIONAL_HEADER.ImageBase
imports={hex(i.address):dict(dll=d.dll.decode(),name=i.name.decode() if i.name else None,ordinal=i.ordinal) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
def dis(addr,size):
 return [f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(pe.get_data(addr-base,size),addr)]
r=dict(object=str(obj),symbol=name,relocations=rel,imports={k:imports[k] for k in ['0x80245c','0x802468','0x802408','0x802440']},load=dis(0x5628e0,327),getContent=dis(0x561f20,354),vtables={})
for a in [0x82deac,0x82deb4]:
 target=struct.unpack('<I',pe.get_data(a-base,4))[0]
 r['vtables'][hex(a)]=dict(slot0=hex(target),body=dis(target,96))
paths=[obj,Path(exe),Path('rebuild/2008-06/native-classes/ContentProviderLoad.cpp'),Path('tools/rbxgs/Client/App/util/ContentProvider.cpp'),Path('tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def')]
vc=Path('tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/include')
paths += [vc/x for x in ['istream','ios','xstring','fstream','sstream','memory']]
paths += [Path('tools/libs/boost_1_35_0/boost')/x for x in ['scoped_ptr.hpp','checked_delete.hpp']]
r['hashes']={str(p):hashlib.sha256(p.read_bytes()).hexdigest() if p.exists() else None for p in paths}
(out/'evidence.json').write_text(json.dumps(r,indent=2),encoding='utf-8')
print(json.dumps({k:r[k] for k in ['relocations','imports','vtables']},indent=2))

r['delete_thunk']=dis(0x6a067a,6)
r['delete_identity']=native_asm.thunk_label('2008-06',0x6a067a)
r['mfc_delete_ordinal']=800
(out/'evidence.json').write_text(json.dumps(r,indent=2),encoding='utf-8')
print(r['delete_thunk'],r['delete_identity'])

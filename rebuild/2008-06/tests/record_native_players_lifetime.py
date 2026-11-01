"""Verify Players constructor/destructor, allocation size, and original vtable thunk."""
import pathlib,json,sys,hashlib,struct,pefile
r=pathlib.Path(__file__).resolve().parents[3];sys.path.insert(0,str(r));from roc import rebuild,match
out=r/'rebuild/2008-06/out/native-layouts';d=json.loads((r/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in d['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]+['/I'+str(r/'tools/rbxgs/Client/Network/raknet30/Source'),'/I'+str(r/'tools/rbxgs/Client/Network/include/Network')];src=r/'rebuild/2008-06/native-classes/PlayersLifetime.cpp';fixture=r/'rebuild/2008-06/tests/NativePlayersLayout.cpp';obj=out/'NativePlayersLifetime.obj'
for unit,o in [(src,obj),(fixture,out/'NativePlayersLayout.obj')]:
 c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(o),str(unit)],out);assert c==0,log
raw=obj.read_bytes();rows=[]
for a,p in [('0049bdc0','??0Players@Network@RBX'),('00499630','??1Players@Network@RBX')]:
 n,b,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(p));t,tr,_=match.target('2008-06',a);assert match.exact_match(t,tr,b,refs);rows.append(dict(address=a,size=len(b),symbol=n))
pe=pefile.PE(str(r/'work/2008-06/original-p4-reference/Roblox.exe'));base=pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I',pe.get_data(0x8227b0-base,4))[0]==0x499850
thunk,_,_=match.target('2008-06','00499850');assert thunk[:4]==bytes.fromhex('83 e9 10 e9') and (0x499850+8+struct.unpack_from('<i',thunk,4)[0])==0x499fb0
deleting,_,_=match.target('2008-06','00499fb0');assert (0x499fb0+8+struct.unpack_from('<i',deleting,4)[0])==0x499630
alloc,_,_=match.target('2008-06','00411fd0');assert bytes.fromhex('68 b0 01 00 00') in alloc
paths=[pathlib.Path(__file__),src,fixture,r/'rebuild/2008-06/native-headers/v8tree/Instance.h',r/'rebuild/2008-06/native-headers/util/IRenderable.h',r/'tools/rbxgs/Client/Network/include/Network/Players.h',r/'tools/rbxgs/Client/Network/Players.cpp'];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();(r/'work/2008-06/shared-layouts/players-lifetime-working.json').write_text(json.dumps(dict(sources={str(p.relative_to(r)):sha(p) for p in paths},object_sha256=sha(obj),methods=rows,original_allocation_size='0x1b0',vtable='0x8227b0',destructor_thunk='0x499850',deleting_destructor='0x499fb0',scope='Inactive relocation-masked lifecycle proof; complete virtual bindings and runtime integration remain open.'),indent=2)+'\n');print('PASS: Players constructor, destructor, size and original vtable thunk')

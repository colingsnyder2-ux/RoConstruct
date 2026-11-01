"""Verify native Players abuse predicate and its original direct binding."""
import pathlib,json,sys,hashlib,struct
r=pathlib.Path(__file__).resolve().parents[3];sys.path.insert(0,str(r));from roc import rebuild,match
out=r/'rebuild/2008-06/out/native-layouts';src=r/'rebuild/2008-06/native-classes/PlayersAbusePredicate.cpp';d=json.loads((r/'work/2008-06/shared-layouts/document-swap-current.json').read_text());f=[x for x in d['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];obj=out/'NativePlayersAbuse.obj';c,log=rebuild.run(rebuild.toolchain(21022),'cl',f+['/Fo'+str(obj),str(src)],out);assert c==0,log
raw=obj.read_bytes();n,b,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?canReportAbuse@Players@Network@RBX'));t,tr,_=match.target('2008-06','00496390');assert match.exact_match(t,tr,b,refs)
sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[n];tab=sec[idx];edges={}
for i in range(tab[7]):
 off,si,k=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start
 if 0<=off<=len(b)-4 and k==20:edges[sy[si][0]]=hex((0x496390+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff)
assert '0x49fe20' in edges.values(),edges
paths=[pathlib.Path(__file__),src,r/'rebuild/2008-06/native-headers/v8tree/Instance.h',r/'rebuild/2008-06/native-headers/util/IRenderable.h',r/'tools/rbxgs/Client/Network/include/Network/Players.h'];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();(r/'work/2008-06/shared-layouts/players-abuse-working.json').write_text(json.dumps(dict(sources={str(p.relative_to(r)):sha(p) for p in paths},object_sha256=sha(obj),address='00496390',size=len(b),direct_calls=edges,scope='Inactive original predicate and donor declaration. Full Players constructor/destructor ABI and runtime linkage remain unproven.'),indent=2)+'\n');print('PASS: real Players predicate and original client lookup')

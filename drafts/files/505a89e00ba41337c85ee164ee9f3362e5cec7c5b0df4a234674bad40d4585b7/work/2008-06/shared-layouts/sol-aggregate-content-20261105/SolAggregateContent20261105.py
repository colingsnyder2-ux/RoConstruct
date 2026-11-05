from pathlib import Path
import sys,json,hashlib,struct,collections,shutil
R=Path.cwd(); sys.path[:0]=[str(R),str(R/'rebuild/2008-06/tests'),str(R/'rebuild/2008-06/p6')]
from roc import libs,match,rebuild
from relink_native_document import prepare
from script_context_owner import references,data_symbols
F=R/'work/2008-06/shared-layouts/sol-aggregate-content-20261105'; V=R/'work/native-candidates/sol-aggregate-content-20261105'
P=R/'work/2008-06/shared-layouts/sol-content-owner-20261105'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def bh(b): return hashlib.sha256(b).hexdigest()
def save(n,x): (F/n).write_text(json.dumps(x,indent=2)+'\n',encoding='utf-8')
command=R/'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/native-doc-link-command.json'
c=json.loads(command.read_text()); tc=rebuild.toolchain(21022); inputs={}; missing=[]; paths=set()
for a in c['arguments']:
 try:
  _,ps=prepare([a],Path(c['cwd']),V,tc); paths.update(ps)
 except FileNotFoundError: missing.append(a)
for p in paths: inputs[str(p)]=sha(p)
inputs[str(command)]=sha(command)
base=Path(c['cwd'])/'null-tool-owner/linked.lib'; assert base in paths
members=list(libs.archive_members(base)); olds=[b for n,b in members if Path(n).name=='ContentProvider.obj']; assert len(olds)==1
old=olds[0]; candidate=P/'ContentProvider.obj'; new=candidate.read_bytes(); comparison=json.loads((P/'comparison.json').read_text())
assert bh(old)==comparison['baseline_object_sha256']; assert bh(new)==comparison['candidate_object_sha256']
frozen=json.loads((P/'frozen-inputs.json').read_text()); drift=[p for p,h in frozen.items() if not Path(p).is_file() or sha(p)!=h]
save('historical-inputs.json',dict(inputs=frozen,drift=drift)); assert not drift,drift
for p,h in frozen.items(): inputs[p]=h
inputs[str(candidate)]=sha(candidate)
a={n:(b,r) for n,b,r in match.coff_functions(old)}; b={n:(v,r) for n,v,r in match.coff_functions(new)}
common=set(a)&set(b); ra,rb=references(old),references(new); da,db=data_symbols(old),data_symbols(new)
assert not set(b)-set(a); assert all(a[n]==b[n] and ra[n]==rb[n] for n in common)
assert not set(db)-set(da); assert all(da[n]==db[n] for n in set(da)&set(db))
names=(set(a)-set(b))|(set(da)-set(db)); assert len(set(a)-set(b))==54 and len(set(da)-set(db))==19
save('comparison.json',dict(retained_bodies=len(common),retained_data=len(set(da)&set(db)),removed_functions=sorted(set(a)-set(b)),removed_data=sorted(set(da)-set(db)),old_sha256=bh(old),candidate_sha256=bh(new)))
providers=collections.defaultdict(list); consumers=[]; inventory=[]; skipped=[]; directives=[]; short_imports=[]
def scan(label,raw,replaced=False):
 inventory.append(dict(input=label,sha256=bh(raw),replaced=replaced))
 if raw[:4]==b'\x00\x00\xff\xff':
  sig1,sig2,version,machine,timestamp,size,ordinal,flags=struct.unpack_from('<HHHHIIHH',raw)
  assert version==0 and machine==0x14c and len(raw)==20+size,(label,version,machine,size,len(raw))
  parts=raw[20:].split(b'\x00'); assert len(parts)>=3
  name=parts[0].decode('latin-1'); dll=parts[1].decode('latin-1')
  short_imports.append(dict(input=label,symbol=name,dll=dll,sha256=bh(raw),external_relocations=0))
  if name in names: providers[name].append(label)
  return
 try: sections,symbols,defs,_=match._coff_data_index(raw)
 except Exception as e:
  skipped.append(dict(input=label,reason=str(e))); return
 if not replaced:
  for n in names & set(defs): providers[n].append(label)
 hits=set()
 for s in sections:
  for i in range(s[7]):
   off,idx,kind=struct.unpack_from('<IIH',raw,s[5]+10*i)
   if idx in symbols and symbols[idx][0] in names and symbols[idx][0] not in defs: hits.add(symbols[idx][0])
 if hits and not replaced: consumers.append(dict(input=label,symbols=sorted(hits)))
 # Preserve linker directives as raw evidence; default-library transitive closure is not claimed.
 if b'/DEFAULTLIB' in raw.upper(): directives.append(label)
for p in sorted(paths):
 if p.suffix.lower()=='.lib':
  for n,raw in libs.archive_members(p): scan(str(p)+'::'+n,raw,p==base and Path(n).name=='ContentProvider.obj')
 elif p.suffix.lower()=='.obj': scan(str(p),p.read_bytes())
scan('task-remainder::ContentProvider.obj',new)
classified=[dict(**row,bindings=[dict(symbol=n,available_surviving_definitions=providers[n],classification='available_surviving_definition' if providers[n] else 'UNRESOLVED') for n in row['symbols']]) for row in consumers]
unresolved=sorted({n for row in consumers for n in row['symbols'] if not providers[n]})
save('input-manifest.json',dict(inputs=inputs,missing=missing,search_paths=[str(tc[k]) for k in ('vc_lib','atlmfc_lib','sdk_lib')],scope='Actual explicit command inputs including every member of resolved explicit libraries. Implicit default-library closure NOT proven; same-name availability is not selected binding/ABI proof.',workspace_insert_caveat='Non-gated diagnostic: catch_relocs recorder failed; EH proof incomplete. SiteTrust coverage only when listed with concrete hash.'))
save('consumer-audit.json',dict(inventory=inventory,consumers=classified,providers=dict(providers),unresolved=unresolved,unparsed=skipped,short_imports=short_imports,default_library_directive_inputs=directives,scope='External relocations to 54 removed functions and 19 removed data; all actual resolved explicit inputs, every archive member. Implicit default libs and selected binding remain unproven.'))
# Recheck exact native provider in the actual command, without compilation.
native=Path(c['cwd'])/'NativeContentProviderLoadFull.obj'; raw=native.read_bytes(); proof=json.loads((P/'native-provider.json').read_text()); sym=proof['symbol']; rows=[x for x in match.coff_functions(raw) if x[0]==sym]; assert len(rows)==1
_,body,refs=rows[0]; target,mask,_=match.target('2008-06','005628e0'); assert match.exact_match(target,mask,body,refs)
_,errors=match.data_check('2008-06','005628e0',target,match.coff_data_refs(raw,sym)); assert not errors
save('native-provider.json',dict(path=str(native),sha256=sha(native),size=len(body),code_exact=True,data_errors=errors,scope='9 direct calls historically reviewed; four indirect calls remain strict-proof blockers. Static ABI contracts separate. No runtime/selection proof.'))
assert not skipped,skipped[:3]
assert not unresolved,unresolved
assert all(Path(p).is_file() and sha(p)==h for p,h in inputs.items())
shutil.copyfile(candidate,V/'ContentProvider.obj'); archive=V/'linked.lib'
code,log=rebuild.run(tc,'lib',['/nologo','/OUT:'+str(archive),str(base),'ContentProvider.obj'],V); (F/'librarian.log').write_text(log,encoding='utf-8'); assert code==0,log
inv=lambda ms: collections.Counter((n,bh(raw)) for n,raw in ms)
before=inv(members); after=inv(libs.archive_members(archive)); assert list((before-after).elements())==[('ContentProvider.obj',bh(old))]; assert list((after-before).elements())==[('ContentProvider.obj',bh(new))]
changed=[p for p,h in inputs.items() if not Path(p).is_file() or sha(p)!=h]; assert not changed,changed
save('replacement.json',dict(baseline=str(base),baseline_sha256=sha(base),replacement=str(archive),replacement_sha256=sha(archive),changed_member='ContentProvider.obj',unchanged_other_members=len(members)-1,normal_librarian=True,source_compiles=0,missing_inputs=missing,unresolved_removed_symbol_consumers=unresolved,scope='Guarded inactive archive derived from actual final migrated baseline. ScriptContext/Part/NewNull and all other member bytes preserved. Parent owns isolated link. Implicit libraries, EH/indirect ABI/runtime/gates/selection remain separate.'))
print(json.dumps(dict(members=len(members),scanned=len(inventory),unparsed=len(skipped),consumers=len(consumers),missing=missing,replacement=str(archive),sha256=sha(archive))))

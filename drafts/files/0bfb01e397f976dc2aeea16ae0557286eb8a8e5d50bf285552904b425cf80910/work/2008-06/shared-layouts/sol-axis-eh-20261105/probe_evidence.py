from pathlib import Path
import hashlib,json,struct,sys,pefile
ROOT=Path.cwd();sys.path.insert(0,str(ROOT))
from roc import match
OUT=ROOT/'work/2008-06/shared-layouts/sol-axis-eh-20261105'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
original=ROOT/'clients/2008-06/Roblox.exe';pe=pefile.PE(str(original));base,image=match._image('2008-06')
axis=ROOT/'work/2008-06/native-check-runs/20261105-131546-668ff08d/unit-000/candidate.obj'
mouse=ROOT/'work/2008-06/p6-probe-runs/20261105-130705-87b5983d/output/NativeMouseCommandFull.obj'
ir=next(p for p in (ROOT/'work/2008-06/shared-layouts/sol-irenderable-20261105/run').rglob('candidate.obj') if sha(p)=='42444b399d06567d75cbed1cbde50660d8d672753602d84959cc7b3e1957dbe7')
# Explicit conditional external anchor independently established from original 617dd0 jmp 615780.
# Preserve global auditor and its failure receipt. Execute task-local derivative with one supplied binding.
s= (ROOT/'rebuild/2008-06/tests/audit_native_eh_graph.py').read_text()
s=s.replace('ROOT=Path(__file__).resolve().parents[3]','ROOT=Path.cwd()')
s=s.replace("try:walk(handler,bindings[handler])", "bind('??1MouseCommand@RBX@@UAE@XZ',0x615780)\ntry:walk(handler,bindings[handler])")
# Reject weak fallback traversal in this derivative instead of treating LIBRARY as alias.
s=s.replace("alias=weak[symbol];assert alias['search_characteristic']==2,alias", "raise AssertionError(('unknown selected weak fallback',symbol,weak[symbol]))\n  alias=weak[symbol]")
(OUT/'conditional_auditor.py').write_text(s)
sys.argv=['conditional_auditor.py',str(axis),'00640560','??0AxisMoveTool@RBX@@QAE@PAVWorkspace@1@@Z','--output',str(OUT/'graph.json')]
try:exec(compile(s,str(OUT/'conditional_auditor.py'),'exec'),{'__file__':str(OUT/'conditional_auditor.py'),'__name__':'__main__'})
except AssertionError:pass
nodes=[]
for p,n,va in [(mouse,'??1MouseCommand@RBX@@UAE@XZ',0x615780),(ir,'??1IRenderable@RBX@@QAE@XZ',0x47d410)]:
 raw=p.read_bytes();secs,syms,defs,starts=match._coff_data_index(raw);f={n:(b,r) for n,b,r in match.coff_functions(raw)};b,r=f[n];v,sec=defs[n];sc=secs[sec];orig=bytes(image[va-base:va-base+len(b)]);edges=[]
 for i in range(sc[7]):
  off,idx,k=struct.unpack_from('<IIH',raw,sc[5]+i*10)
  if v<=off<v+len(b):
   d=off-v;target=struct.unpack_from('<I',orig,d)[0]
   if k==20:target=(va+d+4+struct.unpack_from('<i',orig,d)[0])&0xffffffff
   edges.append(dict(offset=d,symbol=syms[idx][0],kind=k,addend=struct.unpack_from('<i',b,d)[0],original_anchor=hex(target)))
 nodes.append(dict(path=str(p.relative_to(ROOT)),sha256=sha(p),symbol=n,address=hex(va),body_hex=b.hex(),original_hex=orig.hex(),normalized_exact=match.exact_match(orig,[],b,r),edges=edges))
imports=[]
for desc in pe.DIRECTORY_ENTRY_IMPORT:
 for imp in desc.imports:
  if imp.address in (0x802458,) or (imp.name and b'??1?$basic_string@D' in imp.name):
   imports.append(dict(descriptor_rva=hex(desc.struct.get_file_offset()),original_first_thunk=hex(desc.struct.FirstThunk),original_name_rva=hex(desc.struct.Name),dll=desc.dll.decode(),iat=hex(imp.address),hint_name_rva=hex(imp.hint_name_table_rva),name=imp.name.decode(),coff_binding='__imp_'+imp.name.decode()))
headers=[]
for name in ('xstring','yvals.h'):
 p=ROOT/'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/include'/name
 lines=p.read_text().splitlines();hits=[i for i,l in enumerate(lines) if ('basic_string(const _Elem *_Ptr)' in l or '~basic_string()' in l or '#define __CLR_OR_THIS_CALL' in l)]
 headers.append(dict(path=str(p.relative_to(ROOT)),sha256=sha(p),excerpts=[dict(line=i+1,text='\n'.join(lines[max(0,i-1):i+7])) for i in hits]))
receipt=dict(scope='Conditional actual-provider EH continuation and authentic import identity; no selected PE or loaded runtime claim',original_sha256=sha(original),axis_sha256=sha(axis),preserved_generic_failure_sha256=sha(ROOT/'work/2008-06/shared-layouts/sol-axis-ctor-20261105/eh.json'),supplied_external_bindings=[dict(symbol='??1MouseCommand@RBX@@UAE@XZ',address='0x615780',evidence='original NamedArrowBase tailjmp at 617dd0; actual provider below')],continuation_nodes=nodes,original_imports_before_coff_binding=imports,installed_headers=headers,unknown_nodes=['Selected PE provider and weak LIBRARY fallback selection','Loaded SxS MSVCP90/MSVCR90 identity and implementation','Imported constructor/destructor runtime behavior','Full transitive ABI/EH outside bounded graph'],strict_indirect_failure='Axis constructor call offset 78 remains strict proof failure; sidecar does not change it',next_gate='Parent-selected PE evidence for actual provider and import/weak resolution; then loaded SxS runtime evidence. No link/run authorized.')
(OUT/'continuation.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(dict(nodes=nodes,imports=imports),indent=2))

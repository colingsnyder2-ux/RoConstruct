from pathlib import Path
import sys,json,hashlib,struct
R=Path.cwd(); sys.path[:0]=[str(R),str(R/'rebuild/2008-06/tests')]
from roc import libs,match,rebuild
from relink_native_document import prepare
F=R/'work/2008-06/shared-layouts/sol-aggregate-content-20261105'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
m=json.loads((F/'input-manifest.json').read_text()); audit=json.loads((F/'consumer-audit.json').read_text()); names=set(audit['providers']); old={str(Path(x['input'].split('::')[0]).resolve()).lower() for x in audit['inventory'] if not x['input'].startswith('task-remainder')}; rows=[]
for run in ['20261105-131239-7df4c488','20261105-131253-90ee3d03']:
 folder=R/'work/2008-06/native-doc-relinks'/run; cmd=json.loads((folder/'command.json').read_text()); saved=json.loads((folder/'inputs.json').read_text()); args,paths=prepare(cmd['arguments'],Path(cmd['cwd']),F,rebuild.toolchain(21022)); delta=[]
 for p in sorted(paths):
  assert sha(p)==next(h for n,h in saved.items() if Path(n).resolve()==p.resolve())
  if str(p.resolve()).lower() in old or str(p) in m['inputs']: continue
  assert p.suffix.lower()=='.obj',str(p)
  raw=p.read_bytes(); secs,syms,defs,_=match._coff_data_index(raw); hits=set()
  for sec in secs:
   for i in range(sec[7]):
    off,idx,kind=struct.unpack_from('<IIH',raw,sec[5]+10*i)
    if idx in syms and syms[idx][0] in names and syms[idx][0] not in defs: hits.add(syms[idx][0])
  delta.append(dict(path=str(p),sha256=sha(p),removed_symbol_external_references=sorted(hits)))
 base=Path(json.loads((F/'replacement.json').read_text())['baseline']); assert base in paths; assert sha(base)==m['inputs'][str(base)]
 rows.append(dict(run=run,command_sha256=sha(folder/'command.json'),manifest_sha256=sha(folder/'inputs.json'),explicit_count=len(paths),additional_objects=delta,removed_previous_inputs=sorted(old-{str(p.resolve()).lower() for p in paths}),same_migrated_archive_sha256=sha(base),same_member_set=True,all_manifest_hashes_verified=True,scope='Explicit input delta only; implicit default libraries unproven'))
(F/'latest-command-delta.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8'); print(json.dumps(rows,indent=2))
# Lossless compact encoding: replace repeated archive paths by source-table indices.
sources=[]
def label(s):
 path,sep,member=s.partition('::')
 if path not in sources: sources.append(path)
 return [sources.index(path),member] if sep else [sources.index(path)]
ids={row['input']:i for i,row in enumerate(audit['inventory'])}
for x in audit['short_imports']:
 x['inventory_index']=ids[x.pop('input')]; x.pop('sha256')
for x in audit['inventory']: x['input']=label(x['input'])
for x in audit['consumers']:
 x['input']=label(x['input'])
 for b in x['bindings']: b['available_surviving_definitions']=[label(z) for z in b['available_surviving_definitions']]
audit['providers']={n:[label(z) for z in v] for n,v in audit['providers'].items()}; audit['default_library_directive_inputs']=[label(z) for z in audit['default_library_directive_inputs']]; audit['source_table']=sources; audit['encoding']='input=[source_table index, optional archive member]; short imports refer to inventory index, retaining inventory SHA256'
(F/'consumer-audit.json').write_text(json.dumps(audit,separators=(',',':'))+'\n',encoding='utf-8'); print('compact bytes', (F/'consumer-audit.json').stat().st_size)


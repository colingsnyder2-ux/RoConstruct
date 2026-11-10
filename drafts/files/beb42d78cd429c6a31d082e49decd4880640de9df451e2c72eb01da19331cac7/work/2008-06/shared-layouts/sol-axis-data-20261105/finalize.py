import json,hashlib,sys,struct
from pathlib import Path
sys.path.insert(0,str(Path.cwd()))
from roc import match
out=Path('work/2008-06/shared-layouts/sol-axis-data-20261105');p=json.loads((out/'bindings.json').read_text());o=json.loads((out/'original.json').read_text());base,img=match._image('2008-06');h=lambda b:hashlib.sha256(b).hexdigest()
for t in o['tables']:
 for s in t['slots']:
  if t['subobject_offset']==4 and t['constructor']=='0x640560' and s['index'] in (2,3):s['this_adjustment']='Entry receives full object +4; no adjustor thunk. Original render2d 00640f56 / render3dAdorn 00641069 executes lea ecx,[esi-4] before bounds call 00640b40.'
p['string_evidence']={'original_address':'0x961b48','original_hex':bytes(img[0x961b48-base:0x961b48-base+9]).hex(),'original_path':['00640792 jmp 005c5fa0','005c6230 jmp 005c5fa0','005c5fca push 00961b48','005c5fd7 call 00553f90'],'identity':'sAxisMoveTool declaration and current definition AxisMove confirmed as string content binding; name initialization/EH/direct-call ABI separately open','providers':[]}
inputs=json.loads(Path('work/2008-06/native-doc-relinks/20261105-141437-a0617a57/inputs.json').read_text())
for fn,digest in inputs.items():
 ar=Path(fn).read_bytes();members=[]
 if ar[:8]==b'!<arch>\n':
  off=8
  while off+60<len(ar):
   sz=int(ar[off+48:off+58]);members.append((ar[off:off+16].decode().strip(),ar[off+60:off+60+sz]));off+=60+sz+(sz&1)
 elif Path(fn).suffix=='.obj':members=[('',ar)]
 for member,raw in members:
  if raw[:2]!=b'\x4c\x01':continue
  secs,syms,defs,starts=match._coff_data_index(raw);sym='?sAxisMoveTool@RBX@@3PADA'
  if sym in defs:
   v,s=defs[sym];sec=secs[s];bb=raw[sec[4]+v:sec[4]+v+9]
   p['string_evidence']['providers'].append({'symbol':sym,'input':fn,'input_sha256':h(ar),'member':member,'member_sha256':h(raw),'bytes_hex':bb.hex(),'equals_original':bb.hex()==p['string_evidence']['original_hex']})
# Freeze exact instruction-to-relocation obligations in a readable text table.
lines=['Original vptrs first; current COFF pairings are obligations, not selected ownership.','table | subobject | slot | byte offset | original target | prototype | COFF name | normalized matching providers / definitions']
for t in o['tables']:
 for s in t['slots']:
  ps=s.get('providers',[]);lines.append(f"{t['address']} | +{t['subobject_offset']} | {s['index']} | {s['offset']} | {s['target']} | {s.get('prototype')} | {s.get('coff',{}).get('name')} | {sum(x['normalized_code_equal'] for x in ps)}/{len(ps)}")
(out/'slots.txt').write_text('\n'.join(lines))
(out/'bindings.json').write_text(json.dumps(p,indent=2));(out/'original.json').write_text(json.dumps(o,indent=2))
summary={'status':'parked','compile_count':0,'source_shared_archive_edits':0,'input_count':p['input_count'],'input_drift':p['input_drift'],'weak_rule':'All observed E->G entries have search=2 LIBRARY; no unconditional ALIAS claim. Current _E definitions and selected fallback must be checked in successful link/map.','unresolved_render_slots':[{'table':'0084a594','index':2,'offset':8,'target':'00640f30','symbol':'?render2d@AxisMoveTool@RBX@@EAEXPAVAdorn@2@@Z'},{'table':'0084a594','index':3,'offset':12,'target':'00641040','symbol':'?render3dAdorn@AxisMoveTool@RBX@@EAEXPAVAdorn@2@@Z'}],'missing_inputs':['successful selected PE/map (current failed diagnostic supplies none)','reviewed render provider bodies','transitive ABI/EH and indirect dispatch/runtime proof; generic EH failure retained'],'next_bounded_action':'Parent recover the two named render providers using original secondary-this basis; serialize link only after provider readiness, then prove actual _E/_G resolution and selected vtable/RTTI/string pointers. No new hypothesis or compile authorized here.','original_sha256':o['exe_sha256'],'saved_object_sha256':p['object_sha256'],'archive_sha256':h(Path('work/2008-06/shared-layouts/sol-irenderable-20261105/linked.lib').read_bytes()),'preserved_generic_eh':p['preserved_generic_eh'],'task_hashes':{str(f.name):h(f.read_bytes()) for f in out.iterdir() if f.is_file()}}
(out/'handoff.json').write_text(json.dumps(summary,indent=2));print(json.dumps(summary,indent=2));print(p['string_evidence'])

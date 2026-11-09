"""Rank unresolved diagnostic symbols and audit rebuild coverage; read-only."""
import argparse, ast, collections, hashlib, json, re
from pathlib import Path
root=Path(__file__).resolve().parents[3]
parser=argparse.ArgumentParser();parser.add_argument('--json',action='store_true');parser.add_argument('--output',type=Path);args=parser.parse_args()
receipt_path=root/'work/2008-06/shared-layouts/document-swap-provider-trial.json'
raw=receipt_path.read_bytes();receipt=json.loads(raw)
pattern=re.compile(r'^(.*?)\s*:\s*error\s+(LNK\d+):\s+unresolved external symbol\s+"(.*?)"\s+\((.*?)\)')
groups=collections.defaultdict(lambda:{'symbols':{},'lines':0})
for line in receipt['errors']:
 m=pattern.search(line)
 if not m:
  groups['other linker errors']['lines']+=1;continue
 obj,code,display,symbol=m.groups()
 if 'TToolVerb<' in display: family='TToolVerb::'+('isChecked' if 'isChecked' in display else 'newMouseCommand' if 'newMouseCommand' in display else 'other')
 elif 'FilteredSelection<' in display and 'ServiceProvider::find' in display: family='ServiceProvider::find<FilteredSelection>'
 else:
  target=re.search(r'([\w:~]+)::(?:[~\w]+)\(',display)
  family=target.group(1) if target else display.split('(')[0][-80:]
 group=groups[family];group['lines']+=1
 entry=group['symbols'].setdefault(symbol,{'name':display,'objects':set()});entry['objects'].add(obj)
ranked=[]
for family,g in groups.items():
 ranked.append({'family':family,'unique_symbols':len(g['symbols']),'error_lines':g['lines'],'objects':sorted({o for v in g['symbols'].values() for o in v['objects']}),'symbols':[{'name':v['name'],'symbol':k,'objects':sorted(v['objects'])} for k,v in sorted(g['symbols'].items())]})
ranked.sort(key=lambda x:(-x['unique_symbols'],-x['error_lines'],x['family']))
verifier=(root/'rebuild/2008-06/tests/verify_document_swap.py').read_text();checks=next(ast.literal_eval(node.value) for node in ast.parse(verifier).body if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='steps' for t in node.targets))
tests=root/'rebuild/2008-06/tests';coverage={}
for name in checks:
 path=tests/name
 if path.exists():
  text=path.read_text(encoding='utf-8');coverage[name]=set(re.findall(r'[\w.-]+\.obj',text,re.I))
candidate_recorders=collections.defaultdict(list)
for path in tests.glob('record_*.py'):
 if path.name=='record_native_document_link_trial.py':continue
 for objname in set(re.findall(r'[\w.-]+\.obj',path.read_text(encoding='utf-8',errors='replace'),re.I)):
  candidate_recorders[objname].append(path.name)
objects=[x.replace('\\','/').split('/')[-1] for x in receipt['objects']]
covered={name for names in coverage.values() for name in names}
object_freshness=[]
for path,expected in receipt['objects'].items():
 file=root/Path(path.replace('\\','/'))
 if not file.is_file(): status='missing'
 else: status='same' if hashlib.sha256(file.read_bytes()).hexdigest()==expected else 'changed'
 if status!='same':object_freshness.append({'path':path,'status':status})
result={'receipt_revision':receipt.get('revision'),'receipt_sha256':hashlib.sha256(raw).hexdigest(),'link_exit':receipt['link_exit'],'error_lines':len(receipt['errors']),'ranked':ranked,'object_freshness':object_freshness,'rebuild_audit':{'objects':len(objects),'checks':len(checks),'explicitly_named_in_checks':sum(o in covered for o in objects),'not_explicitly_named':[o for o in objects if o not in covered],'recorder_candidates':{o:sorted(candidate_recorders.get(o,[])) for o in objects},'objects_with_recorder_candidates':sum(bool(candidate_recorders.get(o)) for o in objects),'scope':'Text-only lower-bound audit: indirect outputs and generated objects may be missed. Mentions may be inputs, not outputs. It does not prove freshness or a full rebuild.'}}
if args.output:args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
if args.json:print(json.dumps(result,indent=2))
else:
 print(f"Receipt {result['receipt_revision']} | link exit {result['link_exit']} | {result['error_lines']} error lines")
 for g in ranked[:12]:print(f"{g['unique_symbols']:3} symbols / {g['error_lines']:3} lines  {g['family']}")
 print(f"Receipt input hashes: {len(object_freshness)} changed or missing since diagnostic; hashes do not establish source freshness")
 a=result['rebuild_audit'];print(f"Rebuild audit: {a['explicitly_named_in_checks']}/{a['objects']} objects explicitly named by {a['checks']} checks (lower bound; not freshness proof)")

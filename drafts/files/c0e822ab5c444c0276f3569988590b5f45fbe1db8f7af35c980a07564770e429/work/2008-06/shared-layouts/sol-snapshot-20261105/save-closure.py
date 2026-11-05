import json,hashlib
from pathlib import Path
P=Path('work/2008-06/shared-layouts/sol-snapshot-20261105')
base=Path('work/2008-06/native-doc-relinks/20261105-131239-7df4c488')
variant=Path('work/2008-06/native-doc-relinks/20261105-131253-90ee3d03')
results={}
for label,run in [('baseline',base),('factory',variant)]:
 for name in ['result.json','command.json','inputs.json']:(P/(label+'-'+name)).write_bytes((run/name).read_bytes())
 results[label]=json.loads((run/'result.json').read_text())
a={x['symbol'] for x in results['baseline']['blockers']};b={x['symbol'] for x in results['factory']['blockers']}
summary={'baseline_run':str(base),'factory_run':str(variant),'metrics':{k:{'unresolved':len(v['blockers']),'duplicates':len(v['duplicates']),'input_drift':v['changed_inputs']} for k,v in results.items()},'factory_delta':{'resolved':sorted(a-b),'new_required':sorted(b-a)},'factory_object_recompiled':False,'fully_gated_swaps':0,'server_credit':0,'diagnostic_executed':False,'blockers':results['factory']['blockers'],'duplicates':results['factory']['duplicates'],'next':['aggregate content member-only replacement proof on actual migrated final library','authentic AxisMoveTool ctor provider without duplicate factory/Core','authentic Workspace factory/writer,Physics service callback,setActiveDocument providers','resolve duplicate owners using source evidence']}
(P/'closure-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary['metrics']))

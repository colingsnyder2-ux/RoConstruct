import json,subprocess,re
from pathlib import Path
f=[json.loads(s) for s in open('work/2008-06/functions.jsonl')];x=[e['addr'] for e in f if ('PartInstance' in e.get('unit','') and 0x590000<=int(e['addr'],16)<0x5b0000)];x+=['0059d4d0','0059b970'];r=subprocess.run(['roc.cmd','native-asm','2008-06',*x],capture_output=True,text=True);assert r.returncode==0,r.stderr
label='';hits=[]
for line in r.stdout.splitlines():
 if line.startswith('== '):label=line
 if re.search(r'\+ 0x3(?:c8|cc|d0|d4|d8|dc|e0|e4)\]',line):hits.append((label,line))
print('\n'.join(str(h) for h in hits));Path('work/2008-06/shared-layouts/part-tail-scan-worker.json').write_text(json.dumps({'scope':'Native-asm scan of 142 functions with heuristic PartInstance unit labels plus lifetime functions; this is not exhaustive and adjusted this pointers can conceal direct offsets.','functions':x,'hits':hits},indent=2)+'\n')

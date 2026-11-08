import sys, json
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/body-order-worker';work.mkdir(exist_ok=True)
s=(root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp').read_text();old='static int getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }'
variants=['static int getNextStateIndex() { static int p; p++; if (p == 0x7fffffff) p = 1; return p; }','static int getNextStateIndex() { static int p; int n = p + 1; p = n; if (n == 0x7fffffff) p = 1; return p; }','static int getNextStateIndex() { static int p; return (++p == 0x7fffffff) ? (p = 1) : p; }','static int getNextStateIndex() { static int p; if (p == 0x7ffffffe) p = 1; else ++p; return p; }','static int getNextStateIndex() { static int p; p = p + 1; if (p >= 0x7fffffff) p = 1; return p; }']
target,refs,_=match.target('2008-06','006149c0'); rows=[]
for i,v in enumerate(variants):
 src=work/('order%d.cpp'%i);obj=work/('order%d.obj'%i);src.write_text(s.replace(old,v));flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work)
 if c: rows.append({'variant':i,'compile':c,'error':log[-500:]});continue
 name,body,rel=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Body@RBX@@'));exact=match.exact_match(target,refs,body,rel);rows.append({'variant':i,'size':len(body),'exact':exact,'function':v});print(rows[-1],flush=True)
 if exact: break
(work/'results.json').write_text(json.dumps(rows,indent=2))

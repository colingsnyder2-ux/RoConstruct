import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
work=root/'rebuild/2008-06/out/native-layouts/body-mass-state-worker';work.mkdir(exist_ok=True);s=(root/'rebuild/2008-06/out/native-layouts/part-layout-worker/PartContentBodyWorker.cpp').read_text();old='static int getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }'
funcs=['static int getNextStateIndex() { static unsigned p; if (++p == 0x7fffffff) p = 1; return p; }','static int getNextStateIndex() { static long p; if (++p == 0x7fffffff) p = 1; return p; }','static int getNextStateIndex() { static int p=0; if (++p == 0x7fffffff) p = 1; return p; }','static int getNextStateIndex() { static int p; ++p; if (p != 0x7fffffff) return p; p=1; return p; }','static int getNextStateIndex() { static int p; ++p; if (p == 0x7fffffff) { p=1; } return p; }','static __forceinline int getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }','static inline int getNextStateIndex() { static int p; if (++p == 0x7fffffff) p = 1; return p; }']
variants=[('counter%d'%i,s.replace(old,f)) for i,f in enumerate(funcs)]
for i,m in enumerate(['mass(0)','mass(0.0)','mass(float())','mass(+0.0f)','mass(static_cast<float>(0))']):variants.append(('mass%d'%i,s.replace('mass(0.0f)',m)))
target,refs,_=match.target('2008-06','006149c0');rows=[]
for name,v in variants:
 src=work/(name+'.cpp');obj=work/(name+'.obj');src.write_text(v);flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(src)];c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,work)
 if c:print(name,'compile fail',log[-200:],flush=True);continue
 sym,b,r=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('??0Body@RBX@@'));exact=match.exact_match(target,refs,b,r);rows.append({'variant':name,'size':len(b),'exact':exact});print(rows[-1],flush=True)
 if exact:break
(work/'results.json').write_text(json.dumps(rows,indent=2))

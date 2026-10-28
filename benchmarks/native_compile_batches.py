"""Offline compiler benchmark: replay worker method edits, never call a model or submit.

python benchmarks/native_compile_batches.py --workers 20 --tasks 20
Optional --replies points to recorded task directories containing result.json.
Requires the installed VS2008 RTM compiler (or ROC_CL).
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import sys
import threading
import time

sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from roc import match,native_batch,native_sweep,rebuild,setup


def run(args):
    if not 1 <= args.tasks <= 32 or not 1 <= args.workers <= 64:
        raise SystemExit('Use 1-32 methods and 1-64 workers.')
    if 21022 not in setup.compilers():
        raise SystemExit('Historical compiler 21022 required; run roc install or set ROC_CL.')
    output=Path(args.output).resolve();output.mkdir(parents=True,exist_ok=True)
    source='#include <vector>\n#include <map>\n#include <algorithm>\nnamespace RBX {\n'
    for i in range(args.tasks):
        source+=('class Bench%d { public: int value(); int keep(); };\n'
                 'int Bench%d::value(){return %d;}\nint Bench%d::keep(){return %d;}\n')%(i,i,1000+i,i,3000+i)
    source+='}\n'
    corrected=source
    for i in range(args.tasks):corrected=corrected.replace('return %d;'%(1000+i),'return %d;'%(2000+i))
    compilers=native_sweep.resolve_compile_workers(args.compilers,args.workers)
    slots=threading.Semaphore(compilers)
    count=[0];count_lock=threading.Lock()
    def compile(text,label):
        with slots:
            with count_lock:count[0]+=1;number=count[0]
            folder=output/('compile-%03d-%s'%(number,label[:25]));folder.mkdir()
            unit=folder/'BatchFixture.cpp';unit.write_text(text,encoding='utf-8')
            started=time.monotonic()
            result=rebuild.compile_direct('2008-06',[unit],folder,[],'WIN32 NDEBUG',flags='/O2 /Ob0 /GS- /EHsc /MD',cl=21022)
            ok,error=result[str(unit)]
            if not ok:raise RuntimeError(error)
            return dict(ok=True,object=str(unit.with_suffix('.obj')),seconds=time.monotonic()-started,
                        source_sha256=hashlib.sha256(text.encode()).hexdigest())
    reference=compile(corrected,'reference')
    expected={symbol:(body,relocs) for symbol,body,relocs in match.coff_functions(Path(reference['object']).read_bytes())}
    class Matcher:
        def scan(self,data):
            result=[]
            for symbol,body,relocs in match.coff_functions(data):
                if symbol not in expected or match.masked(body,relocs)!=match.masked(*expected[symbol]):continue
                if symbol.startswith('?value@Bench'):
                    n=int(symbol.split('@Bench',1)[1].split('@',1)[0]);addr='target-%d'%n
                elif symbol.startswith('?keep@Bench'):
                    n=int(symbol.split('@Bench',1)[1].split('@',1)[0]);addr='keep-%d'%n
                else:continue
                assert not match.coff_data_refs(data,symbol)  # integer-only fixture
                result.append(dict(addr=addr,symbol=symbol))
            return result
    matcher=Matcher();base=compile(source,'baseline')
    baseline={h['addr'] for h in matcher.scan(Path(base['object']).read_bytes())}
    assert len(baseline)==args.tasks
    def worker(i):
        reply='```cpp\nint Bench%d::value(){return %d;}\n```'%(i,2000+i)
        if args.replies:
            row=json.loads((Path(args.replies)/str(i)/'result.json').read_text())
            reply=next(t['reply'] for t in reversed(row['trials']) if t.get('reply'))
        method='Bench%d::value'%i
        return native_batch.method_candidate(source,method,native_sweep.method_edits(source,reply,method),['target-%d'%i])
    with ThreadPoolExecutor(args.workers) as pool:candidates=list(pool.map(worker,range(args.tasks)))
    report=dict(offline=True,model_requests=0,submitted=False,fixture=True,tasks=args.tasks,workers=args.workers,
                compilers=compilers,compiler=21022,runs=[])
    for size in (1,min(4,args.tasks),args.tasks):
        if any(r['batch_size']==size for r in report['runs']):continue
        before=count[0];started=time.monotonic();text=source;keep=set(baseline);proof=None
        if size==1:
            def independent(candidate):
                return native_batch.prove('App/util/BatchFixture.cpp',source,[candidate],baseline,compile,matcher,lambda _:None)[0]
            with ThreadPoolExecutor(args.workers) as pool:
                proved=list(pool.map(independent,candidates))
            assert all(proved)
            # Independent objects cannot certify their union. The final combined
            # source gets its own compile, just as a real native batch requires.
            for proposal in proved:text=native_sweep.apply_edits(text,proposal['edits'])
            proof=compile(text,'independent-merged')
        else:
            for offset in range(0,len(candidates),size):
                group=candidates[offset:offset+size]
                proposal,trials=native_batch.prove('App/util/BatchFixture.cpp',text,group,keep,compile,matcher,lambda _:None)
                assert proposal
                text=native_sweep.apply_edits(text,proposal['edits']);proof=proposal['proof']
                keep.update(h['addr'] for h in proposal['witnesses'])
        found={h['addr'] for h in matcher.scan(Path(proof['object']).read_bytes())}
        assert baseline <= found and len(found-baseline)==args.tasks
        assert proof['source_sha256']==hashlib.sha256(text.encode()).hexdigest()
        row=dict(batch_size=size,compiler_invocations=count[0]-before,wall_seconds=time.monotonic()-started,
                 exact_targets=len(found-baseline),lost=len(baseline-found))
        report['runs'].append(row);(output/'summary.json').write_text(json.dumps(report,indent=2))
        print(json.dumps(row),flush=True)
    return report


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--workers',type=int,default=20)
    parser.add_argument('--tasks',type=int,default=20)
    parser.add_argument('--compilers',type=lambda v:v if v=='auto' else int(v),default='auto')
    parser.add_argument('--replies')
    parser.add_argument('--output',default='work/integrator-bench/offline-batches')
    run(parser.parse_args())

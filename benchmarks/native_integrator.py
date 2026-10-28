"""Opt-in, no-submit NVIDIA/other-provider throughput benchmark with genuine MSVC COFF proofs.

python benchmarks/native_integrator.py --live --workers 1,4,8,20 --tasks 20 --modes edits,method
Fixture addresses are synthetic; results never become client coverage or native credits.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import json
from pathlib import Path
import statistics
import sys
import threading
import time

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import match, native_sweep, providers, rebuild, setup


def run(args):
    if not args.live:
        raise SystemExit('Pass --live to authorize real cloud requests; nothing is submitted.')
    workers = [int(n) for n in args.workers.split(',')]
    modes = args.modes.split(',')
    if not workers or min(workers) < 1 or max(workers) > 64 or not 1 <= args.tasks <= 128:
        raise SystemExit('Use 1-64 workers and 1-128 fixture tasks.')
    if set(modes) - {'edits', 'method', 'auto'}:
        raise SystemExit('Modes: edits, method, auto')
    if 21022 not in setup.compilers():
        raise SystemExit('VS2008 RTM compiler required; install it or set ROC_CL.')
    output = Path(args.output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    fixtures = []
    flags = '/O2 /Ob0 /GS- /EHsc /MD'
    for i in range(args.tasks):
        source = ('namespace RBX {\nclass Bench%d { public: int value(); int keep(); };\n'
                  'int Bench%d::value() { return %d; }\nint Bench%d::keep() { return %d; }\n}\n') % (i,i,1000+i,i,3000+i)
        reference = match.compile_text('2008-06',source.replace('return %d;'%(1000+i),'return %d;'%(2000+i)),flags=flags,build=21022)
        functions = {symbol:(body,relocs) for symbol,body,relocs in match.coff_functions(reference)}
        fixtures.append((source,functions))
    budget = providers.CloudBudget(requests=len(workers)*len(modes)*args.tasks*args.rounds)
    trace = threading.local()
    generate = providers.generate
    def measured(model,messages,options):
        trace.input_chars += sum(len(m['content']) for m in messages)
        trace.requests += 1
        result = generate(model,messages,options)
        trace.reply_chars += len(result.text)
        return result
    providers.generate = measured
    report = {'fixture':True,'submitted':False,'model':args.model,'tasks':args.tasks,
              'compiler':21022,'flags':flags,'runs':[]}
    try:
        for mode in modes:
            for count in workers:
                inflight=providers.cloud_slots(args.model,count,args.inflight)
                gate,compilers = providers.CloudGate(inflight),threading.Semaphore(args.compilers)
                started = time.monotonic()
                def one(i):
                    trace.input_chars=trace.reply_chars=trace.requests=0
                    source,expected=fixtures[i]
                    folder=output/(mode+'-'+str(count))/str(i)
                    folder.mkdir(parents=True,exist_ok=True)
                    def compile_round(text,label):
                        queued=time.monotonic()
                        with compilers:
                            waited=time.monotonic()-queued;t=time.monotonic()
                            data=match.compile_text('2008-06',text,flags=flags,build=21022)
                            path=folder/(label+'.obj');path.write_bytes(data)
                            symbols=rebuild.coff_externals(data)
                            return {'ok':True,'object':str(path),'seconds':time.monotonic()-t,'queue_seconds':waited,
                                    'defined_symbols':[s for s,d in symbols.items() if d],
                                    'undefined_symbols':[s for s,d in symbols.items() if not d]}
                    class Matcher:
                        def scan(self,data):
                            return [{'addr':'00000001' if symbol.startswith('?value@') else '00000002','symbol':symbol}
                                    for symbol,body,relocs in match.coff_functions(data)
                                    if symbol in expected and match.masked(body,relocs)==match.masked(*expected[symbol])]
                    t=time.monotonic()
                    result={'task':i,'ok':False}
                    try:
                        baseline=compile_round(source,'baseline')
                        matcher=Matcher()
                        owned={h['addr'] for h in matcher.scan(Path(baseline['object']).read_bytes())}
                        assert owned=={'00000002'}
                        proposal,trials=native_sweep.model_proposal('App/util/Bench%d.cpp'%i,source,['00000001'],owned,owned,
                            args.model,args.rounds,compile_round,matcher,
                            lambda addr:{'addr':addr,'rebuilt_symbol':'?value@Bench%d@RBX@@QAEHXZ'%i,
                                         'mined_source':'int Bench%d::value() { return %d; }'%(i,2000+i)},
                            lambda _:None,{'generation':mode,'gate':gate,'budget':budget,'allow_cloud':True,
                                           'timeout':args.timeout,'retries':0,'thinking':'disabled','max_tokens':1024,
                                           'reasoning_effort':args.reasoning_effort})
                        result.update(ok=bool(proposal),trials=trials)
                    except Exception as error:
                        result.update(error=str(error),category=getattr(error,'category',''))
                    result.update(seconds=time.monotonic()-t,input_chars=trace.input_chars,reply_chars=trace.reply_chars,
                                  requests=trace.requests)
                    (folder/'result.json').write_text(json.dumps(result,indent=2))
                    return result
                rows=[]
                with ThreadPoolExecutor(max_workers=count) as pool:
                    for future in as_completed([pool.submit(one,i) for i in range(args.tasks)]):
                        rows.append(future.result())
                wall=time.monotonic()-started
                row={'mode':mode,'workers':count,'inflight':inflight,'wall_seconds':wall,'proofs':sum(r['ok'] for r in rows),
                     'proofs_per_minute':sum(r['ok'] for r in rows)*60/wall,
                     'median_job_seconds':statistics.median(r['seconds'] for r in rows),
                     'input_chars':sum(r['input_chars'] for r in rows),'reply_chars':sum(r['reply_chars'] for r in rows),
                     'requests':sum(r['requests'] for r in rows),'errors':[r for r in rows if not r['ok']]}
                report['runs'].append(row)
                (output/'summary.json').write_text(json.dumps(report,indent=2))
                print(json.dumps({k:v for k,v in row.items() if k!='errors'}),flush=True)
    finally:
        providers.generate=generate
    return report


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--live',action='store_true')
    parser.add_argument('--model',default='opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none')
    parser.add_argument('--workers',default='1,4,8,20')
    parser.add_argument('--tasks',type=int,default=20)
    parser.add_argument('--compilers',type=int,default=4)
    parser.add_argument('--inflight',type=lambda v:v if v=='auto' else int(v),default='auto')
    parser.add_argument('--rounds',type=int,default=1)
    parser.add_argument('--reasoning-effort',choices=['low','medium','high'],default='low')
    parser.add_argument('--timeout',type=int,default=30)
    parser.add_argument('--modes',default='edits,method')
    parser.add_argument('--output',default='work/integrator-bench/live')
    run(parser.parse_args())

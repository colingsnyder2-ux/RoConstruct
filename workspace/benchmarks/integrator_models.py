"""Opt-in paid/plan smoke: bounded model workers, real MSVC, synthetic targets; no uploads."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import sys
import threading
import time

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from roc import match, native_batch, native_sweep, providers, rebuild


def run(model, workers, output):
    if not 1 <= workers <= 32:
        raise ValueError('Workers must be 1-32')
    output.mkdir(parents=True, exist_ok=True)
    expressions = ['x + %d' % (17 + n * 7) for n in range(workers)]
    declarations = 'struct BatchFixture {\n' + ''.join(
        '__declspec(noinline) int f%d(int x);\n' % n for n in range(workers)) + '};\n'
    original = declarations + ''.join('int BatchFixture::f%d(int x) { return x; }\n' % n for n in range(workers))
    target = declarations + ''.join('int BatchFixture::f%d(int x) { return %s; }\n' % (n, e) for n, e in enumerate(expressions))
    compiles = []

    def compile_source(source, label):
        folder = output / label
        folder.mkdir(exist_ok=True)
        path = folder / 'fixture.cpp'
        path.write_text(source, encoding='utf-8')
        result = rebuild.compile_direct('2008-06', [path], folder, [], '', '/O2 /GS- /GR- /EHsc /MD')
        ok, error = result[str(path)]
        compiles.append(label)
        return dict(ok=ok, error=error if not ok else '', object=str(folder / 'fixture.obj'),
                    source_sha256=hashlib.sha256(source.encode()).hexdigest())

    golden = compile_source(target, 'reference')
    if not golden['ok']:
        raise RuntimeError(golden['error'])
    bodies = {native_sweep.symbol_method(name): (name, code, relocs)
              for name, code, relocs in match.coff_functions(Path(golden['object']).read_bytes())}
    groups = {'BatchFixture::f%d' % n: ['%08x' % n] for n in range(workers)}
    expected = {addrs[0]: bodies[method] for method, addrs in groups.items()}
    assert all(not relocs for _, _, relocs in expected.values()), 'Smoke must not ignore relocation/data proof'

    class Matcher:
        def scan(self, data):
            functions = {name: (code, relocs) for name, code, relocs in match.coff_functions(data)}
            return [dict(addr=addr, symbol=name) for addr, (name, code, relocs) in expected.items()
                    if functions.get(name) == (code, relocs)]

    baseline = compile_source(original, 'baseline')
    assert baseline['ok'], baseline['error']
    matcher = Matcher()
    keep = {row['addr'] for row in matcher.scan(Path(baseline['object']).read_bytes())}

    def evidence(addr):
        name, code, _ = expected[addr]
        return dict(addr=addr, rebuilt_symbol=name, target_asm=match.disasm(code, 0),
                    source_origin='synthetic compiler fixture, not Roblox evidence or credit')

    budget = providers.CloudBudget(requests=workers)
    options = dict(allow_cloud=True, budget=budget, gate=providers.CloudGate(workers),
                   max_tokens=768, thinking='disabled', reasoning_effort='low', retries=0, timeout=90,
                   generation='method')
    started = time.monotonic()
    with ThreadPoolExecutor(max_workers=workers) as pool:
        proposal, records = native_batch.model_batch('App/util/BatchFixture.cpp', original, groups, keep,
            model, 1, compile_source, matcher, evidence, print, options, pool)
    result = dict(model=model, workers=workers, requests=budget.requests, tokens=budget.tokens,
                  seconds=round(time.monotonic()-started, 2),
                  local_fixture_matches=len(proposal['witnesses']) if proposal else 0,
                  compiler_calls=compiles, records=records, synthetic=True, submitted=False)
    (output / 'result.json').write_text(json.dumps(result, indent=2), encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k != 'records'}, indent=2))
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--model', required=True)
    parser.add_argument('--workers', type=int, default=10)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = run(args.model, args.workers, args.output.resolve())
    sys.exit(0 if result['local_fixture_matches'] == args.workers else 1)

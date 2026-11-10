"""Offline MSVC search benchmark. Synthetic targets; no model requests or submissions.

python benchmarks/native_search.py --workers 1,2,4 --files 4
"""
import argparse
import json
from pathlib import Path
import sys
import time
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import match, native_sweep as sweep, rebuild, setup


def run(args):
    workers = [int(n) for n in args.workers.split(',')]
    if not workers or min(workers) < 1 or max(workers) > 64 or not 1 <= args.files <= 32:
        raise SystemExit('Use 1-64 workers and 1-32 files.')
    if 21022 not in setup.compilers():
        raise SystemExit('Historical compiler 21022 required.')
    output = Path(args.output).resolve()
    tree, overlay = output / 'tree', output / 'overlay'
    tree.mkdir(parents=True, exist_ok=True)
    overlay.mkdir(exist_ok=True)
    flags = '/O2 /Ob0 /GS- /EHsc /MD'
    texts, expected, names, inventory, rules = {}, {}, {}, {}, []
    for n in range(args.files):
        rel, cls = 'App/Bench%d.cpp' % n, 'Bench%d' % n
        source = ('namespace RBX {\nclass %s { public: int one(); int two(); int keep(); };\n'
                  'int %s::one(){return %d;}\nint %s::two(){return %d;}\nint %s::keep(){return %d;}\n}\n') % (
                      cls, cls, 1000+n, cls, 2000+n, cls, 3000+n)
        corrected = source
        for value in (1000+n, 2000+n):
            old, new = 'return %d;' % value, 'return %d;' % (value+10000)
            corrected = corrected.replace(old, new)
            rules.append(dict(name='constant-%d' % value, files=[rel], evidence='synthetic fixture', edits=[[old, new]]))
        texts[rel] = source
        obj = match.compile_text('2008-06', corrected, flags=flags, build=21022)
        for symbol, body, relocs in match.coff_functions(obj):
            addr = '%08x' % (len(expected)+1)
            assert not match.coff_data_refs(obj, symbol)
            expected[symbol] = addr, body, relocs
            names[addr] = dict(symbol=symbol)
            inventory[addr] = dict(unit='RBX::'+cls)
    def scan(obj):
        return [dict(addr=expected[s][0], symbol=s) for s, body, relocs in match.coff_functions(obj)
                if s in expected and set(expected[s][2]) <= set(relocs)
                and match.masked(body, relocs) == match.masked(expected[s][1], relocs)]
    matcher = SimpleNamespace(scan=scan, identity='synthetic')
    previous = sweep.ownership_candidates
    sweep.ownership_candidates = lambda obj, hits: {h['addr']: [h['addr']] for h in hits}
    report = dict(synthetic=True, server_verified=0, model_requests=0, submissions=0, runs=[])
    try:
        rebuild.toolchain()
        for count in workers:
            folder = output / ('workers-%d' % count)
            folder.mkdir(exist_ok=True)
            started = time.monotonic()
            proposals, records, _ = sweep.grid_discovery(dict(modes=[], scoped_modes=[], keep_partials=False,
                rewrite_rules=rules, search_cache=False), texts, set(names), matcher, folder, count,
                lambda source, rel, label: sweep.compile_unit(source, rel, label, folder, tree, overlay, [], '', flags),
                names, inventory, lambda _: None)
            proofs = sum(len(p['witnesses']) for p in proposals)
            assert proofs == 2 * args.files and all(not p['proof']['losses'] for p in proposals)
            row = dict(workers=count, seconds=round(time.monotonic()-started, 3), fixture_exact=proofs,
                       metrics=json.loads((folder/'metrics.json').read_text()))
            report['runs'].append(row)
            print(json.dumps(row), flush=True)
    finally:
        sweep.ownership_candidates = previous
    (output/'summary.json').write_text(json.dumps(report, indent=2))
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--workers', default='1,2,4')
    parser.add_argument('--files', type=int, default=4)
    parser.add_argument('--output', default='work/integrator-bench/native-search')
    run(parser.parse_args())

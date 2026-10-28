"""Replay real COFF objects through exhaustive and filtered native matching.

python benchmarks/native_matcher.py path/to/Block.obj path/to/Humanoid.obj
No model calls, builds or submissions. Requires installed 2008-06 client analysis.
Object-result caching is disabled; parsing caches are warm in both comparisons.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import sys
import time

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import match, native_sweep


class ExhaustiveMatcher(native_sweep.Matcher):
    def candidates(self, code, relocs):
        return self.index.get(len(code), ())


class NoObjectHits(dict):
    def get(self, key, default=None):
        return default


def run(args):
    if not 1 <= args.tasks <= 1024 or any(not 1 <= n <= 256 for n in args.workers):
        raise SystemExit('Use 1-1024 tasks and 1-256 workers.')
    objects = [(str(path), path.read_bytes()) for path in args.objects]
    addresses = set(match._functions('2008-06'))
    reference = ExhaustiveMatcher(addresses)
    expected = {name:reference.scan(obj) for name, obj in objects}
    report = dict(model_calls=0, builds=0, submissions=0, tasks=args.tasks,
                  object_cache=False, parser_cache='warm', results=[])
    for workers in args.workers:
        reference, filtered = ExhaustiveMatcher(addresses), native_sweep.Matcher(addresses)
        reference.cache, filtered.cache = NoObjectHits(), NoObjectHits()
        for mode, matcher in (('exhaustive', reference), ('prefix-cold', filtered),
                              ('prefix-warm', filtered), ('exhaustive-repeat', reference)):
            started = time.monotonic()
            def one(i):
                name, obj = objects[i % len(objects)]
                hits = matcher.scan(obj)
                if hits != expected[name]:
                    raise AssertionError('Exact address/symbol mismatch: ' + name)
                return len(hits)
            with ThreadPoolExecutor(workers) as pool:
                counts = list(pool.map(one, range(args.tasks)))
            row = dict(workers=workers, mode=mode, seconds=round(time.monotonic()-started, 3), exact_counts=counts)
            report['results'].append(row)
            print(json.dumps(row), flush=True)
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('objects', type=Path, nargs='+')
    parser.add_argument('--tasks', type=int, default=20)
    parser.add_argument('--workers', type=int, nargs='+', default=[1, 20])
    parser.add_argument('--output', type=Path)
    run(parser.parse_args())

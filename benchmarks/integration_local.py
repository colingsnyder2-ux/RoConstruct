"""Bounded compile-only benchmark. No linking, model requests, claims or submissions."""
import json
from pathlib import Path
import sys
import time
import uuid

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from roc import integration, integration_local, rebuild


def run():
    spec = rebuild.load_module('2008-06', 'rbxgs-app')
    plan = next(integration_local.layer_plan(spec))
    source = next(p for p in plan['sources'] if p.as_posix().endswith('/App/util/Units.cpp'))
    output = integration.ROOT / 'work/integrator-bench' / ('local-' + uuid.uuid4().hex[:12])
    rows = []
    for label in ('cold', 'warm'):
        started = time.monotonic()
        result = rebuild.compile_direct('2008-06', [source], output, plan['includes'], plan['defines'],
            plan['flags'], cl=plan['layer'].get('cl', rebuild.BUILD), append=plan['append'])
        ok, message = result[str(source)]
        rows.append(dict(stage=label, seconds=time.monotonic()-started, ok=ok,
                         cache_hit=message == 'content cache hit', diagnostic=message if not ok else None))
    report = dict(file=str(source), runs=rows, linked=False, native_credits=0,
                  speedup=rows[0]['seconds']/rows[1]['seconds'] if all(r['ok'] for r in rows) else None)
    integration.atomic_json(output / 'benchmark.json', report)
    print(json.dumps(report, indent=1))
    print('Evidence: ' + str(output / 'benchmark.json'))
    return all(r['ok'] for r in rows)


if __name__ == '__main__':
    sys.exit(0 if run() else 1)

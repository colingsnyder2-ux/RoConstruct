"""Batch isolated native-Doc closure probes with one shared object cache.

Usage:
  python rebuild/2008-06/p6/probe_native_doc.py SOURCE.cpp [SOURCE.cpp ...]
"""
import json
import os
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).parent
ROOT = HERE.parents[2]
OUT = HERE.parent / 'out' / 'p6-probes'

sources = [Path(arg).resolve() for arg in sys.argv[1:]]
if not sources:
    raise SystemExit('need one or more C++ sources')
for source in sources:
    if not source.is_file():
        raise SystemExit('missing: ' + str(source))

OUT.mkdir(parents=True, exist_ok=True)
results = []
for index, source in enumerate(sources):
    slug = re.sub(r'[^A-Za-z0-9_.-]+', '_', source.stem)
    probe = OUT / ('%02d-%s' % (index, slug))
    env = os.environ.copy()
    env['ROC_NATIVE_DOC_EXTRA'] = str(source)
    command = [sys.executable, str(HERE / 'build_client.py'), '--native-doc',
               '--native-doc-cache', '--native-doc-out', str(probe)]
    run = subprocess.run(command, cwd=ROOT, env=env, text=True,
                         stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (probe / 'probe.log').write_text(run.stdout)
    closure = probe / 'native-doc-closure.json'
    data = json.loads(closure.read_text()) if closure.exists() else {}
    results.append({'source': str(source), 'exit': run.returncode,
                    'unique_unresolved': data.get('unique_unresolved'),
                    'families': data.get('families', {}), 'out': str(probe),
                    'failure_tail': '' if closure.exists() else run.stdout[-1600:]})
    print('%s: %s unresolved' % (source.name, data.get('unique_unresolved', 'no closure')))

(OUT / 'batch-results.json').write_text(json.dumps(results, indent=2) + '\n')

"""Which model produces exacts (no model).  Reads workflow-log.jsonl: per model, rounds used and exacts credited to the
LAST model of a task that ended exact.  Writes workflow-model-rank.json (models by exacts per call); class_workflow.py
orders its ladder by it when --ladder is not given.
  python work/native-client/model_stats.py"""
import collections
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
calls, exact = collections.Counter(), collections.Counter()
for line in (HERE / 'workflow-log.jsonl').read_text(encoding='utf-8').splitlines():
    try:
        r = json.loads(line)
    except ValueError:
        continue
    for m in r.get('models', []):
        calls[m] += 1
    if r.get('exact') and r.get('models'):
        exact[r['models'][-1]] += len(r['exact'])
rank = sorted(calls, key=lambda m: -(exact[m] / calls[m]) if calls[m] >= 5 else 0)
(HERE / 'workflow-model-rank.json').write_text(json.dumps({'rank': rank, 'calls': calls, 'exact': exact}, indent=1))
for m in rank:
    print('%-58s calls %4d  exact %3d  per call %.3f' % (m, calls[m], exact[m], exact[m] / calls[m]))

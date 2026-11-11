"""Group native sources that do not compile unchanged by their first compiler error.

Reads `claude-template-promote/*/baseline/compile.log` (the unchanged-source
compile of the template gate).  Output: claude-baseline-compile-failures.json.
"""
import json
import re
from collections import defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ERROR = re.compile(r'([^\s(]+)\((\d+)\) : (?:fatal )?error (C\d+): (.*)')

groups = defaultdict(list)
for log in sorted(HERE.glob('claude-template-promote/*/baseline/compile.log')):
    promo = log.parents[1] / 'promotion.json'
    if not promo.exists() or json.loads(promo.read_text()).get('probe_status') != 'baseline-compile-failed':
        continue
    hit = ERROR.search(log.read_text(encoding='utf-8', errors='replace'))
    key = '%s %s' % (hit[3], re.sub(r"'[^']*'", "'X'", hit[4])[:80]) if hit else 'no error line'
    groups[key].append({'source': log.parents[1].name, 'file': Path(hit[1]).name if hit else None,
                        'line': int(hit[2]) if hit else None, 'text': hit[4][:160] if hit else None})
rows = sorted(groups.items(), key=lambda kv: -len(kv[1]))
(HERE / 'claude-baseline-compile-failures.json').write_text(json.dumps(dict(rows), indent=1) + '\n')
for key, items in rows:
    files = sorted({i['file'] for i in items if i['file']})
    print(len(items), key, '| in', ', '.join(files[:3]), '| e.g.', items[0]['source'], '|', items[0]['text'])

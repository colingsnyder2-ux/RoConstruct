"""Re-run callee identity learning for every earlier byte-identical draft (learning used the wrong closure before
2026-11-15).  Adds bindings to the LLM closure only; the next native_llm run's regate re-proves each body."""
import glob
import json
import sys
from pathlib import Path

sys.argv = sys.argv[:1]
import native_llm as m  # noqa: E402

latest = {}
for path in sorted(glob.glob(str(m.HERE / 'chats' / '*.json'))):
    try:
        row = json.loads(Path(path).read_text(encoding='utf-8'))
    except (OSError, ValueError):
        continue
    if row.get('status') == 'draft' and 'IDENTICAL' in row.get('result', ''):
        latest[row['addr']] = row
targets = {}
for line in m.LOG.read_text(encoding='utf-8').splitlines():
    row = m._json(line)
    if row and row.get('addr') in latest:
        targets[row['addr']] = row
learned = 0
for addr, t in targets.items():
    for manifest in sorted(m.folder(t).glob('*/run-bulk-*/manifest.json'), key=lambda p: p.stat().st_mtime)[-1:]:
        if m.learn_identities(t, {'manifest': str(manifest)}):
            learned += 1
            print('learned', addr, t['qual'], flush=True)
print('targets', len(targets), 'learned', learned)

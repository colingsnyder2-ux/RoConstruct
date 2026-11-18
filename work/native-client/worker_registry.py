"""List every model worker running on this machine for the dashboard's worker panel (no model).  The pool supervisor
(family_pool.py) only knows its own slots; this adds the family workers started by hand, the text workflow and the
headless Claude / Codex sessions.  Writes work/native-client/workers-extra.json every 10 s; roc/gui.py merges it into
/api/family-pool.
  python work/native-client/worker_registry.py"""
import json
import re
import time
from pathlib import Path

import psutil

HERE = Path(__file__).resolve().parent
OUT = HERE / 'workers-extra.json'


def pool_pids():
    try:
        slots = json.loads((HERE / 'family-pool-status.json').read_text(encoding='utf-8')).get('slots', [])
    except (OSError, ValueError):
        return set()
    return {s.get('pid') or s.get('external') for s in slots} - {None}


def scan():
    pooled, rows = pool_pids(), []
    for proc in psutil.process_iter(['pid', 'name', 'cmdline']):
        try:
            cmd = ' '.join(proc.info['cmdline'] or [])
            name = (proc.info['name'] or '').lower()
        except (psutil.Error, TypeError):
            continue
        pid = proc.info['pid']
        if name.startswith('python') and 'family_agents.py' in cmd and '--list' not in cmd and pid not in pooled:
            model = re.search(r'--model (\S+)', cmd)
            queue = re.search(r'--queue (\S+)', cmd)
            only = re.search(r'--only (?:"([^"]+)"|(\S+))', cmd)
            rows.append({'id': 'manual-%d' % pid, 'kind': 'manual', 'family': (only.group(1) or only.group(2)) if only else 'family batch',
                         'queue': queue.group(1) if queue else 'twins', 'model': model.group(1) if model else '', 'pid': pid})
        elif name.startswith('python') and 'class_workflow.py' in cmd:
            jobs = re.search(r'--jobs (\d+)', cmd)
            rows.append({'id': 'workflow', 'kind': 'text', 'family': 'text workflow (%s slots)' % (jobs.group(1) if jobs else '?'),
                         'queue': 'workflow', 'model': 'openrouter / cloudflare free, then sonnet', 'pid': pid})
        elif name.startswith('claude') and re.search(r' -p( |$)', cmd):
            rows.append({'id': 'claude-%d' % pid, 'kind': 'claude', 'family': 'Claude session', 'queue': 'agents',
                         'model': (re.search(r'--model (\S+)', cmd) or [None, 'claude'])[1], 'pid': pid})
        elif name.startswith('codex') and ' exec ' in cmd:
            rows.append({'id': 'codex-%d' % pid, 'kind': 'codex', 'family': 'Codex session', 'queue': 'agents', 'model': 'codex', 'pid': pid})
    return rows


while True:
    try:
        tmp = OUT.with_suffix('.tmp')
        tmp.write_text(json.dumps({'updated': time.time(), 'workers': scan()}, indent=1), encoding='utf-8')
        tmp.replace(OUT)
    except OSError:
        pass
    time.sleep(10)

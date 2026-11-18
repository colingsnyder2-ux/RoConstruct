"""Keep workers running on independent twin, owner, and ownerless batches."""
import json
import re
import subprocess
import sys
import time
from pathlib import Path

import psutil

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
LOGS = HERE / 'agent-logs'
STATE = HERE / 'family-pool-status.json'
LOGS.mkdir(exist_ok=True)

MODELS = {
    'open': ['opencode:opencode/beam-free', 'opencode:opencode/big-pickle',
             'opencode:opencode/deepseek-v4.1-flash-free', 'opencode:opencode/hy4-flash-free'],
    'nim': ['opencode:roc-nim/lightning', 'opencode:roc-nim/super-vl', 'opencode:roc-nim/nemotron',
            'opencode:roc-nim/kimi'],
}
PREFERRED = {
    'open-1': 'opencode:opencode/beam-free',
    'open-2': 'opencode:opencode/big-pickle',
    'open-3': 'opencode:opencode/deepseek-v4.1-flash-free',
    'nim-1': 'opencode:roc-nim/lightning',
    'nim-2': 'opencode:roc-nim/super-vl',
    'nim-3': 'opencode:roc-nim/nemotron',
    'nim-4': 'opencode:roc-nim/kimi',
}
slots = [
    {'id': 'open-1', 'kind': 'open', 'external': 42352, 'family': 'boost functor pieces: bind_t'},
    {'id': 'open-2', 'kind': 'open', 'external': 52308, 'family': 'boost functor pieces: basic_string'},
    {'id': 'open-3', 'kind': 'open'},
    {'id': 'nim-1', 'kind': 'nim', 'external': 45696, 'family': 'boost::any::holder'},
    {'id': 'nim-2', 'kind': 'nim'},
    {'id': 'nim-3', 'kind': 'nim'},
    {'id': 'nim-4', 'kind': 'nim', 'individual': True},
]
attempted = set()
model_offsets = {'open': 0, 'nim': 0}
model_cooldown = {}
processes = {}
last_scan = 0
queue = []

# Keep running workers when the supervisor is restarted.
try:
    saved = json.loads(STATE.read_text(encoding='utf-8'))
    for slot in slots:
        old = next((x for x in saved['slots'] if x['id'] == slot['id']), {})
        pid = old.get('pid') or old.get('external')
        if pid and psutil.pid_exists(pid):
            slot.update(old)
            slot['external'] = pid
    attempted.update(saved.get('attempted', []))
    model_cooldown.update(saved.get('model_cooldown', {}))
except (OSError, ValueError, KeyError):
    pass


def alive(pid):
    return psutil.pid_exists(pid) and psutil.Process(pid).is_running()


def available_families():
    found = []
    for kind in ('twins', 'owners', 'ownerless'):
        result = subprocess.run([sys.executable, str(HERE / 'family_agents.py'), '--queue', kind,
                                 '--list', '--min', '1'], cwd=ROOT, capture_output=True, text=True,
                                encoding='utf-8', errors='replace', timeout=60, check=True)
        for line in result.stdout.splitlines():
            match = re.match(r'\s*(\d+)\s+(.+)$', line)
            if match:
                found.append({'size': int(match.group(1)), 'family': match.group(2), 'queue': kind})
    return sorted(found, key=lambda x: (0 if x['queue'] == 'twins' and x['size'] > 1 else
                                       1 if x['queue'] == 'owners' and x['size'] > 1 else
                                       2 if x['queue'] == 'ownerless' else 3, -x['size']))


def provider_error(path):
    try:
        lines = path.read_text(encoding='utf-8', errors='replace').splitlines()
    except OSError:
        return False
    for line in lines:
        try:
            event = json.loads(line)
        except ValueError:
            if line.startswith('[family agents]') and any(word in line.lower() for word in ('provider error:', 'timeout')):
                return True
            continue
        if isinstance(event, dict) and event.get('type') == 'error':
            return True
    return False


def choose_model(slot, now):
    candidates = MODELS[slot['kind']]
    offset = model_offsets[slot['kind']] % len(candidates)
    candidates = [PREFERRED[slot['id']]] + [x for x in candidates[offset:] + candidates[:offset]
                                            if x != PREFERRED[slot['id']]]
    available = [x for x in candidates if model_cooldown.get(x, 0) <= now]
    in_use = {s.get('model') for s in slots if s.get('family')}
    return next((x for x in available if x not in in_use), available[0] if available else None)


def save():
    STATE.write_text(json.dumps({'updated': time.time(), 'slots': slots, 'attempted': sorted(attempted),
                                 'model_cooldown': model_cooldown}, indent=2))


while True:
    now = time.time()
    if now - last_scan >= 60:
        try:
            queue = available_families()
        except (OSError, subprocess.TimeoutExpired, subprocess.CalledProcessError):
            queue = []
        last_scan = now
    for slot in slots:
        pid = slot.get('external')
        if pid:
            if alive(pid):
                continue
            slot.pop('external', None)
            family = slot.get('family')
            model = slot.get('model')
            if family and model:
                label = family if slot.get('queue') else ('' if family.startswith('ownerless:') else 'class ') + family
                path = LOGS / ('family-opencode-%s.log' % re.sub(r'\W+', '_', label)[:60])
                if provider_error(path):
                    model_cooldown[model] = now + 900
                    model_offsets[slot['kind']] += 1
                else:
                    attempted.add(family)
            slot.pop('family', None)
            slot.pop('pid', None)
            slot.pop('model', None)
            slot.pop('queue', None)
        proc = processes.get(slot['id'])
        if proc:
            code = proc.poll()
            if code is None:
                continue
            processes.pop(slot['id'])
            label = slot['family'] if slot.get('queue') else ('' if slot['family'].startswith('ownerless:') else 'class ') + slot['family']
            path = LOGS / ('family-opencode-%s.log' % re.sub(r'\W+', '_', label)[:60])
            failed = code != 0 or provider_error(path)
            if failed:
                model_cooldown[slot['model']] = now + 900
                model_offsets[slot['kind']] += 1
            else:
                attempted.add(slot['family'])
            slot.pop('pid', None)
            slot.pop('family', None)
            slot.pop('model', None)
            slot.pop('queue', None)
        active = {s.get('family') for s in slots if s.get('family')}
        active |= {'class ' + f for f in active if not f.startswith(('class ', 'ownerless:'))}
        task = next((x for x in queue if x['family'] not in active and x['family'] not in attempted
                     and (not slot.get('individual') or x['queue'] in ('owners', 'ownerless'))), None)
        if not task:
            continue
        family = task['family']
        model = choose_model(slot, now)
        if not model:
            continue
        log = (LOGS / ('family-pool-' + slot['id'] + '.log')).open('a', encoding='utf-8')
        kwargs = {'creationflags': subprocess.CREATE_NO_WINDOW} if sys.platform == 'win32' else {}
        proc = subprocess.Popen([sys.executable, str(HERE / 'family_agents.py'), '--queue',
                                 task['queue'], '--min', '1', '--exact',
                                 '--jobs', '1', '--model', model, '--only', family],
                                cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, **kwargs)
        log.close()
        processes[slot['id']] = proc
        slot.update(family=family, queue=task['queue'], model=model, pid=proc.pid)
    save()
    time.sleep(10)

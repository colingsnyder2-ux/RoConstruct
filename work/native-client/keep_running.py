"""Keep the lanes busy (owner 2026-11-17).  Every minute: restart any enabled lane whose process (started by this
supervisor) has exited.  No census.  Stop: create work/native-client/KEEP.stop
  python work/native-client/keep_running.py          # lanes: KEEP_LANES env, default agents,codexagents,workflow

Lanes are tracked by their own Popen handle: a process-list query (WMI) fails when the machine is loaded, and that made
an earlier version start the same lane six times (2026-11-17)."""
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PY = sys.executable
FREE = 'opencode/deepseek-v4.1-flash-free,opencode/nemotron-3.5-super-vl-free,opencode/glm-5.3-flash-free'
LANES = {   # name: (argv, cwd, extra env, minimum seconds between starts, seconds before the first start)
    'agents': ([PY, '-u', 'work/native-client/lane_runner.py', 'agents', '--model', 'sonnet', '--jobs', '2', '--codex', '0'],
               ROOT, {'ROC_FABLE_SHARE': '1'}, 60, int(os.environ.get('KEEP_AGENTS_DELAY') or 0)),
    'codexagents': ([PY, '-u', 'work/native-client/lane_runner.py', 'agents', '--model', 'codex', '--jobs',
                     os.environ.get('KEEP_CODEX') or '3'], ROOT, {}, 600, 0),
    'pool': ([PY, '-u', 'work/native-client/family_pool.py'], ROOT, {'PYTHONIOENCODING': 'utf-8'}, 60, 0),
    'codexfam': ([PY, '-u', 'work/native-client/family_agents.py', '--queue', 'ownerless', '--min', '1', '--jobs', '2', '--model', 'codex'],
                 ROOT, {'PYTHONIOENCODING': 'utf-8'}, 300, 0),
    'evolve': ([PY, '-u', 'work/native-client/evolve_lane.py'], ROOT, {'PYTHONIOENCODING': 'utf-8'}, 300, 0),
    'workflow': ([PY, '-u', 'class_workflow.py', '--jobs', '5', '--rounds', '5'], HERE, {'PYTHONIOENCODING': 'utf-8'}, 600, 0),
    'donorctx': ([PY, '-u', 'donor_translate.py', '--jobs', '6', '--rounds', '3', '--model', 'opencode/beam-free'], HERE,
                 {'PYTHONIOENCODING': 'utf-8', 'ROC_LLM_TIMEOUT': '300'}, 1800, 0),
    'failures': ([PY, '-u', 'lane_runner.py', 'failures', '--jobs', '6'], HERE, {'ROC_LADDER': FREE, 'ROC_LLM_TIMEOUT': '300'}, 1800, 0),
}
ENABLED = [n for n in (os.environ.get('KEEP_LANES') or 'agents,workflow').split(',') if n in LANES]
# Codex tool agents are off by default: 0 exact, their shells stall (2026-11-17); Codex stays in the workflow ladder.
began = time.time()
procs, last = {}, {}
while not (HERE / 'KEEP.stop').is_file():
    for name in ENABLED:
        argv, cwd, env, gap, delay = LANES[name]
        alive = name in procs and procs[name].poll() is None
        if alive or time.time() - last.get(name, 0) < gap or time.time() - began < delay:
            continue
        log = open(HERE / ('keep-%s.log' % name), 'a', encoding='utf-8')
        log.write('\n=== start %s ===\n' % time.strftime('%Y-%m-%d %H:%M'))
        log.flush()
        procs[name] = subprocess.Popen(argv, cwd=cwd, env={**os.environ, **env}, stdout=log, stderr=subprocess.STDOUT)
        last[name] = time.time()
        print(time.strftime('%H:%M'), 'started', name, flush=True)
    time.sleep(60)
print('KEEP.stop found; lanes already running finish on their own', flush=True)

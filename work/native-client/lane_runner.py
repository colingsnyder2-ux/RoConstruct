"""One entry point for the automatic native lanes (dashboard job kind `native_lane`).
  python work/native-client/lane_runner.py LANE [--jobs N]
LANE:
  failures  re-queue every remaining compile failure (placeholder + named) and run the lane with header-add enabled
  regate    re-check saved placeholder answers against the current headers (no model calls)
  vendor    preprocessed-unit vendor wrappers (vendor_i.py) -> prove -> learn reference identities -> re-prove
  layout    class-layout lane (native_class_lane.py): one class's failing functions + a header fix per run
  promote   promote proven header-add lines (with before/after prove), then the functions, then prove the new TUs
  census    full census (prove.py --all) + publish the site (drop guard applies)
  classify  refresh remaining-classified.json and print the buckets
Every step prints progress lines; the dashboard streams them."""
import argparse
import glob
import json
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PY = sys.executable
ap = argparse.ArgumentParser()
ap.add_argument('lane', choices=['failures', 'regate', 'vendor', 'layout', 'promote', 'census', 'classify', 'flags', 'auto', 'agent', 'donor', 'pattern'])
ap.add_argument('--jobs', type=int, default=8)
args = ap.parse_args()


def run(cmd, cwd=ROOT, tail=8):
    print('$ ' + ' '.join(map(str, cmd)), flush=True)
    started = time.time()
    proc = subprocess.Popen(list(map(str, cmd)), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                            encoding='utf-8', errors='replace')
    lines = []
    for line in proc.stdout:
        lines.append(line.rstrip())
        if len(line) < 300:
            print('  ' + line.rstrip(), flush=True)
    proc.wait()
    print('  (exit %s, %ds)' % (proc.returncode, time.time() - started), flush=True)
    return proc.returncode, lines


def census_running():
    return (HERE / 'prove-out/CENSUS.lock').is_file()


def results():
    return json.loads((HERE / 'placeholder-lane/results.json').read_text())


def counts(addrs=None):
    r = results()
    rows = [v for a, v in r.items() if addrs is None or a in addrs]
    out = {}
    for v in rows:
        out[v['status']] = out.get(v['status'], 0) + 1
    return out


if args.lane in ('failures', 'regate', 'promote', 'vendor', 'layout') and census_running():
    sys.exit('a census is running (prove-out/CENSUS.lock): try again when it finishes')

if args.lane == 'failures':
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    named = set()
    for f in glob.glob(str(HERE / 'creator-partition/named-*.json')):
        if 'all-fail' in f or 'hdradd' in f:
            continue
        try:
            named |= set(json.loads(Path(f).read_text()))
        except (ValueError, OSError):
            pass
    r = results()
    # Token budget: no-class-header needs class recovery (agent/subagent), and a target with 3+ lane runs waits for a
    # header change instead of burning more model calls.
    fail = [a for a, v in r.items() if v['status'] in ('compile_failed', 'rejected-header-add') and a in cl
            and v.get('runs', 1) < 3]
    for a in fail:
        del r[a]
    (HERE / 'placeholder-lane/results.json').write_text(json.dumps(r, indent=1))
    nm = [a for a in fail if a in named]
    (HERE / 'creator-partition/named-all-fail.json').write_text(json.dumps(nm))
    print('re-queued %d compile failures (%d named) for the header-add lane' % (len(fail), len(nm)), flush=True)
    run([PY, 'native_placeholder_llm.py', '--jobs', args.jobs], cwd=HERE)
    run([PY, 'native_placeholder_llm.py', '--named', 'creator-partition/named-all-fail.json', '--jobs', args.jobs], cwd=HERE)
    done = set(fail)
    r = results()
    print('RESULT %s; exact using header-add: %d' % (counts(done), sum(1 for a in done if r.get(a, {}).get('header_add')
                                                                     and r[a]['status'] == 'inactive_exact')), flush=True)

elif args.lane == 'regate':
    run([PY, 'native_placeholder_llm.py', '--regate', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'vendor':
    run([PY, 'vendor_i.py'], cwd=HERE)
    files = json.loads((HERE / 'creator-partition/vendor-i-wrappers.json').read_text())['written']
    if not files:
        sys.exit('no vendor wrappers written')
    family = 'prove-' + Path(files[0]).stem
    run([PY, 'work/native-client/prove.py', *files, '--rounds', '1', '--no-register'])
    run([PY, 'work/native-client/creator-partition/learn_refs.py', family, 'work/native-client/vendor-identity-bindings.json'])
    run([PY, 'work/native-client/prove.py', *files, '--rounds', '2', '--no-register'])
    units = json.loads((HERE / 'creator-partition/vendor-units.json').read_text())
    targets = {a for v in units.values() for a in v}
    manifest = json.loads((HERE / 'prove-out' / family / 'manifest.json').read_text())
    exact = {c['addr'] for f in manifest['families'] for j in f.get('jobs', []) for c in j.get('checks', [])}
    print('RESULT vendor targets exact: %d of %d' % (len(targets & exact), len(targets)), flush=True)

elif args.lane == 'layout':
    run([PY, 'native_class_lane.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'promote':
    # No-model lane exacts (flag sweep, donor transplant, pattern lane) live in their own hits files: merge them.
    for name in ('flag-sweep-hits.json', 'donor-transplant-hits.json', 'pattern-lane-hits.json'):
        hits_path = HERE / name
        if not hits_path.is_file():
            continue
        r = results()
        hits = json.loads(hits_path.read_text())
        for addr, hit in hits.items():
            row = r.setdefault(addr, {'model': hit.get('model', name.split('-hits')[0])})
            row.update(status='inactive_exact', **({'flags': hit['flags']} if hit.get('flags') else {}),
                       **({'class': hit['cls'], 'decl': hit['decl']} if hit.get('cls') else {}))
        (HERE / 'placeholder-lane/results.json').write_text(json.dumps(r, indent=1))
        print('merged %d exacts from %s' % (len(hits), name), flush=True)
    run([PY, 'promote_header_adds.py'], cwd=HERE)
    run([PY, 'native_placeholder_promote.py'], cwd=HERE)
    _, status = run(['git', 'status', '--short', 'rebuild/2008-06/native-classes'])
    new = [l.split()[-1] for l in status if l.startswith('??') and 'Inferred_' in l]
    if new:
        run([PY, 'work/native-client/prove.py', *new, '--rounds', '2', '--quiet'])
    print('RESULT promoted; %d new Inferred TUs proved' % len(new), flush=True)

elif args.lane == 'census':
    if census_running():
        sys.exit('a census is already running')
    # Register what the lanes and subagents produced: evidence files and new native sources.
    inv_path = HERE / 'ogre-native-full-inventory-all.json'
    inv = json.loads(inv_path.read_text())
    fam = inv['families'][0]
    for ev in ['class-identity-bindings.json', 'template-identity-bindings.json', 'template-identity-bindings-round3.json',
               'template-identity-bindings-netser.json', 'template-identity-bindings-signal.json', 'vendor-identity-bindings.json',
               'inferred-identity-bindings.json', 'identity-session-bindings.json', 'creator-reference-bindings.json']:
        rel = 'work/native-client/' + ev
        if (HERE / ev).is_file() and rel not in fam['evidence']:
            fam['evidence'].append(rel)
    new_src = HERE / 'class-lane-new-sources.json'
    extra = json.loads(new_src.read_text()) if new_src.is_file() else []
    extra += json.loads((HERE / 'creator-partition/vendor-i-wrappers.json').read_text()).get('written', [])         if (HERE / 'creator-partition/vendor-i-wrappers.json').is_file() else []
    for src in extra:
        if (ROOT / src).is_file() and src not in fam['sources']:
            fam['sources'].append(src)
    inv_path.write_text(json.dumps(inv, indent=1))
    print('registered evidence and %d candidate sources' % len(extra), flush=True)
    run([PY, 'work/native-client/prove.py', '--all', '--rounds', '2', '--quiet'])
    run([PY, '-c', 'from roc import integration_site, server; import shutil; '
                   'r = integration_site.build(); print({k: v["functions"] for k, v in r["groups"].items()}); '
                   'server.publish_pages(shutil.which("git"))'])

elif args.lane == 'donor':
    run([PY, 'donor_transplant.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'pattern':
    run([PY, 'pattern_lane.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'flags':
    run([PY, 'flag_sweep.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'auto':
    # Unattended cycle: regate -> header-add failures -> class layout -> flag sweep -> promote -> census + publish,
    # repeated; each cycle counts its gains on the site (census takes minutes since the parallel/per-file cache work).
    for cycle in range(1, 100):
        print('=== auto cycle %d ===' % cycle, flush=True)
        for lane in ('regate', 'donor', 'pattern', 'failures', 'layout', 'flags', 'promote', 'census'):
            run([PY, str(HERE / 'lane_runner.py'), lane, '--jobs', args.jobs])
        if (HERE / 'native-llm' / 'STOP').is_file():
            print('STOP file present: ending auto cycles', flush=True)
            break

elif args.lane == 'agent':
    # One headless Claude Code (Sonnet) class-recovery task per run, from work/native-client/agent-class-queue.json
    # (list of {"class": ..., "brief": ...}); same constrained brief as the class subagents; tool allowlist only.
    queue_path = HERE / 'agent-class-queue.json'
    queue = json.loads(queue_path.read_text()) if queue_path.is_file() else []
    if not queue:
        sys.exit('agent-class-queue.json is empty')
    task = queue.pop(0)
    queue_path.write_text(json.dumps(queue, indent=1))
    brief = (task.get('brief') or '') + '''

Rules (from CLAUDE.md): real native headers and member names, `// INFERRED: <evidence>` on inferred members, no padding
arrays, no (char*)this+offset access, no invented globals, no __emit/asm. Lease files with `roc.cmd lease take`. Prove
with `python work/native-client/prove.py <file> --rounds 1 --no-register` (never --all). Never edit roc/native_bulk.py,
roc/match.py, roc/rebuild.py, rebuild/2008-06/tests/native_check_runner.py, the core headers v8tree/Instance.h,
v8datamodel/DataModel.h, util/Events.h, reflection/*.h, or ogre-native-full-inventory-all.json. Append addr->symbol pairs
of exact functions to work/native-client/class-identity-bindings.json and new .cpp paths to
work/native-client/class-lane-new-sources.json. Commit locally (message ending with
`Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>`), never push. Stop after about 2 hours.'''
    tools = ['Read', 'Edit', 'Write', 'Grep', 'Glob', 'Bash(python:*)', 'Bash(roc.cmd:*)', 'Bash(./roc.cmd:*)',
             'Bash(git add:*)', 'Bash(git commit:*)', 'Bash(git status:*)', 'Bash(git diff:*)', 'Bash(ls:*)', 'Bash(cat:*)']
    print('agent task: %s' % task.get('class'), flush=True)
    run(['claude', '-p', 'Class recovery task for %s.\n%s' % (task.get('class'), brief), '--model', 'sonnet',
         '--permission-mode', 'acceptEdits', '--allowedTools', *tools])

elif args.lane == 'classify':
    run([PY, 'work/native-client/classify_remaining.py', '--refresh'])

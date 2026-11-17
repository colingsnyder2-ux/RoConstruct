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
ap.add_argument('lane', choices=['failures', 'regate', 'vendor', 'layout', 'promote', 'census', 'classify'])
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
    fail = [a for a, v in r.items() if v['status'] in ('compile_failed', 'rejected-header-add', 'no-class-header') and a in cl]
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
    run([PY, 'work/native-client/prove.py', '--all', '--rounds', '2', '--quiet'])
    run([PY, '-c', 'from roc import integration_site, server; import shutil; '
                   'r = integration_site.build(); print({k: v["functions"] for k, v in r["groups"].items()}); '
                   'server.publish_pages(shutil.which("git"))'])

elif args.lane == 'classify':
    run([PY, 'work/native-client/classify_remaining.py', '--refresh'])

"""Run the layout refresh chain in the right order. Nothing is pushed or published unless you pass --publish.

  python work/native-client/layout/refresh_all.py            inventory, export (slow), index, names, map, site data
  python work/native-client/layout/refresh_all.py --quick    skip the export: re-run names, map and site data only
  python work/native-client/layout/refresh_all.py --publish  also rebuild integration.json and publish the site (asks for nothing: use with care)

Steps, each skipped with --skip NAME:
  inventory   inventory.py (builds source-layout-map.json, function-files.json)
  export      layout_pipeline.py --branch (local commit only; never pushes)
  index       ghidra_index.py (slow; skipped when ghidra-index.json exists unless --reindex)
  names       name_match.py
  map         function_map.py (writes docs/function-map.json, prints held-out accuracy)
  libs        site_libs.py
  site        site_paths.py
  queue       review_queue.py
"""
import argparse
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def run(name, *argv, env=None):
    started = time.time()
    print('== %s' % name, flush=True)
    code = subprocess.run([sys.executable, *argv], cwd=ROOT, env={**os.environ, **(env or {})}).returncode
    print('   %s in %.0fs (exit %d)' % (name, time.time() - started, code), flush=True)
    if code:
        sys.exit('step %s failed; later steps need its output' % name)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--quick', action='store_true')
    ap.add_argument('--reindex', action='store_true')
    ap.add_argument('--publish', action='store_true')
    ap.add_argument('--skip', action='append', default=[])
    ap.add_argument('--workers', default='6')
    args = ap.parse_args()
    skip = set(args.skip) | ({'inventory', 'export'} if args.quick else set())
    here = lambda f: str(HERE.relative_to(ROOT) / f)
    if 'inventory' not in skip:
        run('inventory', here('inventory.py'), env={'LAYOUT_SKIP_CONSUMERS': '1'})
    if 'export' not in skip:
        run('export', here('layout_pipeline.py'), '--branch', '--workers', args.workers)
    if 'index' not in skip and (args.reindex or not (HERE / 'ghidra-index.json').exists()):
        run('index', here('ghidra_index.py'))
    if 'names' not in skip and (HERE / 'ghidra-index.json').exists():
        run('names', here('name_match.py'))
    if 'map' not in skip:
        run('map', here('function_map.py'))
    if 'libs' not in skip:
        run('libs', here('site_libs.py'))
    if 'map' not in skip:
        run('map again', here('function_map.py'))          # library files exist now: the L tier needs them
    if 'site' not in skip:
        run('site', here('site_paths.py'))
    if 'queue' not in skip:
        run('queue', here('review_queue.py'))
    if args.publish:
        sys.path.insert(0, str(ROOT))
        import shutil
        from roc import integration_site, server
        integration_site.build(log=print)
        server.publish_pages(shutil.which('git'), log=print)


if __name__ == '__main__':
    main()

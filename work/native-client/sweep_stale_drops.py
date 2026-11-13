"""Clear each module's saved verified drop lists (vdrop.json / excluded.json), rebuild, keep the result only if
ownership does not drop. Lists saved by failed runs (a missing import library, a broken dependency) keep exact
functions out of later builds forever; Ogre lost 300+ to them.

  python work/native-client/sweep_stale_drops.py                 -> every live module with a verified layer
  python work/native-client/sweep_stale_drops.py G3D XTP          -> only these module names
A module that loses owned functions gets its lists back and is rebuilt once more to restore its outputs.
A kept result must also leave every module that depends on it (transitively) linked with its test passing and no
fewer owned functions: a cleared list can make a library redefine symbols another library supplies (G3D's png copies
against libpng), which only the dependent's link shows. Otherwise the lists are restored and the dependents rebuilt.
"""
import json
import shutil
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rebuild  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out'
BACKUP = ROOT / 'work/native-client/drop-list-backups'


def build(spec_stem):
    log = ROOT / 'work/native-client' / ('sweep-%s.log' % spec_stem)
    with log.open('w') as stream:
        subprocess.run([sys.executable, str(ROOT / 'roc.py'), 'rebuild', '2008-06', 'module', spec_stem, '--no-notify'],
                       cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)


def owned(name):
    report = OUT / name / 'report.json'
    data = json.loads(report.read_text()) if report.exists() else {}
    return set(data.get('owned_addrs', [])) if data.get('linked') and data.get('test_exit') == 0 else set()


def dependents(name):
    """[(spec stem, module name)] of every live module that depends on `name`, directly or through another module."""
    specs = {path.stem: spec for path, spec in rebuild.live_module_specs('2008-06')}
    by_name = {spec['name']: stem for stem, spec in specs.items()}
    reach, frontier = [], {by_name[name]}
    while frontier:
        found = {stem for stem, spec in specs.items() if stem not in reach and frontier & set(spec.get('depends', []))}
        reach += sorted(found)
        frontier = found
    return [(stem, specs[stem]['name']) for stem in reach]


def main():
    wanted = set(sys.argv[1:])
    for path, spec in rebuild.live_module_specs('2008-06'):
        name = spec['name']
        verified = OUT / name / 'verified'
        lists = [verified / f for f in ('vdrop.json', 'excluded.json') if (verified / f).exists()]
        if (wanted and name not in wanted) or not spec.get('verified') or not lists:
            continue
        sizes = {f.name: len(json.loads(f.read_text())) for f in lists}
        if not any(sizes.values()):
            continue
        before = owned(name)
        keep = BACKUP / name
        keep.mkdir(parents=True, exist_ok=True)
        for f in lists:
            shutil.copy2(f, keep / f.name)
            f.write_text('[]')
        started = time.time()
        build(path.stem)
        after = owned(name)
        verdict = 'kept' if after and len(after) >= len(before) and not (before - after) else 'restored'
        broken = []
        if verdict == 'kept':
            for stem, dep in dependents(name):
                dep_before = owned(dep)
                build(stem)
                dep_after = owned(dep)
                if not dep_after or dep_before - dep_after:
                    broken.append(dep)
            if broken:
                verdict = 'restored (breaks ' + ', '.join(broken) + ')'
        if verdict.startswith('restored'):
            for f in lists:
                shutil.copy2(keep / f.name, f)
            build(path.stem)
            for stem, dep in dependents(name):
                build(stem)
        print(json.dumps({'module': name, 'lists': sizes, 'before': len(before), 'after': len(after),
                          'gain': len(after - before), 'loss': len(before - after), 'verdict': verdict,
                          'seconds': round(time.time() - started)}), flush=True)


if __name__ == '__main__':
    main()

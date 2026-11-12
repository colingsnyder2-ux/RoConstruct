"""Trial: layer recovered native sources ahead of a library module's upstream objects, build it, report ownership.

  python work/native-client/native_layer_trial.py g3d            -> build trial module G3DNativeTrial, compare with out/G3D
  python work/native-client/native_layer_trial.py xtp --dry-run  -> only list the native -> upstream object mapping

Each native file `rebuild/2008-06/native-classes/X.cpp` that names an upstream file in its header ("upstream PATH")
or whose name minus a library prefix equals an upstream source stem replaces that upstream object: a wrapper
`work/native-layers/<module>-<n>/<Stem>.cpp` includes it, so the object keeps the upstream name and the module's
first-layer-wins resolution picks it. Wrappers are grouped by the file's `// native-flags:` line. The trial copies the
live module's verified swaps/state so the comparison is like for like. Never edits the live module spec.
"""
import argparse
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild  # noqa: E402

CLIENT = '2008-06'
NATIVE = ROOT / 'rebuild' / CLIENT / 'native-classes'
PREFIXES = ('G3D', 'XTP', 'Xtp', 'Ogre', 'Boost', 'Lua', 'Png', 'Jpeg', 'Zlib', 'Mfc', 'Atl', 'Scint')


def upstream_sources(spec):
    """[(layer, recipe, src_root, {stem: path})] for recipe/direct layers."""
    out = []
    for layer in spec['layers']:
        if layer['mode'] == 'recipe':
            recipe = libs.RECIPES[layer['recipe']]
            src = libs._case_path(libs.LIBS / recipe['src'])
            listed = recipe.get('files')
            if layer['files'] == 'recipe' and isinstance(listed, list):
                paths = [src / f for f in listed]
            else:
                globs = (listed if layer['files'] == 'recipe' else layer['files']).split()
                paths = [p for g in globs for p in src.glob(g)]
            paths = [p for p in paths if p.relative_to(src).as_posix() not in layer.get('exclude', [])]
            out.append((layer, layer['recipe'], src, {p.stem: p for p in paths}))
        else:
            src = ROOT / layer['dir']
            paths = [p for g in layer['files'].split() for p in src.glob(g) if p.name not in layer.get('exclude', [])]
            out.append((layer, layer.get('recipe') or layer.get('defines_from_recipe'), src, {p.stem: p for p in paths}))
    return out


def mapping(spec):
    """{(layer index, stem): native file} preferring the header's upstream path over a name match."""
    sources = upstream_sources(spec)
    found = {}
    for native in sorted(NATIVE.glob('*.cpp')):
        head = native.read_text(encoding='utf-8', errors='replace')[:600]
        named = re.search(r'upstream (\S+?\.(?:cpp|c))\b', head)
        stem = None
        if named:
            stem = Path(named.group(1)).stem
            hits = [i for i, (_, _, src, stems) in enumerate(sources)
                    if stem in stems and (ROOT / named.group(1)).resolve() == stems[stem].resolve()]
        else:
            prefix = next((p for p in PREFIXES if native.stem.startswith(p)), None)
            stem = native.stem[len(prefix):] if prefix else None
            hits = [i for i, (_, _, _, stems) in enumerate(sources) if stem in stems]
        if len(hits) == 1 and (hits[0], stem) not in found:
            found[(hits[0], stem)] = native
    return sources, found


def includes_for(layer, recipe_name):
    """Repo-relative include dirs for a recipe (its patched tree when the module builds one) plus layer extras."""
    out = []
    if recipe_name:
        recipe = libs.RECIPES[recipe_name]
        src = libs._case_path(libs.LIBS / recipe['src'])
        tree = rebuild.patched_tree(CLIENT, recipe_name) if layer['mode'] == 'recipe' else src
        out.append(tree)
        for item in recipe.get('include', []):
            if item != 'WINSDK':
                path = libs._case_path(libs.LIBS / item)
                out.append(rebuild._in_tree(path, src, tree) if layer['mode'] == 'recipe' else path)
    out += [ROOT / i for i in layer.get('extra_includes', [])]
    rel = []
    for path in out:
        path = Path(path).resolve()
        try:
            rel.append(path.relative_to(ROOT).as_posix())
        except ValueError:
            continue
    return list(dict.fromkeys(rel))


def upstream_dir(source, stem):
    """Repo-relative folder of the upstream file (inside the patched tree when the layer builds from a recipe)."""
    layer, recipe_name, src, stems = source
    folder = stems[stem].parent
    if layer['mode'] == 'recipe':
        folder = rebuild.patched_tree(CLIENT, recipe_name) / folder.relative_to(src)
    return Path(folder).resolve().relative_to(ROOT).as_posix()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module', help='module spec name, e.g. g3d, g3d-gl, xtp, boost, lua')
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--exclude', nargs='*', default=[], help='upstream stems to leave on the upstream object')
    args = ap.parse_args()
    spec = rebuild.load_module(CLIENT, args.module)
    sources, found = mapping(spec)
    found = {key: native for key, native in found.items() if key[1] not in args.exclude}
    print('%s: %d native files map onto upstream objects' % (spec['name'], len(found)))
    if args.dry_run:
        for (i, stem), native in sorted(found.items()):
            print('  %-28s <- %s' % (stem, native.name))
        return
    if not found:
        return
    groups = {}
    for (i, stem), native in found.items():
        layer, recipe_name = sources[i][0], sources[i][1]
        flags = native.read_text(encoding='utf-8', errors='replace').splitlines()[0]
        flags = flags.split('native-flags:', 1)[1].strip() if 'native-flags:' in flags else layer['flags']
        groups.setdefault((i, flags), []).append((stem, native))
    trial_layers = []
    base = ROOT / 'work' / 'native-layers'
    for n, ((i, flags), items) in enumerate(sorted(groups.items(), key=lambda x: -len(x[1]))):
        layer, recipe_name = sources[i][0], sources[i][1]
        folder = base / ('%s-%d' % (args.module, n))
        if folder.exists():
            shutil.rmtree(folder)
        folder.mkdir(parents=True)
        for stem, native in items:
            (folder / (stem + native.suffix)).write_text(
                '// Native layer wrapper: the recovered native source under its upstream object name.\n'
                '#include "%s"\n' % native.resolve().as_posix())
        recipe = libs.RECIPES.get(recipe_name, {}) if recipe_name else {}
        trial = {'name': 'native%d' % n, 'mode': 'direct', 'dir': folder.relative_to(ROOT).as_posix(), 'files': '*.cpp *.c',
                 'flags': ' '.join([flags] + ['/FI' + h for h in recipe.get('preinclude', [])]),
                 'defines': ((recipe.get('defines') or layer.get('defines') or '') + ' ' + layer.get('extra_defines', '')).strip(),
                 # the upstream file's own folder first: sources include sibling headers ("Resource.h") by quoted name
                 'extra_includes': list(dict.fromkeys(
                     [upstream_dir(sources[i], stem) for stem, _ in items] + includes_for(layer, recipe_name)))}
        trial_layers.append(trial)
    name = spec['name'] + 'NativeTrial'
    trial_spec = dict(spec, name=name, trial=True, layers=trial_layers + spec['layers'],
                      description='TRIAL: %s with recovered native sources layered before upstream (not a gate candidate).' % spec['name'])
    spec_path = ROOT / 'rebuild' / CLIENT / 'modules' / (args.module + '-native-trial.json')
    spec_path.write_text(json.dumps(trial_spec, indent=1))
    out = ROOT / 'rebuild' / CLIENT / 'out'
    live_verified, trial_verified = out / spec['name'] / 'verified', out / name / 'verified'
    if live_verified.exists():
        if trial_verified.exists():
            shutil.rmtree(trial_verified)
        shutil.copytree(live_verified, trial_verified)
    log = ROOT / 'work' / 'native-client' / ('module-%s-trial.log' % args.module)
    with log.open('w') as stream:
        subprocess.run([sys.executable, str(ROOT / 'roc.py'), 'rebuild', CLIENT, 'module', spec_path.stem, '--no-notify'],
                       cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
    live = json.loads((out / spec['name'] / 'report.json').read_text())
    result = json.loads((out / name / 'report.json').read_text())
    before, after = set(live.get('owned_addrs', [])), set(result.get('owned_addrs', []))
    print(json.dumps({'module': spec['name'], 'live': len(before), 'trial': len(after), 'gain': len(after - before),
                      'loss': sorted(before - after), 'linked': result.get('linked'), 'test_exit': result.get('test_exit'),
                      'compile_errors': {k: str(v)[:160] for k, v in (result.get('compile_errors') or {}).items()},
                      'log': log.relative_to(ROOT).as_posix()}, indent=1))


if __name__ == '__main__':
    main()

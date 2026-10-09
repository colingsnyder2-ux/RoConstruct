"""Bounded, resumable expansion of exact-evidenced library/class searches."""
import argparse
import json
import sqlite3
import time
from collections import defaultdict, deque
from pathlib import Path

from roc import clients, libs, setup, worker
from roc.batch_fingerprint import ROOT, REF, key, pending_batches, source_class, source_family, unit_class, unit_family


def flag_variants(source):
    flags = source.splitlines()[2].split(': ', 1)[1]
    keep = [flag for flag in flags.split()
            if flag not in {'/O1', '/O2', '/Ox', '/Od', '/Ob0', '/Ob1', '/Ob2', '/Oy', '/Oy-'}]
    yield flags
    for optimization in ('/O2 /Ob0 /Oy-', '/O2 /Ob1 /Oy-', '/O2 /Ob2 /Oy-',
                         '/O2 /Ob1 /Oy', '/O1 /Ob1 /Oy-', '/Ox /Ob2 /Oy-',
                         '/O2 /Ob2 /Oy', '/Od /Ob0 /Oy-'):
        candidate = ' '.join([*keep, optimization])
        if candidate != flags:
            yield candidate


def local_versions(families):
    """No downloads: index installed recipes, excluding Wild Magic's local-only source."""
    versions = defaultdict(list)
    for name, recipe in sorted(libs.RECIPES.items()):
        family = source_family('// roc-lib: ' + name + ' file.cpp')
        folder = libs.LIBS / recipe['src'] if recipe.get('src') else None
        if (family not in families or family == 'wildmagic' or recipe.get('archive') is True
                or folder is None or not folder.is_dir()):
            continue
        for path in libs.files_of(recipe, folder):
            relative = Path(path).as_posix()
            if not (folder / relative).is_file():
                continue
            token = source_class('// roc-lib: ' + name + ' ' + relative)
            if token:
                versions[family, token].append((name, relative))
    return versions


def plan(db, min_score=85, targets=8):
    evidence, labels = defaultdict(set), defaultdict(set)
    for client, unit, text in db.execute('SELECT client,unit,source FROM funcs WHERE score=100 AND source IS NOT NULL'):
        found = REF.search(text)
        if not unit or not found:
            continue
        source = found.group(1)
        family = source_family(source)
        structural = unit_family(unit)
        if family == 'wildmagic' or (structural and structural != family):
            continue
        if structural and source_class(source) != unit_class(unit):
            continue
        evidence[family, unit_class(unit)].add(source)
        labels[client, unit].add(family)
    groups = defaultdict(list)
    for client, addr, unit, score, text in db.execute(
            'SELECT client,addr,unit,score,source FROM funcs WHERE score>=? AND score<100 ORDER BY score DESC,client,addr',
            (min_score,)):
        family = unit_family(unit or '')
        if family is None:
            proven = labels.get((client, unit), set())
            family = next(iter(proven)) if len(proven) == 1 else None
        if not family or (family, unit_class(unit)) not in evidence:
            continue
        found = REF.search(text or '')
        groups[client, family, unit_class(unit)].append((addr, score, found.group(1) if found else None))
    versions = local_versions({family for _, family, _ in groups})
    have, registry = set(setup.compilers()), clients.load()
    # Round-robin families so a pilot is not consumed by one large XTP class.
    queues = defaultdict(deque)
    for (client, family, token), rows in sorted(groups.items(), key=lambda item: -item[1][0][1]):
        seeds = sorted(evidence[family, token])
        recipes = []
        for source in seeds:
            name, path = source.splitlines()[-1].split(': ', 1)[1].split(' ', 1)
            recipes.append((name, path, source))
        for name, path in versions.get((family, token), []):
            if not any(name == n and path == p for n, p, _ in recipes):
                recipes.append((name, path, seeds[0]))
        per_recipe = []
        for name, path, seed in recipes:
            recipe = libs.RECIPES.get(name)
            if not recipe or recipe.get('archive') is True:
                continue
            language = seed.splitlines()[0].split(': ', 1)[1]
            if language not in recipe.get('langs', []):
                continue
            original = int(seed.splitlines()[1].split(': ', 1)[1])
            builds = [registry.get(client, {}).get('compiler_build'), original, *sorted(have)]
            builds = list(dict.fromkeys(b for b in builds if b in have and b in recipe.get('builds', libs.BUILDS)))
            variants = deque()
            for flags in dict.fromkeys(flag_variants(seed)):
                for build in builds:
                    candidate = libs.source_for(name, path, language, build, flags).strip()
                    if candidate not in variants:
                        variants.append(candidate)
            per_recipe.append(variants)
        candidates = []
        seen = set()
        # Try one candidate per installed version before exhausting a version's flag grid.
        while any(per_recipe):
            for variants in per_recipe:
                if variants:
                    candidate = variants.popleft()
                    if candidate not in seen:
                        seen.add(candidate)
                        candidates.append(candidate)
        for start in range(0, len(rows), targets):
            group = rows[start:start + targets]
            # All variants for this group run before expanding to lower-priority targets.
            for candidate in candidates:
                addrs = [addr for addr, _, previous in group if previous != candidate]
                if addrs:
                    queues[family].append((client, candidate, addrs))
    while any(queues.values()):
        for family in sorted(queues):
            if queues[family]:
                yield queues[family].popleft()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--max-batches', type=int, default=24, help='pilot bound; 0 means all pending batches')
    parser.add_argument('--min-score', type=int, default=85)
    parser.add_argument('--targets', type=int, default=8)
    parser.add_argument('--server', default='http://127.0.0.1:8765')
    parser.add_argument('--dry-run', action='store_true')
    args = parser.parse_args()
    if not 0 <= args.min_score <= 99 or args.targets < 1 or args.max_batches < 0:
        parser.error('min-score must be 0..99; targets positive; max-batches nonnegative')
    state_path = ROOT / 'work/deep-fingerprint.json'
    state = json.loads(state_path.read_text()) if state_path.exists() else {}
    # Reuse fast-pass pair checkpoints without modifying their live state files.
    prior = {marker: set(addrs) for marker, addrs in state.get('checked', {}).items()}
    for path in (ROOT / 'work').glob('batch-fingerprint*.json'):
        for marker, addrs in json.loads(path.read_text()).get('checked', {}).items():
            prior.setdefault(marker, set()).update(addrs)
    state['checked'] = {marker: sorted(addrs) for marker, addrs in prior.items()}
    db = sqlite3.connect('file:%s?mode=ro' % (ROOT / 'work/server.db').as_posix(), uri=True)
    todo = list(pending_batches(plan(db, args.min_score, args.targets), state))
    db.close()
    print('pending', len(todo), 'batches', flush=True)
    if args.max_batches:
        todo = todo[:args.max_batches]
    print('selected', len(todo), 'batches', sum(len(item[2]) for item, _ in todo), 'source/target checks', flush=True)
    if args.dry_run:
        return
    settings = worker.load_settings()
    api = worker.Api(args.server, settings.get('token'))
    started, checks, gains, exact = time.monotonic(), 0, 0, 0
    improved_functions = set()
    by_family = {}
    done = set(state.get('done', []))
    checked = {marker: set(addrs) for marker, addrs in state.get('checked', {}).items()}
    for item, marker in todo:
        client, source, addrs = item
        tick = time.monotonic()
        print('checking', client, source_family(source), len(addrs), source.splitlines()[1:3], source.splitlines()[-1], flush=True)
        try:
            result = api.call('/v1/submit-batch', {'user': settings['user'], 'worker': 'deep-fingerprint',
                              'model': 'roc deep fingerprint', 'client': client, 'source': source, 'addrs': addrs}, timeout=180)
        except worker.ApiFailure as error:
            print('ERROR', str(error), 'batch remains pending', flush=True)
            continue
        rows = result['results']
        if not result.get('verified'):
            raise RuntimeError('Deep pass requires server-verified scoring')
        # A partial response must not permanently skip targets the server never checked.
        returned = {row['addr'] for row in rows} & set(addrs)
        checked.setdefault(key(client, source, []), set()).update(returned)
        if returned == set(addrs):
            done.add(marker)
        changed = [row for row in rows if row['improved']]
        checks += len(returned)
        gains += len(changed)
        improved_functions.update((client, row['addr']) for row in changed)
        exact += sum(row['stored'] == 100 for row in changed)
        family_stats = by_family.setdefault(source_family(source), {'checks': 0, 'gains': 0, 'exact': 0, 'seconds': 0})
        family_stats['checks'] += len(returned)
        family_stats['gains'] += len(changed)
        family_stats['exact'] += sum(row['stored'] == 100 for row in changed)
        family_stats['seconds'] += time.monotonic() - tick
        print('result', 'checks', len(returned), 'improved', len(changed),
              'exact', sum(row['stored'] == 100 for row in changed), 'seconds', round(time.monotonic() - tick, 2), flush=True)
        state.update(done=sorted(done), checked={k: sorted(v) for k, v in checked.items()},
                     last_run={'checks': checks, 'improvement_events': gains,
                               'unique_improved': len(improved_functions), 'new_exact': exact,
                               'seconds': round(time.monotonic() - started, 2), 'families': by_family})
        temporary = state_path.with_suffix('.json.tmp')
        temporary.write_text(json.dumps(state, separators=(',', ':')))
        temporary.replace(state_path)
    elapsed = time.monotonic() - started
    print('SUMMARY', 'checks', checks, 'improvement_events', gains, 'unique_improved', len(improved_functions), 'new_exact', exact,
          'seconds', round(elapsed, 2), 'events_per_hour', round(gains * 3600 / max(elapsed, 0.001), 2), flush=True)


if __name__ == '__main__':
    main()

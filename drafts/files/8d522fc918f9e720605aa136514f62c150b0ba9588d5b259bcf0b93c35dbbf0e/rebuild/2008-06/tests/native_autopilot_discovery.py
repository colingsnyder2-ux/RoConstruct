"""Inventory configured libraries and suggest review-only native source checks."""
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re


def _read_json(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def _tracked_sources(root):
    rows = sorted((root / 'rebuild/2008-06/native-classes').glob('*.cpp'))
    sources = defaultdict(list)
    for row in rows:
        sources[Path(row).stem.casefold()].append(Path(row).resolve())
    return dict(sources)


def _owner(symbol):
    match = re.match(r'^\?[^@?$]+@([^@?$]+)(?:@([^@?$]+))?@@', symbol)
    return (match.group(1), match.group(2) or '') if match else ('', '')


def _source_candidates(source_files, recipe_path, symbol):
    stem = Path(recipe_path.replace('\\', '/')).stem
    owner, namespace = _owner(symbol)
    names = [(stem, 0)]
    if namespace.casefold() == 'g3d':
        names.extend((('G3D' + owner, 1), ('G3D' + owner + '_' + stem, 2), ('G3D' + stem, 3)))
    elif namespace.casefold() == 'ogre':
        names.extend(((owner + '2008', 1), ('Ogre' + owner, 1), ('Ogre' + stem, 2)))
    elif owner:
        names.append((owner, 1))
    names.extend((prefix + stem, 4) for prefix in ('G3D', 'Png5', 'Zlib', 'Lua', 'Jpeg', 'Boost', 'Rak'))
    matches = {}
    for name, rank in names:
        for path in source_files.get(name.casefold(), []):
            previous = matches.get(path)
            if previous is None or rank < previous:
                matches[path] = rank
    if not matches:
        return []
    best = min(matches.values())
    return sorted((path for path, rank in matches.items() if rank == best), key=lambda p: str(p).casefold())


def _add_candidate(candidates, source, address, symbol, provenance):
    key = (address, symbol)
    current = candidates[source].get(key)
    if current is None:
        candidates[source][key] = {
            'addr': address, 'symbol': symbol, 'review_only': True,
            'library': provenance.get('recipe', 'G3D' if 'G3D' in source else 'unclassified'),
            'provenance': [provenance],
        }
    elif provenance not in current['provenance']:
        current['provenance'].append(provenance)


def _source_by_path(source_files, path):
    resolved = path.resolve()
    return [candidate for paths in source_files.values() for candidate in paths
            if candidate == resolved]


def _inactive(root):
    from roc.integration_site import inactive_code
    return inactive_code(root)


def discover(root):
    """Return normalized, deduped candidate jobs; none carries identity proof."""
    root = Path(root).resolve()
    data_path = root / 'docs/data/2008-06.json'
    data = _read_json(data_path)
    data_sha256 = hashlib.sha256(data_path.read_bytes()).hexdigest()
    source_files = _tracked_sources(root)
    inactive = _inactive(root)

    from roc import libs
    candidates = defaultdict(dict)
    issues = []
    inventory = {}
    for row in data.get('funcs', []):
        if not isinstance(row, list) or len(row) < 6:
            continue
        recipe = row[5]
        if not isinstance(recipe, list) or len(recipe) < 1 or not isinstance(recipe[0], str):
            continue
        recipe_name = recipe[0]
        if recipe_name not in libs.RECIPES:
            continue
        library = inventory.setdefault(recipe_name, {'total': 0, 'inactive_exact': 0, 'candidates': 0, 'source_unmapped': 0})
        library['total'] += 1
        if type(row[0]) is int:
            prior = inactive.get(f'{row[0]:08x}')
            if prior and len(prior) > 1 and prior[1] is True:
                library['inactive_exact'] += 1
                continue
        if type(row[0]) is not int or row[0] < 0 or row[0] > 0xffffffff:
            issues.append({'reason': 'malformed_configured_target', 'recipe': recipe_name, 'row': row[:6]})
            continue
        if len(recipe) < 3 or not isinstance(recipe[1], str) or not isinstance(recipe[2], str):
            issues.append({'address': f'{row[0]:08x}', 'reason': 'symbol_not_recorded', 'recipe': recipe_name,
                           'recipe_source': recipe[1] if len(recipe) > 1 else None})
            continue
        recipe_path, symbol = recipe[1:3]
        if not symbol:
            issues.append({'address': f'{row[0]:08x}', 'reason': 'missing_symbol', 'recipe': recipe_name})
            continue
        address = f'{row[0]:08x}'
        size, score = row[1], row[2]
        matches = _source_candidates(source_files, recipe_path, symbol)
        if len(matches) != 1:
            library['source_unmapped'] += 1
            issues.append({
                'address': address,
                'library': recipe_name,
                'symbol': symbol,
                'reason': 'source_unmapped' if not matches else 'source_ambiguous',
                'recipe': recipe_name,
                'recipe_source': recipe_path,
                'candidate_sources': [str(path) for path in matches],
            })
            continue
        source = str(matches[0])
        library['candidates'] += 1
        provenance = {
            'dataset': 'docs/data/2008-06.json',
            'dataset_sha256': data_sha256,
            'recipe': recipe_name,
            'recipe_source': recipe_path,
            'unit_index': row[3],
            'unit': data.get('units', [])[row[3]] if type(row[3]) is int and 0 <= row[3] < len(data.get('units', [])) else None,
            'size': size,
            'score': score,
            'source_catalog': 'local rebuild/2008-06/native-classes source path',
        }
        _add_candidate(candidates, source, address, symbol, provenance)

    # Explicit plans preserve previously reviewed target/source pairings; still review-only here.
    plans = sorted((root / 'rebuild/2008-06/tests').glob('*batch*plan.json'), key=lambda p: p.name.casefold())
    for plan_path in plans:
        try:
            plan = _read_json(plan_path)
        except (OSError, ValueError) as error:
            issues.append({'reason': 'invalid_batch_manifest', 'manifest': str(plan_path), 'detail': str(error)})
            continue
        for job in plan.get('jobs', []) if isinstance(plan, dict) else []:
            raw_source = job.get('source') if isinstance(job, dict) else None
            source_path = Path(raw_source) if isinstance(raw_source, str) else Path()
            source_path = source_path if source_path.is_absolute() else root / 'rebuild/2008-06' / source_path
            tracked = _source_by_path(source_files, source_path)
            if len(tracked) != 1:
                issues.append({'reason': 'manifest_source_untracked', 'manifest': str(plan_path),
                               'source': str(source_path), 'candidate_sources': [str(p) for p in tracked]})
                continue
            source = str(tracked[0])
            for check in job.get('checks', []) if isinstance(job, dict) else []:
                try:
                    address = f'{int(check["addr"], 16):08x}'
                    symbol = check['symbol']
                except (KeyError, TypeError, ValueError):
                    issues.append({'reason': 'malformed_manifest_check', 'manifest': str(plan_path),
                                   'source': source, 'check': check})
                    continue
                if not isinstance(symbol, str) or not symbol:
                    issues.append({'address': address, 'reason': 'missing_symbol', 'manifest': str(plan_path)})
                    continue
                inactive_row = inactive.get(address)
                if inactive_row and len(inactive_row) > 1 and inactive_row[1] is True:
                    continue
                _add_candidate(candidates, source, address, symbol, {
                    'manifest': str(plan_path.relative_to(root)),
                    'manifest_source': raw_source,
                })

    by_address = defaultdict(list)
    for source, checks in candidates.items():
        for (address, symbol), check in checks.items():
            by_address[address].append((source, symbol, check))
    conflicts = {address for address, rows in by_address.items()
                 if len({(source.casefold(), symbol) for source, symbol, _ in rows}) > 1}
    for address in sorted(conflicts):
        rows = by_address[address]
        issues.append({
            'address': address,
            'reason': 'identity_conflict',
            'candidates': [{'source': source, 'symbol': symbol} for source, symbol, _ in rows],
        })
        for source, symbol, _ in rows:
            del candidates[source][(address, symbol)]

    jobs = []
    for source in sorted(candidates, key=str.casefold):
        checks = sorted(candidates[source].values(), key=lambda c: (c['addr'], c['symbol']))
        if checks:
            jobs.append({'source': source, 'checks': checks})
    issues.sort(key=lambda row: (row.get('address', ''), row['reason'], json.dumps(row, sort_keys=True)))
    return {'jobs': jobs, 'issues': issues, 'inventory': inventory}

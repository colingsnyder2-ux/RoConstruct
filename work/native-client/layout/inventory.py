"""Generate the read-only Phase 0 source-layout inventory."""
import argparse
import os
import re
import subprocess
from collections import Counter, defaultdict
from pathlib import PureWindowsPath

from common import HERE, NC, ROOT, load, read, relative, save, sha, sources
from native_lint import strip_comments, survey
import layout_census
import layout_ios
import json
from pathlib import Path

CHOICES = {}
OPEN_PATHS = defaultdict(list)
OPEN_OWNER_DEFS = defaultdict(list)
OPEN_OWNER_PATHS = defaultdict(set)
PATH_EXPRESSION = re.compile(r'native-(?:classes|headers|world)[^\s"\'),}]*')


# Native file names that are recovery-unit labels, not original names.
IOS_VENDORED = ('client/boost', 'client/rendering/ogre-', 'client/rendering/mesa', 'client/rendering/sdl', 'client/network/raknet/')
LIBRARY_NAME = re.compile(r'(?:XTP|Mfc|Atl)')  # at the start of a stem; see the check in run()
CURATED = {k: v for k, v in load(HERE / 'curated-paths.json').items() if not k.startswith('_')} \
    if (HERE / 'curated-paths.json').exists() else {}   # stem -> [original path, evidence]
RECOVERY_NAME = re.compile(r'2008|AppUnit|AppLeaves|Inferred_|roc_|Native|Mined|vendor_i', re.I)


def validate_refresh(mapping, reverse):
    if any(row.get('approved') for row in mapping.values()) or reverse:
        raise ValueError('reviewed mappings or move ledger exist; preserve them before regenerating')


def target_address_evidence(addresses, functions):
    targets = defaultdict(list)
    for address in sorted(addresses):
        target = functions.get(address, {}).get('target_path')
        if target:
            targets[target].append(address)
    return dict(targets)


def target_review_flags(targets):
    normalized = {target.casefold() for target in targets}
    return len(normalized) > 1, len(targets) > len(normalized)


def mark_ambiguous_names(rows):
    counts = Counter(row.get('name') for row in rows.values() if row.get('name'))
    for row in rows.values():
        count = counts.get(row.get('name'), 0)
        row['requires_identity_review'] = count > 1
        if count > 1:
            row['duplicate_target_name_count'] = count


def possible_related_units(rows):
    groups = defaultdict(lambda: defaultdict(lambda: {'evidence': set(), 'addresses': set()}))
    for path, row in rows.items():
        if row.get('original_path'):
            groups[row['original_path'].replace('\\', '/').lower()][path]['evidence'].add('filename-map')
        for target in row.get('function_target_candidates', []):
            member = groups[target.replace('\\', '/').lower()][path]
            member['evidence'].add('address-heuristic')
            member['addresses'].update(row.get('candidate_address_evidence', {}).get(target, []))
    return {target: [{'file': path, 'evidence': sorted(data['evidence']), 'addresses': sorted(data['addresses'])}
                     for path, data in sorted(members.items())]
            for target, members in sorted(groups.items()) if len(members) > 1}


def original_path(value):
    path = value.replace('\\', '/').lower()
    pos = path.find('client/')
    return path[pos:] if pos >= 0 else None


def openrbx_owner_definitions(text):
    code = strip_comments(text)
    pattern = r'(?m)^[ \t]*(?:[^\n;{}]*?\s+)?([A-Za-z_]\w*)::(~?[A-Za-z_]\w*)\s*\([^;{}]*\)\s*(?:const\s*)?(?::[^;{}]*)?\{'
    owners = defaultdict(list)
    for match in re.finditer(pattern, code):
        owners[match[1], match[2]].append(code.count('\n', 0, match.start(1)) + 1)
    return dict(owners)


def decorated_method(name, owner):
    if name.startswith('??0'):
        return owner
    if name.startswith('??1'):
        return '~' + owner
    match = re.match(r'^\?([A-Za-z_]\w*)@', name)
    return match[1] if match else None


def mapping_inputs():
    files = {}
    for folder, dirs, names in os.walk(ROOT / 'tools/openrbx/Client'):
        dirs[:] = [d for d in dirs if d not in ('.git', 'out', 'build', 'accepted')]
        for name in names:
            if name.startswith('roc_') or PureWindowsPath(name).suffix.lower() not in ('.cpp', '.h', '.c', '.hpp', '.inl'):
                continue
            path = ROOT / folder / name
            files[path.relative_to(ROOT).as_posix()] = sha(path)
    identities, lines = NC / 'unnamed-identities.json', HERE / 'pdb-lines.json'
    return {'openrbx_files': files, 'unnamed_identities_sha256': sha(identities) if identities.exists() else None,
            'pdb_lines_sha256': sha(lines) if lines.exists() else None}


def path_index():
    CHOICES.clear()
    OPEN_PATHS.clear()
    OPEN_OWNER_DEFS.clear()
    OPEN_OWNER_PATHS.clear()
    paths = [original_path(s) for s in read(NC / 'webservice-pdb-source-paths.txt').splitlines()]
    paths = sorted(set(p for p in paths if p))
    case = defaultdict(list)
    for folder, dirs, files in os.walk(ROOT / 'tools/openrbx/Client'):
        dirs[:] = [d for d in dirs if d not in ('.git', 'out', 'build', 'accepted')]
        for filename in files:
            if filename.startswith('roc_') or PureWindowsPath(filename).suffix.lower() not in ('.cpp', '.h', '.c', '.hpp', '.inl'):
                continue
            p = ROOT / folder / filename
            name = relative(p).split('tools/openrbx/', 1)[1]
            case[name.lower()].append(name)
            key = PureWindowsPath(name.lower())
            OPEN_PATHS[key.stem, key.suffix].append(name.lower())
            if key.suffix == '.cpp' and not any(part in ('test', 'tests', 'example', 'examples', 'sample', 'samples')
                                                for part in name.lower().split('/')[:-1]):
                for (owner, method), lines in openrbx_owner_definitions(read(p)).items():
                    OPEN_OWNER_DEFS[owner, method].extend((name.lower(), line) for line in lines)
                    OPEN_OWNER_PATHS[owner].add(name.lower())
    bystem = defaultdict(list)
    for path in paths:
        bystem[PureWindowsPath(path).stem].append(path)
    return paths, case, bystem


def choose_path(stem, suffix, case, bystem):
    key = stem.split('<', 1)[0].split('::')[-1].lower()
    if (key, suffix) in CHOICES:
        return dict(CHOICES[key, suffix])
    matches = [p for p in bystem.get(key, []) if p.endswith(suffix)]
    evidence = 'pdb'
    if not matches:
        matches = sorted(set(OPEN_PATHS.get((key, suffix), [])))
        evidence = 'openrbx'
    if evidence == 'openrbx' and len(matches) == 1 and any(
            part in ('test', 'tests', 'example', 'examples', 'sample', 'samples')
            for part in matches[0].lower().split('/')[:-1]):
        result = {'target_path': None, 'evidence': None, 'case_source': None,
                  'inferred_path': True, 'candidates': matches,
                  'reason': 'only OpenRBX test or example basename; production TU unproven'}
        CHOICES[key, suffix] = result
        return dict(result)
    if len(matches) == 1:
        target = matches[0]
        spelling = case.get(target, [])
        cased = target.rsplit('/', 1)[0] + '/' + spelling[0].rsplit('/', 1)[-1] if len(spelling) == 1 else target
        result = {'target_path': cased,
                'evidence': evidence, 'case_source': 'openrbx' if len(spelling) == 1 else 'pdb-lowercase',
                'inferred_path': False, 'association': 'basename-only; review TU membership'}
        CHOICES[key, suffix] = result
        return dict(result)
    result = {'target_path': None, 'evidence': None, 'case_source': None,
            'inferred_path': True, 'candidates': matches,
            'reason': 'ambiguous basename' if matches else 'no original path evidence'}
    CHOICES[key, suffix] = result
    return dict(result)


def protected_consumer(name):
    filename = name.rsplit('/', 1)[-1]
    return (name.startswith(('work/', 'tools/', 'clients/', 'roc/', 'rebuild/2008-06/p6/'))
            or '/_archive/' in '/' + name or name in ('roc.py',
                'docs/integration.json', 'docs/source-links.json', 'docs/progress.json',
                'docs/history.json', 'docs/rebuild-progress.json')
            or filename.startswith(('identity_unlock_', 'native_transplant_', 'unnamed-identities'))
            or filename in ('native_llm.py', 'native_identity_evidence.py', 'native_template_gate.py',
                            'server.py', 'identity-registry.json'))


def consumers():
    # Search in Git first instead of opening every unrelated tracked file in Python.
    found = subprocess.run(['git', 'grep', '-l', '-z', '-I', '-e', 'native-classes',
                            '-e', 'native-headers', '-e', 'native-world', '--',
                            '*.py', '*.json', '*.md', '*.jsonl', '*.cmd', '*.ps1',
                            '*.cpp', '*.h', '*.hpp', '*.c', '*.inl', '*.vcproj',
                            '*.sln', '*.txt', '*.js', '*.html', '*.yml', '*.yaml'],
                           cwd=ROOT, capture_output=True, check=False)
    if found.returncode not in (0, 1):
        raise RuntimeError(found.stderr.decode(errors='replace'))
    tracked = found.stdout.decode().split('\0')
    paths = {ROOT / p for p in tracked if p and not p.startswith('work/native-client/layout/')}
    paths.update(sources())
    # Ignored receipts and website inputs can live below nested work directories.
    for directory in (NC, ROOT / 'work/2008-06', ROOT / 'patches', ROOT / 'docs',
                      ROOT / 'rebuild/2008-06/tests', ROOT / 'rebuild/2008-06/p6',
                      ROOT / 'rebuild/2008-06/patches', ROOT / 'rebuild/2008-06/native-world'):
        if directory.exists():
            paths.update(p for p in directory.rglob('*') if p.is_file()
                         and p.suffix.lower() in ('.py', '.json', '.jsonl', '.md', '.txt', '.html', '.js', '.yml', '.yaml',
                                                  '.cpp', '.c', '.h', '.hpp', '.inl', '.log')
                         and not p.is_relative_to(NC / 'layout'))
    paths.add(ROOT / 'work/leases-cache.json')
    rows = []
    for path in sorted(paths):
        if not path.is_file():
            continue
        data = read(path)
        hits = {}
        for number, line in enumerate(data.splitlines(), 1):
            for match in re.finditer(r'native-(?:classes|headers|world)', line):
                context = line[max(0, match.start() - 90):match.end() + 180]
                pathtext = PATH_EXPRESSION.match(line, match.start())[0]
                kind = 'glob' if any(c in pathtext for c in ('*', '?', '[')) or re.search(r'\b(?:rglob|glob)\s*\(', context) else (
                    'derived' if any(c in context for c in (' / ', 'join', 'NATIVE_DIR', 'startswith')) else 'literal')
                key = kind, pathtext
                row = hits.setdefault(key, {'line': number, 'kind': kind, 'context': context,
                                            'path_expression': pathtext, 'count': 0,
                                            'rewrite': 'owner review: remap exact paths; preserve selection and glob coverage'})
                row['count'] += 1
        if hits:
            name = relative(path)
            protected = protected_consumer(name)
            rows.append({'file': name, 'sha256': sha(path), 'protected': protected, 'references': list(hits.values())})
    return rows


def functions(case, bystem):
    pdb = load(HERE / 'pdb-lines.json') if (HERE / 'pdb-lines.json').exists() else {'functions': []}
    named = defaultdict(list)
    for proc in pdb['functions']:
        for symbol in proc.get('decorated_names', pdb.get('publics', {}).get(proc.get('public_key'), [])):
            if proc['file']:
                named[symbol].append(proc)
    registry = load(ROOT / 'work/2008-06/identity-registry.json')
    identities = NC / 'unnamed-identities.json'
    extra = load(identities) if identities.exists() else {}
    result = {}
    for addr, entry in registry.items():
        if entry.get('kind') != 'code':
            continue
        row = dict(entry)
        if row.get('placeholder') and addr in extra:
            row.update(extra[addr])
        name = row.get('name')
        matches = named.get(name, [])
        locations = sorted({(original_path(p['file']), p['line']) for p in matches if original_path(p['file'])})
        if len(locations) == 1:
            target, line = locations[0]
            source_files = sorted({original_path(f) for p in matches for f in p.get('source_files', [])
                                   if original_path(f)})
            result[addr] = {'name': name, 'target_path': target, 'line': line, 'evidence': 'pdb',
                            'inferred_path': False, 'donor_modules': sorted({p['module'] for p in matches}),
                            'donor_source_files': source_files,
                            'requires_inline_review': len(source_files) > 1 or target.endswith(('.h', '.hpp', '.inl')),
                            'association': 'same decorated name in 2007 donor; target TU still unproved'}
        else:
            choice = choose_path(row.get('owner_class') or '', '.cpp', case, bystem)
            if not choice['target_path'] and not choice['candidates'] and row.get('owner_class'):
                owner = row['owner_class'].split('<', 1)[0].split('::')[-1]
                method = decorated_method(name or '', owner)
                definitions = OPEN_OWNER_DEFS.get((owner, method), []) if method else []
                candidates = sorted({path for path, _ in definitions})
                if len(candidates) == 1:
                    target = candidates[0]
                    spelling = case.get(target, [])
                    cased = target.rsplit('/', 1)[0] + '/' + spelling[0].rsplit('/', 1)[-1] if len(spelling) == 1 else target
                    choice.update(target_path=cased, evidence='openrbx', inferred_path=True,
                                  case_source='openrbx' if len(spelling) == 1 else 'lowercase',
                                  openrbx_definition_lines=sorted({line for path, line in definitions if path == target}),
                                  association='owner and method name match; signature and 2008 TU unproved')
                elif candidates:
                    choice.update(candidates=candidates, reason='owner class occurs in multiple OpenRBX files')
                elif OPEN_OWNER_PATHS.get(owner):
                    choice.update(candidates=sorted(OPEN_OWNER_PATHS[owner]),
                                  reason='owner found but method name absent or unsupported in OpenRBX')
            if not choice['target_path'] and not choice['candidates'] and row.get('owner_class'):
                header = choose_path(row['owner_class'], '.h', case, bystem)
                if header['target_path']:
                    target = header['target_path'].replace('/include/', '/').rsplit('.', 1)[0] + '.cpp'
                    choice.update(target_path=target, evidence='class-rule', case_source=header['case_source'],
                                  inferred_path=True, header_evidence=header['target_path'],
                                  association='owner header area; source TU inferred')
            if not choice['target_path'] and row.get('owner_class') and not choice['candidates']:
                leaf = row['owner_class'].split('<', 1)[0].split('::')[-1]
                if re.fullmatch(r'[A-Za-z_]\w*', leaf):
                    choice.update(target_path='client/app/unclassified/' + leaf + '.cpp',
                                  evidence='class-rule', case_source='owner_class', inferred_path=True)
            if choice['target_path']:
                choice['inferred_path'] = True
                choice.setdefault('association', 'owner-class fallback; function TU unproved')
            result[addr] = {'name': name, **choice, 'line': None,
                            'donor_candidates': [{'file': p, 'line': l} for p, l in locations]}
    mark_ambiguous_names(result)
    return result


def run():
    mapping = HERE / 'source-layout-map.json'
    reverse = HERE / 'reverse-map.json'
    validate_refresh(load(mapping) if mapping.exists() else {}, load(reverse) if reverse.exists() else {})
    mapping_before = mapping_inputs()
    print('Indexing original paths', flush=True)
    registry_before = sha(ROOT / 'work/2008-06/identity-registry.json')
    paths, case, bystem = path_index()
    print('Joining function identities', flush=True)
    funcs = functions(case, bystem)
    order = defaultdict(list)
    for address, row in funcs.items():
        if row.get('line') is not None:
            order[row['target_path']].append({'address': address, 'line': row['line']})
    line_order = {
        'donor_version': '2007-12', 'target_version': '2008-06',
        'files': {path: {'functions_by_target_address': sorted(rows, key=lambda r: int(r['address'], 16)),
                         'adjacent_line_inversions': sum(a['line'] > b['line'] for a, b in zip(
                             sorted(rows, key=lambda r: int(r['address'], 16)),
                             sorted(rows, key=lambda r: int(r['address'], 16))[1:]))}
                  for path, rows in order.items()},
        'limitations': ['Header inlines, ICF and cross-version changes can reorder functions.',
                        'Line order is evidence only; it does not prove target linker order.']}
    print('Mapping source files', flush=True)
    rows, groups = {}, defaultdict(list)
    census = layout_census.targets(funcs, case)
    census_jobs = json.loads(layout_census.CHECKS.read_text(encoding='utf-8'))['jobs']
    ios = {relative(Path(src)): v for src, v in layout_ios.targets(census_jobs).items()}   # iOS Dec 2013 debug-map winners
    areas = {}                                    # include area name -> its original folder, when unique
    for original in paths:
        folder, _, name = original.rpartition('/')
        if '/include/' in original and name.endswith(('.h', '.hpp', '.inl')):
            areas.setdefault(folder.rsplit('/', 1)[-1], set()).add(folder)
    areas = {area: next(iter(folders)) for area, folders in areas.items() if len(folders) == 1}
    for path in sources():
        text = read(path)
        choice = choose_path(path.stem, path.suffix.lower(), case, bystem)
        addresses = set(a.lower() for a in re.findall(r'\b(?:0x)?(00[4-9a-fA-F][0-9a-fA-F]{5})\b', text))
        address_evidence = target_address_evidence(addresses, funcs)
        targets = set(address_evidence)
        split_review, case_review = target_review_flags(targets)
        if len(targets) == 1 and path.suffix == '.cpp' and choice['target_path'] is None and next(iter(targets)).endswith('.cpp'):
            target = next(iter(targets))
            choice.update(target_path=target, evidence='class-rule', case_source='function-owner',
                          inferred_path=True, association='address-comment heuristic; review required')
        vote = census.get(relative(path))
        if vote and 'conflict' in vote and choice.get('evidence') != 'pdb':
            # PDB-named and OpenRBX-named functions of this unit point at different files: nobody guesses.
            choice.update(target_path=None, evidence=None, census_conflict=vote['conflict'],
                          reason='census function evidence contradicts itself')
        elif vote and choice.get('evidence') != 'pdb':
            # Definitions beat lexical address mentions: the census says which functions this unit emits.
            choice.update(target_path=vote['target'], case_source=vote['case_source'],
                          evidence={'pdb': 'census', 'openrbx': 'census-openrbx', 'shared': 'census-shared'}[vote['kind']],
                          inferred_path=True, census_votes=vote['votes'], census_kinds=vote['agreeing_kinds'],
                          association='census: every uniquely owned %s-named function of this unit is in this original file'
                                      % {'pdb': 'PDB', 'openrbx': 'OpenRBX', 'shared': 'PDB (shared with one other piece)'}[vote['kind']])
            split_review = case_review = False
        curated = CURATED.get(path.stem)
        if curated and path.suffix == '.cpp' and choice.get('evidence') != 'pdb':
            # Hand-curated folder (curated-paths.json): inferred, kept under inferred/, never Authentic.
            choice.update(target_path=curated[0], evidence='class-rule', case_source='openrbx', inferred_path=True,
                          census_conflict=None, reason='', association='curated: ' + curated[1])
            split_review = case_review = False
        win = ios.get(relative(path))
        if win and path.suffix == '.cpp':
            if not choice['target_path'] and not win['target'].lower().startswith(IOS_VENDORED):
                # Same-named functions of the iOS Dec 2013 build came from this file: an inferred path, never Authentic.
                choice.update(target_path=win['target'], evidence='ios-debug-map', case_source='ios', inferred_path=True,
                              census_conflict=None, reason='', ios_votes=win['votes'],
                              association='iOS 2013 debug map: %d same-named functions (%d%% of its matches) are in %s'
                                          % (win['votes'], round(100 * win['share']), win['target']))
                split_review = case_review = False
            elif choice['target_path'] and (choice['target_path'] or '').lower().removeprefix('rebuild/2008-06/') != win['target'].lower():
                choice['ios_differs'] = win['target']      # 2013 may have moved the file; kept for review, path unchanged
        # A PDB file-name match checked against what the unit defines. Agreement outweighs the
        # lexical review flags below (they come from addresses mentioned in comments); a census
        # vote for another file is a reason to look, whatever the comments say.
        named = (choice['target_path'] or '').replace('\\', '/').lower() if choice.get('evidence') == 'pdb' else ''
        confirmed = bool(named and vote and vote.get('target', '').lower() == named)
        disputed = bool(named and vote and not confirmed)
        area = areas.get(path.parent.name.lower()) if path.parent.parent.name == 'native-headers' else None
        if (not choice['target_path'] and not choice.get('census_conflict') and area
                and path.suffix.lower() in ('.h', '.hpp', '.inl') and not RECOVERY_NAME.search(path.stem)):
            # No path evidence for this header itself, but its folder is one of the original include
            # areas. A guess, kept apart under inferred/: the file name is the native one.
            choice.update(target_path=area + '/' + path.name, evidence='area-folder', case_source='native',
                          inferred_path=True, association='native-headers folder matches an original include area')
            split_review = case_review = False
        # The flags below read addresses mentioned in the file's text. That is the evidence only for a
        # source placed by its file name or by those mentions and not confirmed by the census. A
        # header's path does not depend on which functions its comments cite, and a census path
        # comes from what the unit defines.
        lexical = (path.suffix == '.cpp' and not confirmed
                   and choice.get('evidence') in ('pdb', 'openrbx', 'class-rule'))
        if LIBRARY_NAME.match(path.stem):
            # Codejock XTP, MFC and ATL were linked in as libraries: never part of Roblox's source tree,
            # whatever the census votes say (a vote only reflects shared template instantiations).
            choice.update(target_path=None, evidence=None, candidates=[], census_conflict=None,
                          reason='library source (Codejock XTP, MFC or ATL): no Roblox path')
            split_review = case_review = False
        choice.update(sha256=sha(path), family=None, merge_group=None, approved=False,
                      function_target_candidates=sorted(targets), requires_split_review=split_review and lexical,
                      requires_case_review=case_review and lexical,
                      requires_identity_review=disputed or lexical and any(
                          funcs[a].get('requires_identity_review') for a in addresses if a in funcs),
                      census_confirms=confirmed, census_disputes=vote if disputed else None,
                      candidate_address_evidence=address_evidence,
                      requires_inline_placement_review=lexical and (
                          any(not t.endswith('.cpp') for t in targets) or
                          any(funcs[a].get('requires_inline_review') for a in addresses if a in funcs)))
        if choice['target_path']:
            target = choice['target_path'].replace('\\', '/')
            # Keep layout under a client-specific build root.
            choice['original_path'] = target
            choice['target_path'] = 'rebuild/2008-06/' + target
            choice['family'] = next((p for p in target.lower().split('/') if p in (
                'gui', 'tool', 'humanoid', 'util', 'v8world', 'v8datamodel', 'rbxview', 'network', 'rendering', 'reflection', 'v8tree')), 'review')
            groups[choice['target_path'].lower()].append(relative(path))
        rows[relative(path)] = choice
    mergegroups = {k: v for k, v in groups.items() if len(v) > 1}
    for target, members in mergegroups.items():
        for member in members:
            rows[member]['merge_group'] = target
            rows[member]['conflict'] = 'multiple sources; definition overlap and TU evidence require review'
    related = possible_related_units(rows)
    print('Surveying path consumers', flush=True)
    # The export pipeline needs only the map; the full consumer survey takes ~30 minutes.
    skip = os.environ.get('LAYOUT_SKIP_CONSUMERS') and (HERE / 'consumers.json').exists()
    cons = load(HERE / 'consumers.json') if skip else consumers()
    print('Linting artifacts', flush=True)
    lint = survey()
    validate_refresh(load(mapping) if mapping.exists() else {}, load(reverse) if reverse.exists() else {})
    save('function-files.json', funcs)
    save('line-order-check.json', line_order)
    save('consumers.json', cons)
    save('source-layout-map.json', rows)
    if not (HERE / 'reverse-map.json').exists():
        save('reverse-map.json', {})
    save('lint-report.json', lint)
    save('merge-groups.json', mergegroups)
    save('possible-related-units.json', {
        'scope': 'Candidate associations only: addresses may be comments, references or constants, not definitions.',
        'groups': related})
    sources.cache_clear()
    snapshot = {relative(p): sha(p) for p in sources()}
    changed = sorted(p for p in set(snapshot) | set(rows) if snapshot.get(p) != rows.get(p, {}).get('sha256'))
    registry_after = sha(ROOT / 'work/2008-06/identity-registry.json')
    mapping_after = mapping_inputs()
    save('input-snapshot.json', {'sources': snapshot,
                               'changed_during_survey': changed,
                               'registry_changed_during_survey': registry_before != registry_after,
                               'registry_sha256': registry_after,
                               'pdb_paths_sha256': sha(NC / 'webservice-pdb-source-paths.txt'),
                               'mapping_inputs': mapping_after,
                               'mapping_inputs_changed_during_survey': mapping_before != mapping_after})
    evidence = Counter(r.get('evidence') or 'unmapped' for r in rows.values())
    report = ['# Source layout inventory', '', 'Read-only snapshot. Proposed paths are not approved moves.', '',
              f'- Native files: {len(rows)}', f'- Path consumer files: {len(cons)}',
              f'- Path references: {sum(r["count"] for c in cons for r in c["references"])}',
              f'- File mapping evidence: {dict(evidence)}',
              f'- Functions with donor line evidence: {sum(r.get("line") is not None for r in funcs.values())}',
              f'- Merge/conflict groups: {len(mergegroups)}',
              f'- Possible related-path groups (heuristic): {len(related)}',
              f'- Unique proposed paths: {len(groups)}; unmapped files: {evidence["unmapped"]}',
              f'- Files with case-only target ambiguity: {sum(r.get("requires_case_review", False) for r in rows.values())}',
              f'- Files mentioning repeated target identities: {sum(r.get("requires_identity_review", False) for r in rows.values())}',
              f'- Source files changed/added during survey: {len(changed)}; registry changed: {registry_before != registry_after}',
              f'- Other mapping inputs changed during survey: {mapping_before != mapping_after}',
              f'- Prove-out tree present in this checkout: {(NC / "prove-out").is_dir()}',
              '', 'Expected final TU count is unresolved until membership and split/merge proof are complete.',
              'Rich-header object contributions include libraries; they are not a direct count of app source files.',
              '', '## Artifact candidates (files)', '']
    report += [f'- {k}: {v}' for k, v in sorted(lint['files_by_category'].items())]
    report += ['', f'Duplicate header basenames: {len(lint["duplicate_header_names"])}.',
               f'Duplicate qualified-definition candidates: {len(lint["duplicate_definition_candidates"])}.',
               '', '## Family order', '', 'gui, tool, humanoid, util, v8world, v8datamodel, rbxview/app, network, rendering, core headers.',
               '', '## Risks and proof still needed', '',
               '- 2007 donor paths and line order are evidence, not proof of 2008 TU boundaries or link order.',
               '- Basename matches and address-comment associations need manual review; mixed units need splitting.',
               '- No source move is approved by this survey. Protected consumers need their owner.',
               '- If prove-out is absent, its protected website inputs are not inventoried; scan the live tree separately.',
               '- Existing flags, dependencies, compiler versions and full link inputs must be frozen before any gate.',
               '- Lint findings are lexical candidates; no template, pragma, helper or stub is safe to remove on this evidence.',
               '- P5/P6 and runtime status have not been reverified; no native build or executable was changed.',
               '- Merge details: merge-groups.json. Possible related paths: possible-related-units.json.',
               '- Full lint: lint-report.json. Consumers: consumers.json.',
               '', '## Merge groups', '']
    report += [f'- {k}: ' + ', '.join(v) for k, v in sorted(mergegroups.items())]
    (HERE / 'PLAN_REPORT.md').write_text('\n'.join(report) + '\n', encoding='utf-8')
    print({'files': len(rows), 'consumers': len(cons), 'evidence': dict(evidence), 'merge_groups': len(mergegroups)})


if __name__ == '__main__':
    run()

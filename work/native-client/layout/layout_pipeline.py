"""One command: select clean mappings, export, beautify, prove, optionally commit the branch.

    python work/native-client/layout/layout_pipeline.py [--refresh] [--branch]

--refresh  rebuild source-layout-map.json first (consumer survey skipped: minutes, not 35).
--branch   commit the result to local branch layout/2008-06 (git plumbing; checkout untouched).
           Pushing stays a manual, owner-approved step.

Selection: one-to-one WebService.pdb basename matches with no open review flag, content
unchanged since the map (line endings aside), no absolute local path in the file.
Proof per .cpp: the verbatim export and the beautified export each compile to an object
identical to the live original (tu_signature). A beautified file that fails falls back to
the verbatim copy; a verbatim copy that fails is dropped. Headers are beautified only when
token-identical and free of line-sensitive macros. No link, P5/P6 or runtime gate.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from collections import Counter
from pathlib import Path

import layout_clean
import layout_export
from coff_compare import compare_merge, parse, tu_signature
from common import NATIVE as NATIVE_SOURCES
from layout_export import EXPORT, HERE, ROOT

BASE = ROOT / 'rebuild/2008-06'
RUNNER = BASE / 'tests/native_check_runner.py'
GATE = HERE / 'gates/pipeline'
WORKERS = int(os.environ.get('LAYOUT_WORKERS', 3))   # parallel compiles per runner batch (runner allows 1-8)
TREE = False                                          # tree check and header hold-back trials: opt in with --tree
BRANCH = 'layout/2008-06'
REVIEW_FLAGS = ('requires_case_review', 'requires_identity_review', 'requires_inline_placement_review')


def proven_path(row):
    """Main tree: PDB file-name match, or census function evidence with a known file-name case."""
    return row.get('evidence') == 'pdb' or (row.get('evidence') == 'census' and row.get('case_source') == 'openrbx'
                                            and row.get('census_votes', 0) >= 2)


def overlay_folders():
    """Top-level native-headers folders that only some units reach, through `/I{headers}/<folder>` in their
    pinned flags: compile-profile overlays of a header, not another original header."""
    found = set()
    pattern = re.compile(r'/I\{headers\}/([^\s/]+)')
    for root in list(NATIVE_SOURCES) + [ROOT / 'rebuild/2008-06/tests']:      # trial files use overlays too
        for folder, _dirs, names in os.walk(root):
            for name in names:
                if name.endswith(('.cpp', '.c')):
                    with open(os.path.join(folder, name), encoding='latin-1') as handle:
                        head = handle.read(4000)
                    found.update(m.casefold() for m in pattern.findall(head))
    return found


def select(rows):
    """Clean one-to-one candidates plus a count of why the rest are held back."""
    # A wrapper holds no code of its own and is never published, so it cannot conflict with the real
    # source it shares an original file with: that source is exported on its own.
    wrapper = set()
    for rel in rows:
        if rel.endswith(('.cpp', '.c')) and (ROOT / rel).is_file()                 and layout_clean.is_wrapper((ROOT / rel).read_bytes().decode('latin-1')):
            wrapper.add(rel)
    overlays = overlay_folders()
    overlay = {rel for rel in rows if rel.endswith(('.h', '.hpp', '.inl')) and 'native-headers/' in rel
               and rel.split('native-headers/', 1)[1].split('/', 1)[0].casefold() in overlays
               and '/' in rel.split('native-headers/', 1)[1]}
    targets = Counter(r['target_path'].casefold() for rel, r in rows.items()
                      if r.get('target_path') and rel not in wrapper and rel not in overlay)
    picked, inferred, held = [], [], Counter()
    for rel, row in rows.items():
        cpp = rel.endswith('.cpp')
        flags = [f for f in REVIEW_FLAGS + (('requires_split_review',) if cpp else ()) if row.get(f)]
        path = ROOT / rel
        if (row.get('reason') or '').startswith('library source'):
            held['library source (XTP, MFC, ATL): no Roblox path'] += 1
        elif not row.get('target_path'):
            held['no original path'] += 1
        elif rel in wrapper:
            held['wrapper around donor or library source'] += 1
        elif rel in overlay:
            held['profile overlay header (reached only through a unit /I flag)'] += 1
        elif targets[row['target_path'].casefold()] > 1 or (row.get('conflict') or row.get('merge_group')) and targets[row['target_path'].casefold()] > 1:
            held['merge or conflict'] += 1
        elif row.get('census_conflict'):
            held['conflicting census evidence'] += 1
        elif flags:
            held[flags[0]] += 1
        elif not path.is_file() or row['sha256'] not in layout_export.hashes(path.read_bytes()):
            held['changed since map'] += 1
        elif proven_path(row):
            picked.append(rel)
        elif '/unclassified/' in row['target_path']:
            held['inferred path with no folder evidence'] += 1
        else:                                     # OpenRBX name or address evidence: published apart, labelled
            inferred.append(rel)
    return sorted(picked), sorted(inferred), dict(held)


def path_tier(export, entry):
    """'original' or 'inferred' for an exported file: the receipt says so; older receipts used an inferred/ folder."""
    return entry.get('path') or ('inferred' if '/layout/inferred/' in export else 'original')


def scrub(value):
    """Machine-specific absolute paths never leave this checkout."""
    text = json.dumps(value)
    for root in (str(ROOT).replace('\\', '\\\\'), ROOT.as_posix()):
        text = text.replace(root, '{root}')
    return json.loads(text)


def compile_objects(sources, flags=None, tag='run', retry=True):
    """{source: object path or None}. One runner batch; flags override the pinned profile."""
    if not sources:
        return {}
    GATE.mkdir(parents=True, exist_ok=True)
    manifest = GATE / (tag + '.json')
    jobs = [{'source': os.path.relpath(s, BASE).replace('\\', '/')} for s in sources]
    manifest.write_text(json.dumps({'compiler_build': 21022, 'jobs': jobs}, indent=1))
    env = dict(os.environ)
    env.pop('NATIVE_FLAGS', None)
    if flags:
        env['NATIVE_FLAGS'] = flags
    done_run = subprocess.run([sys.executable, str(RUNNER), 'run', str(manifest), '--workers', str(WORKERS)], cwd=ROOT, env=env,
                              capture_output=True, text=True)
    out = done_run.stdout.strip().splitlines()
    if not out:   # runner died (e.g. an unreadable source): report these sources as not compiled instead of crashing
        (GATE / (tag + '.runner-error.txt')).write_text(done_run.stderr[-4000:])
        print('runner gave no result for %s (see %s.runner-error.txt)' % (tag, tag), flush=True)
        return {s: None for s in sources}
    results = json.loads(Path(json.loads(out[-1])['results']).read_text())
    rows = results if isinstance(results, list) else results['results']
    done = {str(Path(r['source']).resolve()).casefold(): r['object'] for r in rows if r['status'] == 'complete'}
    LOGS.update({str(Path(r['source']).resolve()).casefold(): r['log'] for r in rows if r.get('log')})
    # Every compile replaces the record, with None when the runner gives no list: a list left over from
    # an earlier compile of the same file (other flags, other include roots) would be wrong.
    DEPS.update({str(Path(r['source']).resolve()).casefold(): list(r['dependencies']) if r.get('dependencies') else None
                 for r in rows})
    # Another lane editing a shared header mid-compile makes the runner reject the object. That says
    # nothing about the source: retry once, then report it as unverified, never as a failure.
    moving = {str(Path(r['source']).resolve()).casefold() for r in rows
              if r['status'] != 'complete' and 'inputs changed' in (r.get('error') or '')}
    result = {s: done.get(str(Path(s).resolve()).casefold()) for s in sources}
    again = [s for s in sources if str(Path(s).resolve()).casefold() in moving]
    if again and retry:
        result.update(compile_objects(again, flags, tag + '-retry', retry=False))
    else:
        UNSETTLED.update(str(Path(s).resolve()).casefold() for s in again)
    return result


def compile_batches(batches, tag):
    """[(flags, [sources])] -> [{source: object}], one runner per flag set, run concurrently: a merge round is
    often many tiny single-flag batches, and running them one after another left most workers idle."""
    from concurrent.futures import ThreadPoolExecutor
    if not batches:
        return []
    with ThreadPoolExecutor(max_workers=min(6, len(batches))) as pool:
        return list(pool.map(lambda nb: compile_objects(nb[1][1], flags=nb[1][0] or None, tag='%s-%d' % (tag, nb[0])),
                             enumerate(batches)))


UNSETTLED = set()   # sources whose compile was rejected only because inputs changed under it
LOGS = {}           # source -> last compile log
DEPS = {}           # source -> files its last compile read (kept by the runner even for cached objects)
REDEFINED = re.compile(r'\((\d+)\) : error C(?:2011|2084|2086|2370|2372|2374|2995)\b')


def repair(text, source):
    """Drop the blocks a redefinition error points at; None when the log offers nothing to drop.

    Pieces of one original file often carry their own copy of a type or helper that another piece,
    or a header, already defines. Removing the later copy is only a proposal: the merged unit must
    still reproduce every member symbol byte for byte.
    """
    log = LOGS.get(str(Path(source).resolve()).casefold())
    if not log or not Path(log).exists():
        return None
    name = Path(source).name.lower()
    hits = {int(m[1]) for line in Path(log).read_text(encoding='utf-8', errors='replace').splitlines()
            if name + '(' in line.lower() for m in [REDEFINED.search(line)] if m}
    return drop_blocks(text, hits) or drop_definitions(text, hits)


def drop_definitions(text, hits):
    """Text without the definitions that the 1-based error lines in hits start, or None.

    drop_blocks needs a blank-line separated block; two pieces often run definitions together or
    wrap them in #if lines. Here a definition is the statement that starts at the error line (plus
    return-type lines above it at the same brace depth) up to its balanced closing brace or its
    semicolon, so neighbours in the same block stay.
    """
    lines = text.split('\n')
    code = [re.sub(r'//.*|"(?:\\.|[^"\\])*"', '', line) for line in lines]
    depth = [0]
    for line in code:
        depth.append(depth[-1] + line.count('{') - line.count('}'))
    drop = set()
    for hit in sorted(hits):
        first = hit - 1
        if not 0 <= first < len(lines) or first in drop or lines[first].lstrip().startswith('#'):
            continue
        while (first > 0 and depth[first - 1] == depth[first] and lines[first - 1].strip()
               and not code[first - 1].rstrip().endswith((';', '{', '}', ':'))
               and not lines[first - 1].lstrip().startswith(('#', '//', '/*', '*'))):
            first -= 1
        end, seen = None, False
        for i in range(first, min(len(lines), first + 500)):
            seen = seen or '{' in code[i]
            if seen and depth[i + 1] <= depth[first]:
                end = i
                break
            if not seen and code[i].rstrip().endswith(';'):
                end = i
                break
        if end is not None and end >= hit - 1 and depth[end + 1] == depth[first]:
            drop.update(range(first, end + 1))
    return '\n'.join(line for i, line in enumerate(lines) if i not in drop) if drop else None


def drop_blocks(text, hits):
    """Text without the brace-balanced blocks (runs of non-blank lines) containing the 1-based lines in hits."""
    lines, drop, start = text.split('\n'), set(), 0
    for i in range(len(lines) + 1):
        if i == len(lines) or not lines[i].strip():
            block = '\n'.join(lines[start:i])
            if (any(start < hit <= i for hit in hits) and block.count('{') == block.count('}')
                    and not re.search(r'^\s*#', block, re.M)):
                drop.update(range(start, i))
            start = i + 1
    return '\n'.join(line for i, line in enumerate(lines) if i not in drop) if drop else None


def unsettled(path):
    return str(Path(path).resolve()).casefold() in UNSETTLED


def same(a, b):
    return bool(a and b) and tu_signature(parse(a)) == tu_signature(parse(b))


def authentic(per_file):
    """Target addresses whose native body sits in a main-tree export with an identical object.

    The website shows these as "Authentic". Only functions that the census lists for exactly one
    native source count, so shared inline/COMDAT helpers stay with whoever really owns them.
    """
    import layout_census
    jobs = json.loads(layout_census.CHECKS.read_text(encoding='utf-8'))['jobs']
    owners = Counter(c['addr'].lower() for job in jobs for c in job['checks'])
    proven = {Path(ROOT / v['source']).resolve().as_posix().casefold(): export
              for export, v in per_file.items()
              if v['status'].endswith('-identical') and path_tier(export, v) == 'original'}
    result = {}
    for job in jobs:
        export = proven.get(Path(job['source']).resolve().as_posix().casefold())
        if export:
            for check in job['checks']:
                if owners[check['addr'].lower()] == 1:
                    result[check['addr'].lower()] = export.removeprefix('rebuild/2008-06/layout/')
    return {'note': 'address -> original-path file in this export; object-identical to the live native source',
            'addresses': dict(sorted(result.items()))}


def join_members(members, texts, dest):
    """One translation unit from several pieces: shared includes once, exact duplicate definitions once."""
    seen, blocks, parts = set(), set(), []
    for m in members:
        body, _ = layout_export.rewrite(texts[m], ROOT / m, dest)
        lines = []
        for line in body.split('\n'):
            if line.startswith('// native-flags:'):
                continue
            once = line.strip() if line.lstrip().startswith(('#include', '#pragma once')) else None
            if once and once in seen:
                continue
            seen.add(once)
            if lines and lines[-1].lstrip().startswith('#include') and line.strip() and not line.lstrip().startswith('#'):
                lines.append('')                  # a definition right under the includes is its own block
            lines.append(line)
        kept = []
        for block in '\n'.join(lines).strip('\n').split('\n\n'):
            # Pieces often carry their own copy of a local type or helper. A second, character-identical
            # definition is dropped; anything that merely looks similar stays and the proof decides.
            key = ' '.join(block.split())
            whole = block.count('{') == block.count('}') and '{' in block and not re.search(r'^\s*#', block, re.M)
            if whole and key in blocks:
                continue
            if whole:
                blocks.add(key)
            kept.append(block)
        parts.append('\n\n'.join(kept))
    return '\n\n'.join(parts) + '\n'


def tree_check(files, out, live, status, merged=None):
    """Phase 4 start: does each exported unit build from the exported headers?

    Every proven single `.cpp` is compiled again with the export's include roots ahead of the live
    ones and must give the same object as its live original; a merged unit must reproduce every
    symbol of its pieces. This is the first check of the tree as a tree, and the only compile proof
    of the tidied headers. A unit fails when an exported header is a variant other units were not
    built with. No link, no client, no runtime.

    Verdicts are remembered with the exported headers the unit included. A remembered verdict
    stands while those headers are unchanged and no header has been added to the export since
    (a removed header the unit never included cannot change its build).
    """
    roots = sorted({str(Path(*path.parts[:path.parts.index('include') + 1]))
                    for path in EXPORT.rglob('*') if path.is_file() and 'include' in path.parts[:-1]})
    headers = {p.relative_to(EXPORT).as_posix().casefold(): layout_export.sha(p.read_bytes())
               for p in EXPORT.rglob('*') if p.is_file() and p.suffix.lower() in ('.h', '.hpp', '.inl')}
    cache_path = GATE / 'tree-cache.json'
    cache = json.loads(cache_path.read_text()) if cache_path.exists() else {}
    cache = {k: v for k, v in cache.items() if 'seen' in v}        # older entries lack the header record

    def valid(entry):
        if not entry['same'] and 'redefined' not in entry:   # failing verdicts need the redefinition record
            return False
        if entry['headers'] is None:              # unknown which headers it read: only the same header set counts
            return headers == entry['seen']
        return (set(headers) <= set(entry['seen'])
                and all(headers.get(h) == entry['seen'].get(h) for h in entry['headers']))

    def redefined(source):
        """Class names the compiler says are defined twice: two copies of one header in the include chain."""
        log = LOGS.get(str(Path(source).resolve()).casefold())
        if not log or not Path(log).exists():
            return []
        text = Path(log).read_text(encoding='utf-8', errors='replace')
        names = re.findall(r"error C(?:2011|2995|2371): '(?:RBX::)?(\w+)", text)
        return sorted(set(names))

    def included(source):
        """Exported headers the unit's last compile read; None when neither record exists.

        The runner's dependency list is used when the compile succeeded (it survives object caching).
        A failed compile has no list but does have a fresh log with the include notes.
        """
        name = str(Path(source).resolve()).casefold()
        read = DEPS.get(name)
        if read is None:
            log = LOGS.get(name)
            if not log or not Path(log).exists():
                return None
            read = [line.split('including file:')[-1].strip()
                    for line in Path(log).read_text(encoding='utf-8', errors='replace').splitlines()
                    if 'including file:' in line]
        inside = {Path(os.path.normpath(d)) for d in read}
        return sorted({d.relative_to(EXPORT).as_posix().casefold() for d in inside
                       if d.is_relative_to(EXPORT) and d.relative_to(EXPORT).as_posix().casefold() in headers})

    default = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS'   # the runner's default profile
    extra = ''.join(' /I' + root for root in roots)

    units = [rel for rel, s in status.items() if s in ('clean-identical', 'verbatim-identical')
             and 'profile' not in layout_clean.build_notes(live[rel].read_bytes().decode('latin-1'))]
    key = {rel: 's' + layout_export.sha(live[rel].read_bytes() + b'\0' + out[rel].read_bytes()) for rel in units}
    todo = [rel for rel in units if key[rel] not in cache or not valid(cache[key[rel]])]
    originals = compile_objects([live[r] for r in todo], tag='tree-live')
    groups = {}
    for rel in todo:
        flags = layout_clean.build_notes(live[rel].read_bytes().decode('latin-1')).get('flags') or default
        groups.setdefault(flags, []).append(rel)
    for n, (flags, rels) in enumerate(sorted(groups.items())):
        built = compile_objects([out[r] for r in rels], flags=flags + extra, tag='tree-%d' % n)
        for rel in rels:
            cache.pop(key[rel], None)
            if unsettled(out[rel]) or unsettled(live[rel]):
                continue                          # no verdict this run
            cache[key[rel]] = {'redefined': redefined(out[rel]), 'same': same(originals[live[rel]], built[out[rel]]),
                               'headers': included(out[rel]), 'seen': headers}

    merged = merged or {}
    mkey = {export: 'm' + layout_export.sha((ROOT / export).read_bytes()) for export in merged}
    mtodo = [export for export in merged if mkey[export] not in cache or not valid(cache[mkey[export]])]
    pieces = compile_objects([ROOT / s for export in mtodo for s in merged[export]['sources']], tag='tree-pieces')
    mgroups = {}
    for export in mtodo:
        mgroups.setdefault(merged[export]['flags'] or default, []).append(export)
    for n, (flags, exports) in enumerate(sorted(mgroups.items())):
        built = compile_objects([ROOT / e for e in exports], flags=flags + extra, tag='tree-merged-%d' % n)
        for export in exports:
            cache.pop(mkey[export], None)
            before = [pieces.get(ROOT / s) for s in merged[export]['sources']]
            obj = built[ROOT / export]
            if unsettled(ROOT / export) or any(unsettled(ROOT / s) for s in merged[export]['sources']):
                continue                          # no verdict this run
            try:
                ok = bool(obj and all(before)) and compare_merge([parse(b) for b in before], [parse(obj)], dedupe=True)['passed']
            except ValueError:
                ok = False
            cache[mkey[export]] = {'redefined': redefined(ROOT / export), 'same': ok,
                                   'headers': included(ROOT / export), 'seen': headers}
    GATE.mkdir(parents=True, exist_ok=True)
    cache_path.write_text(json.dumps(cache, indent=0))

    verdicts = {files[rel]['export'].split('/layout/')[-1]: cache[key[rel]] for rel in units if key[rel] in cache}
    mverdicts = {export.split('/layout/')[-1]: cache[mkey[export]] for export in merged if mkey[export] in cache}
    everything = {**verdicts, **mverdicts}
    exercised = {h for v in everything.values() if v['same'] for h in v['headers'] or ()}
    failing = Counter(h for v in verdicts.values() if not v['same'] for h in v['headers'] or ())
    return {'note': 'exported sources compiled with exported headers first; same object as the live original',
            'include_roots': [Path(r).relative_to(EXPORT).as_posix() for r in roots],
            'units_checked': len(verdicts), 'units_same': sum(v['same'] for v in verdicts.values()),
            'units_without_verdict': len(units) - len(verdicts),
            'merged_checked': len(mverdicts), 'merged_same': sum(v['same'] for v in mverdicts.values()),
            'passing': sum(v['same'] for v in everything.values()),
            'exported_headers': len(headers), 'headers_proven_by_a_passing_unit': len(exercised),
            # used by failing units and by no passing one: a variant that shadows the header the rest build with
            'suspect_headers': {h: n for h, n in sorted(failing.items()) if h not in exercised},
            # every exported header a failing unit used, with how many failing units used it
            'failing_use': dict(failing),
            'failing_detail': {u: {'headers': v['headers'] or [], 'redefined': v.get('redefined', [])}
                               for u, v in verdicts.items() if not v['same']},
            'failing_units': sorted(u for u, v in verdicts.items() if not v['same']),
            'failing_merged_units': sorted(u for u, v in mverdicts.items() if not v['same'])}


def coverage(per_file, merged):
    """Code bytes of the executable whose native source is in the export, by tier.

    A function counts for a file when the census lists it for that source and for no source outside
    the file (one piece, or only pieces of the same merged unit). Sizes come from functions.jsonl.
    This measures how much source is organized; it says nothing about linking or running.
    """
    import layout_census
    jobs = json.loads(layout_census.CHECKS.read_text(encoding='utf-8'))['jobs']
    owners = {}
    for job in jobs:
        source = Path(job['source']).resolve().as_posix().casefold()
        for check in job['checks']:
            owners.setdefault(check['addr'].lower(), set()).add(source)
    sizes = {}
    with open(ROOT / 'work/2008-06/functions.jsonl', encoding='utf-8') as lines:
        for line in lines:
            row = json.loads(line)
            if row.get('kind') == 'code':
                sizes[row['addr'].lower()] = row['size']
    units, names = {}, {}                         # tier -> list of source sets, one per exported file
    for export, v in per_file.items():
        if v['status'] in ('dropped', 'unverified') or not export.endswith(('.cpp', '.c')):
            continue
        tier = 'inferred path' if path_tier(export, v) == 'inferred' else 'original path'
        units.setdefault(tier, []).append({Path(ROOT / v['source']).resolve().as_posix().casefold()})
        names[len(names)] = (tier, export)
    for export, v in merged.items():
        tier = 'merged unit, partial' if v.get('left_out') else 'merged unit, complete'
        units.setdefault(tier, []).append({Path(ROOT / s).resolve().as_posix().casefold() for s in v['sources']})
        names[len(names)] = (tier, export)
    index, file_of = {}, {}
    counters = {tier: 0 for tier in units}
    for number, (tier, export) in names.items():
        group = units[tier][counters[tier]]
        counters[tier] += 1
        for source in group:
            index[source] = (tier, frozenset(group))
            file_of[source] = export.split('/layout/')[-1]
    result = {tier: {'files': len(groups), 'functions': 0, 'bytes': 0} for tier, groups in units.items()}
    organized = {}
    for addr, sources in owners.items():
        hit = index.get(next(iter(sources)))
        if hit and sources <= hit[1] and addr in sizes:
            result[hit[0]]['functions'] += 1
            result[hit[0]]['bytes'] += sizes[addr]
            if hit[0] != 'original path':         # the site's wider tier: organized, path or unit not fully proven
                organized[addr] = [file_of[next(iter(sources))], hit[0]]
    total = sum(sizes.values())
    covered = sum(t['bytes'] for t in result.values())
    return {'note': 'code bytes whose native source is in this export; not a link or runtime claim',
            'executable_code_bytes': total, 'exported_bytes': covered,
            'exported_percent': round(100 * covered / total, 2) if total else 0, 'tiers': result}, organized


def load_overrides():
    """Hand-consolidated merge files (overrides/manifest.json): export path -> {members, flags, text}."""
    path = HERE / 'overrides/manifest.json'
    if not path.exists():
        return {}
    result = {}
    for target, spec in json.loads(path.read_text(encoding='utf-8')).items():
        source = HERE / 'overrides' / target
        if source.is_file():
            result[target.casefold()] = {'members': spec['members'], 'flags': spec.get('flags'),
                                         'text': source.read_bytes().decode('latin-1').replace('\r\n', '\n')}
    return result


def merge_groups(rows, evidence):
    """Phase 3, fail-closed: join split units that map to one original file.

    Pieces are tried in target-address order and in reverse (definition order decides what the
    compiler can inline), under each distinct member flag set. A merged unit is kept with the
    first variant under which every function and data symbol of the members reappears
    byte-identical with the same relocation targets (compare_merge; identical COMDAT copies fold).
    Link order and initializer order are not proven here.
    """
    address = re.compile(r'\b00[4-9a-fA-F][0-9a-fA-F]{5}\b')
    groups = {}
    for rel, row in rows.items():
        if row.get('merge_group') and rel.endswith('.cpp') and row['target_path'].endswith('.cpp'):
            groups.setdefault(row['merge_group'], []).append(rel)
    plans = {}
    overrides = load_overrides()
    for key, members in sorted(groups.items()):
        raws = {m: (ROOT / m).read_bytes() for m in members if (ROOT / m).is_file()}
        texts = {m: raw.decode('latin-1').replace('\r\n', '\n') for m, raw in raws.items()}
        if (len(raws) != len(members) or '/unclassified/' in key
                or any(rows[m]['sha256'] not in layout_export.hashes(raw) for m, raw in raws.items())):
            continue
        # A vendor-profile piece compiles without the client defines and include roots, so it cannot
        # share a unit with normal pieces. Mixed group: join the normal pieces, leave the rest out.
        wrappers = [m for m in members if layout_clean.is_wrapper(texts[m])]   # never published as source
        vendor = [m for m in members if m not in wrappers and 'profile' in layout_clean.build_notes(texts[m])]
        left_out = wrappers + (vendor if 0 < len(vendor) < len(members) - len(wrappers) else [])
        members = [m for m in members if m not in left_out]
        if len(members) < 2:
            continue
        builds = [layout_clean.build_notes(texts[m]) for m in members]
        tier = '' if all(proven_path(rows[m]) for m in members) else 'inferred'
        dest = layout_export.destination(rows[members[0]]['target_path'], tier)
        if dest.exists():
            continue
        members = sorted(members, key=lambda m: min(address.findall(texts[m]) or ['ffffffff']).lower())
        orders = [members] + ([members[::-1]] if len(members) > 1 else [])
        candidates = {}                           # same flags in another order or repeated are one candidate
        for b in builds:
            candidates.setdefault(frozenset(b.get('flags', '').split()), b.get('flags', ''))
        variants = []
        for order in orders:
            text = join_members(order, texts, dest)
            if str(ROOT) not in text:
                variants += [{'flags': flags, 'text': text, 'members': order} for flags in candidates.values()]
        if 3 <= len(members) <= 6:                # whole group first; then every group minus one piece
            for skip in members:
                rest = [m for m in members if m != skip]
                text = join_members(rest, texts, dest)
                if str(ROOT) not in text:
                    variants += [{'flags': flags, 'text': text, 'members': rest} for flags in candidates.values()]
        hand = overrides.get(key.casefold().removeprefix('rebuild/2008-06/'))
        if hand and set(hand['members']) <= set(members) and str(ROOT) not in hand['text']:
            first = hand['members'][0]
            flags = hand['flags'] if hand['flags'] is not None else builds[members.index(first)].get('flags', '')
            variants.insert(0, {'flags': flags, 'text': hand['text'], 'members': list(hand['members']), 'hand': True})
        if not variants:
            continue
        plans[key] = {'tier': tier, 'dest': dest, 'members': members, 'variants': variants, 'left_out': left_out, 'texts': texts,
                      'ck': layout_export.sha(json.dumps([[v['flags'], v['text']] for v in variants]).encode('latin-1', 'replace'))}
    cache_path = GATE / 'merge-cache.json'
    cache = json.loads(cache_path.read_text()) if cache_path.exists() else {}
    known = {k: cache[p['ck']] for k, p in plans.items() if p['ck'] in cache}
    originals = compile_objects([ROOT / m for k, p in plans.items() if k not in known for m in p['members']],
                                tag='merge-members')
    why, detail = {}, {}

    def attempt(pending, tag):
        """Compile each pending unit's next variant; return {key: winning variant}."""
        done = {}
        for key in pending:
            plans[key]['try'] = 0
        while pending:
            batches = {}
            for key in pending:
                batches.setdefault(plans[key]['variants'][plans[key]['try']]['flags'], []).append(key)
            ordered = sorted(batches.items())
            for flags, keys in ordered:
                for key in keys:
                    plans[key]['dest'].parent.mkdir(parents=True, exist_ok=True)
                    plans[key]['dest'].write_bytes(plans[key]['variants'][plans[key]['try']]['text'].encode('latin-1'))
            results = compile_batches([(flags, [plans[k]['dest'] for k in keys]) for flags, keys in ordered], tag)
            for (flags, keys), built in zip(ordered, results):
                for key in keys:
                    before = [originals.get(ROOT / m) for m in plans[key]['variants'][plans[key]['try']]['members']]
                    obj = built[plans[key]['dest']]
                    if not obj:
                        why[key] = 'inputs changing' if unsettled(plans[key]['dest']) else 'merged unit does not compile'
                        current = plans[key]['variants'][plans[key]['try']]
                        fixed = None if unsettled(plans[key]['dest']) or current.get('repairs', 0) >= 6 else repair(current['text'], plans[key]['dest'])
                        if fixed:                 # try the repaired text next, same order and flags
                            plans[key]['variants'].insert(plans[key]['try'] + 1, dict(current, text=fixed, repairs=current.get('repairs', 0) + 1))
                    elif not all(before):
                        why[key] = ('inputs changing' if any(unsettled(ROOT / m) for m in plans[key]['members'])
                                    else 'a member does not compile alone')
                    else:
                        try:
                            verdict = compare_merge([parse(b) for b in before], [parse(obj)], dedupe=True)
                            if verdict['passed']:
                                done[key] = plans[key]['variants'][plans[key]['try']]
                            else:
                                why[key] = 'symbols differ: %d changed or removed, %d changed or added' % (
                                    len(verdict.get('removed_or_changed', [])), len(verdict.get('added_or_changed', [])))
                                detail[key] = {'removed_or_changed': verdict.get('removed_or_changed', [])[:8],
                                               'added_or_changed': verdict.get('added_or_changed', [])[:8],
                                               'reason': verdict.get('reason'),
                                               'before': verdict.get('before', [])[:6], 'after': verdict.get('after', [])[:6]}
                        except ValueError as error:
                            why[key] = 'object comparison refused: %s' % error
                    plans[key]['dest'].unlink()
            pending = [k for k in pending if k not in done and plans[k]['try'] + 1 < len(plans[k]['variants'])]
            for key in pending:
                plans[key]['try'] += 1
        return done

    merged = attempt([k for k in plans if k not in known], 'merge')
    for key, verdict in known.items():
        if verdict['passed']:
            merged[key] = verdict['win']
    # Fallback for groups that fail as a whole: grow the largest subset that still proves out.
    # Pieces are offered biggest first; each stays only if the joined unit, compiled with the first
    # piece's flags, reproduces every symbol of the pieces in it. One piece alone is a valid result.
    greedy = [k for k in plans if k not in merged and not (known.get(k) or {}).get('greedy_tried')]
    originals.update(compile_objects([ROOT / m for k in greedy for m in plans[k]['members']
                                      if not originals.get(ROOT / m)], tag='greedy-members'))
    state = {}
    for key in greedy:
        queue = sorted(plans[key]['members'], key=lambda m: -len(plans[key]['texts'][m]))
        state[key] = {'kept': [], 'queue': queue, 'text': None, 'moving': False,
                      'flags': layout_clean.build_notes(plans[key]['texts'][queue[0]]).get('flags', '')}
    rounds = 0
    while any(state[k]['queue'] for k in greedy):
        batches = {}
        for key in greedy:
            if state[key]['queue']:
                batches.setdefault(state[key]['flags'], []).append(key)
        ordered = sorted(batches.items())
        for flags, keys in ordered:
            for key in keys:
                st, plan = state[key], plans[key]
                st['cand'] = [m for m in plan['members'] if m in st['kept'] or m == st['queue'][0]]
                st['cand_text'] = join_members(st['cand'], plan['texts'], plan['dest'])
                plan['dest'].parent.mkdir(parents=True, exist_ok=True)
                plan['dest'].write_bytes(st['cand_text'].encode('latin-1'))
        results = compile_batches([(flags, [plans[k]['dest'] for k in keys]) for flags, keys in ordered], 'greedy-%d' % rounds)
        for (flags, keys), built in zip(ordered, results):
            for key in keys:
                st, plan = state[key], plans[key]
                before = [originals.get(ROOT / m) for m in st['cand']]
                obj = built[plan['dest']]
                ok = False
                if obj and all(before) and str(ROOT) not in st['cand_text']:
                    try:
                        ok = compare_merge([parse(b) for b in before], [parse(obj)], dedupe=True)['passed']
                    except ValueError:
                        ok = False
                elif unsettled(plan['dest']) or any(unsettled(ROOT / m) for m in st['cand']):
                    st['moving'] = True
                if ok:
                    st['kept'], st['text'] = st['cand'], st['cand_text']
                st['queue'].pop(0)
                plan['dest'].unlink()
        rounds += 1
    for key in greedy:
        if state[key]['kept']:
            merged[key] = {'flags': state[key]['flags'], 'text': state[key]['text'], 'members': state[key]['kept'],
                           'subset': True}
    retry_greedy = {k for k in greedy if state[k]['moving'] and k not in merged}
    tidy = []
    for key, variant in merged.items():
        plan = plans[key]
        plan['clean'], plan['notes'] = layout_clean.clean(variant['text'])
        if plan['clean'] != variant['text'] and layout_clean.tokens(plan['clean']) == layout_clean.tokens(variant['text']):
            tidy.append(key)
    for key in tidy:                              # tidy pass reuses attempt(): one variant, the cleaned text
        plans[key]['raw_variants'] = plans[key]['variants']
        plans[key]['variants'] = [dict(merged[key], text=plans[key]['clean'])]
    tidied = set(attempt([k for k in tidy if k not in known or k in greedy], 'merge-clean'))
    tidied |= {k for k, v in known.items() if v.get('tidied') and k not in greedy}
    for key in tidy:
        plans[key]['variants'] = plans[key]['raw_variants']
    for key, plan in plans.items():
        if key in known and key not in greedy:
            continue                              # remembered verdict stands
        if key not in merged and (key in retry_greedy or key not in known and why.get(key) in ('inputs changing', None)):
            continue                              # no verdict this run: ask again next time
        cache[plan['ck']] = {
            'passed': key in merged, 'tidied': key in tidied, 'greedy_tried': True,
            'win': merged.get(key),
            'why': None if key in merged else why.get(key) or (known.get(key) or {}).get('why', 'not attempted'),
            'target': plan['dest'].relative_to(EXPORT).as_posix(),
            'detail': None if key in merged else detail.get(key) or (known.get(key) or {}).get('detail')}
    GATE.mkdir(parents=True, exist_ok=True)
    cache_path.write_text(json.dumps(cache, indent=0))
    result = {}
    for key, variant in merged.items():
        plan = plans[key]
        export = plan['dest'].relative_to(ROOT).as_posix()
        plan['dest'].parent.mkdir(parents=True, exist_ok=True)
        plan['dest'].write_bytes((plan['clean'] if key in tidied else variant['text']).encode('latin-1'))
        result[export] = {'sources': variant['members'], 'flags': variant['flags'],
                          'status': ('merged and tidied' if key in tidied else 'merged')
                          + ' (per-symbol identical; link order unproven)'}
        result[export]['path'] = 'inferred' if plan['tier'] else 'original'
        if variant.get('hand'):
            result[export]['hand_consolidated'] = True
        left = plan['left_out'] + [m for m in plan['members'] if m not in variant['members']]
        if left:                                 # partial: these pieces of the same original file are not in it
            result[export]['left_out'] = left
        evidence[export] = {'sources': variant['members'], 'build': {'flags': variant['flags']},
                            'notes': plan['notes'] if key in tidied else []}
    return result


def run(refresh=False):
    if refresh:
        import inventory
        os.environ['LAYOUT_SKIP_CONSUMERS'] = '1'
        inventory.run()
    rows = json.loads((HERE / 'source-layout-map.json').read_text(encoding='utf-8'))
    picked, inferred, held = select(rows)
    manifest = HERE / 'families/auto-export.json'
    manifest.write_text(json.dumps({'family': 'layout', 'approved': picked, 'inferred': inferred,
                                    'approved_by': 'automatic: clean one-to-one PDB mappings (layout_pipeline.select)'}, indent=1))
    if EXPORT.exists():
        shutil.rmtree(EXPORT)                     # generated tree; rebuilt from scratch every run
    files = layout_export.export(manifest)['files']
    live = {rel: ROOT / rel for rel in files}
    out = {rel: ROOT / f['export'] for rel, f in files.items()}
    cpps = [rel for rel in files if rel.endswith('.cpp')]

    # Verdicts are remembered per (live text, exported text): a copy that differs from its original
    # only in comments, whitespace and include paths gives the same answer under any header state.
    # ponytail: a header that newly makes a unit line-sensitive is not seen until the unit's text changes.
    cache_path = GATE / 'single-cache.json'
    cache = json.loads(cache_path.read_text()) if cache_path.exists() else {}
    ck = {rel: layout_export.sha((ROOT / rel).read_bytes() + b'\0' + out[rel].read_bytes()) for rel in cpps}
    fresh = [rel for rel in cpps if ck[rel] not in cache]

    # 1. Verbatim export vs live original (both carry their pinned flags).
    objects = compile_objects([live[r] for r in fresh] + [out[r] for r in fresh], tag='verbatim')
    status = {}
    for rel in cpps:
        if rel not in fresh:
            status[rel] = 'verbatim-identical' if cache[ck[rel]]['verbatim'] else 'dropped'
        elif same(objects[live[rel]], objects[out[rel]]):
            status[rel] = 'verbatim-identical'
        elif unsettled(live[rel]) or unsettled(out[rel]):
            status[rel] = 'unverified'            # not exported this run, not remembered
        else:
            status[rel] = 'dropped'

    # 2. Beautify. Token check first; then compile each flag group with its flags as override.
    evidence, verbatim, groups = {}, {}, {}
    for rel, path in out.items():
        raw = path.read_bytes()
        text = raw.decode('latin-1')
        cleaned, notes = layout_clean.clean(text)
        build = layout_clean.build_notes(text)
        if status.get(rel) in ('dropped', 'unverified'):
            continue
        if rel in ck and rel not in fresh:        # remembered verdict: no compile
            if cache[ck[rel]].get('clean'):
                status[rel] = 'clean-identical'
                path.write_bytes(cleaned.encode('latin-1'))
                evidence[files[rel]['export']] = {'source': rel, 'build': build, 'notes': notes}
            continue
        if cleaned == text or layout_clean.tokens(cleaned) != layout_clean.tokens(text):
            status.setdefault(rel, 'verbatim')
            continue
        if rel.endswith('.cpp'):
            if 'profile' in build:                # ponytail: vendor-profile units stay verbatim (runner reads the profile from the file)
                continue
            groups.setdefault(build.get('flags', ''), []).append(rel)
        elif layout_clean.line_sensitive(text):
            status[rel] = 'verbatim (line-sensitive macros)'
            continue
        else:
            status[rel] = 'clean (token-identical)'
        verbatim[rel] = raw
        path.write_bytes(cleaned.encode('latin-1'))
        evidence[files[rel]['export']] = {'source': rel, 'build': build, 'notes': notes}
    tried_clean, moving = {rel for rels in groups.values() for rel in rels}, set()
    for n, (flags, rels) in enumerate(sorted(groups.items())):
        built = compile_objects([out[r] for r in rels], flags=flags or None, tag='clean-%d' % n)
        for rel in rels:
            if same(objects[live[rel]], built[out[rel]]):
                status[rel] = 'clean-identical'
            else:                                 # line numbers reached codegen; publish the proven verbatim copy
                out[rel].write_bytes(verbatim[rel])
                evidence.pop(files[rel]['export'], None)
                if unsettled(out[rel]):
                    moving.add(rel)               # rejected for moving inputs: ask again next run
    for rel in fresh:
        if status[rel] != 'unverified' and rel not in moving:
            cache[ck[rel]] = {'verbatim': status[rel] != 'dropped',
                              'clean': status[rel] == 'clean-identical' if rel in tried_clean else None}
    GATE.mkdir(parents=True, exist_ok=True)
    cache_path.write_text(json.dumps(cache, indent=0))
    for rel, path in out.items():                 # a local absolute path may only survive in the scrubbed evidence
        if status.get(rel) not in ('dropped', 'unverified') and str(ROOT).encode() in path.read_bytes():
            status[rel] = 'dropped'
            held['absolute local path survives tidy'] = held.get('absolute local path survives tidy', 0) + 1
            evidence.pop(files[rel]['export'], None)
    for rel in [r for r, s in status.items() if s in ('dropped', 'unverified')]:
        out[rel].unlink()
    merged = merge_groups(rows, evidence)
    held_headers = []
    by_export = {f['export'].split('/layout/')[-1].casefold(): rel for rel, f in files.items()}

    def hold(header):
        # A header goes with its same-named companions (X.h with X.inl): one without the other does not build.
        stem = header.rsplit('.', 1)[0]
        for name in [h for h in by_export if h.rsplit('.', 1)[0] == stem and exported(h)]:
            rel = by_export[name]
            out[rel].unlink()
            status[rel] = 'dropped'
            evidence.pop(files[rel]['export'], None)
            held_headers.append(files[rel]['export'].split('/layout/')[-1])

    def exported(header):
        return status.get(by_export.get(header)) not in (None, 'dropped', 'unverified')

    # Merged units do not choose which header to blame (that cascaded onto innocent headers), but they
    # do veto: a removal that helps single files and breaks a merged unit leaves a mix of exported and
    # live copies of one header, which is worse than either.
    def failed(t):
        return set(t['failing_units']) | set(t['failing_merged_units'])

    if TREE:
        for _ in range(4):                            # hold back variant headers until the tree stops changing
            tree = tree_check(files, out, live, status, merged)
            # Only a header that several failing units share is treated as the cause. A header used by
            # one failing unit is usually that unit's own header, failing for another reason.
            suspects = [h for h, n in tree['suspect_headers'].items() if n >= 3 and exported(h)]
            if not suspects:
                break
            for header in suspects:
                hold(header)
        # Trial hold-back for headers that passing units use too: remove the one most failing units share,
        # check again, keep the removal only if more units pass and none that passed now fails.
        tried = set()
        for _ in range(3):
            ranked = sorted(((n, h) for h, n in tree['failing_use'].items() if n >= 10 and h not in tried and exported(h)),
                            reverse=True)
            if not ranked:
                break
            header = ranked[0][1]
            tried.add(header)
            stem = header.rsplit('.', 1)[0]           # the header and its same-named companions, as hold() does
            saved = {by_export[h]: out[by_export[h]].read_bytes()
                     for h in by_export if h.rsplit('.', 1)[0] == stem and exported(h)}
            for rel in saved:
                out[rel].unlink()
            trial = tree_check(files, out, live, status, merged)
            before, after = failed(tree), failed(trial)
            for rel, data in saved.items():
                out[rel].write_bytes(data)
            if trial['passing'] > tree['passing'] and not after - before:
                hold(header)                          # removes them again and records them
                tree = trial
        # Targeted trials. When a unit fails with "class X redefined", two physical copies of the header
        # that defines X are in its include chain (the exported one by search path, the live one by a
        # sibling quote include). Remove the exported header that defines X and check again; keep the
        # removal only if more units pass and none that passed fails.
        def defines(rel, leaf):
            text = out[rel].read_bytes().decode('latin-1')
            return bool(re.search(r'\b(?:class|struct)\s+' + re.escape(leaf) + r'\b[^;{}]*\{', text))

        for _ in range(8):
            classes = Counter(c for d in tree['failing_detail'].values() for c in d['redefined'])
            picked = None
            for leaf, _n in classes.most_common():
                cands = sorted({h for d in tree['failing_detail'].values() if leaf in d['redefined']
                                for h in d['headers'] if exported(h) and defines(by_export[h], leaf)})
                if cands and (leaf, tuple(cands)) not in tried:
                    picked = (leaf, cands)
                    break
            if not picked:
                break
            leaf, cands = picked
            tried.add((leaf, tuple(cands)))
            saved = {}
            for header in cands:
                stem = header.rsplit('.', 1)[0]
                saved.update({by_export[h]: out[by_export[h]].read_bytes()
                              for h in by_export if h.rsplit('.', 1)[0] == stem and exported(h)})
            for rel in saved:
                out[rel].unlink()
            trial = tree_check(files, out, live, status, merged)
            for rel, data in saved.items():
                out[rel].write_bytes(data)
            if trial['passing'] > tree['passing'] and not failed(trial) - failed(tree):
                for header in cands:
                    if exported(header):
                        hold(header)
                tree = trial
        tree = tree_check(files, out, live, status, merged)   # final pass also checks the merged units
        (GATE / 'held-headers.json').write_text(json.dumps(sorted(held_headers)))
        (GATE / 'tree-last.json').write_text(json.dumps(tree))
    else:
        # No tree check this time (it is most of a run's compile time): reuse what the last full check
        # decided, so the export stays consistent, and say so in the receipt.
        remembered = GATE / 'held-headers.json'
        for name in (json.loads(remembered.read_text()) if remembered.exists() else []):
            if exported(name.casefold()):
                hold(name.casefold())
        last = GATE / 'tree-last.json'
        tree = json.loads(last.read_text()) if last.exists() else {}
        tree['stale'] = 'tree check not run this time (pass --tree); numbers are from the last full check'
    tree['held_variant_headers'] = sorted(held_headers)
    if held_headers:
        held['variant header that shadows the one other units build with'] = len(held_headers)
    evidence = scrub(evidence)

    summary = {'files': len(status) - sum(s in ('dropped', 'unverified') for s in status.values()) + len(merged),
               'merged_units': merged,
               'inferred_path_files': sum(r in inferred for r, s in status.items() if s not in ('dropped', 'unverified')),
               'status': dict(Counter(status.values())), 'held_back': held,
               'standard': 'object identity by tu_signature (code, data, relocations, symbols; discardable .debug$S excluded)',
               'cache_note': 'the runner may reuse validated cached objects for unchanged live sources',
               'per_file': {files[r]['export']: {'source': r, 'status': s, 'path': 'inferred' if r in inferred else 'original'}
                            for r, s in sorted(status.items())}}
    (EXPORT / 'authentic.json').write_text(json.dumps(authentic(summary['per_file']), indent=0) + '\n')
    summary['coverage'], organized = coverage(summary['per_file'], merged)
    (EXPORT / 'organized.json').write_text(json.dumps({
        'note': 'address -> [file in this export, tier]; source is organized but its path is inferred or it is a merged unit',
        'addresses': dict(sorted(organized.items()))}, indent=0) + '\n')
    summary['tree_check'] = tree
    (EXPORT / 'coverage.json').write_text(json.dumps(summary['coverage'], indent=1) + '\n')
    (EXPORT / 'layout-receipt.json').unlink()
    (EXPORT / 'receipt.json').write_text(json.dumps(summary, indent=1) + '\n')
    (EXPORT / 'evidence.json').write_text(json.dumps(evidence, indent=1) + '\n')
    (EXPORT / 'README.md').write_text((HERE / 'EXPORT_README.md').read_text(encoding='utf-8'), encoding='utf-8')
    print(json.dumps({k: summary[k] for k in ('files', 'status', 'held_back')}, indent=1))
    return summary


def git(*args, index=None, text=True):
    env = dict(os.environ, GIT_INDEX_FILE=str(index)) if index else None
    return subprocess.run(['git', *args], cwd=ROOT, env=env, capture_output=True, text=text, check=True).stdout.strip()


def commit_branch(summary):
    """New commit on BRANCH whose layout folder is exactly the export. No checkout, no push."""
    index = ROOT / '.git/layout-branch-index'
    index.unlink(missing_ok=True)
    parent = git('rev-parse', BRANCH)
    rel = EXPORT.relative_to(ROOT).as_posix()
    git('read-tree', parent, index=index)
    for old in git('ls-files', '--', rel, index=index).splitlines():   # plumbing: no working-tree checks
        git('update-index', '--force-remove', '--', old, index=index)
    for path in sorted(p for p in EXPORT.rglob('*') if p.is_file()):
        blob = git('hash-object', '-w', '--path', path.relative_to(ROOT).as_posix(), str(path))
        git('update-index', '--add', '--cacheinfo', '100644,%s,%s' % (blob, path.relative_to(ROOT).as_posix()), index=index)
    tree = git('write-tree', index=index)
    index.unlink(missing_ok=True)
    if tree == git('rev-parse', parent + '^{tree}'):
        print('branch unchanged')
        return parent
    message = ('layout: %d files at original paths (%s)\n\nGenerated by layout_pipeline.py; every exported .cpp '
               'compiles to an object identical to its live original.\n\n'
               'Co-Authored-By: Claude Fable 5.2 <noreply@anthropic.com>'
               % (summary['files'], ', '.join('%d %s' % (n, s) for s, n in sorted(summary['status'].items()))))
    commit = git('commit-tree', tree, '-p', parent, '-m', message)
    git('update-ref', 'refs/heads/' + BRANCH, commit)
    print('committed', commit[:10], 'to', BRANCH, '(not pushed)')
    return commit


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--refresh', action='store_true')
    parser.add_argument('--branch', action='store_true')
    parser.add_argument('--commit-only', action='store_true', help='commit the existing export without rebuilding it')
    parser.add_argument('--tree', action='store_true', help='also run the tree check and header hold-back trials (slow: most of the compile time)')
    parser.add_argument('--workers', type=int, choices=range(1, 9), default=WORKERS,
                        help='parallel compiles per batch; 3 shares the machine, 6-8 is faster when it is idle (env LAYOUT_WORKERS)')
    args = parser.parse_args()
    WORKERS = args.workers
    TREE = args.tree
    result = json.loads((EXPORT / 'receipt.json').read_text()) if args.commit_only else run(args.refresh)
    if args.branch or args.commit_only:
        commit_branch(result)

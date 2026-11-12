"""Prepare inactive, private overlays for native family draft review."""
import argparse
from collections import Counter, defaultdict
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import tempfile
import uuid

from roc import draft_merger, native_drafts


NATIVE_PREFIXES = ('rebuild/2008-06/native-classes/', 'rebuild/2008-06/native-headers/')
NATIVE_SUFFIXES = {'.c', '.cc', '.cpp', '.cxx', '.h', '.hpp', '.inl', '.inc', '.ipp'}


def _text_hash(text):
    return draft_merger.content_hash(text.encode('utf-8')) if text is not None else None


def canonical_proposal_path(root, name):
    """Export-layout mapping is a merge hypothesis, never an acceptance proof."""
    parts = Path(name).parts
    if len(parts) >= 6 and parts[:2] == ('rebuild', '2008-06') and parts[2] in ('App', 'Network', 'WindowsClient'):
        if parts[3] == 'include':
            target = 'rebuild/2008-06/native-headers/' + '/'.join(parts[4:])
        elif parts[3] == 'src':
            target = 'rebuild/2008-06/native-classes/' + parts[-1]
        else:
            return name
        if (root / target).is_file():
            return target
    # WindowsClient/src/Foo.cpp and WindowsClient/include/Foo.h have five parts.
    if len(parts) == 5 and parts[:3] == ('rebuild', '2008-06', 'WindowsClient'):
        target = 'rebuild/2008-06/' + {'src': 'native-classes/', 'include': 'native-headers/'}.get(parts[3], '') + parts[4]
        if parts[3] in ('src', 'include') and (root / target).is_file():
            return target
    return name


def merge_file(base, current, candidate):
    """Three-way merge text; conflicts/deletions always retain current text."""
    base_lf, current_lf, candidate_lf = (text.replace('\r\n', '\n') if text is not None else None
                                         for text in (base, current, candidate))

    def current_endings(text):
        return text.replace('\n', '\r\n') if current and current.count('\r\n') == current.count('\n') else text

    if candidate_lf == base_lf:
        return dict(state='unchanged', text=current, blockers=[])
    if candidate is None:
        return dict(state='deletion-review', text=current,
                    blockers=['Deletion requires explicit preservation and replacement review'])
    if candidate_lf == current_lf:
        return dict(state='already-present', text=current, blockers=[])
    if base is None:
        if current is None:
            return dict(state='merged', text=candidate, blockers=[])
        return dict(state='conflict', text=current,
                    blockers=['New-file candidate conflicts with an independently existing canonical file'])
    if current is None:
        return dict(state='conflict', text=None,
                    blockers=['Canonical file was independently deleted; candidate cannot restore it automatically'])
    if current_lf == base_lf:
        return dict(state='merged', text=current_endings(candidate_lf), blockers=[])

    with tempfile.TemporaryDirectory(prefix='roc-draft-merge-') as folder:
        folder = Path(folder)
        ours, ancestor, theirs = folder / 'current', folder / 'base', folder / 'candidate'
        ours.write_bytes(current_lf.encode('utf-8'))
        ancestor.write_bytes(base_lf.encode('utf-8'))
        theirs.write_bytes(candidate_lf.encode('utf-8'))
        result = subprocess.run(['git', 'merge-file', '-p', str(ours), str(ancestor), str(theirs)],
                                capture_output=True, check=False)
    if result.returncode == 0:
        return dict(state='merged', text=current_endings(result.stdout.decode('utf-8')), blockers=[])
    if 0 < result.returncode < 128:
        return dict(state='conflict', text=current,
                    blockers=['Three-way merge conflict; canonical version retained in overlay'])
    raise RuntimeError('git merge-file failed: ' + result.stderr.decode('utf-8', errors='replace'))


def _native_files(root):
    result = []
    for prefix in NATIVE_PREFIXES:
        folder = root / prefix
        if not folder.exists():
            continue
        if folder.is_symlink() or (hasattr(folder, 'is_junction') and folder.is_junction()):
            raise ValueError('Native snapshot root is an alias: ' + prefix)
        for path in folder.rglob('*'):
            if path.is_symlink() or (hasattr(path, 'is_junction') and path.is_junction()):
                raise ValueError('Native snapshot contains an aliased path: ' + str(path))
            if path.is_file() and path.suffix.lower() in NATIVE_SUFFIXES:
                result.append(path.relative_to(root).as_posix())
    return sorted(result)


def _write_exact(path, raw):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('wb') as stream:
        stream.write(raw)
        stream.flush()
        os.fsync(stream.fileno())


def _preservation(current, merged, path):
    from roc.draft_methods import CPP_PARSER, extract

    before, before_errors = extract(current.encode('utf-8') if current is not None else b'')
    after, after_errors = extract(merged.encode('utf-8') if merged is not None else b'')
    before_methods = {row['signature']: row['body_sha256'] for row in before}
    after_methods = {row['signature']: row['body_sha256'] for row in after}
    deleted = sorted(before_methods.keys() - after_methods.keys())
    changed = sorted(name for name in before_methods.keys() & after_methods.keys()
                     if before_methods[name] != after_methods[name])
    added = sorted(after_methods.keys() - before_methods.keys())
    def literals(text):
        stack = [CPP_PARSER.parse((text or '').encode('utf-8')).root_node]
        found = set()
        while stack:
            node = stack.pop()
            if node.type in ('string_literal', 'raw_string_literal'):
                found.add(node.text.decode('utf-8'))
            else:
                stack.extend(node.named_children)
        return found

    before_literals = literals(current)
    after_literals = literals(merged)
    removed_literals = sorted(before_literals - after_literals)
    added_literals = sorted(after_literals - before_literals)
    blockers = []
    duplicates = sorted(name for name, count in Counter(row['signature'] for row in after).items() if count > 1)
    if duplicates:
        blockers.append('AST inventory found duplicate method definitions; resolve canonical providers')
    if deleted:
        blockers.append('AST inventory found removed method definitions; verify no-loss against original build')
    if changed:
        blockers.append('AST inventory found changed method bodies; require original-MSVC identity and preservation proof')
    if added:
        blockers.append('AST inventory found added methods; require original-MSVC symbol/address proof')
    if removed_literals:
        blockers.append('AST inventory found removed literal strings; verify data preservation')
    if added_literals:
        blockers.append('AST inventory found new literal strings; verify original data/code identities')
    if before_errors or after_errors:
        blockers.append('AST parse errors make method/string preservation inventory incomplete')
    if path.suffix.lower() in ('.h', '.hpp', '.inl', '.inc', '.ipp'):
        blockers.append('Changed header declarations or fields require original ABI, vtable and layout proof')
    return dict(deleted_methods=deleted, changed_methods=changed, added_methods=added, duplicate_methods=duplicates,
                removed_literals=removed_literals, added_literals=added_literals,
                parse_errors=bool(before_errors or after_errors), blockers=blockers)


def reuse_existing_methods(current, merged):
    """Remove identical textual merge duplicates while retaining the live definition."""
    from roc.draft_methods import CPP_PARSER, extract
    before, errors = extract((current or '').encode())
    raw = merged.encode()
    after, after_errors = extract(raw)
    if errors or after_errors:
        return merged, []
    old, new = defaultdict(list), defaultdict(list)
    for row in before:
        old[row['signature']].append(row)
    for row in after:
        new[row['signature']].append(row)
    nodes = defaultdict(list)
    stack = [CPP_PARSER.parse(raw).root_node]
    while stack:
        node = stack.pop()
        if node.type == 'function_definition':
            nodes[node.start_point.row + 1].append(node)
        stack.extend(node.named_children)
    edits, reused = [], []
    for signature, rows in new.items():
        if len(rows) < 2 or len(old[signature]) != 1:
            continue
        original = old[signature][0]
        if any(row['needs_semantic_resolution'] or row['body_sha256'] != original['body_sha256'] for row in rows):
            continue
        definitions = [nodes[row['line']] for row in rows]
        if any(len(group) != 1 for group in definitions):
            continue
        definitions = [group[0] for group in definitions]
        retained = [node for node in definitions if node.text.decode() in (current or '')]
        if not retained:
            continue
        edits.extend((node.start_byte, node.end_byte) for node in definitions if node != retained[-1])
        reused.append(signature)
    for start, end in sorted(edits, reverse=True):
        raw = raw[:start] + raw[end:]
    return raw.decode(), sorted(reused)


def compare_layouts(before, after):
    """Structural preservation only; unchanged layout does not prove original ABI."""
    return dict(added=sorted(after.keys() - before.keys()), removed=sorted(before.keys() - after.keys()),
                changed=sorted(name for name in before.keys() & after.keys() if before[name] != after[name]))


def layout_variants(log, parse):
    """MSVC repeats unqualified class names; retain every shape instead of the last one."""
    heads = list(re.finditer(r'^class .+?\s+size\(\d+\):\s*$', log, re.M))
    variants = {}
    for index, head in enumerate(heads):
        end = heads[index + 1].start() if index + 1 < len(heads) else len(log)
        for name, layout in parse(log[head.start():end]).items():
            variants[name + '#' + draft_merger.proof_key(layout)] = layout
    return variants


def measure_layout_preservation(root, unit, output):
    from roc import rebuild
    tools = {}
    for name in ('native_class_layout', 'native_vftable_check'):
        path = root / 'work/native-client' / (name + '.py')
        spec = importlib.util.spec_from_file_location('_draft_family_' + name, path)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        tools[name] = module
    layouts, tables, builds = {}, {}, {}
    for kind, build in unit['builds'].items():
        if build.get('exit') != 0:
            return dict(state='unproved', blocker='Both baseline and candidate must compile for layout preservation')
        flags = [flag for flag in build['flags'] if flag not in ('/c', '/showIncludes')
                 and not flag.startswith('/Fo')]
        folder = output / ('layout-' + kind)
        folder.mkdir(parents=True)
        code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Zs', '/d1reportAllClassLayout'],
                                folder, timeout=120)
        (folder / 'compiler.log').write_text(log)
        builds[kind] = dict(exit=code, log=str(folder / 'compiler.log'))
        if code:
            return dict(state='unproved', builds=builds, blocker='Original compiler layout dump failed')
        layouts[kind] = layout_variants(log, tools['native_class_layout'].parse)
        tables[kind] = {(row['class'] + '::' + row['base'] + '#' + draft_merger.proof_key(row['slots'])): row['slots']
                        for row in tools['native_vftable_check'].blocks(log)}
    if not layouts.get('baseline') or not layouts.get('candidate'):
        return dict(state='unproved', builds=builds, blocker='Compiler emitted no comparable class layout inventory')
    classes = compare_layouts(layouts['baseline'], layouts['candidate'])
    virtuals = compare_layouts(tables['baseline'], tables['candidate'])
    return dict(state='changed' if classes['removed'] or classes['changed'] or virtuals['removed'] or virtuals['changed']
                else 'preserved-before-layout', classes=classes, virtual_tables=virtuals, builds=builds,
                classes_before=len(layouts['baseline']), classes_after=len(layouts['candidate']),
                original_abi_proven=False,
                scope='Compiler layout/virtual declaration preservation only; original offsets, slot identities and dependency ABI remain separate')


def prepare(root, bundle_id, output=None, companions=()):
    root = Path(root).resolve()
    if not re.fullmatch(r'[0-9a-f]{64}', str(bundle_id)):
        raise ValueError('Invalid draft bundle identity')
    family_root = root / 'work/draft-merger/families'
    family_resolved = family_root.resolve()
    if not family_resolved.is_relative_to(root):
        raise ValueError('Family scratch path escapes repository root')
    if output is None:
        output = family_root / (bundle_id + '-' + uuid.uuid4().hex)
    else:
        output = Path(output)
        if not output.is_absolute():
            output = root / output
    output = output.resolve()
    if output == family_resolved or not output.is_relative_to(family_resolved):
        raise ValueError('Output must be a new directory under work/draft-merger/families scratch')
    if output.exists():
        raise FileExistsError('Family scratch output already exists: ' + str(output))

    packets = [native_drafts.Inbox(root).packet(identifier) for identifier in (bundle_id, *companions)]
    changes = []
    for identifier, packet in zip((bundle_id, *companions), packets):
        for uploaded, change in packet['files'].items():
            native_drafts.safe_path(uploaded)
            target = canonical_proposal_path(root, uploaded)
            changes.append((identifier, uploaded, target, change))
    packet_paths = sorted({name for _, uploaded, target, _ in changes for name in (uploaded, target)})
    native_names = _native_files(root)
    guarded_paths = sorted(set(native_names) | set(packet_paths))
    frozen = draft_merger.canonical_state(root, guarded_paths)
    snapshot = {}
    for name in native_names:
        state = frozen[name]
        raw = (root / name).read_bytes()
        if draft_merger.content_hash(raw) != state['sha256']:
            raise RuntimeError('Canonical source changed while freezing: ' + name)
        snapshot[name] = raw

    output.mkdir(parents=True)
    overlay = output / 'overlay'
    for name, raw in snapshot.items():
        _write_exact(overlay / name, raw)
        _write_exact(output / 'baseline' / name, raw)
    if draft_merger.canonical_state(root, guarded_paths) != frozen:
        raise RuntimeError('Canonical inputs changed during overlay snapshot')

    rows = []
    for identifier, uploaded, name, change in changes:
        candidate = change['text']
        base = change['base']
        if uploaded != name and name.startswith('rebuild/2008-06/native-classes/'):
            # Export relocation changes the depth of explicit native-header includes.
            candidate = candidate.replace('"../../native-headers/', '"../native-headers/') if candidate else candidate
            base = base.replace('"../../native-headers/', '"../native-headers/') if base else base
        current_raw = snapshot.get(name) if frozen[name]['exists'] else None
        current = current_raw.decode('utf-8') if current_raw is not None else None
        candidate_sha = _text_hash(candidate)
        base_sha = _text_hash(base)
        current_sha = frozen[name]['sha256']
        blockers = []
        preservation = None
        reused = []
        eligible = (name.startswith(NATIVE_PREFIXES) and
                    Path(name).suffix.lower() in NATIVE_SUFFIXES)
        wrapper = re.fullmatch(r'\s*#\s*include\s*"[^"\n]+"\s*',
            re.sub(r'/\*.*?\*/|//[^\n]*', '', candidate or '', flags=re.S))
        other_sources = [row for row in changes if row[1] != uploaded and row[2] == name and row[1] != row[2]]
        if eligible and wrapper and other_sources:
            state, merged = 'compatibility-wrapper', current
            blockers.append('Export compatibility wrapper omitted; reconcile its organized source into canonical provider')
        elif sum(row[2] == name and row[1] != row[2] for row in changes) > 1:
            state, merged = 'conflict', current
            blockers.append('Multiple exported source proposals map to one canonical path; reconcile alternatives')
        elif not eligible:
            state, merged = 'review-needed', current
            blockers.append('Path is not an eligible native source/header path; uploaded content was not copied')
        else:
            outcome = merge_file(base, current, candidate)
            state, merged = outcome['state'], outcome['text']
            blockers.extend(outcome['blockers'])
            if state == 'merged' and merged is not None:
                merged, reused = reuse_existing_methods(current, merged)
                _write_exact(overlay / name, merged.encode('utf-8'))
                if merged != current:
                    preservation = _preservation(current, merged, Path(name))
                    blockers.extend(preservation['blockers'])
        source_sha = _text_hash(merged) if merged is not None and eligible else current_sha if eligible else None
        rows.append(dict(path=name, uploaded_path=uploaded, bundle=identifier,
                         uploaded_candidate_sha256=_text_hash(change['text']), state=state, source_sha256=source_sha,
                         base_sha256=base_sha, current_sha256=current_sha,
                         candidate_sha256=candidate_sha, blockers=list(dict.fromkeys(blockers)),
                         preservation=preservation, reused_methods=reused))

    if draft_merger.canonical_state(root, guarded_paths) != frozen:
        raise RuntimeError('Canonical inputs changed while preparing family overlay')
    overlay_inventory = {}
    for name in _native_files(overlay):
        overlay_inventory[name] = draft_merger.content_hash((overlay / name).read_bytes())
    manifest = dict(schema=1, bundle_id=bundle_id, companion_bundles=list(companions), output=str(output),
                    input_inventory={name: frozen[name]['sha256'] for name in guarded_paths
                                     if name.startswith(NATIVE_PREFIXES) and
                                     Path(name).suffix.lower() in NATIVE_SUFFIXES},
                    overlay_inventory=overlay_inventory, files=rows,
                    summary=dict(file_count=len(rows), merged=sum(row['state'] == 'merged' for row in rows),
                                 conflicts=sum(row['state'] == 'conflict' for row in rows),
                                 deletions_for_review=sum(row['state'] == 'deletion-review' for row in rows),
                                 review_needed=sum(row['state'] == 'review-needed' for row in rows),
                                 accepted=0, activated=0))
    native_drafts.atomic(output / 'manifest.json', manifest)
    return manifest


def measure(root, output, profile='default'):
    """Compile paired frozen family trees; diagnostics never authorize integration."""
    from roc import match, rebuild
    from roc.draft_native import claims_from, closed_function_targets, compile_review_blockers, flags, numeric_literal_targets, original_view
    from roc.input_reuse import ensure_link

    root = Path(root).resolve()
    if profile not in ('default', 'fast-fp', 'partchunk-fast-fp'):
        raise ValueError('Unknown trusted compiler profile')
    output = Path(output).resolve()
    if not output.is_relative_to(root / 'work/draft-merger/families'):
        raise ValueError('Family measurement must use repository scratch output')
    manifest = json.loads((output / 'manifest.json').read_text())
    # Re-read the immutable inbox packet, rather than trusting a proposed manifest.
    packets = [native_drafts.Inbox(root).packet(identifier)
               for identifier in (manifest['bundle_id'], *manifest.get('companion_bundles', []))]
    trees = {'baseline': output / 'baseline', 'candidate': output / 'overlay'}
    inventories = {'baseline': {name: sha for name, sha in manifest['input_inventory'].items() if sha},
                   'candidate': manifest['overlay_inventory']}

    def verify_inputs():
        for kind, tree in trees.items():
            actual = {name: draft_merger.content_hash((tree / name).read_bytes())
                      for name in _native_files(tree)}
            if actual != inventories[kind]:
                raise ValueError('Frozen family ' + kind + ' inventory changed')

    verify_inputs()
    blockers = []
    for row in manifest['files']:
        if row['state'] == 'merged':
            blockers.extend(compile_review_blockers((trees['candidate'] / row['path']).read_bytes(),
                                                    trees['candidate'], row['path']))
    if blockers:
        result = dict(state='blocked', blockers=sorted(set(blockers)), units=[], accepted=0)
        native_drafts.atomic(output / 'measurement.json', result)
        return result
    candidates = [row for row in manifest['files'] if row['state'] == 'merged'
                  and Path(row['path']).suffix.lower() in ('.cpp', '.cc', '.c', '.cxx')]
    if candidates:
        for tree in trees.values():
            ensure_link(root / 'tools', tree / 'tools')
    units = []
    run = output / 'measurements' / uuid.uuid4().hex
    closure_path = root / 'work/native-client/claude-identity-closure.json'
    closure_raw = closure_path.read_bytes() if closure_path.is_file() else None
    hypotheses = defaultdict(set)
    external = {}
    if closure_raw:
        bindings = json.loads(closure_raw).get('bindings', [])
        external = closed_function_targets(bindings)
        for binding in bindings:
            if binding.get('body_exact') is True and binding.get('function_start') is True:
                hypotheses.setdefault(binding['symbol'], set()).add(int(binding['address'], 16))
    for packet in packets:
        for name, change in packet['files'].items():
            if name.endswith('.json') and change['text']:
                try:
                    claims_from(json.loads(change['text']), hypotheses)
                except (ValueError, UnicodeError):
                    pass
    original = binder = None
    for row in candidates:
        path = row['path']
        unit = dict(path=path, builds={}, removed_symbols=[], changed_symbols=[], added_symbols=[])
        bodies = {}
        for kind, tree in trees.items():
            source = tree / path
            if not source.is_file():
                bodies[kind] = {}
                unit['builds'][kind] = dict(state='absent')
                continue
            directory = run / draft_merger.proof_key(path)[:16] / kind
            directory.mkdir(parents=True)
            obj = directory / 'unit.obj'
            configuration = list(flags(tree))
            if profile != 'default':
                configuration += ['/fp:fast']
            if profile == 'partchunk-fast-fp':
                configuration.insert(0, '/I' + str(tree / 'rebuild/2008-06/native-headers/partchunk-profile'))
            configuration += ['/showIncludes', '/Fo' + str(obj), str(source)]
            code, log = rebuild.run(rebuild.toolchain(21022), 'cl', configuration, directory, timeout=120)
            (directory / 'compiler.log').write_text(log)
            unit['builds'][kind] = dict(exit=code, log=str(directory / 'compiler.log'), flags=configuration)
            if code == 0:
                unit['builds'][kind]['object_sha256'] = draft_merger.content_hash(obj.read_bytes())
                bodies[kind] = {name: (body, refs) for name, body, refs in match.coff_functions(obj.read_bytes())}
        if 'baseline' in bodies and 'candidate' in bodies:
            before, after = bodies['baseline'], bodies['candidate']
            unit['removed_symbols'] = sorted(before.keys() - after.keys())
            unit['added_symbols'] = sorted(after.keys() - before.keys())
            unit['changed_symbols'] = sorted(name for name in before.keys() & after.keys()
                                             if before[name] != after[name])
        unit['original_methods'] = []
        if unit['builds'].get('candidate', {}).get('exit') == 0:
            unit['layout_preservation'] = measure_layout_preservation(root, unit, run / draft_merger.proof_key(path)[:16])
        if 'candidate' in bodies and hypotheses:
            if original is None:
                original, binder = original_view(root)
            exact = []
            for symbol, (body, refs) in bodies['candidate'].items():
                addresses = hypotheses.get(symbol, set())
                for address in sorted(addresses):
                    target, target_refs, _ = match.target('2008-06', '%08x' % address)
                    hit = dict(symbol=symbol, address='%08x' % address,
                               exact_code=match.exact_match(target, target_refs, body, refs),
                               references_verified=False, baseline_exact_code=False)
                    if symbol in bodies.get('baseline', {}):
                        baseline_body, baseline_refs = bodies['baseline'][symbol]
                        hit['baseline_exact_code'] = match.exact_match(target, target_refs, baseline_body, baseline_refs)
                    unit['original_methods'].append(hit)
                    if hit['exact_code']:
                        exact.append(hit)
            own = {hit['symbol']: int(hit['address'], 16) for hit in exact
                   if sum(other['symbol'] == hit['symbol'] for other in exact) == 1}
            for hit in exact:
                try:
                    methods = [(hit['symbol'], int(hit['address'], 16))]
                    numeric = numeric_literal_targets(original, obj, methods)
                    evidence = binder.verify(original, obj, methods, dict(external, **numeric['targets']), own)
                    hit['numeric_literals'] = numeric['literals']
                    hit['reference_evidence'] = evidence
                    hit['references_verified'] = not any(row['local_eh'] for row in evidence)
                except (AssertionError, KeyError, ValueError, IndexError, UnicodeError) as error:
                    hit['reference_blocker'] = str(error)
        units.append(unit)
    verify_inputs()
    if closure_raw is not None and closure_path.read_bytes() != closure_raw:
        raise ValueError('Original symbol hypothesis inventory changed during family measurement')
    result = dict(state='measured-unverified', bundle=manifest['bundle_id'], profile=profile, units=units, accepted=0,
                  blockers=['Coherent family compilation is diagnostic; original code/data/reference proof required',
                            'Affected dependent units, ABI/layout/vtables and final batch no-loss gates required'],
                  identity_hypotheses_sha256=draft_merger.content_hash(closure_raw) if closure_raw else None,
                  summary=dict(attempted=len(units), compiled=sum(row['builds'].get('candidate', {}).get('exit') == 0
                                                                 for row in units),
                               new_exact_reference_methods=sum(hit['exact_code'] and hit['references_verified']
                                   and not hit['baseline_exact_code'] for unit in units for hit in unit['original_methods'])))
    native_drafts.atomic(run / 'report.json', result)
    native_drafts.atomic(output / 'measurement.json', result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--bundle')
    parser.add_argument('--with-bundle', action='append', default=[])
    parser.add_argument('--output', type=Path)
    parser.add_argument('--measure', action='store_true')
    parser.add_argument('--profile', choices=('default', 'fast-fp', 'partchunk-fast-fp'), default='default')
    args = parser.parse_args()
    if args.measure:
        if not args.output:
            parser.error('--measure requires --output from a prepared family')
        result = measure(args.root, args.output, args.profile)
    else:
        if not args.bundle:
            parser.error('--bundle required to prepare a family')
        result = prepare(args.root, args.bundle, args.output, args.with_bundle)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()

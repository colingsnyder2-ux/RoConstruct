"""Claim-local feedback. Object proofs are proposals; only the server grants credit."""
import json
import hashlib
import re
import shutil
import statistics
import subprocess
import sys
import time
import uuid
from collections import Counter
from pathlib import Path

from roc import integration, rebuild, native_search


def diagnostics(text, file=None):
    """Keep compiler locations and codes; categories are hints, never ABI evidence."""
    rows = []
    for line in (text or '').splitlines():
        found = re.search(r'^(.*?)\((\d+)(?:,\d+)?\)\s*:\s*(?:fatal )?error\s+(\w+):\s*(.*)', line)
        linker = re.search(r'^(.*?)\s*:\s*(?:fatal )?error\s+(LNK\d+):\s*(.*)', line) if not found else None
        code, message = (found[3], found[4]) if found else (linker[2], linker[3]) if linker else ('', line)
        if not message.strip():
            continue
        category = ('missing_include' if code == 'C1083' else
                    'wrong_namespace' if code in ('C2653', 'C2039') else
                    'missing_declaration' if code in ('C2065', 'C3861', 'C2146') else
                    'wrong_parameter_type' if code in ('C2664', 'C2660', 'C2440') else
                    'wrong_calling_convention' if code in ('C2373', 'C2695') else
                    'linking_failure' if code.startswith('LNK') else 'compilation_failure')
        rows.append(dict(category=category, code=code, message=message,
                         file=found[1] if found else linker[1] if linker else file, line=int(found[2]) if found else None))
    return rows


def object_diagnostic(obj, addr, symbol):
    from roc import match
    row = native_search.diagnose(obj, {addr: symbol})[addr]
    body, relocs = next((b, r) for s, b, r in match.coff_functions(obj) if s == symbol)
    target, target_relocs, _ = match.target(integration.CLIENT, addr)
    row.update(expected_size=len(target), object_size=len(body),
               target_relocations=sorted(target_relocs), object_relocations=sorted(relocs))
    row['category'] = ('function_size_mismatch' if len(target) != len(body) else
                       'relocation_mismatch' if set(target_relocs) - set(relocs) else
                       'referenced_data_mismatch' if row['code_exact'] and not row['data_exact'] else
                       'wrong_calling_convention' if row['blocker'] == 'abi-review' else 'machine_code_mismatch')
    left, right = match.asm_lines(target, target_relocs), match.asm_lines(body, relocs)
    row['first_mismatch'] = next((dict(instruction=i, target=a, object=b)
                                 for i, (a, b) in enumerate(zip(left, right)) if a != b),
                                dict(target_instructions=len(left), object_instructions=len(right)))
    first = row['first_mismatch']
    a, b = first.get('target', ''), first.get('object', '')
    memory = lambda line: re.sub(r'(?<=\+) (?:0x[0-9a-f]+|\d+)(?=\])', ' OFFSET', line)
    if a != b and memory(a) == memory(b):
        if a.startswith('call ') and '[' in a:
            row['category'] = 'incorrect_vtable_slot'
        elif '[ecx +' in a:
            row['category'] = 'incorrect_member_offset'
    row['classification_is_hint'] = True
    return row


def layer_plan(spec):
    """Use the linked module's exact direct-build recipes, including preludes."""
    from roc import libs
    for layer in spec['layers']:
        if layer['mode'] == 'recipe':
            if not layer.get('direct'):
                raise ValueError('Local checking does not support wrapped layer: ' + layer['name'])
            recipe = libs.RECIPES[layer['recipe']]
            src = libs._case_path(libs.LIBS / recipe['src']).resolve()
            tree = rebuild.patched_tree(integration.CLIENT, layer['recipe'])
            listed = recipe.get('files')
            patterns = listed if layer['files'] == 'recipe' else layer['files']
            files = list(patterns) if isinstance(patterns, list) else sorted({
                p.relative_to(src).as_posix() for glob in patterns.split() for p in src.glob(glob)
                if not p.name.startswith('roc_')})
            native_root = (rebuild.ROOT / 'tools/rbxgs/Client').resolve()
            if src.is_relative_to(native_root) and not isinstance(patterns, list):
                extra_root = rebuild.workspace(integration.CLIENT) / 'out/RbxgsApp/overlay' / src.relative_to(native_root)
                files = sorted(set(files) | {p.relative_to(extra_root).as_posix()
                               for glob in patterns.split() for p in extra_root.glob(glob)
                               if not p.name.startswith('roc_')})
            sources = [tree / rel for rel in files if rel not in layer.get('exclude', [])]
            includes = [tree] + [rebuild._in_tree(libs._case_path(libs.LIBS / p), src, tree)
                                 for p in recipe.get('include', []) if p != 'WINSDK']
            defines = recipe.get('defines', '')
            flags = ' '.join([layer['flags']] + ['/FI' + p for p in recipe.get('preinclude', [])])
        else:
            recipe = libs.RECIPES[layer['includes_from_recipe']] if layer.get('includes_from_recipe') else {}
            includes = [(libs.LIBS / p).resolve() for p in recipe.get('include', []) if p != 'WINSDK']
            includes += [(rebuild.ROOT / p).resolve() for p in layer.get('extra_includes', [])]
            defines = libs.RECIPES[layer['defines_from_recipe']]['defines'] if layer.get('defines_from_recipe') else layer.get('defines', '')
            flags = layer['flags']
            sources = [p for glob in layer['files'].split() for p in sorted((rebuild.ROOT / layer['dir']).glob(glob))
                       if not p.name.startswith('roc_') and p.name not in layer.get('exclude', [])]
        yield dict(layer=layer, sources=sources, includes=includes,
                   defines=(defines + ' ' + layer.get('extra_defines', '')).strip(), flags=flags,
                   append=(rebuild.ROOT / layer['append_include']).resolve() if layer.get('append_include') else None)


def unit_output(plan, source, output):
    collisions = plan.setdefault('_collisions', {name for name, count in Counter(p.stem.casefold() for p in plan['sources']).items() if count > 1})
    return output/integration.digest(str(source.resolve()))[:16] if source.stem.casefold() in collisions else output


def affected(plan, changed, tree, output):
    """Unknown include history => compile conservatively; recorded deps prune warm runs."""
    selected = []
    changed_paths = {(tree / p).resolve() for p in changed}
    headers = {p for p in changed_paths if p.suffix.lower() not in ('.cpp', '.c')}
    for source in plan['sources']:
        deps = unit_output(plan, source, output) / (source.stem + '.deps')
        if source.resolve() in changed_paths or headers and not deps.exists():
            selected.append(source)
        elif headers:
            paths = {Path(p).resolve() for p in json.loads(deps.read_text())}
            # Compare vendor and overlay paths by tree-relative suffix.
            if {p.name.casefold() for p in paths} & {p.name.casefold() for p in headers}:
                selected.append(source)
    return selected


def evaluate(claim, candidate, level, output):
    from roc import native_sweep, native_search
    started = time.monotonic()
    base = claim['baseline']['overlay']
    changed = integration.overlay_delta(base, candidate) if base != candidate else {}
    report = dict(client=integration.CLIENT, claim=claim['id'], level=level, accepted=False,
                  grants_credit=False, changed_files=sorted(changed), units=[], diagnostics=[], targets={}, lost=[],
                  candidate_hash=integration.digest(candidate), base_revision=claim.get('base_revision'))
    if level not in ('fast', 'bytes', 'full') or not claim.get('addresses'):
        report.update(ok=False, reason='A valid check level and nonempty claimed targets are required')
        return report
    if not changed:
        report.update(ok=False, reason='No source changes')
        return report
    spec = rebuild.load_module(integration.CLIENT, integration.MODULE)
    registry = rebuild.ROOT / spec['overlay']['patches']
    registry.write_text(json.dumps(candidate))
    tree, overlay = rebuild.build_overlay(integration.CLIENT, spec['name'], spec['overlay'])
    plans = list(layer_plan(spec))
    selected = [(p, affected(p, changed, tree, output / 'candidate' / p['layer']['name'])) for p in plans]
    if not any(sources for _, sources in selected):
        report.update(ok=False, local_comparison='unavailable', reason='No affected translation unit found; linked verification required')
        return report
    protected = claim.get('protected_native')
    report['baseline_ownership_state'] = 'known' if protected is not None else 'unavailable'
    matcher = None
    if level != 'fast':
        manifest = rebuild.ROOT / 'rebuild/2008-06/manifests/functions.json'
        rows = json.loads(manifest.read_text())
        matcher = native_sweep.Matcher(set(claim['addresses']) | set(protected or []), output / 'matches')

    def compile_stage(stage, patches):
        integration.atomic_json(registry, patches)
        ov = rebuild.build_overlay(integration.CLIENT, spec['name'], spec['overlay'])
        hits, objects = set(), []
        for plan, sources in selected:
            layer = plan['layer']
            for source in sources:  # Serial avoids same-stem collisions and bounds compiler memory.
                if stage == 'baseline' and not source.exists() and not rebuild._twin(source, ov).exists():
                    continue  # A new TU has no existing baseline body to preserve.
                folder = unit_output(plan, source, output / stage / layer['name'])
                stamp = time.monotonic()
                result = rebuild.compile_direct(integration.CLIENT, [source], folder, plan['includes'],
                    plan['defines'], plan['flags'], cl=layer.get('cl', rebuild.BUILD), append=plan['append'], overlay=ov)
                ok, message = result[str(source)]
                if not ok and layer.get('fallback_cl'):
                    result = rebuild.compile_direct(integration.CLIENT, [source], folder, plan['includes'],
                        plan['defines'], layer['flags'], cl=layer['fallback_cl'], append=plan['append'], overlay=ov)
                    ok, message = result[str(source)]
                obj = folder / (source.stem + '.obj')
                row = dict(stage=stage, file=str(source), ok=ok, seconds=time.monotonic()-stamp,
                           compile_cache_hit=ok and message == 'content cache hit', object=str(obj))
                command_file = obj.with_suffix('.command.json')
                cache_file = obj.with_suffix('.compile.json')
                row['object_sha256'] = hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None
                row['input_signature'] = json.loads(cache_file.read_text()).get('inputs') if ok and cache_file.exists() else None
                row['command_sha256'] = hashlib.sha256(command_file.read_bytes()).hexdigest() if command_file.exists() else None
                report['units'].append(row)
                if not ok:
                    report['diagnostics'].extend(diagnostics(message, str(source)))
                    continue
                if matcher:
                    data = obj.read_bytes()
                    matched = matcher.scan(data)
                    if stage=='candidate':
                        from roc.native_refs import import_checks
                        for hit in matched:
                            if hit['addr'] in claim['addresses'] and hit.get('symbol'):
                                refs = import_checks(data,hit['symbol'],hit['addr'])
                                report.setdefault('references',{}).setdefault(hit['addr'],[]).extend(refs)
                    hits.update(h['addr'] for h in matched)
                    objects.append(data)
        return hits, objects

    baseline, _ = compile_stage('baseline', base) if matcher else (set(), [])
    found, objects = compile_stage('candidate', candidate)
    report['compile_ok'] = all(r['ok'] for r in report['units'])
    report['lost'] = sorted((baseline & set(protected or [])) - found)
    if matcher and report['compile_ok']:
        names = claim.get('native_names', {})
        for addr in claim['addresses']:
            row = dict(status='object_code_and_data_exact' if addr in found else 'not_established')
            if addr not in found and names.get(addr, {}).get('symbol'):
                symbol = names[addr]['symbol']
                for obj in objects:
                    if any(s == symbol for s, _, _ in native_sweep.match.coff_functions(obj)):
                        row.update(object_diagnostic(obj, addr, symbol))
                        row['status'] = 'mismatch'
                        break
            contradictions = [r for r in report.get('references',{}).get(addr,[]) if r['status']=='incorrect_symbol_reference']
            if contradictions:
                row.update(status='mismatch',category='incorrect_symbol_reference',first_mismatch=contradictions[0])
            report['targets'][addr] = row
    if report['lost']:
        report['diagnostics'].append(dict(category='native_regression', addresses=report['lost']))
    report['ok'] = report['compile_ok'] and not report['lost'] and (not matcher or protected is not None) and (not matcher or
        all(r['status'] == 'object_code_and_data_exact' for r in report['targets'].values()))
    report['requires_linked_verification'] = True  # Object exacts never establish final ownership.
    report['seconds'] = time.monotonic() - started
    return report


def summary(reports):
    units = [u for r in reports for u in r.get('units', [])]
    times = [u['seconds'] for u in units]
    return dict(checks=len(reports), local_successes=sum(bool(r.get('ok')) for r in reports),
                compile_success_rate=sum(u['ok'] for u in units)/len(units) if units else None,
                compile_mean_seconds=statistics.mean(times) if times else None,
                compile_median_seconds=statistics.median(times) if times else None,
                cache_hit_rate=sum(u.get('compile_cache_hit', False) for u in units)/len(units) if units else None,
                server_credits=0, throughput='Read native-search-status for independent server receipts')


def selected_claims(args, directory):
    choices = sum(bool(getattr(args, key, None)) for key in ('claim', 'batch', 'all'))
    if choices != 1:
        raise ValueError('Select --claim ID, --batch FILE, or --all')
    if getattr(args, 'claim', None):
        identifiers = [args.claim]
    elif getattr(args, 'batch', None):
        identifiers = json.loads(Path(args.batch).read_text(encoding='utf-8'))['claims']
    else:
        identifiers = sorted(p.parent.name for p in (directory / 'claims').glob('*/packet.json'))
    if (not isinstance(identifiers, list) or not 1 <= len(identifiers) <= integration.MAX_CLAIMS
            or any(not isinstance(i, str) or not re.fullmatch(r'[0-9a-f]{32}', i) for i in identifiers)
            or len(set(identifiers)) != len(identifiers)):
        raise ValueError('Need distinct valid local claim IDs')
    claims = [json.loads((directory / 'claims' / i / 'packet.json').read_text(encoding='utf-8')) for i in identifiers]
    if any(c.get('id') != identifier for c, identifier in zip(claims, identifiers)):
        raise ValueError('Packet identity differs from selected claim ID')
    first = claims[0]
    if len(claims) == 1:
        return first, directory / 'claims' / identifiers[0], claims
    if len({c.get('user') for c in claims}) != 1 or any(
            any(c['baseline'].get(k) != first['baseline'].get(k) for k in ('overlay', 'generator')) or c['base_revision'] != first['base_revision'] for c in claims):
        raise ValueError('Batch checks require one owner and identical baseline')
    protected = sorted({a for c in claims for a in c['protected_native']}) if all(c.get('protected_native') is not None for c in claims) else None
    combined = dict(first, protected_native=protected, id=integration.digest(sorted(identifiers))[:32],
                    addresses=sorted({a for c in claims for a in c['addresses']}), native_names={})
    for claim in claims:
        for addr, name in claim.get('native_names', {}).items():
            if addr in combined['native_names'] and combined['native_names'][addr] != name:
                raise ValueError('Conflicting native symbol evidence for ' + addr)
            combined['native_names'][addr] = name
    return combined, directory / 'check-batches' / combined['id'], claims


def command(args, fail=True):
    root = integration.ROOT
    directory = root / 'work/integration-client'
    claim, folder, claims = selected_claims(args, directory)
    if sum(bool(getattr(args, flag, False)) for flag in ('fast', 'bytes', 'full')) > 1:
        raise ValueError('Select one check level: --fast, --bytes, or --full')
    from roc import integrator, research
    # Lock only this claim. Different claims compile concurrently in private trees.
    with research.job_lock(folder / 'check.lock'):
        marker = folder / 'check-workspace.json'
        if marker.exists():
            private = Path(json.loads(marker.read_text())['workspace']).resolve()
            if not private.is_relative_to((root / 'local/integrators').resolve()) or private == (root / 'local/integrators').resolve():
                raise ValueError('Invalid local check workspace')
        else:
            private = integrator.workspace()
            integration.atomic_json(marker, dict(workspace=str(private)))
        owner = private / 'integrator-check.json'
        if owner.exists() and json.loads(owner.read_text()).get('claim') != claim['id']:
            raise ValueError('Private check workspace belongs to another claim batch')
        if not owner.exists():
            previous_claim = private / 'claim.json'
            if previous_claim.exists() and json.loads(previous_claim.read_text()).get('id') != claim['id']:
                raise ValueError('Private check workspace contains another claim')
            integration.atomic_json(owner, dict(claim=claim['id']))
        shutil.copytree(root / 'roc', private / 'roc', dirs_exist_ok=True, ignore=shutil.ignore_patterns('__pycache__'))
        shutil.copytree(root / 'rebuild/2008-06', private / 'rebuild/2008-06', dirs_exist_ok=True,
                        ignore=shutil.ignore_patterns('out', '__pycache__'))
        integration.atomic_json(private / 'claim.json', claim)
        if getattr(args, 'full', False):
            shutil.copy2(directory / 'claims' / claims[0]['id'] / 'generator-base.py', private / 'base-generator.py')
        level = 'fast' if args.fast else 'full' if getattr(args, 'full', False) else 'bytes'
        (private / 'work/local-check/result.json').unlink(missing_ok=True)
        (private / 'work/local-check/candidate-overlay.json').unlink(missing_ok=True)
        checked_generator = (private / 'rebuild/2008-06/patches/make_rbxgs_client.py').read_bytes()
        result = subprocess.run([sys.executable, '-m', 'roc.integration_local', level], cwd=private,
                                stdin=subprocess.DEVNULL)
        report_path = private / 'work/local-check/result.json'
        if not report_path.exists():
            raise RuntimeError('Local checker failed before producing diagnostics (exit %s)' % result.returncode)
        report = json.loads(report_path.read_text())
        if result.returncode:
            report.update(ok=False, process_exit=result.returncode)
        archive = folder / 'checks' / (uuid.uuid4().hex + '.json')
        sources = archive.with_suffix('')
        sources.mkdir(parents=True)
        (sources / 'generator.py').write_bytes(checked_generator)
        candidate_file = private / 'work/local-check/candidate-overlay.json'
        if candidate_file.exists():
            shutil.copy2(candidate_file, sources / 'candidate-overlay.json')
        for unit in report.get('units', []):
            obj = Path(unit['object']).resolve()
            if not obj.is_relative_to((private/'work/local-check').resolve()):
                continue
            for suffix in ('.command.json', '.compile.json', '.deps'):
                metadata = obj.with_suffix(suffix)
                if metadata.exists():
                    target = sources/'build-commands'/(integration.digest([unit['file'], unit['stage']])[:16]+suffix)
                    target.parent.mkdir(exist_ok=True)
                    shutil.copy2(metadata, target)
        report['source_snapshot'] = str(sources)
        report['claims'] = [c['id'] for c in claims]
        integration.atomic_json(archive, report)
        integration.atomic_json(folder / 'check.json', report)
        for item in claims:
            integration.atomic_json(directory / 'claims' / item['id'] / 'check.json', report)
        reports = [json.loads(p.read_text()) for p in (folder / 'checks').glob('*.json')]
        integration.atomic_json(folder / 'check-metrics.json', summary(reports))
        print(json.dumps(report, indent=1))
        print('Check evidence: ' + str(archive))
        if fail and not report['ok']:
            raise SystemExit(1)
        return report


def run_check(claim, candidate, level, output):
    report = evaluate(claim, candidate, level, output)
    if level == 'full' and (report.get('compile_ok') or report.get('local_comparison') == 'unavailable') and not report['lost'] and not any(
            r['status'] == 'mismatch' for r in report['targets'].values()):
        from roc.integration_verify import linked_preflight
        generator = rebuild.ROOT / 'rebuild/2008-06/patches/make_rbxgs_client.py'
        original = (rebuild.ROOT / 'base-generator.py').read_bytes()
        if claim['baseline'].get('generator') and hashlib.sha256(original).hexdigest() != claim['baseline']['generator']:
            raise ValueError('Saved baseline generator hash differs from claim')
        generator.write_bytes(original)
        integration.atomic_json(generator.with_name('native-promotions.json'), claim['baseline']['accepted'])
        integration.atomic_json(generator.with_name('rbxgs-client.json'), claim['baseline']['overlay'])
        try:
            report['linked_preflight'] = linked_preflight(rebuild.ROOT,
                integration.overlay_delta(claim['baseline']['overlay'], candidate), output)
            report['ok'] = report['linked_preflight']['accepted']
        except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
            report.update(ok=False, reason=str(error))
            report.setdefault('diagnostics', []).append(dict(category='linked_verification_failure', message=str(error)))
    return report


if __name__ == '__main__':
    output = rebuild.ROOT / 'work/local-check'
    output.mkdir(parents=True, exist_ok=True)
    (output / 'result.json').unlink(missing_ok=True)
    claim = json.loads((rebuild.ROOT / 'claim.json').read_text())
    try:
        integration.run_generator(rebuild.ROOT / 'rebuild/2008-06/patches/make_rbxgs_client.py', rebuild.ROOT)
        candidate = json.loads((rebuild.ROOT / 'rebuild/2008-06/patches/rbxgs-client.json').read_text())
        integration.atomic_json(output / 'candidate-overlay.json', candidate)
        report = run_check(claim, candidate, sys.argv[1], output)
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        report = locals().get('report', dict(accepted=False, grants_credit=False, diagnostics=[]))
        report.update(ok=False, reason=str(error))
        report['diagnostics'].extend(diagnostics(str(error)))
    integration.atomic_json(output / 'result.json', report)
    sys.exit(0 if report['ok'] else 1)

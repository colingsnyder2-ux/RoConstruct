"""Finish an agent-authored native batch without bypassing independent acceptance."""
import hashlib
import json
import os
import re
import subprocess
import uuid
from pathlib import Path

from roc import integration, match, rebuild, research, worker


def rebase_candidate(previous, current, candidate):
    """Carry independent appended recipes forward; conflicting anchors need an agent."""
    if previous.get('generator') != current.get('generator'):
        raise ValueError('Server generator changed; update and reconcile candidate first')
    candidate = integration.canonical_patches(candidate, current['overlay'])
    old = integration.canonical_patches(previous['overlay'], current['overlay'])
    changed = []
    for name in sorted(set(old) | set(current['overlay'])):
        before, after = old.get(name, []), current['overlay'].get(name, [])
        if before == after:
            continue
        ours = candidate.get(name, [])
        if ours == before:
            if name in current['overlay']:
                candidate[name] = after
            else:
                candidate.pop(name, None)
        elif ours[:len(after)] == after and after[:len(before)] == before:
            pass  # An earlier attempt already incorporated this accepted recipe.
        elif ours[:len(before)] == before and after[:len(before)] == before:
            additions, accepted = ours[len(before):], after[len(before):]
            for search, replacement in additions:
                for other_search, other_replacement in accepted:
                    if [search, replacement] == [other_search, other_replacement]:
                        continue
                    if (search and (search in other_search or search in other_replacement)
                            or other_search and (other_search in search or other_search in replacement)):
                        raise ValueError('Accepted recipe conflicts with local anchors: ' + name)
            candidate[name] = after + [pair for pair in additions if pair not in accepted]
        else:
            raise ValueError('Accepted recipe conflicts with local changes: ' + name)
        changed.append(name)
    return candidate, changed


def linked_proofs(client, targets, owners, objects, executable, map_file):
    """Prove retained module implementations, not unreferenced object copies."""
    import pefile
    pe = pefile.PE(str(executable))
    image, base = pe.get_memory_mapped_image(), pe.OPTIONAL_HEADER.ImageBase
    mapped = {}
    for line in map_file.read_text().splitlines():
        parts = line.split()
        if len(parts) >= 5 and ':' in parts[0] and re.fullmatch('[0-9a-fA-F]{8}', parts[2]) and parts[3] == 'f':
            mapped.setdefault(parts[1], []).append((int(parts[2], 16), parts[-1]))
    proofs = []
    for address in targets:
        target, relocations, _ = match.target(client, address)
        hits = []
        for owner in owners[address]:
            data = (objects / owner['object']).read_bytes()
            symbol = owner['symbol']
            functions = {s: (b, r) for s, b, r in match.coff_functions(data)}
            if symbol not in functions:
                continue
            rows = rebuild.pair_object(client, data, {symbol})
            if not any(address in addresses for _, _, addresses in rows):
                continue
            _, object_relocations = functions[symbol]
            for linked, origin in mapped.get(symbol, []):
                if origin != 'linked:' + owner['object']:
                    continue
                body = bytes(image[linked-base:linked-base+len(target)])
                hits.append(dict(symbol=symbol, owner=origin, linked_address='%08x' % linked,
                                 object_code_data_exact=True,
                                 code_exact=match.exact_match(target, relocations, body, object_relocations)))
        proofs.append(dict(target=address, linked_proofs=hits,
                           code_exact_in_executable=any(hit['code_exact'] for hit in hits)))
    return proofs


def source_packet(base, candidate, report, prior, added, model, evidence, known):
    candidate = integration.canonical_patches(candidate, base['overlay'])
    changes = {}
    for name, edits in candidate.items():
        before = base['overlay'].get(name, [])
        if edits != before:
            changes[name] = edits[len(before):] if edits[:len(before)] == before else dict(before=before, after=edits)
    if integration.merge_patches(base['overlay'], changes) != candidate:
        raise ValueError('Candidate removes accepted source paths')
    targets = sorted(set(prior.get('targets', [])) | set(added))
    if not targets or not set(targets) <= set(report['owned_addrs']) or not set(targets) <= known:
        raise ValueError('Packet witnesses need current ownership and known exact-mined targets')
    return dict(client='2008-06', base_revision=base['revision'], model=model, targets=targets,
                evidence=evidence, patches=changes, declarations=prior.get('declarations', []))


def verify_publication(git, commit, files):
    blobs = git('cat-file', '--batch', data=''.join(commit + ':' + name + '\n' for name in files).encode())
    offset = 0
    for expected in files.values():
        end = blobs.index(b'\n', offset)
        header = blobs[offset:end].split()
        if len(header) != 3 or header[1] != b'blob':
            raise ValueError('Publication artifact missing')
        size = int(header[2]); offset = end + 1
        if blobs[offset:offset+size] != expected:
            raise ValueError('Publication artifact differs from verified output')
        offset += size + 1


def publish(repo, folder, names, prefix, identity_root):
    """Publish only review artifacts using a private index; preserve accepted defaults."""
    if not re.fullmatch(r'2008-06/verification/[A-Za-z0-9_-]+', prefix):
        raise ValueError('Publication prefix must name a verification bundle')
    env = dict(os.environ)
    for kind in ('AUTHOR', 'COMMITTER'):
        identity = subprocess.check_output(['git', '-C', str(identity_root), 'var', 'GIT_' + kind + '_IDENT']).decode().strip()
        found = re.fullmatch(r'(.+) <([^>]+)> \d+ [+-]\d{4}', identity)
        if not found:
            raise ValueError('Git publication identity unavailable')
        env['GIT_' + kind + '_NAME'], env['GIT_' + kind + '_EMAIL'] = found.groups()
    def git(*args, data=None, indexed=False):
        return subprocess.check_output(['git', '-C', str(repo), *args], input=data,
                                       env=indexed_env if indexed else env, stderr=subprocess.PIPE)
    git('fetch', 'origin', 'main', '--quiet')
    base = git('rev-parse', 'refs/remotes/origin/main').decode().strip()
    package = json.loads(git('show', base + ':2008-06/package.json'))
    files = {prefix + '/' + name: (folder / name).read_bytes() for name in names}
    changed = False
    for name, data in files.items():
        key, digest = name.removeprefix('2008-06/'), hashlib.sha256(data).hexdigest()
        changed |= package['files'].get(key) != digest
        package['files'][key] = digest
    if not changed:
        verify_publication(git, base, files)
        return dict(commit=base, files=len(files), unchanged=True)
    files['2008-06/package.json'] = (json.dumps(package, indent=2, sort_keys=True) + '\n').encode()
    index = folder / ('publish-index-' + uuid.uuid4().hex)
    indexed_env = dict(env, GIT_INDEX_FILE=str(index.resolve()))
    try:
        git('read-tree', base, indexed=True)
        updates = []
        for name, data in files.items():
            blob = git('hash-object', '-w', '--stdin', data=data).decode().strip()
            updates.append('100644 ' + blob + '\t' + name + '\n')
        git('update-index', '--index-info', data=''.join(updates).encode(), indexed=True)
        tree = git('write-tree', '--missing-ok', indexed=True).decode().strip()
        commit = git('commit-tree', tree, '-p', base,
                     data=b'Publish independently reviewable native batch proofs\n').decode().strip()
        # Verify the committed artifacts in one bounded read before pushing.
        verify_publication(git, commit, files)
        git('push', 'origin', commit + ':refs/heads/main')
        return dict(commit=commit, files=len(files), verified=True)
    finally:
        index.unlink(missing_ok=True)


def run(config_file, log=print):
    config_file = Path(config_file).resolve()
    config = json.loads(config_file.read_text(encoding='utf-8'))
    root = rebuild.ROOT
    if (root / 'work/server.db').exists():
        raise ValueError('Use the existing private contributor checkout, not the server checkout')
    folder = (config_file.parent / config.get('output', 'finished')).resolve()
    folder.mkdir(parents=True, exist_ok=True)
    # One finisher per mutable checkout, including campaigns with different names.
    with research.job_lock(root / 'work/native-finish.lock'):
        integration.atomic_json(folder / 'state.json', dict(state='running'))
        try:
            return finish(config, config_file.parent, folder, log)
        except Exception as error:
            integration.atomic_json(folder / 'state.json', dict(state='failed', error=str(error)))
            raise


def finish(config, directory, folder, log):
    root, client = rebuild.ROOT, '2008-06'
    def read(name):
        return json.loads((directory / config[name]).read_text(encoding='utf-8'))
    model, user = config['model'], config['user']
    if not model.strip() or not user.strip():
        raise ValueError('Actual writer model and contributor required')
    before, expected = read('before'), read('baseline')
    source = (directory / config['test_source']).read_bytes()
    spec = rebuild.load_module(client, config.get('module', 'rbxgs-app'))
    if spec['name'] != 'RbxgsApp' or before.get('module') != spec['name']:
        raise ValueError('Native server source batches currently require coherent RbxgsApp')
    overlay_path = root / spec['overlay']['patches']
    overlay_bytes = overlay_path.read_bytes()
    settings = worker.load_settings()
    api = worker.Api(config.get('server') or settings['server'],
                     integration.native_token(root) or settings.get('native_token') or settings.get('token'))
    try:
        base = api.call('/v1/integration/base')
        if base['revision'] != expected['revision']:
            if not config.get('auto_rebase', True):
                raise ValueError('Server baseline advanced; preserve and rebase candidate before finishing')
            candidate, paths = rebase_candidate(expected, base, json.loads(overlay_bytes))
            backup = folder / ('overlay-before-rebase-' + hashlib.sha256(overlay_bytes).hexdigest() + '.json')
            if not backup.exists():
                backup.write_bytes(overlay_bytes)
            integration.atomic_json(overlay_path, candidate)
            overlay_bytes = overlay_path.read_bytes()
            integration.atomic_json(folder / 'rebase.json', dict(before=expected['revision'], after=base['revision'], paths=paths))
            log('Rebased independent accepted changes: ' + ', '.join(paths))
        report = rebuild.build_module(client, config.get('module', 'rbxgs-app'), log=log)
        if not report.get('linked') or report.get('test_exit') != 0 or report.get('unresolved'):
            raise ValueError('Module compile/link/runtime failed; nothing submitted')
        out = root / 'rebuild' / client / 'out'
        errors = {layer['name']: json.loads((out / spec['name'] / ('layer-' + layer['name']) / 'errors.json').read_text())
                  for layer in spec['layers']}
        integration.atomic_json(folder / 'compile-errors.json', errors)
        if any(errors.values()):
            raise ValueError('Source layer compile errors; nothing submitted')
        added = sorted(set(report['owned_addrs']) - set(before['owned_addrs']))
        lost = sorted(set(before['owned_addrs']) - set(report['owned_addrs']))
        comparison = dict(before=before['owned_2008'], after=report['owned_2008'], added=added, lost=lost)
        integration.atomic_json(folder / 'integrated-comparison.json', comparison)
        if lost or not added:
            raise ValueError('Ownership losses or no gains; nothing submitted')
        owners = json.loads((out / spec['name'] / 'owned-symbols.json').read_text())
        external = {o['object']: rebuild.coff_externals((out / spec['name'] / 'linked' / o['object']).read_bytes())
                    for address in added for o in owners[address]}
        roots = set(re.findall(rb'/INCLUDE:([^"\r\n]+)', source))
        # File-local helpers must be retained by their real callers in the fixture.
        roots = {symbol.decode() for symbol in roots} | {o['symbol'] for a in added for o in owners[a]
                                                       if external[o['object']].get(o['symbol'])}
        test_source = ('\n'.join('#pragma comment(linker, "/INCLUDE:' + s + '")' for s in sorted(roots)) + '\n').encode() + source
        test = 'native_finish_' + integration.digest(str(folder))[:12]
        (root / 'rebuild' / client / 'tests' / (test + '.cpp')).write_bytes(test_source)
        overlay = rebuild.build_overlay(client, spec['name'], spec['overlay'])
        includes = rebuild._overlaid([root / p for p in spec['test_includes']], [], overlay)[0]
        dependencies, seen, pending = [], set(), list(spec.get('depends', []))
        while pending:
            name = pending.pop(0)
            if name in seen:
                continue
            seen.add(name)
            dependency = rebuild.load_module(client, name)
            dependencies.append(out / dependency['name'] / 'linked/linked.lib')
            pending.extend(dependency.get('depends', []))
        objects = out / (test + '/linked')
        runtime = rebuild.resolve_objects(client, test, [out / spec['name'] / 'linked'], test + '/linked',
                                          includes=includes, extra_libs=dependencies, defines=spec['test_defines'],
                                          library_symbols=roots,
                                          generated_objects={Path(f).stem + '.obj' for layer in spec['layers']
                                                             if isinstance(layer.get('files'), list) for f in layer['files']})
        integration.atomic_json(folder / 'forced-runtime-result.json', runtime)
        if not runtime.get('linked') or runtime.get('exit') != 0:
            raise ValueError('Forced link/runtime failed; nothing submitted')
        executable = out / 'tests' / test / (test + '.exe')
        proofs = linked_proofs(client, added, owners, objects, executable, executable.with_suffix('.map'))
        integration.atomic_json(folder / 'linked-executable-proof.json', proofs)
        if not all(p['code_exact_in_executable'] for p in proofs):
            raise ValueError('Linked executable proofs failed; nothing submitted')
        if overlay_path.read_bytes() != overlay_bytes or (directory / config['test_source']).read_bytes() != source:
            raise ValueError('Inputs changed during verification; rerun before submitting')
        current = api.call('/v1/integration/base')
        if current['revision'] != base['revision']:
            raise ValueError('Server baseline advanced during verification; rebase first')
        known = {f['addr'] for f in json.loads((root / 'rebuild' / client / 'manifests/functions.json').read_text()) if f.get('score') == 100}
        prior = read('prior_packet') if config.get('prior_packet') else {}
        evidence = config['evidence']
        if base['revision'] != expected['revision']:
            evidence += '\nAutomatically rebased independent accepted recipes onto ' + base['revision']
            if prior:
                evidence += '; supersedes stale proposal ' + integration.digest(prior)
        packet = source_packet(base, json.loads(overlay_bytes), report, prior, added, model, evidence, known)
        for name, value in [('packet.json', packet), ('final-report.json', report), ('final-owned-symbols.json', owners),
                            ('candidate-overlay.json', json.loads(overlay_bytes)), ('candidate-module.json', spec),
                            ('server-base.json', base)]:
            integration.atomic_json(folder / name, value)
        (folder / 'forced-runtime.cpp').write_bytes(test_source)
        receipt = dict(state='locally-verified', verified=False, credits=0)
        if config.get('submit'):
            receipt = api.call('/v1/integration/type-proposals', dict(user=user, packet=packet))
        integration.atomic_json(folder / 'server-receipt.json', receipt)
    finally:
        api.close()
    delivery = None
    if config.get('notify'):
        from roc.owned_progress import record
        delivery = record(root, before, report, user, model,
                          public_root=directory / config.get('public_root', root), log=log)
        integration.atomic_json(folder / 'webhook-delivery.json', delivery)
    if config.get('publish_repo'):
        names = ['integrated-comparison.json', 'forced-runtime-result.json', 'linked-executable-proof.json',
                 'packet.json', 'final-report.json', 'final-owned-symbols.json', 'candidate-overlay.json',
                 'server-base.json', 'server-receipt.json', 'forced-runtime.cpp', 'compile-errors.json',
                 'candidate-module.json']
        if (folder / 'rebase.json').exists():
            names.append('rebase.json')
        published = publish(directory / config['publish_repo'], folder, names, config['publish_prefix'], root)
        integration.atomic_json(folder / 'publish-receipt.json', published)
    result = dict(state='finished', gained=len(added), lost=0, forced_roots=len(roots), server=receipt)
    if delivery is not None:
        result['webhook'] = delivery
    integration.atomic_json(folder / 'state.json', result)
    log(json.dumps(result))
    return result


def register(cmd):
    def command(args):
        try:
            run(args.config)
        except (ValueError, KeyError) as error:
            raise SystemExit(str(error)) from None
    cmd('native-finish', command, 'build/test/prove/submit/publish an agent-authored native batch',
        (['config'], {'help': 'JSON batch configuration; paths relative to this file'}))

"""Revalidate an accepted baseline in a private verifier snapshot without awarding credit."""
import json
import hashlib
import sqlite3
import shutil
import time
import uuid
from pathlib import Path

from roc import integration, integration_verify


def find_baseline(root, overlay):
    index = Path(root)/'work/integration/baselines/index.json'
    paths = list(json.loads(index.read_text()).values()) if index.exists() else []
    directory = (Path(root)/'work/integration').resolve()
    for name in reversed(paths):
        path = (Path(root)/name).resolve()
        if not path.is_relative_to(directory):
            continue
        registry = path/'rebuild/2008-06/patches/rbxgs-client.json'
        if (path/'integration-result.json').is_file() and registry.is_file() and json.loads(registry.read_text()) == overlay:
            return path
    raise ValueError('No accepted cache reproduces this overlay; finish baseline preparation on configured verifier first')


def audit(root, base, baseline=None, log=print, current_profile=False):
    root = Path(root)
    source = Path(baseline).resolve() if baseline else find_baseline(root, base['overlay'])
    registry = source/'rebuild/2008-06/patches/rbxgs-client.json'
    if json.loads(registry.read_text()) != base['overlay']:
        raise ValueError('Audit baseline overlay differs from current accepted server baseline')
    for name in ('tools','clients'):
        if (source/name).resolve() != (root/name).resolve():
            raise ValueError('Audit baseline must use this verifier installation: '+name)
    if base.get('generator') and hashlib.sha256((source/'rebuild/2008-06/patches/make_rbxgs_client.py').read_bytes()).hexdigest() != base['generator']:
        raise ValueError('Audit baseline generator differs from accepted source identity')
    before = json.loads((source/'integration-result.json').read_text())
    integration_verify.check_gates(before)
    folder = root/'work/integration-audit'/uuid.uuid4().hex
    started = time.monotonic()
    receipt = dict(accepted=False, grants_credit=False, base_revision=base['revision'], baseline=str(source),
                   snapshot=str(folder), source_changes=False, mode='current-profile' if current_profile else 'legacy-reproduction')
    try:
        live = integration_verify.input_hash(root, live_only=True)
        log('Snapshotting accepted inputs for isolated runtime audit: '+str(folder))
        integration_verify.snapshot(source, folder, link=True)
        # Current verifier, build profiles and runtime tests; accepted source overlays stay frozen.
        shutil.copytree(root/'roc', folder/'roc', dirs_exist_ok=True, ignore=shutil.ignore_patterns('__pycache__'))
        shutil.copy2(root/'roc.py', folder/'roc.py')
        shutil.copytree(root/'rebuild/2008-06', folder/'rebuild/2008-06', dirs_exist_ok=True,
                        ignore=shutil.ignore_patterns('out', 'patches', '__pycache__'))
        for name in ('functions.jsonl','bounds.json','vtables.json'):
            path = root/'work/2008-06'/name
            if path.exists():
                shutil.copy2(path,folder/'work/2008-06'/name)
        after = integration_verify.verify_build(folder, log)
        elsewhere = integration_verify.other_module_owned(folder)
        integration.atomic_json(folder/'audit-result.json', after)
        previous, current_owned = set(before['report']['owned_addrs']), set(after['report']['owned_addrs'])
        receipt['ownership'] = dict(before=len(previous), after=len(current_owned),
                                    lost=sorted(previous-current_owned), gained=sorted(current_owned-previous),
                                    uncovered=sorted(previous-current_owned-elsewhere))
        receipt['milestones'] = after['milestones']
        receipt['distinct'] = after['distinct']
        database = root/'work/server.db'
        if database.exists():
            with sqlite3.connect('file:'+database.as_posix()+'?mode=ro',uri=True) as db:
                credited = {row[0] for row in db.execute('SELECT addr FROM integration_credit WHERE client=?',(integration.CLIENT,))}
            receipt['accepted_references'] = integration_verify.check_credited(folder,after['report'],credited)
        receipt['legacy_inventory_reproduced'] = not receipt['ownership']['uncovered'] and after['distinct'] >= before['distinct']
        if current_profile:
            if not database.exists():
                raise ValueError('Current-profile audit requires the authoritative accepted-credit database')
            integration_verify.check_gates(after)
            integration_verify.check_abi(after, before)
        else:
            integration_verify.check_gates(after, before, elsewhere, require_gain=False)
        if integration_verify.input_hash(root, live_only=True) != live:
            raise ValueError('Read-through compiler/vendor inputs changed during audit')
        receipt.update(passed=True, unchanged_owned=sorted(set(before['report']['owned_addrs']) & set(after['report']['owned_addrs'])),
                       milestones=after['milestones'], distinct=after['distinct'])
        integration.atomic_json(folder/'audit-result.json', after)
    except (OSError, ValueError, RuntimeError) as error:
        receipt.update(passed=False, reason=str(error))
        raise
    finally:
        report = folder/'rebuild/2008-06/out/RbxgsApp/report.json'
        if report.exists():
            data = json.loads(report.read_text())
            receipt['module'] = {name: data.get(name) for name in ('linked', 'test_exit', 'unresolved', 'owned_2008')}
        receipt['seconds'] = time.monotonic()-started
        integration.atomic_json(folder/'audit-receipt.json', receipt)
        log('Baseline audit receipt: '+str(folder/'audit-receipt.json'))
    return receipt

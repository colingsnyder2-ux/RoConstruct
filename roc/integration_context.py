"""Bounded claim previews, complete on-demand evidence, transparent task ranking."""
import json
import re
from pathlib import Path
from urllib.parse import urlencode

from roc import integration


def rank(rows, names, paths, abi, mode='balanced', history=None):
    """Heuristic ordering, not a measured success probability or ABI proof."""
    size = sum(r.get('size', 256) for r in rows)
    confidence = sum(names.get(r['addr'], {}).get('score', 0) or 0 for r in rows) / len(rows)
    headers = sum(Path(p).suffix.lower() in ('.h', '.hpp') for p in paths)
    evidence = bool(abi)
    unresolved = sum(r.get('unresolved_dependencies', 0) for r in rows)
    virtual = sum(r.get('virtual_calls', 0) for r in rows)
    branches = sum(r.get('branches', 0) for r in rows)
    value = len(rows) * (1 + confidence / 100) * (1 + bool(headers) + evidence) / (1 + unresolved + virtual + branches/8)
    if history:
        value *= 2 * history['acceptance_probability']
        cost = history.get('median_verification_seconds')
        if cost is not None:
            value /= 1 + cost / 60
    if mode == 'easy':
        return (size / len(rows) * (1 + unresolved + virtual) / (1 + confidence / 100 + evidence), -value)
    if mode == 'large':
        return (-len(rows), -size, -value)
    return (-value / (1 + size / 256), -len(rows))


def context(promotions, identifier, addr):
    with promotions.store.lock:
        row = promotions.store.db.execute('SELECT unit,addresses,base FROM integration_claims WHERE id=?',
                                         (identifier,)).fetchone()
    if not row or addr not in json.loads(row[1]):
        raise ValueError('Function is not in this claim')
    promotions.catalog(row[0])  # Refresh native path index.
    root = promotions.root
    source = root / 'src' / integration.CLIENT / (addr + '.cpp')
    manifest = root / 'rebuild/2008-06/manifests/functions.json'
    function = next((r for r in json.loads(manifest.read_text()) if r['addr'] == addr), {})
    from roc import match
    text = source.read_text(errors='replace') if source.exists() else None
    result = dict(addr=addr, unit=row[0], base_revision=row[2], size=function.get('size'),
                  mining_score=function.get('score'), source=text, source_origin=str(source),
                  mining_score_is_cached_hint=True,
                  mined_compiler=match.directives(text) if text else {},
                  native_name=promotions.native_names().get(addr), native_files={}, assembly=None,
                  objective='Integrate this function using native declarations; preserve existing exact bodies. Server verification required.')
    if (root / 'clients/2008-06/Roblox.exe').exists():
        code, _, _ = match.target(integration.CLIENT, addr)
        result['assembly'] = match.disasm(code, int(addr, 16))
    # Current accepted native declarations are evidence; never snippet ABI stand-ins.
    with promotions.store.lock:
        baseline = promotions.store.db.execute('SELECT payload FROM integration_bases WHERE revision=?', (row[2],)).fetchone()
    if not baseline:
        raise ValueError('Claim baseline evidence is missing')
    patches = json.loads(baseline[0])['overlay']
    for name in sorted(promotions.native_paths.get(row[0], promotions.native_paths.get(row[0].rsplit('::', 1)[-1], []))):
        result['native_files'][name] = integration.overlay_text(root / 'tools/rbxgs/Client', name, patches)
    module = root / 'rebuild/2008-06/modules/rbxgs-app.json'
    from roc import rebuild
    result['native_profiles'] = [dict(layer, compiler_build=layer.get('cl', rebuild.BUILD))
                                 for layer in json.loads(module.read_text()).get('layers', [])] if module.exists() else []
    assembly = result['assembly'] or []
    names = promotions.native_names()
    calls = sorted({m[1].lower().zfill(8) for line in assembly
                    if (m := re.search(r'\b(?:call|jmp) 0x([0-9a-fA-F]+)\s*$', line))})
    result['dependencies'] = [dict(addr=a, native_name=names.get(a)) for a in calls if a != addr]
    abi = root / 'rebuild/2008-06/manifests/abi-evidence.json'
    result['abi'] = json.loads(abi.read_text()).get(row[0], {}) if abi.exists() else {}
    with promotions.store.lock:
        jobs = promotions.store.db.execute("SELECT id,state,receipt FROM integration_jobs WHERE instr(', '||unit||', ', ', '||?||', ')>0 ORDER BY updated DESC LIMIT 3",
                                          (row[0],)).fetchall()
    result['previous_jobs'] = [dict(id=i, state=s, receipt=json.loads(r or '{}')) for i, s, r in jobs]
    return result


def retrieve(api, directory, identifier, addr):
    if not re.fullmatch(r'[0-9a-f]{32}', identifier):
        raise ValueError('Invalid claim ID')
    addr = '%08x' % int(addr, 16)
    packet = directory / 'claims' / identifier / 'packet.json'
    claim = json.loads(packet.read_text(encoding='utf-8'))
    if addr not in claim['addresses']:
        raise ValueError('Function is not in this local claim')
    data = api.call('/v1/integration/context?' + urlencode(dict(claim=identifier, addr=addr)))
    folder = packet.parent / 'context' / addr
    references = dict(data)
    for name, text in data.get('native_files', {}).items():
        path = folder / 'native' / name
        if not path.resolve().is_relative_to((folder / 'native').resolve()):
            raise ValueError('Native evidence path escapes context folder')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding='utf-8')
        references.setdefault('native_paths', []).append(dict(path=str(path.resolve()), first_line=1,
                                                             last_line=len(text.splitlines())))
    references.pop('native_files', None)
    reference = data.get('mined_compiler', {}).get('lib', '')
    if reference:
        from roc import libs
        recipe, _, rel = reference.partition(' ')
        definition = libs.RECIPES.get(recipe, {})
        if definition.get('src') and rel.strip():
            root = libs._case_path(libs.LIBS / definition['src']).resolve()
            source = (root / rel.strip().replace('\\', '/')).resolve()
            if source.is_relative_to(root) and source.is_file():
                references['library_source_file'] = str(source)
    folder.mkdir(parents=True, exist_ok=True)
    for field, filename in (('source', 'mined.cpp'), ('assembly', 'target.asm')):
        value = references.pop(field, None)
        if value is not None:
            text = '\n'.join(value) if isinstance(value, list) else value
            path = folder / filename
            path.write_text(text, encoding='utf-8')
            references[field + '_file'] = dict(path=str(path.resolve()), first_line=1, last_line=len(text.splitlines()))
    history = packet.parent / 'check.json'
    if history.exists():
        references['previous_local_check'] = str(history.resolve())
    integration.atomic_json(folder / 'context.json', references)
    print(json.dumps(references, indent=1))
    return references

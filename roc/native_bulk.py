"""Whole-object native discovery and dependency-closed preflight planning.

Never activates a runtime provider or awards credit. Reference receipts supply
symbol identities, not executable instructions; every counted body is rechecked.
"""
import argparse
from bisect import bisect_left
import hashlib
import importlib.util
import json
import os
import re
import struct
import time
from pathlib import Path

from roc import integration, match, native_promotion, rebuild

ROOT = Path(__file__).resolve().parents[1]
VERSION = 2


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True).encode()).hexdigest()


def sha(path):
    path = Path(path)
    return hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None


# Only files an #include can resolve to may shadow a fallback include. New .cpp/.obj/.log files cannot, and counting them
# made every native class stale whenever anyone added a source file (full-census recompiles).
INCLUDABLE = ('.h', '.hpp', '.hxx', '.inl', '.inc', '.tlh', '.tli', '.rc', '.idl')


def search_inventory(directories):
    # File creation can shadow an unchanged fallback include without changing it.
    result = {}
    for path in sorted(set(Path(d).resolve() for d in directories)):
        if path.is_dir():
            files = [os.path.relpath(os.path.join(folder, name), path)
                     for folder, _, names in os.walk(path) for name in names
                     if name.lower().endswith(INCLUDABLE) or '.' not in name]
            result[str(path)] = digest(sorted(files))
    return result


def address(value):
    number = int(str(value), 16)
    if not 0 <= number <= 0xffffffff:
        raise ValueError('address outside 32-bit target')
    return f'{number:08x}'


def project_path(root, value):
    path = (root / value).resolve()
    if not path.is_relative_to(root.resolve()):
        raise ValueError('input escapes project: ' + str(value))
    return path


def records(value):
    """Find verified rows in existing family receipts, excluding pending lanes."""
    if isinstance(value, dict):
        if value.get('exact') is False or value.get('pending_build') or value.get('exact_pending_build_only'):
            return
        if value.get('symbol') and value.get('address') and '+' not in str(value['address']):
            yield value
        for key, child in value.items():
            if not any(word in key.lower() for word in ('pending', 'non_exact', 'not_exact', 'not_attempted', 'blocked', 'rejected')):
                yield from records(child)
    elif isinstance(value, list):
        for child in value:
            yield from records(child)


def seed_evidence(root, paths, strict_conflicts=True):
    symbols, bindings, blockers, inputs = {}, {}, [], {}
    receipts, rejected = [], set()
    def bind(symbol, target):
        target = address(target)
        if (symbol, target) in rejected:
            return False
        if symbol in bindings and bindings[symbol] != target:
            bindings[symbol] = None
        else:
            bindings[symbol] = target
        return True
    for name in paths:
        path = project_path(root, name)
        inputs[str(path)] = sha(path)
        if not path.is_file():
            blockers.append('missing reference receipt: ' + name)
            continue
        receipt = json.loads(path.read_text(encoding='utf-8'))
        stale = []
        for source, expected in receipt.get('sources', {}).items():
            item = project_path(root, source)
            inputs[str(item)] = sha(item)
            if inputs[str(item)] != expected:
                stale.append(source)
        if stale:
            blockers.append('stale reference receipt: ' + name + ': ' + ', '.join(stale))
            continue
        if receipt.get('layout_pending'):
            blockers.append('layout remains blocked: ' + name)
        receipts.append(receipt)
        for row in (() if receipt.get('layout_pending') else receipt.get('rejected_identities', [])):
            if row.get('symbol') and row.get('address'):
                rejected.add((row['symbol'], address(row['address'])))
    for receipt in receipts:
        for row in records(receipt):
            symbol, target = row['symbol'], address(row['address'])
            if not bind(symbol, target):
                continue
            symbols.setdefault(symbol, set()).add(target)
            for reference, value in row.get('bindings', row.get('verified_targets', {})).items():
                hit = re.match(r'^(0x[0-9a-fA-F]+|[0-9a-fA-F]{8})(?:$|\s|\()', str(value))
                if hit and bind(reference, hit[1]):
                    symbols.setdefault(reference, set()).add(address(hit[1]))
    for symbol, target in bindings.items():
        if target is None:
            symbols.pop(symbol, None)
            if strict_conflicts:
                blockers.append('conflicting reference identity: ' + symbol)
    return symbols, bindings, blockers, inputs


class Targets:
    """Index original bodies once; full comparison still decides every hit."""
    def __init__(self, client, selected=None):
        from roc.native_sweep import Matcher
        inventory = match._functions(client)
        addresses = list(selected) if selected else list(inventory)
        self.matcher = Matcher(addresses, client=client)
        self.client = client
        self.base, self.image = match._image(client)
        self.relocs = match._base_relocs(client)
        self.sorted_relocs = sorted(self.relocs)
        self.identity = digest([hashlib.sha256(self.image).hexdigest(), inventory])

    def candidates(self, body, relocs):
        # Tiny shared returns remain suggestions unless a reference receipt names them.
        return self.matcher.candidates(body, relocs)

    def body(self, addr):
        code, relocs, _ = match.target(self.client, addr)
        return code, relocs

    def data(self, va, size):
        offset = va - self.base
        if offset < 0 or offset + size > len(self.image):
            raise ValueError('reference outside original image')
        return bytes(self.image[offset:offset + size])

    def data_relocations(self, va, size):
        a, b = bisect_left(self.sorted_relocs, va), bisect_left(self.sorted_relocs, va + size)
        return {r - va for r in self.sorted_relocs[a:b]}


_IMPORT_SLOTS = None


def import_slots():
    """{address: 'Name'} for IAT slots the PE import table names (registry kind import-table): authoritative, unlike reference votes."""
    global _IMPORT_SLOTS
    if _IMPORT_SLOTS is None:
        _IMPORT_SLOTS = {}
        path = Path(__file__).resolve().parents[1] / 'work/2008-06/identity-registry.json'
        try:
            for addr, row in json.loads(path.read_text()).items():
                if any(e.get('kind') == 'import-table' for e in row.get('evidence', [])) and '!' in row.get('name', ''):
                    _IMPORT_SLOTS[int(addr, 16)] = row['name'].split('!', 1)[1]
        except (OSError, ValueError):
            pass
    return _IMPORT_SLOTS


def audit_references(raw, symbol, body, target, target_relocs, va, targets, bindings):
    """Check every relocation and initialized-data edge; unknown is a blocker."""
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    errors, references, visited = [], [], set()

    def reference(index, stored, original, depth=0):
        name, value, number, _ = symbols[index]
        base = (original - stored) & 0xffffffff
        known = bindings.get(name)
        if name in bindings and known is None:
            errors.append('conflicting reference identity: ' + name)
            return
        literal = re.fullmatch(r'__real@([0-9a-fA-F]{8}|[0-9a-fA-F]{16})', name)
        is_local_literal = False
        if literal and stored == 0 and number > 0:
            table = sections[number - 1]
            encoded = bytes.fromhex(literal.group(1))[::-1]
            is_local_literal = (table[0].rstrip(b'\0') == b'.rdata' and
                                not table[9] & 0x80000000 and value == 0 and
                                table[3] == len(encoded) and table[4] and
                                raw[table[4]:table[4] + len(encoded)] == encoded and
                                table[7] == 0)
        is_tu_guard = name.startswith('??_B?') or bool(re.match(r'\?[\w$]+@\?\d+\?\?', name))   # function-local static guard: one per translation unit, its address differs per TU
        imported = re.match(r'__imp__(\w+?)(@\d+)?$', name)
        if imported and import_slots().get(base) == imported.group(1):
            is_tu_guard = True      # the PE import table itself says this slot is that API: wins over a conflicting reference vote
        if number > 0 and raw[struct.unpack_from('<I', raw, 8)[0] + 18 * index + 16] == 3:
            is_tu_guard = True      # internal-linkage data defined here (header `static const`): one copy per TU; its bytes are still compared below
        if known is not None and int(known, 16) != base and not is_local_literal and not is_tu_guard:
            errors.append('reference identity differs: %s (bound %s, original reference %08x)' % (name, known, base))
            return
        if number - 1 == section and known is None and base == (va + value - start) & 0xffffffff:
            return      # a label in the audited function's own section (switch table $LN): placed with the body
        if number <= 0 or sections[number - 1][9] & 0x20:
            if known is None:
                errors.append('unproven reference identity: ' + name)
            return
        table = sections[number - 1]
        rawsize, rawptr = table[3], table[4]
        following = [v for _, v, n, _ in symbols.values() if n == number and v > value]
        end = min(following + [rawsize])
        begin = value + stored
        # begin == end: a pointer one past the array. begin < value: the compiler folded a loop index into the displacement
        # (times[i - 1] is addressed as times - 8 + i * 8); begin past the end (up to 1 KB) is the same fold in the other direction.
        # All three anchor at the symbol; the whole symbol is then verified.
        if ((begin == end and stored > 0) or (stored < 0 and begin < value) or (stored > 0 and end < begin <= end + 1024)) and value < end and depth <= 6:
            reference(index, 0, base, depth + 1)
            return
        if depth > 6 or not value <= begin < end:
            errors.append('unproven data span: ' + name)
            return
        key = (index, original, begin)
        if key in visited:
            return
        visited.add(key)
        native = raw[rawptr + begin:rawptr + end] if rawptr else bytes(end - begin)
        expected = targets.data(original, len(native))
        offsets = []
        for offset, nested, kind in relocations(table):
            if begin <= offset < end:
                at = offset - begin
                if kind != 6 or at + 4 > len(native) or original + at not in targets.relocs:
                    errors.append('unsupported data relocation: ' + name)
                    continue
                offsets.append(at)
                reference(nested, struct.unpack_from('<i', native, at)[0],
                          struct.unpack_from('<I', expected, at)[0], depth + 1)
        original_offsets = targets.data_relocations(original, len(native))
        if not original_offsets <= set(offsets) or not match.exact_match(expected, original_offsets, native, offsets):
            errors.append('referenced data differs: ' + name)

    def relocations(table):
        return [struct.unpack_from('<IIH', raw, table[5] + i * 10) for i in range(table[7])]

    offsets = []
    for offset, index, kind in relocations(sections[section]):
        at = offset - start
        if not 0 <= at < len(body):
            continue
        if at + 4 > len(body) or kind not in (6, 20):
            errors.append('unsupported code relocation')
            continue
        if kind == 6 and at not in target_relocs:
            errors.append('absolute field is not relocated in original')
            continue
        offsets.append(at)
        original = struct.unpack_from('<I', target, at)[0] if kind == 6 else (
            va + at + 4 + struct.unpack_from('<i', target, at)[0]) & 0xffffffff
        stored = struct.unpack_from('<i', body, at)[0]
        name = symbols[index][0]
        references.append({'symbol': name, 'address': address(f'{(original - stored) & 0xffffffff:x}'),
                           'kind': kind, 'offset': at, 'external': symbols[index][2] <= 0,
                           'requires_provider': symbols[index][2] <= 0 or bool(sections[symbols[index][2] - 1][9] & 0x20)})
        reference(index, stored, original)
    if not set(target_relocs) <= set(offsets):
        errors.append('original relocated fields missing from object')
    return references, sorted(set(errors))


def harvest(raw, targets, names, bindings):
    rows = []
    for symbol, body, relocs in match.coff_functions(raw):
        started = time.monotonic()
        candidates = set(names.get(symbol, ()))
        if len(body) >= 6:
            candidates.update(targets.candidates(body, relocs))
        analogs, proven, rejections = [], [], []
        for addr in sorted(candidates):
            try:
                target, original_relocs = targets.body(addr)
            except (KeyError, ValueError, SystemExit):
                continue  # a named data target is not a function candidate
            if len(target) != len(body) or not set(original_relocs) <= set(relocs) or not match.exact_match(target, original_relocs, body, relocs):
                continue
            analogs.append(addr)
            # Exact bytes alone cannot assign a constructor, tiny alias or library helper an identity.
            if symbol in bindings and bindings[symbol] is None:
                rejections.append({'addr': addr, 'errors': ['conflicting symbol identity: ' + symbol]})
                continue
            if addr not in names.get(symbol, ()):
                rejections.append({'addr': addr, 'errors': ['symbol identity not established by current reference evidence']})
                continue
            try:
                refs, errors = audit_references(raw, symbol, body, target, original_relocs, int(addr, 16), targets, bindings)
            except (KeyError, ValueError, struct.error) as error:
                refs, errors = [], ['unproven reference: ' + str(error)]
            if not errors:
                proven.append({'addr': addr, 'references': refs})
            else:
                rejections.append({'addr': addr, 'errors': errors})
        row = {'symbol': symbol, 'size': len(body), 'body_sha256': hashlib.sha256(body).hexdigest(),
               'candidates': analogs, 'rejections': rejections,
               'status': 'ambiguous' if len(proven) > 1 else 'inactive_exact' if proven else 'draft'}
        if len(proven) == 1:
            row.update(proven[0])
            row['identity'] = digest([body.hex(), row['references']])
        row['verification_seconds'] = round(time.monotonic() - started, 6)
        rows.append(row)
    return rows


def checker():
    path = ROOT / 'rebuild/2008-06/tests/native_check_runner.py'
    spec = importlib.util.spec_from_file_location('_bulk_native_checker', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def run(config, output, root=ROOT):
    output = Path(output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    lock = output / 'run.lock'
    claim = lock.open('x')
    try:
        with claim:
            return _run(config, output, root)
    finally:
        lock.unlink()


def _run(config, output, root=ROOT):
    root, output = Path(root).resolve(), Path(output).resolve()
    if config.get('client', '2008-06') != '2008-06':
        raise ValueError('initial bulk compiler profile supports 2008-06 only')
    output.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    ledger_path = output / 'ledger.json'
    ledger = json.loads(ledger_path.read_text()) if ledger_path.exists() else {}
    previous_path = output / 'manifest.json'
    previous = json.loads(previous_path.read_text()) if previous_path.exists() else {}
    previous_addresses = {r['addr'] for f in previous.get('families', []) for r in f['symbols'] if r['status'] == 'inactive_exact'}
    runner = checker()
    compiler = int(config.get('roc_cl', 21022))
    if compiler not in (50727, 21022):
        raise ValueError('unsupported roc_cl; expected 50727 or 21022')
    tc = rebuild.toolchain(compiler)
    tools = {str(p): sha(p) for p in (Path(__file__), Path(match.__file__), Path(native_promotion.__file__),
                                    ROOT / 'roc/delink.py', ROOT / 'roc/native_work.py', ROOT / 'roc/native_sweep.py',
                                    Path(rebuild.__file__), ROOT / 'roc/graph.py', Path(runner.__file__), Path(tc['cl']))}
    for name in ('c1xx.dll', 'c2.dll', 'mspdb80.dll', 'mspdb90.dll'):
        path = Path(tc['cl']).parent / name
        tools[str(path)] = sha(path)
    targets = Targets('2008-06', config.get('targets'))
    families, baseline, manifests = [], {}, []
    compiles, parked, reused, total_symbols, exact = 0, 0, 0, 0, set()
    compile_seconds, proof_seconds = 0.0, 0.0
    for spec in config.get('families', []):
        name = spec['name']
        if not re.fullmatch(r'[A-Za-z0-9_.-]+', name):
            raise ValueError('family name must be a filename-safe label')
        names, bindings, blockers, evidence_inputs = seed_evidence(root, spec.get('evidence', []), strict_conflicts=False)
        providers, requires, jobs = [], set(spec.get('requires', [])), []
        family_rows, family_inputs, family_exact = [], dict(evidence_inputs), set()
        per_source_inputs = {}
        for source_name in spec['sources']:
            source = project_path(root, source_name)
            if source.suffix != '.cpp' or not source.is_file():
                blockers.append('missing genuine source: ' + source_name)
                continue
            # Immutable draft copy is review data; compile the original location for quoted includes.
            source_bytes = source.read_bytes()
            draft_hash = hashlib.sha256(source_bytes).hexdigest()
            draft = output / 'drafts' / name / (digest([source_name, draft_hash])[:24] + '-' + source.name)
            draft.parent.mkdir(parents=True, exist_ok=True)
            if draft.exists() and sha(draft) != draft_hash:
                raise ValueError('draft snapshot differs from fingerprint: ' + str(draft))
            if not draft.exists():
                draft.write_bytes(source_bytes)
            key = name + ':' + source_name
            flags = runner.compiler_flags(source)
            search = search_inventory([source.parent] + [Path(f[2:]) for f in flags if f.startswith('/I')])
            prior = ledger.get(key, {})
            control = digest([VERSION, source_name, flags, tools, search])
            fresh = prior.get('control') == control and prior.get('inputs') and all(
                sha(Path(p)) == expected for p, expected in prior['inputs'].items())
            if fresh and prior.get('status') == 'failed':
                parked += 1
                family_inputs.update(prior['inputs'])
                blockers.append(prior.get('error', 'unchanged failed compile'))
                continue
            result = prior
            if fresh and sha(prior.get('object', '')) == prior.get('object_sha256'):
                reused += 1
            else:
                folder = output / 'objects' / (digest([key, time.time_ns()])[:16])
                folder.parent.mkdir(parents=True, exist_ok=True)
                result = runner.compile_job({'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}, folder, tc)
                compiles += 1
                compile_seconds += result.get('compile_seconds', 0)
                inputs = dict(result.get('dependencies', {}))
                inputs[str(source)] = result.get('source_sha256', draft_hash)
                log = (folder / 'compile.log').read_text(encoding='utf-8') if (folder / 'compile.log').exists() else ''
                for included in re.findall(r'^\s*Note: including file:\s*(.*?)\s*$', log, re.M):
                    path = Path(included).resolve()
                    inputs[str(path)] = sha(path)
                for missing in re.findall(r"Cannot open include file:\s*'([^']+)'", log):
                    # Missing declarations wake on creation; no endless identical compiler failures.
                    for directory in [source.parent] + [Path(f[2:]) for f in flags if f.startswith('/I')]:
                        path = directory / missing
                        inputs[str(path)] = sha(path)
                result.update(control=control, inputs=inputs, include_search=search)
                ledger[key] = result
            family_inputs.update(result.get('inputs', {}))
            per_source_inputs[str(source)] = dict(result.get('inputs', {}))
            if result.get('status') != 'complete':
                blockers.append(result.get('error', 'compile failed'))
                continue
            if draft_hash != result.get('source_sha256'):
                blockers.append('source changed between draft copy and compile: ' + source_name)
                continue
            raw = Path(result['object']).read_bytes()
            signature = digest([result['object_sha256'], targets.identity,
                                {k: sorted(v) for k, v in names.items()}, bindings, tools])
            rows = result.get('harvest_rows') if result.get('harvest_signature') == signature else None
            if rows is None:
                proof_started = time.monotonic()
                rows = harvest(raw, targets, names, bindings)
                proof_seconds += time.monotonic() - proof_started
                result.update(harvest_rows=rows, harvest_signature=signature)
            total_symbols += len(rows)
            family_rows.extend(rows)
            checks = []
            for row in rows:
                if row['status'] != 'inactive_exact':
                    continue
                family_exact.add(row['addr'])
                checks.append({'addr': row['addr'], 'symbol': row['symbol']})
                providers.append({'symbol': row['symbol'], 'address': row['addr'], 'identity': row['identity']})
                requires.update(r['symbol'] for r in row['references'] if r.get('requires_provider', r['external']))
            jobs.append({'source': str(source), 'checks': checks, 'object': result['object'],
                         'source_sha256': sha(source), 'object_sha256': result['object_sha256'],
                         'include_search': result.get('include_search', {})})
            if search_inventory(search) != search:
                blockers.append('include search changed during compile: ' + source_name)
                # New shadow headers make this batch's proof stale even if prior headers did not change.
                family_inputs[str(source)] = 'include-search-changed'
        for symbol, addr in bindings.items():
            if addr is None:
                continue
            if symbol in baseline and baseline[symbol]['address'] != addr:
                raise ValueError('conflicting original symbol identity across families: ' + symbol)
            baseline[symbol] = {'address': addr, 'identity': 'original:' + targets.identity + ':' + addr,
                                'origin': 'original-image'}
        # An explicit ABI/layout blocker can park a source-exact family; it is never guessed away.
        blockers.extend(spec.get('blockers', []))
        changed = [p for p, expected in family_inputs.items() if sha(p) != expected]
        # A long batch (hundreds of sources) always overlaps somebody's edits. Void only the sources whose own inputs changed;
        # append-only evidence (inferred names, new reference bindings) never invalidates a byte-exact body.
        used = {p for inputs in per_source_inputs.values() for p in inputs}
        append_only = [p for p in changed if p not in used and Path(p).name.startswith(('inferred-name-identities', 'reference-bindings-'))]
        hard = [p for p in changed if p not in used and p not in append_only]
        if changed and (hard or not per_source_inputs):
            blockers.append('inputs changed during batch: ' + ', '.join(changed))
            providers = []
            for row in family_rows:
                if row['status'] == 'inactive_exact':
                    row['status'] = 'stale'
            for job in jobs:
                job['checks'] = []
        else:
            touched = {p for p in changed if p in used}
            stale_sources = {src for src, inputs in per_source_inputs.items() if touched & set(inputs)}
            if stale_sources:
                blockers.append('inputs changed during batch for %d source(s): %s' % (len(stale_sources), ', '.join(sorted(stale_sources)[:5])))
                dropped = set()
                for job in jobs:
                    if job['source'] in stale_sources:
                        dropped.update((c['addr'], c['symbol']) for c in job['checks'])
                        job['checks'] = []
                for row in family_rows:
                    if (row.get('addr'), row['symbol']) in dropped and row['status'] == 'inactive_exact':
                        row['status'] = 'stale'
                family_exact = {a for a in family_exact if not any(d[0] == a for d in dropped)}
                providers = [x for x in providers if (x['address'], x['symbol']) not in dropped]
            exact.update(family_exact)
        state = 'inactive_exact' if providers else 'compiled' if jobs else 'draft'
        families.append({'name': name, 'status': state, 'providers': providers,
                         'requires': sorted(requires), 'needs': spec.get('needs', []), 'blockers': sorted(set(blockers))})
        manifests.append({'name': name, 'state': state, 'inputs': family_inputs, 'jobs': jobs,
                          'symbols': family_rows, 'blockers': sorted(set(blockers))})
    if any(sha(p) != expected for p, expected in tools.items()):
        exact.clear()
        for family, manifest in zip(families, manifests):
            family.update(status='compiled', providers=[])
            family['blockers'].append('verification tool changed during batch')
            manifest['state'] = 'compiled'
            manifest['blockers'].append('verification tool changed during batch')
            for row in manifest['symbols']:
                if row['status'] == 'inactive_exact':
                    row['status'] = 'stale'
            for job in manifest['jobs']:
                job['checks'] = []
    promotion = native_promotion.plan(families, baseline)
    elapsed = max(time.monotonic() - started, .000001)
    new_addresses = exact - previous_addresses
    report = {'schema': VERSION, 'client': '2008-06', 'roc_cl': compiler, 'families': manifests,
              'target_identity': targets.identity, 'tools': tools, 'promotion': promotion,
              'metrics': {'seconds': round(elapsed, 3), 'compile_invocations': compiles, 'reused_objects': reused,
                          'compile_seconds_this_run': round(compile_seconds, 3),
                          'proof_seconds_this_run': round(proof_seconds, 3),
                          'parked_unchanged_failures': parked, 'emitted_symbols': total_symbols,
                          'inactive_distinct_addresses': len(exact),
                          'new_inactive_distinct_addresses': len(new_addresses),
                          'inactive_addresses_per_hour': round(len(new_addresses) * 3600 / elapsed, 2),
                          'lost_inactive_addresses': sorted(previous_addresses - exact),
                          'server_accepted_addresses_per_hour': None},
              'scope': 'Local inactive body/data/reference proofs and preflight queue only. '
                       'No runtime activation, complete class ABI proof, server submission or credit.'}
    integration.atomic_json(ledger_path, ledger)
    integration.atomic_json(output / 'manifest.json', report)
    integration.atomic_json(output / 'checks.json', {'jobs': [j for f in manifests for j in f['jobs']]})
    integration.atomic_json(output / 'providers.json', promotion)
    return report


def prepare_link(report, output):
    """Consume only fresh, selected slices; link diagnostic scaffold, never run it."""
    from roc import delink
    output = Path(output).resolve()
    def require_fresh():
        inputs = dict(report['tools'])
        for family in report['families']:
            inputs.update(family['inputs'])
            for job in family['jobs']:
                inputs[job['object']] = job['object_sha256']
                if search_inventory(job.get('include_search', {})) != job.get('include_search', {}):
                    raise ValueError('include search changed before preflight: ' + job['source'])
        changed = [p for p, expected in inputs.items() if sha(p) != expected]
        if changed or Targets(report['client']).identity != report['target_identity']:
            raise ValueError('stale preflight inputs: ' + ', '.join(changed))
    require_fresh()
    ready = {name for batch in report['promotion']['batches'] if batch['ready_for_preflight'] for name in batch['families']}
    allowed = {}
    for family in report['families']:
        if family['name'] not in ready:
            continue
        rows = {row['symbol']: row for row in family['symbols'] if row['status'] == 'inactive_exact'}
        for job in family['jobs']:
            for check in job['checks']:
                selected = report['promotion']['selected_providers'].get(check['symbol'], {})
                if selected.get('origin') == 'native' and selected['owner'] == family['name']:
                    row = rows[check['symbol']]
                    if row['addr'] != check['addr'] or row['identity'] != selected['identity']:
                        raise ValueError('provider selection differs from proof')
                    allowed.setdefault(str(Path(job['object']).resolve()), {})[check['symbol']] = int(check['addr'], 16)
    if not allowed:
        raise ValueError('no fresh dependency-ready providers to preflight')
    if output.exists():
        raise ValueError('preflight output must be new: ' + str(output))
    output.mkdir(parents=True)
    # Preserve the original's unique dependencies, data and imports in orig.obj.
    delink.delink(report['client'], output)
    slots = json.loads((output / 'slots.json').read_text())
    candidates = sorted({va for symbols in allowed.values() for va in symbols.values()})
    selection = delink.bind_objects(report['client'], list(allowed), candidates, slots, output, allowed=allowed)
    integration.atomic_json(output / 'selection.json', selection)
    allowed_at = {}
    for symbols in allowed.values():
        for symbol, va in symbols.items():
            allowed_at.setdefault(va, set()).add(symbol)
    selected = {va: symbol for va, symbol in selection['swaps']}
    def approved_symbol(va, symbol):
        names = allowed_at.get(va, set())
        return symbol in names or any(symbol == name + '$roc_%08x' % va for name in names)
    unexpected = sorted((va, symbol) for va, symbol in selected.items()
                        if not approved_symbol(va, symbol))
    if selection['problems'] or unexpected:
        raise ValueError('delink selected an unapproved provider; see selection.json')
    # Folded/template-equivalent bodies can be exact at several approved VAs.  Do
    # not choose among them: omit every ambiguous address from this diagnostic.
    # The link remains a partial, inactive measurement until those identities are
    # independently bound.
    blocked = sorted(set(candidates) - set(selected))
    scaffold = delink.delink(report['client'], output, selection['swaps'], selection['exports'])
    integration.atomic_json(output / 'delink.json', scaffold)
    code, log = delink.link(output, selection['objects'], name='bulk-diagnostic.exe')
    (output / 'link.log').write_text(log, encoding='utf-8')
    require_fresh()
    result = {'status': ('diagnostic_linked' if not blocked else 'diagnostic_linked_partial') if code == 0 else 'link_failed', 'exit': code,
              'selected_addresses': len(selected), 'blocked_ambiguous_addresses': len(blocked),
              'ambiguous_symbols': len(selection['ambiguous']), 'manifest_identity': digest(report),
              'scope': 'Never executed. No ABI/runtime/P5/P6/server acceptance or source credit.'}
    integration.atomic_json(output / 'preflight.json', result)
    return result


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('config', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--prepare-link', type=Path, help='new diagnostic link directory; executable is never run')
    args = parser.parse_args(argv)
    result = run(json.loads(args.config.read_text(encoding='utf-8')), args.out)
    if args.prepare_link:
        result['preflight'] = prepare_link(result, args.prepare_link)
    print(json.dumps({'metrics': result['metrics'], 'batches': result['promotion']['batches'],
                      'preflight': result.get('preflight'), 'scope': result['scope']}, indent=2))
    if result.get('preflight', {}).get('exit'):
        raise SystemExit(result['preflight']['exit'])


def register(cmd):
    cmd('native-bulk', lambda a: main([a.config, '--out', a.out] + (['--prepare-link', a.prepare_link] if a.prepare_link else [])),
        'compile whole native sources, generate inactive proofs and dependency preflight queues',
        (['config'], {}), (['--out'], {'required': True}), (['--prepare-link'], {}))


if __name__ == '__main__':
    main()

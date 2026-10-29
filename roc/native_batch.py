"""Merge worker method edits into whole-TU proofs; never credit uncompiled source."""
import hashlib
from concurrent.futures import as_completed
from pathlib import Path

from roc import integration


def model_batch(rel, text, groups, baseline, model, rounds, compile_round, matcher,
                evidence, log, options, pool, diff=None):
    """File coordinator: AI workers produce method edits, then share a TU compile.
    The caller owns the global AI pool and compiler limiter; nested batches never
    create another set of model workers."""
    from roc import native_sweep as sweep, providers
    sessions, records = {}, []
    attempts = rounds if options.get('generation') == 'method' else 1

    def request(method, targets, attempt):
        state = sessions.setdefault(method, [])
        if not state:
            item = evidence(targets[0])
            state.extend([{'role': 'system', 'content': 'Return only the requested complete C++ method. No tools or prose.'},
                          {'role': 'user', 'content': sweep.method_prompt(rel, text, item, method)}])
        settings = dict({'allow_cloud': True, 'timeout': 180, 'thinking': 'disabled'}, **options)
        settings['edit_blocks'] = False
        settings.setdefault('max_tokens', 3072 if settings['thinking'] == 'disabled' else 32768)
        if settings.get('before_request') and not settings['before_request']():
            return None, None
        log('Requesting %s · %s · %s · batch round %d/%d' % (model, rel, method, attempt + 1, attempts))
        reply = providers.generate(model, state, settings)
        state.append({'role': 'assistant', 'content': sweep.providers_text(reply)})
        try:
            edits = sweep.method_edits(text, reply, method)
            candidate = method_candidate(text, method, edits, targets)
            candidate['generation_seconds'] = getattr(reply, 'latency_s', None)
            return candidate, None
        except ValueError as error:
            state.append({'role': 'user', 'content': 'Rejected: %s. Return the complete corrected method, with its original signature, in one cpp fence.' % error})
            return None, dict(file=rel, mode='batch-ai', method=method, ok=False, error=str(error), reply=sweep.providers_text(reply)[:3000])

    for attempt in range(attempts):
        candidates = []
        futures = {pool.submit(request, method, targets, attempt): method for method, targets in groups.items()}
        for future in as_completed(futures):
            method = futures[future]
            try:
                candidate, error = future.result()
                if candidate:
                    candidates.append(candidate)
                if error:
                    records.append(error)
            except Exception as error:
                records.append(dict(file=rel, mode='batch-ai', method=method, ok=False,
                                    error=str(error)[:500], error_category=getattr(error, 'category', '')))
        if not candidates:
            continue
        log('Compiling shared %s: %d worker methods in one TU' % (rel, len(candidates)))
        proposal, trials = prove(rel, text, candidates, baseline, compile_round, matcher, log)
        records.extend(trials)
        if proposal:
            return proposal, records
        compiled = next((trial for trial in reversed(trials) if trial.get('ok') and trial.get('object')), None)
        errors = '\n'.join(str(t.get('error')) for t in trials if t.get('error'))[-1500:]
        for candidate in candidates:
            feedback = errors or 'Compiled, but no safe newly exact target. Existing exacts must not regress.'
            if compiled and diff:
                obj = Path(compiled['object']).read_bytes()
                feedback += ''.join('\n%s target vs rebuilt:\n%s' % (addr, diff(obj, addr)) for addr in candidate['targets'][:1])
            sessions[candidate['method']].append({'role': 'user', 'content': feedback + '\nReturn the corrected complete method against the ORIGINAL source, in one cpp fence.'})
    return None, records


def method_candidate(text, method, edits, targets):
    from roc import native_sweep as sweep
    changed = sweep.apply_edits(text, edits)
    span = sweep.methods(changed).get(method)
    if span is None:
        raise ValueError('Batch method is missing or ambiguous: ' + method)
    normalized = sweep.method_edits(text, changed[span[0]:span[1]], method)
    if sweep.apply_edits(text, normalized) != changed:
        raise ValueError('Batch edits extend outside ' + method)
    if normalized[0][0] == normalized[0][1]:
        raise ValueError('Worker made no source change')
    integration.validate_patches({'App/util/batch.cpp': normalized})
    return dict(method=method, edits=normalized, targets=sorted(set(targets)))


def prove(rel, text, candidates, baseline, compile_round, matcher, log=print):
    """One compile for compatible, successful methods. Split actual failures,
    prune unproved edits, and recompile any combined recovery before returning it."""
    from roc import native_sweep as sweep
    records, cache = [], {}

    def evaluate(group):
        edits = [pair for candidate in group for pair in candidate['edits']]
        source = sweep.apply_edits(text, edits)
        key = hashlib.sha256(source.encode()).hexdigest()
        if key not in cache:
            result = dict(compile_round(source, 'batch-' + key[:16]))
            if result.get('source_sha256', key) != key:
                raise ValueError('Compiler proof source does not match merged batch')
            hits = matcher.scan(Path(result['object']).read_bytes()) if result['ok'] else []
            result.update(hits=hits, losses=sorted(set(baseline) - {h['addr'] for h in hits}) if result['ok'] else [],
                          comparison_complete=bool(result['ok']),
                          file=rel, generation='batch', batch_methods=[c['method'] for c in group],
                          expected_source_sha256=key)
            records.append(result)
            cache[key] = result
            if result['ok']:
                log('Batch compile: %d methods · %d existing exact lost' % (len(group), len(result['losses'])))
            else:
                log('Batch compile failed: %d methods · no match comparison' % len(group))
        result = cache[key]
        found = {h['addr'] for h in result['hits']}
        targets = {addr for c in group for addr in c['targets']}
        return result, found, (found & targets) - set(baseline)

    def proposal(group, result, new):
        edits = [pair for c in group for pair in c['edits']]
        integration.validate_patches({rel: edits})
        return dict(file=rel, mode='batch', edits=edits,
                    witnesses=[h for h in result['hits'] if h['addr'] in new], proof=result,
                    batch_candidates=group)

    def verify(group):
        result, found, new = evaluate(group)
        if not result['ok'] or result['losses']:
            if len(group) == 1:
                return None
            midpoint = len(group) // 2
            recovered = [p for p in (verify(group[:midpoint]), verify(group[midpoint:])) if p]
            if not recovered:
                return None
            if len(recovered) == 1:
                return recovered[0]
            merged = [c for p in recovered for c in p['batch_candidates']]
            combined, addresses, gains = evaluate(merged)
            required = {h['addr'] for p in recovered for h in p['witnesses']}
            if combined['ok'] and not combined['losses'] and required <= addresses:
                return proposal(merged, combined, gains)
            winner = max(recovered, key=lambda p: len(p['witnesses']))
            records.extend(dict(file=rel, mode='batch-deferred', deferred_proposal=p) for p in recovered if p is not winner)
            return winner
        if not new:
            return None
        contributing = [c for c in group if set(c['targets']) & new]
        if len(contributing) == len(group):
            # Every edited method is itself newly byte/data exact. No unrelated
            # neighbour was changed, so N extra deletion compiles add no proof.
            return proposal(group, result, new)
        reduced, addresses, reduced_new = evaluate(contributing)
        if reduced['ok'] and not reduced['losses'] and new <= addresses:
            return proposal(contributing, reduced, reduced_new)
        # An edited helper may be required by an inlined exact caller. Keep only
        # edits that survive the same deletion proof used by the single-worker path.
        keep = list(group)
        definitions = set(result.get('defined_symbols', ()))
        for candidate in list(group):
            remaining = [c for c in keep if c is not candidate]
            if not remaining:
                continue
            trial, addresses, _ = evaluate(remaining)
            if trial['ok'] and not trial['losses'] and new <= addresses and not definitions.intersection(trial.get('undefined_symbols', ())):
                keep, result = remaining, trial
        return proposal(keep, result, new)

    groups = []
    for candidate in candidates:
        try:
            candidate = method_candidate(text, candidate['method'], candidate['edits'], candidate['targets'])
        except ValueError as error:
            records.append(dict(file=rel, mode='batch-invalid', ok=False, error=str(error), candidate=candidate))
            continue
        for group in groups:
            same = next((c for c in group if c['method'] == candidate['method']), None)
            if same is None:
                group.append(candidate)
                break
            if same['edits'] == candidate['edits']:
                same['targets'] = sorted(set(same['targets']) | set(candidate['targets']))
                break
        else:
            groups.append([candidate])
    proved = [p for group in groups if (p := verify(group))]
    if not proved:
        return None, records
    winner = max(proved, key=lambda p: len(p['witnesses']))
    compatible = []
    occupied = set()
    for item in sorted(proved, key=lambda p: -len(p['witnesses'])):
        methods = {c['method'] for c in item['batch_candidates']}
        if not methods & occupied:
            compatible.append(item)
            occupied.update(methods)
    if len(compatible) > 1:
        merged = [c for p in compatible for c in p['batch_candidates']]
        result, found, new = evaluate(merged)
        required = {h['addr'] for p in compatible for h in p['witnesses']}
        if result['ok'] and not result['losses'] and required <= found:
            winner = proposal(merged, result, new)
            proved = [p for p in proved if p not in compatible]
    records.extend(dict(file=rel, mode='batch-deferred', deferred_proposal=p) for p in proved if p is not winner)
    return winner, records

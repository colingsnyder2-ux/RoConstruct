"""Bounded compiler-only recovery after model attempts; never grants credits."""
from collections import deque
from pathlib import Path

from roc import integration, native_search, native_transforms


def variants(source, method, context='', diagnostics=None):
    from roc import native_sweep as sweep
    selected = {method}
    yield from native_transforms.method_variants(source, selected, context)
    yield from native_transforms.immediate_variants(source,
        {a: d for a, d in (diagnostics or {}).items() if sweep.symbol_method(d.get('symbol', '')) == method})
    for mode in ('assertions', 'nonempty', 'ternary', 'index-int', 'index-size'):
        candidate, edits = sweep.variant(source, mode, selected)
        if edits:
            yield mode + ':' + method, candidate, edits
    yield from native_search.scoped_variants(source,
        ['scoped-osize', 'scoped-speed', 'scoped-fp', 'scoped-noautoinline'], selected)


def run(rel, text, targets, baseline, compile_round, matcher, log, *, rounds=2,
        limit=24, context='', seed=None, diagnostics=None, seen=(), before_trial=None):
    """Round-robin attempted methods, reusing only compiled no-loss improvements.

    Each round has at least one trial slot per locatable method. Coverage records
    distinguish unsupported methods, deduped candidates and exhausted budgets.
    """
    from roc import native_sweep as sweep
    if not rounds or not targets:
        return None, []
    if type(rounds) is not int or not 0 <= rounds <= 8 or type(limit) is not int or not 1 <= limit <= 256:
        raise ValueError('Repair rounds must be 0-8; trial limit must be 1-256')
    records, winners, covered = [], [], {a: 0 for a in targets}
    groups, source, diagnostics = {}, text, diagnostics or {}
    for addr, symbol in targets.items():
        groups.setdefault(sweep.symbol_method(symbol), []).append(addr)
    if seed and seed != text and (not before_trial or before_trial()):
        result = compile_round(seed, 'repair-seed-' + integration.digest(seed)[:16])
        hits = matcher.scan(Path(result['object']).read_bytes()) if result['ok'] else []
        result.update(mode='repair-seed', losses=sorted(set(baseline)-{h['addr'] for h in hits}) if result['ok'] else [],
                      comparison_complete=bool(result['ok']))
        records.append(result)
        if result['ok'] and not result['losses']:
            source, diagnostics = seed, result.get('diagnostics', {})
    seen = set(seen) | {integration.digest(text), integration.digest(source)}
    budget = max(limit, len(groups))
    spans = sweep.methods(source)
    unsupported = {a for method, addresses in groups.items() if method not in spans for a in addresses}
    stopped = False
    log('Experimental repair: %s · %d attempted targets · %d rounds · no AI requests' % (rel, len(targets), rounds))
    for n in range(rounds):
        queues = {method: deque(variants(source, method, context, diagnostics))
                  for method in groups if method in spans}
        used, improved = 0, None
        while any(queues.values()) and used < budget:
            for method, queue in queues.items():
                while queue:
                    mode, candidate, edits = queue.popleft()
                    key = integration.digest(candidate)
                    if key not in seen:
                        break
                else:
                    continue
                if before_trial and not before_trial():
                    stopped = True
                    break
                seen.add(key)
                integration.validate_patches({rel: edits})
                result = compile_round(candidate, 'repair-' + key[:16])
                hits = matcher.scan(Path(result['object']).read_bytes()) if result['ok'] else []
                found = {h['addr'] for h in hits}
                lost = set(baseline)-found if result['ok'] else set()
                result.update(mode='repair', repair_round=n+1, search_family=mode,
                              target_addresses=groups[method], hits=hits, losses=sorted(lost),
                              comparison_complete=bool(result['ok']))
                records.append(result)
                used += 1
                for addr in groups[method]:
                    covered[addr] += 1
                new = (found & set(targets))-set(baseline)
                if result['ok'] and not lost:
                    scores = result.get('diagnostics', {})
                    strength = sum(scores.get(a, {}).get('score', 0) for a in targets)
                    prior = sum(diagnostics.get(a, {}).get('score', 0) for a in targets)
                    if strength > prior and (improved is None or strength > improved[0]):
                        improved = strength, candidate, scores
                    if new and not native_transforms.changed_methods(text, candidate)-{sweep.symbol_method(h['symbol']) for h in hits}:
                        proposal = sweep.minimize(rel, text, native_search.anchored_changes(text, candidate),
                            new, baseline, compile_round, matcher, 'repair',
                            definitions=result.get('defined_symbols', ()), verified=result)
                        if proposal:
                            proposal['mode'] = 'repair'
                            winners.append(proposal)
                if used >= budget:
                    break
            if stopped:
                break
        log('Repair round %d/%d · %d compiles · %d exact proposals' % (n+1, rounds, used, len(winners)))
        if stopped:
            break
        if improved:
            _, source, diagnostics = improved
    records.append(dict(file=rel, mode='repair-coverage', target_addresses=sorted(targets),
        trials_by_target=covered, unsupported_targets=sorted(unsupported), stopped=stopped,
        deferred_targets=sorted(a for a, count in covered.items() if not count and a not in unsupported)))
    return max(winners, key=lambda p: len(p['witnesses']), default=None), records

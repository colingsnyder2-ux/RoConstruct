"""Measured integration selection and bounded model retries. No coverage authority."""
import json
import statistics
import time
import threading
from collections import Counter, defaultdict
from pathlib import Path

from roc import integration


def model_for_attempt(model, options, attempt):
    stronger = options.get('escalation_model')
    after = options.get('escalate_after', 2)
    if type(after) is not int or after < 1:
        raise ValueError('Escalation threshold must be positive')
    return stronger if stronger and attempt >= after else model


def usage(reply, model):
    incoming, outgoing = getattr(reply, 'input_tokens', None), getattr(reply, 'output_tokens', None)
    if incoming == outgoing == 0:
        incoming = outgoing = None
    return dict(model=model, response_received=True, input_tokens=incoming,
                output_tokens=outgoing,
                generation_seconds=getattr(reply, 'latency_s', None))


class AttemptBudget:
    """One private file coordinator owns this record. Input identity reopens stale blockers."""
    def __init__(self, path, key, limit=3):
        if type(limit) is not int or not 1 <= limit <= 100:
            raise ValueError('No-improvement limit must be 1-100')
        self.path, self.key, self.limit = Path(path), key, limit
        self.lock, self.seen_requests = threading.RLock(), set()
        saved = json.loads(self.path.read_text()) if self.path.exists() else {}
        self.targets = saved.get('targets', {}) if saved.get('key') == key else {}

    def blocked(self, addr):
        return self.targets.get(addr, {}).get('failures', 0) >= self.limit

    def prime(self, diagnostics):
        for addr, row in diagnostics.items():
            self.targets.setdefault(addr, dict(failures=0, best_score=row.get('score'), best_frame=bool(row.get('frame_ok')), best_calls=bool(row.get('calls_ok'))))

    def record(self, trials, exact=()):
        with self.lock:
            # Provider failures without a response are not unsuccessful source approaches.
            requests = [r for r in trials if r.get('mode') in ('model-request', 'batch-request') and r.get('response_received') and id(r) not in self.seen_requests]
            self.seen_requests.update(id(r) for r in requests)
            for request in requests:
                for addr in set(request.get('target_addresses', [])):
                    row = self.targets.setdefault(addr, dict(failures=0, best_score=None, best_frame=False, best_calls=False))
                    row['failures'] += 1
                    row['model'] = request.get('model')
            for trial in trials:
                if trial.get('losses') or not trial.get('ok'):
                    continue
                for addr, diag in trial.get('diagnostics', {}).items():
                    row = self.targets.setdefault(addr, dict(failures=0, best_score=None, best_frame=False, best_calls=False))
                    improved = (row['best_score'] is not None and diag.get('score', 0) > row['best_score']
                                or diag.get('frame_ok') and not row.get('best_frame')
                                or diag.get('calls_ok') and not row.get('best_calls'))
                    if improved:
                        row['failures'] = 0
                    row.update(best_score=max(row['best_score'] or 0, diag.get('score', 0)),
                               best_frame=row.get('best_frame', False) or bool(diag.get('frame_ok')),
                               best_calls=row.get('best_calls', False) or bool(diag.get('calls_ok')))
            for addr in exact:
                self.targets.pop(addr, None)
            integration.atomic_json(self.path, dict(key=self.key, targets=self.targets, limit=self.limit,
                                                   updated=time.time(), grants_credit=False))


def learned(jobs):
    """Only finalized independent jobs inform acceptance probability/cost."""
    groups = defaultdict(lambda: dict(accepted=0, rejected=0, verification_seconds=[], credits=0))
    for job in jobs:
        if job['state'] not in ('accepted', 'rejected'):
            continue
        receipt = job.get('receipt') or {}
        for unit in job['unit'].split(', '):
            row = groups[unit]
            row[job['state']] += 1
            seconds = receipt.get('verification_seconds')
            if isinstance(seconds, (int, float)) and seconds >= 0:
                row['verification_seconds'].append(seconds)
            # Batch credits cannot be assigned to individual classes without witness mapping.
            if ', ' not in job['unit'] and job['state'] == 'accepted':
                row['credits'] += receipt.get('credits', 0)
    return {unit: dict(row, acceptance_probability=(row['accepted'] + 1) / (row['accepted'] + row['rejected'] + 2),
                       median_verification_seconds=statistics.median(row['verification_seconds']) if row['verification_seconds'] else None)
            for unit, row in groups.items()}


def local_metrics(records, compilations=None):
    requests = [r for r in records if r.get('mode') in ('model-request', 'batch-request')]
    by_model = {}
    for request in requests:
        model = request.get('model', 'unknown')
        row = by_model.setdefault(model, dict(requests=0, reported_input_tokens=0, reported_output_tokens=0,
                                               responses_with_usage=0, generation_seconds=0))
        row['requests'] += 1
        if request.get('input_tokens') is not None and request.get('output_tokens') is not None:
            row['responses_with_usage'] += 1
            row['reported_input_tokens'] += request['input_tokens']
            row['reported_output_tokens'] += request['output_tokens']
        row['generation_seconds'] += request.get('generation_seconds') or 0
    compiles = [r for r in (compilations if compilations is not None else records) if 'object' in r and 'ok' in r]
    measured = [r['seconds'] for r in compiles if isinstance(r.get('seconds'), (int, float))]
    compared = [r for r in compiles if r.get('comparison_complete')]
    return dict(model_usage=by_model, model_requests=len(requests),
                reported_tokens=sum(r['reported_input_tokens'] + r['reported_output_tokens'] for r in by_model.values()),
                token_reporting_complete=sum(r['responses_with_usage'] for r in by_model.values()) == len(requests),
                compile_mean_seconds=statistics.mean(measured) if measured else None,
                compile_median_seconds=statistics.median(measured) if measured else None,
                compile_success_rate=sum(r['ok'] for r in compiles)/len(compiles) if compiles else None,
                object_matching_success_rate=sum(bool(r.get('hits')) and not r.get('losses') for r in compared)/len(compared) if compared else None,
                failure_reasons=dict(Counter(r.get('error_category') or r.get('blocker') or 'compile-or-match' for r in records
                                             if r.get('ok') is False)), local_results_grant_credit=False)


def server_metrics(promotions, hours=24):
    if not isinstance(hours, (int, float)) or not 0 < hours <= 24*365:
        raise ValueError('Metrics window must be positive and at most one year')
    now = time.time()
    with promotions.store.lock:
        jobs = promotions.store.db.execute('SELECT id,unit,model,state,receipt FROM integration_jobs WHERE updated>=?',
                                          (now-hours*3600,)).fetchall()
        credits = promotions.store.db.execute('SELECT addr FROM integration_credit WHERE client=? AND ts>=?', (integration.CLIENT, now-hours*3600,)).fetchall()
        blocked = promotions.store.db.execute("SELECT COUNT(*) FROM integration_claims WHERE state LIKE 'parked:%' AND expires>?", (now,)).fetchone()[0]
        has_funcs = promotions.store.db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='funcs'").fetchone()
        sizes = dict(promotions.store.db.execute('SELECT addr,size FROM funcs WHERE client=?', (integration.CLIENT,))) if has_funcs else {}
    decoded = [dict(id=i, unit=u, model=m, state=s, receipt=json.loads(r or '{}')) for i,u,m,s,r in jobs]
    timings = [j['receipt']['verification_seconds'] for j in decoded if isinstance(j['receipt'].get('verification_seconds'), (int, float))]
    finalized = [j for j in decoded if j['state'] in ('accepted', 'rejected')]
    accepted = sum(j['state'] == 'accepted' for j in finalized)
    byte_count = sum(sizes[a] for a, in credits) if all(a in sizes for a, in credits) else None
    from roc.native_adapt import namespace_capabilities
    pending = sum(len(rows) for _, rows in promotions.catalog())
    return dict(client=integration.CLIENT, namespace_profiles=namespace_capabilities(promotions.root),
                eligible_pending_exact_functions=pending, window_hours=hours, functions_integrated=len(credits),
                functions_per_hour=len(credits)/hours, native_bytes=byte_count,
                native_bytes_per_hour=byte_count/hours if byte_count is not None else None,
                finalized_jobs=len(finalized), acceptance_rate=accepted/len(finalized) if finalized else None,
                verification_mean_seconds=statistics.mean(timings) if timings else None,
                verification_median_seconds=statistics.median(timings) if timings else None,
                blocked_tasks=blocked, learned_tasks=learned(decoded),
                tokens_per_success=None, token_usage_state='not-attested-by-server',
                independent_receipts_only=True)


class Reservations:
    """Class leases acquired before model work; each HTTP call owns its connection."""
    def __init__(self, api_factory, user, worker, revision, maximum, on_claim, interval=1800, bulk=False):
        self.factory, self.user, self.worker, self.revision = api_factory, user, worker, revision
        self.maximum, self.on_claim, self.interval, self.bulk = maximum, on_claim, interval, bulk
        self.claims, self.lost = {}, set()
        self.lock, self.stop = threading.Lock(), threading.Event()
        self.thread = None

    def reserve(self, units):
        if not units:
            return False
        with self.lock:
            if self.lost or len(set(self.claims) | set(units)) > self.maximum:
                return False
            api = self.factory()
            try:
                missing = sorted(set(units) - set(self.claims))
                groups = [missing] if self.bulk and missing else [[u] for u in missing]
                for group in groups:
                    selection = dict(units=group, count=len(group), compact=True) if self.bulk else dict(unit=group[0], count=1)
                    result = api.call('/v1/integration/claim', dict(user=self.user, worker=self.worker, **selection))
                    for claim in result['claims']:
                        self.claims[claim['unit']] = claim
                        if claim['base_revision'] != self.revision:
                            from roc.native_sweep import BaselineAdvanced
                            raise BaselineAdvanced('Lease baseline changed before model work; saved candidates retained')
                        if 'baseline' not in claim:
                            claim['baseline'] = result['baselines'][claim['base_revision']]
                        if 'protected_native' not in claim:
                            claim['protected_native'] = result.get('protected_native')
                        self.on_claim(claim)
                    if not set(group) <= self.claims.keys():
                        return False
                if self.thread is None:
                    self.thread = threading.Thread(target=self._renew, daemon=True)
                    self.thread.start()
                return True
            finally:
                api.close()

    def renew_once(self):
        with self.lock:
            identifiers = [c['id'] for c in self.claims.values()]
        if not identifiers:
            return
        api = self.factory()
        try:
            result = api.call('/v1/integration/renew', dict(user=self.user, claims=identifiers))
            if not result.get('ok'):
                with self.lock:
                    self.lost.update(identifiers)
        finally:
            api.close()

    def _renew(self):
        from roc.worker import ApiFailure
        while not self.stop.wait(self.interval):
            try:
                self.renew_once()
            except ApiFailure:
                continue  # Final renewal/ownership check is still mandatory before submission.

    def close(self, handled=()):
        self.stop.set()
        if self.thread:
            self.thread.join(timeout=2)
        api = self.factory()
        try:
            for claim in self.claims.values():
                if claim['id'] not in handled:
                    api.call('/v1/integration/release', dict(user=self.user, claim=claim['id']))
        finally:
            api.close()

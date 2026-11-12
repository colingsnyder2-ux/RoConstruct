"""Join exhaustive intake, method lookup and independently measured draft evidence."""
import argparse
from collections import Counter, defaultdict
from contextlib import closing
import json
from pathlib import Path
import sqlite3
import time

from roc.native_drafts import atomic
from roc.draft_merger import content_hash


def reconcile(root, output=None, record_reviews=False):
    root = Path(root).resolve()
    folder = root / 'work/draft-merger'
    intake = json.loads((folder / 'latest.json').read_text())
    methods = json.loads((folder / 'method-decisions.json').read_text()) if (folder / 'method-decisions.json').exists() else None
    native = json.loads((folder / 'native-latest.json').read_text()) if (folder / 'native-latest.json').exists() else None
    if (native and native['summary'].get('measured', 0) < native['summary'].get('total_available', 0)
            and (folder / 'native-complete-latest.json').exists()):
        native = json.loads((folder / 'native-complete-latest.json').read_text())
    method_rows = {(row['path'], row['sha256']): row for row in methods['variants']} if methods else {}
    native_rows = {(row['path'], row['candidate_sha256']): row for row in native['units']} if native else {}
    current_run = intake['summary']['run']
    accepted = []
    with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
        edges = defaultdict(lambda: defaultdict(set))
        if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='source_aliases'").fetchone():
            for path, before_sha, after_sha, normalized, _ in db.execute('SELECT * FROM source_aliases'):
                edges[path][before_sha].update((after_sha, normalized))
        for path, before_sha, after_sha, detail in db.execute("SELECT path,before_sha256,after_sha256,detail FROM actions WHERE state='applied-inactive'"):
            proof = db.execute('SELECT receipt FROM proofs WHERE id=?', (json.loads(detail)['proof'],)).fetchone()
            if not proof:
                continue
            receipt = json.loads(proof[0])
            checks = receipt.get('checks', {})
            if receipt.get('path') == path and (
                    checks.get('existing_code_preserved') is True and checks.get('existing_data_preserved') is True
                    or checks.get('preservation') is True and checks.get('data') is True and checks.get('code') is True):
                edges[path][before_sha].add(after_sha)
        for action, bundle, path, sha, detail in db.execute("SELECT id,bundle,path,after_sha256,detail FROM actions WHERE state='applied-inactive'"):
            identifier = json.loads(detail)['proof']
            proof = db.execute('SELECT receipt FROM proofs WHERE id=?', (identifier,)).fetchone()
            if not proof:
                continue
            receipt = json.loads(proof[0])
            target = root / path
            raw = target.read_bytes() if target.is_file() else None
            present = raw is not None and content_hash(raw) == sha
            if not present and raw is not None:
                current = {content_hash(raw), content_hash(raw.replace(b'\r\n', b'\n'))}
                pending, seen = [sha], set()
                while pending:
                    node = pending.pop()
                    if node in seen:
                        continue
                    seen.add(node)
                    pending.extend(edges[path].get(node, ()))
                present = bool(current & seen)
            if not present and raw is not None and db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='source_aliases'").fetchone():
                aliases = db.execute('SELECT after_sha256,normalized_sha256 FROM source_aliases WHERE path=? AND before_sha256=?', (path, sha)).fetchall()
                present = any(content_hash(raw) == after or content_hash(raw.replace(b'\r\n', b'\n')) == normalized
                              for after, normalized in aliases)
            accepted.append(dict(action=action, bundle=bundle, path=path, proof=identifier,
                methods=sorted(set(receipt['after_methods']) - set(receipt['before_methods'])),
                source_identity_current=present, scope=receipt.get('scope', 'Inactive source only')))
    method_stale = methods is None or bool(methods['summary']['stale_paths']) or methods['summary']['run'] != current_run
    native_stale = native is None or native['summary']['stale'] or native['summary']['run'] != current_run
    if native and native['summary'].get('frozen_inputs'):
        inventory_file = Path(native['summary']['frozen_inputs']) / 'inventory.json'
        if inventory_file.is_file():
            for name, sha in json.loads(inventory_file.read_text()).items():
                path = root / name
                if not path.is_file() or content_hash(path.read_bytes()) != sha:
                    native_stale = True
                    break
    competing = defaultdict(list)
    if native:
        for row in native['units']:
            for method in row['methods']:
                competing[(method['symbol'], method['address'])].append(dict(
                    path=row['path'], candidate_sha256=row['candidate_sha256'],
                    code_exact=method['exact_code'], references_verified=method['references_verified'],
                    score=method['score'], baseline_exact=method.get('baseline_exact_code'),
                    stale=native_stale))
    ranking = []
    for (symbol, address), candidates in sorted(competing.items()):
        candidates.sort(key=lambda row: (-int(row['references_verified']), -int(row['code_exact']),
                                         -row['score'], row['path'], row['candidate_sha256']))
        ranking.append(dict(symbol=symbol, address=address, candidates=candidates,
                            eligible_for_integration=False,
                            source_status='integrated-inactive' if any(symbol + '@' + address in row['methods']
                                and row['source_identity_current'] for row in accepted) else 'source-review-candidate',
                            blocker='Measurement ranking does not authorize writes. Review useful inactive methods individually; inferred names and partial classes are allowed. Executable gates remain separate.'))
    for bundle in intake['bundles']:
        applied = [row for row in accepted if row['bundle'] == bundle['id']]
        if applied:
            bundle['accepted_source_actions'] = applied
            bundle['state'] = 'partially-integrated-inactive'
        for item in bundle['files']:
            key = item['path'], item['candidate_sha256']
            if key in method_rows:
                row = method_rows[key]
                item['method_lookup'] = dict(stale=method_stale, parse_errors=row['parse_errors'],
                    states=dict(Counter(method['status'] for method in row['methods'])),
                    missing_signatures=[method['signature'] for method in row['methods'] if method['status'] == 'not-found'],
                    existing_locations=sorted({hit['path'] for method in row['methods'] for hit in method['locations'] if not hit['shadow']}))
            if key in native_rows:
                row = native_rows[key]
                item['independent_measurement'] = dict(stale=native_stale, compile_exit=row.get('compile_exit'),
                    code_exacts=sum(method['exact_code'] for method in row['methods']),
                    references_verified=sum(method['references_verified'] for method in row['methods']),
                    blockers=row['blockers'], methods=row['methods'])
                item['blockers'].extend(row['blockers'])
                if native_stale:
                    item['blockers'].append('Native measurements are stale or belong to another intake run; independently reverify on pinned current inputs')
            item['blockers'] = list(dict.fromkeys(item['blockers']))
    summary = dict(intake['summary'], method_index_stale=method_stale, native_measurements_stale=native_stale,
                   measured_versions=len(native_rows), ranked_method_targets=len(ranking),
                   blocker_counts=dict(Counter(blocker for bundle in intake['bundles'] for item in bundle['files'] for blocker in item['blockers'])),
                   terminal_duplicates=sum(bundle['state'] == 'duplicate' for bundle in intake['bundles']),
                   unresolved_bundles=sum(bundle['state'] != 'duplicate' for bundle in intake['bundles']))
    summary['accepted_methods'] = sum(len(row['methods']) for row in accepted if row['source_identity_current'])
    summary['historical_source_actions'] = len(accepted)
    summary['decisions'] = dict(Counter(row['state'] for row in intake['bundles']))
    review_results = []
    if (folder / 'native-review-latest.json').exists():
        reviewed = json.loads((folder / 'native-review-latest.json').read_text())
        for row in reviewed['units']:
            gains = [method for method in row['methods'] if method['references_verified'] and method.get('baseline_exact_code') is not True]
            review_results.append(dict(path=row['path'], proposals=row.get('proposals', []),
                compile_exit=row.get('compile_exit'), verified_candidate_gains=len(gains),
                state='needs-full-acceptance-proof' if gains else 'no-new-verified-gain',
                blockers=row['blockers'], stale=reviewed['summary']['stale']))
    report = dict(summary=summary, bundles=intake['bundles'], competing_methods=ranking,
                  accepted_source_actions=accepted, llm_reviews=review_results)
    with closing(sqlite3.connect(folder / 'state.sqlite3')) as db, db:
        for row in report['bundles']:
            db.execute('UPDATE decisions SET detail=? WHERE run=? AND bundle=?',
                       (json.dumps(row), current_run, row['id']))
        if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='review_proposals'").fetchone():
            for row in review_results:
                for proposal in row['proposals']:
                    db.execute('UPDATE review_proposals SET state=? WHERE id=?', (row['state'], proposal))
                    job = db.execute('SELECT job FROM review_proposals WHERE id=?', (proposal,)).fetchone()
                    if job:
                        db.execute('UPDATE review_jobs SET state=?,result=?,updated=? WHERE id=?',
                                   (row['state'], json.dumps(row), time.time(), job[0]))
    if record_reviews:
        with closing(sqlite3.connect(root / 'work/agent-inbox/drafts.sqlite3', timeout=30)) as db, db:
            for row in report['bundles']:
                previous = db.execute('SELECT state,detail FROM reviews WHERE id=?', (row['id'],)).fetchone()
                if not previous or previous[0] != 'reviewing':
                    continue
                try:
                    detail = json.loads(previous[1])
                except (ValueError, TypeError):
                    continue
                own_run = detail.get('coordinator_run')
                if own_run != current_run:
                    if not row.get('accepted_source_actions') or not isinstance(own_run, str):
                        continue
                    with closing(sqlite3.connect(folder / 'state.sqlite3')) as state_db:
                        if not state_db.execute('SELECT 1 FROM runs WHERE id=?', (own_run,)).fetchone():
                            continue
                updated = json.dumps(dict(coordinator_run=current_run, input_key=summary['input_key'],
                                          disposition=row['state'], files=row['files'],
                                          accepted_source_actions=row.get('accepted_source_actions', []),
                                          previous_review=detail if row.get('accepted_source_actions') else None))
                state = 'integrated-inactive' if row.get('accepted_source_actions') else previous[0]
                db.execute('UPDATE reviews SET state=?,detail=?,updated=? WHERE id=? AND detail=?',
                           (state, updated, time.time(), row['id'], previous[1]))
    atomic(folder / 'dispositions.json', report)
    if output:
        atomic(output, report)
    return {key: value for key, value in summary.items() if key != 'blocker_counts'}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--output', type=Path)
    parser.add_argument('--record-reviews', action='store_true')
    args = parser.parse_args()
    print(json.dumps(reconcile(args.root, args.output, args.record_reviews), indent=2))

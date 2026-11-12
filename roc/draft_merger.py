"""Durable native draft intake, reconciliation and proof-bound decisions.

Contributor code and commands are never executed by intake. Syntax inventories
are hints, not permission to replace canonical source or select a provider.
"""
import argparse
from collections import Counter
from contextlib import closing
import hashlib
import json
import os
from pathlib import Path
import sqlite3
import subprocess
import time
import uuid

from roc import native_drafts

VERIFIER_SHA256 = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()

SCHEMA = '''
CREATE TABLE IF NOT EXISTS runs(id TEXT PRIMARY KEY,created REAL,input_key TEXT,
 head TEXT,max_seq INTEGER,inventory TEXT,status TEXT,summary TEXT);
CREATE TABLE IF NOT EXISTS decisions(run TEXT,bundle TEXT,seq INTEGER,user TEXT,
 previous_state TEXT,state TEXT,detail TEXT,PRIMARY KEY(run,bundle));
CREATE TABLE IF NOT EXISTS contents(sha256 TEXT PRIMARY KEY,bytes BLOB);
CREATE TABLE IF NOT EXISTS proofs(id TEXT PRIMARY KEY,input_key TEXT,adapter TEXT,
 candidate_sha256 TEXT,receipt TEXT,created REAL);
CREATE TABLE IF NOT EXISTS actions(id TEXT PRIMARY KEY,run TEXT,bundle TEXT,
 path TEXT,before_sha256 TEXT,after_sha256 TEXT,state TEXT,detail TEXT);
'''


def content_hash(raw):
    return hashlib.sha256(raw).hexdigest()


def proof_key(value):
    return content_hash(json.dumps(value, sort_keys=True, separators=(',', ':'),
                                   allow_nan=False).encode())


def canonical_state(root, paths):
    root = Path(root).resolve()
    result = {}
    for name in sorted(set(paths)):
        native_drafts.safe_path(name)
        path = root / name
        if not path.resolve().is_relative_to(root):
            raise ValueError('Path escapes canonical root: ' + name)
        # Reject even in-root aliases: two path names must not own one file.
        for part in (path, *path.parents):
            if part == root:
                break
            if part.is_symlink() or (hasattr(part, 'is_junction') and part.is_junction()):
                raise ValueError('Aliased canonical path: ' + name)
        if path.exists() and not path.is_file():
            raise ValueError('Canonical path is not a regular file: ' + name)
        raw = path.read_bytes() if path.is_file() else None
        result[name] = dict(exists=raw is not None,
                            sha256=content_hash(raw) if raw is not None else None)
    return result


def classify_packet(packet, committed, live):
    rows = []
    for name, change in packet['files'].items():
        base, candidate, current = change['base'], change['text'], live.get(name)
        if candidate is None:
            state = 'deletion-review'
        elif candidate == committed.get(name):
            state = 'duplicate-committed'
        elif candidate == current:
            state = 'already-live'
        elif candidate == base:
            state = 'no-change'
        elif current is None and base is None:
            state = 'new-file'
        elif current == base:
            state = 'base-applies'
        else:
            state = 'conflict-review'
        sha = lambda text: content_hash(text.encode()) if text is not None else None
        rows.append(dict(path=name, state=state, candidate_sha256=sha(candidate),
                         base_sha256=sha(base), current_sha256=sha(current)))
    return rows


def git(root, *args, data=None):
    return subprocess.run(['git', '-C', str(root), *args], input=data,
                          capture_output=True, check=True).stdout


def committed_text(root, head, paths):
    entries = {}
    for record in git(root, 'ls-tree', '-rz', '-r', head).split(b'\0'):
        if not record:
            continue
        meta, name = record.split(b'\t', 1)
        mode, kind, sha = meta.split()
        if kind == b'blob' and mode in (b'100644', b'100755'):
            entries[name.decode()] = sha.decode()
    names = sorted(set(paths) & entries.keys())
    requested = ''.join(entries[name] + '\n' for name in names).encode()
    data = git(root, 'cat-file', '--batch', data=requested) if names else b''
    result, cursor = dict.fromkeys(paths), 0
    for name in names:
        end = data.index(b'\n', cursor)
        size = int(data[cursor:end].split()[2])
        raw = data[end + 1:end + 1 + size]
        try:
            result[name] = raw.decode('utf-8')
        except UnicodeError:
            result[name] = None
        cursor = end + 2 + size
    return result


def policy_blockers(row):
    state, path = row['state'], row['path']
    if state == 'duplicate-committed':
        return []
    if state == 'already-live':
        return ['Candidate exists in live checkout; commit/independent proof not established']
    if state == 'no-change':
        return ['No candidate change relative to recorded base']
    blockers = []
    if state == 'deletion-review':
        blockers.append('Deletion requires explicit replacement/provider and preservation proof')
    if state == 'conflict-review':
        blockers.append('Recorded base differs from current source; reconcile methods/declarations')
    suffix = Path(path).suffix.lower()
    if suffix in ('.cpp', '.c', '.cc', '.cxx', '.h', '.hpp', '.inl', '.inc', '.ipp'):
        blockers.extend(['Review useful method changes and existing providers; inferred names are allowed',
                         'Compile and preserve existing source/data/declarations under a relevant configuration',
                         'Review affected source behavior; record partial-class/runtime questions separately'])
    elif suffix in ('.json', '.jsonl'):
        blockers.append('Validate evidence provenance and exact source/dependency identities')
    elif suffix in ('.md', '.txt'):
        blockers.append('Factual review; native proof does not establish documentation correctness')
    else:
        blockers.append('Reviewed tooling behavior/security and focused regression checks required')
    return blockers


def checked_proof(db, identifier, expected):
    """Only coordinator-store receipts, never a contributor JSON path."""
    from roc.draft_proof import validate_adapter
    row = db.execute('SELECT adapter,receipt FROM proofs WHERE id=?', (identifier,)).fetchone()
    if row is None:
        raise ValueError('No independently generated proof in coordinator store')
    adapter, raw = row
    receipt = json.loads(raw)
    blockers = validate_adapter(adapter, receipt, expected)
    if blockers:
        raise ValueError('; '.join(blockers))
    return receipt


def apply_new_file(root, db, run, bundle, path, raw, proof_id, expected, lease_check, input_check):
    """Caller holds integration lock. Recoverable addition; never overwrites work.

    Replacement/family edits need their own reviewed adapter. This path cannot
    silently turn an addition receipt into permission to replace a dirty file.
    """
    native_drafts.safe_path(path)
    if (not path.startswith('rebuild/2008-06/native-classes/') or
            Path(path).suffix not in ('.cpp', '.c', '.cc', '.cxx')):
        raise ValueError('Additive adapter only writes native class source')
    if content_hash(raw) != expected['candidate_sha256']:
        raise ValueError('Candidate bytes changed since proof')
    proof = checked_proof(db, proof_id, expected)
    if proof.get('path') != path:
        raise ValueError('Proof path differs from integration target')
    identity = proof_key(dict(proof=proof_id, path=path, sha256=content_hash(raw)))
    target = Path(root) / path
    state = canonical_state(root, [path])[path]
    existing = db.execute('SELECT state,after_sha256 FROM actions WHERE id=?', (identity,)).fetchone()
    if existing:
        if state['sha256'] == existing[1]:
            with db:
                db.execute('UPDATE actions SET state=? WHERE id=?', ('applied-inactive', identity))
            return dict(action=identity, state='applied-inactive', recovered=True)
        raise ValueError('Interrupted integration needs reconciliation; target identity differs')
    if state['exists']:
        raise ValueError('Canonical target already exists; method reconciliation required')
    lease_check(path)
    if input_check() != expected['input_key']:
        raise ValueError('Inputs changed since independent proof')
    with db:
        db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                   (identity, run, bundle, path, None, content_hash(raw), 'prepared',
                    json.dumps(dict(proof=proof_id, input_key=expected['input_key']))))
    # A race after lease/hash checks must fail without clobbering a new file.
    staging = Path(root) / 'work/draft-merger/staging'
    staging.mkdir(parents=True, exist_ok=True)
    temporary = staging / (identity + '.' + uuid.uuid4().hex)
    try:
        with temporary.open('xb') as stream:
            stream.write(raw)
            stream.flush()
            os.fsync(stream.fileno())
        target.parent.mkdir(parents=True, exist_ok=True)
        canonical_state(root, [path])
        os.link(temporary, target)  # Atomic exclusive creation; never replaces a new target.
    finally:
        temporary.unlink(missing_ok=True)
    with db:
        db.execute('UPDATE actions SET state=? WHERE id=?', ('applied-inactive', identity))
    return dict(action=identity, state='applied-inactive', recovered=False)


def syntax_check(name, text):
    """Parse data only. Never import/execute contributor Python."""
    if text is None:
        return None
    try:
        if name.endswith('.py'):
            import ast
            ast.parse(text.encode(), filename=name)
            return 'python-syntax-valid'
        if name.endswith('.json'):
            json.loads(text.lstrip('\ufeff'))
            return 'json-syntax-valid'
        if name.endswith('.jsonl'):
            for line in text.lstrip('\ufeff').splitlines():
                if line.strip():
                    json.loads(line)
            return 'jsonl-syntax-valid'
    except (ValueError, SyntaxError) as error:
        return 'syntax-check-failed: ' + str(error)
    return None


def process(root, report=None, record_reviews=False, native_inputs=False):
    root = Path(root).resolve()
    token = native_drafts.integration_lock(root, 'start')['token']
    try:
        return _process(root, report, record_reviews, native_inputs)
    finally:
        native_drafts.integration_lock(root, 'release', token=token)


def _process(root, report, record_reviews, native_inputs):
    run = uuid.uuid4().hex
    source = root / 'work/agent-inbox/drafts.sqlite3'
    with closing(sqlite3.connect(source.as_uri() + '?mode=ro', uri=True)) as inbox:
        packets = inbox.execute('''SELECT b.seq,b.id,b.user,b.packet,r.state FROM bundles b
            LEFT JOIN reviews r ON r.id=b.id ORDER BY b.seq''').fetchall()
    parsed, invalid, paths = [], [], set()
    for seq, identifier, user, raw, previous in packets:
        try:
            packet = native_drafts.validate(json.loads(raw))
            if native_drafts.digest(packet) != identifier:
                raise ValueError('Stored packet identity mismatch')
            for name, item in packet['files'].items():
                name.encode('utf-8')
                for text in item.values():
                    if text is not None:
                        text.encode('utf-8')
            parsed.append((seq, identifier, user, packet, previous))
            paths.update(packet['files'])
        except (ValueError, TypeError, UnicodeError) as error:
            invalid.append(dict(seq=seq, id=identifier, user=user,
                                previous_state=previous, state='invalid-storage',
                                blockers=[str(error)], files=[]))
    head = git(root, 'rev-parse', 'HEAD').decode().strip()
    inventory, unsafe = {}, {}
    for name in sorted(paths):
        try:
            inventory.update(canonical_state(root, [name]))
        except (ValueError, OSError) as error:
            unsafe[name] = str(error)
    live, live_raw = {}, {}
    for name, state in inventory.items():
        live_raw[name] = (root / name).read_bytes() if state['exists'] else None
        try:
            live[name] = live_raw[name].decode() if state['exists'] else None
        except UnicodeError:
            live[name] = None
    if canonical_state(root, inventory) != inventory:
        raise RuntimeError('Canonical inputs changed while snapshotting')
    committed = committed_text(root, head, paths)
    verifier = VERIFIER_SHA256
    full_inputs = None
    if native_inputs:
        from roc.integration_verify import input_hash
        full_inputs = input_hash(root)
    identity = dict(schema=1, client='2008-06', head=head, files=inventory, unsafe_paths=unsafe,
                    verifier_sha256=verifier, native_input_key=full_inputs)
    key = proof_key(identity)
    folder = root / 'work/draft-merger'
    folder.mkdir(parents=True, exist_ok=True)
    database = folder / 'state.sqlite3'
    rows, content_checks, seen = list(invalid), {}, {}
    with closing(sqlite3.connect(database, timeout=30)) as db, db:
        db.execute('PRAGMA journal_mode=WAL')
        db.execute('PRAGMA synchronous=FULL')
        db.executescript(SCHEMA)
        for raw in live_raw.values():
            if raw is not None:
                db.execute('INSERT OR IGNORE INTO contents VALUES(?,?)', (content_hash(raw), raw))
        db.execute('INSERT INTO runs VALUES(?,?,?,?,?,?,?,?)',
                   (run, time.time(), key, head, max((r[0] for r in packets), default=0),
                    json.dumps(identity), 'processing', '{}'))
        for seq, identifier, user, packet, previous in parsed:
            files = classify_packet(packet, committed, live)
            for item in files:
                name, sha = item['path'], item['candidate_sha256']
                text = packet['files'][name]['text']
                if name in unsafe:
                    item['state'] = 'unsafe-current-path'
                item['blockers'] = policy_blockers(item)
                if name in unsafe:
                    item['blockers'].insert(0, unsafe[name])
                item['retry_when'] = 'Relevant canonical/dependency/toolchain/verifier inputs change, or missing independent proof is supplied by a registered verifier'
                if sha is not None:
                    if sha not in seen:
                        db.execute('INSERT OR IGNORE INTO contents VALUES(?,?)', (sha, text.encode()))
                        seen[sha] = identifier
                    item['same_content_first_bundle'] = seen[sha]
                    if (name, sha) not in content_checks:
                        content_checks[(name, sha)] = syntax_check(name, text)
                    item['syntax'] = content_checks[(name, sha)]
                    if item['syntax'] and item['syntax'].startswith('syntax-check-failed'):
                        item['blockers'].append(item['syntax'])
            state = 'duplicate' if all(f['state'] == 'duplicate-committed' for f in files) else 'proof-or-review-required'
            row = dict(seq=seq, id=identifier, user=user, previous_state=previous,
                       state=state, files=files)
            rows.append(row)
        stale = (git(root, 'rev-parse', 'HEAD').decode().strip() != head or
                 canonical_state(root, inventory) != inventory or
                 content_hash(Path(__file__).read_bytes()) != verifier)
        if full_inputs is not None:
            from roc.integration_verify import input_hash
            stale = input_hash(root) != full_inputs or stale
        summary = dict(run=run, input_key=key, client='2008-06', head=head,
                       bundle_count=len(rows), max_seq=max((r[0] for r in packets), default=0),
                       decisions=dict(Counter(r['state'] for r in rows)),
                       file_states=dict(Counter(f['state'] for r in rows for f in r['files'])),
                       unique_contents=len(seen), stale=stale, reviews_recorded=0,
                       accepted_methods=0, executable_promotions=0,
                       native_inputs_pinned=full_inputs is not None)
        for row in rows:
            db.execute('INSERT INTO decisions VALUES(?,?,?,?,?,?,?)',
                       (run, row['id'], row['seq'], row['user'], row['previous_state'],
                        row['state'], json.dumps(row)))
        if record_reviews and not stale:
            with closing(sqlite3.connect(source, timeout=30)) as inbox, inbox:
                for row in rows:
                    # Existing owner decisions are never replaced by classification.
                    if row['previous_state'] is not None or row['state'] == 'invalid-storage':
                        continue
                    state = 'duplicate' if row['state'] == 'duplicate' else 'reviewing'
                    detail = json.dumps(dict(coordinator_run=run, input_key=key,
                                             disposition=row['state'], files=row['files']))
                    summary['reviews_recorded'] += inbox.execute(
                        'INSERT OR IGNORE INTO reviews VALUES(?,?,?,?)',
                        (row['id'], state, detail, time.time())).rowcount
        db.execute('UPDATE runs SET status=?,summary=? WHERE id=?',
                   ('stale' if stale else 'processed', json.dumps(summary), run))
    result = dict(summary=summary, bundles=rows)
    native_drafts.atomic(folder / 'runs' / (run + '.json'), result)
    native_drafts.atomic(folder / 'latest.json', result)
    if report:
        native_drafts.atomic(report, result)
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('process', 'status', 'run'))
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--report', type=Path)
    parser.add_argument('--record-reviews', action='store_true')
    parser.add_argument('--native-inputs', action='store_true')
    parser.add_argument('--review-limit', type=int, default=3)
    parser.add_argument('--apply', action='store_true')
    parser.add_argument('--publish', action='store_true', help='Publish proof-bound source actions to the authorized branch')
    args = parser.parse_args()
    if args.publish and (args.action != 'run' or not args.apply):
        parser.error('--publish requires run --apply')
    if args.action == 'run':
        result = run_pipeline(args.root, args.report, args.record_reviews,
                              args.review_limit, args.apply, args.publish)
    elif args.action == 'status':
        result = json.loads((args.root / 'work/draft-merger/latest.json').read_text())['summary']
    else:
        result = process(args.root, args.report, args.record_reviews, args.native_inputs)
    print(json.dumps(result, indent=2))


def run_pipeline(root, report=None, record_reviews=False, review_limit=3, apply=False, publish=False):
    """Fixed local stages; no draft-supplied executable names or commands."""
    import sys
    if publish and not apply:
        raise ValueError('Publication requires explicit source application')
    root = Path(root).resolve()
    status = dict(pid=os.getpid(), state='running', stages=[])
    status_file = root / 'work/draft-merger/pipeline-status.json'
    native_drafts.atomic(status_file, status)
    try:
        intake = process(root, record_reviews=record_reviews, native_inputs=True)
        status['run'] = intake['run']
        status['stages'].append(dict(name='intake', state='done'))
        native_drafts.atomic(status_file, status)
        for module, tail in (('roc.draft_methods', ['build']),
                             ('roc.draft_methods', ['inspect']),
                             ('roc.draft_native', [])):
            name = module + ':' + (tail[0] if tail else 'measure')
            status['stages'].append(dict(name=name, state='running'))
            native_drafts.atomic(status_file, status)
            subprocess.run([sys.executable, '-m', module, *tail, '--root', str(root)],
                           cwd=root, check=True)
            status['stages'][-1]['state'] = 'done'
            native_drafts.atomic(status_file, status)
        from roc.draft_report import reconcile
        summary = reconcile(root, report, record_reviews)
        if review_limit:
            from roc import draft_review
            status['stages'].append(dict(name='llm-review', state='running'))
            native_drafts.atomic(status_file, status)
            draft_review.prepare(root)
            reviewed = draft_review.work(root, 'codex:gpt-6-luna', review_limit)
            status['stages'][-1].update(state='done', attempted=reviewed['attempted'], proposals=reviewed['proposals'])
            if reviewed['proposals']:
                subprocess.run([sys.executable, '-m', 'roc.draft_native', '--reviews-only', '--root', str(root)],
                               cwd=root, check=True)
        from roc import draft_getter_queue
        draft_getter_queue.discover(root)
        status['getter_results'] = draft_getter_queue.work(root, apply)
        summary = reconcile(root, report, record_reviews)
        if publish:
            from roc.draft_publish import publish as publish_sources
            status['stages'].append(dict(name='source-publication', state='running'))
            native_drafts.atomic(status_file, status)
            status['publication'] = publish_sources(root, push=True)
            status['stages'][-1].update(state=status['publication']['state'])
            summary = reconcile(root, report, record_reviews)
        status.update(state='processed-pending-acceptance', summary=summary,
                      pending='Complete independent acceptance proof and source/family integration adapters')
        return summary
    except Exception as error:
        status.update(state='failed', error=str(error))
        raise
    finally:
        native_drafts.atomic(status_file, status)


if __name__ == '__main__':
    main()

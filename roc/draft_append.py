"""Proof-bound, append-only reconciliation for existing native class sources."""
import json
import os
from pathlib import Path

from roc import draft_files, draft_merger, native_drafts


def apply_append_file(root, db, run, bundle, path, raw, proof_id, expected, lease_check, input_check):
    """Append verified methods without replacing or activating existing source."""
    native_drafts.safe_path(path)
    if (not path.startswith('rebuild/2008-06/native-classes/') or
            Path(path).suffix.lower() not in ('.cpp', '.cc', '.cxx')):
        raise ValueError('Append adapter only writes native class source')
    if draft_merger.content_hash(raw) != expected['candidate_sha256']:
        raise ValueError('Candidate bytes changed since proof')
    proof = draft_merger.checked_proof(db, proof_id, expected)
    if proof.get('path') != path:
        raise ValueError('Proof path differs from integration target')

    root = Path(root).resolve()
    target = root / path
    identity = draft_merger.proof_key(dict(proof=proof_id, path=path,
                                           sha256=draft_merger.content_hash(raw)))
    state = draft_merger.canonical_state(root, [path])[path]
    existing = db.execute('SELECT state,before_sha256,after_sha256 FROM actions WHERE id=?', (identity,)).fetchone()
    if existing:
        if state['sha256'] == existing[2]:
            with db:
                db.execute('UPDATE actions SET state=? WHERE id=?', ('applied-inactive', identity))
            return dict(action=identity, state='applied-inactive', recovered=True)
        if existing[0] != 'prepared' or state['sha256'] != existing[1]:
            raise ValueError('Interrupted integration needs reconciliation; target identity differs')
    if not state['exists']:
        raise ValueError('Append target does not exist')

    before = target.read_bytes()
    before_sha256 = draft_merger.content_hash(before)
    if state['sha256'] != before_sha256:
        raise ValueError('Canonical source changed while reading')
    if (proof.get('before_sha256') != before_sha256 or
            ('before_sha256' in expected and expected['before_sha256'] != before_sha256)):
        raise ValueError('Proof baseline differs from current source')
    if len(raw) <= len(before) or not raw.startswith(before):
        raise ValueError('Candidate is not a strict append of current source')

    lease_check(path)
    if input_check() != expected['input_key']:
        raise ValueError('Inputs changed since independent proof')
    if draft_merger.canonical_state(root, [path])[path]['sha256'] != before_sha256:
        raise ValueError('Canonical source changed since append checks')

    if not existing:
        with db:
            db.execute('INSERT OR IGNORE INTO contents VALUES(?,?)', (before_sha256, before))
            db.execute('INSERT OR IGNORE INTO contents VALUES(?,?)',
                       (draft_merger.content_hash(raw), raw))
            db.execute('INSERT INTO actions VALUES(?,?,?,?,?,?,?,?)',
                       (identity, run, bundle, path, before_sha256,
                        draft_merger.content_hash(raw), 'prepared',
                        json.dumps(dict(proof=proof_id, input_key=expected['input_key'],
                                        before_sha256=before_sha256,
                                        after_sha256=draft_merger.content_hash(raw)))))

    with draft_files.exclusive_existing(target) as stream:
        stream.seek(0)
        locked_before = stream.read()
        if draft_merger.content_hash(locked_before) != before_sha256:
            raise ValueError('Canonical source changed before exclusive append; prepared action needs reconciliation')
        stream.seek(0, 2)
        stream.write(raw[len(before):])
        stream.flush()
        os.fsync(stream.fileno())
        stream.seek(0)
        if stream.read() != raw:
            raise ValueError('Append result differs from prepared candidate; prepared action needs reconciliation')

    with db:
        db.execute('UPDATE actions SET state=? WHERE id=?', ('applied-inactive', identity))
    return dict(action=identity, state='applied-inactive', recovered=False)

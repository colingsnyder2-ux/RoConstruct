"""Durable, bounded family diagnostics for every inbox bundle; never source acceptance."""
import argparse
from contextlib import closing
import json
from pathlib import Path
import sqlite3
import time

from roc import draft_family, native_drafts
from roc.draft_merger import content_hash, proof_key

SCHEMA = '''CREATE TABLE IF NOT EXISTS family_jobs(
 id TEXT PRIMARY KEY,bundle TEXT,seq INTEGER,user TEXT,input_key TEXT,profile TEXT,state TEXT,
 attempts INTEGER DEFAULT 0,output TEXT,detail TEXT,updated REAL);'''
GATES = ('draft_family_queue.py', 'draft_family.py', 'draft_native.py', 'draft_methods.py',
         'match.py', 'rebuild.py', 'integration_verify.py')


def identity(root):
    from roc.integration_verify import input_hash
    paths = [root / 'roc' / name for name in GATES]
    paths += [root / 'work/native-client' / (name + '.py')
              for name in ('native_class_layout', 'native_vftable_check', 'native_conversion_queue')]
    paths += [root / 'rebuild/2008-06/tests/native_bind.py',
              root / 'work/native-client/claude-identity-closure.json']
    return dict(native_input_key=input_hash(root),
                gates={path.relative_to(root).as_posix(): content_hash(path.read_bytes()) for path in paths})


def schema(db):
    db.execute(SCHEMA)
    if 'user' not in {row[1] for row in db.execute('PRAGMA table_info(family_jobs)')}:
        db.execute('ALTER TABLE family_jobs ADD COLUMN user TEXT')


def plan(root):
    root = Path(root).resolve()
    folder = root / 'work/draft-merger'
    folder.mkdir(parents=True, exist_ok=True)
    with native_drafts.lock(root / 'work/draft-integration.lock'):
        pinned = identity(root)
        key = proof_key(pinned)
        inbox = native_drafts.Inbox(root)
        with inbox.connect() as source:
            bundles = source.execute('SELECT seq,id,user,packet FROM bundles ORDER BY seq').fetchall()
        evidence, latest_native = {}, {}
        for seq, identifier, user, raw in bundles:
            packet = json.loads(raw)
            native = any(draft_family.canonical_proposal_path(root, name).startswith(draft_family.NATIVE_PREFIXES)
                         and Path(draft_family.canonical_proposal_path(root, name)).suffix.lower() in draft_family.NATIVE_SUFFIXES
                         for name in packet.get('files', {}))
            owner = user.lower()
            if native:
                latest_native[owner] = identifier
            elif latest_native.get(owner) and any(name.endswith('.json') for name in packet.get('files', {})):
                evidence.setdefault(latest_native[owner], []).append((seq, identifier))
        jobs = []
        with closing(sqlite3.connect(folder / 'state.sqlite3')) as db, db:
            schema(db)
            for seq, bundle, user, raw in bundles:
                state, profiles, detail = 'queued', ['default'], {}
                try:
                    packet = json.loads(raw)
                    native_drafts.validate(packet)
                    if native_drafts.digest(packet) != bundle:
                        raise ValueError('Draft storage hash mismatch')
                    eligible = []
                    for name, change in packet['files'].items():
                        mapped = draft_family.canonical_proposal_path(root, name)
                        if mapped.startswith(draft_family.NATIVE_PREFIXES) and Path(mapped).suffix.lower() in draft_family.NATIVE_SUFFIXES:
                            eligible.append((name, mapped, change))
                    if not eligible:
                        state = 'non-native-review'
                        detail['blocker'] = 'No supported native source/header path; retain evidence/documentation/script review'
                    else:
                        detail['paths'] = [dict(uploaded=name, canonical=mapped) for name, mapped, _ in eligible]
                        detail['companions'] = [identifier for _, identifier in evidence.get(bundle, [])
                                                if identifier != bundle]
                        text = '\n'.join(change['text'] or '' for _, _, change in eligible)
                        if '/fp:fast' in text:
                            profiles = ['default', 'partchunk-fast-fp' if '/partchunk-profile' in text else 'fast-fp']
                        if not any(Path(mapped).suffix.lower() in ('.cpp', '.cc', '.c', '.cxx') for _, mapped, _ in eligible):
                            detail['blocker'] = 'Header-only proposal needs an affected-source companion/dependency review'
                except (ValueError, TypeError, UnicodeError) as error:
                    state, detail = 'invalid-storage', dict(blocker=str(error))
                for profile in profiles:
                    job = proof_key(dict(bundle=bundle, companions=detail.get('companions', []), inputs=key, profile=profile))
                    db.execute('''INSERT INTO family_jobs
                        (id,bundle,seq,user,input_key,profile,state,attempts,output,detail,updated)
                        VALUES(?,?,?,?,?,?,?,0,NULL,?,?) ON CONFLICT(id) DO UPDATE SET user=excluded.user''',
                               (job, bundle, seq, user, key, profile, state, json.dumps(detail), time.time()))
                    jobs.append(job)
        stale = identity(root) != pinned
        result = dict(input_key=key, identity=pinned, jobs=jobs, bundle_count=len(bundles),
                      max_seq=max((row[0] for row in bundles), default=0), stale=stale)
        native_drafts.atomic(folder / 'family-queue.json', result)
        return summary(root)


def summary(root):
    folder = Path(root) / 'work/draft-merger'
    queue = json.loads((folder / 'family-queue.json').read_text())
    with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
        states = dict(db.execute('SELECT state,COUNT(*) FROM family_jobs WHERE input_key=? GROUP BY state',
                                 (queue['input_key'],)))
    return dict(bundle_count=queue['bundle_count'], max_seq=queue['max_seq'], stale=queue['stale'], states=states)


def work(root, limit=3, users=()):
    root = Path(root).resolve()
    if not 0 <= limit <= 100:
        raise ValueError('Family work limit must be between 0 and 100')
    folder = root / 'work/draft-merger'
    completed = []
    with native_drafts.lock(root / 'work/draft-integration.lock'):
        queue = json.loads((folder / 'family-queue.json').read_text())
        if queue['stale'] or identity(root) != queue['identity']:
            raise ValueError('Family queue inputs changed; prepare a fresh plan')
        with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
            schema(db)
            where, values = '', [queue['input_key']]
            if users:
                where = 'AND lower(user) IN (' + ','.join('?' for _ in users) + ') '
                values.extend(str(user).lower() for user in users)
            values.append(limit)
            jobs = db.execute("SELECT id,bundle,profile,output,attempts,detail FROM family_jobs WHERE input_key=? "
                              "AND state IN ('queued','running','infrastructure-error') AND attempts<3 " + where +
                              'ORDER BY seq DESC,profile LIMIT ?', values).fetchall()
            # The OS lock proves there is no live worker owning these running rows.
            for job, bundle, profile, output, attempts, context in jobs:
                context = json.loads(context).get('planning', json.loads(context))
                with db:
                    db.execute("UPDATE family_jobs SET state='running',attempts=?,updated=? WHERE id=?",
                               (attempts + 1, time.time(), job))
                try:
                    if output:
                        output = Path(output).resolve()
                        if not output.is_relative_to(root / 'work/draft-merger/families'):
                            raise ValueError('Saved family output escaped scratch')
                        manifest = json.loads((output / 'manifest.json').read_text())
                        if manifest['bundle_id'] != bundle:
                            raise ValueError('Saved family output belongs to another bundle')
                        if manifest.get('companion_bundles', []) != context.get('companions', []):
                            raise ValueError('Saved family output has different evidence companions')
                    else:
                        manifest = draft_family.prepare(root, bundle, companions=context.get('companions', []))
                        output = Path(manifest['output'])
                        with db:
                            db.execute('UPDATE family_jobs SET output=? WHERE id=?', (str(output), job))
                    result = draft_family.measure(root, output, profile)
                    state = result['state']
                    detail = dict(planning=context, artifact=str(output / 'measurement.json'), summary=result.get('summary'),
                                  blockers=result.get('blockers', []), accepted=0)
                except Exception as error:
                    state = 'needs-tool-repair' if attempts + 1 >= 3 else 'infrastructure-error'
                    detail = dict(planning=context, blocker=type(error).__name__ + ': ' + str(error), accepted=0)
                with db:
                    db.execute('UPDATE family_jobs SET state=?,detail=?,updated=? WHERE id=?',
                               (state, json.dumps(detail), time.time(), job))
                completed.append(dict(job=job, bundle=bundle, profile=profile, state=state, **detail))
            stale = identity(root) != queue['identity']
            if stale:
                with db:
                    for row in completed:
                        db.execute("UPDATE family_jobs SET state='stale' WHERE id=?", (row['job'],))
                        row['state'] = 'stale'
                queue['stale'] = True
                native_drafts.atomic(folder / 'family-queue.json', queue)
    result = dict(attempted=len(completed), accepted=0, stale=stale, results=completed)
    native_drafts.atomic(folder / 'family-work-latest.json', result)
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('plan', 'work', 'status'))
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--limit', type=int, default=3)
    parser.add_argument('--user', action='append', default=[])
    args = parser.parse_args()
    print(json.dumps(plan(args.root) if args.action == 'plan' else work(args.root, args.limit, args.user)
                     if args.action == 'work' else summary(args.root), indent=2))

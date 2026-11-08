"""Durable, branch-free native draft checkpoints. Uploads never execute or activate code."""
import argparse
import difflib
from contextlib import contextmanager
from fnmatch import fnmatchcase
import hashlib
import io
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import os
from pathlib import Path, PurePosixPath
import re
import secrets
import sqlite3
import subprocess
import sys
import threading
import time
from urllib.error import HTTPError
from urllib.request import Request, urlopen
import uuid

ROOT = Path(__file__).resolve().parents[1]
MAX_BYTES = 16 * 1024 * 1024
PREFIXES = ('rebuild/', 'roc/', 'tests/', 'docs/', 'research/', 'benchmarks/',
            'packaging/', 'work/2008-06/shared-layouts/', 'work/native-candidates/')
ROOT_FILES = ('roc.py','roc.cmd','roc.sh','install.cmd','install.sh','CLAUDE.md','AGENTS.md','README.md')
SUFFIXES = ('.cpp', '.c', '.cc', '.cxx', '.h', '.hpp', '.inl', '.inc', '.ipp', '.def', '.rc',
            '.py', '.json', '.jsonl', '.md', '.txt', '.ps1', '.sh', '.cmd', '.bat', '.cmake',
            '.yml', '.yaml', '.toml', '.js', '.html', '.css', '.svg')


def encoded(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode()


def digest(value):
    return hashlib.sha256(encoded(value)).hexdigest()


def atomic(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + '.' + uuid.uuid4().hex + '.tmp')
    with temporary.open('wb') as stream:
        stream.write(encoded(value))
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temporary, path)


@contextmanager
def lock(path):
    """OS lock: process death releases ownership, never steal a running worker's lock."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('a+b') as stream:
        stream.write(b'0')
        stream.flush()
        stream.seek(0)
        try:
            if os.name == 'nt':
                import msvcrt
                msvcrt.locking(stream.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError as error:
            raise RuntimeError('Already running: ' + str(path)) from error
        try:
            yield
        finally:
            stream.seek(0)
            if os.name == 'nt':
                msvcrt.locking(stream.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(stream.fileno(), fcntl.LOCK_UN)


def safe_path(name):
    if not isinstance(name, str):
        raise ValueError('Draft path must be text')
    p = PurePosixPath(name)
    if (not name or p.as_posix() != name or p.is_absolute() or '..' in p.parts
            or '\\' in name or ':' in name or any(x.startswith('.') or x.endswith((' ', '.')) for x in p.parts)
            or not (name.startswith(PREFIXES) or name in ROOT_FILES) or p.suffix not in SUFFIXES
            or any(x.lower() in ('out', '__pycache__', 'source', 'secrets', 'config') for x in p.parts)
            or re.search(r'(?i)^(?:roconstruct[-_])?(?:secret|credential|token|password|providers|settings)s?\.', p.name)
            or any(re.fullmatch(r'(?i)(con|prn|aux|nul|com[1-9]|lpt[1-9])(\..*)?', x) for x in p.parts)):
        raise ValueError('Unsupported/private draft path: ' + name)
    return name


def validate(packet):
    if not isinstance(packet, dict) or packet.get('schema') != 1:
        raise ValueError('Unsupported draft schema')
    if len(encoded(packet)) > MAX_BYTES:
        raise ValueError('Draft exceeds 16 MiB; split task paths into smaller sessions')
    if not re.fullmatch(r'[A-Za-z0-9_.-]{2,32}', str(packet.get('user', ''))):
        raise ValueError('Need contributor username: 2-32 letters, numbers, dot, underscore, dash')
    if not isinstance(packet.get('model'), str) or not 1 <= len(packet['model']) <= 120:
        raise ValueError('Actual model identity required')
    if not re.fullmatch('[0-9a-f]{32}', str(packet.get('session', ''))):
        raise ValueError('Invalid session identity')
    if not isinstance(packet.get('baseline'), str) or not 1 <= len(packet['baseline']) <= 128:
        raise ValueError('Missing baseline identity')
    files = packet.get('files')
    if not isinstance(files, dict) or not 1 <= len(files) <= 1000:
        raise ValueError('Need 1-1000 changed paths')
    if len({p.casefold() for p in files}) != len(files):
        raise ValueError('Case-colliding paths')
    for name, row in files.items():
        safe_path(name)
        if not isinstance(row, dict) or set(row) != {'base', 'text'}:
            raise ValueError('Draft needs base and text per path')
        if any(v is not None and not isinstance(v, str) for v in row.values()) or row['base'] == row['text']:
            raise ValueError('Invalid/unchanged draft file')
        if any(v is not None and '\x00' in v for v in row.values()):
            raise ValueError('Binary draft files unsupported')
    return packet


def files(root, scopes):
    result = {}
    for scope in scopes:
        safe_path(scope + '/placeholder.cpp' if not Path(scope).suffix else scope)
        path = root / scope
        paths = sorted(path.rglob('*')) if path.is_dir() else [path]
        for p in paths:
            if p.is_symlink() or any(a.is_symlink() for a in p.parents if a != root and a.is_relative_to(root)) or not p.resolve().is_relative_to(root.resolve()):
                raise ValueError('Draft path escapes workspace: ' + str(p))
            if not p.is_file():
                continue
            rel = p.relative_to(root).as_posix()
            if path.is_dir() and (p.suffix not in SUFFIXES or any(a.lower() in ('__pycache__','out','source') for a in p.relative_to(path).parts)):
                continue
            safe_path(rel)
            stat = p.stat()
            if stat.st_size > MAX_BYTES // 2:
                raise ValueError('Draft file too large: ' + rel)
            raw = p.read_bytes()
            if p.stat().st_mtime_ns != stat.st_mtime_ns:
                raise RuntimeError('File still changing; checkpoint deferred: ' + rel)
            result[rel] = raw.decode('utf-8')
    return result


def session_path(root, session):
    if not re.fullmatch('[0-9a-f]{32}', session):
        raise ValueError('Invalid session')
    return root / 'local/drafts/sessions' / session


def initialize(root, scopes, user, model, server, baseline=None):
    root = Path(root)
    if not server.startswith(('https://', 'http://127.0.0.1:', 'http://localhost:')):
        raise ValueError('Draft server must use HTTPS (loopback HTTP allowed for tests)')
    current = files(root, scopes)
    marker = root / 'roconstruct-package.json'
    if not marker.exists() or json.loads(marker.read_text()).get('authority') != 'RoConstruct/work/workspace':
        raise ValueError('Use a verified findings Worker workspace; preserve this checkout and download the current package')
    revision = json.loads(marker.read_text()).get('revision')
    if not revision:
        p = subprocess.run(['git', 'rev-parse', 'HEAD'], cwd=root, capture_output=True, text=True)
        revision = p.stdout.strip() if p.returncode == 0 else None
    if not revision and not baseline:
        raise ValueError('Need package/Git baseline identity')
    session = uuid.uuid4().hex
    folder = session_path(root, session)
    state = dict(schema=1, user=user, model=model, session=session, server=server.rstrip('/'),
                 baseline=baseline or revision, scopes=scopes, base=current, last_files=None, parent=None)
    # A package inventory identifies edits made before session initialization.
    inventory_path = root / 'workspace-manifest.json'
    if not (root / '.git').exists() and inventory_path.exists():
        inventory = json.loads(inventory_path.read_text(encoding='utf-8'))['files']
        expected = {name: value for name, value in inventory.items()
                    if Path(name).suffix in SUFFIXES and any(name == scope or name.startswith(scope.rstrip('/') + '/') for scope in scopes)
                    and not any(part.lower() in ('__pycache__', 'out', 'source') for part in Path(name).parts)}
        dirty = sorted(name for name in current.keys() | expected.keys()
                       if name not in current or hashlib.sha256(current[name].encode('utf-8')).hexdigest() != expected.get(name))
        if dirty:
            raise ValueError('Pre-existing package edits in watched paths; preserve the old session/outbox and initialize an untouched package before porting: ' + ', '.join(dirty))
    # Existing Git edits must remain drafts, not silently become the baseline.
    if (root / '.git').exists():
        tracked = subprocess.check_output(['git','ls-tree','-r','--name-only','HEAD','--',*scopes],cwd=root).decode().splitlines()
        for rel in sorted(set(current) | set(tracked)):
            safe_path(rel)
            p = subprocess.run(['git', 'show', 'HEAD:' + rel], cwd=root, capture_output=True)
            state['base'][rel] = p.stdout.decode('utf-8') if p.returncode == 0 else None
    validate(dict(state, files={'docs/checkpoint.txt': {'base': None, 'text': 'identity check'}}))
    atomic(folder / 'session.json', state)
    return session


def snapshot_changes(root, state, folder):
    current = files(root, state['scopes'])
    changes = {p: dict(base=state['base'].get(p), text=current.get(p))
               for p in sorted(current.keys() | state['base'].keys())
               if state['base'].get(p) != current.get(p)}
    if state['parent']:
        previous = json.loads((folder / 'outbox' / (state['parent'] + '.json')).read_text())
        for name, row in previous['files'].items():
            if name not in changes:
                # A return to the immutable baseline must supersede the earlier edit.
                changes[name] = row if row['text'] == current.get(name) else dict(base=row['text'], text=current.get(name))
    return changes


def checkpoint(root, session):
    folder = session_path(root, session)
    with lock(folder / 'checkpoint.lock'):
        state = json.loads((folder / 'session.json').read_text())
        changes = snapshot_changes(root, state, folder)
        fingerprint = digest(changes)
        if not changes or state['last_files'] == fingerprint:
            return None
        packet = {k: state[k] for k in ('schema', 'user', 'model', 'session', 'baseline', 'parent')}
        packet.update(files=changes, created=time.time(), status='draft', exact_credits=0)
        validate(packet)
        identifier = digest(packet)
        atomic(folder / 'outbox' / (identifier + '.json'), packet)
        state.update(last_files=fingerprint, parent=identifier)
        atomic(folder / 'session.json', state)
        return identifier


def request(server, action, body=None, token=None):
    req = Request(server.rstrip('/') + '/v1/drafts/' + action, encoded(body) if body is not None else None,
                  {'Content-Type': 'application/json', **({'Authorization': 'Bearer ' + token} if token else {})})
    with urlopen(req, timeout=45) as response:
        return json.load(response)


def durable_receipt(folder, identifier):
    path = folder / 'receipts' / (identifier + '.json')
    if not path.exists():
        return None
    try:
        receipt = json.loads(path.read_text())
    except ValueError:
        return None
    return receipt if isinstance(receipt, dict) and receipt.get('id') == identifier and receipt.get('durable') is True else None


def status(root, session):
    folder = session_path(root, session)
    state = json.loads((folder / 'session.json').read_text())
    health = folder / 'health.json'
    outbox = list((folder / 'outbox').glob('*.json'))
    acknowledged = sum(durable_receipt(folder, p.stem) is not None for p in outbox)
    changes = snapshot_changes(root, state, folder)
    latest = state['parent']
    return dict(health=json.loads(health.read_text()) if health.exists() else None,
                queued=len(outbox), acknowledged=acknowledged, pending=len(outbox)-acknowledged,
                latest_packet=latest, latest_receipt=durable_receipt(folder, latest) if latest else None,
                snapshot_current=(digest(changes) == state['last_files']) if latest else not changes)


def flush(root, session):
    folder = session_path(root, session)
    with lock(folder / 'flush.lock'):
        state = json.loads((folder / 'session.json').read_text())
        credentials = folder / 'credentials.json'
        if credentials.exists():
            auth = json.loads(credentials.read_text())
        else:
            auth = request(state['server'], 'register', dict(user=state['user']))
            atomic(credentials, auth)
        sent = []
        for path in sorted((folder / 'outbox').glob('*.json')):
            packet = json.loads(path.read_text())
            identifier = digest(packet)
            if durable_receipt(folder, identifier):
                continue
            receipt = request(state['server'], 'upload', packet, auth['token'])
            if receipt.get('id') != identifier or receipt.get('durable') is not True:
                raise ValueError('Server did not acknowledge durable draft identity')
            atomic(folder / 'receipts' / (identifier + '.json'), receipt)
            sent.append(identifier)
        return sent


class Inbox:
    def __init__(self, root):
        self.root = Path(root)
        self.path = self.root / 'work/agent-inbox/drafts.sqlite3'
        self.path.parent.mkdir(parents=True, exist_ok=True)
        with self.connect() as db:
            db.executescript('''CREATE TABLE IF NOT EXISTS credentials(token TEXT PRIMARY KEY,user TEXT);
                CREATE TABLE IF NOT EXISTS bundles(seq INTEGER PRIMARY KEY AUTOINCREMENT,id TEXT UNIQUE,
                user TEXT,packet TEXT,received REAL);
                CREATE TABLE IF NOT EXISTS reviews(id TEXT PRIMARY KEY,state TEXT,detail TEXT,updated REAL);''')
            db.execute('''CREATE TABLE IF NOT EXISTS notes(user TEXT,scope TEXT,text TEXT,
                       updated REAL,expires REAL,PRIMARY KEY(user,scope))''')

    @contextmanager
    def connect(self):
        db = sqlite3.connect(self.path, timeout=30)
        db.execute('PRAGMA journal_mode=WAL')
        db.execute('PRAGMA synchronous=FULL')
        try:
            with db:
                yield db
        finally:
            db.close()

    def register(self, user):
        if not re.fullmatch(r'[A-Za-z0-9_.-]{2,32}', str(user)):
            raise ValueError('Invalid contributor username')
        token = secrets.token_hex(32)
        with self.connect() as db:
            db.execute('INSERT INTO credentials VALUES(?,?)', (hashlib.sha256(token.encode()).hexdigest(), user))
        return dict(user=user, token=token, scope='draft-upload-only')

    def receive(self, packet, token):
        validate(packet)
        identifier = digest(packet)
        with self.connect() as db:
            auth = db.execute('SELECT user FROM credentials WHERE token=?',
                              (hashlib.sha256(token.encode()).hexdigest(),)).fetchone()
            if not auth or auth[0] != packet['user']:
                raise PermissionError('Invalid contributor-scoped draft credential')
            used = db.execute('SELECT COALESCE(SUM(length(packet)),0) FROM bundles WHERE user=?', (auth[0],)).fetchone()[0]
            if used + len(encoded(packet)) > 512 * 1024 * 1024 and not db.execute('SELECT 1 FROM bundles WHERE id=?', (identifier,)).fetchone():
                raise ValueError('Contributor archive quota reached; owner review needed')
            inserted = db.execute('INSERT OR IGNORE INTO bundles(id,user,packet,received) VALUES(?,?,?,?)',
                       (identifier, packet['user'], encoded(packet).decode(), time.time())).rowcount == 1
            seq, received = db.execute('SELECT seq,received FROM bundles WHERE id=?', (identifier,)).fetchone()
        # SQLite is the authoritative queue; event feed is repairable and never executes payloads.
        if inserted:
            from roc.agent_inbox import record
            record('native-draft', packet['user'], packet['model'], inbox=self.root/'work/agent-inbox',
                   bundle=identifier, seq=seq, verified=False, exact_credits=0)
        return dict(id=identifier, seq=seq, durable=True, received=received, state='received', exact_credits=0)

    def pending(self):
        with self.connect() as db:
            return [dict(seq=seq, id=identifier, user=user, received=received, state=state or 'received')
                    for seq, identifier, user, received, state in db.execute('''SELECT b.seq,b.id,b.user,b.received,r.state
                    FROM bundles b LEFT JOIN reviews r ON b.id=r.id WHERE r.state IS NULL
                    OR r.state NOT IN ('published','duplicate','rejected') ORDER BY b.seq''')]

    def packet(self, identifier):
        with self.connect() as db:
            row = db.execute('SELECT packet FROM bundles WHERE id=?', (identifier,)).fetchone()
        if not row:
            raise ValueError('Unknown draft ID')
        packet = json.loads(row[0])
        validate(packet)
        if digest(packet) != identifier:
            raise ValueError('Draft storage hash mismatch')
        return packet

    def archive(self):
        with self.connect() as db:
            rows = db.execute('SELECT seq,id,packet FROM bundles ORDER BY seq').fetchall()
        result = {}
        for seq, identifier, text in rows:
            packet = validate(json.loads(text))
            if digest(packet) != identifier:
                raise ValueError('Draft archive hash mismatch')
            result['drafts/bundles/' + identifier + '.json'] = encoded(packet)
            for name,row in packet['files'].items():
                if row['text'] is not None:
                    result['drafts/files/' + identifier + '/' + name] = row['text'].encode('utf-8')
        result['drafts/index.json'] = encoded([dict(seq=s, id=i) for s, i, _ in rows])
        return result

    def notes(self):
        with self.connect() as db:
            return [dict(user=user,scope=scope,text=text,updated=updated,expires=expires,
                         advisory_only=True) for user,scope,text,updated,expires in
                    db.execute('SELECT user,scope,text,updated,expires FROM notes WHERE expires>? ORDER BY updated DESC LIMIT 100',(time.time(),))]

    def note(self,body,token):
        user,scope,text=body.get('user'),body.get('scope'),body.get('text')
        clear=body.get('clear',False)
        if not isinstance(scope,str) or not re.fullmatch(r'[\w:. -]{2,120}',scope):
            raise ValueError('Need one class/family coordination scope')
        if type(clear) is not bool or not clear and (not isinstance(text,str) or not 1<=len(text)<=280):
            raise ValueError('Note needs 1-280 characters')
        now=time.time()
        with self.connect() as db:
            db.execute('BEGIN IMMEDIATE')
            auth=db.execute('SELECT user FROM credentials WHERE token=?',(hashlib.sha256(token.encode()).hexdigest(),)).fetchone()
            if not auth or auth[0]!=user:
                raise PermissionError('Invalid contributor-scoped draft credential')
            prior=db.execute('SELECT text,updated,expires FROM notes WHERE user=? AND scope=?',(user,scope)).fetchone()
            if clear:
                db.execute('UPDATE notes SET expires=0 WHERE user=? AND scope=?',(user,scope))
                return dict(cleared=True,advisory_only=True)
            if prior and prior[0]==text and prior[2]>now:
                return dict(unchanged=True,advisory_only=True)
            latest=db.execute('SELECT MAX(updated) FROM notes WHERE user=?',(user,)).fetchone()[0]
            if prior and now-prior[1]<1800 or latest and now-latest<600:
                raise ValueError('Use leases for routine coordination. Notes: one per class/30 min, one per contributor/10 min.')
            db.execute('INSERT OR REPLACE INTO notes VALUES(?,?,?,?,?)',(user,scope,text,now,now+7200))
        return dict(saved=True,expires=now+7200,advisory_only=True)


def handler(inbox):
    class Handler(BaseHTTPRequestHandler):
        def log_message(self, *args):
            pass

        def send(self, code, value):
            body = encoded(value)
            self.send_response(code)
            self.send_header('Content-Type', 'application/json')
            self.send_header('Content-Length', str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def do_GET(self):
            if self.path.rstrip('/').endswith('/v1/drafts/health'):
                return self.send(200, dict(schema=1, draft_upload=True, exact_credits=0))
            if self.path.rstrip('/').endswith('/v1/drafts/notes'):
                return self.send(200,dict(notes=inbox.notes(),leases_authoritative=True))
            self.send(404, dict(error='Unknown draft endpoint'))

        def do_POST(self):
            try:
                self.connection.settimeout(30)
                length = int(self.headers.get('Content-Length', '0'))
                if not 0 < length <= MAX_BYTES:
                    return self.send(413, dict(error='Draft request too large or empty'))
                body = json.loads(self.rfile.read(length))
                if not isinstance(body, dict):
                    raise ValueError('Expected JSON object')
                if self.path.rstrip('/').endswith('/v1/drafts/register'):
                    return self.send(200, inbox.register(body.get('user')))
                if self.path.rstrip('/').endswith('/v1/drafts/upload'):
                    return self.send(200, inbox.receive(body, self.headers.get('Authorization', '').removeprefix('Bearer ')))
                if self.path.rstrip('/').endswith('/v1/drafts/note'):
                    return self.send(200,inbox.note(body,self.headers.get('Authorization','').removeprefix('Bearer ')))
                self.send(404, dict(error='Unknown draft endpoint'))
            except PermissionError as error:
                self.send(403, dict(error=str(error)))
            except (ValueError, TypeError, UnicodeError) as error:
                self.send(400, dict(error=str(error)))
    return Handler


def watch(root, session, every=300):
    folder = session_path(root, session)
    with lock(folder / 'watch.lock'):
        while not (folder / 'stop').exists():
            state = dict(pid=os.getpid(), heartbeat=time.time())
            try:
                state.update(checkpoint=checkpoint(root, session), sent=flush(root, session), error=None)
            except (OSError, ValueError, RuntimeError) as error:
                state['error'] = str(error)
            atomic(folder / 'health.json', state)
            for _ in range(every):
                if (folder / 'stop').exists():
                    break
                time.sleep(1)
        finish(root, session)


def finish(root, session):
    folder = session_path(root, session)
    health = dict(pid=os.getpid(), heartbeat=time.time(), stopped=True)
    try:
        health.update(checkpoint=checkpoint(root, session), sent=flush(root, session), error=None)
    except (OSError, ValueError, RuntimeError) as error:
        health['error'] = str(error)
        raise
    finally:
        atomic(folder / 'health.json', health)


def stop(root, session, wait=False, timeout=60):
    folder = session_path(root, session)
    (folder / 'stop').touch()
    if not wait:
        return dict(stopping=True)
    deadline = time.monotonic() + timeout
    while True:
        try:
            with lock(folder / 'watch.lock'):
                # Also handles a dead/not-yet-started watcher, without losing stop.
                finish(root, session)
                return dict(stopping=False, **status(root, session))
        except RuntimeError as error:
            if not str(error).startswith('Already running:'):
                raise
            if time.monotonic() >= deadline:
                raise RuntimeError('Watcher still stopping; retain session/outbox and retry stop --wait') from error
            time.sleep(.1)


def start(root, session, every=300):
    folder = session_path(root, session)
    with lock(folder / 'watch.lock'):
        (folder / 'stop').unlink(missing_ok=True)
    with (folder / 'watch.log').open('ab') as log:
        p = subprocess.Popen([sys.executable, '-m', 'roc.native_drafts', '--root', str(root), 'watch', session,
                              '--every', str(every)], cwd=root, stdin=subprocess.DEVNULL, stdout=log, stderr=log,
                             creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0,
                             start_new_session=os.name != 'nt')
    return dict(pid=p.pid, session=session)


def triage(root, ref='refs/remotes/findings/work', after=0, forks=(), include_diff=False, discover_forks=False):
    """Read-only draft/fork comparison. Results are leads, never verified review."""
    root = Path(root)

    def git(*args):
        return subprocess.check_output(['git', *args], cwd=root)

    def tree(commit, prefixes):
        result = {}
        for row in git('ls-tree', '-r', '-z', commit, '--', *prefixes).split(b'\0'):
            if row:
                meta, name = row.split(b'\t', 1)
                mode, kind, oid = meta.split()
                result[name.decode('utf-8', errors='surrogateescape')] = (mode.decode(), kind.decode(), oid.decode())
        return result

    commit = git('rev-parse', '--verify', ref + '^{commit}').decode().strip()
    current_tree = tree(commit, ['workspace/', '2008-06/'])
    pending = [row for row in Inbox(root).pending() if row['seq'] > after]
    inbox = Inbox(root)
    records, errors = [], []
    for row in pending:
        try:
            packet = inbox.packet(row['id'])
            for name, value in packet['files'].items():
                records.append({'path': name, 'text': value['text'], 'base_text': value['base'],
                                'source': {'kind': 'draft', 'seq': row['seq'], 'id': row['id'],
                                           'user': row['user'], 'model': packet['model'], 'state': row['state']}})
        except (OSError, ValueError) as error:
            errors.append({'id': row['id'], 'seq': row['seq'], 'error': str(error)})

    observed = []
    forks = list(forks)
    if discover_forks:
        state_path = root / 'work/native-draft-integration-state.json'
        try:
            reviewed = json.loads(state_path.read_text(encoding='utf-8')).get('reviewed_fork_tips', {}) if state_path.exists() else {}
        except (OSError, ValueError) as error:
            errors.append({'error': 'Cannot read reviewed fork tips: ' + str(error)})
            reviewed = {}
        for line in git('for-each-ref', '--format=%(refname)%09%(objectname)', 'refs/forks/').decode().splitlines():
            name, tip = line.split('\t', 1)
            label = name.removeprefix('refs/forks/')
            owner, _, branch = label.partition('/')
            if (not branch or owner == 'origin' or branch in ('archive', 'auto-merge/native',
                    'claude/p6-startup-20261101', 'codex/native-partial-search-20261029',
                    'contrib-snapshot', 'gh-pages') or
                    re.search(r'(^|[/_-])(bot|dependabot|renovate)([/_-]|$)', label, re.I)):
                continue
            item = {'ref': name, 'tip': tip}
            observed.append(item)
            if subprocess.run(['git', 'merge-base', '--is-ancestor', tip, commit], cwd=root, capture_output=True).returncode == 0:
                item['status'] = 'already_in_canonical'; continue
            old = reviewed.get(label)
            if not old:
                try:
                    old = git('merge-base', tip, commit).decode().strip()
                except subprocess.CalledProcessError:
                    item['status'] = 'no_base'
                    errors.append({'fork': label, 'error': 'No reviewed tip or common base'}); continue
            item['base'] = old
            item['status'] = 'unchanged' if old == tip else 'comparison_requested'
            if old != tip and not any(f[0] == label and tuple(f[1:]) == (old, tip) for f in forks):
                forks.append((label, old, tip))

    from roc.native_files_notify import NATIVE_DIRS, native_path, is_native
    native_dirs = NATIVE_DIRS
    for label, old, new in forks:
        if not re.fullmatch(r'[0-9a-f]{40}', old) or not re.fullmatch(r'[0-9a-f]{40}', new):
            errors.append({'fork': label, 'error': 'Fork comparison requires full lowercase commit IDs'}); continue
        if subprocess.run(['git', 'merge-base', '--is-ancestor', old, new], cwd=root,
                          capture_output=True).returncode:
            errors.append({'fork': label, 'old': old, 'new': new,
                           'error': 'Fork old commit is not an available ancestor of new commit'}); continue
        try:
            old_tree, new_tree = tree(old, native_dirs), tree(new, native_dirs)
            changed = git('diff', '--name-only', '-z', '--no-renames', old, new, '--', *native_dirs)
        except subprocess.CalledProcessError as error:
            errors.append({'fork': label, 'old': old, 'new': new, 'error': str(error)}); continue
        for raw in changed.split(b'\0'):
            if not raw:
                continue
            try:
                fork_path = raw.decode('utf-8')
                name = native_path(fork_path)
            except UnicodeDecodeError:
                errors.append({'fork': label, 'error': 'Non-UTF-8 fork path', 'path_bytes': raw.hex()}); continue
            try:
                safe_path(name)
            except ValueError as error:
                errors.append({'fork': label, 'path': name, 'error': str(error)}); continue
            records.append({'path': name, 'fork_new': new_tree.get(fork_path), 'fork_old': old_tree.get(fork_path),
                            'source': {'kind': 'fork', 'label': label, 'old': old, 'new': new,
                                       'fork_path': fork_path}})

    # Index exact native content across the canonical tree, including moved paths.
    native_entries = {name.removeprefix('workspace/'): entry for name, entry in current_tree.items()
                      if name.startswith('workspace/') and is_native(name)
                      and entry[0] in ('100644', '100755') and entry[1] == 'blob'}
    # Read each required blob once. Never read or alter the shared working tree.
    wanted = {entry[2] for entry in native_entries.values()}
    for row in records:
        name = row['path']
        public_path = name.removeprefix('rebuild/') if name.startswith('rebuild/2008-06/') else None
        for entry in (current_tree.get('workspace/' + name), current_tree.get(public_path),
                      row.get('fork_old'), row.get('fork_new')):
            if entry and entry[0] in ('100644', '100755') and entry[1] == 'blob':
                wanted.add(entry[2])
    blobs = {}
    if wanted:
        result = subprocess.run(['git', 'cat-file', '--batch'], cwd=root,
                                input=('\n'.join(sorted(wanted)) + '\n').encode(), capture_output=True, check=True)
        stream = io.BytesIO(result.stdout)
        for oid in sorted(wanted):
            header = stream.readline().split()
            if len(header) != 3 or header[0].decode() != oid or header[1] != b'blob':
                raise ValueError('Git blob identity mismatch')
            blobs[oid] = stream.read(int(header[2])); stream.read(1)

    content_paths = {}
    for name, entry in native_entries.items():
        content_paths.setdefault(hashlib.sha256(blobs[entry[2]]).hexdigest(), []).append(name)

    leases = None
    try:
        dbpath = root / 'work/server.db'
        with sqlite3.connect(dbpath.resolve().as_uri() + '?mode=ro', uri=True, timeout=1) as db:
            leases = [dict(name=name, user=user, patterns=json.loads(patterns), expires=expires)
                      for name, user, patterns, expires in db.execute(
                          'SELECT name,user,patterns,expires FROM file_leases WHERE expires>?', (time.time(),))]
    except (OSError, ValueError, sqlite3.Error):
        pass  # Unknown ownership is not an available lease.

    variants = {}
    normalize = lambda b: b.replace(b'\r\n', b'\n') if b is not None else None
    for row in records:
        name = row['path']; current = current_tree.get('workspace/' + name)
        if current and (current[0] not in ('100644', '100755') or current[1] != 'blob'):
            errors.append({'path': name, 'source': row['source'], 'error': 'Non-regular canonical path'}); continue
        current_bytes = blobs[current[2]] if current else None
        public_path = name.removeprefix('rebuild/') if name.startswith('rebuild/2008-06/') else None
        public = current_tree.get(public_path)
        if public and (public[0] not in ('100644', '100755') or public[1] != 'blob'):
            errors.append({'path': public_path, 'source': row['source'], 'error': 'Non-regular public path'})
            public = None
        public_bytes = blobs[public[2]] if public else None
        if row['source']['kind'] == 'fork':
            old, new = row.get('fork_old'), row.get('fork_new')
            if any(e and (e[0] not in ('100644', '100755') or e[1] != 'blob') for e in (old, new)):
                errors.append({'path': name, 'source': row['source'], 'error': 'Non-regular fork path'}); continue
            base_bytes = blobs[old[2]] if old else None
            candidate = blobs[new[2]] if new else None
        else:
            try:
                base_bytes = row['base_text'].encode('utf-8') if row['base_text'] is not None else None
                candidate = row['text'].encode('utf-8') if row['text'] is not None else None
            except UnicodeEncodeError:
                errors.append({'path': name, 'source': row['source'], 'error': 'Invalid Unicode in draft content'}); continue
        identity = hashlib.sha256(candidate).hexdigest() if candidate is not None else None
        key = (name, identity)
        if candidate is None:
            relation = 'deletion_proposed'
        elif normalize(candidate) == normalize(current_bytes):
            relation = 'same_content' if candidate == current_bytes else 'newline_only'
        elif current_bytes is None and base_bytes is None:
            relation = 'new_path'
        elif base_bytes is None:
            relation = 'base_unavailable'
        elif current_bytes is None:
            relation = 'canonical_path_missing'
        elif normalize(base_bytes) == normalize(current_bytes):
            relation = 'base_matches_current'
        else:
            relation = 'three_way_review'
        source = dict(row['source'], relation=relation,
                      base_sha256=hashlib.sha256(base_bytes).hexdigest() if base_bytes is not None else None)
        if key not in variants:
            covering = None if leases is None else [dict(name=l['name'], user=l['user'], expires=l['expires'])
                for l in leases if any(fnmatchcase(name, pattern) for pattern in l['patterns'])]
            public_relation = ('missing' if public_bytes is None else
                               'deletion_proposed' if candidate is None else
                               'same_content' if candidate == public_bytes else
                               'newline_only' if normalize(candidate) == normalize(public_bytes) else 'different')
            item = dict(path=name, candidate_sha256=identity,
                        canonical_sha256=hashlib.sha256(current_bytes).hexdigest() if current_bytes is not None else None,
                        public_path=public_path if public is not None else None,
                        public_sha256=hashlib.sha256(public_bytes).hexdigest() if public_bytes is not None else None,
                        public_relation=public_relation,
                        canonical_identical_paths=sorted(content_paths.get(identity, [])) if identity else [],
                        leases=covering, sources=[])
            if include_diff:
                try:
                    before = (current_bytes or b'').decode('utf-8').splitlines(keepends=True)
                    after_text = (candidate or b'').decode('utf-8').splitlines(keepends=True)
                    item['diff'] = ''.join(difflib.unified_diff(before, after_text,
                                           fromfile='work/' + name, tofile='candidate/' + name))
                    if public_bytes is not None and public_bytes != current_bytes:
                        public_lines = public_bytes.decode('utf-8').splitlines(keepends=True)
                        item['public_diff'] = ''.join(difflib.unified_diff(public_lines, after_text,
                                                      fromfile=public_path, tofile='candidate/' + name))
                except UnicodeDecodeError:
                    item['diff_error'] = 'Non-UTF-8 content; inspect blob separately'
            variants[key] = item
        variants[key]['sources'].append(source)
    return {'scope': 'Read-only triage; no code executed, review decision, verification, integration or credit.',
            'forks_observed': observed,
            'canonical_commit': commit, 'after_seq': after, 'pending_packets': len(pending),
            'lease_state': 'current local server DB' if leases is not None else 'unknown',
            'variants': list(variants.values()), 'errors': errors}


def integration_lock(root, action, token=None):
    """Hold one OS lock across separate automation tool calls; bounded orphan lifetime."""
    folder = root / 'work/draft-integration-guard'
    folder.mkdir(parents=True, exist_ok=True)
    if action == 'hold':
        with lock(root / 'work/draft-integration.lock'):
            atomic(folder / 'owner.json', dict(token=token,pid=os.getpid(),started=time.time()))
            for _ in range(3 * 3600):
                if (folder / (token + '.stop')).exists():
                    break
                time.sleep(1)
        return dict(released=True)
    if action == 'release':
        owner = json.loads((folder / 'owner.json').read_text())
        if owner['token'] != token:
            raise ValueError('Integration lock belongs to another run')
        (folder / (token + '.stop')).touch()
        return dict(releasing=True)
    with lock(root / 'work/draft-integration.lock'):
        pass
    token = uuid.uuid4().hex
    with (folder / 'guard.log').open('ab') as log:
        p = subprocess.Popen([sys.executable,'-m','roc.native_drafts','--root',str(root),
                              'integration-lock','hold','--token',token],cwd=root,
                             stdin=subprocess.DEVNULL,stdout=log,stderr=log,
                             creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0,
                             start_new_session=os.name != 'nt')
    for _ in range(50):
        owner = folder / 'owner.json'
        if owner.exists() and json.loads(owner.read_text()).get('token') == token:
            return dict(token=token,pid=p.pid,expires_in_seconds=10800)
        if p.poll() is not None:
            raise RuntimeError('Integration lock unavailable; another run may have started')
        time.sleep(.1)
    raise RuntimeError('Integration lock startup timed out')


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    sub = parser.add_subparsers(dest='action', required=True)
    init = sub.add_parser('init')
    init.add_argument('--paths', nargs='+', required=True)
    init.add_argument('--user', required=True)
    init.add_argument('--model', required=True)
    init.add_argument('--server', required=True)
    for action in ('checkpoint', 'flush', 'start', 'watch', 'stop', 'status'):
        p = sub.add_parser(action)
        p.add_argument('session')
        if action in ('watch', 'start'):
            p.add_argument('--every', type=int, default=300)
        if action == 'stop':
            p.add_argument('--wait', action='store_true')
            p.add_argument('--timeout', type=float, default=60)
    sub.add_parser('pending')
    scan = sub.add_parser('triage', help='Read-only deduplicated draft/fork comparison; does not approve or execute')
    scan.add_argument('--ref', default='refs/remotes/findings/work', help='Fetched canonical work commit/ref')
    scan.add_argument('--after', type=int, default=0, help='Only pending draft sequences after this value')
    scan.add_argument('--fork', nargs=3, action='append', default=[], metavar=('LABEL', 'OLD_SHA', 'NEW_SHA'),
                      help='Compare a reviewed fork range already fetched locally; repeat for each branch')
    scan.add_argument('--discover-forks', action='store_true', help='Compare locally fetched contributor refs; never fetch or advance review tips')
    scan.add_argument('--diff', action='store_true', help='Include complete untrusted unified diffs')
    scan.add_argument('--output', type=Path, help='Write new JSON report without replacing an existing file')
    notes=sub.add_parser('notes')
    notes.add_argument('--server')
    note=sub.add_parser('note')
    note.add_argument('session')
    note.add_argument('--scope',required=True)
    note.add_argument('--text')
    note.add_argument('--clear',action='store_true')
    show = sub.add_parser('show')
    show.add_argument('id')
    review = sub.add_parser('review')
    review.add_argument('id')
    review.add_argument('--state', required=True, choices=['reviewing','parked','integrated-inactive','verified','pushed','published','duplicate','rejected'])
    review.add_argument('--detail', required=True)
    host = sub.add_parser('host')
    host.add_argument('--port', type=int, default=8766)
    host.add_argument('--publish-every', type=int, default=3600)
    sub.add_parser('supervise')
    guard = sub.add_parser('integration-lock')
    guard.add_argument('operation', choices=['start','release','hold'])
    guard.add_argument('--token')
    args = parser.parse_args(argv)
    root = args.root.resolve()
    if args.action == 'integration-lock':
        if args.operation != 'start' and not re.fullmatch('[0-9a-f]{32}', args.token or ''):
            raise ValueError('Need integration run token')
        result = integration_lock(root,args.operation,args.token)
    elif args.action == 'init':
        result = dict(session=initialize(root, args.paths, args.user, args.model, args.server))
    elif args.action in ('checkpoint', 'flush', 'start'):
        result = globals()[args.action](root, args.session, **({'every': max(10,args.every)} if args.action == 'start' else {}))
    elif args.action == 'watch':
        return watch(root, args.session, max(10, args.every))
    elif args.action == 'stop':
        result = stop(root, args.session, args.wait, max(0,args.timeout))
    elif args.action == 'status':
        result = status(root, args.session)
    elif args.action == 'notes':
        result=request(args.server,'notes') if args.server else Inbox(root).notes()
    elif args.action == 'note':
        flush(root,args.session)
        folder=session_path(root,args.session)
        state=json.loads((folder/'session.json').read_text())
        auth=json.loads((folder/'credentials.json').read_text())
        result=request(state['server'],'note',dict(user=state['user'],scope=args.scope,text=args.text,clear=args.clear),auth['token'])
    elif args.action == 'supervise':
        with lock(root / 'work/native-draft-supervisor.lock'):
            while True:
                with (root / 'work/native-draft-host.log').open('ab') as log:
                    children = [subprocess.Popen(command,cwd=root,stdin=subprocess.DEVNULL,stdout=log,stderr=log,
                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0)
                                for command in (
                                    [sys.executable,'-u','-m','roc.native_drafts','--root',str(root),'host'],
                                    [sys.executable,'-u',str(root/'roc.py'),'server','--publisher-only',
                                     '--publisher-parent',str(os.getpid())])]
                    while all(child.poll() is None for child in children):
                        time.sleep(5)
                    for child in children:
                        if child.poll() is None:
                            child.terminate()
                            child.wait(timeout=30)
                time.sleep(30)
    elif args.action == 'host':
        inbox = Inbox(root)
        with lock(root / 'work/native-draft-host.lock'):
            from roc.findings_workspace import publish_loop
            threading.Thread(target=publish_loop, args=(root, max(30,args.publish_every)), daemon=True).start()
            ThreadingHTTPServer(('127.0.0.1', args.port), handler(inbox)).serve_forever()
        return
    else:
        inbox = Inbox(root)
        if args.action == 'pending':
            result = inbox.pending()
        elif args.action == 'triage':
            if args.after < 0:
                raise ValueError('--after must be nonnegative')
            result = triage(root, args.ref, args.after, args.fork, args.diff, args.discover_forks)
            if args.output:
                with args.output.open('x', encoding='utf-8', newline='\n') as stream:
                    json.dump(result, stream, indent=2, ensure_ascii=True)
                    stream.write('\n')
                print('Triage report written:', args.output)
                return
        elif args.action == 'show':
            result = inbox.packet(args.id)
        else:
            inbox.packet(args.id)
            with inbox.connect() as db:
                db.execute('INSERT OR REPLACE INTO reviews VALUES(?,?,?,?)', (args.id,args.state,args.detail,time.time()))
            result = dict(id=args.id, state=args.state)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()

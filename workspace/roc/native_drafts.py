"""Durable, branch-free native draft checkpoints. Uploads never execute or activate code."""
import argparse
from contextlib import contextmanager
import hashlib
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
            'work/2008-06/shared-layouts/', 'work/native-candidates/')
SUFFIXES = ('.cpp', '.c', '.h', '.hpp', '.inl', '.py', '.json', '.jsonl', '.md', '.txt')


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
            or not name.startswith(PREFIXES) or p.suffix not in SUFFIXES
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
    revision = json.loads(marker.read_text()).get('revision') if marker.exists() else None
    if not revision:
        p = subprocess.run(['git', 'rev-parse', 'HEAD'], cwd=root, capture_output=True, text=True)
        revision = p.stdout.strip() if p.returncode == 0 else None
    if not revision and not baseline:
        raise ValueError('Need package/Git baseline identity')
    session = uuid.uuid4().hex
    folder = session_path(root, session)
    state = dict(schema=1, user=user, model=model, session=session, server=server.rstrip('/'),
                 baseline=baseline or revision, scopes=scopes, base=current, last_files=None, parent=None)
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


def checkpoint(root, session):
    folder = session_path(root, session)
    with lock(folder / 'checkpoint.lock'):
        state = json.loads((folder / 'session.json').read_text())
        current = files(root, state['scopes'])
        changes = {p: dict(base=state['base'].get(p), text=current.get(p))
                   for p in sorted(current.keys() | state['base'].keys())
                   if state['base'].get(p) != current.get(p)}
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


def request(server, action, body, token=None):
    req = Request(server.rstrip('/') + '/v1/drafts/' + action, encoded(body),
                  {'Content-Type': 'application/json', **({'Authorization': 'Bearer ' + token} if token else {})})
    with urlopen(req, timeout=45) as response:
        return json.load(response)


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
            if (folder / 'receipts' / (identifier + '.json')).exists():
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
        result['drafts/index.json'] = encoded([dict(seq=s, id=i) for s, i, _ in rows])
        return result


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
                self.send(404, dict(error='Unknown draft endpoint'))
            except PermissionError as error:
                self.send(403, dict(error=str(error)))
            except (ValueError, TypeError, UnicodeError) as error:
                self.send(400, dict(error=str(error)))
    return Handler


def watch(root, session, every=300):
    folder = session_path(root, session)
    with lock(folder / 'watch.lock'):
        (folder / 'stop').unlink(missing_ok=True)
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
        checkpoint(root, session)
        try:
            flush(root, session)
        except (OSError, ValueError, RuntimeError) as error:
            atomic(folder / 'health.json', dict(stopped=True, error=str(error)))


def start(root, session, every=300):
    folder = session_path(root, session)
    with lock(folder / 'watch.lock'):
        pass
    with (folder / 'watch.log').open('ab') as log:
        p = subprocess.Popen([sys.executable, '-m', 'roc.native_drafts', '--root', str(root), 'watch', session,
                              '--every', str(every)], cwd=root, stdin=subprocess.DEVNULL, stdout=log, stderr=log,
                             creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0,
                             start_new_session=os.name != 'nt')
    return dict(pid=p.pid, session=session)


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
    sub.add_parser('pending')
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
        (session_path(root, args.session) / 'stop').touch()
        result = dict(stopping=True)
    elif args.action == 'status':
        folder = session_path(root, args.session)
        health = folder / 'health.json'
        result = dict(health=json.loads(health.read_text()) if health.exists() else None,
                      queued=len(list((folder / 'outbox').glob('*.json'))),
                      acknowledged=len(list((folder / 'receipts').glob('*.json'))))
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

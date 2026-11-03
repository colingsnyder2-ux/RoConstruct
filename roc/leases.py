"""File leases: one owner per class/subsystem's files, so forks and workers never edit the same files.

A lease is a name (usually a class or family, e.g. RBX::Humanoid) plus repo-relative glob patterns
(e.g. rebuild/2008-06/native-classes/Humanoid*.cpp). The server refuses a lease whose patterns overlap
another user's active lease; `roc lease check --staged` (the pre-commit hook) refuses commits that touch
files another user holds. Leases expire unless renewed.
"""
from fnmatch import fnmatchcase
import json
from pathlib import Path
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[1]
CACHE = ROOT / 'work' / 'leases-cache.json'
SCHEMA = """
CREATE TABLE IF NOT EXISTS file_leases(
  name TEXT PRIMARY KEY, patterns TEXT NOT NULL, user TEXT NOT NULL, worker TEXT,
  branch TEXT, note TEXT, created REAL, expires REAL);
"""
NAME_RE = re.compile(r'^[\w:.<>, -]{2,120}$')
MAX_HOURS = 72


def _literal(pattern):
    return not any(c in pattern for c in '*?[')


def overlaps(a, b):
    """True when globs a and b can name a common file."""
    if _literal(a):
        return fnmatchcase(a, b)
    if _literal(b):
        return fnmatchcase(b, a)
    # ponytail: two wildcard globs overlap when their literal prefixes nest; conservative, may over-report.
    pa, pb = re.split(r'[*?\[]', a, 1)[0], re.split(r'[*?\[]', b, 1)[0]
    return pa.startswith(pb) or pb.startswith(pa)


def holder(path, leases, user=None):
    """The active lease covering path that belongs to someone other than user."""
    path = path.replace('\\', '/')
    for lease in leases:
        if lease['user'] != user and any(fnmatchcase(path, p) for p in lease['patterns']):
            return lease
    return None


def _clean(patterns):
    if not isinstance(patterns, list) or not 1 <= len(patterns) <= 200:
        raise ValueError('patterns must be a list of 1-200 repo-relative globs')
    out = []
    for p in patterns:
        p = str(p).replace('\\', '/').strip()
        if not p or p.startswith('/') or ':' in p or '..' in p.split('/') or len(p) > 300:
            raise ValueError('bad pattern %r: use repo-relative paths' % p)
        out.append(p)
    return out


class Leases:
    """Server-side store, sharing the server's sqlite connection."""

    def __init__(self, db):
        self.db = db
        self.db.executescript(SCHEMA)

    def active(self, now=None):
        rows = self.db.execute('SELECT name,patterns,user,worker,branch,note,created,expires FROM file_leases '
                               'WHERE expires>? ORDER BY name', (now or time.time(),)).fetchall()
        keys = ('name', 'patterns', 'user', 'worker', 'branch', 'note', 'created', 'expires')
        return [dict(zip(keys, r), patterns=json.loads(r[1])) for r in rows]

    def take(self, user, name, patterns, hours=4, worker=None, branch=None, note=None):
        if not NAME_RE.fullmatch(str(name)):
            raise ValueError('lease name must be 2-120 characters of letters, digits and :.<>,_ -')
        hours = float(hours)
        if not 0 < hours <= MAX_HOURS:
            raise ValueError('hours must be in (0, %d]' % MAX_HOURS)
        patterns, now = _clean(patterns), time.time()
        with self.db:
            for lease in self.active(now):
                if lease['user'] == user:
                    continue
                if lease['name'] == name:
                    raise PermissionError('%s is leased by %s until %s' % (name, lease['user'], _when(lease['expires'])))
                clash = [(a, b) for a in patterns for b in lease['patterns'] if overlaps(a, b)]
                if clash:
                    raise PermissionError('%s overlaps %s (held by %s): %s ~ %s'
                                          % (clash[0][0], lease['name'], lease['user'], clash[0][0], clash[0][1]))
            self.db.execute('INSERT OR REPLACE INTO file_leases VALUES(?,?,?,?,?,?,?,?)',
                            (name, json.dumps(patterns), user, worker, branch, note, now, now + hours * 3600))
        return dict(name=name, user=user, patterns=patterns, expires=now + hours * 3600)

    def renew(self, user, name, hours=4, release=False):
        hours = float(hours)
        if not 0 < hours <= MAX_HOURS:
            raise ValueError('hours must be in (0, %d]' % MAX_HOURS)
        with self.db:
            if release:
                changed = self.db.execute('DELETE FROM file_leases WHERE name=? AND user=?', (name, user)).rowcount
            else:
                changed = self.db.execute('UPDATE file_leases SET expires=? WHERE name=? AND user=? AND expires>?',
                                          (time.time() + hours * 3600, name, user, time.time())).rowcount
        if not changed:
            raise LookupError('no active lease %s held by %s' % (name, user))
        return dict(name=name, released=release)


def _when(ts):
    return time.strftime('%Y-%m-%d %H:%M', time.localtime(ts))


# ---- client ----

def _api(args):
    from roc import worker
    settings = worker.load_settings()
    server = args.server or settings.get('server') or worker.site_server()
    user = args.user or settings.get('user')
    if not server or not user:
        raise SystemExit('Run roc config --server URL --user NAME first')
    return worker.Api(server, settings.get('token')), user


def fetch(args):
    """Active leases from the server; falls back to the last cached list when offline."""
    try:
        api, _ = _api(args)
        leases = api.call('/v1/leases')['leases']
        CACHE.parent.mkdir(parents=True, exist_ok=True)
        CACHE.write_text(json.dumps(dict(fetched=time.time(), leases=leases)))
        return leases, False
    except SystemExit:
        raise
    except Exception:
        if not CACHE.exists():  # fail open: an old or offline server must not block every commit
            print('warning: lease server unreachable and no cached lease list; nothing checked', file=sys.stderr)
            return [], True
        cached = json.loads(CACHE.read_text())
        return [l for l in cached['leases'] if l['expires'] > time.time()], True


def _branch():
    r = subprocess.run(['git', 'rev-parse', '--abbrev-ref', 'HEAD'], cwd=ROOT, capture_output=True, text=True)
    return r.stdout.strip() or None


def main(args):
    if args.action == 'ls':
        leases, stale = fetch(args)
        for l in leases:
            print('%-32s %-14s until %s  %s%s' % (l['name'], l['user'], _when(l['expires']),
                  ' '.join(l['patterns']), ('  [' + l['branch'] + ']') if l.get('branch') else ''))
        print('%d active lease(s)%s' % (len(leases), ' (cached, server unreachable)' if stale else ''))
        return
    if args.action == 'check':
        from roc import worker
        user = args.user or worker.load_settings().get('user')
        if args.name:  # argparse puts the first path in name
            paths = [args.name] + args.paths
        else:
            diff = ['git', 'diff', '--name-only'] + (['--cached'] if args.staged else ['HEAD'])
            paths = subprocess.run(diff, cwd=ROOT, capture_output=True, text=True).stdout.split()
        leases, stale = fetch(args)
        blocked = [(p, holder(p, leases, user)) for p in paths]
        blocked = [(p, l) for p, l in blocked if l]
        for p, l in blocked:
            print('leased by %s (%s, until %s): %s' % (l['user'], l['name'], _when(l['expires']), p), file=sys.stderr)
        if blocked:
            raise SystemExit('%d file(s) belong to another worker\'s lease; coordinate or wait for expiry' % len(blocked))
        print('lease check ok: %d path(s)%s' % (len(paths), ', cached lease list' if stale else ''))
        return
    if args.action == 'hook':
        hook = ROOT / '.git' / 'hooks' / 'pre-commit'
        if hook.exists() and 'roc lease check' not in hook.read_text():
            raise SystemExit('%s already exists; add this line to it: python roc.py lease check --staged' % hook)
        hook.write_text('#!/bin/sh\n# roc lease check: refuse commits touching files another worker leases\n'
                        'exec python "$(git rev-parse --show-toplevel)/roc.py" lease check --staged\n', newline='\n')
        print('installed', hook)
        return
    api, user = _api(args)
    if not args.name:
        raise SystemExit('lease %s needs a NAME' % args.action)
    if args.action == 'take':
        if not args.paths:
            raise SystemExit('lease take NAME needs one or more repo-relative glob patterns')
        import socket
        result = api.call('/v1/leases/take', dict(user=user, name=args.name, patterns=args.paths, hours=args.hours,
                                                  worker=user + '@' + socket.gethostname()[:40],
                                                  branch=args.branch or _branch(), note=args.note))
    else:
        result = api.call('/v1/leases/' + args.action, dict(user=user, name=args.name, hours=args.hours))
    print(json.dumps(result, indent=1))


def register(cmd):
    cmd('lease', main, 'file leases so workers and forks never edit the same class files (take/renew/release/ls/check/hook)',
        (['action'], dict(choices=['take', 'renew', 'release', 'ls', 'check', 'hook'])),
        (['name'], dict(nargs='?', help='lease name, usually the class or family (take/renew/release)')),
        (['paths'], dict(nargs='*', help='take: repo-relative globs; check: paths to test (default: changed files)')),
        (['--hours'], dict(type=float, default=4)), (['--branch'], {}), (['--note'], {}),
        (['--staged'], dict(action='store_true', help='check: staged files (pre-commit hook)')),
        (['--server'], {}), (['--user'], {}))


if __name__ == '__main__':
    a = [
        ('rebuild/2008-06/native-classes/Humanoid*.cpp', 'rebuild/2008-06/native-classes/HumanoidState.cpp', True),
        ('rebuild/2008-06/native-classes/Humanoid*.cpp', 'rebuild/2008-06/native-classes/Camera.cpp', False),
        ('rebuild/2008-06/native-headers/humanoid/*', 'rebuild/2008-06/native-headers/*', True),
        ('rebuild/2008-06/p6/build_client.py', 'rebuild/2008-06/p6/build_client.py', True),
        ('rebuild/2008-06/p6/build_client.py', 'rebuild/2008-06/p6/click_test.py', False),
    ]
    for x, y, want in a:
        assert overlaps(x, y) == want == overlaps(y, x), (x, y)
    import sqlite3
    s = Leases(sqlite3.connect(':memory:'))
    s.take('alice', 'RBX::Humanoid', ['rebuild/2008-06/native-classes/Humanoid*.cpp'])
    try:
        s.take('bob', 'RBX::HumanoidState', ['rebuild/2008-06/native-classes/HumanoidState.cpp'])
        raise AssertionError('overlap accepted')
    except PermissionError:
        pass
    s.take('bob', 'RBX::Camera', ['rebuild/2008-06/native-classes/Camera*.cpp'])
    assert holder('rebuild/2008-06/native-classes/HumanoidFloor.cpp', s.active(), 'bob')['user'] == 'alice'
    assert holder('rebuild/2008-06/native-classes/HumanoidFloor.cpp', s.active(), 'alice') is None
    s.renew('alice', 'RBX::Humanoid', release=True)
    s.take('bob', 'RBX::HumanoidState', ['rebuild/2008-06/native-classes/HumanoidState.cpp'])
    print('leases self-check ok')

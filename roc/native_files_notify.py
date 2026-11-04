"""Announce new native source/header files on the Integration Digest webhook, for this repo and its forks.

A file counts as new when a branch gains it under NATIVE_DIRS. Each file is posted as a GitHub permalink.
State lives in work/native-files-state.json, so a file is announced once. The first scan of a branch only
records its tip (no flood); `roc native-files scan --backfill` announces what a first-seen branch already
has beyond upstream main. Forks are read with plain `git fetch` into refs/forks/<owner>/*, so no remote
config changes.
"""
import json
import re
import subprocess
import threading
import time
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STATE = ROOT / 'work' / 'native-files-state.json'
NATIVE_DIRS = ('rebuild/2008-06/native-classes/', 'rebuild/2008-06/native-headers/', 'rebuild/2008-06/native-world/')
EXTENSIONS = ('.cpp', '.h', '.hpp', '.inc', '.c')
MAX_LINES = 25          # links per embed field
MAX_FIELDS = 6          # fields per message
BOT_BRANCH = 'auto-merge/native'   # written by fork_merge; never announced


def git(*args, cwd=None, check=True):
    r = subprocess.run(["git", *args], cwd=cwd or ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace")
    if check and r.returncode:
        raise RuntimeError('git %s: %s' % (' '.join(args[:3]), r.stderr.strip()[:300]))
    return r.stdout.strip()


def is_native(path):
    return path.startswith(NATIVE_DIRS) and path.endswith(EXTENSIONS)


def load_state():
    try:
        return json.loads(STATE.read_text())
    except (OSError, ValueError):
        return {'tips': {}, 'announced': []}


def save_state(state):
    STATE.parent.mkdir(parents=True, exist_ok=True)
    state['announced'] = state['announced'][-5000:]
    STATE.write_text(json.dumps(state, indent=1))


def repo_slug(url):
    m = re.search(r'github\.com[:/]([^/]+)/([^/.]+)', url or '')
    return '%s/%s' % (m.group(1), m.group(2)) if m else None


def github_token():
    """Token from Git Credential Manager; None when unavailable (forks then come from local remotes only)."""
    try:
        r = subprocess.run(['git', 'credential', 'fill'], input='protocol=https\nhost=github.com\n\n', capture_output=True,
                           text=True, timeout=15)
        for line in r.stdout.splitlines():
            if line.startswith('password='):
                return line[9:]
    except (OSError, subprocess.SubprocessError):
        pass
    return None


def api(path, token=None):
    req = urllib.request.Request('https://api.github.com/' + path, headers={'Accept': 'application/vnd.github+json',
                                                                          'User-Agent': 'roconstruct-native-files'})
    if token:
        req.add_header('Authorization', 'Bearer ' + token)
    with urllib.request.urlopen(req, timeout=30) as response:
        return json.loads(response.read())


def upstream_slug():
    return repo_slug(git('remote', 'get-url', 'origin', check=False))


def discover(token=None, include_forks=True):
    """{slug: label} for the upstream repo and every fork we can see."""
    up = upstream_slug()
    found = {up: 'origin'} if up else {}
    if include_forks and up:
        try:
            for page in range(1, 6):
                forks = api('repos/%s/forks?per_page=100&page=%d' % (up, page), token)
                for fork in forks:
                    found[fork['full_name']] = fork['owner']['login']
                if len(forks) < 100:
                    break
        except (OSError, ValueError) as error:
            print('fork list unavailable: %s' % error)
        for line in git('remote', '-v', check=False).splitlines():       # forks already added as remotes
            parts = line.split()
            if len(parts) == 3 and parts[2] == '(fetch)' and parts[0] not in ('origin', 'findings'):
                slug = repo_slug(parts[1])
                if slug and slug.split('/')[1] == up.split('/')[1]:
                    found.setdefault(slug, parts[0])
    return found


def fetch_refs(slug, label):
    """Fetch every branch of slug into refs/forks/<label>/*; returns {branch: sha}."""
    ns = 'refs/forks/%s' % label.replace('/', '_')
    git('fetch', '--quiet', '--no-tags', 'https://github.com/%s.git' % slug, '+refs/heads/*:%s/*' % ns, check=False)
    out = git('for-each-ref', '--format=%(refname) %(objectname)', ns, check=False)
    return {line.split()[0][len(ns) + 1:]: line.split()[1] for line in out.splitlines() if line.strip()}


def changed_files(old, new):
    """[(kind, path)] native files added ('new') or modified ('changed') between two commits."""
    out = git('diff', '--name-status', '--diff-filter=AM', '--no-renames', old, new, check=False)
    rows = [line.split('\t', 1) for line in out.splitlines() if '\t' in line]
    return [('new' if status == 'A' else 'changed', path) for status, path in rows if is_native(path)]


def upstream_main_tip(repos):
    """Tip of the upstream main branch (what first-seen forks are compared with), or None."""
    label = repos.get(upstream_slug(), 'origin')
    for name in ('main', 'master'):
        tip = git('rev-parse', '--verify', '-q', 'refs/forks/%s/%s' % (label, name), check=False)
        if tip:
            return tip
    return None


def scan(include_forks=True, backfill=False, post=True, save=True, log=print):
    """Detect new native files across branches; returns [(slug, branch, sha, path)] and posts them."""
    state = load_state()
    token = github_token() if include_forks else None
    repos = discover(token, include_forks)
    tips_by_repo = {}
    for slug, label in repos.items():
        try:
            tips_by_repo[slug] = fetch_refs(slug, label)
        except RuntimeError as error:
            log('fetch failed for %s: %s' % (slug, error))
    main_tip = upstream_main_tip(repos)
    new = []
    for slug, tips in tips_by_repo.items():
        for branch, sha in tips.items():
            if branch == BOT_BRANCH:
                continue                                        # merged copies of already announced files
            key = '%s@%s' % (slug, branch)
            old = state['tips'].get(key)
            state['tips'][key] = sha
            if old == sha:
                continue
            if old is None:
                if not backfill:
                    continue                                   # first sight: record only
                base = git('merge-base', sha, main_tip, check=False) if main_tip else ''
                files = changed_files(base, sha) if base else [
                    ('new', p) for p in git('ls-tree', '-r', '--name-only', sha, check=False).splitlines() if is_native(p)]
            elif git('cat-file', '-t', old, check=False) != 'commit':
                continue                                       # history rewritten; re-baselined
            else:
                files = changed_files(old, sha)
            for kind, path in files:
                blob = git('rev-parse', '%s:%s' % (sha, path), check=False)
                announce = '%s:%s' % (path, blob)               # content-based: a merge of the same edit is not re-announced
                if announce not in state['announced']:
                    state['announced'].append(announce)
                    new.append((slug, branch, sha, path, kind))
    if new and post and not post_files(new, log=log):
        return new                                              # leave state untouched so the next poll retries
    if save and (post or not new):
        save_state(state)
    return new


def link(slug, sha, path):
    return 'https://github.com/%s/blob/%s/%s' % (slug, sha[:10], path)


FIELD_LIMIT = 1024     # Discord: characters per field value
EMBED_LIMIT = 5800     # Discord: 6000 characters per embed, with headroom for title/footer


def build_payloads(new, cap=150):
    """Integration Digest embeds, one field group per (repo, branch). Whole links only: a field or message
    is closed before a line would cross Discord's limits, never cut mid-link."""
    shown, extra = new[:cap], max(0, len(new) - cap)
    groups = {}
    for slug, branch, sha, path, kind in shown:
        groups.setdefault((kind != 'new', slug, branch, sha), []).append(path)
    fields = []
    for (changed, slug, branch, sha), paths in sorted(groups.items()):
        title = '✏️ Changed native files' if changed else '\U0001F4C4 New native files'
        name = ('%s · %s · %s' % (title, slug, branch))[:256]
        value = ''
        for p in paths:
            line = '[%s](%s)' % (p.replace('rebuild/2008-06/', ''), link(slug, sha, p))
            if value and len(value) + 1 + len(line) > FIELD_LIMIT:
                fields.append({'name': name, 'value': value, 'inline': False})
                value = ''
            value = value + '\n' + line if value else line[:FIELD_LIMIT]
        if value:
            fields.append({'name': name, 'value': value, 'inline': False})
    if extra:
        fields.append({'name': '➕ More', 'value': '+%d more new or changed native files (see the branches)' % extra, 'inline': False})
    messages, current, size = [], [], 0
    for field in fields:
        cost = len(field['name']) + len(field['value'])
        if current and (size + cost > EMBED_LIMIT or len(current) >= MAX_FIELDS):
            messages.append(current); current, size = [], 0
        current.append(field); size += cost
    if current:
        messages.append(current)
    return [{'allowed_mentions': {'parse': []}, 'embeds': [{
        'title': '⛏️ RoConstruct Integration Digest', 'color': 0xA855F7, 'description': '**2008-06 Client**',
        'footer': {'text': 'RoConstruct Integration'}, 'fields': group,
        'timestamp': datetime.now(timezone.utc).isoformat()}]} for group in messages]


def post_files(new, log=print):
    from roc.reports import server_mines_webhook
    url = server_mines_webhook()
    payloads = build_payloads(new)
    if not url:
        log('no server_mines_webhook configured; %d new native file(s) not posted' % len(new))
        return False
    for body in payloads:
        request = urllib.request.Request(url, json.dumps(body).encode(), {'Content-Type': 'application/json',
                                                                          'User-Agent': 'roconstruct-native-files'})
        try:
            urllib.request.urlopen(request, timeout=20).read()
        except OSError as error:
            log('webhook post failed: %s' % error)
            return False
        time.sleep(1)
    log('posted %d new or changed native file(s) in %d message(s)' % (len(new), len(payloads)))
    return True


def watch(interval=300, log=print, merge=True):
    """Loop for the server: announce new files, then try to merge fork work into the auto-merge branch."""
    while True:
        try:
            scan(log=log)
            if merge:
                from roc import fork_merge
                fork_merge.run(log=log)
        except Exception as error:                          # a bad poll must not kill the server thread
            log('native-files watch error: %s' % error)
        time.sleep(interval)


def start_watch(interval=300, log=print):
    thread = threading.Thread(target=watch, args=(interval, log), daemon=True, name='native-files-watch')
    thread.start()
    return thread


def main(args):
    if args.action == 'scan':
        new = scan(include_forks=not args.no_forks, backfill=args.backfill, post=not args.dry_run, save=not args.dry_run)
        for slug, branch, sha, path, kind in new:
            print("%s %s %s %s" % (kind, slug, branch, link(slug, sha, path)))
        print('%d new or changed native file(s)%s' % (len(new), ' (dry run: nothing posted, state not saved)' if args.dry_run else ''))
        if args.dry_run and new:
            print(json.dumps(build_payloads(new)[0], indent=1)[:1800])
    else:
        from roc import fork_merge
        fork_merge.run(push=not args.dry_run)


def register(cmd):
    cmd('native-files', main, 'announce new native files (this repo + forks) on the Integration Digest webhook; merge forks',
        (['action'], dict(choices=['scan', 'merge'])),
        (['--dry-run'], dict(action='store_true')), (['--no-forks'], dict(action='store_true')),
        (['--backfill'], dict(action='store_true', help='announce what a first-seen branch already has beyond upstream main')))

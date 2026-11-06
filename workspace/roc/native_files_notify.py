"""Announce new native source/header files on the Integration Digest webhook, for this repo and its forks.

A file counts as new when a branch gains it under NATIVE_DIRS. Each file is posted as a GitHub permalink.
State lives in work/native-files-state.json, so a file is announced once. The first scan of a branch only
records its tip (no flood); `roc native-files scan --backfill` announces what a first-seen branch already
has beyond upstream main. Forks are read with plain `git fetch` into refs/forks/<owner>/*, so no remote
config changes.
"""
import json
import os
import re
import sqlite3
import subprocess
import threading
import time
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STATE = ROOT / 'work' / 'native-files-state.json'
NATIVE_DIRS = ('rebuild/2008-06/native-classes/', 'rebuild/2008-06/native-headers/', 'rebuild/2008-06/native-world/')
NATIVE_DIRS += tuple('workspace/' + path for path in NATIVE_DIRS)
EXTENSIONS = ('.cpp', '.h', '.hpp', '.inc', '.c')
MAX_LINES = 25          # links per embed field
MAX_FIELDS = 6          # fields per message
BOT_BRANCH = 'auto-merge/native'   # written by fork_merge; never announced


def git(*args, cwd=None, check=True):
    try:
        r = subprocess.run(["git", *args], cwd=cwd or ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace",
                           timeout=120, env={**os.environ, 'GIT_TERMINAL_PROMPT': '0', 'GCM_INTERACTIVE': 'never'})
    except subprocess.TimeoutExpired as error:
        raise RuntimeError('git %s timed out' % args[0]) from error
    if check and r.returncode:
        raise RuntimeError('git %s: %s' % (' '.join(args[:3]), r.stderr.strip()[:300]))
    return r.stdout.strip()


def native_path(path):
    if path.startswith('workspace/'):
        path = path[len('workspace/'):]
    path = re.sub(r'^drafts/files/[0-9a-f]{64}/', '', path)
    return path


def is_native(path):
    return native_path(path).startswith(NATIVE_DIRS[:3]) and path.endswith(EXTENSIONS)


def load_state():
    try:
        return json.loads(STATE.read_text())
    except (OSError, ValueError):
        return {'tips': {}, 'announced': []}


def save_state(state):
    STATE.parent.mkdir(parents=True, exist_ok=True)
    from roc.native_drafts import atomic
    atomic(STATE, state)


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
    from roc.native_drafts import lock
    STATE.parent.mkdir(parents=True, exist_ok=True)
    with lock(STATE.with_suffix('.lock')):
        return _scan(include_forks, backfill, post, save, log)


def _scan(include_forks=True, backfill=False, post=True, save=True, log=print):
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
    state['announced'] = list(dict.fromkeys(native_path(p) for p in state['announced']))
    new = [tuple(row) for row in state.get('pending', [])]
    queued = set()
    for slug, branch, sha, path, kind in new:
        queued.add(native_path(path) + ':' + git('rev-parse', sha + ':' + path))
    for slug, tips in tips_by_repo.items():
        for branch, sha in tips.items():
            if branch == BOT_BRANCH:
                continue                                        # merged copies of already announced files
            key = '%s@%s' % (slug, branch)
            old = state['tips'].get(key)
            state['tips'][key] = sha
            if old == sha and branch != 'work':
                continue
            if old == sha:
                files = []
            elif old is None:
                if not backfill:
                    continue                                   # first sight: record only
                base = git('merge-base', sha, main_tip, check=False) if main_tip else ''
                files = changed_files(base, sha) if base else [
                    ('new', p) for p in git('ls-tree', '-r', '--name-only', sha, check=False).splitlines() if is_native(p)]
            elif git('cat-file', '-t', old, check=False) != 'commit':
                continue                                       # history rewritten; re-baselined
            else:
                files = changed_files(old, sha)
            # Existing uploads predate this watcher fix. Enumerate immutable draft
            # blobs on work too; logical path/content identities prevent floods.
            if branch == 'work' and slug == upstream_slug():
                files += [('new', p) for p in git('ls-tree', '-r', '--name-only', sha, '--', 'drafts/files/', check=False).splitlines() if is_native(p)]
            for kind, path in files:
                blob = git('rev-parse', '%s:%s' % (sha, path), check=False)
                announce = '%s:%s' % (native_path(path), blob)
                if announce not in state['announced'] and announce not in queued:
                    queued.add(announce)
                    new.append((slug, branch, sha, path, kind))
    state['pending'] = new
    if save and post:
        save_state(state)  # Persist discovery before delivery; never lose a tail.
    def acknowledged(rows):
        for slug, branch, sha, path, kind in rows:
            identity = native_path(path) + ':' + git('rev-parse', sha + ':' + path)
            if identity not in state['announced']:
                state['announced'].append(identity)
        sent = set(rows)
        state['pending'] = [row for row in state['pending'] if tuple(row) not in sent]
        if save:
            save_state(state)
    if new and post:
        post_files(new[:150], log=log, on_sent=acknowledged)
    elif save and not new:
        save_state(state)
    return new


def link(slug, sha, path):
    return 'https://github.com/%s/blob/%s/%s' % (slug, sha[:10], path)


LINKS_PER_MESSAGE = 8   # small messages: 8 links stay far under Discord's 4096-character description limit
DESCRIPTION_LIMIT = 3000


def contributor(slug, sha, path):
    """Attribute immutable uploads to their uploader; distinguish fork/commit credit."""
    draft = re.match(r'^drafts/files/([0-9a-f]{64})/', path)
    if draft:
        try:
            packet = json.loads(git('show', sha + ':drafts/bundles/' + draft[1] + '.json', check=False))
            name = packet.get('user') or 'Unknown uploader'
        except (ValueError, TypeError):
            name = 'Unknown uploader'
        label = 'Contributor'
    elif slug != upstream_slug():
        label, name = 'Contributor', slug.split('/')[0]
    else:
        label = 'Commit author'
        name = git('log', '-1', '--format=%aN', sha, '--', path, check=False) or 'Unknown author'
    name = re.sub(r'([\\`*_{}\[\]()<>|~])', r'\\\1', ' '.join(str(name).split())[:80])
    return '**%s:** %s' % (label, name)


def build_payloads(new, cap=None):
    """One small Integration Digest message per chunk of LINKS_PER_MESSAGE files of one (kind, repo, branch).
    Links go in the embed description (4096 limit) as whole lines; nothing is ever cut mid-link."""
    shown = new if cap is None else new[:cap]
    groups, credits = {}, {}
    for slug, branch, sha, path, kind in shown:
        draft = re.match(r'^drafts/files/([0-9a-f]{64})/', path)
        key = (slug, sha, draft[1] if draft else path)
        if key not in credits:
            credits[key] = contributor(slug, sha, path)
        groups.setdefault((kind != 'new', slug, branch, sha, bool(draft), credits[key]), []).append(path)
    bodies = []
    for (changed, slug, branch, sha, draft, credit), paths in sorted(groups.items()):
        title = '✏️ Changed native files' if changed else '\U0001F4C4 New native files'
        header = '**2008-06 Client**\n%s · `%s` · `%s`' % (title, slug, branch)
        if draft:
            header += '\nInactive draft upload · unverified; no runtime activation or credit'
        header += '\n\n' + credit + '\n'
        chunk = []
        for p in paths:
            line = '[%s](%s)' % ('/'.join(p.split('/')[-2:]), link(slug, sha, p))
            text = '\n'.join([header] + chunk + [line])
            if chunk and (len(chunk) >= LINKS_PER_MESSAGE or len(text) > DESCRIPTION_LIMIT):
                bodies.append('\n'.join([header] + chunk))
                chunk = []
            chunk.append(line)
        if chunk:
            bodies.append('\n'.join([header] + chunk))
    total = len(bodies)
    return [{'allowed_mentions': {'parse': []}, 'embeds': [{
        'title': '⛏️ RoConstruct Integration Digest', 'color': 0xA855F7, 'description': body,
        'footer': {'text': 'RoConstruct Integration' + (' · %d/%d' % (i + 1, total) if total > 1 else '')},
        'timestamp': datetime.now(timezone.utc).isoformat()}]} for i, body in enumerate(bodies)]


def format_payload(body, summary, rows):
    """Player-digest layout with native statuses and original uncut file links."""
    embed = body['embeds'][0]
    original = embed['description']
    lines = original.splitlines()
    links = [line for line in lines if line.startswith('[')]
    credit = next((line for line in lines if line.startswith(('**Contributor:**', '**Commit author:**'))), 'Unknown contributor')
    title = '✏️ Changed native files' if '✏️ Changed native files' in original else '📄 New native files'
    fields, chunk = [], []
    for line in links:
        if chunk and len('\n'.join(chunk + [line])) > 1024:
            fields.append({'name': title, 'value': '\n'.join(chunk), 'inline': False})
            chunk = []
        chunk.append(line)
    if chunk:
        fields.append({'name': title, 'value': '\n'.join(chunk), 'inline': False})
    fields += [
        {'name': '🏆 Workers', 'value': credit, 'inline': True},
        {'name': '✅ Batch', 'value': '**%d new · %d changed files**' % (
            sum(row[4] == 'new' for row in rows), sum(row[4] != 'new' for row in rows)), 'inline': True}]
    models, seen = [], set()
    for slug, branch, sha, path, kind in rows:
        draft = re.match(r'^drafts/files/([0-9a-f]{64})/', path)
        if not draft or draft[1] in seen:
            continue
        seen.add(draft[1])
        try:
            model = json.loads(git('show', sha + ':drafts/bundles/' + draft[1] + '.json', check=False)).get('model')
        except (ValueError, TypeError):
            model = None
        if model:
            model = re.sub(r'([\\`*_{}\[\]()<>|~])', r'\\\1', ' '.join(str(model).split())[:120])
            if model not in models:
                models.append(model)
    fields.append({'name': '🔧 Models', 'value': '\n'.join(models) or 'Unknown', 'inline': True})
    if len(lines) > 1:
        fields.append({'name': '📦 Source', 'value': lines[1].split(' · ', 1)[-1], 'inline': False})
    if 'Inactive draft upload' in original:
        fields.append({'name': '📝 Draft status', 'value': 'Unverified upload · saved for review', 'inline': False})
    embed['description'] = summary
    embed['fields'] = fields
    return body


def post_files(new, log=print, on_sent=None):
    from roc.reports import server_mines_webhook
    url = server_mines_webhook()
    payloads = build_payloads(new)
    try:
        from roc.integration_site import live_progress, progress_description, integration_rate
        snapshot = live_progress(ROOT)
        summary = progress_description(snapshot)
        rate = integration_rate(snapshot, ROOT)
    except (OSError, ValueError, KeyError, TypeError, sqlite3.Error) as error:
        log('native progress unavailable: %s' % error)
        summary = 'Native progress unavailable.'
        rate = 'Building rate · progress unavailable'
    for body in payloads:
        content = body['embeds'][0]['description']
        rows = [row for row in new if link(row[0], row[2], row[3]) in content]
        format_payload(body, summary, rows)
        fields = body['embeds'][0]['fields']
        fields.insert(next(i for i, field in enumerate(fields) if field['name'] == '🏆 Workers'),
                      {'name': '⚡ Integration Rate', 'value': rate, 'inline': True})
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
        if on_sent:
            embed = body['embeds'][0]
            content = '\n'.join([embed['description']] + [field['value'] for field in embed.get('fields', [])])
            on_sent([row for row in new if link(row[0], row[2], row[3]) in content])
        time.sleep(1)
    log('posted %d new or changed native file(s) in %d message(s)' % (len(new), len(payloads)))
    return True


def watch(interval=300, log=print, merge=True):
    """Loop for the server: announce new files, then try to merge fork work into the auto-merge branch."""
    while True:
        try:
            scan(log=log)
            if merge and not (ROOT / "work/draft-workflow-enabled.json").exists():
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

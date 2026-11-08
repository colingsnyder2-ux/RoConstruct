"""Merge fork branches into the bot branch auto-merge/native when they merge cleanly.

Never touches the working branch. For each fork branch (refs/forks/<owner>/<branch>, fetched by
native_files_notify.scan) in a scratch clone under work/fork-merge:
  - clean merge that preserves native sources/proofs -> merge commit on auto-merge/native
  - conflict, unrelated history, or native deletions -> the fork's added/changed native files are copied to
    merge/<owner>/<branch>/<path> with a MERGE_NEEDED.md, so nothing is lost and a human or agent can reconcile.
The branch is pushed to origin; fast-forward your working branch from it when you want the merged work.
"""
import json
import re
import shutil
import subprocess
import time
from pathlib import Path

from roc.native_files_notify import ROOT, BOT_BRANCH, is_native

BRANCH = BOT_BRANCH
CLONE = ROOT / 'work' / 'fork-merge'
STATE = ROOT / 'work' / 'fork-merge-state.json'
MAX_MERGES = 10          # per run
MAX_PARKED_FILES = 200   # per fork branch


def sh(*args, cwd, check=True):
    r = subprocess.run(['git', *args], cwd=cwd, capture_output=True, text=True, encoding='utf-8', errors='replace')
    if check and r.returncode:
        raise RuntimeError('git %s: %s' % (' '.join(args[:3]), (r.stderr or r.stdout).strip()[:400]))
    return r


def load_state():
    try:
        return json.loads(STATE.read_text())
    except (OSError, ValueError):
        return {'parked': {}, 'merged': {}}


def prepare(repo, clone):
    if not (clone / '.git').exists():
        clone.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(['git', 'clone', '--shared', '--no-checkout', '--quiet', str(repo), str(clone)], check=True,
                       capture_output=True)
    sh('config', 'user.name', 'RoConstruct auto-merge', cwd=clone)
    sh('config', 'user.email', 'auto-merge@roconstruct.invalid', cwd=clone)
    sh('config', 'core.autocrlf', 'false', cwd=clone)
    sh('fetch', '--quiet', '--no-tags', str(repo), '+refs/forks/*:refs/forks/*', cwd=clone)


def fork_refs(clone, mine_ref, days):
    """[(owner, branch, ref, sha)] for fork branches (not origin) with a recent tip."""
    cutoff = time.time() - days * 86400
    out = sh('for-each-ref', '--format=%(refname) %(objectname) %(committerdate:unix)', 'refs/forks', cwd=clone).stdout
    rows = []
    for line in out.splitlines():
        ref, sha, when = line.split()
        owner, _, branch = ref[len('refs/forks/'):].partition('/')
        if owner == 'origin' or ref == mine_ref or int(when) < cutoff:
            continue
        rows.append((owner, branch, ref, sha))
    return sorted(rows, key=lambda r: r[3])


def preservation_losses(repo, before, candidate):
    """Reject lost native sources and verification files in the final tree.

    Disable rename detection: a provider move needs a deliberate review rather
    than silently treating a removed verified source as harmless. NUL records
    preserve Windows paths without relying on newline conversion.
    """
    result = subprocess.run(['git', 'diff', '--raw', '--no-abbrev', '--no-renames',
                             '-z', before, candidate, '--'], cwd=repo,
                            capture_output=True, check=True)
    fields = result.stdout.split(b'\0')
    losses = []
    for meta, raw_path in zip(fields[0::2], fields[1::2]):
        path = raw_path.decode('utf-8', errors='surrogateescape')
        parts = path.split('/')
        if parts[0] == 'workspace':
            parts = parts[1:]
        if len(parts) >= 3 and parts[0] == 'rebuild':
            parts = parts[2:]
        elif len(parts) >= 2 and re.fullmatch(r'\d{4}-\d{2}', parts[0]):
            parts = parts[1:]
        legacy = len(parts) >= 2 and parts[0] in (
            'native-classes', 'native-headers', 'native-world', 'tests')
        organized = (len(parts) >= 3 and parts[0] in (
            'App', 'Base', 'Network', 'Rendering', 'WindowsClient', 'Studio', 'Unclassified')
            and parts[1] in ('src', 'include'))
        if not (legacy or organized):
            continue
        _, mode, old, new, status = meta[1:].split()
        reason = None
        if status == b'D':
            reason = 'deleted native source or verification file'
        elif mode not in (b'100644', b'100755'):
            reason = 'native source or verification file replaced by non-regular entry'
        elif status != b'A' and old != new and new == b'e69de29bb2d1d6434b8b29ae775ad8c2e48c5391':
            reason = 'native source or verification file emptied'
        if reason:
            losses.append({'path': path, 'status': status.decode(), 'reason': reason})
    return losses


def native_deletions(clone, before):
    return [row['path'] for row in preservation_losses(clone, before, 'HEAD')]


def park(clone, owner, branch, ref, sha, reason):
    """Copy the fork's added/changed native files under merge/<owner>/<branch>/ and commit them."""
    base = sh('merge-base', ref, 'HEAD', cwd=clone, check=False).stdout.strip()
    if base:
        diff = sh('diff', '--name-status', '--no-renames', base, ref, cwd=clone).stdout.splitlines()
        paths = [l.split('\t', 1)[1] for l in diff if l[0] in 'AM' and is_native(l.split('\t', 1)[1])]
    else:
        paths = [p for p in sh('ls-tree', '-r', '--name-only', ref, cwd=clone).stdout.splitlines() if is_native(p)]
    paths = [p for p in paths if sh('rev-parse', ref + ':' + p, cwd=clone).stdout != sh('rev-parse', '-q', '--verify', 'HEAD:' + p, cwd=clone, check=False).stdout]
    dest = Path('merge') / owner / re.sub(r'[^\w.-]+', '_', branch)
    if not paths:
        return 0
    shutil.rmtree(clone / dest, ignore_errors=True)
    for p in paths[:MAX_PARKED_FILES]:
        target = clone / dest / p
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(subprocess.run(['git', 'show', '%s:%s' % (ref, p)], cwd=clone, capture_output=True).stdout)
    note = ['# Needs a manual merge', '', 'Fork `%s`, branch `%s`, commit `%s`.' % (owner, branch, sha), 'Reason: %s' % reason, '',
            'Files below are the fork\'s version; compare with the same path in the tree:', ''] + ['- `%s`' % p for p in paths[:MAX_PARKED_FILES]]
    if len(paths) > MAX_PARKED_FILES:
        note.append('- +%d more not copied' % (len(paths) - MAX_PARKED_FILES))
    (clone / dest / 'MERGE_NEEDED.md').write_text('\n'.join(note) + '\n', encoding='utf-8')
    sh('add', '-f', '--', str(dest), cwd=clone)
    sh('commit', '--quiet', '-m', 'Fork %s/%s needs a manual merge (%d native files parked)' % (owner, branch, min(len(paths), MAX_PARKED_FILES)),
       cwd=clone)
    return len(paths)


def run(push=True, log=print, repo=ROOT, clone=CLONE, mine=None, days=14, state_file=STATE):
    if (Path(repo) / 'work/draft-workflow-enabled.json').exists():
        return log('Legacy bot merges retired; use reviewed draft integration on work.')
    state = {'parked': {}, 'merged': {}}
    try:
        state = json.loads(Path(state_file).read_text())
    except (OSError, ValueError):
        pass
    mine = mine or subprocess.run(['git', 'rev-parse', '--abbrev-ref', 'HEAD'], cwd=repo, capture_output=True, text=True).stdout.strip()
    prepare(repo, clone)
    mine_ref = 'refs/forks/origin/' + mine
    if sh('rev-parse', '-q', '--verify', mine_ref, cwd=clone, check=False).returncode:
        log('fork-merge: %s not fetched yet; run a scan first' % mine_ref)
        return
    existing = sh('rev-parse', '-q', '--verify', 'refs/forks/origin/' + BRANCH, cwd=clone, check=False).stdout.strip()
    sh('checkout', '--quiet', '-B', BRANCH, existing or mine_ref, cwd=clone)
    sh('reset', '--quiet', '--hard', cwd=clone)
    preservation_base = sh('rev-parse', 'HEAD', cwd=clone).stdout.strip()
    merged = parked = 0
    # keep the bot branch current with the working branch first
    if sh('merge-base', '--is-ancestor', mine_ref, 'HEAD', cwd=clone, check=False).returncode:
        if sh('merge', '--no-edit', '-m', 'Track %s' % mine, mine_ref, cwd=clone, check=False).returncode:
            sh('merge', '--abort', cwd=clone, check=False)
            log('fork-merge: could not fold %s into %s' % (mine, BRANCH))
        elif native_deletions(clone, preservation_base):
            sh('reset', '--quiet', '--hard', preservation_base, cwd=clone)
            log('fork-merge: refused tracking snapshot that removes native sources or proofs')
    for owner, branch, ref, sha in fork_refs(clone, mine_ref, days):
        if merged + parked >= MAX_MERGES:
            break
        key = '%s/%s' % (owner, branch)
        if state['merged'].get(key) == sha or state['parked'].get(key) == sha:
            continue
        if sh('merge-base', '--is-ancestor', ref, 'HEAD', cwd=clone, check=False).returncode == 0:
            state['merged'][key] = sha
            continue
        before = sh('rev-parse', 'HEAD', cwd=clone).stdout.strip()
        result = sh('merge', '--no-ff', '--no-edit', '-m', 'Auto-merge fork %s/%s' % (owner, branch), ref, cwd=clone, check=False)
        if result.returncode == 0:
            lost = native_deletions(clone, before)
            if not lost:
                state['merged'][key] = sha
                merged += 1
                log('fork-merge: merged %s' % key)
                continue
            sh('reset', '--quiet', '--hard', before, cwd=clone)
            reason = 'merge would lose %d native/proof file(s), e.g. %s' % (len(lost), lost[0])
        else:
            conflicts = re.findall(r'CONFLICT[^\n]*', result.stdout)
            sh('merge', '--abort', cwd=clone, check=False)
            reason = (conflicts[0] if conflicts else (result.stderr or 'merge failed').strip().splitlines()[0])[:300]
            if len(conflicts) > 1:
                reason += ' (+%d more conflicts)' % (len(conflicts) - 1)
        count = park(clone, owner, branch, ref, sha, reason)
        state['parked'][key] = sha
        parked += 1
        log('fork-merge: parked %s (%d files): %s' % (key, count, reason))
    if preservation_losses(clone, preservation_base, 'HEAD'):
        raise RuntimeError('fork-merge: final tree loses native sources or proofs; refusing publication')
    if push:                                              # a dry run must not remember what it did
        Path(state_file).parent.mkdir(parents=True, exist_ok=True)
        Path(state_file).write_text(json.dumps(state, indent=1))
    remote = sh('rev-parse', '-q', '--verify', 'refs/forks/origin/' + BRANCH, cwd=clone, check=False).stdout.strip()
    if push and (merged or parked or sh('rev-parse', 'HEAD', cwd=clone).stdout.strip() != remote):
        url = subprocess.run(['git', 'remote', 'get-url', 'origin'], cwd=repo, capture_output=True, text=True).stdout.strip()
        r = sh('push', '--quiet', url, 'HEAD:refs/heads/' + BRANCH, cwd=clone, check=False)
        log('fork-merge: pushed %s (%d merged, %d parked)' % (BRANCH, merged, parked) if r.returncode == 0
            else 'fork-merge: push failed: %s' % r.stderr.strip()[:200])

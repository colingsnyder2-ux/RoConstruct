"""Path-mapped branch redundancy check (item 12).

Compares the checked-out codex branch against refs/remotes/origin/work, accounting
for the layout move (root -> workspace/). Reports:
  - commits unique to codex
  - files identical on work (safe to retire)
  - files present on work but content-different (need review)
  - files absent from work (potentially unique to codex)
No deletions are performed.
"""
import json
import subprocess
import os

ROOT = r'C:\Users\colin\RoConstruct'
CODEX = 'codex/native-partial-search-20261029'
WORK = 'refs/remotes/origin/work'


def run(*args):
    return subprocess.run(['git', *args], capture_output=True, cwd=ROOT)


def ls_tree(ref):
    out = run('ls-tree', '-r', '-z', ref).stdout
    entries = {}
    for chunk in out.split(b'\0'):
        if not chunk:
            continue
        meta, name = chunk.split(b'\t')
        mode, kind, sha = meta.split()
        if kind != b'blob':
            continue
        entries[name.decode()] = sha.decode()
    return entries


def mapped_candidates(p):
    cands = []
    if not p.startswith('workspace/'):
        cands.append('workspace/' + p)
    cands.append(p)
    # research/ may live under workspace/research too
    if p.startswith('research/') and 'workspace/research/' + p[len('research/'):] not in cands:
        cands.append('workspace/research/' + p[len('research/'):])
    return cands


def main():
    codex_files = ls_tree(CODEX)
    work_files = ls_tree(WORK)
    work_blob_set = set(work_files.values())

    identical, different, absent = [], [], []
    LOCAL_ONLY = ('.opencode/', 'work/', 'local/', 'out/', '.pytest_cache/', 'Archive/')
    for p, sha in sorted(codex_files.items()):
        if any(p.startswith(x) for x in LOCAL_ONLY):
            continue
        chosen = None
        for c in mapped_candidates(p):
            if c in work_files:
                chosen = c
                break
        if chosen is None:
            if sha in work_blob_set:
                absent.append((p, sha, 'present-elsewhere-by-content'))
            else:
                absent.append((p, sha, 'TRULY-UNIQUE'))
            continue
        if work_files[chosen] == sha:
            identical.append((p, chosen, sha))
        else:
            different.append((p, chosen, sha, work_files[chosen]))

    # commits unique to codex
    uniq = run('rev-list', '--count', WORK + '..' + CODEX).stdout.decode().strip()
    commit_list = run('rev-list', '--oneline', WORK + '..' + CODEX).stdout.decode().splitlines()

    report = {
        'codex_ref': CODEX,
        'work_ref': WORK,
        'codex_total_blobs': len(codex_files),
        'work_total_blobs': len(work_files),
        'commits_unique_to_codex': int(uniq),
        'unique_commit_list': commit_list,
        'identical_count': len(identical),
        'different_count': len(different),
        'absent_count': len(absent),
        'identical': [{'codex': p, 'work': w} for p, w, _ in identical],
        'different': [{'codex': p, 'work': w, 'codex_blob': a, 'work_blob': b} for p, w, a, b in different],
        'absent': [{'codex': p, 'blob': s, 'status': st} for p, s, st in absent],
        'truly_unique_count': sum(1 for _, _, st in absent if st == 'TRULY-UNIQUE'),
    }
    out = os.path.join(ROOT, 'work', 'native-candidates', 'branch-redundancy-mapped-20261108.json')
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        json.dump(report, f, indent=2)
        f.write('\n')

    # concise summary
    print('commits unique to codex:', uniq)
    print('codex blobs:', len(codex_files), ' work blobs:', len(work_files))
    print('identical (safe to retire):', len(identical))
    print('content-different (review):', len(different))
    print('absent from work (potentially unique):', len(absent))
    print()
    if absent:
        print('--- ABSENT (first 40) ---')
        for p, s, _ in absent[:40]:
            print('  ', p)
    if different:
        print('--- DIFFERENT (first 40) ---')
        for p, w, a, b in different[:40]:
            print(f'  {p}  (work:{w})  {a[:8]} vs {b[:8]}')
    print()
    print('report written:', out)


if __name__ == '__main__':
    main()

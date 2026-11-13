"""List files changed on the checked-out branch since its fork point from work."""
import subprocess

ROOT = r'C:\Users\colin\RoConstruct'


def run(*args):
    return subprocess.run(['git', *args], capture_output=True, cwd=ROOT)


ours, base, work = '0da2d19b0f', '6ab993a3c2cc673a0d6b7211c186a129d46a1733', 'refs/remotes/origin/work'
out = run('diff', '--name-status', '-r', '-z', base, ours).stdout.split(b'\0')
changed = []
for i, chunk in enumerate(out):
    if not chunk:
        continue
    parts = chunk.split(b'\t')
    status = parts[0].decode()
    name = parts[1].decode()
    old = out[i + 2].decode() if len(parts) == 2 else None
    changed.append((status, name, old))

identical, different, absent, renamed_leftover = [], [], [], []
for status, name, old in changed:
    p = run('rev-parse', '--verify', f'{work}:{name}')
    if p.returncode != 0:
        absent.append((status, name))
        continue
    theirs = p.stdout.decode().strip()
    mine = run('rev-parse', '--verify', f'{ours}:{name}')
    mine = mine.stdout.decode().strip() if mine.returncode == 0 else None
    if mine == theirs:
        identical.append(name)
    else:
        different.append((status, name, mine, theirs))

print('== fully identical on work (%d) ==' % len(identical))
for n in identical:
    print('  ', n)
print('== present but different (%d) ==' % len(different))
for st, n, mine, theirs in different:
    print(f'  {st} {n}\n      ours {mine and mine[:12]}  work {theirs[:12]}')
print('== absent from work (%d) ==' % len(absent))
for st, n in absent:
    print(f'  {st} {n}')
print()
print('extra commits on ours not on work:',
      run('rev-list', '--count', work + '..' + ours).stdout.decode().strip())

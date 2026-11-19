"""Split near-miss drafts (placeholder-lane/*/permuted-best.cpp of still-remaining addresses, biggest first) into N evolve.py batch files."""
import glob
import json
import os
import sys

n = int(sys.argv[1]) if len(sys.argv) > 1 else 6
rem = json.load(open('remaining-classified.json'))
c = []
for p in glob.glob('placeholder-lane/*/permuted-best.cpp'):
    a = os.path.basename(os.path.dirname(p))
    if a in rem:
        c.append((rem[a]['size'], p.replace(os.sep, '/')))
c.sort(reverse=True)
print(len(rem), len(c))
for i in range(n):
    open('evolve-shard%d.txt' % i, 'w').write('\n'.join(p for j, (s, p) in enumerate(c) if j % n == i) + '\n')

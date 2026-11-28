"""python spellalias.py: mass alias for `return 0` stubs whose name differs from a REAL linked definition only by how
the analog headers spelled a type: class-name globals (const char* const / char[] / char* const: 3PBDB 3QBDB 3PADA
3QADA), pointer vs reference parameters (PAV/AAV, PBV/ABV), const-ness of pointees and this (QBE/QAE, UBE/UAE).
Every stubbed name is normalized; when exactly ONE non-stub definition in the last map normalizes the same way, the
stub becomes an alias to it (aliases_spell.txt, read by quicktest). Static: no compile, no link.
(FactoryProduct<Part,...,&sPart>::Creator::create was stubbed in the 3PBDB spelling while natives define 3PADA.)"""
import collections, re
from pathlib import Path
H = Path(__file__).parent
RULES = [(re.compile(r'3[PQ][AB]D[AB]'), '3~CS'),        # class-name global: char*/const char*/[const]
         (re.compile(r'(?<=[@$])[PA][AB]V'), '~RV'),       # pointer / reference to class (const or not)
         (re.compile(r'(?<=[@$])[PA][AB]U'), '~RU'),
         (re.compile(r'(?<=@)([QU])[AB]E'), r'\1~E')]       # this const-ness on members


def norm(n):
    for r, s in RULES:
        n = r.sub(s, n)
    return n


stubs, real = set(), collections.defaultdict(set)
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:') and p[1].startswith('?'):
        if 'stubs' in p[-1]:
            stubs.add(p[1])
        else:
            real[norm(p[1])].add(p[1])
out, amb = {}, 0
for s in sorted(stubs):
    c = real.get(norm(s), set()) - {s}
    if len(c) == 1:
        out[s] = next(iter(c))
    elif len(c) > 1:
        amb += 1
try:   # grow-only: aliased stubs vanish from the next map, so a rerun must keep earlier entries
    for l_ in open(H / 'aliases_spell.txt'):
        if '=' in l_:
            k_, v_ = l_.strip().split('=', 1)
            out.setdefault(k_, v_)
except OSError:
    pass
(H / 'aliases_spell.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(out.items())))
print('spellalias: named stubs %d, aliased to a real definition %d, ambiguous %d' % (len(stubs), len(out), amb))
for k, v in list(out.items())[:12]:
    print('  ', k[:70], '\n      ->', v[:70])

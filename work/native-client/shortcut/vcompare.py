"""Compare virtual-function declaration order per class between header trees (heuristic regex, names only).
python vcompare.py TREE_A TREE_B  -> classes present in both whose virtual sequences differ."""
import os, re, sys
def virt(path):
    t = open(path, errors='replace').read()
    t = re.sub(r'//[^\n]*', '', t); t = re.sub(r'/\*.*?\*/', '', t, flags=re.S)
    out = {}
    for m in re.finditer(r'\b(?:class|struct)\s+(\w+)\s*(?::[^{;]*)?\{', t):
        name = m.group(1); i = m.end(); d = 1; j = i
        while j < len(t) and d:
            d += (t[j] == '{') - (t[j] == '}'); j += 1
        body = t[i:j]
        # strip nested braces' contents
        flat = ''; d = 0
        for ch in body:
            if ch == '{': d += 1
            elif ch == '}': d -= 1
            elif d == 0: flat += ch
        seq = [re.sub(r'\s+', ' ', x).strip() for x in re.findall(r'virtual\s+[^;{]*?(~?\w+)\s*\(', flat)]
        if seq: out[name] = seq
    return out
A, B = sys.argv[1], sys.argv[2]
common = same = diff = 0
rows = []
for root, _, fs in os.walk(A):
    for f in fs:
        if not f.endswith('.h'): continue
        pa = os.path.join(root, f); pb = os.path.join(B, os.path.relpath(pa, A))
        if not os.path.exists(pb): continue
        va, vb = virt(pa), virt(pb)
        for c in va:
            if c in vb:
                common += 1
                if va[c] == vb[c]: same += 1
                else:
                    diff += 1; rows.append((c, os.path.relpath(pa, A), len(va[c]), len(vb[c])))
print('classes in both', common, 'same virtual order', same, 'different', diff)
for r in rows[:25]: print(r)

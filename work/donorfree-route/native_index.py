"""python native_index.py: auto/native_index.json = {addr: {file, signature, headers}} for every non-draft native source that
documents an address with a `// <8 hex>` comment above (within 26 lines) a function definition. The definition named in the
comment wins, then the first member function, then the first definition. autorecover.py shows these to the LLM for callees,
so drafts call the real native function instead of inventing an extern."""
import json, re
from pathlib import Path

H = Path(__file__).parent
NC = H.parents[1] / 'rebuild/2008-06/native-classes'
DEF = re.compile(r'^[ \t]*([A-Za-z_][^\n;{}#/]*?\b(?:(\w+)::)?(~?\w+)\s*\([^;{]*?\)\s*(?:const\s*)?)(?::[^{;]*)?\{', re.M)
SKIP = ('if', 'while', 'for', 'switch', 'return', 'catch')
idx = {}
for f in NC.glob('*.cpp'):
    if f.name.startswith('AutoRecover_'):
        continue
    t = f.read_text(errors='replace')
    incs = re.findall(r'#include\s+"([^"]+)"', t)
    for m in re.finditer(r'^[ \t]*//\s*([0-9a-f]{8})\b', t, re.M):
        a = m.group(1)
        if a in idx:
            continue
        rest = t[m.end():]
        comment = rest.split('\n', 1)[0]
        window = '\n'.join(rest.split('\n', 26)[:26])
        defs = [d for d in DEF.finditer(window) if d.group(3) not in SKIP]
        if not defs:
            continue
        d = (next((d for d in defs if re.search(r'\b%s\b' % re.escape(d.group(3)), comment)), None)
             or next((d for d in defs if d.group(2)), None) or defs[0])
        idx[a] = {'file': f.name, 'signature': ' '.join(d.group(1).split())[:220], 'headers': incs[:4]}
(H / 'auto/native_index.json').write_text(json.dumps(idx, indent=0))
print('%d documented native definitions indexed' % len(idx))
if __name__ == '__main__':
    for a in ('0067a7e0', '006786c0', '00448f40'):
        print(a, idx.get(a, {}).get('signature'))

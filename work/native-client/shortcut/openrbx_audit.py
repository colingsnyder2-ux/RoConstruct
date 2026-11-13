"""Count openrbx functions annotated with exe addresses (decomp markers), per top directory."""
import collections, os, re
c, d, s = collections.Counter(), collections.Counter(), collections.Counter()
for root, _, fs in os.walk('tools/openrbx/Client'):
    for f in fs:
        if not f.endswith(('.cpp', '.h')) or f.startswith('roc_'):
            continue
        t = open(os.path.join(root, f), errors='replace').read()
        parts = root.replace(chr(92), '/').split('/')
        top = '/'.join(parts[3:5]) if len(parts) > 4 else '/'.join(parts[3:])
        c[top] += len(re.findall(r'//\s*(?:FUNCTION|TEMPLATE|SYNTHETIC|LIBRARY):\s*ROBLOX\s+0x', t))
        d[top] += len(re.findall(r'//\s*(?:FUNCTION|TEMPLATE|SYNTHETIC|LIBRARY):\s*WEBSERVICE\s+0x', t))
        s[top] += len(re.findall(r'\bSTUB\(', t))
print('ROBLOX-annotated', sum(c.values()), '| WEBSERVICE-annotated', sum(d.values()), '| STUB() bodies', sum(s.values()))
for k, v in c.most_common(14):
    print('  %-28s ROBLOX %5d  WEBSERVICE %5d  STUB %4d' % (k, v, d[k], s[k]))

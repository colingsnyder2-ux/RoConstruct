"""python datatype_audit.py: converted objects bind each analog global (?nativeAdornCount@RBX@@3HA, an int) to the name the
registry has at that original address (?dummyString@RenderDevice@G3D@@0V?$basic_string..., a std::string). When the two
mangled TYPES differ in size, every write through the converted code corrupts the bound object (or reads past it).
Lists those bindings with both sizes. Read-only, seconds. Writes auto/datatype_audit.json."""
import json, re
from pathlib import Path
H = Path(__file__).parent
SC = {'C': 1, 'D': 1, 'E': 1, 'F': 2, 'G': 2, 'H': 4, 'I': 4, 'J': 4, 'K': 4, 'M': 4, 'N': 8, '_N': 1, '_J': 8, '_K': 8,
      '_W': 2, 'O': 8}
CLS = {'?$basic_string@D': 0x1c, '?$basic_string@G': 0x1c, '?$basic_string@_W': 0x1c, '?$shared_ptr@': 8,
       '?$weak_ptr@': 8, 'CStringT': 4, '?$CStringT@': 4, '?$SharedPtr@': 12, 'Vector3@G3D': 12, 'Color3@G3D': 12,
       'CoordinateFrame@G3D': 48, 'Matrix3@G3D': 36, 'Vector2@G3D': 8}


def tsize(sym):
    """size of a mangled global's type, None when unknown: ?name@scope@@3<type><cv> / @@2 (static member) / @@0-1 (private/protected)"""
    m = re.search(r'@@[0-3](.+)$', sym)
    if not m:
        return None
    t = m.group(1)
    if t[:2] in ('PA', 'PB', 'QA', 'QB', 'AA', 'AB') or t[:3] in ('PAP', 'P6A', 'P8'):
        return 4
    if t.startswith(('Y', '_O')):
        return None   # array: size needs the dimension
    for k in ('_N', '_J', '_K', '_W'):
        if t.startswith(k) and len(t) <= 4:
            return SC[k]
    if t[0] in SC and len(t) <= 3:
        return SC[t[0]]
    if t[0] in 'VUW':
        for k, z in CLS.items():
            if k in t:
                return z
        return 'class:' + t[1:].split('@@')[0][:40]
    return None


ren = json.loads((H / 'renamed/rename.json').read_text())
out = {}
for a, x in ren.items():
    rn = x.get('renamed') or {}
    for k, v in (x.get('refs') or {}).items():
        if k.startswith(('rebound:', 'split:', 'collide:')):
            continue
        b = rn.get(k)
        if not (isinstance(b, str) and b != k and k.startswith('?') and b.startswith('?')):
            continue
        if not re.search(r'@@[0-3]', k) or not re.search(r'@@[0-3]', b) or k.startswith('??_') or b.startswith('??_'):
            continue
        s1, s2 = tsize(k), tsize(b)
        if s1 is None or s2 is None or s1 == s2:
            continue
        if isinstance(s1, str) and isinstance(s2, str):
            continue   # two class types of unknown size: no verdict
        e = out.setdefault(v, dict(bound=b, analog_types={}, readers=[]))
        e['analog_types'][k] = s1
        e['bound_size'] = s2
        e['readers'].append(a)
(H / 'auto/datatype_audit.json').write_text(json.dumps(out, indent=1))
print('globals bound to a name of a different-size type: %d (auto/datatype_audit.json)' % len(out))
for v, e in sorted(out.items(), key=lambda kv: -len(kv[1]['readers']))[:25]:
    k, s1 = next(iter(e['analog_types'].items()))
    print('  %s %-45s size %-8s <- analog %-45s size %-8s readers %d' % (v, e['bound'][:45], e['bound_size'], k[:45], s1, len(e['readers'])))

"""Owner class by layout fingerprint (no model).  Every mined byte-exact analog declares the `this` stand-in struct of
its function with pads and typed fields (`char pad0[64]; int m_x;` = an int at +64): byte-proved 2008 layout facts.
 1. Class layouts: union of (offset, width, kind) over the analogs of every function whose owner class is known
    (registry signature)  -> analog-layouts.json
 2. An owner-less remaining function is attributed to class C when all its fields agree with C's layout and C is the
    only class they agree with (leave-one-out validated on known owners; printed precision).  -> layout-owners.json
  python work/native-client/layout_owner.py"""
import collections
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))
import native_llm as m  # noqa: E402
from roc import integration_site  # noqa: E402

reg = m.load_registry()
STRUCT = re.compile(r'\b(?:struct|class)\s+(\w+)\s*(?::[^{]*)?\{([^{}]*)\}', re.S)


def owner(sig):
    flat = re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', sig or '')))
    hit = re.search(r'__thiscall ((?:\w+::)*\w+)::~?\w+\(', flat)
    return hit.group(1) if hit and hit.group(1) not in ('RBX', 'std', 'boost', 'G3D') else None


def size_kind(ty):
    t = ty.replace('const', '').replace('volatile', '').replace('unsigned', '').replace('signed', '').strip()
    if '*' in t or '&' in t:
        return 4, 'p'
    if re.search(r'\bdouble\b|__int64|long long', t):
        return 8, 'f' if 'double' in t else 'i'
    if re.search(r'\bfloat\b', t):
        return 4, 'f'
    if re.search(r'\b(char|bool)\b', t):
        return 1, 'i'
    if re.search(r'\bshort\b|wchar_t', t):
        return 2, 'i'
    if re.search(r'\b(int|long|DWORD|UINT|size_t|BOOL)\b', t) or t == '':
        return 4, 'i'
    return None, None                      # unknown aggregate: offsets after it are not trusted


def this_fields(text):
    """[(offset, width, kind)] of the stand-in struct whose member function the analog defines; None if unusable."""
    code = re.sub(r'//[^\n]*', '', text)
    methods = set(re.findall(r'\b(\w+)::~?\w+\s*\(', code))
    best = None
    for name, body in STRUCT.findall(code):
        if name not in methods:
            continue
        off, fields, ok = 0, [], True
        for decl in body.split(';'):
            d = ' '.join(decl.split())
            if not d or '(' in d or d.startswith(('public', 'private', 'protected', 'friend', 'typedef', 'static', 'enum')):
                continue
            if ':' in d and not d.endswith(':'):                  # bitfield
                ok = False
                break
            arr = re.match(r'(.+?)\s*\b(\w+)\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]$', d)
            plain = re.match(r'(.+?)\s*\b(\w+)$', d)
            if arr:
                size, kind = size_kind(arr.group(1))
                count = int(arr.group(3), 0)
                if size is None:
                    ok = False
                    break
                if re.search(r'\bchar\b', arr.group(1)) and re.match(r'(pad|_pad|gap|unk|filler|reserved)', arr.group(2), re.I):
                    off += count                                  # padding: no alignment, no field
                    continue
                off = (off + min(size, 4) - 1) // min(size, 4) * min(size, 4)
                fields.append((off, size, kind))
                off += size * count
            elif plain:
                size, kind = size_kind(plain.group(1))
                if size is None:
                    ok = False
                    break
                align = min(size, 8 if size == 8 else 4)
                off = (off + align - 1) // align * align
                fields.append((off, size, kind))
                off += size
        if ok and fields and (best is None or len(fields) > len(best)):
            best = fields
    return best


exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
remaining = set(json.loads((HERE / 'remaining-classified.json').read_text())) - exact
per_fn, layouts = {}, collections.defaultdict(lambda: collections.defaultdict(set))
for path in (ROOT / 'src/2008-06').glob('*.cpp'):
    addr = path.stem
    if not re.fullmatch(r'[0-9a-f]{8}', addr):
        continue
    text = path.read_text(errors='replace')
    if re.search(r'^//\s*roc-(?:lib|archive):', text, re.M):
        continue
    fields = this_fields(text)
    if not fields:
        continue
    per_fn[addr] = fields
    cls = owner((reg.get(addr) or {}).get('signature'))
    if cls:
        for f in fields:
            layouts[cls][f].add(addr)
print('analogs with a this-struct: %d; classes with layout facts: %d' % (len(per_fn), len(layouts)))
(HERE / 'analog-layouts.json').write_text(json.dumps(
    {c: [{'off': '0x%x' % o, 'width': w, 'kind': k, 'functions': len(a), 'example': sorted(a)[0]}
         for (o, w, k), a in sorted(fs.items())] for c, fs in sorted(layouts.items())}, indent=1))


def attribute(addr, fields, leave_out=None):
    """Class whose layout agrees with every field, when exactly one does and >= 2 fields sit past +0x10."""
    strong = [f for f in fields if f[0] >= 0x10]
    if len(strong) < 2:
        return None
    hits = []
    for cls, fs in layouts.items():
        if all(f in fs and (fs[f] - {leave_out} if leave_out else fs[f]) for f in strong):
            hits.append(cls)
            if len(hits) > 1:
                return None
    return hits[0] if len(hits) == 1 else None


right = total = 0
for addr, fields in per_fn.items():
    cls = owner((reg.get(addr) or {}).get('signature'))
    if not cls:
        continue
    got = attribute(addr, fields, leave_out=addr)
    if got:
        total += 1
        right += got == cls or got.split('::')[-1] == cls.split('::')[-1]
print('validation on known owners: %d of %d right (%.1f%%)' % (right, total, 100.0 * right / max(1, total)))
out = {}
for addr in remaining:
    if addr in per_fn and not owner((reg.get(addr) or {}).get('signature')):
        cls = attribute(addr, per_fn[addr])
        if cls:
            out[addr] = {'class': cls, 'evidence': 'layout', 'detail': 'fields %s agree only with this class'
                         % ', '.join('+0x%x/%d%s' % f for f in per_fn[addr] if f[0] >= 0x10)}
no_owner = sum(1 for a in remaining if a in per_fn and not owner((reg.get(a) or {}).get('signature')))
print('owner-less remaining with a this-struct: %d; attributed: %d' % (no_owner, len(out)))
print('top classes:', collections.Counter(v['class'] for v in out.values()).most_common(12))
(HERE / 'layout-owners.json').write_text(json.dumps(out, indent=1))

"""python initscan.py: globals the ORIGINAL exe constructs at startup (dynamic initializers 0x7c0000-0x800000:
`mov ecx, ADDR` then `call ctor`) that our link still reads as zero placeholders (dat_<ADDR>) -- the class behind
g_strmgr, mainLogManager, RbxSceneManagerFactory::FACTORY_TYPE_NAME and the ATL thunk pool. For each, suggests the
native global by the string literal the initializer passes (grep of native sources). Read-only; seconds.
Writes auto/initscan.json {addr: {ctor, literal, readers, suggest}}."""
import json, re
from collections import defaultdict
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
ROOT = H.parents[1]
pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
img = pe.get_memory_mapped_image(); base = pe.OPTIONAL_HEADER.ImageBase
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
name = lambda a: (reg.get('%08x' % a) or {}).get('name') or ''
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)


def cstr(va):
    o = va - base
    if not (0 <= o < len(img)):
        return None
    e = img.find(b'\0', o, o + 200)
    s = bytes(img[o:e]) if e > o else b''
    return s.decode('latin-1') if s and len(s) >= 3 and all(32 <= c < 127 for c in s) else None


built = {}   # data address -> (initializer va, ctor va, literal)
code = bytes(img[0x7c0000 - base:0x800000 - base])
# linear sweep is fooled by padding: scan for the B9 imm32 pattern and decode a short window after it
for o in range(len(code) - 10):
    if code[o] != 0xb9:
        continue
    addr = int.from_bytes(code[o + 1:o + 5], 'little')
    if not (0x900000 <= addr < 0x9a0000):
        continue
    va = 0x7c0000 + o
    lit, ctor, lits = None, None, []
    for k in range(max(0, o - 40), o + 24):   # string literals pushed around the ctor call (name, category, ...)
        if code[k] == 0x68:
            c_ = cstr(int.from_bytes(code[k + 1:k + 5], 'little'))
            if c_:
                lits.append(c_); lit = lit or c_
    for ins in md.disasm(code[o + 5:o + 40], va + 5):
        if ins.mnemonic == 'call' and ins.op_str.startswith('0x'):
            ctor = int(ins.op_str, 16); break
    if ctor:
        built.setdefault(addr, (va, ctor, lit, lits))
# how our link binds each address: native data name / override, else a placeholder
nd = json.load(open(H / 'renamed/native_data.json')) if (H / 'renamed/native_data.json').exists() else {}
ren = json.load(open(H / 'renamed/rename.json'))
readers = defaultdict(list)   # only readers that bind the address to a PLACEHOLDER (dat_<addr>): a real name is fine
for a_, x in ren.items():
    rn_ = x.get('renamed') or {}
    for k_, v_ in (x.get('refs') or {}).items():
        if not k_.startswith(('rebound:', 'split:', 'collide:')) and str(rn_.get(k_, '')).startswith('dat_'):
            readers[v_].append(a_)
native_src = list((ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'))
srcs = {p: p.read_text(errors='replace') for p in native_src}
out = {}
# map symbols by their leading identifier, for 'prop_Browsing' -> ?prop_Browsing@Class@RBX@@2V... (unique)
_msyms = defaultdict(list)
for _l in (H / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    _p = _l.split()
    if len(_p) >= 4 and ':' in _p[0] and _p[1].startswith('?') and ('@@2' in _p[1] or '@@3' in _p[1]):
        _msyms[_p[1][1:].split('@', 1)[0]].append(_p[1])
for addr, (va, ctor, lit, lits) in sorted(built.items()):
    k = '%08x' % addr
    if k in nd or not readers.get(k):
        continue   # bound to a native global already, or nothing converted reads it
    sug = []
    auto = None
    for L in lits:   # native reflection statics: static PropDescriptor<...> prop_X("Name", "Category", ...)
        q = '"%s"' % L
        for p, t in srcs.items():
            if q not in t:
                continue
            for m in re.finditer(r'((?:prop|func|event|desc|sig|callback)_\w+)\s*\(\s*' + re.escape(q), t):
                c_ = sorted(set(_msyms.get(m.group(1), [])))
                if len(c_) == 1:
                    auto = auto or c_[0]
                sug.append('%s: %s -> %s' % (p.name, m.group(1), c_[0][:60] if len(c_) == 1 else '%d syms' % len(c_)))
    if lit and not sug:
        q = '"%s"' % lit
        pat = None
        for p, t in srcs.items():
            if q not in t:   # cheap substring test first; regex only on the few files that contain the literal
                continue
            pat = pat or re.compile(r'([A-Za-z_][\w:]*)\s*(?:=\s*|\(\s*)"%s"' % re.escape(lit))
            for m in pat.finditer(t):
                sug.append('%s: %s' % (p.name, m.group(1)))
    out[k] = dict(initializer='%08x' % va, ctor='%08x %s' % (ctor, name(ctor)[:80]), literal=lit, literals=lits[:4],
                  readers=readers[k][:6], suggest=sug[:4], auto=auto)
(H / 'auto/initscan.json').write_text(json.dumps(out, indent=1))
import sys as _sys
_auto = {k: v['auto'] for k, v in out.items() if v.get('auto')}
print('unique native matches: %d' % len(_auto))
if '--apply' in _sys.argv and _auto:   # bind these addresses to the native globals (rename.py native_data rule)
    _of = H / 'renamed/data_overrides.json'
    _d = json.loads(_of.read_text()) if _of.exists() else {}
    _d.update({k: v for k, v in _auto.items() if k not in _d})
    _of.write_text(json.dumps(_d, indent=1))
    print('applied to renamed/data_overrides.json (%d entries)' % len(_d))
print('globals the original builds at startup: %d; read by converted code but not bound to a native global: %d' % (len(built), len(out)))
for k, v in list(out.items())[:25]:
    print('  %s lit=%r ctor=%s readers=%d suggest=%s' % (k, (v['literal'] or '')[:30], v['ctor'][:50], len(v['readers']), v['suggest'][:2]))

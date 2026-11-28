"""python rtclass.py: alias dat_<addr> placeholders that are an MFC CRuntimeClass in the original to our real
?class<N>@<N>@@2UCRuntimeClass@@A. An analog GetRuntimeClass (func_00745630 = CXTPControlButton's vtable slot 0)
returned the zero stub dat_00969574 instead of our classCXTPControlButton -> IsKindOf(CXTPControl) failed ->
CXTPControls::DoPropExchange threw badClass loading IDESettings.xml. Recognised by the original bytes: the first field
points at an ASCII class name and the class symbol of that name is defined by real code in our link.
Writes aliases_rtclass.txt (only grows: an aliased name is no longer a stub, so a rescan cannot see it)."""
import re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
pe = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
img = pe.get_memory_mapped_image(); base = pe.OPTIONAL_HEADER.ImageBase


def cstr(va):
    o = va - base
    if not 0 <= o < len(img):
        return None
    e = img.find(b'\0', o, o + 128)
    s = bytes(img[o:e]) if e > o else b''
    return s.decode() if re.fullmatch(rb'C[A-Za-z_]\w*', s) else None


stubs, real = set(), set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        (stubs if 'stubs' in p[-1] else real).add(p[1])
out = H / 'aliases_rtclass.txt'
al = dict(l.split('=', 1) for l in out.read_text().splitlines() if '=' in l) if out.exists() else {}
for s in stubs:
    m = re.fullmatch(r'_?dat_([0-9a-f]{8})', s)
    if not m:
        continue
    o = int(m.group(1), 16) - base
    if not 0 <= o < len(img) - 24:
        continue
    nm = cstr(struct.unpack_from('<I', img, o)[0])
    size = struct.unpack_from('<I', img, o + 4)[0]
    if nm and 4 <= size < 0x100000:
        cls = '?class%s@%s@@2UCRuntimeClass@@A' % (nm, nm)
        if cls in real:
            al[s] = cls
# natives that name a global after its ORIGINAL address (?g_009739d0@@3PBVName@RBX@@B, Name's null name written by
# initNullName) own that address: dat_<addr> placeholders alias to them (a separate placeholder split the state ->
# getNullName returned 0 -> DataModel::initializeContents crash)
import collections as _c
_gn = _c.defaultdict(set)
for _n in real:
    _m = re.match(r'^\?g_([0-9a-f]{8})@@3', _n) or re.match(r'^_g_([0-9a-f]{8})$', _n)
    if _m:
        _gn[_m.group(1)].add(_n)
_ng = 0
for s in stubs:
    m = re.fullmatch(r'dat_([0-9a-f]{8})', s)
    if m and len(_gn.get(m.group(1), ())) == 1:
        al[s] = next(iter(_gn[m.group(1)])); _ng += 1
try:   # native sources that name an original data address (// 00976b4c: Log::provider -> renamed/native_data.json)
    import json as _j
    _nd = _j.loads((H / 'renamed/native_data.json').read_text())
    for s in stubs:
        m = re.fullmatch(r'dat_([0-9a-f]{8})', s)
        if m and _nd.get(m.group(1)) in real and s not in al:
            al[s] = _nd[m.group(1)]; _ng += 1
except (OSError, ValueError):
    pass
print('rtclass: dat_ placeholders aliased to a native global at that address: %d' % _ng)
out.write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('rtclass: %d dat_ CRuntimeClass placeholders aliased to our class objects (e.g. %s)' % (len(al), sorted(al.items())[:2]))

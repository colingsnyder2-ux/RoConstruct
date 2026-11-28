"""python stubalias.py: bind STUB names (analog spellings) to what the original has at their address. origcover.py found
the original running 123 of our stubs on the File->New path: ?allocate@@YAPAXI@Z / ?freeObject@@YAXPAX@Z / _final are
analog names for the IMPORT THUNKS of operator new / delete / the CRT (`return 0` from operator new...), and 36 names
whose converted body exists but was not bound to them. Mapping (as origcover): func_<X> -> X; else a unique registry
address; else a unique converted-caller ref address. Then:
  original code is `jmp [IAT]`      -> alias to the import's symbol (named; mfc90 by ordinal via renamed/ordinals.json)
  a converted object for X is linked -> alias to its defined symbol (rename.json symbol, else func_<X>)
Writes aliases_stubalias.txt (quicktest reads it; aliased names are stripped from the stub objects)."""
import json, re, struct
from pathlib import Path
import pefile
H = Path(__file__).parent
ROOT = H.parents[1]
reg = json.load(open(ROOT / 'work/2008-06/identity-registry.json'))
ren = json.loads((H / 'renamed/rename.json').read_text())
byname, refaddr = {}, {}
for a, v in reg.items():
    n = (v or {}).get('name')
    if n:
        byname.setdefault(n, set()).add(a)
for x in ren.values():
    for k, v in (x.get('refs') or {}).items():
        if not k.startswith(('collide:', 'split:', 'rebound:')):
            refaddr.setdefault(k, set()).add(v)
own, stubs = {}, []
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and ':' in p[0]:
        own.setdefault(p[1], p[-1])
        if p[0].startswith('0001') and 'stubs' in p[-1]:
            stubs.append(p[1])
real = lambda n: n in own and 'stubs' not in own[n] and own[n] != '<absolute>'
o = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
o.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
img = o.get_memory_mapped_image()
om = json.loads((H / 'renamed/ordinals.json').read_text()).get('mfc90.dll', {})
iat = {}
for d in o.DIRECTORY_ENTRY_IMPORT:
    dll = d.dll.decode().lower()
    for i in d.imports:
        nm = i.name.decode() if i.name else (om.get(str(i.ordinal)) if dll == 'mfc90.dll' else None)
        if nm:
            iat[i.address] = (dll, nm)
al, kinds = {}, {'import': 0, 'converted': 0}
for s in stubs:
    mm = re.match(r'^_?func_([0-9a-f]{8})$', s)
    cand = {mm.group(1)} if mm else (byname.get(s, set()) if len(byname.get(s, ())) == 1 else refaddr.get(s, set()))
    if len(cand) != 1:
        continue
    a = next(iter(cand)); va = int(a, 16)
    if not 0x401000 <= va < 0x7c0000:
        continue
    b = bytes(img[va - 0x400000:va - 0x400000 + 6])
    if b[:2] == b'\xff\x25':
        dll, nm = iat.get(struct.unpack_from('<I', b, 2)[0], (None, None))
        if not nm:
            continue
        # C++ names are the thunk symbol itself; C names: _name (cdecl CRT) or the __imp_ slot's thunk via import lib
        t = nm if nm.startswith('?') else '_' + nm
        if t != s and (real(t) or nm.startswith('?') or dll.startswith(('msvcr', 'msvcp'))):
            al[s] = t; kinds['import'] += 1
        continue
    sym = (ren.get(a) or {}).get('symbol')
    for t in (sym, 'func_' + a):
        if t and t != s and real(t):   # converted body, or the native that replaced an excluded conversion (_fn = Name::declare)
            al[s] = t; kinds['converted'] += 1
            break
_af = H / 'aliases_stubalias.txt'   # grow-only: an aliased name is no longer a stub, a rescan cannot see it
if _af.exists():
    for _l in _af.read_text().splitlines():
        if '=' in _l:
            _k, _v = _l.split('=', 1); al.setdefault(_k, _v)
(H / 'aliases_stubalias.txt').write_text(''.join('%s=%s\n' % kv for kv in sorted(al.items())))
print('stubalias: %d stubs bound to the original\'s code (%s); e.g. %s' % (len(al), kinds, sorted(al.items())[:3]))

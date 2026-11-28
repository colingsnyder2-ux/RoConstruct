"""Compiler glue the original has where our link only has a `mov eax,0; ret` stub, rebuilt from the original's
instructions with RELOCATIONS (never raw target addresses):
  mov eax, imm32 (data 0x7c0000-0x9a0000); ret [n]  -> GetRuntimeClass / GetThisMessageMap-style constant getters:
                                                       `mov eax, dat_<imm>` (rtclass/dat aliases bind our object)
  [add|sub ecx, imm] / [sub dword [esp+4], imm8]; jmp rel32  -> this-adjustor thunks: same prefix + `jmp func_<T>`
  jmp rel32                                          -> plain forwarding thunk: `jmp func_<T>`
item(name, orig) -> (name, body, ret_n, relocs) for coffstub.write, or None when the original is anything else.
addr_of(name) -> original address: func_<X>; else auto/stubret_addr.json (vtable-slot truth); else a unique registry name."""
import json, struct
from pathlib import Path
H = Path(__file__).parent
_IMG = []
_ADDR = {}


def _img():
    if not _IMG:
        import pefile
        _IMG.append(pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image())
    return _IMG[0]


def addr_of(name):
    if name.startswith('func_') and len(name) == 13:
        return int(name[5:], 16)
    if not _ADDR:
        _ADDR['_'] = 1
        try:
            _sa = {k: int(v, 16) for k, v in json.loads((H / 'auto/stubret_addr.json').read_text()).items()}
        except (OSError, ValueError):
            _sa = {}
        _ADDR.update(_sa)
        try:
            rg = json.load(open(H.parents[1] / 'work/2008-06/identity-registry.json'))
            cnt = {}
            for a, v in rg.items():
                n = (v or {}).get('name')
                if n and v.get('kind') == 'code' and n.startswith('?'):
                    cnt[n] = cnt.get(n, 0) + 1; _ADDR.setdefault(n, int(a, 16))
            for n, c in cnt.items():
                if c > 1 and n in _ADDR and n not in _sa:   # ponytail: was re-parsing the json per name (260 s per relink)
                    _ADDR.pop(n, None)
        except (OSError, ValueError):
            pass
    return _ADDR.get(name)


def item(name, orig=None):
    a = orig or addr_of(name)
    if not a or not 0x401000 <= a < 0x7c0000:
        return None
    m = _img()
    o = a - 0x400000
    b = bytes(m[o:o + 16])
    if b[0] == 0xb8:   # mov eax, imm32; ret / ret n
        imm = struct.unpack_from('<I', b, 1)[0]
        if 0x7c0000 <= imm < 0x9a0000 and b[5] in (0xc3, 0xc2):
            n = struct.unpack_from('<H', b, 6)[0] if b[5] == 0xc2 else 0
            return (name, b'\xb8\0\0\0\0', n, [(1, 'dat_%08x' % imm, 0x06)])
        return None
    # vcall thunks: mov eax,[ecx]; jmp [eax+disp] -- position independent, no relocation
    if b[:4] == b'\x8b\x01\xff\x60':
        return (name, b[:5], -1, [])
    if b[:4] == b'\x8b\x01\xff\xa0':
        return (name, b[:8], -1, [])
    if b[:4] == b'\x8b\x01\xff\x20':
        return (name, b[:4], -1, [])
    pre = 0
    if b[:2] in (b'\x83\xc1', b'\x83\xe9'):
        pre = 3
    elif b[:2] in (b'\x81\xc1', b'\x81\xe9'):
        pre = 6
    elif b[:4] == b'\x83\x6c\x24\x04':
        pre = 5
    if b[pre] == 0xe9:
        t = a + pre + 5 + struct.unpack_from('<i', b, pre + 1)[0]
        if 0x401000 <= t < 0x7c0000 and t != a:
            return (name, b[:pre] + b'\xe9\0\0\0\0', -1, [(pre + 1, 'func_%08x' % t, 0x14)])
    return None


if __name__ == '__main__':
    for n in ('func_0075d4f0', 'func_0078e6e0', 'func_00407e90'):
        print(n, item(n))
    assert item('func_0075d4f0')[1][:3] == b'\x83\xc1\xe0'

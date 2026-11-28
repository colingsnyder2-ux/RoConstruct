"""stubs.obj for the donor-free link: one zero-return stub per unresolved FUNCTION symbol and zeroed storage per unresolved DATA
symbol, so the exe links without /FORCE:UNRESOLVED holes and `crashsite.py` (BPSTUBS=1) can log, in call order, which
missing symbol boot reaches first. Harness only: stubs are diagnostics, never part of any proof.

    python work/donorfree-route/make_stubs.py   -> work/donorfree-route/link/stubs.obj (+ stubs.asm, stubs.json)
"""
import json, os, re, sys
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import rebuild

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE))
OUT = HERE / 'link'
FUNC = re.compile(r'@Z$')                  # decorated functions end in @Z (data/vtables use @@<digit>)


# stubs for callee-pops functions: `ret N` (a bare ret unbalances the stack and crashes the first caller)
RET_BYTES = {'?runProc@RunService@RBX@@AAEXV?$shared_ptr@VDataModel@RBX@@@boost@@@Z': 8, '?setParent@Instance@RBX@@QAEXPAV12@@Z': 4, '?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@Reflection@2@@Z': 4}



_UND = None



# a stub for a function that returns a class BY VALUE must construct the caller's hidden result object ([esp+4]):
# an uninitialised std::string from nativeAssetFolder() crashed operator+. Known types become valid empty values;
# eax returns the result pointer as the real function would. Diagnostic safety only: the stub still does nothing.
_SRET = [
    (r'\?AV\?\$basic_string@DU\?\$char_traits@D@std@@V\?\$allocator@D@2@@std@@',
     bytes.fromhex('8b442404' 'c70000000000' 'c6400400' 'c7401400000000' 'c740180f000000')),
    (r'\?AV\?\$shared_ptr@', bytes.fromhex('8b442404' 'c70000000000' 'c7400400000000')),
    (r'\?AV\?\$(?:ReferenceCountedPointer|intrusive_ptr)@', bytes.fromhex('8b442404' 'c70000000000')),
]


def _sret_body(sym):
    import re as _r
    m = _r.match(r'^\?[^?]\S*?@@(?:[A-Z]{2}E|[A-Z]A)(\?AV.*)$', sym)   # return type after access + calling convention
    if not m:
        return None
    for pat, body in _SRET:
        if _r.match(pat, m.group(1)):
            return body
    return None


def signature_ret_bytes(sym):
    """cached wrapper: undname per symbol is the slowest part of a relink (thousands of process starts)."""
    global _UND
    cache = HERE / 'link/undname_cache2.json'   # v2: by-value class sizes (auto/valsizes.json)
    if _UND is None:
        try:
            _UND = json.loads(cache.read_text())
        except Exception:
            _UND = {}
        import atexit
        atexit.register(lambda: cache.write_text(json.dumps(_UND)))
    if sym not in _UND:
        _UND[sym] = _signature_ret_bytes(sym)
    return _UND[sym]


_DEM = {}


def prefetch_demangle(syms):
    """demangle many names per undname.exe launch (one process per name was the slowest part of a relink)."""
    import subprocess
    signature_ret_bytes('?')   # loads the on-disk result cache (_UND): names already answered need no undname launch
    todo = [x for x in syms if x not in _DEM and x not in _UND and len(x) < 4000]
    for i in range(0, len(todo), 200):
        part = todo[i:i + 200]
        try:
            out = subprocess.run([str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')] + part, capture_output=True, text=True).stdout
        except Exception:
            continue
        got = re.findall(r'Undecoration of :- "(.*)"'+r'\s*'+r'\nis :- "(.*)"', out)
        for a, b in got:
            _DEM[a] = b


_VS = []


def _valsizes():
    if not _VS:
        try:
            _VS.append(json.loads((HERE / 'auto/valsizes.json').read_text()))
        except Exception:
            _VS.append({})
    return _VS[0]


def _signature_ret_bytes(sym):
    """callee-pops bytes for a thiscall/stdcall symbol, from its undname signature: 4 per pointer/ref/int/enum param, 8 per
    double/__int64, 0x1c per std::string by value, +4 for a hidden by-value class return (sret). cdecl/unknown -> None."""
    import re, subprocess
    if not re.search(r'@@[A-Z]?[A-Z]*[EG][A-Z]?(?:[A-Z_?$@0-9]|$)', sym) and not re.search(r'(Q|U|M|I|E)[AB]E', sym) and 'AG' not in sym:
        pass
    t = _DEM.get(sym)
    if t is None:
        try:
            out = subprocess.run([str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe'), sym], capture_output=True, text=True).stdout
        except Exception:
            return None
        m = re.search(r'is :- "(.*)"', out)
        if not m: return None
        t = m.group(1)
    if '__thiscall' not in t and '__stdcall' not in t: return None
    i = t.rfind('(')
    # find the matching '(' of the final parameter list
    depth = 0; j = len(t) - 1
    while j >= 0 and not (t[j] == ')' and depth == 0 and ('const' in t[j+1:] or t[j+1:].strip() == '' or True)): j -= 1
    end = t.rfind(')')
    d = 0; k = end
    while k >= 0:
        if t[k] == ')': d += 1
        elif t[k] == '(':
            d -= 1
            if d == 0: break
        k -= 1
    params = t[k + 1:end]
    head = t[:k]
    args = []; d = 0; cur = ''
    for ch in params:
        if ch in '<(': d += 1
        elif ch in '>)': d -= 1
        if ch == ',' and d == 0: args.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): args.append(cur.strip())
    total = 0
    for a in args:
        if a == 'void': continue
        if a.endswith(('*', '&')) or ' * ' in a or ' & ' in a or a.rstrip().endswith('const'): total += 4 if not a.startswith(('class ', 'struct ')) or '*' in a or '&' in a else 4
        elif a.startswith(('double',)) or a.startswith('__int64') or a.startswith('unsigned __int64'): total += 8
        elif 'basic_string' in a: total += 0x1c
        elif a.startswith(('class ', 'struct ')):   # by-value class: size learned from the original (valsizes.py), else one word
            total += _valsizes().get(a.replace('const ', '').strip(), 4)
        else: total += 4
    # hidden sret for a by-value class return (the return type is the text between the access/virtual words and the convention)
    r = re.search(r'^(?:public|protected|private): (?:static |virtual )*(.*?) __(?:thiscall|stdcall)', head)
    if r:
        rt = r.group(1)
        if (rt.startswith(('class ', 'struct ')) and not rt.rstrip().endswith(('*', '&'))): total += 4
    return total


_ERB = {}


def exe_ret_bytes():
    """cached: the original exe and the registry rarely change (was a full disassembly, twice per run)"""
    if _ERB:
        return dict(_ERB)
    ff = ROOT / 'work/native-client/layout/function-files.json'
    cf = HERE / 'link/exe_ret_bytes.json'
    try:
        c = json.loads(cf.read_text())
        if c['mtime'] == ff.stat().st_mtime:
            _ERB.update(c['ret'])
            return dict(_ERB)
    except Exception:
        pass
    _ERB.update(_exe_ret_bytes())
    cf.write_text(json.dumps({'mtime': ff.stat().st_mtime, 'ret': _ERB}))
    return dict(_ERB)


_ARB = {}


def addr_ret_bytes(addr):
    """bytes the original function at addr pops (its first `ret N`): a func_<addr> stub must pop the same, or its caller's
    stack drifts (the boost::any holder's ??_E 0041aba0 stub returned with `ret`, the next ret jumped to 1)"""
    if not _ARB:   # disk cache (deterministic: original binary + address); capstone per func_ stub every relink
        try:
            _ARB.update({int(k, 16): v for k, v in json.loads((HERE / 'link/addr_ret_cache2.json').read_text()).items()})
        except Exception:
            pass
        _ARB[-1] = 0
        import atexit
        atexit.register(lambda: (HERE / 'link/addr_ret_cache2.json').write_text(json.dumps({'%08x' % k: v for k, v in _ARB.items() if k >= 0})))
    if 0x7b0000 <= addr < 0x801000:   # EH unwind funclets (mov/lea ecx,[ebp-x] ; jmp ~T): called by the CRT unwinder
        orig_bytes(addr, 4)          # with no arguments, so they pop nothing. Following the jmp took the destructor's
        o_ = addr - 0x400000         # first `ret 8/16` (another path): every unwind through such a stub shifted the
        if _IMG[o_:o_ + 1] in (b'\x8b', b'\x8d') and _IMG[o_ + 1] & 0xc7 in (0x45, 0x85, 0x4d, 0x8d):   # stack (stubret_all)
            return 0
    if addr not in _ARB:
        import capstone
        orig_bytes(addr, 4)   # loads _IMG
        o = addr - 0x400000
        n = _k = 0
        for ins in capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(bytes(_IMG[o:o + 0x800]), addr):
            if ins.mnemonic == 'ret':
                n = int(ins.op_str, 16) if ins.op_str else 0
                break
            # a thunk (`add ecx,-20h; jmp X`) ends in jmp: scanning on took the NEXT function's `ret 8` -> the stub for
            # the adjustor thunk 0075d4f0 popped 8 bytes, CXTPDockingPaneLayout::Free returned into the heap
            _k += 1
            # thunk shape only (the jmp within the first 3 instructions): a later jmp is a loop / branch inside the body
            if ins.mnemonic == 'jmp' and _k <= 3 and (ins.op_str.startswith('0x') or 'dword ptr [0x' in ins.op_str):
                _ARB[addr] = 0   # recursion guard (thunk chains / self loops)
                if ins.op_str.startswith('0x'):
                    t_ = int(ins.op_str, 16)
                    n = addr_ret_bytes(t_) if 0x401000 <= t_ < 0x7c0000 and t_ not in _ARB else _ARB.get(t_, 0)
                else:
                    n = _import_ret_bytes(int(ins.op_str.split('[0x')[1].rstrip(']'), 16))
                break
        _ARB[addr] = n
    return _ARB[addr]


def _import_ret_bytes(iat):
    """bytes an IMPORTED function pops, from its decorated name (mfc90 ordinals via renamed/ordinals.json): `_X@N` -> N,
    ?decorated -> signature_ret_bytes, cdecl / unknown -> 0"""
    if '_IAT' not in globals():
        import pefile, re as _re
        o_ = pefile.PE(str(HERE.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True)
        o_.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
        om = json.loads((HERE / 'renamed/ordinals.json').read_text()).get('mfc90.dll', {})
        globals()['_IAT'] = {i.address: (i.name.decode() if i.name else om.get(str(i.ordinal), '')) for d in o_.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    nm = _IAT.get(iat, '')
    import re as _re
    m = _re.match(r'^_\w+@(\d+)$', nm)
    if m:
        return int(m.group(1))
    if nm.startswith('?'):
        try:
            return signature_ret_bytes(nm) or 0
        except Exception:
            return 0
    return 0


def _exe_ret_bytes():
    """decorated name -> bytes the original function pops on return (first `ret N` after its entry), from the 2008-06 exe."""
    import struct, capstone
    from roc import clients
    exe = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
    pe = struct.unpack_from('<I', exe, 0x3c)[0]; nsec = struct.unpack_from('<H', exe, pe + 6)[0]; opt = struct.unpack_from('<H', exe, pe + 20)[0]
    base = struct.unpack_from('<I', exe, pe + 24 + 28)[0]
    secs = [struct.unpack_from('<IIII', exe, pe + 24 + opt + 40 * i + 8) for i in range(nsec)]
    def off(v):
        r = v - base
        for vs, va, rs, ro in secs:
            if va <= r < va + max(vs, rs): return ro + r - va
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = {}
    for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items():
        n = r.get('name') or ''
        if not n.startswith('?') and not n.startswith('??'): continue
        o = off(int(a, 16))
        if o is None: continue
        for ins in md.disasm(exe[o:o + 0x600], int(a, 16)):
            if ins.mnemonic == 'ret':
                out[n] = int(ins.op_str, 16) if ins.op_str else 0
                break
    return out


_DR = {}


def data_relocs(va, n):
    """pointers to FUNCTIONS inside an original data block (boost function managers, callback tables): relocate them to
    that function in our link (its real name when our link defines it, else func_<addr>) instead of zeroing them."""
    if not _DR:
        ff = json.load(open(ROOT / 'work/native-client/layout/function-files.json'))
        try:
            dc = set(json.load(open(HERE / 'link/defined_cache.json')))
        except Exception:
            dc = set()
        dup = {a for a, v in ff.items() if (v or {}).get('requires_identity_review') and ((v or {}).get('duplicate_target_name_count') or 1) > 1}
        try:   # an exact converted object for that address beats any name (its code IS the original function)
            rr = json.load(open(HERE / 'renamed/rename.json'))
        except Exception:
            rr = {}
        for a, v in ff.items():
            nm = (v or {}).get('name') or ''
            if (rr.get(a) or {}).get('status') == 'renamed' and len((rr[a].get('symbol') or '')) > 2:
                _DR[int(a, 16)] = rr[a]['symbol']
            else:
                _DR[int(a, 16)] = nm if (nm.startswith('?') and nm in dc and a not in dup) else 'func_' + a
    orig_bytes(va, 4)   # loads _IMG
    o = va - 0x400000
    raw = bytes(_IMG[o:o + n]) if 0 <= o < len(_IMG) else b''
    out = []
    for k in range(0, len(raw) - 3, 4):
        p = int.from_bytes(raw[k:k + 4], 'little')
        if p in _DR:
            out.append((k, _DR[p]))
        elif 0x7c0000 <= p < 0x9a0000 and _msgmap_entries_size(p):   # a message map's entry array, not the string "$"
            out.append((k, 'dat_%08x' % p))                              # its first entry (WM_GETMINMAXINFO=0x24) looks like
        elif 0x7c0000 <= p < 0x9a0000 and _string_at(p):   # pointer to a C string literal ("profiled5"): own copy
            out.append((k, 'roc_str_%08x' % p))
        elif 0x7c0000 <= p < 0x9a0000 and _is_reloc(va + k):
            # pointer to other original DATA (a message map's entry array, a descriptor table): that data's own dat_ copy.
            # Only words the original's base-relocation table marks as pointers (never a plain integer)
            out.append((k, 'dat_%08x' % p))
    return out


_RELOCS = []


def _is_reloc(site):
    import bisect
    if not _RELOCS:
        from roc import fingerprint
        _RELOCS.extend(sorted(fingerprint.Target('2008-06').relocs))
    i = bisect.bisect_left(_RELOCS, site)
    return i < len(_RELOCS) and _RELOCS[i] == site


_ADDRS = []


def data_size(va, cap=0x1000):
    """bytes from va to the next known symbol (identity registry / function table), at most cap: a data copy must
    cover the whole object (message-entry arrays are longer than the old fixed 0x100)"""
    import bisect
    if not _ADDRS:
        try:
            _ADDRS.extend(sorted({int(a, 16) for a in json.load(open(ROOT / 'work/2008-06/identity-registry.json'))} |
                                 {int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json'))}))
        except Exception:
            _ADDRS.append(0xffffffff)
    i = bisect.bisect_right(_ADDRS, va)
    n = max(4, min(cap, (_ADDRS[i] - va) if i < len(_ADDRS) else cap)) + 3 & ~3
    m = _msgmap_entries_size(va)   # an MFC message-map entry array runs to its all-zero terminator, whatever labels
    return max(n, m) if m else n   # sit inside it (CRbxChildFrame's map was cut after 16 bytes -> WM_PAINT flood)


@lru_cache(maxsize=None)   # pure in the original image; data_relocs asked 1.5M times (~15 s)
def _msgmap_entries_size(va):
    """bytes of an AFX_MSGMAP_ENTRY array at va (24-byte entries: nMessage, nCode, nID, nLastID, nSig, pfn; ends with
    an all-zero entry), or None when va does not hold one"""
    import struct
    orig_bytes(va, 4)   # loads _IMG
    o = va - 0x400000
    for i in range(400):
        if not 0 <= o + 24 * i + 24 <= len(_IMG):
            return None
        e = struct.unpack_from('<6I', _IMG, o + 24 * i)
        if not any(e):
            return 24 * (i + 1) if i else None
        if e[0] > 0xffff or e[4] > 0x80 or not 0x401000 <= e[5] < 0x7c0000:
            return None
    return None


STRS = {}   # roc_str_<addr> -> NUL-terminated bytes; callers add them as data items (stubs.obj / quicktest)
_REG_CACHE = []


def _REGN():   # identity registry, loaded once
    if not _REG_CACHE:
        _REG_CACHE.append(json.load(open(ROOT / 'work/2008-06/identity-registry.json')))
    return _REG_CACHE[0]


def _string_at(p):
    nm = 'roc_str_%08x' % p
    if nm in STRS:
        return True
    s = _string_bytes(p)
    if s is None:
        return False
    STRS[nm] = s
    return True


@lru_cache(maxsize=None)   # pure in the original image and the registry; _string_at keeps the STRS side effect
def _string_bytes(p):
    o = p - 0x400000
    if not (0 <= o < len(_IMG)):
        return None
    end = _IMG.find(b'\0', o, o + 1024)
    s = _IMG[o:end] if end > o else b''
    if len(s) < 1 or not all(32 <= c < 127 or c in (9, 10, 13) for c in s):
        return None
    # a vtable / pointer table whose first slot's bytes happen to be printable is NOT a string: Creator vtable 0x838aac
    # starts with 0x005c3370 = "p3\" + NUL -> its copy became roc_str_00838aac and every virtual call jumped to the
    # ORIGINAL address 0x5c3370 (Insert Object crash). Registry-named non-literals and code-address first words are out.
    _rn = (_REGN().get('%08x' % p) or {}).get('name') or ''
    if _rn and not _rn.startswith('??_C@'):
        return None
    if 0x401000 <= int.from_bytes(_IMG[o:o + 4], 'little') < 0x7c0000:
        return None
    return bytes(s) + b'\0'


def orig_bytes(va, n):
    """n initial bytes at va in the original 2008-06 exe (zeros past the raw data, i.e. .bss)."""
    import pefile
    from roc import clients
    global _PE, _IMG
    if '_PE' not in globals():
        _PE = pefile.PE(data=clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes(), fast_load=True)
        _IMG = bytes(_PE.get_memory_mapped_image())   # once: rebuilding the image per dat_ stub cost minutes
    img = _IMG
    o = va - _PE.OPTIONAL_HEADER.ImageBase
    b = bytes(img[o:o + n]) if 0 <= o < len(img) else b''
    b = bytearray(b + bytes(n - len(b)))
    # Printable string tails can numerically resemble image pointers ("ipt\0" in "LocalScript").
    strings = [(m.start(), m.end()) for m in re.finditer(rb'[\x20-\x7e]{9,}\x00', b)]
    for k in range(0, n - 3, 4):   # pointers into the original image are meaningless in this link: zero them
        if 0x401000 <= int.from_bytes(b[k:k + 4], 'little') < 0x9a0000:
            if any(start <= k and k + 4 <= end for start, end in strings) and not _is_reloc(va + k):
                continue
            b[k:k + 4] = bytes(4)
    return bytes(b)


def main():
    log = ((OUT / 'discover.log') if (OUT / 'discover.log').exists() else (OUT / 'link.log')).read_text(errors='replace')
    if (OUT / 'extra_unresolved.txt').exists():   # symbols only the final link reported (boot.py second pass)
        log += ''.join('x.obj : error LNK2001: unresolved external symbol %s' % u + chr(10) for u in (OUT / 'extra_unresolved.txt').read_text().split())
    from donorfree_link_parse import parse_unresolved
    symbols = parse_unresolved(log)
    aliased = set()
    for alias_name in ('aliases.txt', 'aliases_auto.txt', 'aliases_renamed.txt', 'aliases_twins.txt', 'aliases_qualname.txt', 'aliases_draftimp.txt'):
        alias_file = HERE / alias_name
        if alias_file.exists():
            aliased |= {l.split('=')[0].strip() for l in alias_file.read_text().splitlines() if '=' in l and not l.startswith('#')}
    symbols = [s for s in symbols if s not in aliased]
    try:   # symbols the last link showed defined elsewhere too: a plain stub would shadow the real COMDAT definition
        _ex = set(l.strip() for l in (OUT / 'stub_exclude.txt').read_text().splitlines() if l.strip())
        symbols = [s for s in symbols if s not in _ex]
    except OSError:
        pass
    import re as _re
    longs = [s for s in symbols if len(s) >= 240 or not _re.fullmatch(r'[A-Za-z0-9_@?$]+', s)]   # MASM identifier limit 247: these go through /alternatename to shared stubs
    _ls = set(longs)
    symbols = [s for s in symbols if s not in _ls]
    import re as _re
    funcs = [s for s in symbols if _re.match(r'^func_[0-9a-f]{8}$', s) or (s.endswith('Z') and not s.startswith('??_R')) or _re.match(r'^@[A-Za-z]\w*@\d+$', s) or _re.match(r'^_[A-Za-z]\w*(@\d+)?$', s) and not _re.match(r'^_(CLSID|IID|GUID|LIBID|DIID)_', s) and not s.startswith('__af') and not _re.match(r'^_(g|data|gl|s|k)_', s)]   # _g_* etc. are draft globals (data), not functions   # function mangling ends with the Z of its parameter list
    _fs = set(funcs)
    data = [s for s in symbols if s not in _fs]
    ret_n = exe_ret_bytes()
    ret_n.update(RET_BYTES)
    _cached = set(json.loads((HERE / 'link/undname_cache.json').read_text())) if (HERE / 'link/undname_cache.json').exists() else set()
    prefetch_demangle([x for x in funcs if x not in ret_n and x not in _cached])
    for sym in funcs:
        mf = _re.match(r'^@\w+@(\d+)$', sym)
        if mf and sym not in ret_n:
            ret_n[sym] = max(int(mf.group(1)) - 8, 0)   # fastcall: ecx/edx in registers, callee pops the rest
            continue
        mfa = _re.match(r'^func_([0-9a-f]{8})$', sym)
        if mfa and sym not in ret_n:
            ret_n[sym] = addr_ret_bytes(int(mfa.group(1), 16))   # unnamed: the original's own ret N
            continue
        if sym not in ret_n:
            v = signature_ret_bytes(sym)
            if v: ret_n[sym] = v
    lret = exe_ret_bytes()
    long_alias, shared = [], set()
    for s_ in longs:
        if s_.endswith('Z') and not s_.startswith('??_R'):
            n_ = lret.get(s_) or signature_ret_bytes(s_) or 0
            long_alias.append('%s=_roc_stub_ret%d' % (s_, n_)); shared.add(n_)
        else:
            long_alias.append('%s=_roc_stub_data' % s_)
    (HERE / 'aliases_long.txt').write_text('# generated by make_stubs.py (names too long for MASM)' + chr(10) + chr(10).join(long_alias) + chr(10))
    lines = ['.386', '.model flat', 'option casemap:none', '_TEXT SEGMENT']
    for n_ in sorted(shared):
        lines += ['PUBLIC _roc_stub_ret%d' % n_, '_roc_stub_ret%d PROC' % n_, '    xor eax, eax', ('    ret %d' % n_) if n_ else '    ret', '_roc_stub_ret%d ENDP' % n_]
    for s in funcs:
        lines += ['PUBLIC %s' % s, '%s PROC' % s, '    mov eax, %d' % (1 if s.startswith('?hasStringValue@?$EnumPropDescriptor') else 0), ('    ret %d' % ret_n[s]) if ret_n.get(s) else '    ret', '%s ENDP' % s]
    lines += ['_TEXT ENDS', '_DATA SEGMENT']
    for s in data:
        mdat = _re.match(r'^dat_([0-9a-f]{8})$', s)
        if mdat and not os.environ.get('ROC_DAT_ZERO'):   # placeholder global from rename.py: start from the original exe's initial bytes (zero for .bss)
            lines += ['PUBLIC %s' % s, '%s LABEL BYTE' % s] + ['    DB ' + ','.join('0%02xh' % b for b in orig_bytes(int(mdat.group(1), 16), 256)[k:k + 32]) for k in range(0, 256, 32)] + ['    DB 3840 DUP (0)']
        else:
            lines += ['PUBLIC %s' % s, '%s DB 4096 DUP (0)' % s]
    lines += ['PUBLIC _roc_stub_data', '_roc_stub_data DB 4096 DUP (0)', '_DATA ENDS', 'END', '']
    asm = OUT / 'stubs.asm'
    asm.write_text('\n'.join(lines))   # kept for reading; the object is written directly (MASM took ~70 s)
    if os.environ.get('ROC_STUBS_MASM'):
        tc = rebuild.toolchain(21022)
        code, text = rebuild.run(tc, str(rebuild._ml()), ['/nologo', '/c', '/coff', '/Fo' + str(OUT / 'stubs.obj'), str(asm)], OUT)
    else:
        import coffstub
        fl = [('_roc_stub_ret%d' % n_, 0, n_) for n_ in sorted(shared)]
        fl += [(s, _sret_body(s) or (1 if s.startswith('?hasStringValue@?$EnumPropDescriptor') else 0), ret_n.get(s) or 0) for s in funcs]
        dl = []
        # dat_<addr> placeholders keep the ORIGINAL relative layout: neighbouring globals (ATL's thunkHeap/allocateThunk at
        # 0097f308/0097f310, arrays and structs spanning several placeholders) are one block, initialised from the original
        # bytes with function pointers relocated. Separate 4 KB blocks made code that sets one and reads its neighbour see 0.
        dats = sorted((int(m.group(1), 16), s) for s in data for m in [_re.match(r'^dat_([0-9a-f]{8})$', s)] if m)
        clusters, cur = [], []
        for a, s in dats:
            if cur and a - cur[-1][0] > 0x1000:
                clusters.append(cur); cur = []
            cur.append((a, s))
        if cur:
            clusters.append(cur)
        for cl in clusters:
            lo = cl[0][0]
            size = cl[-1][0] - lo + 0x100
            init = orig_bytes(lo, size) if not os.environ.get('ROC_DAT_ZERO') else b''
            dl.append(('roc_datblk_%08x' % lo, init, size + 0xF00, data_relocs(lo, size), [(s, a - lo) for a, s in cl]))
        for s in data:
            if not _re.match(r'^dat_([0-9a-f]{8})$', s):
                dl.append((s, b'', 4096))
        dl.append(('_roc_stub_data', b'', 4096))
        dl += [(s_, b_, len(b_) + 3 & ~3) for s_, b_ in sorted(STRS.items())]
        coffstub.write(str(OUT / 'stubs.obj'), fl, dl)
        code, text = 0, 'coffstub'
    print('functions', len(funcs), 'data', len(data), 'ml exit', code, text[-300:])
    (OUT / 'stubs.json').write_text(json.dumps({'functions': funcs, 'data': data}))
    sys.exit(code)


if __name__ == '__main__':
    main()

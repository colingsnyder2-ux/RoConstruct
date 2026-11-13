"""Stack-correct zero stubs: xor eax,eax; ret N (N from the undecorated __thiscall/__stdcall signature)."""
import ctypes, re, struct
_dbg = ctypes.WinDLL('dbghelp')


def argbytes(n):
    buf = ctypes.create_string_buffer(4096)
    if not _dbg.UnDecorateSymbolName(n.encode(), buf, 4096, 0):
        return 0
    sig = buf.value.decode('latin-1')
    m = re.search(r'__(thiscall|stdcall|fastcall)\s', sig)
    if not m or '__cdecl' in sig[:m.start() + 12]:
        return 0
    start = sig.find('(', m.end())
    depth = 0
    for k in range(start, len(sig)):
        depth += sig[k] == '('
        depth -= sig[k] == ')'
        if depth == 0:
            end = k
            break
    else:
        return 0
    params = sig[start + 1:end].strip()
    if params in ('', 'void'):
        return 0
    parts, d, cur = [], 0, ''
    for ch in params:
        d += ch in '(<['
        d -= ch in ')>]'
        if ch == ',' and d == 0:
            parts.append(cur.strip())
            cur = ''
        else:
            cur += ch
    parts.append(cur.strip())
    return sum(8 if t in ('double', '__int64', 'unsigned __int64') else 4 for t in parts)


def stubcode(n):
    k = argbytes(n)
    return b'\x31\xc0' + (b'\xc2' + struct.pack('<H', k) if k else b'\xc3')

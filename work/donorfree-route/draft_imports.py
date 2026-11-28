"""python draft_imports.py: drafts stand in for import slots with invented function-pointer variables
(AutoRecover_004f0920: `extern DestroyStringFunction destroyString; destroyString(this)` where the original calls
[0x802468] = MSVCP90 std::string destructor). Nothing defines the variable, so it was zero stub data -> call 0.
For each draft (AutoRecover_<addr>) in the link: its undefined pointer-to-function DATA symbols (`@@3P6`) are paired with
the distinct import slots the ORIGINAL function calls/jumps through, in first-use order, when the counts agree.
Writes aliases_draftimp.txt (variable=__imp_<symbol>). Seconds."""
import json, os, re, struct, sys
from pathlib import Path
import capstone
H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import native_asm, rebuild
import pefile
img = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
starts = sorted(int(a, 16) for a in json.load(open(ROOT / 'work/native-client/layout/function-files.json')))
import bisect
try:
    imp = json.loads((H / 'renamed/imp_cache.json').read_text())
except Exception:
    imp = {}


def slots(addr):
    """distinct IAT labels used by call/jmp [mem] in the original function, first-use order"""
    end = starts[bisect.bisect_right(starts, addr)] if bisect.bisect_right(starts, addr) < len(starts) else addr + 0x400
    out = []
    for i in md.disasm(bytes(img[addr - 0x400000:min(end, addr + 0x2000) - 0x400000]), addr):
        m = re.match(r'dword ptr \[(0x[0-9a-f]+)\]$', i.op_str)
        if i.mnemonic in ('call', 'jmp') and m:
            lab = (native_asm.label('2008-06', int(m.group(1), 16)) or '').split(' ')[0]
            if '!' in lab and lab not in out:
                out.append(lab)
    return out


def imp_name(lab):
    dll, n = lab.split('!', 1)
    if n.startswith('?'):
        return '__imp_' + n
    return imp.get(n) or '__imp__' + n


lines, n = [], 0
for l in (H / 'link/donorfree.rsp').read_text().splitlines():
    p = l.strip().strip('"')
    if not p.lower().endswith('candidate.obj'):
        continue
    try:
        src = json.load(open(os.path.join(os.path.dirname(p), 'receipt.json'))).get('source', '')
    except Exception:
        continue
    m = re.search(r'AutoRecover_([0-9a-f]{8})\.cpp$', src)
    if not m or not os.path.exists(p):
        continue
    data = Path(p).read_bytes()
    # undefined pointer-to-function variables, in first-reference order of the symbol table
    vars_ = [s for s, d in rebuild.coff_externals(data).items() if not d and re.search(r'@@3P6|@@3Q6', s)]
    if not vars_:
        continue
    sl = slots(int(m.group(1), 16))
    if len(sl) == len(vars_) == 1 or (len(sl) == len(vars_) and len(sl) > 1 and False):   # ponytail: unique pairing only
        lines.append('%s=%s' % (vars_[0], imp_name(sl[0])))
        n += 1
print('%d draft import-pointer variables bound to the original import slot' % n)

# Direct calls: a draft calls invented helpers (?raise@Signal@@QAEXUHeartbeat@@@Z, ?find@Registry@@..) that only stubs
# satisfy, with the wrong stack cleanup (AutoRecover_00557150 unbalanced the run loop's stack). Pair the draft function's
# REL32 call relocations, in code order, with the ORIGINAL function's E8 call targets; when the counts agree, every
# callee the link does not define is aliased to func_<original target> (exact, native or a stub with the right ret N).
try:
    defined = set(json.load(open(H / 'renamed/defined.json')))
except Exception:
    defined = set()


def coff_calls(data, want):
    """REL32 relocation targets (code order) inside the function symbol `want` (or the largest .text function)"""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = symptr + nsym * 18
    syms, i = {}, 0
    while i < nsym:
        raw, val, sec, typ, cls, naux = struct.unpack_from('<8sIHHBB', data, symptr + 18 * i)
        sec = sec - 0x10000 if sec >= 0xFFFE else sec   # unsigned section number; -1 abs / -2 debug stay special
        nm = (data[strtab + struct.unpack_from('<I', raw, 4)[0]:data.index(b'\0', strtab + struct.unpack_from('<I', raw, 4)[0])]
              if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0')).decode('latin-1')
        syms[i] = (nm, sec, val, typ)
        i += 1 + naux
    fn = [s for s in syms.values() if s[1] > 0 and s[3] == 0x20 and want(s[0])]
    if not fn:
        return None
    _, sec, val, _ = fn[0]
    _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = struct.unpack_from('<8sIIIIIIHHI', data, 20 + optsz + 40 * (sec - 1))
    out = []
    for k in range(nrel):
        off, idx, typ = struct.unpack_from('<IIH', data, relptr + 10 * k)
        if typ == 0x14 and off >= val and off > 0 and data[rawptr + off - 1] == 0xe8:   # REL32 of a `call rel32`
            out.append((off, syms[idx][0]))
    return [n_ for _, n_ in sorted(out)]


def orig_calls(addr):
    end = starts[bisect.bisect_right(starts, addr)] if bisect.bisect_right(starts, addr) < len(starts) else addr + 0x400
    return [int(i.op_str, 16) for i in md.disasm(bytes(img[addr - 0x400000:min(end, addr + 0x2000) - 0x400000]), addr)
            if i.mnemonic == 'call' and i.op_str.startswith('0x')]


nc = 0
for l in (H / 'link/donorfree.rsp').read_text().splitlines():
    p = l.strip().strip('"')
    if not p.lower().endswith('candidate.obj'):
        continue
    try:
        src = json.load(open(os.path.join(os.path.dirname(p), 'receipt.json'))).get('source', '')
    except Exception:
        continue
    m = re.search(r'AutoRecover_([0-9a-f]{8})\.cpp$', src)
    if not m or not os.path.exists(p):
        continue
    a = m.group(1)
    data = Path(p).read_bytes()
    dc = coff_calls(data, lambda s: a in s) or None
    if not dc:
        continue
    oc = orig_calls(int(a, 16))
    if len(oc) != len(dc):
        continue
    for name, t in zip(dc, oc):
        if name not in defined and not name.startswith(('func_', '__imp_')) and name != 'func_%08x' % t:
            lines.append('%s=func_%08x' % (name, t))
            nc += 1
_tg = {}
for l_ in set(lines):
    k_, v_ = l_.split('=', 1)
    _tg.setdefault(k_, set()).add(v_)
lines = ['%s=%s' % (k_, next(iter(v_))) for k_, v_ in _tg.items() if len(v_) == 1]   # one name, several targets: ambiguous
(H / 'aliases_draftimp.txt').write_text('# generated by draft_imports.py\n' + '\n'.join(sorted(lines)) + '\n')
print('%d undefined draft callees bound to the original call target' % nc)

"""python callfix_validate.py: prune auto/callfix_plan.json (grow-only) to renames the ORIGINAL confirms. A rename
S -> func_T in converted object X is dropped only when, in an instruction-aligned prefix of X's original body and ours,
some call that ours makes to func_T is also a call to T (or to its jmp thunk) in the original. The old byte scan
misaligned and kept junk (numChildren -> operator new; ClassDescriptor ctor -> operator new: static init crash)."""
import json, re, struct
from pathlib import Path
import capstone, pefile
H = Path(__file__).parent
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
q = pefile.PE(str(H / 'run/RobloxQT.exe'), fast_load=True).get_memory_mapped_image()
o = pefile.PE(str(H.parents[1] / 'clients/2008-06/Roblox.exe'), fast_load=True).get_memory_mapped_image()
B = 0x400000
RR = json.loads((H / 'renamed/rename.json').read_text())
names, main = {}, {}
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:'):
        try:
            v = int(p[2], 16)
        except ValueError:
            continue
        names.setdefault(v, set()).add(p[1])
        m = re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*([0-9a-f]{8})\.obj', p[-1])
        if m and (p[1] == 'func_' + m.group(1) or p[1] == (RR.get(m.group(1)) or {}).get('symbol')):
            main.setdefault(m.group(1), v)   # the main function may carry its rename symbol (TranslucentVerb ctor), not func_<A>
plan = json.loads((H / 'auto/callfix_plan.json').read_text())
keep, drop = {}, 0
for ob, ren in plan.items():
    X = ob[:8]
    A = main.get(X)
    if A is None:
        keep[ob] = ren; continue   # not checkable now: keep
    x = int(X, 16)
    oi = list(md.disasm(bytes(o[x - B:x - B + 0x1000]), x))
    qi = list(md.disasm(bytes(q[A - B:A - B + 0x1000]), A))
    ok_targets, bad_targets = set(), set()
    for a_, b_ in zip(oi, qi):
        if a_.address - x != b_.address - A or a_.mnemonic != b_.mnemonic:
            break
        if a_.mnemonic == 'call' and a_.op_str.startswith('0x') and b_.op_str.startswith('0x'):
            to, tq = int(a_.op_str, 16), int(b_.op_str, 16)
            for n in names.get(tq, ()):
                m = re.fullmatch(r'func_([0-9a-f]{8})', n)
                if m:
                    T = int(m.group(1), 16)
                    fo = to + 5 + struct.unpack_from('<i', o, to - B + 1)[0] if o[to - B] == 0xe9 else to
                    if T in (to, fo):
                        ok_targets.add(n)
                    else:
                        bad_targets.add(n)   # aligned call: ours reaches func_T, the original calls something else
        if a_.mnemonic in ('ret', 'int3'):
            break
    k = {s: t for s, t in ren.items() if not (t in bad_targets and t not in ok_targets)}   # drop only on a PROVEN contradiction (unconfirmable renames stay: tss::init's mutex::do_lock fix was lost)
    drop += len(ren) - len(k)
    if k:
        keep[ob] = k
# per-SITE rule: every E8 call in X's own body that relocates to S must call T in the original. The aligned-prefix
# rule kept begin/end@named_slot_map -> func_004908a0 in signal1::operator() 006390a0 because func_004908a0 (the
# slot_call_iterator ctor) is also called there legitimately: propertyChanged iterated garbage iterators.
import collections, sys as _sys
_src = (H / 'codematch.py').read_text(encoding='latin-1')
exec(compile(_src[_src.index('def relsyms'):_src.index('def orig_names')], 'relsyms', 'exec'))
for ob in list(keep):
    X = ob[:8]; x = int(X, 16)
    try:
        rs = relsyms((H / 'renamed/obj' / (X + '.obj')).read_bytes())
    except (OSError, ValueError):
        continue
    body = rs.get('func_' + X) or rs.get((RR.get(X) or {}).get('symbol') or '') or {}
    k2 = {}
    for s_, t_ in keep[ob].items():
        m_ = re.fullmatch(r'func_([0-9a-f]{8})', t_)
        sites = [off for off, s2 in body.items() if s2 == s_ and off >= 1 and o[x - B + off - 1] == 0xe8]
        if m_ and sites:
            T = int(m_.group(1), 16); bad = False
            for off in sites:
                to = (x + off + 4 + struct.unpack_from('<i', o, x - B + off)[0]) & 0xffffffff
                fo = to + 5 + struct.unpack_from('<i', o, to - B + 1)[0] if 0 <= to - B < len(o) and o[to - B] == 0xe9 else to
                bad |= T not in (to, fo)
            if bad:
                drop += 1; continue
        k2[s_] = t_
    keep[ob] = k2
# semantic rule: S defined by NATIVE code and the registry names func_T as a different real function -> the old byte
# scan paired unrelated calls (numChildren -> operator new); registry-misnamed renames (do_lock) and analog names stay
reg = json.load(open(H.parents[0] / '2008-06/identity-registry.json'))
native = set()
for l in open(H / 'linkexp/qt.map', errors='replace'):
    p = l.split()
    if len(p) >= 4 and p[0].startswith('0001:') and 'stubs' not in p[-1] and ':' not in p[-1]             and not re.fullmatch(r'(?:(?:ca|cf|dr|nx|ni)_)*[0-9a-f]{8}\.obj', p[-1]):
        native.add(p[1])
for ob in list(keep):
    k2 = {}
    for s_, t_ in keep[ob].items():
        m_ = re.fullmatch(r'func_([0-9a-f]{8})', t_)
        rn = ((reg.get(m_.group(1)) or {}).get('name') or '') if m_ else ''
        if (s_.startswith('??0') and t_ == 'func_006a0920') or (m_ and s_ in native and rn.startswith('?') and rn != s_
                                                               and s_.split('@')[0] != rn.split('@')[0]):
            drop += 1; continue
        k2[s_] = t_
    keep[ob] = k2
keep = {k_: v_ for k_, v_ in keep.items() if v_}
(H / 'auto/callfix_plan.json').write_text(json.dumps(keep, indent=0))
print('callfix_validate: plan objects %d -> %d, renames dropped %d' % (len(plan), len(keep), drop))

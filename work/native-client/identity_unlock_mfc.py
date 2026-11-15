"""Route 1b: MFC IMPLEMENT_DYNAMIC/DYNCREATE/SERIAL statics.

An initializer 'call T; push eax; call AfxClassInit' is the dynamic initializer of the
file-scope `AFX_CLASSINIT _init_X(RUNTIME_CLASS(X))` (afx.h), and T is
`static CRuntimeClass* PASCAL X::GetThisClass()` = 'mov eax, offset classX; ret'.
X comes from CRuntimeClass::m_lpszClassName (first field of classX) and must have an
RTTI type descriptor ??_R0?AVX@@@8 in the registry.  Any other unnamed
'mov eax, offset classX; ret' body with no GetThisClass name yet is X::GetThisClass too
(identical-code folding may also cover _GetBaseClass/GetRuntimeClass of other classes).
Output: work/native-client/identity-unlock-mfc.json
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from identity_unlock_common import ROOT, REG, BASE, IMG, CODE_STARTS, insns, refs, u32, unnamed  # noqa: E402

OUT = ROOT / 'work/native-client/identity-unlock-mfc.json'
AFXCLASSINIT = next(int(a, 16) for a, v in REG.items() if v['name'] == '?AfxClassInit@@YGXPAUCRuntimeClass@@@Z')
RTTI = {v['name'] for v in REG.values() if v['kind'] == 'rtti'}


def cstr(va):
    o = va - BASE
    if not 0 <= o < len(IMG):
        return None
    e = IMG.find(b'\0', o, o + 128)
    s = IMG[o:e].decode('latin1') if e > o else ''
    return s if s.isidentifier() else None


def runtime_class(va):
    """'mov eax, imm; ret' with imm a CRuntimeClass -> class name."""
    ii = insns(va)[:2]
    if len(ii) == 2 and ii[0].mnemonic == 'mov' and ii[0].op_str.startswith('eax, 0x') and ii[1].mnemonic == 'ret':
        rc = refs(ii[0])[0]
        if 0x900000 <= rc < 0xa00000:
            name = cstr(u32(rc))
            if name and '??_R0?AV%s@@@8' % name in RTTI:
                return name, rc
    return None


def main():
    targets = set(unnamed())
    taken = {v['name'] for v in REG.values() if not v.get('placeholder')}
    out = {}

    def emit(a, sym, ev):
        if a in targets and a not in out and sym not in taken:
            out[a] = {'name': sym, 'owner_class': ev[0]['class_name'], 'signature': None, 'kind': 'code',
                      'name_source': 'identity-unlock-mfc', 'evidence': ev + [{'kind': 'decorated-signature', 'symbol': sym}]}
            taken.add(sym)

    for va in CODE_STARTS:
        if not 0x7ee000 <= va < 0x7fa000:
            continue
        ii = insns(va)[:4]
        if len(ii) >= 3 and ii[0].mnemonic == 'call' and ii[2].mnemonic == 'call' and refs(ii[2]) == [AFXCLASSINIT]:
            t = refs(ii[0])[0]
            rc = runtime_class(t)
            if rc:
                ev = [{'kind': 'afx-classinit', 'initializer': '%08x' % va, 'get_this_class': '%08x' % t,
                       'runtime_class': '%08x' % rc[1], 'class_name': rc[0]}]
                emit('%08x' % va, '??__E_init_%s@@YAXXZ' % rc[0], ev)
                emit('%08x' % t, '?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % rc[0], ev)
    for a in sorted(targets - set(out)):
        rc = runtime_class(int(a, 16))
        if rc:
            emit(a, '?GetThisClass@%s@@SGPAUCRuntimeClass@@XZ' % rc[0],
                 [{'kind': 'runtime-class-accessor', 'runtime_class': '%08x' % rc[1], 'class_name': rc[0]}])
    json.dump(out, open(OUT, 'w'), indent=1, sort_keys=True)
    print(len(out))


if __name__ == '__main__':
    main()

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 0046b740: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "CWorkspace.cpp"
// Batch 51: 0046b740 (5 B, registry placeholder func_0046b740) is CWorkspace::FinalRelease, which native CWorkspace.h
// declares ("INFERRED: 0046b740 tail-jumps to cleanup 0046b0e0") and no unit defined: the ATL FinalRelease hook a
// CComObject<CWorkspace> destructor calls (callers 00401ab0 / 00403410, both `call 0046b740`), a tail jump to
// CWorkspace::cleanup 0046b0e0. This replaces the earlier placeholder forwarder struct.
void CWorkspace::FinalRelease() { cleanup(); }

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 0046b740: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "CWorkspace.cpp"
// INFERRED: 0046b740 is a 5-byte jump to CWorkspace::cleanup; the forwarder name and owner are placeholders.
struct Thunk_0046b740 : CWorkspace { void sub_0046b740(); };
void Thunk_0046b740::sub_0046b740() { CWorkspace::cleanup(); }

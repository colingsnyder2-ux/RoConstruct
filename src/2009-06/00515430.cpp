// from server: 100% by auto
// roc 2009-06 00515430  unit: seg_00510000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00515430
//
// 00515430  8b442404             mov eax, dword ptr [esp + 4]
// 00515434  56                   push esi
// 00515435  50                   push eax
// 00515436  8bf1                 mov esi, ecx
// 00515438  e823a4f8ff           call 0x49f860
// 0051543d  8bc6                 mov eax, esi
// 0051543f  5e                   pop esi
// 00515440  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

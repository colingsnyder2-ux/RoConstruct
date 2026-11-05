// from server: 100% by auto
// roc 2008-06 0050e260  unit: seg_00500000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0050e260
//
// 0050e260  8b442404             mov eax, dword ptr [esp + 4]
// 0050e264  56                   push esi
// 0050e265  50                   push eax
// 0050e266  8bf1                 mov esi, ecx
// 0050e268  e843ffffff           call 0x50e1b0
// 0050e26d  8bc6                 mov eax, esi
// 0050e26f  5e                   pop esi
// 0050e270  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

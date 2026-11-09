// from server: 100% by auto
// roc 2010-06 00553a10  unit: seg_00550000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00553a10
//
// 00553a10  8b442404             mov eax, dword ptr [esp + 4]
// 00553a14  56                   push esi
// 00553a15  50                   push eax
// 00553a16  8bf1                 mov esi, ecx
// 00553a18  e843ffffff           call 0x553960
// 00553a1d  8bc6                 mov eax, esi
// 00553a1f  5e                   pop esi
// 00553a20  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

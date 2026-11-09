// from server: 100% by auto
// roc 2011-06 0053ddd0  unit: G3D::ReferenceCountedObject  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053ddd0
//
// 0053ddd0  8b442404             mov eax, dword ptr [esp + 4]
// 0053ddd4  56                   push esi
// 0053ddd5  50                   push eax
// 0053ddd6  8bf1                 mov esi, ecx
// 0053ddd8  e893feffff           call 0x53dc70
// 0053dddd  8bc6                 mov eax, esi
// 0053dddf  5e                   pop esi
// 0053dde0  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

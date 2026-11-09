// from server: 100% by auto
// roc 2012-06 00629d20  unit: G3D::ReferenceCountedObject  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00629d20
//
// 00629d20  8b442404             mov eax, dword ptr [esp + 4]
// 00629d24  56                   push esi
// 00629d25  50                   push eax
// 00629d26  8bf1                 mov esi, ecx
// 00629d28  e893feffff           call 0x629bc0
// 00629d2d  8bc6                 mov eax, esi
// 00629d2f  5e                   pop esi
// 00629d30  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

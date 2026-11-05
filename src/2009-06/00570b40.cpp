// from server: 100% by auto
// roc 2009-06 00570b40  unit: G3D::Log  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00570b40
//
// 00570b40  8b442404             mov eax, dword ptr [esp + 4]
// 00570b44  56                   push esi
// 00570b45  50                   push eax
// 00570b46  8bf1                 mov esi, ecx
// 00570b48  e843ffffff           call 0x570a90
// 00570b4d  8bc6                 mov eax, esi
// 00570b4f  5e                   pop esi
// 00570b50  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

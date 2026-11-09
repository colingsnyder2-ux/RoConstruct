// from server: 100% by auto
// roc 2008-06 004dc4e0  unit: RBX::ViewNew::ViewG3D  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc4e0
//
// 004dc4e0  8b442404             mov eax, dword ptr [esp + 4]
// 004dc4e4  56                   push esi
// 004dc4e5  50                   push eax
// 004dc4e6  8bf1                 mov esi, ecx
// 004dc4e8  e8b3ca0b00           call 0x598fa0
// 004dc4ed  8bc6                 mov eax, esi
// 004dc4ef  5e                   pop esi
// 004dc4f0  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2011-06 007e5340  unit: RBX::MoveResizeJoinTool  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e5340
//
// 007e5340  8b442404             mov eax, dword ptr [esp + 4]
// 007e5344  56                   push esi
// 007e5345  50                   push eax
// 007e5346  8bf1                 mov esi, ecx
// 007e5348  e8736cf7ff           call 0x75bfc0
// 007e534d  8bc6                 mov eax, esi
// 007e534f  5e                   pop esi
// 007e5350  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

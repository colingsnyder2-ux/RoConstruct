// from server: 100% by auto
// roc 2012-06 0094bc60  unit: RBX::MoveResizeJoinTool  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0094bc60
//
// 0094bc60  8b442404             mov eax, dword ptr [esp + 4]
// 0094bc64  56                   push esi
// 0094bc65  50                   push eax
// 0094bc66  8bf1                 mov esi, ecx
// 0094bc68  e8e3b2f4ff           call 0x896f50
// 0094bc6d  8bc6                 mov eax, esi
// 0094bc6f  5e                   pop esi
// 0094bc70  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;

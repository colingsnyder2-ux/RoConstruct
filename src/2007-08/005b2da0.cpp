// from server: 100% by auto
// roc 2007-08 005b2da0  unit: RBX::JointsService  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b2da0
//
// 005b2da0  8b442408             mov eax, dword ptr [esp + 8]
// 005b2da4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b2da8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b2dac  2bc1                 sub eax, ecx
// 005b2dae  c1f802               sar eax, 2
// 005b2db1  8d048500000000       lea eax, [eax*4]
// 005b2db8  56                   push esi
// 005b2db9  8d3410               lea esi, [eax + edx]
// 005b2dbc  740d                 je 0x5b2dcb
// 005b2dbe  50                   push eax
// 005b2dbf  51                   push ecx
// 005b2dc0  50                   push eax
// 005b2dc1  52                   push edx
// 005b2dc2  ff1548e77700         call dword ptr [0x77e748]
// 005b2dc8  83c410               add esp, 0x10
// 005b2dcb  8bc6                 mov eax, esi
// 005b2dcd  5e                   pop esi
// 005b2dce  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2011-06 007a1330  unit: RBX::Network::VPersistentDataStore::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a1330
//
// 007a1330  51                   push ecx
// 007a1331  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a1335  8b542410             mov edx, dword ptr [esp + 0x10]
// 007a1339  c6042400             mov byte ptr [esp], 0
// 007a133d  8b0424               mov eax, dword ptr [esp]
// 007a1340  50                   push eax
// 007a1341  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a1345  51                   push ecx
// 007a1346  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a134a  52                   push edx
// 007a134b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a134f  50                   push eax
// 007a1350  51                   push ecx
// 007a1351  52                   push edx
// 007a1352  e849f7ffff           call 0x7a0aa0
// 007a1357  83c41c               add esp, 0x1c
// 007a135a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

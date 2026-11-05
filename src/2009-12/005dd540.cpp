// from server: 100% by auto
// roc 2009-12 005dd540  unit: RBX::ImmediateMeshGenAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd540
//
// 005dd540  51                   push ecx
// 005dd541  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dd545  8b542410             mov edx, dword ptr [esp + 0x10]
// 005dd549  c6042400             mov byte ptr [esp], 0
// 005dd54d  8b0424               mov eax, dword ptr [esp]
// 005dd550  50                   push eax
// 005dd551  8b442414             mov eax, dword ptr [esp + 0x14]
// 005dd555  51                   push ecx
// 005dd556  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dd55a  52                   push edx
// 005dd55b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005dd55f  50                   push eax
// 005dd560  51                   push ecx
// 005dd561  52                   push edx
// 005dd562  e8d9feffff           call 0x5dd440
// 005dd567  83c41c               add esp, 0x1c
// 005dd56a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

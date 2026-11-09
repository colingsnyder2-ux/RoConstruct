// from server: 100% by auto
// roc 2008-06 0067cbd0  unit: Ogre::RbxEntity  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067cbd0
//
// 0067cbd0  51                   push ecx
// 0067cbd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067cbd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067cbd9  c6042400             mov byte ptr [esp], 0
// 0067cbdd  8b0424               mov eax, dword ptr [esp]
// 0067cbe0  50                   push eax
// 0067cbe1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0067cbe5  51                   push ecx
// 0067cbe6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067cbea  52                   push edx
// 0067cbeb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0067cbef  50                   push eax
// 0067cbf0  51                   push ecx
// 0067cbf1  52                   push edx
// 0067cbf2  e829fbffff           call 0x67c720
// 0067cbf7  83c41c               add esp, 0x1c
// 0067cbfa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

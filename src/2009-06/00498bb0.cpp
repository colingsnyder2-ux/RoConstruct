// from server: 100% by auto
// roc 2009-06 00498bb0  unit: Ogre::RbxArchiveFactory  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498bb0
//
// 00498bb0  51                   push ecx
// 00498bb1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00498bb5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00498bb9  c6042400             mov byte ptr [esp], 0
// 00498bbd  8b0424               mov eax, dword ptr [esp]
// 00498bc0  50                   push eax
// 00498bc1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00498bc5  51                   push ecx
// 00498bc6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00498bca  52                   push edx
// 00498bcb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00498bcf  50                   push eax
// 00498bd0  51                   push ecx
// 00498bd1  52                   push edx
// 00498bd2  e829f9ffff           call 0x498500
// 00498bd7  83c41c               add esp, 0x1c
// 00498bda  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

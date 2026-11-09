// from server: 100% by auto
// roc 2011-06 0093e540  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093e540
//
// 0093e540  51                   push ecx
// 0093e541  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0093e545  8b542410             mov edx, dword ptr [esp + 0x10]
// 0093e549  c6042400             mov byte ptr [esp], 0
// 0093e54d  8b0424               mov eax, dword ptr [esp]
// 0093e550  50                   push eax
// 0093e551  8b442414             mov eax, dword ptr [esp + 0x14]
// 0093e555  51                   push ecx
// 0093e556  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0093e55a  52                   push edx
// 0093e55b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0093e55f  50                   push eax
// 0093e560  51                   push ecx
// 0093e561  52                   push edx
// 0093e562  e809eeffff           call 0x93d370
// 0093e567  83c41c               add esp, 0x1c
// 0093e56a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

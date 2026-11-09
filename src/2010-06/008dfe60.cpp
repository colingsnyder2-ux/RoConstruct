// from server: 100% by auto
// roc 2010-06 008dfe60  unit: Ogre::RbxMaterialAdapter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dfe60
//
// 008dfe60  8b442408             mov eax, dword ptr [esp + 8]
// 008dfe64  8b542404             mov edx, dword ptr [esp + 4]
// 008dfe68  2bc2                 sub eax, edx
// 008dfe6a  56                   push esi
// 008dfe6b  c1f802               sar eax, 2
// 008dfe6e  57                   push edi
// 008dfe6f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008dfe73  8d0c8500000000       lea ecx, [eax*4]
// 008dfe7a  8d3439               lea esi, [ecx + edi]
// 008dfe7d  85c0                 test eax, eax
// 008dfe7f  760d                 jbe 0x8dfe8e
// 008dfe81  51                   push ecx
// 008dfe82  52                   push edx
// 008dfe83  51                   push ecx
// 008dfe84  57                   push edi
// 008dfe85  ff1580a89e00         call dword ptr [0x9ea880]
// 008dfe8b  83c410               add esp, 0x10
// 008dfe8e  5f                   pop edi
// 008dfe8f  8bc6                 mov eax, esi
// 008dfe91  5e                   pop esi
// 008dfe92  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

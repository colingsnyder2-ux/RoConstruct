// from server: 100% by auto
// roc 2010-06 008cdf60  unit: Ogre::RbxMeshLoader  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008cdf60
//
// 008cdf60  51                   push ecx
// 008cdf61  8b542410             mov edx, dword ptr [esp + 0x10]
// 008cdf65  56                   push esi
// 008cdf66  8b742410             mov esi, dword ptr [esp + 0x10]
// 008cdf6a  57                   push edi
// 008cdf6b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008cdf6f  c644240800           mov byte ptr [esp + 8], 0
// 008cdf74  8b442408             mov eax, dword ptr [esp + 8]
// 008cdf78  50                   push eax
// 008cdf79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008cdf7d  52                   push edx
// 008cdf7e  83c108               add ecx, 8
// 008cdf81  51                   push ecx
// 008cdf82  50                   push eax
// 008cdf83  56                   push esi
// 008cdf84  57                   push edi
// 008cdf85  e896f7ffff           call 0x8cd720
// 008cdf8a  8bc6                 mov eax, esi
// 008cdf8c  83c418               add esp, 0x18
// 008cdf8f  c1e005               shl eax, 5
// 008cdf92  03c7                 add eax, edi
// 008cdf94  5f                   pop edi
// 008cdf95  5e                   pop esi
// 008cdf96  59                   pop ecx
// 008cdf97  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;

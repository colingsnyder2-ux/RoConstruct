// from server: 100% by auto
// roc 2009-12 00679d50  unit: RBX::VInstance::?$FilteredSelection  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00679d50
//
// 00679d50  56                   push esi
// 00679d51  8bf1                 mov esi, ecx
// 00679d53  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00679d57  8b4610               mov eax, dword ptr [esi + 0x10]
// 00679d5a  8d5104               lea edx, [ecx + 4]
// 00679d5d  2bc2                 sub eax, edx
// 00679d5f  c1f802               sar eax, 2
// 00679d62  57                   push edi
// 00679d63  85c0                 test eax, eax
// 00679d65  7e15                 jle 0x679d7c
// 00679d67  03c0                 add eax, eax
// 00679d69  03c0                 add eax, eax
// 00679d6b  50                   push eax
// 00679d6c  52                   push edx
// 00679d6d  50                   push eax
// 00679d6e  51                   push ecx
// 00679d6f  ff15c0b79800         call dword ptr [0x98b7c0]
// 00679d75  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00679d79  83c410               add esp, 0x10
// 00679d7c  834610fc             add dword ptr [esi + 0x10], -4
// 00679d80  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00679d84  8b4610               mov eax, dword ptr [esi + 0x10]
// 00679d87  c70700000000         mov dword ptr [edi], 0
// 00679d8d  394e0c               cmp dword ptr [esi + 0xc], ecx
// 00679d90  7704                 ja 0x679d96
// 00679d92  3bc8                 cmp ecx, eax
// 00679d94  760a                 jbe 0x679da0
// 00679d96  ff1560b79800         call dword ptr [0x98b760]
// 00679d9c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00679da0  8b06                 mov eax, dword ptr [esi]
// 00679da2  8907                 mov dword ptr [edi], eax
// 00679da4  894f04               mov dword ptr [edi + 4], ecx
// 00679da7  8bc7                 mov eax, edi
// 00679da9  5f                   pop edi
// 00679daa  5e                   pop esi
// 00679dab  c20c00               ret 0xc
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2009-12 00697ef0  unit: RBX::ArrowTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00697ef0
//
// 00697ef0  83ec08               sub esp, 8
// 00697ef3  56                   push esi
// 00697ef4  8bf1                 mov esi, ecx
// 00697ef6  8b4618               mov eax, dword ptr [esi + 0x18]
// 00697ef9  8b0e                 mov ecx, dword ptr [esi]
// 00697efb  8b10                 mov edx, dword ptr [eax]
// 00697efd  50                   push eax
// 00697efe  51                   push ecx
// 00697eff  52                   push edx
// 00697f00  51                   push ecx
// 00697f01  8d442414             lea eax, [esp + 0x14]
// 00697f05  50                   push eax
// 00697f06  8bce                 mov ecx, esi
// 00697f08  e843c7d9ff           call 0x434650
// 00697f0d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00697f10  51                   push ecx
// 00697f11  e844b91500           call 0x7f385a
// 00697f16  83c404               add esp, 4
// 00697f19  33c0                 xor eax, eax
// 00697f1b  894618               mov dword ptr [esi + 0x18], eax
// 00697f1e  89461c               mov dword ptr [esi + 0x1c], eax
// 00697f21  5e                   pop esi
// 00697f22  83c408               add esp, 8
// 00697f25  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

// from server: 100% by auto
// roc 2008-06 005a1850  unit: RBX::ArrowTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a1850
//
// 005a1850  83ec08               sub esp, 8
// 005a1853  56                   push esi
// 005a1854  8bf1                 mov esi, ecx
// 005a1856  8b4618               mov eax, dword ptr [esi + 0x18]
// 005a1859  8b0e                 mov ecx, dword ptr [esi]
// 005a185b  8b10                 mov edx, dword ptr [eax]
// 005a185d  50                   push eax
// 005a185e  51                   push ecx
// 005a185f  52                   push edx
// 005a1860  51                   push ecx
// 005a1861  8d442414             lea eax, [esp + 0x14]
// 005a1865  50                   push eax
// 005a1866  8bce                 mov ecx, esi
// 005a1868  e8c3940a00           call 0x64ad30
// 005a186d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005a1870  51                   push ecx
// 005a1871  e804ee0f00           call 0x6a067a
// 005a1876  83c404               add esp, 4
// 005a1879  33c0                 xor eax, eax
// 005a187b  894618               mov dword ptr [esi + 0x18], eax
// 005a187e  89461c               mov dword ptr [esi + 0x1c], eax
// 005a1881  5e                   pop esi
// 005a1882  83c408               add esp, 8
// 005a1885  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

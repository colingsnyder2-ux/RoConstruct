// from server: 100% by auto
// roc 2010-06 006e8380  unit: RBX::VInstance::?$NonFactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e8380
//
// 006e8380  83ec08               sub esp, 8
// 006e8383  56                   push esi
// 006e8384  8bf1                 mov esi, ecx
// 006e8386  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e8389  8b0e                 mov ecx, dword ptr [esi]
// 006e838b  8b10                 mov edx, dword ptr [eax]
// 006e838d  50                   push eax
// 006e838e  51                   push ecx
// 006e838f  52                   push edx
// 006e8390  51                   push ecx
// 006e8391  8d442414             lea eax, [esp + 0x14]
// 006e8395  50                   push eax
// 006e8396  8bce                 mov ecx, esi
// 006e8398  e893d8d4ff           call 0x435c30
// 006e839d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e83a0  51                   push ecx
// 006e83a1  e8f4f50b00           call 0x7a799a
// 006e83a6  83c404               add esp, 4
// 006e83a9  33c0                 xor eax, eax
// 006e83ab  894618               mov dword ptr [esi + 0x18], eax
// 006e83ae  89461c               mov dword ptr [esi + 0x1c], eax
// 006e83b1  5e                   pop esi
// 006e83b2  83c408               add esp, 8
// 006e83b5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

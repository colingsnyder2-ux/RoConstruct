// from server: 100% by auto
// roc 2009-12 006f6e00  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6e00
//
// 006f6e00  83ec08               sub esp, 8
// 006f6e03  56                   push esi
// 006f6e04  8bf1                 mov esi, ecx
// 006f6e06  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6e09  8b0e                 mov ecx, dword ptr [esi]
// 006f6e0b  8b10                 mov edx, dword ptr [eax]
// 006f6e0d  50                   push eax
// 006f6e0e  51                   push ecx
// 006f6e0f  52                   push edx
// 006f6e10  51                   push ecx
// 006f6e11  8d442414             lea eax, [esp + 0x14]
// 006f6e15  50                   push eax
// 006f6e16  8bce                 mov ecx, esi
// 006f6e18  e803ffffff           call 0x6f6d20
// 006f6e1d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f6e20  51                   push ecx
// 006f6e21  e834ca0f00           call 0x7f385a
// 006f6e26  83c404               add esp, 4
// 006f6e29  33c0                 xor eax, eax
// 006f6e2b  894618               mov dword ptr [esi + 0x18], eax
// 006f6e2e  89461c               mov dword ptr [esi + 0x1c], eax
// 006f6e31  5e                   pop esi
// 006f6e32  83c408               add esp, 8
// 006f6e35  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

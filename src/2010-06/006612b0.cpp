// from server: 100% by auto
// roc 2010-06 006612b0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006612b0
//
// 006612b0  83ec08               sub esp, 8
// 006612b3  56                   push esi
// 006612b4  8bf1                 mov esi, ecx
// 006612b6  8b4618               mov eax, dword ptr [esi + 0x18]
// 006612b9  8b0e                 mov ecx, dword ptr [esi]
// 006612bb  8b10                 mov edx, dword ptr [eax]
// 006612bd  50                   push eax
// 006612be  51                   push ecx
// 006612bf  52                   push edx
// 006612c0  51                   push ecx
// 006612c1  8d442414             lea eax, [esp + 0x14]
// 006612c5  50                   push eax
// 006612c6  8bce                 mov ecx, esi
// 006612c8  e803ffffff           call 0x6611d0
// 006612cd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006612d0  51                   push ecx
// 006612d1  e8c4661400           call 0x7a799a
// 006612d6  83c404               add esp, 4
// 006612d9  33c0                 xor eax, eax
// 006612db  894618               mov dword ptr [esi + 0x18], eax
// 006612de  89461c               mov dword ptr [esi + 0x1c], eax
// 006612e1  5e                   pop esi
// 006612e2  83c408               add esp, 8
// 006612e5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

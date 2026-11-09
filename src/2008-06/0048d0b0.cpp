// from server: 100% by auto
// roc 2008-06 0048d0b0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d0b0
//
// 0048d0b0  83ec08               sub esp, 8
// 0048d0b3  56                   push esi
// 0048d0b4  8bf1                 mov esi, ecx
// 0048d0b6  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048d0b9  8b0e                 mov ecx, dword ptr [esi]
// 0048d0bb  8b10                 mov edx, dword ptr [eax]
// 0048d0bd  50                   push eax
// 0048d0be  51                   push ecx
// 0048d0bf  52                   push edx
// 0048d0c0  51                   push ecx
// 0048d0c1  8d442414             lea eax, [esp + 0x14]
// 0048d0c5  50                   push eax
// 0048d0c6  8bce                 mov ecx, esi
// 0048d0c8  e8e3682000           call 0x6939b0
// 0048d0cd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048d0d0  51                   push ecx
// 0048d0d1  e8a4352100           call 0x6a067a
// 0048d0d6  83c404               add esp, 4
// 0048d0d9  33c0                 xor eax, eax
// 0048d0db  894618               mov dword ptr [esi + 0x18], eax
// 0048d0de  89461c               mov dword ptr [esi + 0x1c], eax
// 0048d0e1  5e                   pop esi
// 0048d0e2  83c408               add esp, 8
// 0048d0e5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

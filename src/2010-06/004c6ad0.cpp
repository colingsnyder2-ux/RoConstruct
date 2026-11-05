// from server: 100% by auto
// roc 2010-06 004c6ad0  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c6ad0
//
// 004c6ad0  83ec08               sub esp, 8
// 004c6ad3  56                   push esi
// 004c6ad4  8bf1                 mov esi, ecx
// 004c6ad6  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c6ad9  8b0e                 mov ecx, dword ptr [esi]
// 004c6adb  8b10                 mov edx, dword ptr [eax]
// 004c6add  50                   push eax
// 004c6ade  51                   push ecx
// 004c6adf  52                   push edx
// 004c6ae0  51                   push ecx
// 004c6ae1  8d442414             lea eax, [esp + 0x14]
// 004c6ae5  50                   push eax
// 004c6ae6  8bce                 mov ecx, esi
// 004c6ae8  e803f1ffff           call 0x4c5bf0
// 004c6aed  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004c6af0  51                   push ecx
// 004c6af1  e8a40e2e00           call 0x7a799a
// 004c6af6  83c404               add esp, 4
// 004c6af9  33c0                 xor eax, eax
// 004c6afb  894618               mov dword ptr [esi + 0x18], eax
// 004c6afe  89461c               mov dword ptr [esi + 0x1c], eax
// 004c6b01  5e                   pop esi
// 004c6b02  83c408               add esp, 8
// 004c6b05  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

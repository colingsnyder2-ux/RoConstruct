// from server: 100% by auto
// roc 2009-06 0062cfc0  unit: RBX::ArrowTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062cfc0
//
// 0062cfc0  83ec08               sub esp, 8
// 0062cfc3  56                   push esi
// 0062cfc4  8bf1                 mov esi, ecx
// 0062cfc6  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cfc9  8b0e                 mov ecx, dword ptr [esi]
// 0062cfcb  8b10                 mov edx, dword ptr [eax]
// 0062cfcd  50                   push eax
// 0062cfce  51                   push ecx
// 0062cfcf  52                   push edx
// 0062cfd0  51                   push ecx
// 0062cfd1  8d442414             lea eax, [esp + 0x14]
// 0062cfd5  50                   push eax
// 0062cfd6  8bce                 mov ecx, esi
// 0062cfd8  e803ffffff           call 0x62cee0
// 0062cfdd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0062cfe0  51                   push ecx
// 0062cfe1  e84cba0e00           call 0x718a32
// 0062cfe6  83c404               add esp, 4
// 0062cfe9  33c0                 xor eax, eax
// 0062cfeb  894618               mov dword ptr [esi + 0x18], eax
// 0062cfee  89461c               mov dword ptr [esi + 0x1c], eax
// 0062cff1  5e                   pop esi
// 0062cff2  83c408               add esp, 8
// 0062cff5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

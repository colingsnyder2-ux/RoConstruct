// from server: 100% by auto
// roc 2009-12 006841e0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006841e0
//
// 006841e0  83ec08               sub esp, 8
// 006841e3  56                   push esi
// 006841e4  8bf1                 mov esi, ecx
// 006841e6  8b4618               mov eax, dword ptr [esi + 0x18]
// 006841e9  8b0e                 mov ecx, dword ptr [esi]
// 006841eb  8b10                 mov edx, dword ptr [eax]
// 006841ed  50                   push eax
// 006841ee  51                   push ecx
// 006841ef  52                   push edx
// 006841f0  51                   push ecx
// 006841f1  8d442414             lea eax, [esp + 0x14]
// 006841f5  50                   push eax
// 006841f6  8bce                 mov ecx, esi
// 006841f8  e883feffff           call 0x684080
// 006841fd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00684200  51                   push ecx
// 00684201  e854f61600           call 0x7f385a
// 00684206  83c404               add esp, 4
// 00684209  33c0                 xor eax, eax
// 0068420b  894618               mov dword ptr [esi + 0x18], eax
// 0068420e  89461c               mov dword ptr [esi + 0x1c], eax
// 00684211  5e                   pop esi
// 00684212  83c408               add esp, 8
// 00684215  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

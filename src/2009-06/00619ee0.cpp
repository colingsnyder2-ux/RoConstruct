// from server: 100% by auto
// roc 2009-06 00619ee0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619ee0
//
// 00619ee0  83ec08               sub esp, 8
// 00619ee3  56                   push esi
// 00619ee4  8bf1                 mov esi, ecx
// 00619ee6  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619ee9  8b0e                 mov ecx, dword ptr [esi]
// 00619eeb  8b10                 mov edx, dword ptr [eax]
// 00619eed  50                   push eax
// 00619eee  51                   push ecx
// 00619eef  52                   push edx
// 00619ef0  51                   push ecx
// 00619ef1  8d442414             lea eax, [esp + 0x14]
// 00619ef5  50                   push eax
// 00619ef6  8bce                 mov ecx, esi
// 00619ef8  e883feffff           call 0x619d80
// 00619efd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00619f00  51                   push ecx
// 00619f01  e82ceb0f00           call 0x718a32
// 00619f06  83c404               add esp, 4
// 00619f09  33c0                 xor eax, eax
// 00619f0b  894618               mov dword ptr [esi + 0x18], eax
// 00619f0e  89461c               mov dword ptr [esi + 0x1c], eax
// 00619f11  5e                   pop esi
// 00619f12  83c408               add esp, 8
// 00619f15  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

// from server: 100% by auto
// roc 2007-08 004b0070  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b0070
//
// 004b0070  83ec08               sub esp, 8
// 004b0073  56                   push esi
// 004b0074  8bf1                 mov esi, ecx
// 004b0076  8b4604               mov eax, dword ptr [esi + 4]
// 004b0079  8b08                 mov ecx, dword ptr [eax]
// 004b007b  50                   push eax
// 004b007c  56                   push esi
// 004b007d  51                   push ecx
// 004b007e  56                   push esi
// 004b007f  8d442414             lea eax, [esp + 0x14]
// 004b0083  50                   push eax
// 004b0084  8bce                 mov ecx, esi
// 004b0086  e8f5d3ffff           call 0x4ad480
// 004b008b  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b008e  51                   push ecx
// 004b008f  e8cefb1700           call 0x62fc62
// 004b0094  83c404               add esp, 4
// 004b0097  33c0                 xor eax, eax
// 004b0099  894604               mov dword ptr [esi + 4], eax
// 004b009c  894608               mov dword ptr [esi + 8], eax
// 004b009f  5e                   pop esi
// 004b00a0  83c408               add esp, 8
// 004b00a3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

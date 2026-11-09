// from server: 100% by auto
// roc 2009-06 006b88b0  unit: RBX::UniversalTool  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b88b0
//
// 006b88b0  6aff                 push -1
// 006b88b2  68485e8500           push 0x855e48
// 006b88b7  64a100000000         mov eax, dword ptr fs:[0]
// 006b88bd  50                   push eax
// 006b88be  64892500000000       mov dword ptr fs:[0], esp
// 006b88c5  83ec0c               sub esp, 0xc
// 006b88c8  56                   push esi
// 006b88c9  8bf1                 mov esi, ecx
// 006b88cb  89742404             mov dword ptr [esp + 4], esi
// 006b88cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006b88d2  8b0e                 mov ecx, dword ptr [esi]
// 006b88d4  8b10                 mov edx, dword ptr [eax]
// 006b88d6  50                   push eax
// 006b88d7  51                   push ecx
// 006b88d8  52                   push edx
// 006b88d9  51                   push ecx
// 006b88da  8d442418             lea eax, [esp + 0x18]
// 006b88de  50                   push eax
// 006b88df  8bce                 mov ecx, esi
// 006b88e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006b88e9  e8f245f7ff           call 0x62cee0
// 006b88ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006b88f1  51                   push ecx
// 006b88f2  e83b010600           call 0x718a32
// 006b88f7  8b16                 mov edx, dword ptr [esi]
// 006b88f9  52                   push edx
// 006b88fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006b8901  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006b8908  e825010600           call 0x718a32
// 006b890d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006b8911  83c408               add esp, 8
// 006b8914  5e                   pop esi
// 006b8915  64890d00000000       mov dword ptr fs:[0], ecx
// 006b891c  83c418               add esp, 0x18
// 006b891f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

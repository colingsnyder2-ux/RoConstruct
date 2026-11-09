// from server: 100% by auto
// roc 2008-06 00561180  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561180
//
// 00561180  6aff                 push -1
// 00561182  6828d97b00           push 0x7bd928
// 00561187  64a100000000         mov eax, dword ptr fs:[0]
// 0056118d  50                   push eax
// 0056118e  64892500000000       mov dword ptr fs:[0], esp
// 00561195  83ec0c               sub esp, 0xc
// 00561198  56                   push esi
// 00561199  8bf1                 mov esi, ecx
// 0056119b  89742404             mov dword ptr [esp + 4], esi
// 0056119f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005611a2  8b0e                 mov ecx, dword ptr [esi]
// 005611a4  8b10                 mov edx, dword ptr [eax]
// 005611a6  50                   push eax
// 005611a7  51                   push ecx
// 005611a8  52                   push edx
// 005611a9  51                   push ecx
// 005611aa  8d442418             lea eax, [esp + 0x18]
// 005611ae  50                   push eax
// 005611af  8bce                 mov ecx, esi
// 005611b1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005611b9  e8a2f7ffff           call 0x560960
// 005611be  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005611c1  51                   push ecx
// 005611c2  e8b3f41300           call 0x6a067a
// 005611c7  8b16                 mov edx, dword ptr [esi]
// 005611c9  52                   push edx
// 005611ca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005611d1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005611d8  e89df41300           call 0x6a067a
// 005611dd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005611e1  83c408               add esp, 8
// 005611e4  5e                   pop esi
// 005611e5  64890d00000000       mov dword ptr fs:[0], ecx
// 005611ec  83c418               add esp, 0x18
// 005611ef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

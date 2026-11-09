// from server: 100% by auto
// roc 2009-06 004f2470  unit: RBX::Network::Replicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f2470
//
// 004f2470  6aff                 push -1
// 004f2472  68485e8500           push 0x855e48
// 004f2477  64a100000000         mov eax, dword ptr fs:[0]
// 004f247d  50                   push eax
// 004f247e  64892500000000       mov dword ptr fs:[0], esp
// 004f2485  83ec0c               sub esp, 0xc
// 004f2488  56                   push esi
// 004f2489  8bf1                 mov esi, ecx
// 004f248b  89742404             mov dword ptr [esp + 4], esi
// 004f248f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f2492  8b0e                 mov ecx, dword ptr [esi]
// 004f2494  8b10                 mov edx, dword ptr [eax]
// 004f2496  50                   push eax
// 004f2497  51                   push ecx
// 004f2498  52                   push edx
// 004f2499  51                   push ecx
// 004f249a  8d442418             lea eax, [esp + 0x18]
// 004f249e  50                   push eax
// 004f249f  8bce                 mov ecx, esi
// 004f24a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004f24a9  e842f6ffff           call 0x4f1af0
// 004f24ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004f24b1  51                   push ecx
// 004f24b2  e87b652200           call 0x718a32
// 004f24b7  8b16                 mov edx, dword ptr [esi]
// 004f24b9  52                   push edx
// 004f24ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004f24c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004f24c8  e865652200           call 0x718a32
// 004f24cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004f24d1  83c408               add esp, 8
// 004f24d4  5e                   pop esi
// 004f24d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004f24dc  83c418               add esp, 0x18
// 004f24df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

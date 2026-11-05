// from server: 100% by auto
// roc 2010-06 0090a6b0  unit: Ogre::RbxCluster  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0090a6b0
//
// 0090a6b0  6aff                 push -1
// 0090a6b2  68b8d19b00           push 0x9bd1b8
// 0090a6b7  64a100000000         mov eax, dword ptr fs:[0]
// 0090a6bd  50                   push eax
// 0090a6be  64892500000000       mov dword ptr fs:[0], esp
// 0090a6c5  83ec0c               sub esp, 0xc
// 0090a6c8  56                   push esi
// 0090a6c9  8bf1                 mov esi, ecx
// 0090a6cb  89742404             mov dword ptr [esp + 4], esi
// 0090a6cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a6d2  8b0e                 mov ecx, dword ptr [esi]
// 0090a6d4  8b10                 mov edx, dword ptr [eax]
// 0090a6d6  50                   push eax
// 0090a6d7  51                   push ecx
// 0090a6d8  52                   push edx
// 0090a6d9  51                   push ecx
// 0090a6da  8d442418             lea eax, [esp + 0x18]
// 0090a6de  50                   push eax
// 0090a6df  8bce                 mov ecx, esi
// 0090a6e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0090a6e9  e812f9ffff           call 0x90a000
// 0090a6ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0090a6f1  51                   push ecx
// 0090a6f2  e8a3d2e9ff           call 0x7a799a
// 0090a6f7  8b16                 mov edx, dword ptr [esi]
// 0090a6f9  52                   push edx
// 0090a6fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0090a701  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0090a708  e88dd2e9ff           call 0x7a799a
// 0090a70d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0090a711  83c408               add esp, 8
// 0090a714  5e                   pop esi
// 0090a715  64890d00000000       mov dword ptr fs:[0], ecx
// 0090a71c  83c418               add esp, 0x18
// 0090a71f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;

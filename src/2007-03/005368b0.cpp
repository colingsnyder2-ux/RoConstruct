// from server: 100% by auto
// roc 2007-03 005368b0  unit: seg_00530000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005368b0
//
// 005368b0  6aff                 push -1
// 005368b2  68926f7500           push 0x756f92
// 005368b7  64a100000000         mov eax, dword ptr fs:[0]
// 005368bd  50                   push eax
// 005368be  64892500000000       mov dword ptr fs:[0], esp
// 005368c5  83ec44               sub esp, 0x44
// 005368c8  6890557900           push 0x795590
// 005368cd  8d4c2404             lea ecx, [esp + 4]
// 005368d1  ff1578e77700         call dword ptr [0x77e778]
// 005368d7  8d4c241c             lea ecx, [esp + 0x1c]
// 005368db  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005368e3  ff1560e97700         call dword ptr [0x77e960]
// 005368e9  8d0424               lea eax, [esp]
// 005368ec  50                   push eax
// 005368ed  8d4c242c             lea ecx, [esp + 0x2c]
// 005368f1  c644245001           mov byte ptr [esp + 0x50], 1
// 005368f6  c7442420383e7800     mov dword ptr [esp + 0x20], 0x783e38
// 005368fe  ff157ce77700         call dword ptr [0x77e77c]
// 00536904  68ccf38300           push 0x83f3cc
// 00536909  8d4c2420             lea ecx, [esp + 0x20]
// 0053690d  51                   push ecx
// 0053690e  c644245400           mov byte ptr [esp + 0x54], 0
// 00536913  c7442424503e7800     mov dword ptr [esp + 0x24], 0x783e50
// 0053691b  e80e870e00           call 0x61f02e
// standard library vector<char> (function ?_Xran@?$vector@DV?$allocator@D@std@@@std@@KAXXZ)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

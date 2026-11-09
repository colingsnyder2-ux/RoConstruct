// roc 2009-12 007c6400  unit: RBX::ChatOutput  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6400
//
// 007c6400  6aff                 push -1
// 007c6402  6812699500           push 0x956912
// 007c6407  64a100000000         mov eax, dword ptr fs:[0]
// 007c640d  50                   push eax
// 007c640e  64892500000000       mov dword ptr fs:[0], esp
// 007c6415  83ec44               sub esp, 0x44
// 007c6418  68501e9b00           push 0x9b1e50
// 007c641d  8d4c2404             lea ecx, [esp + 4]
// 007c6421  ff15f4b69800         call dword ptr [0x98b6f4]
// 007c6427  8d4c241c             lea ecx, [esp + 0x1c]
// 007c642b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 007c6433  ff1554b79800         call dword ptr [0x98b754]
// 007c6439  8d0424               lea eax, [esp]
// 007c643c  50                   push eax
// 007c643d  8d4c242c             lea ecx, [esp + 0x2c]
// 007c6441  c644245001           mov byte ptr [esp + 0x50], 1
// 007c6446  c744242084f49900     mov dword ptr [esp + 0x20], 0x99f484
// 007c644e  ff15f0b69800         call dword ptr [0x98b6f0]
// 007c6454  688cefa800           push 0xa8ef8c
// 007c6459  8d4c2420             lea ecx, [esp + 0x20]
// 007c645d  51                   push ecx
// 007c645e  c644245400           mov byte ptr [esp + 0x54], 0
// 007c6463  c74424249cf49900     mov dword ptr [esp + 0x24], 0x99f49c
// 007c646b  e808e40200           call 0x7f4878
// standard library vector<char> (function ?_Xran@?$vector@DV?$allocator@D@std@@@std@@KAXXZ)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

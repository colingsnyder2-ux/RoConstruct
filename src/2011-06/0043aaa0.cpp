// from server: 100% by auto
// roc 2011-06 0043aaa0  unit: AsyncResult  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043aaa0
//
// 0043aaa0  6aff                 push -1
// 0043aaa2  68221b9d00           push 0x9d1b22
// 0043aaa7  64a100000000         mov eax, dword ptr fs:[0]
// 0043aaad  50                   push eax
// 0043aaae  64892500000000       mov dword ptr fs:[0], esp
// 0043aab5  83ec44               sub esp, 0x44
// 0043aab8  68e076a600           push 0xa676e0
// 0043aabd  8d4c2404             lea ecx, [esp + 4]
// 0043aac1  ff15c404a400         call dword ptr [0xa404c4]
// 0043aac7  8d4c241c             lea ecx, [esp + 0x1c]
// 0043aacb  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0043aad3  ff15600aa400         call dword ptr [0xa40a60]
// 0043aad9  8d0424               lea eax, [esp]
// 0043aadc  50                   push eax
// 0043aadd  8d4c242c             lea ecx, [esp + 0x2c]
// 0043aae1  c644245001           mov byte ptr [esp + 0x50], 1
// 0043aae6  c7442420c0b5a500     mov dword ptr [esp + 0x20], 0xa5b5c0
// 0043aaee  ff15c804a400         call dword ptr [0xa404c8]
// 0043aaf4  681873b800           push 0xb87318
// 0043aaf9  8d4c2420             lea ecx, [esp + 0x20]
// 0043aafd  51                   push ecx
// 0043aafe  c644245400           mov byte ptr [esp + 0x54], 0
// 0043ab03  c7442424d8b5a500     mov dword ptr [esp + 0x24], 0xa5b5d8
// 0043ab0b  e89c053d00           call 0x80b0ac
// standard library vector<int> (function ?_Xran@?$vector@HV?$allocator@H@std@@@std@@KAXXZ)

// stl: vector<int>
typedef int E;
#include <vector>
template class std::vector<E>;

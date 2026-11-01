// from server: 100% by auto
// roc 2012-06 00446340  unit: RBX::Lua::IAsyncResult  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00446340
//
// 00446340  6aff                 push -1
// 00446342  684269aa00           push 0xaa6942
// 00446347  64a100000000         mov eax, dword ptr fs:[0]
// 0044634d  50                   push eax
// 0044634e  64892500000000       mov dword ptr fs:[0], esp
// 00446355  83ec44               sub esp, 0x44
// 00446358  6850fcb400           push 0xb4fc50
// 0044635d  8d4c2404             lea ecx, [esp + 4]
// 00446361  ff154826b200         call dword ptr [0xb22648]
// 00446367  8d4c241c             lea ecx, [esp + 0x1c]
// 0044636b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00446373  ff15dc29b200         call dword ptr [0xb229dc]
// 00446379  8d0424               lea eax, [esp]
// 0044637c  50                   push eax
// 0044637d  8d4c242c             lea ecx, [esp + 0x2c]
// 00446381  c644245001           mov byte ptr [esp + 0x50], 1
// 00446386  c7442420a02eb400     mov dword ptr [esp + 0x20], 0xb42ea0
// 0044638e  ff154426b200         call dword ptr [0xb22644]
// 00446394  68ac61cd00           push 0xcd61ac
// 00446399  8d4c2420             lea ecx, [esp + 0x20]
// 0044639d  51                   push ecx
// 0044639e  c644245400           mov byte ptr [esp + 0x54], 0
// 004463a3  c7442424b82eb400     mov dword ptr [esp + 0x24], 0xb42eb8
// 004463ab  e894cd5300           call 0x983144
// standard library vector<char> (function ?_Xran@?$vector@DV?$allocator@D@std@@@std@@KAXXZ)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

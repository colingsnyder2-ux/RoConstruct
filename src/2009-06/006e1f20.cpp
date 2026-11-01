// from server: 100% by auto
// roc 2009-06 006e1f20  unit: RBX::ChatOutput  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e1f20
//
// 006e1f20  6aff                 push -1
// 006e1f22  68b2db8500           push 0x85dbb2
// 006e1f27  64a100000000         mov eax, dword ptr fs:[0]
// 006e1f2d  50                   push eax
// 006e1f2e  64892500000000       mov dword ptr fs:[0], esp
// 006e1f35  83ec44               sub esp, 0x44
// 006e1f38  6840d98b00           push 0x8bd940
// 006e1f3d  8d4c2404             lea ecx, [esp + 4]
// 006e1f41  ff15b4e48900         call dword ptr [0x89e4b4]
// 006e1f47  8d4c241c             lea ecx, [esp + 0x1c]
// 006e1f4b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 006e1f53  ff15b8e98900         call dword ptr [0x89e9b8]
// 006e1f59  8d0424               lea eax, [esp]
// 006e1f5c  50                   push eax
// 006e1f5d  8d4c242c             lea ecx, [esp + 0x2c]
// 006e1f61  c644245001           mov byte ptr [esp + 0x50], 1
// 006e1f66  c744242044c98a00     mov dword ptr [esp + 0x20], 0x8ac944
// 006e1f6e  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e1f74  68dc919700           push 0x9791dc
// 006e1f79  8d4c2420             lea ecx, [esp + 0x20]
// 006e1f7d  51                   push ecx
// 006e1f7e  c644245400           mov byte ptr [esp + 0x54], 0
// 006e1f83  c74424245cc98a00     mov dword ptr [esp + 0x24], 0x8ac95c
// 006e1f8b  e8ba7a0300           call 0x719a4a
// standard library vector<char> (function ?_Xran@?$vector@DV?$allocator@D@std@@@std@@KAXXZ)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2009-12 004a3910  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3910
//
// 004a3910  83ec08               sub esp, 8
// 004a3913  53                   push ebx
// 004a3914  55                   push ebp
// 004a3915  56                   push esi
// 004a3916  8bf1                 mov esi, ecx
// 004a3918  8b4610               mov eax, dword ptr [esi + 0x10]
// 004a391b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a391e  8bc8                 mov ecx, eax
// 004a3920  2bcb                 sub ecx, ebx
// 004a3922  57                   push edi
// 004a3923  f7c1e0ffffff         test ecx, 0xffffffe0
// 004a3929  7504                 jne 0x4a392f
// 004a392b  33ff                 xor edi, edi
// 004a392d  eb27                 jmp 0x4a3956
// 004a392f  3bd8                 cmp ebx, eax
// 004a3931  7606                 jbe 0x4a3939
// 004a3933  ff1560b79800         call dword ptr [0x98b760]
// 004a3939  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a393d  8b06                 mov eax, dword ptr [esi]
// 004a393f  85c9                 test ecx, ecx
// 004a3941  7404                 je 0x4a3947
// 004a3943  3bc8                 cmp ecx, eax
// 004a3945  7406                 je 0x4a394d
// 004a3947  ff1560b79800         call dword ptr [0x98b760]
// 004a394d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004a3951  2bfb                 sub edi, ebx
// 004a3953  c1ff05               sar edi, 5
// 004a3956  8b542428             mov edx, dword ptr [esp + 0x28]
// 004a395a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a395e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a3962  52                   push edx
// 004a3963  6a01                 push 1
// 004a3965  50                   push eax
// 004a3966  51                   push ecx
// 004a3967  8bce                 mov ecx, esi
// 004a3969  e812f4ffff           call 0x4a2d80
// 004a396e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a3971  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004a3974  7606                 jbe 0x4a397c
// 004a3976  ff1560b79800         call dword ptr [0x98b760]
// 004a397c  8b36                 mov esi, dword ptr [esi]
// 004a397e  8bee                 mov ebp, esi
// 004a3980  895c2414             mov dword ptr [esp + 0x14], ebx
// 004a3984  85f6                 test esi, esi
// 004a3986  751a                 jne 0x4a39a2
// 004a3988  ff1560b79800         call dword ptr [0x98b760]
// 004a398e  33c0                 xor eax, eax
// 004a3990  c1e705               shl edi, 5
// 004a3993  03fb                 add edi, ebx
// 004a3995  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004a3998  7713                 ja 0x4a39ad
// 004a399a  85f6                 test esi, esi
// 004a399c  7408                 je 0x4a39a6
// 004a399e  8b36                 mov esi, dword ptr [esi]
// 004a39a0  eb06                 jmp 0x4a39a8
// 004a39a2  8b06                 mov eax, dword ptr [esi]
// 004a39a4  ebea                 jmp 0x4a3990
// 004a39a6  33f6                 xor esi, esi
// 004a39a8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004a39ab  7306                 jae 0x4a39b3
// 004a39ad  ff1560b79800         call dword ptr [0x98b760]
// 004a39b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a39b7  897804               mov dword ptr [eax + 4], edi
// 004a39ba  5f                   pop edi
// 004a39bb  5e                   pop esi
// 004a39bc  8928                 mov dword ptr [eax], ebp
// 004a39be  5d                   pop ebp
// 004a39bf  5b                   pop ebx
// 004a39c0  83c408               add esp, 8
// 004a39c3  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;

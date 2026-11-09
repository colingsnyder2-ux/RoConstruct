// from server: 100% by auto
// roc 2010-06 008d3f30  unit: Ogre::VisualEngine  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3f30
//
// 008d3f30  83ec08               sub esp, 8
// 008d3f33  53                   push ebx
// 008d3f34  55                   push ebp
// 008d3f35  56                   push esi
// 008d3f36  8bf1                 mov esi, ecx
// 008d3f38  8b4610               mov eax, dword ptr [esi + 0x10]
// 008d3f3b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d3f3e  8bc8                 mov ecx, eax
// 008d3f40  2bcb                 sub ecx, ebx
// 008d3f42  57                   push edi
// 008d3f43  f7c1f0ffffff         test ecx, 0xfffffff0
// 008d3f49  7504                 jne 0x8d3f4f
// 008d3f4b  33ff                 xor edi, edi
// 008d3f4d  eb27                 jmp 0x8d3f76
// 008d3f4f  3bd8                 cmp ebx, eax
// 008d3f51  7606                 jbe 0x8d3f59
// 008d3f53  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d3f59  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d3f5d  8b06                 mov eax, dword ptr [esi]
// 008d3f5f  85c9                 test ecx, ecx
// 008d3f61  7404                 je 0x8d3f67
// 008d3f63  3bc8                 cmp ecx, eax
// 008d3f65  7406                 je 0x8d3f6d
// 008d3f67  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d3f6d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008d3f71  2bfb                 sub edi, ebx
// 008d3f73  c1ff04               sar edi, 4
// 008d3f76  8b542428             mov edx, dword ptr [esp + 0x28]
// 008d3f7a  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d3f7e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d3f82  52                   push edx
// 008d3f83  6a01                 push 1
// 008d3f85  50                   push eax
// 008d3f86  51                   push ecx
// 008d3f87  8bce                 mov ecx, esi
// 008d3f89  e8a2f2ffff           call 0x8d3230
// 008d3f8e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d3f91  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008d3f94  7606                 jbe 0x8d3f9c
// 008d3f96  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d3f9c  8b36                 mov esi, dword ptr [esi]
// 008d3f9e  8bee                 mov ebp, esi
// 008d3fa0  895c2414             mov dword ptr [esp + 0x14], ebx
// 008d3fa4  85f6                 test esi, esi
// 008d3fa6  751a                 jne 0x8d3fc2
// 008d3fa8  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d3fae  33c0                 xor eax, eax
// 008d3fb0  c1e704               shl edi, 4
// 008d3fb3  03fb                 add edi, ebx
// 008d3fb5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008d3fb8  7713                 ja 0x8d3fcd
// 008d3fba  85f6                 test esi, esi
// 008d3fbc  7408                 je 0x8d3fc6
// 008d3fbe  8b36                 mov esi, dword ptr [esi]
// 008d3fc0  eb06                 jmp 0x8d3fc8
// 008d3fc2  8b06                 mov eax, dword ptr [esi]
// 008d3fc4  ebea                 jmp 0x8d3fb0
// 008d3fc6  33f6                 xor esi, esi
// 008d3fc8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008d3fcb  7306                 jae 0x8d3fd3
// 008d3fcd  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d3fd3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d3fd7  897804               mov dword ptr [eax + 4], edi
// 008d3fda  5f                   pop edi
// 008d3fdb  5e                   pop esi
// 008d3fdc  8928                 mov dword ptr [eax], ebp
// 008d3fde  5d                   pop ebp
// 008d3fdf  5b                   pop ebx
// 008d3fe0  83c408               add esp, 8
// 008d3fe3  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

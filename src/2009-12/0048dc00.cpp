// from server: 100% by auto
// roc 2009-12 0048dc00  unit: G3D::Shader  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048dc00
//
// 0048dc00  83ec08               sub esp, 8
// 0048dc03  53                   push ebx
// 0048dc04  55                   push ebp
// 0048dc05  56                   push esi
// 0048dc06  8bf1                 mov esi, ecx
// 0048dc08  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048dc0b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048dc0e  8bc8                 mov ecx, eax
// 0048dc10  2bcb                 sub ecx, ebx
// 0048dc12  57                   push edi
// 0048dc13  f7c1f0ffffff         test ecx, 0xfffffff0
// 0048dc19  7504                 jne 0x48dc1f
// 0048dc1b  33ff                 xor edi, edi
// 0048dc1d  eb27                 jmp 0x48dc46
// 0048dc1f  3bd8                 cmp ebx, eax
// 0048dc21  7606                 jbe 0x48dc29
// 0048dc23  ff1560b79800         call dword ptr [0x98b760]
// 0048dc29  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048dc2d  8b06                 mov eax, dword ptr [esi]
// 0048dc2f  85c9                 test ecx, ecx
// 0048dc31  7404                 je 0x48dc37
// 0048dc33  3bc8                 cmp ecx, eax
// 0048dc35  7406                 je 0x48dc3d
// 0048dc37  ff1560b79800         call dword ptr [0x98b760]
// 0048dc3d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0048dc41  2bfb                 sub edi, ebx
// 0048dc43  c1ff04               sar edi, 4
// 0048dc46  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048dc4a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048dc4e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048dc52  52                   push edx
// 0048dc53  6a01                 push 1
// 0048dc55  50                   push eax
// 0048dc56  51                   push ecx
// 0048dc57  8bce                 mov ecx, esi
// 0048dc59  e8a2f2ffff           call 0x48cf00
// 0048dc5e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048dc61  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0048dc64  7606                 jbe 0x48dc6c
// 0048dc66  ff1560b79800         call dword ptr [0x98b760]
// 0048dc6c  8b36                 mov esi, dword ptr [esi]
// 0048dc6e  8bee                 mov ebp, esi
// 0048dc70  895c2414             mov dword ptr [esp + 0x14], ebx
// 0048dc74  85f6                 test esi, esi
// 0048dc76  751a                 jne 0x48dc92
// 0048dc78  ff1560b79800         call dword ptr [0x98b760]
// 0048dc7e  33c0                 xor eax, eax
// 0048dc80  c1e704               shl edi, 4
// 0048dc83  03fb                 add edi, ebx
// 0048dc85  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0048dc88  7713                 ja 0x48dc9d
// 0048dc8a  85f6                 test esi, esi
// 0048dc8c  7408                 je 0x48dc96
// 0048dc8e  8b36                 mov esi, dword ptr [esi]
// 0048dc90  eb06                 jmp 0x48dc98
// 0048dc92  8b06                 mov eax, dword ptr [esi]
// 0048dc94  ebea                 jmp 0x48dc80
// 0048dc96  33f6                 xor esi, esi
// 0048dc98  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048dc9b  7306                 jae 0x48dca3
// 0048dc9d  ff1560b79800         call dword ptr [0x98b760]
// 0048dca3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048dca7  897804               mov dword ptr [eax + 4], edi
// 0048dcaa  5f                   pop edi
// 0048dcab  5e                   pop esi
// 0048dcac  8928                 mov dword ptr [eax], ebp
// 0048dcae  5d                   pop ebp
// 0048dcaf  5b                   pop ebx
// 0048dcb0  83c408               add esp, 8
// 0048dcb3  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

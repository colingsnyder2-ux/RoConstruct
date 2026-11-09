// from server: 100% by auto
// roc 2010-06 008cf3a0  unit: Ogre::RbxMeshLoader  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008cf3a0
//
// 008cf3a0  83ec08               sub esp, 8
// 008cf3a3  53                   push ebx
// 008cf3a4  55                   push ebp
// 008cf3a5  56                   push esi
// 008cf3a6  8bf1                 mov esi, ecx
// 008cf3a8  8b4610               mov eax, dword ptr [esi + 0x10]
// 008cf3ab  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008cf3ae  8bc8                 mov ecx, eax
// 008cf3b0  2bcb                 sub ecx, ebx
// 008cf3b2  57                   push edi
// 008cf3b3  f7c1e0ffffff         test ecx, 0xffffffe0
// 008cf3b9  7504                 jne 0x8cf3bf
// 008cf3bb  33ff                 xor edi, edi
// 008cf3bd  eb27                 jmp 0x8cf3e6
// 008cf3bf  3bd8                 cmp ebx, eax
// 008cf3c1  7606                 jbe 0x8cf3c9
// 008cf3c3  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cf3c9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008cf3cd  8b06                 mov eax, dword ptr [esi]
// 008cf3cf  85c9                 test ecx, ecx
// 008cf3d1  7404                 je 0x8cf3d7
// 008cf3d3  3bc8                 cmp ecx, eax
// 008cf3d5  7406                 je 0x8cf3dd
// 008cf3d7  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cf3dd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008cf3e1  2bfb                 sub edi, ebx
// 008cf3e3  c1ff05               sar edi, 5
// 008cf3e6  8b542428             mov edx, dword ptr [esp + 0x28]
// 008cf3ea  8b442424             mov eax, dword ptr [esp + 0x24]
// 008cf3ee  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008cf3f2  52                   push edx
// 008cf3f3  6a01                 push 1
// 008cf3f5  50                   push eax
// 008cf3f6  51                   push ecx
// 008cf3f7  8bce                 mov ecx, esi
// 008cf3f9  e892f1ffff           call 0x8ce590
// 008cf3fe  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008cf401  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008cf404  7606                 jbe 0x8cf40c
// 008cf406  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cf40c  8b36                 mov esi, dword ptr [esi]
// 008cf40e  8bee                 mov ebp, esi
// 008cf410  895c2414             mov dword ptr [esp + 0x14], ebx
// 008cf414  85f6                 test esi, esi
// 008cf416  751a                 jne 0x8cf432
// 008cf418  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cf41e  33c0                 xor eax, eax
// 008cf420  c1e705               shl edi, 5
// 008cf423  03fb                 add edi, ebx
// 008cf425  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008cf428  7713                 ja 0x8cf43d
// 008cf42a  85f6                 test esi, esi
// 008cf42c  7408                 je 0x8cf436
// 008cf42e  8b36                 mov esi, dword ptr [esi]
// 008cf430  eb06                 jmp 0x8cf438
// 008cf432  8b06                 mov eax, dword ptr [esi]
// 008cf434  ebea                 jmp 0x8cf420
// 008cf436  33f6                 xor esi, esi
// 008cf438  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008cf43b  7306                 jae 0x8cf443
// 008cf43d  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cf443  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008cf447  897804               mov dword ptr [eax + 4], edi
// 008cf44a  5f                   pop edi
// 008cf44b  5e                   pop esi
// 008cf44c  8928                 mov dword ptr [eax], ebp
// 008cf44e  5d                   pop ebp
// 008cf44f  5b                   pop ebx
// 008cf450  83c408               add esp, 8
// 008cf453  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;

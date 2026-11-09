// from server: 100% by auto
// roc 2009-06 0043f050  unit: RBX::MergeBinder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043f050
//
// 0043f050  83ec08               sub esp, 8
// 0043f053  53                   push ebx
// 0043f054  55                   push ebp
// 0043f055  56                   push esi
// 0043f056  8bf1                 mov esi, ecx
// 0043f058  8b4610               mov eax, dword ptr [esi + 0x10]
// 0043f05b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0043f05e  8bc8                 mov ecx, eax
// 0043f060  2bcb                 sub ecx, ebx
// 0043f062  57                   push edi
// 0043f063  f7c1f0ffffff         test ecx, 0xfffffff0
// 0043f069  7504                 jne 0x43f06f
// 0043f06b  33ff                 xor edi, edi
// 0043f06d  eb27                 jmp 0x43f096
// 0043f06f  3bd8                 cmp ebx, eax
// 0043f071  7606                 jbe 0x43f079
// 0043f073  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f079  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043f07d  8b06                 mov eax, dword ptr [esi]
// 0043f07f  85c9                 test ecx, ecx
// 0043f081  7404                 je 0x43f087
// 0043f083  3bc8                 cmp ecx, eax
// 0043f085  7406                 je 0x43f08d
// 0043f087  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f08d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043f091  2bfb                 sub edi, ebx
// 0043f093  c1ff04               sar edi, 4
// 0043f096  8b542428             mov edx, dword ptr [esp + 0x28]
// 0043f09a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043f09e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043f0a2  52                   push edx
// 0043f0a3  6a01                 push 1
// 0043f0a5  50                   push eax
// 0043f0a6  51                   push ecx
// 0043f0a7  8bce                 mov ecx, esi
// 0043f0a9  e8c2fcffff           call 0x43ed70
// 0043f0ae  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0043f0b1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0043f0b4  7606                 jbe 0x43f0bc
// 0043f0b6  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f0bc  8b36                 mov esi, dword ptr [esi]
// 0043f0be  8bee                 mov ebp, esi
// 0043f0c0  895c2414             mov dword ptr [esp + 0x14], ebx
// 0043f0c4  85f6                 test esi, esi
// 0043f0c6  751a                 jne 0x43f0e2
// 0043f0c8  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f0ce  33c0                 xor eax, eax
// 0043f0d0  c1e704               shl edi, 4
// 0043f0d3  03fb                 add edi, ebx
// 0043f0d5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0043f0d8  7713                 ja 0x43f0ed
// 0043f0da  85f6                 test esi, esi
// 0043f0dc  7408                 je 0x43f0e6
// 0043f0de  8b36                 mov esi, dword ptr [esi]
// 0043f0e0  eb06                 jmp 0x43f0e8
// 0043f0e2  8b06                 mov eax, dword ptr [esi]
// 0043f0e4  ebea                 jmp 0x43f0d0
// 0043f0e6  33f6                 xor esi, esi
// 0043f0e8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0043f0eb  7306                 jae 0x43f0f3
// 0043f0ed  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f0f3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043f0f7  897804               mov dword ptr [eax + 4], edi
// 0043f0fa  5f                   pop edi
// 0043f0fb  5e                   pop esi
// 0043f0fc  8928                 mov dword ptr [eax], ebp
// 0043f0fe  5d                   pop ebp
// 0043f0ff  5b                   pop ebx
// 0043f100  83c408               add esp, 8
// 0043f103  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

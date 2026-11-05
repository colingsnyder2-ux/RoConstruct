// from server: 100% by auto
// roc 2010-06 00444b80  unit: RBX::MergeBinder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00444b80
//
// 00444b80  83ec08               sub esp, 8
// 00444b83  53                   push ebx
// 00444b84  55                   push ebp
// 00444b85  56                   push esi
// 00444b86  8bf1                 mov esi, ecx
// 00444b88  8b4610               mov eax, dword ptr [esi + 0x10]
// 00444b8b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00444b8e  8bc8                 mov ecx, eax
// 00444b90  2bcb                 sub ecx, ebx
// 00444b92  57                   push edi
// 00444b93  f7c1f0ffffff         test ecx, 0xfffffff0
// 00444b99  7504                 jne 0x444b9f
// 00444b9b  33ff                 xor edi, edi
// 00444b9d  eb27                 jmp 0x444bc6
// 00444b9f  3bd8                 cmp ebx, eax
// 00444ba1  7606                 jbe 0x444ba9
// 00444ba3  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444ba9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00444bad  8b06                 mov eax, dword ptr [esi]
// 00444baf  85c9                 test ecx, ecx
// 00444bb1  7404                 je 0x444bb7
// 00444bb3  3bc8                 cmp ecx, eax
// 00444bb5  7406                 je 0x444bbd
// 00444bb7  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444bbd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00444bc1  2bfb                 sub edi, ebx
// 00444bc3  c1ff04               sar edi, 4
// 00444bc6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00444bca  8b442424             mov eax, dword ptr [esp + 0x24]
// 00444bce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00444bd2  52                   push edx
// 00444bd3  6a01                 push 1
// 00444bd5  50                   push eax
// 00444bd6  51                   push ecx
// 00444bd7  8bce                 mov ecx, esi
// 00444bd9  e8c2fcffff           call 0x4448a0
// 00444bde  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00444be1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00444be4  7606                 jbe 0x444bec
// 00444be6  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444bec  8b36                 mov esi, dword ptr [esi]
// 00444bee  8bee                 mov ebp, esi
// 00444bf0  895c2414             mov dword ptr [esp + 0x14], ebx
// 00444bf4  85f6                 test esi, esi
// 00444bf6  751a                 jne 0x444c12
// 00444bf8  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444bfe  33c0                 xor eax, eax
// 00444c00  c1e704               shl edi, 4
// 00444c03  03fb                 add edi, ebx
// 00444c05  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00444c08  7713                 ja 0x444c1d
// 00444c0a  85f6                 test esi, esi
// 00444c0c  7408                 je 0x444c16
// 00444c0e  8b36                 mov esi, dword ptr [esi]
// 00444c10  eb06                 jmp 0x444c18
// 00444c12  8b06                 mov eax, dword ptr [esi]
// 00444c14  ebea                 jmp 0x444c00
// 00444c16  33f6                 xor esi, esi
// 00444c18  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00444c1b  7306                 jae 0x444c23
// 00444c1d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444c23  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00444c27  897804               mov dword ptr [eax + 4], edi
// 00444c2a  5f                   pop edi
// 00444c2b  5e                   pop esi
// 00444c2c  8928                 mov dword ptr [eax], ebp
// 00444c2e  5d                   pop ebp
// 00444c2f  5b                   pop ebx
// 00444c30  83c408               add esp, 8
// 00444c33  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;

// from server: 100% by auto
// roc 2010-06 004e43c0  unit: RBX::Network::IdSerializer  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e43c0
//
// 004e43c0  83ec08               sub esp, 8
// 004e43c3  53                   push ebx
// 004e43c4  55                   push ebp
// 004e43c5  56                   push esi
// 004e43c6  8bf1                 mov esi, ecx
// 004e43c8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004e43cb  57                   push edi
// 004e43cc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004e43cf  8bcb                 mov ecx, ebx
// 004e43d1  2bcf                 sub ecx, edi
// 004e43d3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e43d8  f7e9                 imul ecx
// 004e43da  d1fa                 sar edx, 1
// 004e43dc  8bc2                 mov eax, edx
// 004e43de  c1e81f               shr eax, 0x1f
// 004e43e1  03c2                 add eax, edx
// 004e43e3  7504                 jne 0x4e43e9
// 004e43e5  33ff                 xor edi, edi
// 004e43e7  eb34                 jmp 0x4e441d
// 004e43e9  3bfb                 cmp edi, ebx
// 004e43eb  7606                 jbe 0x4e43f3
// 004e43ed  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e43f3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004e43f7  8b06                 mov eax, dword ptr [esi]
// 004e43f9  85c9                 test ecx, ecx
// 004e43fb  7404                 je 0x4e4401
// 004e43fd  3bc8                 cmp ecx, eax
// 004e43ff  7406                 je 0x4e4407
// 004e4401  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e4407  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e440b  2bcf                 sub ecx, edi
// 004e440d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e4412  f7e9                 imul ecx
// 004e4414  d1fa                 sar edx, 1
// 004e4416  8bfa                 mov edi, edx
// 004e4418  c1ef1f               shr edi, 0x1f
// 004e441b  03fa                 add edi, edx
// 004e441d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004e4421  8b542424             mov edx, dword ptr [esp + 0x24]
// 004e4425  8b442420             mov eax, dword ptr [esp + 0x20]
// 004e4429  51                   push ecx
// 004e442a  6a01                 push 1
// 004e442c  52                   push edx
// 004e442d  50                   push eax
// 004e442e  8bce                 mov ecx, esi
// 004e4430  e85bf8ffff           call 0x4e3c90
// 004e4435  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004e4438  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004e443b  7606                 jbe 0x4e4443
// 004e443d  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e4443  8b36                 mov esi, dword ptr [esi]
// 004e4445  8bee                 mov ebp, esi
// 004e4447  895c2414             mov dword ptr [esp + 0x14], ebx
// 004e444b  85f6                 test esi, esi
// 004e444d  751b                 jne 0x4e446a
// 004e444f  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e4455  33c0                 xor eax, eax
// 004e4457  8d0c7f               lea ecx, [edi + edi*2]
// 004e445a  8d3c8b               lea edi, [ebx + ecx*4]
// 004e445d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004e4460  7713                 ja 0x4e4475
// 004e4462  85f6                 test esi, esi
// 004e4464  7408                 je 0x4e446e
// 004e4466  8b36                 mov esi, dword ptr [esi]
// 004e4468  eb06                 jmp 0x4e4470
// 004e446a  8b06                 mov eax, dword ptr [esi]
// 004e446c  ebe9                 jmp 0x4e4457
// 004e446e  33f6                 xor esi, esi
// 004e4470  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004e4473  7306                 jae 0x4e447b
// 004e4475  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e447b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004e447f  897804               mov dword ptr [eax + 4], edi
// 004e4482  5f                   pop edi
// 004e4483  5e                   pop esi
// 004e4484  8928                 mov dword ptr [eax], ebp
// 004e4486  5d                   pop ebp
// 004e4487  5b                   pop ebx
// 004e4488  83c408               add esp, 8
// 004e448b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

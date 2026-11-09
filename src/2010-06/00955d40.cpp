// from server: 100% by auto
// roc 2010-06 00955d40  unit: seg_00950000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955d40
//
// 00955d40  83ec08               sub esp, 8
// 00955d43  53                   push ebx
// 00955d44  55                   push ebp
// 00955d45  56                   push esi
// 00955d46  8bf1                 mov esi, ecx
// 00955d48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00955d4b  57                   push edi
// 00955d4c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00955d4f  8bcb                 mov ecx, ebx
// 00955d51  2bcf                 sub ecx, edi
// 00955d53  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955d58  f7e9                 imul ecx
// 00955d5a  d1fa                 sar edx, 1
// 00955d5c  8bc2                 mov eax, edx
// 00955d5e  c1e81f               shr eax, 0x1f
// 00955d61  03c2                 add eax, edx
// 00955d63  7504                 jne 0x955d69
// 00955d65  33ff                 xor edi, edi
// 00955d67  eb34                 jmp 0x955d9d
// 00955d69  3bfb                 cmp edi, ebx
// 00955d6b  7606                 jbe 0x955d73
// 00955d6d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955d73  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00955d77  8b06                 mov eax, dword ptr [esi]
// 00955d79  85c9                 test ecx, ecx
// 00955d7b  7404                 je 0x955d81
// 00955d7d  3bc8                 cmp ecx, eax
// 00955d7f  7406                 je 0x955d87
// 00955d81  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955d87  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00955d8b  2bcf                 sub ecx, edi
// 00955d8d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955d92  f7e9                 imul ecx
// 00955d94  d1fa                 sar edx, 1
// 00955d96  8bfa                 mov edi, edx
// 00955d98  c1ef1f               shr edi, 0x1f
// 00955d9b  03fa                 add edi, edx
// 00955d9d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00955da1  8b542424             mov edx, dword ptr [esp + 0x24]
// 00955da5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00955da9  51                   push ecx
// 00955daa  6a01                 push 1
// 00955dac  52                   push edx
// 00955dad  50                   push eax
// 00955dae  8bce                 mov ecx, esi
// 00955db0  e86bfcffff           call 0x955a20
// 00955db5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00955db8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00955dbb  7606                 jbe 0x955dc3
// 00955dbd  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955dc3  8b36                 mov esi, dword ptr [esi]
// 00955dc5  8bee                 mov ebp, esi
// 00955dc7  895c2414             mov dword ptr [esp + 0x14], ebx
// 00955dcb  85f6                 test esi, esi
// 00955dcd  751b                 jne 0x955dea
// 00955dcf  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955dd5  33c0                 xor eax, eax
// 00955dd7  8d0c7f               lea ecx, [edi + edi*2]
// 00955dda  8d3c8b               lea edi, [ebx + ecx*4]
// 00955ddd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00955de0  7713                 ja 0x955df5
// 00955de2  85f6                 test esi, esi
// 00955de4  7408                 je 0x955dee
// 00955de6  8b36                 mov esi, dword ptr [esi]
// 00955de8  eb06                 jmp 0x955df0
// 00955dea  8b06                 mov eax, dword ptr [esi]
// 00955dec  ebe9                 jmp 0x955dd7
// 00955dee  33f6                 xor esi, esi
// 00955df0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00955df3  7306                 jae 0x955dfb
// 00955df5  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955dfb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00955dff  897804               mov dword ptr [eax + 4], edi
// 00955e02  5f                   pop edi
// 00955e03  5e                   pop esi
// 00955e04  8928                 mov dword ptr [eax], ebp
// 00955e06  5d                   pop ebp
// 00955e07  5b                   pop ebx
// 00955e08  83c408               add esp, 8
// 00955e0b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

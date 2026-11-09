// from server: 100% by auto
// roc 2010-06 0096fc40  unit: seg_00960000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096fc40
//
// 0096fc40  83ec08               sub esp, 8
// 0096fc43  53                   push ebx
// 0096fc44  55                   push ebp
// 0096fc45  56                   push esi
// 0096fc46  8bf1                 mov esi, ecx
// 0096fc48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096fc4b  57                   push edi
// 0096fc4c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0096fc4f  8bcb                 mov ecx, ebx
// 0096fc51  2bcf                 sub ecx, edi
// 0096fc53  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fc58  f7e9                 imul ecx
// 0096fc5a  d1fa                 sar edx, 1
// 0096fc5c  8bc2                 mov eax, edx
// 0096fc5e  c1e81f               shr eax, 0x1f
// 0096fc61  03c2                 add eax, edx
// 0096fc63  7504                 jne 0x96fc69
// 0096fc65  33ff                 xor edi, edi
// 0096fc67  eb34                 jmp 0x96fc9d
// 0096fc69  3bfb                 cmp edi, ebx
// 0096fc6b  7606                 jbe 0x96fc73
// 0096fc6d  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fc73  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0096fc77  8b06                 mov eax, dword ptr [esi]
// 0096fc79  85c9                 test ecx, ecx
// 0096fc7b  7404                 je 0x96fc81
// 0096fc7d  3bc8                 cmp ecx, eax
// 0096fc7f  7406                 je 0x96fc87
// 0096fc81  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fc87  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096fc8b  2bcf                 sub ecx, edi
// 0096fc8d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fc92  f7e9                 imul ecx
// 0096fc94  d1fa                 sar edx, 1
// 0096fc96  8bfa                 mov edi, edx
// 0096fc98  c1ef1f               shr edi, 0x1f
// 0096fc9b  03fa                 add edi, edx
// 0096fc9d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0096fca1  8b542424             mov edx, dword ptr [esp + 0x24]
// 0096fca5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0096fca9  51                   push ecx
// 0096fcaa  6a01                 push 1
// 0096fcac  52                   push edx
// 0096fcad  50                   push eax
// 0096fcae  8bce                 mov ecx, esi
// 0096fcb0  e84bfcffff           call 0x96f900
// 0096fcb5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096fcb8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0096fcbb  7606                 jbe 0x96fcc3
// 0096fcbd  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fcc3  8b36                 mov esi, dword ptr [esi]
// 0096fcc5  8bee                 mov ebp, esi
// 0096fcc7  895c2414             mov dword ptr [esp + 0x14], ebx
// 0096fccb  85f6                 test esi, esi
// 0096fccd  751b                 jne 0x96fcea
// 0096fccf  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fcd5  33c0                 xor eax, eax
// 0096fcd7  8d0c7f               lea ecx, [edi + edi*2]
// 0096fcda  8d3c8b               lea edi, [ebx + ecx*4]
// 0096fcdd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0096fce0  7713                 ja 0x96fcf5
// 0096fce2  85f6                 test esi, esi
// 0096fce4  7408                 je 0x96fcee
// 0096fce6  8b36                 mov esi, dword ptr [esi]
// 0096fce8  eb06                 jmp 0x96fcf0
// 0096fcea  8b06                 mov eax, dword ptr [esi]
// 0096fcec  ebe9                 jmp 0x96fcd7
// 0096fcee  33f6                 xor esi, esi
// 0096fcf0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0096fcf3  7306                 jae 0x96fcfb
// 0096fcf5  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fcfb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0096fcff  897804               mov dword ptr [eax + 4], edi
// 0096fd02  5f                   pop edi
// 0096fd03  5e                   pop esi
// 0096fd04  8928                 mov dword ptr [eax], ebp
// 0096fd06  5d                   pop ebp
// 0096fd07  5b                   pop ebx
// 0096fd08  83c408               add esp, 8
// 0096fd0b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

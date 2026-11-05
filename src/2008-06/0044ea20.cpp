// from server: 100% by auto
// roc 2008-06 0044ea20  unit: CRobloxControlColorSelector  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044ea20
//
// 0044ea20  83ec08               sub esp, 8
// 0044ea23  53                   push ebx
// 0044ea24  55                   push ebp
// 0044ea25  56                   push esi
// 0044ea26  8bf1                 mov esi, ecx
// 0044ea28  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0044ea2b  57                   push edi
// 0044ea2c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0044ea2f  8bcb                 mov ecx, ebx
// 0044ea31  2bcf                 sub ecx, edi
// 0044ea33  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ea38  f7e9                 imul ecx
// 0044ea3a  d1fa                 sar edx, 1
// 0044ea3c  8bc2                 mov eax, edx
// 0044ea3e  c1e81f               shr eax, 0x1f
// 0044ea41  03c2                 add eax, edx
// 0044ea43  7504                 jne 0x44ea49
// 0044ea45  33ff                 xor edi, edi
// 0044ea47  eb34                 jmp 0x44ea7d
// 0044ea49  3bfb                 cmp edi, ebx
// 0044ea4b  7606                 jbe 0x44ea53
// 0044ea4d  ff1590288000         call dword ptr [0x802890]
// 0044ea53  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0044ea57  8b06                 mov eax, dword ptr [esi]
// 0044ea59  85c9                 test ecx, ecx
// 0044ea5b  7404                 je 0x44ea61
// 0044ea5d  3bc8                 cmp ecx, eax
// 0044ea5f  7406                 je 0x44ea67
// 0044ea61  ff1590288000         call dword ptr [0x802890]
// 0044ea67  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044ea6b  2bcf                 sub ecx, edi
// 0044ea6d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ea72  f7e9                 imul ecx
// 0044ea74  d1fa                 sar edx, 1
// 0044ea76  8bfa                 mov edi, edx
// 0044ea78  c1ef1f               shr edi, 0x1f
// 0044ea7b  03fa                 add edi, edx
// 0044ea7d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044ea81  8b542424             mov edx, dword ptr [esp + 0x24]
// 0044ea85  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044ea89  51                   push ecx
// 0044ea8a  6a01                 push 1
// 0044ea8c  52                   push edx
// 0044ea8d  50                   push eax
// 0044ea8e  8bce                 mov ecx, esi
// 0044ea90  e8cbfcffff           call 0x44e760
// 0044ea95  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0044ea98  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0044ea9b  7606                 jbe 0x44eaa3
// 0044ea9d  ff1590288000         call dword ptr [0x802890]
// 0044eaa3  8b36                 mov esi, dword ptr [esi]
// 0044eaa5  8bee                 mov ebp, esi
// 0044eaa7  895c2414             mov dword ptr [esp + 0x14], ebx
// 0044eaab  85f6                 test esi, esi
// 0044eaad  751b                 jne 0x44eaca
// 0044eaaf  ff1590288000         call dword ptr [0x802890]
// 0044eab5  33c0                 xor eax, eax
// 0044eab7  8d0c7f               lea ecx, [edi + edi*2]
// 0044eaba  8d3c8b               lea edi, [ebx + ecx*4]
// 0044eabd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0044eac0  7713                 ja 0x44ead5
// 0044eac2  85f6                 test esi, esi
// 0044eac4  7408                 je 0x44eace
// 0044eac6  8b36                 mov esi, dword ptr [esi]
// 0044eac8  eb06                 jmp 0x44ead0
// 0044eaca  8b06                 mov eax, dword ptr [esi]
// 0044eacc  ebe9                 jmp 0x44eab7
// 0044eace  33f6                 xor esi, esi
// 0044ead0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0044ead3  7306                 jae 0x44eadb
// 0044ead5  ff1590288000         call dword ptr [0x802890]
// 0044eadb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044eadf  897804               mov dword ptr [eax + 4], edi
// 0044eae2  5f                   pop edi
// 0044eae3  5e                   pop esi
// 0044eae4  8928                 mov dword ptr [eax], ebp
// 0044eae6  5d                   pop ebp
// 0044eae7  5b                   pop ebx
// 0044eae8  83c408               add esp, 8
// 0044eaeb  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

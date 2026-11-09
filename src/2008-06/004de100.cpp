// from server: 100% by auto
// roc 2008-06 004de100  unit: RBX::RenderBase::Mesh::Level  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004de100
//
// 004de100  83ec08               sub esp, 8
// 004de103  53                   push ebx
// 004de104  55                   push ebp
// 004de105  56                   push esi
// 004de106  8bf1                 mov esi, ecx
// 004de108  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004de10b  57                   push edi
// 004de10c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004de10f  8bcb                 mov ecx, ebx
// 004de111  2bcf                 sub ecx, edi
// 004de113  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004de118  f7e9                 imul ecx
// 004de11a  d1fa                 sar edx, 1
// 004de11c  8bc2                 mov eax, edx
// 004de11e  c1e81f               shr eax, 0x1f
// 004de121  03c2                 add eax, edx
// 004de123  7504                 jne 0x4de129
// 004de125  33ff                 xor edi, edi
// 004de127  eb34                 jmp 0x4de15d
// 004de129  3bfb                 cmp edi, ebx
// 004de12b  7606                 jbe 0x4de133
// 004de12d  ff1590288000         call dword ptr [0x802890]
// 004de133  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004de137  8b06                 mov eax, dword ptr [esi]
// 004de139  85c9                 test ecx, ecx
// 004de13b  7404                 je 0x4de141
// 004de13d  3bc8                 cmp ecx, eax
// 004de13f  7406                 je 0x4de147
// 004de141  ff1590288000         call dword ptr [0x802890]
// 004de147  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004de14b  2bcf                 sub ecx, edi
// 004de14d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004de152  f7e9                 imul ecx
// 004de154  d1fa                 sar edx, 1
// 004de156  8bfa                 mov edi, edx
// 004de158  c1ef1f               shr edi, 0x1f
// 004de15b  03fa                 add edi, edx
// 004de15d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004de161  8b542424             mov edx, dword ptr [esp + 0x24]
// 004de165  8b442420             mov eax, dword ptr [esp + 0x20]
// 004de169  51                   push ecx
// 004de16a  6a01                 push 1
// 004de16c  52                   push edx
// 004de16d  50                   push eax
// 004de16e  8bce                 mov ecx, esi
// 004de170  e84bfaffff           call 0x4ddbc0
// 004de175  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004de178  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004de17b  7606                 jbe 0x4de183
// 004de17d  ff1590288000         call dword ptr [0x802890]
// 004de183  8b36                 mov esi, dword ptr [esi]
// 004de185  8bee                 mov ebp, esi
// 004de187  895c2414             mov dword ptr [esp + 0x14], ebx
// 004de18b  85f6                 test esi, esi
// 004de18d  751b                 jne 0x4de1aa
// 004de18f  ff1590288000         call dword ptr [0x802890]
// 004de195  33c0                 xor eax, eax
// 004de197  8d0c7f               lea ecx, [edi + edi*2]
// 004de19a  8d3c8b               lea edi, [ebx + ecx*4]
// 004de19d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004de1a0  7713                 ja 0x4de1b5
// 004de1a2  85f6                 test esi, esi
// 004de1a4  7408                 je 0x4de1ae
// 004de1a6  8b36                 mov esi, dword ptr [esi]
// 004de1a8  eb06                 jmp 0x4de1b0
// 004de1aa  8b06                 mov eax, dword ptr [esi]
// 004de1ac  ebe9                 jmp 0x4de197
// 004de1ae  33f6                 xor esi, esi
// 004de1b0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004de1b3  7306                 jae 0x4de1bb
// 004de1b5  ff1590288000         call dword ptr [0x802890]
// 004de1bb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004de1bf  897804               mov dword ptr [eax + 4], edi
// 004de1c2  5f                   pop edi
// 004de1c3  5e                   pop esi
// 004de1c4  8928                 mov dword ptr [eax], ebp
// 004de1c6  5d                   pop ebp
// 004de1c7  5b                   pop ebx
// 004de1c8  83c408               add esp, 8
// 004de1cb  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

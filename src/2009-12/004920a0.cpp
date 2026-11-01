// from server: 100% by auto
// roc 2009-12 004920a0  unit: Ogre::RbxEntity  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004920a0
//
// 004920a0  83ec08               sub esp, 8
// 004920a3  53                   push ebx
// 004920a4  55                   push ebp
// 004920a5  56                   push esi
// 004920a6  8bf1                 mov esi, ecx
// 004920a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004920ab  57                   push edi
// 004920ac  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004920af  8bcb                 mov ecx, ebx
// 004920b1  2bcf                 sub ecx, edi
// 004920b3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004920b8  f7e9                 imul ecx
// 004920ba  d1fa                 sar edx, 1
// 004920bc  8bc2                 mov eax, edx
// 004920be  c1e81f               shr eax, 0x1f
// 004920c1  03c2                 add eax, edx
// 004920c3  7504                 jne 0x4920c9
// 004920c5  33ff                 xor edi, edi
// 004920c7  eb34                 jmp 0x4920fd
// 004920c9  3bfb                 cmp edi, ebx
// 004920cb  7606                 jbe 0x4920d3
// 004920cd  ff1560b79800         call dword ptr [0x98b760]
// 004920d3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004920d7  8b06                 mov eax, dword ptr [esi]
// 004920d9  85c9                 test ecx, ecx
// 004920db  7404                 je 0x4920e1
// 004920dd  3bc8                 cmp ecx, eax
// 004920df  7406                 je 0x4920e7
// 004920e1  ff1560b79800         call dword ptr [0x98b760]
// 004920e7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004920eb  2bcf                 sub ecx, edi
// 004920ed  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004920f2  f7e9                 imul ecx
// 004920f4  d1fa                 sar edx, 1
// 004920f6  8bfa                 mov edi, edx
// 004920f8  c1ef1f               shr edi, 0x1f
// 004920fb  03fa                 add edi, edx
// 004920fd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00492101  8b542424             mov edx, dword ptr [esp + 0x24]
// 00492105  8b442420             mov eax, dword ptr [esp + 0x20]
// 00492109  51                   push ecx
// 0049210a  6a01                 push 1
// 0049210c  52                   push edx
// 0049210d  50                   push eax
// 0049210e  8bce                 mov ecx, esi
// 00492110  e8dbfcffff           call 0x491df0
// 00492115  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00492118  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0049211b  7606                 jbe 0x492123
// 0049211d  ff1560b79800         call dword ptr [0x98b760]
// 00492123  8b36                 mov esi, dword ptr [esi]
// 00492125  8bee                 mov ebp, esi
// 00492127  895c2414             mov dword ptr [esp + 0x14], ebx
// 0049212b  85f6                 test esi, esi
// 0049212d  751b                 jne 0x49214a
// 0049212f  ff1560b79800         call dword ptr [0x98b760]
// 00492135  33c0                 xor eax, eax
// 00492137  8d0c7f               lea ecx, [edi + edi*2]
// 0049213a  8d3c8b               lea edi, [ebx + ecx*4]
// 0049213d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00492140  7713                 ja 0x492155
// 00492142  85f6                 test esi, esi
// 00492144  7408                 je 0x49214e
// 00492146  8b36                 mov esi, dword ptr [esi]
// 00492148  eb06                 jmp 0x492150
// 0049214a  8b06                 mov eax, dword ptr [esi]
// 0049214c  ebe9                 jmp 0x492137
// 0049214e  33f6                 xor esi, esi
// 00492150  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00492153  7306                 jae 0x49215b
// 00492155  ff1560b79800         call dword ptr [0x98b760]
// 0049215b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049215f  897804               mov dword ptr [eax + 4], edi
// 00492162  5f                   pop edi
// 00492163  5e                   pop esi
// 00492164  8928                 mov dword ptr [eax], ebp
// 00492166  5d                   pop ebp
// 00492167  5b                   pop ebx
// 00492168  83c408               add esp, 8
// 0049216b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

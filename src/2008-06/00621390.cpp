// from server: 100% by auto
// roc 2008-06 00621390  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621390
//
// 00621390  83ec08               sub esp, 8
// 00621393  53                   push ebx
// 00621394  55                   push ebp
// 00621395  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0062139b  56                   push esi
// 0062139c  8bf1                 mov esi, ecx
// 0062139e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006213a1  57                   push edi
// 006213a2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006213a5  8bcb                 mov ecx, ebx
// 006213a7  2bcf                 sub ecx, edi
// 006213a9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006213ae  f7e9                 imul ecx
// 006213b0  c1fa02               sar edx, 2
// 006213b3  8bc2                 mov eax, edx
// 006213b5  c1e81f               shr eax, 0x1f
// 006213b8  03c2                 add eax, edx
// 006213ba  7504                 jne 0x6213c0
// 006213bc  33ff                 xor edi, edi
// 006213be  eb2d                 jmp 0x6213ed
// 006213c0  3bfb                 cmp edi, ebx
// 006213c2  7602                 jbe 0x6213c6
// 006213c4  ffd5                 call ebp
// 006213c6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006213ca  8b06                 mov eax, dword ptr [esi]
// 006213cc  85c9                 test ecx, ecx
// 006213ce  7404                 je 0x6213d4
// 006213d0  3bc8                 cmp ecx, eax
// 006213d2  7402                 je 0x6213d6
// 006213d4  ffd5                 call ebp
// 006213d6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006213da  2bcf                 sub ecx, edi
// 006213dc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006213e1  f7e9                 imul ecx
// 006213e3  c1fa02               sar edx, 2
// 006213e6  8bfa                 mov edi, edx
// 006213e8  c1ef1f               shr edi, 0x1f
// 006213eb  03fa                 add edi, edx
// 006213ed  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006213f1  8b542424             mov edx, dword ptr [esp + 0x24]
// 006213f5  8b442420             mov eax, dword ptr [esp + 0x20]
// 006213f9  51                   push ecx
// 006213fa  6a01                 push 1
// 006213fc  52                   push edx
// 006213fd  50                   push eax
// 006213fe  8bce                 mov ecx, esi
// 00621400  e84bfcffff           call 0x621050
// 00621405  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00621408  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0062140b  7602                 jbe 0x62140f
// 0062140d  ffd5                 call ebp
// 0062140f  8b36                 mov esi, dword ptr [esi]
// 00621411  57                   push edi
// 00621412  8d4c2414             lea ecx, [esp + 0x14]
// 00621416  89742414             mov dword ptr [esp + 0x14], esi
// 0062141a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0062141e  e82dc00600           call 0x68d450
// 00621423  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00621427  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062142b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0062142f  5f                   pop edi
// 00621430  5e                   pop esi
// 00621431  5d                   pop ebp
// 00621432  8908                 mov dword ptr [eax], ecx
// 00621434  895004               mov dword ptr [eax + 4], edx
// 00621437  5b                   pop ebx
// 00621438  83c408               add esp, 8
// 0062143b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;

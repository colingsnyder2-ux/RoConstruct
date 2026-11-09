// from server: 100% by auto
// roc 2009-06 00472220  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472220
//
// 00472220  83ec08               sub esp, 8
// 00472223  53                   push ebx
// 00472224  55                   push ebp
// 00472225  56                   push esi
// 00472226  8bf1                 mov esi, ecx
// 00472228  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047222b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0047222e  8bc8                 mov ecx, eax
// 00472230  2bcb                 sub ecx, ebx
// 00472232  57                   push edi
// 00472233  f7c1c0ffffff         test ecx, 0xffffffc0
// 00472239  7504                 jne 0x47223f
// 0047223b  33ff                 xor edi, edi
// 0047223d  eb27                 jmp 0x472266
// 0047223f  3bd8                 cmp ebx, eax
// 00472241  7606                 jbe 0x472249
// 00472243  ff15ace98900         call dword ptr [0x89e9ac]
// 00472249  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047224d  8b06                 mov eax, dword ptr [esi]
// 0047224f  85c9                 test ecx, ecx
// 00472251  7404                 je 0x472257
// 00472253  3bc8                 cmp ecx, eax
// 00472255  7406                 je 0x47225d
// 00472257  ff15ace98900         call dword ptr [0x89e9ac]
// 0047225d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00472261  2bfb                 sub edi, ebx
// 00472263  c1ff06               sar edi, 6
// 00472266  8b542428             mov edx, dword ptr [esp + 0x28]
// 0047226a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047226e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00472272  52                   push edx
// 00472273  6a01                 push 1
// 00472275  50                   push eax
// 00472276  51                   push ecx
// 00472277  8bce                 mov ecx, esi
// 00472279  e882fbffff           call 0x471e00
// 0047227e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00472281  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00472284  7606                 jbe 0x47228c
// 00472286  ff15ace98900         call dword ptr [0x89e9ac]
// 0047228c  8b36                 mov esi, dword ptr [esi]
// 0047228e  8bee                 mov ebp, esi
// 00472290  895c2414             mov dword ptr [esp + 0x14], ebx
// 00472294  85f6                 test esi, esi
// 00472296  751a                 jne 0x4722b2
// 00472298  ff15ace98900         call dword ptr [0x89e9ac]
// 0047229e  33c0                 xor eax, eax
// 004722a0  c1e706               shl edi, 6
// 004722a3  03fb                 add edi, ebx
// 004722a5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004722a8  7713                 ja 0x4722bd
// 004722aa  85f6                 test esi, esi
// 004722ac  7408                 je 0x4722b6
// 004722ae  8b36                 mov esi, dword ptr [esi]
// 004722b0  eb06                 jmp 0x4722b8
// 004722b2  8b06                 mov eax, dword ptr [esi]
// 004722b4  ebea                 jmp 0x4722a0
// 004722b6  33f6                 xor esi, esi
// 004722b8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004722bb  7306                 jae 0x4722c3
// 004722bd  ff15ace98900         call dword ptr [0x89e9ac]
// 004722c3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004722c7  897804               mov dword ptr [eax + 4], edi
// 004722ca  5f                   pop edi
// 004722cb  5e                   pop esi
// 004722cc  8928                 mov dword ptr [eax], ebp
// 004722ce  5d                   pop ebp
// 004722cf  5b                   pop ebx
// 004722d0  83c408               add esp, 8
// 004722d3  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;

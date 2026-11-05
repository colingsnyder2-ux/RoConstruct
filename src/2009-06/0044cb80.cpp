// from server: 100% by auto
// roc 2009-06 0044cb80  unit: CRobloxControlColorSelector  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044cb80
//
// 0044cb80  83ec08               sub esp, 8
// 0044cb83  53                   push ebx
// 0044cb84  55                   push ebp
// 0044cb85  56                   push esi
// 0044cb86  8bf1                 mov esi, ecx
// 0044cb88  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0044cb8b  57                   push edi
// 0044cb8c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0044cb8f  8bcb                 mov ecx, ebx
// 0044cb91  2bcf                 sub ecx, edi
// 0044cb93  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044cb98  f7e9                 imul ecx
// 0044cb9a  d1fa                 sar edx, 1
// 0044cb9c  8bc2                 mov eax, edx
// 0044cb9e  c1e81f               shr eax, 0x1f
// 0044cba1  03c2                 add eax, edx
// 0044cba3  7504                 jne 0x44cba9
// 0044cba5  33ff                 xor edi, edi
// 0044cba7  eb34                 jmp 0x44cbdd
// 0044cba9  3bfb                 cmp edi, ebx
// 0044cbab  7606                 jbe 0x44cbb3
// 0044cbad  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cbb3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0044cbb7  8b06                 mov eax, dword ptr [esi]
// 0044cbb9  85c9                 test ecx, ecx
// 0044cbbb  7404                 je 0x44cbc1
// 0044cbbd  3bc8                 cmp ecx, eax
// 0044cbbf  7406                 je 0x44cbc7
// 0044cbc1  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cbc7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044cbcb  2bcf                 sub ecx, edi
// 0044cbcd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044cbd2  f7e9                 imul ecx
// 0044cbd4  d1fa                 sar edx, 1
// 0044cbd6  8bfa                 mov edi, edx
// 0044cbd8  c1ef1f               shr edi, 0x1f
// 0044cbdb  03fa                 add edi, edx
// 0044cbdd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044cbe1  8b542424             mov edx, dword ptr [esp + 0x24]
// 0044cbe5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044cbe9  51                   push ecx
// 0044cbea  6a01                 push 1
// 0044cbec  52                   push edx
// 0044cbed  50                   push eax
// 0044cbee  8bce                 mov ecx, esi
// 0044cbf0  e84bfcffff           call 0x44c840
// 0044cbf5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0044cbf8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0044cbfb  7606                 jbe 0x44cc03
// 0044cbfd  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cc03  8b36                 mov esi, dword ptr [esi]
// 0044cc05  8bee                 mov ebp, esi
// 0044cc07  895c2414             mov dword ptr [esp + 0x14], ebx
// 0044cc0b  85f6                 test esi, esi
// 0044cc0d  751b                 jne 0x44cc2a
// 0044cc0f  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cc15  33c0                 xor eax, eax
// 0044cc17  8d0c7f               lea ecx, [edi + edi*2]
// 0044cc1a  8d3c8b               lea edi, [ebx + ecx*4]
// 0044cc1d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0044cc20  7713                 ja 0x44cc35
// 0044cc22  85f6                 test esi, esi
// 0044cc24  7408                 je 0x44cc2e
// 0044cc26  8b36                 mov esi, dword ptr [esi]
// 0044cc28  eb06                 jmp 0x44cc30
// 0044cc2a  8b06                 mov eax, dword ptr [esi]
// 0044cc2c  ebe9                 jmp 0x44cc17
// 0044cc2e  33f6                 xor esi, esi
// 0044cc30  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0044cc33  7306                 jae 0x44cc3b
// 0044cc35  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cc3b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044cc3f  897804               mov dword ptr [eax + 4], edi
// 0044cc42  5f                   pop edi
// 0044cc43  5e                   pop esi
// 0044cc44  8928                 mov dword ptr [eax], ebp
// 0044cc46  5d                   pop ebp
// 0044cc47  5b                   pop ebx
// 0044cc48  83c408               add esp, 8
// 0044cc4b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

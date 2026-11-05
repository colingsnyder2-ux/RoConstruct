// from server: 100% by auto
// roc 2010-06 00454210  unit: CRobloxControlColorSelector  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00454210
//
// 00454210  83ec08               sub esp, 8
// 00454213  53                   push ebx
// 00454214  55                   push ebp
// 00454215  56                   push esi
// 00454216  8bf1                 mov esi, ecx
// 00454218  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0045421b  57                   push edi
// 0045421c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0045421f  8bcb                 mov ecx, ebx
// 00454221  2bcf                 sub ecx, edi
// 00454223  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00454228  f7e9                 imul ecx
// 0045422a  d1fa                 sar edx, 1
// 0045422c  8bc2                 mov eax, edx
// 0045422e  c1e81f               shr eax, 0x1f
// 00454231  03c2                 add eax, edx
// 00454233  7504                 jne 0x454239
// 00454235  33ff                 xor edi, edi
// 00454237  eb34                 jmp 0x45426d
// 00454239  3bfb                 cmp edi, ebx
// 0045423b  7606                 jbe 0x454243
// 0045423d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00454243  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00454247  8b06                 mov eax, dword ptr [esi]
// 00454249  85c9                 test ecx, ecx
// 0045424b  7404                 je 0x454251
// 0045424d  3bc8                 cmp ecx, eax
// 0045424f  7406                 je 0x454257
// 00454251  ff150ca99e00         call dword ptr [0x9ea90c]
// 00454257  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045425b  2bcf                 sub ecx, edi
// 0045425d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00454262  f7e9                 imul ecx
// 00454264  d1fa                 sar edx, 1
// 00454266  8bfa                 mov edi, edx
// 00454268  c1ef1f               shr edi, 0x1f
// 0045426b  03fa                 add edi, edx
// 0045426d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00454271  8b542424             mov edx, dword ptr [esp + 0x24]
// 00454275  8b442420             mov eax, dword ptr [esp + 0x20]
// 00454279  51                   push ecx
// 0045427a  6a01                 push 1
// 0045427c  52                   push edx
// 0045427d  50                   push eax
// 0045427e  8bce                 mov ecx, esi
// 00454280  e84bfcffff           call 0x453ed0
// 00454285  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00454288  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0045428b  7606                 jbe 0x454293
// 0045428d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00454293  8b36                 mov esi, dword ptr [esi]
// 00454295  8bee                 mov ebp, esi
// 00454297  895c2414             mov dword ptr [esp + 0x14], ebx
// 0045429b  85f6                 test esi, esi
// 0045429d  751b                 jne 0x4542ba
// 0045429f  ff150ca99e00         call dword ptr [0x9ea90c]
// 004542a5  33c0                 xor eax, eax
// 004542a7  8d0c7f               lea ecx, [edi + edi*2]
// 004542aa  8d3c8b               lea edi, [ebx + ecx*4]
// 004542ad  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004542b0  7713                 ja 0x4542c5
// 004542b2  85f6                 test esi, esi
// 004542b4  7408                 je 0x4542be
// 004542b6  8b36                 mov esi, dword ptr [esi]
// 004542b8  eb06                 jmp 0x4542c0
// 004542ba  8b06                 mov eax, dword ptr [esi]
// 004542bc  ebe9                 jmp 0x4542a7
// 004542be  33f6                 xor esi, esi
// 004542c0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004542c3  7306                 jae 0x4542cb
// 004542c5  ff150ca99e00         call dword ptr [0x9ea90c]
// 004542cb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004542cf  897804               mov dword ptr [eax + 4], edi
// 004542d2  5f                   pop edi
// 004542d3  5e                   pop esi
// 004542d4  8928                 mov dword ptr [eax], ebp
// 004542d6  5d                   pop ebp
// 004542d7  5b                   pop ebx
// 004542d8  83c408               add esp, 8
// 004542db  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;

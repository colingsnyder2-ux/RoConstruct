// from server: 100% by auto
// roc 2010-06 0065a400  unit: RBX::KeyframeSequence  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065a400
//
// 0065a400  83ec08               sub esp, 8
// 0065a403  53                   push ebx
// 0065a404  55                   push ebp
// 0065a405  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0065a40b  56                   push esi
// 0065a40c  8bf1                 mov esi, ecx
// 0065a40e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0065a411  57                   push edi
// 0065a412  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0065a415  8bcb                 mov ecx, ebx
// 0065a417  2bcf                 sub ecx, edi
// 0065a419  b893244992           mov eax, 0x92492493
// 0065a41e  f7e9                 imul ecx
// 0065a420  03d1                 add edx, ecx
// 0065a422  c1fa04               sar edx, 4
// 0065a425  8bc2                 mov eax, edx
// 0065a427  c1e81f               shr eax, 0x1f
// 0065a42a  03c2                 add eax, edx
// 0065a42c  7504                 jne 0x65a432
// 0065a42e  33ff                 xor edi, edi
// 0065a430  eb2f                 jmp 0x65a461
// 0065a432  3bfb                 cmp edi, ebx
// 0065a434  7602                 jbe 0x65a438
// 0065a436  ffd5                 call ebp
// 0065a438  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065a43c  8b06                 mov eax, dword ptr [esi]
// 0065a43e  85c9                 test ecx, ecx
// 0065a440  7404                 je 0x65a446
// 0065a442  3bc8                 cmp ecx, eax
// 0065a444  7402                 je 0x65a448
// 0065a446  ffd5                 call ebp
// 0065a448  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065a44c  2bcf                 sub ecx, edi
// 0065a44e  b893244992           mov eax, 0x92492493
// 0065a453  f7e9                 imul ecx
// 0065a455  03d1                 add edx, ecx
// 0065a457  c1fa04               sar edx, 4
// 0065a45a  8bfa                 mov edi, edx
// 0065a45c  c1ef1f               shr edi, 0x1f
// 0065a45f  03fa                 add edi, edx
// 0065a461  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0065a465  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065a469  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065a46d  51                   push ecx
// 0065a46e  6a01                 push 1
// 0065a470  52                   push edx
// 0065a471  50                   push eax
// 0065a472  8bce                 mov ecx, esi
// 0065a474  e847f8ffff           call 0x659cc0
// 0065a479  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0065a47c  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0065a47f  7602                 jbe 0x65a483
// 0065a481  ffd5                 call ebp
// 0065a483  8b36                 mov esi, dword ptr [esi]
// 0065a485  57                   push edi
// 0065a486  8d4c2414             lea ecx, [esp + 0x14]
// 0065a48a  89742414             mov dword ptr [esp + 0x14], esi
// 0065a48e  895c2418             mov dword ptr [esp + 0x18], ebx
// 0065a492  e8d999dcff           call 0x423e70
// 0065a497  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065a49b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065a49f  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065a4a3  5f                   pop edi
// 0065a4a4  5e                   pop esi
// 0065a4a5  5d                   pop ebp
// 0065a4a6  8908                 mov dword ptr [eax], ecx
// 0065a4a8  895004               mov dword ptr [eax + 4], edx
// 0065a4ab  5b                   pop ebx
// 0065a4ac  83c408               add esp, 8
// 0065a4af  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

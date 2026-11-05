// from server: 100% by auto
// roc 2009-06 00424af0  unit: MainLogManager  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424af0
//
// 00424af0  83ec08               sub esp, 8
// 00424af3  53                   push ebx
// 00424af4  55                   push ebp
// 00424af5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00424afb  56                   push esi
// 00424afc  8bf1                 mov esi, ecx
// 00424afe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00424b01  57                   push edi
// 00424b02  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00424b05  8bcb                 mov ecx, ebx
// 00424b07  2bcf                 sub ecx, edi
// 00424b09  b893244992           mov eax, 0x92492493
// 00424b0e  f7e9                 imul ecx
// 00424b10  03d1                 add edx, ecx
// 00424b12  c1fa04               sar edx, 4
// 00424b15  8bc2                 mov eax, edx
// 00424b17  c1e81f               shr eax, 0x1f
// 00424b1a  03c2                 add eax, edx
// 00424b1c  7504                 jne 0x424b22
// 00424b1e  33ff                 xor edi, edi
// 00424b20  eb2f                 jmp 0x424b51
// 00424b22  3bfb                 cmp edi, ebx
// 00424b24  7602                 jbe 0x424b28
// 00424b26  ffd5                 call ebp
// 00424b28  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00424b2c  8b06                 mov eax, dword ptr [esi]
// 00424b2e  85c9                 test ecx, ecx
// 00424b30  7404                 je 0x424b36
// 00424b32  3bc8                 cmp ecx, eax
// 00424b34  7402                 je 0x424b38
// 00424b36  ffd5                 call ebp
// 00424b38  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00424b3c  2bcf                 sub ecx, edi
// 00424b3e  b893244992           mov eax, 0x92492493
// 00424b43  f7e9                 imul ecx
// 00424b45  03d1                 add edx, ecx
// 00424b47  c1fa04               sar edx, 4
// 00424b4a  8bfa                 mov edi, edx
// 00424b4c  c1ef1f               shr edi, 0x1f
// 00424b4f  03fa                 add edi, edx
// 00424b51  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00424b55  8b542424             mov edx, dword ptr [esp + 0x24]
// 00424b59  8b442420             mov eax, dword ptr [esp + 0x20]
// 00424b5d  51                   push ecx
// 00424b5e  6a01                 push 1
// 00424b60  52                   push edx
// 00424b61  50                   push eax
// 00424b62  8bce                 mov ecx, esi
// 00424b64  e8f7faffff           call 0x424660
// 00424b69  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00424b6c  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00424b6f  7602                 jbe 0x424b73
// 00424b71  ffd5                 call ebp
// 00424b73  8b36                 mov esi, dword ptr [esi]
// 00424b75  57                   push edi
// 00424b76  8d4c2414             lea ecx, [esp + 0x14]
// 00424b7a  89742414             mov dword ptr [esp + 0x14], esi
// 00424b7e  895c2418             mov dword ptr [esp + 0x18], ebx
// 00424b82  e859112b00           call 0x6d5ce0
// 00424b87  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00424b8b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00424b8f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00424b93  5f                   pop edi
// 00424b94  5e                   pop esi
// 00424b95  5d                   pop ebp
// 00424b96  8908                 mov dword ptr [eax], ecx
// 00424b98  895004               mov dword ptr [eax + 4], edx
// 00424b9b  5b                   pop ebx
// 00424b9c  83c408               add esp, 8
// 00424b9f  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;

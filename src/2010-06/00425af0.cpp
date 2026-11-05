// from server: 100% by auto
// roc 2010-06 00425af0  unit: MainLogManager  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425af0
//
// 00425af0  83ec08               sub esp, 8
// 00425af3  53                   push ebx
// 00425af4  55                   push ebp
// 00425af5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00425afb  56                   push esi
// 00425afc  8bf1                 mov esi, ecx
// 00425afe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00425b01  57                   push edi
// 00425b02  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00425b05  8bcb                 mov ecx, ebx
// 00425b07  2bcf                 sub ecx, edi
// 00425b09  b893244992           mov eax, 0x92492493
// 00425b0e  f7e9                 imul ecx
// 00425b10  03d1                 add edx, ecx
// 00425b12  c1fa04               sar edx, 4
// 00425b15  8bc2                 mov eax, edx
// 00425b17  c1e81f               shr eax, 0x1f
// 00425b1a  03c2                 add eax, edx
// 00425b1c  7504                 jne 0x425b22
// 00425b1e  33ff                 xor edi, edi
// 00425b20  eb2f                 jmp 0x425b51
// 00425b22  3bfb                 cmp edi, ebx
// 00425b24  7602                 jbe 0x425b28
// 00425b26  ffd5                 call ebp
// 00425b28  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00425b2c  8b06                 mov eax, dword ptr [esi]
// 00425b2e  85c9                 test ecx, ecx
// 00425b30  7404                 je 0x425b36
// 00425b32  3bc8                 cmp ecx, eax
// 00425b34  7402                 je 0x425b38
// 00425b36  ffd5                 call ebp
// 00425b38  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00425b3c  2bcf                 sub ecx, edi
// 00425b3e  b893244992           mov eax, 0x92492493
// 00425b43  f7e9                 imul ecx
// 00425b45  03d1                 add edx, ecx
// 00425b47  c1fa04               sar edx, 4
// 00425b4a  8bfa                 mov edi, edx
// 00425b4c  c1ef1f               shr edi, 0x1f
// 00425b4f  03fa                 add edi, edx
// 00425b51  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00425b55  8b542424             mov edx, dword ptr [esp + 0x24]
// 00425b59  8b442420             mov eax, dword ptr [esp + 0x20]
// 00425b5d  51                   push ecx
// 00425b5e  6a01                 push 1
// 00425b60  52                   push edx
// 00425b61  50                   push eax
// 00425b62  8bce                 mov ecx, esi
// 00425b64  e8f7faffff           call 0x425660
// 00425b69  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00425b6c  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00425b6f  7602                 jbe 0x425b73
// 00425b71  ffd5                 call ebp
// 00425b73  8b36                 mov esi, dword ptr [esi]
// 00425b75  57                   push edi
// 00425b76  8d4c2414             lea ecx, [esp + 0x14]
// 00425b7a  89742414             mov dword ptr [esp + 0x14], esi
// 00425b7e  895c2418             mov dword ptr [esp + 0x18], ebx
// 00425b82  e8e9e2ffff           call 0x423e70
// 00425b87  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00425b8b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00425b8f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00425b93  5f                   pop edi
// 00425b94  5e                   pop esi
// 00425b95  5d                   pop ebp
// 00425b96  8908                 mov dword ptr [eax], ecx
// 00425b98  895004               mov dword ptr [eax + 4], edx
// 00425b9b  5b                   pop ebx
// 00425b9c  83c408               add esp, 8
// 00425b9f  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
